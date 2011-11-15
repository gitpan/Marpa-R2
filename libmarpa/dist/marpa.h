/*1407:*/
#line 13629 "./marpa.w"

/*
 * Copyright 2011 Jeffrey Kegler
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

/*:1407*//*1408:*/
#line 13653 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*42:*/
#line 673 "./marpa.w"

GLIB_VAR const guint marpa_major_version;
GLIB_VAR const guint marpa_minor_version;
GLIB_VAR const guint marpa_micro_version;
GLIB_VAR const guint marpa_interface_age;
GLIB_VAR const guint marpa_binary_age;
#define MARPA_CHECK_VERSION(major,minor,micro)  \
     (MARPA_MAJOR_VERSION >  (major) \
         || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION >  (minor)) \
         || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION == (minor) \
          && MARPA_MICRO_VERSION >= (micro)))

#define MARPA_CAT(a, b)  a ## b 
/*116:*/
#line 1013 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->t_type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->t_type == MARPA_CONTEXT_INT \
    ? ((struct marpa_context_int_value*)v)->t_data \
    : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->t_type == MARPA_CONTEXT_CONST \
    ? ((struct marpa_context_const_value*)v)->t_data \
    : NULL) 
/*:116*//*263:*/
#line 2023 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:263*//*268:*/
#line 2056 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:268*//*679:*/
#line 5781 "./marpa.w"

#define MARPA_R_EV_NONE  0
#define MARPA_R_EV_EXHAUSTED  1
#define MARPA_R_EV_EARLEY_ITEM_THRESHOLD  2
/*:679*/
#line 686 "./marpa.w"

/*43:*/
#line 694 "./marpa.w"
struct marpa_g;
/*:43*//*604:*/
#line 5347 "./marpa.w"

struct marpa_r;
/*:604*/
#line 687 "./marpa.w"

/*52:*/
#line 733 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:52*//*131:*/
#line 1127 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:131*//*137:*/
#line 1149 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:137*//*214:*/
#line 1535 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:214*//*447:*/
#line 3562 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:447*//*493:*/
#line 3950 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:493*//*615:*/
#line 5428 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:615*//*700:*/
#line 5897 "./marpa.w"
typedef gint Marpa_Earleme;
/*:700*//*702:*/
#line 5901 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:702*//*732:*/
#line 6125 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:732*//*1009:*/
#line 9321 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:1009*//*1073:*/
#line 10244 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:1073*//*1186:*/
#line 11557 "./marpa.w"

typedef gint Marpa_Fork_ID;
/*:1186*//*1384:*/
#line 13404 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1384*/
#line 688 "./marpa.w"

/*207:*/
#line 1503 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:207*//*315:*/
#line 2280 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:315*//*1386:*/
#line 13411 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1386*/
#line 689 "./marpa.w"

/*117:*/
#line 1025 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:117*//*118:*/
#line 1030 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:118*//*119:*/
#line 1035 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:119*//*681:*/
#line 5788 "./marpa.w"

struct marpa_r_event{
gint t_type;
};
/*:681*//*1207:*/
#line 11724 "./marpa.w"

struct marpa_event{
Marpa_Symbol_ID marpa_token_id;
gpointer marpa_value;
Marpa_Rule_ID marpa_rule_id;
gint marpa_arg_0;
gint marpa_arg_n;
};
typedef struct marpa_event Marpa_Event;
/*:1207*/
#line 690 "./marpa.w"

/*41:*/
#line 665 "./marpa.w"

void marpa_version(int*version);

/*:41*//*47:*/
#line 710 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:47*//*49:*/
#line 718 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:49*//*56:*/
#line 739 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:56*//*61:*/
#line 761 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:61*//*71:*/
#line 808 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:71*//*77:*/
#line 837 "./marpa.w"

gpointer marpa_default_value(struct marpa_g*g);
/*:77*//*79:*/
#line 842 "./marpa.w"

gboolean marpa_default_value_set(struct marpa_g*g,gpointer default_value);
/*:79*//*84:*/
#line 860 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:84*//*86:*/
#line 873 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:86*//*96:*/
#line 927 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);
/*:96*//*102:*/
#line 945 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);
/*:102*//*107:*/
#line 967 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:107*//*109:*/
#line 982 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:109*//*127:*/
#line 1092 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:127*//*136:*/
#line 1144 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:136*//*143:*/
#line 1184 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:143*//*153:*/
#line 1226 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:153*//*160:*/
#line 1256 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:160*//*166:*/
#line 1279 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);

/*:166*//*170:*/
#line 1297 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:170*//*174:*/
#line 1315 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);

/*:174*//*178:*/
#line 1336 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);

/*:178*//*182:*/
#line 1356 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:182*//*184:*/
#line 1362 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:184*//*188:*/
#line 1380 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);

