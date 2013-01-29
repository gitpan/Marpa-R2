/*1294:*/
#line 14980 "./marpa.w"

/*1290:*/
#line 14952 "./marpa.w"

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

/*:1290*/
#line 14981 "./marpa.w"


#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "marpa_config.h"

/*36:*/
#line 553 "./marpa.w"

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

/*102:*/
#line 955 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:102*//*259:*/
#line 2318 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:259*//*263:*/
#line 2358 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:263*//*1099:*/
#line 12659 "./marpa.w"

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
#define marpa_v_result(v) marpa_v_arg_0(v)
#define marpa_v_rule_start_es_id(v) ((v)->t_rule_start_es_id)
#define marpa_v_token_start_es_id(v) ((v)->t_token_start_es_id)
#define marpa_v_es_id(v) ((v)->t_es_id)

/*:1099*/
#line 565 "./marpa.w"

/*41:*/
#line 601 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:41*//*564:*/
#line 6137 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:564*//*970:*/
#line 11162 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:970*//*1012:*/
#line 11589 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:1012*//*1013:*/
#line 11592 "./marpa.w"

typedef Marpa_Order ORDER;
/*:1013*//*1046:*/
#line 12037 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1046*//*1094:*/
#line 12617 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1094*/
#line 566 "./marpa.w"

/*86:*/
#line 869 "./marpa.w"

typedef int Marpa_Rank;
/*:86*//*101:*/
#line 952 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:101*//*122:*/
#line 1113 "./marpa.w"

typedef int Marpa_Error_Code;
/*:122*//*129:*/
#line 1151 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:129*//*185:*/
#line 1560 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:185*//*217:*/
#line 1783 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:217*//*289:*/
#line 2506 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:289*//*411:*/
#line 4343 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:411*//*451:*/
#line 4696 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:451*//*620:*/
#line 6543 "./marpa.w"
typedef int Marpa_Earleme;
/*:620*//*622:*/
#line 6547 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:622*//*650:*/
#line 6785 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:650*//*879:*/
#line 9855 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:879*//*939:*/
#line 10729 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:939*//*1080:*/
#line 12478 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1080*//*1134:*/
#line 12996 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1134*//*1265:*/
#line 14652 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1265*/
#line 567 "./marpa.w"

/*38:*/
#line 572 "./marpa.w"

struct marpa_config{
int t_is_ok;
Marpa_Error_Code t_error;
const char*t_error_string;
};
typedef struct marpa_config Marpa_Config;

/*:38*//*103:*/
#line 958 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:103*//*959:*/
#line 10930 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:959*//*1098:*/
#line 12647 "./marpa.w"

struct marpa_value{
Marpa_Step_Type t_step_type;
Marpa_Symbol_ID t_token_id;
int t_token_value;
Marpa_Rule_ID t_rule_id;
int t_arg_0;
int t_arg_n;
Marpa_Earley_Set_ID t_token_start_es_id;
Marpa_Earley_Set_ID t_rule_start_es_id;
Marpa_Earley_Set_ID t_es_id;
};
/*:1098*/
#line 568 "./marpa.w"

/*1271:*/
#line 14704 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1271*//*1273:*/
#line 14712 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1273*/
#line 569 "./marpa.w"


/*:36*/
#line 14987 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1294*/
