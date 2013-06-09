/*1374:*/
#line 16268 "./marpa.w"

/*1370:*/
#line 16240 "./marpa.w"

/*
 * Copyright 2013 Jeffrey Kegler
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

/*:1370*/
#line 16269 "./marpa.w"


#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "marpa_config.h"

/*37:*/
#line 564 "./marpa.w"

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

/*105:*/
#line 980 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:105*//*280:*/
#line 2479 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:280*//*284:*/
#line 2519 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:284*//*1150:*/
#line 13525 "./marpa.w"

#define marpa_v_step_type(v) ((v)->t_step_type)
#define marpa_v_token(v) \
    ((v)->t_token_id)
#define marpa_v_symbol(v) marpa_v_token(v)
#define marpa_v_token_value(v) \
    ((v)->t_token_value)
#define marpa_v_rule(v) \
    ((v)->t_rule_id)
#define marpa_v_arg_0(v) \
    ((v)->t_arg_0)
#define marpa_v_arg_n(v) \
    ((v)->t_arg_n)
#define marpa_v_result(v) \
    ((v)->t_result)
#define marpa_v_rule_start_es_id(v) ((v)->t_rule_start_es_id)
#define marpa_v_token_start_es_id(v) ((v)->t_token_start_es_id)
#define marpa_v_es_id(v) ((v)->t_es_id)

/*:1150*/
#line 576 "./marpa.w"

/*42:*/
#line 612 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:42*//*606:*/
#line 6671 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:606*//*1022:*/
#line 12044 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:1022*//*1064:*/
#line 12471 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:1064*//*1065:*/
#line 12474 "./marpa.w"

typedef Marpa_Order ORDER;
/*:1065*//*1097:*/
#line 12902 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1097*//*1145:*/
#line 13482 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1145*/
#line 577 "./marpa.w"

/*87:*/
#line 879 "./marpa.w"

typedef int Marpa_Rank;
/*:87*//*104:*/
#line 977 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:104*//*128:*/
#line 1155 "./marpa.w"

typedef int Marpa_Error_Code;
/*:128*//*135:*/
#line 1193 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:135*//*206:*/
#line 1720 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:206*//*238:*/
#line 1944 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:238*//*310:*/
#line 2667 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:310*//*434:*/
#line 4572 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:434*//*475:*/
#line 4947 "./marpa.w"

typedef int Marpa_AHFA_State_ID;
/*:475*//*672:*/
#line 7246 "./marpa.w"
typedef int Marpa_Earleme;
/*:672*//*674:*/
#line 7250 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:674*//*704:*/
#line 7534 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:704*//*930:*/
#line 10723 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:930*//*990:*/
#line 11598 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:990*//*1131:*/
#line 13343 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1131*//*1186:*/
#line 13898 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1186*//*1345:*/
#line 15940 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1345*/
#line 578 "./marpa.w"

/*39:*/
#line 583 "./marpa.w"

struct marpa_config{
int t_is_ok;
Marpa_Error_Code t_error;
const char*t_error_string;
};
typedef struct marpa_config Marpa_Config;

/*:39*//*106:*/
#line 983 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:106*//*1010:*/
#line 11799 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:1010*//*1149:*/
#line 13512 "./marpa.w"

struct marpa_value{
Marpa_Step_Type t_step_type;
Marpa_Symbol_ID t_token_id;
int t_token_value;
Marpa_Rule_ID t_rule_id;
int t_arg_0;
int t_arg_n;
int t_result;
Marpa_Earley_Set_ID t_token_start_es_id;
Marpa_Earley_Set_ID t_rule_start_es_id;
Marpa_Earley_Set_ID t_es_id;
};
/*:1149*/
#line 579 "./marpa.w"

/*1351:*/
#line 15992 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1351*//*1353:*/
#line 16000 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1353*/
#line 580 "./marpa.w"


/*:37*/
#line 16275 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1374*/
