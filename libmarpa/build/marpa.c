/*1186:*/
#line 13460 "./marpa.w"

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

/*:1186*//*1187:*/
#line 13483 "./marpa.w"

#include "config.h"
#include "marpa.h"
#include <stdarg.h> 
#include <stddef.h> 
#include <limits.h> 
#include <stdlib.h> 
#include <stdio.h> 
/*1173:*/
#line 13299 "./marpa.w"

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

/*:1173*/
#line 13491 "./marpa.w"

#define PRIVATE_NOT_INLINE static
#define PRIVATE static inline \

#define SYM_Count_of_G(g) (DSTACK_LENGTH((g) ->t_symbols) ) 
#define SYM_by_ID(id) (*DSTACK_INDEX(g->t_symbols,SYM,(id) ) )  \

#define RULE_Count_of_G(g) (DSTACK_LENGTH((g) ->t_rules) ) 
#define RULE_by_ID(g,id) (*DSTACK_INDEX((g) ->t_rules,RULE,(id) ) )  \

#define RULEID_of_G_is_Valid(g,rule_id)  \
((rule_id) >=0&&(rule_id) <RULE_Count_of_G(g) )  \

#define G_is_Trivial(g) (!(g) ->t_proper_start_rule) 
#define Size_of_G(g) ((g) ->t_size) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define G_EVENT_COUNT(g) DSTACK_LENGTH((g) ->t_events) 
#define INITIAL_G_EVENTS_CAPACITY 1
#define G_EVENTS_CLEAR(g) DSTACK_CLEAR((g) ->t_events) 
#define G_EVENT_PUSH(g) DSTACK_PUSH((g) ->t_events,GEV_Object) 
#define I_AM_OK 0x69734f4b
#define IS_G_OK(g) ((g) ->t_is_ok==I_AM_OK) 
#define ID_of_SYM(sym) ((sym) ->t_symbol_id)  \

#define SYMBOL_LHS_RULE_COUNT(symbol) DSTACK_LENGTH(symbol->t_lhs) 
#define SYM_is_Internal(symbol) ((symbol) ->t_is_internal) 
#define SYM_is_Ask_Me_When_Null(symbol) ((symbol) ->t_is_ask_me_when_null) 
#define SYM_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define SYM_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
#define SYM_is_Marked_Terminal(symbol) ((symbol) ->t_is_marked_terminal) 
#define SYMID_is_Terminal(id) (SYM_is_Terminal(SYM_by_ID(id) ) ) 
#define MAX_RHS_LENGTH (INT_MAX>>(2) ) 
#define Length_of_RULE(rule) ((rule) ->t_rhs_length) 
#define LHS_ID_of_RULE(rule) ((rule) ->t_symbols[0]) 
#define RHS_ID_of_RULE(rule,position)  \
((rule) ->t_symbols[(position) +1])  \

#define ID_of_RULE(rule) ((rule) ->t_id) 
#define RULE_is_Used(rule) ((rule) ->t_is_used) 
#define RULE_has_Virtual_LHS(rule) ((rule) ->t_is_virtual_lhs) 
#define RULE_has_Virtual_RHS(rule) ((rule) ->t_is_virtual_rhs) 
#define Real_SYM_Count_of_RULE(rule) ((rule) ->t_real_symbol_count) 
#define RULE_is_Ask_Me(rule) ((rule) ->t_is_ask_me) 
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
#define my_free(p) free(p) 
#define MY_MALLOC(newmem,size) { \
(newmem) = malloc((size) ) ; \
if(UNLIKELY(!(newmem) ) ) (*marpa_out_of_memory) () ; \
}
#define my_new(type,count) ((type*) my_malloc(sizeof(type) *(count) ) ) 
#define my_renew(type,p,count) ((type*) my_realloc((p) ,sizeof(type) *(count) ) )  \

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

#line 13492 "./marpa.w"

#include "marpa_obs.h"
#include "avl.h"
/*1191:*/
#line 13556 "./marpa.w"


#if     __GNUC__ >  2 || (__GNUC__ == 2 && __GNUC_MINOR__ >  4)
#define UNUSED __attribute__((__unused__))
#else
#define UNUSED
#endif

#if defined (__GNUC__) && defined (__STRICT_ANSI__)
#  undef inline
#  define inline __inline__
#endif

#undef      MAX
#define MAX(a, b)  (((a) >  (b)) ? (a) : (b))

#undef      CLAMP
#define CLAMP(x, low, high)  (((x) >  (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

#undef STRINGIFY_ARG
#define STRINGIFY_ARG(contents)       #contents
#undef STRINGIFY
#define STRINGIFY(macro_or_string)        STRINGIFY_ARG (macro_or_string)


#if defined(__GNUC__) && (__GNUC__ < 3) && !defined(__cplusplus)
#  define STRLOC __FILE__ ":" STRINGIFY (__LINE__) ":" __PRETTY_FUNCTION__ "()"
#else
#  define STRLOC __FILE__ ":" STRINGIFY (__LINE__)
#endif


#if defined (__GNUC__)
#  define STRFUNC     ((const char*) (__PRETTY_FUNCTION__))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 19901L
#  define STRFUNC     ((const char*) (__func__))
#else
#  define STRFUNC     ((const char*) ("???"))
#endif

#if defined(__GNUC__) && (__GNUC__ >  2) && defined(__OPTIMIZE__)
#define LIKELY(expr) (__builtin_expect ((expr), 1))
#define UNLIKELY(expr) (__builtin_expect ((expr), 0))
#else
#define LIKELY(expr) (expr)
#define UNLIKELY(expr) (expr)
#endif

/*:1191*/
#line 13495 "./marpa.w"

/*90:*/
#line 886 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:90*//*114:*/
#line 1060 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:114*//*352:*/
#line 3608 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:352*//*390:*/
#line 3977 "./marpa.w"
struct s_AHFA_state;
/*:390*//*467:*/
#line 5084 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:467*//*574:*/
#line 5778 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:574*//*598:*/
#line 5992 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:598*//*618:*/
#line 6282 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:618*//*621:*/
#line 6317 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:621*//*702:*/
#line 7435 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:702*//*708:*/
#line 7486 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:708*//*806:*/
#line 8643 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:806*//*834:*/
#line 9071 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:834*//*861:*/
#line 9506 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:861*//*887:*/
#line 9921 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:887*//*902:*/
#line 10097 "./marpa.w"

typedef struct s_bocage*BOCAGE;
/*:902*//*915:*/
#line 10203 "./marpa.w"

struct s_bocage_setup_per_es;
/*:915*//*972:*/
#line 10889 "./marpa.w"

typedef Marpa_Tree TREE;
/*:972*//*1006:*/
#line 11329 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1006*//*1019:*/
#line 11465 "./marpa.w"

typedef struct s_value*VALUE;
/*:1019*//*1096:*/
#line 12591 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1096*//*1099:*/
#line 12625 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1099*//*1106:*/
#line 12690 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1106*//*1108:*/
#line 12705 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1108*/
#line 13496 "./marpa.w"

/*40:*/
#line 609 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:40*//*113:*/
#line 1058 "./marpa.w"

typedef int SYMID;
/*:113*//*170:*/
#line 1500 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:170*//*259:*/
#line 2395 "./marpa.w"
typedef int SYMI;
/*:259*//*407:*/
#line 4068 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef int AHFAID;

/*:407*//*468:*/
#line 5089 "./marpa.w"
typedef int AEX;
/*:468*//*484:*/
#line 5244 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:484*//*499:*/
#line 5336 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:499*//*571:*/
#line 5769 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:571*//*573:*/
#line 5773 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:573*//*649:*/
#line 6699 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:649*//*651:*/
#line 6711 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:651*//*826:*/
#line 9007 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:826*//*860:*/
#line 9494 "./marpa.w"

typedef int WHEID;


/*:860*//*886:*/
#line 9917 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:886*//*1005:*/
#line 11326 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1005*//*1043:*/
#line 11899 "./marpa.w"

typedef unsigned int Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1043*//*1078:*/
#line 12349 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1078*/
#line 13497 "./marpa.w"

/*34:*/
#line 528 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:34*//*840:*/
#line 9134 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:840*//*1044:*/
#line 11906 "./marpa.w"

static const unsigned int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const unsigned int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= 1u;
static const unsigned int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1044*//*1128:*/
#line 12881 "./marpa.w"

extern void(*marpa_out_of_memory)(void);

/*:1128*//*1168:*/
#line 13279 "./marpa.w"

int(*marpa_debug_handler)(const char*,...);
int marpa_debug_level= 0;

/*:1168*/
#line 13498 "./marpa.w"

/*1097:*/
#line 12594 "./marpa.w"

struct s_dstack{int t_count;int t_capacity;void*t_base;};
/*:1097*/
#line 13499 "./marpa.w"

/*39:*/
#line 603 "./marpa.w"
struct marpa_g{
/*105:*/
#line 1009 "./marpa.w"

int t_is_ok;

/*:105*/
#line 604 "./marpa.w"

/*50:*/
#line 685 "./marpa.w"

DSTACK_DECLARE(t_symbols);
/*:50*//*58:*/
#line 727 "./marpa.w"

DSTACK_DECLARE(t_rules);
/*:58*//*87:*/
#line 874 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:87*//*94:*/
#line 905 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:94*//*101:*/
#line 979 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:101*//*107:*/
#line 1024 "./marpa.w"

const char*t_error_string;
/*:107*//*354:*/
#line 3625 "./marpa.w"

AIM t_AHFA_items;
/*:354*//*408:*/
#line 4072 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:408*/
#line 605 "./marpa.w"

/*44:*/
#line 631 "./marpa.w"
int t_ref_count;
/*:44*//*67:*/
#line 766 "./marpa.w"
Marpa_Symbol_ID t_original_start_symid;
/*:67*//*71:*/
#line 794 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:71*//*75:*/
#line 823 "./marpa.w"
int t_size;
/*:75*//*78:*/
#line 836 "./marpa.w"
int t_max_rule_length;
/*:78*//*108:*/
#line 1026 "./marpa.w"

Marpa_Error_Code t_error;
/*:108*//*260:*/
#line 2397 "./marpa.w"

int t_symbol_instance_count;
/*:260*//*355:*/
#line 3629 "./marpa.w"

unsigned int t_aim_count;
/*:355*//*409:*/
#line 4075 "./marpa.w"
int t_AHFA_len;
/*:409*/
#line 606 "./marpa.w"

/*81:*/
#line 842 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:81*//*84:*/
#line 854 "./marpa.w"
unsigned int t_has_cycle:1;
/*:84*/
#line 607 "./marpa.w"

};
/*:39*//*93:*/
#line 898 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:93*//*115:*/
#line 1073 "./marpa.w"

struct s_symbol{
int t_or_node_type;
SYMID t_symbol_id;
/*120:*/
#line 1116 "./marpa.w"

DSTACK_DECLARE(t_lhs);
/*:120*//*125:*/
#line 1160 "./marpa.w"

DSTACK_DECLARE(t_rhs);
/*:125*//*157:*/
#line 1378 "./marpa.w"

struct s_symbol*t_alias;
/*:157*//*164:*/
#line 1464 "./marpa.w"

RULE t_virtual_lhs_rule;
/*:164*/
#line 1077 "./marpa.w"

/*130:*/
#line 1202 "./marpa.w"
unsigned int t_is_internal:1;
/*:130*//*133:*/
#line 1225 "./marpa.w"
unsigned int t_is_ask_me_when_null:1;
/*:133*//*136:*/
#line 1247 "./marpa.w"
unsigned int t_is_accessible:1;
/*:136*//*139:*/
#line 1267 "./marpa.w"
unsigned int t_is_counted:1;
/*:139*//*142:*/
#line 1282 "./marpa.w"
unsigned int t_is_nulling:1;
/*:142*//*145:*/
#line 1302 "./marpa.w"

unsigned int t_is_terminal:1;
unsigned int t_is_marked_terminal:1;
/*:145*//*150:*/
#line 1340 "./marpa.w"
unsigned int t_is_productive:1;
/*:150*//*153:*/
#line 1356 "./marpa.w"
unsigned int t_is_start:1;
/*:153*//*156:*/
#line 1375 "./marpa.w"

unsigned int t_is_proper_alias:1;
unsigned int t_is_nulling_alias:1;
/*:156*/
#line 1078 "./marpa.w"

};
typedef struct s_symbol SYM_Object;
/*:115*//*169:*/
#line 1490 "./marpa.w"

struct s_rule{
/*257:*/
#line 2390 "./marpa.w"
AIM t_first_aim;
/*:257*/
#line 1492 "./marpa.w"

/*194:*/
#line 1923 "./marpa.w"
int t_rhs_length;
/*:194*//*205:*/
#line 2016 "./marpa.w"
Marpa_Rule_ID t_id;

/*:205*//*234:*/
#line 2222 "./marpa.w"
int t_virtual_start;
/*:234*//*237:*/
#line 2239 "./marpa.w"
int t_virtual_end;
/*:237*//*241:*/
#line 2256 "./marpa.w"
Marpa_Rule_ID t_original;
/*:241*//*245:*/
#line 2275 "./marpa.w"
int t_real_symbol_count;
/*:245*//*248:*/
#line 2301 "./marpa.w"
unsigned int t_is_ask_me:1;
/*:248*//*261:*/
#line 2408 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:261*/
#line 1493 "./marpa.w"

/*207:*/
#line 2027 "./marpa.w"
unsigned int t_is_discard:1;
/*:207*//*216:*/
#line 2110 "./marpa.w"
unsigned int t_is_loop:1;
/*:216*//*220:*/
#line 2129 "./marpa.w"
unsigned int t_is_virtual_loop:1;
/*:220*//*225:*/
#line 2161 "./marpa.w"
unsigned int t_is_used:1;
/*:225*//*228:*/
#line 2188 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:228*//*231:*/
#line 2204 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:231*//*252:*/
#line 2359 "./marpa.w"
unsigned int t_is_semantic_equivalent:1;
/*:252*/
#line 1494 "./marpa.w"

/*195:*/
#line 1926 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:195*/
#line 1495 "./marpa.w"

};
/*:169*//*351:*/
#line 3602 "./marpa.w"

struct s_AHFA_item{
int t_sort_key;
/*360:*/
#line 3651 "./marpa.w"

RULE t_rule;

/*:360*/
#line 3605 "./marpa.w"

/*361:*/
#line 3657 "./marpa.w"

int t_position;

/*:361*//*362:*/
#line 3664 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:362*//*363:*/
#line 3673 "./marpa.w"

int t_leading_nulls;

/*:363*/
#line 3606 "./marpa.w"

};
/*:351*//*391:*/
#line 3978 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*395:*/
#line 4005 "./marpa.w"

SYMID*t_complete_symbols;

/*:395*//*397:*/
#line 4012 "./marpa.w"

AIM*t_items;
/*:397*//*415:*/
#line 4109 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:415*//*470:*/
#line 5101 "./marpa.w"

TRANS*t_transitions;
/*:470*/
#line 3985 "./marpa.w"

/*394:*/
#line 4003 "./marpa.w"

unsigned int t_complete_symbol_count;
/*:394*//*398:*/
#line 4015 "./marpa.w"

int t_item_count;
/*:398*//*416:*/
#line 4110 "./marpa.w"
unsigned int t_postdot_sym_count;

/*:416*//*422:*/
#line 4171 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:422*/
#line 3986 "./marpa.w"

/*402:*/
#line 4056 "./marpa.w"

unsigned int t_is_predict:1;

/*:402*//*405:*/
#line 4064 "./marpa.w"

unsigned int t_is_potential_leo_base:1;
/*:405*/
#line 3987 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:391*//*469:*/
#line 5090 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
int t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:469*//*485:*/
#line 5247 "./marpa.w"

struct s_input{
/*494:*/
#line 5318 "./marpa.w"

struct obstack t_token_obs;

/*:494*//*496:*/
#line 5323 "./marpa.w"

GRAMMAR t_grammar;
/*:496*/
#line 5249 "./marpa.w"

/*488:*/
#line 5264 "./marpa.w"

int t_ref_count;
/*:488*/
#line 5250 "./marpa.w"

};

/*:485*//*575:*/
#line 5784 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:575*//*576:*/
#line 5789 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
int t_postdot_sym_count;
/*577:*/
#line 5801 "./marpa.w"

int t_eim_count;
/*:577*//*579:*/
#line 5815 "./marpa.w"

int t_ordinal;
/*:579*/
#line 5793 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*578:*/
#line 5804 "./marpa.w"

EIM*t_earley_items;

/*:578*//*1116:*/
#line 12775 "./marpa.w"

