/*1190:*/
#line 13682 "./marpa.w"

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

/*:1190*//*1191:*/
#line 13705 "./marpa.w"

#include "config.h"
#include "marpa.h"
#include <stddef.h> 
#include <limits.h> 
#include <string.h> 
#include <stdlib.h> 

#ifndef MARPA_DEBUG
#define MARPA_DEBUG 0
#endif

#if MARPA_DEBUG
#include <stdarg.h> 
#include <stdio.h> 
#endif

/*1177:*/
#line 13521 "./marpa.w"

#if MARPA_DEBUG

#undef MARPA_ENABLE_ASSERT
#define MARPA_ENABLE_ASSERT 1

#define MARPA_DEBUG1(a)  (marpa_debug_level && \
    (*marpa_debug_handler)(a)) 
#define MARPA_DEBUG2(a,b)  (marpa_debug_level && \
    (*marpa_debug_handler)((a),(b))) 
#define MARPA_DEBUG3(a,b,c)  (marpa_debug_level && \
    (*marpa_debug_handler)((a),(b),(c))) 
#define MARPA_DEBUG4(a,b,c,d)  (marpa_debug_level && \
    (*marpa_debug_handler)((a),(b),(c),(d))) 
#define MARPA_DEBUG5(a,b,c,d,e)  (marpa_debug_level && \
    (*marpa_debug_handler)((a),(b),(c),(d),(e))) 

#define MARPA_ASSERT(expr) do { if LIKELY (expr) ; else \
       (*marpa_debug_handler) ("%s: assertion failed %s", STRLOC, #expr); } while (0);
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
#define MARPA_ASSERT(expr) do { if LIKELY (expr) ; else \
       (*marpa_debug_handler) ("%s: assertion failed %s", STRLOC, #expr); } while (0);
#endif

/*:1177*/
#line 13722 "./marpa.w"

#define PRIVATE_NOT_INLINE static
#define PRIVATE static inline \

#define SYM_Count_of_G(g) (DSTACK_LENGTH((g) ->t_symbols) ) 
#define XSY_Count_of_G(g) (DSTACK_LENGTH((g) ->t_symbols) ) 
#define SYM_by_ID(id) (*DSTACK_INDEX(g->t_symbols,SYM,(id) ) )  \

#define XRL_Count_of_G(g) (DSTACK_LENGTH((g) ->t_xrl_stack) ) 
#define RULE_Count_of_G(g) (XRL_Count_of_G(g) ) 
#define XRL_by_ID(id) (*DSTACK_INDEX((g) ->t_xrl_stack,XRL,(id) ) ) 
#define RULE_by_ID(g,id) (XRL_by_ID(id) )  \

#define RULEID_of_G_is_Valid(g,rule_id)  \
((rule_id) >=0&&(rule_id) <RULE_Count_of_G(g) )  \

#define G_is_Trivial(g) (!(g) ->t_proper_start_rule) 
#define External_Size_of_G(g) ((g) ->t_external_size) 
#define Internal_Size_of_G(g) ((g) ->t_internal_size) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define G_EVENT_COUNT(g) DSTACK_LENGTH((g) ->t_events) 
#define INITIAL_G_EVENTS_CAPACITY 1
#define G_EVENTS_CLEAR(g) DSTACK_CLEAR((g) ->t_events) 
#define G_EVENT_PUSH(g) DSTACK_PUSH((g) ->t_events,GEV_Object) 
#define I_AM_OK 0x69734f4b
#define IS_G_OK(g) ((g) ->t_is_ok==I_AM_OK) 
#define ID_of_SYM(sym) ((sym) ->t_symbol_id)  \

#define SYM_is_LHS(symbol) ((symbol) ->t_is_lhs) 
#define ISY_is_LHS(symbol) ((symbol) ->t_is_lhs) 
#define SYM_is_Sequence_LHS(symbol) ((symbol) ->t_is_sequence_lhs) 
#define SYM_is_Internal(symbol) ((symbol) ->t_is_internal) 
#define SYM_is_Ask_Me_When_Null(symbol) ((symbol) ->t_is_ask_me_when_null) 
#define SYM_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define ISY_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define SYM_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
#define SYM_is_Marked_Terminal(symbol) ((symbol) ->t_is_marked_terminal) 
#define SYMID_is_Terminal(id) (SYM_is_Terminal(SYM_by_ID(id) ) ) 
#define LHS_XRL_of_ISY(isy) ((isy) ->t_lhs_xrl) 
#define XRL_Offset_of_ISY(isy) ((isy) ->t_xrl_offset) 
#define MAX_RHS_LENGTH (INT_MAX>>(2) ) 
#define Length_of_RULE(rule) ((rule) ->t_rhs_length) 
#define Length_of_XRL(xrl) ((xrl) ->t_rhs_length) 
#define LHS_ID_of_RULE(rule) ((rule) ->t_symbols[0]) 
#define LHSID_of_XRL(xrl) ((xrl) ->t_symbols[0]) 
#define RHS_ID_of_RULE(rule,position)  \
((rule) ->t_symbols[(position) +1]) 
#define RHSID_of_XRL(xrl,position)  \
((xrl) ->t_symbols[(position) +1])  \

#define ID_of_RULE(rule) ((rule) ->t_id) 
#define XRL_is_Internal(rule) ((rule) ->t_is_Internal) 
#define XRL_is_Sequence(rule) ((rule) ->t_is_sequence) 
#define Minimum_of_XRL(rule) ((rule) ->t_minimum) 
#define Separator_of_XRL(rule) ((rule) ->t_separator_id) 
#define XRL_is_Proper_Separation(rule) ((rule) ->t_is_proper_separation) 
#define RULE_is_Used(rule) ((rule) ->t_is_used) 
#define RULE_has_Virtual_LHS(rule) ((rule) ->t_is_virtual_lhs) 
#define RULE_has_Virtual_RHS(rule) ((rule) ->t_is_virtual_rhs) 
#define Real_SYM_Count_of_RULE(rule) ((rule) ->t_real_symbol_count) 
#define RULE_is_Ask_Me(rule) ((rule) ->t_is_ask_me) 
#define RULE_of_IRL(irl) (irl)  \

#define ID_of_IRL(rule) (ID_of_RULE(rule) )  \

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
#define RULE_of_AIM(item) ((item) ->t_rule) 
#define RULEID_of_AIM(item) ID_of_RULE(RULE_of_AIM(item) ) 
#define LHS_ID_of_AIM(item) (LHS_ID_of_RULE(RULE_of_AIM(item) ) ) 
#define Position_of_AIM(aim) ((aim) ->t_position) 
#define Postdot_SYMID_of_AIM(item) ((item) ->t_postdot) 
#define AIM_is_Completion(aim) (Postdot_SYMID_of_AIM(aim) <0) 
#define Null_Count_of_AIM(aim) ((aim) ->t_leading_nulls) 
#define AHFA_of_G_by_ID(g,id) ((g) ->t_AHFA+(id) ) 
#define Complete_SYMIDs_of_AHFA(state) ((state) ->t_complete_symbols) 
#define Complete_SYM_Count_of_AHFA(state) ((state) ->t_complete_symbol_count) 
#define AIMs_of_AHFA(ahfa) ((ahfa) ->t_items) 
#define AIM_of_AHFA_by_AEX(ahfa,aex) (AIMs_of_AHFA(ahfa) [aex]) 
#define AEX_of_AHFA_by_AIM(ahfa,aim) aex_of_ahfa_by_aim_get((ahfa) ,(aim) ) 
#define AIM_Count_of_AHFA(ahfa) ((ahfa) ->t_item_count) 
#define AHFA_is_Predicted(ahfa) ((ahfa) ->t_is_predict) 
#define EIM_is_Predicted(eim) AHFA_is_Predicted(AHFA_of_EIM(eim) ) 
#define AHFA_is_Potential_Leo_Base(ahfa) ((ahfa) ->t_is_potential_leo_base) 
#define EIM_is_Potential_Leo_Base(eim) AHFA_is_Potential_Leo_Base(AHFA_of_EIM(eim) ) 
#define AHFA_Count_of_G(g) ((g) ->t_AHFA_len) 
#define ID_of_AHFA(state) ((state) ->t_key.t_id)  \

#define Postdot_SYM_Count_of_AHFA(state) ((state) ->t_postdot_sym_count) 
#define Postdot_SYMID_Ary_of_AHFA(state) ((state) ->t_postdot_symid_ary) 
#define AIMID_of_AHFA_by_AEX(g,ahfa,aex)  \
((ahfa) ->t_items[aex]-(g) ->t_AHFA_items) 
#define Leo_LHS_ID_of_AHFA(state) ((state) ->t_leo_lhs_sym) 
#define AHFA_is_Leo_Completion(state) (Leo_LHS_ID_of_AHFA(state) >=0) 
#define SET_1ST_PASS_SORT_KEY_FOR_RULE_ID(sort_key,rule) { \
const AIM aim= rule->t_first_aim; \
if(aim) { \
const SYMID postdot= Postdot_SYMID_of_AIM(aim) ; \
(sort_key) = postdot>=0?postdot:INT_MAX; \
}else{ \
(sort_key) = INT_MAX; \
} \
}
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
#define Empty_Transition_of_AHFA(state) ((state) ->t_empty_transition) 
#define TOK_Obs_of_I(i)  \
(&(i) ->t_token_obs) 
#define G_of_I(i) ((i) ->t_grammar) 
#define I_of_R(r) ((r) ->t_input) 
#define G_of_R(r) (G_of_I((r) ->t_input) ) 
#define AHFA_Count_of_R(r) AHFA_Count_of_G(G_of_R(r) ) 
#define R_BEFORE_INPUT 0x1
#define R_DURING_INPUT 0x2
#define R_AFTER_INPUT 0x3
#define Input_Phase_of_R(r) ((r) ->t_input_phase) 
#define First_ES_of_R(r) ((r) ->t_first_earley_set) 
#define Latest_ES_of_R(r) ((r) ->t_latest_earley_set) 
#define Current_Earleme_of_R(r) ((r) ->t_current_earleme) 
#define Current_ES_of_R(r) current_es_of_r(r) 
#define DEFAULT_EIM_WARNING_THRESHOLD (100) 
#define Furthest_Earleme_of_R(r) ((r) ->t_furthest_earleme) 
#define R_is_Exhausted(r) ((r) ->t_is_exhausted) 
#define EARLEME_THRESHOLD (INT_MAX/4) 
#define Next_ES_of_ES(set) ((set) ->t_next_earley_set) 
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

#define EIM_FATAL_THRESHOLD (INT_MAX/4) 
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
#define EIM_of_EIX(eix) ((eix) ->t_earley_item) 
#define Postdot_SYMID_of_EIX(eix) ((eix) ->t_postdot_symid) 
#define EIX_of_LIM(lim) ((EIX) (lim) ) 
#define Postdot_SYMID_of_LIM(leo) (Postdot_SYMID_of_EIX(EIX_of_LIM(leo) ) ) 
#define Next_PIM_of_LIM(leo) (Next_PIM_of_EIX(EIX_of_LIM(leo) ) ) 
#define Origin_of_LIM(leo) ((leo) ->t_origin) 
#define Top_AHFA_of_LIM(leo) ((leo) ->t_top_ahfa) 
#define Predecessor_LIM_of_LIM(leo) ((leo) ->t_predecessor) 
#define Base_EIM_of_LIM(leo) ((leo) ->t_base) 
#define ES_of_LIM(leo) ((leo) ->t_set) 
#define Chain_Length_of_LIM(leo) ((leo) ->t_chain_length) 
#define Earleme_of_LIM(lim) Earleme_of_ES(ES_of_LIM(lim) ) 
#define LIM_of_PIM(pim) ((LIM) (pim) ) 
#define EIX_of_PIM(pim) ((EIX) (pim) ) 
#define Postdot_SYMID_of_PIM(pim) (Postdot_SYMID_of_EIX(EIX_of_PIM(pim) ) ) 
#define EIM_of_PIM(pim) (EIM_of_EIX(EIX_of_PIM(pim) ) ) 
#define Next_PIM_of_PIM(pim) (Next_PIM_of_EIX(EIX_of_PIM(pim) ) )  \

#define PIM_of_LIM(pim) ((PIM) (pim) ) 
#define PIM_is_LIM(pim) (EIM_of_EIX(EIX_of_PIM(pim) ) ==NULL) 
#define SYMID_of_Postdot_Item(postdot) ((postdot) ->t_earley.transition_symid)  \

#define Next_SRCL_of_SRCL(link) ((link) ->t_next) 
#define Source_of_SRCL(link) ((link) ->t_source) 
#define Source_of_EIM(eim) ((eim) ->t_container.t_unique) 
#define Predecessor_of_Source(srcd) ((srcd) .t_predecessor) 
#define Predecessor_of_SRC(source) Predecessor_of_Source(*(source) ) 
#define Predecessor_of_EIM(item) Predecessor_of_Source(Source_of_EIM(item) ) 
#define Predecessor_of_SRCL(link) Predecessor_of_Source(Source_of_SRCL(link) ) 
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
#define First_Token_Link_of_EIM(item) ((item) ->t_container.t_ambiguous.t_token) 
#define First_Leo_SRCL_of_EIM(item) ((item) ->t_container.t_ambiguous.t_leo)  \

#define Type_of_TOK(tok) ((tok) ->t_unvalued.t_type) 
#define SYMID_of_TOK(tok) ((tok) ->t_unvalued.t_symbol_id) 
#define Value_of_TOK(tok) ((tok) ->t_value) 
#define TOK_Obs_of_R(r) TOK_Obs_of_I(I_of_R(r) ) 
#define TOK_by_SYMID(symbol_id) (SYM_by_ID(symbol_id) ) 
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
#define Next_UR_of_UR(ur) ((ur) ->t_next) 
#define EIM_of_UR(ur) ((ur) ->t_earley_item) 
#define AEX_of_UR(ur) ((ur) ->t_aex)  \

#define URS_of_R(r) (&(r) ->t_ur_node_stack) 
#define Set_boolean_in_PSIA_for_initial_nulls(eim,aim) { \
 \
if(Position_of_AIM(aim) > 0) { \
const int null_count= Null_Count_of_AIM(aim) ; \
 \
if(null_count) { \
AEX aex= AEX_of_EIM_by_AIM((eim) , \
(aim) ) ; \
 \
or_node_estimate+= null_count; \
psia_test_and_set(&bocage_setup_obs,per_es_data, \
(eim) ,aex) ; \
} \
} \
} \

#define DUMMY_OR_NODE -1
#define MAX_TOKEN_OR_NODE -2
#define VALUED_TOKEN_OR_NODE -2
#define NULLING_TOKEN_OR_NODE -3
#define UNVALUED_TOKEN_OR_NODE -4
#define OR_is_Token(or) (Type_of_OR(or) <=MAX_TOKEN_OR_NODE) 
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
const int psia_earley_set_ordinal= ES_Ord_of_EIM(psia_earley_item) ; \
OR**const psia_nodes_by_item=  \
per_es_data[psia_earley_set_ordinal].t_aexes_by_item; \
const int psia_item_ordinal= Ord_of_EIM(psia_earley_item) ; \
OR*const psia_nodes_by_aex= psia_nodes_by_item[psia_item_ordinal]; \
psia_or= psia_nodes_by_aex?psia_nodes_by_aex[psia_aex]:NULL; \
} \

#define OR_of_AND(and) ((and) ->t_current) 
#define Predecessor_OR_of_AND(and) ((and) ->t_predecessor) 
#define Cause_OR_of_AND(and) ((and) ->t_cause) 
#define I_of_B(b) ((b) ->t_input) 
#define OBS_of_B(b) ((b) ->t_obs) 
#define OBS_of_O(order) ((order) ->t_obs) 
#define O_is_Frozen(o) ((o) ->t_is_frozen) 
#define B_of_O(b) ((b) ->t_bocage) 
#define T_is_Exhausted(tree)  \
(!FSTACK_IS_INITIALIZED((tree) ->t_nook_stack) ) 
#define Size_of_TREE(tree) FSTACK_LENGTH((tree) ->t_nook_stack) 
#define NOOK_of_TREE_by_IX(tree,nook_id)  \
FSTACK_INDEX((tree) ->t_nook_stack,NOOK_Object,nook_id) 
#define O_of_T(t) ((t) ->t_order) 
#define T_is_Paused(t) ((t) ->t_pause_counter> 0) 
#define Size_of_T(t) FSTACK_LENGTH((t) ->t_nook_stack) 
#define OR_of_NOOK(nook) ((nook) ->t_or_node) 
#define Choice_of_NOOK(nook) ((nook) ->t_choice) 
#define Parent_of_NOOK(nook) ((nook) ->t_parent) 
#define NOOK_Cause_is_Ready(nook) ((nook) ->t_is_cause_ready) 
#define NOOK_is_Cause(nook) ((nook) ->t_is_cause_of_parent) 
#define NOOK_Predecessor_is_Ready(nook) ((nook) ->t_is_predecessor_ready) 
#define NOOK_is_Predecessor(nook) ((nook) ->t_is_predecessor_of_parent) 
#define Next_Value_Type_of_V(val) ((val) ->t_next_value_type) 
#define V_is_Active(val) (Next_Value_Type_of_V(val) !=MARPA_VALUE_INACTIVE) 
#define V_is_Trace(val) ((val) ->t_trace) 
#define NOOK_of_V(val) ((val) ->t_nook) 
#define SYMID_of_V(val) ((val) ->public.t_semantic_token_id) 
#define RULEID_of_V(val) ((val) ->public.t_semantic_rule_id) 
#define Token_Value_of_V(val) ((val) ->public.t_token_value) 
#define Token_Type_of_V(val) ((val) ->t_token_type) 
#define TOS_of_V(val) ((val) ->public.t_tos) 
#define Arg_N_of_V(val) ((val) ->public.t_arg_n) 
#define VStack_of_V(val) ((val) ->t_virtual_stack) 
#define Nulling_Ask_BV_of_V(val) ((val) ->t_nulling_ask_bv) 
#define T_of_V(v) ((v) ->t_tree) 
#define V_GET_DATA MARPA_VALUE_INTERNAL1 \

#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DECLARE(stack,type) struct{int t_count;type*t_base;}stack;
#define FSTACK_CLEAR(stack) ((stack) .t_count= 0) 
#define FSTACK_INIT(stack,type,n) (FSTACK_CLEAR(stack) ,((stack) .t_base= my_new(type,n) ) ) 
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
#define FSTACK_DESTROY(stack) (my_free((stack) .t_base) )  \

#define DSTACK_DECLARE(this) struct s_dstack this
#define DSTACK_INIT2(this,type)  \
( \
((this) .t_count= 0) , \
((sizeof(this) /1024<=0)  \
?(((this) .t_capacity= 1) ,((this) .t_base= my_malloc(sizeof(this) ) ) )  \
:(((this) .t_capacity= sizeof(this) /1024) , \
((this) .t_base= my_malloc(1024) ) )  \
)  \
) 
#define DSTACK_INIT(this,type,initial_size)  \
( \
((this) .t_count= 0) , \
((this) .t_base= my_new(type,((this) .t_capacity= (initial_size) ) ) )  \
)  \

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

#define STOLEN_DSTACK_DATA_FREE(data) (my_free(data) ) 
#define DSTACK_DESTROY(this) STOLEN_DSTACK_DATA_FREE(this.t_base) 
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
(sizeof(PSL_Object) +(psar->t_psl_length-1) *sizeof(void*) ) 
#define PSL_Datum(psl,i) ((psl) ->t_data[(i) ]) 
#define Dot_PSAR_of_R(r) (&(r) ->t_dot_psar_object) 
#define Dot_PSL_of_ES(es) ((es) ->t_dot_psl) 
#define my_slice_alloc(size) my_malloc(size) 
#define my_slice_new(x) my_malloc(sizeof(x) ) 
#define my_slice_free(x,p) my_free(p) 
#define my_slice_free1(size,p) my_free(p)  \

#define FATAL_FLAG (0x1u) 
#define MARPA_DEV_ERROR(message) (set_error(g,MARPA_ERR_DEVELOPMENT,(message) ,0u) ) 
#define MARPA_INTERNAL_ERROR(message) (set_error(g,MARPA_ERR_INTERNAL,(message) ,0u) ) 
#define MARPA_ERROR(code) (set_error(g,(code) ,NULL,0u) ) 
#define MARPA_FATAL(code) (set_error(g,(code) ,NULL,FATAL_FLAG) ) 
#define MARPA_OFF_DEBUG1(a) 
#define MARPA_OFF_DEBUG2(a,b) 
#define MARPA_OFF_DEBUG3(a,b,c) 
#define MARPA_OFF_DEBUG4(a,b,c,d) 
#define MARPA_OFF_DEBUG5(a,b,c,d,e) 
#define MARPA_OFF_ASSERT(expr) 

#line 13723 "./marpa.w"

#include "marpa_util.h"
#include "marpa_obs.h"
#include "avl.h"
/*92:*/
#line 894 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:92*//*120:*/
#line 1079 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef XSY ISY;
typedef XSY SYM;
typedef const struct s_xsy*XSY_Const;
/*:120*//*358:*/
#line 3752 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:358*//*396:*/
#line 4120 "./marpa.w"
struct s_AHFA_state;
/*:396*//*475:*/
#line 5295 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:475*//*582:*/
#line 5989 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:582*//*606:*/
#line 6203 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:606*//*626:*/
#line 6493 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:626*//*629:*/
#line 6528 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:629*//*710:*/
#line 7646 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:710*//*714:*/
#line 7674 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:714*//*812:*/
#line 8848 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:812*//*840:*/
#line 9276 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:840*//*867:*/
#line 9711 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:867*//*893:*/
#line 10126 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:893*//*908:*/
#line 10302 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:908*//*921:*/
#line 10406 "./marpa.w"

struct s_bocage_setup_per_es;
/*:921*//*977:*/
#line 11078 "./marpa.w"

typedef Marpa_Tree TREE;
/*:977*//*1011:*/
#line 11518 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1011*//*1024:*/
#line 11654 "./marpa.w"

typedef struct s_value*VALUE;
/*:1024*//*1101:*/
#line 12811 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1101*//*1104:*/
#line 12845 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1104*//*1111:*/
#line 12910 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1111*//*1113:*/
#line 12925 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1113*/
#line 13727 "./marpa.w"

/*40:*/
#line 612 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:40*//*119:*/
#line 1075 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
typedef XSYID ISYID;
typedef XSYID SYMID;
/*:119*//*171:*/
#line 1473 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL IRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;
typedef Marpa_Rule_ID IRLID;

/*:171*//*259:*/
#line 2253 "./marpa.w"
typedef int SYMI;
/*:259*//*413:*/
#line 4211 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef int AHFAID;

/*:413*//*476:*/
#line 5300 "./marpa.w"
typedef int AEX;
/*:476*//*492:*/
#line 5455 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:492*//*507:*/
#line 5547 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:507*//*579:*/
#line 5980 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:579*//*581:*/
#line 5984 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:581*//*657:*/
#line 6910 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:657*//*659:*/
#line 6922 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:659*//*832:*/
#line 9212 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:832*//*866:*/
#line 9699 "./marpa.w"

typedef int WHEID;


/*:866*//*892:*/
#line 10122 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:892*//*1010:*/
#line 11515 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1010*//*1048:*/
#line 12094 "./marpa.w"

typedef unsigned int Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1048*//*1083:*/
#line 12569 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1083*/
#line 13728 "./marpa.w"

/*34:*/
#line 529 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:34*//*846:*/
#line 9339 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:846*//*1049:*/
#line 12101 "./marpa.w"

static const unsigned int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const unsigned int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= 1u;
static const unsigned int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1049*//*1134:*/
#line 13104 "./marpa.w"


/*:1134*//*1172:*/
#line 13493 "./marpa.w"

#if MARPA_DEBUG >  0
static int _marpa_default_debug_handler(const char*format,...);
#define MARPA_DEFAULT_DEBUG_HANDLER _marpa_default_debug_handler
#else
#define MARPA_DEFAULT_DEBUG_HANDLER NULL
#endif

int(*marpa_debug_handler)(const char*,...)= 
MARPA_DEFAULT_DEBUG_HANDLER;
int marpa_debug_level= 0;

/*:1172*/
#line 13729 "./marpa.w"

/*1102:*/
#line 12814 "./marpa.w"

struct s_dstack{int t_count;int t_capacity;void*t_base;};
/*:1102*/
#line 13730 "./marpa.w"

/*39:*/
#line 606 "./marpa.w"
struct marpa_g{
/*111:*/
#line 1030 "./marpa.w"

int t_is_ok;

/*:111*/
#line 607 "./marpa.w"

/*50:*/
#line 688 "./marpa.w"

DSTACK_DECLARE(t_symbols);
/*:50*//*58:*/
#line 732 "./marpa.w"

DSTACK_DECLARE(t_xrl_stack);
struct marpa_avl_table*rule_tree;
/*:58*//*89:*/
#line 882 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:89*//*96:*/
#line 913 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:96*//*103:*/
#line 977 "./marpa.w"

AVL_TREE t_xrl_tree;
/*:103*//*107:*/
#line 1000 "./marpa.w"

struct obstack t_obs;
struct obstack t_xrl_obs;
/*:107*//*113:*/
#line 1045 "./marpa.w"

const char*t_error_string;
/*:113*//*360:*/
#line 3769 "./marpa.w"

AIM t_AHFA_items;
/*:360*//*414:*/
#line 4215 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:414*/
#line 608 "./marpa.w"

/*44:*/
#line 634 "./marpa.w"
int t_ref_count;
/*:44*//*69:*/
#line 780 "./marpa.w"
XSYID t_start_xsyid;
/*:69*//*73:*/
#line 808 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:73*//*77:*/
#line 828 "./marpa.w"

int t_external_size;
int t_internal_size;
/*:77*//*80:*/
#line 844 "./marpa.w"
int t_max_rule_length;
/*:80*//*114:*/
#line 1047 "./marpa.w"

Marpa_Error_Code t_error;
/*:114*//*260:*/
#line 2255 "./marpa.w"

int t_symbol_instance_count;
/*:260*//*361:*/
#line 3773 "./marpa.w"

unsigned int t_aim_count;
/*:361*//*415:*/
#line 4218 "./marpa.w"
int t_AHFA_len;
/*:415*/
#line 609 "./marpa.w"

/*83:*/
#line 850 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:83*//*86:*/
#line 862 "./marpa.w"
unsigned int t_has_cycle:1;
/*:86*/
#line 610 "./marpa.w"

};
/*:39*//*95:*/
#line 906 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:95*//*121:*/
#line 1094 "./marpa.w"

