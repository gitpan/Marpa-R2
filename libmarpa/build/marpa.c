/*1231:*/
#line 13923 "./marpa.w"

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

/*:1231*//*1232:*/
#line 13946 "./marpa.w"

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

#include "marpa_util.h"
#define PRIVATE_NOT_INLINE static
#define PRIVATE static inline \

#define XSY_Count_of_G(g) (DSTACK_LENGTH((g) ->t_xsy_stack) ) 
#define SYM_Count_of_G(g) XSY_Count_of_G(g) 
#define ISY_Count_of_G(g) (DSTACK_LENGTH((g) ->t_isy_stack) ) 
#define XSY_by_ID(id) (*DSTACK_INDEX(g->t_xsy_stack,XSY,(id) ) ) 
#define ISY_by_ID(id) (*DSTACK_INDEX(g->t_isy_stack,ISY,(id) ) ) 
#define SYM_by_ID(id) XSY_by_ID(id)  \

#define XRL_Count_of_G(g) (DSTACK_LENGTH((g) ->t_xrl_stack) ) 
#define IRL_Count_of_G(g) (DSTACK_LENGTH((g) ->t_irl_stack) ) 
#define XRL_by_ID(id) (*DSTACK_INDEX((g) ->t_xrl_stack,XRL,(id) ) ) 
#define IRL_by_ID(id) (*DSTACK_INDEX((g) ->t_irl_stack,IRL,(id) ) ) 
#define RULE_by_ID(g,id) (XRL_by_ID(id) )  \

#define XRLID_of_G_is_Valid(rule_id)  \
((rule_id) >=0&&(rule_id) <XRL_Count_of_G(g) ) 
#define IRLID_of_G_is_Valid(irl_id)  \
((irl_id) >=0&&(irl_id) <IRL_Count_of_G(g) ) 
#define RULEID_of_G_is_Valid(g,rule_id) XRLID_of_G_is_Valid(rule_id)  \

#define G_is_Trivial(g) (!(g) ->t_start_irl) 
#define External_Size_of_G(g) ((g) ->t_external_size) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define G_EVENT_COUNT(g) DSTACK_LENGTH((g) ->t_events) 
#define INITIAL_G_EVENTS_CAPACITY 1
#define G_EVENTS_CLEAR(g) DSTACK_CLEAR((g) ->t_events) 
#define G_EVENT_PUSH(g) DSTACK_PUSH((g) ->t_events,GEV_Object) 
#define I_AM_OK 0x69734f4b
#define IS_G_OK(g) ((g) ->t_is_ok==I_AM_OK) 
#define ID_of_XSY(xsy) ((xsy) ->t_symbol_id) 
#define ID_of_SYM(sym) ID_of_XSY(sym)  \

#define XSY_is_LHS(xsy) ((xsy) ->t_is_lhs) 
#define SYM_is_LHS(symbol) XSY_is_LHS(symbol) 
#define SYM_is_Sequence_LHS(symbol) ((symbol) ->t_is_sequence_lhs) 
#define SYM_is_Semantic(symbol) ((symbol) ->t_is_semantic) 
#define SYM_is_Ask_Me_When_Null(symbol) ((symbol) ->t_is_ask_me_when_null) 
#define XSY_is_Accessible(xsy) ((xsy) ->t_is_accessible) 
#define SYM_is_Accessible(sym) XSY_is_Accessible(sym) 
#define XSY_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define SYM_is_Nulling(sym) XSY_is_Nulling(sym) 
#define XSY_is_Nullable(sym) ((sym) ->t_is_nullable) 
#define SYM_is_Nullable(sym) XSY_is_Nullable(sym) 
#define SYM_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
#define SYM_is_Marked_Terminal(symbol) ((symbol) ->t_is_marked_terminal) 
#define SYMID_is_Terminal(id) (SYM_is_Terminal(SYM_by_ID(id) ) ) 
#define XSY_is_Productive(xsy) ((xsy) ->t_is_productive) 
#define SYM_is_Productive(xsy) XSY_is_Productive(xsy) 
#define Source_XSY_of_ISY(isy) (Buddy_of_ISY(isy) ->t_source_xsy) 
#define Source_XSY_of_SYM(symbol) ((symbol) ->t_source_xsy) 
#define Buddy_of_ISY(isy) ((isy) ->t_buddy) 
#define ID_of_ISY(isy) ((isy) ->t_isy_id) 
#define ISY_is_Nulling(isy) ((isy) ->t_is_nulling) 
#define LHS_XRL_of_SYM(sym) ((sym) ->t_lhs_xrl) 
#define XRL_Offset_of_SYM(sym) ((sym) ->t_xrl_offset) 
#define MAX_RHS_LENGTH (INT_MAX>>(2) ) 
#define Length_of_RULE(rule) ((rule) ->t_rhs_length) 
#define Length_of_XRL(xrl) ((xrl) ->t_rhs_length) 
#define LHS_ID_of_RULE(rule) ((rule) ->t_symbols[0]) 
#define LHS_ID_of_XRL(xrl) ((xrl) ->t_symbols[0]) 
#define RHS_ID_of_RULE(rule,position)  \
((rule) ->t_symbols[(position) +1]) 
#define RHS_ID_of_XRL(xrl,position)  \
((xrl) ->t_symbols[(position) +1])  \

#define ID_of_XRL(xrl) ((xrl) ->t_id) 
#define ID_of_RULE(rule) ID_of_XRL(rule) 
#define XRL_is_BNF(rule) ((rule) ->t_is_bnf) 
#define XRL_is_Sequence(rule) ((rule) ->t_is_sequence) 
#define Minimum_of_XRL(rule) ((rule) ->t_minimum) 
#define Separator_of_XRL(rule) ((rule) ->t_separator_id) 
#define XRL_is_Proper_Separation(rule) ((rule) ->t_is_proper_separation) 
#define XRL_is_Nulling(rule) ((rule) ->t_is_nulling) 
#define XRL_is_Accessible(rule) ((rule) ->t_is_accessible) 
#define XRL_is_Productive(rule) ((rule) ->t_is_productive) 
#define XRL_is_Used(xrl) ( \
XRL_is_Accessible(xrl) &&XRL_is_Productive(xrl) &&!XRL_is_Nulling(xrl)  \
) 
#define RULE_has_Virtual_LHS(rule) ((rule) ->t_is_virtual_lhs) 
#define IRL_has_Virtual_LHS(irl) RULE_has_Virtual_LHS(Co_RULE_of_IRL(irl) ) 
#define RULE_has_Virtual_RHS(rule) ((rule) ->t_is_virtual_rhs) 
#define IRL_has_Virtual_RHS(irl) RULE_has_Virtual_RHS(Co_RULE_of_IRL(irl) ) 
#define Virtual_Start_of_IRL(irl) (Co_RULE_of_IRL(irl) ->t_virtual_start) 
#define Virtual_End_of_IRL(irl) (Co_RULE_of_IRL(irl) ->t_virtual_end) 
#define Source_XRL_of_IRL(irl) (Co_RULE_of_IRL(irl) ->t_source_xrl) 
#define Source_XRL_of_RULE(rule) ((rule) ->t_source_xrl) 
#define Real_SYM_Count_of_RULE(rule) ((rule) ->t_real_symbol_count) 
#define Real_SYM_Count_of_IRL(irl) Real_SYM_Count_of_RULE(Co_RULE_of_IRL(irl) ) 
#define XRL_is_Ask_Me(rule) ((rule) ->t_is_ask_me) 
#define Co_RULE_of_IRL(irl) ((irl) ->t_co_rule) 
#define ID_of_IRL(irl) ((irl) ->t_irl_id) 
#define LHS_ID_of_IRL(irl) LHS_ID_of_RULE(Co_RULE_of_IRL(irl) ) 
#define RHS_ID_of_IRL(irl,position) RHS_ID_of_RULE(Co_RULE_of_IRL(irl) ,(position) ) 
#define Length_of_IRL(irl) Length_of_RULE(Co_RULE_of_IRL(irl) ) 
#define SYMI_Count_of_G(g) ((g) ->t_symbol_instance_count) 
#define SYMI_of_RULE(rule) ((rule) ->t_symbol_instance_base) 
#define SYMI_of_IRL(irl) SYMI_of_RULE(Co_RULE_of_IRL(irl) ) 
#define Last_Proper_SYMI_of_RULE(rule) ((rule) ->t_last_proper_symi) 
#define SYMI_of_Completed_RULE(rule)  \
(SYMI_of_RULE(rule) +Length_of_RULE(rule) -1) 
#define SYMI_of_AIM(aim) (symbol_instance_of_ahfa_item_get(aim) ) 
#define Sort_Key_of_AIM(aim) ((aim) ->t_sort_key) 
#define Next_AIM_of_AIM(aim) ((aim) +1) 
#define AIM_by_ID(id) (g->t_AHFA_items+(id) ) 
#define AIM_Count_of_G(g) ((g) ->t_aim_count) 
#define IRL_of_AIM(aim) ((aim) ->t_irl) 
#define RULE_of_AIM(aim) Co_RULE_of_IRL(IRL_of_AIM(aim) ) 
#define IRLID_of_AIM(item) ID_of_IRL(IRL_of_AIM(item) ) 
#define LHS_ID_of_AIM(item) LHS_ID_of_RULE(RULE_of_AIM(item) ) 
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
#define SET_1ST_PASS_SORT_KEY_FOR_IRL(sort_key,irl) { \
const XRL xrl= Co_RULE_of_IRL(irl) ; \
const AIM aim= xrl->t_first_aim; \
(sort_key) = Postdot_SYMID_of_AIM(aim) ; \
} \

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
#define RULE_of_OR(or) Co_RULE_of_IRL(IRL_of_OR(or) ) 
#define IRL_of_OR(or) ((or) ->t_final.t_irl) 
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
#define WHEID_of_SYMID(symid) (irl_count+(symid) ) 
#define WHEID_of_IRLID(irlid) (irlid) 
#define WHEID_of_IRL(irl) WHEID_of_IRLID(ID_of_IRL(irl) ) 
#define WHEID_of_OR(or) ( \
wheid= OR_is_Token(or) ? \
WHEID_of_SYMID(SYMID_of_OR(or) ) : \
WHEID_of_IRL(IRL_of_OR(or) )  \
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
#define B_is_Nulling(b) ((b) ->t_is_nulling) 
#define OBS_of_O(order) ((order) ->t_obs) 
#define O_is_Frozen(o) ((o) ->t_is_frozen) 
#define B_of_O(b) ((b) ->t_bocage) 
#define O_is_Nulling(o) ((o) ->t_is_nulling) 
#define Size_of_TREE(tree) FSTACK_LENGTH((tree) ->t_nook_stack) 
#define NOOK_of_TREE_by_IX(tree,nook_id)  \
FSTACK_INDEX((tree) ->t_nook_stack,NOOK_Object,nook_id) 
#define O_of_T(t) ((t) ->t_order) 
#define T_is_Paused(t) ((t) ->t_pause_counter> 0) 
#define T_is_Exhausted(t) ((t) ->t_is_exhausted) 
#define T_is_Nulling(t) ((t) ->t_is_nulling) 
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
#define T_of_V(v) ((v) ->t_tree) 
#define SYMID_of_V(val) ((val) ->public.t_semantic_token_id) 
#define RULEID_of_V(val) ((val) ->public.t_semantic_rule_id) 
#define Token_Value_of_V(val) ((val) ->public.t_token_value) 
#define Token_Type_of_V(val) ((val) ->t_token_type) 
#define TOS_of_V(val) ((val) ->public.t_tos) 
#define Arg_N_of_V(val) ((val) ->public.t_arg_n) 
#define VStack_of_V(val) ((val) ->t_virtual_stack) 
#define V_is_Nulling(v) ((v) ->t_is_nulling) 
#define V_is_Trace(val) ((val) ->t_trace) 
#define NOOK_of_V(val) ((val) ->t_nook) 
#define Nulling_Ask_BV_of_V(val) ((val) ->t_nulling_ask_bv) 
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
#define DSTACK_PUSH(this,type) ( \
(UNLIKELY((this) .t_count>=(this) .t_capacity)  \
?dstack_resize(&(this) ,sizeof(type) )  \
:0) , \
((type*) (this) .t_base+(this) .t_count++)  \
) 
#define DSTACK_POP(this,type) ((this) .t_count<=0?NULL: \
((type*) (this) .t_base+(--(this) .t_count) ) ) 
#define DSTACK_INDEX(this,type,ix) (DSTACK_BASE((this) ,type) +(ix) ) 
#define DSTACK_TOP(this,type) (DSTACK_LENGTH(this) <=0 \
?NULL \
:DSTACK_INDEX((this) ,type,DSTACK_LENGTH(this) -1) ) 
#define DSTACK_BASE(this,type) ((type*) (this) .t_base) 
#define DSTACK_LENGTH(this) ((this) .t_count) 
#define DSTACK_CAPACITY(this) ((this) .t_capacity)  \

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

#line 13964 "./marpa.w"

#include "marpa_obs.h"
#include "avl.h"
/*93:*/
#line 906 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:93*//*121:*/
#line 1090 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef XSY SYM;
typedef const struct s_xsy*XSY_Const;
/*:121*//*371:*/
#line 3848 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:371*//*410:*/
#line 4222 "./marpa.w"
struct s_AHFA_state;
/*:410*//*491:*/
#line 5392 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:491*//*598:*/
#line 6085 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:598*//*622:*/
#line 6299 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:622*//*642:*/
#line 6589 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:642*//*645:*/
#line 6624 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:645*//*726:*/
#line 7742 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:726*//*730:*/
#line 7770 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:730*//*828:*/
#line 8944 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:828*//*856:*/
#line 9372 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:856*//*883:*/
#line 9811 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:883*//*909:*/
#line 10226 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:909*//*924:*/
#line 10411 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:924*//*937:*/
#line 10519 "./marpa.w"

struct s_bocage_setup_per_es;
/*:937*//*996:*/
#line 11190 "./marpa.w"

typedef Marpa_Tree TREE;
/*:996*//*1035:*/
#line 11665 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1035*//*1048:*/
#line 11801 "./marpa.w"

typedef struct s_value*VALUE;
/*:1048*//*1139:*/
#line 13037 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1139*//*1142:*/
#line 13073 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1142*//*1149:*/
#line 13138 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1149*//*1151:*/
#line 13153 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1151*/
#line 13967 "./marpa.w"

/*40:*/
#line 604 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:40*//*120:*/
#line 1087 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
typedef XSYID SYMID;
/*:120*//*166:*/
#line 1396 "./marpa.w"

struct s_isy;
typedef struct s_isy*ISY;
typedef Marpa_ISY_ID ISYID;

/*:166*//*186:*/
#line 1551 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:186*//*271:*/
#line 2325 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:271*//*279:*/
#line 2387 "./marpa.w"
typedef int SYMI;
/*:279*//*427:*/
#line 4313 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef int AHFAID;

/*:427*//*492:*/
#line 5397 "./marpa.w"
typedef int AEX;
/*:492*//*508:*/
#line 5551 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:508*//*523:*/
#line 5643 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:523*//*595:*/
#line 6076 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:595*//*597:*/
#line 6080 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:597*//*673:*/
#line 7006 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:673*//*675:*/
#line 7018 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:675*//*848:*/
#line 9308 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:848*//*882:*/
#line 9800 "./marpa.w"

typedef int WHEID;

/*:882*//*908:*/
#line 10222 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:908*//*1034:*/
#line 11662 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1034*//*1086:*/
#line 12317 "./marpa.w"

typedef unsigned int Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1086*//*1121:*/
#line 12791 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1121*/
#line 13968 "./marpa.w"

/*34:*/
#line 523 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:34*//*862:*/
#line 9436 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:862*//*1087:*/
#line 12324 "./marpa.w"

static const unsigned int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const unsigned int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= 1u;
static const unsigned int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1087*//*1172:*/
#line 13334 "./marpa.w"


/*:1172*//*1213:*/
#line 13741 "./marpa.w"

int(*_marpa_debug_handler)(const char*,...)= 
MARPA_DEFAULT_DEBUG_HANDLER;
int _marpa_debug_level= 0;

/*:1213*/
#line 13969 "./marpa.w"

/*1140:*/
#line 13040 "./marpa.w"

struct s_dstack{int t_count;int t_capacity;void*t_base;};
/*:1140*/
#line 13970 "./marpa.w"

/*39:*/
#line 598 "./marpa.w"
struct marpa_g{
/*112:*/
#line 1042 "./marpa.w"

int t_is_ok;

/*:112*/
#line 599 "./marpa.w"

/*50:*/
#line 679 "./marpa.w"

DSTACK_DECLARE(t_xsy_stack);
DSTACK_DECLARE(t_isy_stack);

/*:50*//*59:*/
#line 738 "./marpa.w"

DSTACK_DECLARE(t_xrl_stack);
DSTACK_DECLARE(t_irl_stack);
struct marpa_avl_table*t_rule_tree;
/*:59*//*90:*/
#line 894 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:90*//*97:*/
#line 925 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:97*//*104:*/
#line 989 "./marpa.w"

AVL_TREE t_xrl_tree;
/*:104*//*108:*/
#line 1012 "./marpa.w"

struct obstack t_obs;
struct obstack t_xrl_obs;
/*:108*//*114:*/
#line 1057 "./marpa.w"

const char*t_error_string;
/*:114*//*373:*/
#line 3865 "./marpa.w"

AIM t_AHFA_items;
/*:373*//*428:*/
#line 4317 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:428*/
#line 600 "./marpa.w"

/*44:*/
#line 626 "./marpa.w"
int t_ref_count;
/*:44*//*70:*/
#line 797 "./marpa.w"
XSYID t_start_xsyid;
/*:70*//*74:*/
#line 825 "./marpa.w"

IRL t_start_irl;
/*:74*//*78:*/
#line 842 "./marpa.w"

int t_external_size;
/*:78*//*81:*/
#line 856 "./marpa.w"
int t_max_rule_length;
/*:81*//*115:*/
#line 1059 "./marpa.w"

Marpa_Error_Code t_error;
/*:115*//*280:*/
#line 2389 "./marpa.w"

int t_symbol_instance_count;
/*:280*//*374:*/
#line 3869 "./marpa.w"

unsigned int t_aim_count;
/*:374*//*429:*/
#line 4320 "./marpa.w"
int t_AHFA_len;
/*:429*/
#line 601 "./marpa.w"

/*84:*/
#line 862 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:84*//*87:*/
#line 874 "./marpa.w"
unsigned int t_has_cycle:1;
/*:87*/
#line 602 "./marpa.w"

};
/*:39*//*96:*/
#line 918 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:96*//*122:*/
#line 1105 "./marpa.w"