PSL t_dot_psl;
/*:1116*/
#line 5796 "./marpa.w"

};

/*:576*//*619:*/
#line 6286 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:619*//*622:*/
#line 6320 "./marpa.w"

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

/*:622*//*632:*/
#line 6459 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:632*//*703:*/
#line 7443 "./marpa.w"

struct s_token_unvalued{
int t_type;
SYMID t_symbol_id;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:703*//*709:*/
#line 7496 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:709*//*807:*/
#line 8660 "./marpa.w"

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
/*:807*//*837:*/
#line 9109 "./marpa.w"

struct s_draft_or_node
{
/*836:*/
#line 9103 "./marpa.w"

int t_position;
int t_end_set_ordinal;
RULE t_rule;
int t_start_set_ordinal;
ORID t_id;
/*:836*/
#line 9112 "./marpa.w"

DAND t_draft_and_node;
};
/*:837*//*838:*/
#line 9115 "./marpa.w"

struct s_final_or_node
{
/*836:*/
#line 9103 "./marpa.w"

int t_position;
int t_end_set_ordinal;
RULE t_rule;
int t_start_set_ordinal;
ORID t_id;
/*:836*/
#line 9118 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:838*//*839:*/
#line 9126 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:839*//*862:*/
#line 9513 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:862*//*888:*/
#line 9928 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:888*//*916:*/
#line 10205 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:916*//*949:*/
#line 10580 "./marpa.w"

struct s_order{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
/*952:*/
#line 10598 "./marpa.w"

BOCAGE t_bocage;

/*:952*/
#line 10585 "./marpa.w"

/*955:*/
#line 10616 "./marpa.w"
int t_ref_count;
/*:955*/
#line 10586 "./marpa.w"

unsigned int t_is_frozen:1;
};
/*:949*//*973:*/
#line 10903 "./marpa.w"

/*1007:*/
#line 11340 "./marpa.w"

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

/*:1007*/
#line 10904 "./marpa.w"

/*1021:*/
#line 11497 "./marpa.w"

struct s_value{
struct marpa_value public;
DSTACK_DECLARE(t_virtual_stack);
NOOKID t_nook;
Marpa_Tree t_tree;
/*1028:*/
#line 11609 "./marpa.w"

int t_ref_count;
/*:1028*/
#line 11503 "./marpa.w"

Bit_Vector t_nulling_ask_bv;
int t_token_type;
int t_next_value_type;
unsigned int t_trace:1;
};

/*:1021*/
#line 10905 "./marpa.w"

struct s_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_and_node_in_use;
Marpa_Order t_order;
/*979:*/
#line 10963 "./marpa.w"

int t_ref_count;
/*:979*//*986:*/
#line 11043 "./marpa.w"
int t_pause_counter;
/*:986*/
#line 10911 "./marpa.w"

int t_parse_count;
};

/*:973*//*1100:*/
#line 12628 "./marpa.w"

struct s_dqueue{int t_current;struct s_dstack t_stack;};

/*:1100*//*1107:*/
#line 12696 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1107*//*1109:*/
#line 12721 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1109*/
#line 13500 "./marpa.w"

/*500:*/
#line 5339 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*513:*/
#line 5444 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:513*//*525:*/
#line 5507 "./marpa.w"
void**t_sym_workarea;
/*:525*//*529:*/
#line 5518 "./marpa.w"
void**t_workarea2;
/*:529*//*533:*/
#line 5535 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:533*//*537:*/
#line 5561 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:537*//*560:*/
#line 5722 "./marpa.w"
struct obstack t_obs;
/*:560*//*585:*/
#line 5865 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:585*//*606:*/
#line 6127 "./marpa.w"

EIM t_trace_earley_item;
/*:606*//*636:*/
#line 6508 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:636*//*670:*/
#line 6965 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:670*//*710:*/
#line 7504 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:710*//*731:*/
#line 7802 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:731*//*735:*/
#line 7813 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:735*//*739:*/
#line 7824 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:739*//*808:*/
#line 8673 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:808*//*1110:*/
#line 12729 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1110*/
#line 5342 "./marpa.w"

/*503:*/
#line 5368 "./marpa.w"
int t_ref_count;
/*:503*//*517:*/
#line 5471 "./marpa.w"
int t_earley_item_warning_threshold;
/*:517*//*521:*/
#line 5494 "./marpa.w"
EARLEME t_furthest_earleme;
/*:521*//*580:*/
#line 5819 "./marpa.w"

int t_earley_set_count;
/*:580*/
#line 5343 "./marpa.w"

/*510:*/
#line 5436 "./marpa.w"

unsigned int t_input_phase:2;
/*:510*//*552:*/
#line 5660 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:552*//*556:*/
#line 5698 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:556*//*671:*/
#line 6968 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:671*/
#line 5344 "./marpa.w"

};

/*:500*/
#line 13501 "./marpa.w"

/*650:*/
#line 6702 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:650*//*652:*/
#line 6714 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:652*//*653:*/
#line 6720 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:653*//*654:*/
#line 6727 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:654*/
#line 13502 "./marpa.w"

/*599:*/
#line 5999 "./marpa.w"

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
/*604:*/
#line 6099 "./marpa.w"

unsigned int t_source_type:3;

/*:604*/
#line 6010 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:599*/
#line 13503 "./marpa.w"

/*903:*/
#line 10099 "./marpa.w"

struct s_bocage{
/*841:*/
#line 9144 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:841*//*905:*/
#line 10108 "./marpa.w"

INPUT t_input;

/*:905*//*907:*/
#line 10118 "./marpa.w"

struct obstack t_obs;
/*:907*/
#line 10101 "./marpa.w"

/*842:*/
#line 9147 "./marpa.w"

int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:842*//*932:*/
#line 10408 "./marpa.w"
int t_ref_count;
/*:932*/
#line 10102 "./marpa.w"

/*908:*/
#line 10120 "./marpa.w"

unsigned int t_is_obstack_initialized:1;
/*:908*/
#line 10103 "./marpa.w"

};

/*:903*/
#line 13504 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1174:*/
#line 13336 "./marpa.w"

static char*eim_tag_safe(char*buffer,EIM eim);
static char*eim_tag(EIM eim);
/*:1174*//*1176:*/
#line 13361 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim);
static char*lim_tag(LIM lim);
/*:1176*//*1178:*/
#line 13387 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or);
static const char*or_tag(OR or);
/*:1178*//*1180:*/
#line 13419 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AIM aim);
static const char*aim_tag(AIM aim);
/*:1180*/
#line 13507 "./marpa.w"

/*1175:*/
#line 13340 "./marpa.w"

static char*
eim_tag_safe(char*buffer,EIM eim)
{
if(!eim)return"NULL";
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_EIM(eim),Origin_Earleme_of_EIM(eim),
Earleme_of_EIM(eim));
return buffer;
}

static char DEBUG_eim_tag_buffer[1000];
static char*
eim_tag(EIM eim)
{
return eim_tag_safe(DEBUG_eim_tag_buffer,eim);
}

/*:1175*//*1177:*/
#line 13366 "./marpa.w"

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

/*:1177*//*1179:*/
#line 13391 "./marpa.w"

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

/*:1179*//*1181:*/
#line 13422 "./marpa.w"

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

/*:1181*/
#line 13508 "./marpa.w"

#endif
/*35:*/
#line 534 "./marpa.w"

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
#line 550 "./marpa.w"

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
#line 613 "./marpa.w"

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
#line 632 "./marpa.w"

g->t_ref_count= 1;

/*:45*//*51:*/
#line 687 "./marpa.w"

DSTACK_INIT(g->t_symbols,SYM,256);
/*:51*//*59:*/
#line 729 "./marpa.w"

DSTACK_INIT(g->t_rules,RULE,256);
/*:59*//*68:*/
#line 767 "./marpa.w"

g->t_original_start_symid= -1;
/*:68*//*72:*/
#line 797 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;
/*:72*//*76:*/
#line 824 "./marpa.w"

Size_of_G(g)= 0;

/*:76*//*79:*/
#line 837 "./marpa.w"

g->t_max_rule_length= 0;

/*:79*//*82:*/
#line 843 "./marpa.w"

g->t_is_precomputed= 0;
/*:82*//*85:*/
#line 855 "./marpa.w"

g->t_has_cycle= 0;
/*:85*//*88:*/
#line 875 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:88*//*95:*/
#line 913 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:95*//*102:*/
#line 982 "./marpa.w"

my_obstack_init(&g->t_obs);
my_obstack_init(&g->t_obs_tricky);
/*:102*//*109:*/
#line 1028 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:109*//*357:*/
#line 3634 "./marpa.w"

g->t_AHFA_items= NULL;
/*:357*//*410:*/
#line 4076 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:410*/
#line 625 "./marpa.w"


g->t_is_ok= I_AM_OK;
return g;
}
/*:42*//*46:*/
#line 642 "./marpa.w"

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
#line 659 "./marpa.w"

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
#line 671 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
const SYMID symbol_count_of_g= SYM_Count_of_G(g);
/*52:*/
#line 689 "./marpa.w"

{SYMID id;for(id= 0;id<symbol_count_of_g;id++)
{symbol_free(SYM_by_ID(id));}}
DSTACK_DESTROY(g->t_symbols);

/*:52*//*60:*/
#line 731 "./marpa.w"

DSTACK_DESTROY(g->t_rules);

/*:60*//*89:*/
#line 876 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:89*//*96:*/
#line 915 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:96*//*103:*/
#line 985 "./marpa.w"

my_obstack_free(&g->t_obs,NULL);
my_obstack_free(&g->t_obs_tricky,NULL);

/*:103*//*358:*/
#line 3636 "./marpa.w"

my_free(g->t_AHFA_items);

/*:358*//*411:*/
#line 4080 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*412:*/
#line 4090 "./marpa.w"
{
my_free(TRANSs_of_AHFA(ahfa_state));
}

/*:412*/
#line 4084 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:411*/
#line 676 "./marpa.w"

my_slice_free(struct marpa_g,g);
}

/*:49*//*54:*/
#line 696 "./marpa.w"

int marpa_g_symbol_count(Marpa_Grammar g){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 698 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 699 "./marpa.w"

return SYM_Count_of_G(g);
}

/*:54*//*56:*/
#line 708 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,SYM symbol)
{
const SYMID new_id= DSTACK_LENGTH((g)->t_symbols);
*DSTACK_PUSH((g)->t_symbols,SYM)= symbol;
symbol->t_symbol_id= new_id;
}

/*:56*//*57:*/
#line 718 "./marpa.w"

PRIVATE int symbol_is_valid(GRAMMAR g,SYMID symid)
{
return symid>=0&&symid<SYM_Count_of_G(g);
}

/*:57*//*63:*/
#line 736 "./marpa.w"

int marpa_g_rule_count(Marpa_Grammar g){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 738 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 739 "./marpa.w"

return RULE_Count_of_G(g);
}

/*:63*//*65:*/
#line 748 "./marpa.w"

PRIVATE
void rule_add(
GRAMMAR g,
RULE rule)
{
const RULEID new_id= DSTACK_LENGTH((g)->t_rules);
*DSTACK_PUSH((g)->t_rules,RULE)= rule;
rule->t_id= new_id;
Size_of_G(g)+= 1+Length_of_RULE(rule);
g->t_max_rule_length= MAX(Length_of_RULE(rule),g->t_max_rule_length);
}

/*:65*//*69:*/
#line 769 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 772 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 773 "./marpa.w"

return g->t_original_start_symid;
}
/*:69*//*70:*/
#line 778 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 781 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 782 "./marpa.w"

/*1149:*/
#line 13087 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1149*/
#line 783 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 784 "./marpa.w"

return g->t_original_start_symid= symid;
}

/*:70*//*83:*/
#line 845 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 848 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 849 "./marpa.w"

return G_is_Precomputed(g);
}

/*:83*//*86:*/
#line 857 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 860 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 861 "./marpa.w"

return g->t_has_cycle;
}

/*:86*//*98:*/
#line 925 "./marpa.w"

PRIVATE
void event_new(struct marpa_g*g,int type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:98*//*99:*/
#line 934 "./marpa.w"

PRIVATE
void int_event_new(struct marpa_g*g,int type,int value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:99*//*100:*/
#line 944 "./marpa.w"

int
marpa_g_event(Marpa_Grammar g,Marpa_Event public_event,
int ix)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 949 "./marpa.w"

const int index_out_of_bounds= -1;
DSTACK events= &g->t_events;
GEV internal_event;
int type;

MARPA_DEBUG4("%s: ix=%d, event_count=%d",STRLOC,ix,G_EVENT_COUNT(g));
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

/*:100*//*111:*/
#line 1039 "./marpa.w"

Marpa_Error_Code marpa_g_error(Marpa_Grammar g,const char**p_error_string)
{
const Marpa_Error_Code error_code= g->t_error;
const char*error_string= g->t_error_string;
if(IS_G_OK(g)){
g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
}
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:111*//*117:*/
#line 1086 "./marpa.w"

PRIVATE SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= my_malloc(sizeof(SYM_Object));
/*116:*/
#line 1083 "./marpa.w"

symbol->t_or_node_type= UNVALUED_TOKEN_OR_NODE;

/*:116*//*121:*/
#line 1118 "./marpa.w"

DSTACK_INIT(symbol->t_lhs,RULEID,1);
/*:121*//*126:*/
#line 1162 "./marpa.w"

DSTACK_INIT(symbol->t_rhs,RULEID,1);
/*:126*//*131:*/
#line 1204 "./marpa.w"

SYM_is_Internal(symbol)= 1;
/*:131*//*134:*/
#line 1226 "./marpa.w"

SYM_is_Ask_Me_When_Null(symbol)= 0;
/*:134*//*137:*/
#line 1248 "./marpa.w"

symbol->t_is_accessible= 0;
/*:137*//*140:*/
#line 1268 "./marpa.w"

symbol->t_is_counted= 0;
/*:140*//*143:*/
#line 1283 "./marpa.w"

symbol->t_is_nulling= 0;
/*:143*//*146:*/
#line 1305 "./marpa.w"

symbol->t_is_terminal= 0;
symbol->t_is_marked_terminal= 0;
/*:146*//*151:*/
#line 1341 "./marpa.w"

symbol->t_is_productive= 0;
/*:151*//*154:*/
#line 1357 "./marpa.w"
symbol->t_is_start= 0;
/*:154*//*158:*/
#line 1380 "./marpa.w"

symbol->t_is_proper_alias= 0;
symbol->t_is_nulling_alias= 0;
symbol->t_alias= NULL;

/*:158*//*165:*/
#line 1466 "./marpa.w"

symbol->t_virtual_lhs_rule= NULL;

/*:165*/
#line 1091 "./marpa.w"

symbol_add(g,symbol);
return symbol;
}

/*:117*//*118:*/
#line 1096 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const SYM symbol= symbol_new(g);
symbol->t_is_internal= 0;
return ID_of_SYM(symbol);
}

/*:118*//*119:*/
#line 1105 "./marpa.w"

PRIVATE void symbol_free(SYM symbol)
{
/*122:*/
#line 1120 "./marpa.w"

DSTACK_DESTROY(symbol->t_lhs);

/*:122*//*127:*/
#line 1164 "./marpa.w"

DSTACK_DESTROY(symbol->t_rhs);

/*:127*/
#line 1108 "./marpa.w"
my_free(symbol);
}

/*:119*//*123:*/
#line 1123 "./marpa.w"

Marpa_Rule_ID _marpa_g_symbol_lhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1126 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1127 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1128 "./marpa.w"

return DSTACK_LENGTH(SYM_by_ID(symid)->t_lhs);
}
Marpa_Rule_ID _marpa_g_symbol_lhs(struct marpa_g*g,Marpa_Symbol_ID symid,int ix)
{
SYM symbol;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1134 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1135 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1136 "./marpa.w"

symbol= SYM_by_ID(symid);
if(ix<0){
MARPA_ERROR(MARPA_ERR_SYMIX_NEGATIVE);
return failure_indicator;
}
if(ix>=DSTACK_LENGTH(symbol->t_lhs)){
MARPA_ERROR(MARPA_ERR_SYMIX_OOB);
return-1;
}
return*DSTACK_INDEX(symbol->t_lhs,RULEID,ix);
}

/*:123*//*124:*/
#line 1149 "./marpa.w"

PRIVATE
void symbol_lhs_add(SYM symbol,RULEID rule_id)
{
*DSTACK_PUSH(symbol->t_lhs,RULEID)= rule_id;
}

/*:124*//*128:*/
#line 1167 "./marpa.w"

