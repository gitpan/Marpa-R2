/*1372:*/
#line 13416 "./marpa.w"

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

/*:1372*//*1373:*/
#line 13439 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1361:*/
#line 13290 "./marpa.w"

#define MARPA_DEBUG  0 
#define MARPA_ENABLE_ASSERT  0 
#if MARPA_DEBUG
#define MARPA_DEBUG1(a)  g_debug((a)); 
#define MARPA_DEBUG2(a, b)  g_debug((a),(b)); 
#define MARPA_DEBUG3(a, b, c)  g_debug((a),(b),(c)); 
#define MARPA_DEBUG4(a, b, c, d)  g_debug((a),(b),(c),(d)); 
#define MARPA_DEBUG5(a, b, c, d, e)  g_debug((a),(b),(c),(d),(e)); 
#define MARPA_ASSERT(expr) do { if G_LIKELY (expr) ; else \
       g_error ("%s: assertion failed %s", G_STRLOC, #expr); } while (0);
#else 
#define MARPA_DEBUG1(a) 
#define MARPA_DEBUG2(a, b) 
#define MARPA_DEBUG3(a, b, c) 
#define MARPA_DEBUG4(a, b, c, d) 
#define MARPA_DEBUG5(a, b, c, d, e) 
#define MARPA_ASSERT(exp) 
#endif

#if MARPA_ENABLE_ASSERT
#undef MARPA_ASSERT
#define MARPA_ASSERT(expr) do { if G_LIKELY (expr) ; else \
       g_error ("%s: assertion failed %s", G_STRLOC, #expr); } while (0);
#endif

/*:1361*/
#line 13442 "./marpa.w"

#define PRIVATE_NOT_INLINE static \

#define SYM_Count_of_G(g) ((g) ->t_symbols->len) 
#define SYM_by_ID(id) (g_array_index(g->t_symbols,SYM,(id) ) )  \

#define RULE_Count_of_G(g) ((g) ->t_rules->len) 
#define RULE_by_ID(g,id) (g_array_index((g) ->t_rules,RULE,(id) ) )  \

#define RULEID_of_G_is_Valid(g,rule_id)  \
((rule_id) >=0&&(guint) (rule_id) <(g) ->t_rules->len)  \

#define Default_Value_of_G(g) ((g) ->t_default_value) 
#define G_is_Trivial(g) (!(g) ->t_proper_start_rule) 
#define Size_of_G(g) ((g) ->t_size) 
#define LV_Size_of_G(g) ((g) ->t_size) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define G_EVENT_COUNT(g) DSTACK_LENGTH((g) ->t_events) 
#define INITIAL_G_EVENTS_CAPACITY 1
#define G_EVENTS_CLEAR(g) DSTACK_CLEAR((g) ->t_events) 
#define G_EVENT_PUSH(g) DSTACK_PUSH((g) ->t_events,GEV_Object) 
#define ID_of_SYM(sym) ((sym) ->t_symbol_id) 
#define SYMBOL_LHS_RULE_COUNT(symbol) ((symbol) ->t_lhs->len) 
#define SYM_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define SYM_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
#define SYMID_is_Terminal(id) (SYM_is_Terminal(SYM_by_ID(id) ) ) 
#define MAX_RHS_LENGTH (G_MAXINT>>(2) ) 
#define Length_of_RULE(rule) ((rule) ->t_rhs_length) 
#define LHS_ID_of_RULE(rule) ((rule) ->t_symbols[0]) 
#define RHS_ID_of_RULE(rule,position)  \
((rule) ->t_symbols[(position) +1])  \

#define ID_of_RULE(rule) ((rule) ->t_id) 
#define RULE_is_Used(rule) ((rule) ->t_is_used) 
#define RULE_is_Start(rule) ((rule) ->t_is_start) 
#define RULE_is_Virtual_LHS(rule) ((rule) ->t_is_virtual_lhs) 
#define RULE_is_Virtual_RHS(rule) ((rule) ->t_is_virtual_rhs) 
#define Real_SYM_Count_of_RULE(rule) ((rule) ->t_real_symbol_count) 
#define SYMI_Count_of_G(g) ((g) ->t_symbol_instance_count) 
#define SYMI_of_RULE(rule) ((rule) ->t_symbol_instance_base) 
#define Last_Proper_SYMI_of_RULE(rule) ((rule) ->t_last_proper_symi) 
#define SYMI_of_Completed_RULE(rule)  \
(SYMI_of_RULE(rule) +Length_of_RULE(rule) -1) 
#define SYMI_of_AIM(aim) (symbol_instance_of_ahfa_item_get(aim) ) 
#define Sort_Key_of_AIM(aim) ((aim) ->t_sort_key) 
#define Next_AIM_of_AIM(aim) ((aim) +1) 
#define AIM_by_ID(id) (g->t_AHFA_items+(id) ) 
#define AIM_Count_of_G(g) ((g) ->t_aim_count) 
#define LV_AIM_Count_of_G(g) AIM_Count_of_G(g) 
#define RULE_of_AIM(item) ((item) ->t_rule) 
#define RULEID_of_AIM(item) ID_of_RULE(RULE_of_AIM(item) ) 
#define LHS_ID_of_AIM(item) (LHS_ID_of_RULE(RULE_of_AIM(item) ) ) 
#define Position_of_AIM(aim) ((aim) ->t_position) 
#define Postdot_SYMID_of_AIM(item) ((item) ->t_postdot) 
#define AIM_is_Completion(aim) (Postdot_SYMID_of_AIM(aim) <0) 
#define AIM_has_Completed_Start_Rule(aim)  \
(AIM_is_Completion(aim) &&RULE_is_Start(RULE_of_AIM(aim) ) ) 
#define Null_Count_of_AIM(aim) ((aim) ->t_leading_nulls) 
#define AHFA_of_G_by_ID(g,id) ((g) ->t_AHFA+(id) ) 
#define AHFA_has_Completed_Start_Rule(ahfa) ((ahfa) ->t_has_completed_start_rule) 
#define Complete_SYMIDs_of_AHFA(state) ((state) ->t_complete_symbols) 
#define LV_Complete_SYMIDs_of_AHFA(state) Complete_SYMIDs_of_AHFA(state) 
#define Complete_SYM_Count_of_AHFA(state) ((state) ->t_complete_symbol_count) 
#define LV_Complete_SYM_Count_of_AHFA(state) Complete_SYM_Count_of_AHFA(state) 
#define AIMs_of_AHFA(ahfa) ((ahfa) ->t_items) 
#define AIM_of_AHFA_by_AEX(ahfa,aex) (AIMs_of_AHFA(ahfa) [aex]) 
#define LV_AIMs_of_AHFA(ahfa) AIMs_of_AHFA(ahfa) 
#define AIM_Count_of_AHFA(ahfa) ((ahfa) ->t_item_count) 
#define LV_AIM_Count_of_AHFA(ahfa) AIM_Count_of_AHFA(ahfa) 
#define AEX_of_AHFA_by_AIM(ahfa,aim) aex_of_ahfa_by_aim_get((ahfa) ,(aim) ) 
#define AHFA_is_Predicted(ahfa) ((ahfa) ->t_is_predict) 
#define LV_AHFA_is_Predicted(ahfa) AHFA_is_Predicted(ahfa) 
#define EIM_is_Predicted(eim) AHFA_is_Predicted(AHFA_of_EIM(eim) ) 
#define AHFA_Count_of_G(g) ((g) ->t_AHFA_len) 
#define ID_of_AHFA(state) ((state) ->t_key.t_id)  \

#define Postdot_SYM_Count_of_AHFA(state) ((state) ->t_postdot_sym_count) 
#define LV_Postdot_SYM_Count_of_AHFA(state) Postdot_SYM_Count_of_AHFA(state) 
#define Postdot_SYMID_Ary_of_AHFA(state) ((state) ->t_postdot_symid_ary) 
#define LV_Postdot_SYMID_Ary_of_AHFA(state) Postdot_SYMID_Ary_of_AHFA(state) 
#define AIMID_of_AHFA_by_AEX(g,ahfa,aex)  \
((ahfa) ->t_items[aex]-(g) ->t_AHFA_items) 
#define Leo_LHS_ID_of_AHFA(state) ((state) ->t_leo_lhs_sym) 
#define LV_Leo_LHS_ID_of_AHFA(state) Leo_LHS_ID_of_AHFA(state) 
#define AHFA_is_Leo_Completion(state) (Leo_LHS_ID_of_AHFA(state) >=0) 
#define TRANS_of_AHFA_by_SYMID(from_ahfa,id)  \
(*(TRANSs_of_AHFA(from_ahfa) +(id) ) ) 
#define TRANS_of_EIM_by_SYMID(eim,id) TRANS_of_AHFA_by_SYMID(AHFA_of_EIM(eim) ,(id) ) 
#define To_AHFA_of_TRANS(trans) (to_ahfa_of_transition_get(trans) ) 
#define LV_To_AHFA_of_TRANS(trans) ((trans) ->t_ur.t_to_ahfa) 
#define Completion_Count_of_TRANS(trans)  \
(completion_count_of_transition_get(trans) ) 
#define LV_Completion_Count_of_TRANS(trans) ((trans) ->t_ur.t_completion_count) 
#define To_AHFA_of_AHFA_by_SYMID(from_ahfa,id)  \
(To_AHFA_of_TRANS(TRANS_of_AHFA_by_SYMID((from_ahfa) ,(id) ) ) ) 
#define Completion_Count_of_AHFA_by_SYMID(from_ahfa,id)  \
(Completion_Count_of_TRANS(TRANS_of_AHFA_by_SYMID((from ahfa) ,(id) ) ) ) 
#define To_AHFA_of_EIM_by_SYMID(eim,id) To_AHFA_of_AHFA_by_SYMID(AHFA_of_EIM(eim) ,(id) ) 
#define AEXs_of_TRANS(trans) ((trans) ->t_aex) 
#define Leo_Base_AEX_of_TRANS(trans) ((trans) ->t_leo_base_aex) 
#define TRANSs_of_AHFA(ahfa) ((ahfa) ->t_transitions) 
#define LV_TRANSs_of_AHFA(ahfa) TRANSs_of_AHFA(ahfa) 
#define Empty_Transition_of_AHFA(state) ((state) ->t_empty_transition) 
#define G_of_R(r) ((r) ->t_grammar) 
#define AHFA_Count_of_R(r) AHFA_Count_of_G(G_of_R(r) ) 
#define Phase_of_R(r) ((r) ->t_phase) 
#define First_ES_of_R(r) ((r) ->t_first_earley_set) 
#define LV_First_ES_of_R(r) First_ES_of_R(r) 
#define Latest_ES_of_R(r) ((r) ->t_latest_earley_set) 
#define LV_Latest_ES_of_R(r) Latest_ES_of_R(r) 
#define Current_Earleme_of_R(r) ((r) ->t_current_earleme) 
#define LV_Current_Earleme_of_R(r) (Current_Earleme_of_R(r) ) 
#define Current_ES_of_R(r) current_es_of_r(r) 
#define DEFAULT_EIM_WARNING_THRESHOLD (100) 
#define Furthest_Earleme_of_R(r) ((r) ->t_furthest_earleme) 
#define LV_Furthest_Earleme_of_R(r) Furthest_Earleme_of_R(r) 
#define R_is_Exhausted(r) ((r) ->t_is_exhausted) 
#define EARLEME_THRESHOLD (G_MAXINT/4) 
#define Next_ES_of_ES(set) ((set) ->t_next_earley_set) 
#define LV_Next_ES_of_ES(set) Next_ES_of_ES(set) 
#define Postdot_SYM_Count_of_ES(set) ((set) ->t_postdot_sym_count) 
#define First_PIM_of_ES_by_SYMID(set,symid) (first_pim_of_es_by_symid((set) ,(symid) ) ) 
#define PIM_SYM_P_of_ES_by_SYMID(set,symid) (pim_sym_p_find((set) ,(symid) ) ) 
#define EIM_Count_of_ES(set) ((set) ->t_eim_count) 
#define EIMs_of_ES(set) ((set) ->t_earley_items) 
#define ES_Count_of_R(r) ((r) ->t_earley_set_count) 
#define Ord_of_ES(set) ((set) ->t_ordinal) 
#define ES_Ord_is_Valid(r,ordinal)  \
((ordinal) >=0&&(ordinal) <ES_Count_of_R(r) ) 
#define Earleme_of_ES(set) ((set) ->t_key.t_earleme)  \

#define EIM_FATAL_THRESHOLD (G_MAXINT/4) 
#define Complete_SYMIDs_of_EIM(item)  \
Complete_SYMIDs_of_AHFA(AHFA_of_EIM(item) ) 
#define Complete_SYM_Count_of_EIM(item)  \
Complete_SYM_Count_of_AHFA(AHFA_of_EIM(item) ) 
#define Leo_LHS_ID_of_EIM(eim) Leo_LHS_ID_of_AHFA(AHFA_of_EIM(eim) ) 
#define Earley_Item_is_Completion(item)  \
(Complete_SYM_Count_of_EIM(item) > 0) 
#define ES_of_EIM(item) ((item) ->t_key.t_set) 
#define ES_Ord_of_EIM(item) (Ord_of_ES(ES_of_EIM(item) ) ) 
#define Ord_of_EIM(item) ((item) ->t_ordinal) 
#define Earleme_of_EIM(item) Earleme_of_ES(ES_of_EIM(item) ) 
#define AHFAID_of_EIM(item) (ID_of_AHFA(AHFA_of_EIM(item) ) ) 
#define AHFA_of_EIM(item) ((item) ->t_key.t_state) 
#define AIM_Count_of_EIM(item) (AIM_Count_of_AHFA(AHFA_of_EIM(item) ) ) 
#define Origin_Earleme_of_EIM(item) (Earleme_of_ES(Origin_of_EIM(item) ) ) 
#define Origin_Ord_of_EIM(item) (Ord_of_ES(Origin_of_EIM(item) ) ) 
#define Origin_of_EIM(item) ((item) ->t_key.t_origin) 
#define AIM_of_EIM_by_AEX(eim,aex) AIM_of_AHFA_by_AEX(AHFA_of_EIM(eim) ,(aex) ) 
#define AEX_of_EIM_by_AIM(eim,aim) AEX_of_AHFA_by_AIM(AHFA_of_EIM(eim) ,(aim) ) 
#define NO_SOURCE (0U) 
#define SOURCE_IS_TOKEN (1U) 
#define SOURCE_IS_COMPLETION (2U) 
#define SOURCE_IS_LEO (3U) 
#define SOURCE_IS_AMBIGUOUS (4U) 
#define Source_Type_of_EIM(item) ((item) ->t_source_type) 
#define Earley_Item_has_No_Source(item) ((item) ->t_source_type==NO_SOURCE) 
#define Earley_Item_has_Token_Source(item) ((item) ->t_source_type==SOURCE_IS_TOKEN) 
#define Earley_Item_has_Complete_Source(item) ((item) ->t_source_type==SOURCE_IS_COMPLETION) 
#define Earley_Item_has_Leo_Source(item) ((item) ->t_source_type==SOURCE_IS_LEO) 
#define Earley_Item_is_Ambiguous(item) ((item) ->t_source_type==SOURCE_IS_AMBIGUOUS) 
#define Next_PIM_of_EIX(eix) ((eix) ->t_next) 
#define LV_Next_PIM_of_EIX(eix) Next_PIM_of_EIX(eix) 
#define EIM_of_EIX(eix) ((eix) ->t_earley_item) 
#define LV_EIM_of_EIX(eix) EIM_of_EIX(eix) 
#define Postdot_SYMID_of_EIX(eix) ((eix) ->t_postdot_symid) 
#define LV_Postdot_SYMID_of_EIX(eix) Postdot_SYMID_of_EIX(eix) 
#define EIX_of_LIM(lim) ((EIX) (lim) ) 
#define Postdot_SYMID_of_LIM(leo) (Postdot_SYMID_of_EIX(EIX_of_LIM(leo) ) ) 
#define Next_PIM_of_LIM(leo) (Next_PIM_of_EIX(EIX_of_LIM(leo) ) ) 
#define LV_Next_PIM_of_LIM(leo) Next_PIM_of_LIM(leo) 
#define Origin_of_LIM(leo) ((leo) ->t_origin) 
#define LV_Origin_of_LIM(leo) Origin_of_LIM(leo) 
#define Top_AHFA_of_LIM(leo) ((leo) ->t_top_ahfa) 
#define LV_Top_AHFA_of_LIM(leo) Top_AHFA_of_LIM(leo) 
#define Predecessor_LIM_of_LIM(leo) ((leo) ->t_predecessor) 
#define LV_Predecessor_LIM_of_LIM(leo) Predecessor_LIM_of_LIM(leo) 
#define Base_EIM_of_LIM(leo) ((leo) ->t_base) 
#define LV_Base_EIM_of_LIM(leo) Base_EIM_of_LIM(leo) 
#define ES_of_LIM(leo) ((leo) ->t_set) 
#define LV_ES_of_LIM(leo) ES_of_LIM(leo) 
#define Chain_Length_of_LIM(leo) ((leo) ->t_chain_length) 
#define LV_Chain_Length_of_LIM(leo) Chain_Length_of_LIM(leo) 
#define Earleme_of_LIM(lim) Earleme_of_ES(ES_of_LIM(lim) ) 
#define LIM_of_PIM(pim) ((LIM) (pim) ) 
#define EIX_of_PIM(pim) ((EIX) (pim) ) 
#define Postdot_SYMID_of_PIM(pim) (Postdot_SYMID_of_EIX(EIX_of_PIM(pim) ) ) 
#define LV_Postdot_SYMID_of_PIM(pim) Postdot_SYMID_of_PIM(pim) 
#define EIM_of_PIM(pim) (EIM_of_EIX(EIX_of_PIM(pim) ) ) 
#define LV_EIM_of_PIM(pim) EIM_of_PIM(pim) 
#define Next_PIM_of_PIM(pim) (Next_PIM_of_EIX(EIX_of_PIM(pim) ) ) 
#define LV_Next_PIM_of_PIM(pim) Next_PIM_of_PIM(pim)  \

#define PIM_of_LIM(pim) ((PIM) (pim) ) 
#define PIM_is_LIM(pim) (EIM_of_EIX(EIX_of_PIM(pim) ) ==NULL) 
#define SYMID_of_Postdot_Item(postdot) ((postdot) ->t_earley.transition_symid)  \

#define Next_SRCL_of_SRCL(link) ((link) ->t_next) 
#define LV_Next_SRCL_of_SRCL(link) Next_SRCL_of_SRCL(link) 
#define Source_of_SRCL(link) ((link) ->t_source) 
#define Source_of_EIM(eim) ((eim) ->t_container.t_unique) 
#define Predecessor_of_Source(srcd) ((srcd) .t_predecessor) 
#define Predecessor_of_SRC(source) Predecessor_of_Source(*(source) ) 
#define Predecessor_of_EIM(item) Predecessor_of_Source(Source_of_EIM(item) ) 
#define Predecessor_of_SRCL(link) Predecessor_of_Source(Source_of_SRCL(link) ) 
#define LV_Predecessor_of_SRCL(link) Predecessor_of_SRCL(link) 
#define Cause_of_Source(srcd) ((srcd) .t_cause.t_completion) 
#define Cause_of_SRC(source) Cause_of_Source(*(source) ) 
#define Cause_of_EIM(item) Cause_of_Source(Source_of_EIM(item) ) 
#define Cause_of_SRCL(link) Cause_of_Source(Source_of_SRCL(link) ) 
#define TOK_of_Source(srcd) ((srcd) .t_cause.t_token) 
#define TOK_of_SRC(source) TOK_of_Source(*(source) ) 
#define TOK_of_EIM(eim) TOK_of_Source(Source_of_EIM(eim) ) 
#define TOK_of_SRCL(link) TOK_of_Source(Source_of_SRCL(link) ) 
#define SYMID_of_Source(srcd) SYMID_of_TOK(TOK_of_Source(srcd) ) 
#define SYMID_of_SRC(source) SYMID_of_Source(*(source) ) 
#define SYMID_of_EIM(eim) SYMID_of_Source(Source_of_EIM(eim) ) 
#define SYMID_of_SRCL(link) SYMID_of_Source(Source_of_SRCL(link) )  \

#define Cause_AHFA_State_ID_of_SRC(source)  \
AHFAID_of_EIM((EIM) Cause_of_SRC(source) ) 
#define Leo_Transition_SYMID_of_SRC(leo_source)  \
Postdot_SYMID_of_LIM((LIM) Predecessor_of_SRC(leo_source) )  \

#define First_Completion_Link_of_EIM(item) ((item) ->t_container.t_ambiguous.t_completion) 
#define LV_First_Completion_Link_of_EIM(item) First_Completion_Link_of_EIM(item) 
#define First_Token_Link_of_EIM(item) ((item) ->t_container.t_ambiguous.t_token) 
#define LV_First_Token_Link_of_EIM(item) First_Token_Link_of_EIM(item) 
#define First_Leo_SRCL_of_EIM(item) ((item) ->t_container.t_ambiguous.t_leo) 
#define LV_First_Leo_SRCL_of_EIM(item) First_Leo_SRCL_of_EIM(item)  \

#define Type_of_TOK(tok) ((tok) ->t_type) 
#define SYMID_of_TOK(tok) ((tok) ->t_symbol_id) 
#define Value_of_TOK(tok) ((tok) ->t_value) 
#define TOK_Obs_of_R(r) (&(r) ->t_token_obs) 
#define TOKs_by_SYMID_of_R(r) ((r) ->t_tokens_by_symid) 
#define TOK_Obs TOK_Obs_of_R(r) 
#define TOK_by_ID_of_R(r,symbol_id) (TOKs_by_SYMID_of_R(r) [symbol_id]) 
#define TOK_of_ALT(alt) ((alt) ->t_token) 
#define SYMID_of_ALT(alt) SYMID_of_TOK(TOK_of_ALT(alt) ) 
#define Start_ES_of_ALT(alt) ((alt) ->t_start_earley_set) 
#define Start_Earleme_of_ALT(alt) Earleme_of_ES(Start_ES_of_ALT(alt) ) 
#define End_Earleme_of_ALT(alt) ((alt) ->t_end_earleme) 
#define INITIAL_ALTERNATIVES_CAPACITY 1
#define Work_EIMs_of_R(r) DSTACK_BASE((r) ->t_eim_work_stack,EIM) 
#define Work_EIM_Count_of_R(r) DSTACK_LENGTH((r) ->t_eim_work_stack) 
#define WORK_EIMS_CLEAR(r) DSTACK_CLEAR((r) ->t_eim_work_stack) 
#define WORK_EIM_PUSH(r) DSTACK_PUSH((r) ->t_eim_work_stack,EIM) 
#define P_ES_of_R_by_Ord(r,ord) DSTACK_INDEX((r) ->t_earley_set_stack,ES,(ord) ) 
#define ES_of_R_by_Ord(r,ord) (*P_ES_of_R_by_Ord((r) ,(ord) ) ) 
#define LIM_is_Populated(leo) (Origin_of_LIM(leo) !=NULL) 
#define Prev_UR_of_UR(ur) ((ur) ->t_prev) 
#define LV_Prev_UR_of_UR(ur) Prev_UR_of_UR(ur) 
#define Next_UR_of_UR(ur) ((ur) ->t_next) 
#define LV_Next_UR_of_UR(ur) Next_UR_of_UR(ur) 
#define EIM_of_UR(ur) ((ur) ->t_earley_item) 
#define LV_EIM_of_UR(ur) EIM_of_UR(ur) 
#define AEX_of_UR(ur) ((ur) ->t_aex) 
#define LV_AEX_of_UR(ur) AEX_of_UR(ur)  \

#define URS_of_R(r) (&(r) ->t_ur_node_stack) 
#define DUMMY_OR_NODE -1
#define TOKEN_OR_NODE -2
#define OR_is_Token(or) (Type_of_OR(or) ==TOKEN_OR_NODE) 
#define Position_of_OR(or) ((or) ->t_final.t_position) 
#define Type_of_OR(or) ((or) ->t_final.t_position) 
#define RULE_of_OR(or) ((or) ->t_final.t_rule) 
#define Origin_Ord_of_OR(or) ((or) ->t_final.t_start_set_ordinal) 
#define ID_of_OR(or) ((or) ->t_final.t_id) 
#define ES_Ord_of_OR(or) ((or) ->t_draft.t_end_set_ordinal) 
#define DANDs_of_OR(or) ((or) ->t_draft.t_draft_and_node) 
#define First_ANDID_of_OR(or) ((or) ->t_final.t_first_and_node_id) 
#define AND_Count_of_OR(or) ((or) ->t_final.t_and_node_count) 
#define TOK_of_OR(or) (&(or) ->t_token) 
#define SYMID_of_OR(or) SYMID_of_TOK(TOK_of_OR(or) ) 
#define Value_of_OR(or) Value_of_TOK(TOK_of_OR(or) ) 
#define ORs_of_B(b) ((b) ->t_or_nodes) 
#define OR_of_B_by_ID(b,id) (ORs_of_B(b) [(id) ]) 
#define OR_Count_of_B(b) ((b) ->t_or_node_count) 
#define ANDs_of_B(b) ((b) ->t_and_nodes) 
#define AND_Count_of_B(b) ((b) ->t_and_node_count) 
#define Top_ORID_of_B(b) ((b) ->t_top_or_node_id) 
#define Path_AIM_of_LIM(lim) (base_aim_of_lim(lim) +1) 
#define Base_AIM_of_LIM(lim) (base_aim_of_lim(lim) ) 
#define WHEID_of_SYMID(symid) (rule_count_of_g+(symid) ) 
#define WHEID_of_RULEID(ruleid) (ruleid) 
#define WHEID_of_RULE(rule) WHEID_of_RULEID(ID_of_RULE(rule) ) 
#define WHEID_of_OR(or) ( \
wheid= OR_is_Token(or) ? \
WHEID_of_SYMID(SYMID_of_OR(or) ) : \
WHEID_of_RULE(RULE_of_OR(or) )  \
)  \

#define Next_DAND_of_DAND(dand) ((dand) ->t_next) 
#define Predecessor_OR_of_DAND(dand) ((dand) ->t_predecessor) 
#define Cause_OR_of_DAND(dand) ((dand) ->t_cause) 
#define Move_OR_to_Proper_OR(or_node) { \
while(or_node) { \
DAND draft_and_node= DANDs_of_OR(or_node) ; \
OR predecessor_or; \
if(!draft_and_node) break; \
predecessor_or= Predecessor_OR_of_DAND(draft_and_node) ; \
if(predecessor_or&& \
ES_Ord_of_OR(predecessor_or) !=work_earley_set_ordinal)  \
break; \
or_node= predecessor_or; \
} \
} \

#define Set_OR_from_Ord_and_SYMI(or_node,origin,symbol_instance) { \
const PSL or_psl_at_origin= per_es_data[(origin) ].t_or_psl; \
(or_node) = PSL_Datum(or_psl_at_origin,(symbol_instance) ) ; \
} \

#define Set_OR_from_EIM_and_AEX(psia_or,psia_eim,psia_aex) { \
const EIM psia_earley_item= psia_eim; \
const gint psia_earley_set_ordinal= ES_Ord_of_EIM(psia_earley_item) ; \
OR**const psia_nodes_by_item=  \
per_es_data[psia_earley_set_ordinal].t_aexes_by_item; \
const gint psia_item_ordinal= Ord_of_EIM(psia_earley_item) ; \
OR*const psia_nodes_by_aex= psia_nodes_by_item[psia_item_ordinal]; \
psia_or= psia_nodes_by_aex?psia_nodes_by_aex[psia_aex]:NULL; \
} \

#define OR_of_AND(and) ((and) ->t_current) 
#define Predecessor_OR_of_AND(and) ((and) ->t_predecessor) 
#define Cause_OR_of_AND(and) ((and) ->t_cause) 
#define B_of_R(r) ((r) ->t_bocage) 
#define OBS_of_B(b) ((b) ->t_obs) 
#define TREE_is_Initialized(tree) ((tree) ->t_parse_count>=0) 
#define TREE_is_Exhausted(tree) (TREE_is_Initialized(tree)  \
&&!FSTACK_IS_INITIALIZED((tree) ->t_fork_stack) ) 
#define VAL_of_TREE(tree) (&(tree) ->t_val) 
#define Size_of_TREE(tree) FSTACK_LENGTH((tree) ->t_fork_stack) 
#define FORK_of_TREE_by_IX(tree,fork_id)  \
FSTACK_INDEX((tree) ->t_fork_stack,FORK_Object,fork_id) 
#define TREE_of_RANK(rank) (&(rank) ->t_tree) 
#define OBS_of_RANK(rank) ((rank) ->t_obs) 
#define RANK_of_B(b) (&(b) ->t_rank) 
#define OR_of_FORK(fork) ((fork) ->t_or_node) 
#define Choice_of_FORK(fork) ((fork) ->t_choice) 
#define Parent_of_FORK(fork) ((fork) ->t_parent) 
#define FORK_Cause_is_Ready(fork) ((fork) ->t_is_cause_ready) 
#define FORK_is_Cause(fork) ((fork) ->t_is_cause_of_parent) 
#define FORK_Predecessor_is_Ready(fork) ((fork) ->t_is_predecessor_ready) 
#define FORK_is_Predecessor(fork) ((fork) ->t_is_predecessor_of_parent) 
#define SYMID_of_EVE(eve) ((eve) ->marpa_token_id) 
#define Value_of_EVE(eve) ((eve) ->marpa_value) 
#define RULEID_of_EVE(eve) ((eve) ->marpa_rule_id) 
#define Arg0_of_EVE(eve) ((eve) ->marpa_arg_0) 
#define ArgN_of_EVE(eve) ((eve) ->marpa_arg_n) 
#define VAL_is_Active(val) ((val) ->t_active) 
#define VAL_is_Trace(val) ((val) ->t_trace) 
#define FORK_of_VAL(val) ((val) ->t_fork) 
#define TOS_of_VAL(val) ((val) ->t_tos) 
#define VStack_of_VAL(val) ((val) ->t_virtual_stack) 
#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DECLARE(stack,type) struct{gint t_count;type*t_base;}stack;
#define FSTACK_CLEAR(stack) ((stack) .t_count= 0) 
#define FSTACK_INIT(stack,type,n) (FSTACK_CLEAR(stack) ,((stack) .t_base= g_new(type,n) ) ) 
#define FSTACK_SAFE(stack) ((stack) .t_base= NULL) 
#define FSTACK_BASE(stack,type) ((type*) (stack) .t_base) 
#define FSTACK_INDEX(this,type,ix) (FSTACK_BASE((this) ,type) +(ix) ) 
#define FSTACK_TOP(this,type) (FSTACK_LENGTH(this) <=0 \
?NULL \
:FSTACK_INDEX((this) ,type,FSTACK_LENGTH(this) -1) ) 
#define FSTACK_LENGTH(stack) ((stack) .t_count) 
#define FSTACK_PUSH(stack) ((stack) .t_base+stack.t_count++) 
#define FSTACK_POP(stack) ((stack) .t_count<=0?NULL:(stack) .t_base+(--(stack) .t_count) ) 
#define FSTACK_IS_INITIALIZED(stack) ((stack) .t_base) 
#define FSTACK_DESTROY(stack) (g_free((stack) .t_base) )  \