struct s_xsy{
int t_or_node_type;
XSYID t_symbol_id;
/*159:*/
#line 1353 "./marpa.w"
XSY t_source_xsy;
/*:159*//*179:*/
#line 1493 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:179*/
#line 1109 "./marpa.w"

/*126:*/
#line 1144 "./marpa.w"
unsigned int t_is_lhs:1;
/*:126*//*128:*/
#line 1151 "./marpa.w"
unsigned int t_is_sequence_lhs:1;
/*:128*//*130:*/
#line 1159 "./marpa.w"
unsigned int t_is_semantic:1;
/*:130*//*133:*/
#line 1181 "./marpa.w"
unsigned int t_is_ask_me_when_null:1;
/*:133*//*136:*/
#line 1206 "./marpa.w"
unsigned int t_is_accessible:1;
/*:136*//*139:*/
#line 1226 "./marpa.w"
unsigned int t_is_counted:1;
/*:139*//*142:*/
#line 1242 "./marpa.w"
unsigned int t_is_nulling:1;
/*:142*//*145:*/
#line 1258 "./marpa.w"
unsigned int t_is_nullable:1;
/*:145*//*148:*/
#line 1278 "./marpa.w"

unsigned int t_is_terminal:1;
unsigned int t_is_marked_terminal:1;
/*:148*//*153:*/
#line 1317 "./marpa.w"
unsigned int t_is_productive:1;
/*:153*//*156:*/
#line 1333 "./marpa.w"
unsigned int t_is_start:1;
/*:156*/
#line 1110 "./marpa.w"

};
typedef struct s_symbol SYM_Object;
/*:122*//*167:*/
#line 1401 "./marpa.w"

struct s_isy{
/*173:*/
#line 1446 "./marpa.w"

XSY t_buddy;
/*:173*/
#line 1403 "./marpa.w"

/*175:*/
#line 1464 "./marpa.w"
ISYID t_isy_id;

/*:175*/
#line 1404 "./marpa.w"

/*176:*/
#line 1469 "./marpa.w"
unsigned int t_is_nulling:1;
/*:176*/
#line 1405 "./marpa.w"

};

/*:167*//*185:*/
#line 1541 "./marpa.w"

struct s_xrl{
/*266:*/
#line 2312 "./marpa.w"
AIM t_first_aim;
/*:266*/
#line 1543 "./marpa.w"

/*198:*/
#line 1816 "./marpa.w"
int t_rhs_length;
/*:198*//*208:*/
#line 1904 "./marpa.w"
Marpa_Rule_ID t_id;

/*:208*//*247:*/
#line 2143 "./marpa.w"
int t_virtual_start;
/*:247*//*250:*/
#line 2163 "./marpa.w"
int t_virtual_end;
/*:250*//*253:*/
#line 2186 "./marpa.w"
XRL t_source_xrl;
/*:253*//*257:*/
#line 2208 "./marpa.w"
int t_real_symbol_count;
/*:257*//*260:*/
#line 2234 "./marpa.w"
unsigned int t_is_ask_me:1;
/*:260*//*281:*/
#line 2401 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:281*/
#line 1544 "./marpa.w"

/*209:*/
#line 1910 "./marpa.w"
unsigned int t_is_bnf:1;
/*:209*//*211:*/
#line 1917 "./marpa.w"
unsigned int t_is_sequence:1;
/*:211*//*214:*/
#line 1935 "./marpa.w"
int t_minimum;
/*:214*//*216:*/
#line 1943 "./marpa.w"
SYMID t_separator_id;
/*:216*//*220:*/
#line 1962 "./marpa.w"
unsigned int t_is_discard:1;
/*:220*//*224:*/
#line 2001 "./marpa.w"
unsigned int t_is_proper_separation:1;
/*:224*//*228:*/
#line 2021 "./marpa.w"
unsigned int t_is_loop:1;
/*:228*//*231:*/
#line 2037 "./marpa.w"
unsigned int t_is_nulling:1;
/*:231*//*234:*/
#line 2044 "./marpa.w"
unsigned int t_is_accessible:1;
/*:234*//*237:*/
#line 2061 "./marpa.w"
unsigned int t_is_productive:1;
/*:237*//*241:*/
#line 2107 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:241*//*244:*/
#line 2124 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:244*/
#line 1545 "./marpa.w"

/*199:*/
#line 1819 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:199*/
#line 1546 "./marpa.w"

};
/*:185*//*269:*/
#line 2318 "./marpa.w"

struct s_irl{
/*273:*/
#line 2335 "./marpa.w"

XRL t_co_rule;
/*:273*/
#line 2320 "./marpa.w"

/*275:*/
#line 2353 "./marpa.w"
IRLID t_irl_id;

/*:275*/
#line 2321 "./marpa.w"

};
/*:269*//*295:*/
#line 2577 "./marpa.w"

struct sym_rule_pair
{
SYMID t_symid;
RULEID t_ruleid;
};

/*:295*//*370:*/
#line 3842 "./marpa.w"

struct s_AHFA_item{
int t_sort_key;
/*379:*/
#line 3892 "./marpa.w"

IRL t_irl;

/*:379*/
#line 3845 "./marpa.w"

/*380:*/
#line 3898 "./marpa.w"

int t_position;

/*:380*//*381:*/
#line 3905 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:381*//*382:*/
#line 3914 "./marpa.w"

int t_leading_nulls;

/*:382*/
#line 3846 "./marpa.w"

};
/*:370*//*411:*/
#line 4223 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*415:*/
#line 4250 "./marpa.w"

SYMID*t_complete_symbols;

/*:415*//*417:*/
#line 4257 "./marpa.w"

AIM*t_items;
/*:417*//*434:*/
#line 4348 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:434*//*494:*/
#line 5409 "./marpa.w"

TRANS*t_transitions;
/*:494*/
#line 4230 "./marpa.w"

/*414:*/
#line 4248 "./marpa.w"

unsigned int t_complete_symbol_count;
/*:414*//*418:*/
#line 4260 "./marpa.w"

int t_item_count;
/*:418*//*435:*/
#line 4349 "./marpa.w"
unsigned int t_postdot_sym_count;

/*:435*//*441:*/
#line 4410 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:441*/
#line 4231 "./marpa.w"

/*422:*/
#line 4301 "./marpa.w"

unsigned int t_is_predict:1;

/*:422*//*425:*/
#line 4309 "./marpa.w"

unsigned int t_is_potential_leo_base:1;
/*:425*/
#line 4232 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:411*//*493:*/
#line 5398 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
int t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:493*//*509:*/
#line 5554 "./marpa.w"

struct s_input{
/*518:*/
#line 5625 "./marpa.w"

struct obstack t_token_obs;

/*:518*//*520:*/
#line 5630 "./marpa.w"

GRAMMAR t_grammar;
/*:520*/
#line 5556 "./marpa.w"

/*512:*/
#line 5571 "./marpa.w"

int t_ref_count;
/*:512*/
#line 5557 "./marpa.w"

};

/*:509*//*599:*/
#line 6091 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:599*//*600:*/
#line 6096 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
int t_postdot_sym_count;
/*601:*/
#line 6108 "./marpa.w"

int t_eim_count;
/*:601*//*603:*/
#line 6122 "./marpa.w"

int t_ordinal;
/*:603*/
#line 6100 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*602:*/
#line 6111 "./marpa.w"

EIM*t_earley_items;

/*:602*//*1159:*/
#line 13223 "./marpa.w"

PSL t_dot_psl;
/*:1159*/
#line 6103 "./marpa.w"

};

/*:600*//*643:*/
#line 6593 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:643*//*646:*/
#line 6627 "./marpa.w"

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

/*:646*//*656:*/
#line 6766 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:656*//*727:*/
#line 7750 "./marpa.w"

struct s_token_unvalued{
int t_type;
SYMID t_symbol_id;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:727*//*731:*/
#line 7780 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:731*//*829:*/
#line 8961 "./marpa.w"

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
/*:829*//*859:*/
#line 9411 "./marpa.w"

struct s_draft_or_node
{
/*858:*/
#line 9405 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:858*/
#line 9414 "./marpa.w"

DAND t_draft_and_node;
};
/*:859*//*860:*/
#line 9417 "./marpa.w"

struct s_final_or_node
{
/*858:*/
#line 9405 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:858*/
#line 9420 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:860*//*861:*/
#line 9428 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:861*//*884:*/
#line 9818 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:884*//*910:*/
#line 10233 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:910*//*938:*/
#line 10521 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:938*//*971:*/
#line 10873 "./marpa.w"

struct marpa_order{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
/*974:*/
#line 10892 "./marpa.w"

BOCAGE t_bocage;

/*:974*/
#line 10878 "./marpa.w"

/*977:*/
#line 10911 "./marpa.w"
int t_ref_count;
/*:977*/
#line 10879 "./marpa.w"

/*988:*/
#line 11002 "./marpa.w"

unsigned int t_is_nulling:1;

/*:988*/
#line 10880 "./marpa.w"

unsigned int t_is_frozen:1;
};
/*:971*//*997:*/
#line 11202 "./marpa.w"

/*1036:*/
#line 11676 "./marpa.w"

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

/*:1036*/
#line 11203 "./marpa.w"

/*1050:*/
#line 11815 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1057:*/
#line 11902 "./marpa.w"

DSTACK_DECLARE(t_virtual_stack);
/*:1057*//*1078:*/
#line 12052 "./marpa.w"

Bit_Vector t_nulling_ask_bv;
/*:1078*/
#line 11819 "./marpa.w"

/*1061:*/
#line 11936 "./marpa.w"

int t_ref_count;
/*:1061*//*1074:*/
#line 12030 "./marpa.w"

NOOKID t_nook;
/*:1074*/
#line 11820 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1069:*/
#line 12002 "./marpa.w"

unsigned int t_is_nulling:1;
/*:1069*//*1071:*/
#line 12009 "./marpa.w"

unsigned int t_trace:1;
/*:1071*/
#line 11823 "./marpa.w"

};

/*:1050*/
#line 11204 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_and_node_in_use;
Marpa_Order t_order;
/*1003:*/
#line 11274 "./marpa.w"

int t_ref_count;
/*:1003*//*1010:*/
#line 11354 "./marpa.w"
int t_pause_counter;
/*:1010*/
#line 11210 "./marpa.w"

/*1018:*/
#line 11446 "./marpa.w"

unsigned int t_is_exhausted:1;
/*:1018*//*1021:*/
#line 11454 "./marpa.w"

unsigned int t_is_nulling:1;

/*:1021*/
#line 11211 "./marpa.w"

int t_parse_count;
};

/*:997*//*1143:*/
#line 13076 "./marpa.w"

struct s_dqueue{int t_current;struct s_dstack t_stack;};

/*:1143*//*1150:*/
#line 13144 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1150*//*1152:*/
#line 13169 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1152*/
#line 13971 "./marpa.w"

/*524:*/
#line 5646 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*537:*/
#line 5751 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:537*//*549:*/
#line 5814 "./marpa.w"
void**t_sym_workarea;
/*:549*//*553:*/
#line 5825 "./marpa.w"
void**t_workarea2;
/*:553*//*557:*/
#line 5842 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:557*//*561:*/
#line 5868 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:561*//*584:*/
#line 6029 "./marpa.w"
struct obstack t_obs;
/*:584*//*609:*/
#line 6172 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:609*//*630:*/
#line 6434 "./marpa.w"

EIM t_trace_earley_item;
/*:630*//*660:*/
#line 6815 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:660*//*694:*/
#line 7272 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:694*//*732:*/
#line 7788 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:732*//*753:*/
#line 8103 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:753*//*757:*/
#line 8114 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:757*//*761:*/
#line 8125 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:761*//*830:*/
#line 8974 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:830*//*1153:*/
#line 13177 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1153*/
#line 5649 "./marpa.w"

/*527:*/
#line 5675 "./marpa.w"
int t_ref_count;
/*:527*//*541:*/
#line 5778 "./marpa.w"
int t_earley_item_warning_threshold;
/*:541*//*545:*/
#line 5801 "./marpa.w"
EARLEME t_furthest_earleme;
/*:545*//*604:*/
#line 6126 "./marpa.w"

int t_earley_set_count;
/*:604*/
#line 5650 "./marpa.w"

/*534:*/
#line 5743 "./marpa.w"

unsigned int t_input_phase:2;
/*:534*//*576:*/
#line 5967 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:576*//*580:*/
#line 6005 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:580*//*695:*/
#line 7275 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:695*/
#line 5651 "./marpa.w"

};

/*:524*/
#line 13972 "./marpa.w"

/*674:*/
#line 7009 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:674*//*676:*/
#line 7021 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:676*//*677:*/
#line 7027 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:677*//*678:*/
#line 7034 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:678*/
#line 13973 "./marpa.w"

/*623:*/
#line 6306 "./marpa.w"

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
/*628:*/
#line 6406 "./marpa.w"

unsigned int t_source_type:3;

/*:628*/
#line 6317 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:623*/
#line 13974 "./marpa.w"

/*925:*/
#line 10413 "./marpa.w"

struct marpa_bocage{
/*863:*/
#line 9446 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:863*//*927:*/
#line 10422 "./marpa.w"

INPUT t_input;

/*:927*//*929:*/
#line 10432 "./marpa.w"

struct obstack t_obs;
/*:929*/
#line 10415 "./marpa.w"

/*864:*/
#line 9449 "./marpa.w"

int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:864*//*951:*/
#line 10675 "./marpa.w"
int t_ref_count;
/*:951*/
#line 10416 "./marpa.w"

/*930:*/
#line 10434 "./marpa.w"

unsigned int t_is_obstack_initialized:1;
/*:930*//*958:*/
#line 10736 "./marpa.w"

unsigned int t_is_nulling:1;
/*:958*/
#line 10417 "./marpa.w"

};

/*:925*/
#line 13975 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1219:*/
#line 13799 "./marpa.w"

static const char*eim_tag_safe(char*buffer,EIM eim)UNUSED;
static const char*eim_tag(EIM eim)UNUSED;
/*:1219*//*1221:*/
#line 13824 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1221*//*1223:*/
#line 13850 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1223*//*1225:*/
#line 13882 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AIM aim)UNUSED;
static const char*aim_tag(AIM aim)UNUSED;
/*:1225*/
#line 13978 "./marpa.w"

/*1210:*/
#line 13714 "./marpa.w"

int _marpa_default_debug_handler(const char*format,...)
{
va_list args;
va_start(args,format);
vfprintf(stderr,format,args);
va_end(args);
putc('\n',stderr);
return 1;
}


/*:1210*//*1220:*/
#line 13803 "./marpa.w"

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

/*:1220*//*1222:*/
#line 13829 "./marpa.w"

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

/*:1222*//*1224:*/
#line 13854 "./marpa.w"

static const char*
or_tag_safe(char*buffer,OR or)
{
if(!or)return"NULL";
if(OR_is_Token(or))return"TOKEN";
if(Type_of_OR(or)==DUMMY_OR_NODE)return"DUMMY";
sprintf(buffer,"R%d:%d@%d-%d",
ID_of_IRL(IRL_of_OR(or)),Position_of_OR(or),
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

/*:1224*//*1226:*/
#line 13885 "./marpa.w"

static const char*
aim_tag_safe(char*buffer,AIM aim)
{
if(!aim)return"NULL";
const int aim_position= Position_of_AIM(aim);
if(aim_position>=0){
sprintf(buffer,"R%d@%d",IRLID_of_AIM(aim),Position_of_AIM(aim));
}else{
sprintf(buffer,"R%d@end",IRLID_of_AIM(aim));
}
return buffer;
}

static char DEBUG_aim_tag_buffer[1000];
static const char*
aim_tag(AIM aim)
{
return aim_tag_safe(DEBUG_aim_tag_buffer,aim);
}

/*:1226*/
#line 13979 "./marpa.w"

#endif
/*35:*/
#line 529 "./marpa.w"

PRIVATE
Marpa_Error_Code check_alpha_version(
unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
if(required_major!=MARPA_MAJOR_VERSION)
return MARPA_ERR_MAJOR_VERSION_MISMATCH;
if(required_minor!=MARPA_MINOR_VERSION)
return MARPA_ERR_MINOR_VERSION_MISMATCH;
if(required_micro!=MARPA_MICRO_VERSION)
return MARPA_ERR_MICRO_VERSION_MISMATCH;
return MARPA_ERR_NONE;
}

/*:35*//*36:*/
#line 545 "./marpa.w"

Marpa_Error_Code
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
return MARPA_ERR_MAJOR_VERSION_MISMATCH;
if(required_major<MARPA_MAJOR_VERSION)
return MARPA_ERR_MINOR_VERSION_MISMATCH;
if(required_effective_micro<marpa_effective_micro-MARPA_BINARY_AGE)
return MARPA_ERR_MICRO_VERSION_MISMATCH;
if(required_effective_micro> marpa_effective_micro)
return MARPA_ERR_MICRO_VERSION_MISMATCH;
return MARPA_ERR_NONE;
}

/*:36*//*42:*/
#line 608 "./marpa.w"

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
#line 627 "./marpa.w"

g->t_ref_count= 1;

/*:45*//*51:*/
#line 683 "./marpa.w"

DSTACK_INIT2(g->t_xsy_stack,XSY);
DSTACK_SAFE(g->t_isy_stack);

/*:51*//*60:*/
#line 742 "./marpa.w"

DSTACK_INIT2(g->t_xrl_stack,RULE);
DSTACK_SAFE(g->t_irl_stack);
g->t_rule_tree= _marpa_avl_create(duplicate_rule_cmp,NULL,alignof(RULE));

/*:60*//*71:*/
#line 798 "./marpa.w"

g->t_start_xsyid= -1;
/*:71*//*75:*/
#line 827 "./marpa.w"

g->t_start_irl= NULL;
/*:75*//*79:*/
#line 844 "./marpa.w"

External_Size_of_G(g)= 0;

/*:79*//*82:*/
#line 857 "./marpa.w"

g->t_max_rule_length= 0;

/*:82*//*85:*/
#line 863 "./marpa.w"

g->t_is_precomputed= 0;
/*:85*//*88:*/
#line 875 "./marpa.w"

g->t_has_cycle= 0;
/*:88*//*91:*/
#line 895 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:91*//*98:*/
#line 933 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:98*//*105:*/
#line 991 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL,0);
/*:105*//*109:*/
#line 1015 "./marpa.w"

my_obstack_init(&g->t_obs);
my_obstack_begin(&g->t_xrl_obs,0,alignof(struct s_xrl));
/*:109*//*116:*/
#line 1061 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:116*//*376:*/
#line 3874 "./marpa.w"

g->t_AHFA_items= NULL;
/*:376*//*430:*/
#line 4321 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:430*/
#line 620 "./marpa.w"


g->t_is_ok= I_AM_OK;
return g;
}
/*:42*//*46:*/
#line 637 "./marpa.w"

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
#line 654 "./marpa.w"

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
#line 666 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
/*52:*/
#line 687 "./marpa.w"

{
DSTACK_DESTROY(g->t_xsy_stack);
DSTACK_DESTROY(g->t_isy_stack);
}

/*:52*//*62:*/
#line 751 "./marpa.w"

DSTACK_DESTROY(g->t_irl_stack);
DSTACK_DESTROY(g->t_xrl_stack);
/*61:*/
#line 747 "./marpa.w"

_marpa_avl_destroy(g->t_rule_tree);
g->t_rule_tree= NULL;

/*:61*/
#line 754 "./marpa.w"


/*:62*//*92:*/
#line 896 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:92*//*99:*/
#line 935 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:99*//*107:*/
#line 998 "./marpa.w"

/*106:*/
#line 993 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:106*/
#line 999 "./marpa.w"


