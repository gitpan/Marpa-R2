/*1200:*/
#line 13361 "./marpa.w"

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

/*:1200*//*1201:*/
#line 13384 "./marpa.w"

#include "config.h"
#include "marpa.h"
#include <stdarg.h> 
#include <stddef.h> 
#include <limits.h> 
#include <stdlib.h> 
#include <stdio.h> 
/*1187:*/
#line 13200 "./marpa.w"

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
       (*marpa_debug_handler) ("%s: assertion failed %s", G_STRLOC, #expr); } while (0);
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
       (*marpa_debug_handler) ("%s: assertion failed %s", G_STRLOC, #expr); } while (0);
#endif

/*:1187*/
#line 13392 "./marpa.w"

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
#define SYM_is_Ask_Me_When_Null(symbol) ((symbol) ->t_is_ask_me_when_null) 
#define SYM_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define SYM_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
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
#define DSTACK_INIT(this,type,initial_size)  \
(((this) .t_count= 0) , \
((this) .t_base= my_new(type,((this) .t_capacity= (initial_size) ) ) ) )  \

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

#line 13393 "./marpa.w"

#include "marpa_obs.h"
#include "avl.h"
/*1205:*/
#line 13457 "./marpa.w"


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


#if defined(__GNUC__) && (__GNUC__ < 3) && !defined(__cplusplus)
#  define STRLOC __FILE__ ":" G_STRINGIFY (__LINE__) ":" __PRETTY_FUNCTION__ "()"
#else
#  define STRLOC __FILE__ ":" G_STRINGIFY (__LINE__)
#endif


#if defined (__GNUC__)
#  define STRFUNC     ((const char*) (__PRETTY_FUNCTION__))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 19901L
#  define STRFUNC     ((const char*) (__func__))
#else
#  define STRFUNC     ((const char*) ("???"))
#endif

#if defined(__GNUC__) && (__GNUC__ >  2) && defined(__OPTIMIZE__)
#define BOOLEAN_EXPR(expr)                   \
 __extension__ ({                               \
   int _g_boolean_var_;                         \
   if (expr)                                    \
      _g_boolean_var_ =  1;                      \
   else                                         \
      _g_boolean_var_ =  0;                      \
   _g_boolean_var_;                             \
})
#define LIKELY(expr) (__builtin_expect (BOOLEAN_EXPR(expr), 1))
#define UNLIKELY(expr) (__builtin_expect (BOOLEAN_EXPR(expr), 0))
#else
#define LIKELY(expr) (expr)
#define UNLIKELY(expr) (expr)
#endif

/*:1205*/
#line 13396 "./marpa.w"

/*94:*/
#line 910 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:94*//*118:*/
#line 1083 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:118*//*364:*/
#line 3516 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:364*//*402:*/
#line 3887 "./marpa.w"
struct s_AHFA_state;
/*:402*//*479:*/
#line 5001 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:479*//*586:*/
#line 5698 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:586*//*610:*/
#line 5912 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:610*//*630:*/
#line 6202 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:630*//*633:*/
#line 6237 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:633*//*714:*/
#line 7355 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:714*//*720:*/
#line 7406 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:720*//*818:*/
#line 8565 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:818*//*846:*/
#line 8993 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:846*//*873:*/
#line 9428 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:873*//*899:*/
#line 9843 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:899*//*914:*/
#line 10019 "./marpa.w"

typedef struct s_bocage*BOCAGE;
/*:914*//*927:*/
#line 10125 "./marpa.w"

struct s_bocage_setup_per_es;
/*:927*//*984:*/
#line 10815 "./marpa.w"

typedef Marpa_Tree TREE;
/*:984*//*1018:*/
#line 11255 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1018*//*1031:*/
#line 11391 "./marpa.w"

typedef struct s_value*VALUE;
/*:1031*//*1109:*/
#line 12495 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1109*//*1112:*/
#line 12529 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1112*//*1119:*/
#line 12594 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1119*//*1121:*/
#line 12609 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1121*/
#line 13397 "./marpa.w"

/*40:*/
#line 609 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:40*//*117:*/
#line 1081 "./marpa.w"

typedef int SYMID;
/*:117*//*173:*/
#line 1503 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:173*//*262:*/
#line 2339 "./marpa.w"
typedef int SYMI;
/*:262*//*419:*/
#line 3978 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef int AHFAID;

/*:419*//*480:*/
#line 5006 "./marpa.w"
typedef int AEX;
/*:480*//*496:*/
#line 5161 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:496*//*511:*/
#line 5253 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:511*//*583:*/
#line 5689 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:583*//*585:*/
#line 5693 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:585*//*661:*/
#line 6619 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:661*//*663:*/
#line 6631 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:663*//*838:*/
#line 8929 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:838*//*872:*/
#line 9416 "./marpa.w"

typedef int WHEID;


/*:872*//*898:*/
#line 9839 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:898*//*1017:*/
#line 11252 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1017*//*1055:*/
#line 11825 "./marpa.w"

typedef unsigned int Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1055*//*1090:*/
#line 12266 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1090*/
#line 13398 "./marpa.w"

/*34:*/
#line 528 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:34*//*852:*/
#line 9056 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:852*//*1056:*/
#line 11832 "./marpa.w"

static const unsigned int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const unsigned int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= 1u;
static const unsigned int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1056*//*1141:*/
#line 12786 "./marpa.w"

extern void(*marpa_out_of_memory)(void);

/*:1141*//*1182:*/
#line 13180 "./marpa.w"

int(*marpa_debug_handler)(const char*,...);
int marpa_debug_level= 0;

/*:1182*/
#line 13399 "./marpa.w"

/*1110:*/
#line 12498 "./marpa.w"

struct s_dstack{int t_count;int t_capacity;void*t_base;};
/*:1110*/
#line 13400 "./marpa.w"

/*39:*/
#line 603 "./marpa.w"
struct marpa_g{
/*109:*/
#line 1032 "./marpa.w"

int t_is_ok;

/*:109*/
#line 604 "./marpa.w"

/*50:*/
#line 685 "./marpa.w"

DSTACK_DECLARE(t_symbols);
/*:50*//*58:*/
#line 725 "./marpa.w"

DSTACK_DECLARE(t_rules);
/*:58*//*91:*/
#line 898 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:91*//*98:*/
#line 929 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:98*//*105:*/
#line 1002 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:105*//*111:*/
#line 1047 "./marpa.w"

const char*t_error_string;
/*:111*//*366:*/
#line 3533 "./marpa.w"

AIM t_AHFA_items;
/*:366*//*420:*/
#line 3982 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:420*/
#line 605 "./marpa.w"

/*44:*/
#line 631 "./marpa.w"
int t_ref_count;
/*:44*//*67:*/
#line 762 "./marpa.w"
Marpa_Symbol_ID t_original_start_symid;
/*:67*//*71:*/
#line 790 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:71*//*75:*/
#line 819 "./marpa.w"
int t_size;
/*:75*//*78:*/
#line 832 "./marpa.w"
int t_max_rule_length;
/*:78*//*112:*/
#line 1049 "./marpa.w"

Marpa_Error_Code t_error;
/*:112*//*263:*/
#line 2341 "./marpa.w"

int t_symbol_instance_count;
/*:263*//*367:*/
#line 3537 "./marpa.w"

unsigned int t_aim_count;
/*:367*//*421:*/
#line 3985 "./marpa.w"
int t_AHFA_len;
/*:421*/
#line 606 "./marpa.w"

/*81:*/
#line 838 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:81*//*84:*/
#line 850 "./marpa.w"
unsigned int t_has_loop:1;
/*:84*//*87:*/
#line 866 "./marpa.w"
unsigned int t_is_lhs_terminal_ok:1;
/*:87*/
#line 607 "./marpa.w"

};
/*:39*//*97:*/
#line 922 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:97*//*119:*/
#line 1096 "./marpa.w"

struct s_symbol{
int t_or_node_type;
SYMID t_symbol_id;
/*124:*/
#line 1138 "./marpa.w"

DSTACK_DECLARE(t_lhs);
/*:124*//*129:*/
#line 1182 "./marpa.w"

DSTACK_DECLARE(t_rhs);
/*:129*//*160:*/
#line 1379 "./marpa.w"

struct s_symbol*t_alias;
/*:160*//*167:*/
#line 1467 "./marpa.w"

RULE t_virtual_lhs_rule;
/*:167*/
#line 1100 "./marpa.w"

/*134:*/
#line 1231 "./marpa.w"
unsigned int t_is_ask_me_when_null:1;
/*:134*//*137:*/
#line 1253 "./marpa.w"
unsigned int t_is_accessible:1;
/*:137*//*140:*/
#line 1275 "./marpa.w"
unsigned int t_is_counted:1;
/*:140*//*143:*/
#line 1289 "./marpa.w"
unsigned int t_is_nullable:1;
/*:143*//*146:*/
#line 1304 "./marpa.w"
unsigned int t_is_nulling:1;
/*:146*//*149:*/
#line 1318 "./marpa.w"
unsigned int t_is_terminal:1;
/*:149*//*153:*/
#line 1343 "./marpa.w"
unsigned int t_is_productive:1;
/*:153*//*156:*/
#line 1358 "./marpa.w"
unsigned int t_is_start:1;
/*:156*//*159:*/
#line 1376 "./marpa.w"

unsigned int t_is_proper_alias:1;
unsigned int t_is_nulling_alias:1;
/*:159*/
#line 1101 "./marpa.w"

};
typedef struct s_symbol SYM_Object;
/*:119*//*172:*/
#line 1493 "./marpa.w"

struct s_rule{
/*260:*/
#line 2334 "./marpa.w"
AIM t_first_aim;
/*:260*/
#line 1495 "./marpa.w"

/*197:*/
#line 1893 "./marpa.w"
int t_rhs_length;
/*:197*//*208:*/
#line 1958 "./marpa.w"
Marpa_Rule_ID t_id;

/*:208*//*237:*/
#line 2166 "./marpa.w"
int t_virtual_start;
/*:237*//*240:*/
#line 2183 "./marpa.w"
int t_virtual_end;
/*:240*//*244:*/
#line 2200 "./marpa.w"
Marpa_Rule_ID t_original;
/*:244*//*248:*/
#line 2219 "./marpa.w"
int t_real_symbol_count;
/*:248*//*251:*/
#line 2245 "./marpa.w"
unsigned int t_is_ask_me:1;
/*:251*//*264:*/
#line 2352 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:264*/
#line 1496 "./marpa.w"

/*210:*/
#line 1969 "./marpa.w"
unsigned int t_is_discard:1;
/*:210*//*219:*/
#line 2050 "./marpa.w"
unsigned int t_is_loop:1;
/*:219*//*223:*/
#line 2069 "./marpa.w"
unsigned int t_is_virtual_loop:1;
/*:223*//*228:*/
#line 2101 "./marpa.w"
unsigned int t_is_used:1;
/*:228*//*231:*/
#line 2130 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:231*//*234:*/
#line 2147 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:234*//*255:*/
#line 2303 "./marpa.w"
unsigned int t_is_semantic_equivalent:1;
/*:255*/
#line 1497 "./marpa.w"

/*198:*/
#line 1896 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:198*/
#line 1498 "./marpa.w"

};
/*:172*//*363:*/
#line 3510 "./marpa.w"

struct s_AHFA_item{
int t_sort_key;
/*372:*/
#line 3559 "./marpa.w"

RULE t_rule;

/*:372*/
#line 3513 "./marpa.w"

/*373:*/
#line 3565 "./marpa.w"

int t_position;

/*:373*//*374:*/
#line 3572 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:374*//*375:*/
#line 3581 "./marpa.w"

int t_leading_nulls;

/*:375*/
#line 3514 "./marpa.w"

};
/*:363*//*403:*/
#line 3888 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*407:*/
#line 3915 "./marpa.w"

SYMID*t_complete_symbols;

/*:407*//*409:*/
#line 3922 "./marpa.w"

AIM*t_items;
/*:409*//*427:*/
#line 4019 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:427*//*482:*/
#line 5018 "./marpa.w"

TRANS*t_transitions;
/*:482*/
#line 3895 "./marpa.w"

/*406:*/
#line 3913 "./marpa.w"

unsigned int t_complete_symbol_count;
/*:406*//*410:*/
#line 3925 "./marpa.w"

int t_item_count;
/*:410*//*428:*/
#line 4020 "./marpa.w"
unsigned int t_postdot_sym_count;

/*:428*//*434:*/
#line 4081 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:434*/
#line 3896 "./marpa.w"

/*414:*/
#line 3966 "./marpa.w"

unsigned int t_is_predict:1;

/*:414*//*417:*/
#line 3974 "./marpa.w"

unsigned int t_is_potential_leo_base:1;
/*:417*/
#line 3897 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:403*//*481:*/
#line 5007 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
int t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:481*//*497:*/
#line 5164 "./marpa.w"

struct s_input{
/*506:*/
#line 5235 "./marpa.w"

struct obstack t_token_obs;

/*:506*//*508:*/
#line 5240 "./marpa.w"

GRAMMAR t_grammar;
/*:508*/
#line 5166 "./marpa.w"

/*500:*/
#line 5181 "./marpa.w"

int t_ref_count;
/*:500*/
#line 5167 "./marpa.w"

};

/*:497*//*587:*/
#line 5704 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:587*//*588:*/
#line 5709 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
int t_postdot_sym_count;
/*589:*/
#line 5721 "./marpa.w"

int t_eim_count;
/*:589*//*591:*/
#line 5735 "./marpa.w"

int t_ordinal;
/*:591*/
#line 5713 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*590:*/
#line 5724 "./marpa.w"

EIM*t_earley_items;

/*:590*//*1129:*/
#line 12679 "./marpa.w"

PSL t_dot_psl;
/*:1129*/
#line 5716 "./marpa.w"

};

/*:588*//*631:*/
#line 6206 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:631*//*634:*/
#line 6240 "./marpa.w"

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

/*:634*//*644:*/
#line 6379 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:644*//*715:*/
#line 7363 "./marpa.w"

struct s_token_unvalued{
int t_type;
SYMID t_symbol_id;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:715*//*721:*/
#line 7416 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:721*//*819:*/
#line 8582 "./marpa.w"

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
/*:819*//*849:*/
#line 9031 "./marpa.w"

struct s_draft_or_node
{
/*848:*/
#line 9025 "./marpa.w"

int t_position;
int t_end_set_ordinal;
RULE t_rule;
int t_start_set_ordinal;
ORID t_id;
/*:848*/
#line 9034 "./marpa.w"

DAND t_draft_and_node;
};
/*:849*//*850:*/
#line 9037 "./marpa.w"

struct s_final_or_node
{
/*848:*/
#line 9025 "./marpa.w"

int t_position;
int t_end_set_ordinal;
RULE t_rule;
int t_start_set_ordinal;
ORID t_id;
/*:848*/
#line 9040 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:850*//*851:*/
#line 9048 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:851*//*874:*/
#line 9435 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:874*//*900:*/
#line 9850 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:900*//*928:*/
#line 10127 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:928*//*961:*/
#line 10506 "./marpa.w"

struct s_order{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
/*964:*/
#line 10524 "./marpa.w"

BOCAGE t_bocage;

/*:964*/
#line 10511 "./marpa.w"

/*967:*/
#line 10542 "./marpa.w"
int t_ref_count;
/*:967*/
#line 10512 "./marpa.w"

unsigned int t_is_frozen:1;
};
/*:961*//*985:*/
#line 10829 "./marpa.w"

/*1019:*/
#line 11266 "./marpa.w"

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

/*:1019*/
#line 10830 "./marpa.w"

/*1033:*/
#line 11423 "./marpa.w"

struct s_value{
struct marpa_value public;
DSTACK_DECLARE(t_virtual_stack);
NOOKID t_nook;
Marpa_Tree t_tree;
/*1040:*/
#line 11535 "./marpa.w"

int t_ref_count;
/*:1040*/
#line 11429 "./marpa.w"

Bit_Vector t_nulling_ask_bv;
int t_token_type;
int t_next_value_type;
unsigned int t_trace:1;
};

/*:1033*/
#line 10831 "./marpa.w"

struct s_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_and_node_in_use;
Marpa_Order t_order;
/*991:*/
#line 10889 "./marpa.w"

int t_ref_count;
/*:991*//*998:*/
#line 10969 "./marpa.w"
int t_pause_counter;
/*:998*/
#line 10837 "./marpa.w"

int t_parse_count;
};

/*:985*//*1113:*/
#line 12532 "./marpa.w"

struct s_dqueue{int t_current;struct s_dstack t_stack;};

/*:1113*//*1120:*/
#line 12600 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1120*//*1122:*/
#line 12625 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1122*/
#line 13401 "./marpa.w"

/*512:*/
#line 5256 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*525:*/
#line 5364 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:525*//*537:*/
#line 5427 "./marpa.w"
void**t_sym_workarea;
/*:537*//*541:*/
#line 5438 "./marpa.w"
void**t_workarea2;
/*:541*//*545:*/
#line 5455 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:545*//*549:*/
#line 5481 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:549*//*572:*/
#line 5642 "./marpa.w"
struct obstack t_obs;
/*:572*//*597:*/
#line 5785 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:597*//*618:*/
#line 6047 "./marpa.w"

EIM t_trace_earley_item;
/*:618*//*648:*/
#line 6428 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:648*//*682:*/
#line 6885 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:682*//*722:*/
#line 7424 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:722*//*743:*/
#line 7722 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:743*//*747:*/
#line 7734 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:747*//*751:*/
#line 7746 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:751*//*820:*/
#line 8595 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:820*//*1123:*/
#line 12633 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1123*/
#line 5259 "./marpa.w"

/*515:*/
#line 5288 "./marpa.w"
int t_ref_count;
/*:515*//*529:*/
#line 5391 "./marpa.w"
int t_earley_item_warning_threshold;
/*:529*//*533:*/
#line 5414 "./marpa.w"
EARLEME t_furthest_earleme;
/*:533*//*592:*/
#line 5739 "./marpa.w"

int t_earley_set_count;
/*:592*/
#line 5260 "./marpa.w"

/*522:*/
#line 5356 "./marpa.w"

unsigned int t_input_phase:2;
/*:522*//*564:*/
#line 5580 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:564*//*568:*/
#line 5618 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:568*//*683:*/
#line 6888 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:683*/
#line 5261 "./marpa.w"

};

/*:512*/
#line 13402 "./marpa.w"

/*662:*/
#line 6622 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:662*//*664:*/
#line 6634 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:664*//*665:*/
#line 6640 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:665*//*666:*/
#line 6647 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:666*/
#line 13403 "./marpa.w"

/*611:*/
#line 5919 "./marpa.w"

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
/*616:*/
#line 6019 "./marpa.w"

unsigned int t_source_type:3;

/*:616*/
#line 5930 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:611*/
#line 13404 "./marpa.w"

/*915:*/
#line 10021 "./marpa.w"

struct s_bocage{
/*853:*/
#line 9066 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:853*//*917:*/
#line 10030 "./marpa.w"

INPUT t_input;

/*:917*//*919:*/
#line 10040 "./marpa.w"

struct obstack t_obs;
/*:919*/
#line 10023 "./marpa.w"

/*854:*/
#line 9069 "./marpa.w"

int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:854*//*944:*/
#line 10334 "./marpa.w"
int t_ref_count;
/*:944*/
#line 10024 "./marpa.w"

/*920:*/
#line 10042 "./marpa.w"

unsigned int is_obstack_initialized:1;
/*:920*/
#line 10025 "./marpa.w"

};

/*:915*/
#line 13405 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1188:*/
#line 13237 "./marpa.w"

static char*eim_tag_safe(char*buffer,EIM eim);
static char*eim_tag(EIM eim);
/*:1188*//*1190:*/
#line 13262 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim);
static char*lim_tag(LIM lim);
/*:1190*//*1192:*/
#line 13288 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or);
static const char*or_tag(OR or);
/*:1192*//*1194:*/
#line 13320 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AIM aim);
static const char*aim_tag(AIM aim);
/*:1194*/
#line 13408 "./marpa.w"

/*1189:*/
#line 13241 "./marpa.w"

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

/*:1189*//*1191:*/
#line 13267 "./marpa.w"

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

/*:1191*//*1193:*/
#line 13292 "./marpa.w"

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

/*:1193*//*1195:*/
#line 13323 "./marpa.w"

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

/*:1195*/
#line 13409 "./marpa.w"

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
#line 727 "./marpa.w"

DSTACK_INIT(g->t_rules,RULE,256);
/*:59*//*68:*/
#line 763 "./marpa.w"

g->t_original_start_symid= -1;
/*:68*//*72:*/
#line 793 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;
/*:72*//*76:*/
#line 820 "./marpa.w"

Size_of_G(g)= 0;

/*:76*//*79:*/
#line 833 "./marpa.w"

g->t_max_rule_length= 0;

/*:79*//*82:*/
#line 839 "./marpa.w"

g->t_is_precomputed= 0;
/*:82*//*85:*/
#line 851 "./marpa.w"

g->t_has_loop= 0;
/*:85*//*88:*/
#line 867 "./marpa.w"

g->t_is_lhs_terminal_ok= 1;
/*:88*//*92:*/
#line 899 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:92*//*99:*/
#line 937 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:99*//*106:*/
#line 1005 "./marpa.w"

obstack_init(&g->t_obs);
obstack_init(&g->t_obs_tricky);
/*:106*//*113:*/
#line 1051 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:113*//*369:*/
#line 3542 "./marpa.w"

g->t_AHFA_items= NULL;
/*:369*//*422:*/
#line 3986 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:422*/
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
#line 729 "./marpa.w"

DSTACK_DESTROY(g->t_rules);

/*:60*//*93:*/
#line 900 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:93*//*100:*/
#line 939 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:100*//*107:*/
#line 1008 "./marpa.w"

obstack_free(&g->t_obs,NULL);
obstack_free(&g->t_obs_tricky,NULL);

/*:107*//*370:*/
#line 3544 "./marpa.w"

my_free(g->t_AHFA_items);

/*:370*//*423:*/
#line 3990 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*424:*/
#line 4000 "./marpa.w"
{
my_free(TRANSs_of_AHFA(ahfa_state));
}

/*:424*/
#line 3994 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:423*/
#line 676 "./marpa.w"

my_slice_free(struct marpa_g,g);
}