#define DSTACK_DECLARE(this) struct s_dstack this
#define DSTACK_INIT(this,type,initial_size)  \
(((this) .t_count= 0) , \
((this) .t_base= g_new(type,((this) .t_capacity= (initial_size) ) ) ) )  \

#define DSTACK_IS_INITIALIZED(this) ((this) .t_base) 
#define DSTACK_SAFE(this)  \
(((this) .t_count= (this) .t_capacity= 0) ,((this) .t_base= NULL) )  \

#define DSTACK_CLEAR(this) ((this) .t_count= 0) 
#define DSTACK_PUSH(this,type)  \
(((this) .t_count>=(this) .t_capacity?dstack_resize(&(this) ,sizeof(type) ) :0) , \
((type*) (this) .t_base+(this) .t_count++) ) 
#define DSTACK_POP(this,type) ((this) .t_count<=0?NULL: \
((type*) (this) .t_base+(--(this) .t_count) ) ) 
#define DSTACK_INDEX(this,type,ix) (DSTACK_BASE((this) ,type) +(ix) ) 
#define DSTACK_TOP(this,type) (DSTACK_LENGTH(this) <=0 \
?NULL \
:DSTACK_INDEX((this) ,type,DSTACK_LENGTH(this) -1) ) 
#define DSTACK_BASE(this,type) ((type*) (this) .t_base) 
#define DSTACK_LENGTH(this) ((this) .t_count)  \

#define STOLEN_DSTACK_DATA_FREE(data) ((data) &&(g_free(data) ,1) ) 
#define DSTACK_DESTROY(this) STOLEN_DSTACK_DATA_FREE(this.t_base)  \

#define DQUEUE_DECLARE(this) struct s_dqueue this
#define DQUEUE_INIT(this,type,initial_size)  \
((this.t_current= 0) ,DSTACK_INIT(this.t_stack,type,initial_size) ) 
#define DQUEUE_PUSH(this,type) DSTACK_PUSH(this.t_stack,type) 
#define DQUEUE_POP(this,type) DSTACK_POP(this.t_stack,type) 
#define DQUEUE_NEXT(this,type) (this.t_current>=DSTACK_LENGTH(this.t_stack)  \
?NULL \
:(DSTACK_BASE(this.t_stack,type) ) +this.t_current++) 
#define DQUEUE_BASE(this,type) DSTACK_BASE(this.t_stack,type) 
#define DQUEUE_END(this) DSTACK_LENGTH(this.t_stack) 
#define STOLEN_DQUEUE_DATA_FREE(data) STOLEN_DSTACK_DATA_FREE(data)  \

#define Sizeof_PSL(psar)  \
(sizeof(PSL_Object) +(psar->t_psl_length-1) *sizeof(gpointer) ) 
#define PSL_Datum(psl,i) ((psl) ->t_data[(i) ]) 
#define Dot_PSAR_of_R(r) (&(r) ->t_dot_psar_object) 
#define Dot_PSL_of_ES(es) ((es) ->t_dot_psl) 
#define obstack_chunk_alloc g_malloc
#define obstack_chunk_free g_free \

#define FATAL_FLAG (0x1u) 
#define MARPA_ERROR(message) (set_error(g,(message) ,0u) ) 
#define R_ERROR(message) (r_error(r,(message) ,0u) ) 
#define R_FATAL(message) (r_error(r,(message) ,FATAL_FLAG) ) 
#define MARPA_OFF_DEBUG1(a) 
#define MARPA_OFF_DEBUG2(a,b) 
#define MARPA_OFF_DEBUG3(a,b,c) 
#define MARPA_OFF_DEBUG4(a,b,c,d) 
#define MARPA_OFF_DEBUG5(a,b,c,d,e) 
#define MARPA_OFF_ASSERT(expr) 

#line 13443 "./marpa.w"

#include "marpa_obs.h"
/*1359:*/
#line 13237 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1359*/
#line 13445 "./marpa.w"

/*112:*/
#line 1008 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:112*//*136:*/
#line 1151 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:136*//*431:*/
#line 3527 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:431*//*476:*/
#line 3932 "./marpa.w"
struct s_AHFA_state;
/*:476*//*563:*/
#line 5133 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:563*//*680:*/
#line 5795 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:680*//*709:*/
#line 6028 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:709*//*740:*/
#line 6372 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:740*//*743:*/
#line 6414 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:743*//*849:*/
#line 7600 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:849*//*857:*/
#line 7681 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:857*//*959:*/
#line 8832 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:959*//*995:*/
#line 9280 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:995*//*1024:*/
#line 9722 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:1024*//*1052:*/
#line 10142 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:1052*//*1073:*/
#line 10353 "./marpa.w"

struct s_bocage;
typedef struct s_bocage*BOC;
/*:1073*//*1085:*/
#line 10452 "./marpa.w"

struct s_bocage_setup_per_es;
/*:1085*//*1120:*/
#line 10820 "./marpa.w"

struct s_tree;
typedef struct s_tree*TREE;
/*:1120*//*1145:*/
#line 11188 "./marpa.w"

struct s_bocage_rank;
typedef struct s_bocage_rank*RANK;
/*:1145*//*1165:*/
#line 11455 "./marpa.w"

struct s_fork;
typedef struct s_fork*FORK;
/*:1165*//*1186:*/
#line 11645 "./marpa.w"

struct s_value;
typedef struct s_value*VAL;
/*:1186*//*1289:*/
#line 12645 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1289*//*1293:*/
#line 12680 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1293*//*1300:*/
#line 12745 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1300*//*1302:*/
#line 12760 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1302*/
#line 13446 "./marpa.w"

/*45:*/
#line 700 "./marpa.w"

typedef struct marpa_g*GRAMMAR;
typedef const struct marpa_g*GRAMMAR_Const;

/*:45*//*135:*/
#line 1149 "./marpa.w"

typedef gint SYMID;
/*:135*//*210:*/
#line 1542 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:210*//*323:*/
#line 2344 "./marpa.w"
typedef gint SYMI;
/*:323*//*488:*/
#line 4018 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:488*//*564:*/
#line 5138 "./marpa.w"
typedef gint AEX;
/*:564*//*587:*/
#line 5301 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:587*//*677:*/
#line 5785 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:677*//*679:*/
#line 5789 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:679*//*781:*/
#line 6824 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:781*//*783:*/
#line 6836 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:783*//*987:*/
#line 9216 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:987*//*1023:*/
#line 9711 "./marpa.w"

typedef gint WHEID;


/*:1023*//*1051:*/
#line 10139 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:1051*//*1164:*/
#line 11452 "./marpa.w"

typedef Marpa_Fork_ID FORKID;
/*:1164*//*1185:*/
#line 11626 "./marpa.w"

typedef Marpa_Event*EVE;

/*:1185*//*1204:*/
#line 11920 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1204*//*1262:*/
#line 12406 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1262*/
#line 13447 "./marpa.w"

/*39:*/
#line 652 "./marpa.w"

const guint marpa_major_version= MARPA_MAJOR_VERSION;
const guint marpa_minor_version= MARPA_MINOR_VERSION;
const guint marpa_micro_version= MARPA_MICRO_VERSION;
const guint marpa_interface_age= MARPA_INTERFACE_AGE;
const guint marpa_binary_age= MARPA_BINARY_AGE;
/*:39*//*1001:*/
#line 9334 "./marpa.w"

static const gint dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:1001*//*1205:*/
#line 11927 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1205*/
#line 13448 "./marpa.w"

/*1290:*/
#line 12648 "./marpa.w"

struct s_dstack{gint t_count;gint t_capacity;gpointer t_base;};
/*:1290*/
#line 13449 "./marpa.w"

/*44:*/
#line 694 "./marpa.w"
struct marpa_g{
/*50:*/
#line 725 "./marpa.w"
GArray*t_symbols;
/*:50*//*61:*/
#line 779 "./marpa.w"
GArray*t_rules;
/*:61*//*72:*/
#line 826 "./marpa.w"
gpointer t_default_value;
/*:72*//*108:*/
#line 989 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:108*//*116:*/
#line 1025 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:116*//*125:*/
#line 1105 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:125*//*129:*/
#line 1127 "./marpa.w"

Marpa_Error_ID t_error;
Marpa_Error_ID t_fatal_error;
/*:129*//*433:*/
#line 3544 "./marpa.w"

AIM t_AHFA_items;
AIM*t_AHFA_items_by_rule;
/*:433*//*489:*/
#line 4022 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:489*/
#line 695 "./marpa.w"

/*78:*/
#line 846 "./marpa.w"
Marpa_Symbol_ID t_start_symid;
/*:78*//*84:*/
#line 874 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:84*//*88:*/
#line 904 "./marpa.w"
int t_size;
/*:88*//*91:*/
#line 917 "./marpa.w"
gint t_max_rule_length;
/*:91*//*324:*/
#line 2346 "./marpa.w"

gint t_symbol_instance_count;
/*:324*//*434:*/
#line 3550 "./marpa.w"

guint t_aim_count;
/*:434*//*490:*/
#line 4025 "./marpa.w"
gint t_AHFA_len;
/*:490*/
#line 696 "./marpa.w"

/*95:*/
#line 925 "./marpa.w"
guint t_is_precomputed:1;
/*:95*//*98:*/
#line 937 "./marpa.w"
guint t_has_loop:1;
/*:98*//*102:*/
#line 955 "./marpa.w"
guint t_is_lhs_terminal_ok:1;
/*:102*/
#line 697 "./marpa.w"

};
typedef struct marpa_g GRAMMARD;
/*:44*//*115:*/
#line 1018 "./marpa.w"

struct s_g_event{
gint t_type;
gint t_value;
};
typedef struct s_g_event GEV_Object;
/*:115*//*137:*/
#line 1158 "./marpa.w"

struct s_symbol{
/*146:*/
#line 1209 "./marpa.w"
GArray*t_lhs;
/*:146*//*153:*/
#line 1239 "./marpa.w"
GArray*t_rhs;
/*:153*//*192:*/
#line 1409 "./marpa.w"

struct s_symbol*t_alias;
/*:192*//*204:*/
#line 1505 "./marpa.w"

RULE t_virtual_lhs_rule;
/*:204*/
#line 1160 "./marpa.w"

/*144:*/
#line 1200 "./marpa.w"
SYMID t_symbol_id;
/*:144*/
#line 1161 "./marpa.w"

/*160:*/
#line 1261 "./marpa.w"
guint t_is_accessible:1;
/*:160*//*164:*/
#line 1279 "./marpa.w"
guint t_is_counted:1;
/*:164*//*168:*/
#line 1297 "./marpa.w"
guint t_is_nullable:1;
/*:168*//*172:*/
#line 1316 "./marpa.w"
guint t_is_nulling:1;
/*:172*//*176:*/
#line 1336 "./marpa.w"
guint t_is_terminal:1;
/*:176*//*182:*/
#line 1362 "./marpa.w"
guint t_is_productive:1;
/*:182*//*186:*/
#line 1380 "./marpa.w"
guint t_is_start:1;
/*:186*//*191:*/
#line 1406 "./marpa.w"

guint t_is_proper_alias:1;
guint t_is_nulling_alias:1;
/*:191*/
#line 1162 "./marpa.w"

};
typedef struct s_symbol SYM_Object;

/*:137*//*209:*/
#line 1533 "./marpa.w"

struct s_rule{
/*238:*/
#line 1948 "./marpa.w"
gint t_rhs_length;
/*:238*//*255:*/
#line 2020 "./marpa.w"
Marpa_Rule_ID t_id;
/*:255*//*300:*/
#line 2252 "./marpa.w"
gint t_virtual_start;
/*:300*//*304:*/
#line 2268 "./marpa.w"
gint t_virtual_end;
/*:304*//*309:*/
#line 2284 "./marpa.w"
Marpa_Rule_ID t_original;
/*:309*//*314:*/
#line 2303 "./marpa.w"
gint t_real_symbol_count;
/*:314*//*325:*/
#line 2357 "./marpa.w"

gint t_symbol_instance_base;
gint t_last_proper_symi;
/*:325*/
#line 1535 "./marpa.w"

/*258:*/
#line 2032 "./marpa.w"
guint t_is_discard:1;
/*:258*//*272:*/
#line 2116 "./marpa.w"
guint t_is_loop:1;
/*:272*//*277:*/
#line 2137 "./marpa.w"
guint t_is_virtual_loop:1;
/*:277*//*284:*/
#line 2173 "./marpa.w"
guint t_is_used:1;
/*:284*//*288:*/
#line 2189 "./marpa.w"
guint t_is_start:1;
/*:288*//*292:*/
#line 2220 "./marpa.w"
guint t_is_virtual_lhs:1;
/*:292*//*296:*/
#line 2235 "./marpa.w"
guint t_is_virtual_rhs:1;
/*:296*//*318:*/
#line 2316 "./marpa.w"
guint t_is_semantic_equivalent:1;
/*:318*/
#line 1536 "./marpa.w"

/*239:*/
#line 1951 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:239*/
#line 1537 "./marpa.w"

};
/*:209*//*430:*/
#line 3521 "./marpa.w"

struct s_AHFA_item{
gint t_sort_key;
/*440:*/
#line 3576 "./marpa.w"

RULE t_rule;

/*:440*/
#line 3524 "./marpa.w"

/*441:*/
#line 3582 "./marpa.w"

gint t_position;

/*:441*//*442:*/
#line 3591 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:442*//*443:*/
#line 3600 "./marpa.w"

gint t_leading_nulls;

/*:443*/
#line 3525 "./marpa.w"

};
/*:430*//*477:*/
#line 3933 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*480:*/
#line 3954 "./marpa.w"

SYMID*t_complete_symbols;

/*:480*//*482:*/
#line 3964 "./marpa.w"

AIM*t_items;
/*:482*//*497:*/
#line 4066 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:497*//*566:*/
#line 5151 "./marpa.w"

TRANS*t_transitions;
/*:566*/
#line 3940 "./marpa.w"

/*479:*/
#line 3952 "./marpa.w"

guint t_complete_symbol_count;
/*:479*//*483:*/
#line 3966 "./marpa.w"

guint t_item_count;
/*:483*//*498:*/
#line 4067 "./marpa.w"
guint t_postdot_sym_count;

/*:498*//*512:*/
#line 4195 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:512*/
#line 3941 "./marpa.w"

guint t_has_completed_start_rule:1;
/*487:*/
#line 4015 "./marpa.w"

guint t_is_predict:1;

/*:487*/
#line 3943 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:477*//*565:*/
#line 5139 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
gint t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:565*//*681:*/
#line 5801 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:681*//*682:*/
#line 5806 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
gint t_postdot_sym_count;
/*683:*/
#line 5818 "./marpa.w"

gint t_eim_count;
/*:683*//*685:*/
#line 5832 "./marpa.w"

gint t_ordinal;
/*:685*/
#line 5810 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*684:*/
#line 5821 "./marpa.w"

EIM*t_earley_items;

/*:684*//*1311:*/
#line 12835 "./marpa.w"

PSL t_dot_psl;
/*:1311*/
#line 5813 "./marpa.w"

};

/*:682*//*741:*/
#line 6376 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:741*//*744:*/
#line 6417 "./marpa.w"

struct s_leo_item{
EIX_Object t_earley_ix;
ES t_origin;
AHFA t_top_ahfa;
LIM t_predecessor;
EIM t_base;
ES t_set;
gint t_chain_length;
};
typedef struct s_leo_item LIM_Object;

/*:744*//*758:*/
#line 6567 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:758*//*850:*/
#line 7608 "./marpa.w"

struct s_token{
gint t_type;
SYMID t_symbol_id;
gpointer t_value;
};
typedef struct s_token TOK_Object;

/*:850*//*858:*/
#line 7691 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:858*//*961:*/
#line 8854 "./marpa.w"

struct s_ur_node_stack{
struct obstack t_obs;
UR t_base;
UR t_top;
};
struct s_ur_node{
UR t_prev;
UR t_next;
EIM t_earley_item;
AEX t_aex;
};
/*:961*//*998:*/
#line 9309 "./marpa.w"

struct s_draft_or_node
{
/*997:*/
#line 9303 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:997*/
#line 9312 "./marpa.w"

DAND t_draft_and_node;
};
/*:998*//*999:*/
#line 9315 "./marpa.w"

struct s_final_or_node
{
/*997:*/
#line 9303 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:997*/
#line 9318 "./marpa.w"

gint t_first_and_node_id;
gint t_and_node_count;
};
/*:999*//*1000:*/
#line 9326 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:1000*//*1025:*/
#line 9729 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:1025*//*1053:*/
#line 10149 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:1053*//*1086:*/
#line 10454 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:1086*//*1121:*/
#line 10836 "./marpa.w"

/*1166:*/
#line 11466 "./marpa.w"

struct s_fork{
OR t_or_node;
gint t_choice;
FORKID t_parent;
guint t_is_cause_ready:1;
guint t_is_predecessor_ready:1;
guint t_is_cause_of_parent:1;
guint t_is_predecessor_of_parent:1;
};
typedef struct s_fork FORK_Object;

/*:1166*/
#line 10837 "./marpa.w"

/*1187:*/
#line 11662 "./marpa.w"

struct s_value{
DSTACK_DECLARE(t_virtual_stack);
FORKID t_fork;
gint t_tos;
guint t_trace:1;
guint t_active:1;
};
typedef struct s_value VAL_Object;

/*:1187*/
#line 10838 "./marpa.w"

struct s_tree{
FSTACK_DECLARE(t_fork_stack,FORK_Object)
FSTACK_DECLARE(t_fork_worklist,gint)
Bit_Vector t_and_node_in_use;
gint t_parse_count;
VAL_Object t_val;
};
typedef struct s_tree TREE_Object;

/*:1121*//*1146:*/
#line 11198 "./marpa.w"

struct s_bocage_rank{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
TREE_Object t_tree;
};
typedef struct s_bocage_rank RANK_Object;

/*:1146*//*1294:*/
#line 12683 "./marpa.w"

struct s_dqueue{gint t_current;struct s_dstack t_stack;};

/*:1294*//*1301:*/
#line 12751 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
gpointer t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1301*//*1303:*/
#line 12775 "./marpa.w"

struct s_per_earley_set_arena{
gint t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1303*/
#line 13450 "./marpa.w"

/*588:*/
#line 5303 "./marpa.w"

struct marpa_r{
/*595:*/
#line 5361 "./marpa.w"
struct marpa_g*t_grammar;

/*:595*//*602:*/
#line 5402 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:602*//*621:*/
#line 5487 "./marpa.w"
gpointer*t_sym_workarea;
/*:621*//*625:*/
#line 5502 "./marpa.w"
gpointer*t_workarea2;
/*:625*//*629:*/
#line 5523 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:629*//*633:*/
#line 5549 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:633*//*640:*/
#line 5602 "./marpa.w"

GTree*t_earley_item_tree;
/*:640*//*661:*/
#line 5732 "./marpa.w"
struct obstack t_obs;
/*:661*//*692:*/
#line 5885 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:692*//*724:*/
#line 6204 "./marpa.w"

EIM t_trace_earley_item;
/*:724*//*764:*/
#line 6620 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:764*//*806:*/
#line 7109 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:806*//*851:*/
#line 7632 "./marpa.w"

struct obstack t_token_obs;
TOK*t_tokens_by_symid;
/*:851*//*859:*/
#line 7699 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:859*//*885:*/
#line 8001 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:885*//*889:*/
#line 8013 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:889*//*893:*/
#line 8025 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:893*//*962:*/
#line 8867 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:962*//*1075:*/
#line 10364 "./marpa.w"

BOC t_bocage;
/*:1075*//*1304:*/
#line 12783 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1304*/
#line 5305 "./marpa.w"

/*598:*/
#line 5389 "./marpa.w"

Marpa_Phase t_phase;
/*:598*//*610:*/
#line 5440 "./marpa.w"
gint t_earley_item_warning_threshold;
/*:610*//*616:*/
#line 5468 "./marpa.w"
EARLEME t_furthest_earleme;
/*:616*//*686:*/
#line 5836 "./marpa.w"

gint t_earley_set_count;
/*:686*/
#line 5306 "./marpa.w"

/*651:*/
#line 5667 "./marpa.w"

guint t_use_leo_flag:1;
guint t_is_using_leo:1;
/*:651*//*657:*/
#line 5712 "./marpa.w"
guint t_is_exhausted:1;
/*:657*//*807:*/
#line 7112 "./marpa.w"

guint t_trace_source_type:3;
/*:807*/
#line 5307 "./marpa.w"

};

/*:588*/
#line 13451 "./marpa.w"

/*782:*/
#line 6827 "./marpa.w"

struct s_source{
gpointer t_predecessor;
union{
gpointer t_completion;
TOK t_token;
}t_cause;
};

/*:782*//*784:*/
#line 6839 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:784*//*785:*/
#line 6845 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:785*//*786:*/
#line 6852 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:786*/
#line 13452 "./marpa.w"

/*710:*/
#line 6035 "./marpa.w"

struct s_earley_item_key{
AHFA t_state;
ES t_origin;
ES t_set;
};
typedef struct s_earley_item_key EIK_Object;
struct s_earley_item{
EIK_Object t_key;
union u_source_container t_container;
gint t_ordinal;
/*721:*/
#line 6175 "./marpa.w"

guint t_source_type:3;

/*:721*/
#line 6046 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:710*/
#line 13453 "./marpa.w"

/*1074:*/
#line 10356 "./marpa.w"

struct s_bocage{
/*1002:*/
#line 9344 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:1002*//*1077:*/
#line 10372 "./marpa.w"

struct obstack t_obs;
/*:1077*//*1147:*/
#line 11209 "./marpa.w"

RANK_Object t_rank;
/*:1147*/
#line 10358 "./marpa.w"

/*1003:*/
#line 9347 "./marpa.w"

gint t_or_node_count;
gint t_and_node_count;
ORID t_top_or_node_id;

/*:1003*/
#line 10359 "./marpa.w"

/*1078:*/
#line 10374 "./marpa.w"

unsigned int is_obstack_initialized:1;
/*:1078*/
#line 10360 "./marpa.w"

};
typedef struct s_bocage BOC_Object;
/*:1074*/
#line 13454 "./marpa.w"

/*60:*/
#line 772 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid);

/*:60*//*119:*/
#line 1045 "./marpa.w"

static inline
void event_new(struct marpa_g*g,gint type);
/*:119*//*121:*/
#line 1057 "./marpa.w"

static inline
void int_event_new(struct marpa_g*g,gint type,gint value);
/*:121*//*123:*/
#line 1069 "./marpa.w"

gint marpa_g_event(struct marpa_g*g,struct marpa_g_event*public_event,gint ix);
/*:123*//*138:*/
#line 1166 "./marpa.w"

static inline
SYM symbol_new(struct marpa_g*g);
/*:138*//*143:*/
#line 1195 "./marpa.w"

static inline void symbol_free(SYM symbol);

/*:143*//*152:*/
#line 1230 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id);

/*:152*//*159:*/
#line 1257 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id);

/*:159*//*189:*/
#line 1393 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol);
/*:189*//*195:*/
#line 1434 "./marpa.w"

static inline SYM symbol_proper_alias(SYM symbol);
/*:195*//*198:*/
#line 1461 "./marpa.w"

static inline SYM symbol_null_alias(SYM symbol);
/*:198*//*201:*/
#line 1472 "./marpa.w"

static inline
SYM symbol_alias_create(GRAMMAR g,SYM symbol);
/*:201*//*213:*/
#line 1552 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length);
/*:213*//*231:*/
#line 1793 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length);
/*:231*//*243:*/
#line 1973 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
/*:243*//*247:*/
#line 1985 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule);
/*:247*//*251:*/
#line 2001 "./marpa.w"

static inline gsize rule_length_get(RULE rule);
/*:251*//*265:*/
#line 2081 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule);
/*:265*//*269:*/
#line 2105 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule);
/*:269*//*283:*/
#line 2167 "./marpa.w"

static inline gint rule_is_nulling(GRAMMAR g,RULE rule);

/*:283*//*327:*/
#line 2362 "./marpa.w"

static inline gint symbol_instance_of_ahfa_item_get(AIM aim);
/*:327*//*334:*/
#line 2485 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:334*//*371:*/
#line 2819 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:371*//*410:*/
#line 3200 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:410*//*411:*/
#line 3207 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);
/*:411*//*421:*/
#line 3349 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:421*//*439:*/
#line 3568 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id);

/*:439*//*456:*/
#line 3689 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:456*//*461:*/
#line 3764 "./marpa.w"

static gint cmp_by_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:461*//*464:*/
#line 3783 "./marpa.w"

static gint cmp_by_postdot_and_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:464*//*484:*/
#line 3970 "./marpa.w"

static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM aim_sought);
/*:484*//*496:*/
#line 4056 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id);


/*:496*//*516:*/
#line 4226 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b);
/*:516*//*519:*/
#line 4252 "./marpa.w"

PRIVATE_NOT_INLINE void create_AHFA_states(struct marpa_g*g);
/*:519*//*538:*/
#line 4725 "./marpa.w"

static inline AHFA assign_AHFA_state(
AHFA state_p,GTree*duplicates);
/*:538*//*551:*/
#line 4922 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:551*//*554:*/
#line 4979 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
);
/*:554*//*567:*/
#line 5153 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition);
/*:567*//*569:*/
#line 5160 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition);
/*:569*//*571:*/
#line 5168 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix);
/*:571*//*573:*/
#line 5181 "./marpa.w"
static inline
TRANS*transitions_new(struct marpa_g*g);
/*:573*//*575:*/
#line 5195 "./marpa.w"

static inline
void transition_add(struct obstack*obstack,AHFA from_ahfa,SYMID symid,AHFA to_ahfa);
/*:575*//*577:*/
#line 5212 "./marpa.w"

static inline
void completion_count_inc(struct obstack*obstack,AHFA from_ahfa,SYMID symid);
/*:577*//*608:*/
#line 5428 "./marpa.w"

static inline ES current_es_of_r(RECCE r);
/*:608*//*688:*/
#line 5842 "./marpa.w"

static inline ES earley_set_new(RECCE r,EARLEME id);
/*:688*//*711:*/
#line 6056 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key);
/*:711*//*713:*/
#line 6080 "./marpa.w"

static inline
EIM earley_item_assign(const RECCE r,const ES set,const ES origin,const AHFA state);
/*:713*//*717:*/
#line 6135 "./marpa.w"

static inline gint trace_earley_item_cmp(gconstpointer ap,gconstpointer bp);
/*:717*//*719:*/
#line 6146 "./marpa.w"

static inline gint earley_item_cmp(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED);
/*:719*//*722:*/
#line 6178 "./marpa.w"

static const char*invalid_source_type_message(guint type);
/*:722*//*736:*/
#line 6333 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r);
/*:736*//*760:*/
#line 6583 "./marpa.w"

static inline PIM*pim_sym_p_find(ES set,SYMID symid);
/*:760*//*762:*/
#line 6605 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid);
/*:762*//*773:*/
#line 6751 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r);
/*:773*//*790:*/
#line 6892 "./marpa.w"
static inline void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
TOK token);
/*:790*//*792:*/
#line 6924 "./marpa.w"
static inline void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause);
/*:792*//*799:*/
#line 7031 "./marpa.w"
static inline void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause);

/*:799*//*802:*/
#line 7072 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item);

/*:802*//*832:*/
#line 7373 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r);
/*:832*//*854:*/
#line 7658 "./marpa.w"

static inline
TOK token_new(struct marpa_r*r,SYMID symbol_id,gpointer value);
/*:854*//*862:*/
#line 7714 "./marpa.w"

static inline gint alternative_insertion_point(RECCE r,ALT new_alternative);
/*:862*//*864:*/
#line 7755 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b);
/*:864*//*866:*/
#line 7779 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme);
/*:866*//*868:*/
#line 7796 "./marpa.w"

static inline gint alternative_insert(RECCE r,ALT alternative);
/*:868*//*911:*/
#line 8254 "./marpa.w"

static inline void earley_set_update_items(RECCE r,ES set);
/*:911*//*913:*/
#line 8278 "./marpa.w"

static inline void r_update_earley_sets(RECCE r);
/*:913*//*916:*/
#line 8304 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES set);
/*:916*//*965:*/
#line 8878 "./marpa.w"

static inline void ur_node_stack_init(URS stack);
/*:965*//*967:*/
#line 8888 "./marpa.w"

static inline void ur_node_stack_reset(URS stack);
/*:967*//*969:*/
#line 8895 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack);
/*:969*//*971:*/
#line 8905 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev);
/*:971*//*973:*/
#line 8916 "./marpa.w"

static inline void ur_node_push(URS stack,EIM earley_item,AEX aex);
/*:973*//*975:*/
#line 8934 "./marpa.w"

static inline UR ur_node_pop(URS stack);
/*:975*//*980:*/
#line 8999 "./marpa.w"

static inline gint psia_test_and_set(
struct obstack*obs,
struct s_bocage_setup_per_es*per_es_data,
EIM earley_item,
AEX ahfa_element_ix);
/*:980*//*1017:*/
#line 9603 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base);
/*:1017*//*1019:*/
#line 9617 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item);
/*:1019*//*1026:*/
#line 9737 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause);
/*:1026*//*1029:*/
#line 9763 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause);
/*:1029*//*1057:*/
#line 10202 "./marpa.w"

gint marpa_and_node_count(struct marpa_r*r);
/*:1057*//*1060:*/
#line 10241 "./marpa.w"

gint marpa_and_node_parent(struct marpa_r*r,int and_node_id);
/*:1060*//*1062:*/
#line 10253 "./marpa.w"

gint marpa_and_node_predecessor(struct marpa_r*r,int and_node_id);
/*:1062*//*1064:*/
#line 10270 "./marpa.w"

gint marpa_and_node_cause(struct marpa_r*r,int and_node_id);
/*:1064*//*1066:*/
#line 10287 "./marpa.w"

gint marpa_and_node_symbol(struct marpa_r*r,int and_node_id);
/*:1066*//*1070:*/
#line 10333 "./marpa.w"

SYMID and_node_token(AND and_node,gpointer*value_p);
/*:1070*//*1091:*/
#line 10528 "./marpa.w"

static ORID r_create_null_bocage(RECCE r,BOC b);
/*:1091*//*1102:*/
#line 10680 "./marpa.w"

static inline void bocage_destroy(struct marpa_r*r);
/*:1102*//*1106:*/
#line 10723 "./marpa.w"

gint marpa_or_node_set(struct marpa_r*r,int or_node_id);
/*:1106*//*1108:*/
#line 10735 "./marpa.w"

gint marpa_or_node_origin(struct marpa_r*r,int or_node_id);
/*:1108*//*1110:*/
#line 10747 "./marpa.w"

gint marpa_or_node_rule(struct marpa_r*r,int or_node_id);
/*:1110*//*1112:*/
#line 10759 "./marpa.w"

gint marpa_or_node_position(struct marpa_r*r,int or_node_id);
/*:1112*//*1114:*/
#line 10771 "./marpa.w"

gint marpa_or_node_first_and(struct marpa_r*r,int or_node_id);
/*:1114*//*1116:*/
#line 10783 "./marpa.w"