/*:107*//*110:*/
#line 1018 "./marpa.w"

my_obstack_free(&g->t_obs);
my_obstack_free(&g->t_xrl_obs);

/*:110*//*377:*/
#line 3876 "./marpa.w"

my_free(g->t_AHFA_items);

/*:377*//*431:*/
#line 4325 "./marpa.w"

{
if(g->t_AHFA)
{
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}
}

/*:431*/
#line 670 "./marpa.w"

my_slice_free(struct marpa_g,g);
}

/*:49*//*54:*/
#line 697 "./marpa.w"

int marpa_g_symbol_count(Marpa_Grammar g){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 699 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 700 "./marpa.w"

return SYM_Count_of_G(g);
}

/*:54*//*56:*/
#line 711 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,SYM symbol)
{
const SYMID new_id= DSTACK_LENGTH((g)->t_xsy_stack);
*DSTACK_PUSH((g)->t_xsy_stack,SYM)= symbol;
symbol->t_symbol_id= new_id;
}

/*:56*//*57:*/
#line 721 "./marpa.w"

PRIVATE int symbol_is_valid(GRAMMAR g,SYMID symid)
{
return symid>=0&&symid<SYM_Count_of_G(g);
}

/*:57*//*58:*/
#line 728 "./marpa.w"

PRIVATE int isy_is_valid(GRAMMAR g,ISYID isyid)
{
return isyid>=0&&isyid<ISY_Count_of_G(g);
}

/*:58*//*66:*/
#line 759 "./marpa.w"

int marpa_g_rule_count(Marpa_Grammar g){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 761 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 762 "./marpa.w"

return XRL_Count_of_G(g);
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 766 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 767 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:66*//*68:*/
#line 778 "./marpa.w"

PRIVATE void
rule_add(GRAMMAR g,RULE rule)
{
const RULEID new_id= DSTACK_LENGTH((g)->t_xrl_stack);
*DSTACK_PUSH((g)->t_xrl_stack,RULE)= rule;
rule->t_id= new_id;
External_Size_of_G(g)+= 1+Length_of_RULE(rule);
g->t_max_rule_length= MAX(Length_of_RULE(rule),g->t_max_rule_length);
}

/*:68*//*72:*/
#line 800 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 803 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 804 "./marpa.w"

return g->t_start_xsyid;
}
/*:72*//*73:*/
#line 809 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 812 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 813 "./marpa.w"

/*1191:*/
#line 13532 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1191*/
#line 814 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 815 "./marpa.w"

return g->t_start_xsyid= symid;
}

/*:73*//*86:*/
#line 865 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 868 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 869 "./marpa.w"

return G_is_Precomputed(g);
}

/*:86*//*89:*/
#line 877 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 880 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 881 "./marpa.w"

return g->t_has_cycle;
}

/*:89*//*101:*/
#line 945 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:101*//*102:*/
#line 954 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:102*//*103:*/
#line 964 "./marpa.w"

int
marpa_g_event(Marpa_Grammar g,Marpa_Event public_event,
int ix)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 969 "./marpa.w"

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

/*:103*//*118:*/
#line 1072 "./marpa.w"

Marpa_Error_Code marpa_g_error(Marpa_Grammar g,const char**p_error_string)
{
const Marpa_Error_Code error_code= g->t_error;
const char*error_string= g->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:118*//*124:*/
#line 1120 "./marpa.w"

PRIVATE SYM
symbol_new(GRAMMAR g,XSY source)
{
SYM symbol= my_obstack_new(&g->t_obs,struct s_xsy,1);
/*123:*/
#line 1117 "./marpa.w"

symbol->t_or_node_type= NULLING_TOKEN_OR_NODE;

/*:123*//*127:*/
#line 1145 "./marpa.w"

SYM_is_LHS(symbol)= 0;

/*:127*//*129:*/
#line 1152 "./marpa.w"

SYM_is_Sequence_LHS(symbol)= 0;

/*:129*//*131:*/
#line 1160 "./marpa.w"

SYM_is_Semantic(symbol)= 1;
/*:131*//*134:*/
#line 1182 "./marpa.w"

SYM_is_Ask_Me_When_Null(symbol)= 0;
/*:134*//*137:*/
#line 1207 "./marpa.w"

symbol->t_is_accessible= 0;
/*:137*//*140:*/
#line 1227 "./marpa.w"

symbol->t_is_counted= 0;
/*:140*//*143:*/
#line 1243 "./marpa.w"

symbol->t_is_nulling= 0;
/*:143*//*146:*/
#line 1259 "./marpa.w"

symbol->t_is_nullable= 0;
/*:146*//*149:*/
#line 1281 "./marpa.w"

symbol->t_is_terminal= 0;
symbol->t_is_marked_terminal= 0;
/*:149*//*154:*/
#line 1318 "./marpa.w"

symbol->t_is_productive= 0;
/*:154*//*157:*/
#line 1334 "./marpa.w"
symbol->t_is_start= 0;
/*:157*//*160:*/
#line 1354 "./marpa.w"
Source_XSY_of_SYM(symbol)= NULL;
/*:160*//*180:*/
#line 1496 "./marpa.w"

LHS_XRL_of_SYM(symbol)= NULL;
XRL_Offset_of_SYM(symbol)= -1;

/*:180*/
#line 1125 "./marpa.w"

Source_XSY_of_SYM(symbol)= source?source:symbol;
symbol_add(g,symbol);
return symbol;
}

/*:124*//*125:*/
#line 1131 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const SYM symbol= symbol_new(g,0);
return ID_of_SYM(symbol);
}

/*:125*//*132:*/
#line 1162 "./marpa.w"

int _marpa_g_symbol_is_semantic(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1167 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1168 "./marpa.w"

return SYM_is_Semantic(SYM_by_ID(symid));
}

/*:132*//*135:*/
#line 1184 "./marpa.w"

int marpa_g_symbol_is_ask_me_when_null(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1189 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1190 "./marpa.w"

return SYM_is_Ask_Me_When_Null(SYM_by_ID(symid));
}
int marpa_g_symbol_ask_me_when_null_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1197 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1198 "./marpa.w"

symbol= SYM_by_ID(symid);
return SYM_is_Ask_Me_When_Null(symbol)= value?1:0;
}

/*:135*//*138:*/
#line 1215 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1218 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1219 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 1220 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1221 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(symid));
}

/*:138*//*141:*/
#line 1229 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1233 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1234 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1235 "./marpa.w"

return SYM_by_ID(symid)->t_is_counted;
}

/*:141*//*144:*/
#line 1245 "./marpa.w"

int marpa_g_symbol_is_nulling(GRAMMAR g,SYMID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1248 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1249 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 1250 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1251 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));
}

/*:144*//*147:*/
#line 1261 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1264 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1265 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 1266 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1267 "./marpa.w"

return XSY_is_Nullable(SYM_by_ID(symid));
}

/*:147*//*151:*/
#line 1287 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1291 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1292 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1293 "./marpa.w"

return SYMID_is_Terminal(symid);
}
/*:151*//*152:*/
#line 1296 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1301 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1302 "./marpa.w"

/*1191:*/
#line 13532 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1191*/
#line 1303 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1304 "./marpa.w"

symbol= SYM_by_ID(symid);
if(UNLIKELY(value<0||value> 1)){
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
SYM_is_Marked_Terminal(symbol)= 1;
return SYM_is_Terminal(symbol)= value;
}

/*:152*//*155:*/
#line 1320 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1325 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1326 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 1327 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1328 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(symid));
}

/*:155*//*158:*/
#line 1335 "./marpa.w"

int _marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1338 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1339 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 1340 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1341 "./marpa.w"

return SYM_by_ID(symid)->t_is_start;
}

/*:158*//*161:*/
#line 1355 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
XSY source_xsy;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1361 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1362 "./marpa.w"

source_xsy= Source_XSY_of_SYM(SYM_by_ID(symid));
return source_xsy?ID_of_XSY(source_xsy):-1;
}

/*:161*//*163:*/
#line 1373 "./marpa.w"

PRIVATE
ISY symbol_alias_create(GRAMMAR g,SYM symbol)
{
ISY alias_isy= isy_new(g,symbol);
SYM alias= Buddy_of_ISY(alias_isy);
SYM_is_Nulling(symbol)= 0;
XSY_is_Nullable(symbol)= 1;
SYM_is_Nulling(alias)= 1;
XSY_is_Nullable(alias)= 1;
SYM_is_Ask_Me_When_Null(alias)
= SYM_is_Ask_Me_When_Null(symbol);
alias->t_is_productive= 1;
alias->t_is_accessible= symbol->t_is_accessible;
return alias_isy;
}

/*:163*//*169:*/
#line 1410 "./marpa.w"

PRIVATE ISY
isy_start(GRAMMAR g)
{
const ISY new_isy= my_obstack_new(&g->t_obs,struct s_isy,1);
ID_of_ISY(new_isy)= DSTACK_LENGTH((g)->t_isy_stack);
*DSTACK_PUSH((g)->t_isy_stack,ISY)= new_isy;
return new_isy;
}

/*:169*//*170:*/
#line 1421 "./marpa.w"

PRIVATE ISY
isy_new(GRAMMAR g,XSY source)
{
const XSY xsy= symbol_new(g,source);
const ISY new_isy= isy_start(g);
Buddy_of_ISY(new_isy)= xsy;
return new_isy;
}

/*:170*//*171:*/
#line 1432 "./marpa.w"

PRIVATE ISY
isy_clone(GRAMMAR g,XSY xsy)
{
const ISY new_isy= isy_start(g);
Buddy_of_ISY(new_isy)= xsy;
return new_isy;
}

/*:171*//*174:*/
#line 1448 "./marpa.w"

Marpa_Symbol_ID _marpa_g_isy_buddy(
Marpa_Grammar g,
Marpa_ISY_ID isy_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1453 "./marpa.w"

/*1194:*/
#line 13548 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1194*/
#line 1454 "./marpa.w"

return ID_of_XSY(Buddy_of_ISY(ISY_by_ID(isy_id)));
}

/*:174*//*177:*/
#line 1470 "./marpa.w"

int _marpa_g_isy_is_nulling(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1473 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1474 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 1475 "./marpa.w"

/*1194:*/
#line 13548 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1194*/
#line 1476 "./marpa.w"

return ISY_is_Nulling(ISY_by_ID(isy_id));
}

/*:177*//*182:*/
#line 1505 "./marpa.w"

Marpa_Rule_ID _marpa_g_symbol_lhs_xrl(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1508 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1509 "./marpa.w"

{
const SYM symbol= SYM_by_ID(symid);
const XRL lhs_xrl= LHS_XRL_of_SYM(symbol);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:182*//*183:*/
#line 1527 "./marpa.w"

int _marpa_g_symbol_xrl_offset(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1530 "./marpa.w"

SYM symbol;
/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 1532 "./marpa.w"

symbol= SYM_by_ID(symid);
return XRL_Offset_of_SYM(symbol);
}

/*:183*//*189:*/
#line 1569 "./marpa.w"

PRIVATE
XRL xrl_start(GRAMMAR g,const SYMID lhs,const SYMID*rhs,int length)
{
XRL xrl;
const int sizeof_xrl= offsetof(struct s_xrl,t_symbols)+
(length+1)*sizeof(xrl->t_symbols[0]);
my_obstack_blank(&g->t_xrl_obs,sizeof_xrl);
xrl= my_obstack_base(&g->t_xrl_obs);
Length_of_XRL(xrl)= length;
xrl->t_symbols[0]= lhs;
XSY_is_LHS(XSY_by_ID(lhs))= 1;
{
int i;
for(i= 0;i<length;i++)
{
xrl->t_symbols[i+1]= rhs[i];
}
}
return xrl;
}

PRIVATE
XRL xrl_finish(GRAMMAR g,XRL rule)
{
/*210:*/
#line 1911 "./marpa.w"

rule->t_is_bnf= 0;

/*:210*//*212:*/
#line 1918 "./marpa.w"

rule->t_is_sequence= 0;
/*:212*//*215:*/
#line 1936 "./marpa.w"

rule->t_minimum= -1;

/*:215*//*217:*/
#line 1944 "./marpa.w"

Separator_of_XRL(rule)= -1;

/*:217*//*221:*/
#line 1963 "./marpa.w"

rule->t_is_discard= 0;
/*:221*//*225:*/
#line 2002 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:225*//*229:*/
#line 2022 "./marpa.w"

rule->t_is_loop= 0;
/*:229*//*232:*/
#line 2038 "./marpa.w"

XRL_is_Nulling(rule)= 0;

/*:232*//*235:*/
#line 2045 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:235*//*238:*/
#line 2062 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:238*//*242:*/
#line 2108 "./marpa.w"

RULE_has_Virtual_LHS(rule)= 0;
/*:242*//*245:*/
#line 2125 "./marpa.w"

RULE_has_Virtual_RHS(rule)= 0;
/*:245*//*248:*/
#line 2144 "./marpa.w"
rule->t_virtual_start= -1;
/*:248*//*251:*/
#line 2164 "./marpa.w"
rule->t_virtual_end= -1;
/*:251*//*254:*/
#line 2187 "./marpa.w"
Source_XRL_of_RULE(rule)= NULL;
/*:254*//*258:*/
#line 2209 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:258*//*261:*/
#line 2235 "./marpa.w"

XRL_is_Ask_Me(rule)= 0;
/*:261*//*267:*/
#line 2313 "./marpa.w"

rule->t_first_aim= NULL;

/*:267*//*282:*/
#line 2404 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:282*/
#line 1594 "./marpa.w"

rule_add(g,rule);
return rule;
}

PRIVATE_NOT_INLINE
RULE rule_new(GRAMMAR g,
const SYMID lhs,const SYMID*rhs,int length)
{
RULE rule= xrl_start(g,lhs,rhs,length);
xrl_finish(g,rule);
rule= my_obstack_finish(&g->t_xrl_obs);
return rule;
}

PRIVATE IRL
irl_start(GRAMMAR g)
{
const IRL new_irl= my_obstack_new(&g->t_obs,struct s_irl,1);
ID_of_IRL(new_irl)= DSTACK_LENGTH((g)->t_irl_stack);
*DSTACK_PUSH((g)->t_irl_stack,IRL)= new_irl;
return new_irl;
}

/*:189*//*190:*/
#line 1619 "./marpa.w"

PRIVATE IRL
irl_new(GRAMMAR g,
const SYMID lhs,const SYMID*rhs,int length)
{
const XRL xrl= rule_new(g,lhs,rhs,length);
IRL new_irl= irl_start(g);
Co_RULE_of_IRL(new_irl)= xrl;
g->t_max_rule_length= MAX(Length_of_RULE(xrl),g->t_max_rule_length);
return new_irl;
}

/*:190*//*191:*/
#line 1632 "./marpa.w"

PRIVATE IRL
irl_clone(GRAMMAR g,XRL xrl)
{
const IRL new_irl= irl_start(g);
Co_RULE_of_IRL(new_irl)= xrl;
return new_irl;
}

/*:191*//*192:*/
#line 1641 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,int length)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1646 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1649 "./marpa.w"

/*1191:*/
#line 13532 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1191*/
#line 1650 "./marpa.w"

if(UNLIKELY(length> MAX_RHS_LENGTH))
{
MARPA_ERROR(MARPA_ERR_RHS_TOO_LONG);
goto FAILURE;
}
rule= xrl_start(g,lhs,rhs,length);
if(UNLIKELY(_marpa_avl_insert(g->t_xrl_tree,rule)!=NULL))
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
goto FAILURE;
}
if(UNLIKELY(!rule_check(g,rule)))
goto FAILURE;
rule= xrl_finish(g,rule);
rule= my_obstack_finish(&g->t_xrl_obs);
XRL_is_BNF(rule)= 1;
rule_id= rule->t_id;
return rule_id;
FAILURE:
my_obstack_reject(&g->t_xrl_obs);
return failure_indicator;
}

/*:192*//*193:*/
#line 1674 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1681 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1682 "./marpa.w"

/*1191:*/
#line 13532 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1191*/
#line 1683 "./marpa.w"

/*195:*/
#line 1714 "./marpa.w"

{
if(separator_id!=-1)
{
if(UNLIKELY(!symbol_is_valid(g,separator_id)))
{
MARPA_ERROR(MARPA_ERR_BAD_SEPARATOR);
goto FAILURE;
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
}

/*:195*/
#line 1684 "./marpa.w"

/*194:*/
#line 1692 "./marpa.w"

{
original_rule= rule_new(g,lhs_id,&rhs_id,1);
original_rule_id= original_rule->t_id;
if(separator_id>=0)
Separator_of_XRL(original_rule)= separator_id;
Minimum_of_XRL(original_rule)= min;
XRL_is_Sequence(original_rule)= 1;
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

/*:194*/
#line 1685 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:193*//*197:*/
#line 1767 "./marpa.w"

PRIVATE_NOT_INLINE int
duplicate_rule_cmp(const void*ap,const void*bp,void*param UNUSED)
{
XRL xrl1= (XRL)ap;
XRL xrl2= (XRL)bp;
int diff= LHS_ID_of_XRL(xrl2)-LHS_ID_of_XRL(xrl1);
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
diff= RHS_ID_of_XRL(xrl2,ix)-RHS_ID_of_XRL(xrl1,ix);
if(diff)
return diff;
}
}
return 0;
}

/*:197*//*200:*/
#line 1821 "./marpa.w"

PRIVATE int
rule_check(GRAMMAR g,XRL rule)
{
SYM lhs;
const XRLID lhs_id= LHS_ID_of_XRL(rule);
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
const SYMID symid= RHS_ID_of_XRL(rule,rh_index);
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

/*:200*//*201:*/
#line 1853 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:201*//*202:*/
#line 1857 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1859 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1860 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 1861 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:202*//*203:*/
#line 1864 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:203*//*204:*/
#line 1868 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1871 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1872 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 1873 "./marpa.w"

rule= XRL_by_ID(xrl_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:204*//*205:*/
#line 1878 "./marpa.w"

PRIVATE size_t rule_length_get(RULE rule)
{
return Length_of_RULE(rule);}
/*:205*//*206:*/
#line 1882 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1884 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1885 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 1886 "./marpa.w"

return rule_length_get(XRL_by_ID(xrl_id));}

/*:206*//*213:*/
#line 1920 "./marpa.w"

int marpa_g_rule_is_sequence(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1925 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1926 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 1927 "./marpa.w"

return XRL_is_Sequence(XRL_by_ID(xrl_id));
}


/*:213*//*222:*/
#line 1965 "./marpa.w"

int marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 1970 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 1971 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 1972 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:222*//*226:*/
#line 2004 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2009 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 2010 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 2011 "./marpa.w"

return!XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:226*//*230:*/
#line 2024 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2027 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 2028 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 2029 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 2030 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:230*//*236:*/
#line 2047 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2050 "./marpa.w"

XRL xrl;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 2052 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 2053 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:236*//*239:*/
#line 2064 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2067 "./marpa.w"

XRL xrl;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 2069 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 2070 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:239*//*240:*/
#line 2080 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2084 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 2085 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:240*//*243:*/
#line 2110 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2115 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 2116 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2117 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:243*//*246:*/
#line 2127 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2132 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 2133 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2134 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:246*//*249:*/
#line 2145 "./marpa.w"

unsigned int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2151 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 2152 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2153 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:249*//*252:*/
#line 2165 "./marpa.w"

unsigned int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2171 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 2172 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2173 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:252*//*255:*/
#line 2188 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2194 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2195 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:255*//*259:*/
#line 2210 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2215 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 2216 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2217 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:259*//*262:*/
#line 2237 "./marpa.w"

int marpa_g_rule_is_ask_me(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2242 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 2243 "./marpa.w"

return XRL_is_Ask_Me(XRL_by_ID(xrl_id));
}
/*:262*//*263:*/
#line 2262 "./marpa.w"

int marpa_g_rule_whatever_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2267 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 2268 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Ask_Me(xrl)= 0;
}
int marpa_g_rule_ask_me_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2276 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 2277 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Ask_Me(xrl)= 1;
}
int marpa_g_rule_first_child_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2285 "./marpa.w"

