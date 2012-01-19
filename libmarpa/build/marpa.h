/*1188:*/
#line 13245 "./marpa.w"

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

/*:1188*//*1189:*/
#line 13269 "./marpa.w"

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
/*212:*/
#line 1956 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:212*//*216:*/
#line 1994 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:216*/
#line 596 "./marpa.w"

/*38:*/
#line 602 "./marpa.w"

struct marpa_g;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*513:*/
#line 5262 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:513*//*915:*/
#line 10048 "./marpa.w"

struct s_bocage;
typedef struct s_bocage*Marpa_Bocage;
/*:915*//*961:*/
#line 10528 "./marpa.w"

struct s_order;
typedef struct s_order*Marpa_Order;
/*:961*//*962:*/
#line 10531 "./marpa.w"

typedef Marpa_Order ORDER;
/*:962*//*985:*/
#line 10852 "./marpa.w"

struct s_tree;
typedef struct s_tree*Marpa_Tree;
/*:985*//*1035:*/
#line 11451 "./marpa.w"

struct s_value;
typedef struct s_value*Marpa_Value;
/*:1035*/
#line 597 "./marpa.w"

/*99:*/
#line 937 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef gint Marpa_Event_Type;
/*:99*//*114:*/
#line 1069 "./marpa.w"

typedef gint Marpa_Error_Code;
/*:114*//*120:*/
#line 1103 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:120*//*173:*/
#line 1481 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:173*//*363:*/
#line 3483 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:363*//*402:*/
#line 3851 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:402*//*584:*/
#line 5699 "./marpa.w"
typedef gint Marpa_Earleme;
/*:584*//*586:*/
#line 5703 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:586*//*611:*/
#line 5908 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:611*//*839:*/
#line 8944 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:839*//*899:*/
#line 9873 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:899*//*1018:*/
#line 11294 "./marpa.w"

typedef gint Marpa_Nook_ID;
/*:1018*//*1171:*/
#line 13021 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1171*/
#line 598 "./marpa.w"

/*100:*/
#line 941 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
gint t_value;
};
/*:100*//*1032:*/
#line 11421 "./marpa.w"

struct marpa_step{
Marpa_Symbol_ID marpa_token_id;
gpointer marpa_value;
Marpa_Rule_ID marpa_rule_id;
gint marpa_arg_0;
gint marpa_arg_n;
};
typedef struct marpa_step Marpa_Step;
/*:1032*/
#line 599 "./marpa.w"


/*:37*/
#line 13276 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1189*/
