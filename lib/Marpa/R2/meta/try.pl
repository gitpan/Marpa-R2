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

use 5.010;
use strict;
use warnings;
use English qw( -no_match_vars );
use Data::Dumper;
use Carp;
use Scalar::Util qw(blessed reftype);

# This is a 'meta' tool, so I relax some of the
# restrictions I use to guarantee portability.
use autodie;

# I expect to be run from a subdirectory in the
# development heirarchy
use lib '../../../';
use lib '../../../../blib/arch';
use Marpa::R2;
BEGIN { require './Try.pm'; }

use Getopt::Long;
my $verbose          = 1;
my $help_flag        = 0;
my $scannerless_flag = 1;
my $result           = Getopt::Long::GetOptions(
    'help'      => \$help_flag,
);
die "usage $PROGRAM_NAME [--help] file ...\n" if $help_flag;

my $bnf           = do { local $RS = undef; \(<>) };
my $parse_result =
    Marpa::R2::Scanless::G->_source_to_ast( $bnf );
die "_source_to_ast did not return an AST" if not ref $parse_result eq 'REF';
my $self = {};
say "ast result = \n", Data::Dumper::Dumper(evaluate(${$parse_result}, $self));
say "self object = \n", Data::Dumper::Dumper($self);

exit 0;

sub evaluate {
    my ($value, $self) = @_;
    return $value if not defined $value;
    if (Scalar::Util::blessed($value)) {
	return $value->evaluate($self) if $value->can('evaluate');
	return bless [ map { evaluate($_, $self) } @{$value} ], ref $value if Scalar::Util::reftype($value) eq 'ARRAY';
	return $value;
    }
    return [ map { evaluate($_, $self) } @{$value} ] if ref $value eq 'ARRAY';
    return $value;
} ## end sub evaluate

sub sort_bnf {
    my $cmp = $a->{lhs} cmp $b->{lhs};
    return $cmp if $cmp;
    my $a_rhs_length = scalar @{ $a->{rhs} };
    my $b_rhs_length = scalar @{ $b->{rhs} };
    $cmp = $a_rhs_length <=> $b_rhs_length;
    return $cmp if $cmp;
    for my $ix ( 0 .. ($a_rhs_length-1) ) {
        $cmp = $a->{rhs}->[$ix] cmp $b->{rhs}->[$ix];
        return $cmp if $cmp;
    }
    return 0;
} ## end sub sort_bnf

my %cooked_parse_result = (
    is_lexeme         => $parse_result->{is_lexeme},
    character_classes => $parse_result->{character_classes}
);
for my $rule_set (qw(lex_rules g1_rules)) {
    my $aoh        = $parse_result->{$rule_set};
    my $sorted_aoh = [ sort sort_bnf @{$aoh} ];
    $cooked_parse_result{$rule_set} = $sorted_aoh;
}

say "## The code after this line was automatically generated by ",
    $PROGRAM_NAME;
say "## Date: ", scalar localtime();
$Data::Dumper::Sortkeys = 1;
print Data::Dumper->Dump( [ \%cooked_parse_result ], [qw(hashed_metag)] );
say "## The code before this line was automatically generated by ",
    $PROGRAM_NAME;

exit 0;

package Marpa::R2::Internal::MetaG::Symbol;

use English qw( -no_match_vars );