/*1196:*/
#line 13558 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1196*/
#line 2286 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Ask_Me(xrl)= 0;
}

/*:263*//*265:*/
#line 2294 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2299 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2300 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:265*//*274:*/
#line 2337 "./marpa.w"

Marpa_Rule_ID _marpa_g_irl_co_rule(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2342 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2343 "./marpa.w"

return ID_of_XRL(Co_RULE_of_IRL(IRL_by_ID(irl_id)));
}

/*:274*//*276:*/
#line 2356 "./marpa.w"

Marpa_Symbol_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2358 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 2359 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2360 "./marpa.w"

return LHS_ID_of_IRL(IRL_by_ID(irl_id));
}

/*:276*//*277:*/
#line 2365 "./marpa.w"

Marpa_Symbol_ID _marpa_g_irl_rh_symbol(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2368 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 2369 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2370 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHS_ID_of_IRL(irl,ix);
}

/*:277*//*278:*/
#line 2377 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2379 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 2380 "./marpa.w"

/*1195:*/
#line 13553 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1195*/
#line 2381 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}


/*:278*//*284:*/
#line 2418 "./marpa.w"

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

/*:284*//*286:*/
#line 2450 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 2453 "./marpa.w"

int return_value= failure_indicator;
struct obstack obs_precompute;
/*290:*/
#line 2538 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);
ISY*nulling_isy_by_xsyid= NULL;
ISY*primary_isy_by_xsyid= NULL;

/*:290*//*294:*/
#line 2573 "./marpa.w"

XSYID start_xsyid= g->t_start_xsyid;

/*:294*//*306:*/
#line 2864 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:306*/
#line 2456 "./marpa.w"

my_obstack_init(&obs_precompute);
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 2458 "./marpa.w"

G_EVENTS_CLEAR(g);
/*291:*/
#line 2544 "./marpa.w"

if(UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
return failure_indicator;
}

/*:291*/
#line 2460 "./marpa.w"

/*1191:*/
#line 13532 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1191*/
#line 2461 "./marpa.w"

/*293:*/
#line 2554 "./marpa.w"

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

/*:293*/
#line 2462 "./marpa.w"


g->t_is_precomputed= 1;
/*106:*/
#line 993 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:106*/
#line 2465 "./marpa.w"


{
/*299:*/
#line 2749 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:299*//*300:*/
#line 2752 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;
RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:300*//*304:*/
#line 2813 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:304*/
#line 2468 "./marpa.w"

/*289:*/
#line 2525 "./marpa.w"

{
/*297:*/
#line 2597 "./marpa.w"

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

lhs_v= bv_obs_create(&obs_precompute,pre_census_xsy_count);
empty_lhs_v= bv_obs_shadow(&obs_precompute,lhs_v);
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
const XRL rule= XRL_by_ID(rule_id);
const Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
const int rule_length= Length_of_RULE(rule);
const int is_sequence= XRL_is_Sequence(rule);

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
my_obstack_new(&obs_precompute,RULEID,External_Size_of_G(g));
RULEID*p_rule_data= rule_data_base;
_marpa_avl_t_init(&traverser,rhs_avl_tree);

xrl_list_x_rh_sym= my_obstack_new(&obs_precompute,RULEID*,pre_census_xsy_count+1);
for(pair= (struct sym_rule_pair*)_marpa_avl_t_first(&traverser,rhs_avl_tree);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(&traverser))
{
const SYMID current_symid= pair->t_symid;
while(seen_symid<current_symid)
xrl_list_x_rh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(seen_symid<=pre_census_xsy_count)
xrl_list_x_rh_sym[++seen_symid]= p_rule_data;
_marpa_avl_destroy(rhs_avl_tree);
}

{
struct avl_traverser traverser;
struct sym_rule_pair*pair;
SYMID seen_symid= -1;
RULEID*const rule_data_base= 
my_obstack_new(&obs_precompute,RULEID,xrl_count);
RULEID*p_rule_data= rule_data_base;
_marpa_avl_t_init(&traverser,lhs_avl_tree);

xrl_list_x_lh_sym= 
my_obstack_new(&obs_precompute,RULEID*,pre_census_xsy_count+1);
for(pair= 
(struct sym_rule_pair*)_marpa_avl_t_first(&traverser,lhs_avl_tree);
pair;pair= (struct sym_rule_pair*)_marpa_avl_t_next(&traverser))
{
const SYMID current_symid= pair->t_symid;
while(seen_symid<current_symid)
xrl_list_x_lh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(seen_symid<=pre_census_xsy_count)
xrl_list_x_lh_sym[++seen_symid]= p_rule_data;
_marpa_avl_destroy(lhs_avl_tree);
}

}

/*:297*/
#line 2527 "./marpa.w"

/*298:*/
#line 2720 "./marpa.w"

{
SYMID symid;
terminal_v= bv_obs_create(&obs_precompute,pre_census_xsy_count);
bv_not(terminal_v,lhs_v);
for(symid= 0;symid<pre_census_xsy_count;symid++)
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

/*:298*/
#line 2528 "./marpa.w"

/*305:*/
#line 2835 "./marpa.w"

{
XRLID rule_id;
reach_matrix= matrix_obs_create(&obs_precompute,pre_census_xsy_count,pre_census_xsy_count);
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule= XRL_by_ID(rule_id);
SYMID lhs_id= LHS_ID_of_RULE(rule);
unsigned int rhs_ix,rule_length= Length_of_RULE(rule);
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

/*:305*/
#line 2529 "./marpa.w"

/*301:*/
#line 2758 "./marpa.w"

{
unsigned int min,max,start;
XSYID xsyid;
int counted_nullables= 0;
nullable_v= bv_obs_clone(&obs_precompute,empty_lhs_v);
rhs_closure(g,nullable_v,xrl_list_x_rh_sym);
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2)
{
for(xsyid= (XSYID)min;xsyid<=(XSYID)max;
xsyid++)
{
XSY xsy= XSY_by_ID(xsyid);
XSY_is_Nullable(xsy)= 1;
if(UNLIKELY(xsy->t_is_counted))
{
counted_nullables++;
int_event_new(g,MARPA_EVENT_COUNTED_NULLABLE,xsyid);
}
}
}
if(UNLIKELY(counted_nullables))
{
MARPA_ERROR(MARPA_ERR_COUNTED_NULLABLE);
goto FAILURE;
}
}

/*:301*/
#line 2530 "./marpa.w"

/*302:*/
#line 2786 "./marpa.w"

{
productive_v= bv_obs_shadow(&obs_precompute,nullable_v);
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

/*:302*/
#line 2531 "./marpa.w"

/*303:*/
#line 2807 "./marpa.w"

if(UNLIKELY(!bv_bit_test(productive_v,(unsigned int)start_xsyid)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:303*/
#line 2532 "./marpa.w"

/*307:*/
#line 2869 "./marpa.w"

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

/*:307*/
#line 2533 "./marpa.w"

/*308:*/
#line 2889 "./marpa.w"

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

/*:308*/
#line 2534 "./marpa.w"

/*309:*/
#line 2928 "./marpa.w"

{
XRLID xrl_id;
for(xrl_id= 0;xrl_id<xrl_count;xrl_id++)
{
const XRL xrl= XRL_by_ID(xrl_id);
int rh_ix;
int is_nulling= 1;
int is_productive= 1;
const XSYID lhs_id= LHS_ID_of_XRL(xrl);
const XSY lhs= XSY_by_ID(lhs_id);
XRL_is_Accessible(xrl)= XSY_is_Accessible(lhs);
for(rh_ix= 0;rh_ix<Length_of_XRL(xrl);rh_ix++)
{
const XSYID rhs_id= RHS_ID_of_XRL(xrl,rh_ix);
const XSY rh_xsy= XSY_by_ID(rhs_id);
if(LIKELY(!XSY_is_Nulling(rh_xsy)))is_nulling= 0;
if(UNLIKELY(!XSY_is_Productive(rh_xsy)))is_productive= 0;
}
XRL_is_Nulling(xrl)= is_nulling;
XRL_is_Productive(xrl)= is_productive;
}
}

/*:309*/
#line 2535 "./marpa.w"

}

/*:289*/
#line 2469 "./marpa.w"

/*360:*/
#line 3635 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(&obs_precompute,(unsigned int)xrl_count,
(unsigned int)xrl_count);
/*361:*/
#line 3656 "./marpa.w"

{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule= XRL_by_ID(rule_id);
SYMID nonnulling_id= -1;
int nonnulling_count= 0;
int rhs_ix,rule_length;
rule_length= Length_of_RULE(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
if(bv_bit_test(nullable_v,symid))
continue;
nonnulling_id= symid;
nonnulling_count++;
}
if(nonnulling_count==1)
{
/*362:*/
#line 3699 "./marpa.w"

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

/*:362*/
#line 3677 "./marpa.w"

}
else if(nonnulling_count==0)
{
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
nonnulling_id= RHS_ID_of_RULE(rule,rhs_ix);
if(!bv_bit_test(nullable_v,nonnulling_id))
continue;
if(SYM_is_Nulling(SYM_by_ID(nonnulling_id)))
continue;

/*362:*/
#line 3699 "./marpa.w"

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

/*:362*/
#line 3690 "./marpa.w"

}
}
}
}

/*:361*/
#line 3641 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*363:*/
#line 3713 "./marpa.w"

{
XRLID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule;
if(!matrix_bit_test
(unit_transition_matrix,(unsigned int)rule_id,
(unsigned int)rule_id))
continue;
loop_rule_count++;
rule= XRL_by_ID(rule_id);
rule->t_is_loop= 1;
}
}

/*:363*/
#line 3643 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:360*/
#line 2470 "./marpa.w"

}

/*464:*/
#line 4823 "./marpa.w"

DSTACK_INIT(g->t_irl_stack,IRL,2*DSTACK_CAPACITY(g->t_xrl_stack));

/*:464*/
#line 2473 "./marpa.w"

/*465:*/
#line 4831 "./marpa.w"

{
XSYID xsyid;
DSTACK_INIT(g->t_isy_stack,ISY,2*DSTACK_CAPACITY(g->t_xsy_stack));
nulling_isy_by_xsyid= my_obstack_new(&obs_precompute,ISY,pre_census_xsy_count);
primary_isy_by_xsyid= my_obstack_new(&obs_precompute,ISY,pre_census_xsy_count);
for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++){
nulling_isy_by_xsyid[xsyid]= NULL;
primary_isy_by_xsyid[xsyid]= NULL;
}
}

/*:465*/
#line 2474 "./marpa.w"

/*321:*/
#line 3081 "./marpa.w"

