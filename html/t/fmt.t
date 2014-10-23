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

use 5.010;
use strict;
use warnings;

use English qw( -no_match_vars );
use Fatal qw(open close);
use File::Spec;

use lib 'tool/lib';
use lib 'html/tool/lib';
use Test::More tests => 7;
Test::More::use_ok('Marpa::R2::Test');
Test::More::use_ok('Marpa::R2::HTML::Test::Util');
Test::More::use_ok('HTML::PullParser');

my @script_dir = qw( blib script );
my @data_dir   = qw( html t fmt_t_data );

for my $test (qw(1 2)) {
    my $expected;
    my $output = Marpa::R2::HTML::Test::Util::run_command(
        File::Spec->catfile( @script_dir, 'marpa_r2_html_fmt' ),
        File::Spec->catfile( @data_dir, ( 'input' . $test . '.html' ) ) );
    local $RS = undef;
    open my $fh, q{<},
        File::Spec->catfile( @data_dir, ( 'expected' . $test . '.html' ) );
    $expected = <$fh>;
    close $fh;
    Marpa::R2::Test::is( $output, $expected, 'marpa_r2_html_fmt test' );
} ## end for my $test (qw(1 2))