/*:49*//*54:*/
#line 696 "./marpa.w"

int marpa_g_symbol_count(struct marpa_g*g){
return SYM_Count_of_G(g);
}

/*:54*//*56:*/
#line 706 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,SYM symbol)
{
const SYMID new_id= DSTACK_LENGTH((g)->t_symbols);
*DSTACK_PUSH((g)->t_symbols,SYM)= symbol;
symbol->t_symbol_id= new_id;
}

/*:56*//*57:*/
#line 716 "./marpa.w"

PRIVATE int symbol_is_valid(GRAMMAR g,SYMID symid)
{
return symid>=0&&symid<SYM_Count_of_G(g);
}

/*:57*//*63:*/
#line 734 "./marpa.w"

int marpa_g_rule_count(struct marpa_g*g){
return RULE_Count_of_G(g);
}

/*:63*//*65:*/
#line 744 "./marpa.w"

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
#line 765 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 768 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 769 "./marpa.w"

return g->t_original_start_symid;
}
/*:69*//*70:*/
#line 774 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 777 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 778 "./marpa.w"

/*1162:*/
#line 12984 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1162*/
#line 779 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 780 "./marpa.w"

return g->t_original_start_symid= symid;
}

/*:70*//*83:*/
#line 841 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 844 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 845 "./marpa.w"

return G_is_Precomputed(g);
}

/*:83*//*86:*/
#line 853 "./marpa.w"

int marpa_g_has_loop(Marpa_Grammar g)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 856 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 857 "./marpa.w"

return g->t_has_loop;
}

/*:86*//*89:*/
#line 870 "./marpa.w"

int marpa_g_is_lhs_terminal_ok(Marpa_Grammar g)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 873 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 874 "./marpa.w"

return g->t_is_lhs_terminal_ok;
}
/*:89*//*90:*/
#line 879 "./marpa.w"

int marpa_g_is_lhs_terminal_ok_set(
struct marpa_g*g,int value)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 883 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 884 "./marpa.w"

/*1162:*/
#line 12984 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1162*/
#line 885 "./marpa.w"

return g->t_is_lhs_terminal_ok= value?1:0;
}

/*:90*//*102:*/
#line 949 "./marpa.w"

PRIVATE
void event_new(struct marpa_g*g,int type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:102*//*103:*/
#line 958 "./marpa.w"

PRIVATE
void int_event_new(struct marpa_g*g,int type,int value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:103*//*104:*/
#line 968 "./marpa.w"

int
marpa_g_event(Marpa_Grammar g,Marpa_Event public_event,
int ix)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 973 "./marpa.w"

const int index_out_of_bounds= -1;
DSTACK events= &g->t_events;
GEV internal_event;
int type;

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

/*:104*//*115:*/
#line 1062 "./marpa.w"

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

/*:115*//*121:*/
#line 1109 "./marpa.w"

PRIVATE SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= my_malloc(sizeof(SYM_Object));
/*120:*/
#line 1106 "./marpa.w"

symbol->t_or_node_type= UNVALUED_TOKEN_OR_NODE;

/*:120*//*125:*/
#line 1140 "./marpa.w"

DSTACK_INIT(symbol->t_lhs,RULEID,1);
/*:125*//*130:*/
#line 1184 "./marpa.w"

DSTACK_INIT(symbol->t_rhs,RULEID,1);
/*:130*//*135:*/
#line 1232 "./marpa.w"

SYM_is_Ask_Me_When_Null(symbol)= 0;
/*:135*//*138:*/
#line 1254 "./marpa.w"

symbol->t_is_accessible= 0;
/*:138*//*141:*/
#line 1276 "./marpa.w"

symbol->t_is_counted= 0;
/*:141*//*144:*/
#line 1290 "./marpa.w"

symbol->t_is_nullable= 0;
/*:144*//*147:*/
#line 1305 "./marpa.w"

symbol->t_is_nulling= 0;
/*:147*//*150:*/
#line 1319 "./marpa.w"

symbol->t_is_terminal= 0;
/*:150*//*154:*/
#line 1344 "./marpa.w"

symbol->t_is_productive= 0;
/*:154*//*157:*/
#line 1359 "./marpa.w"
symbol->t_is_start= 0;
/*:157*//*161:*/
#line 1381 "./marpa.w"

symbol->t_is_proper_alias= 0;
symbol->t_is_nulling_alias= 0;
symbol->t_alias= NULL;

/*:161*//*168:*/
#line 1469 "./marpa.w"

symbol->t_virtual_lhs_rule= NULL;

/*:168*/
#line 1114 "./marpa.w"

symbol_add(g,symbol);
return symbol;
}

/*:121*//*122:*/
#line 1119 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(struct marpa_g*g)
{
SYMID id= ID_of_SYM(symbol_new(g));
return id;
}

/*:122*//*123:*/
#line 1127 "./marpa.w"

PRIVATE void symbol_free(SYM symbol)
{
/*126:*/
#line 1142 "./marpa.w"

DSTACK_DESTROY(symbol->t_lhs);

/*:126*//*131:*/
#line 1186 "./marpa.w"

DSTACK_DESTROY(symbol->t_rhs);

/*:131*/
#line 1130 "./marpa.w"
my_free(symbol);
}

/*:123*//*127:*/
#line 1145 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_lhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1148 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1149 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1150 "./marpa.w"

return DSTACK_LENGTH(SYM_by_ID(symid)->t_lhs);
}
Marpa_Rule_ID marpa_g_symbol_lhs(struct marpa_g*g,Marpa_Symbol_ID symid,int ix)
{
SYM symbol;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1156 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1157 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1158 "./marpa.w"

symbol= SYM_by_ID(symid);
if(ix<0){
MARPA_DEV_ERROR("symbol lhs index negative");
return failure_indicator;
}
if(ix>=DSTACK_LENGTH(symbol->t_lhs)){
MARPA_DEV_ERROR("symbol lhs index out of bounds");
return-1;
}
return*DSTACK_INDEX(symbol->t_lhs,RULEID,ix);
}

/*:127*//*128:*/
#line 1171 "./marpa.w"

PRIVATE
void symbol_lhs_add(SYM symbol,RULEID rule_id)
{
*DSTACK_PUSH(symbol->t_lhs,RULEID)= rule_id;
}

/*:128*//*132:*/
#line 1189 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_rhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1192 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1193 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1194 "./marpa.w"

return DSTACK_LENGTH(SYM_by_ID(symid)->t_rhs);
}
Marpa_Rule_ID marpa_g_symbol_rhs(struct marpa_g*g,Marpa_Symbol_ID symid,int ix)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1199 "./marpa.w"

SYM symbol;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1201 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1202 "./marpa.w"

if(ix<0){
MARPA_DEV_ERROR("symbol rhs index negative");
return failure_indicator;
}
symbol= SYM_by_ID(symid);
if(ix>=DSTACK_LENGTH(symbol->t_rhs)){
MARPA_DEV_ERROR("symbol rhs index out of bounds");
return-1;
}
return*DSTACK_INDEX(symbol->t_rhs,RULEID,ix);
}

/*:132*//*133:*/
#line 1215 "./marpa.w"

PRIVATE
void symbol_rhs_add(SYM symbol,RULEID rule_id)
{
*DSTACK_PUSH(symbol->t_rhs,RULEID)= rule_id;
}

/*:133*//*136:*/
#line 1234 "./marpa.w"

int marpa_g_symbol_is_ask_me_when_null(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1239 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1240 "./marpa.w"

return SYM_is_Ask_Me_When_Null(SYM_by_ID(symid));
}
int marpa_g_symbol_ask_me_when_null_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1247 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1248 "./marpa.w"

symbol= SYM_by_ID(symid);
return SYM_is_Ask_Me_When_Null(symbol)= value?1:0;
}
/*:136*//*139:*/
#line 1264 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1267 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1268 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 1269 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1270 "./marpa.w"

return SYM_by_ID(symid)->t_is_accessible;
}

/*:139*//*142:*/
#line 1278 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1282 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1283 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1284 "./marpa.w"

return SYM_by_ID(symid)->t_is_counted;
}

/*:142*//*145:*/
#line 1292 "./marpa.w"

int marpa_g_symbol_is_nullable(GRAMMAR g,SYMID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1295 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1296 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 1297 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1298 "./marpa.w"

return SYM_by_ID(symid)->t_is_nullable;
}

/*:145*//*148:*/
#line 1307 "./marpa.w"

int marpa_g_symbol_is_nulling(GRAMMAR g,SYMID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1310 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1311 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 1312 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1313 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));
}

/*:148*//*151:*/
#line 1323 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1327 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1328 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1329 "./marpa.w"

return SYMID_is_Terminal(symid);
}
/*:151*//*152:*/
#line 1332 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1336 "./marpa.w"

/*1162:*/
#line 12984 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1162*/
#line 1337 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1338 "./marpa.w"

return SYMID_is_Terminal(symid)= value;
}

/*:152*//*155:*/
#line 1346 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1351 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 1352 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1353 "./marpa.w"

return SYM_by_ID(symid)->t_is_productive;
}

/*:155*//*158:*/
#line 1360 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1363 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 1364 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1365 "./marpa.w"

return SYM_by_ID(symid)->t_is_start;
}

/*:158*//*162:*/
#line 1390 "./marpa.w"

PRIVATE
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1398 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1399 "./marpa.w"

symbol= SYM_by_ID(symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}

/*:162*//*163:*/
#line 1409 "./marpa.w"

PRIVATE
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1417 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1418 "./marpa.w"

symbol= SYM_by_ID(symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
MARPA_DEV_ERROR("no alias");
return-1;
}
return ID_of_SYM(alias);
}

/*:163*//*165:*/
#line 1434 "./marpa.w"