Marpa_Rule_ID _marpa_g_symbol_rhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1170 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1171 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1172 "./marpa.w"

return DSTACK_LENGTH(SYM_by_ID(symid)->t_rhs);
}
Marpa_Rule_ID _marpa_g_symbol_rhs(struct marpa_g*g,Marpa_Symbol_ID symid,int ix)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1177 "./marpa.w"

SYM symbol;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1179 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1180 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_SYMIX_NEGATIVE);
return failure_indicator;
}
symbol= SYM_by_ID(symid);
if(ix>=DSTACK_LENGTH(symbol->t_rhs)){
MARPA_ERROR(MARPA_ERR_SYMIX_OOB);
return-1;
}
return*DSTACK_INDEX(symbol->t_rhs,RULEID,ix);
}

/*:128*//*129:*/
#line 1193 "./marpa.w"

PRIVATE
void symbol_rhs_add(SYM symbol,RULEID rule_id)
{
*DSTACK_PUSH(symbol->t_rhs,RULEID)= rule_id;
}

/*:129*//*132:*/
#line 1206 "./marpa.w"

int marpa_g_symbol_is_internal(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1211 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1212 "./marpa.w"

return SYM_is_Internal(SYM_by_ID(symid));
}

/*:132*//*135:*/
#line 1228 "./marpa.w"

int marpa_g_symbol_is_ask_me_when_null(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1233 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1234 "./marpa.w"

return SYM_is_Ask_Me_When_Null(SYM_by_ID(symid));
}
int marpa_g_symbol_ask_me_when_null_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1241 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1242 "./marpa.w"

symbol= SYM_by_ID(symid);
return SYM_is_Ask_Me_When_Null(symbol)= value?1:0;
}
/*:135*//*138:*/
#line 1256 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1259 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1260 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 1261 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1262 "./marpa.w"

return SYM_by_ID(symid)->t_is_accessible;
}

/*:138*//*141:*/
#line 1270 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1274 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1275 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1276 "./marpa.w"

return SYM_by_ID(symid)->t_is_counted;
}

/*:141*//*144:*/
#line 1285 "./marpa.w"

int marpa_g_symbol_is_nulling(GRAMMAR g,SYMID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1288 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1289 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 1290 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1291 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));
}

/*:144*//*148:*/
#line 1311 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1315 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1316 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1317 "./marpa.w"

return SYMID_is_Terminal(symid);
}
/*:148*//*149:*/
#line 1320 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1325 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1326 "./marpa.w"

/*1149:*/
#line 13087 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1149*/
#line 1327 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1328 "./marpa.w"

symbol= SYM_by_ID(symid);
/*1151:*/
#line 13098 "./marpa.w"

if(UNLIKELY(SYM_is_Internal(symbol))){
MARPA_ERROR(MARPA_ERR_INTERNAL_SYM);
return failure_indicator;
}
/*:1151*/
#line 1330 "./marpa.w"

if(UNLIKELY(value<0||value> 1)){
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
SYM_is_Marked_Terminal(symbol)= 1;
return SYM_is_Terminal(symbol)= value;
}

/*:149*//*152:*/
#line 1343 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1348 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1349 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 1350 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1351 "./marpa.w"

return SYM_by_ID(symid)->t_is_productive;
}

/*:152*//*155:*/
#line 1358 "./marpa.w"

int _marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1361 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1362 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 1363 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1364 "./marpa.w"

return SYM_by_ID(symid)->t_is_start;
}

/*:155*//*159:*/
#line 1389 "./marpa.w"

PRIVATE
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID _marpa_g_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1397 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1398 "./marpa.w"

symbol= SYM_by_ID(symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}

/*:159*//*160:*/
#line 1408 "./marpa.w"

PRIVATE
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID _marpa_g_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1416 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1417 "./marpa.w"

symbol= SYM_by_ID(symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
MARPA_ERROR(MARPA_ERR_NO_ALIAS);
return-1;
}
return ID_of_SYM(alias);
}

/*:160*//*162:*/
#line 1433 "./marpa.w"

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
#line 1474 "./marpa.w"

Marpa_Rule_ID _marpa_g_symbol_virtual_lhs_rule(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
RULE virtual_lhs_rule;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1479 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 1480 "./marpa.w"

symbol= SYM_by_ID(symid);
virtual_lhs_rule= symbol->t_virtual_lhs_rule;
return virtual_lhs_rule==NULL?-1:ID_of_RULE(virtual_lhs_rule);
}

/*:167*//*173:*/
#line 1516 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,int length)
{
RULE rule;
const int rule_sizeof= offsetof(struct s_rule,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
rule= my_obstack_alloc(&g->t_obs,rule_sizeof);
/*197:*/
#line 1958 "./marpa.w"

Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
{
int i;
for(i= 0;i<length;i++)
{
rule->t_symbols[i+1]= rhs[i];
}
}

/*:197*/
#line 1525 "./marpa.w"

/*208:*/
#line 2028 "./marpa.w"

rule->t_is_discard= 0;
/*:208*//*217:*/
#line 2111 "./marpa.w"

rule->t_is_loop= 0;
/*:217*//*221:*/
#line 2130 "./marpa.w"

rule->t_is_virtual_loop= 0;
/*:221*//*226:*/
#line 2162 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:226*//*229:*/
#line 2189 "./marpa.w"

RULE_has_Virtual_LHS(rule)= 0;
/*:229*//*232:*/
#line 2205 "./marpa.w"

RULE_has_Virtual_RHS(rule)= 0;
/*:232*//*235:*/
#line 2223 "./marpa.w"
rule->t_virtual_start= -1;
/*:235*//*238:*/
#line 2240 "./marpa.w"
rule->t_virtual_end= -1;
/*:238*//*242:*/
#line 2257 "./marpa.w"
rule->t_original= -1;
/*:242*//*246:*/
#line 2276 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:246*//*249:*/
#line 2302 "./marpa.w"

RULE_is_Ask_Me(rule)= 0;
/*:249*//*253:*/
#line 2360 "./marpa.w"

rule->t_is_semantic_equivalent= 0;
/*:253*//*258:*/
#line 2391 "./marpa.w"

rule->t_first_aim= NULL;

/*:258*//*262:*/
#line 2411 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:262*/
#line 1526 "./marpa.w"

rule_add(g,rule);
/*189:*/
#line 1806 "./marpa.w"

symbol_lhs_add(SYM_by_ID(rule->t_symbols[0]),rule->t_id);
if(Length_of_RULE(rule)> 0){
int rh_list_ix;
const unsigned int alloc_size= Length_of_RULE(rule)*sizeof(SYMID);
Marpa_Symbol_ID*rh_symbol_list= my_slice_alloc(alloc_size);
int rh_symbol_list_length= 1;
/*193:*/
#line 1873 "./marpa.w"

{

int rhs_ix= Length_of_RULE(rule)-1;
rh_symbol_list[0]= RHS_ID_of_RULE(rule,(unsigned)rhs_ix);
rh_symbol_list_length= 1;
rhs_ix--;
for(;rhs_ix>=0;rhs_ix--){
int higher_ix;
Marpa_Symbol_ID new_symid= RHS_ID_of_RULE(rule,(unsigned)rhs_ix);
int next_highest_ix= rh_symbol_list_length-1;
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

/*:193*/
#line 1814 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(rh_symbol_list[rh_list_ix]),
rule->t_id);
}
my_slice_free1(alloc_size,rh_symbol_list);
}

/*:189*/
#line 1528 "./marpa.w"

return rule;
}

/*:173*//*174:*/
#line 1532 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,int length)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1536 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1539 "./marpa.w"

/*1149:*/
#line 13087 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1149*/
#line 1540 "./marpa.w"

if(length> MAX_RHS_LENGTH){
MARPA_ERROR(MARPA_ERR_RHS_TOO_LONG);
return failure_indicator;
}
if(is_rule_duplicate(g,lhs,rhs,length)==1){
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
return failure_indicator;
}
if(!rule_check(g,lhs,rhs,length))return failure_indicator;
rule= rule_start(g,lhs,rhs,length);
rule_id= rule->t_id;
return rule_id;
}

/*:174*//*175:*/
#line 1555 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
RULEID return_value= -2;
SYM internal_lhs;
SYMID internal_lhs_id;
SYMID*temp_rhs= NULL;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1566 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1567 "./marpa.w"

/*1149:*/
#line 13087 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1149*/
#line 1568 "./marpa.w"

G_EVENTS_CLEAR(g);
if(UNLIKELY(is_rule_duplicate(g,lhs_id,&rhs_id,1)==1))
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
return failure_indicator;
}

/*177:*/
#line 1609 "./marpa.w"

if(separator_id!=-1)
{
SYM separator;
if(UNLIKELY(!symbol_is_valid(g,separator_id)))
{
MARPA_ERROR(MARPA_ERR_BAD_SEPARATOR);
goto FAILURE;
}
separator= SYM_by_ID(separator_id);
if(UNLIKELY(SYM_is_Internal(separator))){
MARPA_ERROR(MARPA_ERR_INTERNAL_SYM);
goto FAILURE;
}
}
{
SYM lhs;
if(UNLIKELY(!symbol_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
goto FAILURE;
}
lhs= SYM_by_ID(lhs_id);
if(UNLIKELY(SYM_is_Internal(lhs))){
MARPA_ERROR(MARPA_ERR_INTERNAL_SYM);
goto FAILURE;
}
}
{
SYM rhs;
if(UNLIKELY(!symbol_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
goto FAILURE;
}
rhs= SYM_by_ID(rhs_id);
if(UNLIKELY(SYM_is_Internal(rhs))){
MARPA_ERROR(MARPA_ERR_INTERNAL_SYM);
goto FAILURE;
}
}

/*:177*/
#line 1576 "./marpa.w"

/*176:*/
#line 1600 "./marpa.w"

{
original_rule= rule_start(g,lhs_id,&rhs_id,1);
RULE_is_Used(original_rule)= 0;
original_rule_id= original_rule->t_id;
original_rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION)
&&separator_id>=0;
}

/*:176*/
#line 1577 "./marpa.w"

/*178:*/
#line 1651 "./marpa.w"

SYM_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(separator_id)->t_is_counted= 1;}
/*:178*/
#line 1578 "./marpa.w"

if(min==0){/*179:*/
#line 1654 "./marpa.w"

{
RULE rule;
rule= rule_start(g,lhs_id,0,0);
rule->t_is_semantic_equivalent= 1;
rule->t_original= original_rule_id;
}
/*:179*/
#line 1579 "./marpa.w"
}
min= 1;
/*180:*/
#line 1661 "./marpa.w"

{
internal_lhs= symbol_new(g);
internal_lhs_id= ID_of_SYM(internal_lhs);
}

/*:180*/
#line 1581 "./marpa.w"

/*181:*/
#line 1678 "./marpa.w"

temp_rhs= my_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:181*/
#line 1582 "./marpa.w"

/*183:*/
#line 1681 "./marpa.w"

{
RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= 1;

RULE_has_Virtual_RHS(rule)= 1;
}

/*:183*/
#line 1583 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*184:*/
#line 1693 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= 1;
RULE_has_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= 1;
}
/*:184*/
#line 1585 "./marpa.w"

}
/*185:*/
#line 1706 "./marpa.w"

{RULE rule;
int rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
RULE_has_Virtual_LHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix;
}
/*:185*/
#line 1587 "./marpa.w"

/*186:*/
#line 1719 "./marpa.w"

{RULE rule;
int rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
RULE_has_Virtual_LHS(rule)= 1;
RULE_has_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix-1;
}

/*:186*/
#line 1588 "./marpa.w"


return_value= original_rule_id;
FAILURE:;
if(return_value<0){
G_EVENTS_CLEAR(g);
}
/*182:*/
#line 1680 "./marpa.w"
my_free(temp_rhs);
/*:182*/
#line 1595 "./marpa.w"

return return_value;
}

/*:175*//*188:*/
#line 1773 "./marpa.w"

PRIVATE
int is_rule_duplicate(GRAMMAR g,
SYMID lhs_id,SYMID*rhs_ids,int length)
{
int ix;
SYM lhs= SYM_by_ID(lhs_id);
int same_lhs_count= DSTACK_LENGTH(lhs->t_lhs);
for(ix= 0;ix<same_lhs_count;ix++){
RULEID same_lhs_rule_id= *DSTACK_INDEX(lhs->t_lhs,RULEID,ix);
int rhs_position;
RULE rule= RULE_by_ID(g,same_lhs_rule_id);
const int rule_length= Length_of_RULE(rule);
if(rule_length!=length){goto RULE_IS_NOT_DUPLICATE;}
for(rhs_position= 0;rhs_position<rule_length;rhs_position++){
if(RHS_ID_of_RULE(rule,rhs_position)!=rhs_ids[rhs_position]){
goto RULE_IS_NOT_DUPLICATE;
}
}
return 1;
RULE_IS_NOT_DUPLICATE:;
}
return 0;
}

/*:188*//*196:*/
#line 1928 "./marpa.w"

PRIVATE int
rule_check(GRAMMAR g,SYMID lhs_id,SYMID*rhs_ids,int length)
{
int rh_index;
SYM lhs;
if(UNLIKELY(!symbol_is_valid(g,lhs_id)))
goto INVALID_SYMID;
lhs= SYM_by_ID(lhs_id);
if(UNLIKELY(SYM_is_Internal(lhs)))
goto INTERNAL_SYM;
for(rh_index= 0;rh_index<length;rh_index++)
{
SYMID symid= rhs_ids[rh_index];
SYM rhs;
if(UNLIKELY(!symbol_is_valid(g,symid)))
goto INVALID_SYMID;
rhs= SYM_by_ID(symid);
if(UNLIKELY(SYM_is_Internal(rhs)))
goto INTERNAL_SYM;
}
return 1;
INTERNAL_SYM:;
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return 0;
INVALID_SYMID:;
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return 0;
}

/*:196*//*198:*/
#line 1969 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:198*//*199:*/
#line 1973 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID rule_id){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1975 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1976 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 1977 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));
}
/*:199*//*200:*/
#line 1980 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:200*//*201:*/
#line 1984 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,int ix){
RULE rule;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 1987 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 1988 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 1989 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:201*//*202:*/
#line 1994 "./marpa.w"

PRIVATE size_t rule_length_get(RULE rule)
{
return Length_of_RULE(rule);}
/*:202*//*203:*/
#line 1998 "./marpa.w"

int marpa_g_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2000 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 2001 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2002 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}

/*:203*//*209:*/
#line 2030 "./marpa.w"

int marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2035 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 2036 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2037 "./marpa.w"

return!RULE_by_ID(g,rule_id)->t_is_discard;
}

/*:209*//*212:*/
#line 2068 "./marpa.w"

PRIVATE int rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(lhs_id)->t_is_accessible;}
int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2075 "./marpa.w"

RULE rule;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 2077 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2078 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}

/*:212*//*214:*/
#line 2085 "./marpa.w"

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
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2096 "./marpa.w"

RULE rule;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 2098 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2099 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}

/*:214*//*218:*/
#line 2113 "./marpa.w"

int marpa_g_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2116 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 2117 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2118 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 2119 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}

/*:218*//*222:*/
#line 2132 "./marpa.w"

int _marpa_g_rule_is_virtual_loop(Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2135 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 2136 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2137 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;
}

/*:222*//*224:*/
#line 2144 "./marpa.w"

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

/*:224*//*227:*/
#line 2164 "./marpa.w"

int _marpa_g_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2167 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2168 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}

/*:227*//*230:*/
#line 2191 "./marpa.w"

int _marpa_g_rule_is_virtual_lhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2196 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 2197 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2198 "./marpa.w"

return RULE_has_Virtual_LHS(RULE_by_ID(g,rule_id));
}

/*:230*//*233:*/
#line 2207 "./marpa.w"

int _marpa_g_rule_is_virtual_rhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2212 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 2213 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2214 "./marpa.w"

return RULE_has_Virtual_RHS(RULE_by_ID(g,rule_id));
}

/*:233*//*236:*/
#line 2224 "./marpa.w"

unsigned int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2229 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 2230 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2231 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}

/*:236*//*239:*/
#line 2241 "./marpa.w"

unsigned int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2246 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 2247 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2248 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}

/*:239*//*243:*/
#line 2258 "./marpa.w"

Marpa_Rule_ID _marpa_g_rule_original(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2263 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2264 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_original;
}

/*:243*//*247:*/
#line 2277 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2282 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 2283 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2284 "./marpa.w"

return Real_SYM_Count_of_RULE(RULE_by_ID(g,rule_id));
}

