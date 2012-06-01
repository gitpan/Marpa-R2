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


Marpa_Error_Code marpa_check_version (unsigned int required_major, unsigned int required_minor, unsigned int required_micro );
Marpa_Grammar marpa_g_new ( unsigned int required_major, unsigned int required_minor, unsigned int required_micro);
void marpa_g_unref (Marpa_Grammar g);
Marpa_Grammar marpa_g_ref (Marpa_Grammar g);
Marpa_Symbol_ID marpa_g_symbol_new (Marpa_Grammar g);
Marpa_Symbol_ID marpa_g_start_symbol_set ( Marpa_Grammar g, Marpa_Symbol_ID id);
Marpa_Symbol_ID marpa_g_start_symbol (Marpa_Grammar g);
int marpa_g_symbol_count (Marpa_Grammar g);
int marpa_g_symbol_is_terminal ( Marpa_Grammar g, Marpa_Symbol_ID symid);
int marpa_g_symbol_is_terminal_set ( Marpa_Grammar g, Marpa_Symbol_ID symid, int value);
int marpa_g_symbol_is_accessible (Marpa_Grammar g, Marpa_Symbol_ID symid);
int marpa_g_symbol_is_productive (Marpa_Grammar g, Marpa_Symbol_ID symid);
int marpa_g_symbol_is_start ( Marpa_Grammar g, Marpa_Symbol_ID symid);
int marpa_g_symbol_is_nulling (Marpa_Grammar g, Marpa_Symbol_ID symid);
int marpa_g_symbol_is_nullable ( Marpa_Grammar g, Marpa_Symbol_ID symid);
int marpa_g_symbol_ask_me_when_null_set ( Marpa_Grammar g, Marpa_Symbol_ID symbol_id, int value);
int marpa_g_symbol_is_ask_me_when_null ( Marpa_Grammar g, Marpa_Symbol_ID symbol_id);
int marpa_g_rule_count (Marpa_Grammar g);
Marpa_Rule_ID marpa_g_rule_new (Marpa_Grammar g, Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, int length);
Marpa_Symbol_ID marpa_g_rule_lhs ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
int marpa_g_rule_length ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
Marpa_Symbol_ID marpa_g_rule_rh_symbol ( Marpa_Grammar g, Marpa_Rule_ID rule_id, int ix);
int marpa_g_rule_whatever_set ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
int marpa_g_rule_first_child_set ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
int marpa_g_rule_ask_me_set ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
int marpa_g_rule_is_ask_me ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
int marpa_g_rule_is_nulling (Marpa_Grammar g, Marpa_Rule_ID ruleid);
int marpa_g_rule_is_nullable ( Marpa_Grammar g, Marpa_Rule_ID ruleid);
int marpa_g_rule_is_accessible (Marpa_Grammar g, Marpa_Rule_ID id);
int marpa_g_rule_is_productive (Marpa_Grammar g, Marpa_Rule_ID id);
int marpa_g_rule_is_loop (Marpa_Grammar g, Marpa_Rule_ID rule_id);
Marpa_Rule_ID marpa_g_sequence_new (Marpa_Grammar g, Marpa_Symbol_ID lhs_id, Marpa_Symbol_ID rhs_id, Marpa_Symbol_ID separator_id, int min, int flags );
int marpa_g_rule_is_sequence ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
int marpa_g_symbol_is_counted (Marpa_Grammar g, Marpa_Symbol_ID symid);
int marpa_g_rule_is_proper_separation ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
int marpa_g_precompute (Marpa_Grammar g);
int marpa_g_is_precomputed (Marpa_Grammar g);
int marpa_g_has_cycle (Marpa_Grammar g);
int marpa_g_event (Marpa_Grammar g, Marpa_Event* event, int ix);
Marpa_Recognizer marpa_r_new ( Marpa_Grammar g );
Marpa_Recognizer marpa_r_ref (Marpa_Recognizer r);
void marpa_r_unref (Marpa_Recognizer r);
int marpa_r_start_input (Marpa_Recognizer r);
int marpa_r_alternative (Marpa_Recognizer r, Marpa_Symbol_ID token_id, int value, int length);
Marpa_Earleme marpa_r_earleme_complete (Marpa_Recognizer r);
Marpa_Earleme marpa_r_earleme ( Marpa_Recognizer r, Marpa_Earley_Set_ID set_id);
unsigned int marpa_r_current_earleme (Marpa_Recognizer r);
int marpa_r_earley_item_warning_threshold (Marpa_Recognizer r);
int marpa_r_earley_item_warning_threshold_set (Marpa_Recognizer r, int threshold);
unsigned int marpa_r_furthest_earleme (Marpa_Recognizer r);
int marpa_r_terminals_expected ( Marpa_Recognizer r, Marpa_Symbol_ID* buffer);
int marpa_r_is_exhausted (Marpa_Recognizer r);
int marpa_r_event (Marpa_Recognizer r, Marpa_Event* event, int ix);
int marpa_r_progress_report_start ( Marpa_Recognizer r, Marpa_Earley_Set_ID set_id);
int marpa_r_progress_report_finish ( Marpa_Recognizer r );
Marpa_Progress_Item marpa_r_progress_item ( Marpa_Recognizer r );
Marpa_Bocage marpa_b_new (Marpa_Recognizer r, Marpa_Earley_Set_ID ordinal_arg);
Marpa_Grammar marpa_b_g (Marpa_Bocage b);
Marpa_Bocage marpa_b_ref (Marpa_Bocage b);
void marpa_b_unref (Marpa_Bocage b);
Marpa_Order marpa_o_new ( Marpa_Bocage b);
Marpa_Grammar marpa_o_g ( Marpa_Order o);
Marpa_Order marpa_o_ref ( Marpa_Order o);
void marpa_o_unref ( Marpa_Order o);
Marpa_Tree marpa_t_new (Marpa_Order o);
Marpa_Grammar marpa_t_g (Marpa_Tree t);
Marpa_Tree marpa_t_ref (Marpa_Tree t);
void marpa_t_unref (Marpa_Tree t);
int marpa_t_next ( Marpa_Tree t);
int marpa_t_parse_count ( Marpa_Tree t);
Marpa_Value marpa_v_new ( Marpa_Tree t );
Marpa_Grammar marpa_v_g ( Marpa_Value v );
Marpa_Value marpa_v_ref (Marpa_Value v);
void marpa_v_unref ( Marpa_Value v);
int marpa_v_symbol_is_ask_me_when_null ( Marpa_Value v, Marpa_Symbol_ID symid );
int marpa_v_symbol_ask_me_when_null_set ( Marpa_Value v, Marpa_Symbol_ID symid, int value );
Marpa_Step_Type marpa_v_step ( Marpa_Value v);
Marpa_Error_Code marpa_g_error ( Marpa_Grammar g, const char** p_error_string);
Marpa_Error_Code marpa_r_error (Marpa_Recognizer r, const char** p_error_string);
int _marpa_g_isy_is_start ( Marpa_Grammar g, Marpa_ISY_ID isy_id);
int _marpa_g_isy_is_nulling ( Marpa_Grammar g, Marpa_ISY_ID isy_id);
int _marpa_g_isy_is_lhs ( Marpa_Grammar g, Marpa_ISY_ID isy_id);
Marpa_ISY_ID _marpa_g_xsy_nulling_isy ( Marpa_Grammar g, Marpa_Symbol_ID symid);
Marpa_ISY_ID _marpa_g_xsy_isy ( Marpa_Grammar g, Marpa_Symbol_ID symid);
Marpa_Symbol_ID _marpa_g_symbol_proper_alias ( Marpa_Grammar g, Marpa_Symbol_ID symid);
Marpa_Symbol_ID _marpa_g_symbol_null_alias ( Marpa_Grammar g, Marpa_Symbol_ID symid);
int _marpa_g_symbol_is_semantic ( Marpa_Grammar g, Marpa_Symbol_ID symid);
Marpa_Rule_ID _marpa_g_source_xsy ( Marpa_Grammar g, Marpa_ISY_ID isy_id);
Marpa_Rule_ID _marpa_g_isy_lhs_xrl ( Marpa_Grammar g, Marpa_ISY_ID isy_id);
int _marpa_g_isy_xrl_offset ( Marpa_Grammar g, Marpa_ISY_ID isy_id );
int marpa_g_rule_is_keep_separation ( Marpa_Grammar g, Marpa_Rule_ID rule_id);
int _marpa_g_isy_count ( Marpa_Grammar g);
int _marpa_g_irl_count ( Marpa_Grammar g);
Marpa_Symbol_ID _marpa_g_irl_lhs ( Marpa_Grammar g, Marpa_IRL_ID irl_id);
int _marpa_g_irl_length ( Marpa_Grammar g, Marpa_IRL_ID irl_id);
Marpa_Symbol_ID _marpa_g_irl_rh_symbol ( Marpa_Grammar g, Marpa_IRL_ID irl_id, int ix);
int _marpa_g_rule_is_used (Marpa_Grammar g, Marpa_Rule_ID rule_id);
int _marpa_g_irl_is_virtual_lhs (Marpa_Grammar g, Marpa_IRL_ID irl_id);
int _marpa_g_irl_is_virtual_rhs (Marpa_Grammar g, Marpa_IRL_ID irl_id);
unsigned int _marpa_g_virtual_start (Marpa_Grammar g, Marpa_IRL_ID irl_id);
unsigned int _marpa_g_virtual_end (Marpa_Grammar g, Marpa_IRL_ID irl_id);
Marpa_Rule_ID _marpa_g_source_xrl (Marpa_Grammar g, Marpa_IRL_ID irl_id);
int _marpa_g_real_symbol_count (Marpa_Grammar g, Marpa_IRL_ID irl_id);
Marpa_Rule_ID _marpa_g_irl_semantic_equivalent (Marpa_Grammar g, Marpa_IRL_ID irl_id);
int _marpa_g_AHFA_item_count (Marpa_Grammar g);
Marpa_Rule_ID _marpa_g_AHFA_item_irl (Marpa_Grammar g, Marpa_AHFA_Item_ID item_id);
int _marpa_g_AHFA_item_position (Marpa_Grammar g, Marpa_AHFA_Item_ID item_id);
Marpa_Symbol_ID _marpa_g_AHFA_item_postdot (Marpa_Grammar g, Marpa_AHFA_Item_ID item_id);
int _marpa_g_AHFA_item_sort_key (Marpa_Grammar g, Marpa_AHFA_Item_ID item_id);
int _marpa_g_AHFA_state_count (Marpa_Grammar g);
int _marpa_g_AHFA_state_item_count (Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id);
Marpa_AHFA_Item_ID _marpa_g_AHFA_state_item (Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id, int item_ix);
int _marpa_g_AHFA_state_is_predict (Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id);
Marpa_Symbol_ID _marpa_g_AHFA_state_leo_lhs_symbol ( Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id);
int _marpa_g_AHFA_state_transitions ( Marpa_Grammar g, Marpa_AHFA_State_ID AHFA_state_id, int *buffer, int buffer_size );
Marpa_AHFA_State_ID _marpa_g_AHFA_state_empty_transition ( Marpa_Grammar g, Marpa_AHFA_Item_ID AHFA_item_id);
int _marpa_r_is_use_leo (Marpa_Recognizer r);
int _marpa_r_is_use_leo_set ( Marpa_Recognizer r, int value);
Marpa_Earley_Set_ID _marpa_r_trace_earley_set (Marpa_Recognizer r);
Marpa_Earley_Set_ID _marpa_r_latest_earley_set (Marpa_Recognizer r);
int _marpa_r_earley_set_size (Marpa_Recognizer r, Marpa_Earley_Set_ID set_id);
Marpa_Earleme _marpa_r_earley_set_trace (Marpa_Recognizer r, Marpa_Earley_Set_ID set_id);
Marpa_AHFA_State_ID _marpa_r_earley_item_trace (Marpa_Recognizer r, Marpa_Earley_Item_ID item_id);
Marpa_Earley_Set_ID _marpa_r_earley_item_origin (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_leo_predecessor_symbol (Marpa_Recognizer r);
Marpa_Earley_Set_ID _marpa_r_leo_base_origin (Marpa_Recognizer r);
Marpa_AHFA_State_ID _marpa_r_leo_base_state (Marpa_Recognizer r);
Marpa_AHFA_State_ID _marpa_r_leo_expansion_ahfa (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_postdot_symbol_trace (Marpa_Recognizer r, Marpa_Symbol_ID symid);
Marpa_Symbol_ID _marpa_r_first_postdot_item_trace (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_next_postdot_item_trace (Marpa_Recognizer r);
Marpa_AHFA_State_ID _marpa_r_postdot_item_symbol (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_first_token_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_next_token_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_first_completion_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_next_completion_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_first_leo_link_trace (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_next_leo_link_trace (Marpa_Recognizer r);
Marpa_AHFA_State_ID _marpa_r_source_predecessor_state (Marpa_Recognizer r);
Marpa_Symbol_ID _marpa_r_source_token (Marpa_Recognizer r, int *value_p);
Marpa_Symbol_ID _marpa_r_source_leo_transition_symbol (Marpa_Recognizer r);
Marpa_Earley_Set_ID _marpa_r_source_middle (Marpa_Recognizer r);
int _marpa_b_and_node_count ( Marpa_Bocage b);
int _marpa_b_and_node_parent ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id);
int _marpa_b_and_node_predecessor ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id);
int _marpa_b_and_node_cause ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id);
int _marpa_b_and_node_symbol ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id);
Marpa_Symbol_ID _marpa_b_and_node_token ( Marpa_Bocage b, Marpa_And_Node_ID and_node_id, int* value_p);
Marpa_Or_Node_ID _marpa_b_top_or_node ( Marpa_Bocage b);
int _marpa_b_or_node_set ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
int _marpa_b_or_node_origin ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
Marpa_IRL_ID _marpa_b_or_node_irl ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
int _marpa_b_or_node_position ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
int _marpa_b_or_node_first_and ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
int _marpa_b_or_node_last_and ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
int _marpa_b_or_node_and_count ( Marpa_Bocage b, Marpa_Or_Node_ID or_node_id);
int _marpa_o_and_order_set ( Marpa_Order o, Marpa_Or_Node_ID or_node_id, Marpa_And_Node_ID* and_node_ids, int length);
Marpa_And_Node_ID _marpa_o_and_order_get ( Marpa_Order o, Marpa_Or_Node_ID or_node_id, int ix);
int _marpa_t_size ( Marpa_Tree t);
Marpa_Or_Node_ID _marpa_t_nook_or_node ( Marpa_Tree t, Marpa_Nook_ID nook_id);
int _marpa_t_nook_choice ( Marpa_Tree t, Marpa_Nook_ID nook_id );
int _marpa_t_nook_parent ( Marpa_Tree t, Marpa_Nook_ID nook_id );
int _marpa_t_nook_cause_is_ready ( Marpa_Tree t, Marpa_Nook_ID nook_id );
int _marpa_t_nook_predecessor_is_ready ( Marpa_Tree t, Marpa_Nook_ID nook_id );
int _marpa_t_nook_is_cause ( Marpa_Tree t, Marpa_Nook_ID nook_id );
int _marpa_t_nook_is_predecessor ( Marpa_Tree t, Marpa_Nook_ID nook_id );
int _marpa_v_trace ( Marpa_Value v, int flag);
Marpa_Nook_ID _marpa_v_nook ( Marpa_Value v);
#define MARPA_ERROR_COUNT 72
#define MARPA_ERR_NONE 0
#define MARPA_ERR_AHFA_IX_NEGATIVE 1
#define MARPA_ERR_AHFA_IX_OOB 2
#define MARPA_ERR_ANDID_NEGATIVE 3
#define MARPA_ERR_ANDID_NOT_IN_OR 4
#define MARPA_ERR_ANDIX_NEGATIVE 5
#define MARPA_ERR_BAD_SEPARATOR 6
#define MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED 7
#define MARPA_ERR_COUNTED_NULLABLE 8
#define MARPA_ERR_DEVELOPMENT 9
#define MARPA_ERR_DUPLICATE_AND_NODE 10
#define MARPA_ERR_DUPLICATE_RULE 11
#define MARPA_ERR_EIM_COUNT 12
#define MARPA_ERR_EIM_ID_INVALID 13
#define MARPA_ERR_INTERNAL 14
#define MARPA_ERR_INVALID_AHFA_ID 15
#define MARPA_ERR_INVALID_AIMID 16
#define MARPA_ERR_INVALID_BOOLEAN 17
#define MARPA_ERR_INVALID_ES_ORDINAL 18
#define MARPA_ERR_INVALID_IRLID 19
#define MARPA_ERR_INVALID_ISYID 20
#define MARPA_ERR_INVALID_START_SYM 21
#define MARPA_ERR_INVALID_SYMID 22
#define MARPA_ERR_INVALID_XRLID 23
#define MARPA_ERR_INVALID_XSYID 24
#define MARPA_ERR_NOOKID_NEGATIVE 25
#define MARPA_ERR_MAJOR_VERSION_MISMATCH 26
#define MARPA_ERR_MICRO_VERSION_MISMATCH 27
#define MARPA_ERR_MINOR_VERSION_MISMATCH 28
#define MARPA_ERR_NOT_PRECOMPUTED 29
#define MARPA_ERR_NOT_TRACING_COMPLETION_LINKS 30
#define MARPA_ERR_NOT_TRACING_LEO_LINKS 31
#define MARPA_ERR_NOT_TRACING_TOKEN_LINKS 32
#define MARPA_ERR_NO_AND_NODES 33
#define MARPA_ERR_NO_OR_NODES 34
#define MARPA_ERR_NO_PARSE 35
#define MARPA_ERR_NO_RULES 36
#define MARPA_ERR_NO_START_SYM 37
#define MARPA_ERR_NO_TRACE_EIM 38
#define MARPA_ERR_NO_TRACE_ES 39
#define MARPA_ERR_NO_TRACE_PIM 40
#define MARPA_ERR_NO_TRACE_SRCL 41
#define MARPA_ERR_NULLING_TERMINAL 42
#define MARPA_ERR_ORDER_FROZEN 43
#define MARPA_ERR_ORID_NEGATIVE 44
#define MARPA_ERR_OR_ALREADY_ORDERED 45
#define MARPA_ERR_PARSE_EXHAUSTED 46
#define MARPA_ERR_PARSE_TOO_LONG 47
#define MARPA_ERR_PIM_IS_NOT_LIM 48
#define MARPA_ERR_PRECOMPUTED 49
#define MARPA_ERR_PROGRESS_REPORT_NOT_STARTED 50
#define MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT 51
#define MARPA_ERR_RECCE_NOT_STARTED 52
#define MARPA_ERR_RECCE_STARTED 53
#define MARPA_ERR_RHS_TOO_LONG 54
#define MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE 55
#define MARPA_ERR_SOURCE_TYPE_IS_NONE 56
#define MARPA_ERR_SOURCE_TYPE_IS_TOKEN 57
#define MARPA_ERR_SOURCE_TYPE_IS_COMPLETION 58
#define MARPA_ERR_SOURCE_TYPE_IS_LEO 59
#define MARPA_ERR_SOURCE_TYPE_IS_AMBIGUOUS 60
#define MARPA_ERR_SOURCE_TYPE_IS_UNKNOWN 61
#define MARPA_ERR_START_NOT_LHS 62
#define MARPA_ERR_SYM_NOT_NULLABLE 63
#define MARPA_ERR_TOKEN_IS_NOT_TERMINAL 64
#define MARPA_ERR_TOKEN_LENGTH_LE_ZERO 65
#define MARPA_ERR_TOKEN_TOO_LONG 66
#define MARPA_ERR_TREE_EXHAUSTED 67
#define MARPA_ERR_TREE_PAUSED 68
#define MARPA_ERR_UNKNOWN 69
#define MARPA_ERR_UNPRODUCTIVE_START 70
#define MARPA_ERR_VALUATOR_INACTIVE 71
#define MARPA_EVENT_COUNT 6
#define MARPA_EVENT_NONE 0
#define MARPA_EVENT_EXHAUSTED 1
#define MARPA_EVENT_EARLEY_ITEM_THRESHOLD 2
#define MARPA_EVENT_LOOP_RULES 3
#define MARPA_EVENT_COUNTED_NULLABLE 4
#define MARPA_EVENT_NULLING_TERMINAL 5
#define MARPA_STEP_COUNT 7
#define MARPA_STEP_INTERNAL1 0
#define MARPA_STEP_RULE 1
#define MARPA_STEP_TOKEN 2
#define MARPA_STEP_NULLING_SYMBOL 3
#define MARPA_STEP_TRACE 4
#define MARPA_STEP_INACTIVE 5
#define MARPA_STEP_INTERNAL2 6
