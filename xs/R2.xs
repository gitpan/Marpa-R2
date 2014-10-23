/*
 * Copyright 2011 Jeffrey Kegler
 * This file is part of Marpa::R2.  Marpa::R2 is free software: you can
 * redistribute it and/or modify it under the terms of the GNU Lesser
 * General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Marpa::R2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser
 * General Public License along with Marpa::R2.  If not, see
 * http://www.gnu.org/licenses/.
 */

#include <gperl.h>

#include "config.h"
#include "marpa.h"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

#define DEBUG 0
#if !DEBUG
#if defined(G_HAVE_GNUC_VARARGS)
#undef g_debug
#define g_debug(...)
#endif /* defined G_HAVE_GNUC_VARARGS */
#endif /* if !DEBUG */

typedef struct marpa_g Grammar;
typedef struct {
     Marpa_Grammar g;
     char *message_buffer;
     GArray* gint_array;
} G_Wrapper;

typedef struct marpa_r Recce;
typedef struct {
     Marpa_Recce r;
     char *message_buffer;
     GArray* gint_array;
} R_Wrapper;

typedef struct marpa_b Bocage;
typedef struct {
     Marpa_Bocage b;
     char *message_buffer;
} B_Wrapper;

typedef struct marpa_o Order;
typedef struct {
     Marpa_Order o;
     char *message_buffer;
} O_Wrapper;

typedef struct marpa_t Tree;
typedef struct {
     Marpa_Tree t;
     char *message_buffer;
} T_Wrapper;

typedef struct marpa_v Value;
typedef struct {
     Marpa_Value v;
     char *message_buffer;
} V_Wrapper;

static const char grammar_c_class_name[] = "Marpa::R2::Internal::G_C";
static const char recce_c_class_name[] = "Marpa::R2::Internal::R_C";
static const char bocage_c_class_name[] = "Marpa::R2::Internal::B_C";
static const char order_c_class_name[] = "Marpa::R2::Internal::O_C";
static const char tree_c_class_name[] = "Marpa::R2::Internal::T_C";
static const char value_c_class_name[] = "Marpa::R2::Internal::V_C";

static const char *
event_type_to_string (Marpa_Event_Type type)
{
  switch (type)
    {
    case MARPA_G_EV_EXHAUSTED:
      return "exhausted";
    case MARPA_G_EV_EARLEY_ITEM_THRESHOLD:
      return "earley item count";
    case MARPA_G_EV_LOOP_RULES:
      return "loop rules";
    case MARPA_G_EV_NEW_SYMBOL:
      return "new symbol";
    case MARPA_G_EV_NEW_RULE:
      return "new rule";
    }
  return NULL;
}

#include "error.h"
#include "error.c"

/* This routine is for the handling exceptions
   from libmarpa.  It is used when in the general
   cases, for those exception which are not singled
   out for special handling by the XS logic.
   It returns a buffer which must be g_free()'d.
*/
static char *
libmarpa_exception (int error_code, const char *error_string)
{
  const char *suggested_description = NULL;
  /*
   * error_name should always be set when suggested_description is,
   * so this initialization should never be used.
   */
  const char *error_name = "not libmarpa error";
  switch (error_code)
    {
    case MARPA_ERR_DEVELOPMENT:
      return g_strdup_printf ("(development) %s",
			      (error_string ? error_string : "(null)"));
    case MARPA_ERR_INTERNAL:
      return g_strdup_printf ("Internal error at %s",
			      (error_string ? error_string : "(null)"));
    }
  if (error_code >= 0 && error_code < MARPA_ERROR_COUNT) {
      suggested_description = marpa_error_description[error_code].suggested;
      error_name = marpa_error_description[error_code].name;
  }
  if (!suggested_description)
    {
      if (error_string)
	{
	  return g_strdup_printf ("libmarpa error %d %s: %s",
	  error_code, error_name, error_string);
	}
      return g_strdup_printf ("libmarpa error %d %s", error_code, error_name);
    }
  if (error_string)
    {
      return g_strconcat (suggested_description, "; ", error_string, NULL);
    }
  return g_strdup (suggested_description);
}

/* Return value must be g_free()'d */
static const char *
xs_g_error (G_Wrapper * g_wrapper)
{
  const char *error_string;
  struct marpa_g *g = g_wrapper->g;
  const int error_code = marpa_g_error (g, &error_string);
  char *buffer = g_wrapper->message_buffer;
  g_free (buffer);
  g_wrapper->message_buffer = buffer =
    libmarpa_exception (error_code, error_string);
  return buffer;
}

/* Return value must be g_free()'d */
static const char *
xs_r_error (R_Wrapper * r_wrapper)
{
  const char *error_string;
  struct marpa_r *r = r_wrapper->r;
  const int error_code = marpa_r_error (r, &error_string);
  char *buffer = r_wrapper->message_buffer;
  g_free (buffer);
  r_wrapper->message_buffer = buffer =
    libmarpa_exception (error_code, error_string);
  return buffer;
}

/* Return value must be g_free()'d */
static const char *
xs_b_error (B_Wrapper * b_wrapper)
{
  const char *error_string;
  Marpa_Bocage b = b_wrapper->b;
  Marpa_Grammar g = marpa_b_g(b);
  const int error_code = marpa_g_error (g, &error_string);
  char *buffer = b_wrapper->message_buffer;
  g_free (buffer);
  b_wrapper->message_buffer = buffer =
    libmarpa_exception (error_code, error_string);
  return buffer;
}

/* Return value must be g_free()'d */
static const char *
xs_o_error (O_Wrapper * o_wrapper)
{
  const char *error_string;
  Marpa_Order o = o_wrapper->o;
  Marpa_Grammar g = marpa_o_g(o);
  const int error_code = marpa_g_error (g, &error_string);
  char *buffer = o_wrapper->message_buffer;
  g_free (buffer);
  o_wrapper->message_buffer = buffer =
    libmarpa_exception (error_code, error_string);
  return buffer;
}

/* Return value must be g_free()'d */
static const char *
xs_t_error (T_Wrapper * t_wrapper)
{
  const char *error_string;
  Marpa_Tree t = t_wrapper->t;
  Marpa_Grammar g = marpa_t_g(t);
  const int error_code = marpa_g_error (g, &error_string);
  char *buffer = t_wrapper->message_buffer;
  g_free (buffer);
  t_wrapper->message_buffer = buffer =
    libmarpa_exception (error_code, error_string);
  return buffer;
}

