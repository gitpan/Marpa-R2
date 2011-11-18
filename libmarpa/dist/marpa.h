/*1374:*/
#line 13502 "./marpa.w"

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

/*:1374*//*1375:*/
#line 13526 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*45:*/
#line 685 "./marpa.w"

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
/*110:*/
#line 995 "./marpa.w"

#define MARPA_G_EV_NONE 0
#define MARPA_G_EV_EXHAUSTED 1
#define MARPA_G_EV_EARLEY_ITEM_THRESHOLD 2
#define MARPA_G_EV_LOOP_RULES 3
#define MARPA_G_EV_NEW_SYMBOL 4
#define MARPA_G_EV_NEW_RULE 5
/*:110*//*256:*/
#line 2067 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:256*//*261:*/
#line 2100 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:261*/
#line 698 "./marpa.w"

/*46:*/
#line 705 "./marpa.w"
struct marpa_g;
/*:46*//*585:*/
#line 5336 "./marpa.w"

struct marpa_r;
/*:585*/
#line 699 "./marpa.w"

/*112:*/
#line 1005 "./marpa.w"

typedef gint Marpa_Event_Type;
/*:112*//*127:*/
#line 1119 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:127*//*133:*/
#line 1141 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:133*//*207:*/
#line 1568 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:207*//*428:*/
#line 3554 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:428*//*474:*/
#line 3942 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:474*//*596:*/
#line 5417 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:596*//*675:*/
#line 5821 "./marpa.w"
typedef gint Marpa_Earleme;
/*:675*//*677:*/
#line 5825 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:677*//*707:*/
#line 6049 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:707*//*985:*/
#line 9251 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:985*//*1049:*/
#line 10174 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:1049*//*1162:*/
#line 11487 "./marpa.w"

typedef gint Marpa_Fork_ID;
/*:1162*//*1359:*/
#line 13313 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1359*/
#line 700 "./marpa.w"

/*113:*/
#line 1007 "./marpa.w"

struct marpa_g_event{
Marpa_Event_Type t_type;
gint t_value;
};
/*:113*//*1183:*/
#line 11654 "./marpa.w"

struct marpa_event{
Marpa_Symbol_ID marpa_token_id;
gpointer marpa_value;
Marpa_Rule_ID marpa_rule_id;
gint marpa_arg_0;
gint marpa_arg_n;
};
typedef struct marpa_event Marpa_Event;
/*:1183*/
#line 701 "./marpa.w"

/*44:*/
#line 677 "./marpa.w"

void marpa_version(int*version);

/*:44*//*50:*/
#line 721 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:50*//*52:*/
#line 729 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:52*//*56:*/
#line 747 "./marpa.w"

gint marpa_g_symbol_count(struct marpa_g*g);
/*:56*//*66:*/
#line 790 "./marpa.w"

gint marpa_g_rule_count(struct marpa_g*g);
/*:66*//*73:*/
#line 823 "./marpa.w"

gpointer marpa_g_default_value(struct marpa_g*g);
/*:73*//*75:*/
#line 828 "./marpa.w"

gboolean marpa_g_default_value_set(struct marpa_g*g,gpointer default_value);
/*:75*//*80:*/
#line 846 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(struct marpa_g*g);
/*:80*//*82:*/
#line 859 "./marpa.w"

gboolean marpa_g_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:82*//*93:*/
#line 916 "./marpa.w"

gboolean marpa_g_is_precomputed(struct marpa_g*g);
/*:93*//*99:*/
#line 934 "./marpa.w"

gboolean marpa_g_has_loop(struct marpa_g*g);
/*:99*//*104:*/
#line 956 "./marpa.w"

gboolean marpa_g_is_lhs_terminal_ok(struct marpa_g*g);
/*:104*//*106:*/
#line 971 "./marpa.w"

gboolean marpa_g_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:106*//*132:*/
#line 1136 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:132*//*139:*/
#line 1176 "./marpa.w"

Marpa_Symbol_ID marpa_g_symbol_new(struct marpa_g*g);
/*:139*//*148:*/
#line 1209 "./marpa.w"

gint marpa_g_symbol_lhs_count(struct marpa_g*g,Marpa_Symbol_ID symid);
Marpa_Rule_ID marpa_g_symbol_lhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix);
/*:148*//*155:*/
#line 1260 "./marpa.w"

gint marpa_g_symbol_rhs_count(struct marpa_g*g,Marpa_Symbol_ID symid);
Marpa_Rule_ID marpa_g_symbol_rhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix);
/*:155*//*162:*/
#line 1312 "./marpa.w"

