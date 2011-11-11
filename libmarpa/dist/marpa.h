/*1422:*/
#line 13631 "./marpa.w"

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

/*:1422*//*1423:*/
#line 13655 "./marpa.w"

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
#line 1003 "./marpa.w"

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
#line 2010 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:263*//*268:*/
#line 2043 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:268*/
#line 686 "./marpa.w"

/*43:*/
#line 694 "./marpa.w"
struct marpa_g;
/*:43*//*605:*/
#line 5369 "./marpa.w"

struct marpa_r;
/*:605*/
#line 687 "./marpa.w"

/*52:*/
#line 733 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:52*//*131:*/
#line 1117 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:131*//*137:*/
#line 1136 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:137*//*214:*/
#line 1522 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:214*//*448:*/
#line 3547 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:448*//*494:*/
#line 3935 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:494*//*614:*/
#line 5429 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:614*//*622:*/
#line 5461 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:622*//*709:*/
#line 5926 "./marpa.w"
typedef gint Marpa_Earleme;
/*:709*//*711:*/
#line 5930 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:711*//*741:*/
#line 6150 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:741*//*1019:*/
#line 9363 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:1019*//*1083:*/
#line 10286 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:1083*//*1193:*/
#line 11555 "./marpa.w"

typedef gint Marpa_Fork_ID;
/*:1193*//*1391:*/
#line 13375 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1391*/
#line 688 "./marpa.w"

/*207:*/
#line 1490 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:207*//*315:*/
#line 2266 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:315*//*1393:*/
#line 13382 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1393*//*1401:*/
#line 13417 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1401*/
#line 689 "./marpa.w"

/*117:*/
#line 1015 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:117*//*118:*/
#line 1020 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:118*//*119:*/
#line 1025 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:119*//*1214:*/
#line 11715 "./marpa.w"

struct marpa_event{
Marpa_Symbol_ID marpa_token_id;
gpointer marpa_value;
Marpa_Rule_ID marpa_rule_id;
gint marpa_arg_0;
gint marpa_arg_n;
};
typedef struct marpa_event Marpa_Event;
/*:1214*/
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
#line 924 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:96*//*103:*/
#line 942 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:103*//*107:*/
#line 957 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:107*//*109:*/
#line 972 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:109*//*127:*/
#line 1082 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:127*//*136:*/
#line 1131 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:136*//*143:*/
#line 1171 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:143*//*153:*/
#line 1213 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:153*//*160:*/
#line 1243 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:160*//*166:*/
#line 1266 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);

/*:166*//*170:*/
#line 1284 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:170*//*174:*/
#line 1302 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);

/*:174*//*178:*/
#line 1323 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);

/*:178*//*182:*/
#line 1343 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:182*//*184:*/
#line 1349 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:184*//*188:*/
#line 1367 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);

/*:188*//*193:*/
#line 1387 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:193*//*199:*/
#line 1427 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:199*//*202:*/
#line 1455 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:202*//*211:*/
#line 1505 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:211*//*221:*/
#line 1567 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:221*//*223:*/
#line 1591 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:223*//*251:*/
#line 1960 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:251*//*254:*/
#line 1967 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix);
/*:254*//*259:*/
#line 1988 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:259*//*267:*/
#line 2018 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:267*//*272:*/
#line 2063 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:272*//*276:*/
#line 2087 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:276*//*281:*/
#line 2107 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:281*//*286:*/
#line 2128 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:286*//*293:*/
#line 2163 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:293*//*297:*/
#line 2179 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:297*//*301:*/
#line 2209 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:301*//*305:*/
#line 2224 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:305*//*309:*/
#line 2240 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:309*//*313:*/
#line 2256 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:313*//*319:*/
#line 2277 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:319*//*321:*/
#line 2282 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:321*//*323:*/
#line 2287 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:323*//*330:*/
#line 2313 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:330*//*334:*/
#line 2325 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:334*//*339:*/
#line 2348 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:339*//*349:*/
#line 2434 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:349*//*464:*/
#line 3640 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:464*//*466:*/
#line 3651 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:466*//*467:*/
#line 3655 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:467*//*469:*/
#line 3667 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:469*//*471:*/
#line 3678 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:471*//*519:*/
#line 4104 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:519*//*521:*/
#line 4117 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:521*//*522:*/
#line 4120 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:522*//*525:*/
#line 4155 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:525*//*527:*/
#line 4165 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:527*//*532:*/
#line 4229 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:532*//*598:*/
#line 5300 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:598*//*601:*/
#line 5334 "./marpa.w"