PRIVATE
SYM symbol_alias_create(GRAMMAR g,SYM symbol)
{
SYM alias= symbol_new(g);
symbol->t_is_proper_alias= 1;
SYM_is_Nulling(symbol)= 0;
symbol->t_is_nullable= 0;
symbol->t_alias= alias;
alias->t_is_nulling_alias= 1;
SYM_is_Nulling(alias)= 1;
SYM_is_Ask_Me_When_Null(alias)
= SYM_is_Ask_Me_When_Null(symbol);
alias->t_is_nullable= 1;
alias->t_is_productive= 1;
alias->t_is_accessible= symbol->t_is_accessible;
alias->t_alias= symbol;
return alias;
}

/*:165*//*170:*/
#line 1477 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_virtual_lhs_rule(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
RULE virtual_lhs_rule;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1482 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1483 "./marpa.w"

symbol= SYM_by_ID(symid);
virtual_lhs_rule= symbol->t_virtual_lhs_rule;
return virtual_lhs_rule==NULL?-1:ID_of_RULE(virtual_lhs_rule);
}

/*:170*//*176:*/
#line 1515 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,int length)
{
/*1160:*/
#line 12976 "./marpa.w"
void*const failure_indicator= NULL;
/*:1160*/
#line 1520 "./marpa.w"

RULE rule;
const int rule_sizeof= offsetof(struct s_rule,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
/*199:*/
#line 1898 "./marpa.w"

{
SYMID symid= lhs;
/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1901 "./marpa.w"

}
{int rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 1906 "./marpa.w"

}
}

/*:199*/
#line 1524 "./marpa.w"

rule= obstack_alloc(&g->t_obs,rule_sizeof);
/*200:*/
#line 1910 "./marpa.w"

Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
{int i;for(i= 0;i<length;i++){
rule->t_symbols[i+1]= rhs[i];}}
/*:200*/
#line 1526 "./marpa.w"

/*211:*/
#line 1970 "./marpa.w"

rule->t_is_discard= 0;
/*:211*//*220:*/
#line 2051 "./marpa.w"

rule->t_is_loop= 0;
/*:220*//*224:*/
#line 2070 "./marpa.w"

rule->t_is_virtual_loop= 0;
/*:224*//*229:*/
#line 2102 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:229*//*232:*/
#line 2131 "./marpa.w"

RULE_has_Virtual_LHS(rule)= 0;
/*:232*//*235:*/
#line 2148 "./marpa.w"

RULE_has_Virtual_RHS(rule)= 0;
/*:235*//*238:*/
#line 2167 "./marpa.w"
rule->t_virtual_start= -1;
/*:238*//*241:*/
#line 2184 "./marpa.w"
rule->t_virtual_end= -1;
/*:241*//*245:*/
#line 2201 "./marpa.w"
rule->t_original= -1;
/*:245*//*249:*/
#line 2220 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:249*//*252:*/
#line 2246 "./marpa.w"

RULE_is_Ask_Me(rule)= 0;
/*:252*//*256:*/
#line 2304 "./marpa.w"

rule->t_is_semantic_equivalent= 0;
/*:256*//*261:*/
#line 2335 "./marpa.w"

rule->t_first_aim= NULL;

/*:261*//*265:*/
#line 2355 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:265*/
#line 1527 "./marpa.w"

rule_add(g,rule);
/*192:*/
#line 1776 "./marpa.w"

symbol_lhs_add(SYM_by_ID(rule->t_symbols[0]),rule->t_id);
if(Length_of_RULE(rule)> 0){
int rh_list_ix;
const unsigned int alloc_size= Length_of_RULE(rule)*sizeof(SYMID);
Marpa_Symbol_ID*rh_symbol_list= my_slice_alloc(alloc_size);
int rh_symbol_list_length= 1;
/*196:*/
#line 1843 "./marpa.w"

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

/*:196*/
#line 1784 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(rh_symbol_list[rh_list_ix]),
rule->t_id);
}
my_slice_free1(alloc_size,rh_symbol_list);
}

/*:192*/
#line 1529 "./marpa.w"

return rule;
}

/*:176*//*177:*/
#line 1533 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,int length)
{
Marpa_Rule_ID rule_id;
RULE rule;
if(length> MAX_RHS_LENGTH){
MARPA_DEV_ERROR("rhs too long");
return-1;
}
if(is_rule_duplicate(g,lhs,rhs,length)==1){
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
return-1;
}
rule= rule_start(g,lhs,rhs,length);
if(!rule){return-1;}
rule_id= rule->t_id;
return rule_id;
}

/*:177*//*178:*/
#line 1553 "./marpa.w"

int marpa_g_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id;
SYM internal_lhs;
SYMID internal_lhs_id,*temp_rhs;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1562 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1563 "./marpa.w"

/*1162:*/
#line 12984 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1162*/
#line 1564 "./marpa.w"

if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==1)
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
return failure_indicator;
}
G_EVENTS_CLEAR(g);

/*179:*/
#line 1590 "./marpa.w"

{
original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule)
{
MARPA_DEV_ERROR("internal_error");
return failure_indicator;
}
RULE_is_Used(original_rule)= 0;
original_rule_id= original_rule->t_id;
original_rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION)
&&separator_id>=0;
int_event_new(g,MARPA_EVENT_NEW_RULE,original_rule_id);
}

/*:179*/
#line 1572 "./marpa.w"

/*180:*/
#line 1605 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
MARPA_DEV_ERROR("bad separator");
return failure_indicator;
}

/*:180*/
#line 1573 "./marpa.w"

/*181:*/
#line 1611 "./marpa.w"

SYM_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(separator_id)->t_is_counted= 1;}
/*:181*/
#line 1574 "./marpa.w"

if(min==0){/*182:*/
#line 1614 "./marpa.w"

{
RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1168:*/
#line 13014 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1168*/
#line 1617 "./marpa.w"
}
rule->t_is_semantic_equivalent= 1;
rule->t_original= original_rule_id;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}
/*:182*/
#line 1575 "./marpa.w"
}
min= 1;
/*183:*/
#line 1622 "./marpa.w"

{
internal_lhs= symbol_new(g);
internal_lhs_id= ID_of_SYM(internal_lhs);
int_event_new(g,MARPA_EVENT_NEW_SYMBOL,internal_lhs_id);
}

/*:183*/
#line 1577 "./marpa.w"

/*184:*/
#line 1640 "./marpa.w"

temp_rhs= my_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:184*/
#line 1578 "./marpa.w"

/*186:*/
#line 1643 "./marpa.w"

{
RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1168:*/
#line 13014 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1168*/
#line 1648 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= 1;

RULE_has_Virtual_RHS(rule)= 1;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}

/*:186*/
#line 1579 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*187:*/
#line 1657 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1168:*/
#line 13014 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1168*/
#line 1662 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= 1;
RULE_has_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= 1;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}
/*:187*/
#line 1581 "./marpa.w"

}
/*188:*/
#line 1672 "./marpa.w"

{RULE rule;
int rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1168:*/
#line 13014 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1168*/
#line 1682 "./marpa.w"
}
RULE_has_Virtual_LHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}
/*:188*/
#line 1583 "./marpa.w"

/*189:*/
#line 1687 "./marpa.w"

{RULE rule;
int rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1168:*/
#line 13014 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1168*/
#line 1694 "./marpa.w"
}
RULE_has_Virtual_LHS(rule)= 1;
RULE_has_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix-1;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}

/*:189*/
#line 1584 "./marpa.w"

/*185:*/
#line 1642 "./marpa.w"
my_free(temp_rhs);
/*:185*/
#line 1585 "./marpa.w"

return G_EVENT_COUNT(g);
}

/*:178*//*191:*/
#line 1743 "./marpa.w"

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

/*:191*//*201:*/
#line 1915 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:201*//*202:*/
#line 1919 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1921 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 1922 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));}
/*:202*//*203:*/
#line 1924 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:203*//*204:*/
#line 1928 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,int ix){
RULE rule;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1931 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 1932 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:204*//*205:*/
#line 1937 "./marpa.w"

PRIVATE size_t rule_length_get(RULE rule)
{
return Length_of_RULE(rule);}
/*:205*//*206:*/
#line 1941 "./marpa.w"

int marpa_g_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1943 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 1944 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}

/*:206*//*212:*/
#line 1972 "./marpa.w"

int marpa_g_rule_is_discard_separation(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 1977 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 1978 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 1979 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_discard;
}

/*:212*//*215:*/
#line 2010 "./marpa.w"

PRIVATE int rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(lhs_id)->t_is_accessible;}
int marpa_g_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2017 "./marpa.w"

RULE rule;
/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2019 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}

/*:215*//*217:*/
#line 2026 "./marpa.w"

PRIVATE int rule_is_productive(struct marpa_g*g,RULE rule)
{
int rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++){
Marpa_Symbol_ID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_by_ID(rhs_id)->t_is_productive)return 0;
}
return 1;}
int marpa_g_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2037 "./marpa.w"

RULE rule;
/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2039 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}

/*:217*//*221:*/
#line 2055 "./marpa.w"

int marpa_g_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2058 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2059 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}

/*:221*//*225:*/
#line 2074 "./marpa.w"

int marpa_g_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2077 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2078 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;}

/*:225*//*227:*/
#line 2084 "./marpa.w"

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

/*:227*//*230:*/
#line 2106 "./marpa.w"

int marpa_g_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2109 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2110 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}

/*:230*//*233:*/
#line 2134 "./marpa.w"

int marpa_g_rule_is_virtual_lhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2139 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 2140 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2141 "./marpa.w"

return RULE_has_Virtual_LHS(RULE_by_ID(g,rule_id));
}

/*:233*//*236:*/
#line 2151 "./marpa.w"

int marpa_g_rule_is_virtual_rhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2156 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 2157 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2158 "./marpa.w"

return RULE_has_Virtual_RHS(RULE_by_ID(g,rule_id));
}

/*:236*//*239:*/
#line 2168 "./marpa.w"

unsigned int marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2173 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 2174 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2175 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}

/*:239*//*242:*/
#line 2185 "./marpa.w"

unsigned int marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2190 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 2191 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2192 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}

/*:242*//*246:*/
#line 2202 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_original(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2207 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2208 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_original;
}

/*:246*//*250:*/
#line 2221 "./marpa.w"

int marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2226 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 2227 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2228 "./marpa.w"

return Real_SYM_Count_of_RULE(RULE_by_ID(g,rule_id));
}

/*:250*//*253:*/
#line 2248 "./marpa.w"

int marpa_g_rule_is_ask_me(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2253 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2254 "./marpa.w"

return RULE_is_Ask_Me(RULE_by_ID(g,rule_id));
}
/*:253*//*254:*/
#line 2273 "./marpa.w"

int marpa_g_rule_whatever_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2278 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2279 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}
int marpa_g_rule_ask_me_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2287 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2288 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 1;
}
int marpa_g_rule_first_child_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2296 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2297 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}

/*:254*//*259:*/
#line 2315 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2320 "./marpa.w"

/*1165:*/
#line 12999 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1165*/
#line 2321 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(RULE_has_Virtual_LHS(rule))return-1;
if(rule->t_is_semantic_equivalent)return rule->t_original;
return rule_id;
}

/*:259*//*267:*/
#line 2369 "./marpa.w"

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

/*:267*//*268:*/
#line 2395 "./marpa.w"

int marpa_g_precompute(struct marpa_g*g)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 2398 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 2399 "./marpa.w"

G_EVENTS_CLEAR(g);
if(!census(g))return failure_indicator;
if(!CHAF_rewrite(g))return failure_indicator;
if(!g_augment(g))return failure_indicator;
if(!G_is_Trivial(g)){
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*494:*/
#line 5144 "./marpa.w"
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

/*:494*/
#line 2408 "./marpa.w"

}
return G_EVENT_COUNT(g);
}

/*:268*//*270:*/
#line 2445 "./marpa.w"

PRIVATE_NOT_INLINE GRAMMAR census(GRAMMAR g)
{
/*1160:*/
#line 12976 "./marpa.w"
void*const failure_indicator= NULL;
/*:1160*/
#line 2448 "./marpa.w"

/*271:*/
#line 2476 "./marpa.w"

unsigned int pre_rewrite_rule_count= RULE_Count_of_G(g);
unsigned int pre_rewrite_symbol_count= SYM_Count_of_G(g);

/*:271*//*276:*/
#line 2510 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_original_start_symid;
SYM original_start_symbol;

/*:276*//*280:*/
#line 2549 "./marpa.w"

Bit_Vector terminal_v;
int have_marked_terminals= 0;

/*:280*//*286:*/
#line 2600 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
int have_empty_rule= 0;

/*:286*//*288:*/
#line 2632 "./marpa.w"

Bit_Vector nullable_v;
/*:288*//*292:*/
#line 2657 "./marpa.w"

Bit_Vector productive_v;
/*:292*//*295:*/
#line 2698 "./marpa.w"
Bit_Matrix reach_matrix;
/*:295*//*298:*/
#line 2716 "./marpa.w"

Bit_Vector accessible_v;

/*:298*/
#line 2449 "./marpa.w"

/*272:*/
#line 2480 "./marpa.w"

if(RULE_Count_of_G(g)<=0){MARPA_ERROR(MARPA_ERR_NO_RULES);return NULL;}
/*:272*/
#line 2450 "./marpa.w"

/*273:*/
#line 2487 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return NULL;}
/*:273*/
#line 2451 "./marpa.w"

/*275:*/
#line 2495 "./marpa.w"

if(original_start_symid<0){
MARPA_ERROR(MARPA_ERR_NO_START_SYMBOL);
return failure_indicator;
}
if(!symbol_is_valid(g,original_start_symid)){
MARPA_DEV_ERROR("invalid start symbol");
return failure_indicator;
}
original_start_symbol= SYM_by_ID(original_start_symid);
if(DSTACK_LENGTH(original_start_symbol->t_lhs)<=0){
MARPA_ERROR(MARPA_ERR_START_NOT_LHS);
return failure_indicator;
}

/*:275*/
#line 2452 "./marpa.w"

/*277:*/
#line 2514 "./marpa.w"

{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;
rule_id<(Marpa_Rule_ID)pre_rewrite_rule_count;
rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
bv_bit_set(lhs_v,(unsigned int)lhs_id);
if(Length_of_RULE(rule)<=0){
bv_bit_set(empty_lhs_v,(unsigned int)lhs_id);
have_empty_rule= 1;
}
}
}
/*:277*/
#line 2453 "./marpa.w"

/*278:*/
#line 2533 "./marpa.w"

{Marpa_Symbol_ID symid;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symid= 0;
symid<(Marpa_Symbol_ID)pre_rewrite_symbol_count;
symid++){
SYM symbol= SYM_by_ID(symid);
if(SYM_is_Terminal(symbol)){
bv_bit_set(terminal_v,(unsigned int)symid);
have_marked_terminals= 1;
}
}}
/*:278*/
#line 2454 "./marpa.w"

if(have_marked_terminals){
/*282:*/
#line 2567 "./marpa.w"

if(!g->t_is_lhs_terminal_ok){
int no_lhs_terminals;
Bit_Vector bad_lhs_v= bv_clone(terminal_v);
bv_and(bad_lhs_v,bad_lhs_v,lhs_v);
no_lhs_terminals= bv_is_empty(bad_lhs_v);
bv_free(bad_lhs_v);
if(!no_lhs_terminals){
MARPA_ERROR(MARPA_ERR_LHS_IS_TERMINAL);
return NULL;
}
}

/*:282*/
#line 2456 "./marpa.w"

}else{
/*281:*/
#line 2553 "./marpa.w"

if(have_empty_rule&&g->t_is_lhs_terminal_ok){
MARPA_ERROR(MARPA_ERR_NULL_RULE_UNMARKED_TERMINALS);
return NULL;
}
/*:281*/
#line 2458 "./marpa.w"
;
if(g->t_is_lhs_terminal_ok){
/*283:*/
#line 2580 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)SYM_Count_of_G(g);symid++)
{SYMID_is_Terminal(symid)= 1;}}
/*:283*/
#line 2460 "./marpa.w"

}else{
/*284:*/
#line 2585 "./marpa.w"

{unsigned int start= 0;
unsigned int min,max;
bv_not(terminal_v,lhs_v);
while(bv_scan(terminal_v,start,&min,&max)){
Marpa_Symbol_ID symid;
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
SYMID_is_Terminal(symid)= 1;
}
start= max+2;
}
}
/*:284*/
#line 2462 "./marpa.w"

}
}
/*287:*/
#line 2605 "./marpa.w"

