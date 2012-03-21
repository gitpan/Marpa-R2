/*1201:*/
#line 13448 "./marpa.w"

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

/*:1201*//*1202:*/
#line 13472 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "marpa_config.h"

/*37:*/
#line 582 "./marpa.w"

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
/*210:*/
#line 1965 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:210*//*214:*/
#line 2003 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:214*//*1033:*/
#line 11477 "./marpa.w"

#define marpa_v_semantic_token(v) \
    (((const struct marpa_value*)v)->t_semantic_token_id)
#define marpa_v_token_value(v) \
    (((const struct marpa_value*)v)->t_token_value)
#define marpa_v_semantic_rule(v) \
    (((const struct marpa_value*)v)->t_semantic_rule_id)
#define marpa_v_arg_0(v) \
    (((const struct marpa_value*)v)->t_tos)
#define marpa_v_arg_n(v) \
    (((const struct marpa_value*)v)->t_arg_n)

/*:1033*/
#line 595 "./marpa.w"

/*38:*/
#line 602 "./marpa.w"

struct marpa_g;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*509:*/
#line 5253 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:509*//*912:*/
#line 10052 "./marpa.w"

struct s_bocage;
typedef struct s_bocage*Marpa_Bocage;
/*:912*//*958:*/
#line 10528 "./marpa.w"

struct s_order;
typedef struct s_order*Marpa_Order;
/*:958*//*959:*/
#line 10531 "./marpa.w"

typedef Marpa_Order ORDER;
/*:959*//*982:*/
#line 10849 "./marpa.w"

struct s_tree;
typedef struct s_tree*Marpa_Tree;
/*:982*//*1029:*/
#line 11425 "./marpa.w"

struct s_value;
typedef struct s_value*Marpa_Value;
/*:1029*/
#line 596 "./marpa.w"

/*95:*/
#line 909 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:95*//*110:*/
#line 1041 "./marpa.w"

typedef int Marpa_Error_Code;
/*:110*//*116:*/
#line 1075 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:116*//*171:*/
#line 1490 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:171*//*361:*/
#line 3492 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:361*//*400:*/
#line 3860 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:400*//*581:*/
#line 5691 "./marpa.w"
typedef int Marpa_Earleme;
/*:581*//*583:*/
#line 5695 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:583*//*608:*/
#line 5899 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:608*//*836:*/
#line 8941 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:836*//*896:*/
#line 9873 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:896*//*1015:*/
#line 11287 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1015*//*1051:*/
#line 11709 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1051*//*1177:*/
#line 13177 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1177*/
#line 597 "./marpa.w"

/*96:*/
#line 913 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:96*//*1031:*/
#line 11452 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1031*/
#line 598 "./marpa.w"

/*1181:*/
#line 13216 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1181*//*1183:*/
#line 13224 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1183*/
#line 599 "./marpa.w"


/*:37*/
#line 13477 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1202*/
