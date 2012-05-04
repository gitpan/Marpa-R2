/*1226:*/
#line 13868 "./marpa.w"

/*1222:*/
#line 13840 "./marpa.w"

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

/*:1222*/
#line 13869 "./marpa.w"


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

/*208:*/
#line 1902 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:208*//*212:*/
#line 1941 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:212*//*1043:*/
#line 11720 "./marpa.w"

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
/*:1043*/
#line 587 "./marpa.w"

/*38:*/
#line 594 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*513:*/
#line 5523 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:513*//*914:*/
#line 10292 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:914*//*960:*/
#line 10743 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:960*//*961:*/
#line 10746 "./marpa.w"

typedef Marpa_Order ORDER;
/*:961*//*986:*/
#line 11072 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:986*//*1038:*/
#line 11683 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1038*/
#line 588 "./marpa.w"

/*93:*/
#line 889 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:93*//*112:*/
#line 1035 "./marpa.w"

typedef int Marpa_Error_Code;
/*:112*//*118:*/
#line 1065 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:118*//*173:*/
#line 1481 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:173*//*360:*/
#line 3735 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:360*//*400:*/
#line 4093 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:400*//*585:*/
#line 5959 "./marpa.w"
typedef int Marpa_Earleme;
/*:585*//*587:*/
#line 5963 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:587*//*612:*/
#line 6167 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:612*//*838:*/
#line 9190 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:838*//*898:*/
#line 10104 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:898*//*1024:*/
#line 11545 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1024*//*1073:*/
#line 12005 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1073*//*1197:*/
#line 13549 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1197*/
#line 589 "./marpa.w"

/*94:*/
#line 893 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:94*//*1042:*/
#line 11712 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1042*/
#line 590 "./marpa.w"

/*1203:*/
#line 13601 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1203*//*1205:*/
#line 13609 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1205*/
#line 591 "./marpa.w"


/*:37*/
#line 13875 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1226*/
