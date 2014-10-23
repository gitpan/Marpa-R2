#!/usr/bin/perl
# Copyright 2013 Jeffrey Kegler
# This file is part of Marpa::R2.  Marpa::R2 is free software: you can
# redistribute it and/or modify it under the terms of the GNU Lesser
# General Public License as published by the Free Software Foundation,
# either version 3 of the License, or (at your option) any later version.
#
# Marpa::R2 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser
# General Public License along with Marpa::R2.  If not, see
# http://www.gnu.org/licenses/.

# Various that share a calculator semantics

use 5.010;
use strict;
use warnings;
use Test::More tests => 6;
use English qw( -no_match_vars );
use Scalar::Util qw(blessed);

use lib 'inc';
use Marpa::R2::Test;

## no critic (ErrorHandling::RequireCarping);

use Marpa::R2;

my $calculator_grammar = Marpa::R2::Scanless::G->new(
    {   bless_package => 'My_Nodes',
        source        => \(<<'END_OF_SOURCE'),
:default ::= action => ::array bless => ::lhs
:start ::= Script
Script ::= Expression+ separator => comma bless => script
comma ~ [,]
Expression ::=
    Number bless => primary
    | ('(') Expression (')') assoc => group bless => parens
   || Expression ('**') Expression assoc => right bless => power
   || Expression ('*') Expression bless => multiply
    | Expression ('/') Expression bless => divide
   || Expression ('+') Expression bless => add
    | Expression ('-') Expression bless => subtract
Number ~ [\d]+

:discard ~ whitespace
whitespace ~ [\s]+
# allow comments
:discard ~ <hash comment>
<hash comment> ~ <terminated hash comment> | <unterminated
   final hash comment>
<terminated hash comment> ~ '#' <hash comment body> <vertical space char>
<unterminated final hash comment> ~ '#' <hash comment body>
<hash comment body> ~ <hash comment char>*
<vertical space char> ~ [\x{A}\x{B}\x{C}\x{D}\x{2028}\x{2029}]
<hash comment char> ~ [^\x{A}\x{B}\x{C}\x{D}\x{2028}\x{2029}]
END_OF_SOURCE
    }
);

my $show_rules_output = $calculator_grammar->show_rules();

Marpa::R2::Test::is( $show_rules_output,
    <<'END_OF_SHOW_RULES_OUTPUT', 'Scanless show_rules()' );