struct s_xsy{
int t_or_node_type;
XSYID t_symbol_id;
/*157:*/
#line 1327 "./marpa.w"

SYM t_alias;
/*:157*//*164:*/
#line 1415 "./marpa.w"

RULE t_lhs_xrl;
int t_xrl_offset;
/*:164*/
#line 1098 "./marpa.w"

/*126:*/
#line 1137 "./marpa.w"
unsigned int t_is_lhs:1;
/*:126*//*128:*/
#line 1144 "./marpa.w"
unsigned int t_is_sequence_lhs:1;
/*:128*//*130:*/
#line 1150 "./marpa.w"
unsigned int t_is_internal:1;
/*:130*//*133:*/
#line 1173 "./marpa.w"
unsigned int t_is_ask_me_when_null:1;
/*:133*//*136:*/
#line 1195 "./marpa.w"
unsigned int t_is_accessible:1;
/*:136*//*139:*/
#line 1215 "./marpa.w"
unsigned int t_is_counted:1;
/*:139*//*142:*/
#line 1231 "./marpa.w"
unsigned int t_is_nulling:1;
/*:142*//*145:*/
#line 1251 "./marpa.w"

unsigned int t_is_terminal:1;
unsigned int t_is_marked_terminal:1;
/*:145*//*150:*/
#line 1289 "./marpa.w"
unsigned int t_is_productive:1;
/*:150*//*153:*/
#line 1305 "./marpa.w"
unsigned int t_is_start:1;
/*:153*//*156:*/
#line 1324 "./marpa.w"

unsigned int t_is_proper_alias:1;
unsigned int t_is_nulling_alias:1;
/*:156*/
#line 1099 "./marpa.w"

};
typedef struct s_symbol SYM_Object;
/*:121*//*170:*/
#line 1463 "./marpa.w"

struct s_xrl{
/*253:*/
#line 2233 "./marpa.w"
AIM t_first_aim;
/*:253*/
#line 1465 "./marpa.w"

/*181:*/
#line 1726 "./marpa.w"
int t_rhs_length;
/*:181*//*191:*/
#line 1813 "./marpa.w"
Marpa_Rule_ID t_id;

/*:191*//*230:*/
#line 2065 "./marpa.w"
int t_virtual_start;
/*:230*//*233:*/
#line 2082 "./marpa.w"
int t_virtual_end;
/*:233*//*237:*/
#line 2099 "./marpa.w"
Marpa_Rule_ID t_original;
/*:237*//*241:*/
#line 2118 "./marpa.w"
int t_real_symbol_count;
/*:241*//*244:*/
#line 2144 "./marpa.w"
unsigned int t_is_ask_me:1;
/*:244*//*261:*/
#line 2266 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:261*/
#line 1466 "./marpa.w"

/*193:*/
#line 1821 "./marpa.w"
unsigned int t_is_Internal:1;
/*:193*//*195:*/
#line 1828 "./marpa.w"
unsigned int t_is_sequence:1;
/*:195*//*198:*/
#line 1846 "./marpa.w"
int t_minimum;
/*:198*//*200:*/
#line 1854 "./marpa.w"
SYMID t_separator_id;
/*:200*//*204:*/
#line 1873 "./marpa.w"
unsigned int t_is_discard:1;
/*:204*//*208:*/
#line 1912 "./marpa.w"
unsigned int t_is_proper_separation:1;
/*:208*//*216:*/
#line 1972 "./marpa.w"
unsigned int t_is_loop:1;
/*:216*//*221:*/
#line 2004 "./marpa.w"
unsigned int t_is_used:1;
/*:221*//*224:*/
#line 2031 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:224*//*227:*/
#line 2047 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:227*//*248:*/
#line 2202 "./marpa.w"
unsigned int t_is_semantic_equivalent:1;
/*:248*/
#line 1467 "./marpa.w"

/*182:*/
#line 1729 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:182*/
#line 1468 "./marpa.w"

};
/*:170*//*275:*/
#line 2446 "./marpa.w"

struct sym_rule_pair
{
SYMID t_symid;
RULEID t_ruleid;
};

/*:275*//*357:*/
#line 3746 "./marpa.w"

struct s_AHFA_item{
int t_sort_key;
/*366:*/
#line 3795 "./marpa.w"

RULE t_rule;

/*:366*/
#line 3749 "./marpa.w"

/*367:*/
#line 3801 "./marpa.w"

int t_position;

/*:367*//*368:*/
#line 3808 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:368*//*369:*/
#line 3817 "./marpa.w"

int t_leading_nulls;

/*:369*/
#line 3750 "./marpa.w"

};
/*:357*//*397:*/
#line 4121 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*401:*/
#line 4148 "./marpa.w"

SYMID*t_complete_symbols;

/*:401*//*403:*/
#line 4155 "./marpa.w"

AIM*t_items;
/*:403*//*421:*/
#line 4252 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:421*//*478:*/
#line 5312 "./marpa.w"

TRANS*t_transitions;
/*:478*/
#line 4128 "./marpa.w"

/*400:*/
#line 4146 "./marpa.w"

unsigned int t_complete_symbol_count;
/*:400*//*404:*/
#line 4158 "./marpa.w"

int t_item_count;
/*:404*//*422:*/
#line 4253 "./marpa.w"
unsigned int t_postdot_sym_count;

/*:422*//*428:*/
#line 4314 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:428*/
#line 4129 "./marpa.w"

/*408:*/
#line 4199 "./marpa.w"

unsigned int t_is_predict:1;

/*:408*//*411:*/
#line 4207 "./marpa.w"

unsigned int t_is_potential_leo_base:1;
/*:411*/
#line 4130 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:397*//*477:*/
#line 5301 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
int t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:477*//*493:*/
#line 5458 "./marpa.w"

struct s_input{
/*502:*/
#line 5529 "./marpa.w"

struct obstack t_token_obs;

/*:502*//*504:*/
#line 5534 "./marpa.w"

GRAMMAR t_grammar;
/*:504*/
#line 5460 "./marpa.w"

/*496:*/
#line 5475 "./marpa.w"

int t_ref_count;
/*:496*/
#line 5461 "./marpa.w"

};

/*:493*//*583:*/
#line 5995 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:583*//*584:*/
#line 6000 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
int t_postdot_sym_count;
/*585:*/
#line 6012 "./marpa.w"

int t_eim_count;
/*:585*//*587:*/
#line 6026 "./marpa.w"

int t_ordinal;
/*:587*/
#line 6004 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*586:*/
#line 6015 "./marpa.w"

EIM*t_earley_items;

/*:586*//*1121:*/
#line 12995 "./marpa.w"

PSL t_dot_psl;
/*:1121*/
#line 6007 "./marpa.w"

};

/*:584*//*627:*/
#line 6497 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:627*//*630:*/
#line 6531 "./marpa.w"

struct s_leo_item{
EIX_Object t_earley_ix;
ES t_origin;
AHFA t_top_ahfa;
LIM t_predecessor;
EIM t_base;
ES t_set;
int t_chain_length;
};
typedef struct s_leo_item LIM_Object;

/*:630*//*640:*/
#line 6670 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:640*//*711:*/
#line 7654 "./marpa.w"

struct s_token_unvalued{
int t_type;
SYMID t_symbol_id;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:711*//*715:*/
#line 7684 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:715*//*813:*/
#line 8865 "./marpa.w"

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
/*:813*//*843:*/
#line 9314 "./marpa.w"

struct s_draft_or_node
{
/*842:*/
#line 9308 "./marpa.w"

int t_position;
int t_end_set_ordinal;
RULE t_rule;
int t_start_set_ordinal;
ORID t_id;
/*:842*/
#line 9317 "./marpa.w"

DAND t_draft_and_node;
};
/*:843*//*844:*/
#line 9320 "./marpa.w"

struct s_final_or_node
{
/*842:*/
#line 9308 "./marpa.w"

int t_position;
int t_end_set_ordinal;
RULE t_rule;
int t_start_set_ordinal;
ORID t_id;
/*:842*/
#line 9323 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:844*//*845:*/
#line 9331 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:845*//*868:*/
#line 9718 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:868*//*894:*/
#line 10133 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:894*//*922:*/
#line 10408 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:922*//*954:*/
#line 10769 "./marpa.w"

struct marpa_order{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
/*957:*/
#line 10787 "./marpa.w"

BOCAGE t_bocage;

/*:957*/
#line 10774 "./marpa.w"

/*960:*/
#line 10805 "./marpa.w"
int t_ref_count;
/*:960*/
#line 10775 "./marpa.w"

unsigned int t_is_frozen:1;
};
/*:954*//*978:*/
#line 11092 "./marpa.w"

/*1012:*/
#line 11529 "./marpa.w"

struct s_nook{
OR t_or_node;
int t_choice;
NOOKID t_parent;
unsigned int t_is_cause_ready:1;
unsigned int t_is_predecessor_ready:1;
unsigned int t_is_cause_of_parent:1;
unsigned int t_is_predecessor_of_parent:1;
};
typedef struct s_nook NOOK_Object;

/*:1012*/
#line 11093 "./marpa.w"

/*1026:*/
#line 11686 "./marpa.w"

struct s_value{
struct marpa_value public;
DSTACK_DECLARE(t_virtual_stack);
NOOKID t_nook;
Marpa_Tree t_tree;
/*1033:*/
#line 11798 "./marpa.w"

int t_ref_count;
/*:1033*/
#line 11692 "./marpa.w"

Bit_Vector t_nulling_ask_bv;
int t_token_type;
int t_next_value_type;
unsigned int t_trace:1;
};

/*:1026*/
#line 11094 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_and_node_in_use;
Marpa_Order t_order;
/*984:*/
#line 11152 "./marpa.w"

int t_ref_count;
/*:984*//*991:*/
#line 11232 "./marpa.w"
int t_pause_counter;
/*:991*/
#line 11100 "./marpa.w"

int t_parse_count;
};

/*:978*//*1105:*/
#line 12848 "./marpa.w"

struct s_dqueue{int t_current;struct s_dstack t_stack;};

/*:1105*//*1112:*/
#line 12916 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1112*//*1114:*/
#line 12941 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1114*/
#line 13731 "./marpa.w"

/*508:*/
#line 5550 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*521:*/
#line 5655 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:521*//*533:*/
#line 5718 "./marpa.w"
void**t_sym_workarea;
/*:533*//*537:*/
#line 5729 "./marpa.w"
void**t_workarea2;
/*:537*//*541:*/
#line 5746 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:541*//*545:*/
#line 5772 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:545*//*568:*/
#line 5933 "./marpa.w"
struct obstack t_obs;
/*:568*//*593:*/
#line 6076 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:593*//*614:*/
#line 6338 "./marpa.w"

EIM t_trace_earley_item;
/*:614*//*644:*/
#line 6719 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:644*//*678:*/
#line 7176 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:678*//*716:*/
#line 7692 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:716*//*737:*/
#line 8007 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:737*//*741:*/
#line 8018 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:741*//*745:*/
#line 8029 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:745*//*814:*/
#line 8878 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:814*//*1115:*/
#line 12949 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1115*/
#line 5553 "./marpa.w"

/*511:*/
#line 5579 "./marpa.w"
int t_ref_count;
/*:511*//*525:*/
#line 5682 "./marpa.w"
int t_earley_item_warning_threshold;
/*:525*//*529:*/
#line 5705 "./marpa.w"
EARLEME t_furthest_earleme;
/*:529*//*588:*/
#line 6030 "./marpa.w"

int t_earley_set_count;
/*:588*/
#line 5554 "./marpa.w"

/*518:*/
#line 5647 "./marpa.w"

unsigned int t_input_phase:2;
/*:518*//*560:*/
#line 5871 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:560*//*564:*/
#line 5909 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:564*//*679:*/
#line 7179 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:679*/
#line 5555 "./marpa.w"

};

/*:508*/
#line 13732 "./marpa.w"

/*658:*/
#line 6913 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:658*//*660:*/
#line 6925 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:660*//*661:*/
#line 6931 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:661*//*662:*/
#line 6938 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:662*/
#line 13733 "./marpa.w"

/*607:*/
#line 6210 "./marpa.w"

struct s_earley_item_key{
AHFA t_state;
ES t_origin;
ES t_set;
};
typedef struct s_earley_item_key EIK_Object;
struct s_earley_item{
EIK_Object t_key;
union u_source_container t_container;
int t_ordinal;
/*612:*/
#line 6310 "./marpa.w"

unsigned int t_source_type:3;

/*:612*/
#line 6221 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:607*/
#line 13734 "./marpa.w"

/*909:*/
#line 10304 "./marpa.w"

struct marpa_bocage{
/*847:*/
#line 9349 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:847*//*911:*/
#line 10313 "./marpa.w"

INPUT t_input;

/*:911*//*913:*/
#line 10323 "./marpa.w"

struct obstack t_obs;
/*:913*/
#line 10306 "./marpa.w"

/*848:*/
#line 9352 "./marpa.w"

int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:848*//*937:*/
#line 10597 "./marpa.w"
int t_ref_count;
/*:937*/
#line 10307 "./marpa.w"

/*914:*/
#line 10325 "./marpa.w"

unsigned int t_is_obstack_initialized:1;
/*:914*/
#line 10308 "./marpa.w"

};

/*:909*/
#line 13735 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1178:*/
#line 13558 "./marpa.w"

static const char*eim_tag_safe(char*buffer,EIM eim);
static const char*eim_tag(EIM eim);
/*:1178*//*1180:*/
#line 13583 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim);
static char*lim_tag(LIM lim);
/*:1180*//*1182:*/
#line 13609 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or);
static const char*or_tag(OR or);
/*:1182*//*1184:*/
#line 13641 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AIM aim);
static const char*aim_tag(AIM aim);
/*:1184*/
#line 13738 "./marpa.w"

/*1170:*/
#line 13474 "./marpa.w"

static int _marpa_default_debug_handler(const char*format,...)
{
va_list args;
va_start(args,format);
vfprintf(stderr,format,args);
va_end(args);
putc('\n',stderr);
return 1;
}


/*:1170*//*1179:*/
#line 13562 "./marpa.w"

static const char*
eim_tag_safe(char*buffer,EIM eim)
{
if(!eim)return"NULL";
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_EIM(eim),Origin_Earleme_of_EIM(eim),
Earleme_of_EIM(eim));
return buffer;
}

static char DEBUG_eim_tag_buffer[1000];
static const char*
eim_tag(EIM eim)
{
return eim_tag_safe(DEBUG_eim_tag_buffer,eim);
}

/*:1179*//*1181:*/
#line 13588 "./marpa.w"

static char*
lim_tag_safe(char*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_SYMID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}

static char DEBUG_lim_tag_buffer[1000];
static char*
lim_tag(LIM lim)
{
return lim_tag_safe(DEBUG_lim_tag_buffer,lim);
}

/*:1181*//*1183:*/
#line 13613 "./marpa.w"

static const char*
or_tag_safe(char*buffer,OR or)
{
if(!or)return"NULL";
if(OR_is_Token(or))return"TOKEN";
if(Type_of_OR(or)==DUMMY_OR_NODE)return"DUMMY";
sprintf(buffer,"R%d:%d@%d-%d",
ID_of_RULE(RULE_of_OR(or)),Position_of_OR(or),
Origin_Ord_of_OR(or),
ES_Ord_of_OR(or));
return buffer;
}

static char DEBUG_or_tag_buffer[1000];
static const char*
or_tag(OR or)
{
return or_tag_safe(DEBUG_or_tag_buffer,or);
}

/*:1183*//*1185:*/
#line 13644 "./marpa.w"

static const char*
aim_tag_safe(char*buffer,AIM aim)
{
if(!aim)return"NULL";
const int aim_position= Position_of_AIM(aim);
if(aim_position>=0){
sprintf(buffer,"R%d@%d",RULEID_of_AIM(aim),Position_of_AIM(aim));
}else{
sprintf(buffer,"R%d@end",RULEID_of_AIM(aim));
}
return buffer;
}

static char DEBUG_aim_tag_buffer[1000];
static const char*
aim_tag(AIM aim)
{
return aim_tag_safe(DEBUG_aim_tag_buffer,aim);
}

/*:1185*/
#line 13739 "./marpa.w"

#endif
/*35:*/
#line 535 "./marpa.w"

PRIVATE
const char*check_alpha_version(
unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
if(required_major!=MARPA_MAJOR_VERSION)
return"major mismatch in alpha version";
if(required_minor!=MARPA_MINOR_VERSION)
return"minor mismatch in alpha version";
if(required_micro!=MARPA_MICRO_VERSION)
return"micro mismatch in alpha version";
return NULL;
}

/*:35*//*36:*/
#line 551 "./marpa.w"

const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
int marpa_effective_micro= 
100*MARPA_MINOR_VERSION+MARPA_MICRO_VERSION;
int required_effective_micro= 100*required_minor+required_micro;

if(required_major<=2)
return check_alpha_version(required_major,required_minor,
required_micro);
if(required_major> MARPA_MAJOR_VERSION)
return"libmarpa version too old (major mismatch)";
if(required_major<MARPA_MAJOR_VERSION)
return"libmarpa version too new (major mismatch)";
if(required_effective_micro<marpa_effective_micro-MARPA_BINARY_AGE)
return"libmarpa version too new (micro mismatch)";
if(required_effective_micro> marpa_effective_micro)
return"libmarpa version too old (micro mismatch)";
return NULL;
}

/*:36*//*42:*/
#line 616 "./marpa.w"

Marpa_Grammar marpa_g_new(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
GRAMMAR g;

if(check_alpha_version(required_major,required_minor,required_micro))
return NULL;
g= my_slice_new(struct marpa_g);

g->t_is_ok= 0;
/*45:*/
#line 635 "./marpa.w"

g->t_ref_count= 1;

/*:45*//*51:*/
#line 690 "./marpa.w"

DSTACK_INIT(g->t_symbols,SYM,256);
/*:51*//*59:*/
#line 735 "./marpa.w"

DSTACK_INIT(g->t_xrl_stack,RULE,256);
g->rule_tree= _marpa_avl_create(duplicate_rule_cmp,NULL,alignof(RULE));
/*:59*//*70:*/
#line 781 "./marpa.w"

g->t_start_xsyid= -1;
/*:70*//*74:*/
#line 811 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;
/*:74*//*78:*/
#line 831 "./marpa.w"

External_Size_of_G(g)= 0;
Internal_Size_of_G(g)= 0;

/*:78*//*81:*/
#line 845 "./marpa.w"

g->t_max_rule_length= 0;

/*:81*//*84:*/
#line 851 "./marpa.w"

g->t_is_precomputed= 0;
/*:84*//*87:*/
#line 863 "./marpa.w"

g->t_has_cycle= 0;
/*:87*//*90:*/
#line 883 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:90*//*97:*/
#line 921 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:97*//*104:*/
#line 979 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL,0);
/*:104*//*108:*/
#line 1003 "./marpa.w"

my_obstack_init(&g->t_obs);
my_obstack_begin(&g->t_xrl_obs,0,alignof(struct s_xrl));
/*:108*//*115:*/
#line 1049 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:115*//*363:*/
#line 3778 "./marpa.w"

g->t_AHFA_items= NULL;
/*:363*//*416:*/
#line 4219 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:416*/
#line 628 "./marpa.w"


g->t_is_ok= I_AM_OK;
return g;
}
/*:42*//*46:*/
#line 645 "./marpa.w"

PRIVATE
void
grammar_unref(GRAMMAR g)
{
MARPA_ASSERT(g->t_ref_count> 0)
g->t_ref_count--;
if(g->t_ref_count<=0)
{
grammar_free(g);
}
}
void
marpa_g_unref(Marpa_Grammar g)
{grammar_unref(g);}

/*:46*//*48:*/
#line 662 "./marpa.w"

PRIVATE GRAMMAR
grammar_ref(GRAMMAR g)
{
MARPA_ASSERT(g->t_ref_count> 0)
g->t_ref_count++;
return g;
}
Marpa_Grammar
marpa_g_ref(Marpa_Grammar g)
{return grammar_ref(g);}

/*:48*//*49:*/
#line 674 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
const SYMID symbol_count_of_g= SYM_Count_of_G(g);
/*52:*/
#line 692 "./marpa.w"

{SYMID id;for(id= 0;id<symbol_count_of_g;id++)
{symbol_free(SYM_by_ID(id));}}
DSTACK_DESTROY(g->t_symbols);

/*:52*//*61:*/
#line 741 "./marpa.w"

DSTACK_DESTROY(g->t_xrl_stack);
/*60:*/
#line 738 "./marpa.w"

_marpa_avl_destroy(g->rule_tree);
g->rule_tree= NULL;
/*:60*/
#line 743 "./marpa.w"


/*:61*//*91:*/
#line 884 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:91*//*98:*/
#line 923 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:98*//*106:*/
#line 986 "./marpa.w"

/*105:*/
#line 981 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:105*/
#line 987 "./marpa.w"


/*:106*//*109:*/
#line 1006 "./marpa.w"

my_obstack_free(&g->t_obs);
my_obstack_free(&g->t_xrl_obs);

/*:109*//*364:*/
#line 3780 "./marpa.w"

my_free(g->t_AHFA_items);

/*:364*//*417:*/
#line 4223 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*418:*/
#line 4233 "./marpa.w"
{
my_free(TRANSs_of_AHFA(ahfa_state));
}

/*:418*/
#line 4227 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:417*/
#line 679 "./marpa.w"

my_slice_free(struct marpa_g,g);
}

/*:49*//*54:*/
#line 700 "./marpa.w"

int marpa_g_symbol_count(Marpa_Grammar g){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 702 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 703 "./marpa.w"

return SYM_Count_of_G(g);
}

/*:54*//*56:*/
#line 712 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,SYM symbol)
{
const SYMID new_id= DSTACK_LENGTH((g)->t_symbols);
*DSTACK_PUSH((g)->t_symbols,SYM)= symbol;
symbol->t_symbol_id= new_id;
}

/*:56*//*57:*/
#line 722 "./marpa.w"

PRIVATE int symbol_is_valid(GRAMMAR g,SYMID symid)
{
return symid>=0&&symid<SYM_Count_of_G(g);
}

/*:57*//*65:*/
#line 748 "./marpa.w"

int marpa_g_rule_count(Marpa_Grammar g){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 750 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 751 "./marpa.w"

return RULE_Count_of_G(g);
}

/*:65*//*67:*/
#line 761 "./marpa.w"

PRIVATE
void rule_add(
GRAMMAR g,
RULE rule)
{
const RULEID new_id= DSTACK_LENGTH((g)->t_xrl_stack);
*DSTACK_PUSH((g)->t_xrl_stack,RULE)= rule;
rule->t_id= new_id;
External_Size_of_G(g)+= 1+Length_of_RULE(rule);
Internal_Size_of_G(g)+= 1+Length_of_RULE(rule);
g->t_max_rule_length= MAX(Length_of_RULE(rule),g->t_max_rule_length);
}

/*:67*//*71:*/
#line 783 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 786 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 787 "./marpa.w"

return g->t_start_xsyid;
}
/*:71*//*72:*/
#line 792 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 795 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 796 "./marpa.w"

/*1152:*/
#line 13298 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1152*/
#line 797 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 798 "./marpa.w"

return g->t_start_xsyid= symid;
}

/*:72*//*85:*/
#line 853 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 856 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 857 "./marpa.w"

return G_is_Precomputed(g);
}

/*:85*//*88:*/
#line 865 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 868 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 869 "./marpa.w"

return g->t_has_cycle;
}

/*:88*//*100:*/
#line 933 "./marpa.w"

PRIVATE
void event_new(struct marpa_g*g,int type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:100*//*101:*/
#line 942 "./marpa.w"

PRIVATE
void int_event_new(struct marpa_g*g,int type,int value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:101*//*102:*/
#line 952 "./marpa.w"

int
marpa_g_event(Marpa_Grammar g,Marpa_Event public_event,
int ix)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 957 "./marpa.w"

const int index_out_of_bounds= -1;
DSTACK events= &g->t_events;
GEV internal_event;
int type;

if(ix<0)
return failure_indicator;
if(ix>=DSTACK_LENGTH(*events))
return index_out_of_bounds;
internal_event= DSTACK_INDEX(*events,GEV_Object,ix);
type= internal_event->t_type;
public_event->t_type= type;
public_event->t_value= internal_event->t_value;
return type;
}

/*:102*//*117:*/
#line 1060 "./marpa.w"

Marpa_Error_Code marpa_g_error(Marpa_Grammar g,const char**p_error_string)
{
const Marpa_Error_Code error_code= g->t_error;
const char*error_string= g->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:117*//*123:*/
#line 1107 "./marpa.w"

PRIVATE SYM
symbol_new(GRAMMAR g)
{
SYM symbol= my_new(struct s_xsy,1);
/*122:*/
#line 1104 "./marpa.w"

symbol->t_or_node_type= UNVALUED_TOKEN_OR_NODE;

/*:122*//*127:*/
#line 1138 "./marpa.w"

SYM_is_LHS(symbol)= 0;

/*:127*//*129:*/
#line 1145 "./marpa.w"

SYM_is_Sequence_LHS(symbol)= 0;

/*:129*//*131:*/
#line 1152 "./marpa.w"

SYM_is_Internal(symbol)= 0;
/*:131*//*134:*/
#line 1174 "./marpa.w"

SYM_is_Ask_Me_When_Null(symbol)= 0;
/*:134*//*137:*/
#line 1196 "./marpa.w"

symbol->t_is_accessible= 0;
/*:137*//*140:*/
#line 1216 "./marpa.w"

symbol->t_is_counted= 0;
/*:140*//*143:*/
#line 1232 "./marpa.w"

symbol->t_is_nulling= 0;
/*:143*//*146:*/
#line 1254 "./marpa.w"

symbol->t_is_terminal= 0;
symbol->t_is_marked_terminal= 0;
/*:146*//*151:*/
#line 1290 "./marpa.w"

symbol->t_is_productive= 0;
/*:151*//*154:*/
#line 1306 "./marpa.w"
symbol->t_is_start= 0;
/*:154*//*158:*/
#line 1329 "./marpa.w"

symbol->t_is_proper_alias= 0;
symbol->t_is_nulling_alias= 0;
symbol->t_alias= NULL;

/*:158*//*165:*/
#line 1418 "./marpa.w"

LHS_XRL_of_ISY(symbol)= NULL;
XRL_Offset_of_ISY(symbol)= 0;

/*:165*/
#line 1112 "./marpa.w"

symbol_add(g,symbol);
return symbol;
}

/*:123*//*124:*/
#line 1117 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const SYM symbol= symbol_new(g);
symbol->t_is_internal= 0;
return ID_of_SYM(symbol);
}

/*:124*//*125:*/
#line 1126 "./marpa.w"

PRIVATE void symbol_free(SYM symbol)
{
my_free(symbol);
}

/*:125*//*132:*/
#line 1154 "./marpa.w"

int marpa_g_symbol_is_internal(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1159 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1160 "./marpa.w"

return SYM_is_Internal(SYM_by_ID(symid));
}

/*:132*//*135:*/
#line 1176 "./marpa.w"

int marpa_g_symbol_is_ask_me_when_null(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1181 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1182 "./marpa.w"

return SYM_is_Ask_Me_When_Null(SYM_by_ID(symid));
}
int marpa_g_symbol_ask_me_when_null_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1189 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1190 "./marpa.w"

symbol= SYM_by_ID(symid);
return SYM_is_Ask_Me_When_Null(symbol)= value?1:0;
}
/*:135*//*138:*/
#line 1204 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1207 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1208 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 1209 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1210 "./marpa.w"

return SYM_by_ID(symid)->t_is_accessible;
}

/*:138*//*141:*/
#line 1218 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1222 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1223 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1224 "./marpa.w"

return SYM_by_ID(symid)->t_is_counted;
}

/*:141*//*144:*/
#line 1234 "./marpa.w"

int marpa_g_symbol_is_nulling(GRAMMAR g,SYMID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1237 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1238 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 1239 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1240 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));
}