{
unsigned int min,max,start;
SYMID symid;
int counted_nullables= 0;
nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2)
{
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;
symid++)
{
SYM symbol= SYM_by_ID(symid);
if(symbol->t_is_counted)
{
counted_nullables++;
int_event_new(g,MARPA_EVENT_COUNTED_NULLABLE,symid);
}
symbol->t_is_nullable= 1;
}
}
if(counted_nullables)
{
MARPA_ERROR(MARPA_ERR_COUNTED_NULLABLE);
return NULL;
}
}
/*:287*/
#line 2465 "./marpa.w"

/*290:*/
#line 2637 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{unsigned int min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(symid);
symbol->t_is_productive= 1;
}}
}
/*:290*/
#line 2466 "./marpa.w"

/*291:*/
#line 2651 "./marpa.w"

if(!bv_bit_test(productive_v,(unsigned int)original_start_symid))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
return NULL;
}
/*:291*/
#line 2467 "./marpa.w"

/*294:*/
#line 2680 "./marpa.w"

reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{unsigned int symid,no_of_symbols= SYM_Count_of_G(g);
for(symid= 0;symid<no_of_symbols;symid++){
matrix_bit_set(reach_matrix,symid,symid);
}}
{Marpa_Rule_ID rule_id;
RULEID rule_count_of_g= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<rule_count_of_g;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
unsigned int rhs_ix,rule_length= Length_of_RULE(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,
(unsigned int)lhs_id,(unsigned int)RHS_ID_of_RULE(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:294*/
#line 2468 "./marpa.w"

/*297:*/
#line 2702 "./marpa.w"

accessible_v= matrix_row(reach_matrix,(unsigned int)original_start_symid);
{unsigned int min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(symid);
symbol->t_is_accessible= 1;
}}
}
/*:297*/
#line 2469 "./marpa.w"

/*299:*/
#line 2721 "./marpa.w"

{
Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
unsigned int min,max,start;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID productive_id;
for(productive_id= (Marpa_Symbol_ID)min;
productive_id<=(Marpa_Symbol_ID)max;productive_id++)
{
bv_and(reaches_terminal_v,terminal_v,
matrix_row(reach_matrix,(unsigned int)productive_id));
if(bv_is_empty(reaches_terminal_v))
SYM_is_Nulling(SYM_by_ID(productive_id))= 1;
}
}
bv_free(reaches_terminal_v);
}

/*:299*/
#line 2470 "./marpa.w"

/*279:*/
#line 2545 "./marpa.w"

bv_free(terminal_v);
/*:279*//*285:*/
#line 2597 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:285*//*289:*/
#line 2634 "./marpa.w"

bv_free(nullable_v);

/*:289*//*293:*/
#line 2659 "./marpa.w"

bv_free(productive_v);

/*:293*/
#line 2471 "./marpa.w"

/*296:*/
#line 2699 "./marpa.w"

matrix_free(reach_matrix);

/*:296*/
#line 2472 "./marpa.w"

g->t_is_precomputed= 1;
return g;
}
/*:270*//*306:*/
#line 2798 "./marpa.w"

PRIVATE struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*307:*/
#line 2819 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:307*//*311:*/
#line 2869 "./marpa.w"

int factor_count;
int*factor_positions;
/*:311*//*316:*/
#line 2919 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:316*/
#line 2801 "./marpa.w"

/*312:*/
#line 2872 "./marpa.w"

factor_positions= my_new(int,g->t_max_rule_length);
/*:312*//*317:*/
#line 2922 "./marpa.w"

piece_rhs= my_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= my_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:317*/
#line 2802 "./marpa.w"

/*309:*/
#line 2831 "./marpa.w"

{int no_of_symbols= SYM_Count_of_G(g);
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

/*:309*/
#line 2803 "./marpa.w"

pre_chaf_rule_count= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<pre_chaf_rule_count;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const int rule_length= Length_of_RULE(rule);
int nullable_suffix_ix= 0;
/*308:*/
#line 2823 "./marpa.w"

if(!RULE_is_Used(rule)){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}

/*:308*/
#line 2809 "./marpa.w"

/*310:*/
#line 2853 "./marpa.w"

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
/*:310*/
#line 2810 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*314:*/
#line 2878 "./marpa.w"

RULE_is_Used(rule)= 0;
{


int unprocessed_factor_count;

int factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);


int piece_end,piece_start= 0;
for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*320:*/
#line 2932 "./marpa.w"

SYMID chaf_virtual_symid;
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= first_factor_position-piece_start;
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*315:*/
#line 2902 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:315*/
#line 2940 "./marpa.w"

/*321:*/
#line 2959 "./marpa.w"

{
int remaining_rhs_length,piece_rhs_length;
/*322:*/
#line 2971 "./marpa.w"

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
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 2986 "./marpa.w"

}

/*:322*/
#line 2962 "./marpa.w"
;
/*323:*/
#line 2989 "./marpa.w"

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
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3007 "./marpa.w"

}

/*:323*/
#line 2963 "./marpa.w"
;
/*324:*/
#line 3012 "./marpa.w"
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
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3022 "./marpa.w"

}

/*:324*/
#line 2964 "./marpa.w"
;
/*325:*/
#line 3031 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
int real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3036 "./marpa.w"

}

/*:325*/
#line 2965 "./marpa.w"
;
}

/*:321*/
#line 2941 "./marpa.w"

factor_position_ix++;
}else{
int second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*315:*/
#line 2902 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:315*/
#line 2946 "./marpa.w"

/*327:*/
#line 3041 "./marpa.w"
{
int piece_rhs_length;
RULE chaf_rule;
int real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:327*//*328:*/
#line 3050 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3056 "./marpa.w"


/*:328*//*329:*/
#line 3059 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3064 "./marpa.w"


/*:329*//*330:*/
#line 3067 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3073 "./marpa.w"


/*:330*//*331:*/
#line 3076 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3079 "./marpa.w"


/*:331*//*332:*/
#line 3082 "./marpa.w"
}

/*:332*/
#line 2947 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:320*/
#line 2893 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*333:*/
#line 3086 "./marpa.w"
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

/*:333*//*334:*/
#line 3100 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3105 "./marpa.w"


/*:334*//*335:*/
#line 3108 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3113 "./marpa.w"


/*:335*//*336:*/
#line 3116 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3122 "./marpa.w"


/*:336*//*337:*/
#line 3126 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3130 "./marpa.w"

}

/*:337*//*338:*/
#line 3134 "./marpa.w"
}

/*:338*/
#line 2896 "./marpa.w"

}else{
/*339:*/
#line 3137 "./marpa.w"
{
int piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
int real_symbol_count;
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:339*//*340:*/
#line 3148 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3153 "./marpa.w"


/*:340*//*341:*/
#line 3157 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*343:*/
#line 3173 "./marpa.w"

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

/*:343*/
#line 3163 "./marpa.w"

}

/*:341*//*342:*/
#line 3167 "./marpa.w"
}

/*:342*/
#line 2898 "./marpa.w"

}
}

/*:314*/
#line 2813 "./marpa.w"

NEXT_RULE:;
}
/*313:*/
#line 2874 "./marpa.w"

my_free(factor_positions);

/*:313*//*318:*/
#line 2925 "./marpa.w"

my_free(piece_rhs);
my_free(remaining_rhs);

/*:318*/
#line 2816 "./marpa.w"

return g;
}
/*:306*//*344:*/
#line 3192 "./marpa.w"

PRIVATE
SYMID alias_by_id(GRAMMAR g,SYMID proper_id)
{
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
return ID_of_SYM(alias);
}

/*:344*//*346:*/
#line 3203 "./marpa.w"

PRIVATE
GRAMMAR g_augment(GRAMMAR g)
{
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g->t_original_start_symid);
/*347:*/
#line 3218 "./marpa.w"

if(SYM_is_Nulling(old_start)){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:347*/
#line 3212 "./marpa.w"

if(proper_old_start){/*348:*/
#line 3228 "./marpa.w"
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

/*:348*/
#line 3213 "./marpa.w"
}
if(nulling_old_start){/*349:*/
#line 3247 "./marpa.w"
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
nulling_new_start->t_is_nullable= 1;
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

/*:349*/
#line 3214 "./marpa.w"
}
return g;
}

/*:346*//*354:*/
#line 3322 "./marpa.w"

PRIVATE
void loop_detect(struct marpa_g*g)
{
int rule_count_of_g= RULE_Count_of_G(g);
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_create((unsigned int)rule_count_of_g,
(unsigned int)rule_count_of_g);
/*355:*/
#line 3347 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<rule_count_of_g;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID proper_id;
int rhs_ix,rule_length;
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
RULEID ix;
RULEID no_of_lhs_rules= DSTACK_LENGTH(rhs_symbol->t_lhs);
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,(unsigned int)rule_id,
*DSTACK_INDEX(rhs_symbol->t_lhs,RULEID,ix));
}}
NEXT_RULE:;
}}

/*:355*/
#line 3331 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*356:*/
#line 3386 "./marpa.w"
{RULEID rule_id;
for(rule_id= 0;rule_id<rule_count_of_g;rule_id++){
RULE rule;
if(!matrix_bit_test(unit_transition_matrix,(unsigned int)rule_id,(unsigned int)rule_id))
continue;
loop_rule_count++;
rule= RULE_by_ID(g,rule_id);
rule->t_is_loop= 1;
rule->t_is_virtual_loop= rule->t_virtual_start<0||!RULE_has_Virtual_RHS(rule);
}}

/*:356*/
#line 3333 "./marpa.w"

if(loop_rule_count)
{
g->t_has_loop= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
matrix_free(unit_transition_matrix);
}

/*:354*//*371:*/
#line 3548 "./marpa.w"

PRIVATE int item_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:371*//*376:*/
#line 3585 "./marpa.w"

int marpa_g_AHFA_item_count(struct marpa_g*g){
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 3587 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 3588 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:376*//*377:*/
#line 3592 "./marpa.w"

Marpa_Rule_ID marpa_g_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 3595 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 3596 "./marpa.w"

/*1166:*/
#line 13004 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1166*/
#line 3597 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(item_id))->t_id;
}

/*:377*//*379:*/
#line 3602 "./marpa.w"

int marpa_g_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 3605 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 3606 "./marpa.w"

/*1166:*/
#line 13004 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1166*/
#line 3607 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:379*//*381:*/
#line 3612 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 3615 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 3616 "./marpa.w"

/*1166:*/
#line 13004 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1166*/
#line 3617 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:381*//*382:*/
#line 3621 "./marpa.w"

int marpa_g_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 3624 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 3625 "./marpa.w"

/*1166:*/
#line 13004 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1166*/
#line 3626 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:382*//*384:*/
#line 3637 "./marpa.w"

PRIVATE
void create_AHFA_items(GRAMMAR g)
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
/*385:*/
#line 3662 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_RULE(rule);rhs_ix++)
{
SYMID rh_symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(rh_symid);
if(!symbol->t_is_nullable)
{
Last_Proper_SYMI_of_RULE(rule)= symbol_instance_of_next_rule+rhs_ix;
/*386:*/
#line 3686 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:386*/
#line 3673 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*387:*/
#line 3695 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:387*/
#line 3682 "./marpa.w"

current_item++;
}

/*:385*/
#line 3650 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
no_of_items= AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= my_renew(struct s_AHFA_item,base_item,no_of_items);
/*388:*/
#line 3709 "./marpa.w"

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

/*:388*/
#line 3658 "./marpa.w"

/*393:*/
#line 3773 "./marpa.w"

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

/*:393*/
#line 3659 "./marpa.w"

}

/*:384*//*390:*/
#line 3734 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:390*//*392:*/
#line 3749 "./marpa.w"

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

/*:392*//*404:*/
#line 3904 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*418:*/
#line 3976 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;

/*:418*//*435:*/
#line 4082 "./marpa.w"
Leo_LHS_ID_of_AHFA(ahfa)= -1;
/*:435*/
#line 3907 "./marpa.w"

}

/*:404*//*412:*/
#line 3937 "./marpa.w"

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

/*:412*//*426:*/
#line 4009 "./marpa.w"

PRIVATE int AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:426*//*429:*/
#line 4023 "./marpa.w"

int marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:429*//*430:*/
#line 4028 "./marpa.w"

int
marpa_g_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 4031 "./marpa.w"

AHFA state;
/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 4033 "./marpa.w"

/*1167:*/
#line 13009 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1167*/
#line 4034 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:430*//*431:*/
#line 4041 "./marpa.w"

Marpa_AHFA_Item_ID marpa_g_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
int item_ix){
AHFA state;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 4046 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 4047 "./marpa.w"

/*1167:*/
#line 13009 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1167*/
#line 4048 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
if(item_ix<0){
MARPA_DEV_ERROR("symbol lhs index negative");
return failure_indicator;
}
if(item_ix>=state->t_item_count){
MARPA_DEV_ERROR("invalid state item ix");
return failure_indicator;
}
return AIMID_of_AHFA_by_AEX(g,state,item_ix);
}

/*:431*//*432:*/
#line 4061 "./marpa.w"

int marpa_g_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 4065 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 4066 "./marpa.w"

/*1167:*/
#line 13009 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1167*/
#line 4067 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:432*//*436:*/
#line 4083 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 4086 "./marpa.w"

AHFA state;
/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 4088 "./marpa.w"

/*1167:*/
#line 13009 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1167*/
#line 4089 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:436*//*439:*/
#line 4110 "./marpa.w"

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

/*:439*//*440:*/
#line 4138 "./marpa.w"

PRIVATE_NOT_INLINE
void create_AHFA_states(struct marpa_g*g)
{
/*441:*/
#line 4158 "./marpa.w"

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
struct obstack ahfa_work_obs;
int ahfa_count_of_g;
AHFA ahfas_of_g;

/*:441*/
#line 4142 "./marpa.w"

/*442:*/
#line 4173 "./marpa.w"

/*443:*/
#line 4177 "./marpa.w"

{
unsigned int item_id;
unsigned int no_of_items_in_grammar= AIM_Count_of_G(g);
obstack_init(&ahfa_work_obs);
duplicates= marpa_avl_create(AHFA_state_cmp,NULL,NULL);
singleton_duplicates= my_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++)
{
singleton_duplicates[item_id]= NULL;
}
}

/*:443*/
#line 4174 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:442*/
#line 4143 "./marpa.w"

/*463:*/
#line 4679 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_create(symbol_count_of_g,symbol_count_of_g);
/*464:*/
#line 4688 "./marpa.w"

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

/*:464*/
#line 4682 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*465:*/
#line 4725 "./marpa.w"
{
SYMID from_symid;
unsigned int*sort_key_by_rule_id= my_new(unsigned int,rule_count_of_g);
unsigned int no_of_predictable_rules= 0;
/*466:*/
#line 4764 "./marpa.w"

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

/*:466*/
#line 4730 "./marpa.w"

/*467:*/
#line 4776 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
rule_by_sort_key[rule_id]= RULE_by_ID(g,rule_id);
}
qsort(rule_by_sort_key,(int)rule_count_of_g,
sizeof(RULE),cmp_by_rule_sort_key);
}

/*:467*/
#line 4731 "./marpa.w"

/*469:*/
#line 4806 "./marpa.w"

{
unsigned int sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:469*/
#line 4732 "./marpa.w"

/*470:*/
#line 4816 "./marpa.w"

{
prediction_matrix= matrix_create(symbol_count_of_g,no_of_predictable_rules);
for(from_symid= 0;from_symid<(SYMID)symbol_count_of_g;
from_symid++)
{

unsigned int min,max,start;
for(start= 0;
bv_scan(matrix_row
(symbol_by_symbol_matrix,(unsigned int)from_symid),start,
&min,&max);start= max+2)
{
Marpa_Symbol_ID to_symid;
for(to_symid= min;to_symid<=(Marpa_Symbol_ID)max;
to_symid++)
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

matrix_bit_set(prediction_matrix,(unsigned int)from_symid,
sort_key);

}
}
}
}
}

/*:470*/
#line 4733 "./marpa.w"

my_free(sort_key_by_rule_id);
}