{
/*322:*/
#line 3110 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:322*//*325:*/
#line 3163 "./marpa.w"

int factor_count;
int*factor_positions;
/*:325*//*329:*/
#line 3215 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:329*/
#line 3083 "./marpa.w"

/*326:*/
#line 3166 "./marpa.w"

factor_positions= my_obstack_new(&obs_precompute,int,g->t_max_rule_length);

/*:326*//*330:*/
#line 3218 "./marpa.w"

piece_rhs= my_obstack_new(&obs_precompute,Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= my_obstack_new(&obs_precompute,Marpa_Symbol_ID,g->t_max_rule_length);

/*:330*/
#line 3084 "./marpa.w"

/*323:*/
#line 3116 "./marpa.w"

{
XSYID xsyid;
for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++)
{
const XSY xsy= XSY_by_ID(xsyid);
if(UNLIKELY(!xsy->t_is_accessible))
continue;
if(UNLIKELY(!xsy->t_is_productive))
continue;
primary_isy_by_xsyid[xsyid]= isy_clone(g,xsy);
if(XSY_is_Nullable(xsy)&&!XSY_is_Nulling(xsy))
{
nulling_isy_by_xsyid[xsyid]= symbol_alias_create(g,xsy);
}
}
}

/*:323*/
#line 3085 "./marpa.w"

pre_chaf_rule_count= XRL_Count_of_G(g);
for(rule_id= 0;rule_id<pre_chaf_rule_count;rule_id++){

XRL rule= XRL_by_ID(rule_id);
const int rule_length= Length_of_RULE(rule);
int nullable_suffix_ix= 0;
if(XRL_is_Sequence(rule)&&XRL_is_Used(rule))
{
/*310:*/
#line 2953 "./marpa.w"

{
const SYMID lhs_id= LHS_ID_of_RULE(rule);
const ISY internal_lhs_isy= isy_new(g,SYM_by_ID(lhs_id));
const SYM internal_lhs= Buddy_of_ISY(internal_lhs_isy);
const SYMID internal_lhs_id= ID_of_SYM(internal_lhs);
const SYMID rhs_id= RHS_ID_of_RULE(rule,0);
const SYMID separator_id= Separator_of_XRL(rule);
SYM_is_Semantic(internal_lhs)= 0;
LHS_XRL_of_SYM(internal_lhs)= rule;
/*311:*/
#line 2971 "./marpa.w"

{
IRL rewrite_irl= irl_new(g,lhs_id,&internal_lhs_id,1);
RULE rewrite_rule= Co_RULE_of_IRL(rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;

RULE_has_Virtual_RHS(rewrite_rule)= 1;
}

/*:311*/
#line 2963 "./marpa.w"

if(separator_id>=0&&!XRL_is_Proper_Separation(rule)){
/*312:*/
#line 2981 "./marpa.w"

{
RULE rewrite_rule;
IRL rewrite_irl;
SYMID temp_rhs[2];
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rewrite_irl= irl_new(g,lhs_id,temp_rhs,2);
rewrite_rule= Co_RULE_of_IRL(rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
RULE_has_Virtual_RHS(rewrite_rule)= 1;
Real_SYM_Count_of_RULE(rewrite_rule)= 1;
}
/*:312*/
#line 2965 "./marpa.w"

}
/*313:*/
#line 2997 "./marpa.w"

{
const IRL rewrite_irl= irl_new(g,internal_lhs_id,&rhs_id,1);
const RULE rewrite_rule= Co_RULE_of_IRL(rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
RULE_has_Virtual_LHS(rewrite_rule)= 1;
Real_SYM_Count_of_RULE(rewrite_rule)= 1;
}
/*:313*/
#line 2967 "./marpa.w"

/*314:*/
#line 3005 "./marpa.w"

{
RULE rewrite_rule;
IRL rewrite_irl;
SYMID temp_rhs[3];
int rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)
temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rewrite_irl= irl_new(g,internal_lhs_id,temp_rhs,rhs_ix);
rewrite_rule= Co_RULE_of_IRL(rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
RULE_has_Virtual_LHS(rewrite_rule)= 1;
RULE_has_Virtual_RHS(rewrite_rule)= 1;
Real_SYM_Count_of_RULE(rewrite_rule)= rhs_ix-1;
}

/*:314*/
#line 2968 "./marpa.w"

}

/*:310*/
#line 3094 "./marpa.w"

goto NEXT_XRL;
}
if(XRL_is_BNF(rule)&&XRL_is_Used(rule)){
/*324:*/
#line 3142 "./marpa.w"

{
int rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(symid);
if(SYM_is_Nulling(symbol))
continue;
if(SYM_is_Nullable(symbol))
{

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}
}
/*:324*/
#line 3098 "./marpa.w"


if(factor_count> 0){
/*327:*/
#line 3170 "./marpa.w"

{
const XRL chaf_xrl= rule;


int unprocessed_factor_count;

int factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);


int piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*332:*/
#line 3225 "./marpa.w"

SYMID chaf_virtual_symid;
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= first_factor_position-piece_start;
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*328:*/
#line 3195 "./marpa.w"

{
const SYMID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
const ISY chaf_virtual_isy= isy_new(g,SYM_by_ID(chaf_xrl_lhs_id));
SYM chaf_virtual_symbol= Buddy_of_ISY(chaf_virtual_isy);
SYM_is_Semantic(chaf_virtual_symbol)= 0;
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:328*/
#line 3233 "./marpa.w"

/*333:*/
#line 3252 "./marpa.w"

{
int remaining_rhs_length,piece_rhs_length;
/*334:*/
#line 3264 "./marpa.w"

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
{
int real_symbol_count= piece_rhs_length-1;
IRL chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
RULE chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3280 "./marpa.w"

}

/*:334*/
#line 3255 "./marpa.w"
;
/*335:*/
#line 3283 "./marpa.w"

{
int chaf_rule_length= Length_of_RULE(rule)-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;remaining_rhs_length++)
{
Marpa_Symbol_ID original_id= 
RHS_ID_of_RULE(rule,piece_start+remaining_rhs_length);
ISY nulling_isy= nulling_isy_by_xsyid[original_id];
if(nulling_isy){
SYM alias= Buddy_of_ISY(nulling_isy);
remaining_rhs[remaining_rhs_length]= ID_of_SYM(alias);
}else{
remaining_rhs[remaining_rhs_length]= original_id;
}
}
}
{
int real_symbol_count= remaining_rhs_length;
IRL chaf_irl= 
irl_new(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
RULE chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3305 "./marpa.w"

}

/*:335*/
#line 3256 "./marpa.w"
;
/*336:*/
#line 3310 "./marpa.w"
{
Marpa_Symbol_ID proper_id= RHS_ID_of_RULE(rule,first_factor_position);
SYM alias= Buddy_of_ISY(nulling_isy_by_xsyid[proper_id]);
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
ID_of_SYM(alias);
}
{
int real_symbol_count= piece_rhs_length-1;
IRL chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
RULE chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3321 "./marpa.w"

}

/*:336*/
#line 3257 "./marpa.w"
;
/*337:*/
#line 3330 "./marpa.w"

if(piece_start<nullable_suffix_ix){
int real_symbol_count= remaining_rhs_length;
IRL chaf_irl= irl_new(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
RULE chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3335 "./marpa.w"

}

/*:337*/
#line 3258 "./marpa.w"
;
}

/*:333*/
#line 3234 "./marpa.w"

factor_position_ix++;
}else{
int second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*328:*/
#line 3195 "./marpa.w"

{
const SYMID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
const ISY chaf_virtual_isy= isy_new(g,SYM_by_ID(chaf_xrl_lhs_id));
SYM chaf_virtual_symbol= Buddy_of_ISY(chaf_virtual_isy);
SYM_is_Semantic(chaf_virtual_symbol)= 0;
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:328*/
#line 3239 "./marpa.w"

/*339:*/
#line 3340 "./marpa.w"

{
int piece_rhs_length;
int real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;
/*340:*/
#line 3354 "./marpa.w"

{
RULE chaf_rule;
IRL chaf_irl;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3364 "./marpa.w"

}

/*:340*/
#line 3347 "./marpa.w"

/*341:*/
#line 3368 "./marpa.w"

{
RULE chaf_rule;
IRL chaf_irl;
ISY second_factor_isy;
second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
second_factor_isy= nulling_isy_by_xsyid[second_factor_proper_id];
piece_rhs[second_factor_piece_position]= 
second_factor_alias_id= ID_of_XSY(Buddy_of_ISY(second_factor_isy));
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3379 "./marpa.w"

}

/*:341*/
#line 3348 "./marpa.w"

/*342:*/
#line 3383 "./marpa.w"

{
RULE chaf_rule;
IRL chaf_irl;
ISY first_factor_isy;
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_isy= nulling_isy_by_xsyid[first_factor_proper_id];
piece_rhs[first_factor_piece_position]= 
first_factor_alias_id= ID_of_XSY(Buddy_of_ISY(first_factor_isy));
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3395 "./marpa.w"

}

/*:342*/
#line 3349 "./marpa.w"

/*343:*/
#line 3399 "./marpa.w"

{
RULE chaf_rule;
IRL chaf_irl;
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3406 "./marpa.w"

}

/*:343*/
#line 3350 "./marpa.w"

}

/*:339*/
#line 3240 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:332*/
#line 3186 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*344:*/
#line 3411 "./marpa.w"

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
/*345:*/
#line 3430 "./marpa.w"

{
RULE chaf_rule;
IRL chaf_irl;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3439 "./marpa.w"

}

/*:345*/
#line 3423 "./marpa.w"

/*346:*/
#line 3443 "./marpa.w"

{
RULE chaf_rule;
IRL chaf_irl;
ISY second_factor_isy;
second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
second_factor_isy= nulling_isy_by_xsyid[second_factor_proper_id];
piece_rhs[second_factor_piece_position]= 
second_factor_alias_id= ID_of_XSY(Buddy_of_ISY(second_factor_isy));
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3454 "./marpa.w"

}

/*:346*/
#line 3424 "./marpa.w"

/*347:*/
#line 3458 "./marpa.w"

{
RULE chaf_rule;
IRL chaf_irl;
ISY first_factor_isy;
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_isy= nulling_isy_by_xsyid[first_factor_proper_id];
piece_rhs[first_factor_piece_position]= 
first_factor_alias_id= ID_of_XSY(Buddy_of_ISY(first_factor_isy));
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3470 "./marpa.w"

}

/*:347*/
#line 3425 "./marpa.w"

/*348:*/
#line 3475 "./marpa.w"

{
RULE chaf_rule;
IRL chaf_irl;
if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3483 "./marpa.w"

}
}

/*:348*/
#line 3426 "./marpa.w"

}

/*:344*/
#line 3189 "./marpa.w"

}else{
/*349:*/
#line 3488 "./marpa.w"

{
int piece_rhs_length;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
int real_symbol_count;
int first_factor_position= factor_positions[factor_position_ix];
int first_factor_piece_position= 
factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*350:*/
#line 3503 "./marpa.w"

{
RULE chaf_rule;
IRL chaf_irl;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3512 "./marpa.w"

}

/*:350*/
#line 3498 "./marpa.w"

/*351:*/
#line 3517 "./marpa.w"

{
if(piece_start<nullable_suffix_ix)
{
RULE chaf_rule;
IRL chaf_irl;
ISY first_factor_isy;
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_isy= nulling_isy_by_xsyid[first_factor_proper_id];
first_factor_alias_id= ID_of_XSY(Buddy_of_ISY(first_factor_isy));
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_irl= irl_new(g,current_lhs_id,piece_rhs,piece_rhs_length);
chaf_rule= Co_RULE_of_IRL(chaf_irl);
/*352:*/
#line 3538 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
LHS_XRL_of_SYM(current_lhs)= chaf_xrl;
XRL_Offset_of_SYM(current_lhs)= piece_start;
}

/*:352*/
#line 3530 "./marpa.w"

}
}

/*:351*/
#line 3499 "./marpa.w"

}

/*:349*/
#line 3191 "./marpa.w"

}
}

/*:327*/
#line 3101 "./marpa.w"

}else{
IRL new_irl= irl_clone(g,rule);
Source_XRL_of_IRL(new_irl)= rule;
}
}
NEXT_XRL:;
}
}
/*:321*/
#line 2475 "./marpa.w"

/*354:*/
#line 3556 "./marpa.w"

{
const XSY start_xsy= SYM_by_ID(start_xsyid);
if(LIKELY(!SYM_is_Nulling(start_xsy))){
/*355:*/
#line 3564 "./marpa.w"
{
IRL new_start_irl;
RULE new_start_rule;

XSYID new_start_xsyid= -1;
const ISY new_start_isy= isy_new(g,start_xsy);
const XSY new_start_xsy= Buddy_of_ISY(new_start_isy);
new_start_xsyid= ID_of_SYM(new_start_xsy);
SYM_is_Semantic(new_start_xsy)= 0;
new_start_xsy->t_is_accessible= 1;
new_start_xsy->t_is_productive= 1;
new_start_xsy->t_is_start= 1;

start_xsy->t_is_start= 0;

new_start_irl= irl_new(g,new_start_xsyid,&start_xsyid,1);
new_start_rule= Co_RULE_of_IRL(new_start_irl);
RULE_has_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
g->t_start_irl= new_start_irl;
}

/*:355*/
#line 3560 "./marpa.w"

}
}

/*:354*/
#line 2476 "./marpa.w"


if(!G_is_Trivial(g)){
/*463:*/
#line 4813 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
AIM*const item_list_working_buffer
= my_obstack_alloc(&obs_precompute,irl_count*sizeof(AIM));
const SYMID ins_count= SYM_Count_of_G(g);
RULEID**irl_list_x_lh_sym= NULL;

/*:463*/
#line 2480 "./marpa.w"

/*466:*/
#line 4843 "./marpa.w"

{
IRLID irl_id;
const AVL_TREE lhs_avl_tree= 
_marpa_avl_create(sym_rule_cmp,NULL,alignof(struct sym_rule_pair));
struct sym_rule_pair*const p_sym_rule_pair_base= 
my_obstack_new(AVL_OBSTACK(lhs_avl_tree),struct sym_rule_pair,
irl_count);
struct sym_rule_pair*p_sym_rule_pairs= p_sym_rule_pair_base;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
const IRL irl= IRL_by_ID(irl_id);
const XRL xrl= Co_RULE_of_IRL(irl);
p_sym_rule_pairs->t_symid= LHS_ID_of_RULE(xrl);
p_sym_rule_pairs->t_ruleid= irl_id;
_marpa_avl_insert(lhs_avl_tree,p_sym_rule_pairs);
p_sym_rule_pairs++;
}
{
struct avl_traverser traverser;
struct sym_rule_pair*pair;
SYMID seen_symid= -1;
IRLID*const rule_data_base= 
my_obstack_new(&obs_precompute,IRLID,irl_count);
IRLID*p_rule_data= rule_data_base;
_marpa_avl_t_init(&traverser,lhs_avl_tree);

irl_list_x_lh_sym= 
my_obstack_new(&obs_precompute,IRLID*,ins_count+1);
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

/*:466*/
#line 2481 "./marpa.w"

/*391:*/
#line 3964 "./marpa.w"

{
IRLID irl_id;
AIMID ahfa_item_count= 0;
AIM base_item;
AIM current_item;
unsigned int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
const RULE rule= Co_RULE_of_IRL(irl);
/*393:*/
#line 4019 "./marpa.w"

{
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_RULE(rule);rhs_ix++)
{
SYMID rh_symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(rh_symid);
if(!SYM_is_Nulling(symbol))ahfa_item_count++;
}
ahfa_item_count++;
}

/*:393*/
#line 3974 "./marpa.w"

}
current_item= base_item= my_new(struct s_AHFA_item,ahfa_item_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*392:*/
#line 3994 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
const XRL xrl= Co_RULE_of_IRL(irl);
for(rhs_ix= 0;rhs_ix<Length_of_RULE(xrl);rhs_ix++)
{
SYMID rh_symid= RHS_ID_of_RULE(xrl,rhs_ix);
SYM symbol= SYM_by_ID(rh_symid);
if(!SYM_is_Nulling(symbol))
{
Last_Proper_SYMI_of_RULE(xrl)= symbol_instance_of_next_rule+rhs_ix;
/*394:*/
#line 4031 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:394*/
#line 4006 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*395:*/
#line 4040 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:395*/
#line 4015 "./marpa.w"

current_item++;
}

/*:392*/
#line 3979 "./marpa.w"

{
const RULE rule= Co_RULE_of_IRL(irl);
SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(ahfa_item_count==current_item-base_item);
AIM_Count_of_G(g)= ahfa_item_count;
g->t_AHFA_items= my_renew(struct s_AHFA_item,base_item,ahfa_item_count);
/*396:*/
#line 4054 "./marpa.w"

{
AIM items= g->t_AHFA_items;
AIMID item_id= (AIMID)ahfa_item_count;
for(item_id--;item_id>=0;item_id--)
{
AIM item= items+item_id;
RULE rule= RULE_of_AIM(item);
rule->t_first_aim= item;
}
}

/*:396*/
#line 3990 "./marpa.w"

/*401:*/
#line 4112 "./marpa.w"

{
Marpa_AHFA_Item_ID item_id;
AIM*sort_array= my_new(struct s_AHFA_item*,ahfa_item_count);
AIM items= g->t_AHFA_items;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)ahfa_item_count;item_id++)
{
sort_array[item_id]= items+item_id;
}
qsort(sort_array,(int)ahfa_item_count,sizeof(AIM),cmp_by_postdot_and_aimid);
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)ahfa_item_count;item_id++)
{
Sort_Key_of_AIM(sort_array[item_id])= item_id;
}
my_free(sort_array);
}

/*:401*/
#line 3991 "./marpa.w"

}

/*:391*/
#line 2482 "./marpa.w"

/*447:*/
#line 4467 "./marpa.w"

{
/*448:*/
#line 4485 "./marpa.w"

AHFA p_working_state;
const unsigned int initial_no_of_states= 2*AIM_Count_of_G(g);
AIM AHFA_item_0_p= g->t_AHFA_items;
const unsigned int symbol_count_of_g= SYM_Count_of_G(g);
Bit_Matrix prediction_matrix;
IRL*irl_by_sort_key= my_new(IRL,irl_count);
AVL_TREE duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
int ahfa_count_of_g;
AHFA ahfas_of_g;

/*:448*/
#line 4469 "./marpa.w"

/*449:*/
#line 4498 "./marpa.w"

/*450:*/
#line 4502 "./marpa.w"

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

/*:450*/
#line 4499 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:449*/
#line 4470 "./marpa.w"

/*475:*/
#line 5093 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_obs_create(&obs_precompute,symbol_count_of_g,symbol_count_of_g);
/*476:*/
#line 5101 "./marpa.w"

{
IRLID irl_id;
SYMID symid;
for(symid= 0;symid<(SYMID)symbol_count_of_g;symid++)
{

SYM symbol= SYM_by_ID(symid);
if(!SYM_is_LHS(symbol))continue;
matrix_bit_set(symbol_by_symbol_matrix,(unsigned int)symid,(unsigned int)symid);
}
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
SYMID from,to;
const IRL irl= IRL_by_ID(irl_id);
const XRL xrl= Co_RULE_of_IRL(irl);

const AIM item= xrl->t_first_aim;
from= LHS_ID_of_AIM(item);
to= Postdot_SYMID_of_AIM(item);

if(to<0)
continue;

matrix_bit_set(symbol_by_symbol_matrix,(unsigned int)from,(unsigned int)to);
}
}

/*:476*/
#line 5096 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*477:*/
#line 5135 "./marpa.w"
{
SYMID from_symid;
unsigned int*sort_key_by_irl_id= my_new(unsigned int,irl_count);
/*479:*/
#line 5159 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
irl_by_sort_key[irl_id]= IRL_by_ID(irl_id);
}
qsort(irl_by_sort_key,(int)irl_count,
sizeof(RULE),cmp_by_irl_sort_key);
}

/*:479*/
#line 5138 "./marpa.w"

/*481:*/
#line 5192 "./marpa.w"

{
IRLID sort_ordinal;
for(sort_ordinal= 0;sort_ordinal<irl_count;sort_ordinal++)
{
IRL irl= irl_by_sort_key[sort_ordinal];
sort_key_by_irl_id[ID_of_IRL(irl)]= sort_ordinal;
}
}

/*:481*/
#line 5139 "./marpa.w"

/*482:*/
#line 5202 "./marpa.w"

{
prediction_matrix= 
matrix_obs_create(&obs_precompute,symbol_count_of_g,
irl_count);
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
unsigned int sort_ordinal= 
sort_key_by_irl_id[rule_with_this_lhs_symbol];
matrix_bit_set(prediction_matrix,
(unsigned int)from_symid,sort_ordinal);

}
}
}
}
}

/*:482*/
#line 5140 "./marpa.w"

my_free(sort_key_by_irl_id);
}

/*:477*/
#line 5098 "./marpa.w"

}

/*:475*/
#line 4471 "./marpa.w"

/*457:*/
#line 4641 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
const IRL start_irl= g->t_start_irl;
const RULE start_rule= Co_RULE_of_IRL(start_irl);
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
(start_item)),irl_by_sort_key,
&states,duplicates,item_list_working_buffer
);
}

/*:457*/
#line 4472 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*451:*/
#line 4514 "./marpa.w"
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
/*460:*/
#line 4701 "./marpa.w"
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
transition_add(&obs_precompute,p_working_state,working_symbol,p_new_state);
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
transition_add(&obs_precompute,p_working_state,working_symbol,p_new_state);
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
irl_by_sort_key,&states,duplicates,
item_list_working_buffer);
}
else
{
SYMID lhs_id= LHS_ID_of_AIM(single_item_p);
SYMID*complete_symids= my_obstack_alloc(&g->t_obs,sizeof(SYMID));
*complete_symids= lhs_id;
Complete_SYMIDs_of_AHFA(p_new_state)= complete_symids;
completion_count_inc(&obs_precompute,p_new_state,lhs_id);
Complete_SYM_Count_of_AHFA(p_new_state)= 1;
p_new_state->t_postdot_sym_count= 0;
p_new_state->t_empty_transition= NULL;
/*462:*/
#line 4787 "./marpa.w"

{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYM_is_LHS(SYM_by_ID(predot_symid)))
{
Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:462*/
#line 4755 "./marpa.w"

}
}

/*:460*/
#line 4534 "./marpa.w"

}else{
/*467:*/
#line 4888 "./marpa.w"

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
transition_add(&obs_precompute,p_working_state,working_symbol,
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
/*468:*/
#line 4945 "./marpa.w"

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
completion_count_inc(&obs_precompute,p_new_state,
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

/*:468*/
#line 4938 "./marpa.w"

transition_add(&obs_precompute,p_working_state,working_symbol,
p_new_state);
/*470:*/
#line 5025 "./marpa.w"

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
irl_by_sort_key,
&states,
duplicates,
item_list_working_buffer
);
bv_free(predicted_rule_vector);
}
}

/*:470*/
#line 4942 "./marpa.w"

}

/*:467*/
#line 4536 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:451*/
#line 4474 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*452:*/
#line 4546 "./marpa.w"

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

/*:452*/
#line 4479 "./marpa.w"

/*454:*/
#line 4600 "./marpa.w"

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

/*:454*/
#line 4480 "./marpa.w"

/*453:*/
#line 4569 "./marpa.w"

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

/*:453*/
#line 4481 "./marpa.w"

/*455:*/
#line 4633 "./marpa.w"

my_free(irl_by_sort_key);
/*456:*/
#line 4637 "./marpa.w"

my_free(singleton_duplicates);
_marpa_avl_destroy(duplicates);

/*:456*/
#line 4635 "./marpa.w"


/*:455*/
#line 4482 "./marpa.w"

}

/*:447*/
#line 2483 "./marpa.w"

/*506:*/
#line 5534 "./marpa.w"
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

/*:506*/
#line 2484 "./marpa.w"

}
return_value= G_EVENT_COUNT(g);
FAILURE:;
my_obstack_free(&obs_precompute);
return return_value;
}
/*:286*//*296:*/
#line 2584 "./marpa.w"

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

/*:296*//*378:*/
#line 3880 "./marpa.w"

PRIVATE int aim_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:378*//*383:*/
#line 3918 "./marpa.w"

