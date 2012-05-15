/*1252:*/
#line 14209 "./marpa.w"

/*1248:*/
#line 14181 "./marpa.w"

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

/*:1248*/
#line 14210 "./marpa.w"


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

/*235:*/
#line 2061 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:235*//*239:*/
#line 2100 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:239*//*1067:*/
#line 12033 "./marpa.w"

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
/*:1067*/
#line 587 "./marpa.w"

/*38:*/
#line 594 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*536:*/
#line 5827 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:536*//*938:*/
#line 10606 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:938*//*984:*/
#line 11056 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:984*//*985:*/
#line 11059 "./marpa.w"

typedef Marpa_Order ORDER;
/*:985*//*1010:*/
#line 11385 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1010*//*1062:*/
#line 11996 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1062*/
#line 588 "./marpa.w"

/*94:*/
#line 907 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:94*//*113:*/
#line 1053 "./marpa.w"

typedef int Marpa_Error_Code;
/*:113*//*119:*/
#line 1083 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:119*//*171:*/
#line 1434 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:171*//*200:*/
#line 1634 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:200*//*265:*/
#line 2284 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:265*//*383:*/
#line 4037 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:383*//*423:*/
#line 4392 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:423*//*608:*/
#line 6263 "./marpa.w"
typedef int Marpa_Earleme;
/*:608*//*610:*/
#line 6267 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:610*//*635:*/
#line 6471 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:635*//*862:*/
#line 9506 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:862*//*922:*/
#line 10418 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:922*//*1048:*/
#line 11858 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1048*//*1097:*/
#line 12315 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1097*//*1223:*/
#line 13890 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1223*/
#line 589 "./marpa.w"

/*95:*/
#line 911 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:95*//*1066:*/
#line 12025 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1066*/
#line 590 "./marpa.w"

/*1229:*/
#line 13942 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1229*//*1231:*/
#line 13950 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1231*/
#line 591 "./marpa.w"


/*:37*/
#line 14216 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1252*/