gint marpa_or_node_last_and(struct marpa_r*r,int or_node_id);
/*:1116*//*1118:*/
#line 10796 "./marpa.w"

gint marpa_or_node_and_count(struct marpa_r*r,int or_node_id);
/*:1118*//*1122:*/
#line 10848 "./marpa.w"

static inline void tree_exhaust(TREE tree);
/*:1122*//*1124:*/
#line 10869 "./marpa.w"

static inline void tree_safe(TREE tree);
/*:1124*//*1128:*/
#line 10928 "./marpa.w"

static inline void tree_and_node_claim(TREE tree,ANDID and_node_id);
static inline void tree_and_node_release(TREE tree,ANDID and_node_id);
static inline gint tree_and_node_try(TREE tree,ANDID and_node_id);
/*:1128*//*1135:*/
#line 11083 "./marpa.w"

static inline gint or_node_next_choice(BOC b,TREE tree,OR or_node,gint start_choice);
/*:1135*//*1139:*/
#line 11125 "./marpa.w"

static inline void tree_destroy(TREE tree);
/*:1139*//*1143:*/
#line 11162 "./marpa.w"

gint marpa_tree_size(struct marpa_r*r);
/*:1143*//*1149:*/
#line 11214 "./marpa.w"

static inline void rank_safe(RANK rank);
/*:1149*//*1152:*/
#line 11226 "./marpa.w"

static inline void rank_freeze(RANK rank);
static inline void rank_destroy(RANK rank);
/*:1152*//*1160:*/
#line 11389 "./marpa.w"

static inline ANDID and_order_get(BOC b,OR or_node,gint ix);
/*:1160*//*1169:*/
#line 11512 "./marpa.w"

gint marpa_fork_or_node(struct marpa_r*r,int fork_id);
/*:1169*//*1171:*/
#line 11525 "./marpa.w"

gint marpa_fork_choice(struct marpa_r*r,int fork_id);
/*:1171*//*1173:*/
#line 11546 "./marpa.w"

gint marpa_fork_parent(struct marpa_r*r,int fork_id);
/*:1173*//*1175:*/
#line 11559 "./marpa.w"

gint marpa_fork_cause_is_ready(struct marpa_r*r,int fork_id);
/*:1175*//*1177:*/
#line 11572 "./marpa.w"

gint marpa_fork_predecessor_is_ready(struct marpa_r*r,int fork_id);
/*:1177*//*1179:*/
#line 11585 "./marpa.w"

gint marpa_fork_is_cause(struct marpa_r*r,int fork_id);
/*:1179*//*1181:*/
#line 11598 "./marpa.w"

gint marpa_fork_is_predecessor(struct marpa_r*r,int fork_id);
/*:1181*//*1188:*/
#line 11672 "./marpa.w"

static inline void val_safe(VAL val);
/*:1188*//*1194:*/
#line 11755 "./marpa.w"

static inline void val_destroy(VAL val);
/*:1194*//*1207:*/
#line 11940 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:1207*//*1209:*/
#line 11950 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:1209*//*1210:*/
#line 11954 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);
/*:1210*//*1212:*/
#line 11974 "./marpa.w"

static inline Bit_Vector bv_obs_create(struct obstack*obs,guint bits);
/*:1212*//*1215:*/
#line 12007 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:1215*//*1217:*/
#line 12026 "./marpa.w"

static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from);

/*:1217*//*1219:*/
#line 12039 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:1219*//*1221:*/
#line 12049 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:1221*//*1223:*/
#line 12057 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:1223*//*1225:*/
#line 12070 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:1225*//*1227:*/
#line 12074 "./marpa.w"

static inline void bv_clear(Bit_Vector bv);
/*:1227*//*1229:*/
#line 12090 "./marpa.w"

static inline void bv_over_clear(Bit_Vector bv,guint bit);
/*:1229*//*1233:*/
#line 12104 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:1233*//*1235:*/
#line 12112 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:1235*//*1237:*/
#line 12120 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:1237*//*1239:*/
#line 12125 "./marpa.w"

static inline gboolean bv_bit_test_and_set(Bit_Vector vector,guint bit);
/*:1239*//*1242:*/
#line 12152 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:1242*//*1244:*/
#line 12165 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:1244*//*1246:*/
#line 12177 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1246*//*1248:*/
#line 12189 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1248*//*1250:*/
#line 12201 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:1250*//*1252:*/
#line 12275 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:1252*//*1254:*/
#line 12293 "./marpa.w"

static inline guint bv_count(Bit_Vector v);

/*:1254*//*1260:*/
#line 12382 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:1260*//*1265:*/
#line 12430 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:1265*//*1267:*/
#line 12438 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:1267*//*1269:*/
#line 12452 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:1269*//*1271:*/
#line 12470 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:1271*//*1274:*/
#line 12479 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:1274*//*1277:*/
#line 12488 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:1277*//*1280:*/
#line 12497 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:1280*//*1282:*/
#line 12550 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:1282*//*1292:*/
#line 12656 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_size);

/*:1292*//*1307:*/
#line 12789 "./marpa.w"

static inline void psar_init(const PSAR psar,gint length);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
/*:1307*//*1313:*/
#line 12847 "./marpa.w"

static inline void psar_reset(const PSAR psar);
/*:1313*//*1315:*/
#line 12866 "./marpa.w"

static inline void psar_dealloc(const PSAR psar);
/*:1315*//*1317:*/
#line 12887 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar);
/*:1317*//*1321:*/
#line 12913 "./marpa.w"

static inline PSL psl_alloc(const PSAR psar);
/*:1321*//*1356:*/
#line 13198 "./marpa.w"

static void set_error(struct marpa_g*g,Marpa_Message_ID message,guint flags);
static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags);
/*:1356*//*1362:*/
#line 13319 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*eim_tag_safe(gchar*buffer,EIM eim);
PRIVATE_NOT_INLINE gchar*eim_tag(EIM eim);
#endif
/*:1362*//*1364:*/
#line 13347 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim);
#endif
/*:1364*//*1366:*/
#line 13370 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*or_tag_safe(gchar*buffer,OR or);
PRIVATE_NOT_INLINE const gchar*or_tag(OR or);
#endif
/*:1366*/
#line 13455 "./marpa.w"

/*58:*/
#line 756 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symid,
SYM symbol)
{
g_array_insert_val(g->t_symbols,(unsigned)symid,symbol);
}

/*:58*//*70:*/
#line 808 "./marpa.w"

static inline
void rule_add(
struct marpa_g*g,
RULEID rule_id,
RULE rule)
{
g_array_insert_val(g->t_rules,(unsigned)rule_id,rule);
LV_Size_of_G(g)+= 1+Length_of_RULE(rule);
g->t_max_rule_length= MAX(Length_of_RULE(rule),g->t_max_rule_length);
}

/*:70*/
#line 13456 "./marpa.w"

/*40:*/
#line 659 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:40*//*46:*/
#line 704 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*51:*/
#line 726 "./marpa.w"

g->t_symbols= g_array_new(FALSE,FALSE,sizeof(SYM));
/*:51*//*62:*/
#line 780 "./marpa.w"

g->t_rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:62*//*73:*/
#line 827 "./marpa.w"

Default_Value_of_G(g)= NULL;
/*:73*//*79:*/
#line 847 "./marpa.w"

g->t_start_symid= -1;
/*:79*//*85:*/
#line 877 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;
/*:85*//*89:*/
#line 905 "./marpa.w"

LV_Size_of_G(g)= 0;

/*:89*//*92:*/
#line 918 "./marpa.w"

g->t_max_rule_length= 0;

/*:92*//*96:*/
#line 926 "./marpa.w"

g->t_is_precomputed= FALSE;
/*:96*//*99:*/
#line 938 "./marpa.w"

g->t_has_loop= FALSE;
/*:99*//*103:*/
#line 956 "./marpa.w"

g->t_is_lhs_terminal_ok= TRUE;
/*:103*//*109:*/
#line 990 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:109*//*117:*/
#line 1033 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:117*//*126:*/
#line 1108 "./marpa.w"

obstack_init(&g->t_obs);
obstack_init(&g->t_obs_tricky);
/*:126*//*130:*/
#line 1130 "./marpa.w"

g->t_error= NULL;
g->t_fatal_error= NULL;
/*:130*//*436:*/
#line 3555 "./marpa.w"

g->t_AHFA_items= NULL;
g->t_AHFA_items_by_rule= NULL;
/*:436*//*491:*/
#line 4026 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:491*/
#line 707 "./marpa.w"

return g;}
/*:46*//*48:*/
#line 712 "./marpa.w"

void marpa_g_free(struct marpa_g*g)
{/*52:*/
#line 728 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->t_symbols->len;id++)
{symbol_free(SYM_by_ID(id));}}
g_array_free(g->t_symbols,TRUE);

/*:52*//*63:*/
#line 782 "./marpa.w"

g_array_free(g->t_rules,TRUE);

/*:63*//*110:*/
#line 991 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:110*//*118:*/
#line 1035 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:118*//*127:*/
#line 1111 "./marpa.w"

obstack_free(&g->t_obs,NULL);
obstack_free(&g->t_obs_tricky,NULL);

/*:127*//*437:*/
#line 3558 "./marpa.w"

if(g->t_AHFA_items){g_free(g->t_AHFA_items);};
if(g->t_AHFA_items_by_rule){g_free(g->t_AHFA_items_by_rule);};

/*:437*//*492:*/
#line 4030 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*493:*/
#line 4040 "./marpa.w"
{
TRANS*ahfa_transitions= LV_TRANSs_of_AHFA(ahfa_state);
if(ahfa_transitions)
g_free(TRANSs_of_AHFA(ahfa_state));
}

/*:493*/
#line 4034 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:492*/
#line 714 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:48*//*53:*/
#line 736 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->t_symbols;}
/*:53*//*56:*/
#line 746 "./marpa.w"

gint marpa_symbol_count(struct marpa_g*g){
return SYM_Count_of_G(g);
}

/*:56*//*59:*/
#line 767 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid){
return symid>=0&&(guint)symid<g->t_symbols->len;
}
/*:59*//*66:*/
#line 789 "./marpa.w"

gint marpa_rule_count(struct marpa_g*g){
return RULE_Count_of_G(g);
}

/*:66*//*67:*/
#line 797 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->t_rules;}
/*:67*//*75:*/
#line 831 "./marpa.w"

gpointer marpa_default_value(struct marpa_g*g)
{return Default_Value_of_G(g);}
/*:75*//*77:*/
#line 836 "./marpa.w"

gboolean marpa_default_value_set(struct marpa_g*g,gpointer default_value)
{
/*1336:*/
#line 13063 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1336*/
#line 839 "./marpa.w"

/*1339:*/
#line 13073 "./marpa.w"

if(G_is_Precomputed(g)){
g->t_error= "grammar precomputed";
return failure_indicator;
}
/*:1339*/
#line 840 "./marpa.w"

Default_Value_of_G(g)= default_value;
return TRUE;
}

/*:77*//*80:*/
#line 849 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->t_start_symid;}
/*:80*//*82:*/
#line 856 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1336:*/
#line 13063 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1336*/
#line 859 "./marpa.w"

/*1339:*/
#line 13073 "./marpa.w"

if(G_is_Precomputed(g)){
g->t_error= "grammar precomputed";
return failure_indicator;
}
/*:1339*/
#line 860 "./marpa.w"

/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 861 "./marpa.w"

g->t_start_symid= symid;
return TRUE;
}
/*:82*//*97:*/
#line 928 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 931 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 932 "./marpa.w"

return G_is_Precomputed(g);
}

/*:97*//*101:*/
#line 942 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 945 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 946 "./marpa.w"

return g->t_has_loop;
}

/*:101*//*104:*/
#line 959 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->t_is_lhs_terminal_ok;}
/*:104*//*106:*/
#line 966 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(
struct marpa_g*g,gboolean value)
{
if(G_is_Precomputed(g)){
g->t_error= "precomputed";
return FALSE;
}
g->t_is_lhs_terminal_ok= value;
return TRUE;
}
/*:106*//*120:*/
#line 1048 "./marpa.w"

static inline
void event_new(struct marpa_g*g,gint type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:120*//*122:*/
#line 1060 "./marpa.w"

void int_event_new(struct marpa_g*g,gint type,gint value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:122*//*124:*/
#line 1071 "./marpa.w"

gint
marpa_g_event(struct marpa_g*g,struct marpa_g_event*public_event,
gint ix)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 1076 "./marpa.w"

const gint index_out_of_bounds= -1;
DSTACK events= &g->t_events;
GEV internal_event;
gint type;

if(ix<0)
return failure_indicator;
if(ix> DSTACK_LENGTH(*events))
return index_out_of_bounds;
internal_event= DSTACK_INDEX(*events,GEV_Object,ix);
type= internal_event->t_type;
public_event->t_type= type;
public_event->t_value= internal_event->t_value;
return type;
}

/*:124*//*132:*/
#line 1139 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g)
{return g->t_error?g->t_error:"unknown error";}
/*:132*//*139:*/
#line 1169 "./marpa.w"

static inline SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= g_malloc(sizeof(SYM_Object));
/*145:*/
#line 1201 "./marpa.w"
ID_of_SYM(symbol)= g->t_symbols->len;

/*:145*//*147:*/
#line 1210 "./marpa.w"

symbol->t_lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:147*//*154:*/
#line 1240 "./marpa.w"

symbol->t_rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:154*//*161:*/
#line 1262 "./marpa.w"

symbol->t_is_accessible= FALSE;
/*:161*//*165:*/
#line 1280 "./marpa.w"

symbol->t_is_counted= FALSE;
/*:165*//*169:*/
#line 1298 "./marpa.w"

symbol->t_is_nullable= FALSE;
/*:169*//*173:*/
#line 1317 "./marpa.w"

symbol->t_is_nulling= FALSE;
/*:173*//*177:*/
#line 1337 "./marpa.w"

symbol->t_is_terminal= FALSE;
/*:177*//*183:*/
#line 1363 "./marpa.w"

symbol->t_is_productive= FALSE;
/*:183*//*187:*/
#line 1381 "./marpa.w"
symbol->t_is_start= FALSE;
/*:187*//*193:*/
#line 1411 "./marpa.w"

symbol->t_is_proper_alias= FALSE;
symbol->t_is_nulling_alias= FALSE;
symbol->t_alias= NULL;

/*:193*//*205:*/
#line 1507 "./marpa.w"

symbol->t_virtual_lhs_rule= NULL;

/*:205*/
#line 1174 "./marpa.w"

{
SYMID id= ID_of_SYM(symbol);
g_symbol_add(g,id,symbol);
}
return symbol;
}

/*:139*//*141:*/
#line 1184 "./marpa.w"

Marpa_Symbol_ID
marpa_symbol_new(struct marpa_g*g)
{
SYMID id= ID_of_SYM(symbol_new(g));
return id;
}

/*:141*//*142:*/
#line 1192 "./marpa.w"

static inline void symbol_free(SYM symbol)
{/*148:*/
#line 1212 "./marpa.w"

g_array_free(symbol->t_lhs,TRUE);
/*:148*//*155:*/
#line 1242 "./marpa.w"
g_array_free(symbol->t_rhs,TRUE);

/*:155*/
#line 1194 "./marpa.w"
g_free(symbol);}
/*:142*//*149:*/
#line 1217 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1337:*/
#line 13065 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1337*/
#line 1219 "./marpa.w"

/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 1220 "./marpa.w"

return SYM_by_ID(symid)->t_lhs;}
/*:149*//*151:*/
#line 1224 "./marpa.w"
static inline
void symbol_lhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id)
{symbol_lhs_add(SYM_by_ID(symid),rule_id);}
/*:151*//*156:*/
#line 1247 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1337:*/
#line 13065 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1337*/
#line 1249 "./marpa.w"

/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 1250 "./marpa.w"

return SYM_by_ID(symid)->t_rhs;}
/*:156*//*158:*/
#line 1254 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_rhs,rule_id);}
/*:158*//*162:*/
#line 1272 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_accessible;}
/*:162*//*166:*/
#line 1290 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_counted;}
/*:166*//*170:*/
#line 1308 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_nullable;}
/*:170*//*174:*/
#line 1327 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 1329 "./marpa.w"

/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 1330 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));}
/*:174*//*178:*/
#line 1349 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYMID_is_Terminal(id);}
/*:178*//*180:*/
#line 1354 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYMID_is_Terminal(id)= value;}
/*:180*//*184:*/
#line 1373 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_productive;}
/*:184*//*188:*/
#line 1384 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol)
{return symbol->t_is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 1389 "./marpa.w"

/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 1390 "./marpa.w"

return symbol_is_start(SYM_by_ID(symid));
}
/*:188*//*194:*/
#line 1420 "./marpa.w"

static inline
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 1428 "./marpa.w"

/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 1429 "./marpa.w"

symbol= SYM_by_ID(symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}
/*:194*//*197:*/
#line 1443 "./marpa.w"

static inline
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 1451 "./marpa.w"

/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 1452 "./marpa.w"

symbol= SYM_by_ID(symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
g->t_error= "no alias";
return-1;
}
return ID_of_SYM(alias);
}
/*:197*//*202:*/
#line 1475 "./marpa.w"
static inline
SYM symbol_alias_create(GRAMMAR g,SYM symbol)
{
SYM alias= symbol_new(g);
symbol->t_is_proper_alias= TRUE;
SYM_is_Nulling(symbol)= FALSE;
symbol->t_is_nullable= FALSE;
symbol->t_alias= alias;
alias->t_is_nulling_alias= TRUE;
SYM_is_Nulling(alias)= TRUE;
alias->t_is_nullable= TRUE;
alias->t_is_productive= TRUE;
alias->t_is_accessible= symbol->t_is_accessible;
alias->t_alias= symbol;
return alias;
}

/*:202*//*207:*/
#line 1517 "./marpa.w"

Marpa_Rule_ID marpa_symbol_virtual_lhs_rule(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
RULE virtual_lhs_rule;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 1522 "./marpa.w"

/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 1523 "./marpa.w"

symbol= SYM_by_ID(symid);
virtual_lhs_rule= symbol->t_virtual_lhs_rule;
return virtual_lhs_rule==NULL?-1:ID_of_RULE(virtual_lhs_rule);
}

/*:207*//*214:*/
#line 1558 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length)
{
/*1337:*/
#line 13065 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1337*/
#line 1563 "./marpa.w"

RULE rule;
const gint rule_sizeof= G_STRUCT_OFFSET(struct s_rule,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
/*240:*/
#line 1953 "./marpa.w"

{
SYMID symid= lhs;
/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 1956 "./marpa.w"

}
{gint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1341:*/
#line 13083 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1341*/
#line 1961 "./marpa.w"

}
}

/*:240*/
#line 1567 "./marpa.w"

rule= obstack_alloc(&g->t_obs,rule_sizeof);
/*241:*/
#line 1965 "./marpa.w"

Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
{gint i;for(i= 0;i<length;i++){
rule->t_symbols[i+1]= rhs[i];}}
/*:241*/
#line 1569 "./marpa.w"

/*256:*/
#line 2021 "./marpa.w"
rule->t_id= g->t_rules->len;

/*:256*//*259:*/
#line 2033 "./marpa.w"

rule->t_is_discard= FALSE;
/*:259*//*273:*/
#line 2117 "./marpa.w"

rule->t_is_loop= FALSE;
/*:273*//*278:*/
#line 2138 "./marpa.w"

rule->t_is_virtual_loop= FALSE;
/*:278*//*285:*/
#line 2174 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:285*//*289:*/
#line 2190 "./marpa.w"

rule->t_is_start= FALSE;
/*:289*//*293:*/
#line 2221 "./marpa.w"

RULE_is_Virtual_LHS(rule)= FALSE;
/*:293*//*297:*/
#line 2236 "./marpa.w"

RULE_is_Virtual_RHS(rule)= FALSE;
/*:297*//*301:*/
#line 2253 "./marpa.w"
rule->t_virtual_start= -1;
/*:301*//*305:*/
#line 2269 "./marpa.w"
rule->t_virtual_end= -1;
/*:305*//*310:*/
#line 2285 "./marpa.w"
rule->t_original= -1;
/*:310*//*315:*/
#line 2304 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:315*//*319:*/
#line 2317 "./marpa.w"

rule->t_is_semantic_equivalent= FALSE;
/*:319*//*326:*/
#line 2360 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:326*/
#line 1570 "./marpa.w"

rule_add(g,rule->t_id,rule);
/*233:*/
#line 1831 "./marpa.w"

symbol_lhs_add(SYM_by_ID(rule->t_symbols[0]),rule->t_id);
if(Length_of_RULE(rule)> 0){
gint rh_list_ix;
const guint alloc_size= Length_of_RULE(rule)*sizeof(SYMID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*237:*/
#line 1898 "./marpa.w"

{

gint rhs_ix= Length_of_RULE(rule)-1;
rh_symbol_list[0]= RHS_ID_of_RULE(rule,(unsigned)rhs_ix);
rh_symbol_list_length= 1;
rhs_ix--;
for(;rhs_ix>=0;rhs_ix--){
gint higher_ix;
Marpa_Symbol_ID new_symid= RHS_ID_of_RULE(rule,(unsigned)rhs_ix);
gint next_highest_ix= rh_symbol_list_length-1;
while(next_highest_ix>=0){
Marpa_Symbol_ID current_symid= rh_symbol_list[next_highest_ix];
if(current_symid==new_symid)goto ignore_this_symbol;
if(current_symid<new_symid)break;
next_highest_ix--;
}

for(higher_ix= rh_symbol_list_length-1;
higher_ix> next_highest_ix;
higher_ix--){
rh_symbol_list[higher_ix+1]= rh_symbol_list[higher_ix];
}

rh_symbol_list[next_highest_ix+1]= new_symid;
rh_symbol_list_length++;
ignore_this_symbol:;
}
}

/*:237*/
#line 1839 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(rh_symbol_list[rh_list_ix]),
rule->t_id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:233*/
#line 1572 "./marpa.w"

return rule;
}

/*:214*//*216:*/
#line 1579 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
Marpa_Rule_ID rule_id;
RULE rule;
if(length> MAX_RHS_LENGTH){
g->t_error= (Marpa_Error_ID)"rhs too long";
return-1;
}
if(is_rule_duplicate(g,lhs,rhs,length)==TRUE){
g->t_error= (Marpa_Error_ID)"duplicate rule";
return-1;
}
rule= rule_start(g,lhs,rhs,length);
if(!rule){return-1;}
rule_id= rule->t_id;
return rule_id;
}

/*:216*//*218:*/
#line 1603 "./marpa.w"

gint marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags)
{
RULE original_rule;
RULEID original_rule_id;
SYM internal_lhs;
SYMID internal_lhs_id,*temp_rhs;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 1612 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 1613 "./marpa.w"

/*1339:*/
#line 13073 "./marpa.w"

if(G_is_Precomputed(g)){
g->t_error= "grammar precomputed";
return failure_indicator;
}
/*:1339*/
#line 1614 "./marpa.w"

if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE)
{
g->t_error= (Marpa_Error_ID)"duplicate rule";
return failure_indicator;
}
G_EVENTS_CLEAR(g);

/*219:*/
#line 1640 "./marpa.w"

{
original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule)
{
g->t_error= "internal_error";
return failure_indicator;
}
RULE_is_Used(original_rule)= 0;
original_rule_id= original_rule->t_id;
original_rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION)
&&separator_id>=0;
int_event_new(g,MARPA_G_EV_NEW_RULE,original_rule_id);
}

/*:219*/
#line 1622 "./marpa.w"

/*220:*/
#line 1655 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->t_error= "bad separator";
return failure_indicator;
}

/*:220*/
#line 1623 "./marpa.w"

/*221:*/
#line 1661 "./marpa.w"

SYM_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(separator_id)->t_is_counted= 1;}
/*:221*/
#line 1624 "./marpa.w"

if(min==0){/*222:*/
#line 1664 "./marpa.w"

{
RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1346:*/
#line 13108 "./marpa.w"
{
g->t_error= "internal error";
return failure_indicator;
}

/*:1346*/
#line 1667 "./marpa.w"
}
rule->t_is_semantic_equivalent= TRUE;
rule->t_original= original_rule_id;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}
/*:222*/
#line 1625 "./marpa.w"
}
min= 1;
/*223:*/
#line 1672 "./marpa.w"

{
internal_lhs= symbol_new(g);
internal_lhs_id= ID_of_SYM(internal_lhs);
int_event_new(g,MARPA_G_EV_NEW_SYMBOL,internal_lhs_id);
}

/*:223*/
#line 1627 "./marpa.w"

/*224:*/
#line 1690 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:224*/
#line 1628 "./marpa.w"

/*226:*/
#line 1693 "./marpa.w"

{
RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1346:*/
#line 13108 "./marpa.w"
{
g->t_error= "internal error";
return failure_indicator;
}

/*:1346*/
#line 1698 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;

RULE_is_Virtual_RHS(rule)= TRUE;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}

/*:226*/
#line 1629 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*227:*/
#line 1707 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1346:*/
#line 13108 "./marpa.w"
{
g->t_error= "internal error";
return failure_indicator;
}

/*:1346*/
#line 1712 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;
RULE_is_Virtual_RHS(rule)= TRUE;
Real_SYM_Count_of_RULE(rule)= 1;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}
/*:227*/
#line 1631 "./marpa.w"

}
/*228:*/
#line 1722 "./marpa.w"

{RULE rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1346:*/
#line 13108 "./marpa.w"
{
g->t_error= "internal error";
return failure_indicator;
}

/*:1346*/
#line 1732 "./marpa.w"
}
RULE_is_Virtual_LHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}
/*:228*/
#line 1633 "./marpa.w"

/*229:*/
#line 1737 "./marpa.w"

{RULE rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1346:*/
#line 13108 "./marpa.w"
{
g->t_error= "internal error";
return failure_indicator;
}

/*:1346*/
#line 1744 "./marpa.w"
}
RULE_is_Virtual_LHS(rule)= 1;
RULE_is_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix-1;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}

/*:229*/
#line 1634 "./marpa.w"

/*225:*/
#line 1692 "./marpa.w"
g_free(temp_rhs);
/*:225*/
#line 1635 "./marpa.w"

return G_EVENT_COUNT(g);
}

/*:218*//*232:*/
#line 1797 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length)
{
gint ix;
SYM lhs= SYM_by_ID(lhs_id);
GArray*same_lhs_array= lhs->t_lhs;
gint same_lhs_count= same_lhs_array->len;
for(ix= 0;ix<same_lhs_count;ix++){
RULEID same_lhs_rule_id= ((RULEID*)(same_lhs_array->data))[ix];
gint rhs_position;
RULE rule= RULE_by_ID(g,same_lhs_rule_id);
const gint rule_length= Length_of_RULE(rule);
if(rule_length!=length){goto RULE_IS_NOT_DUPLICATE;}
for(rhs_position= 0;rhs_position<rule_length;rhs_position++){
if(RHS_ID_of_RULE(rule,rhs_position)!=rhs_ids[rhs_position]){
goto RULE_IS_NOT_DUPLICATE;
}
}
return TRUE;
RULE_IS_NOT_DUPLICATE:;
}
return FALSE;
}

/*:232*//*242:*/
#line 1970 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule){
return rule->t_symbols[0];}
/*:242*//*244:*/
#line 1975 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 1977 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 1978 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));}
/*:244*//*246:*/
#line 1982 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule){
return rule->t_symbols+1;}
/*:246*//*249:*/
#line 1989 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix){
RULE rule;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 1992 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 1993 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:249*//*250:*/
#line 1998 "./marpa.w"

static inline gsize rule_length_get(RULE rule){
return Length_of_RULE(rule);}
/*:250*//*252:*/
#line 2003 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2005 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2006 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}
/*:252*//*260:*/
#line 2035 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_discard;}
/*:260*//*264:*/
#line 2068 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(lhs_id)->t_is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2075 "./marpa.w"

RULE rule;
/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2077 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:264*//*268:*/
#line 2088 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++){
Marpa_Symbol_ID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_by_ID(rhs_id)->t_is_productive)return FALSE;
}
return TRUE;}
gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2099 "./marpa.w"

RULE rule;
/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2101 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}
/*:268*//*274:*/
#line 2121 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2124 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2125 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}
/*:274*//*279:*/
#line 2142 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2145 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2146 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;}
/*:279*//*282:*/
#line 2154 "./marpa.w"

static inline gint
rule_is_nulling(GRAMMAR g,RULE rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++)
{
SYMID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_is_Nulling(SYM_by_ID(rhs_id)))
return FALSE;
}
return TRUE;
}
/*:282*//*286:*/
#line 2178 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2181 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2182 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}
/*:286*//*290:*/
#line 2194 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2197 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2198 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_start;}
/*:290*//*294:*/
#line 2224 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2227 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2228 "./marpa.w"

return RULE_is_Virtual_LHS(RULE_by_ID(g,rule_id));}
/*:294*//*298:*/
#line 2239 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2242 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2243 "./marpa.w"

return RULE_is_Virtual_RHS(RULE_by_ID(g,rule_id));}
/*:298*//*302:*/
#line 2254 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2257 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2258 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}
/*:302*//*306:*/
#line 2270 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2273 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2274 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}
/*:306*//*311:*/
#line 2286 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2289 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2290 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_original;
}
/*:311*//*317:*/
#line 2307 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2310 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2311 "./marpa.w"

return Real_SYM_Count_of_RULE(RULE_by_ID(g,rule_id));
}

/*:317*//*322:*/
#line 2330 "./marpa.w"

Marpa_Rule_ID
marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2335 "./marpa.w"

/*1342:*/
#line 13088 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1342*/
#line 2336 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(RULE_is_Virtual_LHS(rule))return-1;
if(rule->t_is_semantic_equivalent)return rule->t_original;
return rule_id;
}

/*:322*//*329:*/
#line 2376 "./marpa.w"

static inline gint
symbol_instance_of_ahfa_item_get(AIM aim)
{
gint position= Position_of_AIM(aim);
const gint null_count= Null_Count_of_AIM(aim);
if(position<0||position-null_count> 0){

const RULE rule= RULE_of_AIM(aim);
position= Position_of_AIM(aim-1);
return SYMI_of_RULE(rule)+position;
}
return-1;
}

/*:329*//*330:*/
#line 2402 "./marpa.w"

gint marpa_precompute(struct marpa_g*g)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 2405 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 2406 "./marpa.w"

G_EVENTS_CLEAR(g);
if(!census(g))return failure_indicator;
if(!CHAF_rewrite(g))return failure_indicator;
if(!g_augment(g))return failure_indicator;
if(!G_is_Trivial(g)){
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*585:*/
#line 5287 "./marpa.w"
{
gint symbol_count= SYM_Count_of_G(g);
gint symid;
Bit_Vector bv_is_terminal= bv_create((guint)symbol_count);
g->t_bv_symid_is_terminal= bv_is_terminal;
for(symid= 0;symid<symbol_count;symid++){
if(!SYMID_is_Terminal(symid))continue;
bv_bit_set(bv_is_terminal,(guint)symid);
}
}

/*:585*/
#line 2415 "./marpa.w"

}
return G_EVENT_COUNT(g);
}
/*:330*//*333:*/
#line 2454 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*1337:*/
#line 13065 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1337*/
#line 2457 "./marpa.w"