gboolean marpa_g_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);

/*:162*//*166:*/
#line 1330 "./marpa.w"

gboolean marpa_g_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:166*//*170:*/
#line 1348 "./marpa.w"

gboolean marpa_g_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);

/*:170*//*174:*/
#line 1369 "./marpa.w"

gint marpa_g_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);

/*:174*//*178:*/
#line 1389 "./marpa.w"

gboolean marpa_g_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:178*//*180:*/
#line 1395 "./marpa.w"

void marpa_g_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:180*//*184:*/
#line 1413 "./marpa.w"

gboolean marpa_g_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);

/*:184*//*189:*/
#line 1433 "./marpa.w"

gint marpa_g_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:189*//*195:*/
#line 1473 "./marpa.w"

Marpa_Symbol_ID marpa_g_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:195*//*198:*/
#line 1500 "./marpa.w"

Marpa_Symbol_ID marpa_g_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:198*//*205:*/
#line 1552 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_virtual_lhs_rule(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:205*//*214:*/
#line 1613 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:214*//*216:*/
#line 1636 "./marpa.w"

gint marpa_g_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:216*//*244:*/
#line 2017 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:244*//*247:*/
#line 2024 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix);
/*:247*//*252:*/
#line 2045 "./marpa.w"

gint marpa_g_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:252*//*260:*/
#line 2075 "./marpa.w"

gboolean marpa_g_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:260*//*265:*/
#line 2120 "./marpa.w"

gint marpa_g_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:265*//*269:*/
#line 2144 "./marpa.w"

gint marpa_g_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:269*//*274:*/
#line 2164 "./marpa.w"

gint marpa_g_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:274*//*279:*/
#line 2185 "./marpa.w"

gint marpa_g_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:279*//*286:*/
#line 2221 "./marpa.w"

gint marpa_g_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:286*//*290:*/
#line 2237 "./marpa.w"

gint marpa_g_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:290*//*294:*/
#line 2267 "./marpa.w"

gboolean marpa_g_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:294*//*298:*/
#line 2282 "./marpa.w"

gboolean marpa_g_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:298*//*302:*/
#line 2298 "./marpa.w"

guint marpa_g_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:302*//*306:*/
#line 2314 "./marpa.w"

guint marpa_g_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:306*//*311:*/
#line 2330 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:311*//*315:*/
#line 2342 "./marpa.w"

gint marpa_g_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:315*//*320:*/
#line 2365 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:320*//*330:*/
#line 2456 "./marpa.w"

gint marpa_g_precompute(struct marpa_g*g);

/*:330*//*444:*/
#line 3647 "./marpa.w"

gint marpa_g_AHFA_item_count(struct marpa_g*g);

/*:444*//*446:*/
#line 3658 "./marpa.w"

Marpa_Rule_ID marpa_g_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:446*//*447:*/
#line 3662 "./marpa.w"

gint marpa_g_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:447*//*449:*/
#line 3674 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:449*//*451:*/
#line 3685 "./marpa.w"

gint marpa_g_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:451*//*499:*/
#line 4111 "./marpa.w"

gint marpa_g_AHFA_state_count(struct marpa_g*g);

/*:499*//*501:*/
#line 4124 "./marpa.w"

gint marpa_g_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:501*//*502:*/
#line 4127 "./marpa.w"

Marpa_AHFA_Item_ID marpa_g_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:502*//*505:*/
#line 4159 "./marpa.w"

gint marpa_g_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:505*//*507:*/
#line 4169 "./marpa.w"

Marpa_Rule_ID marpa_g_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:507*//*512:*/
#line 4233 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:512*//*578:*/
#line 5267 "./marpa.w"

gint marpa_g_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:578*//*581:*/
#line 5301 "./marpa.w"

/*:581*//*582:*/
#line 5302 "./marpa.w"

Marpa_AHFA_State_ID marpa_g_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:582*//*588:*/
#line 5347 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);
/*:588*//*592:*/
#line 5391 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:592*//*599:*/
#line 5430 "./marpa.w"

Marpa_Phase marpa_r_phase(struct marpa_r*r);
/*:599*//*605:*/
#line 5458 "./marpa.w"

guint marpa_r_current_earleme(struct marpa_r*r);
/*:605*//*611:*/
#line 5480 "./marpa.w"

guint marpa_r_earley_item_warning_threshold(struct marpa_r*r);
/*:611*//*613:*/
#line 5486 "./marpa.w"

