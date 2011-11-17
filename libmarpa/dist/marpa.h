/*1375:*/
#line 13465 "./marpa.w"

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

/*:1375*//*1376:*/
#line 13489 "./marpa.w"

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
/*111:*/
#line 1001 "./marpa.w"

#define MARPA_G_EV_NONE 0
#define MARPA_G_EV_EXHAUSTED 1
#define MARPA_G_EV_EARLEY_ITEM_THRESHOLD 2
#define MARPA_G_EV_LOOP_RULES 3
#define MARPA_G_EV_NEW_SYMBOL 4
#define MARPA_G_EV_NEW_RULE 5
/*:111*//*257:*/
#line 2030 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:257*//*262:*/
#line 2063 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:262*/
#line 686 "./marpa.w"

/*43:*/
#line 693 "./marpa.w"
struct marpa_g;
/*:43*//*586:*/
#line 5299 "./marpa.w"

struct marpa_r;
/*:586*/
#line 687 "./marpa.w"

/*113:*/
#line 1011 "./marpa.w"

typedef gint Marpa_Event_Type;
/*:113*//*128:*/
#line 1125 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:128*//*134:*/
#line 1147 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:134*//*208:*/
#line 1531 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:208*//*429:*/
#line 3517 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:429*//*475:*/
#line 3905 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:475*//*597:*/
#line 5380 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:597*//*676:*/
#line 5784 "./marpa.w"
typedef gint Marpa_Earleme;
/*:676*//*678:*/
#line 5788 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:678*//*708:*/
#line 6012 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:708*//*986:*/
#line 9214 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:986*//*1050:*/
#line 10137 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:1050*//*1163:*/
#line 11450 "./marpa.w"

typedef gint Marpa_Fork_ID;
/*:1163*//*1360:*/
#line 13276 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1360*/
#line 688 "./marpa.w"

/*114:*/
#line 1013 "./marpa.w"

struct marpa_g_event{
Marpa_Event_Type t_type;
gint t_value;
};
/*:114*//*1184:*/
#line 11617 "./marpa.w"

struct marpa_event{
Marpa_Symbol_ID marpa_token_id;
gpointer marpa_value;
Marpa_Rule_ID marpa_rule_id;
gint marpa_arg_0;
gint marpa_arg_n;
};
typedef struct marpa_event Marpa_Event;
/*:1184*/
#line 689 "./marpa.w"

/*41:*/
#line 665 "./marpa.w"

void marpa_version(int*version);

/*:41*//*47:*/
#line 709 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:47*//*49:*/
#line 717 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:49*//*54:*/
#line 739 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:54*//*55:*/
#line 744 "./marpa.w"

gint marpa_symbol_count(struct marpa_g*g);
/*:55*//*65:*/
#line 787 "./marpa.w"

gint marpa_rule_count(struct marpa_g*g);
/*:65*//*68:*/
#line 800 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:68*//*74:*/
#line 829 "./marpa.w"

gpointer marpa_default_value(struct marpa_g*g);
/*:74*//*76:*/
#line 834 "./marpa.w"

gboolean marpa_default_value_set(struct marpa_g*g,gpointer default_value);
/*:76*//*81:*/
#line 852 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:81*//*83:*/
#line 865 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:83*//*94:*/
#line 922 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);
/*:94*//*100:*/
#line 940 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);
/*:100*//*105:*/
#line 962 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:105*//*107:*/
#line 977 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:107*//*133:*/
#line 1142 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:133*//*140:*/
#line 1182 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:140*//*150:*/
#line 1222 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:150*//*157:*/
#line 1252 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:157*//*163:*/
#line 1275 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);

/*:163*//*167:*/
#line 1293 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:167*//*171:*/
#line 1311 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);

/*:171*//*175:*/
#line 1332 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);

/*:175*//*179:*/
#line 1352 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:179*//*181:*/
#line 1358 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:181*//*185:*/
#line 1376 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);

/*:185*//*190:*/
#line 1396 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:190*//*196:*/
#line 1436 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:196*//*199:*/
#line 1463 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:199*//*206:*/
#line 1515 "./marpa.w"