/*:144*//*148:*/
#line 1260 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1264 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1265 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1266 "./marpa.w"

return SYMID_is_Terminal(symid);
}
/*:148*//*149:*/
#line 1269 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1274 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1275 "./marpa.w"

/*1152:*/
#line 13298 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1152*/
#line 1276 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1277 "./marpa.w"

symbol= SYM_by_ID(symid);
/*1154:*/
#line 13309 "./marpa.w"

if(UNLIKELY(SYM_is_Internal(symbol))){
MARPA_ERROR(MARPA_ERR_INTERNAL_SYM);
return failure_indicator;
}
/*:1154*/
#line 1279 "./marpa.w"

if(UNLIKELY(value<0||value> 1)){
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
SYM_is_Marked_Terminal(symbol)= 1;
return SYM_is_Terminal(symbol)= value;
}

/*:149*//*152:*/
#line 1292 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1297 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1298 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 1299 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1300 "./marpa.w"

return SYM_by_ID(symid)->t_is_productive;
}

/*:152*//*155:*/
#line 1307 "./marpa.w"

int _marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1310 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1311 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 1312 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1313 "./marpa.w"

return SYM_by_ID(symid)->t_is_start;
}

/*:155*//*159:*/
#line 1338 "./marpa.w"

PRIVATE
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID _marpa_g_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1346 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1347 "./marpa.w"

symbol= SYM_by_ID(symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}

/*:159*//*160:*/
#line 1357 "./marpa.w"

PRIVATE
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID _marpa_g_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1365 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1366 "./marpa.w"

symbol= SYM_by_ID(symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
MARPA_ERROR(MARPA_ERR_NO_ALIAS);
return-1;
}
return ID_of_SYM(alias);
}

/*:160*//*162:*/
#line 1382 "./marpa.w"

PRIVATE
SYM symbol_alias_create(GRAMMAR g,SYM symbol)
{
SYM alias= symbol_new(g);
symbol->t_is_proper_alias= 1;
SYM_is_Nulling(symbol)= 0;
symbol->t_alias= alias;
alias->t_is_nulling_alias= 1;
SYM_is_Nulling(alias)= 1;
SYM_is_Ask_Me_When_Null(alias)
= SYM_is_Ask_Me_When_Null(symbol);
alias->t_is_productive= 1;
alias->t_is_accessible= symbol->t_is_accessible;
alias->t_alias= symbol;
return alias;
}

/*:162*//*167:*/
#line 1427 "./marpa.w"

Marpa_Rule_ID _marpa_g_symbol_lhs_xrl(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1430 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1431 "./marpa.w"

{
const SYM symbol= SYM_by_ID(symid);
const XRL lhs_xrl= LHS_XRL_of_ISY(symbol);
if(lhs_xrl)
return ID_of_RULE(lhs_xrl);
}
return-1;
}

/*:167*//*168:*/
#line 1449 "./marpa.w"

int _marpa_g_symbol_xrl_offset(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1452 "./marpa.w"

SYM symbol;
/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 1454 "./marpa.w"

symbol= SYM_by_ID(symid);
return XRL_Offset_of_ISY(symbol);
}

/*:168*//*174:*/
#line 1493 "./marpa.w"

PRIVATE
RULE rule_start(GRAMMAR g,const SYMID lhs,const SYMID*rhs,int length)
{
RULE rule;
const int rule_sizeof= offsetof(struct s_xrl,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
my_obstack_blank(&g->t_xrl_obs,rule_sizeof);
rule= my_obstack_base(&g->t_xrl_obs);
Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
SYM_is_LHS(SYM_by_ID(lhs))= 1;
{
int i;
for(i= 0;i<length;i++)
{
rule->t_symbols[i+1]= rhs[i];
}
}
return rule;
}

PRIVATE
RULE rule_finish(GRAMMAR g,RULE rule)
{
/*194:*/
#line 1822 "./marpa.w"

rule->t_is_Internal= 1;

/*:194*//*196:*/
#line 1829 "./marpa.w"

rule->t_is_sequence= 0;
/*:196*//*199:*/
#line 1847 "./marpa.w"

rule->t_minimum= -1;

/*:199*//*201:*/
#line 1855 "./marpa.w"

Separator_of_XRL(rule)= -1;

/*:201*//*205:*/
#line 1874 "./marpa.w"

rule->t_is_discard= 0;
/*:205*//*209:*/
#line 1913 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:209*//*217:*/
#line 1973 "./marpa.w"

rule->t_is_loop= 0;
/*:217*//*222:*/
#line 2005 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:222*//*225:*/
#line 2032 "./marpa.w"

RULE_has_Virtual_LHS(rule)= 0;
/*:225*//*228:*/
#line 2048 "./marpa.w"

RULE_has_Virtual_RHS(rule)= 0;
/*:228*//*231:*/
#line 2066 "./marpa.w"
rule->t_virtual_start= -1;
/*:231*//*234:*/
#line 2083 "./marpa.w"
rule->t_virtual_end= -1;
/*:234*//*238:*/
#line 2100 "./marpa.w"
rule->t_original= -1;
/*:238*//*242:*/
#line 2119 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:242*//*245:*/
#line 2145 "./marpa.w"

RULE_is_Ask_Me(rule)= 0;
/*:245*//*249:*/
#line 2203 "./marpa.w"

rule->t_is_semantic_equivalent= 0;
/*:249*//*254:*/
#line 2234 "./marpa.w"

rule->t_first_aim= NULL;

/*:254*//*262:*/
#line 2269 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:262*/
#line 1518 "./marpa.w"

rule_add(g,rule);
return rule;
}

PRIVATE_NOT_INLINE
RULE rule_new(GRAMMAR g,
const SYMID lhs,const SYMID*rhs,int length)
{
RULE rule= rule_start(g,lhs,rhs,length);
rule_finish(g,rule);
rule= my_obstack_finish(&g->t_xrl_obs);
return rule;
}

/*:174*//*175:*/
#line 1533 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,int length)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1538 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1541 "./marpa.w"

/*1152:*/
#line 13298 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1152*/
#line 1542 "./marpa.w"

if(UNLIKELY(length> MAX_RHS_LENGTH))
{
MARPA_ERROR(MARPA_ERR_RHS_TOO_LONG);
goto FAILURE;
}
rule= rule_start(g,lhs,rhs,length);
if(UNLIKELY(_marpa_avl_insert(g->t_xrl_tree,rule)!=NULL))
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
goto FAILURE;
}
if(UNLIKELY(!rule_check(g,rule)))
goto FAILURE;
rule= rule_finish(g,rule);
rule= my_obstack_finish(&g->t_xrl_obs);
XRL_is_Internal(rule)= 0;
rule_id= rule->t_id;
return rule_id;
FAILURE:
my_obstack_reject(&g->t_xrl_obs);
return failure_indicator;
}

/*:175*//*176:*/
#line 1566 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1573 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1574 "./marpa.w"

/*1152:*/
#line 13298 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1152*/
#line 1575 "./marpa.w"

/*178:*/
#line 1608 "./marpa.w"

{
if(separator_id!=-1)
{
if(UNLIKELY(!symbol_is_valid(g,separator_id)))
{
MARPA_ERROR(MARPA_ERR_BAD_SEPARATOR);
goto FAILURE;
}
{
const SYM separator= SYM_by_ID(separator_id);
if(UNLIKELY(SYM_is_Internal(separator)))
{
MARPA_ERROR(MARPA_ERR_INTERNAL_SYM);
goto FAILURE;
}
}
}
if(UNLIKELY(!symbol_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
goto FAILURE;
}
{
const SYM lhs= SYM_by_ID(lhs_id);
if(UNLIKELY(SYM_is_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
goto FAILURE;
}
}
if(UNLIKELY(!symbol_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
goto FAILURE;
}
{
const SYM rhs= SYM_by_ID(rhs_id);
if(UNLIKELY(SYM_is_Internal(rhs)))
{
MARPA_ERROR(MARPA_ERR_INTERNAL_SYM);
goto FAILURE;
}
}
}

/*:178*/
#line 1576 "./marpa.w"

/*177:*/
#line 1584 "./marpa.w"

{
original_rule= rule_new(g,lhs_id,&rhs_id,1);
RULE_is_Used(original_rule)= 0;
original_rule_id= original_rule->t_id;
if(separator_id>=0)
Separator_of_XRL(original_rule)= separator_id;
Minimum_of_XRL(original_rule)= min;
XRL_is_Sequence(original_rule)= 1;
XRL_is_Internal(original_rule)= 0;
original_rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION)
&&separator_id>=0;
if(flags&MARPA_PROPER_SEPARATION)
{
XRL_is_Proper_Separation(original_rule)= 1;
}
SYM_is_Sequence_LHS(SYM_by_ID(lhs_id))= 1;
SYM_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0)
{
SYM_by_ID(separator_id)->t_is_counted= 1;
}
}

/*:177*/
#line 1577 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:176*//*180:*/
#line 1677 "./marpa.w"

PRIVATE_NOT_INLINE int
duplicate_rule_cmp(const void*ap,const void*bp,void*param UNUSED)
{
XRL xrl1= (XRL)ap;
XRL xrl2= (XRL)bp;
int diff= LHSID_of_XRL(xrl2)-LHSID_of_XRL(xrl1);
if(diff)
return diff;
{



int ix;
const int length= Length_of_XRL(xrl1);
diff= Length_of_XRL(xrl2)-length;
if(diff)
return diff;
for(ix= 0;ix<length;ix++)
{
diff= RHSID_of_XRL(xrl2,ix)-RHSID_of_XRL(xrl1,ix);
if(diff)
return diff;
}
}
return 0;
}

/*:180*//*183:*/
#line 1731 "./marpa.w"

PRIVATE int
rule_check(GRAMMAR g,XRL rule)
{
SYM lhs;
const XRLID lhs_id= LHSID_of_XRL(rule);
if(UNLIKELY(!symbol_is_valid(g,lhs_id)))
goto INVALID_SYMID;
lhs= SYM_by_ID(lhs_id);
if(UNLIKELY(SYM_is_Sequence_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
return 0;
}
{
int rh_index;
const int length= Length_of_XRL(rule);
for(rh_index= 0;rh_index<length;rh_index++)
{
const SYMID symid= RHSID_of_XRL(rule,rh_index);
SYM rhs;
if(UNLIKELY(!symbol_is_valid(g,symid)))
goto INVALID_SYMID;
rhs= SYM_by_ID(symid);
}
}
return 1;
INVALID_SYMID:;
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return 0;
}

/*:183*//*184:*/
#line 1763 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:184*//*185:*/
#line 1767 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID rule_id){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1769 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1770 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 1771 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));
}
/*:185*//*186:*/
#line 1774 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:186*//*187:*/
#line 1778 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,int ix){
RULE rule;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1781 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1782 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 1783 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:187*//*188:*/
#line 1788 "./marpa.w"

PRIVATE size_t rule_length_get(RULE rule)
{
return Length_of_RULE(rule);}
/*:188*//*189:*/
#line 1792 "./marpa.w"

int marpa_g_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1794 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1795 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 1796 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}

/*:189*//*197:*/
#line 1831 "./marpa.w"

int marpa_g_rule_is_sequence(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1836 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1837 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 1838 "./marpa.w"

return XRL_is_Sequence(RULE_by_ID(g,rule_id));
}


/*:197*//*206:*/
#line 1876 "./marpa.w"

int marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1881 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1882 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 1883 "./marpa.w"

return!RULE_by_ID(g,rule_id)->t_is_discard;
}

/*:206*//*210:*/
#line 1915 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1920 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1921 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 1922 "./marpa.w"

return!XRL_is_Proper_Separation(RULE_by_ID(g,rule_id));
}



/*:210*//*212:*/
#line 1930 "./marpa.w"

PRIVATE int rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(lhs_id)->t_is_accessible;}
int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1937 "./marpa.w"

RULE rule;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1939 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 1940 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}

/*:212*//*214:*/
#line 1947 "./marpa.w"

PRIVATE int rule_is_productive(struct marpa_g*g,RULE rule)
{
int rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++){
Marpa_Symbol_ID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_by_ID(rhs_id)->t_is_productive)return 0;
}
return 1;}
int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1958 "./marpa.w"

RULE rule;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1960 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 1961 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}

/*:214*//*218:*/
#line 1975 "./marpa.w"

int marpa_g_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 1978 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 1979 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 1980 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 1981 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}

/*:218*//*220:*/
#line 1987 "./marpa.w"

PRIVATE int
rule_is_nulling(GRAMMAR g,RULE rule)
{
int rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++)
{
SYMID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_is_Nulling(SYM_by_ID(rhs_id)))
return 0;
}
return 1;
}

/*:220*//*223:*/
#line 2007 "./marpa.w"

int _marpa_g_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2010 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2011 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}

/*:223*//*226:*/
#line 2034 "./marpa.w"

int _marpa_g_rule_is_virtual_lhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2039 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 2040 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2041 "./marpa.w"

return RULE_has_Virtual_LHS(RULE_by_ID(g,rule_id));
}

/*:226*//*229:*/
#line 2050 "./marpa.w"

int _marpa_g_rule_is_virtual_rhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2055 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 2056 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2057 "./marpa.w"

return RULE_has_Virtual_RHS(RULE_by_ID(g,rule_id));
}

/*:229*//*232:*/
#line 2067 "./marpa.w"

unsigned int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2072 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 2073 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2074 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}

/*:232*//*235:*/
#line 2084 "./marpa.w"

unsigned int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2089 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 2090 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2091 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}

/*:235*//*239:*/
#line 2101 "./marpa.w"

Marpa_Rule_ID _marpa_g_rule_original(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2106 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2107 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_original;
}

/*:239*//*243:*/
#line 2120 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2125 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 2126 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2127 "./marpa.w"

return Real_SYM_Count_of_RULE(RULE_by_ID(g,rule_id));
}

/*:243*//*246:*/
#line 2147 "./marpa.w"

int marpa_g_rule_is_ask_me(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2152 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2153 "./marpa.w"

return RULE_is_Ask_Me(RULE_by_ID(g,rule_id));
}
/*:246*//*247:*/
#line 2172 "./marpa.w"

int marpa_g_rule_whatever_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2177 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2178 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}
int marpa_g_rule_ask_me_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2186 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2187 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 1;
}
int marpa_g_rule_first_child_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2195 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2196 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}

/*:247*//*252:*/
#line 2214 "./marpa.w"

Marpa_Rule_ID
_marpa_g_rule_semantic_equivalent(Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2219 "./marpa.w"

/*1156:*/
#line 13319 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1156*/
#line 2220 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(RULE_has_Virtual_LHS(rule))return-1;
if(rule->t_is_semantic_equivalent)return rule->t_original;
return rule_id;
}

/*:252*//*264:*/
#line 2283 "./marpa.w"

PRIVATE int
symbol_instance_of_ahfa_item_get(AIM aim)
{
int position= Position_of_AIM(aim);
const int null_count= Null_Count_of_AIM(aim);
if(position<0||position-null_count> 0){

const RULE rule= RULE_of_AIM(aim);
position= Position_of_AIM(aim-1);
return SYMI_of_RULE(rule)+position;
}
return-1;
}

/*:264*//*266:*/
#line 2315 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 2318 "./marpa.w"

int return_value= failure_indicator;
struct obstack*obs_precompute= my_new(struct obstack,1);
/*267:*/
#line 2362 "./marpa.w"

Bit_Vector nullable_v= NULL;

/*:267*//*270:*/
#line 2409 "./marpa.w"

RULEID xrl_count= XRL_Count_of_G(g);
SYMID xsy_count= XSY_Count_of_G(g);

/*:270*//*274:*/
#line 2442 "./marpa.w"

XSYID start_xsyid= g->t_start_xsyid;

/*:274*//*286:*/
#line 2734 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:286*/
#line 2321 "./marpa.w"

my_obstack_init(obs_precompute);
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 2323 "./marpa.w"

G_EVENTS_CLEAR(g);
/*271:*/
#line 2413 "./marpa.w"

if(UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
return failure_indicator;
}

/*:271*/
#line 2325 "./marpa.w"

/*1152:*/
#line 13298 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1152*/
#line 2326 "./marpa.w"

/*273:*/
#line 2423 "./marpa.w"

{
if(UNLIKELY(start_xsyid<0))
{
MARPA_ERROR(MARPA_ERR_NO_START_SYM);
return failure_indicator;
}
if(UNLIKELY(!symbol_is_valid(g,start_xsyid)))
{
MARPA_ERROR(MARPA_ERR_INVALID_START_SYM);
return failure_indicator;
}
if(UNLIKELY(!SYM_is_LHS(SYM_by_ID(start_xsyid))))
{
MARPA_ERROR(MARPA_ERR_START_NOT_LHS);
return failure_indicator;
}
}

/*:273*/
#line 2327 "./marpa.w"


g->t_is_precomputed= 1;
/*105:*/
#line 981 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:105*/
#line 2330 "./marpa.w"


{
/*279:*/
#line 2620 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:279*//*280:*/
#line 2623 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;
RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:280*//*284:*/
#line 2683 "./marpa.w"

Bit_Vector productive_v= NULL;

/*:284*/
#line 2333 "./marpa.w"

/*269:*/
#line 2397 "./marpa.w"

{
/*277:*/
#line 2466 "./marpa.w"

{
Marpa_Rule_ID rule_id;


const AVL_TREE rhs_avl_tree= 
_marpa_avl_create(sym_rule_cmp,NULL,alignof(struct sym_rule_pair));


struct sym_rule_pair*const p_rh_sym_rule_pair_base= 
my_obstack_new(AVL_OBSTACK(rhs_avl_tree),struct sym_rule_pair,
External_Size_of_G(g));
struct sym_rule_pair*p_rh_sym_rule_pairs= p_rh_sym_rule_pair_base;


const AVL_TREE lhs_avl_tree= 
_marpa_avl_create(sym_rule_cmp,NULL,alignof(struct sym_rule_pair));
struct sym_rule_pair*const p_lh_sym_rule_pair_base= 
my_obstack_new(AVL_OBSTACK(lhs_avl_tree),struct sym_rule_pair,
xrl_count);
struct sym_rule_pair*p_lh_sym_rule_pairs= p_lh_sym_rule_pair_base;

lhs_v= bv_obs_create(obs_precompute,xsy_count);
empty_lhs_v= bv_obs_shadow(obs_precompute,lhs_v);
for(rule_id= 0;rule_id<(Marpa_Rule_ID)xrl_count;rule_id++)
{
const RULE rule= RULE_by_ID(g,rule_id);
const Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
const int rule_length= Length_of_RULE(rule);
const int is_sequence= XRL_is_Sequence(rule);

if(XRL_is_Internal(rule))continue;

bv_bit_set(lhs_v,(unsigned int)lhs_id);


p_lh_sym_rule_pairs->t_symid= lhs_id;
p_lh_sym_rule_pairs->t_ruleid= rule_id;
_marpa_avl_insert(lhs_avl_tree,p_lh_sym_rule_pairs);
p_lh_sym_rule_pairs++;

if(is_sequence)
{
const SYMID separator_id= Separator_of_XRL(rule);
if(Minimum_of_XRL(rule)<=0)
{
bv_bit_set(empty_lhs_v,(unsigned int)lhs_id);
}
if(separator_id>=0){
p_rh_sym_rule_pairs->t_symid= separator_id;
p_rh_sym_rule_pairs->t_ruleid= rule_id;
_marpa_avl_insert(rhs_avl_tree,p_rh_sym_rule_pairs);
p_rh_sym_rule_pairs++;
}
}

if(rule_length<=0)
{
bv_bit_set(empty_lhs_v,(unsigned int)lhs_id);
}
else
{
int rhs_ix;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
p_rh_sym_rule_pairs->t_symid= RHS_ID_of_RULE(rule,rhs_ix);
p_rh_sym_rule_pairs->t_ruleid= rule_id;
_marpa_avl_insert(rhs_avl_tree,p_rh_sym_rule_pairs);
p_rh_sym_rule_pairs++;
}
}
}
{
struct avl_traverser traverser;
struct sym_rule_pair*pair;
SYMID seen_symid= -1;
RULEID*const rule_data_base= 
my_obstack_new(obs_precompute,RULEID,External_Size_of_G(g));
RULEID*p_rule_data= rule_data_base;
_marpa_avl_t_init(&traverser,rhs_avl_tree);

xrl_list_x_rh_sym= my_obstack_new(obs_precompute,RULEID*,xsy_count+1);
for(pair= (struct sym_rule_pair*)_marpa_avl_t_first(&traverser,rhs_avl_tree);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(&traverser))
{
const SYMID current_symid= pair->t_symid;
while(seen_symid<current_symid)
xrl_list_x_rh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(seen_symid<=xsy_count)
xrl_list_x_rh_sym[++seen_symid]= p_rule_data;
_marpa_avl_destroy(rhs_avl_tree);
}

{
struct avl_traverser traverser;
struct sym_rule_pair*pair;
SYMID seen_symid= -1;
RULEID*const rule_data_base= 
my_obstack_new(obs_precompute,RULEID,xrl_count);
RULEID*p_rule_data= rule_data_base;
_marpa_avl_t_init(&traverser,lhs_avl_tree);

xrl_list_x_lh_sym= 
my_obstack_new(obs_precompute,RULEID*,xsy_count+1);
for(pair= 
(struct sym_rule_pair*)_marpa_avl_t_first(&traverser,lhs_avl_tree);
pair;pair= (struct sym_rule_pair*)_marpa_avl_t_next(&traverser))
{
const SYMID current_symid= pair->t_symid;
while(seen_symid<current_symid)
xrl_list_x_lh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(seen_symid<=xsy_count)
xrl_list_x_lh_sym[++seen_symid]= p_rule_data;
_marpa_avl_destroy(lhs_avl_tree);
}

}

/*:277*/
#line 2399 "./marpa.w"

/*278:*/
#line 2591 "./marpa.w"

{
SYMID symid;
terminal_v= bv_obs_create(obs_precompute,xsy_count);
bv_not(terminal_v,lhs_v);
for(symid= 0;symid<xsy_count;symid++)
{
SYM symbol= SYM_by_ID(symid);
if(SYM_is_Marked_Terminal(symbol))
{


if(SYM_is_Terminal(symbol))
{
bv_bit_set(terminal_v,(unsigned int)symid);
continue;
}
bv_bit_clear(terminal_v,(unsigned int)symid);
continue;
}



if(bv_bit_test(terminal_v,(unsigned int)symid))
SYM_is_Terminal(symbol)= 1;
}
}

/*:278*/
#line 2400 "./marpa.w"

/*285:*/
#line 2704 "./marpa.w"

{
RULEID rule_id;
reach_matrix= matrix_obs_create(obs_precompute,xsy_count,xsy_count);
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
RULE rule= RULE_by_ID(g,rule_id);
SYMID lhs_id= LHS_ID_of_RULE(rule);
unsigned int rhs_ix,rule_length= Length_of_RULE(rule);
if(XRL_is_Internal(rule))continue;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
matrix_bit_set(reach_matrix,
(unsigned int)lhs_id,
(unsigned int)RHS_ID_of_RULE(rule,rhs_ix));
}
if(XRL_is_Sequence(rule))
{
const SYMID separator_id= Separator_of_XRL(rule);
if(separator_id>=0)
{
matrix_bit_set(reach_matrix,
(unsigned int)lhs_id,
(unsigned int)separator_id);
}
}
}
transitive_closure(reach_matrix);
}

/*:285*/
#line 2401 "./marpa.w"

/*281:*/
#line 2629 "./marpa.w"

{
unsigned int min,max,start;
SYMID symid;
int counted_nullables= 0;
nullable_v= bv_obs_clone(obs_precompute,empty_lhs_v);
rhs_closure(g,nullable_v,xrl_list_x_rh_sym);
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2)
{
for(symid= (SYMID)min;symid<=(SYMID)max;
symid++)
{
SYM symbol= SYM_by_ID(symid);
if(UNLIKELY(symbol->t_is_counted))
{
counted_nullables++;
int_event_new(g,MARPA_EVENT_COUNTED_NULLABLE,symid);
}
}
}
if(UNLIKELY(counted_nullables))
{
MARPA_ERROR(MARPA_ERR_COUNTED_NULLABLE);
goto FAILURE;
}
}

/*:281*/
#line 2402 "./marpa.w"

/*282:*/
#line 2656 "./marpa.w"

{
productive_v= bv_obs_shadow(obs_precompute,nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v,xrl_list_x_rh_sym);
{
unsigned int min,max,start;
SYMID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);
start= max+2)
{
for(symid= (SYMID)min;
symid<=(SYMID)max;symid++)
{
SYM symbol= SYM_by_ID(symid);
symbol->t_is_productive= 1;
}
}
}
}

/*:282*/
#line 2403 "./marpa.w"

/*283:*/
#line 2677 "./marpa.w"

if(UNLIKELY(!bv_bit_test(productive_v,(unsigned int)start_xsyid)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:283*/
#line 2404 "./marpa.w"

/*287:*/
#line 2739 "./marpa.w"

{
Bit_Vector accessible_v= 
matrix_row(reach_matrix,(unsigned int)start_xsyid);
unsigned int min,max,start;
SYMID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2)
{
for(symid= (SYMID)min;
symid<=(SYMID)max;symid++)
{
SYM symbol= SYM_by_ID(symid);
symbol->t_is_accessible= 1;
}
}
SYM_by_ID(start_xsyid)->t_is_accessible= 1;
}

/*:287*/
#line 2405 "./marpa.w"

/*288:*/
#line 2759 "./marpa.w"

{
Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
int nulling_terminal_found= 0;
unsigned int min,max,start;
for(start= 0;bv_scan(lhs_v,start,&min,&max);start= max+2)
{
SYMID productive_id;
for(productive_id= (SYMID)min;
productive_id<=(SYMID)max;productive_id++)
{
bv_and(reaches_terminal_v,terminal_v,
matrix_row(reach_matrix,(unsigned int)productive_id));
if(bv_is_empty(reaches_terminal_v))
{
const SYM symbol= SYM_by_ID(productive_id);
SYM_is_Nulling(symbol)= 1;
if(UNLIKELY(SYM_is_Terminal(symbol)))
{
nulling_terminal_found= 1;
int_event_new(g,MARPA_EVENT_NULLING_TERMINAL,
productive_id);
}
}
}
}
bv_free(reaches_terminal_v);
if(UNLIKELY(nulling_terminal_found))
{
MARPA_ERROR(MARPA_ERR_NULLING_TERMINAL);
goto FAILURE;
}
}

/*:288*/
#line 2406 "./marpa.w"

}

/*:269*/
#line 2334 "./marpa.w"

/*347:*/
#line 3545 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,(unsigned int)xrl_count,
(unsigned int)xrl_count);
/*348:*/
#line 3566 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
SYMID nonnulling_id= -1;
int nonnulling_count= 0;
int rhs_ix,rule_length;
rule_length= Length_of_RULE(rule);
if(UNLIKELY(XRL_is_Internal(rule)))continue;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
if(bv_bit_test(nullable_v,symid))continue;
nonnulling_id= symid;
nonnulling_count++;
}


