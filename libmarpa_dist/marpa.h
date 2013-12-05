/*1381:*/
#line 16350 "./marpa.w"

/*1377:*/
#line 16322 "./marpa.w"

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

/*:1377*/
#line 16351 "./marpa.w"


#ifndef _MARPA_H__
#define _MARPA_H__ 1
#include "marpa_config.h"

/*37:*/
#line 591 "./marpa.w"

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
#line 1007 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:105*//*281:*/
#line 2521 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:281*//*285:*/
#line 2561 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:285*//*1173:*/
#line 13823 "./marpa.w"

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
#line 603 "./marpa.w"

/*42:*/
#line 639 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:42*//*612:*/
#line 6788 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:612*//*1045:*/
#line 12400 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:1045*//*1083:*/
#line 12737 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:1083*//*1084:*/
#line 12740 "./marpa.w"

typedef Marpa_Order ORDER;
/*:1084*//*1120:*/
#line 13199 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1120*//*1168:*/
#line 13780 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1168*/
#line 604 "./marpa.w"

/*87:*/
#line 906 "./marpa.w"

typedef int Marpa_Rank;
/*:87*//*104:*/
#line 1004 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:104*//*128:*/
#line 1182 "./marpa.w"

typedef int Marpa_Error_Code;
/*:128*//*135:*/
#line 1220 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:135*//*203:*/
#line 1729 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:203*//*239:*/
#line 1986 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:239*//*313:*/
#line 2711 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:313*//*441:*/
#line 4694 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:441*//*482:*/
#line 5069 "./marpa.w"

typedef int Marpa_AHFA_State_ID;
/*:482*//*678:*/
#line 7364 "./marpa.w"
typedef int Marpa_Earleme;
/*:678*//*680:*/
#line 7368 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:680*//*722:*/
#line 7800 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:722*//*936:*/
#line 10849 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:936*//*1012:*/
#line 11926 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:1012*//*1154:*/
#line 13641 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1154*//*1209:*/
#line 14196 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1209*//*1352:*/
#line 16020 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1352*/
#line 605 "./marpa.w"

/*39:*/
#line 610 "./marpa.w"

struct marpa_config{
int t_is_ok;
Marpa_Error_Code t_error;
const char*t_error_string;
};
typedef struct marpa_config Marpa_Config;

/*:39*//*106:*/
#line 1010 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:106*//*1033:*/
#line 12154 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:1033*//*1172:*/
#line 13810 "./marpa.w"

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
#line 606 "./marpa.w"

/*1358:*/
#line 16072 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1358*//*1360:*/
#line 16080 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1360*/
#line 607 "./marpa.w"


/*:37*/
#line 16357 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1381*/
