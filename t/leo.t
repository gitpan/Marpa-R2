#!perl
# Copyright 2012 Jeffrey Kegler
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
# The example from p. 168-169 of Leo's paper.
#
# Make sure I have a CHAF example!
#

use 5.010;
use strict;
use warnings;

use Test::More tests => 17;

use lib 'inc';
use Marpa::R2::Test;
use Marpa::R2;

## no critic (Subroutines::RequireArgUnpacking)

sub generate_action {
    my ($lhs) = @_;
    return sub {
        shift;
        my $v_count = scalar @_;
        return q{} if $v_count <= 0;
        my @vals = map { $_ // q{-} } @_;
        return $lhs . '(' . ( join q{;}, @vals ) . ')';
        }
} ## end sub generate_action

my $C_action       = generate_action('C');
my $S_action       = generate_action('S');
my $default_action = generate_action(q{?});

## use critic

my $grammar = Marpa::R2::Grammar->new(
    {   start => 'S',
        rules => [
            [ 'S', [qw/a S/],   'S_action', ],
            [ 'S', [qw/C/],     'S_action', ],
            [ 'C', [qw(a C b)], 'C_action', ],
            [ 'C', [], ],
        ],
        terminals      => [qw(a b)],
        default_action => 'default_action',
    }
);

$grammar->precompute();

Marpa::R2::Test::is( $grammar->show_symbols(),
    <<'END_OF_STRING', 'Leo168 Symbols' );
0: a, terminal
1: b, terminal
2: S
3: C
4: S[], nulling
5: C[], nulling
6: S[']
END_OF_STRING

Marpa::R2::Test::is( $grammar->show_rules,
    <<'END_OF_STRING', 'Leo168 Rules' );
0: S -> a S
1: S -> C
2: C -> a C b
3: C -> /* empty !used */
4: S -> a S
5: S -> a S[]
6: S -> C
7: C -> a C b
8: C -> a C[] b
9: S['] -> S /* vlhs real=1 */
END_OF_STRING

Marpa::R2::Test::is( $grammar->show_AHFA, <<'END_OF_STRING', 'Leo168 AHFA' );
* S0:
S['] -> . S
 <S> => S2; leo(S['])
* S1: predict
S -> . a S
S -> . a S[]
S -> . C
C -> . a C b
C -> . a C[] b
 <C> => S4; leo(S)
 <a> => S1; S3
* S2: leo-c
S['] -> S .
* S3:
S -> a . S
S -> a S[] .
C -> a . C b
C -> a C[] . b
 <C> => S7
 <S> => S6; leo(S)
 <b> => S5
* S4: leo-c
S -> C .
* S5:
C -> a C[] b .
* S6: leo-c
S -> a S .
* S7:
C -> a C . b
 <b> => S8
* S8:
C -> a C b .
END_OF_STRING

my %expected = (
    'a'        => q{S(a;-)},
    'ab'       => q{S(C(a;-;b))},
    'aa'       => q{S(a;S(a;-))},
    'aab'      => q{S(a;S(C(a;-;b)))},
    'aabb'     => q{S(C(a;C(a;-;b);b))},
    'aaa'      => q{S(a;S(a;S(a;-)))},
    'aaab'     => q{S(a;S(a;S(C(a;-;b))))},
    'aaabb'    => q{S(a;S(C(a;C(a;-;b);b)))},
    'aaabbb'   => q{S(C(a;C(a;C(a;-;b);b);b))},
    'aaaa'     => q{S(a;S(a;S(a;S(a;-))))},
    'aaaab'    => q{S(a;S(a;S(a;S(C(a;-;b)))))},
    'aaaabb'   => q{S(a;S(a;S(C(a;C(a;-;b);b))))},
    'aaaabbb'  => q{S(a;S(C(a;C(a;C(a;-;b);b);b)))},
    'aaaabbbb' => q{S(C(a;C(a;C(a;C(a;-;b);b);b);b))},
);

for my $a_length ( 1 .. 4 ) {
    for my $b_length ( 0 .. $a_length ) {

        my $string = ( 'a' x $a_length ) . ( 'b' x $b_length );
        my $recce = Marpa::R2::Recognizer->new(
            {   grammar  => $grammar,
                closures => {
                    'C_action'       => $C_action,
                    'S_action'       => $S_action,
                    'default_action' => $default_action,
                }
            }
        );
        for (1 .. $a_length ) {
            $recce->read( 'a', 'a' );
        }
        for (1 .. $b_length ) {
            $recce->read( 'b', 'b' );
        }
        my $value_ref = $recce->value();
        my $value = $value_ref ? ${$value_ref} : 'No parse';
        Marpa::R2::Test::is( $value, $expected{$string}, "Parse of $string" );

    } ## end for my $b_length ( 0 .. $a_length )
} ## end for my $a_length ( 1 .. 4 )

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
