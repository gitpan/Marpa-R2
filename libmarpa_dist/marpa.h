/*1314:*/
#line 15245 "./marpa.w"

/*1310:*/
#line 15217 "./marpa.w"

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

/*:1310*/
#line 15246 "./marpa.w"


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
#line 965 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:103*//*263:*/
#line 2334 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:263*//*267:*/
#line 2374 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:267*//*1107:*/
#line 12768 "./marpa.w"

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

/*:1107*/
#line 576 "./marpa.w"

/*42:*/
#line 612 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:42*//*573:*/
#line 6220 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:573*//*979:*/
#line 11287 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:979*//*1021:*/
#line 11714 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:1021*//*1022:*/
#line 11717 "./marpa.w"

typedef Marpa_Order ORDER;
/*:1022*//*1054:*/
#line 12145 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1054*//*1102:*/
#line 12725 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1102*/
#line 577 "./marpa.w"

/*87:*/
#line 879 "./marpa.w"

typedef int Marpa_Rank;
/*:87*//*102:*/
#line 962 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:102*//*126:*/
#line 1137 "./marpa.w"

typedef int Marpa_Error_Code;
/*:126*//*133:*/
#line 1175 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:133*//*189:*/
#line 1576 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:189*//*221:*/
#line 1799 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:221*//*293:*/
#line 2522 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:293*//*417:*/
#line 4365 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:417*//*457:*/
#line 4718 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:457*//*630:*/
#line 6645 "./marpa.w"
typedef int Marpa_Earleme;
/*:630*//*632:*/
#line 6649 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:632*//*662:*/
#line 6933 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:662*//*887:*/
#line 9966 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:887*//*947:*/
#line 10841 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:947*//*1088:*/
#line 12586 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1088*//*1143:*/
#line 13141 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1143*//*1285:*/
#line 14917 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1285*/
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
#line 968 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:104*//*967:*/
#line 11042 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:967*//*1106:*/
#line 12755 "./marpa.w"

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
/*:1106*/
#line 579 "./marpa.w"

/*1291:*/
#line 14969 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1291*//*1293:*/
#line 14977 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1293*/
#line 580 "./marpa.w"


/*:37*/
#line 15252 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1314*/