/*:247*//*250:*/
#line 2304 "./marpa.w"

int marpa_g_rule_is_ask_me(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2309 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2310 "./marpa.w"

return RULE_is_Ask_Me(RULE_by_ID(g,rule_id));
}
/*:250*//*251:*/
#line 2329 "./marpa.w"

int marpa_g_rule_whatever_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2334 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2335 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}
int marpa_g_rule_ask_me_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2343 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2344 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 1;
}
int marpa_g_rule_first_child_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2352 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2353 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}

/*:251*//*256:*/
#line 2371 "./marpa.w"

Marpa_Rule_ID
_marpa_g_rule_semantic_equivalent(Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2376 "./marpa.w"

/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 2377 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(RULE_has_Virtual_LHS(rule))return-1;
if(rule->t_is_semantic_equivalent)return rule->t_original;
return rule_id;
}

/*:256*//*264:*/
#line 2425 "./marpa.w"

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
#line 2457 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 2460 "./marpa.w"

int return_value= failure_indicator;
struct obstack*obs_precompute= my_new(struct obstack,1);
/*267:*/
#line 2494 "./marpa.w"

Bit_Vector nullable_v= NULL;

/*:267*//*270:*/
#line 2542 "./marpa.w"

unsigned int pre_rewrite_rule_count= RULE_Count_of_G(g);
unsigned int pre_rewrite_symbol_count= SYM_Count_of_G(g);

/*:270*//*274:*/
#line 2574 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_original_start_symid;

/*:274*//*284:*/
#line 2745 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:284*/
#line 2463 "./marpa.w"

my_obstack_init(obs_precompute);
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 2465 "./marpa.w"

G_EVENTS_CLEAR(g);
/*271:*/
#line 2546 "./marpa.w"

if(RULE_Count_of_G(g)<=0){
MARPA_ERROR(MARPA_ERR_NO_RULES);
return failure_indicator;
}
/*:271*/
#line 2467 "./marpa.w"

/*1149:*/
#line 13087 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1149*/
#line 2468 "./marpa.w"

/*273:*/
#line 2555 "./marpa.w"

{
if(original_start_symid<0)
{
MARPA_ERROR(MARPA_ERR_NO_START_SYM);
return failure_indicator;
}
if(!symbol_is_valid(g,original_start_symid))
{
MARPA_ERROR(MARPA_ERR_INVALID_START_SYM);
return failure_indicator;
}
if(DSTACK_LENGTH(SYM_by_ID(original_start_symid)->t_lhs)<=0)
{
MARPA_ERROR(MARPA_ERR_START_NOT_LHS);
return failure_indicator;
}
}

/*:273*/
#line 2469 "./marpa.w"

{
/*277:*/
#line 2641 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:277*//*278:*/
#line 2644 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;
Bit_Matrix rule_x_rh_sym_matrix= NULL;

/*:278*//*282:*/
#line 2703 "./marpa.w"

Bit_Vector productive_v= NULL;

/*:282*/
#line 2471 "./marpa.w"

/*269:*/
#line 2529 "./marpa.w"

{
/*275:*/
#line 2577 "./marpa.w"

{
Marpa_Rule_ID rule_id;
lhs_v= bv_obs_create(obs_precompute,pre_rewrite_symbol_count);
empty_lhs_v= bv_obs_shadow(obs_precompute,lhs_v);
rule_x_rh_sym_matrix= 
matrix_obs_create(obs_precompute,pre_rewrite_rule_count,
pre_rewrite_symbol_count);
for(rule_id= 0;rule_id<(Marpa_Rule_ID)pre_rewrite_rule_count;
rule_id++)
{
const RULE rule= RULE_by_ID(g,rule_id);
const Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
const int rule_length= Length_of_RULE(rule);
bv_bit_set(lhs_v,(unsigned int)lhs_id);
if(rule_length<=0)
{
bv_bit_set(empty_lhs_v,(unsigned int)lhs_id);
}
else
{
int rhs_ix;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
matrix_bit_set(rule_x_rh_sym_matrix,
(unsigned int)RHS_ID_of_RULE(rule,rhs_ix),
rule_id);
}
}
}
}

/*:275*/
#line 2531 "./marpa.w"

/*276:*/
#line 2612 "./marpa.w"

{
SYMID symid;
terminal_v= bv_obs_create(obs_precompute,pre_rewrite_symbol_count);
bv_not(terminal_v,lhs_v);
for(symid= 0;symid<(SYMID)pre_rewrite_symbol_count;symid++)
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

/*:276*/
#line 2532 "./marpa.w"

/*283:*/
#line 2724 "./marpa.w"

{
Marpa_Rule_ID rule_id;
RULEID rule_count_of_g= RULE_Count_of_G(g);
reach_matrix
= matrix_obs_create(obs_precompute,pre_rewrite_symbol_count,pre_rewrite_symbol_count);
for(rule_id= 0;rule_id<rule_count_of_g;rule_id++)
{
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
unsigned int rhs_ix,rule_length= Length_of_RULE(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
matrix_bit_set(reach_matrix,
(unsigned int)lhs_id,
(unsigned int)RHS_ID_of_RULE(rule,rhs_ix));
}
}
transitive_closure(reach_matrix);
}

/*:283*/
#line 2533 "./marpa.w"

/*279:*/
#line 2649 "./marpa.w"

{
unsigned int min,max,start;
SYMID symid;
int counted_nullables= 0;
nullable_v= bv_obs_clone(obs_precompute,empty_lhs_v);
rhs_closure(g,nullable_v);
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2)
{
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;
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

/*:279*/
#line 2534 "./marpa.w"

/*280:*/
#line 2676 "./marpa.w"

{
productive_v= bv_obs_shadow(obs_precompute,nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{
unsigned int min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);
start= max+2)
{
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;symid++)
{
SYM symbol= SYM_by_ID(symid);
symbol->t_is_productive= 1;
}
}
}
}

/*:280*/
#line 2535 "./marpa.w"

/*281:*/
#line 2697 "./marpa.w"

if(UNLIKELY(!bv_bit_test(productive_v,(unsigned int)original_start_symid)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:281*/
#line 2536 "./marpa.w"

/*285:*/
#line 2750 "./marpa.w"

{
Bit_Vector accessible_v= 
matrix_row(reach_matrix,(unsigned int)original_start_symid);
unsigned int min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2)
{
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;symid++)
{
SYM symbol= SYM_by_ID(symid);
symbol->t_is_accessible= 1;
}
}
SYM_by_ID(original_start_symid)->t_is_accessible= 1;
}

/*:285*/
#line 2537 "./marpa.w"

/*286:*/
#line 2770 "./marpa.w"

{
Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
int nulling_terminal_found= 0;
unsigned int min,max,start;
for(start= 0;bv_scan(lhs_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID productive_id;
for(productive_id= (Marpa_Symbol_ID)min;
productive_id<=(Marpa_Symbol_ID)max;productive_id++)
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

/*:286*/
#line 2538 "./marpa.w"

g->t_is_precomputed= 1;
}

/*:269*/
#line 2472 "./marpa.w"

/*341:*/
#line 3389 "./marpa.w"

{
int rule_count_of_g= RULE_Count_of_G(g);
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,(unsigned int)rule_count_of_g,
(unsigned int)rule_count_of_g);
/*342:*/
#line 3411 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<rule_count_of_g;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
SYMID nonnulling_id= -1;
int nonnulling_count= 0;
int rhs_ix,rule_length;
rule_length= Length_of_RULE(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
if(bv_bit_test(nullable_v,symid))continue;
nonnulling_id= symid;
nonnulling_count++;
}


if(nonnulling_count==1){
/*343:*/
#line 3447 "./marpa.w"

{
SYM rhs_symbol= SYM_by_ID(nonnulling_id);
RULEID ix;
RULEID no_of_lhs_rules= DSTACK_LENGTH(rhs_symbol->t_lhs);
for(ix= 0;ix<no_of_lhs_rules;ix++)
{


const RULEID to_rule_id= *DSTACK_INDEX(rhs_symbol->t_lhs,RULEID,ix);
MARPA_DEBUG4("%s: unit transition from=%d, to=%d",STRLOC,rule_id,
to_rule_id);
matrix_bit_set(unit_transition_matrix,(unsigned int)rule_id,
to_rule_id);
}
}

/*:343*/
#line 3428 "./marpa.w"

}else if(nonnulling_count==0){
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
nonnulling_id= RHS_ID_of_RULE(rule,rhs_ix);
if(!bv_bit_test(nullable_v,nonnulling_id))
continue;
if(SYM_is_Nulling(SYM_by_ID(nonnulling_id)))
continue;

/*343:*/
#line 3447 "./marpa.w"

{
SYM rhs_symbol= SYM_by_ID(nonnulling_id);
RULEID ix;
RULEID no_of_lhs_rules= DSTACK_LENGTH(rhs_symbol->t_lhs);
for(ix= 0;ix<no_of_lhs_rules;ix++)
{


const RULEID to_rule_id= *DSTACK_INDEX(rhs_symbol->t_lhs,RULEID,ix);
MARPA_DEBUG4("%s: unit transition from=%d, to=%d",STRLOC,rule_id,
to_rule_id);
matrix_bit_set(unit_transition_matrix,(unsigned int)rule_id,
to_rule_id);
}
}

/*:343*/
#line 3438 "./marpa.w"

}
}
}
}

/*:342*/
#line 3396 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*344:*/
#line 3471 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<rule_count_of_g;rule_id++)
{
RULE rule;
if(!matrix_bit_test
(unit_transition_matrix,(unsigned int)rule_id,
(unsigned int)rule_id))
continue;
loop_rule_count++;
rule= RULE_by_ID(g,rule_id);
rule->t_is_loop= 1;
rule->t_is_virtual_loop= rule->t_virtual_start<0
||!RULE_has_Virtual_RHS(rule);
}
}

/*:344*/
#line 3398 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:341*/
#line 2473 "./marpa.w"

}
/*293:*/
#line 2862 "./marpa.w"

{
/*294:*/
#line 2881 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:294*//*298:*/
#line 2940 "./marpa.w"

int factor_count;
int*factor_positions;
/*:298*//*303:*/
#line 2990 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:303*/
#line 2864 "./marpa.w"

/*299:*/
#line 2943 "./marpa.w"

factor_positions= my_new(int,g->t_max_rule_length);
/*:299*//*304:*/
#line 2993 "./marpa.w"

piece_rhs= my_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= my_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:304*/
#line 2865 "./marpa.w"

/*296:*/
#line 2893 "./marpa.w"

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

/*:296*/
#line 2866 "./marpa.w"

pre_chaf_rule_count= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<pre_chaf_rule_count;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const int rule_length= Length_of_RULE(rule);
int nullable_suffix_ix= 0;
/*295:*/
#line 2885 "./marpa.w"

if(!RULE_is_Used(rule)){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}

/*:295*/
#line 2872 "./marpa.w"

/*297:*/
#line 2924 "./marpa.w"

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
/*:297*/
#line 2873 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*301:*/
#line 2949 "./marpa.w"

RULE_is_Used(rule)= 0;
{


int unprocessed_factor_count;

int factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);


int piece_end,piece_start= 0;
for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*307:*/
#line 3003 "./marpa.w"

SYMID chaf_virtual_symid;
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= first_factor_position-piece_start;
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*302:*/
#line 2973 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:302*/
#line 3011 "./marpa.w"

/*308:*/
#line 3030 "./marpa.w"

{
int remaining_rhs_length,piece_rhs_length;
/*309:*/
#line 3042 "./marpa.w"

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
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3057 "./marpa.w"

}

/*:309*/
#line 3033 "./marpa.w"
;
/*310:*/
#line 3060 "./marpa.w"

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
rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3078 "./marpa.w"

}

/*:310*/
#line 3034 "./marpa.w"
;
/*311:*/
#line 3083 "./marpa.w"
{
Marpa_Symbol_ID proper_id= RHS_ID_of_RULE(rule,first_factor_position);
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
ID_of_SYM(alias);
}
{RULE chaf_rule;
int real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3093 "./marpa.w"

}

/*:311*/
#line 3035 "./marpa.w"
;
/*312:*/
#line 3102 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
int real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3107 "./marpa.w"

}

/*:312*/
#line 3036 "./marpa.w"
;
}

/*:308*/
#line 3012 "./marpa.w"

factor_position_ix++;
}else{
int second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*302:*/
#line 2973 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:302*/
#line 3017 "./marpa.w"

/*314:*/
#line 3112 "./marpa.w"
{
int piece_rhs_length;
RULE chaf_rule;
int real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:314*//*315:*/
#line 3121 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3127 "./marpa.w"


/*:315*//*316:*/
#line 3130 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3135 "./marpa.w"


/*:316*//*317:*/
#line 3138 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3144 "./marpa.w"


/*:317*//*318:*/
#line 3147 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3150 "./marpa.w"


/*:318*//*319:*/
#line 3153 "./marpa.w"
}

/*:319*/
#line 3018 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:307*/
#line 2964 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*320:*/
#line 3157 "./marpa.w"
{
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= first_factor_position-piece_start;
int second_factor_position= factor_positions[factor_position_ix+1];
int second_factor_piece_position= second_factor_position-piece_start;
int real_symbol_count;
int piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:320*//*321:*/
#line 3171 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3176 "./marpa.w"


/*:321*//*322:*/
#line 3179 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3184 "./marpa.w"


/*:322*//*323:*/
#line 3187 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3193 "./marpa.w"


/*:323*//*324:*/
#line 3197 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3201 "./marpa.w"

}

/*:324*//*325:*/
#line 3205 "./marpa.w"
}

/*:325*/
#line 2967 "./marpa.w"

}else{
/*326:*/
#line 3208 "./marpa.w"
{
int piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
int real_symbol_count;
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:326*//*327:*/
#line 3219 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3224 "./marpa.w"


/*:327*//*328:*/
#line 3228 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*330:*/
#line 3244 "./marpa.w"

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
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:330*/
#line 3234 "./marpa.w"

}

/*:328*//*329:*/
#line 3238 "./marpa.w"
}

/*:329*/
#line 2969 "./marpa.w"

}
}

/*:301*/
#line 2876 "./marpa.w"

NEXT_RULE:;
}
/*300:*/
#line 2945 "./marpa.w"

my_free(factor_positions);

/*:300*//*305:*/
#line 2996 "./marpa.w"

my_free(piece_rhs);
my_free(remaining_rhs);

/*:305*/
#line 2879 "./marpa.w"

}
/*:293*/
#line 2475 "./marpa.w"

/*333:*/
#line 3274 "./marpa.w"

{
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g->t_original_start_symid);
/*334:*/
#line 3286 "./marpa.w"

if(SYM_is_Nulling(old_start)){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:334*/
#line 3281 "./marpa.w"

if(proper_old_start){/*335:*/
#line 3296 "./marpa.w"
{
RULE new_start_rule;
proper_old_start->t_is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= ID_of_SYM(proper_new_start);
proper_new_start->t_is_accessible= 1;
proper_new_start->t_is_productive= 1;
proper_new_start->t_is_start= 1;
new_start_rule= rule_start(g,proper_new_start_id,&ID_of_SYM(old_start),1);
RULE_has_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= 1;
g->t_proper_start_rule= new_start_rule;
}

/*:335*/
#line 3282 "./marpa.w"
}
if(nulling_old_start){/*336:*/
#line 3315 "./marpa.w"
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
SYM_is_Nulling(nulling_new_start)= 1;
nulling_new_start->t_is_productive= 1;
nulling_new_start->t_is_accessible= 1;
}
nulling_new_start->t_is_start= 1;
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
RULE_has_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= 0;
g->t_null_start_rule= new_start_rule;
}

/*:336*/
#line 3283 "./marpa.w"
}
}

/*:333*/
#line 2476 "./marpa.w"

