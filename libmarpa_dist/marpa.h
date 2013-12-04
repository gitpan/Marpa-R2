/*1397:*/
#line 16568 "./marpa.w"

/*1393:*/
#line 16540 "./marpa.w"

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

/*:1393*/
#line 16569 "./marpa.w"


#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "marpa_config.h"

/*37:*/
#line 586 "./marpa.w"

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
#line 1002 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:105*//*281:*/
#line 2516 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:281*//*285:*/
#line 2556 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:285*//*1173:*/
#line 13818 "./marpa.w"

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

/*:1173*/
#line 598 "./marpa.w"

/*42:*/
#line 634 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:42*//*612:*/
#line 6783 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:612*//*1045:*/
#line 12395 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:1045*//*1083:*/
#line 12732 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:1083*//*1084:*/
#line 12735 "./marpa.w"

typedef Marpa_Order ORDER;
/*:1084*//*1120:*/
#line 13194 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1120*//*1168:*/
#line 13775 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1168*/
#line 599 "./marpa.w"

/*87:*/
#line 901 "./marpa.w"

typedef int Marpa_Rank;
/*:87*//*104:*/
#line 999 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:104*//*128:*/
#line 1177 "./marpa.w"

typedef int Marpa_Error_Code;
/*:128*//*135:*/
#line 1215 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:135*//*203:*/
#line 1724 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:203*//*239:*/
#line 1981 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:239*//*313:*/
#line 2706 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:313*//*441:*/
#line 4689 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:441*//*482:*/
#line 5064 "./marpa.w"

typedef int Marpa_AHFA_State_ID;
/*:482*//*678:*/
#line 7359 "./marpa.w"
typedef int Marpa_Earleme;
/*:678*//*680:*/
#line 7363 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:680*//*722:*/
#line 7795 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:722*//*936:*/
#line 10844 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:936*//*1012:*/
#line 11921 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:1012*//*1154:*/
#line 13636 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1154*//*1209:*/
#line 14191 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1209*//*1368:*/
#line 16240 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1368*/
#line 600 "./marpa.w"

/*39:*/
#line 605 "./marpa.w"

struct marpa_config{
int t_is_ok;
Marpa_Error_Code t_error;
const char*t_error_string;
};
typedef struct marpa_config Marpa_Config;

/*:39*//*106:*/
#line 1005 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:106*//*1033:*/
#line 12149 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:1033*//*1172:*/
#line 13805 "./marpa.w"

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
/*:1172*/
#line 601 "./marpa.w"

/*1374:*/
#line 16292 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1374*//*1376:*/
#line 16300 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1376*/
#line 602 "./marpa.w"


/*:37*/
#line 16575 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1397*/
