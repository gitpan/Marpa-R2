/*1258:*/
#line 14511 "./marpa.w"

/*1254:*/
#line 14483 "./marpa.w"

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

/*:1254*/
#line 14512 "./marpa.w"


#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "marpa_config.h"

/*37:*/
#line 578 "./marpa.w"

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

/*97:*/
#line 932 "./marpa.w"

#define marpa_g_event_value(event) \
    ((event)->t_value)
/*:97*//*237:*/
#line 2112 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:237*//*241:*/
#line 2151 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2
/*:241*//*1066:*/
#line 12232 "./marpa.w"

#define marpa_v_token(v) \
    ((v)->t_token_id)
#define marpa_v_symbol(v) marpa_v_token(v)
#define marpa_v_token_value(v) \
    ((v)->t_token_value)
#define marpa_v_rule(v) \
    ((v)->t_rule_id)
#define marpa_v_arg_0(v) \
    ((v)->t_tos)
#define marpa_v_arg_n(v) \
    ((v)->t_arg_n)
#define marpa_v_result(v) marpa_v_arg_0(v)
/*:1066*/
#line 590 "./marpa.w"

/*42:*/
#line 626 "./marpa.w"

struct marpa_g;
struct marpa_avl_table;
typedef struct marpa_g*Marpa_Grammar;
/*:42*//*539:*/
#line 5878 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*Marpa_Recognizer;
typedef Marpa_Recognizer Marpa_Recce;
/*:539*//*939:*/
#line 10806 "./marpa.w"

struct marpa_bocage;
typedef struct marpa_bocage*Marpa_Bocage;
/*:939*//*983:*/
#line 11252 "./marpa.w"

struct marpa_order;
typedef struct marpa_order*Marpa_Order;
/*:983*//*984:*/
#line 11255 "./marpa.w"

typedef Marpa_Order ORDER;
/*:984*//*1009:*/
#line 11581 "./marpa.w"

struct marpa_tree;
typedef struct marpa_tree*Marpa_Tree;
/*:1009*//*1061:*/
#line 12195 "./marpa.w"

struct marpa_value;
typedef struct marpa_value*Marpa_Value;
/*:1061*/
#line 591 "./marpa.w"

/*96:*/
#line 929 "./marpa.w"

struct marpa_event;
typedef int Marpa_Event_Type;
/*:96*//*117:*/
#line 1090 "./marpa.w"

typedef int Marpa_Error_Code;
/*:117*//*124:*/
#line 1145 "./marpa.w"

typedef int Marpa_Symbol_ID;
/*:124*//*174:*/
#line 1491 "./marpa.w"

typedef int Marpa_ISY_ID;
/*:174*//*203:*/
#line 1690 "./marpa.w"

typedef int Marpa_Rule_ID;
/*:203*//*267:*/
#line 2292 "./marpa.w"

typedef int Marpa_IRL_ID;
/*:267*//*386:*/
#line 4084 "./marpa.w"

typedef int Marpa_AHFA_Item_ID;
/*:386*//*426:*/
#line 4437 "./marpa.w"

typedef int Marpa_AHFA_State_ID;

/*:426*//*593:*/
#line 6240 "./marpa.w"
typedef int Marpa_Earleme;
/*:593*//*595:*/
#line 6244 "./marpa.w"
typedef int Marpa_Earley_Set_ID;
/*:595*//*619:*/
#line 6438 "./marpa.w"
typedef int Marpa_Earley_Item_ID;
/*:619*//*848:*/
#line 9499 "./marpa.w"

typedef int Marpa_Or_Node_ID;
/*:848*//*908:*/
#line 10373 "./marpa.w"

typedef int Marpa_And_Node_ID;
/*:908*//*1047:*/
#line 12057 "./marpa.w"

typedef int Marpa_Nook_ID;
/*:1047*//*1102:*/
#line 12562 "./marpa.w"

typedef int Marpa_Step_Type;
/*:1102*//*1229:*/
#line 14183 "./marpa.w"

typedef const char*Marpa_Message_ID;

/*:1229*/
#line 592 "./marpa.w"

/*39:*/
#line 597 "./marpa.w"

struct marpa_config{
int t_is_ok;
Marpa_Error_Code t_error;
const char*t_error_string;
};
typedef struct marpa_config Marpa_Config;

/*:39*//*98:*/
#line 935 "./marpa.w"

struct marpa_event{
Marpa_Event_Type t_type;
int t_value;
};
typedef struct marpa_event Marpa_Event;
/*:98*//*928:*/
#line 10574 "./marpa.w"

struct marpa_progress_item{
Marpa_Rule_ID t_rule_id;
int t_position;
int t_origin;
};

/*:928*//*1065:*/
#line 12224 "./marpa.w"

struct marpa_value{
Marpa_Symbol_ID t_token_id;
int t_token_value;
Marpa_Rule_ID t_rule_id;
int t_tos;
int t_arg_n;
};
/*:1065*/
#line 593 "./marpa.w"

/*1235:*/
#line 14235 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...));
/*:1235*//*1237:*/
#line 14243 "./marpa.w"

void marpa_debug_level_set(int level);
/*:1237*/
#line 594 "./marpa.w"


/*:37*/
#line 14518 "./marpa.w"


#include "marpa_api.h"
#endif 

/*:1258*/