/*335:*/
#line 2487 "./marpa.w"

guint pre_rewrite_rule_count= g->t_rules->len;
guint pre_rewrite_symbol_count= g->t_symbols->len;

/*:335*//*340:*/
#line 2519 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_start_symid;
SYM original_start_symbol;

/*:340*//*344:*/
#line 2558 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:344*//*350:*/
#line 2609 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:350*//*352:*/
#line 2633 "./marpa.w"

Bit_Vector nullable_v;
/*:352*//*356:*/
#line 2658 "./marpa.w"

Bit_Vector productive_v;
/*:356*//*359:*/
#line 2699 "./marpa.w"
Bit_Matrix reach_matrix;
/*:359*//*362:*/
#line 2717 "./marpa.w"

Bit_Vector accessible_v;

/*:362*/
#line 2458 "./marpa.w"

/*336:*/
#line 2491 "./marpa.w"

if(g->t_rules->len<=0){g->t_error= "no rules";return NULL;}
/*:336*/
#line 2459 "./marpa.w"

/*337:*/
#line 2498 "./marpa.w"

if(G_is_Precomputed(g)){g->t_error= "precomputed";return NULL;}
/*:337*/
#line 2460 "./marpa.w"

/*339:*/
#line 2504 "./marpa.w"

if(original_start_symid<0){
g->t_error= "no start symbol";
return failure_indicator;
}
if(!symbol_is_valid(g,original_start_symid)){
g->t_error= "invalid start symbol";
return failure_indicator;
}
original_start_symbol= SYM_by_ID(original_start_symid);
if(original_start_symbol->t_lhs->len<=0){
g->t_error= "start symbol not on LHS";
return failure_indicator;
}

/*:339*/
#line 2461 "./marpa.w"

/*341:*/
#line 2523 "./marpa.w"

{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;
rule_id<(Marpa_Rule_ID)pre_rewrite_rule_count;
rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
bv_bit_set(lhs_v,(guint)lhs_id);
if(Length_of_RULE(rule)<=0){
bv_bit_set(empty_lhs_v,(guint)lhs_id);
have_empty_rule= 1;
}
}
}
/*:341*/
#line 2462 "./marpa.w"

/*342:*/
#line 2542 "./marpa.w"

{Marpa_Symbol_ID symid;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symid= 0;
symid<(Marpa_Symbol_ID)pre_rewrite_symbol_count;
symid++){
SYM symbol= SYM_by_ID(symid);
if(SYM_is_Terminal(symbol)){
bv_bit_set(terminal_v,(guint)symid);
have_marked_terminals= 1;
}
}}
/*:342*/
#line 2463 "./marpa.w"

if(have_marked_terminals){
/*346:*/
#line 2576 "./marpa.w"

if(!g->t_is_lhs_terminal_ok){
gint no_lhs_terminals;
Bit_Vector bad_lhs_v= bv_clone(terminal_v);
bv_and(bad_lhs_v,bad_lhs_v,lhs_v);
no_lhs_terminals= bv_is_empty(bad_lhs_v);
bv_free(bad_lhs_v);
if(!no_lhs_terminals){
g->t_error= "lhs is terminal";
return NULL;
}
}

/*:346*/
#line 2465 "./marpa.w"

}else{
/*345:*/
#line 2562 "./marpa.w"

if(have_empty_rule&&g->t_is_lhs_terminal_ok){
g->t_error= "empty rule and unmarked terminals";
return NULL;
}
/*:345*/
#line 2467 "./marpa.w"
;
if(g->t_is_lhs_terminal_ok){
/*347:*/
#line 2589 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->t_symbols->len;symid++)
{SYMID_is_Terminal(symid)= 1;}}
/*:347*/
#line 2469 "./marpa.w"

}else{
/*348:*/
#line 2594 "./marpa.w"

{guint start= 0;
guint min,max;
bv_not(terminal_v,lhs_v);
while(bv_scan(terminal_v,start,&min,&max)){
Marpa_Symbol_ID symid;
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
SYMID_is_Terminal(symid)= 1;
}
start= max+2;
}
}
/*:348*/
#line 2471 "./marpa.w"

}
}
/*351:*/
#line 2614 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
SYM symbol= SYM_by_ID(symid);
if(symbol->t_is_counted){
counted_nullables++;
}
symbol->t_is_nullable= 1;
}}
if(counted_nullables){
g->t_error= "counted nullable";
return NULL;
}
}
/*:351*/
#line 2474 "./marpa.w"

/*354:*/
#line 2638 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(symid);
symbol->t_is_productive= 1;
}}
}
/*:354*/
#line 2475 "./marpa.w"

/*355:*/
#line 2652 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->t_start_symid))
{
g->t_error= "unproductive start symbol";
return NULL;
}
/*:355*/
#line 2476 "./marpa.w"

/*358:*/
#line 2681 "./marpa.w"

reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{guint symid,no_of_symbols= SYM_Count_of_G(g);
for(symid= 0;symid<no_of_symbols;symid++){
matrix_bit_set(reach_matrix,symid,symid);
}}
{Marpa_Rule_ID rule_id;
guint no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
guint rhs_ix,rule_length= Length_of_RULE(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,
(guint)lhs_id,(guint)RHS_ID_of_RULE(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:358*/
#line 2477 "./marpa.w"

/*361:*/
#line 2703 "./marpa.w"

accessible_v= matrix_row(reach_matrix,(guint)original_start_symid);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(symid);
symbol->t_is_accessible= 1;
}}
}
/*:361*/
#line 2478 "./marpa.w"

/*363:*/
#line 2722 "./marpa.w"

{
Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
guint min,max,start;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID productive_id;
for(productive_id= (Marpa_Symbol_ID)min;
productive_id<=(Marpa_Symbol_ID)max;productive_id++)
{
bv_and(reaches_terminal_v,terminal_v,
matrix_row(reach_matrix,(guint)productive_id));
if(bv_is_empty(reaches_terminal_v))
SYM_is_Nulling(SYM_by_ID(productive_id))= 1;
}
}
bv_free(reaches_terminal_v);
}

/*:363*/
#line 2479 "./marpa.w"

/*343:*/
#line 2554 "./marpa.w"

bv_free(terminal_v);
/*:343*//*349:*/
#line 2606 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:349*//*353:*/
#line 2635 "./marpa.w"

bv_free(nullable_v);

/*:353*//*357:*/
#line 2660 "./marpa.w"

bv_free(productive_v);

/*:357*/
#line 2480 "./marpa.w"

/*360:*/
#line 2700 "./marpa.w"

matrix_free(reach_matrix);

/*:360*/
#line 2481 "./marpa.w"

g->t_is_precomputed= TRUE;
return g;
}
/*:333*//*370:*/
#line 2798 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*372:*/
#line 2821 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:372*//*376:*/
#line 2871 "./marpa.w"

gint factor_count;
gint*factor_positions;
/*:376*//*381:*/
#line 2921 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:381*/
#line 2801 "./marpa.w"

/*377:*/
#line 2874 "./marpa.w"

factor_positions= g_new(gint,g->t_max_rule_length);
/*:377*//*382:*/
#line 2924 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:382*/
#line 2802 "./marpa.w"

/*374:*/
#line 2833 "./marpa.w"

{gint no_of_symbols= SYM_Count_of_G(g);
Marpa_Symbol_ID symid;
for(symid= 0;symid<no_of_symbols;symid++){
SYM symbol= SYM_by_ID(symid);
SYM alias;
if(!symbol->t_is_nullable)continue;
if(SYM_is_Nulling(symbol))continue;
if(!symbol->t_is_accessible)continue;
if(!symbol->t_is_productive)continue;
if(symbol_null_alias(symbol))continue;
alias= symbol_alias_create(g,symbol);
}}

/*:374*/
#line 2803 "./marpa.w"

no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const gint rule_length= Length_of_RULE(rule);
gint nullable_suffix_ix= 0;
/*373:*/
#line 2825 "./marpa.w"

if(!RULE_is_Used(rule)){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}

/*:373*/
#line 2809 "./marpa.w"

/*375:*/
#line 2855 "./marpa.w"

{gint rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(symid);
if(SYM_is_Nulling(symbol))continue;
if(symbol_null_alias(symbol)){

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}}
/*:375*/
#line 2810 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*379:*/
#line 2880 "./marpa.w"

RULE_is_Used(rule)= 0;
{


gint unprocessed_factor_count;

gint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);


gint piece_end,piece_start= 0;
for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*385:*/
#line 2934 "./marpa.w"

SYMID chaf_virtual_symid;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*380:*/
#line 2904 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:380*/
#line 2942 "./marpa.w"

/*386:*/
#line 2961 "./marpa.w"

{
gint remaining_rhs_length,piece_rhs_length;
/*387:*/
#line 2973 "./marpa.w"

{
gint real_symbol_count= piece_end-piece_start+1;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;
piece_rhs_length++)
{
remaining_rhs[piece_rhs_length]= 
piece_rhs[piece_rhs_length]= 
RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
}
{RULE chaf_rule;
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 2988 "./marpa.w"

}

/*:387*/
#line 2964 "./marpa.w"
;
/*388:*/
#line 2991 "./marpa.w"

{
gint chaf_rule_length= Length_of_RULE(rule)-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;remaining_rhs_length++)
{
Marpa_Symbol_ID original_id= 
RHS_ID_of_RULE(rule,piece_start+remaining_rhs_length);
SYM alias= symbol_null_alias(SYM_by_ID(original_id));
remaining_rhs[remaining_rhs_length]= 
alias?ID_of_SYM(alias):original_id;
}
}
{
RULE chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= 
rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3009 "./marpa.w"

}

/*:388*/
#line 2965 "./marpa.w"
;
/*389:*/
#line 3014 "./marpa.w"
{
Marpa_Symbol_ID proper_id= RHS_ID_of_RULE(rule,first_factor_position);
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
ID_of_SYM(alias);
}
{RULE chaf_rule;
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3024 "./marpa.w"

}

/*:389*/
#line 2966 "./marpa.w"
;
/*390:*/
#line 3033 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3038 "./marpa.w"

}

/*:390*/
#line 2967 "./marpa.w"
;
}

/*:386*/
#line 2943 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*380:*/
#line 2904 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:380*/
#line 2948 "./marpa.w"

/*392:*/
#line 3043 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
gint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:392*//*393:*/
#line 3052 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3058 "./marpa.w"


/*:393*//*394:*/
#line 3061 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3066 "./marpa.w"


/*:394*//*395:*/
#line 3069 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3075 "./marpa.w"


/*:395*//*396:*/
#line 3078 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3081 "./marpa.w"


/*:396*//*397:*/
#line 3084 "./marpa.w"
}

/*:397*/
#line 2949 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:385*/
#line 2895 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*398:*/
#line 3088 "./marpa.w"
{
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
gint second_factor_piece_position= second_factor_position-piece_start;
gint real_symbol_count;
gint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:398*//*399:*/
#line 3102 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3107 "./marpa.w"


/*:399*//*400:*/
#line 3110 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3115 "./marpa.w"


/*:400*//*401:*/
#line 3118 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3124 "./marpa.w"


/*:401*//*402:*/
#line 3128 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3132 "./marpa.w"

}

/*:402*//*403:*/
#line 3136 "./marpa.w"
}

/*:403*/
#line 2898 "./marpa.w"

}else{
/*404:*/
#line 3139 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
gint real_symbol_count;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:404*//*405:*/
#line 3150 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3155 "./marpa.w"


/*:405*//*406:*/
#line 3159 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*408:*/
#line 3175 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:408*/
#line 3165 "./marpa.w"

}

/*:406*//*407:*/
#line 3169 "./marpa.w"
}

/*:407*/
#line 2900 "./marpa.w"

}
}

/*:379*/
#line 2813 "./marpa.w"

NEXT_RULE:;
}
/*378:*/
#line 2876 "./marpa.w"

g_free(factor_positions);

/*:378*//*383:*/
#line 2927 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:383*/
#line 2816 "./marpa.w"

return g;
}
/*:370*//*409:*/
#line 3194 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
return ID_of_SYM(alias);
}
/*:409*//*412:*/
#line 3209 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g->t_start_symid);
/*413:*/
#line 3223 "./marpa.w"

if(SYM_is_Nulling(old_start)){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:413*/
#line 3217 "./marpa.w"

if(proper_old_start){/*414:*/
#line 3233 "./marpa.w"
{
RULE new_start_rule;
proper_old_start->t_is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= ID_of_SYM(proper_new_start);
g->t_start_symid= proper_new_start_id;
proper_new_start->t_is_accessible= TRUE;
proper_new_start->t_is_productive= TRUE;
proper_new_start->t_is_start= TRUE;
new_start_rule= rule_start(g,proper_new_start_id,&ID_of_SYM(old_start),1);
new_start_rule->t_is_start= 1;
RULE_is_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= 1;
g->t_proper_start_rule= new_start_rule;
}

/*:414*/
#line 3218 "./marpa.w"
}
if(nulling_old_start){/*415:*/
#line 3254 "./marpa.w"
{
Marpa_Symbol_ID nulling_new_start_id;
RULE new_start_rule;
SYM nulling_new_start;
if(proper_new_start)
{
nulling_new_start= symbol_alias_create(g,proper_new_start);
nulling_new_start_id= ID_of_SYM(nulling_new_start);
}
else
{
nulling_new_start= symbol_new(g);
nulling_new_start_id= ID_of_SYM(nulling_new_start);
g->t_start_symid= nulling_new_start_id;
SYM_is_Nulling(nulling_new_start)= TRUE;
nulling_new_start->t_is_nullable= TRUE;
nulling_new_start->t_is_productive= TRUE;
nulling_new_start->t_is_accessible= TRUE;
}
nulling_new_start->t_is_start= TRUE;
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
new_start_rule->t_is_start= 1;
RULE_is_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= FALSE;
g->t_null_start_rule= new_start_rule;
}

/*:415*/
#line 3219 "./marpa.w"
}
return g;
}

/*:412*//*420:*/
#line 3331 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{
gint no_of_rules= RULE_Count_of_G(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_create((guint)no_of_rules,(guint)no_of_rules);
/*422:*/
#line 3358 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID proper_id;
gint rhs_ix,rule_length;
if(!RULE_is_Used(rule))continue;
rule_length= Length_of_RULE(rule);
proper_id= -1;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(symid);
if(symbol->t_is_nullable)continue;
if(proper_id>=0)goto NEXT_RULE;

proper_id= symid;
}

if(proper_id<0)continue;

{SYM rhs_symbol= SYM_by_ID(proper_id);
GArray*lhs_rules= rhs_symbol->t_lhs;
gint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,(guint)rule_id,
(guint)g_array_index(lhs_rules,Marpa_Rule_ID,ix));
}}
NEXT_RULE:;
}}

/*:422*/
#line 3339 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*423:*/
#line 3397 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule;
if(!matrix_bit_test(unit_transition_matrix,(guint)rule_id,(guint)rule_id))
continue;
loop_rule_count++;
rule= RULE_by_ID(g,rule_id);
rule->t_is_loop= TRUE;
rule->t_is_virtual_loop= rule->t_virtual_start<0||!RULE_is_Virtual_RHS(rule);
}}

/*:423*/
#line 3341 "./marpa.w"

if(loop_rule_count)
{
g->t_has_loop= TRUE;
int_event_new(g,MARPA_G_EV_LOOP_RULES,loop_rule_count);
}
matrix_free(unit_transition_matrix);
}
/*:420*//*438:*/
#line 3563 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id){
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}
/*:438*//*444:*/
#line 3604 "./marpa.w"

gint marpa_AHFA_item_count(struct marpa_g*g){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 3606 "./marpa.w"

/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 3607 "./marpa.w"

return AIM_Count_of_G(g);
}
/*:444*//*446:*/
#line 3613 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 3616 "./marpa.w"

/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 3617 "./marpa.w"

/*1343:*/
#line 13093 "./marpa.w"

if(!item_is_valid(g,item_id)){
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1343*/
#line 3618 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(item_id))->t_id;
}
/*:446*//*449:*/
#line 3627 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 3630 "./marpa.w"

/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 3631 "./marpa.w"

/*1343:*/
#line 13093 "./marpa.w"

if(!item_is_valid(g,item_id)){
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1343*/
#line 3632 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:449*//*451:*/
#line 3639 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 3642 "./marpa.w"

/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 3643 "./marpa.w"

/*1343:*/
#line 13093 "./marpa.w"

if(!item_is_valid(g,item_id)){
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1343*/
#line 3644 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:451*//*453:*/
#line 3650 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 3653 "./marpa.w"

/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 3654 "./marpa.w"

/*1343:*/
#line 13093 "./marpa.w"

if(!item_is_valid(g,item_id)){
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1343*/
#line 3655 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:453*//*455:*/
#line 3666 "./marpa.w"

static inline
void create_AHFA_items(GRAMMAR g){
RULEID rule_id;
guint no_of_items;
guint no_of_rules= RULE_Count_of_G(g);
AIM base_item= g_new(struct s_AHFA_item,Size_of_G(g));
AIM current_item= base_item;
guint symbol_instance_of_next_rule= 0;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
if(RULE_is_Used(rule)){
/*457:*/
#line 3692 "./marpa.w"

{
gint leading_nulls= 0;
gint rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_RULE(rule);rhs_ix++)
{
SYMID rh_symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(rh_symid);
if(!symbol->t_is_nullable)
{
Last_Proper_SYMI_of_RULE(rule)= symbol_instance_of_next_rule+rhs_ix;
/*458:*/
#line 3716 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:458*/
#line 3703 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*459:*/
#line 3725 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:459*/
#line 3712 "./marpa.w"

current_item++;
}

/*:457*/
#line 3678 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
no_of_items= LV_AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*460:*/
#line 3739 "./marpa.w"

{
AIM*items_by_rule= g_new(AIM,no_of_rules);
AIM items= g->t_AHFA_items;

Marpa_Rule_ID highest_found_rule_id= -1;
Marpa_AHFA_Item_ID item_id;


for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++)
{
items_by_rule[rule_id]= NULL;
}
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
AIM item= items+item_id;
Marpa_Rule_ID rule_id_for_item= RULE_of_AIM(item)->t_id;
if(rule_id_for_item<=highest_found_rule_id)
continue;
items_by_rule[rule_id_for_item]= item;
highest_found_rule_id= rule_id_for_item;
}
g->t_AHFA_items_by_rule= items_by_rule;
}

/*:460*/
#line 3686 "./marpa.w"

/*467:*/
#line 3815 "./marpa.w"

{
Marpa_AHFA_Item_ID item_id;
AIM*sort_array= g_new(struct s_AHFA_item*,no_of_items);
AIM items= g->t_AHFA_items;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
sort_array[item_id]= items+item_id;
}
g_qsort_with_data(sort_array,
(gint)no_of_items,sizeof(AIM),cmp_by_postdot_and_aimid,
(gpointer)NULL);
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
Sort_Key_of_AIM(sort_array[item_id])= item_id;
}
g_free(sort_array);
}

/*:467*/
#line 3687 "./marpa.w"

}
/*:455*//*463:*/
#line 3774 "./marpa.w"

static gint cmp_by_aimid(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED){
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:463*//*466:*/
#line 3792 "./marpa.w"

static gint cmp_by_postdot_and_aimid(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED){
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
gint a_postdot= Postdot_SYMID_of_AIM(a);
gint b_postdot= Postdot_SYMID_of_AIM(b);
if(a_postdot==b_postdot)
return Sort_Key_of_AIM(a)-Sort_Key_of_AIM(b);
if(a_postdot<0)return 1;
if(b_postdot<0)return-1;
return a_postdot-b_postdot;
}

/*:466*//*485:*/
#line 3980 "./marpa.w"

static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM sought_aim)
{
AIM*const aims= AIMs_of_AHFA(ahfa);
gint aim_count= AIM_Count_of_AHFA(ahfa);
gint hi= aim_count-1;
gint lo= 0;
while(hi>=lo){
gint trial_aex= lo+(hi-lo)/2;
AIM trial_aim= aims[trial_aex];
if(trial_aim==sought_aim)return trial_aex;
if(trial_aim<sought_aim){
lo= trial_aex+1;
}else{
hi= trial_aex-1;
}
}
return-1;
}

/*:485*//*495:*/
#line 4051 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id){
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}
/*:495*//*499:*/
#line 4070 "./marpa.w"

gint marpa_AHFA_state_count(struct marpa_g*g){
return AHFA_Count_of_G(g);
}
/*:499*//*501:*/
#line 4077 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 4080 "./marpa.w"

AHFA state;
/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 4082 "./marpa.w"

/*1344:*/
#line 13098 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1344*/
#line 4083 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}
/*:501*//*504:*/
#line 4096 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
guint item_ix){
AHFA state;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 4101 "./marpa.w"

/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 4102 "./marpa.w"

/*1344:*/
#line 13098 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1344*/
#line 4103 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
if(item_ix>=state->t_item_count){
g->t_error= "invalid state item ix";
return failure_indicator;
}
return AIMID_of_AHFA_by_AEX(g,state,item_ix);
}

/*:504*//*505:*/
#line 4112 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 4116 "./marpa.w"

/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 4117 "./marpa.w"

/*1344:*/
#line 13098 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1344*/
#line 4118 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}
/*:505*//*510:*/
#line 4157 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
const gint no_completed_start_rule= -1;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 4161 "./marpa.w"

AHFA state;
/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 4163 "./marpa.w"

/*1344:*/
#line 13098 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1344*/
#line 4164 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
if(AHFA_has_Completed_Start_Rule(state)){
const gint ahfa_item_count= state->t_item_count;
const AIM*ahfa_items= state->t_items;
gint ahfa_ix;
for(ahfa_ix= 0;ahfa_ix<ahfa_item_count;ahfa_ix++)
{
const AIM ahfa_item= ahfa_items[ahfa_ix];
if(AIM_is_Completion(ahfa_item))
{
const RULE rule= RULE_of_AIM(ahfa_item);
if(RULE_is_Start(rule))
return ID_of_RULE(rule);
}
}
/*1346:*/
#line 13108 "./marpa.w"
{
g->t_error= "internal error";
return failure_indicator;
}

/*:1346*/
#line 4180 "./marpa.w"

}
return no_completed_start_rule;
}

/*:510*//*514:*/
#line 4199 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 4202 "./marpa.w"

AHFA state;
/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 4204 "./marpa.w"

/*1344:*/
#line 13098 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1344*/
#line 4205 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:514*//*517:*/
#line 4228 "./marpa.w"

static gint AHFA_state_cmp(
gconstpointer ap,
gconstpointer bp)
{
guint i;
AIM*items_a;
AIM*items_b;
const AHFA state_a= (AHFA)ap;
const AHFA state_b= (AHFA)bp;
guint length= state_a->t_item_count;
gint subkey= length-state_b->t_item_count;
if(subkey)return subkey;
if(length!=state_b->t_item_count)return FALSE;
items_a= state_a->t_items;
items_b= state_b->t_items;
for(i= 0;i<length;i++){
subkey= Sort_Key_of_AIM(items_a[i])-Sort_Key_of_AIM(items_b[i]);
if(subkey)return subkey;
}
return 0;
}

/*:517*//*520:*/
#line 4254 "./marpa.w"

PRIVATE_NOT_INLINE
void create_AHFA_states(struct marpa_g*g){
/*521:*/
#line 4273 "./marpa.w"

AHFA p_working_state;
const guint initial_no_of_states= 2*Size_of_G(g);
AIM AHFA_item_0_p= g->t_AHFA_items;
const guint symbol_count_of_g= SYM_Count_of_G(g);
const guint rule_count_of_g= RULE_Count_of_G(g);
Bit_Matrix prediction_matrix;
RULE*rule_by_sort_key= g_new(RULE,rule_count_of_g);
GTree*duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
struct obstack ahfa_work_obs;
gint ahfa_count_of_g;
AHFA ahfas_of_g;

/*:521*/
#line 4257 "./marpa.w"

/*522:*/
#line 4288 "./marpa.w"

/*523:*/
#line 4292 "./marpa.w"

{
guint item_id;
guint no_of_items_in_grammar= AIM_Count_of_G(g);
obstack_init(&ahfa_work_obs);
duplicates= g_tree_new(AHFA_state_cmp);
singleton_duplicates= g_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++)
{
singleton_duplicates[item_id]= NULL;
}
}

/*:523*/
#line 4289 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:522*/
#line 4258 "./marpa.w"

/*545:*/
#line 4801 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_create(symbol_count_of_g,symbol_count_of_g);
/*546:*/
#line 4810 "./marpa.w"

{
RULEID rule_id;
SYMID symid;
AIM*items_by_rule= g->t_AHFA_items_by_rule;
for(symid= 0;symid<(SYMID)symbol_count_of_g;symid++)
{

SYM symbol= SYM_by_ID(symid);
if(!SYMBOL_LHS_RULE_COUNT(symbol))
continue;
matrix_bit_set(symbol_by_symbol_matrix,(guint)symid,(guint)symid);
}
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
SYMID from,to;

AIM item= items_by_rule[rule_id];

if(!item)
continue;
from= LHS_ID_of_AIM(item);
to= Postdot_SYMID_of_AIM(item);

if(to<0)
continue;

matrix_bit_set(symbol_by_symbol_matrix,(guint)from,(guint)to);
}
}

/*:546*/
#line 4804 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*547:*/
#line 4847 "./marpa.w"
{
AIM*items_by_rule= g->t_AHFA_items_by_rule;
SYMID from_symid;
guint*sort_key_by_rule_id= g_new(guint,rule_count_of_g);
guint no_of_predictable_rules= 0;
/*548:*/
#line 4877 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
AIM item= items_by_rule[rule_id];
SYMID postdot;
if(!item)
goto NOT_A_PREDICTABLE_RULE;
postdot= Postdot_SYMID_of_AIM(item);
if(postdot<0)
goto NOT_A_PREDICTABLE_RULE;
sort_key_by_rule_id[rule_id]= postdot;
no_of_predictable_rules++;
continue;
NOT_A_PREDICTABLE_RULE:
sort_key_by_rule_id[rule_id]= G_MAXINT;
}
}

/*:548*/
#line 4853 "./marpa.w"

/*549:*/
#line 4897 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
rule_by_sort_key[rule_id]= RULE_by_ID(g,rule_id);
}
g_qsort_with_data(rule_by_sort_key,(gint)rule_count_of_g,
sizeof(RULE),cmp_by_rule_sort_key,
(gpointer)sort_key_by_rule_id);
}

/*:549*/
#line 4854 "./marpa.w"

/*552:*/
#line 4929 "./marpa.w"

{
guint sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:552*/
#line 4855 "./marpa.w"

/*553:*/
#line 4939 "./marpa.w"

{
prediction_matrix= matrix_create(symbol_count_of_g,no_of_predictable_rules);
for(from_symid= 0;from_symid<(SYMID)symbol_count_of_g;
from_symid++)
{

guint min,max,start;
for(start= 0;
bv_scan(matrix_row
(symbol_by_symbol_matrix,(guint)from_symid),start,
&min,&max);start= max+2)
{
Marpa_Symbol_ID to_symid;
for(to_symid= min;to_symid<=(Marpa_Symbol_ID)max;
to_symid++)
{

SYM to_symbol= SYM_by_ID(to_symid);
GArray*lhs_rules= to_symbol->t_lhs;
guint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++)
{

Marpa_Rule_ID rule_with_this_lhs_symbol= 
g_array_index(lhs_rules,Marpa_Rule_ID,ix);
guint sort_key= 
sort_key_by_rule_id[rule_with_this_lhs_symbol];
if(sort_key>=no_of_predictable_rules)
continue;

matrix_bit_set(prediction_matrix,(guint)from_symid,
sort_key);

}
}
}
}
}

/*:553*/
#line 4856 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:547*/
#line 4806 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:545*/
#line 4259 "./marpa.w"

/*530:*/
#line 4426 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
Marpa_Rule_ID start_rule_id;
SYMID*postdot_symbol_ids;
AIM start_item;
SYM start_symbol= SYM_by_ID(g->t_start_symid);
AIM*item_list= obstack_alloc(&g->t_obs,sizeof(AIM));

start_rule_id= g_array_index(start_symbol->t_lhs,Marpa_Rule_ID,0);

start_item= g->t_AHFA_items_by_rule[start_rule_id];
item_list[0]= start_item;
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= 1;
p_initial_state->t_key.t_id= 0;
LV_AHFA_is_Predicted(p_initial_state)= 0;
LV_Leo_LHS_ID_of_AHFA(p_initial_state)= -1;
LV_TRANSs_of_AHFA(p_initial_state)= transitions_new(g);
LV_Postdot_SYM_Count_of_AHFA(p_initial_state)= 1;
postdot_symbol_ids= LV_Postdot_SYMID_Ary_of_AHFA(p_initial_state)= 
obstack_alloc(&g->t_obs,sizeof(SYMID));
*postdot_symbol_ids= Postdot_SYMID_of_AIM(start_item);
LV_Complete_SYM_Count_of_AHFA(p_initial_state)= 0;
p_initial_state->t_has_completed_start_rule= 0;
p_initial_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(guint)
Postdot_SYMID_of_AIM
(start_item)),rule_by_sort_key,
&states,duplicates);
}