/*:465*/
#line 4684 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:463*/
#line 4144 "./marpa.w"

/*450:*/
#line 4319 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
const RULE start_rule= g->t_proper_start_rule;
SYMID*postdot_symbol_ids;
AIM start_item;
AIM*item_list= obstack_alloc(&g->t_obs,sizeof(AIM));

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
obstack_alloc(&g->t_obs,sizeof(SYMID));
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

/*:450*/
#line 4145 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*444:*/
#line 4190 "./marpa.w"
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
/*452:*/
#line 4379 "./marpa.w"
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

AHFA_initialize(p_new_state);
singleton_duplicates[single_item_id]= p_new_state;
new_state_item_list= p_new_state->t_items= 
obstack_alloc(&g->t_obs,sizeof(AIM));
new_state_item_list[0]= single_item_p;
p_new_state->t_item_count= 1;
AHFA_is_Predicted(p_new_state)= 0;
p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
postdot= Postdot_SYMID_of_AIM(single_item_p);
if(postdot>=0)
{
Complete_SYM_Count_of_AHFA(p_new_state)= 0;
p_new_state->t_postdot_sym_count= 1;
p_new_state->t_postdot_symid_ary= 
obstack_alloc(&g->t_obs,sizeof(SYMID));
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
SYMID*complete_symids= obstack_alloc(&g->t_obs,sizeof(SYMID));
*complete_symids= lhs_id;
Complete_SYMIDs_of_AHFA(p_new_state)= complete_symids;
completion_count_inc(&ahfa_work_obs,p_new_state,lhs_id);
Complete_SYM_Count_of_AHFA(p_new_state)= 1;
p_new_state->t_postdot_sym_count= 0;
p_new_state->t_empty_transition= NULL;
/*454:*/
#line 4464 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(predot_symid))
> 0)
{
Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:454*/
#line 4432 "./marpa.w"

}
}

/*:452*/
#line 4210 "./marpa.w"

}else{
/*455:*/
#line 4489 "./marpa.w"
{
AHFA p_new_state;
unsigned int predecessor_ix;
unsigned int no_of_new_items_so_far= 0;
AIM*item_list_for_new_state;
AHFA queued_AHFA_state;
p_new_state= DQUEUE_PUSH(states,AHFA_Object);
item_list_for_new_state= p_new_state->t_items= obstack_alloc(&g->t_obs_tricky,
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
obstack_free(&g->t_obs_tricky,item_list_for_new_state);
transition_add(&ahfa_work_obs,p_working_state,working_symbol,queued_AHFA_state);


goto NEXT_WORKING_SYMBOL;
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
AHFA_initialize(p_new_state);
AHFA_is_Predicted(p_new_state)= 0;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
/*456:*/
#line 4539 "./marpa.w"

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
completion_count_inc(&ahfa_work_obs,p_new_state,complete_symbol_id);
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
Complete_SYM_Count_of_AHFA(p_new_state)= bv_count(complete_v)))
{
unsigned int min,max,start;
SYMID*complete_symids= obstack_alloc(&g->t_obs,
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

/*:456*/
#line 4533 "./marpa.w"

transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
/*458:*/
#line 4617 "./marpa.w"
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

/*:458*/
#line 4536 "./marpa.w"

}

/*:455*/
#line 4212 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:444*/
#line 4147 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*445:*/
#line 4222 "./marpa.w"

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
TRANS new_transition= obstack_alloc(&g->t_obs,sizeof_transition);
LV_To_AHFA_of_TRANS(new_transition)= To_AHFA_of_TRANS(working_transition);
LV_Completion_Count_of_TRANS(new_transition)= 0;
transitions[symbol_id]= new_transition;
}
}
}
}

/*:445*/
#line 4152 "./marpa.w"

/*447:*/
#line 4276 "./marpa.w"

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

/*:447*/
#line 4153 "./marpa.w"

/*446:*/
#line 4245 "./marpa.w"

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

/*:446*/
#line 4154 "./marpa.w"

/*448:*/
#line 4309 "./marpa.w"

my_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*449:*/
#line 4315 "./marpa.w"

my_free(singleton_duplicates);
marpa_avl_destroy(duplicates,NULL);

/*:449*/
#line 4312 "./marpa.w"

obstack_free(&ahfa_work_obs,NULL);

/*:448*/
#line 4155 "./marpa.w"

}

/*:440*//*457:*/
#line 4608 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,struct avl_table*duplicates)
{
const AHFA state_found= marpa_avl_insert(duplicates,sought_state);
return state_found;
}

/*:457*//*468:*/
#line 4787 "./marpa.w"

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

/*:468*//*471:*/
#line 4856 "./marpa.w"

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
item_list_for_new_state= obstack_alloc(&g->t_obs,
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
obstack_free(&g->t_obs,item_list_for_new_state);
return queued_AHFA_state;
}
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE((*states_p),AHFA_Object);
AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_empty_transition= NULL;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
Complete_SYM_Count_of_AHFA(p_new_state)= 0;
/*472:*/
#line 4911 "./marpa.w"

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

/*:472*/
#line 4907 "./marpa.w"

return p_new_state;
}

/*:471*//*483:*/
#line 5020 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:483*//*484:*/
#line 5026 "./marpa.w"

PRIVATE int completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:484*//*485:*/
#line 5033 "./marpa.w"

PRIVATE
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,int aim_ix)
{
URTRANS transition;
transition= obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:485*//*486:*/
#line 5044 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g)
{
int symbol_count= SYM_Count_of_G(g);
int symid= 0;
TRANS*transitions;
transitions= my_malloc(symbol_count*sizeof(transitions[0]));
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:486*//*487:*/
#line 5057 "./marpa.w"

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

/*:487*//*488:*/
#line 5071 "./marpa.w"

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

/*:488*//*490:*/
#line 5086 "./marpa.w"

int marpa_g_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
int*buffer,
int buffer_size
){

/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5093 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
int symbol_count;
int ix= 0;
const int max_ix= buffer_size/sizeof(*buffer);
const int max_results= max_ix/2;





/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 5106 "./marpa.w"

/*1167:*/
#line 13009 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1167*/
#line 5107 "./marpa.w"

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

/*:490*//*493:*/
#line 5127 "./marpa.w"

AHFAID marpa_g_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5132 "./marpa.w"

/*1163:*/
#line 12989 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1163*/
#line 5133 "./marpa.w"

/*1167:*/
#line 13009 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1167*/
#line 5134 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:493*//*498:*/
#line 5170 "./marpa.w"

PRIVATE INPUT
input_new(GRAMMAR g)
{
INPUT input= my_slice_new(struct s_input);
obstack_init(TOK_Obs_of_I(input));
/*501:*/
#line 5183 "./marpa.w"

input->t_ref_count= 1;

/*:501*//*509:*/
#line 5242 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:509*/
#line 5176 "./marpa.w"

return input;
}

/*:498*//*502:*/
#line 5187 "./marpa.w"

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

/*:502*//*503:*/
#line 5200 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:503*//*504:*/
#line 5213 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
obstack_free(TOK_Obs_of_I(input),NULL);
my_slice_free(struct s_input,input);
}

/*:504*//*513:*/
#line 5270 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
int symbol_count_of_g;
/*1160:*/
#line 12976 "./marpa.w"
void*const failure_indicator= NULL;
/*:1160*/
#line 5275 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
r= my_slice_new(struct marpa_r);
symbol_count_of_g= SYM_Count_of_G(g);
/*573:*/
#line 5643 "./marpa.w"
obstack_init(&r->t_obs);
/*:573*/
#line 5282 "./marpa.w"

/*516:*/
#line 5289 "./marpa.w"

r->t_ref_count= 1;

/*:516*//*524:*/
#line 5359 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:524*//*526:*/
#line 5368 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:526*//*530:*/
#line 5392 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:530*//*534:*/
#line 5415 "./marpa.w"
r->t_furthest_earleme= 0;
/*:534*//*538:*/
#line 5428 "./marpa.w"
r->t_sym_workarea= NULL;
/*:538*//*542:*/
#line 5439 "./marpa.w"
r->t_workarea2= NULL;
/*:542*//*546:*/
#line 5459 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:546*//*550:*/
#line 5482 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:550*//*565:*/
#line 5583 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:565*//*569:*/
#line 5619 "./marpa.w"
r->t_is_exhausted= 0;
/*:569*//*593:*/
#line 5741 "./marpa.w"

r->t_earley_set_count= 0;

/*:593*//*598:*/
#line 5787 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:598*//*619:*/
#line 6049 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:619*//*649:*/
#line 6431 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:649*//*684:*/
#line 6890 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:684*//*717:*/
#line 7375 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:717*//*723:*/
#line 7432 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:723*//*744:*/
#line 7723 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:744*//*748:*/
#line 7735 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:748*//*752:*/
#line 7747 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:752*//*821:*/
#line 8601 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:821*//*1124:*/
#line 12635 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1124*/
#line 5283 "./marpa.w"

return r;
}

/*:513*//*517:*/
#line 5293 "./marpa.w"

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

/*:517*//*518:*/
#line 5311 "./marpa.w"

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

/*:518*//*519:*/
#line 5325 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5329 "./marpa.w"

/*521:*/
#line 5346 "./marpa.w"
input_unref(input);

/*:521*//*595:*/
#line 5765 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
my_free(EIMs_of_ES(set));
}
}

/*:595*//*724:*/
#line 7434 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:724*//*746:*/
#line 7728 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:746*//*750:*/
#line 7740 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:750*//*753:*/
#line 7748 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:753*//*822:*/
#line 8603 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:822*//*1125:*/
#line 12637 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1125*/
#line 5330 "./marpa.w"

grammar_unref(g);
my_free(r->t_sym_workarea);
my_free(r->t_workarea2);
/*548:*/
#line 5468 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:548*//*552:*/
#line 5485 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:552*/
#line 5334 "./marpa.w"

/*574:*/
#line 5644 "./marpa.w"
obstack_free(&r->t_obs,NULL);

/*:574*/
#line 5335 "./marpa.w"

my_slice_free(struct marpa_r,r);
}

/*:519*//*527:*/
#line 5376 "./marpa.w"

unsigned int marpa_r_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:527*//*528:*/
#line 5381 "./marpa.w"

PRIVATE ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:528*//*531:*/
#line 5394 "./marpa.w"

int marpa_r_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:531*//*532:*/
#line 5400 "./marpa.w"

int marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,int threshold)
{
r->t_earley_item_warning_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
return 1;
}

/*:532*//*535:*/
#line 5416 "./marpa.w"

unsigned int marpa_r_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:535*//*554:*/
#line 5500 "./marpa.w"

int marpa_r_terminals_expected(struct marpa_r*r,Marpa_Symbol_ID*buffer)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5503 "./marpa.w"

/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5504 "./marpa.w"

unsigned int min,max,start;
int ix= 0;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 5507 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 5508 "./marpa.w"

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

/*:554*//*566:*/
#line 5589 "./marpa.w"

int marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5592 "./marpa.w"

/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5593 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 5594 "./marpa.w"

return r->t_use_leo_flag;
}
/*:566*//*567:*/
#line 5597 "./marpa.w"

int marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5601 "./marpa.w"

/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5602 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 5603 "./marpa.w"

/*1169:*/
#line 13022 "./marpa.w"

if(Input_Phase_of_R(r)!=R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce started");
return failure_indicator;
}
/*:1169*/
#line 5604 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:567*//*571:*/
#line 5629 "./marpa.w"

int marpa_r_is_exhausted(struct marpa_r*r)
{
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5632 "./marpa.w"

/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5633 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 5634 "./marpa.w"

return R_is_Exhausted(r);
}

/*:571*//*576:*/
#line 5648 "./marpa.w"

Marpa_Error_Code marpa_r_error(Marpa_Recognizer r,const char**p_error_string)
{
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5651 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:576*//*578:*/
#line 5657 "./marpa.w"

int marpa_r_event(Marpa_Recognizer r,Marpa_Event public_event,int ix)
{
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5660 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:578*//*594:*/
#line 5745 "./marpa.w"

PRIVATE ES
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
Next_ES_of_ES(set)= NULL;
/*1130:*/
#line 12681 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1130*/
#line 5760 "./marpa.w"

return set;
}

/*:594*//*599:*/
#line 5790 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5793 "./marpa.w"

/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5794 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 5796 "./marpa.w"

if(!trace_earley_set){
MARPA_DEV_ERROR("no trace es");
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:599*//*600:*/
#line 5804 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5807 "./marpa.w"

/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5808 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 5809 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:600*//*601:*/
#line 5813 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const int es_does_not_exist= -1;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5817 "./marpa.w"

/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5818 "./marpa.w"

ES earley_set;
/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 5820 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 5821 "./marpa.w"

if(set_id<0){
MARPA_DEV_ERROR("invalid es ordinal");
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

/*:601*//*603:*/
#line 5837 "./marpa.w"

int marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 5840 "./marpa.w"

ES earley_set;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5842 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 5843 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 5844 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_DEV_ERROR("invalid es ordinal");
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:603*//*612:*/
#line 5940 "./marpa.w"

PRIVATE EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1160:*/
#line 12976 "./marpa.w"
void*const failure_indicator= NULL;
/*:1160*/
#line 5944 "./marpa.w"

/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 5945 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const int count= ++EIM_Count_of_ES(set);
/*614:*/
#line 5992 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_EIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:614*/
#line 5950 "./marpa.w"

new_item= obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:612*//*613:*/
#line 5960 "./marpa.w"

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

/*:613*//*617:*/
#line 6024 "./marpa.w"

PRIVATE_NOT_INLINE Marpa_Error_Code invalid_source_type_code(unsigned int type)
{
switch(type){
case NO_SOURCE:
return MARPA_ERR_NONE_IS_INVALID_SOURCE_TYPE;
case SOURCE_IS_TOKEN:
return MARPA_ERR_TOKEN_IS_INVALID_SOURCE_TYPE;
case SOURCE_IS_COMPLETION:
return MARPA_ERR_COMPLETION_IS_INVALID_SOURCE_TYPE;
case SOURCE_IS_LEO:
return MARPA_ERR_LEO_IS_INVALID_SOURCE_TYPE;
case SOURCE_IS_AMBIGUOUS:
return MARPA_ERR_AMBIGUOUS_IS_INVALID_SOURCE_TYPE;
}
return MARPA_ERR_UNKNOWN_SOURCE_TYPE;
}

/*:617*//*624:*/
#line 6089 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const int es_does_not_exist= -1;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6095 "./marpa.w"

/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6096 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6097 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*625:*/
#line 6120 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*651:*/
#line 6470 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:651*/
#line 6123 "./marpa.w"

}

/*:625*/
#line 6104 "./marpa.w"

if(set_id<0)
{
MARPA_DEV_ERROR("invalid es ordinal");
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

/*:624*//*626:*/
#line 6126 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const int eim_does_not_exist= -1;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6131 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6135 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6136 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*625:*/
#line 6120 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*651:*/
#line 6470 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:651*/
#line 6123 "./marpa.w"

}

/*:625*/
#line 6140 "./marpa.w"

MARPA_DEV_ERROR("no trace es");
return failure_indicator;
}
trace_earley_item_clear(r);
if(item_id<0)
{
MARPA_DEV_ERROR("invalid eim ordinal");
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

/*:626*//*628:*/
#line 6169 "./marpa.w"

PRIVATE void trace_earley_item_clear(struct marpa_r*r)
{
/*627:*/
#line 6166 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:627*/
#line 6172 "./marpa.w"

trace_source_link_clear(r);
}

/*:628*//*629:*/
#line 6176 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6179 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6181 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6182 "./marpa.w"

if(!item){
/*627:*/
#line 6166 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:627*/
#line 6184 "./marpa.w"

MARPA_DEV_ERROR("no trace eim");
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:629*//*636:*/
#line 6257 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6261 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6264 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6265 "./marpa.w"

if(!postdot_item){
MARPA_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item)){
MARPA_DEV_ERROR("pim is not lim");
return failure_indicator;
}
predecessor_leo_item= Predecessor_LIM_of_LIM(LIM_of_PIM(postdot_item));
if(!predecessor_leo_item)return no_predecessor;
return Postdot_SYMID_of_LIM(predecessor_leo_item);
}

/*:636*//*637:*/
#line 6279 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6283 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6285 "./marpa.w"

EIM base_earley_item;
/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6287 "./marpa.w"

if(!postdot_item){
MARPA_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:637*//*638:*/
#line 6297 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6301 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6304 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6305 "./marpa.w"

if(!postdot_item){
MARPA_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:638*//*642:*/
#line 6339 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6343 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6345 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6346 "./marpa.w"

if(!postdot_item)
{
MARPA_DEV_ERROR("no trace pim");
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


/*:642*//*646:*/
#line 6395 "./marpa.w"

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
/*:646*//*647:*/
#line 6415 "./marpa.w"

PRIVATE PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:647*//*650:*/
#line 6445 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6450 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6454 "./marpa.w"

/*651:*/
#line 6470 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:651*/
#line 6455 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6456 "./marpa.w"

/*1174:*/
#line 13048 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
MARPA_DEV_ERROR("invalid symid");
return failure_indicator;
}

/*:1174*/
#line 6457 "./marpa.w"

if(!current_es){
MARPA_DEV_ERROR("no pim");
return failure_indicator;
}
pim_sym_p= PIM_SYM_P_of_ES_by_SYMID(current_es,symid);
pim= *pim_sym_p;
if(!pim)return-1;
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return symid;
}

/*:650*//*652:*/
#line 6480 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6484 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6487 "./marpa.w"

PIM*pim_sym_p;
/*651:*/
#line 6470 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:651*/
#line 6489 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6490 "./marpa.w"

if(!current_earley_set){
/*627:*/
#line 6166 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:627*/
#line 6492 "./marpa.w"

MARPA_DEV_ERROR("no trace es");
return failure_indicator;
}
if(current_earley_set->t_postdot_sym_count<=0)return-1;
pim_sym_p= current_earley_set->t_postdot_ary+0;
pim= pim_sym_p[0];
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return Postdot_SYMID_of_PIM(pim);
}

/*:652*//*653:*/
#line 6511 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6516 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6520 "./marpa.w"


pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*651:*/
#line 6470 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:651*/
#line 6524 "./marpa.w"

if(!pim_sym_p||!pim){
MARPA_DEV_ERROR("no trace pim");
return failure_indicator;
}
/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6529 "./marpa.w"

if(!current_set){
MARPA_DEV_ERROR("no trace es");
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

/*:653*//*654:*/
#line 6549 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_postdot_item_symbol(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6552 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6554 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6555 "./marpa.w"

if(!postdot_item){
MARPA_DEV_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:654*//*670:*/
#line 6683 "./marpa.w"
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
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Token_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
TOK_of_Source(new_link->t_source)= token;
First_Token_Link_of_EIM(item)= new_link;
}

/*:670*//*675:*/
#line 6759 "./marpa.w"

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
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Completion_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
First_Completion_Link_of_EIM(item)= new_link;
}

/*:675*//*676:*/
#line 6787 "./marpa.w"

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
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Leo_SRCL_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
First_Leo_SRCL_of_EIM(item)= new_link;
}