if(!G_is_Trivial(g)){
/*372:*/
#line 3729 "./marpa.w"

{
RULEID rule_id;
AIMID no_of_items;
RULEID rule_count_of_g= RULE_Count_of_G(g);
AIM base_item= my_new(struct s_AHFA_item,Size_of_G(g));
AIM current_item= base_item;
unsigned int symbol_instance_of_next_rule= 0;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)rule_count_of_g;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
if(RULE_is_Used(rule)){
/*373:*/
#line 3752 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_RULE(rule);rhs_ix++)
{
SYMID rh_symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(rh_symid);
if(!symbol->t_is_nulling)
{
Last_Proper_SYMI_of_RULE(rule)= symbol_instance_of_next_rule+rhs_ix;
/*374:*/
#line 3776 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:374*/
#line 3763 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*375:*/
#line 3785 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:375*/
#line 3772 "./marpa.w"

current_item++;
}

/*:373*/
#line 3740 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
no_of_items= AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= my_renew(struct s_AHFA_item,base_item,no_of_items);
/*376:*/
#line 3799 "./marpa.w"

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

/*:376*/
#line 3748 "./marpa.w"

/*381:*/
#line 3863 "./marpa.w"

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

/*:381*/
#line 3749 "./marpa.w"

}

/*:372*/
#line 2478 "./marpa.w"

/*428:*/
#line 4228 "./marpa.w"

{
/*429:*/
#line 4246 "./marpa.w"

AHFA p_working_state;
const unsigned int initial_no_of_states= 2*Size_of_G(g);
AIM AHFA_item_0_p= g->t_AHFA_items;
const unsigned int symbol_count_of_g= SYM_Count_of_G(g);
const unsigned int rule_count_of_g= RULE_Count_of_G(g);
Bit_Matrix prediction_matrix;
RULE*rule_by_sort_key= my_new(RULE,rule_count_of_g);
struct avl_table*duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
int ahfa_count_of_g;
AHFA ahfas_of_g;

/*:429*/
#line 4230 "./marpa.w"

/*430:*/
#line 4260 "./marpa.w"

/*431:*/
#line 4264 "./marpa.w"

{
unsigned int item_id;
unsigned int no_of_items_in_grammar= AIM_Count_of_G(g);
duplicates= _marpa_avl_create(AHFA_state_cmp,NULL,NULL);
singleton_duplicates= my_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++)
{
singleton_duplicates[item_id]= NULL;
}
}

/*:431*/
#line 4261 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:430*/
#line 4231 "./marpa.w"

/*451:*/
#line 4763 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_obs_create(obs_precompute,symbol_count_of_g,symbol_count_of_g);
/*452:*/
#line 4771 "./marpa.w"

{
RULEID rule_id;
SYMID symid;
for(symid= 0;symid<(SYMID)symbol_count_of_g;symid++)
{

SYM symbol= SYM_by_ID(symid);
if(!SYMBOL_LHS_RULE_COUNT(symbol))
continue;
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

/*:452*/
#line 4766 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*453:*/
#line 4808 "./marpa.w"
{
SYMID from_symid;
unsigned int*sort_key_by_rule_id= my_new(unsigned int,rule_count_of_g);
unsigned int no_of_predictable_rules= 0;
/*454:*/
#line 4847 "./marpa.w"

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

/*:454*/
#line 4813 "./marpa.w"

/*455:*/
#line 4859 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
rule_by_sort_key[rule_id]= RULE_by_ID(g,rule_id);
}
qsort(rule_by_sort_key,(int)rule_count_of_g,
sizeof(RULE),cmp_by_rule_sort_key);
}

/*:455*/
#line 4814 "./marpa.w"

/*457:*/
#line 4889 "./marpa.w"

{
unsigned int sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:457*/
#line 4815 "./marpa.w"

/*458:*/
#line 4899 "./marpa.w"

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

SYM to_symbol= SYM_by_ID(to_symid);
RULEID ix;
RULEID no_of_lhs_rules= DSTACK_LENGTH(to_symbol->t_lhs);
for(ix= 0;ix<no_of_lhs_rules;ix++)
{

Marpa_Rule_ID rule_with_this_lhs_symbol= 
*DSTACK_INDEX(to_symbol->t_lhs,RULEID,ix);
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

/*:458*/
#line 4816 "./marpa.w"

my_free(sort_key_by_rule_id);
}

/*:453*/
#line 4768 "./marpa.w"

}

/*:451*/
#line 4232 "./marpa.w"

/*438:*/
#line 4403 "./marpa.w"

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
&states,duplicates);
}

/*:438*/
#line 4233 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*432:*/
#line 4276 "./marpa.w"
{
unsigned int no_of_items= p_working_state->t_item_count;
unsigned int current_item_ix= 0;
AIM*item_list;
Marpa_Symbol_ID working_symbol;
item_list= p_working_state->t_items;
working_symbol= Postdot_SYMID_of_AIM(item_list[0]);

if(working_symbol<0)goto NEXT_AHFA_STATE;

while(1){
unsigned int first_working_item_ix= current_item_ix;
unsigned int no_of_items_in_new_state;
for(current_item_ix++;
current_item_ix<no_of_items;
current_item_ix++){
if(Postdot_SYMID_of_AIM(item_list[current_item_ix])!=working_symbol)break;
}
no_of_items_in_new_state= current_item_ix-first_working_item_ix;
if(no_of_items_in_new_state==1){
/*440:*/
#line 4463 "./marpa.w"
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
rule_by_sort_key,&states,duplicates);
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
/*442:*/
#line 4548 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(predot_symid))
> 0)
{
Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:442*/
#line 4516 "./marpa.w"

}
}

/*:440*/
#line 4296 "./marpa.w"

}else{
/*443:*/
#line 4573 "./marpa.w"
{
AHFA p_new_state;
unsigned int predecessor_ix;
unsigned int no_of_new_items_so_far= 0;
AIM*item_list_for_new_state;
AHFA queued_AHFA_state;
p_new_state= DQUEUE_PUSH(states,AHFA_Object);
item_list_for_new_state= p_new_state->t_items= my_obstack_alloc(&g->t_obs_tricky,
no_of_items_in_new_state*sizeof(AIM));
p_new_state->t_item_count= no_of_items_in_new_state;
for(predecessor_ix= first_working_item_ix;
predecessor_ix<current_item_ix;predecessor_ix++)
{
int pre_insertion_point_ix= no_of_new_items_so_far-1;
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
my_obstack_free(&g->t_obs_tricky,item_list_for_new_state);
transition_add(obs_precompute,p_working_state,working_symbol,queued_AHFA_state);


goto NEXT_WORKING_SYMBOL;
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
AHFA_initialize(p_new_state);
AHFA_is_Predicted(p_new_state)= 0;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
/*444:*/
#line 4623 "./marpa.w"

{
unsigned int symbol_count= SYM_Count_of_G(g);
unsigned int item_ix;
unsigned int no_of_postdot_symbols;
unsigned int no_of_complete_symbols;
Bit_Vector complete_v= bv_create(symbol_count);
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_for_new_state[item_ix];
Marpa_Symbol_ID postdot= Postdot_SYMID_of_AIM(item);
if(postdot<0)
{
int complete_symbol_id= LHS_ID_of_AIM(item);
completion_count_inc(obs_precompute,p_new_state,complete_symbol_id);
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

/*:444*/
#line 4617 "./marpa.w"

transition_add(obs_precompute,p_working_state,working_symbol,p_new_state);
/*446:*/
#line 4701 "./marpa.w"
{
unsigned int item_ix;
Marpa_Symbol_ID postdot= -1;
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++){
postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot>=0)break;
}
p_new_state->t_empty_transition= NULL;
if(postdot>=0)
{
Bit_Vector predicted_rule_vector
= bv_shadow(matrix_row(prediction_matrix,(unsigned int)postdot));
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{

postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot<0)
continue;
bv_or_assign(predicted_rule_vector,
matrix_row(prediction_matrix,(unsigned int)postdot));
}

p_new_state->t_empty_transition= create_predicted_AHFA_state(g,
predicted_rule_vector,
rule_by_sort_key,
&states,
duplicates);
bv_free(predicted_rule_vector);
}
}

/*:446*/
#line 4620 "./marpa.w"

}

/*:443*/
#line 4298 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:432*/
#line 4235 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*433:*/
#line 4308 "./marpa.w"

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

/*:433*/
#line 4240 "./marpa.w"

/*435:*/
#line 4362 "./marpa.w"

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

/*:435*/
#line 4241 "./marpa.w"

/*434:*/
#line 4331 "./marpa.w"

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

/*:434*/
#line 4242 "./marpa.w"

/*436:*/
#line 4395 "./marpa.w"

my_free(rule_by_sort_key);
/*437:*/
#line 4399 "./marpa.w"

my_free(singleton_duplicates);
_marpa_avl_destroy(duplicates,NULL);

/*:437*/
#line 4397 "./marpa.w"


/*:436*/
#line 4243 "./marpa.w"

}

/*:428*/
#line 2479 "./marpa.w"

/*482:*/
#line 5227 "./marpa.w"
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

/*:482*/
#line 2480 "./marpa.w"

}
return_value= G_EVENT_COUNT(g);
FAILURE:;
my_obstack_free(obs_precompute,NULL);
my_free(obs_precompute);
return return_value;
}
/*:266*//*331:*/
#line 3263 "./marpa.w"

PRIVATE
SYMID alias_by_id(GRAMMAR g,SYMID proper_id)
{
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
return ID_of_SYM(alias);
}

/*:331*//*359:*/
#line 3640 "./marpa.w"

PRIVATE int aim_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:359*//*364:*/
#line 3677 "./marpa.w"

int _marpa_g_AHFA_item_count(struct marpa_g*g){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 3679 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 3680 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:364*//*365:*/
#line 3684 "./marpa.w"

Marpa_Rule_ID _marpa_g_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 3687 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 3688 "./marpa.w"

/*1154:*/
#line 13113 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1154*/
#line 3689 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(item_id))->t_id;
}

/*:365*//*367:*/
#line 3694 "./marpa.w"

int _marpa_g_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 3697 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 3698 "./marpa.w"

/*1154:*/
#line 13113 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1154*/
#line 3699 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:367*//*369:*/
#line 3704 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 3707 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 3708 "./marpa.w"

/*1154:*/
#line 13113 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1154*/
#line 3709 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:369*//*370:*/
#line 3713 "./marpa.w"

int _marpa_g_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 3716 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 3717 "./marpa.w"

/*1154:*/
#line 13113 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1154*/
#line 3718 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:370*//*378:*/
#line 3824 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:378*//*380:*/
#line 3839 "./marpa.w"

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

/*:380*//*392:*/
#line 3994 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*406:*/
#line 4066 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;

/*:406*//*423:*/
#line 4172 "./marpa.w"
Leo_LHS_ID_of_AHFA(ahfa)= -1;
/*:423*/
#line 3997 "./marpa.w"

}

/*:392*//*400:*/
#line 4027 "./marpa.w"

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

/*:400*//*414:*/
#line 4099 "./marpa.w"

PRIVATE int AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:414*//*417:*/
#line 4113 "./marpa.w"

int _marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:417*//*418:*/
#line 4118 "./marpa.w"

int
_marpa_g_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 4121 "./marpa.w"

AHFA state;
/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 4123 "./marpa.w"

/*1155:*/
#line 13118 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1155*/
#line 4124 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:418*//*419:*/
#line 4131 "./marpa.w"

Marpa_AHFA_Item_ID _marpa_g_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
int item_ix){
AHFA state;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 4136 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 4137 "./marpa.w"

/*1155:*/
#line 13118 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1155*/
#line 4138 "./marpa.w"

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

/*:419*//*420:*/
#line 4151 "./marpa.w"

int _marpa_g_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 4155 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 4156 "./marpa.w"

/*1155:*/
#line 13118 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1155*/
#line 4157 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:420*//*424:*/
#line 4173 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 4176 "./marpa.w"

AHFA state;
/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 4178 "./marpa.w"

/*1155:*/
#line 13118 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1155*/
#line 4179 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:424*//*427:*/
#line 4200 "./marpa.w"

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

/*:427*//*445:*/
#line 4692 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,struct avl_table*duplicates)
{
const AHFA state_found= _marpa_avl_insert(duplicates,sought_state);
return state_found;
}

/*:445*//*456:*/
#line 4870 "./marpa.w"

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

/*:456*//*459:*/
#line 4939 "./marpa.w"

PRIVATE_NOT_INLINE AHFA
create_predicted_AHFA_state(
GRAMMAR g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
struct avl_table*duplicates
)
{
AIM*item_list_for_new_state;
AHFA p_new_state;
unsigned int item_list_ix= 0;
unsigned int no_of_items_in_new_state= bv_count(prediction_rule_vector);
if(no_of_items_in_new_state==0)return NULL;
item_list_for_new_state= my_obstack_alloc(&g->t_obs,
no_of_items_in_new_state*sizeof(AIM));
{
unsigned int start,min,max;
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2)
{
unsigned int rule_sort_key;
for(rule_sort_key= min;rule_sort_key<=max;rule_sort_key++)
{

RULE rule= rule_by_sort_key[rule_sort_key];
item_list_for_new_state[item_list_ix++]= 
rule->t_first_aim;
}
}
}
p_new_state= DQUEUE_PUSH((*states_p),AHFA_Object);
AHFA_initialize(p_new_state);
p_new_state->t_items= item_list_for_new_state;
p_new_state->t_item_count= no_of_items_in_new_state;
{AHFA queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state){


(void)DQUEUE_POP((*states_p),AHFA_Object);
my_obstack_free(&g->t_obs,item_list_for_new_state);
return queued_AHFA_state;
}
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE((*states_p),AHFA_Object);
AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_empty_transition= NULL;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
Complete_SYM_Count_of_AHFA(p_new_state)= 0;
/*460:*/
#line 4994 "./marpa.w"

{
unsigned int symbol_count= SYM_Count_of_G(g);
unsigned int item_ix;
unsigned int no_of_postdot_symbols;
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_for_new_state[item_ix];
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

/*:460*/
#line 4990 "./marpa.w"

return p_new_state;
}

/*:459*//*471:*/
#line 5103 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:471*//*472:*/
#line 5109 "./marpa.w"

PRIVATE int completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:472*//*473:*/
#line 5116 "./marpa.w"

PRIVATE
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,int aim_ix)
{
URTRANS transition;
transition= my_obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:473*//*474:*/
#line 5127 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g)
{
int symbol_count= SYM_Count_of_G(g);
int symid= 0;
TRANS*transitions;
transitions= my_malloc(symbol_count*sizeof(transitions[0]));
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:474*//*475:*/
#line 5140 "./marpa.w"

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

/*:475*//*476:*/
#line 5154 "./marpa.w"

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

/*:476*//*478:*/
#line 5169 "./marpa.w"

int _marpa_g_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
int*buffer,
int buffer_size
){

/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5176 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
int symbol_count;
int ix= 0;
const int max_ix= buffer_size/sizeof(*buffer);
const int max_results= max_ix/2;





/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 5189 "./marpa.w"

/*1155:*/
#line 13118 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1155*/
#line 5190 "./marpa.w"

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

/*:478*//*481:*/
#line 5210 "./marpa.w"

AHFAID _marpa_g_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5215 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 5216 "./marpa.w"

/*1155:*/
#line 13118 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1155*/
#line 5217 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:481*//*486:*/
#line 5253 "./marpa.w"

PRIVATE INPUT
input_new(GRAMMAR g)
{
INPUT input= my_slice_new(struct s_input);
my_obstack_init(TOK_Obs_of_I(input));
/*489:*/
#line 5266 "./marpa.w"

input->t_ref_count= 1;

/*:489*//*497:*/
#line 5325 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:497*/
#line 5259 "./marpa.w"

return input;
}

/*:486*//*490:*/
#line 5270 "./marpa.w"

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

/*:490*//*491:*/
#line 5283 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:491*//*492:*/
#line 5296 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
my_obstack_free(TOK_Obs_of_I(input),NULL);
my_slice_free(struct s_input,input);
}

/*:492*//*501:*/
#line 5353 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
int symbol_count_of_g;
/*1147:*/
#line 13079 "./marpa.w"
void*const failure_indicator= NULL;
/*:1147*/
#line 5358 "./marpa.w"

/*1150:*/
#line 13093 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1150*/
#line 5359 "./marpa.w"

r= my_slice_new(struct marpa_r);
symbol_count_of_g= SYM_Count_of_G(g);
/*561:*/
#line 5723 "./marpa.w"
my_obstack_init(&r->t_obs);
/*:561*/
#line 5362 "./marpa.w"

/*504:*/
#line 5369 "./marpa.w"

r->t_ref_count= 1;

/*:504*//*512:*/
#line 5439 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:512*//*514:*/
#line 5448 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:514*//*518:*/
#line 5472 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:518*//*522:*/
#line 5495 "./marpa.w"
r->t_furthest_earleme= 0;
/*:522*//*526:*/
#line 5508 "./marpa.w"
r->t_sym_workarea= NULL;
/*:526*//*530:*/
#line 5519 "./marpa.w"
r->t_workarea2= NULL;
/*:530*//*534:*/
#line 5539 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:534*//*538:*/
#line 5562 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:538*//*553:*/
#line 5663 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:553*//*557:*/
#line 5699 "./marpa.w"
r->t_is_exhausted= 0;
/*:557*//*581:*/
#line 5821 "./marpa.w"

r->t_earley_set_count= 0;

/*:581*//*586:*/
#line 5867 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:586*//*607:*/
#line 6129 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:607*//*637:*/
#line 6511 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:637*//*672:*/
#line 6970 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:672*//*705:*/
#line 7455 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:705*//*711:*/
#line 7512 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:711*//*732:*/
#line 7803 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:732*//*736:*/
#line 7814 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:736*//*740:*/
#line 7825 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:740*//*809:*/
#line 8679 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:809*//*1111:*/
#line 12731 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1111*/
#line 5363 "./marpa.w"

return r;
}

