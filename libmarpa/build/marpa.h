/*1235:*/
#line 14117 "./marpa.w"

/*1231:*/
#line 14089 "./marpa.w"

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

/*:1231*/
#line 14118 "./marpa.w"


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
#line 2028 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:232*//*236:*/
#line 2067 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:236*//*587:*/
#line 6143 "./marpa.w"

#define marpa_r_event_value(event) \
    ((event)->t_value)
/*:587*//*1050:*/
#line 11939 "./marpa.w"

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
/*:1050*/
#line 587 "./marpa.w"

/*38:*/
#line 594 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*533:*/
#line 5793 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:533*//*923:*/
#line 10523 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:923*//*967:*/
#line 10962 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:967*//*968:*/
#line 10965 "./marpa.w"

typedef Marpa_Order ORDER;
/*:968*//*993:*/
#line 11291 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:993*//*1045:*/
#line 11902 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1045*/
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
#line 1404 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:168*//*197:*/
#line 1603 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:197*//*262:*/
#line 2251 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:262*//*380:*/
#line 3990 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:380*//*420:*/
#line 4343 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:420*//*592:*/
#line 6177 "./marpa.w"
typedef int Marpa_Earleme;
/*:592*//*594:*/
#line 6181 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:594*//*618:*/
#line 6375 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:618*//*847:*/
#line 9424 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:847*//*907:*/
#line 10335 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:907*//*1031:*/
#line 11764 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1031*//*1080:*/
#line 12223 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1080*//*1206:*/
#line 13798 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1206*/
#line 589 "./marpa.w"

/*95:*/
#line 910 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:95*//*1049:*/
#line 11931 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_token_id;
int t_token_value;
Marpa_Rule_ID t_rule_id;
int t_tos;
int t_arg_n;
};
/*:1049*/
#line 590 "./marpa.w"

/*1212:*/
#line 13850 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1212*//*1214:*/
#line 13858 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1214*/
#line 591 "./marpa.w"


/*:37*/
#line 14124 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1235*/
