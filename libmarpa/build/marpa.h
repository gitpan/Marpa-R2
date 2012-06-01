/*1251:*/
#line 14273 "./marpa.w"

/*1247:*/
#line 14245 "./marpa.w"

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

/*:1247*/
#line 14274 "./marpa.w"


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

/*93:*/
#line 900 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:93*//*231:*/
#line 2020 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:231*//*235:*/
#line 2059 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:235*//*590:*/
#line 6168 "./marpa.w"

#define marpa_r_event_value(event) \
    ((event)->t_value)
/*:590*//*934:*/
#line 10490 "./marpa.w"

#define marpa_r_progress_item_rule(item) \
    ((item)->t_rule_id)
#define marpa_r_progress_item_position(item) \
    ((item)->t_position)
#define marpa_r_progress_item_origin(item) \
    ((item)->t_origin)

/*:934*//*1069:*/
#line 12114 "./marpa.w"

#define marpa_v_token(v) \
    ((v)->t_token_id)
#define marpa_v_symbol(v) marpa_v_token(v)
#define marpa_v_token_value(v) \
    ((v)->t_token_value)
#define marpa_v_rule(v) \
    ((v)->t_rule_id)
#define marpa_v_arg_0(v) \
    ((v)->t_tos)
#define marpa_v_arg_n(v) \
    ((v)->t_arg_n)
#define marpa_v_result(v) marpa_v_arg_0(v)
/*:1069*/
#line 587 "./marpa.w"

/*38:*/
#line 594 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*536:*/
#line 5818 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:536*//*943:*/
#line 10704 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:943*//*986:*/
#line 11137 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:986*//*987:*/
#line 11140 "./marpa.w"

typedef Marpa_Order ORDER;
/*:987*//*1012:*/
#line 11466 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1012*//*1064:*/
#line 12077 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1064*/
#line 588 "./marpa.w"

/*92:*/
#line 897 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:92*//*112:*/
#line 1046 "./marpa.w"

typedef int Marpa_Error_Code;
/*:112*//*118:*/
#line 1076 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:118*//*167:*/
#line 1396 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:167*//*196:*/
#line 1595 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:196*//*265:*/
#line 2270 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:265*//*383:*/
#line 4024 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:383*//*423:*/
#line 4377 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:423*//*595:*/
#line 6202 "./marpa.w"
typedef int Marpa_Earleme;
/*:595*//*597:*/
#line 6206 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:597*//*621:*/
#line 6400 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:621*//*851:*/
#line 9397 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:851*//*911:*/
#line 10271 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:911*//*1050:*/
#line 11939 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1050*//*1099:*/
#line 12403 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1099*//*1222:*/
#line 13945 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1222*/
#line 589 "./marpa.w"

/*94:*/
#line 903 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:94*//*931:*/
#line 10472 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};
typedef const struct marpa_progress_item*Marpa_Progress_Item;

/*:931*//*1068:*/
#line 12106 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_token_id;
int t_token_value;
Marpa_Rule_ID t_rule_id;
int t_tos;
int t_arg_n;
};
/*:1068*/
#line 590 "./marpa.w"

/*1228:*/
#line 13997 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1228*//*1230:*/
#line 14005 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1230*/
#line 591 "./marpa.w"


/*:37*/
#line 14280 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1251*/