Lex (G0) Rules:
0: comma -> [[,]]
1: [Lex-0] -> [[\(]]
2: [Lex-1] -> [[\)]]
3: [Lex-2] -> [[\*]] [[\*]]
4: [Lex-3] -> [[\*]]
5: [Lex-4] -> [[\/]]
6: [Lex-5] -> [[\+]]
7: [Lex-6] -> [[\-]]
8: Number -> [[\d]]+
9: [:discard] -> whitespace
10: whitespace -> [[\s]]+
11: [:discard] -> hash comment
12: hash comment -> terminated hash comment
13: hash comment -> unterminated final hash comment
14: terminated hash comment -> [[\#]] hash comment body vertical space char
15: unterminated final hash comment -> [[\#]] hash comment body
16: hash comment body -> hash comment char*
17: vertical space char -> [[\x{A}\x{B}\x{C}\x{D}\x{2028}\x{2029}]]
18: hash comment char -> [[^\x{A}\x{B}\x{C}\x{D}\x{2028}\x{2029}]]
19: [:start_lex] -> Number
20: [:start_lex] -> [:discard]
21: [:start_lex] -> [Lex-0]
22: [:start_lex] -> [Lex-1]
23: [:start_lex] -> [Lex-2]
24: [:start_lex] -> [Lex-3]
25: [:start_lex] -> [Lex-4]
26: [:start_lex] -> [Lex-5]
27: [:start_lex] -> [Lex-6]
28: [:start_lex] -> comma
G1 Rules:
0: [:start] -> Script
1: Script -> Expression+ /* discard_sep */
2: Expression -> Expression
3: Expression -> Expression
4: Expression -> Expression
5: Expression -> Expression
6: Expression -> Number
7: Expression -> [Lex-0] Expression [Lex-1]
8: Expression -> Expression [Lex-2] Expression
9: Expression -> Expression [Lex-3] Expression
10: Expression -> Expression [Lex-4] Expression
11: Expression -> Expression [Lex-5] Expression
12: Expression -> Expression [Lex-6] Expression
END_OF_SHOW_RULES_OUTPUT

do_test('Calculator 1', $calculator_grammar,
'42*2+7/3, 42*(2+7)/3, 2**7-3, 2**(7-3)' => qr/\A 86[.]3\d+ \s+ 126 \s+ 125 \s+ 16\z/xms);
do_test('Calculator 2', $calculator_grammar,
       '42*3+7, 42 * 3 + 7, 42 * 3+7' => qr/ \s* 133 \s+ 133 \s+ 133 \s* /xms);
do_test('Calculator 3', $calculator_grammar,
       '15329 + 42 * 290 * 711, 42*3+7, 3*3+4* 4' =>
            qr/ \s* 8675309 \s+ 133 \s+ 25 \s* /xms);

my $priority_grammar = <<'END_OF_GRAMMAR';
:default ::= action => ::array
:start ::= statement
statement ::= (<say keyword>) expression bless => statement
    | expression bless => statement
expression ::=
    number bless => primary
   | variable bless => variable
   || sign expression bless => unary_sign
   || expression ('+') expression bless => add
number ~ [\d]+
variable ~ [[:alpha:]] <optional word characters>
<optional word characters> ~ [[:alnum:]]*

# Marpa::R2::Display
# name: SLIF lexeme rule synopsis

:lexeme ~ <say keyword> priority => 1

# Marpa::R2::Display::End

<say keyword> ~ 'say'
sign ~ [+-]
:discard ~ whitespace
whitespace ~ [\s]+
END_OF_GRAMMAR

do_test(
    'Priority test 1',
    Marpa::R2::Scanless::G->new(
        {   bless_package => 'My_Nodes',
            source        => \$priority_grammar,
        }
    ),
    'say + 42' => qr/ 42 /xms
);

(my $priority_grammar2 = $priority_grammar) =~ s/priority \s+ => \s+ 1$/priority => -1/xms;
do_test(
    'Priority test 2',
    Marpa::R2::Scanless::G->new(
        {   bless_package => 'My_Nodes',
            source        => \$priority_grammar2,
        }
    ),
    'say + 42' => qr/ 41 /xms
);

sub do_test {
    my ( $name, $grammar, $input, $output_re, $args ) = @_;
    my $recce = Marpa::R2::Scanless::R->new( { grammar => $grammar } );

    $recce->read(\$input);
    my $value_ref = $recce->value();
    if ( not defined $value_ref ) {
        die "No parse was found, after reading the entire input\n";
    }
    my $parse = { variables => { say => -1 } };
    my $value = ${$value_ref}->doit($parse);
    Test::More::like( $value, $output_re, $name );
}

sub My_Nodes::script::doit {
    my ($self, $parse) = @_;
    return join q{ }, map { $_->doit($parse) } @{$self};
}
sub My_Nodes::statement::doit {
    my ($self, $parse) = @_;
    return $self->[0]->doit($parse);
}

sub My_Nodes::add::doit {
    my ($self, $parse) = @_;
    my ( $a, $b ) = @{$self};
    return $a->doit($parse) + $b->doit($parse);
}

sub My_Nodes::subtract::doit {
    my ($self, $parse) = @_;
    my ( $a, $b ) = @{$self};
    return $a->doit($parse) - $b->doit($parse);
}

sub My_Nodes::multiply::doit {
    my ($self, $parse) = @_;
    my ( $a, $b ) = @{$self};
    return $a->doit($parse) * $b->doit($parse);
}

sub My_Nodes::divide::doit {
    my ($self, $parse) = @_;
    my ( $a, $b ) = @{$self};
    return $a->doit($parse) / $b->doit($parse);
}

sub My_Nodes::unary_sign::doit {
    my ($self, $parse) = @_;
    my ( $sign, $expression ) = @{$self};
    my $unsigned_result = $expression->doit($parse);
    return $sign eq '+' ? $unsigned_result : -$unsigned_result;
} ## end sub My_Nodes::unary_sign::doit

sub My_Nodes::variable::doit {
    my ( $self, $parse ) = @_;
    my $name = $self->[0];
    Marpa::R2::Context::bail(qq{variable "$name" does not exist})
        if not exists $parse->{variables}->{$name};
    return $parse->{variables}->{$name};
} ## end sub My_Nodes::variable::doit

sub My_Nodes::primary::doit {
    my ($self, $parse) = @_;
    return $self->[0];
}
sub My_Nodes::parens::doit  {
    my ($self, $parse) = @_;
    return $self->[0]->doit($parse);
}

sub My_Nodes::power::doit {
    my ($self, $parse) = @_;
    my ( $a, $b ) = @{$self};
    return $a->doit($parse)**$b->doit($parse);
}

# vim: expandtab shiftwidth=4:
