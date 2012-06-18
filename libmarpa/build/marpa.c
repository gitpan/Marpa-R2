/*1258:*/
#line 14399 "./marpa.w"

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

/*:1258*//*1259:*/
#line 14422 "./marpa.w"

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
#define XSY_by_ID(id) (*DSTACK_INDEX(g->t_xsy_stack,XSY,(id) ) ) 
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
#define ID_of_SYM(sym) ID_of_XSY(sym) 
#define XSY_is_LHS(xsy) ((xsy) ->t_is_lhs) 
#define SYM_is_LHS(symbol) XSY_is_LHS(symbol) 
#define SYM_is_Sequence_LHS(symbol) ((symbol) ->t_is_sequence_lhs) 
#define SYM_is_Semantic(symbol) ((symbol) ->t_is_semantic) 
#define XSY_is_Valued(symbol) ((symbol) ->t_is_valued) 
#define XSY_is_Valued_Locked(symbol) ((symbol) ->t_is_valued_locked) 
#define XSY_is_Accessible(xsy) ((xsy) ->t_is_accessible) 
#define SYM_is_Accessible(sym) XSY_is_Accessible(sym) 
#define XSY_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define SYM_is_Nulling(sym) XSY_is_Nulling(sym) 
#define XSY_is_Nullable(sym) ((sym) ->t_is_nullable) 
#define SYM_is_Nullable(sym) XSY_is_Nullable(sym) 
#define XSY_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
#define SYM_is_Locked_Terminal(symbol) ((symbol) ->t_is_locked_terminal) 
#define SYMID_is_Terminal(id) (XSY_is_Terminal(SYM_by_ID(id) ) ) 
#define XSY_is_Productive(xsy) ((xsy) ->t_is_productive) 
#define SYM_is_Productive(xsy) XSY_is_Productive(xsy) 
#define ISY_of_XSY(xsy) ((xsy) ->t_isy_equivalent) 
#define ISYID_of_XSY(xsy) ID_of_ISY(ISY_of_XSY(xsy) ) 
#define ISY_by_XSYID(xsyid) (XSY_by_ID(xsyid) ->t_isy_equivalent) 
#define ISYID_by_XSYID(xsyid) ID_of_ISY(ISY_of_XSY(XSY_by_ID(xsyid) ) ) 
#define Nulling_ISY_of_XSY(xsy) ((xsy) ->t_nulling_isy) 
#define Nulling_ISY_by_XSYID(xsy) (XSY_by_ID(xsy) ->t_nulling_isy) 
#define Nulling_ISYID_by_XSYID(xsy) ID_of_ISY(XSY_by_ID(xsy) ->t_nulling_isy) 
#define Nulling_OR_by_ISYID(isyid) ((OR) ISY_by_ID(isyid) ) 
#define ISY_by_ID(id) (*DSTACK_INDEX(g->t_isy_stack,ISY,(id) ) ) 
#define ID_of_ISY(isy) ((isy) ->t_isyid)  \

#define ISY_Count_of_G(g) (DSTACK_LENGTH((g) ->t_isy_stack) ) 
#define ISY_is_Start(isy) ((isy) ->t_is_start) 
#define ISY_is_LHS(isy) ((isy) ->t_is_lhs) 
#define ISY_is_Nulling(isy) ((isy) ->t_isy_is_nulling) 
#define Source_XSY_of_ISY(isy) ((isy) ->t_source_xsy) 
#define LHS_XRL_of_ISY(isy) ((isy) ->t_lhs_xrl) 
#define XRL_Offset_of_ISY(isy) ((isy) ->t_xrl_offset) 
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
#define XRL_is_Nullable(rule) ((rule) ->t_is_nullable) 
#define XRL_is_Accessible(rule) ((rule) ->t_is_accessible) 
#define XRL_is_Productive(rule) ((rule) ->t_is_productive) 
#define XRL_is_Used(xrl) ( \
XRL_is_Accessible(xrl) &&XRL_is_Productive(xrl) &&!XRL_is_Nulling(xrl)  \
) 
#define ID_of_IRL(irl) ((irl) ->t_irl_id) 
#define LHSID_of_IRL(irlid) ((irlid) ->t_isyid_array[0]) 
#define LHS_of_IRL(irl) (ISY_by_ID(LHSID_of_IRL(irl) ) )  \

#define RHSID_of_IRL(irl,position) ((irl) ->t_isyid_array[(position) +1]) 
#define RHS_of_IRL(irl,position) ISY_by_ID(RHSID_of_IRL((irl) ,(position) ) ) 
#define Length_of_IRL(irl) ((irl) ->t_length) 
#define IRL_has_Virtual_LHS(irl) ((irl) ->t_is_virtual_lhs) 
#define IRL_has_Virtual_RHS(irl) ((irl) ->t_is_virtual_rhs) 
#define Real_SYM_Count_of_IRL(irl) ((irl) ->t_real_symbol_count) 
#define Virtual_Start_of_IRL(irl) ((irl) ->t_virtual_start) 
#define Virtual_End_of_IRL(irl) ((irl) ->t_virtual_end) 
#define Source_XRL_of_IRL(irl) ((irl) ->t_source_xrl) 
#define First_AIM_of_IRL(irl) ((irl) ->t_first_aim) 
#define SYMI_Count_of_G(g) ((g) ->t_symbol_instance_count) 
#define SYMI_of_IRL(irl) ((irl) ->t_symbol_instance_base) 
#define Last_Proper_SYMI_of_IRL(irl) ((irl) ->t_last_proper_symi) 
#define SYMI_of_Completed_IRL(irl)  \
(SYMI_of_IRL(irl) +Length_of_IRL(irl) -1) 
#define SYMI_of_AIM(aim) (symbol_instance_of_ahfa_item_get(aim) ) 
#define Sort_Key_of_AIM(aim) ((aim) ->t_sort_key) 
#define Next_AIM_of_AIM(aim) ((aim) +1) 
#define AIM_by_ID(id) (g->t_AHFA_items+(id) ) 
#define AIM_Count_of_G(g) ((g) ->t_aim_count) 
#define IRL_of_AIM(aim) ((aim) ->t_irl) 
#define IRLID_of_AIM(item) ID_of_IRL(IRL_of_AIM(item) ) 
#define LHS_ISYID_of_AIM(item) LHSID_of_IRL(IRL_of_AIM(item) ) 
#define Position_of_AIM(aim) ((aim) ->t_position) 
#define Postdot_ISYID_of_AIM(item) ((item) ->t_postdot_isyid) 
#define AIM_is_Completion(aim) (Postdot_ISYID_of_AIM(aim) <0) 
#define Null_Count_of_AIM(aim) ((aim) ->t_leading_nulls) 
#define AHFA_of_G_by_ID(g,id) ((g) ->t_AHFA+(id) ) 
#define Complete_ISYIDs_of_AHFA(state) ((state) ->t_complete_isyids) 
#define Complete_ISY_Count_of_AHFA(state) ((state) ->t_complete_isy_count) 
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

#define Postdot_ISY_Count_of_AHFA(state) ((state) ->t_postdot_isy_count) 
#define Postdot_ISYIDAry_of_AHFA(state) ((state) ->t_postdot_isyidary) 
#define AIMID_of_AHFA_by_AEX(g,ahfa,aex)  \
((ahfa) ->t_items[aex]-(g) ->t_AHFA_items) 
#define Leo_LHS_ISYID_of_AHFA(state) ((state) ->t_leo_lhs_isyid) 
#define AHFA_is_Leo_Completion(state) (Leo_LHS_ISYID_of_AHFA(state) >=0) 
#define SET_1ST_PASS_SORT_KEY_FOR_IRL(sort_key,irl) { \
const AIM aim= First_AIM_of_IRL(irl) ; \
(sort_key) = Postdot_ISYID_of_AIM(aim) ; \
}
#define TRANS_of_AHFA_by_ISYID(from_ahfa,isyid)  \
(*(TRANSs_of_AHFA(from_ahfa) +(isyid) ) ) 
#define TRANS_of_EIM_by_ISYID(eim,isyid) TRANS_of_AHFA_by_ISYID(AHFA_of_EIM(eim) ,(isyid) ) 
#define To_AHFA_of_TRANS(trans) (to_ahfa_of_transition_get(trans) ) 
#define LV_To_AHFA_of_TRANS(trans) ((trans) ->t_ur.t_to_ahfa) 
#define Completion_Count_of_TRANS(trans)  \
(completion_count_of_transition_get(trans) ) 
#define LV_Completion_Count_of_TRANS(trans) ((trans) ->t_ur.t_completion_count) 
#define To_AHFA_of_AHFA_by_ISYID(from_ahfa,id)  \
(To_AHFA_of_TRANS(TRANS_of_AHFA_by_ISYID((from_ahfa) ,(id) ) ) ) 
#define To_AHFA_of_EIM_by_ISYID(eim,id) To_AHFA_of_AHFA_by_ISYID(AHFA_of_EIM(eim) ,(id) ) 
#define AEXs_of_TRANS(trans) ((trans) ->t_aex) 
#define Leo_Base_AEX_of_TRANS(trans) ((trans) ->t_leo_base_aex) 
#define TRANSs_of_AHFA(ahfa) ((ahfa) ->t_transitions) 
#define Empty_Transition_of_AHFA(state) ((state) ->t_empty_transition) 
#define TOK_Obs_of_I(i)  \
((i) ->t_token_obs) 
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
#define First_PIM_of_ES_by_ISYID(set,isyid) (first_pim_of_es_by_isyid((set) ,(isyid) ) ) 
#define PIM_ISY_P_of_ES_by_ISYID(set,isyid) (pim_isy_p_find((set) ,(isyid) ) ) 
#define EIM_Count_of_ES(set) ((set) ->t_eim_count) 
#define EIMs_of_ES(set) ((set) ->t_earley_items) 
#define ES_Count_of_R(r) ((r) ->t_earley_set_count) 
#define Ord_of_ES(set) ((set) ->t_ordinal) 
#define ES_Ord_is_Valid(r,ordinal)  \
((ordinal) >=0&&(ordinal) <ES_Count_of_R(r) ) 
#define Earleme_of_ES(set) ((set) ->t_key.t_earleme)  \

#define EIM_FATAL_THRESHOLD (INT_MAX/4) 
#define Complete_ISYIDs_of_EIM(item)  \
Complete_ISYIDs_of_AHFA(AHFA_of_EIM(item) ) 
#define Complete_ISY_Count_of_EIM(item)  \
Complete_ISY_Count_of_AHFA(AHFA_of_EIM(item) ) 
#define Leo_LHS_ISYID_of_EIM(eim) Leo_LHS_ISYID_of_AHFA(AHFA_of_EIM(eim) ) 
#define Earley_Item_is_Completion(item)  \
(Complete_ISY_Count_of_EIM(item) > 0) 
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
#define Postdot_ISYID_of_EIX(eix) ((eix) ->t_postdot_isyid) 
#define EIX_of_LIM(lim) ((EIX) (lim) ) 
#define Postdot_ISYID_of_LIM(leo) (Postdot_ISYID_of_EIX(EIX_of_LIM(leo) ) ) 
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
#define Postdot_ISYID_of_PIM(pim) (Postdot_ISYID_of_EIX(EIX_of_PIM(pim) ) ) 
#define EIM_of_PIM(pim) (EIM_of_EIX(EIX_of_PIM(pim) ) ) 
#define Next_PIM_of_PIM(pim) (Next_PIM_of_EIX(EIX_of_PIM(pim) ) )  \

#define PIM_of_LIM(pim) ((PIM) (pim) ) 
#define PIM_is_LIM(pim) (EIM_of_EIX(EIX_of_PIM(pim) ) ==NULL) 
#define Next_SRCL_of_SRCL(link) ((link) ->t_next) 
#define Source_of_SRCL(link) ((link) ->t_source) 
#define SRCL_of_EIM(eim) (&(eim) ->t_container.t_unique) 
#define Source_of_EIM(eim) ((eim) ->t_container.t_unique.t_source) 
#define SRC_of_EIM(eim) (&Source_of_EIM(eim) ) 
#define Predecessor_of_Source(srcd) ((srcd) .t_predecessor) 
#define Predecessor_of_SRC(source) Predecessor_of_Source(*(source) ) 
#define Predecessor_of_EIM(item) Predecessor_of_Source(Source_of_EIM(item) ) 
#define Predecessor_of_SRCL(link) Predecessor_of_Source(Source_of_SRCL(link) ) 
#define LIM_of_SRCL(link) ((LIM) Predecessor_of_SRCL(link) ) 
#define Cause_of_Source(srcd) ((srcd) .t_cause.t_completion) 
#define Cause_of_SRC(source) Cause_of_Source(*(source) ) 
#define Cause_of_EIM(item) Cause_of_Source(Source_of_EIM(item) ) 
#define Cause_of_SRCL(link) Cause_of_Source(Source_of_SRCL(link) ) 
#define TOK_of_Source(srcd) ((srcd) .t_cause.t_token) 
#define TOK_of_SRC(source) TOK_of_Source(*(source) ) 
#define TOK_of_EIM(eim) TOK_of_Source(Source_of_EIM(eim) ) 
#define TOK_of_SRCL(link) TOK_of_Source(Source_of_SRCL(link) ) 
#define ISYID_of_Source(srcd) ISYID_of_TOK(TOK_of_Source(srcd) ) 
#define ISYID_of_SRC(source) ISYID_of_Source(*(source) ) 
#define ISYID_of_EIM(eim) ISYID_of_Source(Source_of_EIM(eim) ) 
#define ISYID_of_SRCL(link) ISYID_of_Source(Source_of_SRCL(link) )  \

#define Cause_AHFAID_of_SRCL(srcl)  \
AHFAID_of_EIM((EIM) Cause_of_SRCL(srcl) ) 
#define Leo_Transition_ISYID_of_SRCL(leo_source_link)  \
Postdot_ISYID_of_LIM(LIM_of_SRCL(leo_source_link) )  \

#define LV_First_Completion_SRCL_of_EIM(item) ((item) ->t_container.t_ambiguous.t_completion) 
#define LV_First_Token_SRCL_of_EIM(item) ((item) ->t_container.t_ambiguous.t_token) 
#define LV_First_Leo_SRCL_of_EIM(item) ((item) ->t_container.t_ambiguous.t_leo) 
#define First_Leo_SRCL_of_EIM(item)  \
(Source_Type_of_EIM(item) ==SOURCE_IS_LEO?(SRCL) SRCL_of_EIM(item) : \
Source_Type_of_EIM(item) ==SOURCE_IS_AMBIGUOUS? \
LV_First_Leo_SRCL_of_EIM(item) :NULL)  \

#define Type_of_TOK(tok) ((tok) ->t_unvalued.t_type) 
#define ISYID_of_TOK(tok) ((tok) ->t_unvalued.t_isyid) 
#define Value_of_TOK(tok) ((tok) ->t_value) 
#define TOK_Obs_of_R(r) TOK_Obs_of_I(I_of_R(r) ) 
#define TOK_of_ALT(alt) ((alt) ->t_token) 
#define ISYID_of_ALT(alt) ISYID_of_TOK(TOK_of_ALT(alt) ) 
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
psia_test_and_set(bocage_setup_obs,per_es_data, \
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
#define IRL_of_OR(or) ((or) ->t_final.t_irl) 
#define Origin_Ord_of_OR(or) ((or) ->t_final.t_start_set_ordinal) 
#define ID_of_OR(or) ((or) ->t_final.t_id) 
#define ES_Ord_of_OR(or) ((or) ->t_draft.t_end_set_ordinal) 
#define DANDs_of_OR(or) ((or) ->t_draft.t_draft_and_node) 
#define First_ANDID_of_OR(or) ((or) ->t_final.t_first_and_node_id) 
#define AND_Count_of_OR(or) ((or) ->t_final.t_and_node_count) 
#define TOK_of_OR(or) (&(or) ->t_token) 
#define ISYID_of_OR(or) ISYID_of_TOK(TOK_of_OR(or) ) 
#define Value_of_OR(or) Value_of_TOK(TOK_of_OR(or) ) 
#define ORs_of_B(b) ((b) ->t_or_nodes) 
#define OR_of_B_by_ID(b,id) (ORs_of_B(b) [(id) ]) 
#define OR_Count_of_B(b) ((b) ->t_or_node_count) 
#define ANDs_of_B(b) ((b) ->t_and_nodes) 
#define AND_Count_of_B(b) ((b) ->t_and_node_count) 
#define Top_ORID_of_B(b) ((b) ->t_top_or_node_id) 
#define Path_AIM_of_LIM(lim) (base_aim_of_lim(lim) +1) 
#define Base_AIM_of_LIM(lim) (base_aim_of_lim(lim) ) 
#define WHEID_of_ISYID(isyid) (irl_count+(isyid) ) 
#define WHEID_of_IRLID(irlid) (irlid) 
#define WHEID_of_IRL(irl) WHEID_of_IRLID(ID_of_IRL(irl) ) 
#define WHEID_of_OR(or) ( \
wheid= OR_is_Token(or) ? \
WHEID_of_ISYID(ISYID_of_OR(or) ) : \
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
#define RULEID_of_PROGRESS(report) ((report) ->t_rule_id) 
#define Position_of_PROGRESS(report) ((report) ->t_position) 
#define Origin_of_PROGRESS(report) ((report) ->t_origin)  \

#define I_of_B(b) ((b) ->t_input) 
#define OBS_of_B(b) ((b) ->t_obs) 
#define Valued_BV_of_B(b) ((b) ->t_valued_bv) 
#define Valued_Locked_BV_of_B(b) ((b) ->t_valued_locked_bv) 
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
#define V_is_Active(val) (Next_Value_Type_of_V(val) !=MARPA_STEP_INACTIVE) 
#define T_of_V(v) ((v) ->t_tree) 
#define XSYID_of_V(val) ((val) ->public.t_token_id) 
#define RULEID_of_V(val) ((val) ->public.t_rule_id) 
#define Token_Value_of_V(val) ((val) ->public.t_token_value) 
#define Token_Type_of_V(val) ((val) ->t_token_type) 
#define TOS_of_V(val) ((val) ->public.t_tos) 
#define Arg_N_of_V(val) ((val) ->public.t_arg_n) 
#define VStack_of_V(val) ((val) ->t_virtual_stack) 
#define V_is_Nulling(v) ((v) ->t_is_nulling) 
#define V_is_Trace(val) ((val) ->t_trace) 
#define NOOK_of_V(val) ((val) ->t_nook) 
#define XSY_is_Valued_BV_of_V(v) ((v) ->t_xsy_is_valued) 
#define XRL_is_Valued_BV_of_V(v) ((v) ->t_xrl_is_valued) 
#define Valued_Locked_BV_of_V(v) ((v) ->t_valued_locked) 
#define V_INITIALIZE MARPA_STEP_INTERNAL1
#define V_GET_DATA MARPA_STEP_INTERNAL2 \

#define lbv_wordbits (sizeof(LBW) *8u) 
#define lbv_lsb (1u) 
#define lbv_msb (1u<<(lbv_wordbits-1u) ) 
#define lbv_w(lbv,bit) ((lbv) +((bit) /lbv_wordbits) ) 
#define lbv_b(bit) (lbv_lsb<<((bit) %bv_wordbits) ) 
#define lbv_bit_set(lbv,bit)  \
(*lbv_w((lbv) ,(bit) ) |= lbv_b(bit) ) 
#define lbv_bit_clear(lbv,bit)  \
(*lbv_w((lbv) ,(bit) ) &= ~lbv_b(bit) ) 
#define lbv_bit_test(lbv,bit)  \
((*lbv_w((lbv) ,(bit) ) &lbv_b(bit) ) !=0U)  \

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

#line 14440 "./marpa.w"

#include "marpa_obs.h"
#include "avl.h"
/*91:*/
#line 896 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:91*//*120:*/
#line 1083 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef XSY SYM;
typedef const struct s_xsy*XSY_Const;

/*:120*//*382:*/
#line 4016 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:382*//*421:*/
#line 4385 "./marpa.w"
struct s_AHFA_state;
/*:421*//*502:*/
#line 5545 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:502*//*596:*/
#line 6193 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:596*//*619:*/
#line 6397 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:619*//*639:*/
#line 6687 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:639*//*642:*/
#line 6722 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:642*//*722:*/
#line 7812 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:722*//*726:*/
#line 7839 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:726*//*831:*/
#line 9106 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:831*//*859:*/
#line 9519 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:859*//*886:*/
#line 9937 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:886*//*912:*/
#line 10333 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:912*//*942:*/
#line 10763 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:942*//*953:*/
#line 10868 "./marpa.w"

struct s_bocage_setup_per_es;
/*:953*//*1012:*/
#line 11538 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1012*//*1051:*/
#line 12013 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1051*//*1064:*/
#line 12149 "./marpa.w"

typedef struct s_value*VALUE;
/*:1064*//*1168:*/
#line 13542 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1168*//*1171:*/
#line 13578 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1171*//*1178:*/
#line 13643 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1178*//*1180:*/
#line 13658 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1180*/
#line 14443 "./marpa.w"

/*40:*/
#line 606 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:40*//*119:*/
#line 1080 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
typedef XSYID SYMID;
/*:119*//*169:*/
#line 1423 "./marpa.w"

struct s_isy;
typedef struct s_isy*ISY;
typedef Marpa_ISY_ID ISYID;

/*:169*//*199:*/
#line 1631 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:199*//*262:*/
#line 2220 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:262*//*293:*/
#line 2416 "./marpa.w"
typedef int SYMI;
/*:293*//*438:*/
#line 4476 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef int AHFAID;

/*:438*//*503:*/
#line 5551 "./marpa.w"
typedef int AEX;
/*:503*//*519:*/
#line 5713 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:519*//*534:*/
#line 5804 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:534*//*593:*/
#line 6184 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:593*//*595:*/
#line 6188 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:595*//*669:*/
#line 7101 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:669*//*671:*/
#line 7113 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:671*//*851:*/
#line 9455 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:851*//*885:*/
#line 9926 "./marpa.w"

typedef int WHEID;

/*:885*//*911:*/
#line 10329 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:911*//*925:*/
#line 10512 "./marpa.w"

typedef struct marpa_progress_item*PROGRESS;
/*:925*//*1050:*/
#line 12010 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1050*//*1110:*/
#line 12756 "./marpa.w"

typedef unsigned int LBW;
typedef LBW*LBV;

/*:1110*//*1116:*/
#line 12829 "./marpa.w"

typedef LBW Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1116*//*1150:*/
#line 13296 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1150*/
#line 14444 "./marpa.w"

/*1169:*/
#line 13545 "./marpa.w"

struct s_dstack{int t_count;int t_capacity;void*t_base;};
/*:1169*/
#line 14445 "./marpa.w"

/*39:*/
#line 600 "./marpa.w"
struct marpa_g{
/*111:*/
#line 1035 "./marpa.w"

int t_is_ok;

/*:111*/
#line 601 "./marpa.w"

/*50:*/
#line 681 "./marpa.w"

DSTACK_DECLARE(t_xsy_stack);
DSTACK_DECLARE(t_isy_stack);

/*:50*//*59:*/
#line 737 "./marpa.w"

DSTACK_DECLARE(t_xrl_stack);
DSTACK_DECLARE(t_irl_stack);
/*:59*//*89:*/
#line 886 "./marpa.w"
Bit_Vector t_bv_isyid_is_terminal;
/*:89*//*96:*/
#line 918 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:96*//*103:*/
#line 982 "./marpa.w"

AVL_TREE t_xrl_tree;
/*:103*//*107:*/
#line 1005 "./marpa.w"

struct obstack*t_obs;
struct obstack*t_xrl_obs;
/*:107*//*113:*/
#line 1050 "./marpa.w"

const char*t_error_string;
/*:113*//*384:*/
#line 4033 "./marpa.w"

AIM t_AHFA_items;
/*:384*//*439:*/
#line 4480 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:439*/
#line 602 "./marpa.w"

/*44:*/
#line 628 "./marpa.w"
int t_ref_count;
/*:44*//*69:*/
#line 789 "./marpa.w"
XSYID t_start_xsyid;
/*:69*//*73:*/
#line 817 "./marpa.w"

IRL t_start_irl;
/*:73*//*77:*/
#line 834 "./marpa.w"

int t_external_size;
/*:77*//*80:*/
#line 848 "./marpa.w"
int t_max_rule_length;
/*:80*//*114:*/
#line 1052 "./marpa.w"

Marpa_Error_Code t_error;
/*:114*//*294:*/
#line 2418 "./marpa.w"

int t_symbol_instance_count;
/*:294*//*385:*/
#line 4037 "./marpa.w"

unsigned int t_aim_count;
/*:385*//*440:*/
#line 4483 "./marpa.w"
int t_AHFA_len;
/*:440*/
#line 603 "./marpa.w"

/*83:*/
#line 854 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:83*//*86:*/
#line 866 "./marpa.w"
unsigned int t_has_cycle:1;
/*:86*/
#line 604 "./marpa.w"

};
/*:39*//*95:*/
#line 911 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:95*//*121:*/
#line 1089 "./marpa.w"

struct s_xsy{
/*159:*/
#line 1356 "./marpa.w"
ISY t_isy_equivalent;
/*:159*//*162:*/
#line 1384 "./marpa.w"
ISY t_nulling_isy;
/*:162*/
#line 1091 "./marpa.w"

/*122:*/
#line 1099 "./marpa.w"
XSYID t_symbol_id;

/*:122*/
#line 1092 "./marpa.w"

/*125:*/
#line 1124 "./marpa.w"
unsigned int t_is_lhs:1;
/*:125*//*127:*/
#line 1131 "./marpa.w"
unsigned int t_is_sequence_lhs:1;
/*:127*//*129:*/
#line 1139 "./marpa.w"
unsigned int t_is_semantic:1;
/*:129*//*132:*/
#line 1162 "./marpa.w"

unsigned int t_is_valued:1;
unsigned int t_is_valued_locked:1;
/*:132*//*136:*/
#line 1205 "./marpa.w"
unsigned int t_is_accessible:1;
/*:136*//*139:*/
#line 1225 "./marpa.w"
unsigned int t_is_counted:1;
/*:139*//*142:*/
#line 1241 "./marpa.w"
unsigned int t_is_nulling:1;
/*:142*//*145:*/
#line 1257 "./marpa.w"
unsigned int t_is_nullable:1;
/*:145*//*148:*/
#line 1277 "./marpa.w"

unsigned int t_is_terminal:1;
unsigned int t_is_locked_terminal:1;
/*:148*//*153:*/
#line 1320 "./marpa.w"
unsigned int t_is_productive:1;
/*:153*//*156:*/
#line 1336 "./marpa.w"
unsigned int t_is_start:1;
/*:156*/
#line 1093 "./marpa.w"

};

/*:121*//*170:*/
#line 1436 "./marpa.w"

struct s_isy{
int t_or_node_type;
ISYID t_isyid;
/*188:*/
#line 1548 "./marpa.w"
XSY t_source_xsy;
/*:188*//*192:*/
#line 1570 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:192*/
#line 1440 "./marpa.w"

/*179:*/
#line 1503 "./marpa.w"
unsigned int t_is_start:1;
/*:179*//*182:*/
#line 1517 "./marpa.w"
unsigned int t_is_lhs:1;
/*:182*//*185:*/
#line 1531 "./marpa.w"
unsigned int t_isy_is_nulling:1;
/*:185*/
#line 1441 "./marpa.w"

};
/*:170*//*198:*/
#line 1622 "./marpa.w"

struct s_xrl{
/*211:*/
#line 1925 "./marpa.w"
int t_rhs_length;
/*:211*//*220:*/
#line 1982 "./marpa.w"
Marpa_Rule_ID t_id;

/*:220*/
#line 1624 "./marpa.w"

/*221:*/
#line 1988 "./marpa.w"
unsigned int t_is_bnf:1;
/*:221*//*223:*/
#line 1995 "./marpa.w"
unsigned int t_is_sequence:1;
/*:223*//*226:*/
#line 2013 "./marpa.w"
int t_minimum;
/*:226*//*228:*/
#line 2021 "./marpa.w"
SYMID t_separator_id;
/*:228*//*232:*/
#line 2040 "./marpa.w"
unsigned int t_is_discard:1;
/*:232*//*236:*/
#line 2079 "./marpa.w"
unsigned int t_is_proper_separation:1;
/*:236*//*240:*/
#line 2099 "./marpa.w"
unsigned int t_is_loop:1;
/*:240*//*243:*/
#line 2115 "./marpa.w"
unsigned int t_is_nulling:1;
/*:243*//*246:*/
#line 2132 "./marpa.w"
unsigned int t_is_nullable:1;
/*:246*//*250:*/
#line 2149 "./marpa.w"
unsigned int t_is_accessible:1;
/*:250*//*253:*/
#line 2166 "./marpa.w"
unsigned int t_is_productive:1;
/*:253*/
#line 1625 "./marpa.w"

/*212:*/
#line 1928 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];


/*:212*/
#line 1626 "./marpa.w"

};
/*:198*//*260:*/
#line 2211 "./marpa.w"

struct s_irl{
/*288:*/
#line 2389 "./marpa.w"
XRL t_source_xrl;
/*:288*//*291:*/
#line 2411 "./marpa.w"
AIM t_first_aim;
/*:291*/
#line 2213 "./marpa.w"

/*263:*/
#line 2231 "./marpa.w"
IRLID t_irl_id;

/*:263*//*270:*/
#line 2266 "./marpa.w"
int t_length;
/*:270*//*279:*/
#line 2329 "./marpa.w"
int t_real_symbol_count;
/*:279*//*282:*/
#line 2347 "./marpa.w"
int t_virtual_start;
/*:282*//*285:*/
#line 2367 "./marpa.w"
int t_virtual_end;
/*:285*//*295:*/
#line 2425 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:295*/
#line 2214 "./marpa.w"

/*272:*/
#line 2292 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:272*//*275:*/
#line 2308 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:275*/
#line 2215 "./marpa.w"

/*265:*/
#line 2236 "./marpa.w"

ISYID t_isyid_array[1];

/*:265*/
#line 2216 "./marpa.w"

};
/*:260*//*309:*/
#line 2603 "./marpa.w"

struct sym_rule_pair
{
SYMID t_symid;
RULEID t_ruleid;
};

/*:309*//*381:*/
#line 4010 "./marpa.w"

struct s_AHFA_item{
int t_sort_key;
/*390:*/
#line 4059 "./marpa.w"

IRL t_irl;

/*:390*/
#line 4013 "./marpa.w"

/*391:*/
#line 4065 "./marpa.w"

int t_position;

/*:391*//*392:*/
#line 4072 "./marpa.w"
ISYID t_postdot_isyid;

/*:392*//*393:*/
#line 4081 "./marpa.w"

int t_leading_nulls;

/*:393*/
#line 4014 "./marpa.w"

};
/*:381*//*422:*/
#line 4386 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*426:*/
#line 4413 "./marpa.w"

ISYID*t_complete_isyids;

/*:426*//*428:*/
#line 4420 "./marpa.w"

AIM*t_items;
/*:428*//*445:*/
#line 4511 "./marpa.w"
Marpa_Symbol_ID*t_postdot_isyidary;
/*:445*//*505:*/
#line 5563 "./marpa.w"

TRANS*t_transitions;
/*:505*/
#line 4393 "./marpa.w"

/*425:*/
#line 4411 "./marpa.w"

unsigned int t_complete_isy_count;
/*:425*//*429:*/
#line 4423 "./marpa.w"

int t_item_count;
/*:429*//*446:*/
#line 4512 "./marpa.w"
unsigned int t_postdot_isy_count;

/*:446*//*452:*/
#line 4573 "./marpa.w"
ISYID t_leo_lhs_isyid;
/*:452*/
#line 4394 "./marpa.w"

/*433:*/
#line 4464 "./marpa.w"

unsigned int t_is_predict:1;

/*:433*//*436:*/
#line 4472 "./marpa.w"

unsigned int t_is_potential_leo_base:1;
/*:436*/
#line 4395 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:422*//*504:*/
#line 5552 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
int t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:504*//*520:*/
#line 5716 "./marpa.w"

struct s_input{
/*529:*/
#line 5786 "./marpa.w"

struct obstack*t_token_obs;

/*:529*//*531:*/
#line 5791 "./marpa.w"

GRAMMAR t_grammar;
/*:531*/
#line 5718 "./marpa.w"

/*523:*/
#line 5732 "./marpa.w"

int t_ref_count;
/*:523*/
#line 5719 "./marpa.w"

};

/*:520*//*597:*/
#line 6199 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:597*//*598:*/
#line 6204 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
int t_postdot_sym_count;
/*599:*/
#line 6216 "./marpa.w"

int t_eim_count;
/*:599*//*601:*/
#line 6230 "./marpa.w"

int t_ordinal;
/*:601*/
#line 6208 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*600:*/
#line 6219 "./marpa.w"

EIM*t_earley_items;

/*:600*//*1188:*/
#line 13728 "./marpa.w"

PSL t_dot_psl;
/*:1188*/
#line 6211 "./marpa.w"

};

/*:598*//*640:*/
#line 6691 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
ISYID t_postdot_isyid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:640*//*643:*/
#line 6725 "./marpa.w"

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

/*:643*//*653:*/
#line 6864 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:653*//*723:*/
#line 7820 "./marpa.w"

struct s_token_unvalued{
int t_type;
ISYID t_isyid;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:723*//*727:*/
#line 7849 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:727*//*832:*/
#line 9123 "./marpa.w"

struct s_ur_node_stack{
struct obstack*t_obs;
UR t_base;
UR t_top;
};
struct s_ur_node{
UR t_prev;
UR t_next;
EIM t_earley_item;
AEX t_aex;
};
/*:832*//*862:*/
#line 9557 "./marpa.w"

struct s_draft_or_node
{
/*861:*/
#line 9551 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:861*/
#line 9560 "./marpa.w"

DAND t_draft_and_node;
};
/*:862*//*863:*/
#line 9563 "./marpa.w"

struct s_final_or_node
{
/*861:*/
#line 9551 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:861*/
#line 9566 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:863*//*864:*/
#line 9574 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:864*//*887:*/
#line 9944 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:887*//*913:*/
#line 10340 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:913*//*954:*/
#line 10870 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:954*//*987:*/
#line 11221 "./marpa.w"

struct marpa_order{
struct obstack*t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
/*990:*/
#line 11241 "./marpa.w"

BOCAGE t_bocage;

/*:990*/
#line 11226 "./marpa.w"

/*993:*/
#line 11260 "./marpa.w"
int t_ref_count;
/*:993*/
#line 11227 "./marpa.w"

/*1004:*/
#line 11351 "./marpa.w"

unsigned int t_is_nulling:1;

/*:1004*/
#line 11228 "./marpa.w"

unsigned int t_is_frozen:1;
};
/*:987*//*1013:*/
#line 11550 "./marpa.w"

/*1052:*/
#line 12024 "./marpa.w"

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

/*:1052*/
#line 11551 "./marpa.w"

/*1066:*/
#line 12163 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1070:*/
#line 12217 "./marpa.w"

struct obstack*t_obs;
/*:1070*//*1075:*/
#line 12264 "./marpa.w"

DSTACK_DECLARE(t_virtual_stack);
/*:1075*//*1098:*/
#line 12422 "./marpa.w"

LBV t_xsy_is_valued;
LBV t_xrl_is_valued;
LBV t_valued_locked;

/*:1098*/
#line 12167 "./marpa.w"

/*1080:*/
#line 12308 "./marpa.w"

int t_ref_count;
/*:1080*//*1093:*/
#line 12398 "./marpa.w"

NOOKID t_nook;
/*:1093*/
#line 12168 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1088:*/
#line 12370 "./marpa.w"

unsigned int t_is_nulling:1;
/*:1088*//*1090:*/
#line 12377 "./marpa.w"

unsigned int t_trace:1;
/*:1090*/
#line 12171 "./marpa.w"

};

/*:1066*/
#line 11552 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_and_node_in_use;
Marpa_Order t_order;
/*1019:*/
#line 11622 "./marpa.w"

int t_ref_count;
/*:1019*//*1026:*/
#line 11702 "./marpa.w"
int t_pause_counter;
/*:1026*/
#line 11558 "./marpa.w"

/*1034:*/
#line 11794 "./marpa.w"

unsigned int t_is_exhausted:1;
/*:1034*//*1037:*/
#line 11802 "./marpa.w"

unsigned int t_is_nulling:1;

/*:1037*/
#line 11559 "./marpa.w"

int t_parse_count;
};

/*:1013*//*1172:*/
#line 13581 "./marpa.w"

struct s_dqueue{int t_current;struct s_dstack t_stack;};

/*:1172*//*1179:*/
#line 13649 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1179*//*1181:*/
#line 13674 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1181*/
#line 14446 "./marpa.w"

/*34:*/
#line 525 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:34*//*865:*/
#line 9582 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:865*//*931:*/
#line 10538 "./marpa.w"

static const struct marpa_progress_item progress_report_not_ready= {-2,-2,-2};

/*:931*//*1117:*/
#line 12836 "./marpa.w"

static const unsigned int bv_wordbits= lbv_wordbits;
static const unsigned int bv_modmask= lbv_wordbits-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= lbv_lsb;
static const unsigned int bv_msb= lbv_msb;

/*:1117*//*1240:*/
#line 14208 "./marpa.w"

int(*_marpa_debug_handler)(const char*,...)= 
MARPA_DEFAULT_DEBUG_HANDLER;
int _marpa_debug_level= 0;

/*:1240*/
#line 14447 "./marpa.w"

/*535:*/
#line 5807 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*548:*/
#line 5904 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:548*//*559:*/
#line 5973 "./marpa.w"
Bit_Vector t_bv_isyid_is_expected;
/*:559*//*581:*/
#line 6134 "./marpa.w"
struct obstack*t_obs;
/*:581*//*606:*/
#line 6270 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:606*//*627:*/
#line 6532 "./marpa.w"

EIM t_trace_earley_item;
/*:627*//*656:*/
#line 6910 "./marpa.w"

union u_postdot_item**t_trace_pim_isy_p;
union u_postdot_item*t_trace_postdot_item;
/*:656*//*690:*/
#line 7377 "./marpa.w"

SRCL t_trace_source_link;
/*:690*//*728:*/
#line 7857 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:728*//*743:*/
#line 8043 "./marpa.w"

LBV t_valued_terminal;
LBV t_unvalued_terminal;
LBV t_valued;
LBV t_unvalued;
LBV t_valued_locked;

/*:743*//*754:*/
#line 8264 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:754*//*758:*/
#line 8275 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:758*//*762:*/
#line 8286 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:762*//*786:*/
#line 8585 "./marpa.w"

Bit_Vector t_bv_lim_symbols;
Bit_Vector t_bv_pim_symbols;
void**t_pim_workarea;
/*:786*//*808:*/
#line 8867 "./marpa.w"

void**t_lim_chain;
/*:808*//*833:*/
#line 9136 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:833*//*926:*/
#line 10514 "./marpa.w"

const struct marpa_progress_item*t_current_report_item;
AVL_TRAV t_progress_report_traverser;
/*:926*//*1182:*/
#line 13682 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1182*/
#line 5810 "./marpa.w"

/*538:*/
#line 5832 "./marpa.w"
int t_ref_count;
/*:538*//*552:*/
#line 5931 "./marpa.w"
int t_earley_item_warning_threshold;
/*:552*//*556:*/
#line 5959 "./marpa.w"
EARLEME t_furthest_earleme;
/*:556*//*602:*/
#line 6234 "./marpa.w"

int t_earley_set_count;
/*:602*/
#line 5811 "./marpa.w"

/*545:*/
#line 5896 "./marpa.w"

unsigned int t_input_phase:2;
/*:545*//*573:*/
#line 6072 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:573*//*577:*/
#line 6110 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:577*//*691:*/
#line 7379 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:691*/
#line 5812 "./marpa.w"

};

/*:535*/
#line 14448 "./marpa.w"

/*670:*/
#line 7104 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:670*//*672:*/
#line 7116 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:672*//*673:*/
#line 7122 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:673*//*674:*/
#line 7129 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source_link t_unique;
};

/*:674*/
#line 14449 "./marpa.w"

/*620:*/
#line 6404 "./marpa.w"

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
/*625:*/
#line 6504 "./marpa.w"

unsigned int t_source_type:3;

/*:625*/
#line 6415 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:620*/
#line 14450 "./marpa.w"

/*943:*/
#line 10765 "./marpa.w"

struct marpa_bocage{
/*866:*/
#line 9592 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:866*//*945:*/
#line 10774 "./marpa.w"

INPUT t_input;

/*:945*//*947:*/
#line 10784 "./marpa.w"

struct obstack*t_obs;
/*:947*//*950:*/
#line 10843 "./marpa.w"

LBV t_valued_bv;
LBV t_valued_locked_bv;

/*:950*/
#line 10767 "./marpa.w"

/*867:*/
#line 9595 "./marpa.w"

int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:867*//*967:*/
#line 11024 "./marpa.w"
int t_ref_count;
/*:967*/
#line 10768 "./marpa.w"

/*974:*/
#line 11084 "./marpa.w"

unsigned int t_is_nulling:1;
/*:974*/
#line 10769 "./marpa.w"

};

/*:943*/
#line 14451 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1246:*/
#line 14275 "./marpa.w"

static const char*eim_tag_safe(char*buffer,EIM eim)UNUSED;
static const char*eim_tag(EIM eim)UNUSED;
/*:1246*//*1248:*/
#line 14300 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1248*//*1250:*/
#line 14326 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1250*//*1252:*/
#line 14358 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AIM aim)UNUSED;
static const char*aim_tag(AIM aim)UNUSED;
/*:1252*/
#line 14454 "./marpa.w"

/*1237:*/
#line 14181 "./marpa.w"

int _marpa_default_debug_handler(const char*format,...)
{
va_list args;
va_start(args,format);
vfprintf(stderr,format,args);
va_end(args);
putc('\n',stderr);
return 1;
}


/*:1237*//*1247:*/
#line 14279 "./marpa.w"

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

/*:1247*//*1249:*/
#line 14305 "./marpa.w"

static char*
lim_tag_safe(char*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_ISYID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}

static char DEBUG_lim_tag_buffer[1000];
static char*
lim_tag(LIM lim)
{
return lim_tag_safe(DEBUG_lim_tag_buffer,lim);
}

/*:1249*//*1251:*/
#line 14330 "./marpa.w"

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

/*:1251*//*1253:*/
#line 14361 "./marpa.w"

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

/*:1253*/
#line 14455 "./marpa.w"

#endif
/*35:*/
#line 531 "./marpa.w"

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
#line 547 "./marpa.w"

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
#line 610 "./marpa.w"

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
#line 629 "./marpa.w"

g->t_ref_count= 1;

/*:45*//*51:*/
#line 685 "./marpa.w"

DSTACK_INIT2(g->t_xsy_stack,XSY);
DSTACK_SAFE(g->t_isy_stack);

/*:51*//*60:*/
#line 740 "./marpa.w"

DSTACK_INIT2(g->t_xrl_stack,RULE);
DSTACK_SAFE(g->t_irl_stack);

/*:60*//*70:*/
#line 790 "./marpa.w"

g->t_start_xsyid= -1;
/*:70*//*74:*/
#line 819 "./marpa.w"

g->t_start_irl= NULL;
/*:74*//*78:*/
#line 836 "./marpa.w"

External_Size_of_G(g)= 0;

/*:78*//*81:*/
#line 849 "./marpa.w"

g->t_max_rule_length= 0;

/*:81*//*84:*/
#line 855 "./marpa.w"

g->t_is_precomputed= 0;
/*:84*//*87:*/
#line 867 "./marpa.w"

g->t_has_cycle= 0;
/*:87*//*90:*/
#line 887 "./marpa.w"
g->t_bv_isyid_is_terminal= NULL;

/*:90*//*97:*/
#line 926 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:97*//*104:*/
#line 984 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL,0);
/*:104*//*108:*/
#line 1008 "./marpa.w"

g->t_obs= my_obstack_init;
g->t_xrl_obs= my_obstack_begin(0,alignof(struct s_xrl));
/*:108*//*115:*/
#line 1054 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:115*//*387:*/
#line 4042 "./marpa.w"

g->t_AHFA_items= NULL;
/*:387*//*441:*/
#line 4484 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:441*/
#line 622 "./marpa.w"


g->t_is_ok= I_AM_OK;
return g;
}
/*:42*//*46:*/
#line 639 "./marpa.w"

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
#line 656 "./marpa.w"

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
#line 668 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
/*52:*/
#line 689 "./marpa.w"

{
DSTACK_DESTROY(g->t_xsy_stack);
DSTACK_DESTROY(g->t_isy_stack);
}

/*:52*//*61:*/
#line 744 "./marpa.w"

DSTACK_DESTROY(g->t_irl_stack);
DSTACK_DESTROY(g->t_xrl_stack);

/*:61*//*98:*/
#line 928 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:98*//*106:*/
#line 991 "./marpa.w"

/*105:*/
#line 986 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:105*/
#line 992 "./marpa.w"


/*:106*//*109:*/
#line 1011 "./marpa.w"

my_obstack_free(g->t_obs);
my_obstack_free(g->t_xrl_obs);

/*:109*//*388:*/
#line 4044 "./marpa.w"

my_free(g->t_AHFA_items);

/*:388*//*442:*/
#line 4488 "./marpa.w"

{
if(g->t_AHFA)
{
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}
}

/*:442*/
#line 672 "./marpa.w"

my_slice_free(struct marpa_g,g);
}

/*:49*//*54:*/
#line 697 "./marpa.w"

int marpa_g_symbol_count(Marpa_Grammar g){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 699 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 700 "./marpa.w"

return XSY_Count_of_G(g);
}

/*:54*//*56:*/
#line 710 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,SYM symbol)
{
const SYMID new_id= DSTACK_LENGTH((g)->t_xsy_stack);
*DSTACK_PUSH((g)->t_xsy_stack,SYM)= symbol;
symbol->t_symbol_id= new_id;
}

/*:56*//*57:*/
#line 720 "./marpa.w"

PRIVATE int xsyid_is_valid(GRAMMAR g,XSYID xsyid)
{
return xsyid>=0&&xsyid<XSY_Count_of_G(g);
}

/*:57*//*58:*/
#line 727 "./marpa.w"

PRIVATE int isy_is_valid(GRAMMAR g,ISYID isyid)
{
return isyid>=0&&isyid<ISY_Count_of_G(g);
}

/*:58*//*65:*/
#line 751 "./marpa.w"

int marpa_g_rule_count(Marpa_Grammar g){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 753 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 754 "./marpa.w"

return XRL_Count_of_G(g);
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 758 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 759 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:65*//*67:*/
#line 770 "./marpa.w"

PRIVATE void
rule_add(GRAMMAR g,RULE rule)
{
const RULEID new_id= DSTACK_LENGTH((g)->t_xrl_stack);
*DSTACK_PUSH((g)->t_xrl_stack,RULE)= rule;
rule->t_id= new_id;
External_Size_of_G(g)+= 1+Length_of_RULE(rule);
g->t_max_rule_length= MAX(Length_of_RULE(rule),g->t_max_rule_length);
}

/*:67*//*71:*/
#line 792 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 795 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 796 "./marpa.w"

return g->t_start_xsyid;
}
/*:71*//*72:*/
#line 801 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 804 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 805 "./marpa.w"

/*1219:*/
#line 14034 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1219*/
#line 806 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 807 "./marpa.w"

return g->t_start_xsyid= xsyid;
}

/*:72*//*85:*/
#line 857 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 860 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 861 "./marpa.w"

return G_is_Precomputed(g);
}

/*:85*//*88:*/
#line 869 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 872 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 873 "./marpa.w"

return g->t_has_cycle;
}

/*:88*//*100:*/
#line 938 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:100*//*101:*/
#line 947 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:101*//*102:*/
#line 957 "./marpa.w"

Marpa_Event_Type
marpa_g_event(Marpa_Grammar g,Marpa_Event*public_event,
int ix)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 962 "./marpa.w"

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
#line 1065 "./marpa.w"

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
#line 1101 "./marpa.w"

PRIVATE SYM
symbol_new(GRAMMAR g)
{
SYM symbol= my_obstack_new(g->t_obs,struct s_xsy,1);
/*126:*/
#line 1125 "./marpa.w"

SYM_is_LHS(symbol)= 0;

/*:126*//*128:*/
#line 1132 "./marpa.w"

SYM_is_Sequence_LHS(symbol)= 0;

/*:128*//*130:*/
#line 1140 "./marpa.w"

SYM_is_Semantic(symbol)= 1;
/*:130*//*133:*/
#line 1165 "./marpa.w"

XSY_is_Valued(symbol)= 0;
XSY_is_Valued_Locked(symbol)= 0;

/*:133*//*137:*/
#line 1206 "./marpa.w"

symbol->t_is_accessible= 0;
/*:137*//*140:*/
#line 1226 "./marpa.w"

symbol->t_is_counted= 0;
/*:140*//*143:*/
#line 1242 "./marpa.w"

symbol->t_is_nulling= 0;
/*:143*//*146:*/
#line 1258 "./marpa.w"

symbol->t_is_nullable= 0;
/*:146*//*149:*/
#line 1280 "./marpa.w"

symbol->t_is_terminal= 0;
symbol->t_is_locked_terminal= 0;
/*:149*//*154:*/
#line 1321 "./marpa.w"

symbol->t_is_productive= 0;
/*:154*//*157:*/
#line 1337 "./marpa.w"
symbol->t_is_start= 0;
/*:157*//*160:*/
#line 1357 "./marpa.w"
ISY_of_XSY(symbol)= NULL;
/*:160*//*163:*/
#line 1385 "./marpa.w"
Nulling_ISY_of_XSY(symbol)= NULL;
/*:163*/
#line 1106 "./marpa.w"

symbol_add(g,symbol);
return symbol;
}

/*:123*//*124:*/
#line 1111 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const SYM symbol= symbol_new(g);
return ID_of_SYM(symbol);
}

/*:124*//*131:*/
#line 1142 "./marpa.w"

int _marpa_g_symbol_is_semantic(
Marpa_Grammar g,
Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1147 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1148 "./marpa.w"

return SYM_is_Semantic(SYM_by_ID(xsyid));
}

/*:131*//*134:*/
#line 1169 "./marpa.w"

int marpa_g_symbol_is_valued(
Marpa_Grammar g,
Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1174 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1175 "./marpa.w"

return XSY_is_Valued(SYM_by_ID(xsyid));
}

/*:134*//*135:*/
#line 1179 "./marpa.w"

int marpa_g_symbol_is_valued_set(
Marpa_Grammar g,Marpa_Symbol_ID xsyid,int value)
{
SYM symbol;
const int valued_is_locked= -1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1185 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1186 "./marpa.w"

symbol= SYM_by_ID(xsyid);
if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
if(UNLIKELY(XSY_is_Valued_Locked(symbol)
&&value!=XSY_is_Valued(symbol)))
{
return valued_is_locked;
}
XSY_is_Valued(symbol)= value;
return value;
}

/*:135*//*138:*/
#line 1214 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1217 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1218 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 1219 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1220 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(xsyid));
}

/*:138*//*141:*/
#line 1228 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1232 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1233 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1234 "./marpa.w"

return SYM_by_ID(xsyid)->t_is_counted;
}

/*:141*//*144:*/
#line 1244 "./marpa.w"

int marpa_g_symbol_is_nulling(Marpa_Grammar g,Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1247 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1248 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 1249 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1250 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(xsyid));
}

/*:144*//*147:*/
#line 1260 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1263 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1264 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 1265 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1266 "./marpa.w"

return XSY_is_Nullable(SYM_by_ID(xsyid));
}

/*:147*//*151:*/
#line 1286 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1290 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1291 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1292 "./marpa.w"

return SYMID_is_Terminal(xsyid);
}
/*:151*//*152:*/
#line 1295 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID xsyid,int value)
{
SYM symbol;
const int terminal_is_locked= -1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1301 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1302 "./marpa.w"

/*1219:*/
#line 14034 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1219*/
#line 1303 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1304 "./marpa.w"

symbol= SYM_by_ID(xsyid);
if(UNLIKELY(value<0||value> 1)){
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
if(UNLIKELY(SYM_is_Locked_Terminal(symbol))){
return terminal_is_locked;
}
SYM_is_Locked_Terminal(symbol)= 1;
return XSY_is_Terminal(symbol)= value;
}

/*:152*//*155:*/
#line 1323 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1328 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1329 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 1330 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1331 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(xsyid));
}

/*:155*//*158:*/
#line 1338 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1341 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1342 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1343 "./marpa.w"

return SYM_by_ID(xsyid)->t_is_start;
}

/*:158*//*161:*/
#line 1358 "./marpa.w"

Marpa_ISY_ID _marpa_g_xsy_isy(
Marpa_Grammar g,
Marpa_Symbol_ID xsyid)
{
XSY xsy;
ISY isy;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1365 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1366 "./marpa.w"

xsy= XSY_by_ID(xsyid);
isy= ISY_of_XSY(xsy);
return isy?ID_of_ISY(isy):-1;
}

/*:161*//*164:*/
#line 1386 "./marpa.w"

Marpa_ISY_ID _marpa_g_xsy_nulling_isy(
Marpa_Grammar g,
Marpa_Symbol_ID xsyid)
{
XSY xsy;
ISY isy;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1393 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 1394 "./marpa.w"

xsy= XSY_by_ID(xsyid);
isy= Nulling_ISY_of_XSY(xsy);
return isy?ID_of_ISY(isy):-1;
}

/*:164*//*166:*/
#line 1406 "./marpa.w"

PRIVATE
ISY symbol_alias_create(GRAMMAR g,SYM symbol)
{
ISY alias_isy= isy_new(g,symbol);
SYM_is_Nulling(symbol)= 0;
XSY_is_Nullable(symbol)= 1;
ISY_is_Nulling(alias_isy)= 1;
return alias_isy;
}

/*:166*//*173:*/
#line 1452 "./marpa.w"

PRIVATE ISY
isy_start(GRAMMAR g)
{
const ISY isy= my_obstack_new(g->t_obs,struct s_isy,1);
ID_of_ISY(isy)= DSTACK_LENGTH((g)->t_isy_stack);
*DSTACK_PUSH((g)->t_isy_stack,ISY)= isy;
/*171:*/
#line 1447 "./marpa.w"

isy->t_or_node_type= NULLING_TOKEN_OR_NODE;

/*:171*//*180:*/
#line 1504 "./marpa.w"
ISY_is_Start(isy)= 0;
/*:180*//*183:*/
#line 1518 "./marpa.w"
ISY_is_LHS(isy)= 0;
/*:183*//*186:*/
#line 1532 "./marpa.w"
ISY_is_Nulling(isy)= 0;
/*:186*//*189:*/
#line 1549 "./marpa.w"
Source_XSY_of_ISY(isy)= NULL;
/*:189*//*193:*/
#line 1573 "./marpa.w"

LHS_XRL_of_ISY(isy)= NULL;
XRL_Offset_of_ISY(isy)= -1;

/*:193*/
#line 1459 "./marpa.w"

return isy;
}

/*:173*//*174:*/
#line 1464 "./marpa.w"

PRIVATE ISY
isy_new(GRAMMAR g,XSY source)
{
const ISY new_isy= isy_start(g);
Source_XSY_of_ISY(new_isy)= source;
return new_isy;
}

/*:174*//*175:*/
#line 1474 "./marpa.w"

PRIVATE ISY
isy_clone(GRAMMAR g,XSY xsy)
{
const ISY new_isy= isy_start(g);
Source_XSY_of_ISY(new_isy)= xsy;
ISY_is_Nulling(new_isy)= XSY_is_Nulling(xsy);
return new_isy;
}

/*:175*//*178:*/
#line 1494 "./marpa.w"

int _marpa_g_isy_count(Marpa_Grammar g){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1496 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1497 "./marpa.w"

return ISY_Count_of_G(g);
}

/*:178*//*181:*/
#line 1505 "./marpa.w"

int _marpa_g_isy_is_start(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1508 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1509 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 1510 "./marpa.w"

/*1222:*/
#line 14050 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1222*/
#line 1511 "./marpa.w"

return ISY_is_Start(ISY_by_ID(isy_id));
}

/*:181*//*184:*/
#line 1519 "./marpa.w"

int _marpa_g_isy_is_lhs(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1522 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1523 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 1524 "./marpa.w"

/*1222:*/
#line 14050 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1222*/
#line 1525 "./marpa.w"

return ISY_is_LHS(ISY_by_ID(isy_id));
}

/*:184*//*187:*/
#line 1533 "./marpa.w"

int _marpa_g_isy_is_nulling(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1536 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1537 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 1538 "./marpa.w"

/*1222:*/
#line 14050 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1222*/
#line 1539 "./marpa.w"

return ISY_is_Nulling(ISY_by_ID(isy_id));
}

/*:187*//*190:*/
#line 1550 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_IRL_ID isy_id)
{
XSY source_xsy;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1556 "./marpa.w"

/*1222:*/
#line 14050 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1222*/
#line 1557 "./marpa.w"

source_xsy= Source_XSY_of_ISY(ISY_by_ID(isy_id));
return source_xsy?ID_of_XSY(source_xsy):-1;
}

/*:190*//*195:*/
#line 1584 "./marpa.w"

Marpa_Rule_ID _marpa_g_isy_lhs_xrl(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1587 "./marpa.w"

/*1222:*/
#line 14050 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1222*/
#line 1588 "./marpa.w"

{
const ISY isy= ISY_by_ID(isy_id);
const XRL lhs_xrl= LHS_XRL_of_ISY(isy);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:195*//*196:*/
#line 1608 "./marpa.w"

int _marpa_g_isy_xrl_offset(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1611 "./marpa.w"

ISY isy;
/*1222:*/
#line 14050 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1222*/
#line 1613 "./marpa.w"

isy= ISY_by_ID(isy_id);
return XRL_Offset_of_ISY(isy);
}

/*:196*//*202:*/
#line 1649 "./marpa.w"

PRIVATE
XRL xrl_start(GRAMMAR g,const SYMID lhs,const SYMID*rhs,int length)
{
XRL xrl;
const int sizeof_xrl= offsetof(struct s_xrl,t_symbols)+
(length+1)*sizeof(xrl->t_symbols[0]);
my_obstack_blank(g->t_xrl_obs,sizeof_xrl);
xrl= my_obstack_base(g->t_xrl_obs);
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
/*222:*/
#line 1989 "./marpa.w"

rule->t_is_bnf= 0;

/*:222*//*224:*/
#line 1996 "./marpa.w"

rule->t_is_sequence= 0;
/*:224*//*227:*/
#line 2014 "./marpa.w"

rule->t_minimum= -1;

/*:227*//*229:*/
#line 2022 "./marpa.w"

Separator_of_XRL(rule)= -1;

/*:229*//*233:*/
#line 2041 "./marpa.w"

rule->t_is_discard= 0;
/*:233*//*237:*/
#line 2080 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:237*//*241:*/
#line 2100 "./marpa.w"

rule->t_is_loop= 0;
/*:241*//*244:*/
#line 2116 "./marpa.w"

XRL_is_Nulling(rule)= 0;
/*:244*//*247:*/
#line 2133 "./marpa.w"

XRL_is_Nullable(rule)= 0;
/*:247*//*251:*/
#line 2150 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:251*//*254:*/
#line 2167 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:254*/
#line 1674 "./marpa.w"

rule_add(g,rule);
return rule;
}

PRIVATE_NOT_INLINE
RULE rule_new(GRAMMAR g,
const SYMID lhs,const SYMID*rhs,int length)
{
RULE rule= xrl_start(g,lhs,rhs,length);
xrl_finish(g,rule);
rule= my_obstack_finish(g->t_xrl_obs);
return rule;
}

/*:202*//*203:*/
#line 1690 "./marpa.w"

PRIVATE IRL
irl_start(GRAMMAR g,int length)
{
IRL irl;
const int sizeof_irl= offsetof(struct s_irl,t_isyid_array)+
(length+1)*sizeof(irl->t_isyid_array[0]);
irl= my_obstack_alloc(g->t_obs,sizeof_irl);
ID_of_IRL(irl)= DSTACK_LENGTH((g)->t_irl_stack);
Length_of_IRL(irl)= length;
/*273:*/
#line 2293 "./marpa.w"

IRL_has_Virtual_LHS(irl)= 0;
/*:273*//*276:*/
#line 2309 "./marpa.w"

IRL_has_Virtual_RHS(irl)= 0;
/*:276*//*280:*/
#line 2330 "./marpa.w"
Real_SYM_Count_of_IRL(irl)= 0;
/*:280*//*283:*/
#line 2348 "./marpa.w"
irl->t_virtual_start= -1;
/*:283*//*286:*/
#line 2368 "./marpa.w"
irl->t_virtual_end= -1;
/*:286*//*289:*/
#line 2390 "./marpa.w"
Source_XRL_of_IRL(irl)= NULL;
/*:289*//*292:*/
#line 2412 "./marpa.w"

First_AIM_of_IRL(irl)= NULL;

/*:292*//*296:*/
#line 2428 "./marpa.w"

Last_Proper_SYMI_of_IRL(irl)= -1;
/*:296*/
#line 1700 "./marpa.w"

*DSTACK_PUSH((g)->t_irl_stack,IRL)= irl;
return irl;
}

PRIVATE void
irl_finish(GRAMMAR g,IRL irl)
{
const ISY lhs_isy= LHS_of_IRL(irl);
ISY_is_LHS(lhs_isy)= 1;
}

/*:203*//*205:*/
#line 1725 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,int length)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1730 "./marpa.w"

const int soft_failure= -1;
Marpa_Rule_ID rule_id;
RULE rule;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1734 "./marpa.w"

/*1219:*/
#line 14034 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1219*/
#line 1735 "./marpa.w"

if(UNLIKELY(length> MAX_RHS_LENGTH))
{
MARPA_ERROR(MARPA_ERR_RHS_TOO_LONG);
return failure_indicator;
}
if(UNLIKELY(!xsyid_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
{
int rh_index;
for(rh_index= 0;rh_index<length;rh_index++)
{
const SYMID rhs_id= rhs_ids[rh_index];
if(UNLIKELY(!xsyid_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
}
}
{
const SYM lhs= SYM_by_ID(lhs_id);
if(UNLIKELY(SYM_is_Sequence_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
return soft_failure;
}
}
rule= xrl_start(g,lhs_id,rhs_ids,length);
if(UNLIKELY(_marpa_avl_insert(g->t_xrl_tree,rule)!=NULL))
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
my_obstack_reject(g->t_xrl_obs);
return soft_failure;
}
rule= xrl_finish(g,rule);
rule= my_obstack_finish(g->t_xrl_obs);
XRL_is_BNF(rule)= 1;
rule_id= rule->t_id;
return rule_id;
}

/*:205*//*206:*/
#line 1780 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1787 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1788 "./marpa.w"

/*1219:*/
#line 14034 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1219*/
#line 1789 "./marpa.w"

/*208:*/
#line 1822 "./marpa.w"

{
if(separator_id!=-1)
{
if(UNLIKELY(!xsyid_is_valid(g,separator_id)))
{
MARPA_ERROR(MARPA_ERR_BAD_SEPARATOR);
goto FAILURE;
}
}
if(UNLIKELY(!xsyid_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
goto FAILURE;
}
{
const SYM lhs= SYM_by_ID(lhs_id);
if(UNLIKELY(SYM_is_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
goto SOFT_FAILURE;
}
}
if(UNLIKELY(!xsyid_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
goto FAILURE;
}
}

/*:208*/
#line 1790 "./marpa.w"

/*207:*/
#line 1800 "./marpa.w"

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

/*:207*/
#line 1791 "./marpa.w"

return original_rule_id;
SOFT_FAILURE:
return-1;
FAILURE:
return failure_indicator;
}

/*:206*//*210:*/
#line 1875 "./marpa.w"

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

/*:210*//*213:*/
#line 1931 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:213*//*214:*/
#line 1935 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1937 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1938 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 1939 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:214*//*215:*/
#line 1942 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:215*//*216:*/
#line 1946 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1949 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1950 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 1951 "./marpa.w"

rule= XRL_by_ID(xrl_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:216*//*217:*/
#line 1956 "./marpa.w"

PRIVATE size_t rule_length_get(RULE rule)
{
return Length_of_RULE(rule);}
/*:217*//*218:*/
#line 1960 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 1962 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 1963 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 1964 "./marpa.w"

return rule_length_get(XRL_by_ID(xrl_id));}

/*:218*//*225:*/
#line 1998 "./marpa.w"

int marpa_g_rule_is_sequence(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2003 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2004 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 2005 "./marpa.w"

return XRL_is_Sequence(XRL_by_ID(xrl_id));
}


/*:225*//*234:*/
#line 2043 "./marpa.w"

int marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2048 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2049 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 2050 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:234*//*238:*/
#line 2082 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2087 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2088 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 2089 "./marpa.w"

return!XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:238*//*242:*/
#line 2102 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2105 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2106 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 2107 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 2108 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:242*//*245:*/
#line 2118 "./marpa.w"

int marpa_g_rule_is_nulling(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2121 "./marpa.w"

XRL xrl;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2123 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 2124 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nulling(xrl);
}

/*:245*//*248:*/
#line 2135 "./marpa.w"

int marpa_g_rule_is_nullable(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2138 "./marpa.w"

XRL xrl;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2140 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 2141 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nullable(xrl);
}

/*:248*//*252:*/
#line 2152 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2155 "./marpa.w"

XRL xrl;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2157 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 2158 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:252*//*255:*/
#line 2169 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2172 "./marpa.w"

XRL xrl;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2174 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 2175 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:255*//*256:*/
#line 2185 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2189 "./marpa.w"

/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 2190 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:256*//*258:*/
#line 2197 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2202 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2203 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:258*//*267:*/
#line 2242 "./marpa.w"

Marpa_ISY_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
IRL irl;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2245 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2246 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2247 "./marpa.w"

irl= IRL_by_ID(irl_id);
return LHSID_of_IRL(irl);
}

/*:267*//*269:*/
#line 2254 "./marpa.w"

Marpa_ISY_ID _marpa_g_irl_rhs(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2257 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2258 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2259 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHSID_of_IRL(irl,ix);
}

/*:269*//*271:*/
#line 2267 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2269 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2270 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2271 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}

/*:271*//*274:*/
#line 2295 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2300 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 2301 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2302 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:274*//*277:*/
#line 2311 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2316 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 2317 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2318 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:277*//*281:*/
#line 2331 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2336 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 2337 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2338 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:281*//*284:*/
#line 2349 "./marpa.w"

unsigned int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2355 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 2356 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2357 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:284*//*287:*/
#line 2369 "./marpa.w"

unsigned int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2375 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 2376 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2377 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:287*//*290:*/
#line 2391 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2397 "./marpa.w"

/*1223:*/
#line 14055 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1223*/
#line 2398 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:290*//*298:*/
#line 2442 "./marpa.w"

PRIVATE int
symbol_instance_of_ahfa_item_get(AIM aim)
{
int position= Position_of_AIM(aim);
const int null_count= Null_Count_of_AIM(aim);
if(position<0||position-null_count> 0){

const IRL irl= IRL_of_AIM(aim);
position= Position_of_AIM(aim-1);
return SYMI_of_IRL(irl)+position;
}
return-1;
}

/*:298*//*300:*/
#line 2474 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 2477 "./marpa.w"

int return_value= failure_indicator;
struct obstack*obs_precompute= my_obstack_init;
/*304:*/
#line 2566 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);

/*:304*//*308:*/
#line 2599 "./marpa.w"

XSYID start_xsyid= g->t_start_xsyid;

/*:308*//*320:*/
#line 2889 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:320*/
#line 2480 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 2481 "./marpa.w"

G_EVENTS_CLEAR(g);
/*305:*/
#line 2570 "./marpa.w"

if(UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
goto SOFT_FAILURE;
}

/*:305*/
#line 2483 "./marpa.w"

/*1219:*/
#line 14034 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1219*/
#line 2484 "./marpa.w"

/*307:*/
#line 2580 "./marpa.w"

{
if(UNLIKELY(start_xsyid<0))
{
MARPA_ERROR(MARPA_ERR_NO_START_SYMBOL);
goto SOFT_FAILURE;
}
if(UNLIKELY(!xsyid_is_valid(g,start_xsyid)))
{
MARPA_ERROR(MARPA_ERR_INVALID_START_SYMBOL);
goto SOFT_FAILURE;
}
if(UNLIKELY(!SYM_is_LHS(SYM_by_ID(start_xsyid))))
{
MARPA_ERROR(MARPA_ERR_START_NOT_LHS);
goto SOFT_FAILURE;
}
}

/*:307*/
#line 2485 "./marpa.w"


g->t_is_precomputed= 1;
/*105:*/
#line 986 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:105*/
#line 2488 "./marpa.w"


{
/*313:*/
#line 2774 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:313*//*314:*/
#line 2777 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;
RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:314*//*318:*/
#line 2838 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:318*/
#line 2491 "./marpa.w"

/*303:*/
#line 2552 "./marpa.w"

{
/*311:*/
#line 2623 "./marpa.w"

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

lhs_v= bv_obs_create(obs_precompute,pre_census_xsy_count);
empty_lhs_v= bv_obs_shadow(obs_precompute,lhs_v);
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
AVL_TRAV traverser;
struct sym_rule_pair*pair;
SYMID seen_symid= -1;
RULEID*const rule_data_base= 
my_obstack_new(obs_precompute,RULEID,External_Size_of_G(g));
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(rhs_avl_tree);

xrl_list_x_rh_sym= my_obstack_new(obs_precompute,RULEID*,pre_census_xsy_count+1);
for(pair= _marpa_avl_t_first(traverser);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(traverser))
{
const SYMID current_symid= pair->t_symid;
while(seen_symid<current_symid)
xrl_list_x_rh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(++seen_symid<=pre_census_xsy_count)
xrl_list_x_rh_sym[seen_symid]= p_rule_data;
_marpa_avl_destroy(rhs_avl_tree);
}

{
AVL_TRAV traverser;
struct sym_rule_pair*pair;
SYMID seen_symid= -1;
RULEID*const rule_data_base= 
my_obstack_new(obs_precompute,RULEID,xrl_count);
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(lhs_avl_tree);

xrl_list_x_lh_sym= 
my_obstack_new(obs_precompute,RULEID*,pre_census_xsy_count+1);
for(pair= _marpa_avl_t_first(traverser);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(traverser))
{
const SYMID current_symid= pair->t_symid;
while(seen_symid<current_symid)
xrl_list_x_lh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(++seen_symid<=pre_census_xsy_count)
xrl_list_x_lh_sym[seen_symid]= p_rule_data;
_marpa_avl_destroy(lhs_avl_tree);
}

}

/*:311*/
#line 2554 "./marpa.w"

/*312:*/
#line 2745 "./marpa.w"

{
SYMID symid;
terminal_v= bv_obs_create(obs_precompute,pre_census_xsy_count);
bv_not(terminal_v,lhs_v);
for(symid= 0;symid<pre_census_xsy_count;symid++)
{
SYM symbol= SYM_by_ID(symid);
if(SYM_is_Locked_Terminal(symbol))
{


if(XSY_is_Terminal(symbol))
{
bv_bit_set(terminal_v,(unsigned int)symid);
continue;
}
bv_bit_clear(terminal_v,(unsigned int)symid);
continue;
}



if(bv_bit_test(terminal_v,(unsigned int)symid))
XSY_is_Terminal(symbol)= 1;
}
}

/*:312*/
#line 2555 "./marpa.w"

/*319:*/
#line 2860 "./marpa.w"

{
XRLID rule_id;
reach_matrix= matrix_obs_create(obs_precompute,pre_census_xsy_count,pre_census_xsy_count);
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

/*:319*/
#line 2556 "./marpa.w"

/*315:*/
#line 2783 "./marpa.w"

{
unsigned int min,max,start;
XSYID xsyid;
int counted_nullables= 0;
nullable_v= bv_obs_clone(obs_precompute,empty_lhs_v);
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
goto SOFT_FAILURE;
}
}

/*:315*/
#line 2557 "./marpa.w"

/*316:*/
#line 2811 "./marpa.w"

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

/*:316*/
#line 2558 "./marpa.w"

/*317:*/
#line 2832 "./marpa.w"

if(UNLIKELY(!bv_bit_test(productive_v,(unsigned int)start_xsyid)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto SOFT_FAILURE;
}
/*:317*/
#line 2559 "./marpa.w"

/*321:*/
#line 2894 "./marpa.w"

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

/*:321*/
#line 2560 "./marpa.w"

/*322:*/
#line 2914 "./marpa.w"

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
if(UNLIKELY(XSY_is_Terminal(symbol)))
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
goto SOFT_FAILURE;
}
}

/*:322*/
#line 2561 "./marpa.w"

/*323:*/
#line 2953 "./marpa.w"

{
XRLID xrl_id;
for(xrl_id= 0;xrl_id<xrl_count;xrl_id++)
{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID lhs_id= LHS_ID_of_XRL(xrl);
const XSY lhs= XSY_by_ID(lhs_id);
XRL_is_Accessible(xrl)= XSY_is_Accessible(lhs);
if(XRL_is_Sequence(xrl)&&Minimum_of_XRL(xrl)<=0)
{
XRL_is_Nulling(xrl)= 0;
XRL_is_Nullable(xrl)= 1;
XRL_is_Productive(xrl)= 1;
continue;
}
{
int rh_ix;
int is_nulling= 1;
int is_nullable= 1;
int is_productive= 1;
for(rh_ix= 0;rh_ix<Length_of_XRL(xrl);rh_ix++)
{
const XSYID rhs_id= RHS_ID_of_XRL(xrl,rh_ix);
const XSY rh_xsy= XSY_by_ID(rhs_id);
if(LIKELY(!XSY_is_Nulling(rh_xsy)))
is_nulling= 0;
if(LIKELY(!XSY_is_Nullable(rh_xsy)))
is_nullable= 0;
if(UNLIKELY(!XSY_is_Productive(rh_xsy)))
is_productive= 0;
}
XRL_is_Nulling(xrl)= is_nulling;
XRL_is_Nullable(xrl)= is_nullable;
XRL_is_Productive(xrl)= is_productive;
}
}
}

/*:323*/
#line 2562 "./marpa.w"

/*324:*/
#line 3001 "./marpa.w"

if(0)
{



XSYID xsyid;
for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++)
{
if(bv_bit_test(terminal_v,xsyid)&&bv_bit_test(lhs_v,xsyid))
{
const XSY xsy= XSY_by_ID(xsyid);
if(XSY_is_Valued_Locked(xsy))
continue;
XSY_is_Valued(xsy)= 1;
XSY_is_Valued_Locked(xsy)= 1;
}
}
}

/*:324*/
#line 2563 "./marpa.w"

}

/*:303*/
#line 2492 "./marpa.w"

/*371:*/
#line 3803 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,(unsigned int)xrl_count,
(unsigned int)xrl_count);
/*372:*/
#line 3824 "./marpa.w"

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
XSYID xsyid= RHS_ID_of_RULE(rule,rhs_ix);
if(bv_bit_test(nullable_v,xsyid))
continue;
nonnulling_id= xsyid;
nonnulling_count++;
}
if(nonnulling_count==1)
{
/*373:*/
#line 3867 "./marpa.w"

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

/*:373*/
#line 3845 "./marpa.w"

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

/*373:*/
#line 3867 "./marpa.w"

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

/*:373*/
#line 3858 "./marpa.w"

}
}
}
}

/*:372*/
#line 3809 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*374:*/
#line 3881 "./marpa.w"

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

/*:374*/
#line 3811 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:371*/
#line 2493 "./marpa.w"

}

/*475:*/
#line 4996 "./marpa.w"

DSTACK_INIT(g->t_irl_stack,IRL,2*DSTACK_CAPACITY(g->t_xrl_stack));

/*:475*/
#line 2496 "./marpa.w"

/*476:*/
#line 5004 "./marpa.w"

{
DSTACK_INIT(g->t_isy_stack,ISY,2*DSTACK_CAPACITY(g->t_xsy_stack));
}

/*:476*/
#line 2497 "./marpa.w"

/*336:*/
#line 3165 "./marpa.w"

{
/*337:*/
#line 3196 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:337*//*340:*/
#line 3254 "./marpa.w"

int factor_count;
int*factor_positions;
/*:340*/
#line 3167 "./marpa.w"

/*341:*/
#line 3257 "./marpa.w"

factor_positions= my_obstack_new(obs_precompute,int,g->t_max_rule_length);

/*:341*/
#line 3168 "./marpa.w"

/*338:*/
#line 3202 "./marpa.w"

{
XSYID xsyid;
for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++)
{
const XSY xsy= XSY_by_ID(xsyid);
if(UNLIKELY(!xsy->t_is_accessible))
continue;
if(UNLIKELY(!xsy->t_is_productive))
continue;
ISY_of_XSY(xsy)= isy_clone(g,xsy);
if(XSY_is_Nulling(xsy))
{
Nulling_ISY_of_XSY(xsy)= ISY_of_XSY(xsy);
continue;
}
if(XSY_is_Nullable(xsy))
{
Nulling_ISY_of_XSY(xsy)= symbol_alias_create(g,xsy);
}
}
}

/*:338*/
#line 3169 "./marpa.w"

pre_chaf_rule_count= XRL_Count_of_G(g);
for(rule_id= 0;rule_id<pre_chaf_rule_count;rule_id++)
{

XRL rule= XRL_by_ID(rule_id);
XRL rewrite_xrl= rule;
const int rewrite_xrl_length= Length_of_XRL(rewrite_xrl);
int nullable_suffix_ix= 0;
if(!XRL_is_Used(rule))
continue;
if(XRL_is_Sequence(rule))
{
/*325:*/
#line 3022 "./marpa.w"

{
const SYMID lhs_id= LHS_ID_of_RULE(rule);
const ISY lhs_isy= ISY_by_XSYID(lhs_id);
const ISYID lhs_isyid= ID_of_ISY(lhs_isy);

const ISY internal_lhs_isy= isy_new(g,SYM_by_ID(lhs_id));
const ISYID internal_lhs_isyid= ID_of_ISY(internal_lhs_isy);

const SYMID rhs_id= RHS_ID_of_RULE(rule,0);
const ISY rhs_isy= ISY_by_XSYID(rhs_id);
const ISYID rhs_isyid= ID_of_ISY(rhs_isy);

const SYMID separator_id= Separator_of_XRL(rule);
ISYID separator_isyid= -1;
if(separator_id>=0){
const ISY separator_isy= ISY_by_XSYID(separator_id);
separator_isyid= ID_of_ISY(separator_isy);
}

LHS_XRL_of_ISY(internal_lhs_isy)= rule;
/*326:*/
#line 3051 "./marpa.w"

{
IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= lhs_isyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_isyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;

IRL_has_Virtual_RHS(rewrite_irl)= 1;
}

/*:326*/
#line 3043 "./marpa.w"

if(separator_isyid>=0&&!XRL_is_Proper_Separation(rule)){
/*327:*/
#line 3063 "./marpa.w"

{
IRL rewrite_irl;
rewrite_irl= irl_start(g,2);
LHSID_of_IRL(rewrite_irl)= lhs_isyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_isyid;
RHSID_of_IRL(rewrite_irl,1)= separator_isyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
IRL_has_Virtual_RHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= 1;
}

/*:327*/
#line 3045 "./marpa.w"

}
/*328:*/
#line 3079 "./marpa.w"

{
const IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= internal_lhs_isyid;
RHSID_of_IRL(rewrite_irl,0)= rhs_isyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
IRL_has_Virtual_LHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= 1;
}
/*:328*/
#line 3047 "./marpa.w"

/*329:*/
#line 3089 "./marpa.w"

{
IRL rewrite_irl;
int rhs_ix= 0;
const int length= separator_isyid>=0?3:2;
rewrite_irl= irl_start(g,length);
LHSID_of_IRL(rewrite_irl)= internal_lhs_isyid;
RHSID_of_IRL(rewrite_irl,rhs_ix++)= internal_lhs_isyid;
if(separator_isyid>=0)
RHSID_of_IRL(rewrite_irl,rhs_ix++)= separator_isyid;
RHSID_of_IRL(rewrite_irl,rhs_ix)= rhs_isyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
IRL_has_Virtual_LHS(rewrite_irl)= 1;
IRL_has_Virtual_RHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= length-1;
}

/*:329*/
#line 3048 "./marpa.w"

}

/*:325*/
#line 3182 "./marpa.w"

continue;
}
/*339:*/
#line 3233 "./marpa.w"

{
int rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rewrite_xrl_length;rhs_ix++)
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
/*:339*/
#line 3185 "./marpa.w"


if(factor_count> 0)
{
/*342:*/
#line 3261 "./marpa.w"

{
const XRL chaf_xrl= rule;


int unprocessed_factor_count;

int factor_position_ix= 0;
ISY current_lhs_isy= ISY_by_XSYID(LHS_ID_of_RULE(rule));
ISYID current_lhs_isyid= ID_of_ISY(current_lhs_isy);


int piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*345:*/
#line 3297 "./marpa.w"

ISY chaf_virtual_isy;
ISYID chaf_virtual_isyid;
int first_factor_position= factor_positions[factor_position_ix];
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*343:*/
#line 3287 "./marpa.w"

{
const SYMID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_isy= isy_new(g,SYM_by_ID(chaf_xrl_lhs_id));
chaf_virtual_isyid= ID_of_ISY(chaf_virtual_isy);
}

/*:343*/
#line 3305 "./marpa.w"

/*346:*/
#line 3324 "./marpa.w"

{
{
const int real_symbol_count= piece_end-piece_start+1;
/*351:*/
#line 3420 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_isyid;
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3433 "./marpa.w"

}

/*:351*/
#line 3328 "./marpa.w"
;
}
/*347:*/
#line 3338 "./marpa.w"

{
int piece_ix;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= rewrite_xrl_length-piece_start;
const int real_symbol_count= chaf_irl_length;

IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
for(piece_ix= second_nulling_piece_ix;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3359 "./marpa.w"

}

/*:347*/
#line 3330 "./marpa.w"
;
{
const int real_symbol_count= piece_end-piece_start+1;
/*353:*/
#line 3464 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_isyid;
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3487 "./marpa.w"

}

/*:353*/
#line 3333 "./marpa.w"
;
}
/*348:*/
#line 3367 "./marpa.w"

{
if(piece_start<nullable_suffix_ix)
{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int second_nulling_piece_ix= 
second_factor_position-piece_start;
const int chaf_irl_length= rewrite_xrl_length-piece_start;
const int real_symbol_count= chaf_irl_length;

IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
for(piece_ix= second_nulling_piece_ix;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3404 "./marpa.w"

}
}

/*:348*/
#line 3335 "./marpa.w"
;
}

/*:346*/
#line 3306 "./marpa.w"

factor_position_ix++;
}else{
piece_end= second_factor_position;
/*343:*/
#line 3287 "./marpa.w"

{
const SYMID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_isy= isy_new(g,SYM_by_ID(chaf_xrl_lhs_id));
chaf_virtual_isyid= ID_of_ISY(chaf_virtual_isy);
}

/*:343*/
#line 3310 "./marpa.w"

/*350:*/
#line 3410 "./marpa.w"

{
const int real_symbol_count= piece_end-piece_start+1;
/*351:*/
#line 3420 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_isyid;
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3433 "./marpa.w"

}

/*:351*/
#line 3413 "./marpa.w"

/*352:*/
#line 3437 "./marpa.w"

{
int piece_ix;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;
piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_isyid;
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3460 "./marpa.w"

}

/*:352*/
#line 3414 "./marpa.w"

/*353:*/
#line 3464 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_isyid;
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3487 "./marpa.w"

}

/*:353*/
#line 3415 "./marpa.w"

/*354:*/
#line 3491 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length-1;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_isyid;
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3524 "./marpa.w"

}

/*:354*/
#line 3416 "./marpa.w"

}

/*:350*/
#line 3311 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_isy= chaf_virtual_isy;
current_lhs_isyid= chaf_virtual_isyid;
piece_start= piece_end+1;

/*:345*/
#line 3278 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*355:*/
#line 3529 "./marpa.w"

{
const int first_factor_position= factor_positions[factor_position_ix];
const int second_factor_position= factor_positions[factor_position_ix+1];
const int real_symbol_count= Length_of_RULE(rule)-piece_start;
piece_end= Length_of_RULE(rule)-1;
/*356:*/
#line 3542 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<chaf_irl_length;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3554 "./marpa.w"

}

/*:356*/
#line 3535 "./marpa.w"

/*357:*/
#line 3558 "./marpa.w"

{
int piece_ix;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3580 "./marpa.w"

}

/*:357*/
#line 3536 "./marpa.w"

/*358:*/
#line 3584 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3606 "./marpa.w"

}

/*:358*/
#line 3537 "./marpa.w"

/*359:*/
#line 3611 "./marpa.w"

{
if(piece_start<nullable_suffix_ix){
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;piece_ix<second_nulling_piece_ix;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3645 "./marpa.w"

}
}

/*:359*/
#line 3538 "./marpa.w"

}

/*:355*/
#line 3281 "./marpa.w"

}else{
/*360:*/
#line 3650 "./marpa.w"

{
int real_symbol_count;
const int first_factor_position= factor_positions[factor_position_ix];
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*361:*/
#line 3661 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<chaf_irl_length;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3673 "./marpa.w"

}

/*:361*/
#line 3656 "./marpa.w"

/*362:*/
#line 3678 "./marpa.w"

{
if(piece_start<nullable_suffix_ix)
{
int piece_ix;
const int nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_isyid;
for(piece_ix= 0;piece_ix<nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,nulling_piece_ix)= 
Nulling_ISYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+nulling_piece_ix));
for(piece_ix= nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
ISYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
/*363:*/
#line 3711 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_ISY(current_lhs_isy)= chaf_xrl;
XRL_Offset_of_ISY(current_lhs_isy)= piece_start;
}

/*:363*/
#line 3703 "./marpa.w"

}
}

/*:362*/
#line 3657 "./marpa.w"

}

/*:360*/
#line 3283 "./marpa.w"

}
}

/*:342*/
#line 3189 "./marpa.w"

continue;
}
/*204:*/
#line 1712 "./marpa.w"

{
int symbol_ix;
const IRL new_irl= irl_start(g,rewrite_xrl_length);
Source_XRL_of_IRL(new_irl)= rule;
for(symbol_ix= 0;symbol_ix<=rewrite_xrl_length;symbol_ix++)
{
new_irl->t_isyid_array[symbol_ix]= 
ISYID_by_XSYID(rule->t_symbols[symbol_ix]);
}
irl_finish(g,new_irl);
}

/*:204*/
#line 3192 "./marpa.w"

}
}

/*:336*/
#line 2498 "./marpa.w"

/*365:*/
#line 3728 "./marpa.w"

{
const XSY start_xsy= SYM_by_ID(start_xsyid);
if(LIKELY(!SYM_is_Nulling(start_xsy))){
/*366:*/
#line 3736 "./marpa.w"
{
IRL new_start_irl;

const ISY new_start_isy= isy_new(g,start_xsy);
ISY_is_Start(new_start_isy)= 1;

start_xsy->t_is_start= 0;

new_start_irl= irl_start(g,1);
LHSID_of_IRL(new_start_irl)= ID_of_ISY(new_start_isy);
RHSID_of_IRL(new_start_irl,0)= ISYID_of_XSY(start_xsy);
irl_finish(g,new_start_irl);
IRL_has_Virtual_LHS(new_start_irl)= 1;
Real_SYM_Count_of_IRL(new_start_irl)= 1;
g->t_start_irl= new_start_irl;

}

/*:366*/
#line 3732 "./marpa.w"

}
}

/*:365*/
#line 2499 "./marpa.w"


if(!G_is_Trivial(g)){
/*474:*/
#line 4985 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
AIM*const item_list_working_buffer
= my_obstack_alloc(obs_precompute,irl_count*sizeof(AIM));
const ISYID isy_count= ISY_Count_of_G(g);
const XSYID xsy_count= XSY_Count_of_G(g);
IRLID**irl_list_x_lh_isy= NULL;

/*:474*/
#line 2503 "./marpa.w"

/*477:*/
#line 5009 "./marpa.w"

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
const ISYID lhs_isyid= LHSID_of_IRL(irl);
p_sym_rule_pairs->t_symid= lhs_isyid;
p_sym_rule_pairs->t_ruleid= irl_id;
_marpa_avl_insert(lhs_avl_tree,p_sym_rule_pairs);
p_sym_rule_pairs++;
}
{
AVL_TRAV traverser;
struct sym_rule_pair*pair;
ISYID seen_isyid= -1;
IRLID*const rule_data_base= 
my_obstack_new(obs_precompute,IRLID,irl_count);
IRLID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(lhs_avl_tree);

irl_list_x_lh_isy= 
my_obstack_new(obs_precompute,IRLID*,isy_count+1);
for(pair= _marpa_avl_t_first(traverser);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(traverser))
{
const ISYID current_isyid= pair->t_symid;
while(seen_isyid<current_isyid)
irl_list_x_lh_isy[++seen_isyid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(++seen_isyid<=isy_count)
irl_list_x_lh_isy[seen_isyid]= p_rule_data;
}
_marpa_avl_destroy(lhs_avl_tree);
}

/*:477*/
#line 2504 "./marpa.w"

/*402:*/
#line 4131 "./marpa.w"

{
IRLID irl_id;
AIMID ahfa_item_count= 0;
AIM base_item;
AIM current_item;
unsigned int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*404:*/
#line 4182 "./marpa.w"

{
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
const ISYID rh_isyid= RHSID_of_IRL(irl,rhs_ix);
const ISY isy= ISY_by_ID(rh_isyid);
if(!ISY_is_Nulling(isy))ahfa_item_count++;
}
ahfa_item_count++;
}

/*:404*/
#line 4140 "./marpa.w"

}
current_item= base_item= my_new(struct s_AHFA_item,ahfa_item_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*403:*/
#line 4159 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
ISYID rh_isyid= RHSID_of_IRL(irl,rhs_ix);
if(!ISY_is_Nulling(ISY_by_ID(rh_isyid)))
{
Last_Proper_SYMI_of_IRL(irl)= symbol_instance_of_next_rule+rhs_ix;
/*405:*/
#line 4194 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_ISYID_of_AIM(current_item)= rh_isyid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:405*/
#line 4169 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*406:*/
#line 4203 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_ISYID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:406*/
#line 4178 "./marpa.w"

current_item++;
}

/*:403*/
#line 4145 "./marpa.w"

{
SYMI_of_IRL(irl)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_IRL(irl);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(ahfa_item_count==current_item-base_item);
AIM_Count_of_G(g)= ahfa_item_count;
g->t_AHFA_items= my_renew(struct s_AHFA_item,base_item,ahfa_item_count);
/*407:*/
#line 4217 "./marpa.w"

{
AIM items= g->t_AHFA_items;
AIMID item_id= (AIMID)ahfa_item_count;
for(item_id--;item_id>=0;item_id--)
{
AIM item= items+item_id;
IRL irl= IRL_of_AIM(item);
First_AIM_of_IRL(irl)= item;
}
}

/*:407*/
#line 4155 "./marpa.w"

/*412:*/
#line 4275 "./marpa.w"

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

/*:412*/
#line 4156 "./marpa.w"

}

/*:402*/
#line 2505 "./marpa.w"

/*458:*/
#line 4630 "./marpa.w"

{
/*459:*/
#line 4648 "./marpa.w"

AHFA p_working_state;
const unsigned int initial_no_of_states= 2*AIM_Count_of_G(g);
AIM AHFA_item_0_p= g->t_AHFA_items;
Bit_Matrix prediction_matrix;
IRL*irl_by_sort_key= my_new(IRL,irl_count);
Bit_Vector per_ahfa_complete_v= bv_obs_create(obs_precompute,isy_count);
Bit_Vector per_ahfa_postdot_v= bv_obs_create(obs_precompute,isy_count);
AVL_TREE duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
int ahfa_count_of_g;
AHFA ahfas_of_g;

/*:459*/
#line 4632 "./marpa.w"

/*460:*/
#line 4662 "./marpa.w"

/*461:*/
#line 4666 "./marpa.w"

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

/*:461*/
#line 4663 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:460*/
#line 4633 "./marpa.w"

/*486:*/
#line 5252 "./marpa.w"
{
Bit_Matrix isy_by_isy_matrix= 
matrix_obs_create(obs_precompute,isy_count,isy_count);
/*487:*/
#line 5260 "./marpa.w"

{
IRLID irl_id;
ISYID isyid;
for(isyid= 0;isyid<isy_count;isyid++)
{

ISY isy= ISY_by_ID(isyid);
if(!ISY_is_LHS(isy))continue;
matrix_bit_set(isy_by_isy_matrix,(unsigned int)isyid,(unsigned int)isyid);
}
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
ISYID from_isyid,to_isyid;
const IRL irl= IRL_by_ID(irl_id);

const AIM item= First_AIM_of_IRL(irl);
to_isyid= Postdot_ISYID_of_AIM(item);

if(to_isyid<0)
continue;

from_isyid= LHS_ISYID_of_AIM(item);
matrix_bit_set(isy_by_isy_matrix,(unsigned int)from_isyid,(unsigned int)to_isyid);
}
}

/*:487*/
#line 5255 "./marpa.w"

transitive_closure(isy_by_isy_matrix);
/*488:*/
#line 5293 "./marpa.w"
{
unsigned int*sort_key_by_irl_id= my_new(unsigned int,irl_count);
/*490:*/
#line 5311 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
irl_by_sort_key[irl_id]= IRL_by_ID(irl_id);
}
qsort(irl_by_sort_key,(int)irl_count,
sizeof(RULE),cmp_by_irl_sort_key);
}

/*:490*/
#line 5295 "./marpa.w"

/*492:*/
#line 5349 "./marpa.w"

{
IRLID sort_ordinal;
for(sort_ordinal= 0;sort_ordinal<irl_count;sort_ordinal++)
{
IRL irl= irl_by_sort_key[sort_ordinal];
sort_key_by_irl_id[ID_of_IRL(irl)]= sort_ordinal;
}
}

/*:492*/
#line 5296 "./marpa.w"

/*493:*/
#line 5359 "./marpa.w"

{
ISYID from_isyid;
prediction_matrix= 
matrix_obs_create(obs_precompute,isy_count,
irl_count);
for(from_isyid= 0;from_isyid<isy_count;from_isyid++)
{

unsigned int min,max,start;
for(start= 0;
bv_scan(matrix_row
(isy_by_isy_matrix,(unsigned int)from_isyid),
start,&min,&max);start= max+2)
{
ISYID to_isyid;
for(to_isyid= min;to_isyid<=(ISYID)max;to_isyid++)
{

RULEID*p_irl_x_lh_isy= irl_list_x_lh_isy[to_isyid];
const RULEID*p_one_past_rules= irl_list_x_lh_isy[to_isyid+1];
for(;p_irl_x_lh_isy<p_one_past_rules;p_irl_x_lh_isy++)
{

const IRLID irl_with_this_lhs= *p_irl_x_lh_isy;
unsigned int sort_ordinal= 
sort_key_by_irl_id[irl_with_this_lhs];
matrix_bit_set(prediction_matrix,
(unsigned int)from_isyid,sort_ordinal);

}
}
}
}
}

/*:493*/
#line 5297 "./marpa.w"

my_free(sort_key_by_irl_id);
}

/*:488*/
#line 5257 "./marpa.w"

}

/*:486*/
#line 4634 "./marpa.w"

/*468:*/
#line 4815 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
const IRL start_irl= g->t_start_irl;
ISYID*postdot_isyidary;
AIM start_item;
ISYID postdot_isyid;
AIM*item_list= my_obstack_alloc(g->t_obs,sizeof(AIM));

start_item= First_AIM_of_IRL(start_irl);
item_list[0]= start_item;
AHFA_initialize(p_initial_state);
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= 1;
p_initial_state->t_key.t_id= 0;
AHFA_is_Predicted(p_initial_state)= 0;
TRANSs_of_AHFA(p_initial_state)= transitions_new(g,isy_count);
Postdot_ISY_Count_of_AHFA(p_initial_state)= 1;
postdot_isyidary= Postdot_ISYIDAry_of_AHFA(p_initial_state)= 
my_obstack_alloc(g->t_obs,sizeof(ISYID));
postdot_isyid= Postdot_ISYID_of_AIM(start_item);
*postdot_isyidary= postdot_isyid;
Complete_ISY_Count_of_AHFA(p_initial_state)= 0;
p_initial_state->t_empty_transition= create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(unsigned int)postdot_isyid),
irl_by_sort_key,&states,duplicates,
item_list_working_buffer);
}

/*:468*/
#line 4635 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*462:*/
#line 4678 "./marpa.w"

{
unsigned int no_of_items= p_working_state->t_item_count;
unsigned int current_item_ix= 0;
AIM*item_list;
ISYID working_isyid;
item_list= p_working_state->t_items;
working_isyid= Postdot_ISYID_of_AIM(item_list[0]);

if(working_isyid<0)
goto NEXT_AHFA_STATE;

while(1)
{
int first_working_item_ix= current_item_ix;
int no_of_items_in_new_state;
for(current_item_ix++;
current_item_ix<no_of_items;current_item_ix++)
{
if(Postdot_ISYID_of_AIM(item_list[current_item_ix])!=
working_isyid)
break;
}
no_of_items_in_new_state= current_item_ix-first_working_item_ix;
if(no_of_items_in_new_state==1)
{
/*471:*/
#line 4873 "./marpa.w"
{
AHFA p_new_state;
AIM*new_state_item_list;
AIM single_item_p= item_list[first_working_item_ix];
Marpa_AHFA_Item_ID single_item_id;
ISYID postdot_isyid;
single_item_p++;
single_item_id= single_item_p-AHFA_item_0_p;
p_new_state= singleton_duplicates[single_item_id];
if(p_new_state)
{
transition_add(obs_precompute,p_working_state,working_isyid,p_new_state);
goto NEXT_WORKING_SYMBOL;
}
p_new_state= DQUEUE_PUSH(states,AHFA_Object);

AHFA_initialize(p_new_state);
singleton_duplicates[single_item_id]= p_new_state;
new_state_item_list= p_new_state->t_items= 
my_obstack_alloc(g->t_obs,sizeof(AIM));
new_state_item_list[0]= single_item_p;
p_new_state->t_item_count= 1;
AHFA_is_Predicted(p_new_state)= 0;
p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
TRANSs_of_AHFA(p_new_state)= transitions_new(g,isy_count);
transition_add(obs_precompute,p_working_state,working_isyid,p_new_state);
postdot_isyid= Postdot_ISYID_of_AIM(single_item_p);
if(postdot_isyid>=0)
{
ISYID*p_postdot_isyidary= Postdot_ISYIDAry_of_AHFA(p_new_state)= 
my_obstack_alloc(g->t_obs,sizeof(ISYID));
Complete_ISY_Count_of_AHFA(p_new_state)= 0;
Postdot_ISY_Count_of_AHFA(p_new_state)= 1;
*p_postdot_isyidary= postdot_isyid;


p_new_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(unsigned int)postdot_isyid),
irl_by_sort_key,&states,duplicates,
item_list_working_buffer);
}
else
{
ISYID lhs_isyid= LHS_ISYID_of_AIM(single_item_p);
ISYID*complete_isyids= my_obstack_alloc(g->t_obs,sizeof(ISYID));
*complete_isyids= lhs_isyid;
Complete_ISYIDs_of_AHFA(p_new_state)= complete_isyids;
completion_count_inc(obs_precompute,p_new_state,lhs_isyid);
Complete_ISY_Count_of_AHFA(p_new_state)= 1;
Postdot_ISY_Count_of_AHFA(p_new_state)= 0;
p_new_state->t_empty_transition= NULL;
/*473:*/
#line 4959 "./marpa.w"

{
AIM previous_ahfa_item= single_item_p-1;
ISYID predot_isyid= Postdot_ISYID_of_AIM(previous_ahfa_item);
if(ISY_is_LHS(ISY_by_ID(predot_isyid)))
{
Leo_LHS_ISYID_of_AHFA(p_new_state)= lhs_isyid;
}
}

/*:473*/
#line 4927 "./marpa.w"

}
}

/*:471*/
#line 4704 "./marpa.w"

}
else
{
/*478:*/
#line 5052 "./marpa.w"

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
transition_add(obs_precompute,p_working_state,working_isyid,
queued_AHFA_state);
goto NEXT_WORKING_SYMBOL;
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
{
int i;
AIM*const final_aim_list= p_new_state->t_items= 
my_obstack_alloc(g->t_obs,no_of_items_in_new_state*sizeof(AIM));
for(i= 0;i<no_of_items_in_new_state;i++){
final_aim_list[i]= item_list_working_buffer[i];
}
}
AHFA_initialize(p_new_state);
AHFA_is_Predicted(p_new_state)= 0;
TRANSs_of_AHFA(p_new_state)= transitions_new(g,isy_count);
/*479:*/
#line 5109 "./marpa.w"

{
int item_ix;
int no_of_postdot_isys;
int no_of_complete_symbols;
bv_clear(per_ahfa_complete_v);
bv_clear(per_ahfa_postdot_v);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_working_buffer[item_ix];
ISYID postdot_isyid= Postdot_ISYID_of_AIM(item);
if(postdot_isyid<0)
{
ISYID complete_symbol_isyid= LHS_ISYID_of_AIM(item);
completion_count_inc(obs_precompute,p_new_state,complete_symbol_isyid);
bv_bit_set(per_ahfa_complete_v,(unsigned int)complete_symbol_isyid);
}
else
{
bv_bit_set(per_ahfa_postdot_v,(unsigned int)postdot_isyid);
}
}
if((no_of_postdot_isys= Postdot_ISY_Count_of_AHFA(p_new_state)= 
bv_count(per_ahfa_postdot_v)))
{
unsigned int min,max,start;
ISYID*p_isyid= Postdot_ISYIDAry_of_AHFA(p_new_state)= 
my_obstack_alloc(g->t_obs,
no_of_postdot_isys*sizeof(ISYID));
for(start= 0;bv_scan(per_ahfa_postdot_v,start,&min,&max);start= max+2)
{
ISYID postdot_isyid;
for(postdot_isyid= (ISYID)min;
postdot_isyid<=(ISYID)max;postdot_isyid++)
{
*p_isyid++= postdot_isyid;
}
}
}
if((no_of_complete_symbols= 
Complete_ISY_Count_of_AHFA(p_new_state)= bv_count(per_ahfa_complete_v)))
{
unsigned int min,max,start;
ISYID*complete_isyids= my_obstack_alloc(g->t_obs,
no_of_complete_symbols*
sizeof(ISYID));
ISYID*p_isyid= complete_isyids;
Complete_ISYIDs_of_AHFA(p_new_state)= complete_isyids;
for(start= 0;bv_scan(per_ahfa_complete_v,start,&min,&max);
start= max+2)
{
ISYID complete_isyid;
for(complete_isyid= (ISYID)min;
complete_isyid<=(ISYID)max;complete_isyid++)
{
*p_isyid++= complete_isyid;
}
}
}
}

/*:479*/
#line 5102 "./marpa.w"

transition_add(obs_precompute,p_working_state,working_isyid,
p_new_state);
/*481:*/
#line 5185 "./marpa.w"

{
int item_ix;
ISYID postdot_isyid= -1;
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
postdot_isyid= Postdot_ISYID_of_AIM(item_list_working_buffer[item_ix]);
if(postdot_isyid>=0)
break;
}
p_new_state->t_empty_transition= NULL;
if(postdot_isyid>=0)
{
Bit_Vector predicted_rule_vector
= bv_shadow(matrix_row(prediction_matrix,postdot_isyid));
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{

postdot_isyid= Postdot_ISYID_of_AIM(item_list_working_buffer[item_ix]);
if(postdot_isyid<0)
continue;
bv_or_assign(predicted_rule_vector,
matrix_row(prediction_matrix,postdot_isyid));
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

/*:481*/
#line 5106 "./marpa.w"

}

/*:478*/
#line 4708 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)
break;
working_isyid= Postdot_ISYID_of_AIM(item_list[current_item_ix]);
if(working_isyid<0)
break;
}
NEXT_AHFA_STATE:;
}

/*:462*/
#line 4637 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*463:*/
#line 4720 "./marpa.w"

{
int ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
ISYID isyid;
AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
for(isyid= 0;isyid<isy_count;isyid++){
TRANS working_transition= transitions[isyid];
if(working_transition){
int completion_count= Completion_Count_of_TRANS(working_transition);
int sizeof_transition= 
offsetof(struct s_transition,t_aex)+completion_count*
sizeof(transitions[0]->t_aex[0]);
TRANS new_transition= my_obstack_alloc(g->t_obs,sizeof_transition);
LV_To_AHFA_of_TRANS(new_transition)= To_AHFA_of_TRANS(working_transition);
LV_Completion_Count_of_TRANS(new_transition)= 0;
transitions[isyid]= new_transition;
}
}
}
}

/*:463*/
#line 4642 "./marpa.w"

/*465:*/
#line 4774 "./marpa.w"

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
ISYID postdot_isyid= Postdot_ISYID_of_AIM(ahfa_item);
if(postdot_isyid>=0)
{
TRANS transition= transitions[postdot_isyid];
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

/*:465*/
#line 4643 "./marpa.w"

/*464:*/
#line 4743 "./marpa.w"

{
int ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
const AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
if(Complete_ISY_Count_of_AHFA(ahfa)> 0){
AIM*aims= AIMs_of_AHFA(ahfa);
int aim_count= AIM_Count_of_AHFA(ahfa);
AEX aex;
for(aex= 0;aex<aim_count;aex++){
AIM ahfa_item= aims[aex];
if(AIM_is_Completion(ahfa_item)){
ISYID completed_isyid= LHS_ISYID_of_AIM(ahfa_item);
TRANS transition= transitions[completed_isyid];
AEX*aexes= AEXs_of_TRANS(transition);
int aex_ix= LV_Completion_Count_of_TRANS(transition)++;
aexes[aex_ix]= aex;
}
}
}
}
}

/*:464*/
#line 4644 "./marpa.w"

/*466:*/
#line 4807 "./marpa.w"

my_free(irl_by_sort_key);
/*467:*/
#line 4811 "./marpa.w"

my_free(singleton_duplicates);
_marpa_avl_destroy(duplicates);

/*:467*/
#line 4809 "./marpa.w"


/*:466*/
#line 4645 "./marpa.w"

}

/*:458*/
#line 2506 "./marpa.w"

/*517:*/
#line 5687 "./marpa.w"

{
int xsyid;
g->t_bv_isyid_is_terminal= bv_obs_create(g->t_obs,isy_count);
for(xsyid= 0;xsyid<xsy_count;xsyid++)
{
if(SYMID_is_Terminal(xsyid))
{


const ISY isy= ISY_of_XSY(XSY_by_ID(xsyid));
if(isy)
{
bv_bit_set(g->t_bv_isyid_is_terminal,
(unsigned int)ID_of_ISY(isy));
}
}
}
}

/*:517*/
#line 2507 "./marpa.w"

}
return_value= G_EVENT_COUNT(g);
goto CLEANUP;
SOFT_FAILURE:;
return_value= -1;
goto CLEANUP;
CLEANUP:;
my_obstack_free(obs_precompute);
return return_value;
}
/*:300*//*310:*/
#line 2610 "./marpa.w"

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

/*:310*//*389:*/
#line 4048 "./marpa.w"

PRIVATE int aim_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:389*//*394:*/
#line 4085 "./marpa.w"

int _marpa_g_AHFA_item_count(Marpa_Grammar g){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 4087 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 4088 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:394*//*395:*/
#line 4092 "./marpa.w"

Marpa_IRL_ID _marpa_g_AHFA_item_irl(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 4095 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 4096 "./marpa.w"

/*1225:*/
#line 14065 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1225*/
#line 4097 "./marpa.w"

return IRLID_of_AIM(AIM_by_ID(item_id));
}

/*:395*//*397:*/
#line 4102 "./marpa.w"

int _marpa_g_AHFA_item_position(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 4105 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 4106 "./marpa.w"

/*1225:*/
#line 14065 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1225*/
#line 4107 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:397*//*399:*/
#line 4112 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_item_postdot(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 4115 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 4116 "./marpa.w"

/*1225:*/
#line 14065 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1225*/
#line 4117 "./marpa.w"

return Postdot_ISYID_of_AIM(AIM_by_ID(item_id));
}

/*:399*//*400:*/
#line 4121 "./marpa.w"

int _marpa_g_AHFA_item_sort_key(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 4124 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 4125 "./marpa.w"

/*1225:*/
#line 14065 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1225*/
#line 4126 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:400*//*409:*/
#line 4236 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:409*//*411:*/
#line 4251 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_postdot_and_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
int a_postdot= Postdot_ISYID_of_AIM(a);
int b_postdot= Postdot_ISYID_of_AIM(b);
if(a_postdot==b_postdot)
return Sort_Key_of_AIM(a)-Sort_Key_of_AIM(b);
if(a_postdot<0)return 1;
if(b_postdot<0)return-1;
return a_postdot-b_postdot;
}

/*:411*//*423:*/
#line 4402 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*437:*/
#line 4474 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;

/*:437*//*453:*/
#line 4574 "./marpa.w"
Leo_LHS_ISYID_of_AHFA(ahfa)= -1;
/*:453*/
#line 4405 "./marpa.w"

}

/*:423*//*431:*/
#line 4435 "./marpa.w"

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

/*:431*//*444:*/
#line 4501 "./marpa.w"

PRIVATE int AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:444*//*447:*/
#line 4515 "./marpa.w"

int _marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:447*//*448:*/
#line 4520 "./marpa.w"

int
_marpa_g_AHFA_state_item_count(Marpa_Grammar g,AHFAID AHFA_state_id)
{/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 4523 "./marpa.w"

AHFA state;
/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 4525 "./marpa.w"

/*1226:*/
#line 14070 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1226*/
#line 4526 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:448*//*449:*/
#line 4533 "./marpa.w"

Marpa_AHFA_Item_ID _marpa_g_AHFA_state_item(Marpa_Grammar g,
AHFAID AHFA_state_id,
int item_ix){
AHFA state;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 4538 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 4539 "./marpa.w"

/*1226:*/
#line 14070 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1226*/
#line 4540 "./marpa.w"

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

/*:449*//*450:*/
#line 4553 "./marpa.w"

int _marpa_g_AHFA_state_is_predict(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 4557 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 4558 "./marpa.w"

/*1226:*/
#line 14070 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1226*/
#line 4559 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:450*//*454:*/
#line 4575 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_state_leo_lhs_symbol(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 4578 "./marpa.w"

AHFA state;
/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 4580 "./marpa.w"

/*1226:*/
#line 14070 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1226*/
#line 4581 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ISYID_of_AHFA(state);
}

/*:454*//*457:*/
#line 4602 "./marpa.w"

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

/*:457*//*480:*/
#line 5176 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,AVL_TREE duplicates)
{
const AHFA state_found= _marpa_avl_insert(duplicates,sought_state);
return state_found;
}

/*:480*//*491:*/
#line 5327 "./marpa.w"

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

/*:491*//*494:*/
#line 5395 "./marpa.w"

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
item_list_working_buffer[item_list_ix++]= First_AIM_of_IRL(irl);
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
my_obstack_alloc(g->t_obs,no_of_items_in_new_state*sizeof(AIM));
for(i= 0;i<no_of_items_in_new_state;i++)
{
final_aim_list[i]= item_list_working_buffer[i];
}
}
AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_empty_transition= NULL;
TRANSs_of_AHFA(p_new_state)= transitions_new(g,ISY_Count_of_G(g));
Complete_ISY_Count_of_AHFA(p_new_state)= 0;
/*495:*/
#line 5459 "./marpa.w"

{
ISYID isy_count= ISY_Count_of_G(g);
int item_ix;
ISYID no_of_postdot_isys;
Bit_Vector postdot_v= bv_create(isy_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_working_buffer[item_ix];
ISYID postdot_isyid= Postdot_ISYID_of_AIM(item);
if(postdot_isyid>=0)
bv_bit_set(postdot_v,(unsigned int)postdot_isyid);
}
if((no_of_postdot_isys= Postdot_ISY_Count_of_AHFA(p_new_state)= 
bv_count(postdot_v)))
{
unsigned int min,max,start;
ISYID*p_isyid= Postdot_ISYIDAry_of_AHFA(p_new_state)= 
my_obstack_alloc(g->t_obs,
no_of_postdot_isys*sizeof(ISYID));
for(start= 0;bv_scan(postdot_v,start,&min,&max);start= max+2)
{
ISYID postdot_isyid;
for(postdot_isyid= (ISYID)min;
postdot_isyid<=(ISYID)max;postdot_isyid++)
{
*p_isyid++= postdot_isyid;
}
}
}
bv_free(postdot_v);
}

/*:495*/
#line 5455 "./marpa.w"

return p_new_state;
}

/*:494*//*506:*/
#line 5565 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:506*//*507:*/
#line 5571 "./marpa.w"

PRIVATE int completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:507*//*508:*/
#line 5578 "./marpa.w"

PRIVATE
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,int aim_ix)
{
URTRANS transition;
transition= my_obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:508*//*509:*/
#line 5589 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g,int isy_count)
{
int isyid= 0;
TRANS*transitions= my_obstack_new(g->t_obs,TRANS,isy_count);
while(isyid<isy_count)transitions[isyid++]= NULL;


return transitions;
}

/*:509*//*510:*/
#line 5600 "./marpa.w"

PRIVATE
void transition_add(struct obstack*obstack,AHFA from_ahfa,ISYID isyid,AHFA to_ahfa)
{
TRANS*transitions= TRANSs_of_AHFA(from_ahfa);
TRANS transition= transitions[isyid];
if(!transition){
transitions[isyid]= (TRANS)transition_new(obstack,to_ahfa,0);
return;
}
LV_To_AHFA_of_TRANS(transition)= to_ahfa;
return;
}

/*:510*//*511:*/
#line 5614 "./marpa.w"

PRIVATE
void completion_count_inc(struct obstack*obstack,AHFA from_ahfa,ISYID isyid)
{
TRANS*transitions= TRANSs_of_AHFA(from_ahfa);
TRANS transition= transitions[isyid];
if(!transition){
transitions[isyid]= (TRANS)transition_new(obstack,NULL,1);
return;
}
LV_Completion_Count_of_TRANS(transition)++;
return;
}

/*:511*//*513:*/
#line 5629 "./marpa.w"

int _marpa_g_AHFA_state_transitions(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id,
int*buffer,
int buffer_size
){

/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 5636 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID isyid;
int isy_count;
int ix= 0;
const int max_ix= buffer_size/sizeof(*buffer);
const int max_results= max_ix/2;





/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 5649 "./marpa.w"

/*1226:*/
#line 14070 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1226*/
#line 5650 "./marpa.w"

if(max_results<=0)return 0;
from_ahfa_state= AHFA_of_G_by_ID(g,AHFA_state_id);
transitions= TRANSs_of_AHFA(from_ahfa_state);
isy_count= ISY_Count_of_G(g);
for(isyid= 0;isyid<isy_count;isyid++){
AHFA to_ahfa_state= To_AHFA_of_TRANS(transitions[isyid]);
if(!to_ahfa_state)continue;
buffer[ix++]= isyid;
buffer[ix++]= ID_of_AHFA(to_ahfa_state);
if(ix/2>=max_results)break;
}
return ix/2;
}

/*:513*//*516:*/
#line 5670 "./marpa.w"

AHFAID _marpa_g_AHFA_state_empty_transition(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 5675 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 5676 "./marpa.w"

/*1226:*/
#line 14070 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1226*/
#line 5677 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:516*//*521:*/
#line 5722 "./marpa.w"

PRIVATE INPUT input_new(GRAMMAR g)
{
INPUT input= my_slice_new(struct s_input);
TOK_Obs_of_I(input)= my_obstack_init;
/*524:*/
#line 5734 "./marpa.w"

input->t_ref_count= 1;

/*:524*//*532:*/
#line 5793 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:532*/
#line 5727 "./marpa.w"

return input;
}

/*:521*//*525:*/
#line 5738 "./marpa.w"

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

/*:525*//*526:*/
#line 5751 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:526*//*527:*/
#line 5764 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
my_obstack_free(TOK_Obs_of_I(input));
my_slice_free(struct s_input,input);
}

/*:527*//*536:*/
#line 5819 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
/*1217:*/
#line 14026 "./marpa.w"
void*const failure_indicator= NULL;
/*:1217*/
#line 5823 "./marpa.w"

/*1220:*/
#line 14040 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1220*/
#line 5824 "./marpa.w"

r= my_slice_new(struct marpa_r);
/*582:*/
#line 6135 "./marpa.w"
r->t_obs= my_obstack_init;
/*:582*/
#line 5826 "./marpa.w"

/*539:*/
#line 5833 "./marpa.w"

r->t_ref_count= 1;

/*:539*//*547:*/
#line 5899 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:547*//*549:*/
#line 5908 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:549*//*553:*/
#line 5932 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:553*//*557:*/
#line 5960 "./marpa.w"
r->t_furthest_earleme= 0;
/*:557*//*560:*/
#line 5974 "./marpa.w"
r->t_bv_isyid_is_expected= NULL;
/*:560*//*574:*/
#line 6075 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:574*//*578:*/
#line 6111 "./marpa.w"
r->t_is_exhausted= 0;
/*:578*//*603:*/
#line 6236 "./marpa.w"

r->t_earley_set_count= 0;

/*:603*//*607:*/
#line 6272 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:607*//*628:*/
#line 6534 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:628*//*657:*/
#line 6913 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;
/*:657*//*692:*/
#line 7381 "./marpa.w"

r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:692*//*725:*/
#line 7831 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:725*//*729:*/
#line 7865 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:729*//*755:*/
#line 8265 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:755*//*759:*/
#line 8276 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:759*//*763:*/
#line 8287 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:763*//*834:*/
#line 9142 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:834*//*927:*/
#line 10517 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
r->t_progress_report_traverser= NULL;
/*:927*//*1183:*/
#line 13684 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1183*/
#line 5827 "./marpa.w"

return r;
}

/*:536*//*540:*/
#line 5837 "./marpa.w"

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

/*:540*//*541:*/
#line 5855 "./marpa.w"

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

/*:541*//*542:*/
#line 5869 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 5873 "./marpa.w"

/*544:*/
#line 5887 "./marpa.w"
input_unref(input);

/*:544*//*730:*/
#line 7867 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:730*//*757:*/
#line 8269 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:757*//*761:*/
#line 8280 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:761*//*764:*/
#line 8288 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:764*//*835:*/
#line 9144 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:835*//*929:*/
#line 10526 "./marpa.w"

/*928:*/
#line 10520 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(TREE_of_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:928*/
#line 10527 "./marpa.w"
;
/*:929*//*1184:*/
#line 13686 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1184*/
#line 5874 "./marpa.w"

grammar_unref(g);
/*583:*/
#line 6136 "./marpa.w"
my_obstack_free(r->t_obs);

/*:583*/
#line 5876 "./marpa.w"

my_slice_free(struct marpa_r,r);
}

/*:542*//*550:*/
#line 5916 "./marpa.w"

unsigned int marpa_r_current_earleme(Marpa_Recognizer r)
{return Current_Earleme_of_R(r);}

/*:550*//*551:*/
#line 5921 "./marpa.w"

PRIVATE ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:551*//*554:*/
#line 5934 "./marpa.w"

int
marpa_r_earley_item_warning_threshold(Marpa_Recognizer r)
{
return r->t_earley_item_warning_threshold;
}

/*:554*//*555:*/
#line 5943 "./marpa.w"

int
marpa_r_earley_item_warning_threshold_set(Marpa_Recognizer r,int threshold)
{
const int new_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
r->t_earley_item_warning_threshold= new_threshold;
return new_threshold;
}

/*:555*//*558:*/
#line 5961 "./marpa.w"

unsigned int marpa_r_furthest_earleme(Marpa_Recognizer r)
{return Furthest_Earleme_of_R(r);}

/*:558*//*563:*/
#line 5990 "./marpa.w"

int marpa_r_terminals_expected(Marpa_Recognizer r,Marpa_Symbol_ID*buffer)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 5993 "./marpa.w"

/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 5994 "./marpa.w"

unsigned int min,max,start;
int ix= 0;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 5997 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 5998 "./marpa.w"

for(start= 0;bv_scan(r->t_bv_isyid_is_expected,start,&min,&max);
start= max+2)
{
ISYID isyid;
for(isyid= (ISYID)min;isyid<=(ISYID)max;isyid++)
{
const ISY isy= ISY_by_ID(isyid);
const XSY xsy= Source_XSY_of_ISY(isy);
buffer[ix++]= ID_of_XSY(xsy);
}
}
return ix;
}

/*:563*//*575:*/
#line 6081 "./marpa.w"

int _marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6084 "./marpa.w"

/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6085 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 6086 "./marpa.w"

return r->t_use_leo_flag;
}
/*:575*//*576:*/
#line 6089 "./marpa.w"

int _marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6093 "./marpa.w"

/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6094 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 6095 "./marpa.w"

/*1227:*/
#line 14079 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1227*/
#line 6096 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:576*//*580:*/
#line 6121 "./marpa.w"

int marpa_r_is_exhausted(Marpa_Recognizer r)
{
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6124 "./marpa.w"

/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6125 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 6126 "./marpa.w"

return R_is_Exhausted(r);
}

/*:580*//*585:*/
#line 6140 "./marpa.w"

Marpa_Error_Code marpa_r_error(Marpa_Recognizer r,const char**p_error_string)
{
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6143 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:585*//*588:*/
#line 6152 "./marpa.w"

int marpa_r_event(Marpa_Recognizer r,Marpa_Event*public_event,int ix)
{
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6155 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:588*//*604:*/
#line 6240 "./marpa.w"

PRIVATE ES
earley_set_new(RECCE r,EARLEME id)
{
ESK_Object key;
ES set;
set= my_obstack_alloc(r->t_obs,sizeof(*set));
key.t_earleme= id;
set->t_key= key;
set->t_postdot_ary= NULL;
set->t_postdot_sym_count= 0;
EIM_Count_of_ES(set)= 0;
set->t_ordinal= r->t_earley_set_count++;
EIMs_of_ES(set)= NULL;
Next_ES_of_ES(set)= NULL;
/*1189:*/
#line 13730 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1189*/
#line 6255 "./marpa.w"

return set;
}

/*:604*//*608:*/
#line 6275 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_trace_earley_set(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6278 "./marpa.w"

/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6279 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6281 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:608*//*609:*/
#line 6289 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6292 "./marpa.w"

/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6293 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6294 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:609*//*610:*/
#line 6298 "./marpa.w"

Marpa_Earleme marpa_r_earleme(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
const int es_does_not_exist= -1;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6302 "./marpa.w"

/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6303 "./marpa.w"

ES earley_set;
/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 6305 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 6306 "./marpa.w"

if(set_id<0){
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
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

/*:610*//*612:*/
#line 6322 "./marpa.w"

int _marpa_r_earley_set_size(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6325 "./marpa.w"

ES earley_set;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6327 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 6328 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 6329 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:612*//*621:*/
#line 6425 "./marpa.w"

PRIVATE EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1217:*/
#line 14026 "./marpa.w"
void*const failure_indicator= NULL;
/*:1217*/
#line 6429 "./marpa.w"

/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6430 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const int count= ++EIM_Count_of_ES(set);
/*623:*/
#line 6477 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_EIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:623*/
#line 6435 "./marpa.w"

new_item= my_obstack_alloc(r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:621*//*622:*/
#line 6445 "./marpa.w"

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

/*:622*//*626:*/
#line 6509 "./marpa.w"

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

/*:626*//*633:*/
#line 6574 "./marpa.w"

Marpa_Earleme
_marpa_r_earley_set_trace(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const int es_does_not_exist= -1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6580 "./marpa.w"

/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6581 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6582 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*634:*/
#line 6605 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*659:*/
#line 6952 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:659*/
#line 6608 "./marpa.w"

}

/*:634*/
#line 6589 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
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

/*:633*//*635:*/
#line 6611 "./marpa.w"

Marpa_AHFA_State_ID
_marpa_r_earley_item_trace(Marpa_Recognizer r,Marpa_Earley_Item_ID item_id)
{
const int eim_does_not_exist= -1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6616 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6620 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6621 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*634:*/
#line 6605 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*659:*/
#line 6952 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:659*/
#line 6608 "./marpa.w"

}

/*:634*/
#line 6625 "./marpa.w"

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

/*:635*//*637:*/
#line 6654 "./marpa.w"

PRIVATE void trace_earley_item_clear(RECCE r)
{
/*636:*/
#line 6651 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:636*/
#line 6657 "./marpa.w"

trace_source_link_clear(r);
}

/*:637*//*638:*/
#line 6661 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_earley_item_origin(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6664 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6666 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6667 "./marpa.w"

if(!item){
/*636:*/
#line 6651 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:636*/
#line 6669 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:638*//*645:*/
#line 6742 "./marpa.w"

Marpa_Symbol_ID _marpa_r_leo_predecessor_symbol(Marpa_Recognizer r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6746 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6749 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6750 "./marpa.w"

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
return Postdot_ISYID_of_LIM(predecessor_leo_item);
}

/*:645*//*646:*/
#line 6764 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_leo_base_origin(Marpa_Recognizer r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6768 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6770 "./marpa.w"

EIM base_earley_item;
/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6772 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:646*//*647:*/
#line 6782 "./marpa.w"

Marpa_AHFA_State_ID _marpa_r_leo_base_state(Marpa_Recognizer r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6786 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6789 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6790 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:647*//*651:*/
#line 6824 "./marpa.w"

Marpa_AHFA_State_ID _marpa_r_leo_expansion_ahfa(Marpa_Recognizer r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6828 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6830 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6831 "./marpa.w"

if(!postdot_item)
{
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(!EIM_of_PIM(postdot_item))
{
const LIM leo_item= LIM_of_PIM(postdot_item);
const EIM base_earley_item= Base_EIM_of_LIM(leo_item);
const ISYID postdot_isyid= Postdot_ISYID_of_LIM(leo_item);
const AHFA to_ahfa= To_AHFA_of_EIM_by_ISYID(base_earley_item,postdot_isyid);
return ID_of_AHFA(to_ahfa);
}
return pim_is_not_a_leo_item;
}


/*:651*//*654:*/
#line 6877 "./marpa.w"

PRIVATE PIM*
pim_isy_p_find(ES set,ISYID isyid)
{
int lo= 0;
int hi= Postdot_SYM_Count_of_ES(set)-1;
PIM*postdot_array= set->t_postdot_ary;
while(hi>=lo){
int trial= lo+(hi-lo)/2;
PIM trial_pim= postdot_array[trial];
ISYID trial_isyid= Postdot_ISYID_of_PIM(trial_pim);
if(trial_isyid==isyid)return postdot_array+trial;
if(trial_isyid<isyid){
lo= trial+1;
}else{
hi= trial-1;
}
}
return NULL;
}
/*:654*//*655:*/
#line 6897 "./marpa.w"

PRIVATE PIM first_pim_of_es_by_isyid(ES set,ISYID isyid)
{
PIM*pim_isy_p= pim_isy_p_find(set,isyid);
return pim_isy_p?*pim_isy_p:NULL;
}

/*:655*//*658:*/
#line 6927 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_postdot_symbol_trace(Marpa_Recognizer r,
Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6932 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_isy_p;
PIM pim;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6936 "./marpa.w"

/*659:*/
#line 6952 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:659*/
#line 6937 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6938 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 6939 "./marpa.w"

if(!current_es){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
pim_isy_p= PIM_ISY_P_of_ES_by_ISYID(current_es,ISYID_by_XSYID(xsyid));
pim= *pim_isy_p;
if(!pim)return-1;
r->t_trace_pim_isy_p= pim_isy_p;
r->t_trace_postdot_item= pim;
return xsyid;
}

/*:658*//*660:*/
#line 6962 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_postdot_item_trace(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6966 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 6969 "./marpa.w"

PIM*pim_isy_p;
/*659:*/
#line 6952 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:659*/
#line 6971 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 6972 "./marpa.w"

if(!current_earley_set){
/*636:*/
#line 6651 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:636*/
#line 6974 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
if(current_earley_set->t_postdot_sym_count<=0)return-1;
pim_isy_p= current_earley_set->t_postdot_ary+0;
pim= pim_isy_p[0];
r->t_trace_pim_isy_p= pim_isy_p;
r->t_trace_postdot_item= pim;
return Postdot_ISYID_of_PIM(pim);
}

/*:660*//*661:*/
#line 6993 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_postdot_item_trace(Marpa_Recognizer r)
{
const SYMID no_more_postdot_symbols= -1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 6998 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_isy_p;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7002 "./marpa.w"


pim_isy_p= r->t_trace_pim_isy_p;
pim= r->t_trace_postdot_item;
/*659:*/
#line 6952 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:659*/
#line 7006 "./marpa.w"

if(!pim_isy_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7011 "./marpa.w"

if(!current_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
pim= Next_PIM_of_PIM(pim);
if(!pim){

pim_isy_p++;
if(pim_isy_p-current_set->t_postdot_ary
>=current_set->t_postdot_sym_count){
return no_more_postdot_symbols;
}
pim= *pim_isy_p;
}
r->t_trace_pim_isy_p= pim_isy_p;
r->t_trace_postdot_item= pim;
return Postdot_ISYID_of_PIM(pim);
}

/*:661*//*662:*/
#line 7031 "./marpa.w"

Marpa_AHFA_State_ID _marpa_r_postdot_item_symbol(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7034 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7036 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7037 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_ISYID_of_PIM(postdot_item);
}


/*:662*//*678:*/
#line 7172 "./marpa.w"
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
const SRCL source_link= SRCL_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_TOKEN;
Predecessor_of_SRCL(source_link)= predecessor;
TOK_of_SRCL(source_link)= token;
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= my_obstack_alloc(r->t_obs,sizeof(*new_link));
new_link->t_next= LV_First_Token_SRCL_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
TOK_of_Source(new_link->t_source)= token;
LV_First_Token_SRCL_of_EIM(item)= new_link;
}

/*:678*//*683:*/
#line 7250 "./marpa.w"

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
const SRCL source_link= SRCL_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_COMPLETION;
Predecessor_of_SRCL(source_link)= predecessor;
Cause_of_SRCL(source_link)= cause;
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= my_obstack_alloc(r->t_obs,sizeof(*new_link));
new_link->t_next= LV_First_Completion_SRCL_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Completion_SRCL_of_EIM(item)= new_link;
}

/*:683*//*684:*/
#line 7280 "./marpa.w"

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
const SRCL source_link= SRCL_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_LEO;
Predecessor_of_SRCL(source_link)= predecessor;
Cause_of_SRCL(source_link)= cause;
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= my_obstack_alloc(r->t_obs,sizeof(*new_link));
new_link->t_next= LV_First_Leo_SRCL_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
}

/*:684*//*686:*/
#line 7329 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*687:*/
#line 7346 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(r->t_obs,sizeof(*new_link));
*new_link= *SRCL_of_EIM(item);
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_SRCL_of_EIM(item)= NULL;
LV_First_Token_SRCL_of_EIM(item)= new_link;
}

/*:687*/
#line 7337 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*688:*/
#line 7354 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(r->t_obs,sizeof(*new_link));
*new_link= *SRCL_of_EIM(item);
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_SRCL_of_EIM(item)= new_link;
LV_First_Token_SRCL_of_EIM(item)= NULL;
}

/*:688*/
#line 7339 "./marpa.w"

return;
case SOURCE_IS_LEO:/*689:*/
#line 7362 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(r->t_obs,sizeof(*new_link));
*new_link= *SRCL_of_EIM(item);
LV_First_Leo_SRCL_of_EIM(item)= new_link;
LV_First_Completion_SRCL_of_EIM(item)= NULL;
LV_First_Token_SRCL_of_EIM(item)= NULL;
}

/*:689*/
#line 7341 "./marpa.w"

return;
}
}

/*:686*//*694:*/
#line 7391 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_token_link_trace(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7394 "./marpa.w"

SRCL source_link;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7398 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7399 "./marpa.w"

/*708:*/
#line 7586 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:708*/
#line 7400 "./marpa.w"

source_type= Source_Type_of_EIM(item);
switch(source_type)
{
case SOURCE_IS_TOKEN:
r->t_trace_source_type= SOURCE_IS_TOKEN;
source_link= SRCL_of_EIM(item);
r->t_trace_source_link= source_link;
return ISYID_of_SRCL(source_link);
case SOURCE_IS_AMBIGUOUS:
{
source_link= LV_First_Token_SRCL_of_EIM(item);
if(source_link)
{
r->t_trace_source_type= SOURCE_IS_TOKEN;
r->t_trace_source_link= source_link;
return ISYID_of_SRCL(source_link);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:694*//*697:*/
#line 7432 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_token_link_trace(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7435 "./marpa.w"

SRCL source_link;
EIM item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7438 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7439 "./marpa.w"

/*708:*/
#line 7586 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:708*/
#line 7440 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_TOKEN){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NOT_TRACING_TOKEN_LINKS);
return failure_indicator;
}
source_link= Next_SRCL_of_SRCL(r->t_trace_source_link);
if(!source_link){
trace_source_link_clear(r);
return-1;
}
r->t_trace_source_link= source_link;
return ISYID_of_SRCL(source_link);
}

/*:697*//*699:*/
#line 7462 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_completion_link_trace(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7465 "./marpa.w"

SRCL source_link;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7469 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7470 "./marpa.w"

/*708:*/
#line 7586 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:708*/
#line 7471 "./marpa.w"

switch((source_type= Source_Type_of_EIM(item)))
{
case SOURCE_IS_COMPLETION:
r->t_trace_source_type= SOURCE_IS_COMPLETION;
source_link= SRCL_of_EIM(item);
r->t_trace_source_link= source_link;
return Cause_AHFAID_of_SRCL(source_link);
case SOURCE_IS_AMBIGUOUS:
{
source_link= LV_First_Completion_SRCL_of_EIM(item);
if(source_link)
{
r->t_trace_source_type= SOURCE_IS_COMPLETION;
r->t_trace_source_link= source_link;
return Cause_AHFAID_of_SRCL(source_link);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:699*//*702:*/
#line 7502 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_completion_link_trace(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7505 "./marpa.w"

SRCL source_link;
EIM item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7508 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7509 "./marpa.w"

/*708:*/
#line 7586 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:708*/
#line 7510 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_COMPLETION){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NOT_TRACING_COMPLETION_LINKS);
return failure_indicator;
}
source_link= Next_SRCL_of_SRCL(r->t_trace_source_link);
if(!source_link){
trace_source_link_clear(r);
return-1;
}
r->t_trace_source_link= source_link;
return Cause_AHFAID_of_SRCL(source_link);
}

/*:702*//*704:*/
#line 7532 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_leo_link_trace(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7536 "./marpa.w"

SRCL source_link;
EIM item= r->t_trace_earley_item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7539 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7540 "./marpa.w"

/*708:*/
#line 7586 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:708*/
#line 7541 "./marpa.w"

source_link= First_Leo_SRCL_of_EIM(item);
if(source_link){
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_source_link= source_link;
return Cause_AHFAID_of_SRCL(source_link);
}
trace_source_link_clear(r);
return-1;
}

/*:704*//*707:*/
#line 7560 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_leo_link_trace(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7564 "./marpa.w"

SRCL source_link;
EIM item;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7567 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7568 "./marpa.w"

/*708:*/
#line 7586 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:708*/
#line 7569 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_LEO)
{
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NOT_TRACING_LEO_LINKS);
return failure_indicator;
}
source_link= Next_SRCL_of_SRCL(r->t_trace_source_link);
if(!source_link)
{
trace_source_link_clear(r);
return-1;
}
r->t_trace_source_link= source_link;
return Cause_AHFAID_of_SRCL(source_link);
}

/*:707*//*709:*/
#line 7595 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:709*//*710:*/
#line 7610 "./marpa.w"

AHFAID _marpa_r_source_predecessor_state(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7613 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7616 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7617 "./marpa.w"

source_type= r->t_trace_source_type;
/*717:*/
#line 7761 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:717*/
#line 7619 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:{
EIM predecessor= Predecessor_of_SRCL(source_link);
if(!predecessor)return-1;
return AHFAID_of_EIM(predecessor);
}
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:710*//*711:*/
#line 7651 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_token(Marpa_Recognizer r,int*value_p)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7654 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7657 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7658 "./marpa.w"

source_type= r->t_trace_source_type;
/*717:*/
#line 7761 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:717*/
#line 7660 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRCL(source_link);
if(value_p)*value_p= Value_of_TOK(token);
return ISYID_of_TOK(token);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:711*//*713:*/
#line 7683 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_leo_transition_symbol(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7686 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7689 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7690 "./marpa.w"

source_type= r->t_trace_source_type;
/*717:*/
#line 7761 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:717*/
#line 7692 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_ISYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:713*//*716:*/
#line 7729 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_source_middle(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7732 "./marpa.w"

const EARLEME no_predecessor= -1;
unsigned int source_type;
SRCL source_link;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7736 "./marpa.w"

/*1230:*/
#line 14095 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 14096 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 14097 "./marpa.w"


/*:1230*/
#line 7737 "./marpa.w"

source_type= r->t_trace_source_type;
/*717:*/
#line 7761 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:717*/
#line 7739 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
{
LIM predecessor= LIM_of_SRCL(source_link);
if(!predecessor)return no_predecessor;
return
ES_Ord_of_EIM(Base_EIM_of_LIM(predecessor));
}
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:
{
EIM predecessor= Predecessor_of_SRCL(source_link);
if(!predecessor)return no_predecessor;
return ES_Ord_of_EIM(predecessor);
}
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:716*//*732:*/
#line 7873 "./marpa.w"

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

/*:732*//*734:*/
#line 7917 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= ISYID_of_ALT(a)-ISYID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:734*//*735:*/
#line 7934 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:735*//*736:*/
#line 7949 "./marpa.w"

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

/*:736*//*737:*/
#line 7968 "./marpa.w"
int marpa_r_start_input(Marpa_Recognizer r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 7974 "./marpa.w"

/*738:*/
#line 8008 "./marpa.w"

const ISYID isy_count= ISY_Count_of_G(g);
const ISYID xsy_count= XSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(isy_count);
/*:738*/
#line 7975 "./marpa.w"

/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 7976 "./marpa.w"

/*1227:*/
#line 14079 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1227*/
#line 7977 "./marpa.w"

Current_Earleme_of_R(r)= 0;
/*744:*/
#line 8050 "./marpa.w"

{
XSYID xsyid;
r->t_valued_terminal= lbv_obs_new0(r->t_obs,xsy_count);
r->t_unvalued_terminal= lbv_obs_new0(r->t_obs,xsy_count);
r->t_valued= lbv_obs_new0(r->t_obs,xsy_count);
r->t_unvalued= lbv_obs_new0(r->t_obs,xsy_count);
r->t_valued_locked= lbv_obs_new0(r->t_obs,xsy_count);
for(xsyid= 0;xsyid<xsy_count;xsyid++)
{
const XSY xsy= XSY_by_ID(xsyid);
if(XSY_is_Valued_Locked(xsy))
{
lbv_bit_set(r->t_valued_locked,xsyid);
}
if(XSY_is_Valued(xsy))
{
lbv_bit_set(r->t_valued,xsyid);
if(XSY_is_Terminal(xsy))
{
lbv_bit_set(r->t_valued_terminal,xsyid);
}
}
else
{
lbv_bit_set(r->t_unvalued,xsyid);
if(XSY_is_Terminal(xsy))
{
lbv_bit_set(r->t_unvalued_terminal,xsyid);
}
}
}
}

/*:744*/
#line 7979 "./marpa.w"

if(G_is_Trivial(g)){
/*579:*/
#line 6112 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:579*/
#line 7981 "./marpa.w"

return 1;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
psar_reset(Dot_PSAR_of_R(r));
/*561:*/
#line 5975 "./marpa.w"

r->t_bv_isyid_is_expected= bv_obs_create(r->t_obs,(unsigned int)isy_count);
/*:561*//*787:*/
#line 8589 "./marpa.w"

r->t_bv_lim_symbols= bv_obs_create(r->t_obs,isy_count);
r->t_bv_pim_symbols= bv_obs_create(r->t_obs,isy_count);
r->t_pim_workarea= my_obstack_new(r->t_obs,void*,isy_count);
/*:787*//*809:*/
#line 8869 "./marpa.w"

r->t_lim_chain= my_obstack_new(r->t_obs,void*,2*isy_count);
/*:809*/
#line 7986 "./marpa.w"

/*756:*/
#line 8266 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT2(r->t_eim_work_stack,EIM);
/*:756*//*760:*/
#line 8277 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT2(r->t_completion_stack,EIM);
/*:760*/
#line 7987 "./marpa.w"

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
postdot_items_create(r,bv_ok_for_chain,set0);
earley_set_update_items(r,set0);
r->t_is_using_leo= r->t_use_leo_flag;
/*739:*/
#line 8012 "./marpa.w"

bv_free(bv_ok_for_chain);

/*:739*/
#line 8004 "./marpa.w"

return 1;
}

/*:737*//*748:*/
#line 8112 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID token_xsyid,
int value,
int length)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 8119 "./marpa.w"

/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 8120 "./marpa.w"

const int duplicate_token_indicator= -3;
const int unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
ISYID token_isyid;
/*1229:*/
#line 14089 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1229*/
#line 8127 "./marpa.w"

/*749:*/
#line 8135 "./marpa.w"
{
const XSY_Const token= SYM_by_ID(token_xsyid);
if(length<=0){
MARPA_ERROR(MARPA_ERR_TOKEN_LENGTH_LE_ZERO);
return failure_indicator;
}
if(length>=EARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_TOKEN_TOO_LONG);
return failure_indicator;
}
if(value&&UNLIKELY(!lbv_bit_test(r->t_valued_terminal,token_xsyid)))
{
if(!XSY_is_Terminal(token)){
MARPA_ERROR(MARPA_ERR_TOKEN_IS_NOT_TERMINAL);
return failure_indicator;
}
if(lbv_bit_test(r->t_valued_locked,token_xsyid)){
MARPA_ERROR(MARPA_ERR_SYMBOL_VALUED_CONFLICT);
return failure_indicator;
}
lbv_bit_set(r->t_valued_locked,token_xsyid);
lbv_bit_set(r->t_valued_terminal,token_xsyid);
lbv_bit_set(r->t_valued,token_xsyid);
}
if(!value&&UNLIKELY(!lbv_bit_test(r->t_unvalued_terminal,token_xsyid)))
{
if(!XSY_is_Terminal(token)){
MARPA_ERROR(MARPA_ERR_TOKEN_IS_NOT_TERMINAL);
return failure_indicator;
}
if(lbv_bit_test(r->t_valued_locked,token_xsyid)){
MARPA_ERROR(MARPA_ERR_SYMBOL_VALUED_CONFLICT);
return failure_indicator;
}
lbv_bit_set(r->t_valued_locked,token_xsyid);
lbv_bit_set(r->t_unvalued_terminal,token_xsyid);
lbv_bit_set(r->t_unvalued,token_xsyid);
}
}

/*:749*/
#line 8128 "./marpa.w"

/*752:*/
#line 8195 "./marpa.w"
{
ISY token_isy= ISY_by_XSYID(token_xsyid);
if(UNLIKELY(!token_isy)){
return unexpected_token_indicator;
}
token_isyid= ID_of_ISY(token_isy);
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_ISYID(current_earley_set,token_isyid))
return unexpected_token_indicator;
}

/*:752*/
#line 8129 "./marpa.w"

/*750:*/
#line 8175 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return failure_indicator;
}
}

/*:750*/
#line 8130 "./marpa.w"

/*753:*/
#line 8223 "./marpa.w"

{
TOK token;
ALT_Object alternative;
struct obstack*const token_obstack= TOK_Obs_of_I(input);
if(value)
{
my_obstack_blank(TOK_Obs_of_I(input),sizeof(*token));
token= my_obstack_base(token_obstack);
ISYID_of_TOK(token)= token_isyid;
Type_of_TOK(token)= VALUED_TOKEN_OR_NODE;
Value_of_TOK(token)= value;
}
else
{
my_obstack_blank(TOK_Obs_of_I(input),sizeof(token->t_unvalued));
token= my_obstack_base(token_obstack);
ISYID_of_TOK(token)= token_isyid;
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

/*:753*/
#line 8131 "./marpa.w"

return current_earleme;
}

/*:748*//*766:*/
#line 8307 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(Marpa_Recognizer r)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 8311 "./marpa.w"

/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 8312 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
int count_of_expected_terminals;
/*767:*/
#line 8347 "./marpa.w"

const ISYID isy_count= ISY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(isy_count);
/*:767*/
#line 8317 "./marpa.w"

/*1229:*/
#line 14089 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1229*/
#line 8318 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_isyid_is_expected);
/*769:*/
#line 8353 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*579:*/
#line 6112 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:579*/
#line 8357 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:769*/
#line 8322 "./marpa.w"

/*771:*/
#line 8378 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:771*/
#line 8323 "./marpa.w"

/*770:*/
#line 8365 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:770*/
#line 8324 "./marpa.w"

/*772:*/
#line 8384 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*773:*/
#line 8391 "./marpa.w"

{
ES start_earley_set= Start_ES_of_ALT(alternative);
TOK token= TOK_of_ALT(alternative);
ISYID token_isyid= ISYID_of_TOK(token);
PIM pim= First_PIM_of_ES_by_ISYID(start_earley_set,token_isyid);
for(;pim;pim= Next_PIM_of_PIM(pim)){
AHFA scanned_AHFA,prediction_AHFA;
EIM scanned_earley_item;
EIM predecessor= EIM_of_PIM(pim);
if(!predecessor)
continue;
scanned_AHFA= To_AHFA_of_EIM_by_ISYID(predecessor,token_isyid);
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

/*:773*/
#line 8388 "./marpa.w"

}

/*:772*/
#line 8325 "./marpa.w"

/*774:*/
#line 8418 "./marpa.w"
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

/*:774*/
#line 8326 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*775:*/
#line 8437 "./marpa.w"

{
ISYID*complete_isyids= Complete_ISYIDs_of_EIM(cause);
int count= Complete_ISY_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
int isy_ix;
for(isy_ix= 0;isy_ix<count;isy_ix++)
{
ISYID complete_isyid= complete_isyids[isy_ix];
/*776:*/
#line 8450 "./marpa.w"

{
PIM postdot_item;
for(postdot_item= First_PIM_of_ES_by_ISYID(middle,complete_isyid);
postdot_item;postdot_item= Next_PIM_of_PIM(postdot_item))
{
EIM predecessor= EIM_of_PIM(postdot_item);
EIM effect;
AHFA effect_AHFA_state;
if(predecessor)
{
/*777:*/
#line 8473 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_ISYID(predecessor,complete_isyid);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*778:*/
#line 8489 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:778*/
#line 8482 "./marpa.w"

}
/*779:*/
#line 8496 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:779*/
#line 8484 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:777*/
#line 8461 "./marpa.w"

}
else
{
/*780:*/
#line 8506 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*778:*/
#line 8489 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:778*/
#line 8515 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:780*/
#line 8465 "./marpa.w"

break;


}
}
}

/*:776*/
#line 8446 "./marpa.w"

}
}

/*:775*/
#line 8329 "./marpa.w"

}
postdot_items_create(r,bv_ok_for_chain,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_isyid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


/*579:*/
#line 6112 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:579*/
#line 8339 "./marpa.w"

event_new(g,MARPA_EVENT_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
/*768:*/
#line 8350 "./marpa.w"

bv_free(bv_ok_for_chain);

/*:768*/
#line 8343 "./marpa.w"

return G_EVENT_COUNT(g);
}

/*:766*//*781:*/
#line 8520 "./marpa.w"

PRIVATE void earley_set_update_items(RECCE r,ES set)
{
EIM*working_earley_items;
EIM*finished_earley_items;
int working_earley_item_count;
int i;
EIMs_of_ES(set)= my_obstack_new(r->t_obs,EIM,EIM_Count_of_ES(set));
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

/*:781*//*782:*/
#line 8541 "./marpa.w"

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

/*:782*//*789:*/
#line 8596 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,
Bit_Vector bv_ok_for_chain,
ES current_earley_set)
{
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 8602 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
/*788:*/
#line 8593 "./marpa.w"

bv_clear(r->t_bv_lim_symbols);
bv_clear(r->t_bv_pim_symbols);
/*:788*/
#line 8604 "./marpa.w"

/*790:*/
#line 8616 "./marpa.w"
{
EIM*work_earley_items= DSTACK_BASE(r->t_eim_work_stack,EIM);
int no_of_work_earley_items= DSTACK_LENGTH(r->t_eim_work_stack);
int ix;
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
EIM earley_item= work_earley_items[ix];
AHFA state= AHFA_of_EIM(earley_item);
int isy_ix;
ISYID postdot_isy_count= Postdot_ISY_Count_of_AHFA(state);
ISYID*postdot_isyidary= 
Postdot_ISYIDAry_of_AHFA(state);
for(isy_ix= 0;isy_ix<postdot_isy_count;isy_ix++)
{
PIM old_pim= NULL;
PIM new_pim;
ISYID isyid;
new_pim= my_obstack_alloc(r->t_obs,sizeof(EIX_Object));
isyid= postdot_isyidary[isy_ix];
Postdot_ISYID_of_PIM(new_pim)= isyid;
EIM_of_PIM(new_pim)= earley_item;
if(bv_bit_test(r->t_bv_pim_symbols,(unsigned int)isyid))
old_pim= r->t_pim_workarea[isyid];
Next_PIM_of_PIM(new_pim)= old_pim;
if(!old_pim)current_earley_set->t_postdot_sym_count++;
r->t_pim_workarea[isyid]= new_pim;
bv_bit_set(r->t_bv_pim_symbols,(unsigned int)isyid);
}
}
}

/*:790*/
#line 8605 "./marpa.w"

if(r->t_is_using_leo){
/*794:*/
#line 8674 "./marpa.w"

{
unsigned int min,max,start;
for(start= 0;bv_scan(r->t_bv_pim_symbols,start,&min,&max);
start= max+2)
{
ISYID isyid;
for(isyid= (ISYID)min;isyid<=(ISYID)max;isyid++)
{
PIM this_pim= r->t_pim_workarea[isyid];
if(!Next_PIM_of_PIM(this_pim))
{

EIM leo_base= EIM_of_PIM(this_pim);
if(EIM_is_Potential_Leo_Base(leo_base))
{
AHFA base_to_ahfa= 
To_AHFA_of_EIM_by_ISYID(leo_base,isyid);
if(AHFA_is_Leo_Completion(base_to_ahfa))
{
/*795:*/
#line 8708 "./marpa.w"
{
LIM new_lim;
new_lim= my_obstack_alloc(r->t_obs,sizeof(*new_lim));
Postdot_ISYID_of_LIM(new_lim)= isyid;
EIM_of_PIM(new_lim)= NULL;
Predecessor_LIM_of_LIM(new_lim)= NULL;
Origin_of_LIM(new_lim)= NULL;
Chain_Length_of_LIM(new_lim)= -1;
Top_AHFA_of_LIM(new_lim)= base_to_ahfa;
Base_EIM_of_LIM(new_lim)= leo_base;
ES_of_LIM(new_lim)= current_earley_set;
Next_PIM_of_LIM(new_lim)= this_pim;
r->t_pim_workarea[isyid]= new_lim;
bv_bit_set(r->t_bv_lim_symbols,(unsigned int)isyid);
}

/*:795*/
#line 8694 "./marpa.w"

}
}
}
}
}
}

/*:794*/
#line 8607 "./marpa.w"

/*804:*/
#line 8793 "./marpa.w"
{
unsigned int min,max,start;

bv_copy(bv_ok_for_chain,r->t_bv_lim_symbols);
for(start= 0;bv_scan(r->t_bv_lim_symbols,start,&min,&max);
start= max+2)
{

ISYID main_loop_isyid;
for(main_loop_isyid= (ISYID)min;
main_loop_isyid<=(ISYID)max;
main_loop_isyid++)
{
LIM predecessor_lim;
LIM lim_to_process= r->t_pim_workarea[main_loop_isyid];
if(LIM_is_Populated(lim_to_process))continue;

/*807:*/
#line 8851 "./marpa.w"
{
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
const ES predecessor_set= Origin_of_EIM(base_eim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const ISYID predecessor_transition_isyid= 
Leo_LHS_ISYID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Earleme_of_ES(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_ES_by_ISYID(predecessor_set,predecessor_transition_isyid);
}else{
predecessor_pim= r->t_pim_workarea[predecessor_transition_isyid];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:807*/
#line 8810 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*815:*/
#line 8952 "./marpa.w"

{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:815*/
#line 8812 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*817:*/
#line 8974 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:817*/
#line 8818 "./marpa.w"

continue;
}
/*810:*/
#line 8871 "./marpa.w"
{
int lim_chain_ix;
/*813:*/
#line 8891 "./marpa.w"

{
ISYID postdot_isyid_of_lim_to_process
= Postdot_ISYID_of_LIM(lim_to_process);
lim_chain_ix= 0;
r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);
bv_bit_clear(bv_ok_for_chain,
(unsigned int)postdot_isyid_of_lim_to_process);


while(1)
{
lim_to_process= predecessor_lim;





postdot_isyid_of_lim_to_process= Postdot_ISYID_of_LIM(lim_to_process);
if(!bv_bit_test
(bv_ok_for_chain,(unsigned int)postdot_isyid_of_lim_to_process))
{





break;
}

/*807:*/
#line 8851 "./marpa.w"
{
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
const ES predecessor_set= Origin_of_EIM(base_eim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const ISYID predecessor_transition_isyid= 
Leo_LHS_ISYID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Earleme_of_ES(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_ES_by_ISYID(predecessor_set,predecessor_transition_isyid);
}else{
predecessor_pim= r->t_pim_workarea[predecessor_transition_isyid];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:807*/
#line 8921 "./marpa.w"


r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,
(unsigned int)postdot_isyid_of_lim_to_process);


if(!predecessor_lim)
break;

if(LIM_is_Populated(predecessor_lim))
break;



}
}

/*:813*/
#line 8873 "./marpa.w"

/*814:*/
#line 8941 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= r->t_lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*815:*/
#line 8952 "./marpa.w"

{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:815*/
#line 8945 "./marpa.w"

}else{
/*817:*/
#line 8974 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:817*/
#line 8947 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:814*/
#line 8874 "./marpa.w"

}

/*:810*/
#line 8821 "./marpa.w"

}
}
}

/*:804*/
#line 8608 "./marpa.w"

}
/*818:*/
#line 8980 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= my_obstack_alloc(r->t_obs,
current_earley_set->t_postdot_sym_count*sizeof(PIM));
unsigned int min,max,start;
int postdot_array_ix= 0;
for(start= 0;bv_scan(r->t_bv_pim_symbols,start,&min,&max);start= max+2){
ISYID isyid;
for(isyid= (ISYID)min;isyid<=(ISYID)max;isyid++){
PIM this_pim= r->t_pim_workarea[isyid];
if(this_pim)postdot_array[postdot_array_ix++]= this_pim;
}
}
}

/*:818*/
#line 8610 "./marpa.w"

bv_and(r->t_bv_isyid_is_expected,r->t_bv_pim_symbols,g->t_bv_isyid_is_terminal);
}

/*:789*//*836:*/
#line 9147 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
stack->t_obs= my_obstack_init;
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:836*//*837:*/
#line 9155 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:837*//*838:*/
#line 9161 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)my_obstack_free(stack->t_obs);
stack->t_base= NULL;
}

/*:838*//*839:*/
#line 9168 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= my_obstack_alloc(stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:839*//*840:*/
#line 9178 "./marpa.w"

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

/*:840*//*841:*/
#line 9194 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:841*//*845:*/
#line 9257 "./marpa.w"

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

/*:845*//*881:*/
#line 9825 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const ISYID postdot_isyid= Postdot_ISYID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_ISYID(base,postdot_isyid);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:881*//*882:*/
#line 9837 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:882*//*888:*/
#line 9952 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= my_obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:888*//*890:*/
#line 9975 "./marpa.w"

PRIVATE
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:890*//*917:*/
#line 10393 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 10396 "./marpa.w"

/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 10397 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 10398 "./marpa.w"

return AND_Count_of_B(b);
}

/*:917*//*919:*/
#line 10424 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 10429 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 10430 "./marpa.w"

/*918:*/
#line 10402 "./marpa.w"

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

/*:918*/
#line 10431 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:919*//*920:*/
#line 10435 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 10440 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 10441 "./marpa.w"

/*918:*/
#line 10402 "./marpa.w"

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

/*:918*/
#line 10442 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:920*//*921:*/
#line 10451 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 10456 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 10457 "./marpa.w"

/*918:*/
#line 10402 "./marpa.w"

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

/*:918*/
#line 10458 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:921*//*922:*/
#line 10467 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 10472 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 10473 "./marpa.w"

/*918:*/
#line 10402 "./marpa.w"

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

/*:918*/
#line 10474 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?ISYID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:922*//*923:*/
#line 10483 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK token;
AND and_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 10489 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 10490 "./marpa.w"

/*918:*/
#line 10402 "./marpa.w"

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

/*:918*/
#line 10491 "./marpa.w"

token= and_node_token(and_node);
if(token){
if(value_p)
*value_p= Value_of_TOK(token);
return ISYID_of_TOK(token);
}
return-1;
}
/*:923*//*924:*/
#line 10500 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:924*//*933:*/
#line 10546 "./marpa.w"

PRIVATE_NOT_INLINE int report_item_cmp(
const void*ap,
const void*bp,
void*param UNUSED)
{
const struct marpa_progress_item*const report_a= ap;
const struct marpa_progress_item*const report_b= bp;
if(Position_of_PROGRESS(report_a)> Position_of_PROGRESS(report_b))return 1;
if(Position_of_PROGRESS(report_a)<Position_of_PROGRESS(report_b))return-1;
if(RULEID_of_PROGRESS(report_a)> RULEID_of_PROGRESS(report_b))return 1;
if(RULEID_of_PROGRESS(report_a)<RULEID_of_PROGRESS(report_b))return-1;
if(Origin_of_PROGRESS(report_a)> Origin_of_PROGRESS(report_b))return 1;
if(Origin_of_PROGRESS(report_a)<Origin_of_PROGRESS(report_b))return-1;
return 0;
}

/*:933*//*934:*/
#line 10563 "./marpa.w"

int marpa_r_progress_report_start(
Marpa_Recognizer r,
Marpa_Earley_Set_ID set_id)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 10568 "./marpa.w"

const int es_does_not_exist= -1;
ES earley_set;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 10571 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 10572 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 10573 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
return es_does_not_exist;
}
earley_set= ES_of_R_by_Ord(r,set_id);
/*928:*/
#line 10520 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(TREE_of_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:928*/
#line 10585 "./marpa.w"

{
const AVL_TREE report_tree= 
_marpa_avl_create(report_item_cmp,NULL,alignof(PROGRESS));
const EIM*const earley_items= EIMs_of_ES(earley_set);
const int earley_item_count= EIM_Count_of_ES(earley_set);
int earley_item_id;
for(earley_item_id= 0;earley_item_id<earley_item_count;
earley_item_id++)
{
/*935:*/
#line 10602 "./marpa.w"

{
const int initial_phase= 1;
const int leo_source_link_phase= 2;
const int leo_path_item_phase= 3;
int next_phase= initial_phase;
SRCL leo_source_link= NULL;
LIM next_leo_item= NULL;
const EIM earley_item= earley_items[earley_item_id];
while(1)
{
ESID report_origin;
AHFA report_AHFA_state;
while(1)
{
const int phase= next_phase;
if(phase==initial_phase)
{
report_origin= Origin_Ord_of_EIM(earley_item);
report_AHFA_state= AHFA_of_EIM(earley_item);
next_phase= leo_source_link_phase;
goto INSERT_ITEMS_INTO_TREE;
}
if(phase==leo_source_link_phase)
{
leo_source_link= leo_source_link?
Next_SRCL_of_SRCL(leo_source_link):
First_Leo_SRCL_of_EIM(earley_item);
if(leo_source_link)
{
next_leo_item= LIM_of_SRCL(leo_source_link);
next_phase= leo_path_item_phase;
goto NEXT_PHASE;
}
goto NEXT_EARLEY_ITEM;


}
if(phase==leo_path_item_phase)
{
const LIM leo_item= next_leo_item;
if(!leo_item)
{
next_phase= leo_source_link_phase;
goto NEXT_PHASE;
}
{
const EIM base_earley_item= Base_EIM_of_LIM(leo_item);
const ISYID postdot_isyid= Postdot_ISYID_of_LIM(leo_item);
report_origin= Ord_of_ES(ES_of_LIM(leo_item));
report_AHFA_state= 
To_AHFA_of_EIM_by_ISYID(base_earley_item,postdot_isyid);
next_leo_item= Predecessor_LIM_of_LIM(leo_item);
goto INSERT_ITEMS_INTO_TREE;
}
}
NEXT_PHASE:;
}
INSERT_ITEMS_INTO_TREE:
/*936:*/
#line 10666 "./marpa.w"

{
AEX aex;
const int aim_count= report_AHFA_state->t_item_count;
for(aex= 0;aex<aim_count;aex++)
{
const AIM report_aim= AIM_of_AHFA_by_AEX(report_AHFA_state,aex);
const IRL irl= IRL_of_AIM(report_aim);
const XRL source_xrl= Source_XRL_of_IRL(irl);
if(source_xrl)
{
const int irl_position= Position_of_AIM(report_aim);
int xrl_position= irl_position;
const int virtual_start= Virtual_Start_of_IRL(irl);
if(virtual_start>=0)
{
xrl_position+= virtual_start;
}
if(XRL_is_Sequence(source_xrl))
{
if(IRL_has_Virtual_LHS(irl))
{
if(irl_position<=0)goto NEXT_AIM;
xrl_position= -1;
}
else
{
xrl_position= irl_position> 0?-1:0;
}
}
{
const PROGRESS new_report_item= 
my_obstack_new(AVL_OBSTACK(report_tree),struct marpa_progress_item,
1);
Position_of_PROGRESS(new_report_item)= xrl_position;
Origin_of_PROGRESS(new_report_item)= report_origin;
RULEID_of_PROGRESS(new_report_item)= ID_of_XRL(source_xrl);
_marpa_avl_insert(report_tree,new_report_item);
}
}
NEXT_AIM:;
}
}

/*:936*/
#line 10661 "./marpa.w"

}
NEXT_EARLEY_ITEM:;
}

/*:935*/
#line 10595 "./marpa.w"

}
r->t_progress_report_traverser= _marpa_avl_t_init(report_tree);
return marpa_avl_count(report_tree);
}
}

/*:934*//*937:*/
#line 10710 "./marpa.w"

int marpa_r_progress_report_finish(Marpa_Recognizer r){
const int success= 1;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 10713 "./marpa.w"

/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 10714 "./marpa.w"

const AVL_TRAV traverser= r->t_progress_report_traverser;
/*939:*/
#line 10747 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:939*/
#line 10716 "./marpa.w"

/*928:*/
#line 10520 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(TREE_of_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:928*/
#line 10717 "./marpa.w"

return success;
}

/*:937*//*938:*/
#line 10721 "./marpa.w"

Marpa_Rule_ID marpa_r_progress_item(
Marpa_Recognizer r,int*position,Marpa_Earley_Set_ID*origin
){
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 10725 "./marpa.w"

const RULEID no_more_items= -1;
PROGRESS report_item;
AVL_TRAV traverser;
/*543:*/
#line 5884 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:543*/
#line 10729 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 10730 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 10731 "./marpa.w"

traverser= r->t_progress_report_traverser;
if(UNLIKELY(!position||!origin)){
MARPA_ERROR(MARPA_ERR_POINTER_ARG_NULL);
return failure_indicator;
}
/*939:*/
#line 10747 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:939*/
#line 10737 "./marpa.w"

report_item= _marpa_avl_t_next(traverser);
if(!report_item){
return no_more_items;
}
*position= Position_of_PROGRESS(report_item);
*origin= Origin_of_PROGRESS(report_item);
return RULEID_of_PROGRESS(report_item);
}

/*:938*//*949:*/
#line 10790 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1217:*/
#line 14026 "./marpa.w"
void*const failure_indicator= NULL;
/*:1217*/
#line 10794 "./marpa.w"

/*952:*/
#line 10852 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int isy_count= ISY_Count_of_G(g);
const int xsy_count= XSY_Count_of_G(g);
const IRLID irl_count= IRL_Count_of_G(g);
BOCAGE b= NULL;
ES end_of_parse_earley_set;
EARLEME end_of_parse_earleme;
EIM start_eim= NULL;
AIM start_aim= NULL;
AEX start_aex= -1;
struct obstack*bocage_setup_obs= NULL;
int total_earley_items_in_parse;
int or_node_estimate= 0;
const int earley_set_count_of_r= ES_Count_of_R(r);

/*:952*//*955:*/
#line 10876 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:955*/
#line 10795 "./marpa.w"

INPUT input;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 10797 "./marpa.w"

/*1228:*/
#line 14084 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1228*/
#line 10798 "./marpa.w"

{
struct obstack*const obstack= my_obstack_init;
b= my_obstack_new(obstack,struct marpa_bocage,1);
OBS_of_B(b)= obstack;
}
/*868:*/
#line 9600 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:868*//*951:*/
#line 10847 "./marpa.w"

Valued_BV_of_B(b)= lbv_copy(b->t_obs,r->t_valued,xsy_count);
Valued_Locked_BV_of_B(b)= 
lbv_copy(b->t_obs,r->t_valued_locked,xsy_count);

/*:951*//*968:*/
#line 11025 "./marpa.w"

b->t_ref_count= 1;

/*:968*//*975:*/
#line 11086 "./marpa.w"

B_is_Nulling(b)= 0;

/*:975*/
#line 10804 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*956:*/
#line 10879 "./marpa.w"

{
if(ordinal_arg==-1)
{
end_of_parse_earley_set= Current_ES_of_R(r);
}
else
{
if(!ES_Ord_is_Valid(r,ordinal_arg))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
end_of_parse_earley_set= ES_of_R_by_Ord(r,ordinal_arg);
}

if(!end_of_parse_earley_set)
goto NO_PARSE;
end_of_parse_earleme= Earleme_of_ES(end_of_parse_earley_set);
}

/*:956*/
#line 10814 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(SYM_by_ID(g->t_start_xsyid)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*960:*/
#line 10953 "./marpa.w"

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

/*:960*/
#line 10822 "./marpa.w"

if(!start_eim)goto NO_PARSE;
bocage_setup_obs= my_obstack_init;
/*957:*/
#line 10901 "./marpa.w"

{
unsigned int ix;
unsigned int earley_set_count= ES_Count_of_R(r);
total_earley_items_in_parse= 0;
per_es_data= 
my_obstack_alloc(bocage_setup_obs,
sizeof(struct s_bocage_setup_per_es)*earley_set_count);
for(ix= 0;ix<earley_set_count;ix++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,ix);
const unsigned int item_count= EIM_Count_of_ES(earley_set);
total_earley_items_in_parse+= item_count;
{
struct s_bocage_setup_per_es*per_es= per_es_data+ix;
OR**const per_eim_eixes= per_es->t_aexes_by_item= 
my_obstack_alloc(bocage_setup_obs,sizeof(OR*)*item_count);
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

/*:957*/
#line 10825 "./marpa.w"

/*843:*/
#line 9216 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*844:*/
#line 9244 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:844*/
#line 9225 "./marpa.w"

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
/*846:*/
#line 9285 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
switch(source_type)
{
case SOURCE_IS_TOKEN:
predecessor_earley_item= Predecessor_of_EIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= LV_First_Token_SRCL_of_EIM(parent_earley_item);
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
/*844:*/
#line 9244 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:844*/
#line 9313 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:846*/
#line 9238 "./marpa.w"

/*848:*/
#line 9343 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
EIM cause_earley_item= NULL;
const ISYID transition_symbol_isyid= Postdot_ISYID_of_AIM(predecessor_aim);
switch(source_type)
{
case SOURCE_IS_COMPLETION:
predecessor_earley_item= Predecessor_of_EIM(parent_earley_item);
cause_earley_item= Cause_of_EIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= LV_First_Completion_SRCL_of_EIM(parent_earley_item);
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
/*844:*/
#line 9244 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:844*/
#line 9379 "./marpa.w"

}
}
{
const TRANS cause_completion_data= 
TRANS_of_EIM_by_ISYID(cause_earley_item,transition_symbol_isyid);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
const EIM ur_earley_item= cause_earley_item;
int ix;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*844:*/
#line 9244 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:844*/
#line 9392 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:848*/
#line 9239 "./marpa.w"

/*849:*/
#line 9402 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_EIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
const EIM cause_earley_item= Cause_of_SRCL(source_link);
LIM leo_predecessor= LIM_of_SRCL(source_link);
const ISYID transition_isyid= Postdot_ISYID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_EIM_by_ISYID(cause_earley_item,transition_isyid);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
int ix;
EIM ur_earley_item= cause_earley_item;
for(ix= 0;ix<aex_count;ix++)
{
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*844:*/
#line 9244 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:844*/
#line 9421 "./marpa.w"

}
while(leo_predecessor)
{
ISYID postdot_isyid= Postdot_ISYID_of_LIM(leo_predecessor);
EIM leo_base= Base_EIM_of_LIM(leo_predecessor);
TRANS transition= TRANS_of_EIM_by_ISYID(leo_base,postdot_isyid);
const AEX ur_aex= Leo_Base_AEX_of_TRANS(transition);
const AIM ur_aim= AIM_of_EIM_by_AEX(leo_base,ur_aex);
ur_earley_item= leo_base;


or_node_estimate+= 1+Null_Count_of_AIM(ur_aim+1);
if(EIM_is_Predicted(ur_earley_item))
{
Set_boolean_in_PSIA_for_initial_nulls(ur_earley_item,ur_aim);
}
else
{
/*844:*/
#line 9244 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:844*/
#line 9440 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
}
}

/*:849*/
#line 9240 "./marpa.w"

}
}

/*:843*/
#line 10826 "./marpa.w"

/*870:*/
#line 9618 "./marpa.w"

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
/*1195:*/
#line 13787 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1195*/
#line 9638 "./marpa.w"

/*871:*/
#line 9646 "./marpa.w"

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
/*872:*/
#line 9666 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1195:*/
#line 13787 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1195*/
#line 9676 "./marpa.w"

/*874:*/
#line 9694 "./marpa.w"

{
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const IRL irl= IRL_of_AIM(ahfa_item);
/*875:*/
#line 9723 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)my_obstack_alloc(OBS_of_B(b),sizeof(OR_Object));
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


/*:875*/
#line 9704 "./marpa.w"

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

/*:874*/
#line 9677 "./marpa.w"

/*877:*/
#line 9748 "./marpa.w"

{
const int null_count= Null_Count_of_AIM(ahfa_item);
if(null_count> 0)
{
const IRL irl= IRL_of_AIM(ahfa_item);
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
const OR cause= Nulling_OR_by_ISYID(RHSID_of_IRL(irl,rhs_ix));
/*875:*/
#line 9723 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)my_obstack_alloc(OBS_of_B(b),sizeof(OR_Object));
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


/*:875*/
#line 9767 "./marpa.w"

or_node= PSL_Datum(or_psl,symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= work_origin_ordinal;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= irl;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
draft_and_node= DANDs_of_OR(or_node)= 
draft_and_node_new(bocage_setup_obs,predecessor,
cause);
Next_DAND_of_DAND(draft_and_node)= NULL;
}
psia_or_node= or_node;
}
}
}

/*:877*/
#line 9678 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*878:*/
#line 9785 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_EIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*880:*/
#line 9807 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const IRL path_irl= IRL_of_AIM(path_ahfa_item);
const int symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*883:*/
#line 9848 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1195:*/
#line 13787 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1195*/
#line 9855 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*875:*/
#line 9723 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)my_obstack_alloc(OBS_of_B(b),sizeof(OR_Object));
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


/*:875*/
#line 9859 "./marpa.w"

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

/*:883*/
#line 9817 "./marpa.w"

/*884:*/
#line 9875 "./marpa.w"

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
const OR cause= Nulling_OR_by_ISYID(RHSID_of_IRL(path_irl,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_IRL(path_irl))
MARPA_ASSERT(symbol_instance>=0)
/*875:*/
#line 9723 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)my_obstack_alloc(OBS_of_B(b),sizeof(OR_Object));
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


/*:875*/
#line 9892 "./marpa.w"

PSL_Datum(this_earley_set_psl,symbol_instance)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
DANDs_of_OR(or_node)= draft_and_node= 
draft_and_node_new(bocage_setup_obs,predecessor,cause);
Next_DAND_of_DAND(draft_and_node)= NULL;
}
MARPA_ASSERT(Position_of_OR(or_node)<=
SYMI_of_IRL(path_irl)+Length_of_IRL(path_irl))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_IRL(path_irl))
}
}

/*:884*/
#line 9818 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:880*/
#line 9793 "./marpa.w"

}
}
}

/*:878*/
#line 9686 "./marpa.w"

}

/*:872*/
#line 9660 "./marpa.w"

}
}
}
}

/*:871*/
#line 9639 "./marpa.w"

/*891:*/
#line 9985 "./marpa.w"

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
/*893:*/
#line 10022 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const int work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*894:*/
#line 10038 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_EIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
EIM cause_earley_item= Cause_of_SRCL(source_link);
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*895:*/
#line 10053 "./marpa.w"

{

IRL path_irl= NULL;

IRL previous_path_irl;
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
OR dand_predecessor;
OR path_or_node;
EIM base_earley_item;
AEX base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*896:*/
#line 10080 "./marpa.w"

{
if(higher_path_leo_item){
/*900:*/
#line 10124 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:900*/
#line 10083 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:896*/
#line 10066 "./marpa.w"

/*898:*/
#line 10094 "./marpa.w"

{
const ISYID transition_isyid= Postdot_ISYID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_EIM_by_ISYID(cause_earley_item,transition_isyid);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
int ix;
for(ix= 0;ix<aex_count;ix++)
{
const AEX cause_aex= aexes[ix];
OR dand_cause;
Set_OR_from_EIM_and_AEX(dand_cause,cause_earley_item,cause_aex);
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:898*/
#line 10067 "./marpa.w"

previous_path_irl= path_irl;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*896:*/
#line 10080 "./marpa.w"

{
if(higher_path_leo_item){
/*900:*/
#line 10124 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:900*/
#line 10083 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:896*/
#line 10074 "./marpa.w"

/*901:*/
#line 10134 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_IRL(previous_path_irl);
const int origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:901*/
#line 10075 "./marpa.w"

previous_path_irl= path_irl;
}
}

/*:895*/
#line 10047 "./marpa.w"

}
}
}

/*:894*/
#line 10033 "./marpa.w"

/*902:*/
#line 10144 "./marpa.w"

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
source_link= LV_First_Token_SRCL_of_EIM(work_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
while(token)
{
/*903:*/
#line 10174 "./marpa.w"

{
OR dand_predecessor;
/*904:*/
#line 10182 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:904*/
#line 10177 "./marpa.w"

draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:903*/
#line 10166 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:902*/
#line 10034 "./marpa.w"

/*905:*/
#line 10193 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
EIM cause_earley_item= NULL;
const ISYID transition_symbol_isyid= Postdot_ISYID_of_AIM(work_predecessor_aim);
switch(work_source_type)
{
case SOURCE_IS_COMPLETION:
predecessor_earley_item= Predecessor_of_EIM(work_earley_item);
cause_earley_item= Cause_of_EIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= LV_First_Completion_SRCL_of_EIM(work_earley_item);
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
TRANS_of_EIM_by_ISYID(cause_earley_item,transition_symbol_isyid);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
int ix;
for(ix= 0;ix<aex_count;ix++){
const AEX cause_aex= aexes[ix];
/*906:*/
#line 10233 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_IRL(IRL_of_AIM(cause_ahfa_item));
/*904:*/
#line 10182 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:904*/
#line 10241 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:906*/
#line 10224 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:905*/
#line 10035 "./marpa.w"

}

/*:893*/
#line 10000 "./marpa.w"

}
}
}
}
}

/*:891*/
#line 9640 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= my_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:870*/
#line 10827 "./marpa.w"

/*914:*/
#line 10348 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*907:*/
#line 10247 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
int or_node_id= 0;
psar_init(and_psar,irl_count+isy_count);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*909:*/
#line 10279 "./marpa.w"

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

/*:909*/
#line 10257 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:907*/
#line 10351 "./marpa.w"

/*915:*/
#line 10355 "./marpa.w"

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

/*:915*/
#line 10352 "./marpa.w"

}

/*:914*/
#line 10828 "./marpa.w"

/*961:*/
#line 10982 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:961*/
#line 10829 "./marpa.w"
;
my_obstack_free(bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
input_unref(input);
if(b){
/*971:*/
#line 11062 "./marpa.w"

/*869:*/
#line 9607 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:869*/
#line 11063 "./marpa.w"
;
/*948:*/
#line 10786 "./marpa.w"

my_obstack_free(OBS_of_B(b));

/*:948*/
#line 11064 "./marpa.w"
;

/*:971*/
#line 10836 "./marpa.w"
;
}
return NULL;
}

/*:949*//*963:*/
#line 11005 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11008 "./marpa.w"

return g;
}

/*:963*//*965:*/
#line 11014 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11017 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11018 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11019 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:965*//*969:*/
#line 11029 "./marpa.w"

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

/*:969*//*970:*/
#line 11047 "./marpa.w"

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

/*:970*//*972:*/
#line 11069 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11073 "./marpa.w"

input_unref(input);
if(b)
{
/*971:*/
#line 11062 "./marpa.w"

/*869:*/
#line 9607 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:869*/
#line 11063 "./marpa.w"
;
/*948:*/
#line 10786 "./marpa.w"

my_obstack_free(OBS_of_B(b));

/*:948*/
#line 11064 "./marpa.w"
;

/*:971*/
#line 11077 "./marpa.w"
;
}
}

/*:972*//*978:*/
#line 11120 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11125 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11126 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11127 "./marpa.w"

/*977:*/
#line 11098 "./marpa.w"

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

/*:977*/
#line 11128 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:978*//*979:*/
#line 11132 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11137 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11138 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11139 "./marpa.w"

/*977:*/
#line 11098 "./marpa.w"

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

/*:977*/
#line 11140 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:979*//*980:*/
#line 11144 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11149 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11150 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11151 "./marpa.w"

/*977:*/
#line 11098 "./marpa.w"

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

/*:977*/
#line 11152 "./marpa.w"

return ID_of_IRL(IRL_of_OR(or_node));
}

/*:980*//*981:*/
#line 11156 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11161 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11162 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11163 "./marpa.w"

/*977:*/
#line 11098 "./marpa.w"

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

/*:977*/
#line 11164 "./marpa.w"

return Position_of_OR(or_node);
}

/*:981*//*982:*/
#line 11168 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11173 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11174 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11175 "./marpa.w"

/*977:*/
#line 11098 "./marpa.w"

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

/*:977*/
#line 11176 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:982*//*983:*/
#line 11180 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11185 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11186 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11187 "./marpa.w"

/*977:*/
#line 11098 "./marpa.w"

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

/*:977*/
#line 11188 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:983*//*984:*/
#line 11193 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11198 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11199 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11200 "./marpa.w"

/*977:*/
#line 11098 "./marpa.w"

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

/*:977*/
#line 11201 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:984*//*991:*/
#line 11244 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1217:*/
#line 14026 "./marpa.w"
void*const failure_indicator= NULL;
/*:1217*/
#line 11247 "./marpa.w"

/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11248 "./marpa.w"

ORDER o;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11250 "./marpa.w"

o= my_slice_new(*o);
B_of_O(o)= b;
bocage_ref(b);
/*988:*/
#line 11231 "./marpa.w"

{
o->t_and_node_in_use= NULL;
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
OBS_of_O(o)= NULL;
}

/*:988*//*994:*/
#line 11261 "./marpa.w"

o->t_ref_count= 1;

/*:994*/
#line 11254 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
return o;
}

/*:991*//*995:*/
#line 11265 "./marpa.w"

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

/*:995*//*996:*/
#line 11283 "./marpa.w"

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

/*:996*//*997:*/
#line 11297 "./marpa.w"

PRIVATE void order_strip(ORDER o)
{
if(o->t_and_node_in_use)
{
bv_free(o->t_and_node_in_use);
o->t_and_node_in_use= NULL;
}
}
/*:997*//*998:*/
#line 11306 "./marpa.w"

PRIVATE void order_freeze(ORDER o)
{
order_strip(o);
O_is_Frozen(o)= 0;
}
/*:998*//*999:*/
#line 11312 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11315 "./marpa.w"

bocage_unref(b);
order_strip(o);
if(o->t_and_node_orderings){
o->t_and_node_orderings= NULL;
my_obstack_free(OBS_of_O(o));
}
my_slice_free(*o,o);
}

/*:999*//*1002:*/
#line 11341 "./marpa.w"

Marpa_Grammar marpa_o_g(Marpa_Order o)
{
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11344 "./marpa.w"

return g;
}

/*:1002*//*1008:*/
#line 11403 "./marpa.w"

int _marpa_o_and_order_set(
Marpa_Order o,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
int length)
{
OR or_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11411 "./marpa.w"

/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11412 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11413 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*977:*/
#line 11098 "./marpa.w"

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

/*:977*/
#line 11419 "./marpa.w"

{
ANDID**and_node_orderings;
Bit_Vector and_node_in_use;
struct obstack*obs= OBS_of_O(o);
ANDID first_and_node_id;
ANDID and_count_of_or;
and_node_orderings= o->t_and_node_orderings;
and_node_in_use= o->t_and_node_in_use;
if(!and_node_orderings)
{
int and_id;
const int and_count_of_r= AND_Count_of_B(b);
obs= OBS_of_O(o)= my_obstack_init;
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

/*:1008*//*1009:*/
#line 11482 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,int ix)
{
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11485 "./marpa.w"

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

/*:1009*//*1010:*/
#line 11507 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11512 "./marpa.w"

/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11513 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11514 "./marpa.w"

/*977:*/
#line 11098 "./marpa.w"

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

/*:977*/
#line 11515 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
return and_order_get(o,or_node,ix);
}

/*:1010*//*1015:*/
#line 11567 "./marpa.w"

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

/*:1015*//*1016:*/
#line 11585 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1217:*/
#line 14026 "./marpa.w"
void*const failure_indicator= NULL;
/*:1217*/
#line 11588 "./marpa.w"

TREE t;
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11590 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11591 "./marpa.w"

t= my_slice_new(*t);
O_of_T(t)= o;
order_ref(o);
order_freeze(o);
/*1035:*/
#line 11796 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1035*/
#line 11596 "./marpa.w"

/*1017:*/
#line 11601 "./marpa.w"

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

/*:1017*//*1020:*/
#line 11624 "./marpa.w"

t->t_ref_count= 1;

/*:1020*//*1027:*/
#line 11703 "./marpa.w"
t->t_pause_counter= 0;
/*:1027*/
#line 11597 "./marpa.w"

return t;
}

/*:1016*//*1021:*/
#line 11628 "./marpa.w"

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

/*:1021*//*1022:*/
#line 11646 "./marpa.w"

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

/*:1022*//*1023:*/
#line 11660 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_slice_free(*t,t);
}

/*:1023*//*1028:*/
#line 11704 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1028*//*1029:*/
#line 11713 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1029*//*1031:*/
#line 11735 "./marpa.w"

Marpa_Grammar marpa_t_g(Marpa_Tree t)
{
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 11738 "./marpa.w"

return g;
}

/*:1031*//*1032:*/
#line 11742 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11745 "./marpa.w"

int is_first_tree_attempt= 0;
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 11747 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11748 "./marpa.w"

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
/*1042:*/
#line 11830 "./marpa.w"

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

/*:1042*/
#line 11771 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
}else{
/*1043:*/
#line 11855 "./marpa.w"
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

/*:1043*/
#line 11778 "./marpa.w"

}
/*1044:*/
#line 11907 "./marpa.w"
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
/*1046:*/
#line 11968 "./marpa.w"

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

/*:1046*/
#line 11949 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1044*/
#line 11780 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return-1;

}

/*:1032*//*1039:*/
#line 11810 "./marpa.w"

PRIVATE void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:1039*//*1040:*/
#line 11816 "./marpa.w"

PRIVATE void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:1040*//*1041:*/
#line 11824 "./marpa.w"

PRIVATE int tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}

/*:1041*//*1045:*/
#line 11955 "./marpa.w"

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

/*:1045*//*1047:*/
#line 11986 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1047*//*1048:*/
#line 11994 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 11997 "./marpa.w"

/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 11998 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 11999 "./marpa.w"

if(T_is_Exhausted(t)){
return-1;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1048*//*1055:*/
#line 12058 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12062 "./marpa.w"

/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12063 "./marpa.w"

/*1054:*/
#line 12040 "./marpa.w"
{
NOOK base_nook;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12042 "./marpa.w"

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

/*:1054*/
#line 12064 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1055*//*1056:*/
#line 12068 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12072 "./marpa.w"

/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12073 "./marpa.w"

/*1054:*/
#line 12040 "./marpa.w"
{
NOOK base_nook;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12042 "./marpa.w"

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

/*:1054*/
#line 12074 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1056*//*1057:*/
#line 12078 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12082 "./marpa.w"

/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12083 "./marpa.w"

/*1054:*/
#line 12040 "./marpa.w"
{
NOOK base_nook;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12042 "./marpa.w"

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

/*:1054*/
#line 12084 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1057*//*1058:*/
#line 12088 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12092 "./marpa.w"

/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12093 "./marpa.w"

/*1054:*/
#line 12040 "./marpa.w"
{
NOOK base_nook;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12042 "./marpa.w"

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

/*:1054*/
#line 12094 "./marpa.w"

return NOOK_Cause_is_Ready(nook);
}

/*:1058*//*1059:*/
#line 12098 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12102 "./marpa.w"

/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12103 "./marpa.w"

/*1054:*/
#line 12040 "./marpa.w"
{
NOOK base_nook;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12042 "./marpa.w"

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

/*:1054*/
#line 12104 "./marpa.w"

return NOOK_Predecessor_is_Ready(nook);
}

/*:1059*//*1060:*/
#line 12108 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12112 "./marpa.w"

/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12113 "./marpa.w"

/*1054:*/
#line 12040 "./marpa.w"
{
NOOK base_nook;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12042 "./marpa.w"

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

/*:1054*/
#line 12114 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1060*//*1061:*/
#line 12118 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12122 "./marpa.w"

/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12123 "./marpa.w"

/*1054:*/
#line 12040 "./marpa.w"
{
NOOK base_nook;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12042 "./marpa.w"

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

/*:1054*/
#line 12124 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1061*//*1078:*/
#line 12277 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1217:*/
#line 14026 "./marpa.w"
void*const failure_indicator= NULL;
/*:1217*/
#line 12280 "./marpa.w"

/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12281 "./marpa.w"
;
/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12282 "./marpa.w"

if(!T_is_Exhausted(t))
{
const XSYID xsy_count= XSY_Count_of_G(g);
struct obstack*const obstack= my_obstack_init;
const VALUE v= my_obstack_new(obstack,struct s_value,1);
v->t_obs= obstack;
Next_Value_Type_of_V(v)= V_INITIALIZE;
/*1069:*/
#line 12207 "./marpa.w"

XSYID_of_V(v)= -1;
RULEID_of_V(v)= -1;
Token_Value_of_V(v)= -1;
Token_Type_of_V(v)= DUMMY_OR_NODE;
TOS_of_V(v)= -1;
Arg_N_of_V(v)= -1;

/*:1069*//*1076:*/
#line 12266 "./marpa.w"

DSTACK_SAFE(VStack_of_V(v));
/*:1076*//*1081:*/
#line 12310 "./marpa.w"

v->t_ref_count= 1;

/*:1081*//*1089:*/
#line 12372 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1089*//*1091:*/
#line 12379 "./marpa.w"

V_is_Trace(v)= 0;
/*:1091*//*1094:*/
#line 12400 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1094*//*1099:*/
#line 12427 "./marpa.w"

{
XSY_is_Valued_BV_of_V(v)= lbv_copy(v->t_obs,Valued_BV_of_B(b),xsy_count);
Valued_Locked_BV_of_V(v)= 
lbv_copy(v->t_obs,Valued_Locked_BV_of_B(b),xsy_count);
}

/*:1099*/
#line 12290 "./marpa.w"

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

/*:1078*//*1082:*/
#line 12314 "./marpa.w"

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

/*:1082*//*1083:*/
#line 12332 "./marpa.w"

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

/*:1083*//*1084:*/
#line 12346 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
/*1077:*/
#line 12268 "./marpa.w"

{
if(LIKELY(DSTACK_IS_INITIALIZED(VStack_of_V(v))!=NULL))
{
DSTACK_DESTROY(VStack_of_V(v));
}
}

/*:1077*/
#line 12350 "./marpa.w"

/*1071:*/
#line 12219 "./marpa.w"

my_obstack_free(v->t_obs);

/*:1071*/
#line 12351 "./marpa.w"

}

/*:1084*//*1086:*/
#line 12359 "./marpa.w"

Marpa_Grammar marpa_v_g(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1085:*/
#line 12354 "./marpa.w"

TREE t= T_of_V(v);
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12356 "./marpa.w"


/*:1085*/
#line 12363 "./marpa.w"

return g;
}

/*:1086*//*1092:*/
#line 12381 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12384 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1085:*/
#line 12354 "./marpa.w"

TREE t= T_of_V(v);
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12356 "./marpa.w"


/*:1085*/
#line 12386 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12387 "./marpa.w"

if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1092*//*1095:*/
#line 12403 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12406 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1085:*/
#line 12354 "./marpa.w"

TREE t= T_of_V(v);
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12356 "./marpa.w"


/*:1085*/
#line 12408 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12409 "./marpa.w"

if(UNLIKELY(V_is_Nulling(v)))return-1;
if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1095*//*1100:*/
#line 12436 "./marpa.w"

int marpa_v_symbol_is_valued(
Marpa_Value public_v,
Marpa_Symbol_ID xsyid)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12441 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1085:*/
#line 12354 "./marpa.w"

TREE t= T_of_V(v);
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12356 "./marpa.w"


/*:1085*/
#line 12443 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12444 "./marpa.w"

/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 12445 "./marpa.w"

return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsyid);
}

/*:1100*//*1101:*/
#line 12449 "./marpa.w"

PRIVATE int symbol_is_valued_set(
VALUE v,XSYID xsyid,int value)
{
const int valued_is_locked= -1;
const int old_value= lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsyid);
if(old_value==value){
lbv_bit_set(Valued_Locked_BV_of_V(v),xsyid);
return value;
}

if(UNLIKELY(lbv_bit_test(Valued_Locked_BV_of_V(v),xsyid))){
return valued_is_locked;
}
lbv_bit_set(Valued_Locked_BV_of_V(v),xsyid);
if(value){
lbv_bit_set(XSY_is_Valued_BV_of_V(v),xsyid);
}else{
lbv_bit_clear(XSY_is_Valued_BV_of_V(v),xsyid);
}
return value;
}

/*:1101*//*1102:*/
#line 12472 "./marpa.w"

int marpa_v_symbol_is_valued_set(
Marpa_Value public_v,Marpa_Symbol_ID xsyid,int value)
{
const VALUE v= (VALUE)public_v;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12477 "./marpa.w"

/*1085:*/
#line 12354 "./marpa.w"

TREE t= T_of_V(v);
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12356 "./marpa.w"


/*:1085*/
#line 12478 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12479 "./marpa.w"

if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1221:*/
#line 14045 "./marpa.w"

if(UNLIKELY(!xsyid_is_valid(g,xsyid))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1221*/
#line 12485 "./marpa.w"

return symbol_is_valued_set(v,xsyid,value);
}

/*:1102*//*1103:*/
#line 12489 "./marpa.w"

int marpa_v_rule_is_valued_set(
Marpa_Value public_v,Marpa_Rule_ID xrl_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12494 "./marpa.w"

/*1085:*/
#line 12354 "./marpa.w"

TREE t= T_of_V(v);
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12356 "./marpa.w"


/*:1085*/
#line 12495 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12496 "./marpa.w"

if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1224:*/
#line 14060 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1224*/
#line 12502 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsyid= LHS_ID_of_XRL(xrl);
return symbol_is_valued_set(v,xsyid,value);
}
}

/*:1103*//*1106:*/
#line 12518 "./marpa.w"

Marpa_Step_Type marpa_v_step(Marpa_Value public_v)
{
/*1218:*/
#line 14029 "./marpa.w"
const int failure_indicator= -2;

/*:1218*/
#line 12521 "./marpa.w"

const VALUE v= (VALUE)public_v;

if(V_is_Nulling(v)){
/*1085:*/
#line 12354 "./marpa.w"

TREE t= T_of_V(v);
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12356 "./marpa.w"


/*:1085*/
#line 12525 "./marpa.w"

/*1108:*/
#line 12602 "./marpa.w"

{
while(V_is_Active(v)){
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case V_INITIALIZE:
case V_GET_DATA:
{
Next_Value_Type_of_V(v)= MARPA_STEP_INACTIVE;
XSYID_of_V(v)= g->t_start_xsyid;
TOS_of_V(v)= Arg_N_of_V(v)= 0;
if(lbv_bit_test(XSY_is_Valued_BV_of_V(v),XSYID_of_V(v)))
return MARPA_STEP_NULLING_SYMBOL;
}



}
}
}

/*:1108*/
#line 12526 "./marpa.w"

return MARPA_STEP_INACTIVE;
}

while(V_is_Active(v)){
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case V_INITIALIZE:
{
XSYID xsy_count;
/*1085:*/
#line 12354 "./marpa.w"

TREE t= T_of_V(v);
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12356 "./marpa.w"


/*:1085*/
#line 12537 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
lbv_fill(Valued_Locked_BV_of_V(v),xsy_count);
/*1107:*/
#line 12586 "./marpa.w"

{
const LBV xsy_bv= XSY_is_Valued_BV_of_V(v);
const XRLID xrl_count= XRL_Count_of_G(g);
const LBV xrl_bv= lbv_obs_new0(v->t_obs,xrl_count);
XRLID xrlid;
XRL_is_Valued_BV_of_V(v)= xrl_bv;
for(xrlid= 0;xrlid<xrl_count;xrlid++){
const XRL xrl= XRL_by_ID(xrlid);
const XSYID lhs_xsyid= LHS_ID_of_XRL(xrl);
if(lbv_bit_test(xsy_bv,lhs_xsyid)){
lbv_bit_set(xrl_bv,xrlid);
}
}
}

/*:1107*/
#line 12540 "./marpa.w"

}

case V_GET_DATA:
/*1109:*/
#line 12624 "./marpa.w"

{
AND and_nodes;




int pop_arguments= 1;
/*1085:*/
#line 12354 "./marpa.w"

TREE t= T_of_V(v);
/*1014:*/
#line 11563 "./marpa.w"

ORDER o= O_of_T(t);
/*1000:*/
#line 11325 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*946:*/
#line 10777 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:946*/
#line 11327 "./marpa.w"


/*:1000*/
#line 11565 "./marpa.w"
;

/*:1014*/
#line 12356 "./marpa.w"


/*:1085*/
#line 12632 "./marpa.w"

/*1231:*/
#line 14099 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1231*/
#line 12633 "./marpa.w"

and_nodes= ANDs_of_B(B_of_O(o));

if(NOOK_of_V(v)<0){
NOOK_of_V(v)= Size_of_TREE(t);
}

while(1){
OR or;
IRL nook_irl;
Token_Value_of_V(v)= -1;
RULEID_of_V(v)= -1;
NOOK_of_V(v)--;
if(NOOK_of_V(v)<0){
Next_Value_Type_of_V(v)= MARPA_STEP_INACTIVE;
break;
}
if(pop_arguments){


Arg_N_of_V(v)= TOS_of_V(v);
pop_arguments= 0;
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
const ISYID token_isyid= ISYID_of_TOK(token);
TOS_of_V(v)= ++Arg_N_of_V(v);
if(token_type==VALUED_TOKEN_OR_NODE)
{
const ISY token_isy= ISY_by_ID(token_isyid);
XSYID_of_V(v)= ID_of_XSY(Source_XSY_of_ISY(token_isy));
Token_Value_of_V(v)= Value_of_TOK(token);
}
else if(token_type==NULLING_TOKEN_OR_NODE)
{
const ISY token_isy= ISY_by_ID(token_isyid);
const XSY source_xsy= Source_XSY_of_ISY(token_isy);
const XSYID source_xsyid= ID_of_XSY(source_xsy);
if(bv_bit_test(XSY_is_Valued_BV_of_V(v),source_xsyid))
{
XSYID_of_V(v)= source_xsyid;
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
if(Position_of_OR(or)==Length_of_IRL(nook_irl)){
int virtual_rhs= IRL_has_Virtual_RHS(nook_irl);
int virtual_lhs= IRL_has_Virtual_LHS(nook_irl);
int real_symbol_count;
const DSTACK virtual_stack= &VStack_of_V(v);
if(virtual_lhs){
real_symbol_count= Real_SYM_Count_of_IRL(nook_irl);
if(virtual_rhs){
*(DSTACK_TOP(*virtual_stack,int))+= real_symbol_count;
}else{
*DSTACK_PUSH(*virtual_stack,int)= real_symbol_count;
}
}else{

if(virtual_rhs){
real_symbol_count= Real_SYM_Count_of_IRL(nook_irl);
real_symbol_count+= *DSTACK_POP(*virtual_stack,int);
}else{
real_symbol_count= Length_of_IRL(nook_irl);
}
{


XRLID original_rule_id= ID_of_XRL(Source_XRL_of_IRL(nook_irl));
TOS_of_V(v)= Arg_N_of_V(v)-real_symbol_count+1;
pop_arguments= 1;
if(lbv_bit_test(XRL_is_Valued_BV_of_V(v),original_rule_id))
{
RULEID_of_V(v)= original_rule_id;
}
}

}
}
if(RULEID_of_V(v)>=0)break;
if(Token_Type_of_V(v)!=DUMMY_OR_NODE)break;
if(V_is_Trace(v))break;
}
}

/*:1109*/
#line 12544 "./marpa.w"

if(!V_is_Active(v))break;

case MARPA_STEP_TOKEN:
{
int token_type= Token_Type_of_V(v);
Next_Value_Type_of_V(v)= MARPA_STEP_RULE;
if(token_type==NULLING_TOKEN_OR_NODE)
{
if(lbv_bit_test(XSY_is_Valued_BV_of_V(v),XSYID_of_V(v)))
return MARPA_STEP_NULLING_SYMBOL;
}
else if(token_type!=DUMMY_OR_NODE)
{
return MARPA_STEP_TOKEN;
}
}

case MARPA_STEP_RULE:
if(RULEID_of_V(v)>=0)
{
Next_Value_Type_of_V(v)= MARPA_STEP_TRACE;
return MARPA_STEP_RULE;
}

case MARPA_STEP_TRACE:
Next_Value_Type_of_V(v)= V_GET_DATA;
if(V_is_Trace(v))
{
return MARPA_STEP_TRACE;
}
}
}

Next_Value_Type_of_V(v)= MARPA_STEP_INACTIVE;
return MARPA_STEP_INACTIVE;
}

/*:1106*//*1111:*/
#line 12761 "./marpa.w"

PRIVATE int lbv_bits_to_size(int bits)
{
return(bits+(lbv_wordbits-1))/lbv_wordbits;
}

/*:1111*//*1112:*/
#line 12768 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new0(struct obstack*obs,int bits)
{
int size= lbv_bits_to_size(bits);
LBV lbv= my_obstack_new(obs,LBW,size);
if(size> 0){
LBW*addr= lbv;
while(size--)*addr++= 0u;
}
return lbv;
}

/*:1112*//*1114:*/
#line 12792 "./marpa.w"

PRIVATE LBV lbv_copy(
struct obstack*obs,LBV old_lbv,int bits)
{
int size= lbv_bits_to_size(bits);
const LBV new_lbv= my_obstack_new(obs,LBW,size);
if(size> 0){
LBW*from_addr= old_lbv;
LBW*to_addr= new_lbv;
while(size--)*to_addr++= *from_addr++;
}
return new_lbv;
}

/*:1114*//*1115:*/
#line 12808 "./marpa.w"

PRIVATE LBV lbv_fill(
LBV lbv,int bits)
{
int size= lbv_bits_to_size(bits);
if(size> 0){
LBW*to_addr= lbv;
while(size--)*to_addr++= ~((LBW)0);
}
return lbv;
}

/*:1115*//*1118:*/
#line 12844 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(unsigned int bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1118*//*1119:*/
#line 12850 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(unsigned int bits)
{
unsigned int mask= bits&bv_modmask;
if(mask)mask= (unsigned int)~(~0uL<<mask);else mask= (unsigned int)~0uL;
return(mask);
}

/*:1119*//*1121:*/
#line 12864 "./marpa.w"

PRIVATE Bit_Vector bv_create(unsigned int bits)
{
unsigned int size= bv_bits_to_size(bits);
unsigned int bytes= (size+bv_hiddenwords)*sizeof(Bit_Vector_Word);
unsigned int*addr= (Bit_Vector)my_malloc0((size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}

/*:1121*//*1123:*/
#line 12882 "./marpa.w"

PRIVATE Bit_Vector
bv_obs_create(struct obstack*obs,unsigned int bits)
{
unsigned int size= bv_bits_to_size(bits);
unsigned int bytes= (size+bv_hiddenwords)*sizeof(Bit_Vector_Word);
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


/*:1123*//*1124:*/
#line 12903 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,BV_BITS(bv));
}

/*:1124*//*1125:*/
#line 12917 "./marpa.w"

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

/*:1125*//*1126:*/
#line 12935 "./marpa.w"

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

/*:1126*//*1127:*/
#line 12949 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1127*//*1128:*/
#line 12960 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1128*//*1129:*/
#line 12971 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1129*//*1131:*/
#line 12985 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,unsigned int bit)
{
unsigned int length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1131*//*1133:*/
#line 12993 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1133*//*1134:*/
#line 13000 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1134*//*1135:*/
#line 13007 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,unsigned int bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1135*//*1136:*/
#line 13015 "./marpa.w"

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

/*:1136*//*1137:*/
#line 13028 "./marpa.w"

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

/*:1137*//*1138:*/
#line 13042 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1138*//*1139:*/
#line 13052 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1139*//*1140:*/
#line 13062 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1140*//*1141:*/
#line 13072 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1141*//*1142:*/
#line 13082 "./marpa.w"

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

/*:1142*//*1143:*/
#line 13154 "./marpa.w"

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

/*:1143*//*1148:*/
#line 13202 "./marpa.w"

PRIVATE void
rhs_closure(GRAMMAR g,Bit_Vector bv,XRLID**xrl_list_x_rh_sym)
{
unsigned int min,max,start= 0;
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_DECLARE(stack,XSYID)
FSTACK_INIT(stack,XSYID,XSY_Count_of_G(g));
while(bv_scan(bv,start,&min,&max))
{
unsigned int xsyid;
for(xsyid= min;xsyid<=max;xsyid++)
{
*(FSTACK_PUSH(stack))= xsyid;
}
start= max+2;
}
while((top_of_stack= FSTACK_POP(stack)))
{
const SYMID xsyid= *top_of_stack;
XRLID*p_xrl= xrl_list_x_rh_sym[xsyid];
const XRLID*p_one_past_rules= xrl_list_x_rh_sym[xsyid+1];
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

/*:1148*//*1152:*/
#line 13304 "./marpa.w"

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

/*:1152*//*1153:*/
#line 13331 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1153*//*1154:*/
#line 13347 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,unsigned int row)
{
Bit_Vector row0= matrix+bv_hiddenwords;
unsigned int words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1154*//*1156:*/
#line 13356 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1156*//*1158:*/
#line 13364 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1158*//*1160:*/
#line 13372 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1160*//*1161:*/
#line 13385 "./marpa.w"

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

/*:1161*//*1170:*/
#line 13549 "./marpa.w"

PRIVATE_NOT_INLINE void*dstack_resize(struct s_dstack*this,size_t type_bytes)
{
this->t_capacity*= 2;
this->t_base= my_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}

/*:1170*//*1185:*/
#line 13688 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1185*//*1186:*/
#line 13695 "./marpa.w"

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
/*:1186*//*1187:*/
#line 13709 "./marpa.w"

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
/*:1187*//*1190:*/
#line 13740 "./marpa.w"

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

/*:1190*//*1192:*/
#line 13758 "./marpa.w"

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

/*:1192*//*1194:*/
#line 13778 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1194*//*1196:*/
#line 13802 "./marpa.w"

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

/*:1196*//*1199:*/
#line 13828 "./marpa.w"

PRIVATE_NOT_INLINE void*
_marpa_default_out_of_memory(void)
{
abort();
}
void*(*_marpa_out_of_memory)(void)= _marpa_default_out_of_memory;

/*:1199*//*1234:*/
#line 14143 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}

/*:1234*//*1242:*/
#line 14215 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
_marpa_debug_handler= debug_handler;
}

/*:1242*//*1244:*/
#line 14223 "./marpa.w"

void marpa_debug_level_set(int level)
{
_marpa_debug_level= level;
}

/*:1244*/
#line 14457 "./marpa.w"


/*:1259*/