gboolean marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:613*//*617:*/
#line 5507 "./marpa.w"

guint marpa_r_furthest_earleme(struct marpa_r*r);
/*:617*//*636:*/
#line 5600 "./marpa.w"

gint marpa_r_terminals_expected(struct marpa_r*r,GArray*result);
/*:636*//*652:*/
#line 5713 "./marpa.w"

gboolean marpa_r_is_use_leo(struct marpa_r*r);
/*:652*//*654:*/
#line 5725 "./marpa.w"

gboolean marpa_r_is_use_leo_set(struct marpa_r*r,gboolean value);
/*:654*//*658:*/
#line 5754 "./marpa.w"

gboolean marpa_r_is_exhausted(struct marpa_r*r);
/*:658*//*666:*/
#line 5778 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);
/*:666*//*670:*/
#line 5789 "./marpa.w"

gint marpa_r_event(const struct marpa_r*r,struct marpa_g_event*public_event,gint ix);
/*:670*//*693:*/
#line 5927 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r);
/*:693*//*695:*/
#line 5943 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r);
/*:695*//*697:*/
#line 5962 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:697*//*700:*/
#line 5988 "./marpa.w"

gint marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:700*//*729:*/
#line 6283 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:729*//*732:*/
#line 6323 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:732*//*737:*/
#line 6379 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r);
/*:737*//*745:*/
#line 6471 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r);
/*:745*//*747:*/
#line 6495 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r);
/*:747*//*749:*/
#line 6515 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r);
/*:749*//*751:*/
#line 6537 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r);
/*:751*//*765:*/
#line 6674 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:765*//*768:*/
#line 6713 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r);
/*:768*//*770:*/
#line 6747 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r);
/*:770*//*809:*/
#line 7162 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r);
/*:809*//*813:*/
#line 7208 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r);
/*:813*//*816:*/
#line 7241 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r);
/*:816*//*820:*/
#line 7286 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r);
/*:820*//*823:*/
#line 7321 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_leo_link_trace(struct marpa_r*r);
/*:823*//*827:*/
#line 7369 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_leo_link_trace(struct marpa_r*r);
/*:827*//*833:*/
#line 7427 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_source_predecessor_state(struct marpa_r*r);
/*:833*//*835:*/
#line 7470 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,gpointer*value_p);
/*:835*//*838:*/
#line 7504 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r);
/*:838*//*841:*/
#line 7547 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r);
/*:841*//*870:*/
#line 7854 "./marpa.w"
gboolean marpa_r_start_input(struct marpa_r*r);
/*:870*//*878:*/
#line 7939 "./marpa.w"
gboolean marpa_r_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length);
/*:878*//*896:*/
#line 8083 "./marpa.w"

Marpa_Earleme marpa_r_earleme_complete(struct marpa_r*r);
/*:896*//*1067:*/
#line 10357 "./marpa.w"

Marpa_Symbol_ID marpa_b_and_node_token(struct marpa_r*r,
Marpa_And_Node_ID and_node_id,gpointer*value_p);
/*:1067*//*1081:*/
#line 10434 "./marpa.w"

gint marpa_b_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal_arg);
/*:1081*//*1099:*/
#line 10702 "./marpa.w"

gint marpa_b_free(struct marpa_r*r);
/*:1099*//*1125:*/
#line 10921 "./marpa.w"

int marpa_t_new(struct marpa_r*r);
/*:1125*//*1140:*/
#line 11174 "./marpa.w"

gint marpa_t_parse_count(struct marpa_r*r);
/*:1140*//*1154:*/
#line 11297 "./marpa.w"

gint marpa_o_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length);
/*:1154*//*1160:*/
#line 11428 "./marpa.w"

Marpa_And_Node_ID marpa_o_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix);
/*:1160*//*1189:*/
#line 11721 "./marpa.w"

int marpa_v_new(struct marpa_r*r);
/*:1189*//*1196:*/
#line 11820 "./marpa.w"

gint marpa_v_trace(struct marpa_r*r,gint flag);
/*:1196*//*1198:*/
#line 11835 "./marpa.w"

Marpa_Fork_ID marpa_v_fork(struct marpa_r*r);
/*:1198*//*1200:*/
#line 11849 "./marpa.w"

Marpa_Fork_ID marpa_v_event(struct marpa_r*r,Marpa_Event*event);
/*:1200*/
#line 702 "./marpa.w"


/*:45*/
#line 13531 "./marpa.w"

#endif __MARPA_H__

/*:1375*/
