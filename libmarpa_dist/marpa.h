/*1297:*/
#line 15059 "./marpa.w"

/*1293:*/
#line 15031 "./marpa.w"

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

/*:1293*/
#line 15060 "./marpa.w"


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

/*103:*/
#line 966 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:103*//*260:*/
#line 2329 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:260*//*264:*/
#line 2369 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:264*//*1102:*/
#line 12725 "./marpa.w"

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

/*:1102*/
#line 576 "./marpa.w"

/*42:*/
#line 612 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:42*//*565:*/
#line 6148 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:565*//*973:*/
#line 11227 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:973*//*1015:*/
#line 11654 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:1015*//*1016:*/
#line 11657 "./marpa.w"

typedef Marpa_Order ORDER;
/*:1016*//*1049:*/
#line 12102 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1049*//*1097:*/
#line 12682 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1097*/
#line 577 "./marpa.w"

/*87:*/
#line 880 "./marpa.w"

typedef int Marpa_Rank;
/*:87*//*102:*/
#line 963 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:102*//*123:*/
#line 1124 "./marpa.w"

typedef int Marpa_Error_Code;
/*:123*//*130:*/
#line 1162 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:130*//*186:*/
#line 1571 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:186*//*218:*/
#line 1794 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:218*//*290:*/
#line 2517 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:290*//*412:*/
#line 4354 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:412*//*452:*/
#line 4707 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:452*//*621:*/
#line 6554 "./marpa.w"
typedef int Marpa_Earleme;
/*:621*//*623:*/
#line 6558 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:623*//*653:*/
#line 6842 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:653*//*882:*/
#line 9919 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:882*//*942:*/
#line 10794 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:942*//*1083:*/
#line 12543 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1083*//*1137:*/
#line 13071 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1137*//*1268:*/
#line 14731 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1268*/
#line 578 "./marpa.w"

/*39:*/
#line 583 "./marpa.w"

struct marpa_config{
int t_is_ok;
Marpa_Error_Code t_error;
const char*t_error_string;
};
typedef struct marpa_config Marpa_Config;

/*:39*//*104:*/
#line 969 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:104*//*962:*/
#line 10995 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:962*//*1101:*/
#line 12712 "./marpa.w"

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
/*:1101*/
#line 579 "./marpa.w"

/*1274:*/
#line 14783 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1274*//*1276:*/
#line 14791 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1276*/
#line 580 "./marpa.w"


/*:37*/
#line 15066 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1297*/
