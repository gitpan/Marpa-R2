/*1189:*/
#line 13518 "./marpa.w"

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

/*:1189*//*1190:*/
#line 13542 "./marpa.w"

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
/*206:*/
#line 2025 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:206*//*210:*/
#line 2063 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:210*//*1022:*/
#line 11514 "./marpa.w"

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

/*:1022*/
#line 593 "./marpa.w"

/*38:*/
#line 600 "./marpa.w"

struct marpa_g;
typedef struct marpa_g*Marpa_Grammar;
/*:38*//*498:*/
#line 5332 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:498*//*901:*/
#line 10094 "./marpa.w"

struct s_bocage;
typedef struct s_bocage*Marpa_Bocage;
/*:901*//*947:*/
#line 10565 "./marpa.w"

struct s_order;
typedef struct s_order*Marpa_Order;
/*:947*//*948:*/
#line 10568 "./marpa.w"

typedef Marpa_Order ORDER;
/*:948*//*971:*/
#line 10886 "./marpa.w"

struct s_tree;
typedef struct s_tree*Marpa_Tree;
/*:971*//*1018:*/
#line 11462 "./marpa.w"

struct s_value;
typedef struct s_value*Marpa_Value;
/*:1018*/
#line 594 "./marpa.w"

/*91:*/
#line 889 "./marpa.w"

struct marpa_event;
typedef struct marpa_event*Marpa_Event;
typedef int Marpa_Event_Type;
/*:91*//*106:*/
#line 1022 "./marpa.w"

typedef int Marpa_Error_Code;
/*:106*//*112:*/
#line 1056 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:112*//*168:*/
#line 1488 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:168*//*350:*/
#line 3598 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:350*//*389:*/
#line 3951 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:389*//*570:*/
#line 5768 "./marpa.w"
typedef int Marpa_Earleme;
/*:570*//*572:*/
#line 5772 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:572*//*597:*/
#line 5976 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:597*//*825:*/
#line 9005 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:825*//*885:*/
#line 9915 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:885*//*1004:*/
#line 11324 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1004*//*1040:*/
#line 11746 "./marpa.w"

typedef int Marpa_Value_Type;
/*:1040*//*1165:*/
#line 13244 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1165*/
#line 595 "./marpa.w"

/*92:*/
#line 893 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
/*:92*//*1020:*/
#line 11489 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_semantic_token_id;
int t_token_value;
Marpa_Rule_ID t_semantic_rule_id;
int t_tos;
int t_arg_n;
};
/*:1020*/
#line 596 "./marpa.w"

/*1169:*/
#line 13283 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1169*//*1171:*/
#line 13291 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1171*/
#line 597 "./marpa.w"


/*:37*/
#line 13547 "./marpa.w"


#include "marpa_api.h"
#endif __MARPA_H__

/*:1190*/
