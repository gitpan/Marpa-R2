/*1222:*/
#line 13835 "./marpa.w"

/*1218:*/
#line 13807 "./marpa.w"

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

/*:1218*/
#line 13836 "./marpa.w"


#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "marpa_config.h"

/*37:*/
#line 581 "./marpa.w"

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

#define MARPA_CAT(a, b)  a ## b 
/*207:*/
#line 1876 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:207*//*211:*/
#line 1915 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:211*//*1041:*/
#line 11692 "./marpa.w"

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
/*:1041*/
#line 594 "./marpa.w"

/*38:*/
#line 602 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*511:*/
#line 5500 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:511*//*912:*/
#line 10266 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:912*//*958:*/
#line 10715 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:958*//*959:*/
#line 10718 "./marpa.w"

typedef Marpa_Order ORDER;
/*:959*//*984:*/
#line 11044 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:984*//*1036:*/
#line 11655 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1036*/
#line 595 "./marpa.w"

/*93:*/
#line 898 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:93*//*112:*/
#line 1044 "./marpa.w"

typedef int Marpa_Error_Code;
/*:112*//*118:*/
#line 1074 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:118*//*173:*/
#line 1484 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:173*//*359:*/
#line 3700 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:359*//*398:*/
#line 4047 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:398*//*583:*/
#line 5936 "./marpa.w"
typedef int Marpa_Earleme;
/*:583*//*585:*/
#line 5940 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:585*//*610:*/
#line 6144 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:610*//*836:*/
#line 9167 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:836*//*896:*/
#line 10078 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:896*//*1022:*/
#line 11517 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1022*//*1071:*/
#line 11977 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1071*//*1194:*/
#line 13517 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1194*/
#line 596 "./marpa.w"

/*94:*/
#line 902 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:94*//*1040:*/
#line 11684 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1040*/
#line 597 "./marpa.w"

/*1197:*/
#line 13548 "./marpa.w"

extern int(*marpa_debug_handler)(const char*,...);
extern int marpa_debug_level;
/*:1197*/
#line 598 "./marpa.w"

/*1199:*/
#line 13567 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1199*//*1201:*/
#line 13575 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1201*/
#line 599 "./marpa.w"


/*:37*/
#line 13842 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1222*/