int _marpa_g_AHFA_item_count(Marpa_Grammar g){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 3920 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 3921 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:383*//*384:*/
#line 3925 "./marpa.w"

Marpa_IRL_ID _marpa_g_AHFA_item_irl(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 3928 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 3929 "./marpa.w"

/*1197:*/
#line 13563 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1197*/
#line 3930 "./marpa.w"

return IRLID_of_AIM(AIM_by_ID(item_id));
}

/*:384*//*386:*/
#line 3935 "./marpa.w"

int _marpa_g_AHFA_item_position(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 3938 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 3939 "./marpa.w"

/*1197:*/
#line 13563 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1197*/
#line 3940 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:386*//*388:*/
#line 3945 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_item_postdot(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 3948 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 3949 "./marpa.w"

/*1197:*/
#line 13563 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1197*/
#line 3950 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:388*//*389:*/
#line 3954 "./marpa.w"

int _marpa_g_AHFA_item_sort_key(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 3957 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 3958 "./marpa.w"

/*1197:*/
#line 13563 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1197*/
#line 3959 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:389*//*398:*/
#line 4073 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:398*//*400:*/
#line 4088 "./marpa.w"

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

/*:400*//*412:*/
#line 4239 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*426:*/
#line 4311 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;

/*:426*//*442:*/
#line 4411 "./marpa.w"
Leo_LHS_ID_of_AHFA(ahfa)= -1;
/*:442*/
#line 4242 "./marpa.w"

}

/*:412*//*420:*/
#line 4272 "./marpa.w"

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

/*:420*//*433:*/
#line 4338 "./marpa.w"

PRIVATE int AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:433*//*436:*/
#line 4352 "./marpa.w"

int _marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:436*//*437:*/
#line 4357 "./marpa.w"

int
_marpa_g_AHFA_state_item_count(Marpa_Grammar g,AHFAID AHFA_state_id)
{/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 4360 "./marpa.w"

AHFA state;
/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 4362 "./marpa.w"

/*1198:*/
#line 13568 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1198*/
#line 4363 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:437*//*438:*/
#line 4370 "./marpa.w"

Marpa_AHFA_Item_ID _marpa_g_AHFA_state_item(Marpa_Grammar g,
AHFAID AHFA_state_id,
int item_ix){
AHFA state;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 4375 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 4376 "./marpa.w"

/*1198:*/
#line 13568 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1198*/
#line 4377 "./marpa.w"

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

/*:438*//*439:*/
#line 4390 "./marpa.w"

int _marpa_g_AHFA_state_is_predict(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 4394 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 4395 "./marpa.w"

/*1198:*/
#line 13568 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1198*/
#line 4396 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:439*//*443:*/
#line 4412 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_state_leo_lhs_symbol(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 4415 "./marpa.w"

AHFA state;
/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 4417 "./marpa.w"

/*1198:*/
#line 13568 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1198*/
#line 4418 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:443*//*446:*/
#line 4439 "./marpa.w"

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

/*:446*//*469:*/
#line 5016 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,AVL_TREE duplicates)
{
const AHFA state_found= _marpa_avl_insert(duplicates,sought_state);
return state_found;
}

/*:469*//*480:*/
#line 5170 "./marpa.w"

PRIVATE_NOT_INLINE int
cmp_by_irl_sort_key(const void*ap,const void*bp)
{
const IRL irl_a= *(IRL*)ap;
const IRL irl_b= *(IRL*)bp;
unsigned int sort_key_a;
unsigned int sort_key_b;
SET_1ST_PASS_SORT_KEY_FOR_IRL(sort_key_a,irl_a);
SET_1ST_PASS_SORT_KEY_FOR_IRL(sort_key_b,irl_b);
if(sort_key_a!=sort_key_b)
return sort_key_a-sort_key_b;
{
IRLID a_id= ID_of_IRL(irl_a);
IRLID b_id= ID_of_IRL(irl_b);
return a_id-b_id;
}
}

/*:480*//*483:*/
#line 5237 "./marpa.w"

PRIVATE_NOT_INLINE AHFA
create_predicted_AHFA_state(
GRAMMAR g,
Bit_Vector prediction_rule_vector,
IRL*irl_by_sort_key,
DQUEUE states_p,
AVL_TREE duplicates,
AIM*item_list_working_buffer
)
{
AHFA p_new_state;
int item_list_ix= 0;
int no_of_items_in_new_state= bv_count(prediction_rule_vector);
if(no_of_items_in_new_state==0)
return NULL;
{
unsigned int start,min,max;
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2)
{
unsigned int sort_ordinal;
for(sort_ordinal= min;sort_ordinal<=max;sort_ordinal++)
{

const IRL irl= irl_by_sort_key[sort_ordinal];
XRL xrl= Co_RULE_of_IRL(irl);
item_list_working_buffer[item_list_ix++]= xrl->t_first_aim;
}
}
}
p_new_state= DQUEUE_PUSH((*states_p),AHFA_Object);
AHFA_initialize(p_new_state);
p_new_state->t_items= item_list_working_buffer;
p_new_state->t_item_count= no_of_items_in_new_state;
{
AHFA queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state)
{


(void)DQUEUE_POP((*states_p),AHFA_Object);
return queued_AHFA_state;
}
}

p_new_state->t_key.t_id= 
p_new_state-DQUEUE_BASE((*states_p),AHFA_Object);
{
int i;
AIM*const final_aim_list= p_new_state->t_items= 
my_obstack_alloc(&g->t_obs,no_of_items_in_new_state*sizeof(AIM));
for(i= 0;i<no_of_items_in_new_state;i++)
{
final_aim_list[i]= item_list_working_buffer[i];
}
}
AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_empty_transition= NULL;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
Complete_SYM_Count_of_AHFA(p_new_state)= 0;
/*484:*/
#line 5302 "./marpa.w"

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

/*:484*/
#line 5298 "./marpa.w"

return p_new_state;
}

/*:483*//*495:*/
#line 5411 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:495*//*496:*/
#line 5417 "./marpa.w"

PRIVATE int completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:496*//*497:*/
#line 5424 "./marpa.w"

PRIVATE
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,int aim_ix)
{
URTRANS transition;
transition= my_obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:497*//*498:*/
#line 5435 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g)
{
int symbol_count= SYM_Count_of_G(g);
int symid= 0;
TRANS*transitions= my_obstack_new(&g->t_obs,TRANS,symbol_count);
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:498*//*499:*/
#line 5447 "./marpa.w"

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

/*:499*//*500:*/
#line 5461 "./marpa.w"

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

/*:500*//*502:*/
#line 5476 "./marpa.w"

int _marpa_g_AHFA_state_transitions(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id,
int*buffer,
int buffer_size
){

/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 5483 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
int symbol_count;
int ix= 0;
const int max_ix= buffer_size/sizeof(*buffer);
const int max_results= max_ix/2;





/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 5496 "./marpa.w"

/*1198:*/
#line 13568 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1198*/
#line 5497 "./marpa.w"

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

/*:502*//*505:*/
#line 5517 "./marpa.w"

AHFAID _marpa_g_AHFA_state_empty_transition(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 5522 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 5523 "./marpa.w"

/*1198:*/
#line 13568 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1198*/
#line 5524 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:505*//*510:*/
#line 5560 "./marpa.w"

PRIVATE INPUT
input_new(GRAMMAR g)
{
INPUT input= my_slice_new(struct s_input);
my_obstack_init(TOK_Obs_of_I(input));
/*513:*/
#line 5573 "./marpa.w"

input->t_ref_count= 1;

/*:513*//*521:*/
#line 5632 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:521*/
#line 5566 "./marpa.w"

return input;
}

/*:510*//*514:*/
#line 5577 "./marpa.w"

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

/*:514*//*515:*/
#line 5590 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:515*//*516:*/
#line 5603 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
my_obstack_free(TOK_Obs_of_I(input));
my_slice_free(struct s_input,input);
}

/*:516*//*525:*/
#line 5660 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
int symbol_count_of_g;
/*1189:*/
#line 13524 "./marpa.w"
void*const failure_indicator= NULL;
/*:1189*/
#line 5665 "./marpa.w"

/*1192:*/
#line 13538 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1192*/
#line 5666 "./marpa.w"

r= my_slice_new(struct marpa_r);
symbol_count_of_g= SYM_Count_of_G(g);
/*585:*/
#line 6030 "./marpa.w"
my_obstack_init(&r->t_obs);
/*:585*/
#line 5669 "./marpa.w"

/*528:*/
#line 5676 "./marpa.w"

r->t_ref_count= 1;

/*:528*//*536:*/
#line 5746 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:536*//*538:*/
#line 5755 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:538*//*542:*/
#line 5779 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:542*//*546:*/
#line 5802 "./marpa.w"
r->t_furthest_earleme= 0;
/*:546*//*550:*/
#line 5815 "./marpa.w"
r->t_sym_workarea= NULL;
/*:550*//*554:*/
#line 5826 "./marpa.w"
r->t_workarea2= NULL;
/*:554*//*558:*/
#line 5846 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:558*//*562:*/
#line 5869 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:562*//*577:*/
#line 5970 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:577*//*581:*/
#line 6006 "./marpa.w"
r->t_is_exhausted= 0;
/*:581*//*605:*/
#line 6128 "./marpa.w"

r->t_earley_set_count= 0;

/*:605*//*610:*/
#line 6174 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:610*//*631:*/
#line 6436 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:631*//*661:*/
#line 6818 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:661*//*696:*/
#line 7277 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:696*//*729:*/
#line 7762 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:729*//*733:*/
#line 7796 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:733*//*754:*/
#line 8104 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:754*//*758:*/
#line 8115 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:758*//*762:*/
#line 8126 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:762*//*831:*/
#line 8980 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:831*//*1154:*/
#line 13179 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1154*/
#line 5670 "./marpa.w"

return r;
}

/*:525*//*529:*/
#line 5680 "./marpa.w"

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

/*:529*//*530:*/
#line 5698 "./marpa.w"

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

/*:530*//*531:*/
#line 5712 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 5716 "./marpa.w"

/*533:*/
#line 5733 "./marpa.w"
input_unref(input);

/*:533*//*607:*/
#line 6152 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
my_free(EIMs_of_ES(set));
}
}

/*:607*//*734:*/
#line 7798 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:734*//*756:*/
#line 8108 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:756*//*760:*/
#line 8119 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:760*//*763:*/
#line 8127 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:763*//*832:*/
#line 8982 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:832*//*1155:*/
#line 13181 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1155*/
#line 5717 "./marpa.w"

grammar_unref(g);
my_free(r->t_sym_workarea);
my_free(r->t_workarea2);
/*560:*/
#line 5855 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:560*//*564:*/
#line 5872 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:564*/
#line 5721 "./marpa.w"

/*586:*/
#line 6031 "./marpa.w"
my_obstack_free(&r->t_obs);

/*:586*/
#line 5722 "./marpa.w"

my_slice_free(struct marpa_r,r);
}

/*:531*//*539:*/
#line 5763 "./marpa.w"

unsigned int marpa_r_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:539*//*540:*/
#line 5768 "./marpa.w"

PRIVATE ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:540*//*543:*/
#line 5781 "./marpa.w"

int marpa_r_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:543*//*544:*/
#line 5787 "./marpa.w"

int marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,int threshold)
{
r->t_earley_item_warning_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
return 1;
}

/*:544*//*547:*/
#line 5803 "./marpa.w"

unsigned int marpa_r_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:547*//*566:*/
#line 5887 "./marpa.w"

int marpa_r_terminals_expected(struct marpa_r*r,Marpa_Symbol_ID*buffer)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 5890 "./marpa.w"

/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 5891 "./marpa.w"

unsigned int min,max,start;
int ix= 0;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 5894 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 5895 "./marpa.w"

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

/*:566*//*578:*/
#line 5976 "./marpa.w"

int marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 5979 "./marpa.w"

/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 5980 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 5981 "./marpa.w"

return r->t_use_leo_flag;
}
/*:578*//*579:*/
#line 5984 "./marpa.w"

int marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 5988 "./marpa.w"

/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 5989 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 5990 "./marpa.w"

/*1199:*/
#line 13577 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1199*/
#line 5991 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:579*//*583:*/
#line 6016 "./marpa.w"

int marpa_r_is_exhausted(struct marpa_r*r)
{
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6019 "./marpa.w"

/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6020 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 6021 "./marpa.w"

return R_is_Exhausted(r);
}

/*:583*//*588:*/
#line 6035 "./marpa.w"

Marpa_Error_Code marpa_r_error(Marpa_Recognizer r,const char**p_error_string)
{
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6038 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:588*//*590:*/
#line 6044 "./marpa.w"

int marpa_r_event(Marpa_Recognizer r,Marpa_Event public_event,int ix)
{
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6047 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:590*//*606:*/
#line 6132 "./marpa.w"

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
/*1160:*/
#line 13225 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1160*/
#line 6147 "./marpa.w"

return set;
}

/*:606*//*611:*/
#line 6177 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6180 "./marpa.w"

/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6181 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6183 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:611*//*612:*/
#line 6191 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6194 "./marpa.w"

/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6195 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6196 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:612*//*613:*/
#line 6200 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const int es_does_not_exist= -1;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6204 "./marpa.w"

/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6205 "./marpa.w"

ES earley_set;
/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 6207 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 6208 "./marpa.w"

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

/*:613*//*615:*/
#line 6224 "./marpa.w"

int marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6227 "./marpa.w"

ES earley_set;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6229 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 6230 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 6231 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_ES_ORDINAL);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:615*//*624:*/
#line 6327 "./marpa.w"

PRIVATE EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1189:*/
#line 13524 "./marpa.w"
void*const failure_indicator= NULL;
/*:1189*/
#line 6331 "./marpa.w"

/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6332 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const int count= ++EIM_Count_of_ES(set);
/*626:*/
#line 6379 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_EIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:626*/
#line 6337 "./marpa.w"

new_item= my_obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:624*//*625:*/
#line 6347 "./marpa.w"

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

/*:625*//*629:*/
#line 6411 "./marpa.w"

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

/*:629*//*636:*/
#line 6476 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const int es_does_not_exist= -1;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6482 "./marpa.w"

/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6483 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6484 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*637:*/
#line 6507 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*663:*/
#line 6857 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:663*/
#line 6510 "./marpa.w"

}

/*:637*/
#line 6491 "./marpa.w"

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

/*:636*//*638:*/
#line 6513 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const int eim_does_not_exist= -1;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6518 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6522 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6523 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*637:*/
#line 6507 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*663:*/
#line 6857 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:663*/
#line 6510 "./marpa.w"

}

/*:637*/
#line 6527 "./marpa.w"

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

/*:638*//*640:*/
#line 6556 "./marpa.w"

PRIVATE void trace_earley_item_clear(struct marpa_r*r)
{
/*639:*/
#line 6553 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:639*/
#line 6559 "./marpa.w"

trace_source_link_clear(r);
}

/*:640*//*641:*/
#line 6563 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6566 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6568 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6569 "./marpa.w"

if(!item){
/*639:*/
#line 6553 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:639*/
#line 6571 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:641*//*648:*/
#line 6644 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6648 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6651 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6652 "./marpa.w"

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

/*:648*//*649:*/
#line 6666 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6670 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6672 "./marpa.w"

EIM base_earley_item;
/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6674 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:649*//*650:*/
#line 6684 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6688 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6691 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6692 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:650*//*654:*/
#line 6726 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6730 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6732 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6733 "./marpa.w"

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


/*:654*//*658:*/
#line 6782 "./marpa.w"

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
/*:658*//*659:*/
#line 6802 "./marpa.w"

PRIVATE PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:659*//*662:*/
#line 6832 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6837 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6841 "./marpa.w"

/*663:*/
#line 6857 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:663*/
#line 6842 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6843 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 6844 "./marpa.w"

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

/*:662*//*664:*/
#line 6867 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6871 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6874 "./marpa.w"

PIM*pim_sym_p;
/*663:*/
#line 6857 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:663*/
#line 6876 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6877 "./marpa.w"

if(!current_earley_set){
/*639:*/
#line 6553 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:639*/
#line 6879 "./marpa.w"

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

/*:664*//*665:*/
#line 6898 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6903 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6907 "./marpa.w"


pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*663:*/
#line 6857 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:663*/
#line 6911 "./marpa.w"

if(!pim_sym_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6916 "./marpa.w"

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

/*:665*//*666:*/
#line 6936 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_postdot_item_symbol(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 6939 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 6941 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 6942 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:666*//*682:*/
#line 7070 "./marpa.w"
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

/*:682*//*687:*/
#line 7146 "./marpa.w"

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

/*:687*//*688:*/
#line 7174 "./marpa.w"

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

/*:688*//*690:*/
#line 7221 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*691:*/
#line 7238 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= new_link;
}

/*:691*/
#line 7229 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*692:*/
#line 7247 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= new_link;
First_Token_Link_of_EIM(item)= NULL;
}

/*:692*/
#line 7231 "./marpa.w"

return;
case SOURCE_IS_LEO:/*693:*/
#line 7256 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= new_link;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= NULL;
}

/*:693*/
#line 7233 "./marpa.w"

return;
}
}

/*:690*//*698:*/
#line 7288 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7291 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7295 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7296 "./marpa.w"

/*712:*/
#line 7515 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:712*/
#line 7297 "./marpa.w"

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

/*:698*//*701:*/
#line 7332 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7335 "./marpa.w"

SRCL full_link;
EIM item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7338 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7339 "./marpa.w"

/*712:*/
#line 7515 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:712*/
#line 7340 "./marpa.w"

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

/*:701*//*703:*/
#line 7363 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7366 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7370 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7371 "./marpa.w"

/*712:*/
#line 7515 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:712*/
#line 7372 "./marpa.w"

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

/*:703*//*706:*/
#line 7406 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7409 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7413 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7414 "./marpa.w"

/*712:*/
#line 7515 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:712*/
#line 7415 "./marpa.w"

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

/*:706*//*708:*/
#line 7439 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_leo_link_trace(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7443 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7447 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7448 "./marpa.w"

/*712:*/
#line 7515 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:712*/
#line 7449 "./marpa.w"

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

/*:708*//*711:*/
#line 7485 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_leo_link_trace(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7489 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7493 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7494 "./marpa.w"

/*712:*/
#line 7515 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:712*/
#line 7495 "./marpa.w"

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

/*:711*//*713:*/
#line 7524 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:713*//*714:*/
#line 7540 "./marpa.w"

AHFAID marpa_r_source_predecessor_state(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7543 "./marpa.w"

unsigned int source_type;
SRC source;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7546 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7547 "./marpa.w"

source_type= r->t_trace_source_type;
/*721:*/
#line 7691 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:721*/
#line 7549 "./marpa.w"

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

/*:714*//*715:*/
#line 7581 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,int*value_p)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7584 "./marpa.w"

unsigned int source_type;
SRC source;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7587 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7588 "./marpa.w"

source_type= r->t_trace_source_type;
/*721:*/
#line 7691 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:721*/
#line 7590 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:715*//*717:*/
#line 7613 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7616 "./marpa.w"

unsigned int source_type;
SRC source;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7619 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7620 "./marpa.w"

source_type= r->t_trace_source_type;
/*721:*/
#line 7691 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:721*/
#line 7622 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:717*//*720:*/
#line 7659 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7662 "./marpa.w"

const EARLEME no_predecessor= -1;
unsigned int source_type;
SRC source;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7666 "./marpa.w"

/*1202:*/
#line 13593 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 13594 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 13595 "./marpa.w"


/*:1202*/
#line 7667 "./marpa.w"

source_type= r->t_trace_source_type;
/*721:*/
#line 7691 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:721*/
#line 7669 "./marpa.w"

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

/*:720*//*736:*/
#line 7804 "./marpa.w"

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

/*:736*//*738:*/
#line 7848 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:738*//*739:*/
#line 7865 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:739*//*740:*/
#line 7880 "./marpa.w"

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

/*:740*//*741:*/
#line 7899 "./marpa.w"
int marpa_r_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7905 "./marpa.w"

const int symbol_count_of_g= SYM_Count_of_G(g);
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7907 "./marpa.w"

/*1199:*/
#line 13577 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1199*/
#line 7908 "./marpa.w"

Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g)){
/*582:*/
#line 6007 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:582*/
#line 7911 "./marpa.w"

return 1;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
/*555:*/
#line 5827 "./marpa.w"

{
const unsigned int sym_workarea_size= sizeof(void*)*symbol_count_of_g;
/*551:*/
#line 5816 "./marpa.w"

r->t_sym_workarea= my_malloc(sym_workarea_size);

/*:551*/
#line 5830 "./marpa.w"

r->t_workarea2= my_malloc(2u*sym_workarea_size);
}

/*:555*/
#line 7915 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*559:*/
#line 5850 "./marpa.w"
{
r->t_bv_sym= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym2= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym3= bv_create((unsigned int)symbol_count_of_g);
}
/*:559*//*563:*/
#line 5870 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((unsigned int)symbol_count_of_g);
/*:563*/
#line 7917 "./marpa.w"

/*755:*/
#line 8105 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT2(r->t_eim_work_stack,EIM);
/*:755*//*759:*/
#line 8116 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT2(r->t_completion_stack,EIM);
/*:759*/
#line 7918 "./marpa.w"

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

/*:741*//*748:*/
#line 7986 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID token_id,
int value,
int length)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 7993 "./marpa.w"

/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 7994 "./marpa.w"

const int duplicate_token_indicator= -3;
const int unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1201:*/
#line 13587 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1201*/
#line 8000 "./marpa.w"

/*749:*/
#line 8008 "./marpa.w"
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

/*:749*/
#line 8001 "./marpa.w"