if(nonnulling_count==1){
/*349:*/
#line 3603 "./marpa.w"

{
RULEID*p_xrl= xrl_list_x_lh_sym[nonnulling_id];
const RULEID*p_one_past_rules= xrl_list_x_lh_sym[nonnulling_id+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{


const RULEID to_rule_id= *p_xrl;
matrix_bit_set(unit_transition_matrix,(unsigned int)rule_id,
to_rule_id);
}
}

/*:349*/
#line 3584 "./marpa.w"

}else if(nonnulling_count==0){
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
nonnulling_id= RHS_ID_of_RULE(rule,rhs_ix);
if(!bv_bit_test(nullable_v,nonnulling_id))
continue;
if(SYM_is_Nulling(SYM_by_ID(nonnulling_id)))
continue;

/*349:*/
#line 3603 "./marpa.w"

{
RULEID*p_xrl= xrl_list_x_lh_sym[nonnulling_id];
const RULEID*p_one_past_rules= xrl_list_x_lh_sym[nonnulling_id+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{


const RULEID to_rule_id= *p_xrl;
matrix_bit_set(unit_transition_matrix,(unsigned int)rule_id,
to_rule_id);
}
}

/*:349*/
#line 3594 "./marpa.w"

}
}
}
}

/*:348*/
#line 3551 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*350:*/
#line 3617 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
RULE rule;
if(!matrix_bit_test
(unit_transition_matrix,(unsigned int)rule_id,
(unsigned int)rule_id))
continue;
loop_rule_count++;
rule= RULE_by_ID(g,rule_id);
rule->t_is_loop= 1;
}
}

/*:350*/
#line 3553 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:347*/
#line 2335 "./marpa.w"

}

/*289:*/
#line 2794 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
const RULE original_rule= RULE_by_ID(g,rule_id);
if(!XRL_is_Sequence(original_rule))continue;
/*290:*/
#line 2805 "./marpa.w"

{
const SYM internal_lhs= symbol_new(g);
const SYMID internal_lhs_id= ID_of_SYM(internal_lhs);
const SYMID lhs_id= LHS_ID_of_RULE(original_rule);
const SYMID rhs_id= RHS_ID_of_RULE(original_rule,0);
const SYMID separator_id= Separator_of_XRL(original_rule);
const RULEID original_rule_id= ID_of_RULE(original_rule);
SYM_is_Internal(internal_lhs)= 1;
LHS_XRL_of_ISY(internal_lhs)= original_rule;
if(Minimum_of_XRL(original_rule)<=0){
/*291:*/
#line 2826 "./marpa.w"

{
RULE rule;
rule= rule_new(g,lhs_id,0,0);
rule->t_is_semantic_equivalent= 1;
rule->t_original= original_rule_id;
}

/*:291*/
#line 2816 "./marpa.w"

}
/*292:*/
#line 2834 "./marpa.w"

{
RULE rule;
rule= rule_new(g,lhs_id,&internal_lhs_id,1);
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= 1;

RULE_has_Virtual_RHS(rule)= 1;
}

/*:292*/
#line 2818 "./marpa.w"

if(separator_id>=0&&!XRL_is_Proper_Separation(original_rule)){
/*293:*/
#line 2845 "./marpa.w"

{RULE rule;
SYMID temp_rhs[2];
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_new(g,lhs_id,temp_rhs,2);
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= 1;
RULE_has_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= 1;
}
/*:293*/
#line 2820 "./marpa.w"

}
/*294:*/
#line 2859 "./marpa.w"

{
const RULE rule= rule_new(g,internal_lhs_id,&rhs_id,1);
rule->t_original= original_rule_id;
RULE_has_Virtual_LHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= 1;
}
/*:294*/
#line 2822 "./marpa.w"

/*295:*/
#line 2866 "./marpa.w"

{
RULE rule;
SYMID temp_rhs[3];
int rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)
temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_new(g,internal_lhs_id,temp_rhs,rhs_ix);
rule->t_original= original_rule_id;
RULE_has_Virtual_LHS(rule)= 1;
RULE_has_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix-1;
}

/*:295*/
#line 2823 "./marpa.w"

}

/*:290*/
#line 2801 "./marpa.w"

}
}

/*:289*/
#line 2338 "./marpa.w"

/*302:*/
#line 2940 "./marpa.w"

{
/*303:*/
#line 2980 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:303*//*307:*/
#line 3057 "./marpa.w"

int factor_count;
int*factor_positions;
/*:307*//*312:*/
#line 3109 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:312*/
#line 2942 "./marpa.w"

/*308:*/
#line 3060 "./marpa.w"

factor_positions= my_new(int,g->t_max_rule_length);
/*:308*//*313:*/
#line 3112 "./marpa.w"

piece_rhs= my_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= my_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:313*/
#line 2943 "./marpa.w"

/*305:*/
#line 3010 "./marpa.w"

{
unsigned int min,max,start;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID nullable_id;
for(nullable_id= (Marpa_Symbol_ID)min;nullable_id<=(Marpa_Symbol_ID)max;
nullable_id++)
{
const SYM nullable= SYM_by_ID(nullable_id);
if(SYM_is_Nulling(nullable))
continue;
if(UNLIKELY(!nullable->t_is_accessible))
continue;
if(UNLIKELY(!nullable->t_is_productive))
continue;
if(UNLIKELY(symbol_null_alias(nullable)!=NULL))
continue;
symbol_alias_create(g,nullable);
}
}
}

/*:305*/
#line 2944 "./marpa.w"

pre_chaf_rule_count= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<pre_chaf_rule_count;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const int rule_length= Length_of_RULE(rule);
int nullable_suffix_ix= 0;
if(XRL_is_Internal(rule)){
RULE original_rule= RULE_by_ID(g,rule->t_original);
if(!rule_is_accessible(g,original_rule))
{
MARPA_DEBUG3("%s: rule %d marked NOT used",STRLOC,ID_of_RULE(rule));
RULE_is_Used(rule)= 0;
goto NEXT_CHAF_CANDIDATE;
}
if(!rule_is_productive(g,original_rule))
{
MARPA_DEBUG3("%s: rule %d marked NOT used",STRLOC,ID_of_RULE(rule));
RULE_is_Used(rule)= 0;
goto NEXT_CHAF_CANDIDATE;
}
if(rule_length<=0){
MARPA_DEBUG3("%s: rule %d marked NOT used",STRLOC,ID_of_RULE(rule));
RULE_is_Used(rule)= 0;
goto NEXT_CHAF_CANDIDATE;
}
goto NEXT_CHAF_CANDIDATE;
}
/*304:*/
#line 2984 "./marpa.w"

if(!RULE_is_Used(rule))
{
goto NEXT_CHAF_CANDIDATE;
}
if(rule_is_nulling(g,rule))
{
MARPA_DEBUG3("%s: rule %d marked NOT used",STRLOC,ID_of_RULE(rule));
RULE_is_Used(rule)= 0;
goto NEXT_CHAF_CANDIDATE;
}
if(!rule_is_accessible(g,rule))
{
MARPA_DEBUG3("%s: rule %d marked NOT used",STRLOC,ID_of_RULE(rule));
RULE_is_Used(rule)= 0;
goto NEXT_CHAF_CANDIDATE;
}
if(!rule_is_productive(g,rule))
{
MARPA_DEBUG3("%s: rule %d marked NOT used",STRLOC,ID_of_RULE(rule));
RULE_is_Used(rule)= 0;
goto NEXT_CHAF_CANDIDATE;
}

/*:304*/
#line 2971 "./marpa.w"

/*306:*/
#line 3041 "./marpa.w"

{int rhs_ix;
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
/*:306*/
#line 2972 "./marpa.w"


if(factor_count<=0)goto NEXT_CHAF_CANDIDATE;
/*310:*/
#line 3066 "./marpa.w"

MARPA_DEBUG3("%s: rule %d marked NOT used",STRLOC,ID_of_RULE(rule));
RULE_is_Used(rule)= 0;
{
const XRL chaf_xrl= rule;


int unprocessed_factor_count;

int factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);


int piece_end,piece_start= 0;
for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*316:*/
#line 3122 "./marpa.w"

SYMID chaf_virtual_symid;
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= first_factor_position-piece_start;
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*311:*/
#line 3092 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:311*/
#line 3130 "./marpa.w"

/*317:*/
#line 3149 "./marpa.w"

{
int remaining_rhs_length,piece_rhs_length;
/*318:*/
#line 3161 "./marpa.w"

{
int real_symbol_count= piece_end-piece_start+1;
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
int real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3176 "./marpa.w"

}

/*:318*/
#line 3152 "./marpa.w"
;
/*319:*/
#line 3179 "./marpa.w"

{
int chaf_rule_length= Length_of_RULE(rule)-piece_start;
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
int real_symbol_count= remaining_rhs_length;
chaf_rule= 
rule_new(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3197 "./marpa.w"

}

/*:319*/
#line 3153 "./marpa.w"
;
/*320:*/
#line 3202 "./marpa.w"
{
Marpa_Symbol_ID proper_id= RHS_ID_of_RULE(rule,first_factor_position);
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
ID_of_SYM(alias);
}
{RULE chaf_rule;
int real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3212 "./marpa.w"

}

/*:320*/
#line 3154 "./marpa.w"
;
/*321:*/
#line 3221 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
int real_symbol_count= remaining_rhs_length;
chaf_rule= rule_new(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3226 "./marpa.w"

}

/*:321*/
#line 3155 "./marpa.w"
;
}

/*:317*/
#line 3131 "./marpa.w"

factor_position_ix++;
}else{
int second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*311:*/
#line 3092 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:311*/
#line 3136 "./marpa.w"

/*323:*/
#line 3231 "./marpa.w"

{
int piece_rhs_length;
int real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;
/*324:*/
#line 3245 "./marpa.w"

{
RULE chaf_rule;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3253 "./marpa.w"

}

/*:324*/
#line 3238 "./marpa.w"

/*325:*/
#line 3257 "./marpa.w"

{
RULE chaf_rule;
second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3264 "./marpa.w"

}

/*:325*/
#line 3239 "./marpa.w"

/*326:*/
#line 3268 "./marpa.w"

{
RULE chaf_rule;
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3276 "./marpa.w"

}

/*:326*/
#line 3240 "./marpa.w"

/*327:*/
#line 3280 "./marpa.w"

{
RULE chaf_rule;
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3285 "./marpa.w"

}

/*:327*/
#line 3241 "./marpa.w"

}

/*:323*/
#line 3137 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:316*/
#line 3083 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*328:*/
#line 3290 "./marpa.w"

{
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= first_factor_position-piece_start;
int second_factor_position= factor_positions[factor_position_ix+1];
int second_factor_piece_position= second_factor_position-piece_start;
int real_symbol_count;
int piece_rhs_length;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*329:*/
#line 3309 "./marpa.w"

{
RULE chaf_rule;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3316 "./marpa.w"

}

/*:329*/
#line 3302 "./marpa.w"

/*330:*/
#line 3320 "./marpa.w"

{
RULE chaf_rule;
second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3327 "./marpa.w"

}

/*:330*/
#line 3303 "./marpa.w"

/*331:*/
#line 3331 "./marpa.w"

{
RULE chaf_rule;
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3339 "./marpa.w"

}

/*:331*/
#line 3304 "./marpa.w"

/*332:*/
#line 3344 "./marpa.w"

{
RULE chaf_rule;
if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3350 "./marpa.w"

}
}

/*:332*/
#line 3305 "./marpa.w"

}

/*:328*/
#line 3086 "./marpa.w"

}else{
/*333:*/
#line 3355 "./marpa.w"

{
int piece_rhs_length;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
int real_symbol_count;
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= 
factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*334:*/
#line 3370 "./marpa.w"

{
RULE chaf_rule;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3377 "./marpa.w"

}

/*:334*/
#line 3365 "./marpa.w"

/*335:*/
#line 3382 "./marpa.w"

{
RULE chaf_rule;
if(piece_start<nullable_suffix_ix)
{
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*336:*/
#line 3399 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs)= piece_start;
}

/*:336*/
#line 3391 "./marpa.w"

}
}

/*:335*/
#line 3366 "./marpa.w"

}

/*:333*/
#line 3088 "./marpa.w"

}
}

/*:310*/
#line 2975 "./marpa.w"

NEXT_CHAF_CANDIDATE:;
}
/*309:*/
#line 3062 "./marpa.w"

my_free(factor_positions);

/*:309*//*314:*/
#line 3115 "./marpa.w"

my_free(piece_rhs);
my_free(remaining_rhs);

/*:314*/
#line 2978 "./marpa.w"

}
/*:302*/
#line 2339 "./marpa.w"

/*339:*/
#line 3430 "./marpa.w"

{
ISYID proper_start_isyid= -1;
XSY proper_start_xsy= NULL;
XSY nulling_start_xsy= NULL;
ISY proper_start_isy= NULL;
const XSY start_xsy= SYM_by_ID(g->t_start_xsyid);
/*340:*/
#line 3442 "./marpa.w"

if(SYM_is_Nulling(start_xsy)){
start_xsy->t_is_accessible= 0;
nulling_start_xsy= start_xsy;
}else{
proper_start_xsy= start_xsy;
nulling_start_xsy= symbol_null_alias(start_xsy);
}
start_xsy->t_is_start= 0;

/*:340*/
#line 3437 "./marpa.w"

if(proper_start_xsy){/*341:*/
#line 3452 "./marpa.w"
{
RULE new_start_rule;
proper_start_xsy->t_is_start= 0;
proper_start_isy= symbol_new(g);
proper_start_isyid= ID_of_SYM(proper_start_isy);
proper_start_isy->t_is_accessible= 1;
proper_start_isy->t_is_productive= 1;
proper_start_isy->t_is_start= 1;
new_start_rule= rule_new(g,proper_start_isyid,&ID_of_SYM(start_xsy),1);
RULE_has_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= 1;
g->t_proper_start_rule= new_start_rule;
}

/*:341*/
#line 3438 "./marpa.w"
}
if(nulling_start_xsy){/*342:*/
#line 3471 "./marpa.w"
{
Marpa_Symbol_ID nulling_new_start_id;
RULE new_start_rule;
SYM nulling_new_start;
if(proper_start_isy)
{
nulling_new_start= symbol_alias_create(g,proper_start_isy);
nulling_new_start_id= ID_of_SYM(nulling_new_start);
}
else
{
nulling_new_start= symbol_new(g);
nulling_new_start_id= ID_of_SYM(nulling_new_start);
SYM_is_Nulling(nulling_new_start)= 1;
nulling_new_start->t_is_productive= 1;
nulling_new_start->t_is_accessible= 1;
}
nulling_new_start->t_is_start= 1;
new_start_rule= rule_new(g,nulling_new_start_id,0,0);
RULE_has_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= 0;
g->t_null_start_rule= new_start_rule;
}

/*:342*/
#line 3439 "./marpa.w"
}
}

/*:339*/
#line 2340 "./marpa.w"


if(!G_is_Trivial(g)){
/*449:*/
#line 4717 "./marpa.w"

AIM*const item_list_working_buffer
= my_obstack_alloc(obs_precompute,RULE_Count_of_G(g)*sizeof(AIM));
const RULEID irl_count= RULE_Count_of_G(g);
const SYMID ins_count= SYM_Count_of_G(g);
RULEID**irl_list_x_lh_sym= NULL;

/*:449*/
#line 2344 "./marpa.w"

/*450:*/
#line 4724 "./marpa.w"

{
Marpa_Rule_ID rule_id;
const AVL_TREE lhs_avl_tree= 
_marpa_avl_create(sym_rule_cmp,NULL,alignof(struct sym_rule_pair));
struct sym_rule_pair*const p_sym_rule_pair_base= 
my_obstack_new(AVL_OBSTACK(lhs_avl_tree),struct sym_rule_pair,
irl_count);
struct sym_rule_pair*p_sym_rule_pairs= p_sym_rule_pair_base;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)irl_count;rule_id++)
{
const RULE rule= RULE_by_ID(g,rule_id);
p_sym_rule_pairs->t_symid= LHS_ID_of_RULE(rule);
p_sym_rule_pairs->t_ruleid= rule_id;
_marpa_avl_insert(lhs_avl_tree,p_sym_rule_pairs);
p_sym_rule_pairs++;
}
{
struct avl_traverser traverser;
struct sym_rule_pair*pair;
SYMID seen_symid= -1;
RULEID*const rule_data_base= 
my_obstack_new(obs_precompute,RULEID,irl_count);
RULEID*p_rule_data= rule_data_base;
_marpa_avl_t_init(&traverser,lhs_avl_tree);

irl_list_x_lh_sym= 
my_obstack_new(obs_precompute,RULEID*,ins_count+1);
for(pair= 
(struct sym_rule_pair*)_marpa_avl_t_first(&traverser,
lhs_avl_tree);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(&traverser))
{
const SYMID current_symid= pair->t_symid;
while(seen_symid<current_symid)
irl_list_x_lh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(seen_symid<=ins_count)
irl_list_x_lh_sym[++seen_symid]= p_rule_data;
}
_marpa_avl_destroy(lhs_avl_tree);
}

/*:450*/
#line 2345 "./marpa.w"

/*378:*/
#line 3871 "./marpa.w"

{
RULEID rule_id;
AIMID no_of_items;
RULEID rule_count_of_g= RULE_Count_of_G(g);
AIM base_item= my_new(struct s_AHFA_item,Internal_Size_of_G(g));
AIM current_item= base_item;
unsigned int symbol_instance_of_next_rule= 0;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)rule_count_of_g;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
if(RULE_is_Used(rule)){
MARPA_DEBUG3("%s: rule %d AFHA items being created",STRLOC,ID_of_RULE(rule));
/*379:*/
#line 3895 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_RULE(rule);rhs_ix++)
{
SYMID rh_symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(rh_symid);
if(!ISY_is_Nulling(symbol)||SYM_is_Internal(symbol))
{
Last_Proper_SYMI_of_RULE(rule)= symbol_instance_of_next_rule+rhs_ix;
/*380:*/
#line 3919 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:380*/
#line 3906 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*381:*/
#line 3928 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:381*/
#line 3915 "./marpa.w"

current_item++;
}

/*:379*/
#line 3883 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
no_of_items= AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= my_renew(struct s_AHFA_item,base_item,no_of_items);
/*382:*/
#line 3942 "./marpa.w"

{
AIM items= g->t_AHFA_items;

Marpa_Rule_ID highest_found_rule_id= -1;
Marpa_AHFA_Item_ID item_id;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
AIM item= items+item_id;
RULE rule= RULE_of_AIM(item);
Marpa_Rule_ID rule_id_for_item= rule->t_id;
if(rule_id_for_item<=highest_found_rule_id)
continue;
rule->t_first_aim= item;
highest_found_rule_id= rule_id_for_item;
}
}

/*:382*/
#line 3891 "./marpa.w"

/*387:*/
#line 4006 "./marpa.w"

{
Marpa_AHFA_Item_ID item_id;
AIM*sort_array= my_new(struct s_AHFA_item*,no_of_items);
AIM items= g->t_AHFA_items;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
sort_array[item_id]= items+item_id;
}
qsort(sort_array,(int)no_of_items,sizeof(AIM),cmp_by_postdot_and_aimid);
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
Sort_Key_of_AIM(sort_array[item_id])= item_id;
}
my_free(sort_array);
}

/*:387*/
#line 3892 "./marpa.w"

}

/*:378*/
#line 2346 "./marpa.w"

/*434:*/
#line 4371 "./marpa.w"

{
/*435:*/
#line 4389 "./marpa.w"

AHFA p_working_state;
const unsigned int initial_no_of_states= 2*Internal_Size_of_G(g);
AIM AHFA_item_0_p= g->t_AHFA_items;
const unsigned int symbol_count_of_g= SYM_Count_of_G(g);
const unsigned int rule_count_of_g= RULE_Count_of_G(g);
Bit_Matrix prediction_matrix;
RULE*rule_by_sort_key= my_new(RULE,rule_count_of_g);
AVL_TREE duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
int ahfa_count_of_g;
AHFA ahfas_of_g;

/*:435*/
#line 4373 "./marpa.w"

/*436:*/
#line 4403 "./marpa.w"

/*437:*/
#line 4407 "./marpa.w"

{
unsigned int item_id;
unsigned int no_of_items_in_grammar= AIM_Count_of_G(g);
duplicates= _marpa_avl_create(AHFA_state_cmp,NULL,0);
singleton_duplicates= my_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++)
{
singleton_duplicates[item_id]= NULL;
}
}

/*:437*/
#line 4404 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:436*/
#line 4374 "./marpa.w"

/*459:*/
#line 4972 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_obs_create(obs_precompute,symbol_count_of_g,symbol_count_of_g);
/*460:*/
#line 4980 "./marpa.w"

{
RULEID rule_id;
SYMID symid;
for(symid= 0;symid<(SYMID)symbol_count_of_g;symid++)
{

SYM symbol= SYM_by_ID(symid);
if(!ISY_is_LHS(symbol))continue;
matrix_bit_set(symbol_by_symbol_matrix,(unsigned int)symid,(unsigned int)symid);
}
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
SYMID from,to;
const RULE rule= RULE_by_ID(g,rule_id);

const AIM item= rule->t_first_aim;

if(!item)
continue;
from= LHS_ID_of_AIM(item);
to= Postdot_SYMID_of_AIM(item);

if(to<0)
continue;

matrix_bit_set(symbol_by_symbol_matrix,(unsigned int)from,(unsigned int)to);
}
}

/*:460*/
#line 4975 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*461:*/
#line 5016 "./marpa.w"
{
SYMID from_symid;
unsigned int*sort_key_by_rule_id= my_new(unsigned int,rule_count_of_g);
unsigned int no_of_predictable_rules= 0;
/*462:*/
#line 5055 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
RULE rule= RULE_by_ID(g,rule_id);
int sort_key;
SET_1ST_PASS_SORT_KEY_FOR_RULE_ID(sort_key,rule);
if(sort_key!=INT_MAX)no_of_predictable_rules++;
}
}

/*:462*/
#line 5021 "./marpa.w"

/*463:*/
#line 5067 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
rule_by_sort_key[rule_id]= RULE_by_ID(g,rule_id);
}
qsort(rule_by_sort_key,(int)rule_count_of_g,
sizeof(RULE),cmp_by_rule_sort_key);
}

/*:463*/
#line 5022 "./marpa.w"

/*465:*/
#line 5097 "./marpa.w"

{
unsigned int sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:465*/
#line 5023 "./marpa.w"

/*466:*/
#line 5107 "./marpa.w"

{
prediction_matrix= 
matrix_obs_create(obs_precompute,symbol_count_of_g,
no_of_predictable_rules);
for(from_symid= 0;from_symid<(SYMID)symbol_count_of_g;from_symid++)
{

unsigned int min,max,start;
for(start= 0;
bv_scan(matrix_row
(symbol_by_symbol_matrix,(unsigned int)from_symid),
start,&min,&max);start= max+2)
{
Marpa_Symbol_ID to_symid;
for(to_symid= min;to_symid<=(Marpa_Symbol_ID)max;to_symid++)
{

RULEID*p_irl_x_lh_sym= irl_list_x_lh_sym[to_symid];
const RULEID*p_one_past_rules= irl_list_x_lh_sym[to_symid+1];
for(;p_irl_x_lh_sym<p_one_past_rules;p_irl_x_lh_sym++)
{

const RULEID rule_with_this_lhs_symbol= *p_irl_x_lh_sym;
unsigned int sort_key= 
sort_key_by_rule_id[rule_with_this_lhs_symbol];
if(sort_key>=no_of_predictable_rules)
continue;

matrix_bit_set(prediction_matrix,
(unsigned int)from_symid,sort_key);

}
}
}
}
}

/*:466*/
#line 5024 "./marpa.w"

my_free(sort_key_by_rule_id);
}

/*:461*/
#line 4977 "./marpa.w"

}

/*:459*/
#line 4375 "./marpa.w"

/*444:*/
#line 4546 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
const RULE start_rule= g->t_proper_start_rule;
SYMID*postdot_symbol_ids;
AIM start_item;
AIM*item_list= my_obstack_alloc(&g->t_obs,sizeof(AIM));

start_item= start_rule->t_first_aim;
item_list[0]= start_item;
AHFA_initialize(p_initial_state);
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= 1;
p_initial_state->t_key.t_id= 0;
AHFA_is_Predicted(p_initial_state)= 0;
TRANSs_of_AHFA(p_initial_state)= transitions_new(g);
Postdot_SYM_Count_of_AHFA(p_initial_state)= 1;
postdot_symbol_ids= Postdot_SYMID_Ary_of_AHFA(p_initial_state)= 
my_obstack_alloc(&g->t_obs,sizeof(SYMID));
*postdot_symbol_ids= Postdot_SYMID_of_AIM(start_item);
Complete_SYM_Count_of_AHFA(p_initial_state)= 0;
p_initial_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(unsigned int)
Postdot_SYMID_of_AIM
(start_item)),rule_by_sort_key,
&states,duplicates,item_list_working_buffer);
}