/*:676*//*678:*/
#line 6834 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*679:*/
#line 6851 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= new_link;
}

/*:679*/
#line 6842 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*680:*/
#line 6860 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= new_link;
First_Token_Link_of_EIM(item)= NULL;
}

/*:680*/
#line 6844 "./marpa.w"

return;
case SOURCE_IS_LEO:/*681:*/
#line 6869 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= new_link;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= NULL;
}

/*:681*/
#line 6846 "./marpa.w"

return;
}
}

/*:678*//*686:*/
#line 6901 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6904 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6908 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6909 "./marpa.w"

/*700:*/
#line 7128 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_DEV_ERROR("no eim");
return failure_indicator;
}

/*:700*/
#line 6910 "./marpa.w"

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

/*:686*//*689:*/
#line 6945 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6948 "./marpa.w"

SRCL full_link;
EIM item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6951 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6952 "./marpa.w"

/*700:*/
#line 7128 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_DEV_ERROR("no eim");
return failure_indicator;
}

/*:700*/
#line 6953 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_TOKEN){
trace_source_link_clear(r);
MARPA_DEV_ERROR("not tracing token links");
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

/*:689*//*691:*/
#line 6976 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 6979 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 6983 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 6984 "./marpa.w"

/*700:*/
#line 7128 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_DEV_ERROR("no eim");
return failure_indicator;
}

/*:700*/
#line 6985 "./marpa.w"

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

/*:691*//*694:*/
#line 7019 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7022 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7026 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 7027 "./marpa.w"

/*700:*/
#line 7128 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_DEV_ERROR("no eim");
return failure_indicator;
}

/*:700*/
#line 7028 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_COMPLETION){
trace_source_link_clear(r);
MARPA_DEV_ERROR("not tracing completion links");
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

/*:694*//*696:*/
#line 7052 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_leo_link_trace(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7056 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7060 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 7061 "./marpa.w"

/*700:*/
#line 7128 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_DEV_ERROR("no eim");
return failure_indicator;
}

/*:700*/
#line 7062 "./marpa.w"

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

/*:696*//*699:*/
#line 7098 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_leo_link_trace(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7102 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7106 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 7107 "./marpa.w"

/*700:*/
#line 7128 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_DEV_ERROR("no eim");
return failure_indicator;
}

/*:700*/
#line 7108 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_LEO)
{
trace_source_link_clear(r);
MARPA_DEV_ERROR("not tracing leo links");
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

/*:699*//*701:*/
#line 7137 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:701*//*702:*/
#line 7153 "./marpa.w"

AHFAID marpa_r_source_predecessor_state(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7156 "./marpa.w"

unsigned int source_type;
SRC source;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7159 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 7160 "./marpa.w"

source_type= r->t_trace_source_type;
/*709:*/
#line 7304 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:709*/
#line 7162 "./marpa.w"

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

/*:702*//*703:*/
#line 7194 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,int*value_p)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7197 "./marpa.w"

unsigned int source_type;
SRC source;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7200 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 7201 "./marpa.w"

source_type= r->t_trace_source_type;
/*709:*/
#line 7304 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:709*/
#line 7203 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:703*//*705:*/
#line 7226 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7229 "./marpa.w"

unsigned int source_type;
SRC source;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7232 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 7233 "./marpa.w"

source_type= r->t_trace_source_type;
/*709:*/
#line 7304 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:709*/
#line 7235 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:705*//*708:*/
#line 7272 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7275 "./marpa.w"

const EARLEME no_predecessor= -1;
unsigned int source_type;
SRC source;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7279 "./marpa.w"

/*1172:*/
#line 13038 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 13039 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 13040 "./marpa.w"


/*:1172*/
#line 7280 "./marpa.w"

source_type= r->t_trace_source_type;
/*709:*/
#line 7304 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:709*/
#line 7282 "./marpa.w"

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

/*:708*//*718:*/
#line 7380 "./marpa.w"

PRIVATE
TOK token_new(INPUT input,SYMID symbol_id,int value)
{
TOK token;
if(value){
token= obstack_alloc(TOK_Obs_of_I(input),sizeof(*token));
SYMID_of_TOK(token)= symbol_id;
Type_of_TOK(token)= VALUED_TOKEN_OR_NODE;
Value_of_TOK(token)= value;
}else{
token= obstack_alloc(TOK_Obs_of_I(input),sizeof(token->t_unvalued));
SYMID_of_TOK(token)= symbol_id;
Type_of_TOK(token)= UNVALUED_TOKEN_OR_NODE;
}
return token;
}

/*:718*//*726:*/
#line 7440 "./marpa.w"

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

/*:726*//*728:*/
#line 7484 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:728*//*729:*/
#line 7501 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:729*//*730:*/
#line 7516 "./marpa.w"

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

/*:730*//*731:*/
#line 7535 "./marpa.w"
int marpa_r_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7541 "./marpa.w"

const int symbol_count_of_g= SYM_Count_of_G(g);
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7543 "./marpa.w"

/*1169:*/
#line 13022 "./marpa.w"

if(Input_Phase_of_R(r)!=R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce started");
return failure_indicator;
}
/*:1169*/
#line 7544 "./marpa.w"

Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g)){
/*570:*/
#line 5620 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:570*/
#line 7547 "./marpa.w"

return 1;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
/*543:*/
#line 5440 "./marpa.w"

{
const unsigned int sym_workarea_size= sizeof(void*)*symbol_count_of_g;
/*539:*/
#line 5429 "./marpa.w"

r->t_sym_workarea= my_malloc(sym_workarea_size);

/*:539*/
#line 5443 "./marpa.w"

r->t_workarea2= my_malloc(2u*sym_workarea_size);
}

/*:543*/
#line 7551 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*547:*/
#line 5463 "./marpa.w"
{
r->t_bv_sym= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym2= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym3= bv_create((unsigned int)symbol_count_of_g);
}
/*:547*//*551:*/
#line 5483 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((unsigned int)symbol_count_of_g);
/*:551*/
#line 7553 "./marpa.w"

/*745:*/
#line 7724 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT(r->t_eim_work_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:745*//*749:*/
#line 7736 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT(r->t_completion_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:749*/
#line 7554 "./marpa.w"

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

/*:731*//*738:*/
#line 7622 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID token_id,
int value,
int length)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7629 "./marpa.w"

/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7630 "./marpa.w"

const int duplicate_token_indicator= -3;
const int unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1171:*/
#line 13032 "./marpa.w"

if(Input_Phase_of_R(r)!=R_DURING_INPUT){
MARPA_DEV_ERROR("recce not accepting input");
return failure_indicator;
}

/*:1171*/
#line 7636 "./marpa.w"

/*739:*/
#line 7644 "./marpa.w"
{
const SYM_Const token= SYM_by_ID(token_id);
if(!SYM_is_Terminal(token)){
MARPA_DEV_ERROR("token is not a terminal");
return failure_indicator;
}
if(length<=0){
MARPA_DEV_ERROR("token length negative or zero");
return failure_indicator;
}
if(length>=EARLEME_THRESHOLD){
MARPA_DEV_ERROR("token too long");
return failure_indicator;
}
}

/*:739*/
#line 7637 "./marpa.w"

/*741:*/
#line 7675 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:741*/
#line 7638 "./marpa.w"

/*740:*/
#line 7660 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
MARPA_DEV_ERROR("parse too long");
return failure_indicator;
}
}

/*:740*/
#line 7639 "./marpa.w"

/*742:*/
#line 7698 "./marpa.w"

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
/*719:*/
#line 7401 "./marpa.w"
obstack_free(TOK_Obs_of_R(r),token);

/*:719*/
#line 7709 "./marpa.w"

return duplicate_token_indicator;
}
}

/*:742*/
#line 7640 "./marpa.w"

return current_earleme;
}

/*:738*//*755:*/
#line 7767 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(struct marpa_r*r)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 7771 "./marpa.w"

/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 7772 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
int count_of_expected_terminals;
/*1171:*/
#line 13032 "./marpa.w"

if(Input_Phase_of_R(r)!=R_DURING_INPUT){
MARPA_DEV_ERROR("recce not accepting input");
return failure_indicator;
}

/*:1171*/
#line 7777 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*756:*/
#line 7805 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*570:*/
#line 5620 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:570*/
#line 7809 "./marpa.w"

MARPA_DEV_ERROR("parse exhausted");
return failure_indicator;
}
}

/*:756*/
#line 7781 "./marpa.w"

/*758:*/
#line 7830 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:758*/
#line 7782 "./marpa.w"

/*757:*/
#line 7817 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:757*/
#line 7783 "./marpa.w"

/*759:*/
#line 7836 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*760:*/
#line 7843 "./marpa.w"

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

/*:760*/
#line 7840 "./marpa.w"

}

/*:759*/
#line 7784 "./marpa.w"

/*761:*/
#line 7870 "./marpa.w"
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

/*:761*/
#line 7785 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*762:*/
#line 7889 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
int count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
int symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*763:*/
#line 7902 "./marpa.w"

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
/*764:*/
#line 7925 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*765:*/
#line 7941 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:765*/
#line 7934 "./marpa.w"

}
/*766:*/
#line 7948 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:766*/
#line 7936 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:764*/
#line 7913 "./marpa.w"

}
else
{
/*767:*/
#line 7958 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*765:*/
#line 7941 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:765*/
#line 7967 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:767*/
#line 7917 "./marpa.w"

break;


}
}
}

/*:763*/
#line 7898 "./marpa.w"

}
}

/*:762*/
#line 7788 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


/*570:*/
#line 5620 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:570*/
#line 7798 "./marpa.w"

event_new(g,MARPA_EVENT_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:755*//*768:*/
#line 7972 "./marpa.w"

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

/*:768*//*769:*/
#line 7993 "./marpa.w"

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

/*:769*//*775:*/
#line 8037 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,ES current_earley_set)
{
void**const pim_workarea= r->t_sym_workarea;
/*520:*/
#line 5343 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:520*/
#line 8042 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*776:*/
#line 8059 "./marpa.w"
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
new_pim= obstack_alloc(&r->t_obs,sizeof(EIX_Object));
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

/*:776*/
#line 8048 "./marpa.w"

if(r->t_is_using_leo){
/*780:*/
#line 8117 "./marpa.w"

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
/*781:*/
#line 8151 "./marpa.w"
{
LIM new_lim;
new_lim= obstack_alloc(&r->t_obs,sizeof(*new_lim));
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

/*:781*/
#line 8137 "./marpa.w"

}
}
}
}
}
}

/*:780*/
#line 8050 "./marpa.w"

/*790:*/
#line 8236 "./marpa.w"
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

/*793:*/
#line 8295 "./marpa.w"
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

/*:793*/
#line 8254 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*799:*/
#line 8387 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:799*/
#line 8256 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*801:*/
#line 8408 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:801*/
#line 8262 "./marpa.w"

continue;
}
/*794:*/
#line 8310 "./marpa.w"
{
void**const lim_chain= r->t_workarea2;
int lim_chain_ix;
/*797:*/
#line 8331 "./marpa.w"
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

/*793:*/
#line 8295 "./marpa.w"
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

/*:793*/
#line 8357 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(unsigned int)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:797*/
#line 8313 "./marpa.w"

/*798:*/
#line 8376 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*799:*/
#line 8387 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:799*/
#line 8380 "./marpa.w"

}else{
/*801:*/
#line 8408 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:801*/
#line 8382 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:798*/
#line 8314 "./marpa.w"

}

/*:794*/
#line 8265 "./marpa.w"

}
}
}

/*:790*/
#line 8051 "./marpa.w"

}
/*802:*/
#line 8414 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= obstack_alloc(&r->t_obs,
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

/*:802*/
#line 8053 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:775*//*823:*/
#line 8606 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:823*//*824:*/
#line 8614 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:824*//*825:*/
#line 8620 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)obstack_free(&stack->t_obs,NULL);
stack->t_base= NULL;
}

/*:825*//*826:*/
#line 8627 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:826*//*827:*/
#line 8637 "./marpa.w"

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

/*:827*//*828:*/
#line 8653 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:828*//*832:*/
#line 8716 "./marpa.w"

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

/*:832*//*868:*/
#line 9316 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:868*//*869:*/
#line 9328 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:869*//*875:*/
#line 9443 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause);
return draft_and_node;
}

/*:875*//*877:*/
#line 9466 "./marpa.w"

PRIVATE
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:877*//*904:*/
#line 9903 "./marpa.w"

int marpa_b_and_node_count(Marpa_Bocage b)
{
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 9906 "./marpa.w"

/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 9907 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 9908 "./marpa.w"

return AND_Count_of_B(b);
}

/*:904*//*906:*/
#line 9929 "./marpa.w"