/*:530*/
#line 4260 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*524:*/
#line 4305 "./marpa.w"
{
guint no_of_items= p_working_state->t_item_count;
guint current_item_ix= 0;
AIM*item_list;
Marpa_Symbol_ID working_symbol;
item_list= p_working_state->t_items;
working_symbol= Postdot_SYMID_of_AIM(item_list[0]);

if(working_symbol<0)goto NEXT_AHFA_STATE;

while(1){
guint first_working_item_ix= current_item_ix;
guint no_of_items_in_new_state;
for(current_item_ix++;
current_item_ix<no_of_items;
current_item_ix++){
if(Postdot_SYMID_of_AIM(item_list[current_item_ix])!=working_symbol)break;
}
no_of_items_in_new_state= current_item_ix-first_working_item_ix;
if(no_of_items_in_new_state==1){
/*532:*/
#line 4490 "./marpa.w"
{
AHFA p_new_state;
AIM*new_state_item_list;
AIM single_item_p= item_list[first_working_item_ix];
Marpa_AHFA_Item_ID single_item_id;
Marpa_Symbol_ID postdot;
single_item_p++;
single_item_id= single_item_p-AHFA_item_0_p;
p_new_state= singleton_duplicates[single_item_id];
if(p_new_state)
{
transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
goto NEXT_WORKING_SYMBOL;
}
p_new_state= DQUEUE_PUSH(states,AHFA_Object);

singleton_duplicates[single_item_id]= p_new_state;
new_state_item_list= p_new_state->t_items= 
obstack_alloc(&g->t_obs,sizeof(AIM));
new_state_item_list[0]= single_item_p;
p_new_state->t_item_count= 1;
LV_AHFA_is_Predicted(p_new_state)= 0;
if(AIM_has_Completed_Start_Rule(single_item_p)){
p_new_state->t_has_completed_start_rule= 1;
}else{
p_new_state->t_has_completed_start_rule= 0;
}
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
LV_TRANSs_of_AHFA(p_new_state)= transitions_new(g);
transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
postdot= Postdot_SYMID_of_AIM(single_item_p);
if(postdot>=0)
{
LV_Complete_SYM_Count_of_AHFA(p_new_state)= 0;
p_new_state->t_postdot_sym_count= 1;
p_new_state->t_postdot_symid_ary= 
obstack_alloc(&g->t_obs,sizeof(SYMID));
*(p_new_state->t_postdot_symid_ary)= postdot;


p_new_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(guint)postdot),
rule_by_sort_key,&states,duplicates);
}
else
{
SYMID lhs_id= LHS_ID_of_AIM(single_item_p);
SYMID*complete_symids= obstack_alloc(&g->t_obs,sizeof(SYMID));
*complete_symids= lhs_id;
LV_Complete_SYMIDs_of_AHFA(p_new_state)= complete_symids;
completion_count_inc(&ahfa_work_obs,p_new_state,lhs_id);
LV_Complete_SYM_Count_of_AHFA(p_new_state)= 1;
p_new_state->t_postdot_sym_count= 0;
p_new_state->t_empty_transition= NULL;
/*534:*/
#line 4580 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(predot_symid))
> 0)
{
LV_Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:534*/
#line 4548 "./marpa.w"

}
}

/*:532*/
#line 4325 "./marpa.w"

}else{
/*535:*/
#line 4605 "./marpa.w"
{
AHFA p_new_state;
guint predecessor_ix;
guint no_of_new_items_so_far= 0;
AIM*item_list_for_new_state;
AHFA queued_AHFA_state;
p_new_state= DQUEUE_PUSH(states,AHFA_Object);
item_list_for_new_state= p_new_state->t_items= obstack_alloc(&g->t_obs_tricky,
no_of_items_in_new_state*sizeof(AIM));
p_new_state->t_item_count= no_of_items_in_new_state;
for(predecessor_ix= first_working_item_ix;
predecessor_ix<current_item_ix;predecessor_ix++)
{
gint pre_insertion_point_ix= no_of_new_items_so_far-1;
AIM new_item_p= item_list[predecessor_ix]+1;
while(pre_insertion_point_ix>=0)
{
AIM*current_item_pp= 
item_list_for_new_state+pre_insertion_point_ix;
if(Sort_Key_of_AIM(new_item_p)>=
Sort_Key_of_AIM(*current_item_pp))
break;
*(current_item_pp+1)= *current_item_pp;
pre_insertion_point_ix--;
}
item_list_for_new_state[pre_insertion_point_ix+1]= new_item_p;
no_of_new_items_so_far++;
}
queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state)
{

(void)DQUEUE_POP(states,AHFA_Object);
obstack_free(&g->t_obs_tricky,item_list_for_new_state);
transition_add(&ahfa_work_obs,p_working_state,working_symbol,queued_AHFA_state);


goto NEXT_WORKING_SYMBOL;
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
LV_AHFA_is_Predicted(p_new_state)= 0;
p_new_state->t_has_completed_start_rule= 0;
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
LV_TRANSs_of_AHFA(p_new_state)= transitions_new(g);
/*536:*/
#line 4656 "./marpa.w"

{
guint symbol_count= SYM_Count_of_G(g);
guint item_ix;
guint no_of_postdot_symbols;
guint no_of_complete_symbols;
Bit_Vector complete_v= bv_create(symbol_count);
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_for_new_state[item_ix];
Marpa_Symbol_ID postdot= Postdot_SYMID_of_AIM(item);
if(postdot<0)
{
gint complete_symbol_id= LHS_ID_of_AIM(item);
completion_count_inc(&ahfa_work_obs,p_new_state,complete_symbol_id);
bv_bit_set(complete_v,(guint)complete_symbol_id);
}
else
{
bv_bit_set(postdot_v,(guint)postdot);
}
}
if((no_of_postdot_symbols= p_new_state->t_postdot_sym_count= 
bv_count(postdot_v)))
{
guint min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->t_postdot_symid_ary= 
obstack_alloc(&g->t_obs,
no_of_postdot_symbols*sizeof(SYMID));
for(start= 0;bv_scan(postdot_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID postdot;
for(postdot= (Marpa_Symbol_ID)min;
postdot<=(Marpa_Symbol_ID)max;postdot++)
{
*p_symbol++= postdot;
}
}
}
if((no_of_complete_symbols= 
LV_Complete_SYM_Count_of_AHFA(p_new_state)= bv_count(complete_v)))
{
guint min,max,start;
SYMID*complete_symids= obstack_alloc(&g->t_obs,
no_of_complete_symbols*
sizeof(SYMID));
SYMID*p_symbol= complete_symids;
LV_Complete_SYMIDs_of_AHFA(p_new_state)= complete_symids;
for(start= 0;bv_scan(complete_v,start,&min,&max);start= max+2)
{
SYMID complete_symbol_id;
for(complete_symbol_id= (SYMID)min;complete_symbol_id<=(SYMID)max;
complete_symbol_id++)
{
*p_symbol++= complete_symbol_id;
}
}
}
bv_free(postdot_v);
bv_free(complete_v);
}

/*:536*/
#line 4650 "./marpa.w"

transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
/*540:*/
#line 4739 "./marpa.w"
{
guint item_ix;
Marpa_Symbol_ID postdot= -1;
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++){
postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot>=0)break;
}
p_new_state->t_empty_transition= NULL;
if(postdot>=0)
{
Bit_Vector predicted_rule_vector
= bv_shadow(matrix_row(prediction_matrix,(guint)postdot));
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{

postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot<0)
continue;
bv_or_assign(predicted_rule_vector,
matrix_row(prediction_matrix,(guint)postdot));
}

p_new_state->t_empty_transition= create_predicted_AHFA_state(g,
predicted_rule_vector,
rule_by_sort_key,
&states,
duplicates);
bv_free(predicted_rule_vector);
}
}

/*:540*/
#line 4653 "./marpa.w"

}

/*:535*/
#line 4327 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:524*/
#line 4262 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*525:*/
#line 4337 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
guint symbol_id;
AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
for(symbol_id= 0;symbol_id<symbol_count_of_g;symbol_id++){
TRANS working_transition= transitions[symbol_id];
if(working_transition){
gint completion_count= Completion_Count_of_TRANS(working_transition);
gint sizeof_transition= 
G_STRUCT_OFFSET(struct s_transition,t_aex)+completion_count*
sizeof(transitions[0]->t_aex[0]);
TRANS new_transition= obstack_alloc(&g->t_obs,sizeof_transition);
LV_To_AHFA_of_TRANS(new_transition)= To_AHFA_of_TRANS(working_transition);
LV_Completion_Count_of_TRANS(new_transition)= 0;
transitions[symbol_id]= new_transition;
}
}
}
}

/*:525*/
#line 4267 "./marpa.w"

/*527:*/
#line 4389 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++)
{
AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
AIM*aims= AIMs_of_AHFA(ahfa);
gint aim_count= AIM_Count_of_AHFA(ahfa);
AEX aex;
g_qsort_with_data(aims,aim_count,sizeof(AIM*),cmp_by_aimid,NULL);
for(aex= 0;aex<aim_count;aex++)
{
AIM ahfa_item= aims[aex];
SYMID postdot= Postdot_SYMID_of_AIM(ahfa_item);
if(postdot>=0)
{
TRANS transition= transitions[postdot];
AHFA to_ahfa= To_AHFA_of_TRANS(transition);
if(!AHFA_is_Leo_Completion(to_ahfa))
continue;
Leo_Base_AEX_of_TRANS(transition)= aex;
}
}
}
}

/*:527*/
#line 4268 "./marpa.w"

/*526:*/
#line 4360 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
const AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
if(Complete_SYM_Count_of_AHFA(ahfa)> 0){
AIM*aims= AIMs_of_AHFA(ahfa);
gint aim_count= AIM_Count_of_AHFA(ahfa);
AEX aex;
for(aex= 0;aex<aim_count;aex++){
AIM ahfa_item= aims[aex];
if(AIM_is_Completion(ahfa_item)){
SYMID completed_symbol_id= LHS_ID_of_AIM(ahfa_item);
TRANS transition= transitions[completed_symbol_id];
AEX*aexes= AEXs_of_TRANS(transition);
gint aex_ix= LV_Completion_Count_of_TRANS(transition)++;
MARPA_OFF_DEBUG4("Added completion aex at %d for ahfa_id=%d sym=%d",
aex_ix,ahfa_id,completed_symbol_id);
aexes[aex_ix]= aex;
}
}
}
}
}

/*:526*/
#line 4269 "./marpa.w"

/*528:*/
#line 4416 "./marpa.w"

g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*529:*/
#line 4422 "./marpa.w"

g_free(singleton_duplicates);
g_tree_destroy(duplicates);

/*:529*/
#line 4419 "./marpa.w"

obstack_free(&ahfa_work_obs,NULL);

/*:528*/
#line 4270 "./marpa.w"

}

/*:520*//*539:*/
#line 4728 "./marpa.w"

static inline AHFA
assign_AHFA_state(AHFA sought_state,GTree*duplicates)
{
const AHFA state_found= g_tree_lookup(duplicates,sought_state);
if(state_found)return state_found;
g_tree_insert(duplicates,sought_state,sought_state);
return NULL;
}

/*:539*//*550:*/
#line 4909 "./marpa.w"
static gint
cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data){
RULE a= *(RULE*)ap;
RULE b= *(RULE*)bp;
guint*sort_key_by_rule_id= (guint*)user_data;
Marpa_Rule_ID a_id= a->t_id;
Marpa_Rule_ID b_id= b->t_id;
guint sort_key_a= sort_key_by_rule_id[a_id];
guint sort_key_b= sort_key_by_rule_id[b_id];
if(sort_key_a==sort_key_b)return a_id-b_id;
return sort_key_a-sort_key_b;
}
/*:550*//*555:*/
#line 4988 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
){
AIM*item_list_for_new_state;
AHFA p_new_state;
guint item_list_ix= 0;
guint no_of_items_in_new_state= bv_count(prediction_rule_vector);
if(no_of_items_in_new_state==0)return NULL;
item_list_for_new_state= obstack_alloc(&g->t_obs,
no_of_items_in_new_state*sizeof(AIM));
{
guint start,min,max;
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2)
{
guint rule_sort_key;
for(rule_sort_key= min;rule_sort_key<=max;rule_sort_key++)
{

RULE rule= rule_by_sort_key[rule_sort_key];
item_list_for_new_state[item_list_ix++]= 
g->t_AHFA_items_by_rule[rule->t_id];
}
}
}
p_new_state= DQUEUE_PUSH((*states_p),AHFA_Object);
p_new_state->t_items= item_list_for_new_state;
p_new_state->t_item_count= no_of_items_in_new_state;
{AHFA queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state){


(void)DQUEUE_POP((*states_p),AHFA_Object);
obstack_free(&g->t_obs,item_list_for_new_state);
return queued_AHFA_state;
}
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE((*states_p),AHFA_Object);
LV_AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_has_completed_start_rule= 0;
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
p_new_state->t_empty_transition= NULL;
LV_TRANSs_of_AHFA(p_new_state)= transitions_new(g);
LV_Complete_SYM_Count_of_AHFA(p_new_state)= 0;
/*556:*/
#line 5043 "./marpa.w"

{
guint symbol_count= SYM_Count_of_G(g);
guint item_ix;
guint no_of_postdot_symbols;
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_for_new_state[item_ix];
SYMID postdot= Postdot_SYMID_of_AIM(item);
if(postdot>=0)
bv_bit_set(postdot_v,(guint)postdot);
}
if((no_of_postdot_symbols= p_new_state->t_postdot_sym_count= 
bv_count(postdot_v)))
{
guint min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->t_postdot_symid_ary= 
obstack_alloc(&g->t_obs,
no_of_postdot_symbols*sizeof(SYMID));
for(start= 0;bv_scan(postdot_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID postdot;
for(postdot= (Marpa_Symbol_ID)min;
postdot<=(Marpa_Symbol_ID)max;postdot++)
{
*p_symbol++= postdot;
}
}
}
bv_free(postdot_v);
}

/*:556*/
#line 5039 "./marpa.w"

return p_new_state;
}

/*:555*//*568:*/
#line 5155 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition){
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:568*//*570:*/
#line 5162 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition){
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:570*//*572:*/
#line 5171 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix){
URTRANS transition;
transition= obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:572*//*574:*/
#line 5183 "./marpa.w"
static inline
TRANS*transitions_new(struct marpa_g*g){
gint symbol_count= SYM_Count_of_G(g);
gint symid= 0;
TRANS*transitions;
transitions= g_malloc(symbol_count*sizeof(transitions[0]));
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:574*//*576:*/
#line 5198 "./marpa.w"

static inline
void transition_add(struct obstack*obstack,AHFA from_ahfa,SYMID symid,AHFA to_ahfa)
{
TRANS*transitions= TRANSs_of_AHFA(from_ahfa);
TRANS transition= transitions[symid];
if(!transition){
transitions[symid]= (TRANS)transition_new(obstack,to_ahfa,0);
return;
}
LV_To_AHFA_of_TRANS(transition)= to_ahfa;
return;
}

/*:576*//*578:*/
#line 5215 "./marpa.w"

static inline
void completion_count_inc(struct obstack*obstack,AHFA from_ahfa,SYMID symid)
{
TRANS*transitions= TRANSs_of_AHFA(from_ahfa);
TRANS transition= transitions[symid];
if(!transition){
transitions[symid]= (TRANS)transition_new(obstack,NULL,1);
return;
}
LV_Completion_Count_of_TRANS(transition)++;
return;
}

/*:578*//*580:*/
#line 5234 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 5239 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
gint symbol_count;

/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 5245 "./marpa.w"

/*1344:*/
#line 13098 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1344*/
#line 5246 "./marpa.w"

/*1345:*/
#line 13103 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
g->t_error= "garray size mismatch";
return failure_indicator;
}
/*:1345*/
#line 5247 "./marpa.w"

from_ahfa_state= AHFA_of_G_by_ID(g,AHFA_state_id);
transitions= TRANSs_of_AHFA(from_ahfa_state);
symbol_count= SYM_Count_of_G(g);
g_array_set_size(result,0);
for(symid= 0;symid<symbol_count;symid++){
AHFA to_ahfa_state= To_AHFA_of_TRANS(transitions[symid]);
if(!to_ahfa_state)continue;
g_array_append_val(result,symid);
g_array_append_val(result,ID_of_AHFA(to_ahfa_state));
}
return result->len;
}

/*:580*//*584:*/
#line 5270 "./marpa.w"

AHFAID marpa_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 5275 "./marpa.w"

/*1340:*/
#line 13078 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1340*/
#line 5276 "./marpa.w"

/*1344:*/
#line 13098 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1344*/
#line 5277 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:584*//*590:*/
#line 5318 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g)
{RECCE r;
gint symbol_count_of_g;
/*1337:*/
#line 13065 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1337*/
#line 5322 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "precomputed";
return failure_indicator;
}
r= g_slice_new(struct marpa_r);
r->t_grammar= g;
symbol_count_of_g= SYM_Count_of_G(g);
/*662:*/
#line 5733 "./marpa.w"
obstack_init(&r->t_obs);
/*:662*/
#line 5330 "./marpa.w"

/*599:*/
#line 5391 "./marpa.w"

Phase_of_R(r)= initial_phase;
/*:599*//*603:*/
#line 5406 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;
/*:603*//*611:*/
#line 5441 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:611*//*617:*/
#line 5469 "./marpa.w"
r->t_furthest_earleme= 0;
/*:617*//*622:*/
#line 5488 "./marpa.w"
r->t_sym_workarea= NULL;
/*:622*//*626:*/
#line 5503 "./marpa.w"
r->t_workarea2= NULL;
/*:626*//*630:*/
#line 5527 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:630*//*634:*/
#line 5550 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:634*//*641:*/
#line 5605 "./marpa.w"

r->t_earley_item_tree= g_tree_new(trace_earley_item_cmp);

/*:641*//*652:*/
#line 5670 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:652*//*658:*/
#line 5713 "./marpa.w"
r->t_is_exhausted= 0;
/*:658*//*687:*/
#line 5838 "./marpa.w"

r->t_earley_set_count= 0;

/*:687*//*693:*/
#line 5887 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:693*//*725:*/
#line 6206 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:725*//*765:*/
#line 6623 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:765*//*808:*/
#line 7114 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:808*//*852:*/
#line 7635 "./marpa.w"

{
gpointer default_value= Default_Value_of_G(g);
gint i;
TOK*tokens_by_symid;
obstack_init(TOK_Obs);
tokens_by_symid= 
obstack_alloc(TOK_Obs,sizeof(TOK)*symbol_count_of_g);
for(i= 0;i<symbol_count_of_g;i++)
{
tokens_by_symid[i]= token_new(r,i,default_value);
}
TOKs_by_SYMID_of_R(r)= tokens_by_symid;
}
/*:852*//*860:*/
#line 7707 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:860*//*886:*/
#line 8002 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:886*//*890:*/
#line 8014 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:890*//*894:*/
#line 8026 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:894*//*963:*/
#line 8873 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:963*//*1076:*/
#line 10366 "./marpa.w"

B_of_R(r)= NULL;

/*:1076*//*1305:*/
#line 12785 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1305*/
#line 5331 "./marpa.w"

/*591:*/
#line 5337 "./marpa.w"

{
if(G_is_Trivial(g)){
R_is_Exhausted(r)= 1;
}
}

/*:591*/
#line 5332 "./marpa.w"

return r;}

/*:590*//*592:*/
#line 5344 "./marpa.w"

void marpa_r_free(struct marpa_r*r)
{
/*604:*/
#line 5410 "./marpa.w"

{
if(r->t_earley_item_tree)
g_tree_destroy(r->t_earley_item_tree);
}

/*:604*//*690:*/
#line 5864 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
if(EIMs_of_ES(set))
g_free(EIMs_of_ES(set));
}
}

/*:690*//*853:*/
#line 7649 "./marpa.w"

{
TOK*tokens_by_symid= TOKs_by_SYMID_of_R(r);
if(tokens_by_symid){
obstack_free(TOK_Obs,NULL);
TOKs_by_SYMID_of_R(r)= NULL;
}
}

/*:853*//*861:*/
#line 7709 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:861*//*888:*/
#line 8007 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:888*//*892:*/
#line 8019 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:892*//*895:*/
#line 8027 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:895*//*964:*/
#line 8875 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:964*//*1099:*/
#line 10660 "./marpa.w"
bocage_destroy(r);

/*:1099*//*1306:*/
#line 12787 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1306*/
#line 5347 "./marpa.w"

if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*632:*/
#line 5536 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:632*//*636:*/
#line 5553 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:636*/
#line 5350 "./marpa.w"

/*663:*/
#line 5734 "./marpa.w"
obstack_free(&r->t_obs,NULL);

/*:663*/
#line 5351 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:592*//*601:*/
#line 5395 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r)
{return Phase_of_R(r);}

/*:601*//*607:*/
#line 5423 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:607*//*609:*/
#line 5430 "./marpa.w"

static inline ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:609*//*613:*/
#line 5445 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:613*//*615:*/
#line 5453 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold)
{
r->t_earley_item_warning_threshold= threshold==0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:615*//*619:*/
#line 5472 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:619*//*638:*/
#line 5565 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 5568 "./marpa.w"

/*664:*/
#line 5736 "./marpa.w"

GRAMMAR g= G_of_R(r);

/*:664*/
#line 5569 "./marpa.w"

guint min,max,start;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 5571 "./marpa.w"

/*1350:*/
#line 13131 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_ERROR("recce not in input phase");
return failure_indicator;
}

/*:1350*/
#line 5572 "./marpa.w"

/*1354:*/
#line 13160 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
R_ERROR("garray size mismatch");
return failure_indicator;
}

/*:1354*/
#line 5573 "./marpa.w"

g_array_set_size(result,0);
for(start= 0;bv_scan(r->t_bv_symid_is_expected,start,&min,&max);
start= max+2)
{
gint symid;
for(symid= (gint)min;symid<=(gint)max;symid++)
{
g_array_append_val(result,symid);
}
}
return(gint)result->len;
}

/*:638*//*654:*/
#line 5678 "./marpa.w"

gint marpa_is_use_leo(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 5681 "./marpa.w"

struct marpa_g*g= G_of_R(r);
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 5683 "./marpa.w"

return r->t_use_leo_flag?1:0;
}
/*:654*//*656:*/
#line 5690 "./marpa.w"

gboolean marpa_is_use_leo_set(
struct marpa_r*r,gboolean value)
{
/*1336:*/
#line 13063 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1336*/
#line 5694 "./marpa.w"

struct marpa_g*g= G_of_R(r);
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 5696 "./marpa.w"

/*1347:*/
#line 13116 "./marpa.w"

if(Phase_of_R(r)!=initial_phase){
R_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1347*/
#line 5697 "./marpa.w"

r->t_use_leo_flag= value;
return TRUE;
}

/*:656*//*660:*/
#line 5719 "./marpa.w"

gint marpa_is_exhausted(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 5722 "./marpa.w"

struct marpa_g*g= G_of_R(r);
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 5724 "./marpa.w"

return r->t_is_exhausted?1:0;
}

/*:660*//*668:*/
#line 5743 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r)
{
/*664:*/
#line 5736 "./marpa.w"

GRAMMAR g= G_of_R(r);

/*:664*/
#line 5746 "./marpa.w"

return marpa_g_error(g);
}

/*:668*//*672:*/
#line 5754 "./marpa.w"

gint marpa_r_event(const struct marpa_r*r,struct marpa_g_event*public_event,gint ix)
{
/*664:*/
#line 5736 "./marpa.w"

GRAMMAR g= G_of_R(r);

/*:664*/
#line 5757 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:672*//*689:*/
#line 5844 "./marpa.w"

static inline ES
earley_set_new(RECCE r,EARLEME id)
{
ESK_Object key;
ES set;
set= obstack_alloc(&r->t_obs,sizeof(*set));
key.t_earleme= id;
set->t_key= key;
set->t_postdot_ary= NULL;
set->t_postdot_sym_count= 0;
EIM_Count_of_ES(set)= 0;
set->t_ordinal= r->t_earley_set_count++;
EIMs_of_ES(set)= NULL;
LV_Next_ES_of_ES(set)= NULL;
/*1312:*/
#line 12837 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1312*/
#line 5859 "./marpa.w"

return set;
}

/*:689*//*695:*/
#line 5892 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 5895 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 5898 "./marpa.w"

if(!trace_earley_set){
R_ERROR("no trace es");
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:695*//*697:*/
#line 5908 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 5911 "./marpa.w"

struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 5913 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:697*//*699:*/
#line 5927 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const gint es_does_not_exist= -1;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 5931 "./marpa.w"

ES earley_set;
struct marpa_g*g= G_of_R(r);
/*1348:*/
#line 13121 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1348*/
#line 5934 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 5935 "./marpa.w"

if(set_id<0){
R_ERROR("invalid es ordinal");
return failure_indicator;
}
r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
return es_does_not_exist;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return Earleme_of_ES(earley_set);
}

/*:699*//*702:*/
#line 5953 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 5956 "./marpa.w"

ES earley_set;
struct marpa_g*g= G_of_R(r);
/*1348:*/
#line 13121 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1348*/
#line 5959 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 5960 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
R_ERROR("invalid es ordinal");
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:702*//*712:*/
#line 6059 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1337:*/
#line 13065 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1337*/
#line 6063 "./marpa.w"

struct marpa_g*g= G_of_R(r);
EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const gint count= ++EIM_Count_of_ES(set);
/*715:*/
#line 6115 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(G_UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
R_FATAL("eim count exceeds fatal threshold");
return failure_indicator;
}
int_event_new(g,MARPA_G_EV_EARLEY_ITEM_THRESHOLD,count);
}

/*:715*/
#line 6069 "./marpa.w"

new_item= obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
g_tree_insert(r->t_earley_item_tree,new_item,new_item);
return new_item;
}

/*:712*//*714:*/
#line 6083 "./marpa.w"

static inline EIM
earley_item_assign(const RECCE r,const ES set,const ES origin,
const AHFA state)
{
EIK_Object key;
EIM eim;
PSL psl;
AHFAID ahfa_id= ID_of_AHFA(state);
PSL*psl_owner= &Dot_PSL_of_ES(origin);
if(!*psl_owner)
{
psl_claim(psl_owner,Dot_PSAR_of_R(r));
}
psl= *psl_owner;
eim= PSL_Datum(psl,ahfa_id);
if(eim
&&Earleme_of_EIM(eim)==Earleme_of_ES(set)
&&Earleme_of_ES(Origin_of_EIM(eim))==Earleme_of_ES(origin))
{
return eim;
}
key.t_origin= origin;
key.t_state= state;
key.t_set= set;
eim= earley_item_create(r,key);
PSL_Datum(psl,ahfa_id)= eim;
return eim;
}

/*:714*//*718:*/
#line 6137 "./marpa.w"

static inline gint trace_earley_item_cmp(gconstpointer ap,gconstpointer bp)
{
const EIM_Object*eim_a= ap;
const EIM_Object*eim_b= bp;
gint subkey= Earleme_of_EIM(eim_a)-Earleme_of_EIM(eim_b);
if(subkey)return subkey;
return earley_item_cmp(ap,bp,0);
}
/*:718*//*720:*/
#line 6150 "./marpa.w"

static inline gint earley_item_cmp(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED)
{
const struct s_earley_item*eim_a= ap;
const struct s_earley_item*eim_b= bp;
gint subkey= 
AHFAID_of_EIM(eim_a)-
AHFAID_of_EIM(eim_b);
if(subkey)return subkey;
return Origin_Earleme_of_EIM(eim_a)-Origin_Earleme_of_EIM(eim_b);
}

/*:720*//*723:*/
#line 6182 "./marpa.w"

static const char*invalid_source_type_message(guint type){
switch(type){
case NO_SOURCE:
return"invalid source type: none";
case SOURCE_IS_TOKEN:
return"invalid source type: token";
case SOURCE_IS_COMPLETION:
return"invalid source type: completion";
case SOURCE_IS_LEO:
return"invalid source type: leo";
case SOURCE_IS_AMBIGUOUS:
return"invalid source type: ambiguous";
}
return"unknown source type";
}

/*:723*//*731:*/
#line 6249 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const gint es_does_not_exist= -1;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6255 "./marpa.w"

struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6257 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*732:*/
#line 6280 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*768:*/
#line 6666 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:768*/
#line 6283 "./marpa.w"

}

/*:732*/
#line 6264 "./marpa.w"

if(set_id<0)
{
R_ERROR("invalid es ordinal");
return failure_indicator;
}
r_update_earley_sets(r);
if(set_id>=DSTACK_LENGTH(r->t_earley_set_stack))
{
return es_does_not_exist;
}
earley_set= ES_of_R_by_Ord(r,set_id);
r->t_trace_earley_set= earley_set;
return Earleme_of_ES(earley_set);
}

/*:731*//*734:*/
#line 6290 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const gint eim_does_not_exist= -1;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6295 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6300 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*732:*/
#line 6280 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*768:*/
#line 6666 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:768*/
#line 6283 "./marpa.w"

}

/*:732*/
#line 6304 "./marpa.w"

R_ERROR("no trace es");
return failure_indicator;
}
trace_earley_item_clear(r);
if(item_id<0)
{
R_ERROR("invalid eim ordinal");
return failure_indicator;
}
if(item_id>=EIM_Count_of_ES(trace_earley_set))
{
return eim_does_not_exist;
}
earley_items= EIMs_of_ES(trace_earley_set);
earley_item= earley_items[item_id];
r->t_trace_earley_item= earley_item;
return AHFAID_of_EIM(earley_item);
}

/*:734*//*737:*/
#line 6335 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r)
{
/*735:*/
#line 6330 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:735*/
#line 6338 "./marpa.w"

trace_source_link_clear(r);
}

/*:737*//*739:*/
#line 6344 "./marpa.w"

Marpa_Earley_Set_ID marpa_earley_item_origin(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6347 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1348:*/
#line 13121 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1348*/
#line 6349 "./marpa.w"

if(!item){
/*735:*/
#line 6330 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:735*/
#line 6351 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:739*//*747:*/
#line 6436 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6440 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6444 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item)){
R_ERROR("pim is not lim");
return failure_indicator;
}
predecessor_leo_item= Predecessor_LIM_of_LIM(LIM_of_PIM(postdot_item));
if(!predecessor_leo_item)return no_predecessor;
return Postdot_SYMID_of_LIM(predecessor_leo_item);
}

/*:747*//*749:*/
#line 6460 "./marpa.w"

Marpa_Earley_Set_ID marpa_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6464 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
struct marpa_g*g= G_of_R(r);
EIM base_earley_item;
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6468 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:749*//*751:*/
#line 6480 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6484 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6488 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:751*//*756:*/
#line 6524 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6528 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6531 "./marpa.w"

if(!postdot_item)
{
R_ERROR("no trace pim");
return failure_indicator;
}
if(!EIM_of_PIM(postdot_item))
{
const LIM leo_item= LIM_of_PIM(postdot_item);
const EIM base_earley_item= Base_EIM_of_LIM(leo_item);
const SYMID postdot_symbol= Postdot_SYMID_of_LIM(leo_item);
const AHFA to_ahfa= To_AHFA_of_EIM_by_SYMID(base_earley_item,postdot_symbol);
return ID_of_AHFA(to_ahfa);
}
return pim_is_not_a_leo_item;
}


/*:756*//*761:*/
#line 6585 "./marpa.w"

static inline PIM*
pim_sym_p_find(ES set,SYMID symid)
{
gint lo= 0;
gint hi= Postdot_SYM_Count_of_ES(set)-1;
PIM*postdot_array= set->t_postdot_ary;
while(hi>=lo){
gint trial= lo+(hi-lo)/2;
PIM trial_pim= postdot_array[trial];
SYMID trial_symid= Postdot_SYMID_of_PIM(trial_pim);
if(trial_symid==symid)return postdot_array+trial;
if(trial_symid<symid){
lo= trial+1;
}else{
hi= trial-1;
}
}
return NULL;
}
/*:761*//*763:*/
#line 6607 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:763*//*767:*/
#line 6641 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6646 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
struct marpa_g*g= G_of_R(r);
/*768:*/
#line 6666 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:768*/
#line 6651 "./marpa.w"

/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6652 "./marpa.w"

/*1353:*/
#line 13155 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
R_ERROR("invalid symid");
return failure_indicator;
}
/*:1353*/
#line 6653 "./marpa.w"

if(!current_es){
R_ERROR("no pim");
return failure_indicator;
}
pim_sym_p= PIM_SYM_P_of_ES_by_SYMID(current_es,symid);
pim= *pim_sym_p;
if(!pim)return-1;
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return symid;
}

/*:767*//*770:*/
#line 6679 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6683 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
struct marpa_g*g= G_of_R(r);
PIM*pim_sym_p;
/*768:*/
#line 6666 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:768*/
#line 6688 "./marpa.w"

/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6689 "./marpa.w"

if(!current_earley_set){
/*735:*/
#line 6330 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:735*/
#line 6691 "./marpa.w"

R_ERROR("no trace es");
return failure_indicator;
}
if(current_earley_set->t_postdot_sym_count<=0)return-1;
pim_sym_p= current_earley_set->t_postdot_ary+0;
pim= pim_sym_p[0];
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return Postdot_SYMID_of_PIM(pim);
}

