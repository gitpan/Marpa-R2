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
default_rank( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_default_rank(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->default_rank(): %s",
     xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
default_rank_set( g_wrapper, rank )
    G_Wrapper *g_wrapper;
    Marpa_Rank rank;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_default_rank_set(self, rank);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->default_rank_set(%d): %s",
     rank, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
error_clear( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_error_clear(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->error_clear(): %s",
     xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
event_count( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_event_count(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->event_count(): %s",
     xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
has_cycle( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_has_cycle(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->has_cycle(): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->is_precomputed(): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->precompute(): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_count(): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_is_accessible(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_is_loop(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_is_nullable(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_is_nulling(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_is_productive(%d): %s",
     rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_is_proper_separation( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_is_proper_separation(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_is_proper_separation(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_is_sequence(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_length(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_lhs(%d): %s",
     rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_null_high( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_null_high(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_null_high(%d): %s",
     rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_null_high_set( g_wrapper, rule_id, flag )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
    int flag;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_null_high_set(self, rule_id, flag);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_null_high_set(%d, %d): %s",
     rule_id, flag, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_rank( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_rank(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_rank(%d): %s",
     rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_rank_set( g_wrapper, rule_id, rank )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
    Marpa_Rank rank;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_rank_set(self, rule_id, rank);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_rank_set(%d, %d): %s",
     rule_id, rank, xs_g_error( g_wrapper ));
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->rule_rhs(%d, %d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->start_symbol(): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->start_symbol_set(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_count(): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_accessible(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_counted(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_nullable(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_nulling(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_productive(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_start(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_terminal(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_terminal_set(%d, %d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_valued(%d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_is_valued_set(%d, %d): %s",
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
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_new(): %s",
     xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_rank( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_rank(self, symbol_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_rank(%d): %s",
     symbol_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
symbol_rank_set( g_wrapper, symbol_id, rank )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
    Marpa_Rank rank;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_rank_set(self, symbol_id, rank);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->symbol_rank_set(%d, %d): %s",
     symbol_id, rank, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Thin::R

void
current_earleme( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_current_earleme(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->current_earleme(): %s",
     xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
earleme( r_wrapper, ordinal )
    R_Wrapper *r_wrapper;
    Marpa_Earley_Set_ID ordinal;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_earleme(self, ordinal);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->earleme(%d): %s",
     ordinal, xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
earleme_complete( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_earleme_complete(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->earleme_complete(): %s",
     xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
earley_item_warning_threshold( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_earley_item_warning_threshold(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->earley_item_warning_threshold(): %s",
     xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
earley_item_warning_threshold_set( r_wrapper, too_many_earley_items )
    R_Wrapper *r_wrapper;
    int too_many_earley_items;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_earley_item_warning_threshold_set(self, too_many_earley_items);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->earley_item_warning_threshold_set(%d): %s",
     too_many_earley_items, xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
furthest_earleme( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_furthest_earleme(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->furthest_earleme(): %s",
     xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
is_exhausted( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_is_exhausted(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->is_exhausted(): %s",
     xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
latest_earley_set( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_latest_earley_set(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->latest_earley_set(): %s",
     xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
progress_report_finish( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_progress_report_finish(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->progress_report_finish(): %s",
     xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
progress_report_start( r_wrapper, ordinal )
    R_Wrapper *r_wrapper;
    Marpa_Earley_Set_ID ordinal;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_progress_report_start(self, ordinal);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->progress_report_start(%d): %s",
     ordinal, xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
start_input( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_start_input(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->start_input(): %s",
     xs_g_error( r_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Thin::O

void
high_rank_only_set( o_wrapper, flag )
    O_Wrapper *o_wrapper;
    int flag;
PPCODE:
{
  Marpa_Order self = o_wrapper->o;
  int gp_result = marpa_o_high_rank_only_set(self, flag);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && o_wrapper->base->throw ) {
    croak( "Problem in o->high_rank_only_set(%d): %s",
     flag, xs_g_error( o_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
high_rank_only( o_wrapper )
    O_Wrapper *o_wrapper;
PPCODE:
{
  Marpa_Order self = o_wrapper->o;
  int gp_result = marpa_o_high_rank_only(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && o_wrapper->base->throw ) {
    croak( "Problem in o->high_rank_only(): %s",
     xs_g_error( o_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rank( o_wrapper )
    O_Wrapper *o_wrapper;
PPCODE:
{
  Marpa_Order self = o_wrapper->o;
  int gp_result = marpa_o_rank(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && o_wrapper->base->throw ) {
    croak( "Problem in o->rank(): %s",
     xs_g_error( o_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Thin::T

void
next( t_wrapper )
    T_Wrapper *t_wrapper;
PPCODE:
{
  Marpa_Tree self = t_wrapper->t;
  int gp_result = marpa_t_next(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && t_wrapper->base->throw ) {
    croak( "Problem in t->next(): %s",
     xs_g_error( t_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
parse_count( t_wrapper )
    T_Wrapper *t_wrapper;
PPCODE:
{
  Marpa_Tree self = t_wrapper->t;
  int gp_result = marpa_t_parse_count(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && t_wrapper->base->throw ) {
    croak( "Problem in t->parse_count(): %s",
     xs_g_error( t_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Thin::V

void
symbol_is_valued_set( v_wrapper, symbol_id, value )
    V_Wrapper *v_wrapper;
    Marpa_Symbol_ID symbol_id;
    int value;
PPCODE:
{
  Marpa_Value self = v_wrapper->v;
  int gp_result = marpa_v_symbol_is_valued_set(self, symbol_id, value);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && v_wrapper->base->throw ) {
    croak( "Problem in v->symbol_is_valued_set(%d, %d): %s",
     symbol_id, value, xs_g_error( v_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
rule_is_valued_set( v_wrapper, symbol_id, value )
    V_Wrapper *v_wrapper;
    Marpa_Rule_ID symbol_id;
    int value;
PPCODE:
{
  Marpa_Value self = v_wrapper->v;
  int gp_result = marpa_v_rule_is_valued_set(self, symbol_id, value);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && v_wrapper->base->throw ) {
    croak( "Problem in v->rule_is_valued_set(%d, %d): %s",
     symbol_id, value, xs_g_error( v_wrapper->base ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Thin::G

void
_marpa_g_rule_is_keep_separation( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = _marpa_g_rule_is_keep_separation(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->_marpa_g_rule_is_keep_separation(%d): %s",
     rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
_marpa_g_irl_lhs( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = _marpa_g_irl_lhs(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->_marpa_g_irl_lhs(%d): %s",
     rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
_marpa_g_irl_rhs( g_wrapper, rule_id, ix )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID rule_id;
    int ix;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = _marpa_g_irl_rhs(self, rule_id, ix);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->_marpa_g_irl_rhs(%d, %d): %s",
     rule_id, ix, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
_marpa_g_irl_length( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = _marpa_g_irl_length(self, rule_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->_marpa_g_irl_length(%d): %s",
     rule_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
_marpa_g_irl_rank( g_wrapper, irl_id )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID irl_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = _marpa_g_irl_rank(self, irl_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->_marpa_g_irl_rank(%d): %s",
     irl_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
_marpa_g_isy_rank( g_wrapper, isy_id )
    G_Wrapper *g_wrapper;
    Marpa_ISY_ID isy_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = _marpa_g_isy_rank(self, isy_id);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && g_wrapper->throw ) {
    croak( "Problem in g->_marpa_g_isy_rank(%d): %s",
     isy_id, xs_g_error( g_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

