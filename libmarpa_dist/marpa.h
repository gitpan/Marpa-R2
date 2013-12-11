/*1382:*/
#line 16374 "./marpa.w"

/*1378:*/
#line 16346 "./marpa.w"

/*
 * Copyright 2013 Jeffrey Kegler
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

/*:1378*/
#line 16375 "./marpa.w"


#ifndef _MARPA_H__
#define _MARPA_H__ 1
#include "marpa_config.h"

/*38:*/
#line 614 "./marpa.w"

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

/*106:*/
#line 1030 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:106*//*282:*/
#line 2544 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:282*//*286:*/
#line 2584 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:286*//*1174:*/
#line 13847 "./marpa.w"

#define marpa_v_step_type(v) ((v)->t_step_type)
#define marpa_v_token(v) \
    ((v)->t_token_id)
#define marpa_v_symbol(v) marpa_v_token(v)
#define marpa_v_token_value(v) \
    ((v)->t_token_value)
#define marpa_v_rule(v) \
    ((v)->t_rule_id)
#define marpa_v_arg_0(v) \
    ((v)->t_arg_0)
#define marpa_v_arg_n(v) \
    ((v)->t_arg_n)
#define marpa_v_result(v) \
    ((v)->t_result)
#define marpa_v_rule_start_es_id(v) ((v)->t_rule_start_ys_id)
#define marpa_v_token_start_es_id(v) ((v)->t_token_start_ys_id)
#define marpa_v_es_id(v) ((v)->t_ys_id)

/*:1174*/
#line 626 "./marpa.w"

/*43:*/
#line 662 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:43*//*613:*/
#line 6811 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:613*//*1046:*/
#line 12423 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:1046*//*1084:*/
#line 12760 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:1084*//*1085:*/
#line 12763 "./marpa.w"

typedef Marpa_Order ORDER;
/*:1085*//*1121:*/
#line 13222 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1121*//*1169:*/
#line 13803 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1169*/
#line 627 "./marpa.w"

/*88:*/
#line 929 "./marpa.w"

typedef int Marpa_Rank;
/*:88*//*105:*/
#line 1027 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:105*//*129:*/
#line 1205 "./marpa.w"

typedef int Marpa_Error_Code;
/*:129*//*136:*/
#line 1243 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:136*//*204:*/
#line 1752 "./marpa.w"

typedef int Marpa_NSY_ID;
/*:204*//*240:*/
#line 2009 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:240*//*314:*/
#line 2734 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:314*//*442:*/
#line 4717 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:442*//*483:*/
#line 5092 "./marpa.w"

typedef int Marpa_AHFA_State_ID;
/*:483*//*679:*/
#line 7387 "./marpa.w"
typedef int Marpa_Earleme;
/*:679*//*681:*/
#line 7391 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:681*//*723:*/
#line 7823 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:723*//*937:*/
#line 10872 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:937*//*1013:*/
#line 11949 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:1013*//*1155:*/
#line 13664 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1155*//*1210:*/
#line 14220 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1210*//*1353:*/
#line 16044 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1353*/
#line 628 "./marpa.w"

/*40:*/
#line 633 "./marpa.w"

struct marpa_config{
int t_is_ok;
Marpa_Error_Code t_error;
const char*t_error_string;
};
typedef struct marpa_config Marpa_Config;

/*:40*//*107:*/
#line 1033 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:107*//*1034:*/
#line 12177 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:1034*//*1173:*/
#line 13833 "./marpa.w"

struct marpa_value{
Marpa_Step_Type t_step_type;
Marpa_Symbol_ID t_token_id;
int t_token_value;
Marpa_Rule_ID t_rule_id;
int t_arg_0;
int t_arg_n;
int t_result;
Marpa_Earley_Set_ID t_token_start_ys_id;
Marpa_Earley_Set_ID t_rule_start_ys_id;
Marpa_Earley_Set_ID t_ys_id;
};
/*:1173*/
#line 629 "./marpa.w"

/*1359:*/
#line 16096 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1359*//*1361:*/
#line 16104 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1361*/
#line 630 "./marpa.w"


/*:38*/
#line 16381 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1382*/
