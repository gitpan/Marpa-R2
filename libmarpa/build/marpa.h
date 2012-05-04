/*1227:*/
#line 13864 "./marpa.w"

/*1223:*/
#line 13836 "./marpa.w"

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

/*:1223*/
#line 13865 "./marpa.w"


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

/*209:*/
#line 1903 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:209*//*213:*/
#line 1942 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:213*//*1044:*/
#line 11716 "./marpa.w"

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
/*:1044*/
#line 587 "./marpa.w"

/*38:*/
#line 594 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*514:*/
#line 5522 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:514*//*915:*/
#line 10288 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:915*//*961:*/
#line 10739 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:961*//*962:*/
#line 10742 "./marpa.w"

typedef Marpa_Order ORDER;
/*:962*//*987:*/
#line 11068 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:987*//*1039:*/
#line 11679 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1039*/
#line 588 "./marpa.w"

/*94:*/
#line 890 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:94*//*113:*/
#line 1036 "./marpa.w"

typedef int Marpa_Error_Code;
/*:113*//*119:*/
#line 1066 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:119*//*174:*/
#line 1482 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:174*//*361:*/
#line 3734 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:361*//*401:*/
#line 4092 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:401*//*586:*/
#line 5958 "./marpa.w"
typedef int Marpa_Earleme;
/*:586*//*588:*/
#line 5962 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:588*//*613:*/
#line 6166 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:613*//*839:*/
#line 9189 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:839*//*899:*/
#line 10100 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:899*//*1025:*/
#line 11541 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1025*//*1074:*/
#line 12001 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1074*//*1198:*/
#line 13545 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1198*/
#line 589 "./marpa.w"

/*95:*/
#line 894 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:95*//*1043:*/
#line 11708 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1043*/
#line 590 "./marpa.w"

/*1204:*/
#line 13597 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1204*//*1206:*/
#line 13605 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1206*/
#line 591 "./marpa.w"


/*:37*/
#line 13871 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1227*/