/*:601*//*602:*/
#line 5335 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:602*//*608:*/
#line 5380 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);
/*:608*//*611:*/
#line 5414 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:611*//*618:*/
#line 5435 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:618*//*625:*/
#line 5475 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:625*//*631:*/
#line 5503 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:631*//*637:*/
#line 5525 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:637*//*639:*/
#line 5531 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:639*//*643:*/
#line 5552 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:643*//*662:*/
#line 5645 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:662*//*678:*/
#line 5755 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:678*//*681:*/
#line 5776 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:681*//*684:*/
#line 5795 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:684*//*696:*/
#line 5864 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:696*//*705:*/
#line 5900 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:705*//*727:*/
#line 6032 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:727*//*729:*/
#line 6047 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:729*//*731:*/
#line 6065 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:731*//*734:*/
#line 6090 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:734*//*763:*/
#line 6385 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:763*//*766:*/
#line 6424 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:766*//*771:*/
#line 6479 "./marpa.w"

Marpa_Earley_Set_ID marpa_earley_item_origin(struct marpa_r*r);
/*:771*//*779:*/
#line 6571 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r);
/*:779*//*781:*/
#line 6594 "./marpa.w"

Marpa_Earley_Set_ID marpa_leo_base_origin(struct marpa_r*r);
/*:781*//*783:*/
#line 6613 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r);
/*:783*//*785:*/
#line 6634 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r);
/*:785*//*799:*/
#line 6770 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:799*//*802:*/
#line 6808 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:802*//*804:*/
#line 6841 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:804*//*843:*/
#line 7254 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:843*//*847:*/
#line 7299 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:847*//*850:*/
#line 7331 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:850*//*854:*/
#line 7375 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:854*//*857:*/
#line 7409 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:857*//*861:*/
#line 7456 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:861*//*867:*/
#line 7513 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:867*//*869:*/
#line 7555 "./marpa.w"

Marpa_Symbol_ID marpa_source_token(struct marpa_r*r,gpointer*value_p);
/*:869*//*872:*/
#line 7588 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:872*//*875:*/
#line 7630 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:875*//*904:*/
#line 7936 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:904*//*912:*/
#line 8020 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length);
/*:912*//*930:*/
#line 8166 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:930*//*1101:*/
#line 10464 "./marpa.w"

Marpa_Symbol_ID marpa_and_node_token(struct marpa_r*r,
Marpa_And_Node_ID and_node_id,gpointer*value_p);
/*:1101*//*1115:*/
#line 10540 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1115*//*1130:*/
#line 10783 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1130*//*1156:*/
#line 10994 "./marpa.w"

int marpa_tree_new(struct marpa_r*r);
/*:1156*//*1171:*/
#line 11246 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r);
/*:1171*//*1185:*/
#line 11367 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length);
/*:1185*//*1191:*/
#line 11497 "./marpa.w"

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix);
/*:1191*//*1220:*/
#line 11782 "./marpa.w"

int marpa_val_new(struct marpa_r*r);
/*:1220*//*1227:*/
#line 11880 "./marpa.w"

gint marpa_val_trace(struct marpa_r*r,gint flag);
/*:1227*//*1229:*/
#line 11894 "./marpa.w"

Marpa_Fork_ID marpa_val_fork(struct marpa_r*r);
/*:1229*//*1231:*/
#line 11907 "./marpa.w"

Marpa_Fork_ID marpa_val_event(struct marpa_r*r,Marpa_Event*event);
/*:1231*//*1397:*/
#line 13397 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1397*//*1405:*/
#line 13434 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1405*/
#line 691 "./marpa.w"


/*:42*/
#line 13660 "./marpa.w"

#endif __MARPA_H__

/*:1423*/
