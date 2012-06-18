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

 # Generated automatically by xs/gp_generate.pl
 # NOTE: Changes made to this file will be lost: look at xs/gp_generate.pl.

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Thin::G

void
has_cycle( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_has_cycle(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->has_cycle(): %s", 
      xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
is_precomputed( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_is_precomputed(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->is_precomputed(): %s", 
      xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
precompute( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_precompute(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->precompute(): %s", 
      xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_count( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_count(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_count(): %s", 
      xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_is_accessible( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_is_accessible(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_is_accessible(%d): %s", 
      rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_is_keep_separation( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_is_keep_separation(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_is_keep_separation(%d): %s", 
      rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_is_loop( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_is_loop(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_is_loop(%d): %s", 
      rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_is_nullable( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_is_nullable(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_is_nullable(%d): %s", 
      rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_is_nulling( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_is_nulling(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_is_nulling(%d): %s", 
      rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_is_productive( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_is_productive(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_is_productive(%d): %s", 
      rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_is_sequence( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_is_sequence(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_is_sequence(%d): %s", 
      rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_length( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_length(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_length(%d): %s", 
      rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_lhs( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_lhs(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_lhs(%d): %s", 
      rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_rhs( g_wrapper, rule_id, ix )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
    int ix;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_rhs(self, rule_id, ix);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->rule_rhs(%d, %d): %s", 
      rule_id, ix, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
start_symbol( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_start_symbol(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->start_symbol(): %s", 
      xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
start_symbol_set( g_wrapper, id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_start_symbol_set(self, id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->start_symbol_set(%d): %s", 
      id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_count( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_count(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_count(): %s", 
      xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_accessible( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_accessible(self, symbol_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_accessible(%d): %s", 
      symbol_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_counted( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_counted(self, symbol_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_counted(%d): %s", 
      symbol_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_nullable( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_nullable(self, symbol_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_nullable(%d): %s", 
      symbol_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_nulling( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_nulling(self, symbol_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_nulling(%d): %s", 
      symbol_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_productive( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_productive(self, symbol_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_productive(%d): %s", 
      symbol_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_start( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_start(self, symbol_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_start(%d): %s", 
      symbol_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_terminal( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_terminal(self, symbol_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_terminal(%d): %s", 
      symbol_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_terminal_set( g_wrapper, symbol_id, boolean )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_terminal_set(self, symbol_id, boolean);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_terminal_set(%d, %d): %s", 
      symbol_id, boolean, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_valued( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_valued(self, symbol_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_valued(%d): %s", 
      symbol_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_is_valued_set( g_wrapper, symbol_id, boolean )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_is_valued_set(self, symbol_id, boolean);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_is_valued_set(%d, %d): %s", 
      symbol_id, boolean, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_new( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_new(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 ) {
    croak("Problem in g->symbol_new(): %s", 
      xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