# Make the child argument into a symbol, if it is
# not one already
sub evaluate { return $_[0] };
sub new {
    my ( $class, $self, $hide ) = @_;
    return bless { name => ('' . $self), is_hidden => ($hide//0) }, $class if ref $self eq q{};
    return $self;
}

sub create_internal_symbol {
    my ($self, $symbol_name) = @_;
    $self->{needs_symbol}->{$symbol_name} = 1;
    my $symbol = Marpa::R2::Internal::MetaG::Symbol->new($symbol_name);
    return $symbol;
}

# Return the character class symbol name,
# after ensuring everything is set up properly
sub assign_symbol_by_char_class {
    my ( $self, $char_class, $symbol_name ) = @_;

    # default symbol name always start with TWO left square brackets
    $symbol_name //= '[' . $char_class . ']';
    $self->{character_classes} //= {};
    my $cc_hash    = $self->{character_classes};
    my (undef, $symbol) = $cc_hash->{$symbol_name};
    if ( not defined $symbol ) {
        my $regex;
        if ( not defined eval { $regex = qr/$char_class/xms; 1; } ) {
            Carp::croak( 'Bad Character class: ',
                $char_class, "\n", 'Perl said ', $EVAL_ERROR );
        }
        $symbol = create_internal_symbol($self, $symbol_name);
        $cc_hash->{$symbol_name} = [ $regex, $symbol ];
    } ## end if ( not defined $hash_entry )
    return $symbol;
} ## end sub assign_symbol_by_char_class

sub is_symbol { return 1 };
sub name { return $_[0]->{name} }
sub names { return $_[0]->{name} }
sub is_hidden { return $_[0]->{is_hidden} }
sub are_all_hidden { return $_[0]->{is_hidden} }

sub is_lexical { return shift->{is_lexical} // 0 }
sub hidden_set { return shift->{is_hidden} = 1; }
sub lexical_set { return shift->{is_lexical} = 1; }
sub mask { return shift->is_hidden() ? 0 : 1 }

sub symbols { return $_[0]; }
sub symbol_lists { return $_[0]; }

package Marpa::R2::Internal::Scanless::Symbol_List;

sub new { my $class = shift; return bless { symbol_lists => [@_] }, $class }

sub is_symbol { return 0 };

sub names {
    return map { $_->names() } @{ shift->{symbol_lists} };
}

sub are_all_hidden {
     $_->is_hidden() || return 0 for @{ shift->{symbol_lists } };
     return 1;
}

sub is_hidden {
    return map { $_->is_hidden() } @{ shift->{symbol_lists } };
}

sub hidden_set {
    $_->hidden_set() for @{ shift->{symbol_lists} };
    return 0;
}

sub is_lexical { return shift->{is_lexical} // 0 }
sub lexical_set { return shift->{is_lexical} = 1; }

sub mask {
    return
        map { $_ ? 0 : 1 } map { $_->is_hidden() } @{ shift->{symbol_lists} };
}

sub symbols {
    return map { $_->symbols() } @{ shift->{symbol_lists} };
}

# The "unflattened" list, which may contain other lists
sub symbol_lists { return @{ shift->{symbol_lists} }; }

package Marpa::R2::Internal::MetaG_Nodes::single_symbol;

package Marpa::R2::Internal::MetaG_Nodes::kwc_ws_star;
sub evaluate { return create_internal_symbol($_[1], $_[0]->[0]) }
package Marpa::R2::Internal::MetaG_Nodes::kwc_ws_plus;
sub evaluate { return create_internal_symbol($_[1], $_[0]->[0]) }
package Marpa::R2::Internal::MetaG_Nodes::kwc_ws;
sub evaluate { return create_internal_symbol($_[1], $_[0]->[0]) }
package Marpa::R2::Internal::MetaG_Nodes::kwc_any;
sub evaluate {
    return Marpa::R2::Internal::MetaG::Symbol::assign_symbol_by_char_class(
        $_[1], '[\p{Cn}\P{Cn}]', $_[0]->[0] );
}

package Marpa::R2::Internal::MetaG_Nodes::single_symbol;
sub evaluate { return $_[0]->[0]->evaluate(); }
package Marpa::R2::Internal::MetaG_Nodes::symbol;
sub evaluate { return $_[0]->[0]->evaluate() ; }
package Marpa::R2::Internal::MetaG_Nodes::symbol_name;
sub evaluate { return $_[0]->[0]->evaluate(); }

package Marpa::R2::Internal::MetaG_Nodes::character_class;

sub evaluate {
    my ( $values, $self ) = @_;
    my $symbol =
        Marpa::R2::Internal::MetaG::Symbol::assign_symbol_by_char_class(
        $self, $values->[0] );
    $symbol->lexical_set();
    return $symbol;
} ## end sub evaluate

package Marpa::R2::Internal::MetaG_Nodes::bare_name;
sub evaluate { return Marpa::R2::Internal::MetaG::Symbol->new( $_[0]->[0] ); }

package Marpa::R2::Internal::MetaG_Nodes::bracketed_name;

sub evaluate {
    my ($children) = @_;
    my $bracketed_name = $children->[0];

    # normalize whitespace
    $bracketed_name =~ s/\A [<] \s*//xms;
    $bracketed_name =~ s/ \s* [>] \z//xms;
    $bracketed_name =~ s/ \s+ / /gxms;
    return Marpa::R2::Internal::MetaG::Symbol->new($bracketed_name);
} ## end sub evaluate

package Marpa::R2::Internal::MetaG_Nodes::single_quoted_string;

sub evaluate {
    my ($values, $self ) = @_;
    my $string = $values->[0];
    my @symbols = ();
    for my $char_class ( map { '[' . (quotemeta $_) . ']' } split //xms, substr $string, 1, -1) {
        my $symbol = Marpa::R2::Internal::MetaG::Symbol::assign_symbol_by_char_class(
        $self, $char_class);
        push @symbols, $symbol;
    }
    my $list = Marpa::R2::Internal::Scanless::Symbol_List->new(@symbols);
    $list->lexical_set();
    return $list;
}