/*:188*//*193:*/
#line 1400 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:193*//*199:*/
#line 1440 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:199*//*202:*/
#line 1468 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:202*//*211:*/
#line 1518 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:211*//*221:*/
#line 1580 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:221*//*223:*/
#line 1604 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:223*//*251:*/
#line 1973 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:251*//*254:*/
#line 1980 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix);
/*:254*//*259:*/
#line 2001 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:259*//*267:*/
#line 2031 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:267*//*272:*/
#line 2076 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:272*//*276:*/
#line 2100 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:276*//*281:*/
#line 2120 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:281*//*286:*/
#line 2141 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:286*//*293:*/
#line 2177 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:293*//*297:*/
#line 2193 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:297*//*301:*/
#line 2223 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:301*//*305:*/
#line 2238 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:305*//*309:*/
#line 2254 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:309*//*313:*/
#line 2270 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:313*//*319:*/
#line 2291 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:319*//*321:*/
#line 2296 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:321*//*323:*/
#line 2301 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:323*//*330:*/
#line 2327 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:330*//*334:*/
#line 2339 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:334*//*339:*/
#line 2362 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:339*//*349:*/
#line 2450 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:349*//*463:*/
#line 3655 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:463*//*465:*/
#line 3666 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:465*//*466:*/
#line 3670 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:466*//*468:*/
#line 3682 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:468*//*470:*/
#line 3693 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:470*//*518:*/
#line 4119 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:518*//*520:*/
#line 4132 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:520*//*521:*/
#line 4135 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:521*//*524:*/
#line 4170 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:524*//*526:*/
#line 4180 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:526*//*531:*/
#line 4244 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:531*//*597:*/
#line 5278 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:597*//*600:*/
#line 5312 "./marpa.w"

/*:600*//*601:*/
#line 5313 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:601*//*607:*/
#line 5358 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);
/*:607*//*611:*/
#line 5402 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:611*//*618:*/
#line 5441 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:618*//*624:*/
#line 5469 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:624*//*630:*/
#line 5491 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:630*//*632:*/
#line 5497 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:632*//*636:*/
#line 5518 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:636*//*655:*/
#line 5611 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:655*//*671:*/
#line 5722 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:671*//*673:*/
#line 5734 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);
/*:673*//*677:*/
#line 5763 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:677*//*695:*/
#line 5865 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);
/*:695*//*718:*/
#line 6003 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:718*//*720:*/
#line 6019 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:720*//*722:*/
#line 6038 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:722*//*725:*/
#line 6064 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:725*//*754:*/
#line 6360 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:754*//*757:*/
#line 6400 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:757*//*762:*/
#line 6456 "./marpa.w"

Marpa_Earley_Set_ID marpa_earley_item_origin(struct marpa_r*r);
/*:762*//*770:*/
#line 6548 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r);
/*:770*//*772:*/
#line 6572 "./marpa.w"

Marpa_Earley_Set_ID marpa_leo_base_origin(struct marpa_r*r);
/*:772*//*774:*/
#line 6592 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r);
/*:774*//*776:*/
#line 6614 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r);
/*:776*//*790:*/
#line 6751 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:790*//*793:*/
#line 6790 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:793*//*795:*/
#line 6824 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:795*//*834:*/
#line 7239 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:834*//*838:*/
#line 7285 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:838*//*841:*/
#line 7318 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:841*//*845:*/
#line 7363 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:845*//*848:*/
#line 7398 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:848*//*852:*/
#line 7446 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:852*//*858:*/
#line 7504 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:858*//*860:*/
#line 7547 "./marpa.w"

Marpa_Symbol_ID marpa_source_token(struct marpa_r*r,gpointer*value_p);
/*:860*//*863:*/
#line 7581 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:863*//*866:*/
#line 7624 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:866*//*895:*/
#line 7931 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:895*//*903:*/
#line 8016 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length);
/*:903*//*921:*/
#line 8162 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:921*//*1091:*/
#line 10427 "./marpa.w"

Marpa_Symbol_ID marpa_and_node_token(struct marpa_r*r,
Marpa_And_Node_ID and_node_id,gpointer*value_p);
/*:1091*//*1105:*/
#line 10504 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal_arg);
/*:1105*//*1123:*/
#line 10772 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1123*//*1149:*/
#line 10991 "./marpa.w"

int marpa_tree_new(struct marpa_r*r);
/*:1149*//*1164:*/
#line 11244 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r);
/*:1164*//*1178:*/
#line 11367 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length);
/*:1178*//*1184:*/
#line 11498 "./marpa.w"

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix);
/*:1184*//*1213:*/
#line 11791 "./marpa.w"

int marpa_val_new(struct marpa_r*r);
/*:1213*//*1220:*/
#line 11890 "./marpa.w"

gint marpa_val_trace(struct marpa_r*r,gint flag);
/*:1220*//*1222:*/
#line 11905 "./marpa.w"

Marpa_Fork_ID marpa_val_fork(struct marpa_r*r);
/*:1222*//*1224:*/
#line 11919 "./marpa.w"

Marpa_Fork_ID marpa_val_event(struct marpa_r*r,Marpa_Event*event);
/*:1224*//*1390:*/
#line 13426 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1390*/
#line 691 "./marpa.w"


/*:42*/
#line 13658 "./marpa.w"

#endif __MARPA_H__

/*:1408*/
