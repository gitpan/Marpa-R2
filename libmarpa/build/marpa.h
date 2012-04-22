/*1201:*/
#line 13758 "./marpa.w"

/*1197:*/
#line 13730 "./marpa.w"

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

/*:1197*/
#line 13759 "./marpa.w"


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
/*204:*/
#line 1860 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:204*//*208:*/
#line 1899 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:208*//*1032:*/
#line 11688 "./marpa.w"

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

/*:1032*/
#line 593 "./marpa.w"

/*38:*/
#line 601 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*510:*/
#line 5511 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:510*//*911:*/
#line 10267 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:911*//*957:*/
#line 10739 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:957*//*958:*/
#line 10742 "./marpa.w"

typedef Marpa_Order ORDER;
/*:958*//*981:*/
#line 11060 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:981*//*1028:*/
#line 11636 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1028*/
#line 594 "./marpa.w"

/*94:*/
#line 902 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:94*//*109:*/
#line 1023 "./marpa.w"

typedef int Marpa_Error_Code;
/*:109*//*115:*/
#line 1057 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:115*//*168:*/
#line 1452 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:168*//*360:*/
#line 3707 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:360*//*399:*/
#line 4061 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:399*//*582:*/
#line 5947 "./marpa.w"
typedef int Marpa_Earleme;
/*:582*//*584:*/
#line 5951 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:584*//*609:*/
#line 6155 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:609*//*835:*/
#line 9178 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:835*//*895:*/
#line 10088 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:895*//*1014:*/
#line 11498 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1014*//*1050:*/
#line 11925 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1050*//*1173:*/
#line 13440 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1173*/
#line 595 "./marpa.w"

/*95:*/
#line 906 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:95*//*1030:*/
#line 11663 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1030*/
#line 596 "./marpa.w"

/*1176:*/
#line 13471 "./marpa.w"

extern int(*marpa_debug_handler)(const char*,...);
extern int marpa_debug_level;
/*:1176*/
#line 597 "./marpa.w"

/*1178:*/
#line 13490 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1178*//*1180:*/
#line 13498 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1180*/
#line 598 "./marpa.w"


/*:37*/
#line 13765 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1201*/
