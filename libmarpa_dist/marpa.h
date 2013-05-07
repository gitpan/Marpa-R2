/*1353:*/
#line 15675 "./marpa.w"

/*1349:*/
#line 15647 "./marpa.w"

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

/*:1349*/
#line 15676 "./marpa.w"


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
#line 974 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:105*//*271:*/
#line 2398 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:271*//*275:*/
#line 2438 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:275*//*1139:*/
#line 13122 "./marpa.w"

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

/*:1139*/
#line 576 "./marpa.w"

/*42:*/
#line 612 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:42*//*596:*/
#line 6464 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:596*//*1011:*/
#line 11641 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:1011*//*1053:*/
#line 12068 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:1053*//*1054:*/
#line 12071 "./marpa.w"

typedef Marpa_Order ORDER;
/*:1054*//*1086:*/
#line 12499 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1086*//*1134:*/
#line 13079 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1134*/
#line 577 "./marpa.w"

/*87:*/
#line 879 "./marpa.w"

typedef int Marpa_Rank;
/*:87*//*104:*/
#line 971 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:104*//*128:*/
#line 1149 "./marpa.w"

typedef int Marpa_Error_Code;
/*:128*//*135:*/
#line 1187 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:135*//*195:*/
#line 1623 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:195*//*229:*/
#line 1863 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:229*//*301:*/
#line 2586 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:301*//*432:*/
#line 4471 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:432*//*472:*/
#line 4824 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:472*//*658:*/
#line 6946 "./marpa.w"
typedef int Marpa_Earleme;
/*:658*//*660:*/
#line 6950 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:660*//*690:*/
#line 7234 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:690*//*919:*/
#line 10320 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:919*//*979:*/
#line 11195 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:979*//*1120:*/
#line 12940 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1120*//*1175:*/
#line 13495 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1175*//*1324:*/
#line 15347 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1324*/
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
#line 977 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:106*//*999:*/
#line 11396 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:999*//*1138:*/
#line 13109 "./marpa.w"

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
/*:1138*/
#line 579 "./marpa.w"

/*1330:*/
#line 15399 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1330*//*1332:*/
#line 15407 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1332*/
#line 580 "./marpa.w"


/*:37*/
#line 15682 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1353*/