/*751:*/
#line 8039 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:751*/
#line 8002 "./marpa.w"

/*750:*/
#line 8024 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return failure_indicator;
}
}

/*:750*/
#line 8003 "./marpa.w"

/*752:*/
#line 8062 "./marpa.w"

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

/*:752*/
#line 8004 "./marpa.w"

return current_earleme;
}

/*:748*//*765:*/
#line 8146 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(struct marpa_r*r)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 8150 "./marpa.w"

/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 8151 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
int count_of_expected_terminals;
/*1201:*/
#line 13587 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1201*/
#line 8156 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*766:*/
#line 8184 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*582:*/
#line 6007 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:582*/
#line 8188 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:766*/
#line 8160 "./marpa.w"

/*768:*/
#line 8209 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:768*/
#line 8161 "./marpa.w"

/*767:*/
#line 8196 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:767*/
#line 8162 "./marpa.w"

/*769:*/
#line 8215 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*770:*/
#line 8222 "./marpa.w"

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

/*:770*/
#line 8219 "./marpa.w"

}

/*:769*/
#line 8163 "./marpa.w"

/*771:*/
#line 8249 "./marpa.w"
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

/*:771*/
#line 8164 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*772:*/
#line 8268 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
int count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
int symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*773:*/
#line 8281 "./marpa.w"

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
/*774:*/
#line 8304 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*775:*/
#line 8320 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:775*/
#line 8313 "./marpa.w"

}
/*776:*/
#line 8327 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:776*/
#line 8315 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:774*/
#line 8292 "./marpa.w"

}
else
{
/*777:*/
#line 8337 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*775:*/
#line 8320 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:775*/
#line 8346 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:777*/
#line 8296 "./marpa.w"

break;


}
}
}

/*:773*/
#line 8277 "./marpa.w"

}
}

/*:772*/
#line 8167 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


/*582:*/
#line 6007 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:582*/
#line 8177 "./marpa.w"

event_new(g,MARPA_EVENT_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:765*//*778:*/
#line 8351 "./marpa.w"

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

/*:778*//*779:*/
#line 8372 "./marpa.w"

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

/*:779*//*785:*/
#line 8416 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,ES current_earley_set)
{
void**const pim_workarea= r->t_sym_workarea;
/*532:*/
#line 5730 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:532*/
#line 8421 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*786:*/
#line 8438 "./marpa.w"
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

/*:786*/
#line 8427 "./marpa.w"

if(r->t_is_using_leo){
/*790:*/
#line 8496 "./marpa.w"

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
/*791:*/
#line 8530 "./marpa.w"
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

/*:791*/
#line 8516 "./marpa.w"

}
}
}
}
}
}

/*:790*/
#line 8429 "./marpa.w"

/*800:*/
#line 8615 "./marpa.w"
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

/*803:*/
#line 8674 "./marpa.w"
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

/*:803*/
#line 8633 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*809:*/
#line 8766 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:809*/
#line 8635 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*811:*/
#line 8787 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:811*/
#line 8641 "./marpa.w"

continue;
}
/*804:*/
#line 8689 "./marpa.w"
{
void**const lim_chain= r->t_workarea2;
int lim_chain_ix;
/*807:*/
#line 8710 "./marpa.w"
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

/*803:*/
#line 8674 "./marpa.w"
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

/*:803*/
#line 8736 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(unsigned int)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:807*/
#line 8692 "./marpa.w"

/*808:*/
#line 8755 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*809:*/
#line 8766 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:809*/
#line 8759 "./marpa.w"

}else{
/*811:*/
#line 8787 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:811*/
#line 8761 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:808*/
#line 8693 "./marpa.w"

}

/*:804*/
#line 8644 "./marpa.w"

}
}
}

/*:800*/
#line 8430 "./marpa.w"

}
/*812:*/
#line 8793 "./marpa.w"
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

/*:812*/
#line 8432 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:785*//*833:*/
#line 8985 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
my_obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:833*//*834:*/
#line 8993 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:834*//*835:*/
#line 8999 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)my_obstack_free(&stack->t_obs);
stack->t_base= NULL;
}

/*:835*//*836:*/
#line 9006 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= my_obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:836*//*837:*/
#line 9016 "./marpa.w"

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

/*:837*//*838:*/
#line 9032 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:838*//*842:*/
#line 9095 "./marpa.w"

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

/*:842*//*878:*/
#line 9699 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:878*//*879:*/
#line 9711 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:879*//*885:*/
#line 9826 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= my_obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:885*//*887:*/
#line 9849 "./marpa.w"

PRIVATE
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:887*//*914:*/
#line 10286 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10289 "./marpa.w"

/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10290 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10291 "./marpa.w"

return AND_Count_of_B(b);
}

/*:914*//*916:*/
#line 10317 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10322 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10323 "./marpa.w"

/*915:*/
#line 10295 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:915*/
#line 10324 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:916*//*917:*/
#line 10328 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10333 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10334 "./marpa.w"

/*915:*/
#line 10295 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:915*/
#line 10335 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:917*//*918:*/
#line 10344 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10349 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10350 "./marpa.w"

/*915:*/
#line 10295 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:915*/
#line 10351 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:918*//*919:*/
#line 10360 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10365 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10366 "./marpa.w"

/*915:*/
#line 10295 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:915*/
#line 10367 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:919*//*920:*/
#line 10376 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK token;
AND and_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10382 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10383 "./marpa.w"

/*915:*/
#line 10295 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:915*/
#line 10384 "./marpa.w"

token= and_node_token(and_node);
if(token){
if(value_p)
*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
return-1;
}
/*:920*//*921:*/
#line 10393 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:921*//*935:*/
#line 10457 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1189:*/
#line 13524 "./marpa.w"
void*const failure_indicator= NULL;
/*:1189*/
#line 10461 "./marpa.w"

/*936:*/
#line 10504 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int symbol_count_of_g= SYM_Count_of_G(g);
const IRLID irl_count= IRL_Count_of_G(g);
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

/*:936*//*939:*/
#line 10527 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:939*/
#line 10462 "./marpa.w"

INPUT input;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10464 "./marpa.w"

/*1200:*/
#line 13582 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1200*/
#line 10465 "./marpa.w"

b= my_slice_new(*b);
/*865:*/
#line 9454 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:865*//*931:*/
#line 10436 "./marpa.w"

b->t_is_obstack_initialized= 1;
my_obstack_init(&OBS_of_B(b));
/*:931*//*952:*/
#line 10676 "./marpa.w"

b->t_ref_count= 1;

/*:952*//*959:*/
#line 10738 "./marpa.w"

B_is_Nulling(b)= 0;

/*:959*/
#line 10467 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*940:*/
#line 10530 "./marpa.w"

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

/*:940*/
#line 10477 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(SYM_by_ID(g->t_start_xsyid)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*944:*/
#line 10604 "./marpa.w"

{
int eim_ix;
EIM*const earley_items= EIMs_of_ES(end_of_parse_earley_set);
const IRL start_irl= g->t_start_irl;
const IRLID sought_irl_id= ID_of_IRL(start_irl);
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
if(IRLID_of_AIM(ahfa_item)==sought_irl_id){
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

/*:944*/
#line 10485 "./marpa.w"

if(!start_eim)goto NO_PARSE;
my_obstack_init(&bocage_setup_obs);
/*941:*/
#line 10552 "./marpa.w"

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

/*:941*/
#line 10488 "./marpa.w"

/*840:*/
#line 9054 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*841:*/
#line 9082 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:841*/
#line 9063 "./marpa.w"

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
/*843:*/
#line 9123 "./marpa.w"

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
/*841:*/
#line 9082 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:841*/
#line 9151 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:843*/
#line 9076 "./marpa.w"

/*845:*/
#line 9181 "./marpa.w"

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
/*841:*/
#line 9082 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:841*/
#line 9217 "./marpa.w"

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
/*841:*/
#line 9082 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:841*/
#line 9230 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:845*/
#line 9077 "./marpa.w"

/*846:*/
#line 9240 "./marpa.w"

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
/*841:*/
#line 9082 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:841*/
#line 9273 "./marpa.w"

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
/*841:*/
#line 9082 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:841*/
#line 9289 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:846*/
#line 9078 "./marpa.w"

}
}

/*:840*/
#line 10489 "./marpa.w"

/*867:*/
#line 9472 "./marpa.w"

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
/*1166:*/
#line 13282 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1166*/
#line 9492 "./marpa.w"

/*868:*/
#line 9500 "./marpa.w"

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
/*869:*/
#line 9520 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1166:*/
#line 13282 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1166*/
#line 9530 "./marpa.w"

/*871:*/
#line 9548 "./marpa.w"

{
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const IRL irl= IRL_of_AIM(ahfa_item);
/*872:*/
#line 9577 "./marpa.w"

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


/*:872*/
#line 9558 "./marpa.w"

or_node= last_or_node;
PSL_Datum(or_psl,ahfa_item_symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= Origin_Ord_of_EIM(work_earley_item);
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= irl;
Position_of_OR(or_node)= 
ahfa_item_symbol_instance-SYMI_of_IRL(irl)+1;
DANDs_of_OR(or_node)= NULL;
}
psia_or_node= or_node;
}
}

/*:871*/
#line 9531 "./marpa.w"

/*874:*/
#line 9602 "./marpa.w"

{
const int null_count= Null_Count_of_AIM(ahfa_item);
if(null_count> 0)
{
const IRL irl= IRL_of_AIM(ahfa_item);
const RULE rule= Co_RULE_of_IRL(irl);
const int symbol_instance_of_rule= SYMI_of_IRL(irl);
const int first_null_symbol_instance= 
ahfa_item_symbol_instance<0?symbol_instance_of_rule:ahfa_item_symbol_instance+1;
int i;
for(i= 0;i<null_count;i++)
{
const int symbol_instance= first_null_symbol_instance+i;
OR or_node= PSL_Datum(or_psl,symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal){
DAND draft_and_node;
const int rhs_ix= symbol_instance-symbol_instance_of_rule;
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_SYMID(RHS_ID_of_RULE(rule,rhs_ix));
/*872:*/
#line 9577 "./marpa.w"

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


/*:872*/
#line 9622 "./marpa.w"

or_node= PSL_Datum(or_psl,symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= work_origin_ordinal;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= irl;
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

/*:874*/
#line 9532 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*875:*/
#line 9640 "./marpa.w"
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
/*877:*/
#line 9680 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const IRL path_irl= IRL_of_AIM(path_ahfa_item);
const RULE path_rule= Co_RULE_of_IRL(path_irl);
const int symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*880:*/
#line 9722 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1166:*/
#line 13282 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1166*/
#line 9729 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*872:*/
#line 9577 "./marpa.w"

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


/*:872*/
#line 9733 "./marpa.w"

PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= 
symbol_instance_of_path_ahfa_item-SYMI_of_IRL(path_irl)+1;
DANDs_of_OR(or_node)= NULL;
}
}
}

/*:880*/
#line 9691 "./marpa.w"

/*881:*/
#line 9749 "./marpa.w"

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
const int rhs_ix= symbol_instance-SYMI_of_IRL(path_irl);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_SYMID(RHS_ID_of_RULE(path_rule,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_RULE(path_rule))
MARPA_ASSERT(symbol_instance>=0)
/*872:*/
#line 9577 "./marpa.w"

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


/*:872*/
#line 9766 "./marpa.w"

PSL_Datum(this_earley_set_psl,symbol_instance)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
DANDs_of_OR(or_node)= draft_and_node= 
draft_and_node_new(&bocage_setup_obs,predecessor,cause);
Next_DAND_of_DAND(draft_and_node)= NULL;
}
MARPA_ASSERT(Position_of_OR(or_node)<=
SYMI_of_IRL(path_irl)+Length_of_RULE(path_rule))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_RULE(path_rule))
}
}

/*:881*/
#line 9692 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:877*/
#line 9662 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:875*/
#line 9540 "./marpa.w"

}

/*:869*/
#line 9514 "./marpa.w"

}
}
}
}

/*:868*/
#line 9493 "./marpa.w"

/*888:*/
#line 9859 "./marpa.w"

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
/*890:*/
#line 9896 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const int work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*891:*/
#line 9912 "./marpa.w"
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
/*892:*/
#line 9944 "./marpa.w"

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
/*893:*/
#line 9973 "./marpa.w"

{
if(higher_path_leo_item){
/*897:*/
#line 10017 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:897*/
#line 9976 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:893*/
#line 9959 "./marpa.w"

/*895:*/
#line 9987 "./marpa.w"

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

/*:895*/
#line 9960 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*893:*/
#line 9973 "./marpa.w"

{
if(higher_path_leo_item){
/*897:*/
#line 10017 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:897*/
#line 9976 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:893*/
#line 9967 "./marpa.w"

/*898:*/
#line 10027 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const int origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:898*/
#line 9968 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:892*/
#line 9934 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:891*/
#line 9907 "./marpa.w"

/*899:*/
#line 10037 "./marpa.w"

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
/*900:*/
#line 10067 "./marpa.w"

{
OR dand_predecessor;
/*901:*/
#line 10075 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:901*/
#line 10070 "./marpa.w"

draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:900*/
#line 10059 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:899*/
#line 9908 "./marpa.w"

/*902:*/
#line 10086 "./marpa.w"

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
/*903:*/
#line 10126 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*901:*/
#line 10075 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:901*/
#line 10134 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:903*/
#line 10117 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:902*/
#line 9909 "./marpa.w"

}

/*:890*/
#line 9874 "./marpa.w"

}
}
}
}
}

/*:888*/
#line 9494 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= my_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:867*/
#line 10490 "./marpa.w"

/*911:*/
#line 10241 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*904:*/
#line 10140 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
int or_node_id= 0;
psar_init(and_psar,irl_count+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*906:*/
#line 10172 "./marpa.w"

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

/*:906*/
#line 10150 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:904*/
#line 10244 "./marpa.w"

/*912:*/
#line 10248 "./marpa.w"

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

/*:912*/
#line 10245 "./marpa.w"

}

/*:911*/
#line 10491 "./marpa.w"

/*945:*/
#line 10633 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:945*/
#line 10492 "./marpa.w"
;
my_obstack_free(&bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
input_unref(input);
if(b){
/*955:*/
#line 10713 "./marpa.w"

/*866:*/
#line 9461 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:866*/
#line 10714 "./marpa.w"
;
/*932:*/
#line 10439 "./marpa.w"

if(b->t_is_obstack_initialized){
my_obstack_free(&OBS_of_B(b));
b->t_is_obstack_initialized= 0;
}

/*:932*/
#line 10715 "./marpa.w"
;

/*:955*/
#line 10499 "./marpa.w"
;
}
return NULL;
}

/*:935*//*947:*/
#line 10656 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10659 "./marpa.w"

return g;
}

/*:947*//*949:*/
#line 10665 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10668 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10669 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10670 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:949*//*953:*/
#line 10680 "./marpa.w"

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

/*:953*//*954:*/
#line 10698 "./marpa.w"

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

/*:954*//*956:*/
#line 10720 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10724 "./marpa.w"

input_unref(input);
if(b)
{
/*955:*/
#line 10713 "./marpa.w"

/*866:*/
#line 9461 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:866*/
#line 10714 "./marpa.w"
;
/*932:*/
#line 10439 "./marpa.w"

if(b->t_is_obstack_initialized){
my_obstack_free(&OBS_of_B(b));
b->t_is_obstack_initialized= 0;
}

/*:932*/
#line 10715 "./marpa.w"
;

/*:955*/
#line 10728 "./marpa.w"
;
my_slice_free(*b,b);
}
}

/*:956*//*962:*/
#line 10772 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10777 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10778 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10779 "./marpa.w"

/*961:*/
#line 10750 "./marpa.w"

{
if(UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}
}

/*:961*/
#line 10780 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:962*//*963:*/
#line 10784 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10789 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10790 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10791 "./marpa.w"

/*961:*/
#line 10750 "./marpa.w"

{
if(UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}
}

/*:961*/
#line 10792 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:963*//*964:*/
#line 10796 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10801 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10802 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10803 "./marpa.w"

/*961:*/
#line 10750 "./marpa.w"

{
if(UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}
}

/*:961*/
#line 10804 "./marpa.w"

return ID_of_IRL(IRL_of_OR(or_node));
}

/*:964*//*965:*/
#line 10808 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10813 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10814 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10815 "./marpa.w"

/*961:*/
#line 10750 "./marpa.w"

{
if(UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}
}

/*:961*/
#line 10816 "./marpa.w"

return Position_of_OR(or_node);
}

/*:965*//*966:*/
#line 10820 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10825 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10826 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10827 "./marpa.w"

/*961:*/
#line 10750 "./marpa.w"

{
if(UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}
}

/*:961*/
#line 10828 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:966*//*967:*/
#line 10832 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10837 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10838 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10839 "./marpa.w"

/*961:*/
#line 10750 "./marpa.w"

{
if(UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}
}

/*:961*/
#line 10840 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:967*//*968:*/
#line 10845 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 10850 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10851 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10852 "./marpa.w"

/*961:*/
#line 10750 "./marpa.w"

{
if(UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}
}

/*:961*/
#line 10853 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:968*//*975:*/
#line 10895 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1189:*/
#line 13524 "./marpa.w"
void*const failure_indicator= NULL;
/*:1189*/
#line 10898 "./marpa.w"

/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10899 "./marpa.w"

ORDER o;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 10901 "./marpa.w"

o= my_slice_new(*o);
B_of_O(o)= b;
bocage_ref(b);
/*972:*/
#line 10883 "./marpa.w"

{
o->t_and_node_in_use= NULL;
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
}

/*:972*//*978:*/
#line 10912 "./marpa.w"

o->t_ref_count= 1;

/*:978*/
#line 10905 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
return o;
}

/*:975*//*979:*/
#line 10916 "./marpa.w"

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

/*:979*//*980:*/
#line 10934 "./marpa.w"

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

/*:980*//*981:*/
#line 10948 "./marpa.w"

PRIVATE void order_strip(ORDER o)
{
if(o->t_and_node_in_use)
{
bv_free(o->t_and_node_in_use);
o->t_and_node_in_use= NULL;
}
}
/*:981*//*982:*/
#line 10957 "./marpa.w"

PRIVATE void order_freeze(ORDER o)
{
order_strip(o);
O_is_Frozen(o)= 0;
}
/*:982*//*983:*/
#line 10963 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 10966 "./marpa.w"

bocage_unref(b);
order_strip(o);
if(o->t_and_node_orderings){
o->t_and_node_orderings= NULL;
my_obstack_free(&OBS_of_O(o));
}
my_slice_free(*o,o);
}

/*:983*//*986:*/
#line 10992 "./marpa.w"

Marpa_Grammar marpa_o_g(Marpa_Order o)
{
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 10995 "./marpa.w"

return g;
}

/*:986*//*992:*/
#line 11054 "./marpa.w"

