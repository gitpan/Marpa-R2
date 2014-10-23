#!/usr/bin/perl
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

# Rewriting tests, to check the accuracy of the
# tracing documentation.

use 5.010;
use strict;
use warnings;

use Fatal qw(open close);
use Test::More tests => 3;

use lib 'tool/lib';
use Marpa::R2::Test;

BEGIN {
    Test::More::use_ok('Marpa::R2');
}

my $chaf_rule =
#<<< no perltidy
# Marpa::R2::Display
# name: CHAF Rule

{   lhs => 'statement',
    rhs => [
        qw/optional_whitespace expression
            optional_whitespace optional_modifier
            optional_whitespace/
    ]
}

# Marpa::R2::Display::End
; # semicolon to terminate rule

#>>> no perltidy

my $separated_sequence_rule =
#<<< no perltidy
# Marpa::R2::Display
# name: Separated Sequence Rule

{
    lhs       => 'statements',
    rhs       => [qw/statement/],
    separator => 'comma',
    min       => 1
}

# Marpa::R2::Display::End
; # semicolon to terminate rule

#>>> no perltidy

my $sequence_rule =
#<<< no perltidy
# Marpa::R2::Display
# name: Sequence Rule

    { lhs => 'block', rhs => [qw/statements/], min => 0 },

# Marpa::R2::Display::End
; # semicolon to terminate rule

#>>> no perltidy

my $grammar = Marpa::R2::Grammar->new(
    {   start   => 'block',
        symbols => {
            'block' => {
                terminal   => 1,
                null_value => 'Null parse'
            }
        },
        terminals => [qw(whitespace modifier expression comma)],
        rules     => [
            $chaf_rule,
            $separated_sequence_rule,
            $sequence_rule,
            { lhs => 'optional_whitespace', rhs => [qw(whitespace)] },
            { lhs => 'optional_whitespace', },
            { lhs => 'optional_modifier',   rhs => [qw(modifier)] },
            { lhs => 'optional_modifier', },
        ],
    }
);

$grammar->precompute();

my $recce = Marpa::R2::Recognizer->new( { grammar => $grammar } );

# While we are at it, test the handling of null parses in
# the Single Parse Evaluator
$recce->end_input();

# Marpa::R2::Display::End

my $show_rules_output = $grammar->show_rules();

# Marpa::R2::Display
# name: Rewrite show_rules Output
# start-after-line: END_RULES
# end-before-line: '^END_RULES$'

Marpa::R2::Test::is( $show_rules_output, <<'END_RULES', 'Rewritten Rules' );
0: statement -> optional_whitespace expression optional_whitespace optional_modifier optional_whitespace /* !used */
1: statements -> statement /* !used discard_sep */
2: statements -> statements[statement+] /* vrhs real=0 */
3: statements -> statements[statement+] comma /* vrhs real=1 */
4: statements[statement+] -> statement /* vlhs real=1 */
5: statements[statement+] -> statements[statement+] comma statement /* vlhs vrhs real=2 */
6: block -> statements /* !used */
7: block -> /* empty !used */
8: block -> block[statements*] /* vrhs real=0 */
9: block[statements*] -> statements /* vlhs real=1 */
10: block[statements*] -> block[statements*] statements /* vlhs vrhs real=1 */
11: optional_whitespace -> whitespace
12: optional_whitespace -> /* empty !used */
13: optional_modifier -> modifier
14: optional_modifier -> /* empty !used */
15: statement -> optional_whitespace expression statement[R0:2] /* vrhs real=2 */
16: statement -> optional_whitespace expression optional_whitespace[] optional_modifier[] optional_whitespace[]
17: statement -> optional_whitespace[] expression statement[R0:2] /* vrhs real=2 */
18: statement -> optional_whitespace[] expression optional_whitespace[] optional_modifier[] optional_whitespace[]
19: statement[R0:2] -> optional_whitespace statement[R0:3] /* vlhs vrhs real=1 */
20: statement[R0:2] -> optional_whitespace optional_modifier[] optional_whitespace[] /* vlhs real=3 */
21: statement[R0:2] -> optional_whitespace[] statement[R0:3] /* vlhs vrhs real=1 */
22: statement[R0:3] -> optional_modifier optional_whitespace /* vlhs real=2 */
23: statement[R0:3] -> optional_modifier optional_whitespace[] /* vlhs real=2 */
24: statement[R0:3] -> optional_modifier[] optional_whitespace /* vlhs real=2 */
25: block['] -> block /* vlhs real=1 */
26: block['][] -> /* empty !used vlhs real=1 */
END_RULES

# Marpa::R2::Display::End

my $value_ref = $recce->value();
my $value = $value_ref ? ${$value_ref} : 'No Parse';

Marpa::R2::Test::is( $value, 'Null parse', 'Null parse value' );

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
