/*1196:*/
#line 13773 "./marpa.w"

/*1192:*/
#line 13745 "./marpa.w"

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

/*:1192*/
#line 13774 "./marpa.w"


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
/*203:*/
#line 1871 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:203*//*207:*/
#line 1910 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:207*//*1027:*/
#line 11703 "./marpa.w"

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

/*:1027*/
#line 594 "./marpa.w"

/*38:*/
#line 602 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*506:*/
#line 5543 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:506*//*907:*/
#line 10299 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:907*//*952:*/
#line 10754 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:952*//*953:*/
#line 10757 "./marpa.w"

typedef Marpa_Order ORDER;
/*:953*//*976:*/
#line 11075 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:976*//*1023:*/
#line 11651 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1023*/
#line 595 "./marpa.w"

/*93:*/
#line 897 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:93*//*112:*/
#line 1043 "./marpa.w"

typedef int Marpa_Error_Code;
/*:112*//*118:*/
#line 1073 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:118*//*169:*/
#line 1461 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:169*//*356:*/
#line 3742 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:356*//*395:*/
#line 4094 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:395*//*578:*/
#line 5979 "./marpa.w"
typedef int Marpa_Earleme;
/*:578*//*580:*/
#line 5983 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:580*//*605:*/
#line 6187 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:605*//*831:*/
#line 9210 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:831*//*891:*/
#line 10120 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:891*//*1009:*/
#line 11513 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1009*//*1045:*/
#line 11940 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1045*//*1168:*/
#line 13455 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1168*/
#line 596 "./marpa.w"

/*94:*/
#line 901 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:94*//*1025:*/
#line 11678 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1025*/
#line 597 "./marpa.w"

/*1171:*/
#line 13486 "./marpa.w"

extern int(*marpa_debug_handler)(const char*,...);
extern int marpa_debug_level;
/*:1171*/
#line 598 "./marpa.w"

/*1173:*/
#line 13505 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1173*//*1175:*/
#line 13513 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1175*/
#line 599 "./marpa.w"


/*:37*/
#line 13780 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1196*/