int marpa_b_and_node_parent(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 9933 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 9934 "./marpa.w"

/*905:*/
#line 9912 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_DEV_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
MARPA_DEV_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:905*/
#line 9935 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:906*//*907:*/
#line 9939 "./marpa.w"

int marpa_b_and_node_predecessor(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 9943 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 9944 "./marpa.w"

/*905:*/
#line 9912 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_DEV_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
MARPA_DEV_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:905*/
#line 9945 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:907*//*908:*/
#line 9954 "./marpa.w"

int marpa_b_and_node_cause(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 9958 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 9959 "./marpa.w"

/*905:*/
#line 9912 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_DEV_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
MARPA_DEV_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:905*/
#line 9960 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:908*//*909:*/
#line 9969 "./marpa.w"

int marpa_b_and_node_symbol(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 9973 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 9974 "./marpa.w"

/*905:*/
#line 9912 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_DEV_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
MARPA_DEV_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:905*/
#line 9975 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:909*//*910:*/
#line 9984 "./marpa.w"

Marpa_Symbol_ID marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK token;
AND and_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 9990 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 9991 "./marpa.w"

/*905:*/
#line 9912 "./marpa.w"
{
AND and_nodes;
and_nodes= ANDs_of_B(b);
if(!and_nodes){
MARPA_DEV_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
MARPA_DEV_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:905*/
#line 9992 "./marpa.w"

token= and_node_token(and_node);
if(token){
if(value_p)
*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
return-1;
}
/*:910*//*911:*/
#line 10001 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:911*//*925:*/
#line 10065 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Rule_ID rule_id,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1160:*/
#line 12976 "./marpa.w"
void*const failure_indicator= NULL;
/*:1160*/
#line 10070 "./marpa.w"

/*926:*/
#line 10109 "./marpa.w"

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

/*:926*//*929:*/
#line 10133 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:929*/
#line 10071 "./marpa.w"

INPUT input;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10073 "./marpa.w"

/*1170:*/
#line 13027 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
MARPA_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1170*/
#line 10074 "./marpa.w"

b= my_slice_new(struct s_bocage);
/*855:*/
#line 9074 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;

/*:855*//*921:*/
#line 10044 "./marpa.w"

b->is_obstack_initialized= 1;
obstack_init(&OBS_of_B(b));
/*:921*//*945:*/
#line 10335 "./marpa.w"

b->t_ref_count= 1;

/*:945*/
#line 10076 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
r_update_earley_sets(r);
/*930:*/
#line 10136 "./marpa.w"

{
if(ordinal_arg==-1)
{
end_of_parse_earley_set= Current_ES_of_R(r);
}
else
{
if(!ES_Ord_is_Valid(r,ordinal_arg))
{
MARPA_DEV_ERROR("invalid es ordinal");
return failure_indicator;
}
end_of_parse_earley_set= ES_of_R_by_Ord(r,ordinal_arg);
}

if(!end_of_parse_earley_set)
goto B_NEW_RETURN_ERROR;
end_of_parse_earleme= Earleme_of_ES(end_of_parse_earley_set);
}

/*:930*/
#line 10085 "./marpa.w"

if(end_of_parse_earleme==0){
if(!g->t_null_start_rule)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
/*931:*/
#line 10157 "./marpa.w"

{
if(rule_id==-1)
{
completed_start_rule= g->t_proper_start_rule;
if(!completed_start_rule)goto B_NEW_RETURN_ERROR;
}
else
{
if(!RULEID_of_G_is_Valid(g,rule_id))
{
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
completed_start_rule= RULE_by_ID(g,rule_id);
}
}

/*:931*/
#line 10090 "./marpa.w"

/*937:*/
#line 10265 "./marpa.w"

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

/*:937*/
#line 10091 "./marpa.w"

if(!start_eim)goto B_NEW_RETURN_ERROR;
obstack_init(&bocage_setup_obs);
/*934:*/
#line 10213 "./marpa.w"

{
unsigned int ix;
unsigned int earley_set_count= ES_Count_of_R(r);
total_earley_items_in_parse= 0;
per_es_data= 
obstack_alloc(&bocage_setup_obs,
sizeof(struct s_bocage_setup_per_es)*earley_set_count);
for(ix= 0;ix<earley_set_count;ix++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,ix);
const unsigned int item_count= EIM_Count_of_ES(earley_set);
total_earley_items_in_parse+= item_count;
{
struct s_bocage_setup_per_es*per_es= per_es_data+ix;
OR**const per_eim_eixes= per_es->t_aexes_by_item= 
obstack_alloc(&bocage_setup_obs,sizeof(OR*)*item_count);
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

/*:934*/
#line 10094 "./marpa.w"

/*830:*/
#line 8675 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*831:*/
#line 8703 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:831*/
#line 8684 "./marpa.w"

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
/*833:*/
#line 8744 "./marpa.w"

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
/*831:*/
#line 8703 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:831*/
#line 8772 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:833*/
#line 8697 "./marpa.w"

/*835:*/
#line 8802 "./marpa.w"

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
/*831:*/
#line 8703 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:831*/
#line 8838 "./marpa.w"

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
/*831:*/
#line 8703 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:831*/
#line 8851 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:835*/
#line 8698 "./marpa.w"

/*836:*/
#line 8861 "./marpa.w"

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
/*831:*/
#line 8703 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:831*/
#line 8894 "./marpa.w"

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
/*831:*/
#line 8703 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:831*/
#line 8910 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:836*/
#line 8699 "./marpa.w"

}
}

/*:830*/
#line 10095 "./marpa.w"

/*857:*/
#line 9091 "./marpa.w"

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
/*1136:*/
#line 12738 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1136*/
#line 9111 "./marpa.w"

/*858:*/
#line 9119 "./marpa.w"

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
/*859:*/
#line 9139 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1136:*/
#line 12738 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1136*/
#line 9149 "./marpa.w"

/*861:*/
#line 9167 "./marpa.w"

{
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const RULE rule= RULE_of_AIM(ahfa_item);
/*862:*/
#line 9196 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
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


/*:862*/
#line 9177 "./marpa.w"

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

/*:861*/
#line 9150 "./marpa.w"

/*864:*/
#line 9221 "./marpa.w"

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
/*862:*/
#line 9196 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
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


/*:862*/
#line 9240 "./marpa.w"

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

/*:864*/
#line 9151 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*865:*/
#line 9258 "./marpa.w"
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
/*867:*/
#line 9298 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const int symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*870:*/
#line 9339 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1136:*/
#line 12738 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1136*/
#line 9346 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*862:*/
#line 9196 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
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


/*:862*/
#line 9350 "./marpa.w"

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

/*:870*/
#line 9308 "./marpa.w"

/*871:*/
#line 9366 "./marpa.w"

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
/*862:*/
#line 9196 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
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


/*:862*/
#line 9383 "./marpa.w"

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

/*:871*/
#line 9309 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:867*/
#line 9280 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:865*/
#line 9159 "./marpa.w"

}

/*:859*/
#line 9133 "./marpa.w"

}
}
}
}

/*:858*/
#line 9112 "./marpa.w"

/*878:*/
#line 9476 "./marpa.w"

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
/*880:*/
#line 9513 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const int work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*881:*/
#line 9529 "./marpa.w"
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
/*882:*/
#line 9561 "./marpa.w"

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
/*883:*/
#line 9590 "./marpa.w"

{
if(higher_path_leo_item){
/*887:*/
#line 9634 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:887*/
#line 9593 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:883*/
#line 9576 "./marpa.w"

/*885:*/
#line 9604 "./marpa.w"

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

/*:885*/
#line 9577 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*883:*/
#line 9590 "./marpa.w"

{
if(higher_path_leo_item){
/*887:*/
#line 9634 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:887*/
#line 9593 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:883*/
#line 9584 "./marpa.w"

/*888:*/
#line 9644 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const int origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:888*/
#line 9585 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:882*/
#line 9551 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:881*/
#line 9524 "./marpa.w"

/*889:*/
#line 9654 "./marpa.w"

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
/*890:*/
#line 9684 "./marpa.w"

{
OR dand_predecessor;
/*891:*/
#line 9692 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:891*/
#line 9687 "./marpa.w"

draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:890*/
#line 9676 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:889*/
#line 9525 "./marpa.w"

/*892:*/
#line 9703 "./marpa.w"

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
/*893:*/
#line 9743 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*891:*/
#line 9692 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:891*/
#line 9751 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:893*/
#line 9734 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:892*/
#line 9526 "./marpa.w"

}

/*:880*/
#line 9491 "./marpa.w"

}
}
}
}
}

/*:878*/
#line 9113 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= my_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:857*/
#line 10096 "./marpa.w"

/*901:*/
#line 9858 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*894:*/
#line 9757 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
int or_node_id= 0;
psar_init(and_psar,rule_count_of_g+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*896:*/
#line 9789 "./marpa.w"

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

/*:896*/
#line 9767 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:894*/
#line 9861 "./marpa.w"

/*902:*/
#line 9865 "./marpa.w"

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

/*:902*/
#line 9862 "./marpa.w"

}

/*:901*/
#line 10097 "./marpa.w"

/*938:*/
#line 10293 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:938*/
#line 10098 "./marpa.w"
;
obstack_free(&bocage_setup_obs,NULL);
return b;
B_NEW_RETURN_ERROR:;
input_unref(input);
if(b){
/*948:*/
#line 10372 "./marpa.w"

/*856:*/
#line 9080 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:856*/
#line 10373 "./marpa.w"
;
/*922:*/
#line 10047 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:922*/
#line 10374 "./marpa.w"
;

/*:948*/
#line 10104 "./marpa.w"
;
}
return NULL;
}

/*:925*//*933:*/
#line 10180 "./marpa.w"

PRIVATE_NOT_INLINE BOCAGE r_create_null_bocage(RECCE r,BOCAGE b)
{
const GRAMMAR g= G_of_R(r);
const RULE null_start_rule= g->t_null_start_rule;
int rule_length= Length_of_RULE(g->t_null_start_rule);
OR*or_nodes= ORs_of_B(b)= my_new(OR,1);
AND and_nodes= ANDs_of_B(b)= my_new(AND_Object,1);
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
(OR)TOK_by_SYMID(RHS_ID_of_RULE(null_start_rule,rule_length-1));

return b;
}

/*:933*//*940:*/
#line 10316 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10319 "./marpa.w"

return g;
}

/*:940*//*942:*/
#line 10324 "./marpa.w"

Marpa_Or_Node_ID marpa_b_top_or_node(Marpa_Bocage b)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10327 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10328 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10329 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:942*//*946:*/
#line 10339 "./marpa.w"

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

/*:946*//*947:*/
#line 10357 "./marpa.w"

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

/*:947*//*949:*/
#line 10379 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10383 "./marpa.w"

input_unref(input);
if(b)
{
/*948:*/
#line 10372 "./marpa.w"

/*856:*/
#line 9080 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:856*/
#line 10373 "./marpa.w"
;
/*922:*/
#line 10047 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:922*/
#line 10374 "./marpa.w"
;

/*:948*/
#line 10387 "./marpa.w"
;
my_slice_free(struct s_bocage,b);
}
}

/*:949*//*952:*/
#line 10412 "./marpa.w"

int marpa_b_or_node_set(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10416 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10417 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10418 "./marpa.w"

/*951:*/
#line 10395 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_DEV_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
MARPA_DEV_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:951*/
#line 10419 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:952*//*953:*/
#line 10423 "./marpa.w"

int marpa_b_or_node_origin(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10427 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10428 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10429 "./marpa.w"

/*951:*/
#line 10395 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_DEV_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
MARPA_DEV_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:951*/
#line 10430 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:953*//*954:*/
#line 10434 "./marpa.w"

int marpa_b_or_node_rule(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10438 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10439 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10440 "./marpa.w"

/*951:*/
#line 10395 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_DEV_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
MARPA_DEV_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:951*/
#line 10441 "./marpa.w"

return ID_of_RULE(RULE_of_OR(or_node));
}

/*:954*//*955:*/
#line 10445 "./marpa.w"

int marpa_b_or_node_position(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10449 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10450 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10451 "./marpa.w"

/*951:*/
#line 10395 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_DEV_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
MARPA_DEV_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:951*/
#line 10452 "./marpa.w"

return Position_of_OR(or_node);
}

/*:955*//*956:*/
#line 10456 "./marpa.w"

int marpa_b_or_node_first_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10460 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10461 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10462 "./marpa.w"

/*951:*/
#line 10395 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_DEV_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
MARPA_DEV_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:951*/
#line 10463 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:956*//*957:*/
#line 10467 "./marpa.w"

int marpa_b_or_node_last_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10471 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10472 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10473 "./marpa.w"

/*951:*/
#line 10395 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_DEV_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
MARPA_DEV_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:951*/
#line 10474 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:957*//*958:*/
#line 10479 "./marpa.w"

int marpa_b_or_node_and_count(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10483 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10484 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10485 "./marpa.w"

/*951:*/
#line 10395 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_DEV_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
MARPA_DEV_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:951*/
#line 10486 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:958*//*965:*/
#line 10527 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1160:*/
#line 12976 "./marpa.w"
void*const failure_indicator= NULL;
/*:1160*/
#line 10530 "./marpa.w"

/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10531 "./marpa.w"

ORDER o;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10533 "./marpa.w"

o= my_slice_new(struct s_order);
B_of_O(o)= b;
bocage_ref(b);
/*962:*/
#line 10515 "./marpa.w"

{
o->t_and_node_in_use= NULL;
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
}

/*:962*//*968:*/
#line 10543 "./marpa.w"

o->t_ref_count= 1;

/*:968*/
#line 10537 "./marpa.w"

return o;
}

/*:965*//*969:*/
#line 10547 "./marpa.w"

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

/*:969*//*970:*/
#line 10565 "./marpa.w"

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

/*:970*//*971:*/
#line 10579 "./marpa.w"

PRIVATE void order_strip(ORDER o)
{
if(o->t_and_node_in_use)
{
bv_free(o->t_and_node_in_use);
o->t_and_node_in_use= NULL;
}
}
/*:971*//*972:*/
#line 10588 "./marpa.w"

PRIVATE void order_freeze(ORDER o)
{
order_strip(o);
O_is_Frozen(o)= 0;
}
/*:972*//*973:*/
#line 10594 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10597 "./marpa.w"

bocage_unref(b);
order_strip(o);
if(o->t_and_node_orderings){
o->t_and_node_orderings= NULL;
obstack_free(&OBS_of_O(o),NULL);
}
my_slice_free(struct s_order,o);
}

/*:973*//*976:*/
#line 10623 "./marpa.w"

Marpa_Grammar marpa_o_g(Marpa_Order o)
{
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10626 "./marpa.w"

return g;
}

/*:976*//*980:*/
#line 10679 "./marpa.w"

int marpa_o_and_order_set(
Marpa_Order o,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
int length)
{
OR or_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10687 "./marpa.w"

/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10688 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10689 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*951:*/
#line 10395 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_DEV_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
MARPA_DEV_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:951*/
#line 10695 "./marpa.w"

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
obstack_init(obs);
o->t_and_node_orderings= 
and_node_orderings= 
obstack_alloc(obs,sizeof(ANDID*)*and_count_of_r);
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
MARPA_DEV_ERROR("and node not in or node");
return failure_indicator;
}
if(bv_bit_test(and_node_in_use,(unsigned int)and_node_id))
{
MARPA_DEV_ERROR("dup and node");
return failure_indicator;
}
bv_bit_set(and_node_in_use,(unsigned int)and_node_id);
}
}
if(and_node_orderings[or_node_id]){
MARPA_DEV_ERROR("or node already ordered");
return failure_indicator;
}
{
ANDID*orderings= obstack_alloc(obs,sizeof(ANDID)*(length+1));
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

/*:980*//*981:*/
#line 10759 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,int ix)
{
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10762 "./marpa.w"

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

/*:981*//*982:*/
#line 10784 "./marpa.w"

Marpa_And_Node_ID marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 10789 "./marpa.w"

/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10790 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10791 "./marpa.w"

/*951:*/
#line 10395 "./marpa.w"
{
OR*or_nodes;
or_nodes= ORs_of_B(b);
if(!or_nodes){
MARPA_DEV_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
MARPA_DEV_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:951*/
#line 10792 "./marpa.w"

if(ix<0){
MARPA_DEV_ERROR("negative and ix");
return failure_indicator;
}
return and_order_get(o,or_node,ix);
}

/*:982*//*987:*/
#line 10845 "./marpa.w"

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

/*:987*//*988:*/
#line 10864 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1160:*/
#line 12976 "./marpa.w"
void*const failure_indicator= NULL;
/*:1160*/
#line 10867 "./marpa.w"

TREE t;
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10869 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 10870 "./marpa.w"

t= my_slice_new(struct s_tree);
O_of_T(t)= o;
order_ref(o);
order_freeze(o);
/*989:*/
#line 10879 "./marpa.w"

{
const int and_count= AND_Count_of_B(b);
t->t_parse_count= 0;
t->t_and_node_in_use= bv_create((unsigned int)and_count);
FSTACK_INIT(t->t_nook_stack,NOOK_Object,and_count);
FSTACK_INIT(t->t_nook_worklist,int,and_count);
}

/*:989*//*992:*/
#line 10891 "./marpa.w"

t->t_ref_count= 1;

/*:992*//*999:*/
#line 10970 "./marpa.w"
t->t_pause_counter= 0;
/*:999*/
#line 10875 "./marpa.w"

return t;
}

/*:988*//*993:*/
#line 10895 "./marpa.w"

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

/*:993*//*994:*/
#line 10913 "./marpa.w"

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

/*:994*//*995:*/
#line 10927 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_slice_free(struct s_tree,t);
}

/*:995*//*1000:*/
#line 10971 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1000*//*1001:*/
#line 10980 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1001*//*1003:*/
#line 11002 "./marpa.w"

Marpa_Grammar marpa_t_g(Marpa_Tree t)
{
/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11005 "./marpa.w"

return g;
}

/*:1003*//*1004:*/
#line 11009 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11012 "./marpa.w"

int is_first_tree_attempt= 0;
/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11014 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11015 "./marpa.w"

if(T_is_Paused(t)){
MARPA_DEV_ERROR("tree is paused");
return failure_indicator;
}
if(T_is_Exhausted(t))
{
return-1;
}

if(t->t_parse_count<1)
{
is_first_tree_attempt= 1;
/*1009:*/
#line 11073 "./marpa.w"

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

/*:1009*/
#line 11028 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
}else{
/*1010:*/
#line 11098 "./marpa.w"
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

/*:1010*/
#line 11035 "./marpa.w"

}
/*1011:*/
#line 11150 "./marpa.w"
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
/*1013:*/
#line 11211 "./marpa.w"

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

/*:1013*/
#line 11192 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1011*/
#line 11037 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return-1;

}