/*:501*//*505:*/
#line 5373 "./marpa.w"

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

/*:505*//*506:*/
#line 5391 "./marpa.w"

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

/*:506*//*507:*/
#line 5405 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5409 "./marpa.w"

/*509:*/
#line 5426 "./marpa.w"
input_unref(input);

/*:509*//*583:*/
#line 5845 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
my_free(EIMs_of_ES(set));
}
}

/*:583*//*712:*/
#line 7514 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:712*//*734:*/
#line 7807 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:734*//*738:*/
#line 7818 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:738*//*741:*/
#line 7826 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:741*//*810:*/
#line 8681 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:810*//*1112:*/
#line 12733 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1112*/
#line 5410 "./marpa.w"

grammar_unref(g);
my_free(r->t_sym_workarea);
my_free(r->t_workarea2);
/*536:*/
#line 5548 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:536*//*540:*/
#line 5565 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:540*/
#line 5414 "./marpa.w"

/*562:*/
#line 5724 "./marpa.w"
my_obstack_free(&r->t_obs,NULL);

/*:562*/
#line 5415 "./marpa.w"

my_slice_free(struct marpa_r,r);
}

/*:507*//*515:*/
#line 5456 "./marpa.w"

unsigned int marpa_r_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:515*//*516:*/
#line 5461 "./marpa.w"

PRIVATE ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:516*//*519:*/
#line 5474 "./marpa.w"

int marpa_r_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:519*//*520:*/
#line 5480 "./marpa.w"

int marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,int threshold)
{
r->t_earley_item_warning_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
return 1;
}

/*:520*//*523:*/
#line 5496 "./marpa.w"

unsigned int marpa_r_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:523*//*542:*/
#line 5580 "./marpa.w"

int marpa_r_terminals_expected(struct marpa_r*r,Marpa_Symbol_ID*buffer)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5583 "./marpa.w"

/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5584 "./marpa.w"

unsigned int min,max,start;
int ix= 0;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 5587 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 5588 "./marpa.w"

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

/*:542*//*554:*/
#line 5669 "./marpa.w"

int marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5672 "./marpa.w"

/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5673 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 5674 "./marpa.w"

return r->t_use_leo_flag;
}
/*:554*//*555:*/
#line 5677 "./marpa.w"

int marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5681 "./marpa.w"

/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5682 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 5683 "./marpa.w"

/*1156:*/
#line 13127 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1156*/
#line 5684 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:555*//*559:*/
#line 5709 "./marpa.w"

int marpa_r_is_exhausted(struct marpa_r*r)
{
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5712 "./marpa.w"

/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5713 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 5714 "./marpa.w"

return R_is_Exhausted(r);
}

/*:559*//*564:*/
#line 5728 "./marpa.w"

Marpa_Error_Code marpa_r_error(Marpa_Recognizer r,const char**p_error_string)
{
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5731 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:564*//*566:*/
#line 5737 "./marpa.w"

int marpa_r_event(Marpa_Recognizer r,Marpa_Event public_event,int ix)
{
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5740 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:566*//*582:*/
#line 5825 "./marpa.w"

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
/*1117:*/
#line 12777 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1117*/
#line 5840 "./marpa.w"

return set;
}

/*:582*//*587:*/
#line 5870 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5873 "./marpa.w"

/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5874 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 5876 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:587*//*588:*/
#line 5884 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5887 "./marpa.w"

/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5888 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 5889 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:588*//*589:*/
#line 5893 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const int es_does_not_exist= -1;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5897 "./marpa.w"

/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5898 "./marpa.w"

ES earley_set;
/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 5900 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 5901 "./marpa.w"

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

/*:589*//*591:*/
#line 5917 "./marpa.w"

int marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 5920 "./marpa.w"

ES earley_set;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 5922 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 5923 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 5924 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_ES_ORDINAL);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:591*//*600:*/
#line 6020 "./marpa.w"

PRIVATE EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1147:*/
#line 13079 "./marpa.w"
void*const failure_indicator= NULL;
/*:1147*/
#line 6024 "./marpa.w"

/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6025 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const int count= ++EIM_Count_of_ES(set);
/*602:*/
#line 6072 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_EIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:602*/
#line 6030 "./marpa.w"

new_item= my_obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:600*//*601:*/
#line 6040 "./marpa.w"

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

/*:601*//*605:*/
#line 6104 "./marpa.w"

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

/*:605*//*612:*/
#line 6169 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const int es_does_not_exist= -1;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6175 "./marpa.w"

/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6176 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6177 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*613:*/
#line 6200 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*639:*/
#line 6550 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:639*/
#line 6203 "./marpa.w"

}

/*:613*/
#line 6184 "./marpa.w"

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

/*:612*//*614:*/
#line 6206 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const int eim_does_not_exist= -1;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6211 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6215 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6216 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*613:*/
#line 6200 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*639:*/
#line 6550 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:639*/
#line 6203 "./marpa.w"

}

/*:613*/
#line 6220 "./marpa.w"

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

/*:614*//*616:*/
#line 6249 "./marpa.w"

PRIVATE void trace_earley_item_clear(struct marpa_r*r)
{
/*615:*/
#line 6246 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:615*/
#line 6252 "./marpa.w"

trace_source_link_clear(r);
}

/*:616*//*617:*/
#line 6256 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6259 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6261 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6262 "./marpa.w"

if(!item){
/*615:*/
#line 6246 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:615*/
#line 6264 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:617*//*624:*/
#line 6337 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6341 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6344 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6345 "./marpa.w"

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

/*:624*//*625:*/
#line 6359 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6363 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6365 "./marpa.w"

EIM base_earley_item;
/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6367 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:625*//*626:*/
#line 6377 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6381 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6384 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6385 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:626*//*630:*/
#line 6419 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6423 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6425 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6426 "./marpa.w"

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


/*:630*//*634:*/
#line 6475 "./marpa.w"

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
/*:634*//*635:*/
#line 6495 "./marpa.w"

PRIVATE PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:635*//*638:*/
#line 6525 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6530 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6534 "./marpa.w"

/*639:*/
#line 6550 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:639*/
#line 6535 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6536 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 6537 "./marpa.w"

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

/*:638*//*640:*/
#line 6560 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6564 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6567 "./marpa.w"

PIM*pim_sym_p;
/*639:*/
#line 6550 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:639*/
#line 6569 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6570 "./marpa.w"

if(!current_earley_set){
/*615:*/
#line 6246 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:615*/
#line 6572 "./marpa.w"

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

/*:640*//*641:*/
#line 6591 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6596 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6600 "./marpa.w"


pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*639:*/
#line 6550 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:639*/
#line 6604 "./marpa.w"

if(!pim_sym_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6609 "./marpa.w"

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

/*:641*//*642:*/
#line 6629 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_postdot_item_symbol(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6632 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6634 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6635 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:642*//*658:*/
#line 6763 "./marpa.w"
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

/*:658*//*663:*/
#line 6839 "./marpa.w"

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

/*:663*//*664:*/
#line 6867 "./marpa.w"

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

/*:664*//*666:*/
#line 6914 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*667:*/
#line 6931 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= new_link;
}

/*:667*/
#line 6922 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*668:*/
#line 6940 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= new_link;
First_Token_Link_of_EIM(item)= NULL;
}

/*:668*/
#line 6924 "./marpa.w"

return;
case SOURCE_IS_LEO:/*669:*/
#line 6949 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= new_link;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= NULL;
}

/*:669*/
#line 6926 "./marpa.w"

return;
}
}

/*:666*//*674:*/
#line 6981 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 6984 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 6988 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 6989 "./marpa.w"

/*688:*/
#line 7208 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:688*/
#line 6990 "./marpa.w"

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

/*:674*//*677:*/
#line 7025 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7028 "./marpa.w"

SRCL full_link;
EIM item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7031 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 7032 "./marpa.w"

/*688:*/
#line 7208 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:688*/
#line 7033 "./marpa.w"

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

/*:677*//*679:*/
#line 7056 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7059 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7063 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 7064 "./marpa.w"

/*688:*/
#line 7208 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:688*/
#line 7065 "./marpa.w"

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

/*:679*//*682:*/
#line 7099 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7102 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7106 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 7107 "./marpa.w"

/*688:*/
#line 7208 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:688*/
#line 7108 "./marpa.w"

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

/*:682*//*684:*/
#line 7132 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_leo_link_trace(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7136 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7140 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 7141 "./marpa.w"

/*688:*/
#line 7208 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:688*/
#line 7142 "./marpa.w"

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

/*:684*//*687:*/
#line 7178 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_leo_link_trace(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7182 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7186 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 7187 "./marpa.w"

/*688:*/
#line 7208 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:688*/
#line 7188 "./marpa.w"

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

/*:687*//*689:*/
#line 7217 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:689*//*690:*/
#line 7233 "./marpa.w"

AHFAID marpa_r_source_predecessor_state(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7236 "./marpa.w"

unsigned int source_type;
SRC source;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7239 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 7240 "./marpa.w"

source_type= r->t_trace_source_type;
/*697:*/
#line 7384 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:697*/
#line 7242 "./marpa.w"

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

/*:690*//*691:*/
#line 7274 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,int*value_p)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7277 "./marpa.w"

unsigned int source_type;
SRC source;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7280 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 7281 "./marpa.w"

source_type= r->t_trace_source_type;
/*697:*/
#line 7384 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:697*/
#line 7283 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:691*//*693:*/
#line 7306 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7309 "./marpa.w"

unsigned int source_type;
SRC source;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7312 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 7313 "./marpa.w"

source_type= r->t_trace_source_type;
/*697:*/
#line 7384 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:697*/
#line 7315 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:693*//*696:*/
#line 7352 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7355 "./marpa.w"

const EARLEME no_predecessor= -1;
unsigned int source_type;
SRC source;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7359 "./marpa.w"

/*1159:*/
#line 13143 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 13145 "./marpa.w"


/*:1159*/
#line 7360 "./marpa.w"

source_type= r->t_trace_source_type;
/*697:*/
#line 7384 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:697*/
#line 7362 "./marpa.w"

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

/*:696*//*706:*/
#line 7460 "./marpa.w"

PRIVATE
TOK token_new(INPUT input,SYMID symbol_id,int value)
{
TOK token;
if(value){
token= my_obstack_alloc(TOK_Obs_of_I(input),sizeof(*token));
SYMID_of_TOK(token)= symbol_id;
Type_of_TOK(token)= VALUED_TOKEN_OR_NODE;
Value_of_TOK(token)= value;
}else{
token= my_obstack_alloc(TOK_Obs_of_I(input),sizeof(token->t_unvalued));
SYMID_of_TOK(token)= symbol_id;
Type_of_TOK(token)= UNVALUED_TOKEN_OR_NODE;
}
return token;
}

/*:706*//*714:*/
#line 7520 "./marpa.w"

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

/*:714*//*716:*/
#line 7564 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:716*//*717:*/
#line 7581 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:717*//*718:*/
#line 7596 "./marpa.w"

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

/*:718*//*719:*/
#line 7615 "./marpa.w"
int marpa_r_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7621 "./marpa.w"

const int symbol_count_of_g= SYM_Count_of_G(g);
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7623 "./marpa.w"

/*1156:*/
#line 13127 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1156*/
#line 7624 "./marpa.w"

Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g)){
/*558:*/
#line 5700 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:558*/
#line 7627 "./marpa.w"

return 1;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
/*531:*/
#line 5520 "./marpa.w"

{
const unsigned int sym_workarea_size= sizeof(void*)*symbol_count_of_g;
/*527:*/
#line 5509 "./marpa.w"

r->t_sym_workarea= my_malloc(sym_workarea_size);

/*:527*/
#line 5523 "./marpa.w"

r->t_workarea2= my_malloc(2u*sym_workarea_size);
}

/*:531*/
#line 7631 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*535:*/
#line 5543 "./marpa.w"
{
r->t_bv_sym= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym2= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym3= bv_create((unsigned int)symbol_count_of_g);
}
/*:535*//*539:*/
#line 5563 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((unsigned int)symbol_count_of_g);
/*:539*/
#line 7633 "./marpa.w"

/*733:*/
#line 7804 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT2(r->t_eim_work_stack,EIM);
/*:733*//*737:*/
#line 7815 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT2(r->t_completion_stack,EIM);
/*:737*/
#line 7634 "./marpa.w"

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

/*:719*//*726:*/
#line 7702 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID token_id,
int value,
int length)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7709 "./marpa.w"

/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7710 "./marpa.w"

const int duplicate_token_indicator= -3;
const int unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1158:*/
#line 13137 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1158*/
#line 7716 "./marpa.w"

/*727:*/
#line 7724 "./marpa.w"
{
const SYM_Const token= SYM_by_ID(token_id);
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

/*:727*/
#line 7717 "./marpa.w"

/*729:*/
#line 7755 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:729*/
#line 7718 "./marpa.w"

/*728:*/
#line 7740 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return failure_indicator;
}
}

/*:728*/
#line 7719 "./marpa.w"

/*730:*/
#line 7778 "./marpa.w"

{
TOK token= token_new(input,token_id,value);
ALT_Object alternative;
if(Furthest_Earleme_of_R(r)<target_earleme)
Furthest_Earleme_of_R(r)= target_earleme;
alternative.t_token= token;
alternative.t_start_earley_set= current_earley_set;
alternative.t_end_earleme= target_earleme;
if(alternative_insert(r,&alternative)<0)
{
/*707:*/
#line 7481 "./marpa.w"
my_obstack_free(TOK_Obs_of_R(r),token);

/*:707*/
#line 7789 "./marpa.w"

return duplicate_token_indicator;
}
}

/*:730*/
#line 7720 "./marpa.w"

return current_earleme;
}

/*:726*//*743:*/
#line 7845 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(struct marpa_r*r)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 7849 "./marpa.w"

/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 7850 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
int count_of_expected_terminals;
/*1158:*/
#line 13137 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1158*/
#line 7855 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*744:*/
#line 7883 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*558:*/
#line 5700 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:558*/
#line 7887 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:744*/
#line 7859 "./marpa.w"

/*746:*/
#line 7908 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:746*/
#line 7860 "./marpa.w"

/*745:*/
#line 7895 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:745*/
#line 7861 "./marpa.w"

/*747:*/
#line 7914 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*748:*/
#line 7921 "./marpa.w"

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

/*:748*/
#line 7918 "./marpa.w"

}

/*:747*/
#line 7862 "./marpa.w"

/*749:*/
#line 7948 "./marpa.w"
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

/*:749*/
#line 7863 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*750:*/
#line 7967 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
int count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
int symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*751:*/
#line 7980 "./marpa.w"

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
/*752:*/
#line 8003 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*753:*/
#line 8019 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:753*/
#line 8012 "./marpa.w"

}
/*754:*/
#line 8026 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:754*/
#line 8014 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:752*/
#line 7991 "./marpa.w"

}
else
{
/*755:*/
#line 8036 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*753:*/
#line 8019 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:753*/
#line 8045 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:755*/
#line 7995 "./marpa.w"

break;


}
}
}

/*:751*/
#line 7976 "./marpa.w"

}
}

/*:750*/
#line 7866 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


/*558:*/
#line 5700 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:558*/
#line 7876 "./marpa.w"

event_new(g,MARPA_EVENT_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:743*//*756:*/
#line 8050 "./marpa.w"

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

/*:756*//*757:*/
#line 8071 "./marpa.w"

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

/*:757*//*763:*/
#line 8115 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,ES current_earley_set)
{
void**const pim_workarea= r->t_sym_workarea;
/*508:*/
#line 5423 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:508*/
#line 8120 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*764:*/
#line 8137 "./marpa.w"
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

/*:764*/
#line 8126 "./marpa.w"

if(r->t_is_using_leo){
/*768:*/
#line 8195 "./marpa.w"

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
/*769:*/
#line 8229 "./marpa.w"
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

/*:769*/
#line 8215 "./marpa.w"

}
}
}
}
}
}

