/*1245:*/
#line 14243 "./marpa.w"

/*1241:*/
#line 14215 "./marpa.w"

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

/*:1241*/
#line 14244 "./marpa.w"


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

/*94:*/
#line 907 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:94*//*232:*/
#line 2027 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:232*//*236:*/
#line 2066 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:236*//*591:*/
#line 6178 "./marpa.w"

#define marpa_r_event_value(event) \
    ((event)->t_value)
/*:591*//*930:*/
#line 10560 "./marpa.w"

#define marpa_r_report_rule(v) \
    Rule_of_REPORT((r)->t-current_report_item)
#define marpa_r_report_position(v) \
    Position_of_REPORT((r)->t-current_report_item)
#define marpa_r_report_origin(v) \
    Origin_of_REPORT((r)->t-current_report_item)

/*:930*//*1062:*/
#line 12086 "./marpa.w"

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
/*:1062*/
#line 587 "./marpa.w"

/*38:*/
#line 594 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*537:*/
#line 5828 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:537*//*936:*/
#line 10676 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:936*//*979:*/
#line 11109 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:979*//*980:*/
#line 11112 "./marpa.w"

typedef Marpa_Order ORDER;
/*:980*//*1005:*/
#line 11438 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1005*//*1057:*/
#line 12049 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1057*/
#line 588 "./marpa.w"

/*93:*/
#line 904 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:93*//*113:*/
#line 1053 "./marpa.w"

typedef int Marpa_Error_Code;
/*:113*//*119:*/
#line 1083 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:119*//*168:*/
#line 1403 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:168*//*197:*/
#line 1602 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:197*//*266:*/
#line 2277 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:266*//*384:*/
#line 4032 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:384*//*424:*/
#line 4385 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:424*//*596:*/
#line 6212 "./marpa.w"
typedef int Marpa_Earleme;
/*:596*//*598:*/
#line 6216 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:598*//*622:*/
#line 6410 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:622*//*848:*/
#line 9433 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:848*//*908:*/
#line 10344 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:908*//*1043:*/
#line 11911 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1043*//*1092:*/
#line 12375 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1092*//*1216:*/
#line 13924 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1216*/
#line 589 "./marpa.w"

/*95:*/
#line 910 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:95*//*1061:*/
#line 12078 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_token_id;
int t_token_value;
Marpa_Rule_ID t_rule_id;
int t_tos;
int t_arg_n;
};
/*:1061*/
#line 590 "./marpa.w"

/*1222:*/
#line 13976 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1222*//*1224:*/
#line 13984 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1224*/
#line 591 "./marpa.w"


/*:37*/
#line 14250 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1245*/
