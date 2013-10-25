/*1395:*/
#line 16527 "./marpa.w"

/*1391:*/
#line 16499 "./marpa.w"

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

/*:1391*/
#line 16528 "./marpa.w"


#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "marpa_config.h"

/*37:*/
#line 585 "./marpa.w"

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
#line 1001 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:105*//*281:*/
#line 2515 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:281*//*285:*/
#line 2555 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:285*//*1171:*/
#line 13784 "./marpa.w"

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

/*:1171*/
#line 597 "./marpa.w"

/*42:*/
#line 633 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:42*//*612:*/
#line 6774 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:612*//*1045:*/
#line 12377 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:1045*//*1082:*/
#line 12706 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:1082*//*1083:*/
#line 12709 "./marpa.w"

typedef Marpa_Order ORDER;
/*:1083*//*1118:*/
#line 13160 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1118*//*1166:*/
#line 13741 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1166*/
#line 598 "./marpa.w"

/*87:*/
#line 900 "./marpa.w"

typedef int Marpa_Rank;
/*:87*//*104:*/
#line 998 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:104*//*128:*/
#line 1176 "./marpa.w"

typedef int Marpa_Error_Code;
/*:128*//*135:*/
#line 1214 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:135*//*203:*/
#line 1723 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:203*//*239:*/
#line 1980 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:239*//*313:*/
#line 2705 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:313*//*441:*/
#line 4680 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:441*//*482:*/
#line 5055 "./marpa.w"

typedef int Marpa_AHFA_State_ID;
/*:482*//*678:*/
#line 7350 "./marpa.w"
typedef int Marpa_Earleme;
/*:678*//*680:*/
#line 7354 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:680*//*722:*/
#line 7786 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:722*//*936:*/
#line 10826 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:936*//*1012:*/
#line 11903 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:1012*//*1152:*/
#line 13602 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1152*//*1207:*/
#line 14157 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1207*//*1366:*/
#line 16199 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1366*/
#line 599 "./marpa.w"

/*39:*/
#line 604 "./marpa.w"

struct marpa_config{
int t_is_ok;
Marpa_Error_Code t_error;
const char*t_error_string;
};
typedef struct marpa_config Marpa_Config;

/*:39*//*106:*/
#line 1004 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:106*//*1033:*/
#line 12131 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:1033*//*1170:*/
#line 13771 "./marpa.w"

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
/*:1170*/
#line 600 "./marpa.w"

/*1372:*/
#line 16251 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1372*//*1374:*/
#line 16259 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1374*/
#line 601 "./marpa.w"


/*:37*/
#line 16534 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1395*/