/*:768*/
#line 8128 "./marpa.w"

/*778:*/
#line 8314 "./marpa.w"
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

/*781:*/
#line 8373 "./marpa.w"
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

/*:781*/
#line 8332 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*787:*/
#line 8465 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:787*/
#line 8334 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*789:*/
#line 8486 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:789*/
#line 8340 "./marpa.w"

continue;
}
/*782:*/
#line 8388 "./marpa.w"
{
void**const lim_chain= r->t_workarea2;
int lim_chain_ix;
/*785:*/
#line 8409 "./marpa.w"
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

/*781:*/
#line 8373 "./marpa.w"
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

/*:781*/
#line 8435 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(unsigned int)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:785*/
#line 8391 "./marpa.w"

/*786:*/
#line 8454 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*787:*/
#line 8465 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:787*/
#line 8458 "./marpa.w"

}else{
/*789:*/
#line 8486 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:789*/
#line 8460 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:786*/
#line 8392 "./marpa.w"

}

/*:782*/
#line 8343 "./marpa.w"

}
}
}

/*:778*/
#line 8129 "./marpa.w"

}
/*790:*/
#line 8492 "./marpa.w"
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

/*:790*/
#line 8131 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:763*//*811:*/
#line 8684 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
my_obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:811*//*812:*/
#line 8692 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:812*//*813:*/
#line 8698 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)my_obstack_free(&stack->t_obs,NULL);
stack->t_base= NULL;
}

/*:813*//*814:*/
#line 8705 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= my_obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:814*//*815:*/
#line 8715 "./marpa.w"

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

/*:815*//*816:*/
#line 8731 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:816*//*820:*/
#line 8794 "./marpa.w"

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

/*:820*//*856:*/
#line 9394 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:856*//*857:*/
#line 9406 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:857*//*863:*/
#line 9521 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= my_obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause);
return draft_and_node;
}

/*:863*//*865:*/
#line 9544 "./marpa.w"

PRIVATE
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:865*//*892:*/
#line 9981 "./marpa.w"

int marpa_b_and_node_count(Marpa_Bocage b)
{
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 9984 "./marpa.w"

/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 9985 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 9986 "./marpa.w"

return AND_Count_of_B(b);
}

/*:892*//*894:*/
#line 10007 "./marpa.w"

int marpa_b_and_node_parent(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10011 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10012 "./marpa.w"

/*893:*/
#line 9990 "./marpa.w"
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

/*:893*/
#line 10013 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:894*//*895:*/
#line 10017 "./marpa.w"

int marpa_b_and_node_predecessor(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10021 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10022 "./marpa.w"

/*893:*/
#line 9990 "./marpa.w"
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

/*:893*/
#line 10023 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:895*//*896:*/
#line 10032 "./marpa.w"

int marpa_b_and_node_cause(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10036 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10037 "./marpa.w"

/*893:*/
#line 9990 "./marpa.w"
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

/*:893*/
#line 10038 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:896*//*897:*/
#line 10047 "./marpa.w"

int marpa_b_and_node_symbol(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10051 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10052 "./marpa.w"

/*893:*/
#line 9990 "./marpa.w"
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

/*:893*/
#line 10053 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:897*//*898:*/
#line 10062 "./marpa.w"

Marpa_Symbol_ID marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK token;
AND and_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10068 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10069 "./marpa.w"

/*893:*/
#line 9990 "./marpa.w"
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

/*:893*/
#line 10070 "./marpa.w"

token= and_node_token(and_node);
if(token){
if(value_p)
*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
return-1;
}
/*:898*//*899:*/
#line 10079 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:899*//*913:*/
#line 10143 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Rule_ID rule_id,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1147:*/
#line 13079 "./marpa.w"
void*const failure_indicator= NULL;
/*:1147*/
#line 10148 "./marpa.w"

/*914:*/
#line 10187 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int rule_count_of_g= RULE_Count_of_G(g);
const int symbol_count_of_g= SYM_Count_of_G(g);
BOCAGE b= NULL;
ES end_of_parse_earley_set;
EARLEME end_of_parse_earleme;
RULE completed_start_rule;
EIM start_eim= NULL;
AIM start_aim= NULL;
AEX start_aex= -1;
struct obstack bocage_setup_obs;
int total_earley_items_in_parse;
int or_node_estimate= 0;
const int earley_set_count_of_r= ES_Count_of_R(r);

/*:914*//*917:*/
#line 10211 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:917*/
#line 10149 "./marpa.w"

INPUT input;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10151 "./marpa.w"

/*1157:*/
#line 13132 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1157*/
#line 10152 "./marpa.w"

b= my_slice_new(struct s_bocage);
/*843:*/
#line 9152 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;

/*:843*//*909:*/
#line 10122 "./marpa.w"

b->t_is_obstack_initialized= 1;
my_obstack_init(&OBS_of_B(b));
/*:909*//*933:*/
#line 10409 "./marpa.w"

b->t_ref_count= 1;

/*:933*/
#line 10154 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
r_update_earley_sets(r);
/*918:*/
#line 10214 "./marpa.w"

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
goto B_NEW_RETURN_ERROR;
end_of_parse_earleme= Earleme_of_ES(end_of_parse_earley_set);
}

/*:918*/
#line 10163 "./marpa.w"

if(end_of_parse_earleme==0){
if(!g->t_null_start_rule)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
/*919:*/
#line 10235 "./marpa.w"

{
if(rule_id==-1)
{
completed_start_rule= g->t_proper_start_rule;
if(!completed_start_rule)goto B_NEW_RETURN_ERROR;
}
else
{
/*1153:*/
#line 13108 "./marpa.w"

if(UNLIKELY(!RULEID_of_G_is_Valid(g,rule_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULEID);
return failure_indicator;
}
/*:1153*/
#line 10244 "./marpa.w"

completed_start_rule= RULE_by_ID(g,rule_id);
}
}

/*:919*/
#line 10168 "./marpa.w"

/*925:*/
#line 10339 "./marpa.w"

{
int eim_ix;
EIM*const earley_items= EIMs_of_ES(end_of_parse_earley_set);
const RULEID sought_rule_id= ID_of_RULE(completed_start_rule);
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

/*:925*/
#line 10169 "./marpa.w"

if(!start_eim)goto B_NEW_RETURN_ERROR;
my_obstack_init(&bocage_setup_obs);
/*922:*/
#line 10287 "./marpa.w"

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

/*:922*/
#line 10172 "./marpa.w"

/*818:*/
#line 8753 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*819:*/
#line 8781 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:819*/
#line 8762 "./marpa.w"

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
/*821:*/
#line 8822 "./marpa.w"

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
/*819:*/
#line 8781 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:819*/
#line 8850 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:821*/
#line 8775 "./marpa.w"

/*823:*/
#line 8880 "./marpa.w"

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
/*819:*/
#line 8781 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:819*/
#line 8916 "./marpa.w"

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
/*819:*/
#line 8781 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:819*/
#line 8929 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:823*/
#line 8776 "./marpa.w"

/*824:*/
#line 8939 "./marpa.w"

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
/*819:*/
#line 8781 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:819*/
#line 8972 "./marpa.w"

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
/*819:*/
#line 8781 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:819*/
#line 8988 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:824*/
#line 8777 "./marpa.w"

}
}

/*:818*/
#line 10173 "./marpa.w"

/*845:*/
#line 9169 "./marpa.w"

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
/*1123:*/
#line 12834 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1123*/
#line 9189 "./marpa.w"

/*846:*/
#line 9197 "./marpa.w"

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
/*847:*/
#line 9217 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1123:*/
#line 12834 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1123*/
#line 9227 "./marpa.w"

/*849:*/
#line 9245 "./marpa.w"

{
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const RULE rule= RULE_of_AIM(ahfa_item);
/*850:*/
#line 9274 "./marpa.w"

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


/*:850*/
#line 9255 "./marpa.w"

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

/*:849*/
#line 9228 "./marpa.w"

/*852:*/
#line 9299 "./marpa.w"

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
/*850:*/
#line 9274 "./marpa.w"

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


/*:850*/
#line 9318 "./marpa.w"

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

/*:852*/
#line 9229 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*853:*/
#line 9336 "./marpa.w"
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
/*855:*/
#line 9376 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const int symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*858:*/
#line 9417 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1123:*/
#line 12834 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1123*/
#line 9424 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*850:*/
#line 9274 "./marpa.w"

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


/*:850*/
#line 9428 "./marpa.w"

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

/*:858*/
#line 9386 "./marpa.w"

/*859:*/
#line 9444 "./marpa.w"

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
/*850:*/
#line 9274 "./marpa.w"

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


/*:850*/
#line 9461 "./marpa.w"

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

/*:859*/
#line 9387 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:855*/
#line 9358 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:853*/
#line 9237 "./marpa.w"

}

/*:847*/
#line 9211 "./marpa.w"

}
}
}
}

/*:846*/
#line 9190 "./marpa.w"

/*866:*/
#line 9554 "./marpa.w"

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
/*868:*/
#line 9591 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const int work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*869:*/
#line 9607 "./marpa.w"
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
/*870:*/
#line 9639 "./marpa.w"

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
/*871:*/
#line 9668 "./marpa.w"

{
if(higher_path_leo_item){
/*875:*/
#line 9712 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:875*/
#line 9671 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:871*/
#line 9654 "./marpa.w"

/*873:*/
#line 9682 "./marpa.w"

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

/*:873*/
#line 9655 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*871:*/
#line 9668 "./marpa.w"

{
if(higher_path_leo_item){
/*875:*/
#line 9712 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:875*/
#line 9671 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:871*/
#line 9662 "./marpa.w"

/*876:*/
#line 9722 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const int origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:876*/
#line 9663 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:870*/
#line 9629 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:869*/
#line 9602 "./marpa.w"

/*877:*/
#line 9732 "./marpa.w"

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
/*878:*/
#line 9762 "./marpa.w"

{
OR dand_predecessor;
/*879:*/
#line 9770 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:879*/
#line 9765 "./marpa.w"

draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:878*/
#line 9754 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:877*/
#line 9603 "./marpa.w"

/*880:*/
#line 9781 "./marpa.w"

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
/*881:*/
#line 9821 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*879:*/
#line 9770 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:879*/
#line 9829 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:881*/
#line 9812 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:880*/
#line 9604 "./marpa.w"

}

/*:868*/
#line 9569 "./marpa.w"

}
}
}
}
}

/*:866*/
#line 9191 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= my_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:845*/
#line 10174 "./marpa.w"

/*889:*/
#line 9936 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*882:*/
#line 9835 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
int or_node_id= 0;
psar_init(and_psar,rule_count_of_g+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*884:*/
#line 9867 "./marpa.w"

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

/*:884*/
#line 9845 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:882*/
#line 9939 "./marpa.w"

/*890:*/
#line 9943 "./marpa.w"

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

/*:890*/
#line 9940 "./marpa.w"

}

/*:889*/
#line 10175 "./marpa.w"

/*926:*/
#line 10367 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:926*/
#line 10176 "./marpa.w"
;
my_obstack_free(&bocage_setup_obs,NULL);
return b;
B_NEW_RETURN_ERROR:;
input_unref(input);
if(b){
/*936:*/
#line 10446 "./marpa.w"

/*844:*/
#line 9158 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:844*/
#line 10447 "./marpa.w"
;
/*910:*/
#line 10125 "./marpa.w"

if(b->t_is_obstack_initialized){
my_obstack_free(&OBS_of_B(b),NULL);
b->t_is_obstack_initialized= 0;
}

/*:910*/
#line 10448 "./marpa.w"
;

/*:936*/
#line 10182 "./marpa.w"
;
}
return NULL;
}

/*:913*//*921:*/
#line 10254 "./marpa.w"

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

/*:921*//*928:*/
#line 10390 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10393 "./marpa.w"

return g;
}

/*:928*//*930:*/
#line 10398 "./marpa.w"

Marpa_Or_Node_ID marpa_b_top_or_node(Marpa_Bocage b)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10401 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10402 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10403 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:930*//*934:*/
#line 10413 "./marpa.w"

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

/*:934*//*935:*/
#line 10431 "./marpa.w"

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

/*:935*//*937:*/
#line 10453 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10457 "./marpa.w"

input_unref(input);
if(b)
{
/*936:*/
#line 10446 "./marpa.w"

/*844:*/
#line 9158 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:844*/
#line 10447 "./marpa.w"
;
/*910:*/
#line 10125 "./marpa.w"

if(b->t_is_obstack_initialized){
my_obstack_free(&OBS_of_B(b),NULL);
b->t_is_obstack_initialized= 0;
}

/*:910*/
#line 10448 "./marpa.w"
;

/*:936*/
#line 10461 "./marpa.w"
;
my_slice_free(struct s_bocage,b);
}
}

/*:937*//*940:*/
#line 10486 "./marpa.w"

int marpa_b_or_node_set(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10490 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10491 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10492 "./marpa.w"

/*939:*/
#line 10469 "./marpa.w"
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

/*:939*/
#line 10493 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:940*//*941:*/
#line 10497 "./marpa.w"

int marpa_b_or_node_origin(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10501 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10502 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10503 "./marpa.w"

/*939:*/
#line 10469 "./marpa.w"
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

/*:939*/
#line 10504 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:941*//*942:*/
#line 10508 "./marpa.w"

int marpa_b_or_node_rule(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10512 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10513 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10514 "./marpa.w"

/*939:*/
#line 10469 "./marpa.w"
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

/*:939*/
#line 10515 "./marpa.w"

return ID_of_RULE(RULE_of_OR(or_node));
}

/*:942*//*943:*/
#line 10519 "./marpa.w"

int marpa_b_or_node_position(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10523 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10524 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10525 "./marpa.w"

/*939:*/
#line 10469 "./marpa.w"
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

/*:939*/
#line 10526 "./marpa.w"

return Position_of_OR(or_node);
}

/*:943*//*944:*/
#line 10530 "./marpa.w"

int marpa_b_or_node_first_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10534 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10535 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10536 "./marpa.w"

/*939:*/
#line 10469 "./marpa.w"
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

/*:939*/
#line 10537 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:944*//*945:*/
#line 10541 "./marpa.w"

int marpa_b_or_node_last_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10545 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10546 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10547 "./marpa.w"

/*939:*/
#line 10469 "./marpa.w"
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

/*:939*/
#line 10548 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:945*//*946:*/
#line 10553 "./marpa.w"

int marpa_b_or_node_and_count(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10557 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10558 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10559 "./marpa.w"

/*939:*/
#line 10469 "./marpa.w"
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

/*:939*/
#line 10560 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:946*//*953:*/
#line 10601 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1147:*/
#line 13079 "./marpa.w"
void*const failure_indicator= NULL;
/*:1147*/
#line 10604 "./marpa.w"

/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10605 "./marpa.w"

ORDER o;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10607 "./marpa.w"

o= my_slice_new(struct s_order);
B_of_O(o)= b;
bocage_ref(b);
/*950:*/
#line 10589 "./marpa.w"

{
o->t_and_node_in_use= NULL;
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
}

/*:950*//*956:*/
#line 10617 "./marpa.w"

o->t_ref_count= 1;

/*:956*/
#line 10611 "./marpa.w"

return o;
}

/*:953*//*957:*/
#line 10621 "./marpa.w"

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

/*:957*//*958:*/
#line 10639 "./marpa.w"

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

/*:958*//*959:*/
#line 10653 "./marpa.w"

PRIVATE void order_strip(ORDER o)
{
if(o->t_and_node_in_use)
{
bv_free(o->t_and_node_in_use);
o->t_and_node_in_use= NULL;
}
}
/*:959*//*960:*/
#line 10662 "./marpa.w"

PRIVATE void order_freeze(ORDER o)
{
order_strip(o);
O_is_Frozen(o)= 0;
}
/*:960*//*961:*/
#line 10668 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10671 "./marpa.w"

bocage_unref(b);
order_strip(o);
if(o->t_and_node_orderings){
o->t_and_node_orderings= NULL;
my_obstack_free(&OBS_of_O(o),NULL);
}
my_slice_free(struct s_order,o);
}

/*:961*//*964:*/
#line 10697 "./marpa.w"

Marpa_Grammar marpa_o_g(Marpa_Order o)
{
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10700 "./marpa.w"

return g;
}

/*:964*//*968:*/
#line 10753 "./marpa.w"

int marpa_o_and_order_set(
Marpa_Order o,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
int length)
{
OR or_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10761 "./marpa.w"

/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10762 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10763 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*939:*/
#line 10469 "./marpa.w"
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

/*:939*/
#line 10769 "./marpa.w"

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

/*:968*//*969:*/
#line 10833 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,int ix)
{
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10836 "./marpa.w"

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

/*:969*//*970:*/
#line 10858 "./marpa.w"

Marpa_And_Node_ID marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 10863 "./marpa.w"

/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10864 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10865 "./marpa.w"

/*939:*/
#line 10469 "./marpa.w"
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

/*:939*/
#line 10866 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
return and_order_get(o,or_node,ix);
}

/*:970*//*975:*/
#line 10919 "./marpa.w"

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

/*:975*//*976:*/
#line 10938 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1147:*/
#line 13079 "./marpa.w"
void*const failure_indicator= NULL;
/*:1147*/
#line 10941 "./marpa.w"

TREE t;
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10943 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 10944 "./marpa.w"

t= my_slice_new(struct s_tree);
O_of_T(t)= o;
order_ref(o);
order_freeze(o);
/*977:*/
#line 10953 "./marpa.w"

{
const int and_count= AND_Count_of_B(b);
t->t_parse_count= 0;
t->t_and_node_in_use= bv_create((unsigned int)and_count);
FSTACK_INIT(t->t_nook_stack,NOOK_Object,and_count);
FSTACK_INIT(t->t_nook_worklist,int,and_count);
}

/*:977*//*980:*/
#line 10965 "./marpa.w"

t->t_ref_count= 1;

/*:980*//*987:*/
#line 11044 "./marpa.w"
t->t_pause_counter= 0;
/*:987*/
#line 10949 "./marpa.w"

return t;
}

/*:976*//*981:*/
#line 10969 "./marpa.w"

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

/*:981*//*982:*/
#line 10987 "./marpa.w"

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

/*:982*//*983:*/
#line 11001 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_slice_free(struct s_tree,t);
}