/*:1004*//*1006:*/
#line 11053 "./marpa.w"

PRIVATE void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:1006*//*1007:*/
#line 11059 "./marpa.w"

PRIVATE void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:1007*//*1008:*/
#line 11067 "./marpa.w"

PRIVATE int tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}

/*:1008*//*1012:*/
#line 11198 "./marpa.w"

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

/*:1012*//*1014:*/
#line 11229 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1014*//*1015:*/
#line 11237 "./marpa.w"

int marpa_t_size(Marpa_Tree t)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11240 "./marpa.w"

/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11241 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11242 "./marpa.w"

if(T_is_Exhausted(t)){
return-1;
}
return Size_of_T(t);
}

/*:1015*//*1022:*/
#line 11300 "./marpa.w"

int marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11304 "./marpa.w"

/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11305 "./marpa.w"

/*1021:*/
#line 11282 "./marpa.w"
{
NOOK base_nook;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11284 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1021*/
#line 11306 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1022*//*1023:*/
#line 11310 "./marpa.w"

int marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11314 "./marpa.w"

/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11315 "./marpa.w"

/*1021:*/
#line 11282 "./marpa.w"
{
NOOK base_nook;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11284 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1021*/
#line 11316 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1023*//*1024:*/
#line 11320 "./marpa.w"

int marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11324 "./marpa.w"

/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11325 "./marpa.w"

/*1021:*/
#line 11282 "./marpa.w"
{
NOOK base_nook;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11284 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1021*/
#line 11326 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1024*//*1025:*/
#line 11330 "./marpa.w"

int marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11334 "./marpa.w"

/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11335 "./marpa.w"

/*1021:*/
#line 11282 "./marpa.w"
{
NOOK base_nook;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11284 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1021*/
#line 11336 "./marpa.w"

return NOOK_Cause_is_Ready(nook);
}

/*:1025*//*1026:*/
#line 11340 "./marpa.w"

int marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11344 "./marpa.w"

/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11345 "./marpa.w"

/*1021:*/
#line 11282 "./marpa.w"
{
NOOK base_nook;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11284 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1021*/
#line 11346 "./marpa.w"

return NOOK_Predecessor_is_Ready(nook);
}

/*:1026*//*1027:*/
#line 11350 "./marpa.w"

int marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11354 "./marpa.w"

/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11355 "./marpa.w"

/*1021:*/
#line 11282 "./marpa.w"
{
NOOK base_nook;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11284 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1021*/
#line 11356 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1027*//*1028:*/
#line 11360 "./marpa.w"

int marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11364 "./marpa.w"

/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11365 "./marpa.w"

/*1021:*/
#line 11282 "./marpa.w"
{
NOOK base_nook;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11284 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1021*/
#line 11366 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1028*//*1037:*/
#line 11492 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1160:*/
#line 12976 "./marpa.w"
void*const failure_indicator= NULL;
/*:1160*/
#line 11495 "./marpa.w"

/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11496 "./marpa.w"
;
/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11497 "./marpa.w"

if(!T_is_Exhausted(t))
{
VALUE v= my_slice_new(struct s_value);
const int minimum_stack_size= (8192/sizeof(int));
const int initial_stack_size= 
MAX(Size_of_TREE(t)/1024,minimum_stack_size);
DSTACK_INIT(VStack_of_V(v),int,initial_stack_size);
/*1038:*/
#line 11520 "./marpa.w"

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

/*:1038*/
#line 11505 "./marpa.w"

Next_Value_Type_of_V(v)= V_GET_DATA;
V_is_Trace(v)= 1;
TOS_of_V(v)= -1;
NOOK_of_V(v)= -1;
/*1041:*/
#line 11537 "./marpa.w"

v->t_ref_count= 1;

/*:1041*/
#line 11510 "./marpa.w"

tree_pause(t);
T_of_V(v)= t;
return v;
}
MARPA_DEV_ERROR("tree is exhausted");
return NULL;
}

/*:1037*//*1042:*/
#line 11541 "./marpa.w"

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

/*:1042*//*1043:*/
#line 11559 "./marpa.w"

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

/*:1043*//*1044:*/
#line 11573 "./marpa.w"

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

/*:1044*//*1046:*/
#line 11590 "./marpa.w"

Marpa_Grammar marpa_v_g(Marpa_Value v)
{
/*1045:*/
#line 11585 "./marpa.w"

TREE t= T_of_V(v);
/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11587 "./marpa.w"


/*:1045*/
#line 11593 "./marpa.w"

return g;
}

/*:1046*//*1047:*/
#line 11597 "./marpa.w"

int marpa_v_trace(Marpa_Value v,int flag)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11600 "./marpa.w"

/*1045:*/
#line 11585 "./marpa.w"

TREE t= T_of_V(v);
/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11587 "./marpa.w"


/*:1045*/
#line 11601 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11602 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1047*//*1048:*/
#line 11610 "./marpa.w"

Marpa_Nook_ID marpa_v_nook(Marpa_Value v)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11613 "./marpa.w"

/*1045:*/
#line 11585 "./marpa.w"

TREE t= T_of_V(v);
/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11587 "./marpa.w"


/*:1045*/
#line 11614 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11615 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1048*//*1050:*/
#line 11625 "./marpa.w"

int marpa_v_symbol_is_ask_me_when_null(
Marpa_Value v,
Marpa_Symbol_ID symid)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11630 "./marpa.w"

/*1045:*/
#line 11585 "./marpa.w"

TREE t= T_of_V(v);
/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11587 "./marpa.w"


/*:1045*/
#line 11631 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11632 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 11633 "./marpa.w"

return bv_bit_test(Nulling_Ask_BV_of_V(v),symid);
}
/*:1050*//*1051:*/
#line 11646 "./marpa.w"

int marpa_v_symbol_ask_me_when_null_set(
Marpa_Value v,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11651 "./marpa.w"

/*1045:*/
#line 11585 "./marpa.w"

TREE t= T_of_V(v);
/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11587 "./marpa.w"


/*:1045*/
#line 11652 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11653 "./marpa.w"

/*1164:*/
#line 12994 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1164*/
#line 11654 "./marpa.w"

symbol= SYM_by_ID(symid);
if(!SYM_is_Nulling(symbol)){
symbol= symbol_null_alias(symbol);
if(!symbol&&value){
MARPA_ERROR(MARPA_ERR_SYMBOL_NOT_NULLABLE);
}
}
if(value){
bv_bit_set(Nulling_Ask_BV_of_V(v),symid);
}else{
bv_bit_clear(Nulling_Ask_BV_of_V(v),symid);
}
return value?1:0;
}

/*:1051*//*1053:*/
#line 11676 "./marpa.w"

Marpa_Value_Type marpa_v_step(Marpa_Value v)
{
/*1161:*/
#line 12979 "./marpa.w"
const int failure_indicator= -2;

/*:1161*/
#line 11679 "./marpa.w"


while(V_is_Active(v)){
Marpa_Value_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case V_GET_DATA:
/*1054:*/
#line 11723 "./marpa.w"

{
AND and_nodes;
/*1045:*/
#line 11585 "./marpa.w"

TREE t= T_of_V(v);
/*986:*/
#line 10841 "./marpa.w"

ORDER o= O_of_T(t);
/*974:*/
#line 10607 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*918:*/
#line 10033 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:918*/
#line 10609 "./marpa.w"


/*:974*/
#line 10843 "./marpa.w"
;

/*:986*/
#line 11587 "./marpa.w"


/*:1045*/
#line 11726 "./marpa.w"

/*1173:*/
#line 13042 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1173*/
#line 11727 "./marpa.w"

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

/*:1054*/
#line 11686 "./marpa.w"

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

/*:1053*//*1057:*/
#line 11840 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(unsigned int bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1057*//*1058:*/
#line 11846 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(unsigned int bits)
{
unsigned int mask= bits&bv_modmask;
if(mask)mask= (unsigned int)~(~0uL<<mask);else mask= (unsigned int)~0uL;
return(mask);
}

/*:1058*//*1060:*/
#line 11860 "./marpa.w"

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

/*:1060*//*1062:*/
#line 11878 "./marpa.w"

PRIVATE Bit_Vector
bv_obs_create(struct obstack*obs,unsigned int bits)
{
unsigned int size= bv_bits_to_size(bits);
unsigned int bytes= (size+bv_hiddenwords)<<sizeof(unsigned int);
unsigned int*addr= (Bit_Vector)obstack_alloc(obs,(size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
if(size> 0){
Bit_Vector bv= addr;
while(size--)*bv++= 0u;
}
return addr;
}


/*:1062*//*1063:*/
#line 11899 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}

/*:1063*//*1064:*/
#line 11909 "./marpa.w"

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

/*:1064*//*1065:*/
#line 11927 "./marpa.w"

PRIVATE
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}

/*:1065*//*1066:*/
#line 11935 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
vector-= bv_hiddenwords;
my_free(vector);
}

/*:1066*//*1067:*/
#line 11943 "./marpa.w"

PRIVATE int bv_bytes(Bit_Vector bv)
{
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}

/*:1067*//*1068:*/
#line 11950 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1068*//*1069:*/
#line 11961 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1069*//*1071:*/
#line 11975 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,unsigned int bit)
{
unsigned int length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1071*//*1073:*/
#line 11983 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1073*//*1074:*/
#line 11990 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1074*//*1075:*/
#line 11997 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,unsigned int bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1075*//*1076:*/
#line 12005 "./marpa.w"

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

/*:1076*//*1077:*/
#line 12018 "./marpa.w"

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

/*:1077*//*1078:*/
#line 12032 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1078*//*1079:*/
#line 12042 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1079*//*1080:*/
#line 12052 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1080*//*1081:*/
#line 12062 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1081*//*1082:*/
#line 12072 "./marpa.w"

PRIVATE
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

/*:1082*//*1083:*/
#line 12144 "./marpa.w"

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

/*:1083*//*1088:*/
#line 12196 "./marpa.w"

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

/*:1088*//*1092:*/
#line 12274 "./marpa.w"

PRIVATE Bit_Matrix matrix_create(unsigned int rows,unsigned int columns)
{
unsigned int bv_data_words= bv_bits_to_size(columns);
unsigned int row_bytes= (bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
unsigned int bv_mask= bv_bits_to_unused_mask(columns);
Bit_Vector_Word*matrix_addr= my_malloc0((size_t)(row_bytes*rows));
unsigned int row;
for(row= 0;row<rows;row++){
unsigned int row_start= row*(bv_data_words+bv_hiddenwords);
matrix_addr[row_start]= columns;
matrix_addr[row_start+1]= bv_data_words;
matrix_addr[row_start+2]= bv_mask;
}
return matrix_addr;
}

/*:1092*//*1093:*/
#line 12292 "./marpa.w"

PRIVATE void matrix_free(Bit_Matrix matrix)
{
my_free(matrix);
}

/*:1093*//*1094:*/
#line 12304 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1094*//*1095:*/
#line 12320 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,unsigned int row)
{
Bit_Vector row0= matrix+bv_hiddenwords;
unsigned int words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1095*//*1097:*/
#line 12329 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1097*//*1099:*/
#line 12337 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1099*//*1101:*/
#line 12345 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1101*//*1102:*/
#line 12358 "./marpa.w"

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

/*:1102*//*1111:*/
#line 12500 "./marpa.w"

PRIVATE void*dstack_resize(struct s_dstack*this,size_t type_bytes)
{
this->t_capacity*= 2;
this->t_base= my_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}

/*:1111*//*1126:*/
#line 12639 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1126*//*1127:*/
#line 12646 "./marpa.w"

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
/*:1127*//*1128:*/
#line 12660 "./marpa.w"

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
/*:1128*//*1131:*/
#line 12691 "./marpa.w"

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

/*:1131*//*1133:*/
#line 12709 "./marpa.w"

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

/*:1133*//*1135:*/
#line 12729 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1135*//*1137:*/
#line 12753 "./marpa.w"

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

/*:1137*//*1140:*/
#line 12777 "./marpa.w"

PRIVATE_NOT_INLINE void
default_out_of_memory(void)
{
(*marpa_debug_handler)("Out of memory");
abort();
}
void(*marpa_out_of_memory)(void)= default_out_of_memory;

/*:1140*//*1148:*/
#line 12869 "./marpa.w"

PRIVATE void*
my_malloc(size_t size)
{
void*newmem= malloc(size);
if(!newmem)(*marpa_out_of_memory)();
return newmem;
}
/*:1148*//*1150:*/
#line 12879 "./marpa.w"

extern void*
marpa_avl_malloc(struct libavl_allocator*alloc UNUSED,size_t size);
void*
marpa_avl_malloc(struct libavl_allocator*alloc UNUSED,size_t size)
{
return my_malloc(size);
}
extern void
marpa_avl_free(struct libavl_allocator*alloc UNUSED,void*p);
void
marpa_avl_free(struct libavl_allocator*alloc UNUSED,void*p)
{
my_free(p);
}

/*:1150*//*1151:*/
#line 12895 "./marpa.w"

PRIVATE void*
my_malloc0(size_t size)
{
void*newmem= my_malloc(size);
memset(newmem,0,size);
return newmem;
}

/*:1151*//*1152:*/
#line 12904 "./marpa.w"

PRIVATE void*
my_realloc(void*mem,size_t size)
{
void*newmem;
if(!mem)return my_malloc(size);
newmem= realloc(mem,size);
if(!newmem)(*marpa_out_of_memory)();
return newmem;
}

/*:1152*//*1177:*/
#line 13092 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(struct marpa_g*g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}

/*:1177*//*1181:*/
#line 13164 "./marpa.w"

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

/*:1181*//*1184:*/
#line 13186 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
marpa_debug_handler= debug_handler;
}

/*:1184*//*1186:*/
#line 13194 "./marpa.w"

void marpa_debug_level_set(int level)
{
marpa_debug_level= level;
}

/*:1186*/
#line 13411 "./marpa.w"


/*:1201*/