/* Return value must be g_free()'d */
static const char *
xs_v_error (V_Wrapper * v_wrapper)
{
  const char *error_string;
  Marpa_Value v = v_wrapper->v;
  Marpa_Grammar g = marpa_v_g(v);
  const int error_code = marpa_g_error (g, &error_string);
  char *buffer = v_wrapper->message_buffer;
  g_free (buffer);
  v_wrapper->message_buffer = buffer =
    libmarpa_exception (error_code, error_string);
  return buffer;
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Internal

PROTOTYPES: DISABLE

void
error_names()
PPCODE:
{
  int error_code;
  for (error_code = 0; error_code < MARPA_ERROR_COUNT; error_code++)
    {
      const char *error_name = marpa_error_description[error_code].name;
      XPUSHs (sv_2mortal (newSVpv (error_name, 0)));
    }
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Internal::G_C

G_Wrapper *
new( class, non_c_sv )
    char * class;
PREINIT:
    struct marpa_g *g;
    SV *sv;
    G_Wrapper *g_wrapper;
    const char *version_error;
PPCODE:
    version_error =
	marpa_check_version(MARPA_MAJOR_VERSION, MARPA_MINOR_VERSION, MARPA_MICRO_VERSION,
	   MARPA_VARIANT);
    if (version_error) {
	  croak ("Problem in Marpa::R2->new(): %s", version_error);
    }
    g = marpa_g_new(MARPA_VARIANT);
    Newx( g_wrapper, 1, G_Wrapper );
    g_wrapper->g = g;
    g_wrapper->message_buffer = NULL;
    g_wrapper->gint_array = g_array_new( FALSE, FALSE, sizeof(gint));
    sv = sv_newmortal();
    sv_setref_pv(sv, grammar_c_class_name, (void*)g_wrapper);
    XPUSHs(sv);

void
DESTROY( g_wrapper )
    G_Wrapper *g_wrapper;
PREINIT:
    struct marpa_g * grammar;
CODE:
    g_free(g_wrapper->message_buffer);
    grammar = g_wrapper->g;
    g_array_free(g_wrapper->gint_array, TRUE);
    marpa_g_unref( grammar );
    Safefree( g_wrapper );

void
start_symbol_set( g_wrapper, id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_start_symbol_set (g, id);
  if (result < 0)
    {
      croak ("Problem in g->start_symbol_set(): %s", xs_g_error (g_wrapper));
    }
  XSRETURN_YES;
}

void
start_symbol( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  Marpa_Symbol_ID id = marpa_g_start_symbol (g);
  if (id <= -2)
    {
      croak ("Problem in g->start_symbol(): %s", xs_g_error (g_wrapper));
    }
  if (id < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (id)));
}

void
default_value_set( g_wrapper, value )
    G_Wrapper *g_wrapper;
    int value;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_default_token_value_set (g, GINT_TO_POINTER (value));
  if (result < 0)
    {
      croak ("Problem in g->default_token_value_set(): %s", xs_g_error (g_wrapper));
    }
  XSRETURN_YES;
}

void
default_value( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gpointer value;
  gint result = marpa_g_default_token_value (g, &value);
  if (result < 0)
    {
      croak ("Problem in g->default_token_value(): %s",
	     xs_g_error (g_wrapper));
    }
  if (!value)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (GPOINTER_TO_INT (value))));
}