/*:983*//*988:*/
#line 11045 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:988*//*989:*/
#line 11054 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:989*//*991:*/
#line 11076 "./marpa.w"

Marpa_Grammar marpa_t_g(Marpa_Tree t)
{
/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11079 "./marpa.w"

return g;
}

/*:991*//*992:*/
#line 11083 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11086 "./marpa.w"

int is_first_tree_attempt= 0;
/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11088 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11089 "./marpa.w"

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
/*997:*/
#line 11147 "./marpa.w"

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

/*:997*/
#line 11102 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
}else{
/*998:*/
#line 11172 "./marpa.w"
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

/*:998*/
#line 11109 "./marpa.w"

}
/*999:*/
#line 11224 "./marpa.w"
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
/*1001:*/
#line 11285 "./marpa.w"

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

/*:1001*/
#line 11266 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:999*/
#line 11111 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return-1;

}

/*:992*//*994:*/
#line 11127 "./marpa.w"

PRIVATE void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:994*//*995:*/
#line 11133 "./marpa.w"

PRIVATE void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:995*//*996:*/
#line 11141 "./marpa.w"

PRIVATE int tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}

/*:996*//*1000:*/
#line 11272 "./marpa.w"

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

/*:1000*//*1002:*/
#line 11303 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1002*//*1003:*/
#line 11311 "./marpa.w"

int marpa_t_size(Marpa_Tree t)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11314 "./marpa.w"

/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11315 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11316 "./marpa.w"

if(T_is_Exhausted(t)){
return-1;
}
return Size_of_T(t);
}

/*:1003*//*1010:*/
#line 11374 "./marpa.w"

int marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11378 "./marpa.w"

/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11379 "./marpa.w"

/*1009:*/
#line 11356 "./marpa.w"
{
NOOK base_nook;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11358 "./marpa.w"

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

/*:1009*/
#line 11380 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1010*//*1011:*/
#line 11384 "./marpa.w"

int marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11388 "./marpa.w"

/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11389 "./marpa.w"

/*1009:*/
#line 11356 "./marpa.w"
{
NOOK base_nook;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11358 "./marpa.w"

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

/*:1009*/
#line 11390 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1011*//*1012:*/
#line 11394 "./marpa.w"

int marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11398 "./marpa.w"

/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11399 "./marpa.w"

/*1009:*/
#line 11356 "./marpa.w"
{
NOOK base_nook;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11358 "./marpa.w"

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

/*:1009*/
#line 11400 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1012*//*1013:*/
#line 11404 "./marpa.w"

int marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11408 "./marpa.w"

/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11409 "./marpa.w"

/*1009:*/
#line 11356 "./marpa.w"
{
NOOK base_nook;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11358 "./marpa.w"

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

/*:1009*/
#line 11410 "./marpa.w"

return NOOK_Cause_is_Ready(nook);
}

/*:1013*//*1014:*/
#line 11414 "./marpa.w"

int marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11418 "./marpa.w"

/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11419 "./marpa.w"

/*1009:*/
#line 11356 "./marpa.w"
{
NOOK base_nook;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11358 "./marpa.w"

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

/*:1009*/
#line 11420 "./marpa.w"

return NOOK_Predecessor_is_Ready(nook);
}

/*:1014*//*1015:*/
#line 11424 "./marpa.w"

int marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11428 "./marpa.w"

/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11429 "./marpa.w"

/*1009:*/
#line 11356 "./marpa.w"
{
NOOK base_nook;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11358 "./marpa.w"

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

/*:1009*/
#line 11430 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1015*//*1016:*/
#line 11434 "./marpa.w"

int marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11438 "./marpa.w"

/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11439 "./marpa.w"

/*1009:*/
#line 11356 "./marpa.w"
{
NOOK base_nook;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11358 "./marpa.w"

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

/*:1009*/
#line 11440 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1016*//*1025:*/
#line 11566 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1147:*/
#line 13079 "./marpa.w"
void*const failure_indicator= NULL;
/*:1147*/
#line 11569 "./marpa.w"

/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11570 "./marpa.w"
;
/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11571 "./marpa.w"

if(!T_is_Exhausted(t))
{
VALUE v= my_slice_new(struct s_value);
const int minimum_stack_size= (8192/sizeof(int));
const int initial_stack_size= 
MAX(Size_of_TREE(t)/1024,minimum_stack_size);
DSTACK_INIT(VStack_of_V(v),int,initial_stack_size);
/*1026:*/
#line 11594 "./marpa.w"

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

/*:1026*/
#line 11579 "./marpa.w"

Next_Value_Type_of_V(v)= V_GET_DATA;
V_is_Trace(v)= 1;
TOS_of_V(v)= -1;
NOOK_of_V(v)= -1;
/*1029:*/
#line 11611 "./marpa.w"

v->t_ref_count= 1;

/*:1029*/
#line 11584 "./marpa.w"

tree_pause(t);
T_of_V(v)= t;
return v;
}
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return NULL;
}

/*:1025*//*1030:*/
#line 11615 "./marpa.w"

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
marpa_v_unref(Marpa_Value v)
{
value_unref(v);
}

/*:1030*//*1031:*/
#line 11633 "./marpa.w"

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
return value_ref(v);
}

/*:1031*//*1032:*/
#line 11647 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
bv_free(Nulling_Ask_BV_of_V(v));
if(DSTACK_IS_INITIALIZED(v->t_virtual_stack))
{
DSTACK_DESTROY(v->t_virtual_stack);
}
my_slice_free(struct s_value,v);
}

/*:1032*//*1034:*/
#line 11664 "./marpa.w"

Marpa_Grammar marpa_v_g(Marpa_Value v)
{
/*1033:*/
#line 11659 "./marpa.w"

TREE t= T_of_V(v);
/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11661 "./marpa.w"


/*:1033*/
#line 11667 "./marpa.w"

return g;
}

/*:1034*//*1035:*/
#line 11671 "./marpa.w"

int marpa_v_trace(Marpa_Value v,int flag)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11674 "./marpa.w"

/*1033:*/
#line 11659 "./marpa.w"

TREE t= T_of_V(v);
/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11661 "./marpa.w"


/*:1033*/
#line 11675 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11676 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1035*//*1036:*/
#line 11684 "./marpa.w"

Marpa_Nook_ID marpa_v_nook(Marpa_Value v)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11687 "./marpa.w"

/*1033:*/
#line 11659 "./marpa.w"

TREE t= T_of_V(v);
/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11661 "./marpa.w"


/*:1033*/
#line 11688 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11689 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1036*//*1038:*/
#line 11699 "./marpa.w"

int marpa_v_symbol_is_ask_me_when_null(
Marpa_Value v,
Marpa_Symbol_ID symid)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11704 "./marpa.w"

/*1033:*/
#line 11659 "./marpa.w"

TREE t= T_of_V(v);
/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11661 "./marpa.w"


/*:1033*/
#line 11705 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11706 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 11707 "./marpa.w"

return bv_bit_test(Nulling_Ask_BV_of_V(v),symid);
}
/*:1038*//*1039:*/
#line 11720 "./marpa.w"

int marpa_v_symbol_ask_me_when_null_set(
Marpa_Value v,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11725 "./marpa.w"

/*1033:*/
#line 11659 "./marpa.w"

TREE t= T_of_V(v);
/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11661 "./marpa.w"


/*:1033*/
#line 11726 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11727 "./marpa.w"

/*1152:*/
#line 13103 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMID);
return failure_indicator;
}
/*:1152*/
#line 11728 "./marpa.w"

symbol= SYM_by_ID(symid);
if(!SYM_is_Nulling(symbol)){
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

/*:1039*//*1041:*/
#line 11750 "./marpa.w"

Marpa_Value_Type marpa_v_step(Marpa_Value v)
{
/*1148:*/
#line 13082 "./marpa.w"
const int failure_indicator= -2;

/*:1148*/
#line 11753 "./marpa.w"


while(V_is_Active(v)){
Marpa_Value_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case V_GET_DATA:
/*1042:*/
#line 11797 "./marpa.w"

{
AND and_nodes;
/*1033:*/
#line 11659 "./marpa.w"

TREE t= T_of_V(v);
/*974:*/
#line 10915 "./marpa.w"

ORDER o= O_of_T(t);
/*962:*/
#line 10681 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*906:*/
#line 10111 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:906*/
#line 10683 "./marpa.w"


/*:962*/
#line 10917 "./marpa.w"
;

/*:974*/
#line 11661 "./marpa.w"


/*:1033*/
#line 11800 "./marpa.w"

/*1160:*/
#line 13147 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1160*/
#line 11801 "./marpa.w"

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

/*:1042*/
#line 11760 "./marpa.w"

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

/*:1041*//*1045:*/
#line 11914 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(unsigned int bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1045*//*1046:*/
#line 11920 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(unsigned int bits)
{
unsigned int mask= bits&bv_modmask;
if(mask)mask= (unsigned int)~(~0uL<<mask);else mask= (unsigned int)~0uL;
return(mask);
}

/*:1046*//*1048:*/
#line 11934 "./marpa.w"

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

/*:1048*//*1050:*/
#line 11952 "./marpa.w"

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


/*:1050*//*1051:*/
#line 11973 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,BV_BITS(bv));
}

/*:1051*//*1052:*/
#line 11987 "./marpa.w"

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

/*:1052*//*1053:*/
#line 12005 "./marpa.w"

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

/*:1053*//*1054:*/
#line 12019 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1054*//*1055:*/
#line 12030 "./marpa.w"

PRIVATE int bv_bytes(Bit_Vector bv)
{
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}

/*:1055*//*1056:*/
#line 12037 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1056*//*1057:*/
#line 12048 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1057*//*1059:*/
#line 12062 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,unsigned int bit)
{
unsigned int length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1059*//*1061:*/
#line 12070 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1061*//*1062:*/
#line 12077 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1062*//*1063:*/
#line 12084 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,unsigned int bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1063*//*1064:*/
#line 12092 "./marpa.w"

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

/*:1064*//*1065:*/
#line 12105 "./marpa.w"

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

/*:1065*//*1066:*/
#line 12119 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1066*//*1067:*/
#line 12129 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1067*//*1068:*/
#line 12139 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1068*//*1069:*/
#line 12149 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1069*//*1070:*/
#line 12159 "./marpa.w"

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

/*:1070*//*1071:*/
#line 12231 "./marpa.w"

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

/*:1071*//*1076:*/
#line 12279 "./marpa.w"

PRIVATE_NOT_INLINE void
rhs_closure(GRAMMAR g,Bit_Vector bv)
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
RULEID rule_ix;
const SYM symbol= SYM_by_ID(*top_of_stack);
const RULEID rh_rule_count= DSTACK_LENGTH(symbol->t_rhs);
for(rule_ix= 0;rule_ix<rh_rule_count;rule_ix++)
{
Marpa_Rule_ID rule_id= 
*DSTACK_INDEX(symbol->t_rhs,RULEID,rule_ix);
RULE rule= RULE_by_ID(g,rule_id);
unsigned int rule_length;
unsigned int rh_ix;
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
if(bv_bit_test(bv,(unsigned int)lhs_id))
goto NEXT_RULE;
rule_length= Length_of_RULE(rule);
for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test(bv,(unsigned int)RHS_ID_of_RULE(rule,rh_ix)))
goto NEXT_RULE;
}



bv_bit_set(bv,(unsigned int)lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}

/*:1076*//*1080:*/
#line 12357 "./marpa.w"

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

/*:1080*//*1081:*/
#line 12384 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1081*//*1082:*/
#line 12400 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,unsigned int row)
{
Bit_Vector row0= matrix+bv_hiddenwords;
unsigned int words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1082*//*1084:*/
#line 12409 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1084*//*1086:*/
#line 12417 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1086*//*1088:*/
#line 12425 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1088*//*1089:*/
#line 12438 "./marpa.w"

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

/*:1089*//*1098:*/
#line 12596 "./marpa.w"

PRIVATE void*dstack_resize(struct s_dstack*this,size_t type_bytes)
{
this->t_capacity*= 2;
this->t_base= my_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}

/*:1098*//*1113:*/
#line 12735 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1113*//*1114:*/
#line 12742 "./marpa.w"

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
/*:1114*//*1115:*/
#line 12756 "./marpa.w"

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
/*:1115*//*1118:*/
#line 12787 "./marpa.w"

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

/*:1118*//*1120:*/
#line 12805 "./marpa.w"

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

/*:1120*//*1122:*/
#line 12825 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1122*//*1124:*/
#line 12849 "./marpa.w"

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

/*:1124*//*1127:*/
#line 12873 "./marpa.w"

PRIVATE_NOT_INLINE void
default_out_of_memory(void)
{
abort();
}
void(*marpa_out_of_memory)(void)= default_out_of_memory;

/*:1127*//*1135:*/
#line 12968 "./marpa.w"

PRIVATE void*
my_malloc(size_t size)
{
void*newmem;
MY_MALLOC(newmem,size);
return newmem;
}
/*:1135*//*1137:*/
#line 12978 "./marpa.w"

extern void*
_marpa_avl_malloc(struct libavl_allocator*alloc UNUSED,size_t size);
void*
_marpa_avl_malloc(struct libavl_allocator*alloc UNUSED,size_t size)
{
return my_malloc(size);
}
extern void
_marpa_avl_free(struct libavl_allocator*alloc UNUSED,void*p);
void
_marpa_avl_free(struct libavl_allocator*alloc UNUSED,void*p)
{
my_free(p);
}

/*:1137*//*1138:*/
#line 12994 "./marpa.w"

PRIVATE void*
my_malloc0(size_t size)
{
void*newmem;
MY_MALLOC(newmem,size);
memset(newmem,0,size);
return newmem;
}

/*:1138*//*1139:*/
#line 13004 "./marpa.w"

PRIVATE void*
my_realloc(void*mem,size_t size)
{
void*newmem;
if(!mem){
MY_MALLOC(newmem,size);
return newmem;
}
newmem= realloc(mem,size);
if(!newmem)(*marpa_out_of_memory)();
return newmem;
}

/*:1139*//*1163:*/
#line 13191 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(struct marpa_g*g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}

/*:1163*//*1167:*/
#line 13263 "./marpa.w"

PRIVATE_NOT_INLINE
int marpa_default_debug_handler(const char*format,...)
{
va_list args;
va_start(args,format);
vfprintf(stderr,format,args);
va_end(args);
putc('\n',stderr);
return 1;
}

int(*marpa_debug_handler)(const char*,...)
= marpa_default_debug_handler;

/*:1167*//*1170:*/
#line 13285 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
marpa_debug_handler= debug_handler;
}

/*:1170*//*1172:*/
#line 13293 "./marpa.w"

void marpa_debug_level_set(int level)
{
marpa_debug_level= level;
}

/*:1172*/
#line 13510 "./marpa.w"


/*:1187*/
