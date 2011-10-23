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

# Package with logic for running tests common to
# multiple Marpa implementations

# So that the do-file has the default package name
package main;

use 5.010;
use strict;
use warnings;

use English qw( -no_match_vars );
use File::Spec;
use Carp;

sub Marpa::Test::Common::run {
    my ($path) = @_;
    my ( $volume, $dirs, $file_name ) = File::Spec->splitpath($path);
    my @dirs = File::Spec->splitdir($dirs);
    $dirs = File::Spec->catdir( @dirs, 'common' );
    my $f = File::Spec->catpath( $volume, $dirs, $file_name );
    DO: {
        local $ERRNO      = undef;
        local $EVAL_ERROR = undef;
        last DO                                        if defined do $f;
        die qq{Compilation error in $f\n"$EVAL_ERROR"} if $EVAL_ERROR;
        die "$f: $ERRNO"                               if $ERRNO;
    } ## end DO:
    return 1;    # keep perlcritic happy
} ## end sub Marpa::Test::Common::run

1;