/*:444*/
#line 4376 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*438:*/
#line 4419 "./marpa.w"
{
unsigned int no_of_items= p_working_state->t_item_count;
unsigned int current_item_ix= 0;
AIM*item_list;
Marpa_Symbol_ID working_symbol;
item_list= p_working_state->t_items;
working_symbol= Postdot_SYMID_of_AIM(item_list[0]);

if(working_symbol<0)goto NEXT_AHFA_STATE;

while(1){
int first_working_item_ix= current_item_ix;
int no_of_items_in_new_state;
for(current_item_ix++;
current_item_ix<no_of_items;
current_item_ix++){
if(Postdot_SYMID_of_AIM(item_list[current_item_ix])!=working_symbol)break;
}
no_of_items_in_new_state= current_item_ix-first_working_item_ix;
if(no_of_items_in_new_state==1){
/*446:*/
#line 4606 "./marpa.w"
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
transition_add(obs_precompute,p_working_state,working_symbol,p_new_state);
goto NEXT_WORKING_SYMBOL;
}
p_new_state= DQUEUE_PUSH(states,AHFA_Object);

AHFA_initialize(p_new_state);
singleton_duplicates[single_item_id]= p_new_state;
new_state_item_list= p_new_state->t_items= 
my_obstack_alloc(&g->t_obs,sizeof(AIM));
new_state_item_list[0]= single_item_p;
p_new_state->t_item_count= 1;
AHFA_is_Predicted(p_new_state)= 0;
p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
transition_add(obs_precompute,p_working_state,working_symbol,p_new_state);
postdot= Postdot_SYMID_of_AIM(single_item_p);
if(postdot>=0)
{
Complete_SYM_Count_of_AHFA(p_new_state)= 0;
p_new_state->t_postdot_sym_count= 1;
p_new_state->t_postdot_symid_ary= 
my_obstack_alloc(&g->t_obs,sizeof(SYMID));
*(p_new_state->t_postdot_symid_ary)= postdot;


p_new_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(unsigned int)postdot),
rule_by_sort_key,&states,duplicates,item_list_working_buffer);
}
else
{
SYMID lhs_id= LHS_ID_of_AIM(single_item_p);
SYMID*complete_symids= my_obstack_alloc(&g->t_obs,sizeof(SYMID));
*complete_symids= lhs_id;
Complete_SYMIDs_of_AHFA(p_new_state)= complete_symids;
completion_count_inc(obs_precompute,p_new_state,lhs_id);
Complete_SYM_Count_of_AHFA(p_new_state)= 1;
p_new_state->t_postdot_sym_count= 0;
p_new_state->t_empty_transition= NULL;
/*448:*/
#line 4691 "./marpa.w"

{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(ISY_is_LHS(SYM_by_ID(predot_symid)))
{
Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:448*/
#line 4659 "./marpa.w"

}
}

/*:446*/
#line 4439 "./marpa.w"

}else{
/*451:*/
#line 4768 "./marpa.w"

{
AHFA p_new_state;
unsigned int predecessor_ix;
unsigned int no_of_new_items_so_far= 0;
AHFA queued_AHFA_state;
p_new_state= DQUEUE_PUSH(states,AHFA_Object);
p_new_state->t_item_count= no_of_items_in_new_state;
for(predecessor_ix= first_working_item_ix;
predecessor_ix<current_item_ix;predecessor_ix++)
{
int pre_insertion_point_ix= no_of_new_items_so_far-1;
AIM new_item_p= item_list[predecessor_ix]+1;
while(pre_insertion_point_ix>=0)
{
AIM*current_item_pp= 
item_list_working_buffer+pre_insertion_point_ix;
if(Sort_Key_of_AIM(new_item_p)>=
Sort_Key_of_AIM(*current_item_pp))
break;
*(current_item_pp+1)= *current_item_pp;
pre_insertion_point_ix--;
}
item_list_working_buffer[pre_insertion_point_ix+1]= new_item_p;
no_of_new_items_so_far++;
}
p_new_state->t_items= item_list_working_buffer;
queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state)
{

(void)DQUEUE_POP(states,AHFA_Object);
transition_add(obs_precompute,p_working_state,working_symbol,
queued_AHFA_state);
goto NEXT_WORKING_SYMBOL;
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
{
int i;
AIM*const final_aim_list= p_new_state->t_items= 
my_obstack_alloc(&g->t_obs,no_of_items_in_new_state*sizeof(AIM));
for(i= 0;i<no_of_items_in_new_state;i++){
final_aim_list[i]= item_list_working_buffer[i];
}
}
AHFA_initialize(p_new_state);
AHFA_is_Predicted(p_new_state)= 0;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
/*452:*/
#line 4825 "./marpa.w"

{
int symbol_count= SYM_Count_of_G(g);
int item_ix;
int no_of_postdot_symbols;
int no_of_complete_symbols;
Bit_Vector complete_v= bv_create(symbol_count);
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_working_buffer[item_ix];
Marpa_Symbol_ID postdot= Postdot_SYMID_of_AIM(item);
if(postdot<0)
{
int complete_symbol_id= LHS_ID_of_AIM(item);
completion_count_inc(obs_precompute,p_new_state,
complete_symbol_id);
bv_bit_set(complete_v,(unsigned int)complete_symbol_id);
}
else
{
bv_bit_set(postdot_v,(unsigned int)postdot);
}
}
if((no_of_postdot_symbols= p_new_state->t_postdot_sym_count= 
bv_count(postdot_v)))
{
unsigned int min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->t_postdot_symid_ary= 
my_obstack_alloc(&g->t_obs,
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
Complete_SYM_Count_of_AHFA(p_new_state)= bv_count(complete_v)))
{
unsigned int min,max,start;
SYMID*complete_symids= my_obstack_alloc(&g->t_obs,
no_of_complete_symbols*
sizeof(SYMID));
SYMID*p_symbol= complete_symids;
Complete_SYMIDs_of_AHFA(p_new_state)= complete_symids;
for(start= 0;bv_scan(complete_v,start,&min,&max);
start= max+2)
{
SYMID complete_symbol_id;
for(complete_symbol_id= (SYMID)min;
complete_symbol_id<=(SYMID)max;complete_symbol_id++)
{
*p_symbol++= complete_symbol_id;
}
}
}
bv_free(postdot_v);
bv_free(complete_v);
}

/*:452*/
#line 4818 "./marpa.w"

transition_add(obs_precompute,p_working_state,working_symbol,
p_new_state);
/*454:*/
#line 4905 "./marpa.w"

{
int item_ix;
Marpa_Symbol_ID postdot= -1;
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
postdot= Postdot_SYMID_of_AIM(item_list_working_buffer[item_ix]);
if(postdot>=0)
break;
}
p_new_state->t_empty_transition= NULL;
if(postdot>=0)
{
Bit_Vector predicted_rule_vector
= bv_shadow(matrix_row(prediction_matrix,(unsigned int)postdot));
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{

postdot= Postdot_SYMID_of_AIM(item_list_working_buffer[item_ix]);
if(postdot<0)
continue;
bv_or_assign(predicted_rule_vector,
matrix_row(prediction_matrix,
(unsigned int)postdot));
}

p_new_state->t_empty_transition= create_predicted_AHFA_state(g,
predicted_rule_vector,
rule_by_sort_key,
&states,
duplicates,
item_list_working_buffer);
bv_free(predicted_rule_vector);
}
}

/*:454*/
#line 4822 "./marpa.w"

}

/*:451*/
#line 4441 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:438*/
#line 4378 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*439:*/
#line 4451 "./marpa.w"

{
int ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
unsigned int symbol_id;
AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
for(symbol_id= 0;symbol_id<symbol_count_of_g;symbol_id++){
TRANS working_transition= transitions[symbol_id];
if(working_transition){
int completion_count= Completion_Count_of_TRANS(working_transition);
int sizeof_transition= 
offsetof(struct s_transition,t_aex)+completion_count*
sizeof(transitions[0]->t_aex[0]);
TRANS new_transition= my_obstack_alloc(&g->t_obs,sizeof_transition);
LV_To_AHFA_of_TRANS(new_transition)= To_AHFA_of_TRANS(working_transition);
LV_Completion_Count_of_TRANS(new_transition)= 0;
transitions[symbol_id]= new_transition;
}
}
}
}

/*:439*/
#line 4383 "./marpa.w"

/*441:*/
#line 4505 "./marpa.w"

{
int ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++)
{
AHFA from_ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(from_ahfa);
AIM*aims= AIMs_of_AHFA(from_ahfa);
int aim_count= AIM_Count_of_AHFA(from_ahfa);
AEX aex;
qsort(aims,aim_count,sizeof(AIM*),cmp_by_aimid);
for(aex= 0;aex<aim_count;aex++)
{
AIM ahfa_item= aims[aex];
SYMID postdot= Postdot_SYMID_of_AIM(ahfa_item);
if(postdot>=0)
{
TRANS transition= transitions[postdot];
AHFA to_ahfa= To_AHFA_of_TRANS(transition);
if(AHFA_is_Leo_Completion(to_ahfa))
{
Leo_Base_AEX_of_TRANS(transition)= aex;
AHFA_is_Potential_Leo_Base(from_ahfa)= 1;
}
else
{
Leo_Base_AEX_of_TRANS(transition)= -1;
}
}
}
}
}

/*:441*/
#line 4384 "./marpa.w"

/*440:*/
#line 4474 "./marpa.w"

{
int ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
const AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
if(Complete_SYM_Count_of_AHFA(ahfa)> 0){
AIM*aims= AIMs_of_AHFA(ahfa);
int aim_count= AIM_Count_of_AHFA(ahfa);
AEX aex;
for(aex= 0;aex<aim_count;aex++){
AIM ahfa_item= aims[aex];
if(AIM_is_Completion(ahfa_item)){
SYMID completed_symbol_id= LHS_ID_of_AIM(ahfa_item);
TRANS transition= transitions[completed_symbol_id];
AEX*aexes= AEXs_of_TRANS(transition);
int aex_ix= LV_Completion_Count_of_TRANS(transition)++;
aexes[aex_ix]= aex;
}
}
}
}
}

/*:440*/
#line 4385 "./marpa.w"

/*442:*/
#line 4538 "./marpa.w"

my_free(rule_by_sort_key);
/*443:*/
#line 4542 "./marpa.w"

my_free(singleton_duplicates);
_marpa_avl_destroy(duplicates);

/*:443*/
#line 4540 "./marpa.w"


/*:442*/
#line 4386 "./marpa.w"

}

/*:434*/
#line 2347 "./marpa.w"

/*490:*/
#line 5438 "./marpa.w"
{
int symbol_count= SYM_Count_of_G(g);
int symid;
Bit_Vector bv_is_terminal= bv_create((unsigned int)symbol_count);
g->t_bv_symid_is_terminal= bv_is_terminal;
for(symid= 0;symid<symbol_count;symid++){
if(!SYMID_is_Terminal(symid))continue;
bv_bit_set(bv_is_terminal,(unsigned int)symid);
}
}

/*:490*/
#line 2348 "./marpa.w"

}
return_value= G_EVENT_COUNT(g);
FAILURE:;
my_obstack_free(obs_precompute);
my_free(obs_precompute);
return return_value;
}
/*:266*//*276:*/
#line 2453 "./marpa.w"

PRIVATE_NOT_INLINE int sym_rule_cmp(
const void*ap,
const void*bp,
void*param UNUSED)
{
const struct sym_rule_pair*pair_a= (struct sym_rule_pair*)ap;
const struct sym_rule_pair*pair_b= (struct sym_rule_pair*)bp;
int result= pair_a->t_symid-pair_b->t_symid;
if(result)return result;
return pair_a->t_ruleid-pair_b->t_ruleid;
}

/*:276*//*337:*/
#line 3419 "./marpa.w"

PRIVATE
SYMID alias_by_id(GRAMMAR g,SYMID proper_id)
{
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
return ID_of_SYM(alias);
}

/*:337*//*365:*/
#line 3784 "./marpa.w"

PRIVATE int aim_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:365*//*370:*/
#line 3821 "./marpa.w"

int _marpa_g_AHFA_item_count(struct marpa_g*g){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 3823 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 3824 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:370*//*371:*/
#line 3828 "./marpa.w"

Marpa_Rule_ID _marpa_g_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 3831 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 3832 "./marpa.w"

/*1157:*/
#line 13324 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1157*/
#line 3833 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(item_id))->t_id;
}

/*:371*//*373:*/
#line 3838 "./marpa.w"

int _marpa_g_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 3841 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 3842 "./marpa.w"

/*1157:*/
#line 13324 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1157*/
#line 3843 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:373*//*375:*/
#line 3848 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 3851 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 3852 "./marpa.w"

/*1157:*/
#line 13324 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1157*/
#line 3853 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:375*//*376:*/
#line 3857 "./marpa.w"

int _marpa_g_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 3860 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 3861 "./marpa.w"

/*1157:*/
#line 13324 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1157*/
#line 3862 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:376*//*384:*/
#line 3967 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:384*//*386:*/
#line 3982 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_postdot_and_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
int a_postdot= Postdot_SYMID_of_AIM(a);
int b_postdot= Postdot_SYMID_of_AIM(b);
if(a_postdot==b_postdot)
return Sort_Key_of_AIM(a)-Sort_Key_of_AIM(b);
if(a_postdot<0)return 1;
if(b_postdot<0)return-1;
return a_postdot-b_postdot;
}

/*:386*//*398:*/
#line 4137 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*412:*/
#line 4209 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;

/*:412*//*429:*/
#line 4315 "./marpa.w"
Leo_LHS_ID_of_AHFA(ahfa)= -1;
/*:429*/
#line 4140 "./marpa.w"

}

/*:398*//*406:*/
#line 4170 "./marpa.w"

PRIVATE AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM sought_aim)
{
AIM*const aims= AIMs_of_AHFA(ahfa);
int aim_count= AIM_Count_of_AHFA(ahfa);
int hi= aim_count-1;
int lo= 0;
while(hi>=lo){
int trial_aex= lo+(hi-lo)/2;
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

/*:406*//*420:*/
#line 4242 "./marpa.w"

PRIVATE int AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:420*//*423:*/
#line 4256 "./marpa.w"

int _marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:423*//*424:*/
#line 4261 "./marpa.w"

int
_marpa_g_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 4264 "./marpa.w"

AHFA state;
/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 4266 "./marpa.w"

/*1158:*/
#line 13329 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1158*/
#line 4267 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:424*//*425:*/
#line 4274 "./marpa.w"

Marpa_AHFA_Item_ID _marpa_g_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
int item_ix){
AHFA state;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 4279 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 4280 "./marpa.w"

/*1158:*/
#line 13329 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1158*/
#line 4281 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
if(item_ix<0){
MARPA_ERROR(MARPA_ERR_AHFA_IX_NEGATIVE);
return failure_indicator;
}
if(item_ix>=state->t_item_count){
MARPA_ERROR(MARPA_ERR_AHFA_IX_OOB);
return failure_indicator;
}
return AIMID_of_AHFA_by_AEX(g,state,item_ix);
}

/*:425*//*426:*/
#line 4294 "./marpa.w"

int _marpa_g_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 4298 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 4299 "./marpa.w"

/*1158:*/
#line 13329 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1158*/
#line 4300 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:426*//*430:*/
#line 4316 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 4319 "./marpa.w"

AHFA state;
/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 4321 "./marpa.w"

/*1158:*/
#line 13329 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1158*/
#line 4322 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:430*//*433:*/
#line 4343 "./marpa.w"

PRIVATE_NOT_INLINE int AHFA_state_cmp(
const void*ap,
const void*bp,
void*param UNUSED)
{
AIM*items_a;
AIM*items_b;
const AHFA state_a= (AHFA)ap;
const AHFA state_b= (AHFA)bp;
const int length_a= state_a->t_item_count;
const int length_b= state_b->t_item_count;
int major_key= length_a-length_b;
if(major_key)return major_key;
{
int i,minor_key;
items_a= state_a->t_items;
items_b= state_b->t_items;
for(i= 0;i<length_a;i++)
{
minor_key= Sort_Key_of_AIM(items_a[i])-Sort_Key_of_AIM(items_b[i]);
if(minor_key)return minor_key;
}
}
return 0;
}

/*:433*//*453:*/
#line 4896 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,AVL_TREE duplicates)
{
const AHFA state_found= _marpa_avl_insert(duplicates,sought_state);
return state_found;
}

/*:453*//*464:*/
#line 5078 "./marpa.w"

PRIVATE_NOT_INLINE int
cmp_by_rule_sort_key(const void*ap,const void*bp)
{
RULE rule_a= *(RULE*)ap;
RULE rule_b= *(RULE*)bp;
unsigned int sort_key_a;
unsigned int sort_key_b;
Marpa_Rule_ID a_id= rule_a->t_id;
Marpa_Rule_ID b_id= rule_b->t_id;
SET_1ST_PASS_SORT_KEY_FOR_RULE_ID(sort_key_a,rule_a);
SET_1ST_PASS_SORT_KEY_FOR_RULE_ID(sort_key_b,rule_b);
if(sort_key_a==sort_key_b)return a_id-b_id;
return sort_key_a-sort_key_b;
}

/*:464*//*467:*/
#line 5145 "./marpa.w"

PRIVATE_NOT_INLINE AHFA
create_predicted_AHFA_state(
GRAMMAR g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
AVL_TREE duplicates,
AIM*item_list_working_buffer
)
{
AHFA p_new_state;
int item_list_ix= 0;
int no_of_items_in_new_state= bv_count(prediction_rule_vector);
if(no_of_items_in_new_state==0)return NULL;
{
unsigned int start,min,max;
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2)
{
unsigned int rule_sort_key;
for(rule_sort_key= min;rule_sort_key<=max;rule_sort_key++)
{

RULE rule= rule_by_sort_key[rule_sort_key];
item_list_working_buffer[item_list_ix++]= 
rule->t_first_aim;
}
}
}
p_new_state= DQUEUE_PUSH((*states_p),AHFA_Object);
AHFA_initialize(p_new_state);
p_new_state->t_items= item_list_working_buffer;
p_new_state->t_item_count= no_of_items_in_new_state;
{AHFA queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state){


(void)DQUEUE_POP((*states_p),AHFA_Object);
return queued_AHFA_state;
}
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE((*states_p),AHFA_Object);
{
int i;
AIM*const final_aim_list= p_new_state->t_items= 
my_obstack_alloc(&g->t_obs,no_of_items_in_new_state*sizeof(AIM));
for(i= 0;i<no_of_items_in_new_state;i++){
final_aim_list[i]= item_list_working_buffer[i];
}
}
AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_empty_transition= NULL;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
Complete_SYM_Count_of_AHFA(p_new_state)= 0;
/*468:*/
#line 5205 "./marpa.w"

{
SYMID symbol_count= SYM_Count_of_G(g);
int item_ix;
SYMID no_of_postdot_symbols;
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_working_buffer[item_ix];
SYMID postdot= Postdot_SYMID_of_AIM(item);
if(postdot>=0)
bv_bit_set(postdot_v,(unsigned int)postdot);
}
if((no_of_postdot_symbols= p_new_state->t_postdot_sym_count= 
bv_count(postdot_v)))
{
unsigned int min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->t_postdot_symid_ary= 
my_obstack_alloc(&g->t_obs,
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

/*:468*/
#line 5201 "./marpa.w"

return p_new_state;
}

/*:467*//*479:*/
#line 5314 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:479*//*480:*/
#line 5320 "./marpa.w"

PRIVATE int completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:480*//*481:*/
#line 5327 "./marpa.w"

PRIVATE
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,int aim_ix)
{
URTRANS transition;
transition= my_obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:481*//*482:*/
#line 5338 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g)
{
int symbol_count= SYM_Count_of_G(g);
int symid= 0;
TRANS*transitions;
transitions= my_malloc(symbol_count*sizeof(transitions[0]));
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:482*//*483:*/
#line 5351 "./marpa.w"

PRIVATE
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

/*:483*//*484:*/
#line 5365 "./marpa.w"

PRIVATE
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

/*:484*//*486:*/
#line 5380 "./marpa.w"

int _marpa_g_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
int*buffer,
int buffer_size
){

/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 5387 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
int symbol_count;
int ix= 0;
const int max_ix= buffer_size/sizeof(*buffer);
const int max_results= max_ix/2;





/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 5400 "./marpa.w"

/*1158:*/
#line 13329 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1158*/
#line 5401 "./marpa.w"

if(max_results<=0)return 0;
from_ahfa_state= AHFA_of_G_by_ID(g,AHFA_state_id);
transitions= TRANSs_of_AHFA(from_ahfa_state);
symbol_count= SYM_Count_of_G(g);
for(symid= 0;symid<symbol_count;symid++){
AHFA to_ahfa_state= To_AHFA_of_TRANS(transitions[symid]);
if(!to_ahfa_state)continue;
buffer[ix++]= symid;
buffer[ix++]= ID_of_AHFA(to_ahfa_state);
if(ix/2>=max_results)break;
}
return ix/2;
}

/*:486*//*489:*/
#line 5421 "./marpa.w"

AHFAID _marpa_g_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 5426 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 5427 "./marpa.w"

/*1158:*/
#line 13329 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1158*/
#line 5428 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:489*//*494:*/
#line 5464 "./marpa.w"

PRIVATE INPUT
input_new(GRAMMAR g)
{
INPUT input= my_slice_new(struct s_input);
my_obstack_init(TOK_Obs_of_I(input));
/*497:*/
#line 5477 "./marpa.w"

input->t_ref_count= 1;

/*:497*//*505:*/
#line 5536 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:505*/
#line 5470 "./marpa.w"

return input;
}

/*:494*//*498:*/
#line 5481 "./marpa.w"

PRIVATE void
input_unref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count--;
if(input->t_ref_count<=0)
{
input_free(input);
}
}

/*:498*//*499:*/
#line 5494 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:499*//*500:*/
#line 5507 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
my_obstack_free(TOK_Obs_of_I(input));
my_slice_free(struct s_input,input);
}

/*:500*//*509:*/
#line 5564 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
int symbol_count_of_g;
/*1150:*/
#line 13290 "./marpa.w"
void*const failure_indicator= NULL;
/*:1150*/
#line 5569 "./marpa.w"

/*1153:*/
#line 13304 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1153*/
#line 5570 "./marpa.w"

r= my_slice_new(struct marpa_r);
symbol_count_of_g= SYM_Count_of_G(g);
/*569:*/
#line 5934 "./marpa.w"
my_obstack_init(&r->t_obs);
/*:569*/
#line 5573 "./marpa.w"

/*512:*/
#line 5580 "./marpa.w"

r->t_ref_count= 1;

/*:512*//*520:*/
#line 5650 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:520*//*522:*/
#line 5659 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:522*//*526:*/
#line 5683 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:526*//*530:*/
#line 5706 "./marpa.w"
r->t_furthest_earleme= 0;
/*:530*//*534:*/
#line 5719 "./marpa.w"
r->t_sym_workarea= NULL;
/*:534*//*538:*/
#line 5730 "./marpa.w"
r->t_workarea2= NULL;
/*:538*//*542:*/
#line 5750 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:542*//*546:*/
#line 5773 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:546*//*561:*/
#line 5874 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:561*//*565:*/
#line 5910 "./marpa.w"
r->t_is_exhausted= 0;
/*:565*//*589:*/
#line 6032 "./marpa.w"

r->t_earley_set_count= 0;

/*:589*//*594:*/
#line 6078 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:594*//*615:*/
#line 6340 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:615*//*645:*/
#line 6722 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:645*//*680:*/
#line 7181 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:680*//*713:*/
#line 7666 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:713*//*717:*/
#line 7700 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:717*//*738:*/
#line 8008 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:738*//*742:*/
#line 8019 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:742*//*746:*/
#line 8030 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:746*//*815:*/
#line 8884 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:815*//*1116:*/
#line 12951 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1116*/
#line 5574 "./marpa.w"

return r;
}

/*:509*//*513:*/
#line 5584 "./marpa.w"

PRIVATE void
recce_unref(RECCE r)
{
MARPA_ASSERT(r->t_ref_count> 0)
r->t_ref_count--;
if(r->t_ref_count<=0)
{
recce_free(r);
}
}
void
marpa_r_unref(Marpa_Recognizer r)
{
recce_unref(r);
}

/*:513*//*514:*/
#line 5602 "./marpa.w"

PRIVATE
RECCE recce_ref(RECCE r)
{
MARPA_ASSERT(r->t_ref_count> 0)
r->t_ref_count++;
return r;
}
Marpa_Recognizer
marpa_r_ref(Marpa_Recognizer r)
{
return recce_ref(r);
}

/*:514*//*515:*/
#line 5616 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5620 "./marpa.w"

/*517:*/
#line 5637 "./marpa.w"
input_unref(input);

/*:517*//*591:*/
#line 6056 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
my_free(EIMs_of_ES(set));
}
}

/*:591*//*718:*/
#line 7702 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:718*//*740:*/
#line 8012 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:740*//*744:*/
#line 8023 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:744*//*747:*/
#line 8031 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:747*//*816:*/
#line 8886 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:816*//*1117:*/
#line 12953 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1117*/
#line 5621 "./marpa.w"

grammar_unref(g);
my_free(r->t_sym_workarea);
my_free(r->t_workarea2);
/*544:*/
#line 5759 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:544*//*548:*/
#line 5776 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:548*/
#line 5625 "./marpa.w"

/*570:*/
#line 5935 "./marpa.w"
my_obstack_free(&r->t_obs);

/*:570*/
#line 5626 "./marpa.w"

my_slice_free(struct marpa_r,r);
}

/*:515*//*523:*/
#line 5667 "./marpa.w"

unsigned int marpa_r_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:523*//*524:*/
#line 5672 "./marpa.w"

PRIVATE ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:524*//*527:*/
#line 5685 "./marpa.w"

int marpa_r_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:527*//*528:*/
#line 5691 "./marpa.w"

int marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,int threshold)
{
r->t_earley_item_warning_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
return 1;
}

/*:528*//*531:*/
#line 5707 "./marpa.w"

unsigned int marpa_r_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:531*//*550:*/
#line 5791 "./marpa.w"

int marpa_r_terminals_expected(struct marpa_r*r,Marpa_Symbol_ID*buffer)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 5794 "./marpa.w"

/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5795 "./marpa.w"

unsigned int min,max,start;
int ix= 0;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 5798 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 5799 "./marpa.w"

for(start= 0;bv_scan(r->t_bv_symid_is_expected,start,&min,&max);
start= max+2)
{
SYMID symid;
for(symid= (SYMID)min;symid<=(SYMID)max;symid++)
{
buffer[ix++]= symid;
}
}
return ix;
}

/*:550*//*562:*/
#line 5880 "./marpa.w"

int marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5883 "./marpa.w"

/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 5884 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 5885 "./marpa.w"

return r->t_use_leo_flag;
}
/*:562*//*563:*/
#line 5888 "./marpa.w"

int marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5892 "./marpa.w"

/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 5893 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 5894 "./marpa.w"

/*1159:*/
#line 13338 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1159*/
#line 5895 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:563*//*567:*/
#line 5920 "./marpa.w"

int marpa_r_is_exhausted(struct marpa_r*r)
{
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5923 "./marpa.w"

/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 5924 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 5925 "./marpa.w"

return R_is_Exhausted(r);
}

/*:567*//*572:*/
#line 5939 "./marpa.w"

Marpa_Error_Code marpa_r_error(Marpa_Recognizer r,const char**p_error_string)
{
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5942 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:572*//*574:*/
#line 5948 "./marpa.w"

int marpa_r_event(Marpa_Recognizer r,Marpa_Event public_event,int ix)
{
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5951 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:574*//*590:*/
#line 6036 "./marpa.w"

PRIVATE ES
earley_set_new(RECCE r,EARLEME id)
{
ESK_Object key;
ES set;
set= my_obstack_alloc(&r->t_obs,sizeof(*set));
key.t_earleme= id;
set->t_key= key;
set->t_postdot_ary= NULL;
set->t_postdot_sym_count= 0;
EIM_Count_of_ES(set)= 0;
set->t_ordinal= r->t_earley_set_count++;
EIMs_of_ES(set)= NULL;
Next_ES_of_ES(set)= NULL;
/*1122:*/
#line 12997 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1122*/
#line 6051 "./marpa.w"

return set;
}

/*:590*//*595:*/
#line 6081 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6084 "./marpa.w"

/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6085 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6087 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:595*//*596:*/
#line 6095 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6098 "./marpa.w"

/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6099 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6100 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:596*//*597:*/
#line 6104 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const int es_does_not_exist= -1;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6108 "./marpa.w"

/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6109 "./marpa.w"

ES earley_set;
/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 6111 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 6112 "./marpa.w"

if(set_id<0){
MARPA_ERROR(MARPA_ERR_INVALID_ES_ORDINAL);
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

/*:597*//*599:*/
#line 6128 "./marpa.w"

int marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6131 "./marpa.w"

ES earley_set;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6133 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 6134 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 6135 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_ES_ORDINAL);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:599*//*608:*/
#line 6231 "./marpa.w"

PRIVATE EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1150:*/
#line 13290 "./marpa.w"
void*const failure_indicator= NULL;
/*:1150*/
#line 6235 "./marpa.w"

/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6236 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const int count= ++EIM_Count_of_ES(set);
/*610:*/
#line 6283 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_EIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:610*/
#line 6241 "./marpa.w"

new_item= my_obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:608*//*609:*/
#line 6251 "./marpa.w"

PRIVATE EIM
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

/*:609*//*613:*/
#line 6315 "./marpa.w"

PRIVATE_NOT_INLINE Marpa_Error_Code invalid_source_type_code(unsigned int type)
{
switch(type){
case NO_SOURCE:
return MARPA_ERR_SOURCE_TYPE_IS_NONE;
case SOURCE_IS_TOKEN:
return MARPA_ERR_SOURCE_TYPE_IS_TOKEN;
case SOURCE_IS_COMPLETION:
return MARPA_ERR_SOURCE_TYPE_IS_COMPLETION;
case SOURCE_IS_LEO:
return MARPA_ERR_SOURCE_TYPE_IS_LEO;
case SOURCE_IS_AMBIGUOUS:
return MARPA_ERR_SOURCE_TYPE_IS_AMBIGUOUS;
}
return MARPA_ERR_SOURCE_TYPE_IS_UNKNOWN;
}

/*:613*//*620:*/
#line 6380 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const int es_does_not_exist= -1;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6386 "./marpa.w"

/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6387 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6388 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*621:*/
#line 6411 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*647:*/
#line 6761 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:647*/
#line 6414 "./marpa.w"

}

/*:621*/
#line 6395 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_ES_ORDINAL);
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

/*:620*//*622:*/
#line 6417 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const int eim_does_not_exist= -1;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6422 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6426 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6427 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*621:*/
#line 6411 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*647:*/
#line 6761 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:647*/
#line 6414 "./marpa.w"

}

