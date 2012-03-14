/*1184:*/
#line 13283 "./marpa.w"

/*
 * Copyright 2012 Jeffrey Kegler
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
/*
 * DO NOT EDIT DIRECTLY
 * This file is written by ctangle
 * It is not intended to be modified directly
 */

/*:1184*//*1185:*/
#line 13307 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
#include "marpa_config.h"

/*37:*/
#line 583 "./marpa.w"

GLIB_VAR const guint marpa_major_version;
GLIB_VAR const guint marpa_minor_version;
GLIB_VAR const guint marpa_micro_version;
GLIB_VAR const guint marpa_interface_age;
GLIB_VAR const guint marpa_binary_age;
#define MARPA_CHECK_VERSION(major,minor,micro)  \
     (MARPA_MAJOR_VERSION >  (major) \
         || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION >  (minor)) \
         || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION == (minor) \
          && MARPA_MICRO_VERSION >= (micro)))

#define MARPA_CAT(a, b)  a ## b 
/*210:*/
#line 1965 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:210*//*214:*/
#line 2003 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:214*//*1032:*/
#line 11467 "./marpa.w"

#define marpa_v_semantic_token(v) \
    (((const struct marpa_value*)v)->t_semantic_token_id)
#define marpa_v_token_value(v) \
    (((const struct marpa_value*)v)->t_token_value)
#define marpa_v_semantic_rule(v) \
    (((const struct marpa_value*)v)->t_semantic_rule_id)
#define marpa_v_arg_0(v) \
    (((const struct marpa_value*)v)->t_tos)
#define marpa_v_arg_n(v) \
    (((const struct marpa_value*)v)->t_arg_n)

/*:1032*/
#line 596 "./marpa.w"

/*38:*/
#line 602 "./marpa.w"

struct marpa_g;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*509:*/
#line 5246 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:509*//*911:*/
#line 10042 "./marpa.w"

struct s_bocage;
typedef struct s_bocage*Marpa_Bocage;
/*:911*//*957:*/
#line 10518 "./marpa.w"

struct s_order;
typedef struct s_order*Marpa_Order;
/*:957*//*958:*/
#line 10521 "./marpa.w"

typedef Marpa_Order ORDER;
/*:958*//*981:*/
#line 10839 "./marpa.w"

struct s_tree;
typedef struct s_tree*Marpa_Tree;
/*:981*//*1028:*/
#line 11415 "./marpa.w"

struct s_value;
typedef struct s_value*Marpa_Value;
/*:1028*/
#line 597 "./marpa.w"

/*95:*/
#line 909 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef gint Marpa_Event_Type;
/*:95*//*110:*/
#line 1041 "./marpa.w"

typedef gint Marpa_Error_Code;
/*:110*//*116:*/
#line 1075 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:116*//*171:*/
#line 1490 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:171*//*361:*/
#line 3492 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:361*//*400:*/
#line 3860 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:400*//*580:*/
#line 5680 "./marpa.w"
typedef gint Marpa_Earleme;
/*:580*//*582:*/
#line 5684 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:582*//*607:*/
#line 5889 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:607*//*835:*/
#line 8925 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:835*//*895:*/
#line 9863 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:895*//*1014:*/
#line 11277 "./marpa.w"

typedef gint Marpa_Nook_ID;
/*:1014*//*1046:*/
#line 11634 "./marpa.w"

typedef gint Marpa_Value_Type;
/*:1046*//*1167:*/
#line 13059 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1167*/
#line 598 "./marpa.w"

/*96:*/
#line 913 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
gint t_value;
};
/*:96*//*1030:*/
#line 11442 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
gpointer t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
gint t_tos;
gint t_arg_n;
};
/*:1030*/
#line 599 "./marpa.w"


/*:37*/
#line 13314 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1185*/
