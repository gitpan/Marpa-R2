/*1203:*/
#line 13432 "./marpa.w"

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

/*:1203*//*1204:*/
#line 13456 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "marpa_config.h"

/*37:*/
#line 580 "./marpa.w"

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
/*209:*/
#line 1967 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:209*//*213:*/
#line 2005 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:213*//*1034:*/
#line 11438 "./marpa.w"

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

/*:1034*/
#line 593 "./marpa.w"

/*38:*/
#line 600 "./marpa.w"

struct marpa_g;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*510:*/
#line 5249 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:510*//*913:*/
#line 10014 "./marpa.w"

struct s_bocage;
typedef struct s_bocage*Marpa_Bocage;
/*:913*//*959:*/
#line 10489 "./marpa.w"

struct s_order;
typedef struct s_order*Marpa_Order;
/*:959*//*960:*/
#line 10492 "./marpa.w"

typedef Marpa_Order ORDER;
/*:960*//*983:*/
#line 10810 "./marpa.w"

struct s_tree;
typedef struct s_tree*Marpa_Tree;
/*:983*//*1030:*/
#line 11386 "./marpa.w"

struct s_value;
typedef struct s_value*Marpa_Value;
/*:1030*/
#line 594 "./marpa.w"

/*95:*/
#line 913 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:95*//*110:*/
#line 1045 "./marpa.w"

typedef int Marpa_Error_Code;
/*:110*//*116:*/
#line 1079 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:116*//*171:*/
#line 1491 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:171*//*362:*/
#line 3506 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:362*//*401:*/
#line 3861 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:401*//*582:*/
#line 5688 "./marpa.w"
typedef int Marpa_Earleme;
/*:582*//*584:*/
#line 5692 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:584*//*609:*/
#line 5896 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:609*//*837:*/
#line 8925 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:837*//*897:*/
#line 9835 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:897*//*1016:*/
#line 11248 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1016*//*1052:*/
#line 11670 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1052*//*1179:*/
#line 13158 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1179*/
#line 595 "./marpa.w"

/*96:*/
#line 917 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:96*//*1032:*/
#line 11413 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1032*/
#line 596 "./marpa.w"

/*1183:*/
#line 13197 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1183*//*1185:*/
#line 13205 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1185*/
#line 597 "./marpa.w"


/*:37*/
#line 13461 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1204*/