/*:621*/
#line 6431 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
trace_earley_item_clear(r);
if(item_id<0)
{
MARPA_ERROR(MARPA_ERR_EIM_ID_INVALID);
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

/*:622*//*624:*/
#line 6460 "./marpa.w"

PRIVATE void trace_earley_item_clear(struct marpa_r*r)
{
/*623:*/
#line 6457 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:623*/
#line 6463 "./marpa.w"

trace_source_link_clear(r);
}

/*:624*//*625:*/
#line 6467 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6470 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6472 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6473 "./marpa.w"

if(!item){
/*623:*/
#line 6457 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:623*/
#line 6475 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:625*//*632:*/
#line 6548 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6552 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6555 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6556 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item)){
MARPA_ERROR(MARPA_ERR_PIM_IS_NOT_LIM);
return failure_indicator;
}
predecessor_leo_item= Predecessor_LIM_of_LIM(LIM_of_PIM(postdot_item));
if(!predecessor_leo_item)return no_predecessor;
return Postdot_SYMID_of_LIM(predecessor_leo_item);
}

/*:632*//*633:*/
#line 6570 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6574 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6576 "./marpa.w"

EIM base_earley_item;
/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6578 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:633*//*634:*/
#line 6588 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6592 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6595 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6596 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:634*//*638:*/
#line 6630 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6634 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6636 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6637 "./marpa.w"

if(!postdot_item)
{
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
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


/*:638*//*642:*/
#line 6686 "./marpa.w"

PRIVATE PIM*
pim_sym_p_find(ES set,SYMID symid)
{
int lo= 0;
int hi= Postdot_SYM_Count_of_ES(set)-1;
PIM*postdot_array= set->t_postdot_ary;
while(hi>=lo){
int trial= lo+(hi-lo)/2;
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
/*:642*//*643:*/
#line 6706 "./marpa.w"

PRIVATE PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:643*//*646:*/
#line 6736 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6741 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6745 "./marpa.w"

/*647:*/
#line 6761 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:647*/
#line 6746 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6747 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 6748 "./marpa.w"

if(!current_es){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
pim_sym_p= PIM_SYM_P_of_ES_by_SYMID(current_es,symid);
pim= *pim_sym_p;
if(!pim)return-1;
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return symid;
}

/*:646*//*648:*/
#line 6771 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6775 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6778 "./marpa.w"

PIM*pim_sym_p;
/*647:*/
#line 6761 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:647*/
#line 6780 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6781 "./marpa.w"

if(!current_earley_set){
/*623:*/
#line 6457 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:623*/
#line 6783 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
if(current_earley_set->t_postdot_sym_count<=0)return-1;
pim_sym_p= current_earley_set->t_postdot_ary+0;
pim= pim_sym_p[0];
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return Postdot_SYMID_of_PIM(pim);
}

/*:648*//*649:*/
#line 6802 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6807 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6811 "./marpa.w"


pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*647:*/
#line 6761 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:647*/
#line 6815 "./marpa.w"

if(!pim_sym_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6820 "./marpa.w"

if(!current_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
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

/*:649*//*650:*/
#line 6840 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_postdot_item_symbol(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 6843 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6845 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 6846 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:650*//*666:*/
#line 6974 "./marpa.w"
PRIVATE
void
token_link_add(RECCE r,
EIM item,
EIM predecessor,
TOK token)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_EIM(item);
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
new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Token_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
TOK_of_Source(new_link->t_source)= token;
First_Token_Link_of_EIM(item)= new_link;
}

/*:666*//*671:*/
#line 7050 "./marpa.w"

PRIVATE
void
completion_link_add(RECCE r,
EIM item,
EIM predecessor,
EIM cause)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_EIM(item);
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
new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Completion_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
First_Completion_Link_of_EIM(item)= new_link;
}

/*:671*//*672:*/
#line 7078 "./marpa.w"

PRIVATE void
leo_link_add(RECCE r,
EIM item,
LIM predecessor,
EIM cause)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_EIM(item);
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
new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Leo_SRCL_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
First_Leo_SRCL_of_EIM(item)= new_link;
}

/*:672*//*674:*/
#line 7125 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*675:*/
#line 7142 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= new_link;
}

/*:675*/
#line 7133 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*676:*/
#line 7151 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= new_link;
First_Token_Link_of_EIM(item)= NULL;
}

/*:676*/
#line 7135 "./marpa.w"

return;
case SOURCE_IS_LEO:/*677:*/
#line 7160 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= new_link;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= NULL;
}

/*:677*/
#line 7137 "./marpa.w"

return;
}
}

/*:674*//*682:*/
#line 7192 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7195 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7199 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7200 "./marpa.w"

/*696:*/
#line 7419 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:696*/
#line 7201 "./marpa.w"

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

/*:682*//*685:*/
#line 7236 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7239 "./marpa.w"

SRCL full_link;
EIM item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7242 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7243 "./marpa.w"

/*696:*/
#line 7419 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:696*/
#line 7244 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_TOKEN){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NOT_TRACING_TOKEN_LINKS);
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

/*:685*//*687:*/
#line 7267 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7270 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7274 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7275 "./marpa.w"

/*696:*/
#line 7419 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:696*/
#line 7276 "./marpa.w"

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

/*:687*//*690:*/
#line 7310 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7313 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7317 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7318 "./marpa.w"

/*696:*/
#line 7419 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:696*/
#line 7319 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_COMPLETION){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NOT_TRACING_COMPLETION_LINKS);
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

/*:690*//*692:*/
#line 7343 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_leo_link_trace(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7347 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7351 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7352 "./marpa.w"

/*696:*/
#line 7419 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:696*/
#line 7353 "./marpa.w"

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

/*:692*//*695:*/
#line 7389 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_leo_link_trace(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7393 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7397 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7398 "./marpa.w"

/*696:*/
#line 7419 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:696*/
#line 7399 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_LEO)
{
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NOT_TRACING_LEO_LINKS);
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

/*:695*//*697:*/
#line 7428 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:697*//*698:*/
#line 7444 "./marpa.w"

AHFAID marpa_r_source_predecessor_state(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7447 "./marpa.w"

unsigned int source_type;
SRC source;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7450 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7451 "./marpa.w"

source_type= r->t_trace_source_type;
/*705:*/
#line 7595 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:705*/
#line 7453 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:{
EIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return-1;
return AHFAID_of_EIM(predecessor);
}
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:698*//*699:*/
#line 7485 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,int*value_p)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7488 "./marpa.w"

unsigned int source_type;
SRC source;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7491 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7492 "./marpa.w"

source_type= r->t_trace_source_type;
/*705:*/
#line 7595 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:705*/
#line 7494 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:699*//*701:*/
#line 7517 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7520 "./marpa.w"

unsigned int source_type;
SRC source;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7523 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7524 "./marpa.w"

source_type= r->t_trace_source_type;
/*705:*/
#line 7595 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:705*/
#line 7526 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:701*//*704:*/
#line 7563 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7566 "./marpa.w"

const EARLEME no_predecessor= -1;
unsigned int source_type;
SRC source;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7570 "./marpa.w"

/*1162:*/
#line 13354 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 13355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 13356 "./marpa.w"


/*:1162*/
#line 7571 "./marpa.w"

source_type= r->t_trace_source_type;
/*705:*/
#line 7595 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:705*/
#line 7573 "./marpa.w"

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
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:704*//*720:*/
#line 7708 "./marpa.w"

PRIVATE int
alternative_insertion_point(RECCE r,ALT new_alternative)
{
DSTACK alternatives= &r->t_alternatives;
ALT alternative;
int hi= DSTACK_LENGTH(*alternatives)-1;
int lo= 0;
int trial;

if(hi<0)
return 0;
alternative= DSTACK_BASE(*alternatives,ALT_Object);
for(;;)
{
int outcome;
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

/*:720*//*722:*/
#line 7752 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:722*//*723:*/
#line 7769 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:723*//*724:*/
#line 7784 "./marpa.w"

PRIVATE int alternative_insert(RECCE r,ALT new_alternative)
{
ALT top_of_stack,base_of_stack;
DSTACK alternatives= &r->t_alternatives;
int ix;
int insertion_point= alternative_insertion_point(r,new_alternative);
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

/*:724*//*725:*/
#line 7803 "./marpa.w"
int marpa_r_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7809 "./marpa.w"

const int symbol_count_of_g= SYM_Count_of_G(g);
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7811 "./marpa.w"

/*1159:*/
#line 13338 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1159*/
#line 7812 "./marpa.w"

Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g)){
/*566:*/
#line 5911 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:566*/
#line 7815 "./marpa.w"

return 1;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
/*539:*/
#line 5731 "./marpa.w"

{
const unsigned int sym_workarea_size= sizeof(void*)*symbol_count_of_g;
/*535:*/
#line 5720 "./marpa.w"

r->t_sym_workarea= my_malloc(sym_workarea_size);

/*:535*/
#line 5734 "./marpa.w"

r->t_workarea2= my_malloc(2u*sym_workarea_size);
}

/*:539*/
#line 7819 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*543:*/
#line 5754 "./marpa.w"
{
r->t_bv_sym= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym2= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym3= bv_create((unsigned int)symbol_count_of_g);
}
/*:543*//*547:*/
#line 5774 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((unsigned int)symbol_count_of_g);
/*:547*/
#line 7821 "./marpa.w"

/*739:*/
#line 8009 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT2(r->t_eim_work_stack,EIM);
/*:739*//*743:*/
#line 8020 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT2(r->t_completion_stack,EIM);
/*:743*/
#line 7822 "./marpa.w"

set0= earley_set_new(r,0);
Latest_ES_of_R(r)= set0;
First_ES_of_R(r)= set0;
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
return 1;
}

/*:725*//*732:*/
#line 7890 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID token_id,
int value,
int length)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 7897 "./marpa.w"

/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7898 "./marpa.w"

const int duplicate_token_indicator= -3;
const int unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1161:*/
#line 13348 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1161*/
#line 7904 "./marpa.w"

/*733:*/
#line 7912 "./marpa.w"
{
const XSY_Const token= SYM_by_ID(token_id);
if(!SYM_is_Terminal(token)){
MARPA_ERROR(MARPA_ERR_TOKEN_IS_NOT_TERMINAL);
return failure_indicator;
}
if(length<=0){
MARPA_ERROR(MARPA_ERR_TOKEN_LENGTH_LE_ZERO);
return failure_indicator;
}
if(length>=EARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_TOKEN_TOO_LONG);
return failure_indicator;
}
}

/*:733*/
#line 7905 "./marpa.w"

/*735:*/
#line 7943 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:735*/
#line 7906 "./marpa.w"

/*734:*/
#line 7928 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return failure_indicator;
}
}

/*:734*/
#line 7907 "./marpa.w"

/*736:*/
#line 7966 "./marpa.w"

{
TOK token;
ALT_Object alternative;
struct obstack*const token_obstack= TOK_Obs_of_I(input);
if(value)
{
my_obstack_blank(TOK_Obs_of_I(input),sizeof(*token));
token= my_obstack_base(token_obstack);
SYMID_of_TOK(token)= token_id;
Type_of_TOK(token)= VALUED_TOKEN_OR_NODE;
Value_of_TOK(token)= value;
}
else
{
my_obstack_blank(TOK_Obs_of_I(input),sizeof(token->t_unvalued));
token= my_obstack_base(token_obstack);
SYMID_of_TOK(token)= token_id;
Type_of_TOK(token)= UNVALUED_TOKEN_OR_NODE;
}
if(Furthest_Earleme_of_R(r)<target_earleme)
Furthest_Earleme_of_R(r)= target_earleme;
alternative.t_token= token;
alternative.t_start_earley_set= current_earley_set;
alternative.t_end_earleme= target_earleme;
if(alternative_insert(r,&alternative)<0)
{
my_obstack_reject(token_obstack);
return duplicate_token_indicator;
}
token= my_obstack_finish(token_obstack);
}

/*:736*/
#line 7908 "./marpa.w"

return current_earleme;
}

/*:732*//*749:*/
#line 8050 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(struct marpa_r*r)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 8054 "./marpa.w"

/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 8055 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
int count_of_expected_terminals;
/*1161:*/
#line 13348 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1161*/
#line 8060 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*750:*/
#line 8088 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*566:*/
#line 5911 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:566*/
#line 8092 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:750*/
#line 8064 "./marpa.w"

/*752:*/
#line 8113 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:752*/
#line 8065 "./marpa.w"

/*751:*/
#line 8100 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:751*/
#line 8066 "./marpa.w"

/*753:*/
#line 8119 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*754:*/
#line 8126 "./marpa.w"

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

/*:754*/
#line 8123 "./marpa.w"

}

/*:753*/
#line 8067 "./marpa.w"

/*755:*/
#line 8153 "./marpa.w"
{
EIM*work_earley_items= DSTACK_BASE(r->t_eim_work_stack,EIM);
int no_of_work_earley_items= DSTACK_LENGTH(r->t_eim_work_stack);
int ix;
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

/*:755*/
#line 8068 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*756:*/
#line 8172 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
int count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
int symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*757:*/
#line 8185 "./marpa.w"

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
/*758:*/
#line 8208 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*759:*/
#line 8224 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:759*/
#line 8217 "./marpa.w"

}
/*760:*/
#line 8231 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:760*/
#line 8219 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:758*/
#line 8196 "./marpa.w"

}
else
{
/*761:*/
#line 8241 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*759:*/
#line 8224 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:759*/
#line 8250 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:761*/
#line 8200 "./marpa.w"

break;


}
}
}

/*:757*/
#line 8181 "./marpa.w"

}
}

/*:756*/
#line 8071 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


/*566:*/
#line 5911 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:566*/
#line 8081 "./marpa.w"

event_new(g,MARPA_EVENT_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:749*//*762:*/
#line 8255 "./marpa.w"

PRIVATE void earley_set_update_items(RECCE r,ES set)
{
EIM*working_earley_items;
EIM*finished_earley_items;
int working_earley_item_count;
int i;
EIMs_of_ES(set)= my_renew(EIM,EIMs_of_ES(set),EIM_Count_of_ES(set));
finished_earley_items= EIMs_of_ES(set);
working_earley_items= Work_EIMs_of_R(r);
working_earley_item_count= Work_EIM_Count_of_R(r);
for(i= 0;i<working_earley_item_count;i++){
EIM earley_item= working_earley_items[i];
int ordinal= Ord_of_EIM(earley_item);
finished_earley_items[ordinal]= earley_item;
}
WORK_EIMS_CLEAR(r);
}

/*:762*//*763:*/
#line 8276 "./marpa.w"

PRIVATE void r_update_earley_sets(RECCE r)
{
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

/*:763*//*769:*/
#line 8320 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,ES current_earley_set)
{
void**const pim_workarea= r->t_sym_workarea;
/*516:*/
#line 5634 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 8325 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*770:*/
#line 8342 "./marpa.w"
{
EIM*work_earley_items= DSTACK_BASE(r->t_eim_work_stack,EIM);
int no_of_work_earley_items= DSTACK_LENGTH(r->t_eim_work_stack);
int ix;
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
EIM earley_item= work_earley_items[ix];
AHFA state= AHFA_of_EIM(earley_item);
int symbol_ix;
int postdot_symbol_count= Postdot_SYM_Count_of_AHFA(state);
Marpa_Symbol_ID*postdot_symbols= 
Postdot_SYMID_Ary_of_AHFA(state);
for(symbol_ix= 0;symbol_ix<postdot_symbol_count;symbol_ix++)
{
PIM old_pim= NULL;
PIM new_pim;
Marpa_Symbol_ID symid;
new_pim= my_obstack_alloc(&r->t_obs,sizeof(EIX_Object));
symid= postdot_symbols[symbol_ix];
Postdot_SYMID_of_PIM(new_pim)= symid;
EIM_of_PIM(new_pim)= earley_item;
if(bv_bit_test(bv_pim_symbols,(unsigned int)symid))
old_pim= pim_workarea[symid];
Next_PIM_of_PIM(new_pim)= old_pim;
if(!old_pim)current_earley_set->t_postdot_sym_count++;
pim_workarea[symid]= new_pim;
bv_bit_set(bv_pim_symbols,(unsigned int)symid);
}
}
}

/*:770*/
#line 8331 "./marpa.w"

if(r->t_is_using_leo){
/*774:*/
#line 8400 "./marpa.w"

{
unsigned int min,max,start;
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
if(EIM_is_Potential_Leo_Base(leo_base))
{
AHFA base_to_ahfa= 
To_AHFA_of_EIM_by_SYMID(leo_base,symid);
if(AHFA_is_Leo_Completion(base_to_ahfa))
{
/*775:*/
#line 8434 "./marpa.w"
{
LIM new_lim;
new_lim= my_obstack_alloc(&r->t_obs,sizeof(*new_lim));
Postdot_SYMID_of_LIM(new_lim)= symid;
EIM_of_PIM(new_lim)= NULL;
Predecessor_LIM_of_LIM(new_lim)= NULL;
Origin_of_LIM(new_lim)= NULL;
Chain_Length_of_LIM(new_lim)= -1;
Top_AHFA_of_LIM(new_lim)= base_to_ahfa;
Base_EIM_of_LIM(new_lim)= leo_base;
ES_of_LIM(new_lim)= current_earley_set;
Next_PIM_of_LIM(new_lim)= this_pim;
pim_workarea[symid]= new_lim;
bv_bit_set(bv_lim_symbols,(unsigned int)symid);
}

/*:775*/
#line 8420 "./marpa.w"

}
}
}
}
}
}

/*:774*/
#line 8333 "./marpa.w"

/*784:*/
#line 8519 "./marpa.w"
{
const Bit_Vector bv_ok_for_chain= r->t_bv_sym3;
unsigned int min,max,start;

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

/*787:*/
#line 8578 "./marpa.w"
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

/*:787*/
#line 8537 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*793:*/
#line 8670 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:793*/
#line 8539 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*795:*/
#line 8691 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:795*/
#line 8545 "./marpa.w"

continue;
}
/*788:*/
#line 8593 "./marpa.w"
{
void**const lim_chain= r->t_workarea2;
int lim_chain_ix;
/*791:*/
#line 8614 "./marpa.w"
{
SYMID postdot_symid_of_lim_to_process
= Postdot_SYMID_of_LIM(lim_to_process);
lim_chain_ix= 0;
lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);
bv_bit_clear(bv_ok_for_chain,(unsigned int)postdot_symid_of_lim_to_process);


while(1){
lim_to_process= predecessor_lim;






postdot_symid_of_lim_to_process= Postdot_SYMID_of_LIM(lim_to_process);
if(!bv_bit_test(bv_ok_for_chain,(unsigned int)postdot_symid_of_lim_to_process)){





break;
}

/*787:*/
#line 8578 "./marpa.w"
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

/*:787*/
#line 8640 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(unsigned int)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:791*/
#line 8596 "./marpa.w"

/*792:*/
#line 8659 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*793:*/
#line 8670 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:793*/
#line 8663 "./marpa.w"

}else{
/*795:*/
#line 8691 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:795*/
#line 8665 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:792*/
#line 8597 "./marpa.w"

}

/*:788*/
#line 8548 "./marpa.w"

}
}
}

/*:784*/
#line 8334 "./marpa.w"

}
/*796:*/
#line 8697 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= my_obstack_alloc(&r->t_obs,
current_earley_set->t_postdot_sym_count*sizeof(PIM));
unsigned int min,max,start;
int postdot_array_ix= 0;
for(start= 0;bv_scan(bv_pim_symbols,start,&min,&max);start= max+2){
SYMID symid;
for(symid= (SYMID)min;symid<=(SYMID)max;symid++){
PIM this_pim= pim_workarea[symid];
if(this_pim)postdot_array[postdot_array_ix++]= this_pim;
}
}
}

/*:796*/
#line 8336 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:769*//*817:*/
#line 8889 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
my_obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:817*//*818:*/
#line 8897 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:818*//*819:*/
#line 8903 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)my_obstack_free(&stack->t_obs);
stack->t_base= NULL;
}

/*:819*//*820:*/
#line 8910 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= my_obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:820*//*821:*/
#line 8920 "./marpa.w"

PRIVATE void
ur_node_push(URS stack,EIM earley_item,AEX aex)
{
UR top= stack->t_top;
UR new_top= Next_UR_of_UR(top);
EIM_of_UR(top)= earley_item;
AEX_of_UR(top)= aex;
if(!new_top)
{
new_top= ur_node_new(stack,top);
Next_UR_of_UR(top)= new_top;
}
stack->t_top= new_top;
}

/*:821*//*822:*/
#line 8936 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:822*//*826:*/
#line 8999 "./marpa.w"