/*:770*//*772:*/
#line 6713 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6718 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
struct marpa_g*g= G_of_R(r);

pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*768:*/
#line 6666 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:768*/
#line 6726 "./marpa.w"

if(!pim_sym_p||!pim){
R_ERROR("no trace pim");
return failure_indicator;
}
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6731 "./marpa.w"

if(!current_set){
R_ERROR("no trace es");
return failure_indicator;
}
pim= Next_PIM_of_PIM(pim);
if(!pim){

pim_sym_p++;
if(pim_sym_p-current_set->t_postdot_ary
>=current_set->t_postdot_sym_count){
return no_more_postdot_symbols;
}
pim= *pim_sym_p;
}
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return Postdot_SYMID_of_PIM(pim);
}

/*:772*//*774:*/
#line 6753 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 6756 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 6759 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:774*//*791:*/
#line 6897 "./marpa.w"
static inline
void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
TOK token)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_EIM(item)= SOURCE_IS_TOKEN;
item->t_container.t_unique.t_predecessor= predecessor;
TOK_of_Source(item->t_container.t_unique)= token;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Token_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
TOK_of_Source(new_link->t_source)= token;
LV_First_Token_Link_of_EIM(item)= new_link;
}

/*:791*//*797:*/
#line 6978 "./marpa.w"
static inline
void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_EIM(item)= SOURCE_IS_COMPLETION;
item->t_container.t_unique.t_predecessor= predecessor;
Cause_of_Source(item->t_container.t_unique)= cause;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Completion_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Completion_Link_of_EIM(item)= new_link;
}

/*:797*//*798:*/
#line 7005 "./marpa.w"
static inline
void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_EIM(item)= SOURCE_IS_LEO;
item->t_container.t_unique.t_predecessor= predecessor;
Cause_of_Source(item->t_container.t_unique)= cause;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Leo_SRCL_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
}
/*:798*//*801:*/
#line 7057 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
guint previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*803:*/
#line 7075 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= new_link;
}

/*:803*/
#line 7064 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*804:*/
#line 7084 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= new_link;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:804*/
#line 7066 "./marpa.w"

return;
case SOURCE_IS_LEO:/*805:*/
#line 7093 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:805*/
#line 7068 "./marpa.w"

return;
}
}
/*:801*//*811:*/
#line 7127 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7130 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7135 "./marpa.w"

/*830:*/
#line 7364 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:830*/
#line 7136 "./marpa.w"

source_type= Source_Type_of_EIM(item);
switch(source_type)
{
case SOURCE_IS_TOKEN:
r->t_trace_source_type= SOURCE_IS_TOKEN;
source= &(item->t_container.t_unique);
r->t_trace_source= source;
r->t_trace_next_source_link= NULL;
return SYMID_of_SRC(source);
case SOURCE_IS_AMBIGUOUS:
{
SRCL full_link= 
First_Token_Link_of_EIM(item);
if(full_link)
{
r->t_trace_source_type= SOURCE_IS_TOKEN;
r->t_trace_next_source_link= Next_SRCL_of_SRCL(full_link);
r->t_trace_source= &(full_link->t_source);
return SYMID_of_SRCL(full_link);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:811*//*815:*/
#line 7173 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7176 "./marpa.w"

SRCL full_link;
EIM item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7180 "./marpa.w"

/*830:*/
#line 7364 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:830*/
#line 7181 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_TOKEN){
trace_source_link_clear(r);
R_ERROR("not tracing token links");
return failure_indicator;
}
if(!r->t_trace_next_source_link){
trace_source_link_clear(r);
return-1;
}
full_link= r->t_trace_next_source_link;
r->t_trace_next_source_link= Next_SRCL_of_SRCL(full_link);
r->t_trace_source= &(full_link->t_source);
return SYMID_of_SRCL(full_link);
}

/*:815*//*818:*/
#line 7206 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7209 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7214 "./marpa.w"

/*830:*/
#line 7364 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:830*/
#line 7215 "./marpa.w"

switch((source_type= Source_Type_of_EIM(item)))
{
case SOURCE_IS_COMPLETION:
r->t_trace_source_type= SOURCE_IS_COMPLETION;
source= &(item->t_container.t_unique);
r->t_trace_source= source;
r->t_trace_next_source_link= NULL;
return Cause_AHFA_State_ID_of_SRC(source);
case SOURCE_IS_AMBIGUOUS:
{
SRCL completion_link= First_Completion_Link_of_EIM(item);
if(completion_link)
{
source= &(completion_link->t_source);
r->t_trace_source_type= SOURCE_IS_COMPLETION;
r->t_trace_next_source_link= Next_SRCL_of_SRCL(completion_link);
r->t_trace_source= source;
return Cause_AHFA_State_ID_of_SRC(source);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:818*//*822:*/
#line 7251 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7254 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7259 "./marpa.w"

/*830:*/
#line 7364 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:830*/
#line 7260 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_COMPLETION){
trace_source_link_clear(r);
R_ERROR("not tracing completion links");
return failure_indicator;
}
if(!r->t_trace_next_source_link){
trace_source_link_clear(r);
return-1;
}
completion_link= r->t_trace_next_source_link;
r->t_trace_next_source_link= Next_SRCL_of_SRCL(r->t_trace_next_source_link);
source= &(completion_link->t_source);
r->t_trace_source= source;
return Cause_AHFA_State_ID_of_SRC(source);
}

/*:822*//*825:*/
#line 7286 "./marpa.w"

Marpa_Symbol_ID
marpa_first_leo_link_trace(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7290 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7295 "./marpa.w"

/*830:*/
#line 7364 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:830*/
#line 7296 "./marpa.w"

switch((source_type= Source_Type_of_EIM(item)))
{
case SOURCE_IS_LEO:
r->t_trace_source_type= SOURCE_IS_LEO;
source= &(item->t_container.t_unique);
r->t_trace_source= source;
r->t_trace_next_source_link= NULL;
return Cause_AHFA_State_ID_of_SRC(source);
case SOURCE_IS_AMBIGUOUS:
{
SRCL full_link= 
First_Leo_SRCL_of_EIM(item);
if(full_link)
{
source= &(full_link->t_source);
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_next_source_link= (SRCL)
Next_SRCL_of_SRCL(full_link);
r->t_trace_source= source;
return Cause_AHFA_State_ID_of_SRC(source);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:825*//*829:*/
#line 7334 "./marpa.w"

Marpa_Symbol_ID
marpa_next_leo_link_trace(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7338 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7343 "./marpa.w"

/*830:*/
#line 7364 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:830*/
#line 7344 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_LEO)
{
trace_source_link_clear(r);
R_ERROR("not tracing leo links");
return failure_indicator;
}
if(!r->t_trace_next_source_link)
{
trace_source_link_clear(r);
return-1;
}
full_link= r->t_trace_next_source_link;
source= &(full_link->t_source);
r->t_trace_source= source;
r->t_trace_next_source_link= 
Next_SRCL_of_SRCL(r->t_trace_next_source_link);
return Cause_AHFA_State_ID_of_SRC(source);
}

/*:829*//*833:*/
#line 7375 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r){
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:833*//*835:*/
#line 7392 "./marpa.w"

AHFAID marpa_source_predecessor_state(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7395 "./marpa.w"

guint source_type;
SRC source;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7399 "./marpa.w"

source_type= r->t_trace_source_type;
/*844:*/
#line 7549 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:844*/
#line 7401 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:{
EIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return-1;
return AHFAID_of_EIM(predecessor);
}
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:835*//*837:*/
#line 7435 "./marpa.w"

Marpa_Symbol_ID marpa_source_token(struct marpa_r*r,gpointer*value_p)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7438 "./marpa.w"

guint source_type;
SRC source;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7442 "./marpa.w"

source_type= r->t_trace_source_type;
/*844:*/
#line 7549 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:844*/
#line 7444 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:837*//*840:*/
#line 7469 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7472 "./marpa.w"

guint source_type;
SRC source;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7476 "./marpa.w"

source_type= r->t_trace_source_type;
/*844:*/
#line 7549 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:844*/
#line 7478 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:840*//*843:*/
#line 7517 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7520 "./marpa.w"

const EARLEME no_predecessor= -1;
guint source_type;
SRC source;
struct marpa_g*g= G_of_R(r);
/*1351:*/
#line 13137 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 13138 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

/*:1351*/
#line 7525 "./marpa.w"

source_type= r->t_trace_source_type;
/*844:*/
#line 7549 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:844*/
#line 7527 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
{
LIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return no_predecessor;
return
ES_Ord_of_EIM(Base_EIM_of_LIM(predecessor));
}
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:
{
EIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return no_predecessor;
return ES_Ord_of_EIM(predecessor);
}
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:843*//*855:*/
#line 7661 "./marpa.w"

static inline
TOK token_new(struct marpa_r*r,SYMID symbol_id,gpointer value)
{
TOK token;
token= obstack_alloc(TOK_Obs,sizeof(*token));
Type_of_TOK(token)= TOKEN_OR_NODE;
SYMID_of_TOK(token)= symbol_id;
Value_of_TOK(token)= value;
return token;
}

/*:855*//*863:*/
#line 7717 "./marpa.w"

static inline gint
alternative_insertion_point(RECCE r,ALT new_alternative)
{
DSTACK alternatives= &r->t_alternatives;
ALT alternative;
gint hi= DSTACK_LENGTH(*alternatives)-1;
gint lo= 0;
gint trial;

if(hi<0)
return 0;
alternative= DSTACK_BASE(*alternatives,ALT_Object);
for(;;)
{
gint outcome;
trial= lo+(hi-lo)/2;
outcome= alternative_cmp(new_alternative,alternative+trial);
if(outcome==0)
return-1;
if(outcome> 0)
{
lo= trial+1;
}
else
{
hi= trial-1;
}
if(hi<lo)
return outcome> 0?trial+1:trial;
}
}

/*:863*//*865:*/
#line 7763 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b){
gint subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:865*//*867:*/
#line 7781 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:867*//*869:*/
#line 7798 "./marpa.w"

static inline gint alternative_insert(RECCE r,ALT new_alternative)
{
ALT top_of_stack,base_of_stack;
DSTACK alternatives= &r->t_alternatives;
gint ix;
gint insertion_point= alternative_insertion_point(r,new_alternative);
if(insertion_point<0)
return insertion_point;
top_of_stack= DSTACK_PUSH(*alternatives,ALT_Object);
base_of_stack= DSTACK_BASE(*alternatives,ALT_Object);
for(ix= top_of_stack-base_of_stack;ix> insertion_point;ix--){
base_of_stack[ix]= base_of_stack[ix-1];
}
base_of_stack[insertion_point]= *new_alternative;
return insertion_point;
}

/*:869*//*872:*/
#line 7818 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
GRAMMAR_Const g= G_of_R(r);
const gint symbol_count_of_g= SYM_Count_of_G(g);
/*1336:*/
#line 13063 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1336*/
#line 7826 "./marpa.w"

/*1347:*/
#line 13116 "./marpa.w"

if(Phase_of_R(r)!=initial_phase){
R_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1347*/
#line 7827 "./marpa.w"

Phase_of_R(r)= input_phase;
LV_Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g))return TRUE;
/*627:*/
#line 5504 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*623:*/
#line 5489 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:623*/
#line 5507 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:627*/
#line 7831 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*631:*/
#line 5531 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:631*//*635:*/
#line 5551 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:635*/
#line 7833 "./marpa.w"

/*887:*/
#line 8003 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT(r->t_eim_work_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:887*//*891:*/
#line 8015 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT(r->t_completion_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:891*/
#line 7834 "./marpa.w"

set0= earley_set_new(r,0);
LV_Latest_ES_of_R(r)= set0;
LV_First_ES_of_R(r)= set0;
state= AHFA_of_G_by_ID(g,0);
key.t_origin= set0;
key.t_state= state;
key.t_set= set0;
item= earley_item_create(r,key);
state= Empty_Transition_of_AHFA(state);
if(state){
key.t_state= state;
item= earley_item_create(r,key);
}
postdot_items_create(r,set0);
earley_set_update_items(r,set0);
r->t_is_using_leo= r->t_use_leo_flag;
return TRUE;
}

/*:872*//*880:*/
#line 7904 "./marpa.w"

gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 7907 "./marpa.w"

GRAMMAR g= G_of_R(r);
const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1350:*/
#line 13131 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_ERROR("recce not in input phase");
return failure_indicator;
}

/*:1350*/
#line 7914 "./marpa.w"

/*1349:*/
#line 13126 "./marpa.w"

if(R_is_Exhausted(r)){
R_ERROR("recce exhausted");
return failure_indicator;
}
/*:1349*/
#line 7915 "./marpa.w"

/*881:*/
#line 7923 "./marpa.w"
{
const SYM_Const token= SYM_by_ID(token_id);
if(!SYM_is_Terminal(token)){
R_ERROR("token is not a terminal");
return failure_indicator;
}
if(length<=0){
R_ERROR("token length negative or zero");
return failure_indicator;
}
if(length>=EARLEME_THRESHOLD){
R_ERROR("token too long");
return failure_indicator;
}
}

/*:881*/
#line 7916 "./marpa.w"

/*883:*/
#line 7954 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:883*/
#line 7917 "./marpa.w"

/*882:*/
#line 7939 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
R_ERROR("parse too long");
return failure_indicator;
}
}

/*:882*/
#line 7918 "./marpa.w"

/*884:*/
#line 7977 "./marpa.w"

{
TOK token= token_new(r,token_id,value);
ALT_Object alternative;
if(Furthest_Earleme_of_R(r)<target_earleme)
LV_Furthest_Earleme_of_R(r)= target_earleme;
alternative.t_token= token;
alternative.t_start_earley_set= current_earley_set;
alternative.t_end_earleme= target_earleme;
if(alternative_insert(r,&alternative)<0)
{
/*856:*/
#line 7676 "./marpa.w"
obstack_free(TOK_Obs,token);

/*:856*/
#line 7988 "./marpa.w"

return duplicate_token_indicator;
}
}

/*:884*/
#line 7919 "./marpa.w"

return current_earleme;
}

/*:880*//*898:*/
#line 8048 "./marpa.w"

Marpa_Earleme
marpa_earleme_complete(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 8052 "./marpa.w"

/*664:*/
#line 5736 "./marpa.w"

GRAMMAR g= G_of_R(r);

/*:664*/
#line 8053 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
gint count_of_expected_terminals;
/*1350:*/
#line 13131 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_ERROR("recce not in input phase");
return failure_indicator;
}

/*:1350*/
#line 8058 "./marpa.w"

/*1349:*/
#line 13126 "./marpa.w"

if(R_is_Exhausted(r)){
R_ERROR("recce exhausted");
return failure_indicator;
}
/*:1349*/
#line 8059 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*899:*/
#line 8087 "./marpa.w"
{
current_earleme= ++(LV_Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
R_is_Exhausted(r)= 1;
R_ERROR("parse exhausted");
return failure_indicator;
}
}

/*:899*/
#line 8063 "./marpa.w"

/*901:*/
#line 8112 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:901*/
#line 8064 "./marpa.w"

/*900:*/
#line 8099 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
LV_Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
LV_Latest_ES_of_R(r)= current_earley_set;
}

/*:900*/
#line 8065 "./marpa.w"

/*902:*/
#line 8118 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*903:*/
#line 8125 "./marpa.w"

{
ES start_earley_set= Start_ES_of_ALT(alternative);
TOK token= TOK_of_ALT(alternative);
SYMID token_id= SYMID_of_TOK(token);
PIM pim= First_PIM_of_ES_by_SYMID(start_earley_set,token_id);
for(;pim;pim= Next_PIM_of_PIM(pim)){
AHFA scanned_AHFA,prediction_AHFA;
EIM scanned_earley_item;
EIM predecessor= EIM_of_PIM(pim);
if(!predecessor)
continue;
scanned_AHFA= To_AHFA_of_EIM_by_SYMID(predecessor,token_id);
scanned_earley_item= earley_item_assign(r,
current_earley_set,
Origin_of_EIM(predecessor),
scanned_AHFA);
token_link_add(r,scanned_earley_item,predecessor,token);
prediction_AHFA= Empty_Transition_of_AHFA(scanned_AHFA);
if(!prediction_AHFA)continue;
scanned_earley_item= earley_item_assign(r,
current_earley_set,
current_earley_set,
prediction_AHFA);
}
}

/*:903*/
#line 8122 "./marpa.w"

}

/*:902*/
#line 8066 "./marpa.w"

/*904:*/
#line 8152 "./marpa.w"
{
EIM*work_earley_items= DSTACK_BASE(r->t_eim_work_stack,EIM);
gint no_of_work_earley_items= DSTACK_LENGTH(r->t_eim_work_stack);
gint ix;
DSTACK_CLEAR(r->t_completion_stack);
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
EIM earley_item= work_earley_items[ix];
EIM*tos;
if(!Earley_Item_is_Completion(earley_item))
continue;
tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= earley_item;
}
}

/*:904*/
#line 8067 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*905:*/
#line 8171 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*906:*/
#line 8184 "./marpa.w"

{
PIM postdot_item;
for(postdot_item= First_PIM_of_ES_by_SYMID(middle,complete_symbol);
postdot_item;postdot_item= Next_PIM_of_PIM(postdot_item))
{
EIM predecessor= EIM_of_PIM(postdot_item);
EIM effect;
AHFA effect_AHFA_state;
if(predecessor)
{
/*907:*/
#line 8207 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*908:*/
#line 8223 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:908*/
#line 8216 "./marpa.w"

}
/*909:*/
#line 8230 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:909*/
#line 8218 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:907*/
#line 8195 "./marpa.w"

}
else
{
/*910:*/
#line 8240 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*908:*/
#line 8223 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:908*/
#line 8249 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:910*/
#line 8199 "./marpa.w"

break;


}
}
}

/*:906*/
#line 8180 "./marpa.w"

}
}

/*:905*/
#line 8070 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