Marpa_Rule_ID marpa_symbol_virtual_lhs_rule(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:206*//*215:*/
#line 1576 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:215*//*217:*/
#line 1599 "./marpa.w"

gint marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:217*//*245:*/
#line 1980 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:245*//*248:*/
#line 1987 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix);
/*:248*//*253:*/
#line 2008 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:253*//*261:*/
#line 2038 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:261*//*266:*/
#line 2083 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:266*//*270:*/
#line 2107 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:270*//*275:*/
#line 2127 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:275*//*280:*/
#line 2148 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:280*//*287:*/
#line 2184 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:287*//*291:*/
#line 2200 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:291*//*295:*/
#line 2230 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:295*//*299:*/
#line 2245 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:299*//*303:*/
#line 2261 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:303*//*307:*/
#line 2277 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:307*//*312:*/
#line 2293 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:312*//*316:*/
#line 2305 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:316*//*321:*/
#line 2328 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:321*//*331:*/
#line 2419 "./marpa.w"

gint marpa_precompute(struct marpa_g*g);

/*:331*//*445:*/
#line 3610 "./marpa.w"

gint marpa_AHFA_item_count(struct marpa_g*g);

/*:445*//*447:*/
#line 3621 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:447*//*448:*/
#line 3625 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:448*//*450:*/
#line 3637 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:450*//*452:*/
#line 3648 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:452*//*500:*/
#line 4074 "./marpa.w"

gint marpa_AHFA_state_count(struct marpa_g*g);

/*:500*//*502:*/
#line 4087 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:502*//*503:*/
#line 4090 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:503*//*506:*/
#line 4122 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:506*//*508:*/
#line 4132 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:508*//*513:*/
#line 4196 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:513*//*579:*/
#line 5230 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:579*//*582:*/
#line 5264 "./marpa.w"

/*:582*//*583:*/
#line 5265 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:583*//*589:*/
#line 5310 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);
/*:589*//*593:*/
#line 5354 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:593*//*600:*/
#line 5393 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:600*//*606:*/
#line 5421 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:606*//*612:*/
#line 5443 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:612*//*614:*/
#line 5449 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:614*//*618:*/
#line 5470 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:618*//*637:*/
#line 5563 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:637*//*653:*/
#line 5676 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:653*//*655:*/
#line 5688 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);
/*:655*//*659:*/
#line 5717 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:659*//*667:*/
#line 5741 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);
/*:667*//*671:*/
#line 5752 "./marpa.w"

gint marpa_r_event(const struct marpa_r*r,struct marpa_g_event*public_event,gint ix);
/*:671*//*694:*/
#line 5890 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:694*//*696:*/
#line 5906 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:696*//*698:*/
#line 5925 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:698*//*701:*/
#line 5951 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:701*//*730:*/
#line 6246 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:730*//*733:*/
#line 6286 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:733*//*738:*/
#line 6342 "./marpa.w"

Marpa_Earley_Set_ID marpa_earley_item_origin(struct marpa_r*r);
/*:738*//*746:*/
#line 6434 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r);
/*:746*//*748:*/
#line 6458 "./marpa.w"

Marpa_Earley_Set_ID marpa_leo_base_origin(struct marpa_r*r);
/*:748*//*750:*/
#line 6478 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r);
/*:750*//*752:*/
#line 6500 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r);
/*:752*//*766:*/
#line 6637 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:766*//*769:*/
#line 6676 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:769*//*771:*/
#line 6710 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:771*//*810:*/
#line 7125 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:810*//*814:*/
#line 7171 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:814*//*817:*/
#line 7204 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:817*//*821:*/
#line 7249 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:821*//*824:*/
#line 7284 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:824*//*828:*/
#line 7332 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:828*//*834:*/
#line 7390 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:834*//*836:*/
#line 7433 "./marpa.w"

Marpa_Symbol_ID marpa_source_token(struct marpa_r*r,gpointer*value_p);
/*:836*//*839:*/
#line 7467 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:839*//*842:*/
#line 7510 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:842*//*871:*/
#line 7817 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:871*//*879:*/
#line 7902 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length);
/*:879*//*897:*/
#line 8046 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:897*//*1068:*/
#line 10320 "./marpa.w"

Marpa_Symbol_ID marpa_and_node_token(struct marpa_r*r,
Marpa_And_Node_ID and_node_id,gpointer*value_p);
/*:1068*//*1082:*/
#line 10397 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal_arg);
/*:1082*//*1100:*/
#line 10665 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1100*//*1126:*/
#line 10884 "./marpa.w"

int marpa_tree_new(struct marpa_r*r);
/*:1126*//*1141:*/
#line 11137 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r);
/*:1141*//*1155:*/
#line 11260 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length);
/*:1155*//*1161:*/
#line 11391 "./marpa.w"

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix);
/*:1161*//*1190:*/
#line 11684 "./marpa.w"

int marpa_val_new(struct marpa_r*r);
/*:1190*//*1197:*/
#line 11783 "./marpa.w"

gint marpa_val_trace(struct marpa_r*r,gint flag);
/*:1197*//*1199:*/
#line 11798 "./marpa.w"

Marpa_Fork_ID marpa_val_fork(struct marpa_r*r);
/*:1199*//*1201:*/
#line 11812 "./marpa.w"

Marpa_Fork_ID marpa_val_event(struct marpa_r*r,Marpa_Event*event);
/*:1201*/
#line 690 "./marpa.w"


/*:42*/
#line 13494 "./marpa.w"

#endif __MARPA_H__

/*:1376*/
