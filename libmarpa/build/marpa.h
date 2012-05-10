/*1237:*/
#line 14013 "./marpa.w"

/*1233:*/
#line 13985 "./marpa.w"

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

/*:1233*/
#line 14014 "./marpa.w"


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

/*219:*/
#line 1960 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:219*//*223:*/
#line 1999 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:223*//*1052:*/
#line 11835 "./marpa.w"

#define marpa_v_semantic_token(v) \
    ((v)->t_semantic_token_id)
#define marpa_v_token_value(v) \
    ((v)->t_token_value)
#define marpa_v_semantic_rule(v) \
    ((v)->t_semantic_rule_id)
#define marpa_v_arg_0(v) \
    ((v)->t_tos)
#define marpa_v_arg_n(v) \
    ((v)->t_arg_n)
/*:1052*/
#line 587 "./marpa.w"

/*38:*/
#line 594 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*522:*/
#line 5639 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:522*//*923:*/
#line 10408 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:923*//*969:*/
#line 10858 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:969*//*970:*/
#line 10861 "./marpa.w"

typedef Marpa_Order ORDER;
/*:970*//*995:*/
#line 11187 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:995*//*1047:*/
#line 11798 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1047*/
#line 588 "./marpa.w"

/*94:*/
#line 909 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:94*//*113:*/
#line 1055 "./marpa.w"

typedef int Marpa_Error_Code;
/*:113*//*119:*/
#line 1085 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:119*//*165:*/
#line 1394 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:165*//*184:*/
#line 1539 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:184*//*270:*/
#line 2323 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:270*//*369:*/
#line 3838 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:369*//*409:*/
#line 4196 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:409*//*594:*/
#line 6075 "./marpa.w"
typedef int Marpa_Earleme;
/*:594*//*596:*/
#line 6079 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:596*//*621:*/
#line 6283 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:621*//*847:*/
#line 9306 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:847*//*907:*/
#line 10220 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:907*//*1033:*/
#line 11660 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1033*//*1082:*/
#line 12117 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1082*//*1208:*/
#line 13694 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1208*/
#line 589 "./marpa.w"

/*95:*/
#line 913 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:95*//*1051:*/
#line 11827 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1051*/
#line 590 "./marpa.w"

/*1214:*/
#line 13746 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1214*//*1216:*/
#line 13754 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1216*/
#line 591 "./marpa.w"


/*:37*/
#line 14020 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1237*/
