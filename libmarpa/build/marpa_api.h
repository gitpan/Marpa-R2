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
 * This file is written by texi2proto.pl
 * It is not intended to be modified directly
 */


const char* marpa_check_version (unsigned int required_major, unsigned int required_minor, unsigned int required_micro );
Marpa_Grammar marpa_g_new ( guint required_major, guint required_minor, guint required_micro);
void marpa_g_unref (Marpa_Grammar g);
Marpa_Grammar marpa_g_ref (Marpa_Grammar g);
Marpa_Symbol_ID marpa_g_symbol_new (Marpa_Grammar g);
Marpa_Symbol_ID marpa_g_start_symbol_set ( Marpa_Grammar g, Marpa_Symbol_ID id);
Marpa_Symbol_ID marpa_g_start_symbol (Marpa_Grammar g);
gint marpa_g_symbol_count (Marpa_Grammar g);
gint marpa_g_is_lhs_terminal_ok (Marpa_Grammar g);
gint marpa_g_is_lhs_terminal_ok_set ( Marpa_Grammar g, gint value);
gint marpa_g_symbol_is_terminal ( Marpa_Grammar g, Marpa_Symbol_ID symid);
gint marpa_g_symbol_is_terminal_set ( Marpa_Grammar g, Marpa_Symbol_ID symid, gint value);
gint marpa_g_symbol_is_accessible (Marpa_Grammar g, Marpa_Symbol_ID symid);
gint marpa_g_symbol_is_counted (Marpa_Grammar g, Marpa_Symbol_ID symid);
gint marpa_g_symbol_is_nullable (Marpa_Grammar g, Marpa_Symbol_ID symid);
gint marpa_g_symbol_is_nulling (Marpa_Grammar g, Marpa_Symbol_ID symid);
gint marpa_g_symbol_is_productive (Marpa_Grammar g, Marpa_Symbol_ID symid);
gint marpa_g_rule_count (Marpa_Grammar g);
Marpa_Rule_ID marpa_g_rule_new (Marpa_Grammar g, Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length);
gint marpa_g_sequence_new (Marpa_Grammar g, Marpa_Symbol_ID lhs_id, Marpa_Symbol_ID rhs_id, Marpa_Symbol_ID separator_id, gint min, gint flags );
gint marpa_g_rule_is_accessible (Marpa_Grammar g, Marpa_Rule_ID id);
gint marpa_g_rule_is_productive (Marpa_Grammar g, Marpa_Rule_ID id);
gint marpa_g_rule_is_loop (Marpa_Grammar g, Marpa_Rule_ID rule_id);
Marpa_Symbol_ID marpa_g_rule_lhs ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_rule_length ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_rule_is_discard_separation ( Marpa_Grammar g, Marpa_Rule_ID id);
Marpa_Symbol_ID marpa_g_rule_rh_symbol ( Marpa_Grammar g, Marpa_Rule_ID rule_id, gint ix);
gint marpa_g_rule_whatever_set ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_rule_first_child_set ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_rule_ask_me_set ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_rule_is_ask_me ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_precompute (Marpa_Grammar g);
gint marpa_g_is_precomputed (Marpa_Grammar g);
gint marpa_g_has_loop (Marpa_Grammar g);
gint marpa_g_symbol_is_start ( Marpa_Grammar g, Marpa_Symbol_ID symid);
gint marpa_g_symbol_ask_me_when_null_set ( Marpa_Grammar g, Marpa_Symbol_ID symbol_id);
gint marpa_g_symbol_is_ask_me_when_null ( Marpa_Grammar g, Marpa_Symbol_ID symbol_id);
gint marpa_g_symbol_lhs_count (Marpa_Grammar g, Marpa_Symbol_ID symid);
Marpa_Rule_ID marpa_g_symbol_lhs (Marpa_Grammar g, Marpa_Symbol_ID symid, gint ix);
gint marpa_g_symbol_rhs_count (Marpa_Grammar g, Marpa_Symbol_ID symid);
Marpa_Rule_ID marpa_g_symbol_rhs (Marpa_Grammar g, Marpa_Symbol_ID symid, gint ix);
Marpa_Symbol_ID marpa_g_symbol_proper_alias (Marpa_Grammar g, Marpa_Symbol_ID symid);
Marpa_Symbol_ID marpa_g_symbol_null_alias (Marpa_Grammar g, Marpa_Symbol_ID symid);
Marpa_Rule_ID marpa_g_symbol_virtual_lhs_rule (Marpa_Grammar g, Marpa_Symbol_ID symid);
gint marpa_g_rule_is_virtual_loop (Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_rule_is_used (Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_rule_is_virtual_lhs (Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_rule_is_virtual_rhs (Marpa_Grammar g, Marpa_Rule_ID rule_id);
guint marpa_g_virtual_start (Marpa_Grammar g, Marpa_Rule_ID rule_id);
guint marpa_g_virtual_end (Marpa_Grammar g, Marpa_Rule_ID rule_id);
Marpa_Rule_ID marpa_g_rule_original (Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_real_symbol_count (Marpa_Grammar g, Marpa_Rule_ID rule_id);
Marpa_Rule_ID marpa_g_rule_semantic_equivalent (Marpa_Grammar g, Marpa_Rule_ID rule_id);
gint marpa_g_AHFA_item_count (Marpa_Grammar g);
Marpa_Rule_ID marpa_g_AHFA_item_rule (Marpa_Grammar g, Marpa_AHFA_Item_ID item_id);
gint marpa_g_AHFA_item_position (Marpa_Grammar g, Marpa_AHFA_Item_ID item_id);
Marpa_Symbol_ID marpa_g_AHFA_item_postdot (Marpa_Grammar g, Marpa_AHFA_Item_ID item_id);
gint marpa_g_AHFA_item_sort_key (Marpa_Grammar g, Marpa_AHFA_Item_ID item_id);
gint marpa_g_AHFA_state_count (Marpa_Grammar g);
gint marpa_g_AHFA_state_item_count (Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id);
Marpa_AHFA_Item_ID marpa_g_AHFA_state_item (Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id, gint item_ix);
gint marpa_g_AHFA_state_is_predict (Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id);
Marpa_Symbol_ID marpa_g_AHFA_state_leo_lhs_symbol (Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id);
gint marpa_g_AHFA_state_transitions (Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id, GArray *result);
Marpa_AHFA_State_ID marpa_g_AHFA_state_empty_transition (Marpa_Grammar g, Marpa_AHFA_Item_ID AHFA_item_id);
gint marpa_g_event (Marpa_Grammar g, Marpa_Event public_event, gint ix);
Marpa_Recognizer marpa_r_new ( Marpa_Grammar g );
Marpa_Recognizer marpa_r_ref (Marpa_Recognizer r);
void marpa_r_unref (Marpa_Recognizer r);
gint marpa_r_start_input (Marpa_Recognizer r);
gint marpa_r_alternative (Marpa_Recognizer r, Marpa_Symbol_ID token_id, gpointer value, gint length);
Marpa_Earleme marpa_r_earleme_complete (Marpa_Recognizer r);
Marpa_Error_Code marpa_r_error (Marpa_Recognizer r, const char** p_error_string);
Marpa_Earleme marpa_r_earleme ( Marpa_Recognizer r, Marpa_Earley_Set_ID set_id);
guint marpa_r_current_earleme (Marpa_Recognizer r);
gint marpa_r_earley_item_warning_threshold (Marpa_Recognizer r);
gint marpa_r_earley_item_warning_threshold_set (Marpa_Recognizer r, gint threshold);
guint marpa_r_furthest_earleme (Marpa_Recognizer r);
gint marpa_r_terminals_expected (Marpa_Recognizer r, GArray* result);
gint marpa_r_is_use_leo (Marpa_Recognizer r);
gint marpa_r_is_use_leo_set ( Marpa_Recognizer r, gint value);
gint marpa_r_is_exhausted (Marpa_Recognizer r);
gint marpa_r_event (Marpa_Recognizer r, Marpa_Event public_event, gint ix);
Marpa_Earley_Set_ID marpa_r_trace_earley_set (Marpa_Recognizer r);
Marpa_Earley_Set_ID marpa_r_latest_earley_set (Marpa_Recognizer r);
gint marpa_r_earley_set_size (Marpa_Recognizer r, Marpa_Earley_Set_ID set_id);
Marpa_Earleme marpa_r_earley_set_trace (Marpa_Recognizer r, Marpa_Earley_Set_ID set_id);
Marpa_AHFA_State_ID marpa_r_earley_item_trace (Marpa_Recognizer r, Marpa_Earley_Item_ID item_id);
Marpa_Earley_Set_ID marpa_r_earley_item_origin (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_leo_predecessor_symbol (Marpa_Recognizer r);
Marpa_Earley_Set_ID marpa_r_leo_base_origin (Marpa_Recognizer r);
Marpa_AHFA_State_ID marpa_r_leo_base_state (Marpa_Recognizer r);
Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_postdot_symbol_trace (Marpa_Recognizer r, Marpa_Symbol_ID symid);
Marpa_Symbol_ID marpa_r_first_postdot_item_trace (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_next_postdot_item_trace (Marpa_Recognizer r);
Marpa_AHFA_State_ID marpa_r_postdot_item_symbol (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_first_token_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_next_token_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_first_completion_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_next_completion_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_first_leo_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_next_leo_link_trace (Marpa_Recognizer r);
Marpa_AHFA_State_ID marpa_r_source_predecessor_state (Marpa_Recognizer r);
Marpa_Symbol_ID marpa_r_source_token (Marpa_Recognizer r, gpointer *value_p);
Marpa_Symbol_ID marpa_r_source_leo_transition_symbol (Marpa_Recognizer r);
Marpa_Earley_Set_ID marpa_r_source_middle (Marpa_Recognizer r);
Marpa_Bocage marpa_b_new (Marpa_Recognizer r, Marpa_Rule_ID rule_id, Marpa_Earley_Set_ID ordinal_arg);
Marpa_Grammar marpa_b_g (Marpa_Bocage b);
Marpa_Bocage marpa_b_ref (Marpa_Bocage b);
void marpa_b_unref (Marpa_Bocage b);
gint marpa_b_and_node_count ( Marpa_Bocage b);
gint marpa_b_and_node_parent ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id);
gint marpa_b_and_node_predecessor ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id);
gint marpa_b_and_node_cause ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id);
gint marpa_b_and_node_symbol ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id);
Marpa_Symbol_ID marpa_b_and_node_token ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id, gpointer* value_p);
Marpa_Or_Node_ID marpa_b_top_or_node ( Marpa_Bocage b);
gint marpa_b_or_node_set ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
gint marpa_b_or_node_origin ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
gint marpa_b_or_node_rule ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
gint marpa_b_or_node_position ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
gint marpa_b_or_node_first_and ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
gint marpa_b_or_node_last_and ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
gint marpa_b_or_node_and_count ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
Marpa_Order marpa_o_new ( Marpa_Bocage b);
Marpa_Grammar marpa_o_g ( Marpa_Order o);
void marpa_o_unref ( Marpa_Order o);
Marpa_Order marpa_o_ref ( Marpa_Order o);
gint marpa_o_and_order_set ( Marpa_Order o, Marpa_Or_Node_ID or_node_id, Marpa_And_Node_ID* and_node_ids, gint length);
Marpa_And_Node_ID marpa_o_and_order_get ( Marpa_Order o, Marpa_Or_Node_ID or_node_id, gint ix);
Marpa_Tree marpa_t_new (Marpa_Order o);
Marpa_Grammar marpa_t_g (Marpa_Tree o);
Marpa_Tree marpa_t_ref (Marpa_Tree t);
void marpa_t_unref (Marpa_Tree t);
gint marpa_t_next ( Marpa_Tree t);
gint marpa_t_parse_count ( Marpa_Tree t);
gint marpa_t_size ( Marpa_Tree t);
Marpa_Or_Node_ID marpa_t_nook_or_node ( Marpa_Tree t, Marpa_Nook_ID nook_id);
gint marpa_t_nook_choice ( Marpa_Tree t, Marpa_Nook_ID nook_id );
gint marpa_t_nook_parent ( Marpa_Tree t, Marpa_Nook_ID nook_id );
gint marpa_t_nook_cause_is_ready ( Marpa_Tree t, Marpa_Nook_ID nook_id );
gint marpa_t_nook_predecessor_is_ready ( Marpa_Tree t, Marpa_Nook_ID nook_id );
gint marpa_t_nook_is_cause ( Marpa_Tree t, Marpa_Nook_ID nook_id );
gint marpa_t_nook_is_predecessor ( Marpa_Tree t, Marpa_Nook_ID nook_id );
Marpa_Value marpa_v_new ( Marpa_Tree t);
Marpa_Grammar marpa_v_g (Marpa_Value v);
void marpa_v_unref (Marpa_Value v);
Marpa_Value marpa_v_ref (Marpa_Value v);
Marpa_Value_Type marpa_v_step ( Marpa_Value v);
gint marpa_v_trace ( Marpa_Value v, gint flag);
Marpa_Nook_ID marpa_v_nook ( Marpa_Value v);
Marpa_Error_Code marpa_g_error ( Marpa_Grammar g, const char** p_error_string);
#define MARPA_ERROR_COUNT 16
#define MARPA_ERR_NONE 0
#define MARPA_ERR_UNKNOWN 1
#define MARPA_ERR_INTERNAL 2
#define MARPA_ERR_DEVELOPMENT 3
#define MARPA_ERR_COUNTED_NULLABLE 4
#define MARPA_ERR_DUPLICATE_RULE 5
#define MARPA_ERR_EIM_COUNT 6
#define MARPA_ERR_LHS_IS_TERMINAL 7
#define MARPA_ERR_NO_PARSE 8
#define MARPA_ERR_NO_RULES 9
#define MARPA_ERR_NO_START_SYMBOL 10
#define MARPA_ERR_NULL_RULE_UNMARKED_TERMINALS 11
#define MARPA_ERR_ORDER_FROZEN 12
#define MARPA_ERR_PRECOMPUTED 13
#define MARPA_ERR_START_NOT_LHS 14
#define MARPA_ERR_UNPRODUCTIVE_START 15
#define MARPA_EVENT_COUNT 7
#define MARPA_EVENT_NONE 0
#define MARPA_EVENT_EXHAUSTED 1
#define MARPA_EVENT_EARLEY_ITEM_THRESHOLD 2
#define MARPA_EVENT_LOOP_RULES 3
#define MARPA_EVENT_NEW_SYMBOL 4
#define MARPA_EVENT_NEW_RULE 5
#define MARPA_EVENT_COUNTED_NULLABLE 6
#define MARPA_VALUE_TYPE_COUNT 7
#define MARPA_VALUE_INTERNAL1 0
#define MARPA_VALUE_RULE 1
#define MARPA_VALUE_TOKEN 2
#define MARPA_VALUE_NULLING_TOKEN 3
#define MARPA_VALUE_TRACE 4
#define MARPA_VALUE_INACTIVE 5
#define MARPA_VALUE_INTERNAL2 6