int _marpa_o_and_order_set(
Marpa_Order o,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
int length)
{
OR or_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11062 "./marpa.w"

/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11063 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11064 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*961:*/
#line 10750 "./marpa.w"

{
if(UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}
}

/*:961*/
#line 11070 "./marpa.w"

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

/*:992*//*993:*/
#line 11134 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,int ix)
{
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11137 "./marpa.w"

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

/*:993*//*994:*/
#line 11159 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11164 "./marpa.w"

/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11165 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11166 "./marpa.w"

/*961:*/
#line 10750 "./marpa.w"

{
if(UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}
}

/*:961*/
#line 11167 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
return and_order_get(o,or_node,ix);
}

/*:994*//*999:*/
#line 11219 "./marpa.w"

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
bv_free(t->t_and_node_in_use);
t->t_and_node_in_use= NULL;
T_is_Exhausted(t)= 1;
}

/*:999*//*1000:*/
#line 11237 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1189:*/
#line 13524 "./marpa.w"
void*const failure_indicator= NULL;
/*:1189*/
#line 11240 "./marpa.w"

TREE t;
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11242 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11243 "./marpa.w"

t= my_slice_new(*t);
O_of_T(t)= o;
order_ref(o);
order_freeze(o);
/*1019:*/
#line 11448 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1019*/
#line 11248 "./marpa.w"

/*1001:*/
#line 11253 "./marpa.w"

{
t->t_parse_count= 0;
if(O_is_Nulling(o))
{
T_is_Nulling(t)= 1;
t->t_and_node_in_use= NULL;
FSTACK_SAFE(t->t_nook_stack);
FSTACK_SAFE(t->t_nook_worklist);
}
else
{
const int and_count= AND_Count_of_B(b);
T_is_Nulling(t)= 0;
t->t_and_node_in_use= bv_create((unsigned int)and_count);
FSTACK_INIT(t->t_nook_stack,NOOK_Object,and_count);
FSTACK_INIT(t->t_nook_worklist,int,and_count);
}
}

/*:1001*//*1004:*/
#line 11276 "./marpa.w"

t->t_ref_count= 1;

/*:1004*//*1011:*/
#line 11355 "./marpa.w"
t->t_pause_counter= 0;
/*:1011*/
#line 11249 "./marpa.w"

return t;
}

/*:1000*//*1005:*/
#line 11280 "./marpa.w"

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

/*:1005*//*1006:*/
#line 11298 "./marpa.w"

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

/*:1006*//*1007:*/
#line 11312 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_slice_free(*t,t);
}

/*:1007*//*1012:*/
#line 11356 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1012*//*1013:*/
#line 11365 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1013*//*1015:*/
#line 11387 "./marpa.w"

Marpa_Grammar marpa_t_g(Marpa_Tree t)
{
/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11390 "./marpa.w"

return g;
}

/*:1015*//*1016:*/
#line 11394 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11397 "./marpa.w"

int is_first_tree_attempt= 0;
/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11399 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11400 "./marpa.w"

if(T_is_Paused(t)){
MARPA_ERROR(MARPA_ERR_TREE_PAUSED);
return failure_indicator;
}

if(T_is_Exhausted(t))
{
return-1;
}

if(T_is_Nulling(t)){
if(t->t_parse_count<1){
t->t_parse_count++;
return 0;
}else{
goto TREE_IS_EXHAUSTED;
}
}

if(t->t_parse_count<1)
{
is_first_tree_attempt= 1;
/*1026:*/
#line 11482 "./marpa.w"

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

/*:1026*/
#line 11423 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
}else{
/*1027:*/
#line 11507 "./marpa.w"
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

/*:1027*/
#line 11430 "./marpa.w"

}
/*1028:*/
#line 11559 "./marpa.w"
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
/*1030:*/
#line 11620 "./marpa.w"

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

/*:1030*/
#line 11601 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1028*/
#line 11432 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return-1;

}

/*:1016*//*1023:*/
#line 11462 "./marpa.w"

PRIVATE void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:1023*//*1024:*/
#line 11468 "./marpa.w"

PRIVATE void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:1024*//*1025:*/
#line 11476 "./marpa.w"

PRIVATE int tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}

/*:1025*//*1029:*/
#line 11607 "./marpa.w"

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

/*:1029*//*1031:*/
#line 11638 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1031*//*1032:*/
#line 11646 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11649 "./marpa.w"

/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11650 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11651 "./marpa.w"

if(T_is_Exhausted(t)){
return-1;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1032*//*1039:*/
#line 11710 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11714 "./marpa.w"

/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11715 "./marpa.w"

/*1038:*/
#line 11692 "./marpa.w"
{
NOOK base_nook;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11694 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1038*/
#line 11716 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1039*//*1040:*/
#line 11720 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11724 "./marpa.w"

/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11725 "./marpa.w"

/*1038:*/
#line 11692 "./marpa.w"
{
NOOK base_nook;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11694 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1038*/
#line 11726 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1040*//*1041:*/
#line 11730 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11734 "./marpa.w"

/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11735 "./marpa.w"

/*1038:*/
#line 11692 "./marpa.w"
{
NOOK base_nook;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11694 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1038*/
#line 11736 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1041*//*1042:*/
#line 11740 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11744 "./marpa.w"

/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11745 "./marpa.w"

/*1038:*/
#line 11692 "./marpa.w"
{
NOOK base_nook;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11694 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1038*/
#line 11746 "./marpa.w"

return NOOK_Cause_is_Ready(nook);
}

/*:1042*//*1043:*/
#line 11750 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11754 "./marpa.w"

/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11755 "./marpa.w"

/*1038:*/
#line 11692 "./marpa.w"
{
NOOK base_nook;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11694 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1038*/
#line 11756 "./marpa.w"

return NOOK_Predecessor_is_Ready(nook);
}

/*:1043*//*1044:*/
#line 11760 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11764 "./marpa.w"

/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11765 "./marpa.w"

/*1038:*/
#line 11692 "./marpa.w"
{
NOOK base_nook;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11694 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1038*/
#line 11766 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1044*//*1045:*/
#line 11770 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 11774 "./marpa.w"

/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11775 "./marpa.w"

/*1038:*/
#line 11692 "./marpa.w"
{
NOOK base_nook;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11694 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1038*/
#line 11776 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1045*//*1059:*/
#line 11908 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1189:*/
#line 13524 "./marpa.w"
void*const failure_indicator= NULL;
/*:1189*/
#line 11911 "./marpa.w"

/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11912 "./marpa.w"
;
/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 11913 "./marpa.w"

if(!T_is_Exhausted(t))
{
VALUE v= my_slice_new(struct s_value);
Next_Value_Type_of_V(v)= V_GET_DATA;
/*1053:*/
#line 11852 "./marpa.w"

SYMID_of_V(v)= -1;
RULEID_of_V(v)= -1;
Token_Value_of_V(v)= -1;
Token_Type_of_V(v)= DUMMY_OR_NODE;
TOS_of_V(v)= -1;
Arg_N_of_V(v)= -1;

/*:1053*//*1058:*/
#line 11904 "./marpa.w"

DSTACK_SAFE(VStack_of_V(v));

/*:1058*//*1062:*/
#line 11938 "./marpa.w"

v->t_ref_count= 1;

/*:1062*//*1070:*/
#line 12004 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1070*//*1072:*/
#line 12011 "./marpa.w"

V_is_Trace(v)= 0;
/*:1072*//*1075:*/
#line 12032 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1075*//*1079:*/
#line 12054 "./marpa.w"

{
const SYMID symbol_count_of_g= SYM_Count_of_G(g);
SYMID ix;
Nulling_Ask_BV_of_V(v)= bv_create(symbol_count_of_g);
for(ix= 0;ix<symbol_count_of_g;ix++){
const SYM symbol= SYM_by_ID(ix);
if(SYM_is_Ask_Me_When_Null(symbol))
{
bv_bit_set(Nulling_Ask_BV_of_V(v),ix);
}
}
}

/*:1079*/
#line 11918 "./marpa.w"

tree_pause(t);
T_of_V(v)= t;
if(T_is_Nulling(o)){
V_is_Nulling(v)= 1;
}else{
const int minimum_stack_size= (8192/sizeof(int));
const int initial_stack_size= 
MAX(Size_of_TREE(t)/1024,minimum_stack_size);
DSTACK_INIT(VStack_of_V(v),int,initial_stack_size);
}
return(Marpa_Value)v;
}
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return NULL;
}

/*:1059*//*1063:*/
#line 11942 "./marpa.w"

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

/*:1063*//*1064:*/
#line 11960 "./marpa.w"

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

/*:1064*//*1065:*/
#line 11974 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
bv_free(Nulling_Ask_BV_of_V(v));
if(LIKELY(DSTACK_IS_INITIALIZED(VStack_of_V(v))!=NULL))
{
DSTACK_DESTROY(VStack_of_V(v));
}
my_slice_free(*v,v);
}

/*:1065*//*1067:*/
#line 11991 "./marpa.w"

Marpa_Grammar marpa_v_g(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1066:*/
#line 11986 "./marpa.w"

TREE t= T_of_V(v);
/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11988 "./marpa.w"


/*:1066*/
#line 11995 "./marpa.w"

return g;
}

/*:1067*//*1073:*/
#line 12013 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 12016 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1066:*/
#line 11986 "./marpa.w"

TREE t= T_of_V(v);
/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11988 "./marpa.w"


/*:1066*/
#line 12018 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 12019 "./marpa.w"

if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1073*//*1076:*/
#line 12035 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 12038 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1066:*/
#line 11986 "./marpa.w"

TREE t= T_of_V(v);
/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11988 "./marpa.w"


/*:1066*/
#line 12040 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 12041 "./marpa.w"

if(UNLIKELY(V_is_Nulling(v)))return-1;
if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1076*//*1080:*/
#line 12070 "./marpa.w"

int marpa_v_symbol_is_ask_me_when_null(
Marpa_Value public_v,
Marpa_Symbol_ID symid)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 12075 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1066:*/
#line 11986 "./marpa.w"

TREE t= T_of_V(v);
/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11988 "./marpa.w"


/*:1066*/
#line 12077 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 12078 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 12079 "./marpa.w"

return bv_bit_test(Nulling_Ask_BV_of_V(v),symid);
}
/*:1080*//*1081:*/
#line 12092 "./marpa.w"

int marpa_v_symbol_ask_me_when_null_set(
Marpa_Value public_v,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
const VALUE v= (VALUE)public_v;
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 12098 "./marpa.w"

/*1066:*/
#line 11986 "./marpa.w"

TREE t= T_of_V(v);
/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11988 "./marpa.w"


/*:1066*/
#line 12099 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 12100 "./marpa.w"

/*1193:*/
#line 13543 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1193*/
#line 12101 "./marpa.w"

symbol= SYM_by_ID(symid);
if(UNLIKELY(!SYM_is_Nullable(symbol)&&value)){
MARPA_ERROR(MARPA_ERR_SYM_NOT_NULLABLE);
}
if(value){
bv_bit_set(Nulling_Ask_BV_of_V(v),symid);
}else{
bv_bit_clear(Nulling_Ask_BV_of_V(v),symid);
}
return value?1:0;
}

/*:1081*//*1083:*/
#line 12121 "./marpa.w"

Marpa_Value_Type marpa_v_step(Marpa_Value public_v)
{
/*1190:*/
#line 13527 "./marpa.w"
const int failure_indicator= -2;

/*:1190*/
#line 12124 "./marpa.w"

const VALUE v= (VALUE)public_v;

if(V_is_Nulling(v)){
/*1066:*/
#line 11986 "./marpa.w"

TREE t= T_of_V(v);
/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11988 "./marpa.w"


/*:1066*/
#line 12128 "./marpa.w"

/*1084:*/
#line 12176 "./marpa.w"

{
while(V_is_Active(v)){
Marpa_Value_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case V_GET_DATA:
{
Next_Value_Type_of_V(v)= MARPA_VALUE_INACTIVE;
SYMID_of_V(v)= g->t_start_xsyid;
TOS_of_V(v)= Arg_N_of_V(v)= 0;
if(bv_bit_test(Nulling_Ask_BV_of_V(v),SYMID_of_V(v)))
return MARPA_VALUE_NULLING_SYMBOL;
}



}
}
}

/*:1084*/
#line 12129 "./marpa.w"

return MARPA_VALUE_INACTIVE;
}

while(V_is_Active(v)){
Marpa_Value_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case V_GET_DATA:
/*1085:*/
#line 12197 "./marpa.w"

{
AND and_nodes;
/*1066:*/
#line 11986 "./marpa.w"

TREE t= T_of_V(v);
/*998:*/
#line 11215 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 10976 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*928:*/
#line 10425 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:928*/
#line 10978 "./marpa.w"


/*:984*/
#line 11217 "./marpa.w"
;

/*:998*/
#line 11988 "./marpa.w"


/*:1066*/
#line 12200 "./marpa.w"

/*1203:*/
#line 13597 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1203*/
#line 12201 "./marpa.w"

and_nodes= ANDs_of_B(B_of_O(o));

Arg_N_of_V(v)= TOS_of_V(v);
if(NOOK_of_V(v)<0){
NOOK_of_V(v)= Size_of_TREE(t);
}

while(1){
OR or;
RULE nook_rule;
IRL nook_irl;
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
const SYM token_symbol= SYM_by_ID(token_id);
SYMID_of_V(v)= ID_of_XSY(Source_XSY_of_SYM(token_symbol));
Token_Value_of_V(v)= Value_of_TOK(token);
}
else if(token_type==NULLING_TOKEN_OR_NODE)
{
const SYM token_symbol= SYM_by_ID(token_id);
const XSY source_symbol= Source_XSY_of_SYM(token_symbol);
const SYMID source_symid= ID_of_SYM(source_symbol);
if(bv_bit_test(Nulling_Ask_BV_of_V(v),source_symid))
{
SYMID_of_V(v)= source_symid;
}
else
{
Token_Type_of_V(v)= DUMMY_OR_NODE;


}
}
else
{
Token_Type_of_V(v)= DUMMY_OR_NODE;


}
}
}
nook_irl= IRL_of_OR(or);
nook_rule= Co_RULE_of_IRL(nook_irl);
if(Position_of_OR(or)==Length_of_RULE(nook_rule)){
int virtual_rhs= RULE_has_Virtual_RHS(nook_rule);
int virtual_lhs= IRL_has_Virtual_LHS(nook_irl);
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


XRLID original_rule_id= ID_of_XRL(Source_XRL_of_IRL(nook_irl));
if(XRL_is_Ask_Me(XRL_by_ID(original_rule_id)))
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

/*:1085*/
#line 12138 "./marpa.w"

if(!V_is_Active(v))break;

case MARPA_VALUE_TOKEN:
{
int token_type= Token_Type_of_V(v);
Next_Value_Type_of_V(v)= MARPA_VALUE_RULE;
if(token_type==NULLING_TOKEN_OR_NODE)
{
if(bv_bit_test(Nulling_Ask_BV_of_V(v),SYMID_of_V(v)))
return MARPA_VALUE_NULLING_SYMBOL;
}
else if(token_type!=DUMMY_OR_NODE)
{
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

/*:1083*//*1088:*/
#line 12332 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(unsigned int bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1088*//*1089:*/
#line 12338 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(unsigned int bits)
{
unsigned int mask= bits&bv_modmask;
if(mask)mask= (unsigned int)~(~0uL<<mask);else mask= (unsigned int)~0uL;
return(mask);
}

/*:1089*//*1091:*/
#line 12352 "./marpa.w"

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

/*:1091*//*1093:*/
#line 12370 "./marpa.w"

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


/*:1093*//*1094:*/
#line 12391 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,BV_BITS(bv));
}

/*:1094*//*1095:*/
#line 12405 "./marpa.w"

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

/*:1095*//*1096:*/
#line 12423 "./marpa.w"

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

/*:1096*//*1097:*/
#line 12437 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1097*//*1098:*/
#line 12448 "./marpa.w"

PRIVATE int bv_bytes(Bit_Vector bv)
{
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}

/*:1098*//*1099:*/
#line 12455 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1099*//*1100:*/
#line 12466 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1100*//*1102:*/
#line 12480 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,unsigned int bit)
{
unsigned int length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1102*//*1104:*/
#line 12488 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1104*//*1105:*/
#line 12495 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1105*//*1106:*/
#line 12502 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,unsigned int bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1106*//*1107:*/
#line 12510 "./marpa.w"

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

/*:1107*//*1108:*/
#line 12523 "./marpa.w"

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

/*:1108*//*1109:*/
#line 12537 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1109*//*1110:*/
#line 12547 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1110*//*1111:*/
#line 12557 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1111*//*1112:*/
#line 12567 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1112*//*1113:*/
#line 12577 "./marpa.w"

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

/*:1113*//*1114:*/
#line 12649 "./marpa.w"

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

/*:1114*//*1119:*/
#line 12697 "./marpa.w"

PRIVATE void
rhs_closure(GRAMMAR g,Bit_Vector bv,XRLID**xrl_list_x_rh_sym)
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
XRLID*p_xrl= xrl_list_x_rh_sym[symid];
const XRLID*p_one_past_rules= xrl_list_x_rh_sym[symid+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{
const XRLID rule_id= *p_xrl;
const XRL rule= XRL_by_ID(rule_id);
int rule_length;
int rh_ix;
const SYMID lhs_id= LHS_ID_of_XRL(rule);

const int is_sequence= XRL_is_Sequence(rule);

if(bv_bit_test(bv,(unsigned int)lhs_id))
goto NEXT_RULE;
rule_length= Length_of_XRL(rule);






for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test
(bv,(unsigned int)RHS_ID_of_XRL(rule,rh_ix)))
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

/*:1119*//*1123:*/
#line 12799 "./marpa.w"

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

/*:1123*//*1124:*/
#line 12826 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1124*//*1125:*/
#line 12842 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,unsigned int row)
{
Bit_Vector row0= matrix+bv_hiddenwords;
unsigned int words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1125*//*1127:*/
#line 12851 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1127*//*1129:*/
#line 12859 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1129*//*1131:*/
#line 12867 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1131*//*1132:*/
#line 12880 "./marpa.w"

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

/*:1132*//*1141:*/
#line 13044 "./marpa.w"

PRIVATE_NOT_INLINE void*dstack_resize(struct s_dstack*this,size_t type_bytes)
{
this->t_capacity*= 2;
this->t_base= my_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}

/*:1141*//*1156:*/
#line 13183 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1156*//*1157:*/
#line 13190 "./marpa.w"

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
/*:1157*//*1158:*/
#line 13204 "./marpa.w"

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
/*:1158*//*1161:*/
#line 13235 "./marpa.w"

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

/*:1161*//*1163:*/
#line 13253 "./marpa.w"

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

/*:1163*//*1165:*/
#line 13273 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1165*//*1167:*/
#line 13297 "./marpa.w"

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

/*:1167*//*1170:*/
#line 13323 "./marpa.w"

PRIVATE_NOT_INLINE void*
_marpa_default_out_of_memory(void)
{
abort();
}
void*(*_marpa_out_of_memory)(void)= _marpa_default_out_of_memory;

/*:1170*//*1206:*/
#line 13641 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}

/*:1206*//*1215:*/
#line 13748 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
_marpa_debug_handler= debug_handler;
}

/*:1215*//*1217:*/
#line 13756 "./marpa.w"

void marpa_debug_level_set(int level)
{
_marpa_debug_level= level;
}

/*:1217*/
#line 13981 "./marpa.w"


/*:1232*/
