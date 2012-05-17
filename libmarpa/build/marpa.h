/*1235:*/
#line 14117 "./marpa.w"

/*1231:*/
#line 14089 "./marpa.w"

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

/*:1231*/
#line 14118 "./marpa.w"


#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "marpa_config.h"

/*37:*/
#line 575 "./marpa.w"

extern const unsigned int marpa_major_version;
extern const unsigned int marpa_minor_version;
extern const unsigned int marpa_micro_version;
extern const unsigned int marpa_interface_age;
extern const unsigned int marpa_binary_age;
#define MARPA_CHECK_VERSION(major,minor,micro)  \
     (MARPA_MAJOR_VERSION >  (major) \
         || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION >  (minor)) \
         || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION == (minor) \
          && MARPA_MICRO_VERSION >= (micro)))

/*231:*/
#line 2025 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:231*//*235:*/
#line 2064 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:235*//*1050:*/
#line 11941 "./marpa.w"

#define marpa_v_semantic_token(v) \
    ((v)->t_semantic_token_id)
#define marpa_v_token_value(v) \
    ((v)->t_token_value)
#define marpa_v_semantic_rule(v) \
    ((v)->t_semantic_rule_id)
#define marpa_v_arg_0(v) \
    ((v)->t_tos)
#define marpa_v_arg_n(v) \
    ((v)->t_arg_n)
/*:1050*/
#line 587 "./marpa.w"

/*38:*/
#line 594 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*532:*/
#line 5790 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:532*//*921:*/
#line 10514 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:921*//*967:*/
#line 10964 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:967*//*968:*/
#line 10967 "./marpa.w"

typedef Marpa_Order ORDER;
/*:968*//*993:*/
#line 11293 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:993*//*1045:*/
#line 11904 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1045*/
#line 588 "./marpa.w"

/*93:*/
#line 904 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:93*//*112:*/
#line 1050 "./marpa.w"

typedef int Marpa_Error_Code;
/*:112*//*118:*/
#line 1080 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:118*//*167:*/
#line 1401 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:167*//*196:*/
#line 1600 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:196*//*261:*/
#line 2248 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:261*//*379:*/
#line 3987 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:379*//*419:*/
#line 4340 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:419*//*590:*/
#line 6168 "./marpa.w"
typedef int Marpa_Earleme;
/*:590*//*592:*/
#line 6172 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:592*//*616:*/
#line 6366 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:616*//*845:*/
#line 9415 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:845*//*905:*/
#line 10326 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:905*//*1031:*/
#line 11766 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1031*//*1080:*/
#line 12223 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1080*//*1206:*/
#line 13798 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1206*/
#line 589 "./marpa.w"

/*94:*/
#line 908 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:94*//*1049:*/
#line 11933 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1049*/
#line 590 "./marpa.w"

/*1212:*/
#line 13850 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1212*//*1214:*/
#line 13858 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1214*/
#line 591 "./marpa.w"


/*:37*/
#line 14124 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1235*/