PRIVATE int psia_test_and_set(
struct obstack*obs,
struct s_bocage_setup_per_es*per_es_data,
EIM earley_item,
AEX ahfa_element_ix)
{
const int aim_count_of_item= AIM_Count_of_EIM(earley_item);
const Marpa_Earley_Set_ID set_ordinal= ES_Ord_of_EIM(earley_item);
OR**nodes_by_item= per_es_data[set_ordinal].t_aexes_by_item;
const int item_ordinal= Ord_of_EIM(earley_item);
OR*nodes_by_aex= nodes_by_item[item_ordinal];
MARPA_ASSERT(ahfa_element_ix<aim_count_of_item)
if(!nodes_by_aex){
AEX aex;
nodes_by_aex= nodes_by_item[item_ordinal]= 
my_obstack_alloc(obs,aim_count_of_item*sizeof(OR));
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

/*:826*//*862:*/
#line 9599 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:862*//*863:*/
#line 9611 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:863*//*869:*/
#line 9726 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= my_obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:869*//*871:*/
#line 9749 "./marpa.w"

PRIVATE
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:871*//*898:*/
#line 10186 "./marpa.w"

int marpa_b_and_node_count(Marpa_Bocage b)
{
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10189 "./marpa.w"

/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10190 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10191 "./marpa.w"

return AND_Count_of_B(b);
}

/*:898*//*900:*/
#line 10212 "./marpa.w"

int marpa_b_and_node_parent(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10216 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10217 "./marpa.w"

/*899:*/
#line 10195 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
if(and_node_id<0){
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:899*/
#line 10218 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:900*//*901:*/
#line 10222 "./marpa.w"

int marpa_b_and_node_predecessor(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10226 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10227 "./marpa.w"

/*899:*/
#line 10195 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
if(and_node_id<0){
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:899*/
#line 10228 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:901*//*902:*/
#line 10237 "./marpa.w"

int marpa_b_and_node_cause(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10241 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10242 "./marpa.w"

/*899:*/
#line 10195 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
if(and_node_id<0){
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:899*/
#line 10243 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:902*//*903:*/
#line 10252 "./marpa.w"

int marpa_b_and_node_symbol(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10256 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10257 "./marpa.w"

/*899:*/
#line 10195 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
if(and_node_id<0){
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:899*/
#line 10258 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:903*//*904:*/
#line 10267 "./marpa.w"

Marpa_Symbol_ID marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK token;
AND and_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10273 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10274 "./marpa.w"

/*899:*/
#line 10195 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
if(and_node_id<0){
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:899*/
#line 10275 "./marpa.w"

token= and_node_token(and_node);
if(token){
if(value_p)
*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
return-1;
}
/*:904*//*905:*/
#line 10284 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:905*//*919:*/
#line 10348 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1150:*/
#line 13290 "./marpa.w"
void*const failure_indicator= NULL;
/*:1150*/
#line 10352 "./marpa.w"

/*920:*/
#line 10391 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int rule_count_of_g= RULE_Count_of_G(g);
const int symbol_count_of_g= SYM_Count_of_G(g);
BOCAGE b= NULL;
ES end_of_parse_earley_set;
EARLEME end_of_parse_earleme;
EIM start_eim= NULL;
AIM start_aim= NULL;
AEX start_aex= -1;
struct obstack bocage_setup_obs;
int total_earley_items_in_parse;
int or_node_estimate= 0;
const int earley_set_count_of_r= ES_Count_of_R(r);

/*:920*//*923:*/
#line 10414 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:923*/
#line 10353 "./marpa.w"

INPUT input;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10355 "./marpa.w"

/*1160:*/
#line 13343 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1160*/
#line 10356 "./marpa.w"

b= my_slice_new(*b);
/*849:*/
#line 9357 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;

/*:849*//*915:*/
#line 10327 "./marpa.w"

b->t_is_obstack_initialized= 1;
my_obstack_init(&OBS_of_B(b));
/*:915*//*938:*/
#line 10598 "./marpa.w"

b->t_ref_count= 1;

/*:938*/
#line 10358 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto NO_PARSE;
return r_create_null_bocage(r,b);
}
r_update_earley_sets(r);
/*924:*/
#line 10417 "./marpa.w"

{
if(ordinal_arg==-1)
{
end_of_parse_earley_set= Current_ES_of_R(r);
}
else
{
if(!ES_Ord_is_Valid(r,ordinal_arg))
{
MARPA_ERROR(MARPA_ERR_INVALID_ES_ORDINAL);
return failure_indicator;
}
end_of_parse_earley_set= ES_of_R_by_Ord(r,ordinal_arg);
}

if(!end_of_parse_earley_set)
goto NO_PARSE;
end_of_parse_earleme= Earleme_of_ES(end_of_parse_earley_set);
}

/*:924*/
#line 10367 "./marpa.w"

if(end_of_parse_earleme==0){
if(!g->t_null_start_rule)goto NO_PARSE;
return r_create_null_bocage(r,b);
}
/*930:*/
#line 10528 "./marpa.w"

{
int eim_ix;
EIM*const earley_items= EIMs_of_ES(end_of_parse_earley_set);
const RULEID sought_rule_id= ID_of_RULE(g->t_proper_start_rule);
const int earley_item_count= EIM_Count_of_ES(end_of_parse_earley_set);
for(eim_ix= 0;eim_ix<earley_item_count;eim_ix++){
const EIM earley_item= earley_items[eim_ix];
const AHFA ahfa_state= AHFA_of_EIM(earley_item);
if(Origin_Earleme_of_EIM(earley_item)> 0)continue;
if(!AHFA_is_Predicted(ahfa_state)){
int aex;
AIM*const ahfa_items= AIMs_of_AHFA(ahfa_state);
const int ahfa_item_count= AIM_Count_of_AHFA(ahfa_state);
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

/*:930*/
#line 10372 "./marpa.w"

if(!start_eim)goto NO_PARSE;
my_obstack_init(&bocage_setup_obs);
/*927:*/
#line 10476 "./marpa.w"

{
unsigned int ix;
unsigned int earley_set_count= ES_Count_of_R(r);
total_earley_items_in_parse= 0;
per_es_data= 
my_obstack_alloc(&bocage_setup_obs,
sizeof(struct s_bocage_setup_per_es)*earley_set_count);
for(ix= 0;ix<earley_set_count;ix++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,ix);
const unsigned int item_count= EIM_Count_of_ES(earley_set);
total_earley_items_in_parse+= item_count;
{
struct s_bocage_setup_per_es*per_es= per_es_data+ix;
OR**const per_eim_eixes= per_es->t_aexes_by_item= 
my_obstack_alloc(&bocage_setup_obs,sizeof(OR*)*item_count);
unsigned int item_ordinal;
per_es->t_or_psl= NULL;
per_es->t_and_psl= NULL;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
per_eim_eixes[item_ordinal]= NULL;
}
}
}
}

/*:927*/
#line 10375 "./marpa.w"

/*824:*/
#line 8958 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*825:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:825*/
#line 8967 "./marpa.w"

}
while((ur_node= ur_node_pop(ur_node_stack)))
{
const EIM_Const parent_earley_item= EIM_of_UR(ur_node);
const AEX parent_aex= AEX_of_UR(ur_node);
const AIM parent_aim= AIM_of_EIM_by_AEX(parent_earley_item,parent_aex);
MARPA_ASSERT(parent_aim>=AIM_by_ID(1))
const AIM predecessor_aim= parent_aim-1;


unsigned int source_type= Source_Type_of_EIM(parent_earley_item);
MARPA_ASSERT(!EIM_is_Predicted(parent_earley_item))
/*827:*/
#line 9027 "./marpa.w"

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
Set_boolean_in_PSIA_for_initial_nulls(predecessor_earley_item,predecessor_aim);
}else{
const EIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
/*825:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:825*/
#line 9055 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:827*/
#line 8980 "./marpa.w"

/*829:*/
#line 9085 "./marpa.w"

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
Set_boolean_in_PSIA_for_initial_nulls(predecessor_earley_item,predecessor_aim);
}
else
{
const EIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
/*825:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:825*/
#line 9121 "./marpa.w"

}
}
{
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
const EIM ur_earley_item= cause_earley_item;
int ix;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*825:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:825*/
#line 9134 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:829*/
#line 8981 "./marpa.w"

/*830:*/
#line 9144 "./marpa.w"

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
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
int ix;
EIM ur_earley_item= cause_earley_item;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*825:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:825*/
#line 9177 "./marpa.w"

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
Set_boolean_in_PSIA_for_initial_nulls(ur_earley_item,ur_aim);
}else{
/*825:*/
#line 8986 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:825*/
#line 9193 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:830*/
#line 8982 "./marpa.w"

}
}

/*:824*/
#line 10376 "./marpa.w"

/*851:*/
#line 9374 "./marpa.w"

{
PSAR_Object or_per_es_arena;
const PSAR or_psar= &or_per_es_arena;
int work_earley_set_ordinal;
OR last_or_node= NULL;
ORs_of_B(b)= my_new(OR,or_node_estimate);
psar_init(or_psar,SYMI_Count_of_G(g));
for(work_earley_set_ordinal= 0;
work_earley_set_ordinal<earley_set_count_of_r;
work_earley_set_ordinal++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,work_earley_set_ordinal);
EIM*const eims_of_es= EIMs_of_ES(earley_set);
const int item_count= EIM_Count_of_ES(earley_set);
PSL this_earley_set_psl;
OR**const nodes_by_item= per_es_data[work_earley_set_ordinal].t_aexes_by_item;
psar_dealloc(or_psar);
#define PSL_ES_ORD work_earley_set_ordinal
#define CLAIMED_PSL this_earley_set_psl
/*1128:*/
#line 13054 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1128*/
#line 9394 "./marpa.w"

/*852:*/
#line 9402 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const work_nodes_by_aex= nodes_by_item[item_ordinal];
if(work_nodes_by_aex){
const EIM work_earley_item= eims_of_es[item_ordinal];
const int work_ahfa_item_count= AIM_Count_of_EIM(work_earley_item);
AEX work_aex;
const int work_origin_ordinal= Ord_of_ES(Origin_of_EIM(work_earley_item));
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
if(!work_nodes_by_aex[work_aex])continue;
/*853:*/
#line 9422 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1128:*/
#line 13054 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1128*/
#line 9432 "./marpa.w"

/*855:*/
#line 9450 "./marpa.w"

{
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const RULE rule= RULE_of_AIM(ahfa_item);
/*856:*/
#line 9479 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)my_obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
my_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:856*/
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

/*:855*/
#line 9433 "./marpa.w"

/*858:*/
#line 9504 "./marpa.w"

{
const int null_count= Null_Count_of_AIM(ahfa_item);
if(null_count> 0)
{
const RULE rule= RULE_of_AIM(ahfa_item);
const int symbol_instance_of_rule= SYMI_of_RULE(rule);
const int first_null_symbol_instance= 
ahfa_item_symbol_instance<0?symbol_instance_of_rule:ahfa_item_symbol_instance+1;
int i;
for(i= 0;i<null_count;i++)
{
const int symbol_instance= first_null_symbol_instance+i;
OR or_node= PSL_Datum(or_psl,symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal){
DAND draft_and_node;
const int rhs_ix= symbol_instance-SYMI_of_RULE(rule);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_SYMID(RHS_ID_of_RULE(rule,rhs_ix));
/*856:*/
#line 9479 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)my_obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
my_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:856*/
#line 9523 "./marpa.w"

or_node= PSL_Datum(or_psl,symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= work_origin_ordinal;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= rule;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
draft_and_node= DANDs_of_OR(or_node)= 
draft_and_node_new(&bocage_setup_obs,predecessor,
cause);
Next_DAND_of_DAND(draft_and_node)= NULL;
}
psia_or_node= or_node;
}
}
}

/*:858*/
#line 9434 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*859:*/
#line 9541 "./marpa.w"
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
/*861:*/
#line 9581 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const int symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*864:*/
#line 9622 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1128:*/
#line 13054 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1128*/
#line 9629 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*856:*/
#line 9479 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)my_obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
my_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:856*/
#line 9633 "./marpa.w"

PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= path_rule;
Position_of_OR(or_node)= 
symbol_instance_of_path_ahfa_item-SYMI_of_RULE(path_rule)+1;
DANDs_of_OR(or_node)= NULL;
}
}
}

/*:864*/
#line 9591 "./marpa.w"

/*865:*/
#line 9649 "./marpa.w"

{
int i;
const int null_count= Null_Count_of_AIM(path_ahfa_item);
for(i= 1;i<=null_count;i++)
{
const int symbol_instance= symbol_instance_of_path_ahfa_item+i;
OR or_node= PSL_Datum(this_earley_set_psl,symbol_instance);
MARPA_ASSERT(symbol_instance<SYMI_Count_of_G(g))
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
DAND draft_and_node;
const int rhs_ix= symbol_instance-SYMI_of_RULE(path_rule);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_SYMID(RHS_ID_of_RULE(path_rule,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_RULE(path_rule))
MARPA_ASSERT(symbol_instance>=0)
/*856:*/
#line 9479 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)my_obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
my_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:856*/
#line 9666 "./marpa.w"

PSL_Datum(this_earley_set_psl,symbol_instance)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= path_rule;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
DANDs_of_OR(or_node)= draft_and_node= 
draft_and_node_new(&bocage_setup_obs,predecessor,cause);
Next_DAND_of_DAND(draft_and_node)= NULL;
}
MARPA_ASSERT(Position_of_OR(or_node)<=
SYMI_of_RULE(path_rule)+Length_of_RULE(path_rule))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_RULE(path_rule))
}
}

/*:865*/
#line 9592 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:861*/
#line 9563 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:859*/
#line 9442 "./marpa.w"

}

/*:853*/
#line 9416 "./marpa.w"

}
}
}
}

/*:852*/
#line 9395 "./marpa.w"

/*872:*/
#line 9759 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const nodes_by_aex= nodes_by_item[item_ordinal];
if(nodes_by_aex){
const EIM work_earley_item= eims_of_es[item_ordinal];
const int work_ahfa_item_count= AIM_Count_of_EIM(work_earley_item);
const int work_origin_ordinal= Ord_of_ES(Origin_of_EIM(work_earley_item));
AEX work_aex;
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
OR or_node= nodes_by_aex[work_aex];
Move_OR_to_Proper_OR(or_node);
if(or_node){
/*874:*/
#line 9796 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const int work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*875:*/
#line 9812 "./marpa.w"
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
/*876:*/
#line 9844 "./marpa.w"

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
/*877:*/
#line 9873 "./marpa.w"

{
if(higher_path_leo_item){
/*881:*/
#line 9917 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:881*/
#line 9876 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:877*/
#line 9859 "./marpa.w"

/*879:*/
#line 9887 "./marpa.w"

{
const SYMID transition_symbol_id= Postdot_SYMID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
int ix;
for(ix= 0;ix<aex_count;ix++)
{
const AEX cause_aex= aexes[ix];
OR dand_cause;
Set_OR_from_EIM_and_AEX(dand_cause,cause_earley_item,cause_aex);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:879*/
#line 9860 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*877:*/
#line 9873 "./marpa.w"

{
if(higher_path_leo_item){
/*881:*/
#line 9917 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:881*/
#line 9876 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:877*/
#line 9867 "./marpa.w"

/*882:*/
#line 9927 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const int origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:882*/
#line 9868 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:876*/
#line 9834 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:875*/
#line 9807 "./marpa.w"

/*883:*/
#line 9937 "./marpa.w"

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
/*884:*/
#line 9967 "./marpa.w"

{
OR dand_predecessor;
/*885:*/
#line 9975 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:885*/
#line 9970 "./marpa.w"

draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:884*/
#line 9959 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:883*/
#line 9808 "./marpa.w"

/*886:*/
#line 9986 "./marpa.w"

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
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
int ix;
for(ix= 0;ix<aex_count;ix++){
const AEX cause_aex= aexes[ix];
/*887:*/
#line 10026 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*885:*/
#line 9975 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:885*/
#line 10034 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:887*/
#line 10017 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:886*/
#line 9809 "./marpa.w"

}

/*:874*/
#line 9774 "./marpa.w"

}
}
}
}
}

/*:872*/
#line 9396 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= my_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:851*/
#line 10377 "./marpa.w"

/*895:*/
#line 10141 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*888:*/
#line 10040 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
int or_node_id= 0;
psar_init(and_psar,rule_count_of_g+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*890:*/
#line 10072 "./marpa.w"

{
DAND dand= DANDs_of_OR(work_or_node);
DAND next_dand= Next_DAND_of_DAND(dand);
ORID work_or_node_id= ID_of_OR(work_or_node);

if(next_dand)
{
int origin_ordinal= Origin_Ord_of_OR(work_or_node);
psar_dealloc(and_psar);
while(dand)
{
OR psl_or_node;
OR predecessor= Predecessor_OR_of_DAND(dand);
WHEID wheid= WHEID_of_OR(Cause_OR_of_DAND(dand));
const int middle_ordinal= 
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

/*:890*/
#line 10050 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:888*/
#line 10144 "./marpa.w"

/*896:*/
#line 10148 "./marpa.w"

{
const int or_count_of_b= OR_Count_of_B(b);
int or_node_id;
int and_node_id= 0;
const OR*ors_of_b= ORs_of_B(b);
const AND ands_of_b= ANDs_of_B(b)= 
my_new(AND_Object,unique_draft_and_node_count);
for(or_node_id= 0;or_node_id<or_count_of_b;or_node_id++)
{
int and_count_of_parent_or= 0;
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

/*:896*/
#line 10145 "./marpa.w"

}

/*:895*/
#line 10378 "./marpa.w"

/*931:*/
#line 10556 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:931*/
#line 10379 "./marpa.w"
;
my_obstack_free(&bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
input_unref(input);
if(b){
/*941:*/
#line 10635 "./marpa.w"

/*850:*/
#line 9363 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:850*/
#line 10636 "./marpa.w"
;
/*916:*/
#line 10330 "./marpa.w"

if(b->t_is_obstack_initialized){
my_obstack_free(&OBS_of_B(b));
b->t_is_obstack_initialized= 0;
}

/*:916*/
#line 10637 "./marpa.w"
;

/*:941*/
#line 10386 "./marpa.w"
;
}
return NULL;
}

/*:919*//*926:*/
#line 10443 "./marpa.w"

PRIVATE_NOT_INLINE BOCAGE r_create_null_bocage(RECCE r,BOCAGE b)
{
const GRAMMAR g= G_of_R(r);
const RULE null_start_rule= g->t_null_start_rule;
int rule_length= Length_of_RULE(g->t_null_start_rule);
OR*or_nodes= ORs_of_B(b)= my_new(OR,1);
AND and_nodes= ANDs_of_B(b)= my_new(AND_Object,1);
OR or_node= or_nodes[0]= 
(OR)my_obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
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
(OR)TOK_by_SYMID(RHS_ID_of_RULE(null_start_rule,rule_length-1));

return b;
}

/*:926*//*933:*/
#line 10579 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10582 "./marpa.w"

return g;
}

/*:933*//*935:*/
#line 10587 "./marpa.w"

Marpa_Or_Node_ID marpa_b_top_or_node(Marpa_Bocage b)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10590 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10591 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10592 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:935*//*939:*/
#line 10602 "./marpa.w"

PRIVATE void
bocage_unref(BOCAGE b)
{
MARPA_ASSERT(b->t_ref_count> 0)
b->t_ref_count--;
if(b->t_ref_count<=0)
{
bocage_free(b);
}
}
void
marpa_b_unref(Marpa_Bocage b)
{
bocage_unref(b);
}

/*:939*//*940:*/
#line 10620 "./marpa.w"

PRIVATE BOCAGE
bocage_ref(BOCAGE b)
{
MARPA_ASSERT(b->t_ref_count> 0)
b->t_ref_count++;
return b;
}
Marpa_Bocage
marpa_b_ref(Marpa_Bocage b)
{
return bocage_ref(b);
}

/*:940*//*942:*/
#line 10642 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10646 "./marpa.w"

input_unref(input);
if(b)
{
/*941:*/
#line 10635 "./marpa.w"

/*850:*/
#line 9363 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:850*/
#line 10636 "./marpa.w"
;
/*916:*/
#line 10330 "./marpa.w"

if(b->t_is_obstack_initialized){
my_obstack_free(&OBS_of_B(b));
b->t_is_obstack_initialized= 0;
}

/*:916*/
#line 10637 "./marpa.w"
;

/*:941*/
#line 10650 "./marpa.w"
;
my_slice_free(*b,b);
}
}

/*:942*//*945:*/
#line 10675 "./marpa.w"

int marpa_b_or_node_set(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10679 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10680 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10681 "./marpa.w"

/*944:*/
#line 10658 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
if(or_node_id<0){
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:944*/
#line 10682 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:945*//*946:*/
#line 10686 "./marpa.w"

int marpa_b_or_node_origin(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10690 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10691 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10692 "./marpa.w"

/*944:*/
#line 10658 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
if(or_node_id<0){
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:944*/
#line 10693 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:946*//*947:*/
#line 10697 "./marpa.w"

int marpa_b_or_node_rule(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10701 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10702 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10703 "./marpa.w"

/*944:*/
#line 10658 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
if(or_node_id<0){
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:944*/
#line 10704 "./marpa.w"

return ID_of_RULE(RULE_of_OR(or_node));
}

/*:947*//*948:*/
#line 10708 "./marpa.w"

int marpa_b_or_node_position(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10712 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10713 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10714 "./marpa.w"

/*944:*/
#line 10658 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
if(or_node_id<0){
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:944*/
#line 10715 "./marpa.w"

return Position_of_OR(or_node);
}

/*:948*//*949:*/
#line 10719 "./marpa.w"

int marpa_b_or_node_first_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10723 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10724 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10725 "./marpa.w"

/*944:*/
#line 10658 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
if(or_node_id<0){
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:944*/
#line 10726 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:949*//*950:*/
#line 10730 "./marpa.w"

int marpa_b_or_node_last_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10734 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10735 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10736 "./marpa.w"

/*944:*/
#line 10658 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
if(or_node_id<0){
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:944*/
#line 10737 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:950*//*951:*/
#line 10742 "./marpa.w"

int marpa_b_or_node_and_count(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10746 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10747 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10748 "./marpa.w"

/*944:*/
#line 10658 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
if(or_node_id<0){
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:944*/
#line 10749 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:951*//*958:*/
#line 10790 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1150:*/
#line 13290 "./marpa.w"
void*const failure_indicator= NULL;
/*:1150*/
#line 10793 "./marpa.w"

/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10794 "./marpa.w"

ORDER o;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10796 "./marpa.w"

o= my_slice_new(*o);
B_of_O(o)= b;
bocage_ref(b);
/*955:*/
#line 10778 "./marpa.w"

{
o->t_and_node_in_use= NULL;
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
}

/*:955*//*961:*/
#line 10806 "./marpa.w"

o->t_ref_count= 1;

/*:961*/
#line 10800 "./marpa.w"

return o;
}

/*:958*//*962:*/
#line 10810 "./marpa.w"

PRIVATE void
order_unref(ORDER o)
{
MARPA_ASSERT(o->t_ref_count> 0)
o->t_ref_count--;
if(o->t_ref_count<=0)
{
order_free(o);
}
}
void
marpa_o_unref(Marpa_Order o)
{
order_unref(o);
}

/*:962*//*963:*/
#line 10828 "./marpa.w"

PRIVATE ORDER
order_ref(ORDER o)
{
MARPA_ASSERT(o->t_ref_count> 0)
o->t_ref_count++;
return o;
}
Marpa_Order
marpa_o_ref(Marpa_Order o)
{
return order_ref(o);
}

/*:963*//*964:*/
#line 10842 "./marpa.w"

PRIVATE void order_strip(ORDER o)
{
if(o->t_and_node_in_use)
{
bv_free(o->t_and_node_in_use);
o->t_and_node_in_use= NULL;
}
}
/*:964*//*965:*/
#line 10851 "./marpa.w"

PRIVATE void order_freeze(ORDER o)
{
order_strip(o);
O_is_Frozen(o)= 0;
}
/*:965*//*966:*/
#line 10857 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 10860 "./marpa.w"

bocage_unref(b);
order_strip(o);
if(o->t_and_node_orderings){
o->t_and_node_orderings= NULL;
my_obstack_free(&OBS_of_O(o));
}
my_slice_free(*o,o);
}

/*:966*//*969:*/
#line 10886 "./marpa.w"

Marpa_Grammar marpa_o_g(Marpa_Order o)
{
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 10889 "./marpa.w"

return g;
}

/*:969*//*973:*/
#line 10942 "./marpa.w"

int marpa_o_and_order_set(
Marpa_Order o,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
int length)
{
OR or_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 10950 "./marpa.w"

/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 10951 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 10952 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*944:*/
#line 10658 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
if(or_node_id<0){
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:944*/
#line 10958 "./marpa.w"

{
ANDID**and_node_orderings;
Bit_Vector and_node_in_use;
struct obstack*obs;
ANDID first_and_node_id;
ANDID and_count_of_or;
and_node_orderings= o->t_and_node_orderings;
and_node_in_use= o->t_and_node_in_use;
obs= &OBS_of_O(o);
if(!and_node_orderings)
{
int and_id;
const int and_count_of_r= AND_Count_of_B(b);
my_obstack_init(obs);
o->t_and_node_orderings= 
and_node_orderings= 
my_obstack_alloc(obs,sizeof(ANDID*)*and_count_of_r);
for(and_id= 0;and_id<and_count_of_r;and_id++)
{
and_node_orderings[and_id]= (ANDID*)NULL;
}
o->t_and_node_in_use= 
and_node_in_use= bv_create((unsigned int)and_count_of_r);
}
first_and_node_id= First_ANDID_of_OR(or_node);
and_count_of_or= AND_Count_of_OR(or_node);
{
int and_ix;
for(and_ix= 0;and_ix<length;and_ix++)
{
ANDID and_node_id= and_node_ids[and_ix];
if(and_node_id<first_and_node_id||
and_node_id-first_and_node_id>=and_count_of_or){
MARPA_ERROR(MARPA_ERR_ANDID_NOT_IN_OR);
return failure_indicator;
}
if(bv_bit_test(and_node_in_use,(unsigned int)and_node_id))
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_AND_NODE);
return failure_indicator;
}
bv_bit_set(and_node_in_use,(unsigned int)and_node_id);
}
}
if(and_node_orderings[or_node_id]){
MARPA_ERROR(MARPA_ERR_OR_ALREADY_ORDERED);
return failure_indicator;
}
{
ANDID*orderings= my_obstack_alloc(obs,sizeof(ANDID)*(length+1));
int i;
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

/*:973*//*974:*/
#line 11022 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,int ix)
{
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11025 "./marpa.w"

ANDID**and_node_orderings;
if(ix>=AND_Count_of_OR(or_node))
{
return-1;
}
and_node_orderings= o->t_and_node_orderings;
if(and_node_orderings)
{
ORID or_node_id= ID_of_OR(or_node);
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)
{
int length= ordering[0];
if(ix>=length)
return-1;
return ordering[1+ix];
}
}
return First_ANDID_of_OR(or_node)+ix;
}

/*:974*//*975:*/
#line 11047 "./marpa.w"

Marpa_And_Node_ID marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11052 "./marpa.w"

/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11053 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11054 "./marpa.w"

/*944:*/
#line 10658 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
if(or_node_id<0){
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:944*/
#line 11055 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
return and_order_get(o,or_node,ix);
}

/*:975*//*980:*/
#line 11108 "./marpa.w"

PRIVATE void tree_exhaust(TREE t)
{
if(FSTACK_IS_INITIALIZED(t->t_nook_stack))
{
FSTACK_DESTROY(t->t_nook_stack);
FSTACK_SAFE(t->t_nook_stack);
}
if(FSTACK_IS_INITIALIZED(t->t_nook_worklist))
{
FSTACK_DESTROY(t->t_nook_worklist);
FSTACK_SAFE(t->t_nook_worklist);
}
if(t->t_and_node_in_use){
bv_free(t->t_and_node_in_use);
t->t_and_node_in_use= NULL;
}
}

/*:980*//*981:*/
#line 11127 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1150:*/
#line 13290 "./marpa.w"
void*const failure_indicator= NULL;
/*:1150*/
#line 11130 "./marpa.w"

TREE t;
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11132 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11133 "./marpa.w"

t= my_slice_new(*t);
O_of_T(t)= o;
order_ref(o);
order_freeze(o);
/*982:*/
#line 11142 "./marpa.w"

{
const int and_count= AND_Count_of_B(b);
t->t_parse_count= 0;
t->t_and_node_in_use= bv_create((unsigned int)and_count);
FSTACK_INIT(t->t_nook_stack,NOOK_Object,and_count);
FSTACK_INIT(t->t_nook_worklist,int,and_count);
}

/*:982*//*985:*/
#line 11154 "./marpa.w"

t->t_ref_count= 1;

/*:985*//*992:*/
#line 11233 "./marpa.w"
t->t_pause_counter= 0;
/*:992*/
#line 11138 "./marpa.w"

return t;
}

/*:981*//*986:*/
#line 11158 "./marpa.w"

PRIVATE void
tree_unref(TREE t)
{
MARPA_ASSERT(t->t_ref_count> 0)
t->t_ref_count--;
if(t->t_ref_count<=0)
{
tree_free(t);
}
}
void
marpa_t_unref(Marpa_Tree t)
{
tree_unref(t);
}

/*:986*//*987:*/
#line 11176 "./marpa.w"

PRIVATE TREE
tree_ref(TREE t)
{
MARPA_ASSERT(t->t_ref_count> 0)
t->t_ref_count++;
return t;
}
Marpa_Tree
marpa_t_ref(Marpa_Tree t)
{
return tree_ref(t);
}

/*:987*//*988:*/
#line 11190 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_slice_free(*t,t);
}

/*:988*//*993:*/
#line 11234 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:993*//*994:*/
#line 11243 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:994*//*996:*/
#line 11265 "./marpa.w"

Marpa_Grammar marpa_t_g(Marpa_Tree t)
{
/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11268 "./marpa.w"

return g;
}

/*:996*//*997:*/
#line 11272 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11275 "./marpa.w"

int is_first_tree_attempt= 0;
/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11277 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11278 "./marpa.w"

if(T_is_Paused(t)){
MARPA_ERROR(MARPA_ERR_TREE_PAUSED);
return failure_indicator;
}
if(T_is_Exhausted(t))
{
return-1;
}

if(t->t_parse_count<1)
{
is_first_tree_attempt= 1;
/*1002:*/
#line 11336 "./marpa.w"

{
ORID top_or_id= Top_ORID_of_B(b);
OR top_or_node= OR_of_B_by_ID(b,top_or_id);
NOOK nook;
int choice;
choice= or_node_next_choice(o,t,top_or_node,0);


if(choice<0)
goto TREE_IS_EXHAUSTED;
nook= FSTACK_PUSH(t->t_nook_stack);
OR_of_NOOK(nook)= top_or_node;
Choice_of_NOOK(nook)= choice;
Parent_of_NOOK(nook)= -1;
NOOK_Cause_is_Ready(nook)= 0;
NOOK_is_Cause(nook)= 0;
NOOK_Predecessor_is_Ready(nook)= 0;
NOOK_is_Predecessor(nook)= 0;
*(FSTACK_PUSH(t->t_nook_worklist))= 0;
}

/*:1002*/
#line 11291 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
}else{
/*1003:*/
#line 11361 "./marpa.w"
{
while(1){
NOOK iteration_candidate= FSTACK_TOP(t->t_nook_stack,NOOK_Object);
int choice;
if(!iteration_candidate)break;
choice= Choice_of_NOOK(iteration_candidate);
MARPA_ASSERT(choice>=0);
{
OR or_node= OR_of_NOOK(iteration_candidate);
ANDID and_node_id= and_order_get(o,or_node,choice);
tree_and_node_release(t,and_node_id);
choice= or_node_next_choice(o,t,or_node,choice+1);
}
if(choice>=0){





Choice_of_NOOK(iteration_candidate)= choice;
NOOK_Cause_is_Ready(iteration_candidate)= 0;
NOOK_Predecessor_is_Ready(iteration_candidate)= 0;
break;
}
{

const int parent_nook_ix= Parent_of_NOOK(iteration_candidate);
if(parent_nook_ix>=0){
NOOK parent_nook= NOOK_of_TREE_by_IX(t,parent_nook_ix);
if(NOOK_is_Cause(iteration_candidate)){
NOOK_Cause_is_Ready(parent_nook)= 0;
}
if(NOOK_is_Predecessor(iteration_candidate)){
NOOK_Predecessor_is_Ready(parent_nook)= 0;
}
}


FSTACK_POP(t->t_nook_stack);
}
}
{
int stack_length= Size_of_T(t);
int i;
if(stack_length<=0)goto TREE_IS_EXHAUSTED;
FSTACK_CLEAR(t->t_nook_worklist);
for(i= 0;i<stack_length;i++){
*(FSTACK_PUSH(t->t_nook_worklist))= i;
}
}
}

/*:1003*/
#line 11298 "./marpa.w"

}
/*1004:*/
#line 11413 "./marpa.w"
{
while(1){
NOOKID*p_work_nook_id;
NOOK work_nook;
ANDID work_and_node_id;
AND work_and_node;
OR work_or_node;
OR child_or_node= NULL;
int choice;
int child_is_cause= 0;
int child_is_predecessor= 0;
p_work_nook_id= FSTACK_TOP(t->t_nook_worklist,NOOKID);
if(!p_work_nook_id){
goto TREE_IS_FINISHED;
}
work_nook= NOOK_of_TREE_by_IX(t,*p_work_nook_id);
work_or_node= OR_of_NOOK(work_nook);
work_and_node_id= and_order_get(o,work_or_node,Choice_of_NOOK(work_nook));
work_and_node= ands_of_b+work_and_node_id;
if(!NOOK_Cause_is_Ready(work_nook)){
child_or_node= Cause_OR_of_AND(work_and_node);
if(child_or_node&&OR_is_Token(child_or_node))child_or_node= NULL;
if(child_or_node){
child_is_cause= 1;
}else{
NOOK_Cause_is_Ready(work_nook)= 1;
}
}
if(!child_or_node&&!NOOK_Predecessor_is_Ready(work_nook)){
child_or_node= Predecessor_OR_of_AND(work_and_node);
if(child_or_node){
child_is_predecessor= 1;
}else{
NOOK_Predecessor_is_Ready(work_nook)= 1;
}
}
if(!child_or_node){
FSTACK_POP(t->t_nook_worklist);
goto NEXT_NOOK_ON_WORKLIST;
}
choice= or_node_next_choice(o,t,child_or_node,0);
if(choice<0)goto NEXT_TREE;
/*1006:*/
#line 11474 "./marpa.w"

{
NOOKID new_nook_id= Size_of_T(t);
NOOK new_nook= FSTACK_PUSH(t->t_nook_stack);
*(FSTACK_PUSH(t->t_nook_worklist))= new_nook_id;
Parent_of_NOOK(new_nook)= *p_work_nook_id;
Choice_of_NOOK(new_nook)= choice;
OR_of_NOOK(new_nook)= child_or_node;
NOOK_Cause_is_Ready(new_nook)= 0;
if((NOOK_is_Cause(new_nook)= child_is_cause)){
NOOK_Cause_is_Ready(work_nook)= 1;
}
NOOK_Predecessor_is_Ready(new_nook)= 0;
if((NOOK_is_Predecessor(new_nook)= child_is_predecessor)){
NOOK_Predecessor_is_Ready(work_nook)= 1;
}
}

/*:1006*/
#line 11455 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1004*/
#line 11300 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return-1;

}

/*:997*//*999:*/
#line 11316 "./marpa.w"

PRIVATE void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:999*//*1000:*/
#line 11322 "./marpa.w"

PRIVATE void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:1000*//*1001:*/
#line 11330 "./marpa.w"

PRIVATE int tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}

/*:1001*//*1005:*/
#line 11461 "./marpa.w"

PRIVATE int or_node_next_choice(ORDER o,TREE tree,OR or_node,int start_choice)
{
int choice= start_choice;
while(1){
ANDID and_node_id= and_order_get(o,or_node,choice);
if(and_node_id<0)return-1;
if(tree_and_node_try(tree,and_node_id))return choice;
choice++;
}
return-1;
}

/*:1005*//*1007:*/
#line 11492 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1007*//*1008:*/
#line 11500 "./marpa.w"

int marpa_t_size(Marpa_Tree t)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11503 "./marpa.w"

/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11504 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11505 "./marpa.w"

if(T_is_Exhausted(t)){
return-1;
}
return Size_of_T(t);
}

/*:1008*//*1015:*/
#line 11563 "./marpa.w"

int marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11567 "./marpa.w"

/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11568 "./marpa.w"

/*1014:*/
#line 11545 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11547 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1014*/
#line 11569 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1015*//*1016:*/
#line 11573 "./marpa.w"

int marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11577 "./marpa.w"

/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11578 "./marpa.w"

/*1014:*/
#line 11545 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11547 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1014*/
#line 11579 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1016*//*1017:*/
#line 11583 "./marpa.w"

int marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11587 "./marpa.w"

/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11588 "./marpa.w"

/*1014:*/
#line 11545 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11547 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1014*/
#line 11589 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1017*//*1018:*/
#line 11593 "./marpa.w"

int marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11597 "./marpa.w"

/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11598 "./marpa.w"

/*1014:*/
#line 11545 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11547 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1014*/
#line 11599 "./marpa.w"

return NOOK_Cause_is_Ready(nook);
}

/*:1018*//*1019:*/
#line 11603 "./marpa.w"

int marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11607 "./marpa.w"

/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11608 "./marpa.w"

/*1014:*/
#line 11545 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11547 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1014*/
#line 11609 "./marpa.w"

return NOOK_Predecessor_is_Ready(nook);
}

/*:1019*//*1020:*/
#line 11613 "./marpa.w"

int marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11617 "./marpa.w"

/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11618 "./marpa.w"

/*1014:*/
#line 11545 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11547 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1014*/
#line 11619 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1020*//*1021:*/
#line 11623 "./marpa.w"

int marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11627 "./marpa.w"

/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11628 "./marpa.w"

/*1014:*/
#line 11545 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11547 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1014*/
#line 11629 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1021*//*1030:*/
#line 11755 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1150:*/
#line 13290 "./marpa.w"
void*const failure_indicator= NULL;
/*:1150*/
#line 11758 "./marpa.w"

/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11759 "./marpa.w"
;
/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11760 "./marpa.w"

if(!T_is_Exhausted(t))
{
VALUE v= my_slice_new(struct s_value);
const int minimum_stack_size= (8192/sizeof(int));
const int initial_stack_size= 
MAX(Size_of_TREE(t)/1024,minimum_stack_size);
DSTACK_INIT(VStack_of_V(v),int,initial_stack_size);
/*1031:*/
#line 11783 "./marpa.w"

{
const SYMID symbol_count_of_g= SYM_Count_of_G(g);
SYMID ix;
Nulling_Ask_BV_of_V(v)= bv_create(symbol_count_of_g);
for(ix= 0;ix<symbol_count_of_g;ix++){
const SYM symbol= SYM_by_ID(ix);
if(SYM_is_Nulling(symbol)&&SYM_is_Ask_Me_When_Null(symbol))
{
bv_bit_set(Nulling_Ask_BV_of_V(v),ix);
}
}
}

/*:1031*/
#line 11768 "./marpa.w"

Next_Value_Type_of_V(v)= V_GET_DATA;
V_is_Trace(v)= 1;
TOS_of_V(v)= -1;
NOOK_of_V(v)= -1;
/*1034:*/
#line 11800 "./marpa.w"

v->t_ref_count= 1;

/*:1034*/
#line 11773 "./marpa.w"

tree_pause(t);
T_of_V(v)= t;
return(Marpa_Value)v;
}
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return NULL;
}

/*:1030*//*1035:*/
#line 11804 "./marpa.w"

PRIVATE void
value_unref(VALUE v)
{
MARPA_ASSERT(v->t_ref_count> 0)
v->t_ref_count--;
if(v->t_ref_count<=0)
{
value_free(v);
}
}
void
marpa_v_unref(Marpa_Value public_v)
{
value_unref((VALUE)public_v);
}

/*:1035*//*1036:*/
#line 11822 "./marpa.w"

PRIVATE VALUE
value_ref(VALUE v)
{
MARPA_ASSERT(v->t_ref_count> 0)
v->t_ref_count++;
return v;
}
Marpa_Value
marpa_v_ref(Marpa_Value v)
{
return(Marpa_Value)value_ref((VALUE)v);
}

/*:1036*//*1037:*/
#line 11836 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
bv_free(Nulling_Ask_BV_of_V(v));
if(LIKELY(DSTACK_IS_INITIALIZED(v->t_virtual_stack)!=NULL))
{
DSTACK_DESTROY(v->t_virtual_stack);
}
my_slice_free(*v,v);
}

/*:1037*//*1039:*/
#line 11853 "./marpa.w"

Marpa_Grammar marpa_v_g(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1038:*/
#line 11848 "./marpa.w"

TREE t= T_of_V(v);
/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11850 "./marpa.w"


/*:1038*/
#line 11857 "./marpa.w"

return g;
}

/*:1039*//*1040:*/
#line 11861 "./marpa.w"

int marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11864 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1038:*/
#line 11848 "./marpa.w"

TREE t= T_of_V(v);
/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11850 "./marpa.w"


/*:1038*/
#line 11866 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11867 "./marpa.w"

if(UNLIKELY(!V_is_Active(v))){
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1040*//*1041:*/
#line 11875 "./marpa.w"

Marpa_Nook_ID marpa_v_nook(Marpa_Value public_v)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11878 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1038:*/
#line 11848 "./marpa.w"

TREE t= T_of_V(v);
/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11850 "./marpa.w"


/*:1038*/
#line 11880 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11881 "./marpa.w"

if(UNLIKELY(!V_is_Active(v))){
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1041*//*1043:*/
#line 11891 "./marpa.w"

int marpa_v_symbol_is_ask_me_when_null(
Marpa_Value public_v,
Marpa_Symbol_ID symid)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11896 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1038:*/
#line 11848 "./marpa.w"

TREE t= T_of_V(v);
/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11850 "./marpa.w"


/*:1038*/
#line 11898 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11899 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 11900 "./marpa.w"

return bv_bit_test(Nulling_Ask_BV_of_V(v),symid);
}
/*:1043*//*1044:*/
#line 11913 "./marpa.w"

int marpa_v_symbol_ask_me_when_null_set(
Marpa_Value public_v,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
const VALUE v= (VALUE)public_v;
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11919 "./marpa.w"

/*1038:*/
#line 11848 "./marpa.w"

TREE t= T_of_V(v);
/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11850 "./marpa.w"


/*:1038*/
#line 11920 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11921 "./marpa.w"

/*1155:*/
#line 13314 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1155*/
#line 11922 "./marpa.w"

symbol= SYM_by_ID(symid);
if(UNLIKELY(!SYM_is_Nulling(symbol))){
symbol= symbol_null_alias(symbol);
if(!symbol&&value){
MARPA_ERROR(MARPA_ERR_SYM_NOT_NULLABLE);
}
}
if(value){
bv_bit_set(Nulling_Ask_BV_of_V(v),symid);
}else{
bv_bit_clear(Nulling_Ask_BV_of_V(v),symid);
}
return value?1:0;
}

/*:1044*//*1046:*/
#line 11944 "./marpa.w"

Marpa_Value_Type marpa_v_step(Marpa_Value public_v)
{
/*1151:*/
#line 13293 "./marpa.w"
const int failure_indicator= -2;

/*:1151*/
#line 11947 "./marpa.w"

const VALUE v= (VALUE)public_v;

while(UNLIKELY(V_is_Active(v))){
Marpa_Value_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case V_GET_DATA:
/*1047:*/
#line 11992 "./marpa.w"

{
AND and_nodes;
/*1038:*/
#line 11848 "./marpa.w"

TREE t= T_of_V(v);
/*979:*/
#line 11104 "./marpa.w"

ORDER o= O_of_T(t);
/*967:*/
#line 10870 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*912:*/
#line 10316 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:912*/
#line 10872 "./marpa.w"


/*:967*/
#line 11106 "./marpa.w"
;

/*:979*/
#line 11850 "./marpa.w"


/*:1038*/
#line 11995 "./marpa.w"

/*1163:*/
#line 13358 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1163*/
#line 11996 "./marpa.w"

and_nodes= ANDs_of_B(B_of_O(o));

Arg_N_of_V(v)= TOS_of_V(v);
if(NOOK_of_V(v)<0){
NOOK_of_V(v)= Size_of_TREE(t);
}

while(1){
OR or;
RULE nook_rule;
Token_Value_of_V(v)= -1;
RULEID_of_V(v)= -1;
NOOK_of_V(v)--;
if(NOOK_of_V(v)<0){
Next_Value_Type_of_V(v)= MARPA_VALUE_INACTIVE;
break;
}
{
ANDID and_node_id;
AND and_node;
TOK token;
int token_type;
const NOOK nook= NOOK_of_TREE_by_IX(t,NOOK_of_V(v));
const int choice= Choice_of_NOOK(nook);
or= OR_of_NOOK(nook);
and_node_id= and_order_get(o,or,choice);
and_node= and_nodes+and_node_id;
token= and_node_token(and_node);
token_type= token?Type_of_TOK(token):DUMMY_OR_NODE;
Token_Type_of_V(v)= token_type;
if(token_type!=DUMMY_OR_NODE)
{
const SYMID token_id= SYMID_of_TOK(token);
TOS_of_V(v)= ++Arg_N_of_V(v);
if(token_type==VALUED_TOKEN_OR_NODE)
{
SYMID_of_V(v)= token_id;
Token_Value_of_V(v)= Value_of_TOK(token);
}
else if(bv_bit_test(Nulling_Ask_BV_of_V(v),token_id)){
SYMID_of_V(v)= token_id;
}else{
Token_Type_of_V(v)= DUMMY_OR_NODE;


}
}
}
nook_rule= RULE_of_OR(or);
if(Position_of_OR(or)==Length_of_RULE(nook_rule)){
int virtual_rhs= RULE_has_Virtual_RHS(nook_rule);
int virtual_lhs= RULE_has_Virtual_LHS(nook_rule);
int real_symbol_count;
const DSTACK virtual_stack= &VStack_of_V(v);
if(virtual_lhs){
real_symbol_count= Real_SYM_Count_of_RULE(nook_rule);
if(virtual_rhs){
*(DSTACK_TOP(*virtual_stack,int))+= real_symbol_count;
}else{
*DSTACK_PUSH(*virtual_stack,int)= real_symbol_count;
}
}else{

if(virtual_rhs){
real_symbol_count= Real_SYM_Count_of_RULE(nook_rule);
real_symbol_count+= *DSTACK_POP(*virtual_stack,int);
}else{
real_symbol_count= Length_of_RULE(nook_rule);
}
{
RULEID original_rule_id= 
nook_rule->t_is_semantic_equivalent?
nook_rule->t_original:ID_of_RULE(nook_rule);
if(RULE_is_Ask_Me(RULE_by_ID(g,original_rule_id)))
{
RULEID_of_V(v)= original_rule_id;
TOS_of_V(v)= Arg_N_of_V(v)-real_symbol_count+1;
}
}

}
}
if(RULEID_of_V(v)>=0)break;
if(Token_Type_of_V(v)!=DUMMY_OR_NODE)break;
if(V_is_Trace(v))break;
}
}

/*:1047*/
#line 11955 "./marpa.w"

if(!V_is_Active(v))break;

case MARPA_VALUE_TOKEN:
{
int token_type= Token_Type_of_V(v);
if(token_type!=DUMMY_OR_NODE)
{
Next_Value_Type_of_V(v)= MARPA_VALUE_RULE;
if(bv_bit_test(Nulling_Ask_BV_of_V(v),SYMID_of_V(v)))
return MARPA_VALUE_NULLING_TOKEN;


return MARPA_VALUE_TOKEN;
}
}

case MARPA_VALUE_RULE:
if(RULEID_of_V(v)>=0)
{
Next_Value_Type_of_V(v)= MARPA_VALUE_TRACE;
return MARPA_VALUE_RULE;
}

case MARPA_VALUE_TRACE:
Next_Value_Type_of_V(v)= V_GET_DATA;
if(V_is_Trace(v))
{
return MARPA_VALUE_TRACE;
}
}
}

Next_Value_Type_of_V(v)= MARPA_VALUE_INACTIVE;
return MARPA_VALUE_INACTIVE;
}

/*:1046*//*1050:*/
#line 12109 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(unsigned int bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1050*//*1051:*/
#line 12115 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(unsigned int bits)
{
unsigned int mask= bits&bv_modmask;
if(mask)mask= (unsigned int)~(~0uL<<mask);else mask= (unsigned int)~0uL;
return(mask);
}

/*:1051*//*1053:*/
#line 12129 "./marpa.w"

PRIVATE Bit_Vector bv_create(unsigned int bits)
{
unsigned int size= bv_bits_to_size(bits);
unsigned int bytes= (size+bv_hiddenwords)<<sizeof(unsigned int);
unsigned int*addr= (Bit_Vector)my_malloc0((size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}

/*:1053*//*1055:*/
#line 12147 "./marpa.w"

PRIVATE Bit_Vector
bv_obs_create(struct obstack*obs,unsigned int bits)
{
unsigned int size= bv_bits_to_size(bits);
unsigned int bytes= (size+bv_hiddenwords)<<sizeof(unsigned int);
unsigned int*addr= (Bit_Vector)my_obstack_alloc(obs,(size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
if(size> 0){
Bit_Vector bv= addr;
while(size--)*bv++= 0u;
}
return addr;
}


/*:1055*//*1056:*/
#line 12168 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,BV_BITS(bv));
}

/*:1056*//*1057:*/
#line 12182 "./marpa.w"

PRIVATE
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from)
{
unsigned int*p_to= bv_to;
const unsigned int bits= BV_BITS(bv_to);
if(bits> 0)
{
int count= BV_SIZE(bv_to);
while(count--)*p_to++= *bv_from++;
}
return(bv_to);
}

/*:1057*//*1058:*/
#line 12200 "./marpa.w"

PRIVATE
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}

PRIVATE
Bit_Vector bv_obs_clone(struct obstack*obs,Bit_Vector bv)
{
return bv_copy(bv_obs_shadow(obs,bv),bv);
}

/*:1058*//*1059:*/
#line 12214 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1059*//*1060:*/
#line 12225 "./marpa.w"

PRIVATE int bv_bytes(Bit_Vector bv)
{
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}

/*:1060*//*1061:*/
#line 12232 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1061*//*1062:*/
#line 12243 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1062*//*1064:*/
#line 12257 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,unsigned int bit)
{
unsigned int length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1064*//*1066:*/
#line 12265 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1066*//*1067:*/
#line 12272 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1067*//*1068:*/
#line 12279 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,unsigned int bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1068*//*1069:*/
#line 12287 "./marpa.w"

PRIVATE int
bv_bit_test_and_set(Bit_Vector vector,unsigned int bit)
{
Bit_Vector addr= vector+(bit/bv_wordbits);
unsigned int mask= bv_lsb<<(bit%bv_wordbits);
if((*addr&mask)!=0u)
return 1;
*addr|= mask;
return 0;
}

/*:1069*//*1070:*/
#line 12300 "./marpa.w"

PRIVATE
int bv_is_empty(Bit_Vector addr)
{
unsigned int size= BV_SIZE(addr);
int r= 1;
if(size> 0){
*(addr+size-1)&= BV_MASK(addr);
while(r&&(size--> 0))r= (*addr++==0);
}
return(r);
}

/*:1070*//*1071:*/
#line 12314 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1071*//*1072:*/
#line 12324 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1072*//*1073:*/
#line 12334 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1073*//*1074:*/
#line 12344 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1074*//*1075:*/
#line 12354 "./marpa.w"

PRIVATE_NOT_INLINE
int bv_scan(Bit_Vector bv,unsigned int start,
unsigned int*min,unsigned int*max)
{
unsigned int size= BV_SIZE(bv);
unsigned int mask= BV_MASK(bv);
unsigned int offset;
unsigned int bitmask;
unsigned int value;
int empty;

if(size==0)return 0;
if(start>=BV_BITS(bv))return 0;
*min= start;
*max= start;
offset= start/bv_wordbits;
*(bv+size-1)&= mask;
bv+= offset;
size-= offset;
bitmask= (unsigned int)1<<(start&bv_modmask);
mask= ~(bitmask|(bitmask-(unsigned int)1));
value= *bv++;
if((value&bitmask)==0)
{
value&= mask;
if(value==0)
{
offset++;
empty= 1;
while(empty&&(--size> 0))
{
if((value= *bv++))empty= 0;else offset++;
}
if(empty)return 0;
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
empty= 1;
while(empty&&(--size> 0))
{
if((value= ~*bv++))empty= 0;else offset++;
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
return 1;
}

/*:1075*//*1076:*/
#line 12426 "./marpa.w"

PRIVATE unsigned int
bv_count(Bit_Vector v)
{
unsigned int start,min,max;
unsigned int count= 0;
for(start= 0;bv_scan(v,start,&min,&max);start= max+2)
{
count+= max-min+1;
}
return count;
}

/*:1076*//*1081:*/
#line 12474 "./marpa.w"

PRIVATE void
rhs_closure(GRAMMAR g,Bit_Vector bv,RULEID**xrl_list_x_rh_sym)
{
unsigned int min,max,start= 0;
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_DECLARE(stack,Marpa_Symbol_ID)
FSTACK_INIT(stack,Marpa_Symbol_ID,SYM_Count_of_G(g));
while(bv_scan(bv,start,&min,&max))
{
unsigned int symid;
for(symid= min;symid<=max;symid++)
{
*(FSTACK_PUSH(stack))= symid;
}
start= max+2;
}
while((top_of_stack= FSTACK_POP(stack)))
{
const SYMID symid= *top_of_stack;
RULEID*p_xrl= xrl_list_x_rh_sym[symid];
const RULEID*p_one_past_rules= xrl_list_x_rh_sym[symid+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{
const RULEID rule_id= *p_xrl;
const RULE rule= RULE_by_ID(g,rule_id);
int rule_length;
int rh_ix;
const SYMID lhs_id= LHS_ID_of_RULE(rule);

const int is_sequence= XRL_is_Sequence(rule);

if(XRL_is_Internal(rule))goto NEXT_RULE;
if(bv_bit_test(bv,(unsigned int)lhs_id))
goto NEXT_RULE;
rule_length= Length_of_RULE(rule);






for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test
(bv,(unsigned int)RHS_ID_of_RULE(rule,rh_ix)))
goto NEXT_RULE;
}





if(is_sequence&&Minimum_of_XRL(rule)>=2)
{
SYMID separator_id= Separator_of_XRL(rule);
if(separator_id>=0)
{
if(!bv_bit_test(bv,(unsigned int)separator_id))
goto NEXT_RULE;
}
}




bv_bit_set(bv,(unsigned int)lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}

/*:1081*//*1085:*/
#line 12577 "./marpa.w"

PRIVATE Bit_Matrix matrix_obs_create(struct obstack*obs,unsigned int rows,unsigned int columns)
{
const unsigned int bv_data_words= bv_bits_to_size(columns);
const unsigned int row_bytes= (bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
const unsigned int bv_mask= bv_bits_to_unused_mask(columns);
const size_t allocation_size= row_bytes*rows;
Bit_Vector_Word*matrix_addr= my_obstack_alloc(obs,allocation_size);
unsigned int row;
for(row= 0;row<rows;row++){
const unsigned int row_start= row*(bv_data_words+bv_hiddenwords);
Bit_Vector_Word*p_current_word= matrix_addr+row_start;
int data_word_counter= bv_data_words;
*p_current_word++= columns;
*p_current_word++= bv_data_words;
*p_current_word++= bv_mask;
while(data_word_counter--)*p_current_word++= 0;
}
return matrix_addr;
}

/*:1085*//*1086:*/
#line 12604 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1086*//*1087:*/
#line 12620 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,unsigned int row)
{
Bit_Vector row0= matrix+bv_hiddenwords;
unsigned int words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1087*//*1089:*/
#line 12629 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1089*//*1091:*/
#line 12637 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1091*//*1093:*/
#line 12645 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1093*//*1094:*/
#line 12658 "./marpa.w"

PRIVATE_NOT_INLINE void transitive_closure(Bit_Matrix matrix)
{
struct transition{unsigned int from,to;}*top_of_stack= NULL;
unsigned int size= matrix_columns(matrix);
unsigned int row;
DSTACK_DECLARE(stack);
DSTACK_INIT(stack,struct transition,1024);
for(row= 0;row<size;row++){
unsigned int min,max,start;
Bit_Vector row_vector= matrix_row(matrix,row);
for(start= 0;bv_scan(row_vector,start,&min,&max);start= max+2){
unsigned int column;
for(column= min;column<=max;column++){
struct transition*t= DSTACK_PUSH(stack,struct transition);
t->from= row;
t->to= column;
}}}
while((top_of_stack= DSTACK_POP(stack,struct transition))){
unsigned int old_from= top_of_stack->from;
unsigned int old_to= top_of_stack->to;
unsigned int new_ix;
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

/*:1094*//*1103:*/
#line 12816 "./marpa.w"

PRIVATE void*dstack_resize(struct s_dstack*this,size_t type_bytes)
{
this->t_capacity*= 2;
this->t_base= my_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}

/*:1103*//*1118:*/
#line 12955 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1118*//*1119:*/
#line 12962 "./marpa.w"

PRIVATE void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl)
{
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
if(owner)
*owner= NULL;
my_slice_free1(Sizeof_PSL(psar),psl);
psl= next_psl;
}
}
/*:1119*//*1120:*/
#line 12976 "./marpa.w"

PRIVATE PSL psl_new(const PSAR psar)
{
int i;
PSL new_psl= my_slice_alloc(Sizeof_PSL(psar));
new_psl->t_next= NULL;
new_psl->t_prev= NULL;
new_psl->t_owner= NULL;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(new_psl,i)= NULL;
}
return new_psl;
}
/*:1120*//*1123:*/
#line 13007 "./marpa.w"

PRIVATE void psar_reset(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl&&psl->t_owner){
int i;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(psl,i)= NULL;
}
psl= psl->t_next;
}
psar_dealloc(psar);
}

/*:1123*//*1125:*/
#line 13025 "./marpa.w"

PRIVATE void psar_dealloc(const PSAR psar)
{
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

/*:1125*//*1127:*/
#line 13045 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1127*//*1129:*/
#line 13069 "./marpa.w"

PRIVATE PSL psl_alloc(const PSAR psar)
{
PSL free_psl= psar->t_first_free_psl;
PSL next_psl= free_psl->t_next;
if(!next_psl){
next_psl= free_psl->t_next= psl_new(psar);
next_psl->t_prev= free_psl;
}
psar->t_first_free_psl= next_psl;
return free_psl;
}

/*:1129*//*1132:*/
#line 13093 "./marpa.w"

PRIVATE_NOT_INLINE void
_marpa_default_out_of_memory(void)
{
abort();
}
void(*_marpa_out_of_memory)(void)= _marpa_default_out_of_memory;

/*:1132*//*1166:*/
#line 13402 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(struct marpa_g*g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}

/*:1166*//*1174:*/
#line 13507 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
marpa_debug_handler= debug_handler;
}

/*:1174*//*1176:*/
#line 13515 "./marpa.w"

void marpa_debug_level_set(int level)
{
marpa_debug_level= level;
}

/*:1176*/
#line 13741 "./marpa.w"


/*:1191*/