R_is_Exhausted(r)= 1;
event_new(g,MARPA_G_EV_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:898*//*912:*/
#line 8256 "./marpa.w"

static inline void earley_set_update_items(RECCE r,ES set){
EIM*working_earley_items;
EIM*finished_earley_items;
gint working_earley_item_count;
gint i;
if(!EIMs_of_ES(set)){
EIMs_of_ES(set)= g_new(EIM,EIM_Count_of_ES(set));
}else{
EIMs_of_ES(set)= g_renew(EIM,EIMs_of_ES(set),EIM_Count_of_ES(set));
}
finished_earley_items= EIMs_of_ES(set);
working_earley_items= Work_EIMs_of_R(r);
working_earley_item_count= Work_EIM_Count_of_R(r);
for(i= 0;i<working_earley_item_count;i++){
EIM earley_item= working_earley_items[i];
gint ordinal= Ord_of_EIM(earley_item);
finished_earley_items[ordinal]= earley_item;
}
WORK_EIMS_CLEAR(r);
}

/*:912*//*914:*/
#line 8282 "./marpa.w"

static inline void r_update_earley_sets(RECCE r){
ES set;
ES first_unstacked_earley_set;
if(!DSTACK_IS_INITIALIZED(r->t_earley_set_stack)){
first_unstacked_earley_set= First_ES_of_R(r);
DSTACK_INIT(r->t_earley_set_stack,ES,
MAX(1024,ES_Count_of_R(r)));
}else{
ES*top_of_stack= DSTACK_TOP(r->t_earley_set_stack,ES);
first_unstacked_earley_set= Next_ES_of_ES(*top_of_stack);
}
for(set= first_unstacked_earley_set;set;set= Next_ES_of_ES(set)){
ES*top_of_stack= DSTACK_PUSH(r->t_earley_set_stack,ES);
(*top_of_stack)= set;
}
}

/*:914*//*918:*/
#line 8320 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES current_earley_set)
{
gpointer*const pim_workarea= r->t_sym_workarea;
GRAMMAR_Const g= G_of_R(r);
EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*919:*/
#line 8342 "./marpa.w"
{
EIM*work_earley_items= DSTACK_BASE(r->t_eim_work_stack,EIM);
gint no_of_work_earley_items= DSTACK_LENGTH(r->t_eim_work_stack);
gint ix;
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
EIM earley_item= work_earley_items[ix];
AHFA state= AHFA_of_EIM(earley_item);
gint symbol_ix;
gint postdot_symbol_count= Postdot_SYM_Count_of_AHFA(state);
Marpa_Symbol_ID*postdot_symbols= 
Postdot_SYMID_Ary_of_AHFA(state);
for(symbol_ix= 0;symbol_ix<postdot_symbol_count;symbol_ix++)
{
PIM old_pim= NULL;
PIM new_pim;
Marpa_Symbol_ID symid;
new_pim= obstack_alloc(&r->t_obs,sizeof(EIX_Object));
symid= postdot_symbols[symbol_ix];
LV_Postdot_SYMID_of_PIM(new_pim)= symid;
LV_EIM_of_PIM(new_pim)= earley_item;
if(bv_bit_test(bv_pim_symbols,(guint)symid))
old_pim= pim_workarea[symid];
if(old_pim){
LV_Next_PIM_of_PIM(new_pim)= old_pim;
}else{
LV_Next_PIM_of_PIM(new_pim)= NULL;
current_earley_set->t_postdot_sym_count++;
}
pim_workarea[symid]= new_pim;
bv_bit_set(bv_pim_symbols,(guint)symid);
}
}
}

/*:919*/
#line 8331 "./marpa.w"

if(r->t_is_using_leo){
/*921:*/
#line 8388 "./marpa.w"

{
guint min,max,start;
for(start= 0;bv_scan(bv_pim_symbols,start,&min,&max);
start= max+2)
{
SYMID symid;
for(symid= (SYMID)min;symid<=(SYMID)max;symid++)
{
PIM this_pim= pim_workarea[symid];
if(!Next_PIM_of_PIM(this_pim))
{

EIM leo_base= EIM_of_PIM(this_pim);
AHFA base_to_ahfa= To_AHFA_of_EIM_by_SYMID(leo_base,symid);
if(AHFA_is_Leo_Completion(base_to_ahfa))
{
/*922:*/
#line 8418 "./marpa.w"
{
LIM new_lim;
new_lim= obstack_alloc(&r->t_obs,sizeof(*new_lim));
Postdot_SYMID_of_LIM(new_lim)= symid;
LV_EIM_of_PIM(new_lim)= NULL;
LV_Predecessor_LIM_of_LIM(new_lim)= NULL;
LV_Origin_of_LIM(new_lim)= NULL;
LV_Chain_Length_of_LIM(new_lim)= -1;
LV_Top_AHFA_of_LIM(new_lim)= base_to_ahfa;
LV_Base_EIM_of_LIM(new_lim)= leo_base;
LV_ES_of_LIM(new_lim)= current_earley_set;
LV_Next_PIM_of_LIM(new_lim)= this_pim;
pim_workarea[symid]= new_lim;
bv_bit_set(bv_lim_symbols,(guint)symid);
}

/*:922*/
#line 8405 "./marpa.w"

}
}
}
}
}

/*:921*/
#line 8333 "./marpa.w"

/*931:*/
#line 8503 "./marpa.w"
{
const Bit_Vector bv_ok_for_chain= r->t_bv_sym3;
guint min,max,start;

bv_copy(bv_ok_for_chain,bv_lim_symbols);
for(start= 0;bv_scan(bv_lim_symbols,start,&min,&max);
start= max+2)
{

SYMID main_loop_symbol_id;
for(main_loop_symbol_id= (SYMID)min;
main_loop_symbol_id<=(SYMID)max;
main_loop_symbol_id++)
{
LIM predecessor_lim;
LIM lim_to_process= pim_workarea[main_loop_symbol_id];
if(LIM_is_Populated(lim_to_process))continue;

/*934:*/
#line 8562 "./marpa.w"
{
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
const ES predecessor_set= Origin_of_EIM(base_eim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const SYMID predecessor_transition_symbol= Leo_LHS_ID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Earleme_of_ES(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_ES_by_SYMID(predecessor_set,predecessor_transition_symbol);
}else{
predecessor_pim= pim_workarea[predecessor_transition_symbol];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:934*/
#line 8521 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*940:*/
#line 8654 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:940*/
#line 8523 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*942:*/
#line 8675 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
LV_Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:942*/
#line 8529 "./marpa.w"

continue;
}
/*935:*/
#line 8577 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*938:*/
#line 8598 "./marpa.w"
{
SYMID postdot_symid_of_lim_to_process
= Postdot_SYMID_of_LIM(lim_to_process);
lim_chain_ix= 0;
lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);
bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);


while(1){
lim_to_process= predecessor_lim;






postdot_symid_of_lim_to_process= Postdot_SYMID_of_LIM(lim_to_process);
if(!bv_bit_test(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process)){





break;
}

/*934:*/
#line 8562 "./marpa.w"
{
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
const ES predecessor_set= Origin_of_EIM(base_eim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const SYMID predecessor_transition_symbol= Leo_LHS_ID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Earleme_of_ES(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_ES_by_SYMID(predecessor_set,predecessor_transition_symbol);
}else{
predecessor_pim= pim_workarea[predecessor_transition_symbol];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:934*/
#line 8624 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:938*/
#line 8580 "./marpa.w"

/*939:*/
#line 8643 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*940:*/
#line 8654 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:940*/
#line 8647 "./marpa.w"

}else{
/*942:*/
#line 8675 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
LV_Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:942*/
#line 8649 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:939*/
#line 8581 "./marpa.w"

}

/*:935*/
#line 8532 "./marpa.w"

}
}
}

/*:931*/
#line 8334 "./marpa.w"

}
/*943:*/
#line 8681 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= obstack_alloc(&r->t_obs,
current_earley_set->t_postdot_sym_count*sizeof(PIM));
guint min,max,start;
gint postdot_array_ix= 0;
for(start= 0;bv_scan(bv_pim_symbols,start,&min,&max);start= max+2){
SYMID symid;
for(symid= (SYMID)min;symid<=(SYMID)max;symid++){
PIM this_pim= pim_workarea[symid];
if(this_pim)postdot_array[postdot_array_ix++]= this_pim;
}
}
}

/*:943*/
#line 8336 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:918*//*966:*/
#line 8880 "./marpa.w"

static inline void ur_node_stack_init(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_init %s",G_STRLOC);
obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:966*//*968:*/
#line 8890 "./marpa.w"

static inline void ur_node_stack_reset(URS stack){
stack->t_top= stack->t_base;
}

/*:968*//*970:*/
#line 8897 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
if(stack->t_base)obstack_free(&stack->t_obs,NULL);
stack->t_base= NULL;
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
}

/*:970*//*972:*/
#line 8907 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev){
UR new_ur_node;
new_ur_node= obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
LV_Next_UR_of_UR(new_ur_node)= 0;
LV_Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:972*//*974:*/
#line 8918 "./marpa.w"

static inline void
ur_node_push(URS stack,EIM earley_item,AEX aex)
{
UR top= stack->t_top;
UR new_top= Next_UR_of_UR(top);
LV_EIM_of_UR(top)= earley_item;
LV_AEX_of_UR(top)= aex;
if(!new_top)
{
new_top= ur_node_new(stack,top);
LV_Next_UR_of_UR(top)= new_top;
}
stack->t_top= new_top;
}

/*:974*//*976:*/
#line 8936 "./marpa.w"

static inline UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:976*//*981:*/
#line 9005 "./marpa.w"

static inline gint psia_test_and_set(
struct obstack*obs,
struct s_bocage_setup_per_es*per_es_data,
EIM earley_item,
AEX ahfa_element_ix)
{
const gint aim_count_of_item= AIM_Count_of_EIM(earley_item);
const Marpa_Earley_Set_ID set_ordinal= ES_Ord_of_EIM(earley_item);
OR**nodes_by_item= per_es_data[set_ordinal].t_aexes_by_item;
const gint item_ordinal= Ord_of_EIM(earley_item);
OR*nodes_by_aex= nodes_by_item[item_ordinal];
MARPA_ASSERT(ahfa_element_ix<aim_count_of_item)
if(!nodes_by_aex){
AEX aex;
nodes_by_aex= nodes_by_item[item_ordinal]= 
obstack_alloc(obs,aim_count_of_item*sizeof(OR));
for(aex= 0;aex<aim_count_of_item;aex++){
nodes_by_aex[aex]= NULL;
}
}
if(!nodes_by_aex[ahfa_element_ix]){
nodes_by_aex[ahfa_element_ix]= dummy_or_node;
return 0;
}
return 1;
}

/*:981*//*1018:*/
#line 9605 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:1018*//*1020:*/
#line 9619 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:1020*//*1027:*/
#line 9740 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause);
return draft_and_node;
}

/*:1027*//*1030:*/
#line 9766 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:1030*//*1058:*/
#line 10204 "./marpa.w"

gint marpa_and_node_count(struct marpa_r*r)
{
BOC b= B_of_R(r);
struct marpa_g*g= G_of_R(r);
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10209 "./marpa.w"

/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10210 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
return AND_Count_of_B(b);
}

/*:1058*//*1061:*/
#line 10243 "./marpa.w"

gint marpa_and_node_parent(struct marpa_r*r,int and_node_id)
{
AND and_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10247 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1059:*/
#line 10218 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10221 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1059*/
#line 10249 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1061*//*1063:*/
#line 10255 "./marpa.w"

gint marpa_and_node_predecessor(struct marpa_r*r,int and_node_id)
{
AND and_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10259 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1059:*/
#line 10218 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10221 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1059*/
#line 10261 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1063*//*1065:*/
#line 10272 "./marpa.w"

gint marpa_and_node_cause(struct marpa_r*r,int and_node_id)
{
AND and_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10276 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1059:*/
#line 10218 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10221 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1059*/
#line 10278 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1065*//*1067:*/
#line 10289 "./marpa.w"

gint marpa_and_node_symbol(struct marpa_r*r,int and_node_id)
{
AND and_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10293 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1059:*/
#line 10218 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10221 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1059*/
#line 10295 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1067*//*1069:*/
#line 10323 "./marpa.w"

Marpa_Symbol_ID marpa_and_node_token(struct marpa_r*r,
Marpa_And_Node_ID and_node_id,gpointer*value_p)
{
AND and_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10328 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1059:*/
#line 10218 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10221 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1059*/
#line 10330 "./marpa.w"

return and_node_token(and_node,value_p);
}
/*:1069*//*1071:*/
#line 10335 "./marpa.w"

SYMID and_node_token(AND and_node,gpointer*value_p)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
const TOK token= TOK_of_OR(cause_or);
if(value_p)
*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
return-1;
}

/*:1071*//*1083:*/
#line 10399 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal_arg){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10401 "./marpa.w"

ORID top_or_node_id= failure_indicator;
const gint no_parse= -1;
/*1084:*/
#line 10436 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const gint rule_count_of_g= RULE_Count_of_G(g);
const gint symbol_count_of_g= SYM_Count_of_G(g);
BOC b= NULL;
ES end_of_parse_earley_set;
EARLEME end_of_parse_earleme;
RULE completed_start_rule;
EIM start_eim= NULL;
AIM start_aim= NULL;
AEX start_aex= -1;
struct obstack bocage_setup_obs;
gint total_earley_items_in_parse;
gint or_node_estimate= 0;
const gint earley_set_count_of_r= ES_Count_of_R(r);

/*:1084*//*1087:*/
#line 10460 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:1087*/
#line 10404 "./marpa.w"

/*1088:*/
#line 10463 "./marpa.w"

{
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10465 "./marpa.w"

if(B_of_R(r))
{
R_ERROR("bocage in use");
return failure_indicator;
}
switch(Phase_of_R(r))
{
default:
R_ERROR("recce not evaluation-ready");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
}

/*:1088*/
#line 10405 "./marpa.w"

b= B_of_R(r)= g_slice_new(BOC_Object);
/*1004:*/
#line 9352 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;

/*:1004*//*1079:*/
#line 10376 "./marpa.w"

b->is_obstack_initialized= 1;
obstack_init(&OBS_of_B(b));
/*:1079*//*1148:*/
#line 11211 "./marpa.w"

MARPA_DEBUG3("%s rank_safe where b=%p",G_STRLOC,b);
rank_safe(RANK_of_B(b));
/*:1148*/
#line 10407 "./marpa.w"

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto SOFT_ERROR;
return r_create_null_bocage(r,b);
}
r_update_earley_sets(r);
/*1089:*/
#line 10482 "./marpa.w"

{
MARPA_OFF_DEBUG2("ordinal_arg=%d",ordinal_arg);
if(ordinal_arg==-1)
{
end_of_parse_earley_set= Current_ES_of_R(r);
}
else
{
if(!ES_Ord_is_Valid(r,ordinal_arg))
{
R_ERROR("invalid es ordinal");
return failure_indicator;
}
end_of_parse_earley_set= ES_of_R_by_Ord(r,ordinal_arg);
}

if(!end_of_parse_earley_set)
return no_parse;
end_of_parse_earleme= Earleme_of_ES(end_of_parse_earley_set);
}

/*:1089*/
#line 10413 "./marpa.w"

if(end_of_parse_earleme==0){
if(!g->t_null_start_rule)goto SOFT_ERROR;
return r_create_null_bocage(r,b);
}
/*1090:*/
#line 10504 "./marpa.w"

{
if(rule_id==-1)
{
completed_start_rule= g->t_proper_start_rule;
if(!completed_start_rule)
return no_parse;
}
else
{
if(!RULEID_of_G_is_Valid(g,rule_id))
{
R_ERROR("invalid rule id");
return failure_indicator;
}
completed_start_rule= RULE_by_ID(g,rule_id);
}
MARPA_OFF_DEBUG2("ordinal=%d",ordinal);
}

/*:1090*/
#line 10418 "./marpa.w"

/*1096:*/
#line 10617 "./marpa.w"

{
gint eim_ix;
EIM*const earley_items= EIMs_of_ES(end_of_parse_earley_set);
const RULEID sought_rule_id= ID_of_RULE(completed_start_rule);
const gint earley_item_count= EIM_Count_of_ES(end_of_parse_earley_set);
for(eim_ix= 0;eim_ix<earley_item_count;eim_ix++){
const EIM earley_item= earley_items[eim_ix];
const AHFA ahfa_state= AHFA_of_EIM(earley_item);
if(Origin_Earleme_of_EIM(earley_item)> 0)continue;
if(!AHFA_is_Predicted(ahfa_state)){
gint aex;
AIM*const ahfa_items= AIMs_of_AHFA(ahfa_state);
const gint ahfa_item_count= AIM_Count_of_AHFA(ahfa_state);
for(aex= 0;aex<ahfa_item_count;aex++){
const AIM ahfa_item= ahfa_items[aex];
if(RULEID_of_AIM(ahfa_item)==sought_rule_id){
start_aim= ahfa_item;
start_eim= earley_item;
start_aex= aex;
break;
}
}
}
if(start_eim)break;
}
}

/*:1096*/
#line 10419 "./marpa.w"

if(!start_eim)goto SOFT_ERROR;
Phase_of_R(r)= evaluation_phase;
obstack_init(&bocage_setup_obs);
/*1093:*/
#line 10565 "./marpa.w"

{
guint ix;
guint earley_set_count= ES_Count_of_R(r);
total_earley_items_in_parse= 0;
per_es_data= 
obstack_alloc(&bocage_setup_obs,
sizeof(struct s_bocage_setup_per_es)*earley_set_count);
for(ix= 0;ix<earley_set_count;ix++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,ix);
const guint item_count= EIM_Count_of_ES(earley_set);
total_earley_items_in_parse+= item_count;
{
struct s_bocage_setup_per_es*per_es= per_es_data+ix;
OR**const per_eim_eixes= per_es->t_aexes_by_item= 
obstack_alloc(&bocage_setup_obs,sizeof(OR*)*item_count);
guint item_ordinal;
per_es->t_or_psl= NULL;
per_es->t_and_psl= NULL;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
per_eim_eixes[item_ordinal]= NULL;
}
}
}
}

/*:1093*/
#line 10423 "./marpa.w"

/*978:*/
#line 8958 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*979:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:979*/
#line 8967 "./marpa.w"

}
while((ur_node= ur_node_pop(ur_node_stack)))
{
const EIM_Const parent_earley_item= EIM_of_UR(ur_node);
const AEX parent_aex= AEX_of_UR(ur_node);
const AIM parent_aim= AIM_of_EIM_by_AEX(parent_earley_item,parent_aex);
MARPA_ASSERT(parent_aim>=AIM_by_ID(1))
const AIM predecessor_aim= parent_aim-1;


guint source_type= Source_Type_of_EIM(parent_earley_item);
MARPA_ASSERT(!EIM_is_Predicted(parent_earley_item))
/*982:*/
#line 9033 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
switch(source_type)
{
case SOURCE_IS_TOKEN:
predecessor_earley_item= Predecessor_of_EIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Token_Link_of_EIM(parent_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
for(;;)
{
if(predecessor_earley_item)
{
if(EIM_is_Predicted(predecessor_earley_item)){
/*983:*/
#line 9075 "./marpa.w"
{
if(Position_of_AIM(predecessor_aim)> 0){
const gint null_count= Null_Count_of_AIM(predecessor_aim);
if(null_count){
AEX predecessor_aex= AEX_of_EIM_by_AIM(predecessor_earley_item,
predecessor_aim);
or_node_estimate+= null_count;
psia_test_and_set(&bocage_setup_obs,per_es_data,
predecessor_earley_item,predecessor_aex);
}
}
}

/*:983*/
#line 9055 "./marpa.w"

}else{
const EIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
/*979:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:979*/
#line 9061 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:982*/
#line 8980 "./marpa.w"

/*984:*/
#line 9088 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
EIM cause_earley_item= NULL;
const SYMID transition_symbol_id= Postdot_SYMID_of_AIM(predecessor_aim);
switch(source_type)
{
case SOURCE_IS_COMPLETION:
predecessor_earley_item= Predecessor_of_EIM(parent_earley_item);
cause_earley_item= Cause_of_EIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Completion_Link_of_EIM(parent_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
while(cause_earley_item)
{
if(predecessor_earley_item)
{
if(EIM_is_Predicted(predecessor_earley_item))
{
/*983:*/
#line 9075 "./marpa.w"
{
if(Position_of_AIM(predecessor_aim)> 0){
const gint null_count= Null_Count_of_AIM(predecessor_aim);
if(null_count){
AEX predecessor_aex= AEX_of_EIM_by_AIM(predecessor_earley_item,
predecessor_aim);
or_node_estimate+= null_count;
psia_test_and_set(&bocage_setup_obs,per_es_data,
predecessor_earley_item,predecessor_aex);
}
}
}

/*:983*/
#line 9116 "./marpa.w"

}
else
{
const EIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
/*979:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:979*/
#line 9124 "./marpa.w"

}
}
{
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
const EIM ur_earley_item= cause_earley_item;
gint ix;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*979:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:979*/
#line 9137 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:984*/
#line 8981 "./marpa.w"

/*985:*/
#line 9147 "./marpa.w"

{
SRCL source_link= NULL;
EIM cause_earley_item= NULL;
LIM leo_predecessor= NULL;
switch(source_type)
{
case SOURCE_IS_LEO:
leo_predecessor= Predecessor_of_EIM(parent_earley_item);
cause_earley_item= Cause_of_EIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Leo_SRCL_of_EIM(parent_earley_item);
if(source_link)
{
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
while(cause_earley_item)
{
const SYMID transition_symbol_id= Postdot_SYMID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
gint ix;
EIM ur_earley_item= cause_earley_item;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*979:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:979*/
#line 9180 "./marpa.w"

}
while(leo_predecessor){
SYMID postdot= Postdot_SYMID_of_LIM(leo_predecessor);
EIM leo_base= Base_EIM_of_LIM(leo_predecessor);
TRANS transition= TRANS_of_EIM_by_SYMID(leo_base,postdot);
const AEX ur_aex= Leo_Base_AEX_of_TRANS(transition);
const AIM ur_aim= AIM_of_EIM_by_AEX(leo_base,ur_aex);
ur_earley_item= leo_base;


or_node_estimate+= 1+Null_Count_of_AIM(ur_aim+1);
if(EIM_is_Predicted(ur_earley_item))
{
const EIM predecessor_earley_item= ur_earley_item;
/*983:*/
#line 9075 "./marpa.w"
{
if(Position_of_AIM(predecessor_aim)> 0){
const gint null_count= Null_Count_of_AIM(predecessor_aim);
if(null_count){
AEX predecessor_aex= AEX_of_EIM_by_AIM(predecessor_earley_item,
predecessor_aim);
or_node_estimate+= null_count;
psia_test_and_set(&bocage_setup_obs,per_es_data,
predecessor_earley_item,predecessor_aex);
}
}
}

/*:983*/
#line 9195 "./marpa.w"

}else{
/*979:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:979*/
#line 9197 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:985*/
#line 8982 "./marpa.w"

}
}

/*:978*/
#line 10424 "./marpa.w"

/*1006:*/
#line 9375 "./marpa.w"

{
PSAR_Object or_per_es_arena;
const PSAR or_psar= &or_per_es_arena;
gint work_earley_set_ordinal;
OR last_or_node= NULL;
ORs_of_B(b)= g_new(OR,or_node_estimate);
psar_init(or_psar,SYMI_Count_of_G(g));
for(work_earley_set_ordinal= 0;
work_earley_set_ordinal<earley_set_count_of_r;
work_earley_set_ordinal++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,work_earley_set_ordinal);
EIM*const eims_of_es= EIMs_of_ES(earley_set);
const gint item_count= EIM_Count_of_ES(earley_set);
PSL this_earley_set_psl;
OR**const nodes_by_item= per_es_data[work_earley_set_ordinal].t_aexes_by_item;
psar_dealloc(or_psar);
#define PSL_ES_ORD work_earley_set_ordinal
#define CLAIMED_PSL this_earley_set_psl
/*1319:*/
#line 12898 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1319*/
#line 9395 "./marpa.w"

/*1007:*/
#line 9403 "./marpa.w"

{
gint item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const work_nodes_by_aex= nodes_by_item[item_ordinal];
if(work_nodes_by_aex){
const EIM work_earley_item= eims_of_es[item_ordinal];
const gint work_ahfa_item_count= AIM_Count_of_EIM(work_earley_item);
AEX work_aex;
const gint work_origin_ordinal= Ord_of_ES(Origin_of_EIM(work_earley_item));
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
if(!work_nodes_by_aex[work_aex])continue;
/*1008:*/
#line 9423 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1319:*/
#line 12898 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1319*/
#line 9433 "./marpa.w"

/*1010:*/
#line 9449 "./marpa.w"

{
MARPA_OFF_DEBUG3("%s ahfa_item_symbol_instance = %d",G_STRLOC,ahfa_item_symbol_instance);
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const RULE rule= RULE_of_AIM(ahfa_item);
/*1011:*/
#line 9479 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1011*/
#line 9460 "./marpa.w"

or_node= last_or_node;
PSL_Datum(or_psl,ahfa_item_symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= Origin_Ord_of_EIM(work_earley_item);
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= rule;
Position_of_OR(or_node)= 
ahfa_item_symbol_instance-SYMI_of_RULE(rule)+1;
DANDs_of_OR(or_node)= NULL;
}
psia_or_node= or_node;
}
}

/*:1010*/
#line 9434 "./marpa.w"

/*1013:*/
#line 9504 "./marpa.w"

{
const gint null_count= Null_Count_of_AIM(ahfa_item);
if(null_count> 0)
{
const RULE rule= RULE_of_AIM(ahfa_item);
const gint symbol_instance_of_rule= SYMI_of_RULE(rule);
const gint first_null_symbol_instance= 
ahfa_item_symbol_instance<0?symbol_instance_of_rule:ahfa_item_symbol_instance+1;
gint i;
for(i= 0;i<null_count;i++)
{
const gint symbol_instance= first_null_symbol_instance+i;
OR or_node= PSL_Datum(or_psl,symbol_instance);
MARPA_OFF_DEBUG3("adding nulling token or-node EIM = %s aex=%d",
eim_tag(work_earley_item),work_aex);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal){
DAND draft_and_node;
const gint rhs_ix= symbol_instance-SYMI_of_RULE(rule);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_ID_of_R(r,RHS_ID_of_RULE(rule,rhs_ix));
/*1011:*/
#line 9479 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1011*/
#line 9525 "./marpa.w"

or_node= PSL_Datum(or_psl,symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= work_origin_ordinal;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= rule;
MARPA_OFF_DEBUG3("Added rule %p to or-node %p",RULE_of_OR(or_node),or_node);
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
draft_and_node= DANDs_of_OR(or_node)= 
draft_and_node_new(&bocage_setup_obs,predecessor,
cause);
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,DANDs_of_OR(or_node));
Next_DAND_of_DAND(draft_and_node)= NULL;
}
psia_or_node= or_node;
}
}
}

/*:1013*/
#line 9435 "./marpa.w"

}


MARPA_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*1014:*/
#line 9545 "./marpa.w"
{
SRCL source_link= NULL;
EIM cause_earley_item= NULL;
LIM leo_predecessor= NULL;
switch(Source_Type_of_EIM(work_earley_item))
{
case SOURCE_IS_LEO:
leo_predecessor= Predecessor_of_EIM(work_earley_item);
cause_earley_item= Cause_of_EIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Leo_SRCL_of_EIM(work_earley_item);
if(source_link)
{
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
if(leo_predecessor){
for(;;){
/*1016:*/
#line 9585 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const gint ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const gint symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*1021:*/
#line 9630 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1319:*/
#line 12898 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1319*/
#line 9637 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*1011:*/
#line 9479 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1011*/
#line 9641 "./marpa.w"

PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= path_rule;
Position_of_OR(or_node)= 
symbol_instance_of_path_ahfa_item-SYMI_of_RULE(path_rule)+1;
MARPA_OFF_DEBUG3("Created or-node %s at %s",or_tag(or_node),G_STRLOC);
DANDs_of_OR(or_node)= NULL;
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,DANDs_of_OR(or_node));
}
}
}

/*:1021*/
#line 9595 "./marpa.w"

/*1022:*/
#line 9659 "./marpa.w"

{
gint i;
const gint null_count= Null_Count_of_AIM(path_ahfa_item);
for(i= 1;i<=null_count;i++)
{
const gint symbol_instance= symbol_instance_of_path_ahfa_item+i;
OR or_node= PSL_Datum(this_earley_set_psl,symbol_instance);
MARPA_ASSERT(symbol_instance<SYMI_Count_of_G(g))
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
DAND draft_and_node;
const gint rhs_ix= symbol_instance-SYMI_of_RULE(path_rule);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_ID_of_R(r,RHS_ID_of_RULE(path_rule,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_RULE(path_rule))
MARPA_ASSERT(symbol_instance>=0)
/*1011:*/
#line 9479 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1011*/
#line 9676 "./marpa.w"

PSL_Datum(this_earley_set_psl,symbol_instance)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= path_rule;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
DANDs_of_OR(or_node)= draft_and_node= 
draft_and_node_new(&bocage_setup_obs,predecessor,cause);
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,
DANDs_of_OR(or_node));
Next_DAND_of_DAND(draft_and_node)= NULL;
}
MARPA_ASSERT(Position_of_OR(or_node)<=
SYMI_of_RULE(path_rule)+Length_of_RULE(path_rule))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_RULE(path_rule))
}
}

/*:1022*/
#line 9596 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:1016*/
#line 9567 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:1014*/
#line 9441 "./marpa.w"

}

/*:1008*/
#line 9417 "./marpa.w"

}
}
}
}

/*:1007*/
#line 9396 "./marpa.w"

/*1031:*/
#line 9776 "./marpa.w"

{
gint item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const nodes_by_aex= nodes_by_item[item_ordinal];
if(nodes_by_aex){
const EIM work_earley_item= eims_of_es[item_ordinal];
const gint work_ahfa_item_count= AIM_Count_of_EIM(work_earley_item);
const gint work_origin_ordinal= Ord_of_ES(Origin_of_EIM(work_earley_item));
AEX work_aex;
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
OR or_node= nodes_by_aex[work_aex];
Move_OR_to_Proper_OR(or_node);
if(or_node){
/*1033:*/
#line 9813 "./marpa.w"

{
guint work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const gint work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*1034:*/
#line 9829 "./marpa.w"
{
SRCL source_link= NULL;
EIM cause_earley_item= NULL;
LIM leo_predecessor= NULL;
switch(Source_Type_of_EIM(work_earley_item))
{
case SOURCE_IS_LEO:
leo_predecessor= Predecessor_of_EIM(work_earley_item);
cause_earley_item= Cause_of_EIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Leo_SRCL_of_EIM(work_earley_item);
if(source_link)
{
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
if(leo_predecessor){
for(;;){
/*1035:*/
#line 9861 "./marpa.w"

{

RULE path_rule= NULL;

RULE previous_path_rule;
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);


OR dand_predecessor;
OR path_or_node;
EIM base_earley_item;
AEX base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*1036:*/
#line 9890 "./marpa.w"

{
if(higher_path_leo_item){
/*1040:*/
#line 9934 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:1040*/
#line 9893 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:1036*/
#line 9876 "./marpa.w"

/*1038:*/
#line 9904 "./marpa.w"

{
const SYMID transition_symbol_id= Postdot_SYMID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
gint ix;
for(ix= 0;ix<aex_count;ix++)
{
const AEX cause_aex= aexes[ix];
OR dand_cause;
Set_OR_from_EIM_and_AEX(dand_cause,cause_earley_item,cause_aex);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:1038*/
#line 9877 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*1036:*/
#line 9890 "./marpa.w"

{
if(higher_path_leo_item){
/*1040:*/
#line 9934 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:1040*/
#line 9893 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:1036*/
#line 9884 "./marpa.w"

/*1041:*/
#line 9944 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const gint origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:1041*/
#line 9885 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:1035*/
#line 9851 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:1034*/
#line 9824 "./marpa.w"

/*1042:*/
#line 9954 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
TOK token= NULL;
switch(work_source_type)
{
case SOURCE_IS_TOKEN:
predecessor_earley_item= Predecessor_of_EIM(work_earley_item);
token= TOK_of_EIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Token_Link_of_EIM(work_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
while(token)
{
/*1043:*/
#line 9984 "./marpa.w"

{
OR dand_predecessor;
/*1044:*/
#line 9992 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1044*/
#line 9987 "./marpa.w"

draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:1043*/
#line 9976 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1042*/
#line 9825 "./marpa.w"

/*1045:*/
#line 10003 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
EIM cause_earley_item= NULL;
const SYMID transition_symbol_id= Postdot_SYMID_of_AIM(work_predecessor_aim);
switch(work_source_type)
{
case SOURCE_IS_COMPLETION:
predecessor_earley_item= Predecessor_of_EIM(work_earley_item);
cause_earley_item= Cause_of_EIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Completion_Link_of_EIM(work_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
while(cause_earley_item)
{
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
gint ix;
for(ix= 0;ix<aex_count;ix++){
const AEX cause_aex= aexes[ix];
/*1046:*/
#line 10043 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const gint middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*1044:*/
#line 9992 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1044*/
#line 10051 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:1046*/
#line 10034 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1045*/
#line 9826 "./marpa.w"

}

/*:1033*/
#line 9791 "./marpa.w"

}
}
}
}
}

/*:1031*/
#line 9397 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= g_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:1006*/
#line 10425 "./marpa.w"

/*1054:*/
#line 10157 "./marpa.w"

{
gint unique_draft_and_node_count= 0;
/*1047:*/
#line 10057 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const gint or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
gint or_node_id= 0;
psar_init(and_psar,rule_count_of_g+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*1049:*/
#line 10089 "./marpa.w"

{
DAND dand= DANDs_of_OR(work_or_node);
DAND next_dand= Next_DAND_of_DAND(dand);
ORID work_or_node_id= ID_of_OR(work_or_node);

if(next_dand)
{
gint origin_ordinal= Origin_Ord_of_OR(work_or_node);
psar_dealloc(and_psar);
while(dand)
{
OR psl_or_node;
OR predecessor= Predecessor_OR_of_DAND(dand);
WHEID wheid= WHEID_of_OR(Cause_OR_of_DAND(dand));
const gint middle_ordinal= 
predecessor?ES_Ord_of_OR(predecessor):origin_ordinal;
PSL and_psl;
PSL*psl_owner= &per_es_data[middle_ordinal].t_and_psl;

if(!*psl_owner)psl_claim(psl_owner,and_psar);
and_psl= *psl_owner;
psl_or_node= PSL_Datum(and_psl,wheid);
if(psl_or_node&&ID_of_OR(psl_or_node)==work_or_node_id)
{

Cause_OR_of_DAND(dand)= NULL;
}else{

PSL_Datum(and_psl,wheid)= work_or_node;
unique_draft_and_node_count++;
}
dand= Next_DAND_of_DAND(dand);
}
}else{
unique_draft_and_node_count++;
}
}

/*:1049*/
#line 10067 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:1047*/
#line 10160 "./marpa.w"

/*1055:*/
#line 10164 "./marpa.w"

{
const gint or_count_of_b= OR_Count_of_B(b);
gint or_node_id;
gint and_node_id= 0;
const OR*ors_of_b= ORs_of_B(b);
const AND ands_of_b= ANDs_of_B(b)= 
g_new(AND_Object,unique_draft_and_node_count);
for(or_node_id= 0;or_node_id<or_count_of_b;or_node_id++)
{
gint and_count_of_parent_or= 0;
const OR or_node= ors_of_b[or_node_id];
DAND dand= DANDs_of_OR(or_node);
First_ANDID_of_OR(or_node)= and_node_id;
while(dand)
{
const OR cause_or_node= Cause_OR_of_DAND(dand);
if(cause_or_node)
{

const AND and_node= ands_of_b+and_node_id;
OR_of_AND(and_node)= or_node;
Predecessor_OR_of_AND(and_node)= 
Predecessor_OR_of_DAND(dand);
Cause_OR_of_AND(and_node)= cause_or_node;
and_node_id++;
and_count_of_parent_or++;
}
dand= Next_DAND_of_DAND(dand);
}
AND_Count_of_OR(or_node)= and_count_of_parent_or;
}
AND_Count_of_B(b)= and_node_id;
MARPA_ASSERT(and_node_id==unique_draft_and_node_count);
}

/*:1055*/
#line 10161 "./marpa.w"

}

/*:1054*/
#line 10426 "./marpa.w"

/*1097:*/
#line 10645 "./marpa.w"
{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const gint start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
top_or_node_id= ID_of_OR(top_or_node);
}

/*:1097*/
#line 10427 "./marpa.w"

obstack_free(&bocage_setup_obs,NULL);
Top_ORID_of_B(b)= top_or_node_id;
return top_or_node_id;
SOFT_ERROR:;
/*1098:*/
#line 10655 "./marpa.w"

/*1005:*/
#line 9358 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
if(or_nodes)
{
g_free(or_nodes);
ORs_of_B(b)= NULL;
}
if(and_nodes)
{
g_free(and_nodes);
ANDs_of_B(b)= NULL;
}
}

/*:1005*//*1151:*/
#line 11224 "./marpa.w"

rank_destroy(RANK_of_B(b));
/*:1151*/
#line 10656 "./marpa.w"
;
/*1080:*/
#line 10379 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:1080*/
#line 10657 "./marpa.w"
;

/*:1098*/
#line 10432 "./marpa.w"
;
return no_parse;
}

/*:1083*//*1092:*/
#line 10531 "./marpa.w"

static ORID r_create_null_bocage(RECCE r,BOC b)
{
const GRAMMAR g= G_of_R(r);
const RULE null_start_rule= g->t_null_start_rule;
gint rule_length= Length_of_RULE(g->t_null_start_rule);
OR*or_nodes= ORs_of_B(b)= g_new(OR,1);
AND and_nodes= ANDs_of_B(b)= g_new(AND_Object,1);
OR or_node= or_nodes[0]= 
(OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ORID null_or_node_id= 0;
Top_ORID_of_B(b)= null_or_node_id;

OR_Count_of_B(b)= 1;
AND_Count_of_B(b)= 1;

RULE_of_OR(or_node)= null_start_rule;
Position_of_OR(or_node)= rule_length;
Origin_Ord_of_OR(or_node)= 0;
ID_of_OR(or_node)= null_or_node_id;
ES_Ord_of_OR(or_node)= 0;
First_ANDID_of_OR(or_node)= 0;
AND_Count_of_OR(or_node)= 1;

OR_of_AND(and_nodes)= or_node;
Predecessor_OR_of_AND(and_nodes)= NULL;
Cause_OR_of_AND(and_nodes)= 
(OR)TOK_by_ID_of_R(r,
RHS_ID_of_RULE(null_start_rule,rule_length-1));

return null_or_node_id;
}

/*:1092*//*1101:*/
#line 10667 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r){
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10669 "./marpa.w"

struct marpa_g*g= G_of_R(r);
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10671 "./marpa.w"

if(Phase_of_R(r)==evaluation_phase){

Phase_of_R(r)= input_phase;
}
bocage_destroy(r);
return 1;
}

/*:1101*//*1103:*/
#line 10682 "./marpa.w"

static inline void bocage_destroy(struct marpa_r*r)
{
BOC b= B_of_R(r);
MARPA_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
if(b){
/*1098:*/
#line 10655 "./marpa.w"

/*1005:*/
#line 9358 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
if(or_nodes)
{
g_free(or_nodes);
ORs_of_B(b)= NULL;
}
if(and_nodes)
{
g_free(and_nodes);
ANDs_of_B(b)= NULL;
}
}

/*:1005*//*1151:*/
#line 11224 "./marpa.w"

rank_destroy(RANK_of_B(b));
/*:1151*/
#line 10656 "./marpa.w"
;
/*1080:*/
#line 10379 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:1080*/
#line 10657 "./marpa.w"
;

/*:1098*/
#line 10688 "./marpa.w"
;
g_slice_free(BOC_Object,b);
B_of_R(r)= NULL;
}
MARPA_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
}

/*:1103*//*1107:*/
#line 10725 "./marpa.w"

gint marpa_or_node_set(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10729 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1105:*/
#line 10698 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10701 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1105*/
#line 10731 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:1107*//*1109:*/
#line 10737 "./marpa.w"

gint marpa_or_node_origin(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10741 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1105:*/
#line 10698 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10701 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1105*/
#line 10743 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:1109*//*1111:*/
#line 10749 "./marpa.w"

gint marpa_or_node_rule(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10753 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1105:*/
#line 10698 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10701 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1105*/
#line 10755 "./marpa.w"

return ID_of_RULE(RULE_of_OR(or_node));
}

/*:1111*//*1113:*/
#line 10761 "./marpa.w"

gint marpa_or_node_position(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10765 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1105:*/
#line 10698 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10701 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1105*/
#line 10767 "./marpa.w"

return Position_of_OR(or_node);
}

/*:1113*//*1115:*/
#line 10773 "./marpa.w"

gint marpa_or_node_first_and(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10777 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1105:*/
#line 10698 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10701 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1105*/
#line 10779 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:1115*//*1117:*/
#line 10785 "./marpa.w"

gint marpa_or_node_last_and(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10789 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1105:*/
#line 10698 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10701 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1105*/
#line 10791 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:1117*//*1119:*/
#line 10798 "./marpa.w"

gint marpa_or_node_and_count(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10802 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1105:*/
#line 10698 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10701 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1105*/
#line 10804 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:1119*//*1123:*/
#line 10850 "./marpa.w"

static inline void tree_exhaust(TREE tree)
{
if(FSTACK_IS_INITIALIZED(tree->t_fork_stack))
{
FSTACK_DESTROY(tree->t_fork_stack);
FSTACK_SAFE(tree->t_fork_stack);
}
if(FSTACK_IS_INITIALIZED(tree->t_fork_worklist))
{
FSTACK_DESTROY(tree->t_fork_worklist);
FSTACK_SAFE(tree->t_fork_worklist);
}
if(tree->t_and_node_in_use){
bv_free(tree->t_and_node_in_use);
tree->t_and_node_in_use= NULL;
}
}

/*:1123*//*1125:*/
#line 10871 "./marpa.w"

static inline void tree_safe(TREE tree)
{
FSTACK_SAFE(tree->t_fork_stack);
FSTACK_SAFE(tree->t_fork_worklist);
tree->t_and_node_in_use= NULL;
tree->t_parse_count= -1;
val_safe(VAL_of_TREE(tree));
}

/*:1125*//*1127:*/
#line 10886 "./marpa.w"

int marpa_tree_new(struct marpa_r*r)
{
BOC b;
TREE tree;
gint first_tree_of_series= 0;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 10892 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10894 "./marpa.w"

/*1138:*/
#line 11116 "./marpa.w"

{
b= B_of_R(r);
if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
}

/*:1138*/
#line 10895 "./marpa.w"

tree= TREE_of_RANK(RANK_of_B(b));
if(TREE_is_Exhausted(tree)){
return-1;
}
val_destroy(VAL_of_TREE(tree));
if(!TREE_is_Initialized(tree))
{
first_tree_of_series= 1;
/*1132:*/
#line 10954 "./marpa.w"

{
ORID top_or_id= Top_ORID_of_B(b);
OR top_or_node= OR_of_B_by_ID(b,top_or_id);
FORK fork;
gint choice;
const gint and_count= AND_Count_of_B(b);
tree->t_parse_count= 0;
tree->t_and_node_in_use= bv_create((guint)and_count);
FSTACK_INIT(tree->t_fork_stack,FORK_Object,and_count);
FSTACK_INIT(tree->t_fork_worklist,gint,and_count);
choice= or_node_next_choice(b,tree,top_or_node,0);


if(choice<0)goto TREE_IS_EXHAUSTED;
fork= FSTACK_PUSH(tree->t_fork_stack);
OR_of_FORK(fork)= top_or_node;
Choice_of_FORK(fork)= choice;
Parent_of_FORK(fork)= -1;
FORK_Cause_is_Ready(fork)= 0;
FORK_is_Cause(fork)= 0;
FORK_Predecessor_is_Ready(fork)= 0;
FORK_is_Predecessor(fork)= 0;
*(FSTACK_PUSH(tree->t_fork_worklist))= 0;
}

/*:1132*/
#line 10906 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(!first_tree_of_series){
/*1133:*/
#line 10983 "./marpa.w"
{
while(1){
FORK iteration_candidate= FSTACK_TOP(tree->t_fork_stack,FORK_Object);
gint choice;
if(!iteration_candidate)break;
choice= Choice_of_FORK(iteration_candidate);
MARPA_ASSERT(choice>=0);
{
OR or_node= OR_of_FORK(iteration_candidate);
ANDID and_node_id= and_order_get(b,or_node,choice);
tree_and_node_release(tree,and_node_id);
choice= or_node_next_choice(b,tree,or_node,choice+1);
}
if(choice>=0){





Choice_of_FORK(iteration_candidate)= choice;
FORK_Cause_is_Ready(iteration_candidate)= 0;
FORK_Predecessor_is_Ready(iteration_candidate)= 0;
break;
}
{

const gint parent_fork_ix= Parent_of_FORK(iteration_candidate);
if(parent_fork_ix>=0){
FORK parent_fork= FORK_of_TREE_by_IX(tree,parent_fork_ix);
if(FORK_is_Cause(iteration_candidate)){
FORK_Cause_is_Ready(parent_fork)= 0;
}
if(FORK_is_Predecessor(iteration_candidate)){
FORK_Predecessor_is_Ready(parent_fork)= 0;
}
}


FSTACK_POP(tree->t_fork_stack);
}
}
{
gint stack_length= FSTACK_LENGTH(tree->t_fork_stack);
gint i;
if(stack_length<=0)goto TREE_IS_EXHAUSTED;
FSTACK_CLEAR(tree->t_fork_worklist);
for(i= 0;i<stack_length;i++){
*(FSTACK_PUSH(tree->t_fork_worklist))= i;
}
}
}

/*:1133*/
#line 10911 "./marpa.w"

}
first_tree_of_series= 0;
/*1134:*/
#line 11035 "./marpa.w"
{
while(1){
FORKID*p_work_fork_id;
FORK work_fork;
ANDID work_and_node_id;
AND work_and_node;
OR work_or_node;
OR child_or_node= NULL;
gint choice;
gint child_is_cause= 0;
gint child_is_predecessor= 0;
p_work_fork_id= FSTACK_TOP(tree->t_fork_worklist,FORKID);
if(!p_work_fork_id){
goto TREE_IS_FINISHED;
}
work_fork= FORK_of_TREE_by_IX(tree,*p_work_fork_id);
work_or_node= OR_of_FORK(work_fork);
work_and_node_id= and_order_get(b,work_or_node,Choice_of_FORK(work_fork));
work_and_node= ands_of_b+work_and_node_id;
if(!FORK_Cause_is_Ready(work_fork)){
child_or_node= Cause_OR_of_AND(work_and_node);
if(child_or_node&&OR_is_Token(child_or_node))child_or_node= NULL;
if(child_or_node){
child_is_cause= 1;
}else{
FORK_Cause_is_Ready(work_fork)= 1;
}
}
if(!child_or_node&&!FORK_Predecessor_is_Ready(work_fork)){
child_or_node= Predecessor_OR_of_AND(work_and_node);
if(child_or_node){
child_is_predecessor= 1;
}else{
FORK_Predecessor_is_Ready(work_fork)= 1;
}
}
if(!child_or_node){
FSTACK_POP(tree->t_fork_worklist);
goto NEXT_FORK_ON_WORKLIST;
}
choice= or_node_next_choice(b,tree,child_or_node,0);
if(choice<0)goto NEXT_TREE;
/*1137:*/
#line 11098 "./marpa.w"

{
FORKID new_fork_id= FSTACK_LENGTH(tree->t_fork_stack);
FORK new_fork= FSTACK_PUSH(tree->t_fork_stack);
*(FSTACK_PUSH(tree->t_fork_worklist))= new_fork_id;
Parent_of_FORK(new_fork)= *p_work_fork_id;
Choice_of_FORK(new_fork)= choice;
OR_of_FORK(new_fork)= child_or_node;
FORK_Cause_is_Ready(new_fork)= 0;
if((FORK_is_Cause(new_fork)= child_is_cause)){
FORK_Cause_is_Ready(work_fork)= 1;
}
FORK_Predecessor_is_Ready(new_fork)= 0;
if((FORK_is_Predecessor(new_fork)= child_is_predecessor)){
FORK_Predecessor_is_Ready(work_fork)= 1;
}
}

/*:1137*/
#line 11077 "./marpa.w"
;
NEXT_FORK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1134*/
#line 10914 "./marpa.w"

}
TREE_IS_FINISHED:;
tree->t_parse_count++;
return FSTACK_LENGTH(tree->t_fork_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(tree);
return-1;
}

/*:1127*//*1129:*/
#line 10933 "./marpa.w"

static inline void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1129*//*1130:*/
#line 10939 "./marpa.w"

static inline void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1130*//*1131:*/
#line 10947 "./marpa.w"

static inline gint tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(guint)and_node_id);
}

/*:1131*//*1136:*/
#line 11085 "./marpa.w"

static inline gint or_node_next_choice(BOC b,TREE tree,OR or_node,gint start_choice)
{
gint choice= start_choice;
while(1){
ANDID and_node_id= and_order_get(b,or_node,choice);
if(and_node_id<0)return-1;
if(tree_and_node_try(tree,and_node_id))return choice;
choice++;
}
return-1;
}

/*:1136*//*1140:*/
#line 11127 "./marpa.w"

static inline void tree_destroy(TREE tree)
{
tree_exhaust(tree);
tree->t_parse_count= -1;
MARPA_DEBUG4("%s tree=%p parse_count=%d",G_STRLOC,tree,tree->t_parse_count);
}

/*:1140*//*1142:*/
#line 11139 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r)
{
BOC b;
TREE tree;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11144 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11146 "./marpa.w"

b= B_of_R(r);
if(!b){
return-1;
}
tree= TREE_of_RANK(RANK_of_B(b));
MARPA_DEBUG3("%s b=%p",G_STRLOC,b);
MARPA_DEBUG4("%s tree=%p parse_count=%d",G_STRLOC,tree,tree->t_parse_count);
return tree->t_parse_count;
}

/*:1142*//*1144:*/
#line 11164 "./marpa.w"

gint marpa_tree_size(struct marpa_r*r)
{
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11167 "./marpa.w"

BOC b= B_of_R(r);
TREE tree;
GRAMMAR g= G_of_R(r);
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11171 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
return-1;
}
return FSTACK_LENGTH(tree->t_fork_stack);
}

/*:1144*//*1150:*/
#line 11216 "./marpa.w"

static inline void rank_safe(RANK rank)
{
rank->t_and_node_in_use= NULL;
rank->t_and_node_orderings= NULL;
tree_safe(TREE_of_RANK(rank));
}

/*:1150*//*1153:*/
#line 11229 "./marpa.w"

static inline void rank_freeze(RANK rank)
{
if(rank->t_and_node_in_use)
{
bv_free(rank->t_and_node_in_use);
rank->t_and_node_in_use= NULL;
}
}
static inline void rank_destroy(RANK rank)
{
tree_destroy(TREE_of_RANK(rank));
rank_freeze(rank);
if(rank->t_and_node_orderings){
rank->t_and_node_orderings= NULL;
obstack_free(&OBS_of_RANK(rank),NULL);
}
}

/*:1153*//*1158:*/
#line 11305 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length)
{
OR or_node;
RANK rank;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11313 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1105:*/
#line 10698 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10701 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1105*/
#line 11315 "./marpa.w"

{BOC b= B_of_R(r);
ANDID**and_node_orderings;
Bit_Vector and_node_in_use;
struct obstack*obs;
ANDID first_and_node_id;
ANDID and_count_of_or;
if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
rank= RANK_of_B(b);
and_node_orderings= rank->t_and_node_orderings;
and_node_in_use= rank->t_and_node_in_use;
obs= &OBS_of_RANK(rank);
if(and_node_orderings&&!and_node_in_use)
{
R_ERROR("ranker frozen");
return failure_indicator;
}
if(!and_node_orderings)
{
gint and_id;
const gint and_count_of_r= AND_Count_of_B(b);
obstack_init(obs);
rank->t_and_node_orderings= 
and_node_orderings= 
obstack_alloc(obs,sizeof(ANDID*)*and_count_of_r);
for(and_id= 0;and_id<and_count_of_r;and_id++)
{
and_node_orderings[and_id]= (ANDID*)NULL;
}
rank->t_and_node_in_use= 
and_node_in_use= bv_create((guint)and_count_of_r);
}
first_and_node_id= First_ANDID_of_OR(or_node);
and_count_of_or= AND_Count_of_OR(or_node);
{
gint and_ix;
for(and_ix= 0;and_ix<length;and_ix++)
{
ANDID and_node_id= and_node_ids[and_ix];
if(and_node_id<first_and_node_id||
and_node_id-first_and_node_id>=and_count_of_or){
R_ERROR("and node not in or node");
return failure_indicator;
}
if(bv_bit_test(and_node_in_use,(guint)and_node_id))
{
R_ERROR("dup and node");
return failure_indicator;
}
bv_bit_set(and_node_in_use,(guint)and_node_id);
}
}
if(and_node_orderings[or_node_id]){
R_ERROR("or node already ordered");
return failure_indicator;
}
{
ANDID*orderings= obstack_alloc(obs,sizeof(ANDID)*(length+1));
gint i;
and_node_orderings[or_node_id]= orderings;
*orderings++= length;
for(i= 0;i<length;i++)
{
*orderings++= and_node_ids[i];
}
}
}
return 1;
}

/*:1158*//*1162:*/
#line 11393 "./marpa.w"

static inline ANDID and_order_get(BOC b,OR or_node,gint ix)
{
RANK rank;
ANDID**and_node_orderings;
if(ix>=AND_Count_of_OR(or_node))
{
return-1;
}
rank= RANK_of_B(b);
and_node_orderings= rank->t_and_node_orderings;
if(and_node_orderings)
{
ORID or_node_id= ID_of_OR(or_node);
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)
{
gint length= ordering[0];
if(ix>=length)
return-1;
return ordering[1+ix];
}
}
return First_ANDID_of_OR(or_node)+ix;
}

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix)
{
OR or_node;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11422 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1105:*/
#line 10698 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 10701 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1105*/
#line 11424 "./marpa.w"

if(ix<0){
R_ERROR("negative and ix");
return failure_indicator;
}
{
BOC b= B_of_R(r);
if(!b)
{
R_ERROR("no bocage");
return failure_indicator;
}
return and_order_get(b,or_node,ix);
}
}

/*:1162*//*1170:*/
#line 11514 "./marpa.w"

gint marpa_fork_or_node(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11518 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1168:*/
#line 11482 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11486 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1168*/
#line 11520 "./marpa.w"

return ID_of_OR(OR_of_FORK(fork));
}

/*:1170*//*1172:*/
#line 11527 "./marpa.w"

gint marpa_fork_choice(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11531 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1168:*/
#line 11482 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11486 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1168*/
#line 11533 "./marpa.w"

return Choice_of_FORK(fork);
}

/*:1172*//*1174:*/
#line 11548 "./marpa.w"

gint marpa_fork_parent(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11552 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1168:*/
#line 11482 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11486 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1168*/
#line 11554 "./marpa.w"

return Parent_of_FORK(fork);
}

/*:1174*//*1176:*/
#line 11561 "./marpa.w"

gint marpa_fork_cause_is_ready(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11565 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1168:*/
#line 11482 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11486 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1168*/
#line 11567 "./marpa.w"

return FORK_Cause_is_Ready(fork);
}

/*:1176*//*1178:*/
#line 11574 "./marpa.w"

gint marpa_fork_predecessor_is_ready(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11578 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1168:*/
#line 11482 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11486 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1168*/
#line 11580 "./marpa.w"

return FORK_Predecessor_is_Ready(fork);
}

/*:1178*//*1180:*/
#line 11587 "./marpa.w"

gint marpa_fork_is_cause(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11591 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1168:*/
#line 11482 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11486 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1168*/
#line 11593 "./marpa.w"

return FORK_is_Cause(fork);
}

/*:1180*//*1182:*/
#line 11600 "./marpa.w"

gint marpa_fork_is_predecessor(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11604 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1168:*/
#line 11482 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11486 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1168*/
#line 11606 "./marpa.w"

return FORK_is_Predecessor(fork);
}

/*:1182*//*1189:*/
#line 11674 "./marpa.w"

static inline void val_safe(VAL val)
{
DSTACK_SAFE(val->t_virtual_stack);
VAL_is_Active(val)= 0;
VAL_is_Trace(val)= 0;
TOS_of_VAL(val)= -1;
FORK_of_VAL(val)= -1;
}

/*:1189*//*1193:*/
#line 11725 "./marpa.w"

int marpa_val_new(struct marpa_r*r)
{
BOC b;
TREE tree;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11730 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11732 "./marpa.w"

/*1138:*/
#line 11116 "./marpa.w"

{
b= B_of_R(r);
if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
}

/*:1138*/
#line 11733 "./marpa.w"

tree= TREE_of_RANK(RANK_of_B(b));
if(TREE_is_Exhausted(tree)){
return-1;
}
if(!TREE_is_Initialized(tree))
{
R_ERROR("tree not initialized");
return failure_indicator;
}
{
VAL val= VAL_of_TREE(tree);
const gint minimum_stack_size= (8192/sizeof(gint));
const gint initial_stack_size= 
MAX(Size_of_TREE(tree)/1024,minimum_stack_size);
val_destroy(val);
DSTACK_INIT(VStack_of_VAL(val),gint,initial_stack_size);
VAL_is_Active(val)= 1;
}
return 1;
}

/*:1193*//*1195:*/
#line 11757 "./marpa.w"

static inline void val_destroy(VAL val)
{

if(DSTACK_IS_INITIALIZED(val->t_virtual_stack))
{
DSTACK_DESTROY(val->t_virtual_stack);
DSTACK_SAFE(val->t_virtual_stack);
}
val_safe(val);
}

/*:1195*//*1198:*/
#line 11785 "./marpa.w"

gint marpa_val_trace(struct marpa_r*r,gint flag)
{
BOC b;
TREE tree;
VAL val;
GRAMMAR g= G_of_R(r);
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11792 "./marpa.w"

/*1196:*/
#line 11770 "./marpa.w"
{
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11771 "./marpa.w"

b= B_of_R(r);
if(!b){
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
val= VAL_of_TREE(tree);
if(!VAL_is_Active(val)){
return failure_indicator;
}
}

/*:1196*/
#line 11793 "./marpa.w"

VAL_is_Trace(val)= flag;
return 1;
}

/*:1198*//*1200:*/
#line 11800 "./marpa.w"

Marpa_Fork_ID marpa_val_fork(struct marpa_r*r)
{
BOC b;
TREE tree;
VAL val;
/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11806 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1196:*/
#line 11770 "./marpa.w"
{
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11771 "./marpa.w"

b= B_of_R(r);
if(!b){
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
val= VAL_of_TREE(tree);
if(!VAL_is_Active(val)){
return failure_indicator;
}
}

/*:1196*/
#line 11808 "./marpa.w"

return FORK_of_VAL(val);
}

/*:1200*//*1202:*/
#line 11814 "./marpa.w"

Marpa_Fork_ID marpa_val_event(struct marpa_r*r,Marpa_Event*event)
{
BOC b;
TREE tree;
VAL val;
AND and_nodes;
gint semantic_rule_id= -1;
gint token_id= -1;
gpointer token_value= NULL;
gint arg_0= -1;
gint arg_n= -1;
FORKID fork_ix;
gint continue_with_next_fork;
GRAMMAR g= G_of_R(r);


/*1338:*/
#line 13068 "./marpa.w"
const int failure_indicator= -2;

/*:1338*/
#line 11831 "./marpa.w"

/*1196:*/
#line 11770 "./marpa.w"
{
/*1352:*/
#line 13149 "./marpa.w"

if(g->t_fatal_error){
MARPA_ERROR(g->t_fatal_error);
return failure_indicator;
}

/*:1352*/
#line 11771 "./marpa.w"

b= B_of_R(r);
if(!b){
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
val= VAL_of_TREE(tree);
if(!VAL_is_Active(val)){
return failure_indicator;
}
}

/*:1196*/
#line 11832 "./marpa.w"

and_nodes= ANDs_of_B(b);

arg_0= arg_n= TOS_of_VAL(val);
fork_ix= FORK_of_VAL(val);
if(fork_ix<0){
fork_ix= Size_of_TREE(tree);
}
continue_with_next_fork= !VAL_is_Trace(val);

while(1){
OR or;
RULE fork_rule;
fork_ix--;
if(fork_ix<0)goto RETURN_SOFT_ERROR;
{
ANDID and_node_id;
AND and_node;
const FORK fork= FORK_of_TREE_by_IX(tree,fork_ix);
const gint choice= Choice_of_FORK(fork);
or= OR_of_FORK(fork);
and_node_id= and_order_get(b,or,choice);
and_node= and_nodes+and_node_id;
token_id= and_node_token(and_node,&token_value);
}
if(token_id>=0){
arg_0= ++arg_n;
continue_with_next_fork= 0;
}
fork_rule= RULE_of_OR(or);
if(Position_of_OR(or)==Length_of_RULE(fork_rule)){
gint virtual_rhs= RULE_is_Virtual_RHS(fork_rule);
gint virtual_lhs= RULE_is_Virtual_LHS(fork_rule);
gint real_symbol_count;
const DSTACK virtual_stack= &VStack_of_VAL(val);
if(virtual_lhs){
real_symbol_count= Real_SYM_Count_of_RULE(fork_rule);
if(virtual_rhs){
*(DSTACK_TOP(*virtual_stack,gint))+= real_symbol_count;
}else{
*DSTACK_PUSH(*virtual_stack,gint)= real_symbol_count;
}
goto NEXT_FORK;
}
if(virtual_rhs){
real_symbol_count= Real_SYM_Count_of_RULE(fork_rule);
real_symbol_count+= *DSTACK_POP(*virtual_stack,gint);
}else{
real_symbol_count= Length_of_RULE(fork_rule);
}
arg_0= arg_n-real_symbol_count+1;
semantic_rule_id= 
fork_rule->t_is_semantic_equivalent?
fork_rule->t_original:ID_of_RULE(fork_rule);
continue_with_next_fork= 0;
}
NEXT_FORK:;
if(!continue_with_next_fork)break;
}

/*1203:*/
#line 11901 "./marpa.w"

{
SYMID_of_EVE(event)= token_id;
Value_of_EVE(event)= token_value;
RULEID_of_EVE(event)= semantic_rule_id;
TOS_of_VAL(val)= Arg0_of_EVE(event)= arg_0;
FORK_of_VAL(val)= fork_ix;
ArgN_of_EVE(event)= arg_n;
}

/*:1203*/
#line 11892 "./marpa.w"

return FORK_of_VAL(val);

RETURN_SOFT_ERROR:;
/*1203:*/
#line 11901 "./marpa.w"

{
SYMID_of_EVE(event)= token_id;
Value_of_EVE(event)= token_value;
RULEID_of_EVE(event)= semantic_rule_id;
TOS_of_VAL(val)= Arg0_of_EVE(event)= arg_0;
FORK_of_VAL(val)= fork_ix;
ArgN_of_EVE(event)= arg_n;
}

/*:1203*/
#line 11896 "./marpa.w"

return-1;

}

/*:1202*//*1206:*/
#line 11935 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1206*//*1208:*/
#line 11943 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:1208*//*1211:*/
#line 11961 "./marpa.w"

static inline Bit_Vector bv_create(guint bits)
{
guint size= bv_bits_to_size(bits);
guint bytes= (size+bv_hiddenwords)<<sizeof(guint);
guint*addr= (Bit_Vector)g_malloc0((size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}

/*:1211*//*1213:*/
#line 11981 "./marpa.w"

static inline Bit_Vector
bv_obs_create(struct obstack*obs,guint bits)
{
guint size= bv_bits_to_size(bits);
guint bytes= (size+bv_hiddenwords)<<sizeof(guint);
guint*addr= (Bit_Vector)obstack_alloc(obs,(size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
if(size> 0){
Bit_Vector bv= addr;
while(size--)*bv++= 0u;
}
return addr;
}


/*:1213*//*1214:*/
#line 12002 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:1214*//*1216:*/
#line 12014 "./marpa.w"
static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from)
{
guint*p_to= bv_to;
const guint bits= BV_BITS(bv_to);
if(bits> 0)
{
gint count= BV_SIZE(bv_to);
while(count--)*p_to++= *bv_from++;
}
return(bv_to);
}
/*:1216*//*1218:*/
#line 12034 "./marpa.w"
static inline
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}
/*:1218*//*1220:*/
#line 12044 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:1220*//*1222:*/
#line 12053 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:1222*//*1224:*/
#line 12061 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:1224*//*1228:*/
#line 12076 "./marpa.w"

static inline void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1228*//*1230:*/
#line 12092 "./marpa.w"

static inline void bv_over_clear(Bit_Vector bv,guint bit)
{
guint length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1230*//*1232:*/
#line 12100 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:1232*//*1234:*/
#line 12108 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:1234*//*1236:*/
#line 12116 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:1236*//*1240:*/
#line 12127 "./marpa.w"

static inline gboolean
bv_bit_test_and_set(Bit_Vector vector,guint bit)
{
Bit_Vector addr= vector+(bit/bv_wordbits);
guint mask= bv_lsb<<(bit%bv_wordbits);
if((*addr&mask)!=0u)
return 1;
*addr|= mask;
return 0;
}

/*:1240*//*1241:*/
#line 12140 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr)
{
guint size= BV_SIZE(addr);
gboolean r= TRUE;
if(size> 0){
*(addr+size-1)&= BV_MASK(addr);
while(r&&(size--> 0))r= (*addr++==0);
}
return(r);
}
/*:1241*//*1243:*/
#line 12157 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:1243*//*1245:*/
#line 12169 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:1245*//*1247:*/
#line 12181 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:1247*//*1249:*/
#line 12193 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:1249*//*1251:*/
#line 12205 "./marpa.w"

static inline
gboolean bv_scan(Bit_Vector bv,guint start,
guint*min,guint*max)
{
guint size= BV_SIZE(bv);
guint mask= BV_MASK(bv);
guint offset;
guint bitmask;
guint value;
gboolean empty;

if(size==0)return FALSE;
if(start>=BV_BITS(bv))return FALSE;
*min= start;
*max= start;
offset= start/bv_wordbits;
*(bv+size-1)&= mask;
bv+= offset;
size-= offset;
bitmask= (guint)1<<(start&bv_modmask);
mask= ~(bitmask|(bitmask-(guint)1));
value= *bv++;
if((value&bitmask)==0)
{
value&= mask;
if(value==0)
{
offset++;
empty= TRUE;
while(empty&&(--size> 0))
{
if((value= *bv++))empty= FALSE;else offset++;
}
if(empty)return FALSE;
}
start= offset*bv_wordbits;
bitmask= bv_lsb;
mask= value;
while(!(mask&bv_lsb))
{
bitmask<<= 1;
mask>>= 1;
start++;
}
mask= ~(bitmask|(bitmask-1));
*min= start;
*max= start;
}
value= ~value;
value&= mask;
if(value==0)
{
offset++;
empty= TRUE;
while(empty&&(--size> 0))
{
if((value= ~*bv++))empty= FALSE;else offset++;
}
if(empty)value= bv_lsb;
}
start= offset*bv_wordbits;
while(!(value&bv_lsb))
{
value>>= 1;
start++;
}
*max= --start;
return TRUE;
}
/*:1251*//*1253:*/
#line 12281 "./marpa.w"

static inline guint
bv_count(Bit_Vector v)
{
guint start,min,max;
guint count= 0;
for(start= 0;bv_scan(v,start,&min,&max);start= max+2)
{
count+= max-min+1;
}
return count;
}
/*:1253*//*1259:*/
#line 12335 "./marpa.w"

static void
rhs_closure(struct marpa_g*g,Bit_Vector bv)
{
guint min,max,start= 0;
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_DECLARE(stack,Marpa_Symbol_ID)
FSTACK_INIT(stack,Marpa_Symbol_ID,SYM_Count_of_G(g));
while(bv_scan(bv,start,&min,&max))
{
guint symid;
for(symid= min;symid<=max;symid++)
{
*(FSTACK_PUSH(stack))= symid;
}
start= max+2;
}
while((top_of_stack= FSTACK_POP(stack)))
{
guint rule_ix;
GArray*rules= SYM_by_ID(*top_of_stack)->t_rhs;
for(rule_ix= 0;rule_ix<rules->len;rule_ix++)
{
Marpa_Rule_ID rule_id= 
g_array_index(rules,Marpa_Rule_ID,rule_ix);
RULE rule= RULE_by_ID(g,rule_id);
guint rule_length;
guint rh_ix;
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
if(bv_bit_test(bv,(guint)lhs_id))
goto NEXT_RULE;
rule_length= Length_of_RULE(rule);
for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test(bv,(guint)RHS_ID_of_RULE(rule,rh_ix)))
goto NEXT_RULE;
}



bv_bit_set(bv,(guint)lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}
/*:1259*//*1264:*/
#line 12414 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns)
{
guint bv_data_words= bv_bits_to_size(columns);
guint row_bytes= (bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
guint bv_mask= bv_bits_to_unused_mask(columns);
Bit_Vector_Word*matrix_addr= g_malloc0((size_t)(row_bytes*rows));
guint row;
for(row= 0;row<rows;row++){
guint row_start= row*(bv_data_words+bv_hiddenwords);
matrix_addr[row_start]= columns;
matrix_addr[row_start+1]= bv_data_words;
matrix_addr[row_start+2]= bv_mask;
}
return matrix_addr;
}
/*:1264*//*1266:*/
#line 12434 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:1266*//*1268:*/
#line 12447 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:1268*//*1270:*/
#line 12464 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:1270*//*1273:*/
#line 12474 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:1273*//*1276:*/
#line 12483 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:1276*//*1279:*/
#line 12492 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:1279*//*1281:*/
#line 12506 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix)
{
struct transition{guint from,to;}*top_of_stack= NULL;
guint size= matrix_columns(matrix);
guint row;
DSTACK_DECLARE(stack);
DSTACK_INIT(stack,struct transition,1024);
for(row= 0;row<size;row++){
guint min,max,start;
Bit_Vector row_vector= matrix_row(matrix,row);
for(start= 0;bv_scan(row_vector,start,&min,&max);start= max+2){
guint column;
for(column= min;column<=max;column++){
struct transition*t= DSTACK_PUSH(stack,struct transition);
t->from= row;
t->to= column;
}}}
while((top_of_stack= DSTACK_POP(stack,struct transition))){
guint old_from= top_of_stack->from;
guint old_to= top_of_stack->to;
guint new_ix;
for(new_ix= 0;new_ix<size;new_ix++){



if(!matrix_bit_test(matrix,new_ix,old_to)&&
matrix_bit_test(matrix,new_ix,old_from)){
struct transition*t= (DSTACK_PUSH(stack,struct transition));
matrix_bit_set(matrix,new_ix,old_to);
t->from= new_ix;
t->to= old_to;
}
if(!matrix_bit_test(matrix,old_from,new_ix)&&
matrix_bit_test(matrix,old_to,new_ix)){
struct transition*t= (DSTACK_PUSH(stack,struct transition));
matrix_bit_set(matrix,old_from,new_ix);
t->from= old_from;
t->to= new_ix;
}
}
}
DSTACK_DESTROY(stack);
}
/*:1281*//*1291:*/
#line 12650 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_bytes){
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}
/*:1291*//*1308:*/
#line 12793 "./marpa.w"

static inline void
psar_init(const PSAR psar,gint length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1308*//*1309:*/
#line 12800 "./marpa.w"

static inline void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
MARPA_OFF_DEBUG3("%s psl=%p",G_STRLOC,psl);
while(psl)
{
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
MARPA_OFF_DEBUG3("%s owner=%p",G_STRLOC,owner);
if(owner)
*owner= NULL;
g_slice_free1(Sizeof_PSL(psar),psl);
psl= next_psl;
MARPA_OFF_DEBUG3("%s psl=%p",G_STRLOC,psl);
}
}
/*:1309*//*1310:*/
#line 12817 "./marpa.w"

static inline PSL psl_new(const PSAR psar){
gint i;
PSL new_psl= g_slice_alloc(Sizeof_PSL(psar));
new_psl->t_next= NULL;
new_psl->t_prev= NULL;
new_psl->t_owner= NULL;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(new_psl,i)= NULL;
}
return new_psl;
}
/*:1310*//*1314:*/
#line 12849 "./marpa.w"

static inline void psar_reset(const PSAR psar){
PSL psl= psar->t_first_psl;
while(psl&&psl->t_owner){
gint i;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(psl,i)= NULL;
}
psl= psl->t_next;
}
psar_dealloc(psar);
}

/*:1314*//*1316:*/
#line 12868 "./marpa.w"

static inline void psar_dealloc(const PSAR psar){
PSL psl= psar->t_first_psl;
while(psl){
PSL*owner= psl->t_owner;
if(!owner)break;
(*owner)= NULL;
psl->t_owner= NULL;
psl= psl->t_next;
}
psar->t_first_free_psl= psar->t_first_psl;
}

/*:1316*//*1318:*/
#line 12890 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar){
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1318*//*1322:*/
#line 12915 "./marpa.w"

static inline PSL psl_alloc(const PSAR psar){
PSL free_psl= psar->t_first_free_psl;
PSL next_psl= free_psl->t_next;
if(!next_psl){
next_psl= free_psl->t_next= psl_new(psar);
next_psl->t_prev= free_psl;
}
psar->t_first_free_psl= next_psl;
return free_psl;
}

/*:1322*//*1357:*/
#line 13206 "./marpa.w"

static void
set_error(struct marpa_g*g,Marpa_Message_ID message,guint flags)
{
g->t_error= message;
if(flags&FATAL_FLAG)
g->t_fatal_error= g->t_error;
}

static void
r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags)
{
set_error(G_of_R(r),message,flags);
}

/*:1357*//*1363:*/
#line 13325 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*
eim_tag_safe(gchar*buffer,EIM eim)
{
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_EIM(eim),Origin_Earleme_of_EIM(eim),
Earleme_of_EIM(eim));
return buffer;
}

static char DEBUG_eim_tag_buffer[1000];
PRIVATE_NOT_INLINE gchar*
eim_tag(EIM eim)
{
return eim_tag_safe(DEBUG_eim_tag_buffer,eim);
}
#endif

/*:1363*//*1365:*/
#line 13354 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_SYMID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}
#endif

/*:1365*//*1367:*/
#line 13376 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*
or_tag_safe(gchar*buffer,OR or)
{
if(OR_is_Token(or))return"TOKEN";
if(Type_of_OR(or)==DUMMY_OR_NODE)return"DUMMY";
sprintf(buffer,"R%d:%d@%d-%d",
ID_of_RULE(RULE_of_OR(or)),Position_of_OR(or),
Origin_Ord_of_OR(or),
ES_Ord_of_OR(or));
return buffer;
}

static char DEBUG_or_tag_buffer[1000];
PRIVATE_NOT_INLINE const gchar*
or_tag(OR or)
{
return or_tag_safe(DEBUG_or_tag_buffer,or);
}
#endif


/*:1367*/
#line 13457 "./marpa.w"


/*:1373*/
