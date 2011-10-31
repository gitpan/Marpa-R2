#!perl
# Copyright 2011 Jeffrey Kegler
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
#
use 5.010;
use strict;
use warnings;

# The Wall Series: a sequence of numbers generated by an especially
# ambiguous section of Perl syntax, relaxed to ignore precedence
# and lvalue restricitons.

# This produces numbers in the series A052952 in the literature.
# It's a kind of ragtime Fibonacci series.  My proof that the
# parse counts generated by this grammar and A052952 are identical
# is at perlmonks.org: http://perlmonks.org/?node_id=649892

use Test::More tests => 13;
use lib 'tool/lib';
use Marpa::R2::Test;

BEGIN {
    Test::More::use_ok('Marpa::R2');
}

# The inefficiency (at least some of it) is deliberate.
# Passing up a duples of [ string, value ] and then
# assembling a final string at the top would be better
# than assembling the string then taking it
# apart at each step.  But I wanted to test having
# a start symbol that appears repeatedly on the RHS.

## no critic (Subroutines::RequireArgUnpacking)

sub minus {
    shift;
    my ( $right_string, $right_value ) = ( $_[2] =~ /^(.*)==(.*)$/xms );
    my ( $left_string,  $left_value )  = ( $_[0] =~ /^(.*)==(.*)$/xms );
    my $value = $left_value - $right_value;
    return '(' . $left_string . q{-} . $right_string . ')==' . $value;
} ## end sub minus

sub postfix_decr {
    shift;
    my ( $string, $value ) = ( $_[0] =~ /^(.*)==(.*)$/xms );
    return '(' . $string . q{--} . ')==' . $value--;
}

sub prefix_decr {
    shift;
    my ( $string, $value ) = ( $_[2] =~ /^(.*)==(.*)$/xms );
    return '(' . q{--} . $string . ')==' . --$value;
}

sub negation {
    shift;
    my ( $string, $value ) = ( $_[1] =~ /^(.*)==(.*)$/xms );
    return '(' . q{-} . $string . ')==' . -$value;
}

sub number {
    shift;
    return "$_[0]==$_[0]";
}

sub default_action {
    shift;
    my $v_count = scalar @_;
    return q{}   if $v_count <= 0;
    return $_[0] if $v_count == 1;
    return '(' . join( q{;}, @_ ) . ')';
} ## end sub default_action

## use critic

my $g = Marpa::R2::Grammar->new(
    {   start   => 'E',
        actions => 'main',
        rules   => [
            [ 'E', [qw/E Minus E/],     'minus' ],
            [ 'E', [qw/E Minus Minus/], 'postfix_decr' ],
            [ 'E', [qw/Minus Minus E/], 'prefix_decr' ],
            [ 'E', [qw/Minus E/],       'negation', ],
            [ 'E', [qw/Number/],        'number' ],
        ],
        default_action => 'default_action'
    }
);

my @expected = qw(0 1 1 3 4 8 12 21 33 55 88 144 232 );

$g->precompute();

for my $n ( 1 .. 12 ) {

    # Set max_parses just in case there's an infinite loop.
    # This is for debugging, after all
    my $recce =
        Marpa::R2::Recognizer->new( { grammar => $g, max_parses => 300 } );
    $recce->read( 'Number', 6, 1 );
    for my $i (1 .. $n) {
            $recce->read( 'Minus', q{-}, 1 );
    }
    $recce->read( 'Number', 1, 1 );

    my $parse_count = 0;
    while ( $recce->value() ) { $parse_count++; }
    Marpa::R2::Test::is( $expected[$n], $parse_count,
        "Wall Series Number $n" );

} ## end for my $n ( 1 .. 12 )

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