void
is_precomputed( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_is_precomputed (g);
  if (result < 0)
    {
      croak ("Problem in g->default_token_value(): %s",
	     xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
event( g_wrapper, ix )
    G_Wrapper *g_wrapper;
    int ix;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  struct marpa_event event;
  const char *result_string = NULL;
  Marpa_Event_Type result = marpa_g_event (g, &event, ix);
  if (result < 0)
    {
      croak ("Problem in g->event(): %s", xs_g_error (g_wrapper));
    }
  result_string = event_type_to_string (result);
  if (!result_string)
    {
      croak ("Problem in g->event(): unknown event %d", result);
    }
  XPUSHs (sv_2mortal (newSVpv (result_string, 0)));
  XPUSHs (sv_2mortal (newSViv (event.t_value)));
}

void
has_loop( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_has_loop (g);
  if (result < 0)
    {
      croak ("Problem in g->has_loop(): %s", xs_g_error (g_wrapper));
    }
  if (result) XSRETURN_YES;
  XSRETURN_NO;
}

void
is_lhs_terminal_ok_set( g_wrapper, boolean )
    G_Wrapper *g_wrapper;
    int boolean;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_is_lhs_terminal_ok_set (g, (boolean ? TRUE : FALSE));
  if (result < 0)
    {
      croak ("Problem in g->is_lhs_terminal_ok_set(): %s", xs_g_error (g_wrapper));
    }
  XSRETURN_YES;
}

void
is_lhs_terminal_ok( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_is_lhs_terminal_ok (g);
  if (result < 0)
    {
      croak ("Problem in g->is_lhs_terminal_ok(): %s",
	     xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

Marpa_Symbol_ID
symbol_new( g )
    Grammar *g;
CODE:
    RETVAL = marpa_g_symbol_new(g);
OUTPUT:
    RETVAL

void
symbol_lhs_rule_ids( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  int i;
  gint count = marpa_g_symbol_lhs_count (g, symbol_id);
  if (count < -1)
    {
      croak ("Problem in g->symbol_lhs_rule_ids: %s", xs_g_error (g_wrapper));
    }
  if (count == -1)
    {
      XSRETURN_UNDEF;
    }
  for (i = 0; i < count; i++)
    {
      Marpa_Rule_ID rule_id = marpa_g_symbol_lhs (g, symbol_id, i);
      if (rule_id < 0)
	{
	  croak ("Problem in g->symbol_lhs_rule_ids: %s",
		 xs_g_error (g_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (rule_id)));
    }
}

void
symbol_rhs_rule_ids( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  int i;
  gint count = marpa_g_symbol_rhs_count (g, symbol_id);
  if (count < -1)
    {
      croak ("Problem in g->symbol_rhs_rule_ids: %s", xs_g_error (g_wrapper));
    }
  if (count == -1)
    {
      XSRETURN_UNDEF;
    }
  for (i = 0; i < count; i++)
    {
      Marpa_Rule_ID rule_id = marpa_g_symbol_rhs (g, symbol_id, i);
      if (rule_id < 0)
	{
	  croak ("Problem in g->symbol_rhs_rule_ids: %s",
		 xs_g_error (g_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (rule_id)));
    }
}

void
symbol_is_accessible( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_symbol_is_accessible (g, symbol_id);
  if (result < 0)
    {
      croak ("Problem in g->symbol_is_accessible(): %s", xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
symbol_is_counted( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_symbol_is_counted (g, symbol_id);
  if (result < 0)
    {
      croak ("Problem in g->symbol_is_counted(): %s", xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
symbol_is_nullable( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_symbol_is_nullable (g, symbol_id);
  if (result < 0)
    {
      croak ("Problem in g->symbol_is_nullable(): %s",
	     xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
symbol_is_nulling( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_symbol_is_nulling (g, symbol_id);
  if (result < 0)
    {
      croak ("Problem in g->symbol_is_nulling(%d): %s", symbol_id,
	     xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
symbol_is_terminal_set( g_wrapper, symbol_id, boolean )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result =
    marpa_g_symbol_is_terminal_set (g, symbol_id, (boolean ? TRUE : FALSE));
  if (result < 0)
    {
      croak ("Problem in g->symbol_is_terminal_set(%d, %d): %s",
	     symbol_id, boolean, xs_g_error (g_wrapper));
    }
}

void
symbol_is_terminal( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  gint result = marpa_g_symbol_is_terminal (g, symbol_id);
  if (result < 0)
    {
      croak ("Problem in g->symbol_is_terminal(%d): %s",
	     symbol_id, xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
symbol_is_productive( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gint result = marpa_g_symbol_is_productive( g, symbol_id );
    if (result < 0) { croak("Invalid symbol %d", symbol_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
symbol_is_start( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gint result = marpa_g_symbol_is_start( g, symbol_id );
    if (result < 0) { croak("Invalid symbol %d", symbol_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

Marpa_Symbol_ID
symbol_null_alias( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  Marpa_Symbol_ID alias_id = marpa_g_symbol_null_alias (g, symbol_id);
  if (alias_id < -1)
    {
      croak ("problem with g->symbol_null_alias: %s", xs_g_error (g_wrapper));
    }
  if (alias_id < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (alias_id)));
}

Marpa_Symbol_ID
symbol_proper_alias( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  Marpa_Symbol_ID alias_id = marpa_g_symbol_proper_alias (g, symbol_id);
  if (alias_id < -1)
    {
      croak ("problem with g->symbol_proper_alias: %s", xs_g_error (g_wrapper));
    }
  if (alias_id < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (alias_id)));
}

Marpa_Rule_ID
symbol_virtual_lhs_rule( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  Marpa_Rule_ID rule_id = marpa_g_symbol_virtual_lhs_rule (g, symbol_id);
  if (rule_id < -1)
    {
      croak ("problem with g->symbol_virtual_lhs_rule: %s",
	     xs_g_error (g_wrapper));
    }
  if (rule_id < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (rule_id)));
}

 # Rules

Marpa_Rule_ID
rule_new( g, lhs, rhs_av )
    Grammar *g;
    Marpa_Symbol_ID lhs;
    AV *rhs_av;
PREINIT:
    int length;
    Marpa_Symbol_ID* rhs;
    Marpa_Rule_ID new_rule_id;
PPCODE:
    length = av_len(rhs_av)+1;
    if (length <= 0) {
        rhs = (Marpa_Symbol_ID*)NULL;
    } else {
	int i;
        Newx(rhs, length, Marpa_Symbol_ID);
	for (i = 0; i < length; i++) {
	    SV** elem = av_fetch(rhs_av, i, 0);
	    if (elem == NULL) {
		Safefree(rhs);
	        XSRETURN_UNDEF;
	    } else {
	        rhs[i] = SvIV(*elem);
	    }
	}
    }
    new_rule_id = marpa_g_rule_new(g, lhs, rhs, length);
    Safefree(rhs);
    if (new_rule_id < 0) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(new_rule_id) ) );

 # This function invalidates any current iteration on
 # the hash args.  This seesm to be the way things are
 # done in Perl -- in particular there seems to be no
 # easy way to  prevent that.
Marpa_Rule_ID
sequence_new( g, lhs, rhs, args )
    Grammar *g;
    Marpa_Symbol_ID lhs;
    Marpa_Symbol_ID rhs;
    HV *args;
PREINIT:
    Marpa_Rule_ID new_rule_id;
    Marpa_Symbol_ID separator = -1;
    gint min = 1;
    gint flags = 0;
PPCODE:
    if (args) {
	I32 retlen;
	char* key;
	SV* arg_value;
	hv_iterinit(args);
	while ((arg_value = hv_iternextsv (args, &key, &retlen)))
	  {
	    if ((*key == 'k') && strnEQ (key, "keep", (unsigned) retlen))
	      {
		if (SvTRUE (arg_value))
		  flags |= MARPA_KEEP_SEPARATION;
		continue;
	      }
	    if ((*key == 'm') && strnEQ (key, "min", (unsigned) retlen))
	      {
		gint raw_min = SvIV (arg_value);
		if (raw_min < 0)
		  {
		    croak ("sequence_new(): min cannot be less than 0");
		  }
		min = raw_min;
		continue;
	      }
	    if ((*key == 'p') && strnEQ (key, "proper", (unsigned) retlen))
	      {
		if (SvTRUE (arg_value))
		  flags |= MARPA_PROPER_SEPARATION;
		continue;
      }
    if ((*key == 's') && strnEQ (key, "separator", (unsigned) retlen))
      {
	separator = SvIV (arg_value);
	continue;
      }
    croak ("unknown argument to sequence_new(): %.*s", (int)retlen, key);
  }
    }
    new_rule_id = marpa_g_sequence_new(g, lhs, rhs, separator, min, flags );
    if (new_rule_id < 0) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(new_rule_id) ) );

Marpa_Symbol_ID
rule_lhs( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
    struct marpa_g* g = g_wrapper->g;
    int result = marpa_g_rule_lhs(g, rule_id);
    if (result < -1) { 
      croak ("Problem in g->rule_lhs(%d): %s", rule_id, xs_g_error (g_wrapper));
      }
    if (result < 0) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(result) ) );
}

Marpa_Symbol_ID
rule_rhs( g_wrapper, rule_id, ix )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
    int ix;
PPCODE:
{
    struct marpa_g* g = g_wrapper->g;
    int result = marpa_g_rule_rh_symbol(g, rule_id, ix);
    if (result < -1) { 
      croak ("Problem in g->rule_rhs(%d, %d): %s", rule_id, ix, xs_g_error (g_wrapper));
      }
    if (result < 0) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(result) ) );
}

int
rule_length( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  int result = marpa_g_rule_length (g, rule_id);
  if (result < -1)
    {
      croak ("Problem in g->rule_length(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
rule_is_accessible( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_is_accessible (g, rule_id);
  if (result < -1)
    {
      croak ("Problem in g->rule_is_accessible(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      croak ("Invalid rule %d", rule_id);
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
rule_is_productive( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_is_productive (g, rule_id);
  if (result < -1)
    {
      croak ("Problem in g->rule_is_productive(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      croak ("Invalid rule %d", rule_id);
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
rule_is_loop( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_is_loop (g, rule_id);
  if (result < -1)
    {
      croak ("Problem in g->rule_is_loop(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      croak ("Invalid rule %d", rule_id);
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
rule_is_virtual_loop( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_is_virtual_loop (g, rule_id);
  if (result < -1)
    {
      croak ("Problem in g->rule_is_virtual_loop(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      croak ("Invalid rule %d", rule_id);
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

int
rule_virtual_start( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  int result = marpa_g_virtual_start (g, rule_id);
  if (result <= -2)
    {
      croak ("Problem in g->rule_is_virtual_start(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
    XPUSHs( sv_2mortal( newSViv(result) ) );
}

int
rule_virtual_end( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  int result = marpa_g_virtual_end (g, rule_id);
  if (result <= -2)
    {
      croak ("Problem in g->rule_is_virtual_end(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
rule_is_used( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_is_used (g, rule_id);
  if (result < 0)
    {
      croak ("Problem in g->rule_is_used(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
rule_is_discard_separation( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_is_discard_separation (g, rule_id);
  if (result < 0)
    {
      croak ("Problem in g->rule_is_discard_separation(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
rule_is_virtual_lhs( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_is_virtual_lhs (g, rule_id);
  if (result < 0)
    {
      croak ("Problem in g->rule_is_virtual_lhs(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
rule_is_virtual_rhs( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_is_virtual_rhs (g, rule_id);
  if (result < 0)
    {
      croak ("Problem in g->rule_is_virtual_rhs(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

Marpa_Rule_ID
real_symbol_count( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_g_real_symbol_count(g, rule_id);
OUTPUT:
    RETVAL

Marpa_Rule_ID
rule_original( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_g_rule_original(g, rule_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

void
rule_ask_me_set( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_ask_me_set (g, rule_id);
  if (result <= -2)
    {
      croak ("Problem in g->rule_ask_me_set(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

Marpa_Rule_ID
semantic_equivalent( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_semantic_equivalent (g, rule_id);
  if (result <= -2)
    {
      croak ("Problem in g->semantic_equivalent(%d): %s", rule_id,
	     xs_g_error (g_wrapper));
    }
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
AHFA_item_count( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_AHFA_item_count (g);
  if (result <= -2)
    {
      croak ("Problem in g->AHFA_item_count(): %s", xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
rule_count( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint result = marpa_g_rule_count (g);
  if (result < -1)
    {
      croak ("Problem in g->rule_count(): %s", xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
symbol_count( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  gint count = marpa_g_symbol_count (g);
  if (count < -1)
    {
      croak ("Problem in g->symbol_count(): %s", xs_g_error (g_wrapper));
    }
  if (count < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (count)));
}

Marpa_Rule_ID
AHFA_item_rule( g, item_id )
    Grammar *g;
    Marpa_AHFA_Item_ID item_id;
CODE:
    RETVAL = marpa_g_AHFA_item_rule(g, item_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

 # -1 is a valid return value, so -2 indicates an error
int
AHFA_item_position( g, item_id )
    Grammar *g;
    Marpa_AHFA_Item_ID item_id;
CODE:
    RETVAL = marpa_g_AHFA_item_position(g, item_id);
    if (RETVAL <= -2) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

int
AHFA_item_sort_key( g, item_id )
    Grammar *g;
    Marpa_AHFA_Item_ID item_id;
CODE:
    RETVAL = marpa_g_AHFA_item_sort_key(g, item_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

 # -1 is a valid return value, and -2 indicates an error
Marpa_Symbol_ID
AHFA_item_postdot( g, item_id )
    Grammar *g;
    Marpa_AHFA_Item_ID item_id;
CODE:
    RETVAL = marpa_g_AHFA_item_postdot(g, item_id);
    if (RETVAL <= -2) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

int
AHFA_state_count( g )
    Grammar *g;
CODE:
    RETVAL = marpa_g_AHFA_state_count(g );
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

 # In scalar context, returns the count
void
AHFA_state_items( g, AHFA_state_id )
    Grammar *g;
    Marpa_AHFA_State_ID AHFA_state_id;
PPCODE:
    { gint count = marpa_g_AHFA_state_item_count(g, AHFA_state_id);
    if (count < 0) { croak("Invalid AHFA state %d", AHFA_state_id); }
    if (GIMME == G_ARRAY) {
        gint item_ix;
        EXTEND(SP, count);
        for (item_ix = 0; item_ix < count; item_ix++) {
	    Marpa_AHFA_Item_ID item_id
		= marpa_g_AHFA_state_item(g, AHFA_state_id, item_ix);
            PUSHs( sv_2mortal( newSViv(item_id) ) );
        }
    } else {
        XPUSHs( sv_2mortal( newSViv(count) ) );
    }
    }

 # In scalar context, returns the count
void
AHFA_state_transitions( g_wrapper, AHFA_state_id )
    G_Wrapper *g_wrapper;
    Marpa_AHFA_State_ID AHFA_state_id;
PPCODE:
{
  Grammar *g = g_wrapper->g;
  GArray *const gint_array = g_wrapper->gint_array;
  const gint result =
    marpa_g_AHFA_state_transitions (g, AHFA_state_id, gint_array);
  if (result < 0)
    {
      croak ("Problem in AHFA_state_transitions(): %s", xs_g_error (g_wrapper));
    }
  if (GIMME == G_ARRAY)
    {
      const gint count = gint_array->len;
      gint ix;
      for (ix = 0; ix < count; ix++)
	{
	  XPUSHs (sv_2mortal
		  (newSViv (g_array_index (gint_array, gint, ix))));
	}
    }
  else
    {
      XPUSHs (sv_2mortal (newSViv ((gint) gint_array->len)));
    }
}

 # -1 is a valid return value, and -2 indicates an error
Marpa_AHFA_State_ID
AHFA_state_empty_transition( g, AHFA_state_id )
    Grammar *g;
    Marpa_AHFA_State_ID AHFA_state_id;
CODE:
    RETVAL = marpa_g_AHFA_state_empty_transition(g, AHFA_state_id);
    if (RETVAL <= -2) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

void
AHFA_state_is_predict( g, AHFA_state_id )
    Grammar *g;
    Marpa_AHFA_State_ID AHFA_state_id;
PPCODE:
    { gint result = marpa_g_AHFA_state_is_predict( g, AHFA_state_id );
    if (result < 0) { croak("Invalid AHFA state %d", AHFA_state_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
AHFA_state_leo_lhs_symbol( g, AHFA_state_id )
    Grammar *g;
    Marpa_AHFA_State_ID AHFA_state_id;
PPCODE:
    { gint result = marpa_g_AHFA_state_leo_lhs_symbol( g, AHFA_state_id );
    if (result < -1) { croak("Invalid AHFA state %d", AHFA_state_id); }
    if (result == -1) XSRETURN_UNDEF;
    XPUSHs( sv_2mortal( newSViv(result) ) );
    }

void
error( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  struct marpa_g *g = g_wrapper->g;
  XPUSHs (sv_2mortal (newSVpv (xs_g_error (g_wrapper), 0)));
}

void
error_code( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  struct marpa_g* g = g_wrapper->g;
  const Marpa_Error_Code error_code = marpa_g_error (g, NULL);
  if (error_code < 0) {
	  XSRETURN_UNDEF;
  }
  XPUSHs (sv_2mortal (newSViv (error_code)));
}

void precompute( g )
    Grammar *g;
PPCODE:
    {
      gint result = marpa_g_precompute (g);
      if (result < 0) {
         XSRETURN_UNDEF;
      }
      XPUSHs (sv_2mortal (newSViv (result)));
    }

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Internal::R_C

void
new( class, g_wrapper )
    char * class;
    G_Wrapper *g_wrapper;
PPCODE:
{
    struct marpa_g* g = g_wrapper->g;
    SV *sv;
    R_Wrapper *r_wrapper;
    Marpa_Recce r;
    r = marpa_r_new(g);
    if (!r) { croak ("failure in marpa_r_new: %s", xs_g_error (g_wrapper)); };
    Newx( r_wrapper, 1, R_Wrapper );
    r_wrapper->r = r;
    r_wrapper->gint_array = g_array_new( FALSE, FALSE, sizeof(gint));
    r_wrapper->message_buffer = NULL;
    sv = sv_newmortal();
    sv_setref_pv(sv, recce_c_class_name, (void*)r_wrapper);
    XPUSHs(sv);
}

void
DESTROY( r_wrapper )
    R_Wrapper *r_wrapper;
PREINIT:
    struct marpa_r *r;
CODE:
    g_free(r_wrapper->message_buffer);
    r = r_wrapper->r;
    g_array_free(r_wrapper->gint_array, TRUE);
    marpa_r_unref( r );
    Safefree( r_wrapper );

void
error( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  XPUSHs (sv_2mortal (newSVpv (xs_r_error (r_wrapper), 0)));
}

void
error_code( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  const Marpa_Error_Code error_code = marpa_r_error (r, NULL);
  if (error_code < 0) {
	  XSRETURN_UNDEF;
  }
  XPUSHs (sv_2mortal (newSViv (error_code)));
}

Marpa_Earleme
current_earleme( r_wrapper )
    R_Wrapper *r_wrapper;
CODE:
    RETVAL = marpa_r_current_earleme(r_wrapper->r);
OUTPUT:
    RETVAL

Marpa_Earleme
furthest_earleme( r_wrapper )
    R_Wrapper *r_wrapper;
CODE:
    RETVAL = marpa_r_furthest_earleme(r_wrapper->r);
OUTPUT:
    RETVAL

void
is_use_leo_set( r_wrapper, boolean )
    R_Wrapper *r_wrapper;
    int boolean;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  gint result = marpa_r_is_use_leo_set (r, (boolean ? TRUE : FALSE));
  if (result < 0)
    {
      croak ("Problem in is_use_leo_set(): %s", xs_r_error (r_wrapper));
    }
  XSRETURN_YES;
}

void
is_use_leo( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  gint boolean = marpa_r_is_use_leo (r);
  if (boolean < 0)
    {
      croak ("Problem in is_use_leo(): %s", xs_r_error (r_wrapper));
    }
  if (boolean)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
is_exhausted( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  gint boolean = marpa_r_is_exhausted (r);
  if (boolean < 0)
    {
      croak ("Problem in is_exhausted(): %s", xs_r_error (r_wrapper));
    }
  if (boolean)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
start_input( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
    gint result = marpa_r_start_input(r_wrapper->r);
  if (result < 0)
    {
      croak ("Problem in r->start_input(): %s", xs_r_error (r_wrapper));
    }
    XSRETURN_YES;
}

 # current earleme on success -- return that directly
 # -1 means rejected because unexpected -- return undef
 # -3 means rejected as duplicate -- call croak
 # -2 means some other failure -- call croak
void
alternative( r_wrapper, symbol_id, value, length )
    R_Wrapper *r_wrapper;
    Marpa_Symbol_ID symbol_id;
    int value;
    int length;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      gint result =
	marpa_r_alternative (r, symbol_id, GINT_TO_POINTER(value), length);
      if (result == -1)
	{
	  XSRETURN_UNDEF;
	}
      if (result == -3)
	{
	  croak ("r->alternative(): Attempt to read same symbol twice at same location");
	  }
      if (result < 0)
	{
	  croak ("Invalid alternative: %s", xs_r_error (r_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (result)));
    }

void
earley_item_warning_threshold_set( r_wrapper, too_many_earley_items )
    R_Wrapper *r_wrapper;
    int too_many_earley_items;
PPCODE:
{
  gint result =
    marpa_r_earley_item_warning_threshold_set (r_wrapper->r,
					       too_many_earley_items);
      if (result < 0)
	{
	  croak ("Problem in r->earley_item_warning_threshold: %s", xs_r_error (r_wrapper));
	}
    XSRETURN_YES;
}

void
too_many_earley_items( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  gint too_many_earley_items =
    marpa_r_earley_item_warning_threshold (r_wrapper->r);
  XPUSHs (sv_2mortal (newSViv (too_many_earley_items)));
}

void
latest_earley_set( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      gint latest_earley_set = marpa_r_latest_earley_set(r);
      if (latest_earley_set < 0)
	{
      croak ("Problem with r->latest_earley_set(): %s",
		 xs_r_error(r_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (latest_earley_set)));
    }

void
earley_set_size( r_wrapper, set_ordinal )
    R_Wrapper *r_wrapper;
    Marpa_Earley_Set_ID set_ordinal;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      gint earley_set_size = marpa_r_earley_set_size (r, set_ordinal);
      if (earley_set_size < 0) {
	  croak ("Problem in r->earley_set_size(): %s", xs_r_error(r_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (earley_set_size)));
    }

void
earley_set_trace( r_wrapper, set_ordinal )
    R_Wrapper *r_wrapper;
    Marpa_Earley_Set_ID set_ordinal;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    Marpa_AHFA_State_ID result = marpa_r_earley_set_trace(
	r, set_ordinal );
    if (result == -1) { XSRETURN_UNDEF; }
    if (result < 0) { croak("problem with r->earley_set_trace: %s", xs_r_error(r_wrapper)); }
    XPUSHs( sv_2mortal( newSViv(result) ) );
    }

void
earley_item_trace( r_wrapper, item_ordinal )
    R_Wrapper *r_wrapper;
    Marpa_Earley_Item_ID item_ordinal;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    Marpa_AHFA_State_ID result = marpa_r_earley_item_trace(
	r, item_ordinal);
    if (result == -1) { XSRETURN_UNDEF; }
    if (result < 0) { croak("problem with r->earley_item_trace: %s", xs_r_error(r_wrapper)); }
    XPUSHs( sv_2mortal( newSViv(result) ) );
    }

void
earley_item_origin( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      gint origin_earleme = marpa_r_earley_item_origin (r);
      if (origin_earleme < 0)
	{
      croak ("Problem with r->earley_item_origin(): %s",
		 xs_r_error(r_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (origin_earleme)));
    }

void
first_token_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint token_id = marpa_r_first_token_link_trace(r);
    if (token_id <= -2) { croak("Trace first token link problem: %s", xs_r_error(r_wrapper)); }
    if (token_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(token_id) ) );
    }

void
next_token_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint token_id = marpa_r_next_token_link_trace(r);
    if (token_id <= -2) { croak("Trace next token link problem: %s", xs_r_error(r_wrapper)); }
    if (token_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(token_id) ) );
    }

void
first_completion_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint AHFA_state_id = marpa_r_first_completion_link_trace(r);
    if (AHFA_state_id <= -2) { croak("Trace first completion link problem: %s", xs_r_error(r_wrapper)); }
    if (AHFA_state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(AHFA_state_id) ) );
    }

void
next_completion_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint AHFA_state_id = marpa_r_next_completion_link_trace(r);
    if (AHFA_state_id <= -2) { croak("Trace next completion link problem: %s", xs_r_error(r_wrapper)); }
    if (AHFA_state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(AHFA_state_id) ) );
    }

void
first_leo_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint AHFA_state_id = marpa_r_first_leo_link_trace(r);
    if (AHFA_state_id <= -2) { croak("Trace first completion link problem: %s", xs_r_error(r_wrapper)); }
    if (AHFA_state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(AHFA_state_id) ) );
    }

void
next_leo_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint AHFA_state_id = marpa_r_next_leo_link_trace(r);
    if (AHFA_state_id <= -2) { croak("Trace next completion link problem: %s", xs_r_error(r_wrapper)); }
    if (AHFA_state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(AHFA_state_id) ) );
    }

void
source_predecessor_state( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint state_id = marpa_r_source_predecessor_state(r);
    if (state_id <= -2) { croak("Problem finding trace source predecessor state: %s", xs_r_error(r_wrapper)); }
    if (state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(state_id) ) );
    }

void
source_leo_transition_symbol( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint symbol_id = marpa_r_source_leo_transition_symbol(r);
    if (symbol_id <= -2) { croak("Problem finding trace source leo transition symbol: %s", xs_r_error(r_wrapper)); }
    if (symbol_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(symbol_id) ) );
    }

void
source_token( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gpointer value;
    gint symbol_id = marpa_r_source_token(r, &value);
    if (symbol_id == -1) { XSRETURN_UNDEF; }
    if (symbol_id < 0) { croak("Problem with r->source_token(): %s", xs_r_error(r_wrapper)); }
	XPUSHs( sv_2mortal( newSViv(symbol_id) ) );
	XPUSHs( sv_2mortal( newSViv(GPOINTER_TO_INT(value)) ) );
    }

void
source_middle( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint middle = marpa_r_source_middle(r);
    if (middle <= -2) { croak("Problem with r->source_middle(): %s", xs_r_error(r_wrapper)); }
    if (middle == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(middle) ) );
    }

void
first_postdot_item_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint postdot_symbol_id = marpa_r_first_postdot_item_trace(r);
    if (postdot_symbol_id <= -2) { croak("Trace first postdot item problem: %s", xs_r_error(r_wrapper)); }
    if (postdot_symbol_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(postdot_symbol_id) ) );
    }

void
next_postdot_item_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    gint postdot_symbol_id = marpa_r_next_postdot_item_trace(r);
    if (postdot_symbol_id <= -2) { croak("Trace next postdot item problem: %s", xs_r_error(r_wrapper)); }
    if (postdot_symbol_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(postdot_symbol_id) ) );
    }

void
postdot_symbol_trace( r_wrapper, symid )
    R_Wrapper *r_wrapper;
    Marpa_Symbol_ID symid;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  gint postdot_symbol_id = marpa_r_postdot_symbol_trace (r, symid);
  if (postdot_symbol_id == -1)
    {
      XSRETURN_UNDEF;
    }
  if (postdot_symbol_id <= 0)
    {
      croak ("Problem in r->postdot_symbol_trace: %s", xs_r_error (r_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (postdot_symbol_id)));
}

void
leo_base_state( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      gint leo_base_state = marpa_r_leo_base_state (r);
      if (leo_base_state == -1) { XSRETURN_UNDEF; }
      if (leo_base_state < 0) {
	  croak ("Problem in r->leo_base_state(): %s", xs_r_error(r_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (leo_base_state)));
    }

void
leo_base_origin( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      gint leo_base_origin = marpa_r_leo_base_origin (r);
      if (leo_base_origin == -1) { XSRETURN_UNDEF; }
      if (leo_base_origin < 0) {
	  croak ("Problem in r->leo_base_origin(): %s", xs_r_error(r_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (leo_base_origin)));
    }

void
leo_expansion_ahfa( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  gint leo_expansion_ahfa = marpa_r_leo_expansion_ahfa (r);
  if (leo_expansion_ahfa == -1)
    {
      XSRETURN_UNDEF;
    }
  if (leo_expansion_ahfa < 0)
    {
      croak ("Problem in r->leo_expansion_ahfa(): %s", xs_r_error (r_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (leo_expansion_ahfa)));
}

void
trace_earley_set( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      gint trace_earley_set = marpa_r_trace_earley_set (r);
      if (trace_earley_set < 0) {
	  croak ("Problem in r->trace_earley_set(): %s", xs_r_error(r_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (trace_earley_set)));
    }

void
postdot_item_symbol( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      gint postdot_item_symbol = marpa_r_postdot_item_symbol (r);
      if (postdot_item_symbol < 0) {
	  croak ("Problem in r->postdot_item_symbol(): %s", xs_r_error(r_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (postdot_item_symbol)));
    }

void
leo_predecessor_symbol( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      gint leo_predecessor_symbol = marpa_r_leo_predecessor_symbol (r);
      if (leo_predecessor_symbol == -1) { XSRETURN_UNDEF; }
      if (leo_predecessor_symbol < 0) {
	  croak ("Problem in r->leo_predecessor_symbol(): %s", xs_r_error(r_wrapper));
	}
      XPUSHs (sv_2mortal (newSViv (leo_predecessor_symbol)));
    }

void
terminals_expected( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
        GArray* terminal_ids = r_wrapper->gint_array;
        gint count = marpa_r_terminals_expected(r, terminal_ids);
	if (count < 0) {
	  croak ("Problem in r->terminals_expected(): %s", xs_r_error(r_wrapper));
	}
	if (GIMME == G_ARRAY) {
	    int i;
	    EXTEND(SP, count);
	    for (i = 0; i < count; i++) {
		PUSHs (sv_2mortal (newSViv (g_array_index (terminal_ids, gint, i))));
	    }
	} else {
	    XPUSHs( sv_2mortal( newSViv(count) ) );
	}
    }

void
earleme_complete( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
        Marpa_Earleme result = marpa_r_earleme_complete(r);
	if (result < 0) {
	  croak ("Problem in r->earleme_complete(): %s", xs_r_error(r_wrapper));
	}
	XPUSHs( sv_2mortal( newSViv(result) ) );
    }

void
event( r_wrapper, ix )
    R_Wrapper *r_wrapper;
    int ix;
PPCODE:
    {
      struct marpa_r * const r = r_wrapper->r;
      struct marpa_event event;
      const char *result_string = NULL;
      Marpa_Event_Type result = marpa_r_event (r, &event, ix);
      if (result < 0)
	{
	  croak ("Problem in r->earleme_event(): %s", xs_r_error(r_wrapper));
	}
	result_string = event_type_to_string(result);
      if (!result_string)
	{
	  croak ("Problem in r->earleme_event(): unknown event %d", result);
	}
      XPUSHs (sv_2mortal (newSVpv (result_string, 0)));
      XPUSHs (sv_2mortal (newSViv (event.t_value)));
    }

void
earleme( r_wrapper, ordinal )
     R_Wrapper *r_wrapper;
     Marpa_Earley_Set_ID ordinal;
PPCODE:
    { struct marpa_r* const r = r_wrapper->r;
	gint result = marpa_r_earleme(r, ordinal);
	if (result == -1) { XSRETURN_UNDEF; }
	if (result < 0) {
	  croak ("Problem in r->earleme(): %s", xs_r_error(r_wrapper));
	}
	XPUSHs( sv_2mortal( newSViv(result) ) );
    }

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Internal::B_C

void
new( class, r_wrapper, rule_id, ordinal )
    char * class;
    R_Wrapper *r_wrapper;
    Marpa_Rule_ID rule_id;
    Marpa_Earley_Set_ID ordinal;
PPCODE:
{
  SV *sv;
  Marpa_Recognizer r = r_wrapper->r;
  B_Wrapper *b_wrapper;
  Marpa_Bocage b = marpa_b_new (r, rule_id, ordinal);
  if (!b)
    {
      croak ("Problem in b->new(): %s", xs_r_error (r_wrapper));
    }
  Newx (b_wrapper, 1, B_Wrapper);
  b_wrapper->message_buffer = NULL;
  b_wrapper->b = b;
  sv = sv_newmortal ();
  sv_setref_pv (sv, bocage_c_class_name, (void *) b_wrapper);
  XPUSHs (sv);
}

void
DESTROY( b_wrapper )
    B_Wrapper *b_wrapper;
PPCODE:
{
    const Marpa_Bocage b = b_wrapper->b;
    marpa_b_unref(b);
    g_free(b_wrapper->message_buffer);
    Safefree( b_wrapper );
}

void
top_or_node( b_wrapper )
     B_Wrapper *b_wrapper;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_top_or_node (b);
  if (result < 0)
    {
      croak ("Problem in b->top_or_node(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
or_node_set( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_Or_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_or_node_set (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->or_node_set(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
or_node_origin( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_Or_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_or_node_origin (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->or_node_origin(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
or_node_position( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_Or_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_or_node_position (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->or_node_position(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
or_node_rule( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_Or_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_or_node_rule (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->or_node_rule(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
or_node_first_and( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_Or_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_or_node_first_and (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->or_node_first_and(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
or_node_last_and( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_Or_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_or_node_last_and (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->or_node_last_and(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
or_node_and_count( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_Or_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_or_node_and_count (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->or_node_and_count(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
and_node_count( b_wrapper )
     B_Wrapper *b_wrapper;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_and_node_count (b);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->and_node_count(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
and_node_parent( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_And_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_and_node_parent (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->and_node_parent(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
and_node_predecessor( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_And_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_and_node_predecessor (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->and_node_predecessor(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
and_node_cause( b_wrapper, ordinal )
     B_Wrapper *b_wrapper;
     Marpa_And_Node_ID ordinal;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_and_node_cause (b, ordinal);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->and_node_cause(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
and_node_symbol( b_wrapper, and_node_id )
     B_Wrapper *b_wrapper;
     Marpa_And_Node_ID and_node_id;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gint result = marpa_b_and_node_symbol (b, and_node_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->and_node_symbol(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
and_node_token( b_wrapper, and_node_id )
     B_Wrapper *b_wrapper;
     Marpa_And_Node_ID and_node_id;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  gpointer value = NULL;
  gint result = marpa_b_and_node_token (b, and_node_id, &value);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->and_node_symbol(): %s", xs_b_error (b_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
  XPUSHs (sv_2mortal (newSViv (GPOINTER_TO_INT (value))));
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Internal::O_C

void
new( class, b_wrapper )
    char * class;
    B_Wrapper *b_wrapper;
PPCODE:
{
  SV *sv;
  Marpa_Bocage b = b_wrapper->b;
  O_Wrapper *o_wrapper;
  Marpa_Order o = marpa_o_new (b);
  if (!o)
    {
      croak ("Problem in o->new(): %s", xs_b_error (b_wrapper));
    }
  Newx (o_wrapper, 1, O_Wrapper);
  o_wrapper->message_buffer = NULL;
  o_wrapper->o = o;
  sv = sv_newmortal ();
  sv_setref_pv (sv, order_c_class_name, (void *) o_wrapper);
  XPUSHs (sv);
}

void
DESTROY( o_wrapper )
    O_Wrapper *o_wrapper;
PPCODE:
{
    const Marpa_Order o = o_wrapper->o;
    marpa_o_unref(o);
    g_free(o_wrapper->message_buffer);
    Safefree( o_wrapper );
}

int
and_node_order_set( o_wrapper, or_node_id, and_node_id_av )
    O_Wrapper *o_wrapper;
    Marpa_Or_Node_ID or_node_id;
    AV *and_node_id_av;
PPCODE:
{
  Marpa_Order o = o_wrapper->o;
  int length = av_len (and_node_id_av) + 1;
  int result;
  Marpa_And_Node_ID *and_node_ids;
  int i;
  Newx (and_node_ids, length, Marpa_And_Node_ID);
  for (i = 0; i < length; i++)
    {
      SV **elem = av_fetch (and_node_id_av, i, 0);
      if (elem == NULL)
	{
	  Safefree (and_node_ids);
	  XSRETURN_UNDEF;
	}
      else
	{
	  and_node_ids[i] = SvIV (*elem);
	}
    }
  result = marpa_o_and_order_set (o, or_node_id, and_node_ids, length);
  Safefree (and_node_ids);
  if (result < 0)
    {
      XSRETURN_NO;
    }
  XSRETURN_YES;
}

int
and_node_order_get( o_wrapper, or_node_id, and_ix )
    O_Wrapper *o_wrapper;
    Marpa_Or_Node_ID or_node_id;
    int and_ix;
PPCODE:
{
    Marpa_Order o = o_wrapper->o;
    int result;
    result = marpa_o_and_order_get(o, or_node_id, and_ix);
    if (result == -1) { XSRETURN_UNDEF; }
    if (result < 0) {
      croak ("Problem in o->and_node_order_get(): %s", xs_o_error(o_wrapper));
    }
    XPUSHs( sv_2mortal( newSViv(result) ) );
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Internal::T_C

void
new( class, o_wrapper )
    char * class;
    O_Wrapper *o_wrapper;
PPCODE:
{
  SV *sv;
  Marpa_Order o = o_wrapper->o;
  T_Wrapper *t_wrapper;
  Marpa_Tree t = marpa_t_new (o);
  if (!t)
    {
      croak ("Problem in t->new(): %s", xs_o_error (o_wrapper));
    }
  Newx (t_wrapper, 1, T_Wrapper);
  t_wrapper->message_buffer = NULL;
  t_wrapper->t = t;
  sv = sv_newmortal ();
  sv_setref_pv (sv, tree_c_class_name, (void *) t_wrapper);
  XPUSHs (sv);
}

void
DESTROY( t_wrapper )
    T_Wrapper *t_wrapper;
PPCODE:
{
    const Marpa_Tree t = t_wrapper->t;
    marpa_t_unref(t);
    g_free(t_wrapper->message_buffer);
    Safefree( t_wrapper );
}

void
next( t_wrapper )
    T_Wrapper *t_wrapper;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_next (t);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->next(): %s", xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
parse_count( t_wrapper )
    T_Wrapper *t_wrapper;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_parse_count (t);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->parse_count(): %s", xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
size( t_wrapper )
    T_Wrapper *t_wrapper;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_size (t);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->size(): %s", xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
nook_or_node( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_nook_or_node (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->nook_or_node(): %s", xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
nook_choice( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_nook_choice (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->nook_choice(): %s", xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
nook_parent( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_nook_parent (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->nook_parent(): %s", xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
nook_is_cause( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_nook_is_cause (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->nook_is_cause(): %s", xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
nook_cause_is_ready( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_nook_cause_is_ready (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->nook_cause_is_ready(): %s", xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}


int
nook_is_predecessor( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_nook_is_predecessor (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->nook_is_predecessor(): %s", xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

int
nook_predecessor_is_ready( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = marpa_t_nook_predecessor_is_ready (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->nook_predecessor_is_ready(): %s",
	     xs_t_error (t_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

MODULE = Marpa::R2        PACKAGE = Marpa::R2::Internal::V_C

void
new( class, t_wrapper )
    char * class;
    T_Wrapper *t_wrapper;
PPCODE:
{
  SV *sv;
  Marpa_Tree t = t_wrapper->t;
  V_Wrapper *v_wrapper;
  Marpa_Value v = marpa_v_new (t);
  if (!v)
    {
      croak ("Problem in v->new(): %s", xs_t_error (t_wrapper));
    }
  Newx (v_wrapper, 1, V_Wrapper);
  v_wrapper->message_buffer = NULL;
  v_wrapper->v = v;
  sv = sv_newmortal ();
  sv_setref_pv (sv, value_c_class_name, (void *) v_wrapper);
  XPUSHs (sv);
}

void
DESTROY( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
    const Marpa_Value v = v_wrapper->v;
    marpa_v_unref(v);
    g_free(v_wrapper->message_buffer);
    Safefree( v_wrapper );
}

void
step( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
  const Marpa_Value v = v_wrapper->v;
  int status;
  SV *sv;
  Marpa_Step step;
  status = marpa_v_step (v, &step);
  if (status == -1)
    {
      XSRETURN_UNDEF;
    }
  if (status < 0)
    {
      croak ("Problem in v->step(): %s", xs_v_error (v_wrapper));
    }
  if (step.marpa_token_id < 0)
    {
      XPUSHs (&PL_sv_undef);
      XPUSHs (&PL_sv_undef);
    }
  else
    {
      XPUSHs (sv_2mortal (newSViv (step.marpa_token_id)));
      XPUSHs (sv_2mortal (newSViv (GPOINTER_TO_INT (step.marpa_value))));
    }
  sv =
    step.marpa_rule_id <
    0 ? &PL_sv_undef : sv_2mortal (newSViv (step.marpa_rule_id));
  XPUSHs (sv);
  XPUSHs (sv_2mortal (newSViv (step.marpa_arg_0)));
  XPUSHs (sv_2mortal (newSViv (step.marpa_arg_n)));
}

void
trace( v_wrapper, flag )
    V_Wrapper *v_wrapper;
    int flag;
PPCODE:
{
  const Marpa_Value v = v_wrapper->v;
  int status;
  status = marpa_v_trace (v, flag);
  if (status == -1)
    {
      XSRETURN_UNDEF;
    }
  if (status < 0)
    {
      croak ("Problem in v->trace(): %s", xs_v_error (v_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (status)));
}

void
nook( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
  const Marpa_Value v = v_wrapper->v;
  int status;
  status = marpa_v_nook (v);
  if (status == -1)
    {
      XSRETURN_UNDEF;
    }
  if (status < 0)
    {
      croak ("Problem in v->nook(): %s", xs_v_error (v_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (status)));
}

BOOT:
    gperl_handle_logs_for(G_LOG_DOMAIN);
