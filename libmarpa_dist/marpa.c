/*1391:*/
#line 16467 "./marpa.w"

/*
 * Copyright 2013 Jeffrey Kegler
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

/*:1391*//*1392:*/
#line 16490 "./marpa.w"

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
#define XSY_by_ID(id) (*DSTACK_INDEX(g->t_xsy_stack,XSY,(id) ) )  \

#define XSYID_is_Malformed(xsy_id) ((xsy_id) <0) 
#define XSYID_of_G_Exists(xsy_id) ((xsy_id) <XSY_Count_of_G(g) ) 
#define XRL_Count_of_G(g) (DSTACK_LENGTH((g) ->t_xrl_stack) ) 
#define IRL_Count_of_G(g) (DSTACK_LENGTH((g) ->t_irl_stack) ) 
#define XRL_by_ID(id) (*DSTACK_INDEX((g) ->t_xrl_stack,XRL,(id) ) ) 
#define IRL_by_ID(id) (*DSTACK_INDEX((g) ->t_irl_stack,IRL,(id) ) ) 
#define RULE_by_ID(g,id) (XRL_by_ID(id) )  \

#define XRLID_is_Malformed(rule_id) ((rule_id) <0) 
#define XRLID_of_G_Exists(rule_id) ((rule_id) <XRL_Count_of_G(g) ) 
#define IRLID_of_G_is_Valid(irl_id)  \
((irl_id) >=0&&(irl_id) <IRL_Count_of_G(g) )  \

#define G_is_Trivial(g) (!(g) ->t_start_irl) 
#define External_Size_of_G(g) ((g) ->t_external_size) 
#define MAXIMUM_RANK (INT_MAX/4) 
#define MINIMUM_RANK (INT_MIN/4+(INT_MIN%4> 0?1:0) ) 
#define Default_Rank_of_G(g) ((g) ->t_default_rank) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define G_EVENT_COUNT(g) DSTACK_LENGTH((g) ->t_events) 
#define INITIAL_G_EVENTS_CAPACITY (1024/sizeof(int) ) 
#define G_EVENTS_CLEAR(g) DSTACK_CLEAR((g) ->t_events) 
#define G_EVENT_PUSH(g) DSTACK_PUSH((g) ->t_events,GEV_Object) 
#define I_AM_OK 0x69734f4b
#define IS_G_OK(g) ((g) ->t_is_ok==I_AM_OK) 
#define ID_of_XSY(xsy) ((xsy) ->t_symbol_id) 
#define Rank_of_XSY(symbol) ((symbol) ->t_rank) 
#define XSY_is_LHS(xsy) ((xsy) ->t_is_lhs) 
#define XSY_is_Sequence_LHS(xsy) ((xsy) ->t_is_sequence_lhs) 
#define XSY_is_Valued(symbol) ((symbol) ->t_is_valued) 
#define XSY_is_Valued_Locked(symbol) ((symbol) ->t_is_valued_locked) 
#define XSY_is_Accessible(xsy) ((xsy) ->t_is_accessible) 
#define XSY_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define XSY_is_Nullable(xsy) ((xsy) ->t_is_nullable) 
#define XSYID_is_Nullable(xsyid) XSY_is_Nullable(XSY_by_ID(xsyid) ) 
#define XSY_is_Terminal(xsy) ((xsy) ->t_is_terminal) 
#define XSY_is_Locked_Terminal(xsy) ((xsy) ->t_is_locked_terminal) 
#define XSYID_is_Terminal(id) (XSY_is_Terminal(XSY_by_ID(id) ) ) 
#define XSY_is_Productive(xsy) ((xsy) ->t_is_productive) 
#define XSY_is_Completion_Event(xsy) ((xsy) ->t_is_completion_event) 
#define XSYID_is_Completion_Event(xsyid) XSY_is_Completion_Event(XSY_by_ID(xsyid) ) 
#define XSY_is_Nulled_Event(xsy) ((xsy) ->t_is_nulled_event) 
#define XSYID_is_Nulled_Event(xsyid) XSY_is_Nulled_Event(XSY_by_ID(xsyid) ) 
#define XSY_is_Prediction_Event(xsy) ((xsy) ->t_is_prediction_event) 
#define XSYID_is_Prediction_Event(xsyid) XSY_is_Prediction_Event(XSY_by_ID(xsyid) ) 
#define Nulled_XSYIDs_of_XSY(xsy) ((xsy) ->t_nulled_event_xsyids) 
#define Nulled_XSYIDs_of_XSYID(xsyid)  \
Nulled_XSYIDs_of_XSY(XSY_by_ID(xsyid) ) 
#define ISY_of_XSY(xsy) ((xsy) ->t_isy_equivalent) 
#define ISYID_of_XSY(xsy) ID_of_ISY(ISY_of_XSY(xsy) ) 
#define ISY_by_XSYID(xsy_id) (XSY_by_ID(xsy_id) ->t_isy_equivalent) 
#define ISYID_by_XSYID(xsy_id) ID_of_ISY(ISY_of_XSY(XSY_by_ID(xsy_id) ) ) 
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
#define ISY_is_Semantic(isy) ((isy) ->t_is_semantic) 
#define ISYID_is_Semantic(isyid) (ISY_is_Semantic(ISY_by_ID(isyid) ) ) 
#define Source_XSY_of_ISY(isy) ((isy) ->t_source_xsy) 
#define Source_XSY_of_ISYID(isyid) (Source_XSY_of_ISY(ISY_by_ID(isyid) ) ) 
#define LHS_XRL_of_ISY(isy) ((isy) ->t_lhs_xrl) 
#define XRL_Offset_of_ISY(isy) ((isy) ->t_xrl_offset) 
#define ISY_Rank_by_XSY(xsy)  \
((xsy) ->t_rank*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK) 
#define Rank_of_ISY(isy) ((isy) ->t_rank) 
#define MAX_RHS_LENGTH (INT_MAX>>(2) ) 
#define Length_of_XRL(xrl) ((xrl) ->t_rhs_length) 
#define LHS_ID_of_RULE(rule) ((rule) ->t_symbols[0]) 
#define LHS_ID_of_XRL(xrl) ((xrl) ->t_symbols[0]) 
#define RHS_ID_of_RULE(rule,position)  \
((rule) ->t_symbols[(position) +1]) 
#define RHS_ID_of_XRL(xrl,position)  \
((xrl) ->t_symbols[(position) +1])  \

#define ID_of_XRL(xrl) ((xrl) ->t_id) 
#define ID_of_RULE(rule) ID_of_XRL(rule) 
#define Rank_of_XRL(rule) ((rule) ->t_rank) 
#define Null_Ranks_High_of_RULE(rule) ((rule) ->t_null_ranks_high) 
#define XRL_is_BNF(rule) ((rule) ->t_is_bnf) 
#define XRL_is_Sequence(rule) ((rule) ->t_is_sequence) 
#define Minimum_of_XRL(rule) ((rule) ->t_minimum) 
#define Separator_of_XRL(rule) ((rule) ->t_separator_id) 
#define XRL_is_Proper_Separation(rule) ((rule) ->t_is_proper_separation) 
#define XRL_is_Nulling(rule) ((rule) ->t_is_nulling) 
#define XRL_is_Nullable(rule) ((rule) ->t_is_nullable) 
#define XRL_is_Accessible(rule) ((rule) ->t_is_accessible) 
#define XRL_is_Productive(rule) ((rule) ->t_is_productive) 
#define XRL_is_Used(rule) ((rule) ->t_is_used) 
#define ID_of_IRL(irl) ((irl) ->t_irl_id) 
#define LHSID_of_IRL(irlid) ((irlid) ->t_isyid_array[0]) 
#define LHS_of_IRL(irl) (ISY_by_ID(LHSID_of_IRL(irl) ) )  \

#define RHSID_of_IRL(irl,position) ((irl) ->t_isyid_array[(position) +1]) 
#define RHS_of_IRL(irl,position) ISY_by_ID(RHSID_of_IRL((irl) ,(position) ) ) 
#define Length_of_IRL(irl) ((irl) ->t_length) 
#define IRL_has_Virtual_LHS(irl) ((irl) ->t_is_virtual_lhs) 
#define IRL_has_Virtual_RHS(irl) ((irl) ->t_is_virtual_rhs) 
#define IRL_is_Right_Recursive(irl) ((irl) ->t_is_right_recursive) 
#define Real_SYM_Count_of_IRL(irl) ((irl) ->t_real_symbol_count) 
#define Virtual_Start_of_IRL(irl) ((irl) ->t_virtual_start) 
#define Virtual_End_of_IRL(irl) ((irl) ->t_virtual_end) 
#define Source_XRL_of_IRL(irl) ((irl) ->t_source_xrl) 
#define EXTERNAL_RANK_FACTOR 4
#define MAXIMUM_CHAF_RANK 3
#define IRL_CHAF_Rank_by_XRL(xrl,chaf_rank) ( \
((xrl) ->t_rank*EXTERNAL_RANK_FACTOR) + \
(((xrl) ->t_null_ranks_high) ?(MAXIMUM_CHAF_RANK- \
(chaf_rank) ) :(chaf_rank) )  \
) 
#define IRL_Rank_by_XRL(xrl) IRL_CHAF_Rank_by_XRL((xrl) ,MAXIMUM_CHAF_RANK) 
#define Rank_of_IRL(irl) ((irl) ->t_rank) 
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
#define Completion_XSYIDs_of_AHFA(state) ((state) ->t_completion_xsyids) 
#define Nulled_XSYIDs_of_AHFA(state) ((state) ->t_nulled_xsyids) 
#define Prediction_XSYIDs_of_AHFA(state) ((state) ->t_prediction_xsyids) 
#define Completion_CIL_of_AHFA(state) ((state) ->t_complete_isyids) 
#define Complete_ISYID_of_AHFA(state,ix)  \
Item_of_CIL(Completion_CIL_of_AHFA(state) ,(ix) ) 
#define Complete_ISY_Count_of_AHFA(state)  \
Count_of_CIL(Completion_CIL_of_AHFA(state) )  \

#define AIMs_of_AHFA(ahfa) ((ahfa) ->t_items) 
#define AIM_of_AHFA_by_AEX(ahfa,aex) (AIMs_of_AHFA(ahfa) [aex]) 
#define AEX_of_AHFA_by_AIM(ahfa,aim) aex_of_ahfa_by_aim_get((ahfa) ,(aim) ) 
#define AIM_Count_of_AHFA(ahfa) ((ahfa) ->t_item_count) 
#define AHFA_is_Predicted(ahfa) ((ahfa) ->t_is_predict) 
#define EIM_is_Predicted(eim) AHFA_is_Predicted(AHFA_of_EIM(eim) ) 
#define AHFA_is_Potential_Leo_Base(ahfa) ((ahfa) ->t_is_potential_leo_base) 
#define EIM_is_Potential_Leo_Base(eim) AHFA_is_Potential_Leo_Base(AHFA_of_EIM(eim) ) 
#define Event_Group_Size_of_AHFA(ahfa) ((ahfa) ->t_event_group_size) 
#define Event_AHFAIDs_of_AHFA(ahfa) ((ahfa) ->t_event_ahfaids) 
#define AHFA_has_Event(ahfa) (Count_of_CIL(Event_AHFAIDs_of_AHFA(ahfa) ) !=0) 
#define AHFA_of_G_by_ID(g,id) ((g) ->t_AHFA+(id) ) 
#define AHFA_by_ID(id) (g->t_AHFA+(id) ) 
#define AHFA_Count_of_G(g) ((g) ->t_AHFA_len) 
#define ID_of_AHFA(state) ((state) ->t_key.t_id)  \

#define Postdot_ISY_Count_of_AHFA(state) ((state) ->t_postdot_isy_count) 
#define Postdot_ISYIDAry_of_AHFA(state) ((state) ->t_postdot_isyidary) 
#define AIMID_of_AHFA_by_AEX(g,ahfa,aex)  \
((ahfa) ->t_items[aex]-(g) ->t_AHFA_items) 
#define Leo_LHS_ISYID_of_AHFA(state) ((state) ->t_leo_lhs_isyid) 
#define Leo_IRLID_of_AHFA(state) ((state) ->t_leo_irlid) 
#define AHFA_is_Leo_Completion(state) (Leo_IRLID_of_AHFA(state) >=0) 
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

#define Value_of_ES(set) ((set) ->t_value) 
#define PValue_of_ES(set) ((set) ->t_pvalue) 
#define EIM_FATAL_THRESHOLD (INT_MAX/4) 
#define Complete_ISYID_of_EIM(item,ix)  \
Complete_ISYID_of_AHFA(AHFA_of_EIM(item) ,(ix) ) 
#define Complete_ISY_Count_of_EIM(item)  \
Complete_ISY_Count_of_AHFA(AHFA_of_EIM(item) ) 
#define Leo_IRLID_of_EIM(eim) Leo_IRLID_of_AHFA(AHFA_of_EIM(eim) ) 
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
#define Earleme_of_LIM(lim) Earleme_of_ES(ES_of_LIM(lim) ) 
#define CIL_of_LIM(lim) ((lim) ->t_cil) 
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
#define Ambiguity_Metric_of_B(b) ((b) ->t_ambiguity_metric) 
#define B_is_Nulling(b) ((b) ->t_is_nulling) 
#define OBS_of_O(order) ((order) ->t_ordering_obs) 
#define O_is_Default(order) (!OBS_of_O(order) ) 
#define O_is_Frozen(o) ((o) ->t_is_frozen) 
#define B_of_O(b) ((b) ->t_bocage) 
#define Ambiguity_Metric_of_O(o) ((o) ->t_ambiguity_metric) 
#define O_is_Nulling(o) ((o) ->t_is_nulling) 
#define High_Rank_Count_of_O(order) ((order) ->t_high_rank_count) 
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
#define NOOK_Cause_is_Expanded(nook) ((nook) ->t_is_cause_ready) 
#define NOOK_is_Cause(nook) ((nook) ->t_is_cause_of_parent) 
#define NOOK_Predecessor_is_Expanded(nook) ((nook) ->t_is_predecessor_ready) 
#define NOOK_is_Predecessor(nook) ((nook) ->t_is_predecessor_of_parent) 
#define Next_Value_Type_of_V(val) ((val) ->t_next_value_type) 
#define V_is_Active(val) (Next_Value_Type_of_V(val) !=MARPA_STEP_INACTIVE) 
#define T_of_V(v) ((v) ->t_tree) 
#define Step_Type_of_V(val) ((val) ->public.t_step_type) 
#define XSYID_of_V(val) ((val) ->public.t_token_id) 
#define RULEID_of_V(val) ((val) ->public.t_rule_id) 
#define Token_Value_of_V(val) ((val) ->public.t_token_value) 
#define Token_Type_of_V(val) ((val) ->t_token_type) 
#define Arg_0_of_V(val) ((val) ->public.t_arg_0) 
#define Arg_N_of_V(val) ((val) ->public.t_arg_n) 
#define Result_of_V(val) ((val) ->public.t_result) 
#define Rule_Start_of_V(val) ((val) ->public.t_rule_start_es_id) 
#define Token_Start_of_V(val) ((val) ->public.t_token_start_es_id) 
#define ES_ID_of_V(val) ((val) ->public.t_es_id) 
#define VStack_of_V(val) ((val) ->t_virtual_stack) 
#define V_is_Nulling(v) ((v) ->t_is_nulling) 
#define V_is_Trace(val) ((val) ->t_trace) 
#define NOOK_of_V(val) ((val) ->t_nook) 
#define XSY_is_Valued_BV_of_V(v) ((v) ->t_xsy_is_valued) 
#define XRL_is_Valued_BV_of_V(v) ((v) ->t_xrl_is_valued) 
#define Valued_Locked_BV_of_V(v) ((v) ->t_valued_locked) 
#define STEP_GET_DATA MARPA_STEP_INTERNAL2 \

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
#define DSTACK_INIT(this,type,initial_size)  \
( \
((this) .t_count= 0) , \
((this) .t_base= my_new(type,((this) .t_capacity= (initial_size) ) ) )  \
) 
#define DSTACK_INIT2(this,type)  \
DSTACK_INIT((this) ,type,MAX(4,1024/sizeof(this) ) )  \

#define DSTACK_IS_INITIALIZED(this) ((this) .t_base) 
#define DSTACK_SAFE(this)  \
(((this) .t_count= (this) .t_capacity= 0) ,((this) .t_base= NULL) )  \

#define DSTACK_CLEAR(this) ((this) .t_count= 0) 
#define DSTACK_PUSH(this,type) ( \
(UNLIKELY((this) .t_count>=(this) .t_capacity)  \
?dstack_resize2(&(this) ,sizeof(type) )  \
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
#define DSTACK_RESIZE(this,type,new_size) (dstack_resize((this) ,sizeof(type) ,(new_size) ) ) 
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

#define Count_of_CIL(cil) (cil[0]) 
#define Item_of_CIL(cil,ix) (cil[1+(ix) ]) 
#define Sizeof_CIL(ix) (sizeof(int) *(1+(ix) ) ) 
#define CAPACITY_OF_CILAR(cilar) (CAPACITY_OF_DSTACK(cilar->t_buffer) -1) 
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

#line 16508 "./marpa.w"

#include "marpa_obs.h"
#include "avl.h"
/*103:*/
#line 996 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:103*//*137:*/
#line 1219 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef const struct s_xsy*XSY_Const;

/*:137*//*443:*/
#line 4699 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:443*//*484:*/
#line 5069 "./marpa.w"
struct s_AHFA_state;
/*:484*//*576:*/
#line 6361 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:576*//*682:*/
#line 7369 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:682*//*723:*/
#line 7811 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:723*//*731:*/
#line 7952 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:731*//*734:*/
#line 7986 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:734*//*811:*/
#line 9019 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:811*//*815:*/
#line 9046 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:815*//*917:*/
#line 10489 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:917*//*945:*/
#line 10902 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:945*//*988:*/
#line 11523 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:988*//*1014:*/
#line 11919 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:1014*//*1046:*/
#line 12390 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:1046*//*1057:*/
#line 12495 "./marpa.w"

struct s_bocage_setup_per_es;
/*:1057*//*1121:*/
#line 13189 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1121*//*1156:*/
#line 13634 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1156*//*1169:*/
#line 13771 "./marpa.w"

typedef struct s_value*VALUE;
/*:1169*//*1280:*/
#line 15254 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1280*//*1284:*/
#line 15303 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1284*//*1290:*/
#line 15357 "./marpa.w"

struct s_cil_arena;
/*:1290*//*1310:*/
#line 15688 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1310*//*1312:*/
#line 15703 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1312*/
#line 16511 "./marpa.w"

/*44:*/
#line 644 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:44*//*136:*/
#line 1217 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
/*:136*//*204:*/
#line 1726 "./marpa.w"

struct s_isy;
typedef struct s_isy*ISY;
typedef Marpa_ISY_ID ISYID;

/*:204*//*241:*/
#line 1992 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:241*//*314:*/
#line 2708 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:314*//*352:*/
#line 2956 "./marpa.w"
typedef int SYMI;
/*:352*//*483:*/
#line 5066 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef int AHFAID;
/*:483*//*577:*/
#line 6367 "./marpa.w"
typedef int AEX;
/*:577*//*598:*/
#line 6696 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:598*//*613:*/
#line 6787 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:613*//*679:*/
#line 7360 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:679*//*681:*/
#line 7364 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:681*//*758:*/
#line 8308 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:758*//*760:*/
#line 8320 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:760*//*937:*/
#line 10838 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:937*//*987:*/
#line 11512 "./marpa.w"

typedef int WHEID;

/*:987*//*1013:*/
#line 11915 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:1013*//*1028:*/
#line 12125 "./marpa.w"

typedef struct marpa_progress_item*PROGRESS;
/*:1028*//*1155:*/
#line 13630 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1155*//*1214:*/
#line 14436 "./marpa.w"

typedef unsigned int LBW;
typedef LBW*LBV;

/*:1214*//*1222:*/
#line 14527 "./marpa.w"

typedef LBW Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1222*//*1287:*/
#line 15324 "./marpa.w"

typedef int*CIL;

/*:1287*//*1291:*/
#line 15360 "./marpa.w"

typedef struct s_cil_arena*CILAR;
/*:1291*/
#line 16512 "./marpa.w"

/*1281:*/
#line 15257 "./marpa.w"

struct s_dstack{int t_count;int t_capacity;void*t_base;};
/*:1281*//*1289:*/
#line 15349 "./marpa.w"

struct s_cil_arena{
struct obstack*t_obs;
AVL_TREE t_avl;
DSTACK_DECLARE(t_buffer);
};
typedef struct s_cil_arena CILAR_Object;

/*:1289*/
#line 16513 "./marpa.w"

/*43:*/
#line 638 "./marpa.w"
struct marpa_g{
/*127:*/
#line 1164 "./marpa.w"

int t_is_ok;

/*:127*/
#line 639 "./marpa.w"

/*54:*/
#line 719 "./marpa.w"

DSTACK_DECLARE(t_xsy_stack);
DSTACK_DECLARE(t_isy_stack);

/*:54*//*63:*/
#line 776 "./marpa.w"

DSTACK_DECLARE(t_xrl_stack);
DSTACK_DECLARE(t_irl_stack);
/*:63*//*99:*/
#line 971 "./marpa.w"
Bit_Vector t_bv_isyid_is_terminal;
/*:99*//*101:*/
#line 980 "./marpa.w"

Bit_Vector t_lbv_xsyid_is_completion_event;
Bit_Vector t_lbv_xsyid_is_nulled_event;
Bit_Vector t_lbv_xsyid_is_prediction_event;
/*:101*//*108:*/
#line 1018 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:108*//*116:*/
#line 1090 "./marpa.w"

AVL_TREE t_xrl_tree;
/*:116*//*120:*/
#line 1120 "./marpa.w"

struct obstack*t_obs;
struct obstack*t_xrl_obs;
/*:120*//*123:*/
#line 1137 "./marpa.w"

CILAR_Object t_cilar;
/*:123*//*129:*/
#line 1179 "./marpa.w"

const char*t_error_string;
/*:129*//*445:*/
#line 4716 "./marpa.w"

AIM t_AHFA_items;
/*:445*//*509:*/
#line 5214 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:509*/
#line 640 "./marpa.w"

/*48:*/
#line 666 "./marpa.w"
int t_ref_count;
/*:48*//*73:*/
#line 827 "./marpa.w"
XSYID t_start_xsy_id;
/*:73*//*77:*/
#line 860 "./marpa.w"

IRL t_start_irl;
/*:77*//*81:*/
#line 877 "./marpa.w"

int t_external_size;
/*:81*//*84:*/
#line 891 "./marpa.w"
int t_max_rule_length;
/*:84*//*88:*/
#line 904 "./marpa.w"
Marpa_Rank t_default_rank;
/*:88*//*130:*/
#line 1181 "./marpa.w"

Marpa_Error_Code t_error;
/*:130*//*353:*/
#line 2958 "./marpa.w"

int t_symbol_instance_count;
/*:353*//*446:*/
#line 4720 "./marpa.w"

unsigned int t_aim_count;
/*:446*//*510:*/
#line 5219 "./marpa.w"
int t_AHFA_len;
/*:510*/
#line 641 "./marpa.w"

/*93:*/
#line 939 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:93*//*96:*/
#line 951 "./marpa.w"
unsigned int t_has_cycle:1;
/*:96*/
#line 642 "./marpa.w"

};
/*:43*//*107:*/
#line 1011 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:107*//*138:*/
#line 1224 "./marpa.w"

struct s_xsy{
/*190:*/
#line 1627 "./marpa.w"

CIL t_nulled_event_xsyids;
/*:190*//*193:*/
#line 1654 "./marpa.w"
ISY t_isy_equivalent;
/*:193*//*197:*/
#line 1686 "./marpa.w"
ISY t_nulling_isy;
/*:197*/
#line 1226 "./marpa.w"

/*139:*/
#line 1233 "./marpa.w"
XSYID t_symbol_id;

/*:139*//*145:*/
#line 1267 "./marpa.w"

Marpa_Rank t_rank;
/*:145*/
#line 1227 "./marpa.w"

/*142:*/
#line 1254 "./marpa.w"
unsigned int t_is_start:1;
/*:142*//*149:*/
#line 1314 "./marpa.w"
unsigned int t_is_lhs:1;
/*:149*//*151:*/
#line 1321 "./marpa.w"
unsigned int t_is_sequence_lhs:1;
/*:151*//*153:*/
#line 1335 "./marpa.w"

unsigned int t_is_valued:1;
unsigned int t_is_valued_locked:1;
/*:153*//*157:*/
#line 1379 "./marpa.w"
unsigned int t_is_accessible:1;
/*:157*//*160:*/
#line 1400 "./marpa.w"
unsigned int t_is_counted:1;
/*:160*//*163:*/
#line 1416 "./marpa.w"
unsigned int t_is_nulling:1;
/*:163*//*166:*/
#line 1433 "./marpa.w"
unsigned int t_is_nullable:1;
/*:166*//*169:*/
#line 1454 "./marpa.w"

unsigned int t_is_terminal:1;
unsigned int t_is_locked_terminal:1;
/*:169*//*174:*/
#line 1501 "./marpa.w"
unsigned int t_is_productive:1;
/*:174*//*177:*/
#line 1520 "./marpa.w"
unsigned int t_is_completion_event:1;
/*:177*//*181:*/
#line 1555 "./marpa.w"
unsigned int t_is_nulled_event:1;
/*:181*//*185:*/
#line 1590 "./marpa.w"
unsigned int t_is_prediction_event:1;
/*:185*/
#line 1228 "./marpa.w"

};

/*:138*//*205:*/
#line 1740 "./marpa.w"

struct s_isy{
int t_or_node_type;
ISYID t_isyid;
/*227:*/
#line 1890 "./marpa.w"
XSY t_source_xsy;
/*:227*//*231:*/
#line 1913 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:231*/
#line 1744 "./marpa.w"

/*236:*/
#line 1966 "./marpa.w"
Marpa_Rank t_rank;
/*:236*/
#line 1745 "./marpa.w"

/*215:*/
#line 1824 "./marpa.w"
unsigned int t_is_start:1;
/*:215*//*218:*/
#line 1838 "./marpa.w"
unsigned int t_is_lhs:1;
/*:218*//*221:*/
#line 1852 "./marpa.w"
unsigned int t_isy_is_nulling:1;
/*:221*//*224:*/
#line 1869 "./marpa.w"
unsigned int t_is_semantic:1;
/*:224*/
#line 1746 "./marpa.w"

};
/*:205*//*240:*/
#line 1983 "./marpa.w"

struct s_xrl{
/*253:*/
#line 2283 "./marpa.w"
int t_rhs_length;
/*:253*//*261:*/
#line 2348 "./marpa.w"
Marpa_Rule_ID t_id;

/*:261*//*262:*/
#line 2351 "./marpa.w"

Marpa_Rank t_rank;
/*:262*/
#line 1985 "./marpa.w"

/*266:*/
#line 2399 "./marpa.w"

unsigned int t_null_ranks_high:1;
/*:266*//*270:*/
#line 2440 "./marpa.w"
unsigned int t_is_bnf:1;
/*:270*//*272:*/
#line 2446 "./marpa.w"
unsigned int t_is_sequence:1;
/*:272*//*274:*/
#line 2460 "./marpa.w"
int t_minimum;
/*:274*//*277:*/
#line 2485 "./marpa.w"
XSYID t_separator_id;
/*:277*//*282:*/
#line 2518 "./marpa.w"
unsigned int t_is_discard:1;
/*:282*//*286:*/
#line 2558 "./marpa.w"
unsigned int t_is_proper_separation:1;
/*:286*//*290:*/
#line 2579 "./marpa.w"
unsigned int t_is_loop:1;
/*:290*//*293:*/
#line 2596 "./marpa.w"
unsigned int t_is_nulling:1;
/*:293*//*296:*/
#line 2614 "./marpa.w"
unsigned int t_is_nullable:1;
/*:296*//*300:*/
#line 2632 "./marpa.w"
unsigned int t_is_accessible:1;
/*:300*//*303:*/
#line 2650 "./marpa.w"
unsigned int t_is_productive:1;
/*:303*//*306:*/
#line 2668 "./marpa.w"
unsigned int t_is_used:1;
/*:306*/
#line 1986 "./marpa.w"

/*254:*/
#line 2286 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];


/*:254*/
#line 1987 "./marpa.w"

};
/*:240*//*312:*/
#line 2699 "./marpa.w"

struct s_irl{
/*344:*/
#line 2900 "./marpa.w"
XRL t_source_xrl;
/*:344*//*350:*/
#line 2948 "./marpa.w"
AIM t_first_aim;
/*:350*/
#line 2701 "./marpa.w"

/*315:*/
#line 2719 "./marpa.w"
IRLID t_irl_id;

/*:315*//*322:*/
#line 2756 "./marpa.w"
int t_length;
/*:322*//*335:*/
#line 2840 "./marpa.w"
int t_real_symbol_count;
/*:335*//*338:*/
#line 2858 "./marpa.w"
int t_virtual_start;
/*:338*//*341:*/
#line 2878 "./marpa.w"
int t_virtual_end;
/*:341*//*347:*/
#line 2927 "./marpa.w"
Marpa_Rank t_rank;
/*:347*//*354:*/
#line 2965 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:354*/
#line 2702 "./marpa.w"

/*326:*/
#line 2797 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:326*//*329:*/
#line 2813 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:329*//*332:*/
#line 2829 "./marpa.w"
unsigned int t_is_right_recursive:1;
/*:332*/
#line 2703 "./marpa.w"

/*317:*/
#line 2724 "./marpa.w"

ISYID t_isyid_array[1];

/*:317*/
#line 2704 "./marpa.w"

};
/*:312*//*367:*/
#line 3158 "./marpa.w"

struct sym_rule_pair
{
XSYID t_symid;
RULEID t_ruleid;
};

/*:367*//*442:*/
#line 4693 "./marpa.w"

struct s_AHFA_item{
int t_sort_key;
/*451:*/
#line 4742 "./marpa.w"

IRL t_irl;

/*:451*/
#line 4696 "./marpa.w"

/*452:*/
#line 4748 "./marpa.w"

int t_position;

/*:452*//*453:*/
#line 4755 "./marpa.w"
ISYID t_postdot_isyid;

/*:453*//*454:*/
#line 4764 "./marpa.w"

int t_leading_nulls;

/*:454*/
#line 4697 "./marpa.w"

};
/*:442*//*485:*/
#line 5070 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*489:*/
#line 5097 "./marpa.w"

CIL t_completion_xsyids;
CIL t_nulled_xsyids;
CIL t_prediction_xsyids;

/*:489*//*492:*/
#line 5119 "./marpa.w"

CIL t_indirect_completion_event_isyids;
CIL t_direct_completion_event_isyids;
CIL t_complete_isyids;

/*:492*//*494:*/
#line 5128 "./marpa.w"

AIM*t_items;
/*:494*//*505:*/
#line 5203 "./marpa.w"

CIL t_event_ahfaids;
/*:505*//*515:*/
#line 5247 "./marpa.w"
Marpa_Symbol_ID*t_postdot_isyidary;
/*:515*//*579:*/
#line 6379 "./marpa.w"

TRANS*t_transitions;
/*:579*/
#line 5077 "./marpa.w"

/*495:*/
#line 5131 "./marpa.w"

int t_item_count;
/*:495*//*506:*/
#line 5207 "./marpa.w"

int t_event_group_size;
/*:506*//*516:*/
#line 5248 "./marpa.w"
unsigned int t_postdot_isy_count;

/*:516*//*527:*/
#line 5411 "./marpa.w"

ISYID t_leo_lhs_isyid;
IRLID t_leo_irlid;
/*:527*/
#line 5078 "./marpa.w"

/*499:*/
#line 5172 "./marpa.w"

unsigned int t_is_predict:1;

/*:499*//*502:*/
#line 5180 "./marpa.w"

unsigned int t_is_potential_leo_base:1;
/*:502*/
#line 5079 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:485*//*578:*/
#line 6368 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
int t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:578*//*599:*/
#line 6699 "./marpa.w"

struct s_input{
/*608:*/
#line 6769 "./marpa.w"

struct obstack*t_token_obs;

/*:608*//*610:*/
#line 6774 "./marpa.w"

GRAMMAR t_grammar;
/*:610*/
#line 6701 "./marpa.w"

/*602:*/
#line 6715 "./marpa.w"

int t_ref_count;
/*:602*/
#line 6702 "./marpa.w"

};

/*:599*//*683:*/
#line 7375 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:683*//*684:*/
#line 7380 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*686:*/
#line 7395 "./marpa.w"

EIM*t_earley_items;

/*:686*//*1320:*/
#line 15773 "./marpa.w"

PSL t_dot_psl;
/*:1320*/
#line 7385 "./marpa.w"

int t_postdot_sym_count;
/*685:*/
#line 7392 "./marpa.w"

int t_eim_count;
/*:685*//*687:*/
#line 7406 "./marpa.w"

int t_ordinal;
/*:687*//*691:*/
#line 7424 "./marpa.w"

int t_value;
void*t_pvalue;
/*:691*/
#line 7387 "./marpa.w"

};

/*:684*//*732:*/
#line 7956 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
ISYID t_postdot_isyid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:732*//*735:*/
#line 7989 "./marpa.w"

struct s_leo_item{
EIX_Object t_earley_ix;
/*736:*/
#line 8002 "./marpa.w"

CIL t_cil;

/*:736*/
#line 7992 "./marpa.w"

ES t_origin;
AHFA t_top_ahfa;
LIM t_predecessor;
EIM t_base;
ES t_set;
};
typedef struct s_leo_item LIM_Object;

/*:735*//*742:*/
#line 8083 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:742*//*812:*/
#line 9027 "./marpa.w"

struct s_token_unvalued{
int t_type;
ISYID t_isyid;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:812*//*816:*/
#line 9056 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:816*//*918:*/
#line 10506 "./marpa.w"

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
/*:918*//*948:*/
#line 10940 "./marpa.w"

struct s_draft_or_node
{
/*947:*/
#line 10934 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:947*/
#line 10943 "./marpa.w"

DAND t_draft_and_node;
};
/*:948*//*949:*/
#line 10946 "./marpa.w"

struct s_final_or_node
{
/*947:*/
#line 10934 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:947*/
#line 10949 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:949*//*950:*/
#line 10957 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:950*//*989:*/
#line 11530 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:989*//*1015:*/
#line 11926 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:1015*//*1058:*/
#line 12497 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:1058*//*1085:*/
#line 12738 "./marpa.w"

struct marpa_order{
struct obstack*t_ordering_obs;
ANDID**t_and_node_orderings;
/*1088:*/
#line 12756 "./marpa.w"

BOCAGE t_bocage;

/*:1088*/
#line 12742 "./marpa.w"

/*1091:*/
#line 12776 "./marpa.w"
int t_ref_count;
/*:1091*//*1098:*/
#line 12832 "./marpa.w"
int t_ambiguity_metric;

/*:1098*//*1103:*/
#line 12864 "./marpa.w"
int t_high_rank_count;
/*:1103*/
#line 12743 "./marpa.w"

/*1101:*/
#line 12846 "./marpa.w"

unsigned int t_is_nulling:1;
/*:1101*/
#line 12744 "./marpa.w"

unsigned int t_is_frozen:1;
};
/*:1085*//*1122:*/
#line 13201 "./marpa.w"

/*1157:*/
#line 13645 "./marpa.w"

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

/*:1157*/
#line 13202 "./marpa.w"

/*1171:*/
#line 13785 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1175:*/
#line 13862 "./marpa.w"

struct obstack*t_obs;
/*:1175*//*1180:*/
#line 13909 "./marpa.w"

DSTACK_DECLARE(t_virtual_stack);
/*:1180*//*1202:*/
#line 14062 "./marpa.w"

LBV t_xsy_is_valued;
LBV t_xrl_is_valued;
LBV t_valued_locked;

/*:1202*/
#line 13789 "./marpa.w"

/*1185:*/
#line 13957 "./marpa.w"

int t_ref_count;
/*:1185*//*1197:*/
#line 14038 "./marpa.w"

NOOKID t_nook;
/*:1197*/
#line 13790 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1192:*/
#line 14010 "./marpa.w"

unsigned int t_is_nulling:1;
/*:1192*//*1194:*/
#line 14017 "./marpa.w"

unsigned int t_trace:1;
/*:1194*/
#line 13793 "./marpa.w"

};

/*:1171*/
#line 13203 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_or_node_in_use;
Marpa_Order t_order;
/*1128:*/
#line 13274 "./marpa.w"

int t_ref_count;
/*:1128*//*1135:*/
#line 13354 "./marpa.w"
int t_pause_counter;
/*:1135*/
#line 13209 "./marpa.w"

/*1141:*/
#line 13425 "./marpa.w"

unsigned int t_is_exhausted:1;
/*:1141*//*1144:*/
#line 13433 "./marpa.w"

unsigned int t_is_nulling:1;

/*:1144*/
#line 13210 "./marpa.w"

int t_parse_count;
};

/*:1122*//*1257:*/
#line 14997 "./marpa.w"

struct s_bit_matrix{
int t_row_count;
Bit_Vector_Word t_row_data[1];
};
typedef struct s_bit_matrix*Bit_Matrix;

/*:1257*//*1285:*/
#line 15306 "./marpa.w"

struct s_dqueue{int t_current;struct s_dstack t_stack;};

/*:1285*//*1311:*/
#line 15694 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1311*//*1313:*/
#line 15719 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1313*/
#line 16514 "./marpa.w"

/*34:*/
#line 547 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;

/*:34*//*951:*/
#line 10965 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:951*//*1034:*/
#line 12151 "./marpa.w"

static const struct marpa_progress_item progress_report_not_ready= {-2,-2,-2};

/*:1034*//*1223:*/
#line 14534 "./marpa.w"

static const unsigned int bv_wordbits= lbv_wordbits;
static const unsigned int bv_modmask= lbv_wordbits-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= lbv_lsb;
static const unsigned int bv_msb= lbv_msb;

/*:1223*//*1373:*/
#line 16276 "./marpa.w"

int(*_marpa_debug_handler)(const char*,...)= 
MARPA_DEFAULT_DEBUG_HANDLER;
int _marpa_debug_level= 0;

/*:1373*/
#line 16515 "./marpa.w"

/*614:*/
#line 6790 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*627:*/
#line 6889 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:627*//*639:*/
#line 6961 "./marpa.w"

Bit_Vector t_lbv_xsyid_completion_event_is_active;
Bit_Vector t_lbv_xsyid_nulled_event_is_active;
Bit_Vector t_lbv_xsyid_prediction_event_is_active;
/*:639*//*642:*/
#line 6981 "./marpa.w"
Bit_Vector t_bv_isyid_is_expected;
/*:642*//*646:*/
#line 7037 "./marpa.w"
LBV t_isy_expected_is_event;
/*:646*//*672:*/
#line 7331 "./marpa.w"
struct obstack*t_obs;
/*:672*//*698:*/
#line 7536 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:698*//*705:*/
#line 7610 "./marpa.w"

EIM t_trace_earley_item;
/*:705*//*745:*/
#line 8129 "./marpa.w"

union u_postdot_item**t_trace_pim_isy_p;
union u_postdot_item*t_trace_postdot_item;
/*:745*//*779:*/
#line 8584 "./marpa.w"

SRCL t_trace_source_link;
/*:779*//*817:*/
#line 9064 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:817*//*832:*/
#line 9260 "./marpa.w"

LBV t_valued_terminal;
LBV t_unvalued_terminal;
LBV t_valued;
LBV t_unvalued;
LBV t_valued_locked;

/*:832*//*840:*/
#line 9476 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:840*//*844:*/
#line 9487 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:844*//*848:*/
#line 9494 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:848*//*873:*/
#line 9948 "./marpa.w"

Bit_Vector t_bv_lim_symbols;
Bit_Vector t_bv_pim_symbols;
void**t_pim_workarea;
/*:873*//*894:*/
#line 10217 "./marpa.w"

void**t_lim_chain;
/*:894*//*919:*/
#line 10519 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:919*//*1029:*/
#line 12127 "./marpa.w"

const struct marpa_progress_item*t_current_report_item;
AVL_TRAV t_progress_report_traverser;
/*:1029*//*1314:*/
#line 15727 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1314*/
#line 6793 "./marpa.w"

/*617:*/
#line 6817 "./marpa.w"
int t_ref_count;
/*:617*//*631:*/
#line 6916 "./marpa.w"
int t_earley_item_warning_threshold;
/*:631*//*635:*/
#line 6944 "./marpa.w"
EARLEME t_furthest_earleme;
/*:635*//*640:*/
#line 6965 "./marpa.w"

int t_active_event_count;
/*:640*//*688:*/
#line 7410 "./marpa.w"

int t_earley_set_count;
/*:688*/
#line 6794 "./marpa.w"

/*624:*/
#line 6881 "./marpa.w"

unsigned int t_input_phase:2;
/*:624*//*664:*/
#line 7268 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:664*//*668:*/
#line 7306 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:668*//*780:*/
#line 8586 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:780*/
#line 6795 "./marpa.w"

};

/*:614*/
#line 16516 "./marpa.w"

/*759:*/
#line 8311 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:759*//*761:*/
#line 8323 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:761*//*762:*/
#line 8329 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:762*//*763:*/
#line 8336 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source_link t_unique;
};

/*:763*/
#line 16517 "./marpa.w"

/*724:*/
#line 7818 "./marpa.w"

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
/*729:*/
#line 7918 "./marpa.w"

unsigned int t_source_type:3;

/*:729*/
#line 7829 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:724*/
#line 16518 "./marpa.w"

/*1047:*/
#line 12392 "./marpa.w"

struct marpa_bocage{
/*952:*/
#line 10975 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:952*//*1049:*/
#line 12401 "./marpa.w"

INPUT t_input;

/*:1049*//*1051:*/
#line 12411 "./marpa.w"

struct obstack*t_obs;
/*:1051*//*1054:*/
#line 12470 "./marpa.w"

LBV t_valued_bv;
LBV t_valued_locked_bv;

/*:1054*/
#line 12394 "./marpa.w"

/*953:*/
#line 10978 "./marpa.w"

int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:953*//*1069:*/
#line 12637 "./marpa.w"
int t_ambiguity_metric;
/*:1069*//*1073:*/
#line 12651 "./marpa.w"
int t_ref_count;
/*:1073*/
#line 12395 "./marpa.w"

/*1080:*/
#line 12710 "./marpa.w"

unsigned int t_is_nulling:1;
/*:1080*/
#line 12396 "./marpa.w"

};

/*:1047*/
#line 16519 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1379:*/
#line 16343 "./marpa.w"

static const char*eim_tag_safe(char*buffer,EIM eim)UNUSED;
static const char*eim_tag(EIM eim)UNUSED;
/*:1379*//*1381:*/
#line 16368 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1381*//*1383:*/
#line 16394 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1383*//*1385:*/
#line 16426 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AIM aim)UNUSED;
static const char*aim_tag(AIM aim)UNUSED;
/*:1385*/
#line 16522 "./marpa.w"

/*1370:*/
#line 16249 "./marpa.w"

int _marpa_default_debug_handler(const char*format,...)
{
va_list args;
va_start(args,format);
vfprintf(stderr,format,args);
va_end(args);
putc('\n',stderr);
return 1;
}


/*:1370*//*1380:*/
#line 16347 "./marpa.w"

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

/*:1380*//*1382:*/
#line 16373 "./marpa.w"

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

/*:1382*//*1384:*/
#line 16398 "./marpa.w"

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

/*:1384*//*1386:*/
#line 16429 "./marpa.w"

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

/*:1386*/
#line 16523 "./marpa.w"

#endif
/*35:*/
#line 552 "./marpa.w"

Marpa_Error_Code
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
if(required_major!=MARPA_MAJOR_VERSION)
return MARPA_ERR_MAJOR_VERSION_MISMATCH;
if(required_minor> MARPA_MINOR_VERSION)
return MARPA_ERR_MINOR_VERSION_MISMATCH;
if(required_minor<MARPA_MINOR_VERSION)
return MARPA_ERR_NONE;
if(required_micro> MARPA_MICRO_VERSION)
return MARPA_ERR_MICRO_VERSION_MISMATCH;
return MARPA_ERR_NONE;
}

/*:35*//*36:*/
#line 570 "./marpa.w"

Marpa_Error_Code
marpa_version(unsigned int*version)
{
*version++= MARPA_MAJOR_VERSION;
*version++= MARPA_MINOR_VERSION;
*version= MARPA_MICRO_VERSION;
return 0;
}

/*:36*//*40:*/
#line 613 "./marpa.w"

int marpa_c_init(Marpa_Config*config)
{
config->t_is_ok= I_AM_OK;
config->t_error= MARPA_ERR_NONE;
config->t_error_string= NULL;
return 0;
}

/*:40*//*41:*/
#line 622 "./marpa.w"

Marpa_Error_Code marpa_c_error(Marpa_Config*config,const char**p_error_string)
{
const Marpa_Error_Code error_code= config->t_error;
const char*error_string= config->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:41*//*46:*/
#line 648 "./marpa.w"

Marpa_Grammar marpa_g_new(Marpa_Config*configuration)
{
GRAMMAR g;
if(configuration&&configuration->t_is_ok!=I_AM_OK){
configuration->t_error= MARPA_ERR_I_AM_NOT_OK;
return NULL;
}
g= my_slice_new(struct marpa_g);

g->t_is_ok= 0;
/*49:*/
#line 667 "./marpa.w"

g->t_ref_count= 1;

/*:49*//*55:*/
#line 723 "./marpa.w"

DSTACK_INIT2(g->t_xsy_stack,XSY);
DSTACK_SAFE(g->t_isy_stack);

/*:55*//*64:*/
#line 779 "./marpa.w"

DSTACK_INIT2(g->t_xrl_stack,RULE);
DSTACK_SAFE(g->t_irl_stack);

/*:64*//*74:*/
#line 828 "./marpa.w"

g->t_start_xsy_id= -1;
/*:74*//*78:*/
#line 862 "./marpa.w"

g->t_start_irl= NULL;
/*:78*//*82:*/
#line 879 "./marpa.w"

External_Size_of_G(g)= 0;

/*:82*//*85:*/
#line 892 "./marpa.w"

g->t_max_rule_length= 0;

/*:85*//*89:*/
#line 905 "./marpa.w"

g->t_default_rank= 0;
/*:89*//*94:*/
#line 940 "./marpa.w"

g->t_is_precomputed= 0;
/*:94*//*97:*/
#line 952 "./marpa.w"

g->t_has_cycle= 0;
/*:97*//*100:*/
#line 972 "./marpa.w"
g->t_bv_isyid_is_terminal= NULL;

/*:100*//*102:*/
#line 984 "./marpa.w"

g->t_lbv_xsyid_is_completion_event= NULL;
g->t_lbv_xsyid_is_nulled_event= NULL;
g->t_lbv_xsyid_is_prediction_event= NULL;

/*:102*//*109:*/
#line 1022 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:109*//*117:*/
#line 1092 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL,0);
/*:117*//*121:*/
#line 1123 "./marpa.w"

g->t_obs= my_obstack_init;
g->t_xrl_obs= my_obstack_begin(0,alignof(struct s_xrl));
/*:121*//*124:*/
#line 1139 "./marpa.w"

cilar_init(&(g)->t_cilar);
/*:124*//*131:*/
#line 1183 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:131*//*448:*/
#line 4725 "./marpa.w"

g->t_AHFA_items= NULL;
/*:448*//*511:*/
#line 5220 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:511*/
#line 659 "./marpa.w"


g->t_is_ok= I_AM_OK;
return g;
}

/*:46*//*50:*/
#line 677 "./marpa.w"

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

/*:50*//*52:*/
#line 694 "./marpa.w"

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

/*:52*//*53:*/
#line 706 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
/*56:*/
#line 727 "./marpa.w"

{
DSTACK_DESTROY(g->t_xsy_stack);
DSTACK_DESTROY(g->t_isy_stack);
}

/*:56*//*65:*/
#line 783 "./marpa.w"

DSTACK_DESTROY(g->t_irl_stack);
DSTACK_DESTROY(g->t_xrl_stack);

/*:65*//*110:*/
#line 1024 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:110*//*119:*/
#line 1099 "./marpa.w"

/*118:*/
#line 1094 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:118*/
#line 1100 "./marpa.w"


/*:119*//*122:*/
#line 1126 "./marpa.w"

my_obstack_free(g->t_obs);
my_obstack_free(g->t_xrl_obs);

/*:122*//*125:*/
#line 1141 "./marpa.w"

cilar_destroy(&(g)->t_cilar);

/*:125*//*449:*/
#line 4727 "./marpa.w"

my_free(g->t_AHFA_items);

/*:449*//*512:*/
#line 5224 "./marpa.w"

{
if(g->t_AHFA)
{
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}
}

/*:512*/
#line 710 "./marpa.w"

my_slice_free(struct marpa_g,g);
}

/*:53*//*58:*/
#line 735 "./marpa.w"

int marpa_g_highest_symbol_id(Marpa_Grammar g){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 737 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 738 "./marpa.w"

return XSY_Count_of_G(g)-1;
}

/*:58*//*60:*/
#line 747 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,XSY symbol)
{
const XSYID new_id= DSTACK_LENGTH((g)->t_xsy_stack);
*DSTACK_PUSH((g)->t_xsy_stack,XSY)= symbol;
symbol->t_symbol_id= new_id;
}

/*:60*//*61:*/
#line 759 "./marpa.w"

PRIVATE int xsy_id_is_valid(GRAMMAR g,XSYID xsy_id)
{
return!XSYID_is_Malformed(xsy_id)&&XSYID_of_G_Exists(xsy_id);
}

/*:61*//*62:*/
#line 766 "./marpa.w"

PRIVATE int isy_is_valid(GRAMMAR g,ISYID isyid)
{
return isyid>=0&&isyid<ISY_Count_of_G(g);
}

/*:62*//*69:*/
#line 790 "./marpa.w"

int marpa_g_highest_rule_id(Marpa_Grammar g){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 792 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 793 "./marpa.w"

return XRL_Count_of_G(g)-1;
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 797 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 798 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:69*//*71:*/
#line 809 "./marpa.w"

PRIVATE void
rule_add(GRAMMAR g,RULE rule)
{
const RULEID new_id= DSTACK_LENGTH((g)->t_xrl_stack);
*DSTACK_PUSH((g)->t_xrl_stack,RULE)= rule;
rule->t_id= new_id;
External_Size_of_G(g)+= 1+Length_of_XRL(rule);
g->t_max_rule_length= MAX(Length_of_XRL(rule),g->t_max_rule_length);
}

/*:71*//*75:*/
#line 830 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 833 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 834 "./marpa.w"

return g->t_start_xsy_id;
}
/*:75*//*76:*/
#line 843 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 846 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 847 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 848 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 849 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 850 "./marpa.w"

return g->t_start_xsy_id= xsy_id;
}

/*:76*//*90:*/
#line 907 "./marpa.w"

Marpa_Rank marpa_g_default_rank(Marpa_Grammar g)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 910 "./marpa.w"

clear_error(g);
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 912 "./marpa.w"

return Default_Rank_of_G(g);
}
/*:90*//*91:*/
#line 917 "./marpa.w"

Marpa_Rank marpa_g_default_rank_set(Marpa_Grammar g,Marpa_Rank rank)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 920 "./marpa.w"

clear_error(g);
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 922 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 923 "./marpa.w"

if(UNLIKELY(rank<MINIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_LOW);
return failure_indicator;
}
if(UNLIKELY(rank> MAXIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_HIGH);
return failure_indicator;
}
return Default_Rank_of_G(g)= rank;
}

/*:91*//*95:*/
#line 942 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 945 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 946 "./marpa.w"

return G_is_Precomputed(g);
}

/*:95*//*98:*/
#line 954 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 957 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 958 "./marpa.w"

return g->t_has_cycle;
}

/*:98*//*112:*/
#line 1034 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:112*//*113:*/
#line 1043 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:113*//*114:*/
#line 1053 "./marpa.w"

Marpa_Event_Type
marpa_g_event(Marpa_Grammar g,Marpa_Event*public_event,
int ix)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1058 "./marpa.w"

DSTACK events= &g->t_events;
GEV internal_event;
int type;

if(ix<0){
MARPA_ERROR(MARPA_ERR_EVENT_IX_NEGATIVE);
return failure_indicator;
}
if(ix>=DSTACK_LENGTH(*events)){
MARPA_ERROR(MARPA_ERR_EVENT_IX_OOB);
return failure_indicator;
}
internal_event= DSTACK_INDEX(*events,GEV_Object,ix);
type= internal_event->t_type;
public_event->t_type= type;
public_event->t_value= internal_event->t_value;
return type;
}

/*:114*//*115:*/
#line 1078 "./marpa.w"

Marpa_Event_Type
marpa_g_event_count(Marpa_Grammar g)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1082 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1083 "./marpa.w"

return DSTACK_LENGTH(g->t_events);
}

/*:115*//*133:*/
#line 1194 "./marpa.w"

Marpa_Error_Code marpa_g_error(Marpa_Grammar g,const char**p_error_string)
{
const Marpa_Error_Code error_code= g->t_error;
const char*error_string= g->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:133*//*134:*/
#line 1205 "./marpa.w"

Marpa_Error_Code
marpa_g_error_clear(Marpa_Grammar g)
{
clear_error(g);
return g->t_error;
}

/*:134*//*140:*/
#line 1235 "./marpa.w"

PRIVATE XSY
symbol_new(GRAMMAR g)
{
XSY xsy= my_obstack_new(g->t_obs,struct s_xsy,1);
/*143:*/
#line 1255 "./marpa.w"
xsy->t_is_start= 0;
/*:143*//*146:*/
#line 1269 "./marpa.w"

xsy->t_rank= Default_Rank_of_G(g);
/*:146*//*150:*/
#line 1315 "./marpa.w"

XSY_is_LHS(xsy)= 0;

/*:150*//*152:*/
#line 1322 "./marpa.w"

XSY_is_Sequence_LHS(xsy)= 0;

/*:152*//*154:*/
#line 1338 "./marpa.w"

XSY_is_Valued(xsy)= 0;
XSY_is_Valued_Locked(xsy)= 0;

/*:154*//*158:*/
#line 1380 "./marpa.w"

xsy->t_is_accessible= 0;
/*:158*//*161:*/
#line 1401 "./marpa.w"

xsy->t_is_counted= 0;
/*:161*//*164:*/
#line 1417 "./marpa.w"

xsy->t_is_nulling= 0;
/*:164*//*167:*/
#line 1434 "./marpa.w"

xsy->t_is_nullable= 0;
/*:167*//*170:*/
#line 1457 "./marpa.w"

xsy->t_is_terminal= 0;
xsy->t_is_locked_terminal= 0;
/*:170*//*175:*/
#line 1502 "./marpa.w"

xsy->t_is_productive= 0;
/*:175*//*178:*/
#line 1521 "./marpa.w"

xsy->t_is_completion_event= 0;
/*:178*//*182:*/
#line 1556 "./marpa.w"

xsy->t_is_nulled_event= 0;
/*:182*//*186:*/
#line 1591 "./marpa.w"

xsy->t_is_prediction_event= 0;
/*:186*//*191:*/
#line 1639 "./marpa.w"

Nulled_XSYIDs_of_XSY(xsy)= NULL;

/*:191*//*194:*/
#line 1655 "./marpa.w"
ISY_of_XSY(xsy)= NULL;
/*:194*//*198:*/
#line 1687 "./marpa.w"
Nulling_ISY_of_XSY(xsy)= NULL;
/*:198*/
#line 1240 "./marpa.w"

symbol_add(g,xsy);
return xsy;
}

/*:140*//*141:*/
#line 1245 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const XSY symbol= symbol_new(g);
return ID_of_XSY(symbol);
}

/*:141*//*144:*/
#line 1256 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1259 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1260 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1261 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1262 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_start;
}

/*:144*//*147:*/
#line 1272 "./marpa.w"

int marpa_g_symbol_rank(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1277 "./marpa.w"

clear_error(g);
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1279 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1280 "./marpa.w"

/*1351:*/
#line 16075 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1351*/
#line 1281 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
return Rank_of_XSY(xsy);
}
/*:147*//*148:*/
#line 1285 "./marpa.w"

int marpa_g_symbol_rank_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,Marpa_Rank rank)
{
XSY xsy;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1290 "./marpa.w"

clear_error(g);
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1292 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 1293 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1294 "./marpa.w"

/*1351:*/
#line 16075 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1351*/
#line 1295 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(UNLIKELY(rank<MINIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_LOW);
return failure_indicator;
}
if(UNLIKELY(rank> MAXIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_HIGH);
return failure_indicator;
}
return Rank_of_XSY(xsy)= rank;
}

/*:148*//*155:*/
#line 1342 "./marpa.w"

int marpa_g_symbol_is_valued(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1347 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1348 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1349 "./marpa.w"

return XSY_is_Valued(XSY_by_ID(xsy_id));
}

/*:155*//*156:*/
#line 1353 "./marpa.w"

int marpa_g_symbol_is_valued_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1358 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1359 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1360 "./marpa.w"

symbol= XSY_by_ID(xsy_id);
if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
if(UNLIKELY(XSY_is_Valued_Locked(symbol)
&&value!=XSY_is_Valued(symbol)))
{
MARPA_ERROR(MARPA_ERR_VALUED_IS_LOCKED);
return failure_indicator;
}
XSY_is_Valued(symbol)= value;
return value;
}

/*:156*//*159:*/
#line 1388 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1391 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1392 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 1393 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1394 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1395 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(xsy_id));
}

/*:159*//*162:*/
#line 1403 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1407 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1408 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1409 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1410 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_counted;
}

/*:162*//*165:*/
#line 1419 "./marpa.w"

int marpa_g_symbol_is_nulling(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1422 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1423 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 1424 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1425 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1426 "./marpa.w"

return XSY_is_Nulling(XSY_by_ID(xsy_id));
}

/*:165*//*168:*/
#line 1436 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1439 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1440 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 1441 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1442 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1443 "./marpa.w"

return XSYID_is_Nullable(xsy_id);
}

/*:168*//*172:*/
#line 1463 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1467 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1468 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1469 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1470 "./marpa.w"

return XSYID_is_Terminal(xsy_id);
}
/*:172*//*173:*/
#line 1473 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1478 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1479 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 1480 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1481 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1482 "./marpa.w"

symbol= XSY_by_ID(xsy_id);
if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
if(UNLIKELY(XSY_is_Locked_Terminal(symbol))
&&XSY_is_Terminal(symbol)!=value)
{
MARPA_ERROR(MARPA_ERR_TERMINAL_IS_LOCKED);
return failure_indicator;
}
XSY_is_Locked_Terminal(symbol)= 1;
return XSY_is_Terminal(symbol)= value;
}

/*:173*//*176:*/
#line 1504 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1509 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1510 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 1511 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1512 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1513 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(xsy_id));
}

/*:176*//*179:*/
#line 1523 "./marpa.w"

int marpa_g_symbol_is_completion_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1527 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1528 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1529 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1530 "./marpa.w"

return XSYID_is_Completion_Event(xsy_id);
}
/*:179*//*180:*/
#line 1533 "./marpa.w"

int marpa_g_symbol_is_completion_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1538 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1539 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 1540 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1541 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1542 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Completion_Event(xsy)= value;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:180*//*183:*/
#line 1558 "./marpa.w"

int marpa_g_symbol_is_nulled_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1562 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1563 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1564 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1565 "./marpa.w"

return XSYID_is_Nulled_Event(xsy_id);
}
/*:183*//*184:*/
#line 1568 "./marpa.w"

int marpa_g_symbol_is_nulled_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1573 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1574 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 1575 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1576 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1577 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Nulled_Event(xsy)= value;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:184*//*187:*/
#line 1593 "./marpa.w"

int marpa_g_symbol_is_prediction_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1597 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1598 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1599 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1600 "./marpa.w"

return XSYID_is_Prediction_Event(xsy_id);
}
/*:187*//*188:*/
#line 1603 "./marpa.w"

int marpa_g_symbol_is_prediction_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1608 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1609 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 1610 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1611 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1612 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Prediction_Event(xsy)= value;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:188*//*189:*/
#line 1622 "./marpa.w"

/*:189*//*195:*/
#line 1656 "./marpa.w"

Marpa_ISY_ID _marpa_g_xsy_isy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
ISY isy;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1663 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1664 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1665 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
isy= ISY_of_XSY(xsy);
return isy?ID_of_ISY(isy):-1;
}

/*:195*//*199:*/
#line 1688 "./marpa.w"

Marpa_ISY_ID _marpa_g_xsy_nulling_isy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
ISY isy;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1695 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 1696 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 1697 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
isy= Nulling_ISY_of_XSY(xsy);
return isy?ID_of_ISY(isy):-1;
}

/*:199*//*201:*/
#line 1709 "./marpa.w"

PRIVATE
ISY symbol_alias_create(GRAMMAR g,XSY symbol)
{
ISY alias_isy= semantic_isy_new(g,symbol);
XSY_is_Nulling(symbol)= 0;
XSY_is_Nullable(symbol)= 1;
ISY_is_Nulling(alias_isy)= 1;
return alias_isy;
}

/*:201*//*208:*/
#line 1757 "./marpa.w"

PRIVATE ISY
isy_start(GRAMMAR g)
{
const ISY isy= my_obstack_new(g->t_obs,struct s_isy,1);
ID_of_ISY(isy)= DSTACK_LENGTH((g)->t_isy_stack);
*DSTACK_PUSH((g)->t_isy_stack,ISY)= isy;
/*206:*/
#line 1752 "./marpa.w"

isy->t_or_node_type= NULLING_TOKEN_OR_NODE;

/*:206*//*216:*/
#line 1825 "./marpa.w"
ISY_is_Start(isy)= 0;
/*:216*//*219:*/
#line 1839 "./marpa.w"
ISY_is_LHS(isy)= 0;
/*:219*//*222:*/
#line 1853 "./marpa.w"
ISY_is_Nulling(isy)= 0;
/*:222*//*225:*/
#line 1870 "./marpa.w"
ISY_is_Semantic(isy)= 0;
/*:225*//*228:*/
#line 1891 "./marpa.w"
Source_XSY_of_ISY(isy)= NULL;
/*:228*//*232:*/
#line 1916 "./marpa.w"

LHS_XRL_of_ISY(isy)= NULL;
XRL_Offset_of_ISY(isy)= -1;

/*:232*//*237:*/
#line 1967 "./marpa.w"

Rank_of_ISY(isy)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:237*/
#line 1764 "./marpa.w"

return isy;
}

/*:208*//*209:*/
#line 1770 "./marpa.w"

PRIVATE ISY
isy_new(GRAMMAR g,XSY source)
{
const ISY new_isy= isy_start(g);
Source_XSY_of_ISY(new_isy)= source;
Rank_of_ISY(new_isy)= ISY_Rank_by_XSY(source);
return new_isy;
}

/*:209*//*210:*/
#line 1782 "./marpa.w"

PRIVATE ISY
semantic_isy_new(GRAMMAR g,XSY source)
{
const ISY new_isy= isy_new(g,source);
ISY_is_Semantic(new_isy)= 1;
return new_isy;
}

/*:210*//*211:*/
#line 1793 "./marpa.w"

PRIVATE ISY
isy_clone(GRAMMAR g,XSY xsy)
{
const ISY new_isy= isy_start(g);
Source_XSY_of_ISY(new_isy)= xsy;
ISY_is_Semantic(new_isy)= 1;
Rank_of_ISY(new_isy)= ISY_Rank_by_XSY(xsy);
ISY_is_Nulling(new_isy)= XSY_is_Nulling(xsy);
return new_isy;
}

/*:211*//*214:*/
#line 1815 "./marpa.w"

int _marpa_g_isy_count(Marpa_Grammar g){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1817 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1818 "./marpa.w"

return ISY_Count_of_G(g);
}

/*:214*//*217:*/
#line 1826 "./marpa.w"

int _marpa_g_isy_is_start(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1829 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1830 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 1831 "./marpa.w"

/*1352:*/
#line 16080 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1352*/
#line 1832 "./marpa.w"

return ISY_is_Start(ISY_by_ID(isy_id));
}

/*:217*//*220:*/
#line 1840 "./marpa.w"

int _marpa_g_isy_is_lhs(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1843 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1844 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 1845 "./marpa.w"

/*1352:*/
#line 16080 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1352*/
#line 1846 "./marpa.w"

return ISY_is_LHS(ISY_by_ID(isy_id));
}

/*:220*//*223:*/
#line 1854 "./marpa.w"

int _marpa_g_isy_is_nulling(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1857 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 1858 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 1859 "./marpa.w"

/*1352:*/
#line 16080 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1352*/
#line 1860 "./marpa.w"

return ISY_is_Nulling(ISY_by_ID(isy_id));
}

/*:223*//*226:*/
#line 1871 "./marpa.w"

int _marpa_g_isy_is_semantic(
Marpa_Grammar g,
Marpa_IRL_ID isy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1876 "./marpa.w"

/*1352:*/
#line 16080 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1352*/
#line 1877 "./marpa.w"

return ISYID_is_Semantic(isy_id);
}

/*:226*//*229:*/
#line 1892 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_IRL_ID isy_id)
{
XSY source_xsy;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1898 "./marpa.w"

/*1352:*/
#line 16080 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1352*/
#line 1899 "./marpa.w"

source_xsy= Source_XSY_of_ISYID(isy_id);
return ID_of_XSY(source_xsy);
}

/*:229*//*234:*/
#line 1927 "./marpa.w"

Marpa_Rule_ID _marpa_g_isy_lhs_xrl(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1930 "./marpa.w"

/*1352:*/
#line 16080 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1352*/
#line 1931 "./marpa.w"

{
const ISY isy= ISY_by_ID(isy_id);
const XRL lhs_xrl= LHS_XRL_of_ISY(isy);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:234*//*235:*/
#line 1951 "./marpa.w"

int _marpa_g_isy_xrl_offset(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1954 "./marpa.w"

ISY isy;
/*1352:*/
#line 16080 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1352*/
#line 1956 "./marpa.w"

isy= ISY_by_ID(isy_id);
return XRL_Offset_of_ISY(isy);
}

/*:235*//*238:*/
#line 1969 "./marpa.w"

Marpa_Rank _marpa_g_isy_rank(
Marpa_Grammar g,
Marpa_ISY_ID isy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1974 "./marpa.w"

/*1352:*/
#line 16080 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1352*/
#line 1975 "./marpa.w"

return Rank_of_ISY(ISY_by_ID(isy_id));
}

/*:238*//*244:*/
#line 2010 "./marpa.w"

PRIVATE
XRL xrl_start(GRAMMAR g,const XSYID lhs,const XSYID*rhs,int length)
{
XRL xrl;
const int sizeof_xrl= offsetof(struct s_xrl,t_symbols)+
(length+1)*sizeof(xrl->t_symbols[0]);
my_obstack_reserve(g->t_xrl_obs,sizeof_xrl);
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
/*263:*/
#line 2353 "./marpa.w"

rule->t_rank= Default_Rank_of_G(g);
/*:263*//*267:*/
#line 2401 "./marpa.w"

rule->t_null_ranks_high= 0;
/*:267*//*271:*/
#line 2441 "./marpa.w"

rule->t_is_bnf= 0;

/*:271*//*273:*/
#line 2447 "./marpa.w"

rule->t_is_sequence= 0;

/*:273*//*275:*/
#line 2461 "./marpa.w"

rule->t_minimum= -1;
/*:275*//*278:*/
#line 2486 "./marpa.w"

Separator_of_XRL(rule)= -1;
/*:278*//*283:*/
#line 2519 "./marpa.w"

rule->t_is_discard= 0;
/*:283*//*287:*/
#line 2559 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:287*//*291:*/
#line 2580 "./marpa.w"

rule->t_is_loop= 0;
/*:291*//*294:*/
#line 2597 "./marpa.w"

XRL_is_Nulling(rule)= 0;
/*:294*//*297:*/
#line 2615 "./marpa.w"

XRL_is_Nullable(rule)= 0;
/*:297*//*301:*/
#line 2633 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:301*//*304:*/
#line 2651 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:304*//*307:*/
#line 2670 "./marpa.w"

XRL_is_Used(rule)= 0;
/*:307*/
#line 2035 "./marpa.w"

rule_add(g,rule);
return rule;
}

PRIVATE_NOT_INLINE
RULE rule_new(GRAMMAR g,
const XSYID lhs,const XSYID*rhs,int length)
{
RULE rule= xrl_start(g,lhs,rhs,length);
xrl_finish(g,rule);
rule= my_obstack_finish(g->t_xrl_obs);
return rule;
}

/*:244*//*245:*/
#line 2051 "./marpa.w"

PRIVATE IRL
irl_start(GRAMMAR g,int length)
{
IRL irl;
const int sizeof_irl= offsetof(struct s_irl,t_isyid_array)+
(length+1)*sizeof(irl->t_isyid_array[0]);
irl= my_obstack_alloc(g->t_obs,sizeof_irl);
ID_of_IRL(irl)= DSTACK_LENGTH((g)->t_irl_stack);
Length_of_IRL(irl)= length;
/*327:*/
#line 2798 "./marpa.w"

IRL_has_Virtual_LHS(irl)= 0;
/*:327*//*330:*/
#line 2814 "./marpa.w"

IRL_has_Virtual_RHS(irl)= 0;
/*:330*//*333:*/
#line 2830 "./marpa.w"

IRL_is_Right_Recursive(irl)= 0;

/*:333*//*336:*/
#line 2841 "./marpa.w"
Real_SYM_Count_of_IRL(irl)= 0;
/*:336*//*339:*/
#line 2859 "./marpa.w"
irl->t_virtual_start= -1;
/*:339*//*342:*/
#line 2879 "./marpa.w"
irl->t_virtual_end= -1;
/*:342*//*345:*/
#line 2901 "./marpa.w"
Source_XRL_of_IRL(irl)= NULL;
/*:345*//*348:*/
#line 2928 "./marpa.w"

Rank_of_IRL(irl)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:348*//*351:*/
#line 2949 "./marpa.w"

First_AIM_of_IRL(irl)= NULL;

/*:351*//*355:*/
#line 2968 "./marpa.w"

Last_Proper_SYMI_of_IRL(irl)= -1;
/*:355*/
#line 2061 "./marpa.w"

*DSTACK_PUSH((g)->t_irl_stack,IRL)= irl;
return irl;
}

PRIVATE void
irl_finish(GRAMMAR g,IRL irl)
{
const ISY lhs_isy= LHS_of_IRL(irl);
ISY_is_LHS(lhs_isy)= 1;
}

/*:245*//*247:*/
#line 2087 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,int length)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2092 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2095 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 2096 "./marpa.w"

if(UNLIKELY(length> MAX_RHS_LENGTH))
{
MARPA_ERROR(MARPA_ERR_RHS_TOO_LONG);
return failure_indicator;
}
if(UNLIKELY(!xsy_id_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
{
int rh_index;
for(rh_index= 0;rh_index<length;rh_index++)
{
const XSYID rhs_id= rhs_ids[rh_index];
if(UNLIKELY(!xsy_id_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
}
}
{
const XSY lhs= XSY_by_ID(lhs_id);
if(UNLIKELY(XSY_is_Sequence_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
return failure_indicator;
}
}
rule= xrl_start(g,lhs_id,rhs_ids,length);
if(UNLIKELY(_marpa_avl_insert(g->t_xrl_tree,rule)!=NULL))
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
my_obstack_reject(g->t_xrl_obs);
return failure_indicator;
}
rule= xrl_finish(g,rule);
rule= my_obstack_finish(g->t_xrl_obs);
XRL_is_BNF(rule)= 1;
rule_id= rule->t_id;
return rule_id;
}

/*:247*//*248:*/
#line 2141 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2148 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2149 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 2150 "./marpa.w"

/*250:*/
#line 2181 "./marpa.w"

{
if(separator_id!=-1)
{
if(UNLIKELY(!xsy_id_is_valid(g,separator_id)))
{
MARPA_ERROR(MARPA_ERR_BAD_SEPARATOR);
goto FAILURE;
}
}
if(UNLIKELY(!xsy_id_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
goto FAILURE;
}
{
const XSY lhs= XSY_by_ID(lhs_id);
if(UNLIKELY(XSY_is_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
goto FAILURE;
}
}
if(UNLIKELY(!xsy_id_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
goto FAILURE;
}
}

/*:250*/
#line 2151 "./marpa.w"

/*249:*/
#line 2159 "./marpa.w"

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
XSY_is_Sequence_LHS(XSY_by_ID(lhs_id))= 1;
XSY_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0)
{
XSY_by_ID(separator_id)->t_is_counted= 1;
}
}

/*:249*/
#line 2152 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:248*//*252:*/
#line 2234 "./marpa.w"

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

/*:252*//*255:*/
#line 2289 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:255*//*256:*/
#line 2293 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2295 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2296 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2297 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2298 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:256*//*257:*/
#line 2301 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:257*//*258:*/
#line 2305 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2308 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2309 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2310 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2311 "./marpa.w"

rule= XRL_by_ID(xrl_id);
if(ix<0){
MARPA_ERROR(MARPA_ERR_RHS_IX_NEGATIVE);
return failure_indicator;
}
if(Length_of_XRL(rule)<=ix){
MARPA_ERROR(MARPA_ERR_RHS_IX_OOB);
return failure_indicator;
}
return RHS_ID_of_RULE(rule,ix);
}

/*:258*//*259:*/
#line 2324 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2326 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2327 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2328 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2329 "./marpa.w"

return Length_of_XRL(XRL_by_ID(xrl_id));
}

/*:259*//*264:*/
#line 2356 "./marpa.w"

int marpa_g_rule_rank(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2361 "./marpa.w"

clear_error(g);
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2363 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2364 "./marpa.w"

/*1355:*/
#line 16098 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1355*/
#line 2365 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Rank_of_XRL(xrl);
}
/*:264*//*265:*/
#line 2369 "./marpa.w"

int marpa_g_rule_rank_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,Marpa_Rank rank)
{
XRL xrl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2374 "./marpa.w"

clear_error(g);
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2376 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 2377 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2378 "./marpa.w"

/*1355:*/
#line 16098 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1355*/
#line 2379 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(UNLIKELY(rank<MINIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_LOW);
return failure_indicator;
}
if(UNLIKELY(rank> MAXIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_HIGH);
return failure_indicator;
}
return Rank_of_XRL(xrl)= rank;
}

/*:265*//*268:*/
#line 2405 "./marpa.w"

int marpa_g_rule_null_high(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2410 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2411 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2412 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2413 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Null_Ranks_High_of_RULE(xrl);
}
/*:268*//*269:*/
#line 2417 "./marpa.w"

int marpa_g_rule_null_high_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,int flag)
{
XRL xrl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2422 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2423 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 2424 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2425 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2426 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(UNLIKELY(flag<0||flag> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return Null_Ranks_High_of_RULE(xrl)= flag;
}

/*:269*//*276:*/
#line 2463 "./marpa.w"

int marpa_g_sequence_min(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2468 "./marpa.w"

XRL xrl;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2470 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2471 "./marpa.w"

/*1355:*/
#line 16098 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1355*/
#line 2472 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Minimum_of_XRL(xrl);
}

/*:276*//*279:*/
#line 2488 "./marpa.w"

Marpa_Symbol_ID marpa_g_sequence_separator(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2493 "./marpa.w"

XRL xrl;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2495 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2496 "./marpa.w"

/*1355:*/
#line 16098 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1355*/
#line 2497 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Separator_of_XRL(xrl);
}

/*:279*//*284:*/
#line 2521 "./marpa.w"

int _marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2526 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2527 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2528 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2529 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:284*//*288:*/
#line 2561 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2566 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2567 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2568 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2569 "./marpa.w"

return!XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:288*//*292:*/
#line 2582 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2585 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2586 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2587 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2588 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 2589 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:292*//*295:*/
#line 2599 "./marpa.w"

int marpa_g_rule_is_nulling(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2602 "./marpa.w"

XRL xrl;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2604 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2605 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2606 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nulling(xrl);
}

/*:295*//*298:*/
#line 2617 "./marpa.w"

int marpa_g_rule_is_nullable(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2620 "./marpa.w"

XRL xrl;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2622 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2623 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2624 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nullable(xrl);
}

/*:298*//*302:*/
#line 2635 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2638 "./marpa.w"

XRL xrl;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2640 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2641 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2642 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:302*//*305:*/
#line 2653 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2656 "./marpa.w"

XRL xrl;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2658 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2659 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2660 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:305*//*308:*/
#line 2672 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2676 "./marpa.w"

/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 2677 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 2678 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:308*//*310:*/
#line 2685 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2690 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2691 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:310*//*319:*/
#line 2730 "./marpa.w"

Marpa_ISY_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
IRL irl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2733 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2734 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 2735 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2736 "./marpa.w"

irl= IRL_by_ID(irl_id);
return LHSID_of_IRL(irl);
}

/*:319*//*321:*/
#line 2743 "./marpa.w"

Marpa_ISY_ID _marpa_g_irl_rhs(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2746 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2747 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 2748 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2749 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHSID_of_IRL(irl,ix);
}

/*:321*//*323:*/
#line 2757 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2759 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 2760 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 2761 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2762 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}

/*:323*//*328:*/
#line 2800 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2805 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 2806 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2807 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:328*//*331:*/
#line 2816 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2821 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 2822 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2823 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:331*//*337:*/
#line 2842 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2847 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 2848 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2849 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:337*//*340:*/
#line 2860 "./marpa.w"

unsigned int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2866 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 2867 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2868 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:340*//*343:*/
#line 2880 "./marpa.w"

unsigned int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2886 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 2887 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2888 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:343*//*346:*/
#line 2902 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2908 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2909 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:346*//*349:*/
#line 2930 "./marpa.w"

Marpa_Rank _marpa_g_irl_rank(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2935 "./marpa.w"

/*1353:*/
#line 16085 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1353*/
#line 2936 "./marpa.w"

return Rank_of_IRL(IRL_by_ID(irl_id));
}

/*:349*//*357:*/
#line 2982 "./marpa.w"

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

/*:357*//*359:*/
#line 3014 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 3017 "./marpa.w"

int return_value= failure_indicator;
struct obstack*obs_precompute= my_obstack_init;
/*362:*/
#line 3121 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);

/*:362*//*366:*/
#line 3154 "./marpa.w"

XSYID start_xsy_id= g->t_start_xsy_id;

/*:366*//*378:*/
#line 3444 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:378*/
#line 3020 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 3021 "./marpa.w"

G_EVENTS_CLEAR(g);
/*363:*/
#line 3125 "./marpa.w"

if(UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
goto FAILURE;
}

/*:363*/
#line 3023 "./marpa.w"

/*1347:*/
#line 16052 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1347*/
#line 3024 "./marpa.w"

/*365:*/
#line 3135 "./marpa.w"

{
if(UNLIKELY(start_xsy_id<0))
{
MARPA_ERROR(MARPA_ERR_NO_START_SYMBOL);
goto FAILURE;
}
if(UNLIKELY(!xsy_id_is_valid(g,start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_START_SYMBOL);
goto FAILURE;
}
if(UNLIKELY(!XSY_is_LHS(XSY_by_ID(start_xsy_id))))
{
MARPA_ERROR(MARPA_ERR_START_NOT_LHS);
goto FAILURE;
}
}

/*:365*/
#line 3025 "./marpa.w"




/*118:*/
#line 1094 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:118*/
#line 3029 "./marpa.w"


{
/*371:*/
#line 3329 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:371*//*372:*/
#line 3332 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;
RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:372*//*376:*/
#line 3393 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:376*/
#line 3032 "./marpa.w"

/*361:*/
#line 3104 "./marpa.w"

{
/*369:*/
#line 3178 "./marpa.w"

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
const int rule_length= Length_of_XRL(rule);
const int is_sequence= XRL_is_Sequence(rule);

bv_bit_set(lhs_v,(unsigned int)lhs_id);


p_lh_sym_rule_pairs->t_symid= lhs_id;
p_lh_sym_rule_pairs->t_ruleid= rule_id;
_marpa_avl_insert(lhs_avl_tree,p_lh_sym_rule_pairs);
p_lh_sym_rule_pairs++;

if(is_sequence)
{
const XSYID separator_id= Separator_of_XRL(rule);
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
XSYID seen_symid= -1;
RULEID*const rule_data_base= 
my_obstack_new(obs_precompute,RULEID,External_Size_of_G(g));
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(rhs_avl_tree);

xrl_list_x_rh_sym= my_obstack_new(obs_precompute,RULEID*,pre_census_xsy_count+1);
for(pair= _marpa_avl_t_first(traverser);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(traverser))
{
const XSYID current_symid= pair->t_symid;
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
XSYID seen_symid= -1;
RULEID*const rule_data_base= 
my_obstack_new(obs_precompute,RULEID,xrl_count);
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(lhs_avl_tree);

xrl_list_x_lh_sym= 
my_obstack_new(obs_precompute,RULEID*,pre_census_xsy_count+1);
for(pair= _marpa_avl_t_first(traverser);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(traverser))
{
const XSYID current_symid= pair->t_symid;
while(seen_symid<current_symid)
xrl_list_x_lh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(++seen_symid<=pre_census_xsy_count)
xrl_list_x_lh_sym[seen_symid]= p_rule_data;
_marpa_avl_destroy(lhs_avl_tree);
}

}

/*:369*/
#line 3106 "./marpa.w"

/*370:*/
#line 3300 "./marpa.w"

{
XSYID symid;
terminal_v= bv_obs_create(obs_precompute,pre_census_xsy_count);
bv_not(terminal_v,lhs_v);
for(symid= 0;symid<pre_census_xsy_count;symid++)
{
XSY symbol= XSY_by_ID(symid);


if(XSY_is_Locked_Terminal(symbol))
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

/*:370*/
#line 3107 "./marpa.w"

/*377:*/
#line 3415 "./marpa.w"

{
XRLID rule_id;
reach_matrix= matrix_obs_create(obs_precompute,pre_census_xsy_count,pre_census_xsy_count);
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule= XRL_by_ID(rule_id);
XSYID lhs_id= LHS_ID_of_RULE(rule);
unsigned int rhs_ix,rule_length= Length_of_XRL(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
matrix_bit_set(reach_matrix,
(unsigned int)lhs_id,
(unsigned int)RHS_ID_of_RULE(rule,rhs_ix));
}
if(XRL_is_Sequence(rule))
{
const XSYID separator_id= Separator_of_XRL(rule);
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

/*:377*/
#line 3108 "./marpa.w"

/*373:*/
#line 3338 "./marpa.w"

{
unsigned int min,max,start;
XSYID xsy_id;
int counted_nullables= 0;
nullable_v= bv_obs_clone(obs_precompute,empty_lhs_v);
rhs_closure(g,nullable_v,xrl_list_x_rh_sym);
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2)
{
for(xsy_id= (XSYID)min;xsy_id<=(XSYID)max;
xsy_id++)
{
XSY xsy= XSY_by_ID(xsy_id);
XSY_is_Nullable(xsy)= 1;
if(UNLIKELY(xsy->t_is_counted))
{
counted_nullables++;
int_event_new(g,MARPA_EVENT_COUNTED_NULLABLE,xsy_id);
}
}
}
if(UNLIKELY(counted_nullables))
{
MARPA_ERROR(MARPA_ERR_COUNTED_NULLABLE);
goto FAILURE;
}
}

/*:373*/
#line 3109 "./marpa.w"

/*374:*/
#line 3366 "./marpa.w"

{
productive_v= bv_obs_shadow(obs_precompute,nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v,xrl_list_x_rh_sym);
{
unsigned int min,max,start;
XSYID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);
start= max+2)
{
for(symid= (XSYID)min;
symid<=(XSYID)max;symid++)
{
XSY symbol= XSY_by_ID(symid);
symbol->t_is_productive= 1;
}
}
}
}

/*:374*/
#line 3110 "./marpa.w"

/*375:*/
#line 3387 "./marpa.w"

if(UNLIKELY(!bv_bit_test(productive_v,(unsigned int)start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:375*/
#line 3111 "./marpa.w"

/*379:*/
#line 3449 "./marpa.w"

{
Bit_Vector accessible_v= 
matrix_row(reach_matrix,(unsigned int)start_xsy_id);
unsigned int min,max,start;
XSYID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2)
{
for(symid= (XSYID)min;
symid<=(XSYID)max;symid++)
{
XSY symbol= XSY_by_ID(symid);
symbol->t_is_accessible= 1;
}
}
XSY_by_ID(start_xsy_id)->t_is_accessible= 1;
}

/*:379*/
#line 3112 "./marpa.w"

/*380:*/
#line 3469 "./marpa.w"

{
Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
int nulling_terminal_found= 0;
unsigned int min,max,start;
for(start= 0;bv_scan(lhs_v,start,&min,&max);start= max+2)
{
XSYID productive_id;
for(productive_id= (XSYID)min;
productive_id<=(XSYID)max;productive_id++)
{
bv_and(reaches_terminal_v,terminal_v,
matrix_row(reach_matrix,(unsigned int)productive_id));
if(bv_is_empty(reaches_terminal_v))
{
const XSY symbol= XSY_by_ID(productive_id);
XSY_is_Nulling(symbol)= 1;
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
goto FAILURE;
}
}

/*:380*/
#line 3113 "./marpa.w"

/*381:*/
#line 3508 "./marpa.w"

{
XRLID xrl_id;
for(xrl_id= 0;xrl_id<xrl_count;xrl_id++)
{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID lhs_id= LHS_ID_of_XRL(xrl);
const XSY lhs= XSY_by_ID(lhs_id);
XRL_is_Accessible(xrl)= XSY_is_Accessible(lhs);
if(XRL_is_Sequence(xrl))
{
/*383:*/
#line 3559 "./marpa.w"

{
const XSYID rhs_id= RHS_ID_of_XRL(xrl,0);
const XSY rh_xsy= XSY_by_ID(rhs_id);
const XSYID separator_id= Separator_of_XRL(xrl);



XRL_is_Nullable(xrl)= Minimum_of_XRL(xrl)<=0
||XSY_is_Nullable(rh_xsy);


XRL_is_Nulling(xrl)= XSY_is_Nulling(rh_xsy);


XRL_is_Productive(xrl)= XRL_is_Nullable(xrl)||XSY_is_Productive(rh_xsy);


XRL_is_Used(xrl)= XRL_is_Accessible(xrl)&&XSY_is_Productive(rh_xsy);


if(separator_id>=0)
{
const XSY separator_xsy= XSY_by_ID(separator_id);

if(!XSY_is_Nulling(separator_xsy))
{
XRL_is_Nulling(xrl)= 0;
}



if(UNLIKELY(!XSY_is_Productive(separator_xsy)))
{
XRL_is_Productive(xrl)= XRL_is_Nullable(xrl);


XRL_is_Used(xrl)= 0;
}
}


if(XRL_is_Nulling(xrl))XRL_is_Used(xrl)= 0;
}

/*:383*/
#line 3519 "./marpa.w"

continue;
}
/*382:*/
#line 3528 "./marpa.w"

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
XRL_is_Used(xrl)= XRL_is_Accessible(xrl)&&XRL_is_Productive(xrl)
&&!XRL_is_Nulling(xrl);
}

/*:382*/
#line 3522 "./marpa.w"

}
}

/*:381*/
#line 3114 "./marpa.w"

/*384:*/
#line 3613 "./marpa.w"

if(0)
{



XSYID xsy_id;
for(xsy_id= 0;xsy_id<pre_census_xsy_count;xsy_id++)
{
if(bv_bit_test(terminal_v,xsy_id)&&bv_bit_test(lhs_v,xsy_id))
{
const XSY xsy= XSY_by_ID(xsy_id);
if(XSY_is_Valued_Locked(xsy))
continue;
XSY_is_Valued(xsy)= 1;
XSY_is_Valued_Locked(xsy)= 1;
}
}
}

/*:384*/
#line 3115 "./marpa.w"

if(1){
/*385:*/
#line 3641 "./marpa.w"

{
XSYID xsyid;
XRLID xrlid;
int nullable_xsy_count= 0;

void*matrix_buffer= my_malloc(matrix_sizeof(
(unsigned int)pre_census_xsy_count,
(unsigned int)pre_census_xsy_count));

Bit_Matrix nullification_matrix= 
matrix_buffer_create(matrix_buffer,(unsigned int)pre_census_xsy_count,
(unsigned int)pre_census_xsy_count);
for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++)
{
if(!XSYID_is_Nullable(xsyid))
continue;
nullable_xsy_count++;
matrix_bit_set(nullification_matrix,(unsigned int)xsyid,
(unsigned int)xsyid);
}
for(xrlid= 0;xrlid<xrl_count;xrlid++)
{
int rh_ix;
XRL xrl= XRL_by_ID(xrlid);
const XSYID lhs_id= LHS_ID_of_XRL(xrl);
if(XRL_is_Nullable(xrl))
{
for(rh_ix= 0;rh_ix<Length_of_XRL(xrl);rh_ix++)
{
const XSYID rhs_id= RHS_ID_of_XRL(xrl,rh_ix);
matrix_bit_set(nullification_matrix,(unsigned int)lhs_id,
(unsigned int)rhs_id);
}
}
}
transitive_closure(nullification_matrix);
for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++)
{
Bit_Vector bv_nullifications_by_to_xsy= 
matrix_row(nullification_matrix,(unsigned long)xsyid);
Nulled_XSYIDs_of_XSYID(xsyid)= 
cil_bv_add(&g->t_cilar,bv_nullifications_by_to_xsy);
}
my_free(matrix_buffer);
}

/*:385*/
#line 3117 "./marpa.w"

}
}

/*:361*/
#line 3033 "./marpa.w"

/*432:*/
#line 4486 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,(unsigned int)xrl_count,
(unsigned int)xrl_count);
/*433:*/
#line 4507 "./marpa.w"

{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule= XRL_by_ID(rule_id);
XSYID nonnulling_id= -1;
int nonnulling_count= 0;
int rhs_ix,rule_length;
rule_length= Length_of_XRL(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
XSYID xsy_id= RHS_ID_of_RULE(rule,rhs_ix);
if(bv_bit_test(nullable_v,xsy_id))
continue;
nonnulling_id= xsy_id;
nonnulling_count++;
}
if(nonnulling_count==1)
{
/*434:*/
#line 4550 "./marpa.w"

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

/*:434*/
#line 4528 "./marpa.w"

}
else if(nonnulling_count==0)
{
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
nonnulling_id= RHS_ID_of_RULE(rule,rhs_ix);
if(!bv_bit_test(nullable_v,nonnulling_id))
continue;
if(XSY_is_Nulling(XSY_by_ID(nonnulling_id)))
continue;

/*434:*/
#line 4550 "./marpa.w"

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

/*:434*/
#line 4541 "./marpa.w"

}
}
}
}

/*:433*/
#line 4492 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*435:*/
#line 4564 "./marpa.w"

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

/*:435*/
#line 4494 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:432*/
#line 3034 "./marpa.w"

}


/*549:*/
#line 5826 "./marpa.w"

DSTACK_INIT(g->t_irl_stack,IRL,2*DSTACK_CAPACITY(g->t_xrl_stack));

/*:549*/
#line 3038 "./marpa.w"

/*550:*/
#line 5834 "./marpa.w"

{
DSTACK_INIT(g->t_isy_stack,ISY,2*DSTACK_CAPACITY(g->t_xsy_stack));
}

/*:550*/
#line 3039 "./marpa.w"

/*397:*/
#line 3836 "./marpa.w"

{
/*398:*/
#line 3867 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:398*//*401:*/
#line 3925 "./marpa.w"

int factor_count;
int*factor_positions;
/*:401*/
#line 3838 "./marpa.w"

/*402:*/
#line 3928 "./marpa.w"

factor_positions= my_obstack_new(obs_precompute,int,g->t_max_rule_length);

/*:402*/
#line 3839 "./marpa.w"

/*399:*/
#line 3873 "./marpa.w"

{
XSYID xsy_id;
for(xsy_id= 0;xsy_id<pre_census_xsy_count;xsy_id++)
{
const XSY xsy_to_clone= XSY_by_ID(xsy_id);
if(UNLIKELY(!xsy_to_clone->t_is_accessible))
continue;
if(UNLIKELY(!xsy_to_clone->t_is_productive))
continue;
ISY_of_XSY(xsy_to_clone)= isy_clone(g,xsy_to_clone);
if(XSY_is_Nulling(xsy_to_clone))
{
Nulling_ISY_of_XSY(xsy_to_clone)= ISY_of_XSY(xsy_to_clone);
continue;
}
if(XSY_is_Nullable(xsy_to_clone))
{
Nulling_ISY_of_XSY(xsy_to_clone)= symbol_alias_create(g,xsy_to_clone);
}
}
}

/*:399*/
#line 3840 "./marpa.w"

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
/*386:*/
#line 3689 "./marpa.w"

{
const XSYID lhs_id= LHS_ID_of_RULE(rule);
const ISY lhs_isy= ISY_by_XSYID(lhs_id);
const ISYID lhs_isyid= ID_of_ISY(lhs_isy);

const ISY internal_lhs_isy= isy_new(g,XSY_by_ID(lhs_id));
const ISYID internal_lhs_isyid= ID_of_ISY(internal_lhs_isy);

const XSYID rhs_id= RHS_ID_of_RULE(rule,0);
const ISY rhs_isy= ISY_by_XSYID(rhs_id);
const ISYID rhs_isyid= ID_of_ISY(rhs_isy);

const XSYID separator_id= Separator_of_XRL(rule);
ISYID separator_isyid= -1;
if(separator_id>=0){
const ISY separator_isy= ISY_by_XSYID(separator_id);
separator_isyid= ID_of_ISY(separator_isy);
}

LHS_XRL_of_ISY(internal_lhs_isy)= rule;
/*387:*/
#line 3718 "./marpa.w"

{
IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= lhs_isyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_isyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);

IRL_has_Virtual_RHS(rewrite_irl)= 1;
}

/*:387*/
#line 3710 "./marpa.w"

if(separator_isyid>=0&&!XRL_is_Proper_Separation(rule)){
/*388:*/
#line 3731 "./marpa.w"

{
IRL rewrite_irl;
rewrite_irl= irl_start(g,2);
LHSID_of_IRL(rewrite_irl)= lhs_isyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_isyid;
RHSID_of_IRL(rewrite_irl,1)= separator_isyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);
IRL_has_Virtual_RHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= 1;
}

/*:388*/
#line 3712 "./marpa.w"

}
/*389:*/
#line 3748 "./marpa.w"

{
const IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= internal_lhs_isyid;
RHSID_of_IRL(rewrite_irl,0)= rhs_isyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);
IRL_has_Virtual_LHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= 1;
}
/*:389*/
#line 3714 "./marpa.w"

/*390:*/
#line 3759 "./marpa.w"

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
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);
IRL_has_Virtual_LHS(rewrite_irl)= 1;
IRL_has_Virtual_RHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= length-1;
}

/*:390*/
#line 3715 "./marpa.w"

}

/*:386*/
#line 3853 "./marpa.w"

continue;
}
/*400:*/
#line 3904 "./marpa.w"

{
int rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rewrite_xrl_length;rhs_ix++)
{
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
XSY symbol= XSY_by_ID(symid);
if(XSY_is_Nulling(symbol))
continue;
if(XSY_is_Nullable(symbol))
{

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}
}
/*:400*/
#line 3856 "./marpa.w"


if(factor_count> 0)
{
/*403:*/
#line 3932 "./marpa.w"

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
/*406:*/
#line 3968 "./marpa.w"

ISY chaf_virtual_isy;
ISYID chaf_virtual_isyid;
int first_factor_position= factor_positions[factor_position_ix];
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*404:*/
#line 3958 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_isy= isy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_isyid= ID_of_ISY(chaf_virtual_isy);
}

/*:404*/
#line 3976 "./marpa.w"

/*407:*/
#line 3995 "./marpa.w"

{
{
const int real_symbol_count= piece_end-piece_start+1;
/*412:*/
#line 4093 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4107 "./marpa.w"

}

/*:412*/
#line 3999 "./marpa.w"
;
}
/*408:*/
#line 4009 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,2);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4031 "./marpa.w"

}

/*:408*/
#line 4001 "./marpa.w"
;
{
const int real_symbol_count= piece_end-piece_start+1;
/*414:*/
#line 4139 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,1);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4163 "./marpa.w"

}

/*:414*/
#line 4004 "./marpa.w"
;
}
/*409:*/
#line 4039 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4077 "./marpa.w"

}
}

/*:409*/
#line 4006 "./marpa.w"
;
}

/*:407*/
#line 3977 "./marpa.w"

factor_position_ix++;
}else{
piece_end= second_factor_position;
/*404:*/
#line 3958 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_isy= isy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_isyid= ID_of_ISY(chaf_virtual_isy);
}

/*:404*/
#line 3981 "./marpa.w"

/*411:*/
#line 4083 "./marpa.w"

{
const int real_symbol_count= piece_end-piece_start+1;
/*412:*/
#line 4093 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4107 "./marpa.w"

}

/*:412*/
#line 4086 "./marpa.w"

/*413:*/
#line 4111 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,2);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4135 "./marpa.w"

}

/*:413*/
#line 4087 "./marpa.w"

/*414:*/
#line 4139 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,1);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4163 "./marpa.w"

}

/*:414*/
#line 4088 "./marpa.w"

/*415:*/
#line 4167 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4201 "./marpa.w"

}

/*:415*/
#line 4089 "./marpa.w"

}

/*:411*/
#line 3982 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_isy= chaf_virtual_isy;
current_lhs_isyid= chaf_virtual_isyid;
piece_start= piece_end+1;

/*:406*/
#line 3949 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*416:*/
#line 4206 "./marpa.w"

{
const int first_factor_position= factor_positions[factor_position_ix];
const int second_factor_position= factor_positions[factor_position_ix+1];
const int real_symbol_count= Length_of_XRL(rule)-piece_start;
piece_end= Length_of_XRL(rule)-1;
/*417:*/
#line 4219 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4232 "./marpa.w"

}

/*:417*/
#line 4212 "./marpa.w"

/*418:*/
#line 4236 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,2);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4259 "./marpa.w"

}

/*:418*/
#line 4213 "./marpa.w"

/*419:*/
#line 4263 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,1);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4286 "./marpa.w"

}

/*:419*/
#line 4214 "./marpa.w"

/*420:*/
#line 4291 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4326 "./marpa.w"

}
}

/*:420*/
#line 4215 "./marpa.w"

}

/*:416*/
#line 3952 "./marpa.w"

}else{
/*421:*/
#line 4331 "./marpa.w"

{
int real_symbol_count;
const int first_factor_position= factor_positions[factor_position_ix];
piece_end= Length_of_XRL(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*422:*/
#line 4342 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4355 "./marpa.w"

}

/*:422*/
#line 4337 "./marpa.w"

/*423:*/
#line 4360 "./marpa.w"

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
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*424:*/
#line 4394 "./marpa.w"

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

/*:424*/
#line 4386 "./marpa.w"

}
}

/*:423*/
#line 4338 "./marpa.w"

}

/*:421*/
#line 3954 "./marpa.w"

}
}

/*:403*/
#line 3860 "./marpa.w"

continue;
}
/*246:*/
#line 2073 "./marpa.w"

{
int symbol_ix;
const IRL new_irl= irl_start(g,rewrite_xrl_length);
Source_XRL_of_IRL(new_irl)= rule;
Rank_of_IRL(new_irl)= IRL_Rank_by_XRL(rule);
for(symbol_ix= 0;symbol_ix<=rewrite_xrl_length;symbol_ix++)
{
new_irl->t_isyid_array[symbol_ix]= 
ISYID_by_XSYID(rule->t_symbols[symbol_ix]);
}
irl_finish(g,new_irl);
}

/*:246*/
#line 3863 "./marpa.w"

}
}

/*:397*/
#line 3040 "./marpa.w"

/*426:*/
#line 4411 "./marpa.w"

{
const XSY start_xsy= XSY_by_ID(start_xsy_id);
if(LIKELY(!XSY_is_Nulling(start_xsy))){
/*427:*/
#line 4419 "./marpa.w"
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

/*:427*/
#line 4415 "./marpa.w"

}
}

/*:426*/
#line 3041 "./marpa.w"



if(!G_is_Trivial(g)){
/*548:*/
#line 5814 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
AIM*const item_list_working_buffer
= my_obstack_alloc(obs_precompute,irl_count*sizeof(AIM));
const ISYID isy_count= ISY_Count_of_G(g);
const XSYID xsy_count= XSY_Count_of_G(g);
IRLID**irl_list_x_lh_isy= NULL;
Bit_Matrix isy_by_right_isy_matrix;

/*:548*/
#line 3046 "./marpa.w"

/*551:*/
#line 5839 "./marpa.w"

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

/*:551*/
#line 3047 "./marpa.w"

/*463:*/
#line 4814 "./marpa.w"

{
IRLID irl_id;
AIMID ahfa_item_count= 0;
AIM base_item;
AIM current_item;
unsigned int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*465:*/
#line 4865 "./marpa.w"

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

/*:465*/
#line 4823 "./marpa.w"

}
current_item= base_item= my_new(struct s_AHFA_item,ahfa_item_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*464:*/
#line 4842 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
ISYID rh_isyid= RHSID_of_IRL(irl,rhs_ix);
if(!ISY_is_Nulling(ISY_by_ID(rh_isyid)))
{
Last_Proper_SYMI_of_IRL(irl)= symbol_instance_of_next_rule+rhs_ix;
/*466:*/
#line 4877 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_ISYID_of_AIM(current_item)= rh_isyid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:466*/
#line 4852 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*467:*/
#line 4886 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_ISYID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:467*/
#line 4861 "./marpa.w"

current_item++;
}

/*:464*/
#line 4828 "./marpa.w"

{
SYMI_of_IRL(irl)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_IRL(irl);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(ahfa_item_count==current_item-base_item);
AIM_Count_of_G(g)= ahfa_item_count;
g->t_AHFA_items= my_renew(struct s_AHFA_item,base_item,ahfa_item_count);
/*468:*/
#line 4900 "./marpa.w"

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

/*:468*/
#line 4838 "./marpa.w"

/*473:*/
#line 4958 "./marpa.w"

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

/*:473*/
#line 4839 "./marpa.w"

}

/*:463*/
#line 3048 "./marpa.w"

/*533:*/
#line 5472 "./marpa.w"

{
/*534:*/
#line 5491 "./marpa.w"

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

/*:534*/
#line 5474 "./marpa.w"

/*535:*/
#line 5504 "./marpa.w"

/*536:*/
#line 5508 "./marpa.w"

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

/*:536*/
#line 5505 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:535*/
#line 5475 "./marpa.w"

/*560:*/
#line 6066 "./marpa.w"
{
Bit_Matrix prediction_isy_by_isy_matrix= 
matrix_obs_create(obs_precompute,isy_count,isy_count);
/*561:*/
#line 6074 "./marpa.w"

{
IRLID irl_id;
ISYID isyid;
for(isyid= 0;isyid<isy_count;isyid++)
{

ISY isy= ISY_by_ID(isyid);
if(!ISY_is_LHS(isy))continue;
matrix_bit_set(prediction_isy_by_isy_matrix,(unsigned int)isyid,(unsigned int)isyid);
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
matrix_bit_set(prediction_isy_by_isy_matrix,
(unsigned int)from_isyid,
(unsigned int)to_isyid);
}
}

/*:561*/
#line 6069 "./marpa.w"

transitive_closure(prediction_isy_by_isy_matrix);
/*562:*/
#line 6109 "./marpa.w"
{
unsigned int*sort_key_by_irl_id= my_new(unsigned int,irl_count);
/*564:*/
#line 6127 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
irl_by_sort_key[irl_id]= IRL_by_ID(irl_id);
}
qsort(irl_by_sort_key,(int)irl_count,
sizeof(RULE),cmp_by_irl_sort_key);
}

/*:564*/
#line 6111 "./marpa.w"

/*566:*/
#line 6165 "./marpa.w"

{
IRLID sort_ordinal;
for(sort_ordinal= 0;sort_ordinal<irl_count;sort_ordinal++)
{
IRL irl= irl_by_sort_key[sort_ordinal];
sort_key_by_irl_id[ID_of_IRL(irl)]= sort_ordinal;
}
}

/*:566*/
#line 6112 "./marpa.w"

/*567:*/
#line 6175 "./marpa.w"

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
(prediction_isy_by_isy_matrix,(unsigned int)from_isyid),
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

/*:567*/
#line 6113 "./marpa.w"

my_free(sort_key_by_irl_id);
}

/*:562*/
#line 6071 "./marpa.w"

}

/*:560*/
#line 5476 "./marpa.w"

/*522:*/
#line 5309 "./marpa.w"
{
isy_by_right_isy_matrix= 
matrix_obs_create(obs_precompute,isy_count,isy_count);
/*523:*/
#line 5320 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
const IRL irl= IRL_by_ID(irl_id);
int rhs_ix;
for(rhs_ix= Length_of_IRL(irl)-1;
rhs_ix>=0;
rhs_ix--)
{


const ISYID rh_isyid= RHSID_of_IRL(irl,rhs_ix);
if(!ISY_is_Nulling(ISY_by_ID(rh_isyid)))
{
matrix_bit_set(isy_by_right_isy_matrix,
(unsigned int)LHSID_of_IRL(irl),
(unsigned int)rh_isyid);
break;
}
}
}
}

/*:523*/
#line 5312 "./marpa.w"

transitive_closure(isy_by_right_isy_matrix);
/*524:*/
#line 5345 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
const IRL irl= IRL_by_ID(irl_id);
int rhs_ix;
for(rhs_ix= Length_of_IRL(irl)-1;rhs_ix>=0;rhs_ix--)
{
const ISYID rh_isyid= RHSID_of_IRL(irl,rhs_ix);
if(!ISY_is_Nulling(ISY_by_ID(rh_isyid)))
{



if(matrix_bit_test(isy_by_right_isy_matrix,
(unsigned int)rh_isyid,
(unsigned int)LHSID_of_IRL(irl)))
{
IRL_is_Right_Recursive(irl)= 1;
}
break;
}
}
}
}

/*:524*/
#line 5314 "./marpa.w"

matrix_clear(isy_by_right_isy_matrix);
/*525:*/
#line 5372 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
int rhs_ix;
const IRL irl= IRL_by_ID(irl_id);
if(!IRL_is_Right_Recursive(irl)){continue;}
for(rhs_ix= Length_of_IRL(irl)-1;
rhs_ix>=0;
rhs_ix--)
{


const ISYID rh_isyid= RHSID_of_IRL(irl,rhs_ix);
if(!ISY_is_Nulling(ISY_by_ID(rh_isyid)))
{
matrix_bit_set(isy_by_right_isy_matrix,
(unsigned int)LHSID_of_IRL(irl),
(unsigned int)rh_isyid);
break;
}
}
}
}

/*:525*/
#line 5316 "./marpa.w"

transitive_closure(isy_by_right_isy_matrix);
}

/*:522*/
#line 5477 "./marpa.w"

/*543:*/
#line 5665 "./marpa.w"

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
Completion_CIL_of_AHFA(p_initial_state)= 
cil_empty(&g->t_cilar);
p_initial_state->t_empty_transition= create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(unsigned int)postdot_isyid),
irl_by_sort_key,&states,duplicates,
item_list_working_buffer);
}

/*:543*/
#line 5478 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*537:*/
#line 5520 "./marpa.w"

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
/*546:*/
#line 5724 "./marpa.w"
{
AHFA p_new_state;
AIM*new_state_item_list;
AIM working_aim_p= item_list[first_working_item_ix];
Marpa_AHFA_Item_ID working_aim_id;
ISYID postdot_isyid;
working_aim_p++;
working_aim_id= working_aim_p-AHFA_item_0_p;
p_new_state= singleton_duplicates[working_aim_id];
if(p_new_state)
{
transition_add(obs_precompute,p_working_state,working_isyid,p_new_state);
goto NEXT_WORKING_SYMBOL;
}
p_new_state= DQUEUE_PUSH(states,AHFA_Object);

AHFA_initialize(p_new_state);
singleton_duplicates[working_aim_id]= p_new_state;
new_state_item_list= p_new_state->t_items= 
my_obstack_alloc(g->t_obs,sizeof(AIM));
new_state_item_list[0]= working_aim_p;
p_new_state->t_item_count= 1;
AHFA_is_Predicted(p_new_state)= 0;
p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
TRANSs_of_AHFA(p_new_state)= transitions_new(g,isy_count);
transition_add(obs_precompute,p_working_state,working_isyid,p_new_state);
postdot_isyid= Postdot_ISYID_of_AIM(working_aim_p);
if(postdot_isyid>=0)
{
ISYID*p_postdot_isyidary= Postdot_ISYIDAry_of_AHFA(p_new_state)= 
my_obstack_alloc(g->t_obs,sizeof(ISYID));
Completion_CIL_of_AHFA(p_new_state)
= cil_empty(&g->t_cilar);
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

const IRL irl= IRL_of_AIM(working_aim_p);
const ISYID lhs_isyid= LHSID_of_IRL(irl);
Completion_CIL_of_AHFA(p_new_state)= cil_singleton(&g->t_cilar,lhs_isyid);
completion_count_inc(obs_precompute,p_new_state,lhs_isyid);

Postdot_ISY_Count_of_AHFA(p_new_state)= 0;
p_new_state->t_empty_transition= NULL;
/*547:*/
#line 5788 "./marpa.w"

{
const IRL aim_irl= IRL_of_AIM(working_aim_p);
if(IRL_is_Right_Recursive(aim_irl))
{
Leo_LHS_ISYID_of_AHFA(p_new_state)= lhs_isyid;
Leo_IRLID_of_AHFA(p_new_state)= ID_of_IRL(aim_irl);
}
}

/*:547*/
#line 5779 "./marpa.w"

}
}

/*:546*/
#line 5546 "./marpa.w"

}
else
{
/*552:*/
#line 5882 "./marpa.w"

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
/*553:*/
#line 5940 "./marpa.w"

{
int item_ix;
int no_of_postdot_isys;
bv_clear(per_ahfa_complete_v);
bv_clear(per_ahfa_postdot_v);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_working_buffer[item_ix];
ISYID postdot_isyid= Postdot_ISYID_of_AIM(item);
if(postdot_isyid<0)
{
ISYID complete_symbol_isyid= LHS_ISYID_of_AIM(item);
completion_count_inc(obs_precompute,p_new_state,
complete_symbol_isyid);
bv_bit_set(per_ahfa_complete_v,
(unsigned int)complete_symbol_isyid);
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
for(start= 0;bv_scan(per_ahfa_postdot_v,start,&min,&max);
start= max+2)
{
ISYID postdot_isyid;
for(postdot_isyid= (ISYID)min;
postdot_isyid<=(ISYID)max;postdot_isyid++)
{
*p_isyid++= postdot_isyid;
}
}
}
Completion_CIL_of_AHFA(p_new_state)= cil_bv_add(&g->t_cilar,per_ahfa_complete_v);
}

/*:553*/
#line 5932 "./marpa.w"

transition_add(obs_precompute,p_working_state,working_isyid,
p_new_state);
/*555:*/
#line 5999 "./marpa.w"

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

/*:555*/
#line 5936 "./marpa.w"

}

/*:552*/
#line 5550 "./marpa.w"

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

/*:537*/
#line 5480 "./marpa.w"

}
g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*538:*/
#line 5563 "./marpa.w"

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

/*:538*/
#line 5485 "./marpa.w"

/*540:*/
#line 5624 "./marpa.w"

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

/*:540*/
#line 5486 "./marpa.w"

/*539:*/
#line 5593 "./marpa.w"

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

/*:539*/
#line 5487 "./marpa.w"

/*541:*/
#line 5657 "./marpa.w"

my_free(irl_by_sort_key);
/*542:*/
#line 5661 "./marpa.w"

my_free(singleton_duplicates);
_marpa_avl_destroy(duplicates);

/*:542*/
#line 5659 "./marpa.w"


/*:541*/
#line 5488 "./marpa.w"

}

/*:533*/
#line 3049 "./marpa.w"

/*590:*/
#line 6505 "./marpa.w"

{
int xsy_id;
g->t_bv_isyid_is_terminal= bv_obs_create(g->t_obs,isy_count);
for(xsy_id= 0;xsy_id<xsy_count;xsy_id++)
{
if(XSYID_is_Terminal(xsy_id))
{


const ISY isy= ISY_of_XSY(XSY_by_ID(xsy_id));
if(isy)
{
bv_bit_set(g->t_bv_isyid_is_terminal,
(unsigned int)ID_of_ISY(isy));
}
}
}
}

/*:590*/
#line 3050 "./marpa.w"

/*591:*/
#line 6526 "./marpa.w"

{
int xsyid;
g->t_lbv_xsyid_is_completion_event= bv_obs_create(g->t_obs,xsy_count);
g->t_lbv_xsyid_is_nulled_event= bv_obs_create(g->t_obs,xsy_count);
g->t_lbv_xsyid_is_prediction_event= bv_obs_create(g->t_obs,xsy_count);
for(xsyid= 0;xsyid<xsy_count;xsyid++)
{
if(XSYID_is_Completion_Event(xsyid))
{
lbv_bit_set(g->t_lbv_xsyid_is_completion_event,xsyid);
}
if(XSYID_is_Nulled_Event(xsyid))
{
lbv_bit_set(g->t_lbv_xsyid_is_nulled_event,xsyid);
}
if(XSYID_is_Prediction_Event(xsyid))
{
lbv_bit_set(g->t_lbv_xsyid_is_prediction_event,xsyid);
}
}
}

/*:591*/
#line 3051 "./marpa.w"

/*592:*/
#line 6549 "./marpa.w"

{
AHFAID ahfaid;
const AHFAID ahfa_count_of_g= AHFA_Count_of_G(g);
const LBV bv_completion_xsyid= bv_create(xsy_count);
const LBV bv_prediction_xsyid= bv_create(xsy_count);
const LBV bv_nulled_xsyid= bv_create(xsy_count);
const CILAR cilar= &g->t_cilar;
for(ahfaid= 0;ahfaid<ahfa_count_of_g;ahfaid++)
{
AEX aex;
const AHFA ahfa= AHFA_of_G_by_ID(g,ahfaid);
const int ahfa_item_count= AIM_Count_of_AHFA(ahfa);
bv_clear(bv_completion_xsyid);
bv_clear(bv_prediction_xsyid);
bv_clear(bv_nulled_xsyid);
for(aex= 0;aex<(AEX)ahfa_item_count;aex++)
{
int rhs_ix;
const AIM aim= AIM_of_AHFA_by_AEX(ahfa,aex);
const ISYID postdot_isyid= Postdot_ISYID_of_AIM(aim);
const IRL irl= IRL_of_AIM(aim);
int raw_position= Position_of_AIM(aim);
if(raw_position<0)
{
raw_position= Length_of_IRL(irl);
if(!IRL_has_Virtual_LHS(irl))
{
const ISY lhs= LHS_of_IRL(irl);
const XSY xsy= Source_XSY_of_ISY(lhs);
if(XSY_is_Completion_Event(xsy))
{
const XSYID xsyid= ID_of_XSY(xsy);
bv_bit_set(bv_completion_xsyid,xsyid);
}
}
}
if(postdot_isyid>=0)
{
const XSY xsy= Source_XSY_of_ISYID(postdot_isyid);
const XSYID xsyid= ID_of_XSY(xsy);
bv_bit_set(bv_prediction_xsyid,xsyid);
}
for(rhs_ix= raw_position-Null_Count_of_AIM(aim);
rhs_ix<raw_position;rhs_ix++)
{
int cil_ix;
const ISYID rhs_isyid= RHSID_of_IRL(irl,rhs_ix);
const XSY xsy= Source_XSY_of_ISYID(rhs_isyid);
const CIL nulled_xsyids= Nulled_XSYIDs_of_XSY(xsy);
const int cil_count= Count_of_CIL(nulled_xsyids);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
const XSYID nulled_xsyid= 
Item_of_CIL(nulled_xsyids,cil_ix);
bv_bit_set(bv_nulled_xsyid,nulled_xsyid);
}
}
}
Completion_XSYIDs_of_AHFA(ahfa)= 
cil_bv_add(cilar,bv_completion_xsyid);
Nulled_XSYIDs_of_AHFA(ahfa)= cil_bv_add(cilar,bv_nulled_xsyid);
Prediction_XSYIDs_of_AHFA(ahfa)= 
cil_bv_add(cilar,bv_prediction_xsyid);
}
bv_free(bv_completion_xsyid);
bv_free(bv_prediction_xsyid);
bv_free(bv_nulled_xsyid);
}

/*:592*/
#line 3053 "./marpa.w"

/*593:*/
#line 6619 "./marpa.w"

{
AHFAID ahfa_id;
for(ahfa_id= 0;ahfa_id<AHFA_Count_of_G(g);ahfa_id++)
{
const CILAR cilar= &g->t_cilar;
const AHFA ahfa= AHFA_by_ID(ahfa_id);
const int ahfa_is_event= 
Count_of_CIL(Completion_XSYIDs_of_AHFA(ahfa))
||Count_of_CIL(Nulled_XSYIDs_of_AHFA(ahfa))
||Count_of_CIL(Prediction_XSYIDs_of_AHFA(ahfa));
Event_AHFAIDs_of_AHFA(ahfa)= 
ahfa_is_event?cil_singleton(cilar,ahfa_id):cil_empty(cilar);
}
}

/*:593*/
#line 3054 "./marpa.w"

/*594:*/
#line 6635 "./marpa.w"

{
const AHFAID ahfa_count_of_g= AHFA_Count_of_G(g);
AHFAID outer_ahfa_id;
for(outer_ahfa_id= 0;outer_ahfa_id<ahfa_count_of_g;outer_ahfa_id++)
{
AHFAID inner_ahfa_id;
const AHFA outer_ahfa= AHFA_by_ID(outer_ahfa_id);




const ISYID outer_isyid= Leo_LHS_ISYID_of_AHFA(outer_ahfa);
if(outer_isyid<0){
if(AHFA_has_Event(outer_ahfa)){
Event_Group_Size_of_AHFA(outer_ahfa)= 1;
}
continue;

}
for(inner_ahfa_id= 0;inner_ahfa_id<ahfa_count_of_g;
inner_ahfa_id++)
{
IRLID inner_isyid;
const AHFA inner_ahfa= AHFA_by_ID(inner_ahfa_id);
if(!AHFA_has_Event(inner_ahfa))
continue;

inner_isyid= Leo_LHS_ISYID_of_AHFA(inner_ahfa);
if(inner_isyid<0)
continue;

if(matrix_bit_test(isy_by_right_isy_matrix,
(unsigned int)outer_isyid,
(unsigned int)inner_isyid))
{
Event_Group_Size_of_AHFA(outer_ahfa)++;

}
}
}
}

/*:594*/
#line 3055 "./marpa.w"

}
g->t_is_precomputed= 1;
if(g->t_has_cycle)
{
MARPA_ERROR(MARPA_ERR_GRAMMAR_HAS_CYCLE);
goto FAILURE;
}
/*595:*/
#line 6682 "./marpa.w"

{cilar_reinit(&g->t_cilar);}
/*:595*/
#line 3063 "./marpa.w"

return_value= 0;
goto CLEANUP;
FAILURE:;
goto CLEANUP;
CLEANUP:;
my_obstack_free(obs_precompute);
return return_value;
}

/*:359*//*368:*/
#line 3165 "./marpa.w"

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

/*:368*//*450:*/
#line 4731 "./marpa.w"

PRIVATE int aim_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:450*//*455:*/
#line 4768 "./marpa.w"

int _marpa_g_AHFA_item_count(Marpa_Grammar g){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4770 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 4771 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:455*//*456:*/
#line 4775 "./marpa.w"

Marpa_IRL_ID _marpa_g_AHFA_item_irl(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4778 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 4779 "./marpa.w"

/*1357:*/
#line 16109 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1357*/
#line 4780 "./marpa.w"

return IRLID_of_AIM(AIM_by_ID(item_id));
}

/*:456*//*458:*/
#line 4785 "./marpa.w"

int _marpa_g_AHFA_item_position(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4788 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 4789 "./marpa.w"

/*1357:*/
#line 16109 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1357*/
#line 4790 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:458*//*460:*/
#line 4795 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_item_postdot(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4798 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 4799 "./marpa.w"

/*1357:*/
#line 16109 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1357*/
#line 4800 "./marpa.w"

return Postdot_ISYID_of_AIM(AIM_by_ID(item_id));
}

/*:460*//*461:*/
#line 4804 "./marpa.w"

int _marpa_g_AHFA_item_sort_key(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4807 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 4808 "./marpa.w"

/*1357:*/
#line 16109 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1357*/
#line 4809 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:461*//*470:*/
#line 4919 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:470*//*472:*/
#line 4934 "./marpa.w"

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

/*:472*//*486:*/
#line 5086 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*503:*/
#line 5182 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;


/*:503*//*507:*/
#line 5209 "./marpa.w"

Event_AHFAIDs_of_AHFA(ahfa)= NULL;
Event_Group_Size_of_AHFA(ahfa)= 0;

/*:507*//*528:*/
#line 5414 "./marpa.w"

Leo_LHS_ISYID_of_AHFA(ahfa)= -1;
Leo_IRLID_of_AHFA(ahfa)= -1;
/*:528*/
#line 5089 "./marpa.w"

}

/*:486*//*497:*/
#line 5143 "./marpa.w"

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

/*:497*//*514:*/
#line 5237 "./marpa.w"

PRIVATE int AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:514*//*517:*/
#line 5251 "./marpa.w"

int _marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:517*//*518:*/
#line 5256 "./marpa.w"

int
_marpa_g_AHFA_state_item_count(Marpa_Grammar g,AHFAID AHFA_state_id)
{/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5259 "./marpa.w"

AHFA state;
/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 5261 "./marpa.w"

/*1358:*/
#line 16114 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1358*/
#line 5262 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:518*//*519:*/
#line 5269 "./marpa.w"

Marpa_AHFA_Item_ID _marpa_g_AHFA_state_item(Marpa_Grammar g,
AHFAID AHFA_state_id,
int item_ix){
AHFA state;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5274 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 5275 "./marpa.w"

/*1358:*/
#line 16114 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1358*/
#line 5276 "./marpa.w"

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

/*:519*//*520:*/
#line 5289 "./marpa.w"

int _marpa_g_AHFA_state_is_predict(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5293 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 5294 "./marpa.w"

/*1358:*/
#line 16114 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1358*/
#line 5295 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:520*//*529:*/
#line 5417 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_state_leo_lhs_symbol(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5420 "./marpa.w"

AHFA state;
/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 5422 "./marpa.w"

/*1358:*/
#line 16114 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1358*/
#line 5423 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ISYID_of_AHFA(state);
}

/*:529*//*532:*/
#line 5444 "./marpa.w"

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

/*:532*//*554:*/
#line 5990 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,AVL_TREE duplicates)
{
const AHFA state_found= _marpa_avl_insert(duplicates,sought_state);
return state_found;
}

/*:554*//*565:*/
#line 6143 "./marpa.w"

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

/*:565*//*568:*/
#line 6211 "./marpa.w"

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
Completion_CIL_of_AHFA(p_new_state)= cil_empty(&g->t_cilar);
/*569:*/
#line 6275 "./marpa.w"

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

/*:569*/
#line 6271 "./marpa.w"

return p_new_state;
}

/*:568*//*580:*/
#line 6381 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:580*//*581:*/
#line 6387 "./marpa.w"

PRIVATE int completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:581*//*582:*/
#line 6394 "./marpa.w"

PRIVATE
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,int aim_ix)
{
URTRANS transition;
transition= my_obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:582*//*583:*/
#line 6405 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g,int isy_count)
{
int isyid= 0;
TRANS*transitions= my_obstack_new(g->t_obs,TRANS,isy_count);
while(isyid<isy_count)transitions[isyid++]= NULL;


return transitions;
}

/*:583*//*584:*/
#line 6416 "./marpa.w"

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

/*:584*//*585:*/
#line 6434 "./marpa.w"

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

/*:585*//*587:*/
#line 6449 "./marpa.w"

int _marpa_g_AHFA_state_transitions(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id,
int*buffer,
int buffer_size
){

/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6456 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
XSYID isyid;
int isy_count;
int ix= 0;
const int max_ix= buffer_size/sizeof(*buffer);
const int max_results= max_ix/2;





/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 6469 "./marpa.w"

/*1358:*/
#line 16114 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1358*/
#line 6470 "./marpa.w"

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

/*:587*//*589:*/
#line 6489 "./marpa.w"

AHFAID _marpa_g_AHFA_state_empty_transition(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6494 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 6495 "./marpa.w"

/*1358:*/
#line 16114 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1358*/
#line 6496 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}

/*:589*//*600:*/
#line 6705 "./marpa.w"

PRIVATE INPUT input_new(GRAMMAR g)
{
INPUT input= my_slice_new(struct s_input);
TOK_Obs_of_I(input)= my_obstack_init;
/*603:*/
#line 6717 "./marpa.w"

input->t_ref_count= 1;

/*:603*//*611:*/
#line 6776 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:611*/
#line 6710 "./marpa.w"

return input;
}

/*:600*//*604:*/
#line 6721 "./marpa.w"

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

/*:604*//*605:*/
#line 6734 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:605*//*606:*/
#line 6747 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
my_obstack_free(TOK_Obs_of_I(input));
my_slice_free(struct s_input,input);
}

/*:606*//*615:*/
#line 6802 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
ISYID isy_count;
/*1345:*/
#line 16044 "./marpa.w"
void*const failure_indicator= NULL;
/*:1345*/
#line 6807 "./marpa.w"

/*1348:*/
#line 16058 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1348*/
#line 6808 "./marpa.w"

isy_count= ISY_Count_of_G(g);
r= my_slice_new(struct marpa_r);
/*673:*/
#line 7332 "./marpa.w"
r->t_obs= my_obstack_init;
/*:673*/
#line 6811 "./marpa.w"

/*618:*/
#line 6818 "./marpa.w"

r->t_ref_count= 1;

/*:618*//*626:*/
#line 6884 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:626*//*628:*/
#line 6893 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:628*//*632:*/
#line 6917 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:632*//*636:*/
#line 6945 "./marpa.w"
r->t_furthest_earleme= 0;
/*:636*//*641:*/
#line 6967 "./marpa.w"

r->t_lbv_xsyid_completion_event_is_active= NULL;
r->t_lbv_xsyid_nulled_event_is_active= NULL;
r->t_lbv_xsyid_prediction_event_is_active= NULL;
r->t_active_event_count= 0;

/*:641*//*643:*/
#line 6982 "./marpa.w"

r->t_bv_isyid_is_expected= bv_obs_create(r->t_obs,(unsigned int)isy_count);
/*:643*//*647:*/
#line 7038 "./marpa.w"

r->t_isy_expected_is_event= lbv_obs_new0(r->t_obs,isy_count);
/*:647*//*665:*/
#line 7271 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:665*//*669:*/
#line 7307 "./marpa.w"
r->t_is_exhausted= 0;
/*:669*//*689:*/
#line 7412 "./marpa.w"

r->t_earley_set_count= 0;

/*:689*//*699:*/
#line 7538 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:699*//*706:*/
#line 7612 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:706*//*746:*/
#line 8132 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;
/*:746*//*781:*/
#line 8588 "./marpa.w"

r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:781*//*814:*/
#line 9038 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:814*//*818:*/
#line 9067 "./marpa.w"

DSTACK_INIT2(r->t_alternatives,ALT_Object);
/*:818*//*841:*/
#line 9477 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:841*//*845:*/
#line 9488 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:845*//*849:*/
#line 9495 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:849*//*920:*/
#line 10525 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:920*//*1030:*/
#line 12130 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
r->t_progress_report_traverser= NULL;
/*:1030*//*1315:*/
#line 15729 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1315*/
#line 6812 "./marpa.w"

return r;
}

/*:615*//*619:*/
#line 6822 "./marpa.w"

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

/*:619*//*620:*/
#line 6840 "./marpa.w"

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

/*:620*//*621:*/
#line 6854 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 6858 "./marpa.w"

/*623:*/
#line 6872 "./marpa.w"
input_unref(input);

/*:623*//*819:*/
#line 9069 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:819*//*843:*/
#line 9481 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:843*//*847:*/
#line 9492 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:847*//*850:*/
#line 9496 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:850*//*921:*/
#line 10527 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:921*//*1032:*/
#line 12139 "./marpa.w"

/*1031:*/
#line 12133 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(TREE_of_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:1031*/
#line 12140 "./marpa.w"
;
/*:1032*//*1316:*/
#line 15731 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1316*/
#line 6859 "./marpa.w"

grammar_unref(g);
/*674:*/
#line 7333 "./marpa.w"
my_obstack_free(r->t_obs);

/*:674*/
#line 6861 "./marpa.w"

my_slice_free(struct marpa_r,r);
}

/*:621*//*629:*/
#line 6901 "./marpa.w"

unsigned int marpa_r_current_earleme(Marpa_Recognizer r)
{return Current_Earleme_of_R(r);}

/*:629*//*630:*/
#line 6906 "./marpa.w"

PRIVATE ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:630*//*633:*/
#line 6919 "./marpa.w"

int
marpa_r_earley_item_warning_threshold(Marpa_Recognizer r)
{
return r->t_earley_item_warning_threshold;
}

/*:633*//*634:*/
#line 6928 "./marpa.w"

int
marpa_r_earley_item_warning_threshold_set(Marpa_Recognizer r,int threshold)
{
const int new_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
r->t_earley_item_warning_threshold= new_threshold;
return new_threshold;
}

/*:634*//*637:*/
#line 6946 "./marpa.w"

unsigned int marpa_r_furthest_earleme(Marpa_Recognizer r)
{return Furthest_Earleme_of_R(r);}

/*:637*//*644:*/
#line 6990 "./marpa.w"

int marpa_r_terminals_expected(Marpa_Recognizer r,Marpa_Symbol_ID*buffer)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6993 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 6994 "./marpa.w"

unsigned int min,max,start;
int ix= 0;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 6997 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 6998 "./marpa.w"

for(start= 0;bv_scan(r->t_bv_isyid_is_expected,start,&min,&max);
start= max+2)
{
ISYID isyid;
for(isyid= (ISYID)min;isyid<=(ISYID)max;isyid++)
{
const XSY xsy= Source_XSY_of_ISYID(isyid);
buffer[ix++]= ID_of_XSY(xsy);
}
}
return ix;
}
/*:644*//*645:*/
#line 7011 "./marpa.w"

int marpa_r_terminal_is_expected(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7015 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7016 "./marpa.w"

XSY xsy;
ISY isy;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7019 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 7020 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 7021 "./marpa.w"

/*1351:*/
#line 16075 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1351*/
#line 7022 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(UNLIKELY(!XSY_is_Terminal(xsy))){
return 0;
}
isy= ISY_of_XSY(xsy);
if(UNLIKELY(!isy))return 0;
return bv_bit_test(r->t_bv_isyid_is_expected,ID_of_ISY(isy));
}

/*:645*//*648:*/
#line 7041 "./marpa.w"

int marpa_r_expected_symbol_event_set(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
ISY isy;
ISYID isyid;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7047 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7048 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7049 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 7050 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 7051 "./marpa.w"

if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
xsy= XSY_by_ID(xsy_id);
if(UNLIKELY(XSY_is_Nulling(xsy))){
MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NULLING);
}
isy= ISY_of_XSY(xsy);
if(UNLIKELY(!isy)){
MARPA_ERROR(MARPA_ERR_SYMBOL_IS_UNUSED);
}
isyid= ID_of_ISY(isy);
if(value){
lbv_bit_set(r->t_isy_expected_is_event,isyid);
}else{
lbv_bit_clear(r->t_isy_expected_is_event,isyid);
}
return value;
}

/*:648*//*650:*/
#line 7088 "./marpa.w"

int marpa_r_completion_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7091 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7092 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7093 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 7094 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 7095 "./marpa.w"

switch(reactivate){
case 0:
if(lbv_bit_test(r->t_lbv_xsyid_completion_event_is_active,xsy_id)){
lbv_bit_clear(r->t_lbv_xsyid_completion_event_is_active,xsy_id);
r->t_active_event_count--;
}
return 0;
case 1:
if(!lbv_bit_test(g->t_lbv_xsyid_is_completion_event,xsy_id)){


MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NOT_COMPLETION_EVENT);
}
if(!lbv_bit_test(r->t_lbv_xsyid_completion_event_is_active,xsy_id)){
lbv_bit_set(r->t_lbv_xsyid_completion_event_is_active,xsy_id);
r->t_active_event_count++;
}
return 1;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:650*//*652:*/
#line 7133 "./marpa.w"

int marpa_r_nulled_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7136 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7137 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7138 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 7139 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 7140 "./marpa.w"

switch(reactivate){
case 0:
if(lbv_bit_test(r->t_lbv_xsyid_nulled_event_is_active,xsy_id)){
lbv_bit_clear(r->t_lbv_xsyid_nulled_event_is_active,xsy_id);
r->t_active_event_count--;
}
return 0;
case 1:
if(!lbv_bit_test(g->t_lbv_xsyid_is_nulled_event,xsy_id)){


MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NOT_NULLED_EVENT);
}
if(!lbv_bit_test(r->t_lbv_xsyid_nulled_event_is_active,xsy_id)){
lbv_bit_set(r->t_lbv_xsyid_nulled_event_is_active,xsy_id);
r->t_active_event_count++;
}
return 1;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:652*//*654:*/
#line 7178 "./marpa.w"

int marpa_r_prediction_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7181 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7182 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7183 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 7184 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 7185 "./marpa.w"

switch(reactivate){
case 0:
if(lbv_bit_test(r->t_lbv_xsyid_prediction_event_is_active,xsy_id)){
lbv_bit_clear(r->t_lbv_xsyid_prediction_event_is_active,xsy_id);
r->t_active_event_count--;
}
return 0;
case 1:
if(!lbv_bit_test(g->t_lbv_xsyid_is_prediction_event,xsy_id)){


MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NOT_PREDICTION_EVENT);
}
if(!lbv_bit_test(r->t_lbv_xsyid_prediction_event_is_active,xsy_id)){
lbv_bit_set(r->t_lbv_xsyid_prediction_event_is_active,xsy_id);
r->t_active_event_count++;
}
return 1;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:654*//*666:*/
#line 7277 "./marpa.w"

int _marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7280 "./marpa.w"

/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7281 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7282 "./marpa.w"

return r->t_use_leo_flag;
}
/*:666*//*667:*/
#line 7285 "./marpa.w"

int _marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7289 "./marpa.w"

/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7290 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7291 "./marpa.w"

/*1359:*/
#line 16123 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1359*/
#line 7292 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:667*//*671:*/
#line 7318 "./marpa.w"

int marpa_r_is_exhausted(Marpa_Recognizer r)
{
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7321 "./marpa.w"

/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7322 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7323 "./marpa.w"

return R_is_Exhausted(r);
}

/*:671*//*693:*/
#line 7431 "./marpa.w"

int marpa_r_earley_set_value(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7434 "./marpa.w"

ES earley_set;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7436 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7437 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 7438 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return Value_of_ES(earley_set);
}

/*:693*//*694:*/
#line 7454 "./marpa.w"

int
marpa_r_earley_set_values(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id,
int*p_value,void**p_pvalue)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7459 "./marpa.w"

ES earley_set;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7461 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7462 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 7463 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
if(p_value)*p_value= Value_of_ES(earley_set);
if(p_pvalue)*p_pvalue= PValue_of_ES(earley_set);
return 1;
}

/*:694*//*695:*/
#line 7481 "./marpa.w"

int marpa_r_latest_earley_set_value_set(Marpa_Recognizer r,int value)
{
ES earley_set;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7485 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7486 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7487 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 7488 "./marpa.w"

earley_set= Latest_ES_of_R(r);
return Value_of_ES(earley_set)= value;
}

/*:695*//*696:*/
#line 7493 "./marpa.w"

int marpa_r_latest_earley_set_values_set(Marpa_Recognizer r,int value,
void*pvalue)
{
ES earley_set;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7498 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7499 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7500 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 7501 "./marpa.w"

earley_set= Latest_ES_of_R(r);
Value_of_ES(earley_set)= value;
PValue_of_ES(earley_set)= pvalue;
return 1;
}

/*:696*//*697:*/
#line 7509 "./marpa.w"

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
/*692:*/
#line 7427 "./marpa.w"

Value_of_ES(set)= -1;
PValue_of_ES(set)= NULL;

/*:692*//*1321:*/
#line 15775 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1321*/
#line 7524 "./marpa.w"

return set;
}

/*:697*//*700:*/
#line 7541 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_trace_earley_set(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7544 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7545 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 7547 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:700*//*701:*/
#line 7555 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7558 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7559 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 7560 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:701*//*702:*/
#line 7564 "./marpa.w"

Marpa_Earleme marpa_r_earleme(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7567 "./marpa.w"

/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7568 "./marpa.w"

ES earley_set;
/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 7570 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7571 "./marpa.w"

if(set_id<0){
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return Earleme_of_ES(earley_set);
}

/*:702*//*704:*/
#line 7588 "./marpa.w"

int _marpa_r_earley_set_size(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7591 "./marpa.w"

ES earley_set;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7593 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 7594 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 7595 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:704*//*711:*/
#line 7652 "./marpa.w"

Marpa_Earleme
_marpa_r_earley_set_trace(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const int es_does_not_exist= -1;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7658 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7659 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 7660 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*712:*/
#line 7683 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*748:*/
#line 8172 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:748*/
#line 7686 "./marpa.w"

}

/*:712*/
#line 7667 "./marpa.w"

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

/*:711*//*713:*/
#line 7689 "./marpa.w"

Marpa_AHFA_State_ID
_marpa_r_earley_item_trace(Marpa_Recognizer r,Marpa_Earley_Item_ID item_id)
{
const int eim_does_not_exist= -1;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7694 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7698 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 7699 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*712:*/
#line 7683 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*748:*/
#line 8172 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:748*/
#line 7686 "./marpa.w"

}

/*:712*/
#line 7703 "./marpa.w"

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

/*:713*//*715:*/
#line 7732 "./marpa.w"

PRIVATE void trace_earley_item_clear(RECCE r)
{
/*714:*/
#line 7729 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:714*/
#line 7735 "./marpa.w"

trace_source_link_clear(r);
}

/*:715*//*716:*/
#line 7739 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_earley_item_origin(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7742 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7744 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 7745 "./marpa.w"

if(!item){
/*714:*/
#line 7729 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:714*/
#line 7747 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:716*//*725:*/
#line 7839 "./marpa.w"

PRIVATE EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1345:*/
#line 16044 "./marpa.w"
void*const failure_indicator= NULL;
/*:1345*/
#line 7843 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 7844 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const int count= ++EIM_Count_of_ES(set);
/*727:*/
#line 7891 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_EIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:727*/
#line 7849 "./marpa.w"

new_item= my_obstack_new(r->t_obs,struct s_earley_item,1);
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:725*//*726:*/
#line 7859 "./marpa.w"

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

/*:726*//*730:*/
#line 7923 "./marpa.w"

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

/*:730*//*738:*/
#line 8010 "./marpa.w"

Marpa_Symbol_ID _marpa_r_leo_predecessor_symbol(Marpa_Recognizer r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8014 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8017 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8018 "./marpa.w"

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

/*:738*//*739:*/
#line 8032 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_leo_base_origin(Marpa_Recognizer r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8036 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8038 "./marpa.w"

EIM base_earley_item;
/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8040 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:739*//*740:*/
#line 8050 "./marpa.w"

Marpa_AHFA_State_ID _marpa_r_leo_base_state(Marpa_Recognizer r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8054 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8057 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8058 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:740*//*743:*/
#line 8096 "./marpa.w"

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
/*:743*//*744:*/
#line 8116 "./marpa.w"

PRIVATE PIM first_pim_of_es_by_isyid(ES set,ISYID isyid)
{
PIM*pim_isy_p= pim_isy_p_find(set,isyid);
return pim_isy_p?*pim_isy_p:NULL;
}

/*:744*//*747:*/
#line 8146 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_postdot_symbol_trace(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8151 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_isy_p;
PIM pim;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8155 "./marpa.w"

/*748:*/
#line 8172 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:748*/
#line 8156 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8157 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 8158 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 8159 "./marpa.w"

if(!current_es){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
pim_isy_p= PIM_ISY_P_of_ES_by_ISYID(current_es,ISYID_by_XSYID(xsy_id));
pim= *pim_isy_p;
if(!pim)return-1;
r->t_trace_pim_isy_p= pim_isy_p;
r->t_trace_postdot_item= pim;
return xsy_id;
}

/*:747*//*749:*/
#line 8182 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_postdot_item_trace(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8186 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8189 "./marpa.w"

PIM*pim_isy_p;
/*748:*/
#line 8172 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:748*/
#line 8191 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8192 "./marpa.w"

if(!current_earley_set){
/*714:*/
#line 7729 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:714*/
#line 8194 "./marpa.w"

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

/*:749*//*750:*/
#line 8213 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_postdot_item_trace(Marpa_Recognizer r)
{
const XSYID no_more_postdot_symbols= -1;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8218 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_isy_p;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8222 "./marpa.w"


pim_isy_p= r->t_trace_pim_isy_p;
pim= r->t_trace_postdot_item;
/*748:*/
#line 8172 "./marpa.w"

r->t_trace_pim_isy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:748*/
#line 8226 "./marpa.w"

if(!pim_isy_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8231 "./marpa.w"

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

/*:750*//*751:*/
#line 8251 "./marpa.w"

Marpa_AHFA_State_ID _marpa_r_postdot_item_symbol(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8254 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8256 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8257 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_ISYID_of_PIM(postdot_item);
}


/*:751*//*767:*/
#line 8379 "./marpa.w"
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

/*:767*//*772:*/
#line 8457 "./marpa.w"

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

/*:772*//*773:*/
#line 8487 "./marpa.w"

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

/*:773*//*775:*/
#line 8536 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*776:*/
#line 8553 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(r->t_obs,sizeof(*new_link));
*new_link= *SRCL_of_EIM(item);
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_SRCL_of_EIM(item)= NULL;
LV_First_Token_SRCL_of_EIM(item)= new_link;
}

/*:776*/
#line 8544 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*777:*/
#line 8561 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(r->t_obs,sizeof(*new_link));
*new_link= *SRCL_of_EIM(item);
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_SRCL_of_EIM(item)= new_link;
LV_First_Token_SRCL_of_EIM(item)= NULL;
}

/*:777*/
#line 8546 "./marpa.w"

return;
case SOURCE_IS_LEO:/*778:*/
#line 8569 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(r->t_obs,sizeof(*new_link));
*new_link= *SRCL_of_EIM(item);
LV_First_Leo_SRCL_of_EIM(item)= new_link;
LV_First_Completion_SRCL_of_EIM(item)= NULL;
LV_First_Token_SRCL_of_EIM(item)= NULL;
}

/*:778*/
#line 8548 "./marpa.w"

return;
}
}

/*:775*//*783:*/
#line 8598 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_token_link_trace(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8601 "./marpa.w"

SRCL source_link;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8605 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8606 "./marpa.w"

/*797:*/
#line 8793 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:797*/
#line 8607 "./marpa.w"

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

/*:783*//*786:*/
#line 8639 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_token_link_trace(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8642 "./marpa.w"

SRCL source_link;
EIM item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8645 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8646 "./marpa.w"

/*797:*/
#line 8793 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:797*/
#line 8647 "./marpa.w"

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

/*:786*//*788:*/
#line 8669 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_completion_link_trace(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8672 "./marpa.w"

SRCL source_link;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8676 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8677 "./marpa.w"

/*797:*/
#line 8793 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:797*/
#line 8678 "./marpa.w"

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

/*:788*//*791:*/
#line 8709 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_completion_link_trace(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8712 "./marpa.w"

SRCL source_link;
EIM item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8715 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8716 "./marpa.w"

/*797:*/
#line 8793 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:797*/
#line 8717 "./marpa.w"

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

/*:791*//*793:*/
#line 8739 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_leo_link_trace(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8743 "./marpa.w"

SRCL source_link;
EIM item= r->t_trace_earley_item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8746 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8747 "./marpa.w"

/*797:*/
#line 8793 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:797*/
#line 8748 "./marpa.w"

source_link= First_Leo_SRCL_of_EIM(item);
if(source_link){
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_source_link= source_link;
return Cause_AHFAID_of_SRCL(source_link);
}
trace_source_link_clear(r);
return-1;
}

/*:793*//*796:*/
#line 8767 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_leo_link_trace(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8771 "./marpa.w"

SRCL source_link;
EIM item;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8774 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8775 "./marpa.w"

/*797:*/
#line 8793 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:797*/
#line 8776 "./marpa.w"

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

/*:796*//*798:*/
#line 8802 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:798*//*799:*/
#line 8817 "./marpa.w"

AHFAID _marpa_r_source_predecessor_state(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8820 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8823 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8824 "./marpa.w"

source_type= r->t_trace_source_type;
/*806:*/
#line 8968 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:806*/
#line 8826 "./marpa.w"

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

/*:799*//*800:*/
#line 8858 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_token(Marpa_Recognizer r,int*value_p)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8861 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8864 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8865 "./marpa.w"

source_type= r->t_trace_source_type;
/*806:*/
#line 8968 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:806*/
#line 8867 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRCL(source_link);
if(value_p)*value_p= Value_of_TOK(token);
return ISYID_of_TOK(token);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:800*//*802:*/
#line 8890 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_leo_transition_symbol(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8893 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8896 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8897 "./marpa.w"

source_type= r->t_trace_source_type;
/*806:*/
#line 8968 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:806*/
#line 8899 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_ISYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:802*//*805:*/
#line 8936 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_source_middle(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 8939 "./marpa.w"

const EARLEME no_predecessor= -1;
unsigned int source_type;
SRCL source_link;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 8943 "./marpa.w"

/*1362:*/
#line 16139 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 16140 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 16141 "./marpa.w"


/*:1362*/
#line 8944 "./marpa.w"

source_type= r->t_trace_source_type;
/*806:*/
#line 8968 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:806*/
#line 8946 "./marpa.w"

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

/*:805*//*821:*/
#line 9075 "./marpa.w"

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

/*:821*//*823:*/
#line 9119 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= ISYID_of_ALT(a)-ISYID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:823*//*824:*/
#line 9136 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:824*//*825:*/
#line 9151 "./marpa.w"

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

/*:825*//*826:*/
#line 9170 "./marpa.w"
int marpa_r_start_input(Marpa_Recognizer r)
{
int return_value= 1;
ES set0;
EIK_Object key;
AHFA state;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 9176 "./marpa.w"

/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 9177 "./marpa.w"

/*1359:*/
#line 16123 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1359*/
#line 9178 "./marpa.w"

{
/*827:*/
#line 9225 "./marpa.w"

const ISYID isy_count= ISY_Count_of_G(g);
const ISYID xsy_count= XSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(isy_count);
/*:827*/
#line 9180 "./marpa.w"

Current_Earleme_of_R(r)= 0;
/*833:*/
#line 9267 "./marpa.w"

{
XSYID xsy_id;
r->t_valued_terminal= lbv_obs_new0(r->t_obs,xsy_count);
r->t_unvalued_terminal= lbv_obs_new0(r->t_obs,xsy_count);
r->t_valued= lbv_obs_new0(r->t_obs,xsy_count);
r->t_unvalued= lbv_obs_new0(r->t_obs,xsy_count);
r->t_valued_locked= lbv_obs_new0(r->t_obs,xsy_count);
for(xsy_id= 0;xsy_id<xsy_count;xsy_id++)
{
const XSY xsy= XSY_by_ID(xsy_id);
if(XSY_is_Valued_Locked(xsy))
{
lbv_bit_set(r->t_valued_locked,xsy_id);
}
if(XSY_is_Valued(xsy))
{
lbv_bit_set(r->t_valued,xsy_id);
if(XSY_is_Terminal(xsy))
{
lbv_bit_set(r->t_valued_terminal,xsy_id);
}
}
else
{
lbv_bit_set(r->t_unvalued,xsy_id);
if(XSY_is_Terminal(xsy))
{
lbv_bit_set(r->t_unvalued_terminal,xsy_id);
}
}
}
}

/*:833*/
#line 9182 "./marpa.w"

G_EVENTS_CLEAR(g);
if(G_is_Trivial(g)){
/*670:*/
#line 7308 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:670*/
#line 9185 "./marpa.w"

goto CLEANUP;
}
r->t_lbv_xsyid_completion_event_is_active= 
lbv_clone(r->t_obs,g->t_lbv_xsyid_is_completion_event,xsy_count);
r->t_lbv_xsyid_nulled_event_is_active= 
lbv_clone(r->t_obs,g->t_lbv_xsyid_is_nulled_event,xsy_count);
r->t_lbv_xsyid_prediction_event_is_active= 
lbv_clone(r->t_obs,g->t_lbv_xsyid_is_prediction_event,xsy_count);
r->t_active_event_count= 
bv_count(g->t_lbv_xsyid_is_completion_event)
+bv_count(g->t_lbv_xsyid_is_nulled_event)
+bv_count(g->t_lbv_xsyid_is_prediction_event);
Input_Phase_of_R(r)= R_DURING_INPUT;
psar_reset(Dot_PSAR_of_R(r));
/*874:*/
#line 9952 "./marpa.w"

r->t_bv_lim_symbols= bv_obs_create(r->t_obs,isy_count);
r->t_bv_pim_symbols= bv_obs_create(r->t_obs,isy_count);
r->t_pim_workarea= my_obstack_new(r->t_obs,void*,isy_count);
/*:874*//*895:*/
#line 10219 "./marpa.w"

r->t_lim_chain= my_obstack_new(r->t_obs,void*,2*isy_count);
/*:895*/
#line 9200 "./marpa.w"

/*842:*/
#line 9478 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT2(r->t_eim_work_stack,EIM);
/*:842*//*846:*/
#line 9489 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT2(r->t_completion_stack,EIM);
/*:846*/
#line 9201 "./marpa.w"

set0= earley_set_new(r,0);
Latest_ES_of_R(r)= set0;
First_ES_of_R(r)= set0;
state= AHFA_of_G_by_ID(g,0);
key.t_origin= set0;
key.t_state= state;
key.t_set= set0;
earley_item_create(r,key);
state= Empty_Transition_of_AHFA(state);
if(state){
key.t_state= state;
earley_item_create(r,key);
}
postdot_items_create(r,bv_ok_for_chain,set0);
earley_set_update_items(r,set0);
r->t_is_using_leo= r->t_use_leo_flag;
trigger_events(r);
CLEANUP:;
/*828:*/
#line 9229 "./marpa.w"

bv_free(bv_ok_for_chain);

/*:828*/
#line 9220 "./marpa.w"

}
return return_value;
}

/*:826*//*834:*/
#line 9307 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID token_xsy_id,
int value,
int length)
{
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 9314 "./marpa.w"

ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
ISYID token_isyid;
if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT))
{
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT;
}
if(UNLIKELY(!xsy_id_is_valid(g,token_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return MARPA_ERR_INVALID_SYMBOL_ID;
}
/*835:*/
#line 9336 "./marpa.w"
{
const XSY_Const token= XSY_by_ID(token_xsy_id);
if(length<=0){
MARPA_ERROR(MARPA_ERR_TOKEN_LENGTH_LE_ZERO);
return MARPA_ERR_TOKEN_LENGTH_LE_ZERO;
}
if(length>=EARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_TOKEN_TOO_LONG);
return MARPA_ERR_TOKEN_TOO_LONG;
}
if(value&&UNLIKELY(!lbv_bit_test(r->t_valued_terminal,token_xsy_id)))
{
if(!XSY_is_Terminal(token)){
MARPA_ERROR(MARPA_ERR_TOKEN_IS_NOT_TERMINAL);
return MARPA_ERR_TOKEN_IS_NOT_TERMINAL;
}
if(lbv_bit_test(r->t_valued_locked,token_xsy_id)){
MARPA_ERROR(MARPA_ERR_SYMBOL_VALUED_CONFLICT);
return MARPA_ERR_SYMBOL_VALUED_CONFLICT;
}
lbv_bit_set(r->t_valued_locked,token_xsy_id);
lbv_bit_set(r->t_valued_terminal,token_xsy_id);
lbv_bit_set(r->t_valued,token_xsy_id);
}
if(!value&&UNLIKELY(!lbv_bit_test(r->t_unvalued_terminal,token_xsy_id)))
{
if(!XSY_is_Terminal(token)){
MARPA_ERROR(MARPA_ERR_TOKEN_IS_NOT_TERMINAL);
return MARPA_ERR_TOKEN_IS_NOT_TERMINAL;
}
if(lbv_bit_test(r->t_valued_locked,token_xsy_id)){
MARPA_ERROR(MARPA_ERR_SYMBOL_VALUED_CONFLICT);
return MARPA_ERR_SYMBOL_VALUED_CONFLICT;
}
lbv_bit_set(r->t_valued_locked,token_xsy_id);
lbv_bit_set(r->t_unvalued_terminal,token_xsy_id);
lbv_bit_set(r->t_unvalued,token_xsy_id);
}
}

/*:835*/
#line 9329 "./marpa.w"

/*838:*/
#line 9396 "./marpa.w"

{
ISY token_isy= ISY_by_XSYID(token_xsy_id);
if(UNLIKELY(!token_isy))
{
MARPA_ERROR(MARPA_ERR_INACCESSIBLE_TOKEN);
return MARPA_ERR_INACCESSIBLE_TOKEN;
}
token_isyid= ID_of_ISY(token_isy);
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)
{
MARPA_ERROR(MARPA_ERR_NO_TOKEN_EXPECTED_HERE);
return MARPA_ERR_NO_TOKEN_EXPECTED_HERE;
}
if(!First_PIM_of_ES_by_ISYID(current_earley_set,token_isyid))
{
MARPA_ERROR(MARPA_ERR_UNEXPECTED_TOKEN_ID);
return MARPA_ERR_UNEXPECTED_TOKEN_ID;
}
}

/*:838*/
#line 9330 "./marpa.w"

/*836:*/
#line 9376 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return MARPA_ERR_PARSE_TOO_LONG;
}
}

/*:836*/
#line 9331 "./marpa.w"

/*839:*/
#line 9434 "./marpa.w"

{
TOK token;
ALT_Object alternative;
struct obstack*const token_obstack= TOK_Obs_of_I(input);
if(value)
{
my_obstack_reserve(TOK_Obs_of_I(input),sizeof(*token));
token= my_obstack_base(token_obstack);
ISYID_of_TOK(token)= token_isyid;
Type_of_TOK(token)= VALUED_TOKEN_OR_NODE;
Value_of_TOK(token)= value;
}
else
{
my_obstack_reserve(TOK_Obs_of_I(input),sizeof(token->t_unvalued));
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
MARPA_ERROR(MARPA_ERR_DUPLICATE_TOKEN);
return MARPA_ERR_DUPLICATE_TOKEN;
}
token= my_obstack_finish(token_obstack);
}

/*:839*/
#line 9332 "./marpa.w"

return MARPA_ERR_NONE;
}

/*:834*//*852:*/
#line 9515 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 9519 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 9520 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;




EARLEME return_value= -2;

/*1361:*/
#line 16133 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1361*/
#line 9530 "./marpa.w"

{
int count_of_expected_terminals;
/*853:*/
#line 9571 "./marpa.w"

const ISYID isy_count= ISY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(isy_count);
struct obstack*const earleme_complete_obs= my_obstack_init;
/*:853*/
#line 9533 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_isyid_is_expected);
/*855:*/
#line 9579 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*670:*/
#line 7308 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:670*/
#line 9583 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:855*/
#line 9537 "./marpa.w"

/*857:*/
#line 9601 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack||current_earleme!=End_Earleme_of_ALT(top_of_stack))
{
return_value= 0;
goto CLEANUP;
}
}

/*:857*/
#line 9538 "./marpa.w"

/*856:*/
#line 9591 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:856*/
#line 9539 "./marpa.w"

/*858:*/
#line 9610 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*859:*/
#line 9617 "./marpa.w"

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

/*:859*/
#line 9614 "./marpa.w"

}

/*:858*/
#line 9540 "./marpa.w"

/*860:*/
#line 9644 "./marpa.w"
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

/*:860*/
#line 9541 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*861:*/
#line 9663 "./marpa.w"

{
int count= Complete_ISY_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
int isy_ix;
for(isy_ix= 0;isy_ix<count;isy_ix++)
{
ISYID complete_isyid= Complete_ISYID_of_EIM(cause,isy_ix);
/*862:*/
#line 9675 "./marpa.w"

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
/*863:*/
#line 9698 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_ISYID(predecessor,complete_isyid);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*864:*/
#line 9714 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:864*/
#line 9707 "./marpa.w"

}
/*865:*/
#line 9721 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:865*/
#line 9709 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:863*/
#line 9686 "./marpa.w"

}
else
{
/*866:*/
#line 9731 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*864:*/
#line 9714 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:864*/
#line 9740 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:866*/
#line 9690 "./marpa.w"

break;


}
}
}

/*:862*/
#line 9671 "./marpa.w"

}
}

/*:861*/
#line 9544 "./marpa.w"

}
postdot_items_create(r,bv_ok_for_chain,current_earley_set);




count_of_expected_terminals= bv_count(r->t_bv_isyid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{
/*670:*/
#line 7308 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:670*/
#line 9555 "./marpa.w"

}
earley_set_update_items(r,current_earley_set);
if(r->t_active_event_count> 0){
trigger_events(r);
}
return_value= G_EVENT_COUNT(g);
CLEANUP:;
/*854:*/
#line 9575 "./marpa.w"

bv_free(bv_ok_for_chain);
my_obstack_free(earleme_complete_obs);

/*:854*/
#line 9563 "./marpa.w"

}
return return_value;
}

/*:852*//*867:*/
#line 9745 "./marpa.w"

PRIVATE void trigger_events(RECCE r)
{
const GRAMMAR g= G_of_R(r);
const ES current_earley_set= Latest_ES_of_R(r);
unsigned int min,max,start;
int eim_ix;
struct obstack*const trigger_events_obs= my_obstack_init;
const EIM*eims= EIMs_of_ES(current_earley_set);
const XSYID xsy_count= XSY_Count_of_G(g);
const AHFAID ahfa_count= AHFA_Count_of_G(g);
Bit_Vector bv_completion_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_nulled_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_prediction_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_ahfa_event_trigger= 
bv_obs_create(trigger_events_obs,ahfa_count);
const int working_earley_item_count= EIM_Count_of_ES(current_earley_set);
for(eim_ix= 0;eim_ix<working_earley_item_count;eim_ix++)
{
const EIM eim= eims[eim_ix];
const AHFA top_ahfa= AHFA_of_EIM(eim);
const AHFAID top_ahfaid= ID_of_AHFA(top_ahfa);
if(AHFA_has_Event(top_ahfa))
{

bv_bit_set(bv_ahfa_event_trigger,top_ahfaid);
}
{

const SRCL first_leo_source_link= First_Leo_SRCL_of_EIM(eim);
SRCL setup_source_link;
for(setup_source_link= first_leo_source_link;setup_source_link;
setup_source_link= Next_SRCL_of_SRCL(setup_source_link))
{
int cil_ix;
const LIM lim= LIM_of_SRCL(setup_source_link);
const CIL event_ahfaids= CIL_of_LIM(lim);
const int event_ahfa_count= Count_of_CIL(event_ahfaids);
for(cil_ix= 0;cil_ix<event_ahfa_count;cil_ix++)
{
const ISYID leo_path_ahfaid= 
Item_of_CIL(event_ahfaids,cil_ix);
bv_bit_set(bv_ahfa_event_trigger,leo_path_ahfaid);


}
}
}
}

for(start= 0;bv_scan(bv_ahfa_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_ahfaid;
for(event_ahfaid= (ISYID)min;event_ahfaid<=(ISYID)max;
event_ahfaid++)
{
int cil_ix;
const AHFA event_ahfa= AHFA_by_ID(event_ahfaid);
{
const CIL completion_xsyids= 
Completion_XSYIDs_of_AHFA(event_ahfa);
const int event_xsy_count= Count_of_CIL(completion_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(completion_xsyids,cil_ix);
bv_bit_set(bv_completion_event_trigger,event_xsyid);
}
}
{
const CIL nulled_xsyids= Nulled_XSYIDs_of_AHFA(event_ahfa);
const int event_xsy_count= Count_of_CIL(nulled_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(nulled_xsyids,cil_ix);
bv_bit_set(bv_nulled_event_trigger,event_xsyid);
}
}
{
const CIL prediction_xsyids= 
Prediction_XSYIDs_of_AHFA(event_ahfa);
const int event_xsy_count= Count_of_CIL(prediction_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(prediction_xsyids,cil_ix);
bv_bit_set(bv_prediction_event_trigger,event_xsyid);
}
}
}
}

for(start= 0;bv_scan(bv_completion_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_xsyid;
for(event_xsyid= (ISYID)min;event_xsyid<=(ISYID)max;
event_xsyid++)
{
if(lbv_bit_test
(r->t_lbv_xsyid_completion_event_is_active,event_xsyid))
{
int_event_new(g,MARPA_EVENT_SYMBOL_COMPLETED,event_xsyid);
}
}
}
for(start= 0;bv_scan(bv_nulled_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_xsyid;
for(event_xsyid= (ISYID)min;event_xsyid<=(ISYID)max;
event_xsyid++)
{
if(lbv_bit_test
(r->t_lbv_xsyid_nulled_event_is_active,event_xsyid))
{
int_event_new(g,MARPA_EVENT_SYMBOL_NULLED,event_xsyid);
}

}
}
for(start= 0;bv_scan(bv_prediction_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_xsyid;
for(event_xsyid= (ISYID)min;event_xsyid<=(ISYID)max;
event_xsyid++)
{
if(lbv_bit_test
(r->t_lbv_xsyid_prediction_event_is_active,event_xsyid))
{
int_event_new(g,MARPA_EVENT_SYMBOL_PREDICTED,event_xsyid);
}
}
}
my_obstack_free(trigger_events_obs);
}

/*:867*//*868:*/
#line 9885 "./marpa.w"

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

/*:868*//*869:*/
#line 9906 "./marpa.w"

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

/*:869*//*876:*/
#line 9959 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,
Bit_Vector bv_ok_for_chain,
ES current_earley_set)
{
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 9965 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
/*875:*/
#line 9956 "./marpa.w"

bv_clear(r->t_bv_lim_symbols);
bv_clear(r->t_bv_pim_symbols);
/*:875*/
#line 9967 "./marpa.w"

/*877:*/
#line 9979 "./marpa.w"
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

/*:877*/
#line 9968 "./marpa.w"

if(r->t_is_using_leo){
/*880:*/
#line 10024 "./marpa.w"

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
/*881:*/
#line 10058 "./marpa.w"
{
LIM new_lim;
new_lim= my_obstack_alloc(r->t_obs,sizeof(*new_lim));
Postdot_ISYID_of_LIM(new_lim)= isyid;
EIM_of_PIM(new_lim)= NULL;
Predecessor_LIM_of_LIM(new_lim)= NULL;
Origin_of_LIM(new_lim)= NULL;
CIL_of_LIM(new_lim)= NULL;
Top_AHFA_of_LIM(new_lim)= base_to_ahfa;
Base_EIM_of_LIM(new_lim)= leo_base;
ES_of_LIM(new_lim)= current_earley_set;
Next_PIM_of_LIM(new_lim)= this_pim;
r->t_pim_workarea[isyid]= new_lim;
bv_bit_set(r->t_bv_lim_symbols,(unsigned int)isyid);
}

/*:881*/
#line 10044 "./marpa.w"

}
}
}
}
}
}

/*:880*/
#line 9970 "./marpa.w"

/*890:*/
#line 10143 "./marpa.w"
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

/*893:*/
#line 10201 "./marpa.w"
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

/*:893*/
#line 10160 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*901:*/
#line 10308 "./marpa.w"

{
const AHFA top_ahfa= Top_AHFA_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);
CIL_of_LIM(lim_to_process)= predecessor_cil;


Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHFA(top_ahfa)> Count_of_CIL(predecessor_cil))
{
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);


const CIL base_to_ahfa_event_ahfaids= 
Event_AHFAIDs_of_AHFA(base_to_ahfa);
if(Count_of_CIL(base_to_ahfa_event_ahfaids))
{
CIL new_cil= cil_merge_one(&g->t_cilar,predecessor_cil,
Item_of_CIL
(base_to_ahfa_event_ahfaids,0));
if(new_cil)
{
CIL_of_LIM(lim_to_process)= new_cil;
}
}
}
Top_AHFA_of_LIM(lim_to_process)= top_ahfa;
}

/*:901*/
#line 10162 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*903:*/
#line 10351 "./marpa.w"
{
const AHFA top_AHFA= Top_AHFA_of_LIM(lim_to_process);
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
CIL_of_LIM(lim_to_process)= Event_AHFAIDs_of_AHFA(top_AHFA);
}

/*:903*/
#line 10168 "./marpa.w"

continue;
}
/*896:*/
#line 10221 "./marpa.w"
{
int lim_chain_ix;
/*899:*/
#line 10241 "./marpa.w"

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

/*893:*/
#line 10201 "./marpa.w"
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

/*:893*/
#line 10271 "./marpa.w"


r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,
(unsigned int)postdot_isyid_of_lim_to_process);


if(!predecessor_lim)
break;

if(LIM_is_Populated(predecessor_lim))
break;



}
}

/*:899*/
#line 10223 "./marpa.w"

/*900:*/
#line 10291 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= r->t_lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*901:*/
#line 10308 "./marpa.w"

{
const AHFA top_ahfa= Top_AHFA_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);
CIL_of_LIM(lim_to_process)= predecessor_cil;


Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHFA(top_ahfa)> Count_of_CIL(predecessor_cil))
{
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);


const CIL base_to_ahfa_event_ahfaids= 
Event_AHFAIDs_of_AHFA(base_to_ahfa);
if(Count_of_CIL(base_to_ahfa_event_ahfaids))
{
CIL new_cil= cil_merge_one(&g->t_cilar,predecessor_cil,
Item_of_CIL
(base_to_ahfa_event_ahfaids,0));
if(new_cil)
{
CIL_of_LIM(lim_to_process)= new_cil;
}
}
}
Top_AHFA_of_LIM(lim_to_process)= top_ahfa;
}

/*:901*/
#line 10295 "./marpa.w"

}else{
/*903:*/
#line 10351 "./marpa.w"
{
const AHFA top_AHFA= Top_AHFA_of_LIM(lim_to_process);
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
CIL_of_LIM(lim_to_process)= Event_AHFAIDs_of_AHFA(top_AHFA);
}

/*:903*/
#line 10297 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:900*/
#line 10224 "./marpa.w"

}

/*:896*/
#line 10171 "./marpa.w"

}
}
}

/*:890*/
#line 9971 "./marpa.w"

}
/*904:*/
#line 10358 "./marpa.w"
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
if(lbv_bit_test(r->t_isy_expected_is_event,isyid)){
XSY xsy= Source_XSY_of_ISYID(isyid);
int_event_new(g,MARPA_EVENT_SYMBOL_EXPECTED,ID_of_XSY(xsy));
}
if(this_pim)postdot_array[postdot_array_ix++]= this_pim;
}
}
}

/*:904*/
#line 9973 "./marpa.w"

bv_and(r->t_bv_isyid_is_expected,r->t_bv_pim_symbols,g->t_bv_isyid_is_terminal);
}

/*:876*//*922:*/
#line 10530 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
stack->t_obs= my_obstack_init;
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:922*//*923:*/
#line 10538 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:923*//*924:*/
#line 10544 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)my_obstack_free(stack->t_obs);
stack->t_base= NULL;
}

/*:924*//*925:*/
#line 10551 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= my_obstack_alloc(stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:925*//*926:*/
#line 10561 "./marpa.w"

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

/*:926*//*927:*/
#line 10577 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:927*//*931:*/
#line 10640 "./marpa.w"

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

/*:931*//*967:*/
#line 11209 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const ISYID postdot_isyid= Postdot_ISYID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_ISYID(base,postdot_isyid);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:967*//*968:*/
#line 11221 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:968*//*974:*/
#line 11325 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11330 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11331 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11332 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11333 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11334 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:974*//*975:*/
#line 11338 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11343 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11344 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11345 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11346 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11347 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:975*//*976:*/
#line 11351 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11356 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11357 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11358 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11359 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11360 "./marpa.w"

return ID_of_IRL(IRL_of_OR(or_node));
}

/*:976*//*977:*/
#line 11364 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11369 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11370 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11371 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11372 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11373 "./marpa.w"

return Position_of_OR(or_node);
}

/*:977*//*978:*/
#line 11377 "./marpa.w"

int _marpa_b_or_node_is_whole(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11382 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11383 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11384 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11385 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11386 "./marpa.w"

return Position_of_OR(or_node)>=Length_of_IRL(IRL_of_OR(or_node))?1:0;
}

/*:978*//*979:*/
#line 11390 "./marpa.w"

int _marpa_b_or_node_is_semantic(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11395 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11396 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11397 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11398 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11399 "./marpa.w"

return!IRL_has_Virtual_LHS(IRL_of_OR(or_node));
}

/*:979*//*980:*/
#line 11403 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11408 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11409 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11410 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11411 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11412 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:980*//*981:*/
#line 11416 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11421 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11422 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11423 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11424 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11425 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:981*//*982:*/
#line 11430 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11435 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11436 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11437 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11438 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11439 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:982*//*985:*/
#line 11453 "./marpa.w"

int _marpa_o_or_node_and_node_count(Marpa_Order o,
Marpa_Or_Node_ID or_node_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11457 "./marpa.w"

/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 11458 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11459 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11460 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[0];
}
{
OR or_node;
/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11469 "./marpa.w"

return AND_Count_of_OR(or_node);
}
}

/*:985*//*986:*/
#line 11474 "./marpa.w"

int _marpa_o_or_node_and_node_id_by_ix(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11478 "./marpa.w"

/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 11479 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11480 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 11481 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[1+ix];
}
{
OR or_node;
/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 11490 "./marpa.w"

return First_ANDID_of_OR(or_node)+ix;
}
}

/*:986*//*990:*/
#line 11538 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= my_obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:990*//*992:*/
#line 11561 "./marpa.w"

PRIVATE
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:992*//*1019:*/
#line 11981 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11984 "./marpa.w"

/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11985 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 11986 "./marpa.w"

return AND_Count_of_B(b);
}

/*:1019*//*1021:*/
#line 12012 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12017 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12018 "./marpa.w"

/*1020:*/
#line 11990 "./marpa.w"

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

/*:1020*/
#line 12019 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1021*//*1022:*/
#line 12023 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12028 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12029 "./marpa.w"

/*1020:*/
#line 11990 "./marpa.w"

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

/*:1020*/
#line 12030 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1022*//*1023:*/
#line 12039 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12044 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12045 "./marpa.w"

/*1020:*/
#line 11990 "./marpa.w"

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

/*:1020*/
#line 12046 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1023*//*1024:*/
#line 12055 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12060 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12061 "./marpa.w"

/*1020:*/
#line 11990 "./marpa.w"

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

/*:1020*/
#line 12062 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const XSYID symbol_id= 
OR_is_Token(cause_or)?ISYID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1024*//*1025:*/
#line 12071 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK token;
AND and_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12077 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12078 "./marpa.w"

/*1020:*/
#line 11990 "./marpa.w"

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

/*:1020*/
#line 12079 "./marpa.w"

token= and_node_token(and_node);
if(token){
if(value_p)
*value_p= Value_of_TOK(token);
return ISYID_of_TOK(token);
}
return-1;
}
/*:1025*//*1026:*/
#line 12088 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:1026*//*1027:*/
#line 12106 "./marpa.w"

Marpa_Earley_Set_ID _marpa_b_and_node_middle(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12111 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12112 "./marpa.w"

/*1020:*/
#line 11990 "./marpa.w"

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

/*:1020*/
#line 12113 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
if(predecessor_or)
{
return ES_Ord_of_OR(predecessor_or);
}
}
return Origin_Ord_of_OR(OR_of_AND(and_node));
}

/*:1027*//*1036:*/
#line 12159 "./marpa.w"

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

/*:1036*//*1037:*/
#line 12176 "./marpa.w"

int marpa_r_progress_report_start(
Marpa_Recognizer r,
Marpa_Earley_Set_ID set_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12181 "./marpa.w"

ES earley_set;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 12183 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12184 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 12185 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
/*1031:*/
#line 12133 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(TREE_of_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:1031*/
#line 12198 "./marpa.w"

{
const AVL_TREE report_tree= 
_marpa_avl_create(report_item_cmp,NULL,alignof(PROGRESS));
const EIM*const earley_items= EIMs_of_ES(earley_set);
const int earley_item_count= EIM_Count_of_ES(earley_set);
int earley_item_id;
for(earley_item_id= 0;earley_item_id<earley_item_count;
earley_item_id++)
{
/*1039:*/
#line 12228 "./marpa.w"

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
/*1040:*/
#line 12292 "./marpa.w"

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

/*:1040*/
#line 12287 "./marpa.w"

}
NEXT_EARLEY_ITEM:;
}

/*:1039*/
#line 12208 "./marpa.w"

}
r->t_progress_report_traverser= _marpa_avl_t_init(report_tree);
return marpa_avl_count(report_tree);
}
}
/*:1037*//*1038:*/
#line 12215 "./marpa.w"

int marpa_r_progress_report_reset(Marpa_Recognizer r)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12218 "./marpa.w"

AVL_TRAV traverser= r->t_progress_report_traverser;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 12220 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12221 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 12222 "./marpa.w"

/*1043:*/
#line 12373 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:1043*/
#line 12223 "./marpa.w"

_marpa_avl_t_reset(traverser);
return 1;
}

/*:1038*//*1041:*/
#line 12336 "./marpa.w"

int marpa_r_progress_report_finish(Marpa_Recognizer r){
const int success= 1;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12339 "./marpa.w"

/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 12340 "./marpa.w"

const AVL_TRAV traverser= r->t_progress_report_traverser;
/*1043:*/
#line 12373 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:1043*/
#line 12342 "./marpa.w"

/*1031:*/
#line 12133 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(TREE_of_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:1031*/
#line 12343 "./marpa.w"

return success;
}

/*:1041*//*1042:*/
#line 12347 "./marpa.w"

Marpa_Rule_ID marpa_r_progress_item(
Marpa_Recognizer r,int*position,Marpa_Earley_Set_ID*origin
){
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12351 "./marpa.w"

PROGRESS report_item;
AVL_TRAV traverser;
/*622:*/
#line 6869 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:622*/
#line 12354 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12355 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 12356 "./marpa.w"

traverser= r->t_progress_report_traverser;
if(UNLIKELY(!position||!origin)){
MARPA_ERROR(MARPA_ERR_POINTER_ARG_NULL);
return failure_indicator;
}
/*1043:*/
#line 12373 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:1043*/
#line 12362 "./marpa.w"

report_item= _marpa_avl_t_next(traverser);
if(!report_item){
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_EXHAUSTED);
return-1;
}
*position= Position_of_PROGRESS(report_item);
*origin= Origin_of_PROGRESS(report_item);
return RULEID_of_PROGRESS(report_item);
}

/*:1042*//*1053:*/
#line 12417 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1345:*/
#line 16044 "./marpa.w"
void*const failure_indicator= NULL;
/*:1345*/
#line 12421 "./marpa.w"

/*1056:*/
#line 12479 "./marpa.w"

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

/*:1056*//*1059:*/
#line 12503 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:1059*/
#line 12422 "./marpa.w"

INPUT input;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12424 "./marpa.w"

/*1360:*/
#line 16128 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1360*/
#line 12425 "./marpa.w"

{
struct obstack*const obstack= my_obstack_init;
b= my_obstack_new(obstack,struct marpa_bocage,1);
OBS_of_B(b)= obstack;
}
/*954:*/
#line 10983 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:954*//*1055:*/
#line 12474 "./marpa.w"

Valued_BV_of_B(b)= lbv_clone(b->t_obs,r->t_valued,xsy_count);
Valued_Locked_BV_of_B(b)= 
lbv_clone(b->t_obs,r->t_valued_locked,xsy_count);

/*:1055*//*1070:*/
#line 12638 "./marpa.w"

Ambiguity_Metric_of_B(b)= 1;

/*:1070*//*1074:*/
#line 12652 "./marpa.w"

b->t_ref_count= 1;
/*:1074*//*1081:*/
#line 12712 "./marpa.w"

B_is_Nulling(b)= 0;
/*:1081*/
#line 12431 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*1060:*/
#line 12506 "./marpa.w"

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

/*:1060*/
#line 12441 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(XSY_by_ID(g->t_start_xsy_id)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*1064:*/
#line 12580 "./marpa.w"

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

/*:1064*/
#line 12449 "./marpa.w"

if(!start_eim)goto NO_PARSE;
bocage_setup_obs= my_obstack_init;
/*1061:*/
#line 12528 "./marpa.w"

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

/*:1061*/
#line 12452 "./marpa.w"

/*929:*/
#line 10599 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*930:*/
#line 10627 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:930*/
#line 10608 "./marpa.w"

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
/*932:*/
#line 10668 "./marpa.w"

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
/*930:*/
#line 10627 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:930*/
#line 10696 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:932*/
#line 10621 "./marpa.w"

/*934:*/
#line 10726 "./marpa.w"

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
/*930:*/
#line 10627 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:930*/
#line 10762 "./marpa.w"

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
/*930:*/
#line 10627 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:930*/
#line 10775 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:934*/
#line 10622 "./marpa.w"

/*935:*/
#line 10785 "./marpa.w"

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
/*930:*/
#line 10627 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:930*/
#line 10804 "./marpa.w"

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
/*930:*/
#line 10627 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:930*/
#line 10823 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
}
}

/*:935*/
#line 10623 "./marpa.w"

}
}

/*:929*/
#line 12453 "./marpa.w"

/*956:*/
#line 11001 "./marpa.w"

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
/*1327:*/
#line 15832 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1327*/
#line 11021 "./marpa.w"

/*957:*/
#line 11029 "./marpa.w"

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
/*958:*/
#line 11049 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1327:*/
#line 15832 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1327*/
#line 11059 "./marpa.w"

/*960:*/
#line 11077 "./marpa.w"

{
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const IRL irl= IRL_of_AIM(ahfa_item);
/*961:*/
#line 11106 "./marpa.w"

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


/*:961*/
#line 11087 "./marpa.w"

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

/*:960*/
#line 11060 "./marpa.w"

/*963:*/
#line 11132 "./marpa.w"

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
/*961:*/
#line 11106 "./marpa.w"

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


/*:961*/
#line 11151 "./marpa.w"

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

/*:963*/
#line 11061 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*964:*/
#line 11169 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_EIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*966:*/
#line 11191 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const IRL path_irl= IRL_of_AIM(path_ahfa_item);
const int symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*969:*/
#line 11232 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1327:*/
#line 15832 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1327*/
#line 11239 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*961:*/
#line 11106 "./marpa.w"

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


/*:961*/
#line 11243 "./marpa.w"

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

/*:969*/
#line 11201 "./marpa.w"

/*970:*/
#line 11259 "./marpa.w"

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
/*961:*/
#line 11106 "./marpa.w"

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


/*:961*/
#line 11276 "./marpa.w"

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

/*:970*/
#line 11202 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:966*/
#line 11177 "./marpa.w"

}
}
}

/*:964*/
#line 11069 "./marpa.w"

}

/*:958*/
#line 11043 "./marpa.w"

}
}
}
}

/*:957*/
#line 11022 "./marpa.w"

/*993:*/
#line 11571 "./marpa.w"

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
/*995:*/
#line 11608 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const int work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*996:*/
#line 11624 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_EIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
EIM cause_earley_item= Cause_of_SRCL(source_link);
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*997:*/
#line 11639 "./marpa.w"

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
/*998:*/
#line 11666 "./marpa.w"

{
if(higher_path_leo_item){
/*1002:*/
#line 11710 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:1002*/
#line 11669 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:998*/
#line 11652 "./marpa.w"

/*1000:*/
#line 11680 "./marpa.w"

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

/*:1000*/
#line 11653 "./marpa.w"

previous_path_irl= path_irl;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*998:*/
#line 11666 "./marpa.w"

{
if(higher_path_leo_item){
/*1002:*/
#line 11710 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:1002*/
#line 11669 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:998*/
#line 11660 "./marpa.w"

/*1003:*/
#line 11720 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_IRL(previous_path_irl);
const int origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:1003*/
#line 11661 "./marpa.w"

previous_path_irl= path_irl;
}
}

/*:997*/
#line 11633 "./marpa.w"

}
}
}

/*:996*/
#line 11619 "./marpa.w"

/*1004:*/
#line 11730 "./marpa.w"

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
/*1005:*/
#line 11760 "./marpa.w"

{
OR dand_predecessor;
/*1006:*/
#line 11768 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1006*/
#line 11763 "./marpa.w"

draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:1005*/
#line 11752 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1004*/
#line 11620 "./marpa.w"

/*1007:*/
#line 11779 "./marpa.w"

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
/*1008:*/
#line 11819 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_IRL(IRL_of_AIM(cause_ahfa_item));
/*1006:*/
#line 11768 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1006*/
#line 11827 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:1008*/
#line 11810 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1007*/
#line 11621 "./marpa.w"

}

/*:995*/
#line 11586 "./marpa.w"

}
}
}
}
}

/*:993*/
#line 11023 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= my_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:956*/
#line 12454 "./marpa.w"

/*1016:*/
#line 11934 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*1009:*/
#line 11833 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
int or_node_id= 0;
psar_init(and_psar,irl_count+isy_count);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*1011:*/
#line 11865 "./marpa.w"

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

/*:1011*/
#line 11843 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:1009*/
#line 11937 "./marpa.w"

/*1017:*/
#line 11941 "./marpa.w"

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
Ambiguity_Metric_of_B(b)= 
MAX(Ambiguity_Metric_of_B(b),and_count_of_parent_or);
}
AND_Count_of_B(b)= and_node_id;
MARPA_ASSERT(and_node_id==unique_draft_and_node_count);
}

/*:1017*/
#line 11938 "./marpa.w"

}

/*:1016*/
#line 12455 "./marpa.w"

/*1065:*/
#line 12609 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:1065*/
#line 12456 "./marpa.w"
;
my_obstack_free(bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
input_unref(input);
if(b){
/*1077:*/
#line 12688 "./marpa.w"

/*955:*/
#line 10990 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:955*/
#line 12689 "./marpa.w"
;
/*1052:*/
#line 12413 "./marpa.w"

my_obstack_free(OBS_of_B(b));

/*:1052*/
#line 12690 "./marpa.w"
;

/*:1077*/
#line 12463 "./marpa.w"
;
}
return NULL;
}

/*:1053*//*1067:*/
#line 12622 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12625 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12626 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12627 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:1067*//*1071:*/
#line 12641 "./marpa.w"

int marpa_b_ambiguity_metric(Marpa_Bocage b)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12644 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12645 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12646 "./marpa.w"

return Ambiguity_Metric_of_B(b);
}

/*:1071*//*1075:*/
#line 12655 "./marpa.w"

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

/*:1075*//*1076:*/
#line 12673 "./marpa.w"

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

/*:1076*//*1078:*/
#line 12695 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12699 "./marpa.w"

input_unref(input);
if(b)
{
/*1077:*/
#line 12688 "./marpa.w"

/*955:*/
#line 10990 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:955*/
#line 12689 "./marpa.w"
;
/*1052:*/
#line 12413 "./marpa.w"

my_obstack_free(OBS_of_B(b));

/*:1052*/
#line 12690 "./marpa.w"
;

/*:1077*/
#line 12703 "./marpa.w"
;
}
}

/*:1078*//*1082:*/
#line 12714 "./marpa.w"

int marpa_b_is_null(Marpa_Bocage b)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12717 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12718 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12719 "./marpa.w"

return B_is_Nulling(b);
}

/*:1082*//*1089:*/
#line 12759 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1345:*/
#line 16044 "./marpa.w"
void*const failure_indicator= NULL;
/*:1345*/
#line 12762 "./marpa.w"

/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12763 "./marpa.w"

ORDER o;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12765 "./marpa.w"

o= my_slice_new(*o);
B_of_O(o)= b;
bocage_ref(b);
/*1086:*/
#line 12747 "./marpa.w"

{
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
OBS_of_O(o)= NULL;
}

/*:1086*//*1092:*/
#line 12777 "./marpa.w"

o->t_ref_count= 1;

/*:1092*//*1104:*/
#line 12865 "./marpa.w"

High_Rank_Count_of_O(o)= 1;
/*:1104*/
#line 12769 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
Ambiguity_Metric_of_O(o)= Ambiguity_Metric_of_B(b);
return o;
}

/*:1089*//*1093:*/
#line 12781 "./marpa.w"

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

/*:1093*//*1094:*/
#line 12799 "./marpa.w"

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

/*:1094*//*1095:*/
#line 12813 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 12816 "./marpa.w"

bocage_unref(b);
my_obstack_free(OBS_of_O(o));
my_slice_free(*o,o);
}

/*:1095*//*1099:*/
#line 12834 "./marpa.w"

int marpa_o_ambiguity_metric(Marpa_Order o)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12837 "./marpa.w"

/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 12838 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12839 "./marpa.w"

return Ambiguity_Metric_of_O(o);
}

/*:1099*//*1102:*/
#line 12848 "./marpa.w"

int marpa_o_is_null(Marpa_Order o)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12851 "./marpa.w"

/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 12852 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12853 "./marpa.w"

return O_is_Nulling(o);
}

/*:1102*//*1105:*/
#line 12867 "./marpa.w"

int marpa_o_high_rank_only_set(
Marpa_Order o,
int count)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12872 "./marpa.w"

/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 12873 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12874 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
if(UNLIKELY(count<0||count> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return High_Rank_Count_of_O(o)= count;
}

/*:1105*//*1106:*/
#line 12889 "./marpa.w"

int marpa_o_high_rank_only(Marpa_Order o)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12892 "./marpa.w"

/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 12893 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12894 "./marpa.w"

return High_Rank_Count_of_O(o);
}

/*:1106*//*1110:*/
#line 12931 "./marpa.w"

int marpa_o_rank(Marpa_Order o)
{
ANDID**and_node_orderings;
struct obstack*obs;
int bocage_was_reordered= 0;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12937 "./marpa.w"

/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 12938 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 12939 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*1116:*/
#line 13104 "./marpa.w"

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
}

/*:1116*/
#line 12945 "./marpa.w"

if(High_Rank_Count_of_O(o)){
/*1111:*/
#line 12960 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
OR*const or_nodes= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
int or_node_id= 0;
int ambiguity_metric= 1;

while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= or_nodes[or_node_id];
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1112:*/
#line 12978 "./marpa.w"

{
if(and_count_of_or> 1)
{
int high_rank_so_far= INT_MIN;
const ANDID first_and_node_id= First_ANDID_of_OR(work_or_node);
const ANDID last_and_node_id= 
(first_and_node_id+and_count_of_or)-1;
ANDID*const order_base= 
(my_obstack_reserve(obs,sizeof(ANDID)*(and_count_of_or+1)),
my_obstack_base(obs));
ANDID*order= order_base+1;
ANDID and_node_id;
bocage_was_reordered= 1;
for(and_node_id= first_and_node_id;and_node_id<=last_and_node_id;
and_node_id++)
{
const AND and_node= and_nodes+and_node_id;
int and_node_rank;
/*1113:*/
#line 13016 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const ISYID isy_id= ISYID_of_OR(cause_or);
and_node_rank= Rank_of_ISY(ISY_by_ID(isy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1113*/
#line 12997 "./marpa.w"

if(and_node_rank> high_rank_so_far)
{
order= order_base+1;
high_rank_so_far= and_node_rank;
}
if(and_node_rank>=high_rank_so_far)
*order++= and_node_id;
}
{
int final_count= (order-order_base)-1;
*order_base= final_count;
ambiguity_metric= MAX(ambiguity_metric,final_count);
my_obstack_confirm_fast(obs,sizeof(ANDID)*(final_count+1));
and_node_orderings[or_node_id]= my_obstack_finish(obs);
}
}
}

/*:1112*/
#line 12972 "./marpa.w"

or_node_id++;
}
Ambiguity_Metric_of_O(o)= ambiguity_metric;
}

/*:1111*/
#line 12947 "./marpa.w"

}else{
/*1114:*/
#line 13027 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
OR*const or_nodes= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
const int and_node_count_of_b= AND_Count_of_B(b);
int or_node_id= 0;
int*rank_by_and_id= my_new(int,and_node_count_of_b);
int and_node_id;
for(and_node_id= 0;and_node_id<and_node_count_of_b;and_node_id++)
{
const AND and_node= and_nodes+and_node_id;
int and_node_rank;
/*1113:*/
#line 13016 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const ISYID isy_id= ISYID_of_OR(cause_or);
and_node_rank= Rank_of_ISY(ISY_by_ID(isy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1113*/
#line 13040 "./marpa.w"

rank_by_and_id[and_node_id]= and_node_rank;
}
while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= or_nodes[or_node_id];
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1115:*/
#line 13073 "./marpa.w"

{
if(and_count_of_or> 1)
{
const ANDID first_and_node_id= First_ANDID_of_OR(work_or_node);
ANDID*const order_base= 
my_obstack_alloc(obs,sizeof(ANDID)*(and_count_of_or+1));
ANDID*order= order_base+1;
int nodes_inserted_so_far;
bocage_was_reordered= 1;
and_node_orderings[or_node_id]= order_base;
*order_base= and_count_of_or;
for(nodes_inserted_so_far= 0;nodes_inserted_so_far<and_count_of_or;
nodes_inserted_so_far++)
{
const ANDID new_and_node_id= 
first_and_node_id+nodes_inserted_so_far;
int pre_insertion_ix= nodes_inserted_so_far-1;
while(pre_insertion_ix>=0)
{
if(rank_by_and_id[new_and_node_id]<=
rank_by_and_id[order[pre_insertion_ix]])
break;
order[pre_insertion_ix+1]= order[pre_insertion_ix];
pre_insertion_ix--;
}
order[pre_insertion_ix+1]= new_and_node_id;
}
}
}

/*:1115*/
#line 13047 "./marpa.w"

or_node_id++;
}
my_free(rank_by_and_id);
}

/*:1114*/
#line 12949 "./marpa.w"

}
if(!bocage_was_reordered){
my_obstack_free(obs);
OBS_of_O(o)= NULL;
o->t_and_node_orderings= NULL;
}
O_is_Frozen(o)= 1;
return 1;
}

/*:1110*//*1117:*/
#line 13121 "./marpa.w"

PRIVATE ANDID and_order_ix_is_valid(ORDER o,OR or_node,int ix)
{
if(ix>=AND_Count_of_OR(or_node))return 0;
if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ORID or_node_id= ID_of_OR(or_node);
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)
{
int length= ordering[0];
if(ix>=length)return 0;
}
}
return 1;
}

/*:1117*//*1118:*/
#line 13142 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,int ix)
{
if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ORID or_node_id= ID_of_OR(or_node);
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)
return ordering[1+ix];
}
return First_ANDID_of_OR(or_node)+ix;
}

/*:1118*//*1119:*/
#line 13156 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13161 "./marpa.w"

/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13162 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13163 "./marpa.w"

/*972:*/
#line 11302 "./marpa.w"

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
}
/*:972*/
#line 13164 "./marpa.w"

/*973:*/
#line 11314 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:973*/
#line 13165 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
if(!and_order_ix_is_valid(o,or_node,ix))return-1;
return and_order_get(o,or_node,ix);
}

/*:1119*//*1124:*/
#line 13218 "./marpa.w"

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
bv_free(t->t_or_node_in_use);
t->t_or_node_in_use= NULL;
T_is_Exhausted(t)= 1;
}

/*:1124*//*1125:*/
#line 13236 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1345:*/
#line 16044 "./marpa.w"
void*const failure_indicator= NULL;
/*:1345*/
#line 13239 "./marpa.w"

TREE t;
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13241 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13242 "./marpa.w"

t= my_slice_new(*t);
O_of_T(t)= o;
order_ref(o);
O_is_Frozen(o)= 1;
/*1142:*/
#line 13427 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1142*/
#line 13247 "./marpa.w"

/*1126:*/
#line 13252 "./marpa.w"

{
t->t_parse_count= 0;
if(O_is_Nulling(o))
{
T_is_Nulling(t)= 1;
t->t_or_node_in_use= NULL;
FSTACK_SAFE(t->t_nook_stack);
FSTACK_SAFE(t->t_nook_worklist);
}
else
{
const int and_count= AND_Count_of_B(b);
const int or_count= OR_Count_of_B(b);
T_is_Nulling(t)= 0;
t->t_or_node_in_use= bv_create((unsigned int)or_count);
FSTACK_INIT(t->t_nook_stack,NOOK_Object,and_count);
FSTACK_INIT(t->t_nook_worklist,int,and_count);
}
}

/*:1126*//*1129:*/
#line 13276 "./marpa.w"

t->t_ref_count= 1;

/*:1129*//*1136:*/
#line 13355 "./marpa.w"
t->t_pause_counter= 0;
/*:1136*/
#line 13248 "./marpa.w"

return t;
}

/*:1125*//*1130:*/
#line 13280 "./marpa.w"

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

/*:1130*//*1131:*/
#line 13298 "./marpa.w"

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

/*:1131*//*1132:*/
#line 13312 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_slice_free(*t,t);
}

/*:1132*//*1137:*/
#line 13356 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1137*//*1138:*/
#line 13365 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1138*//*1139:*/
#line 13375 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13378 "./marpa.w"

const int termination_indicator= -1;
int is_first_tree_attempt= (t->t_parse_count<1);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13381 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13382 "./marpa.w"

if(T_is_Paused(t)){
MARPA_ERROR(MARPA_ERR_TREE_PAUSED);
return failure_indicator;
}

if(T_is_Exhausted(t))
{
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return termination_indicator;
}

if(T_is_Nulling(t)){
if(is_first_tree_attempt){
t->t_parse_count++;
return 0;
}else{
goto TREE_IS_EXHAUSTED;
}
}

while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
/*1148:*/
#line 13456 "./marpa.w"

{
ORID top_or_id= Top_ORID_of_B(b);
OR top_or_node= OR_of_B_by_ID(b,top_or_id);
NOOK nook;



const int choice= 0;
if(!and_order_ix_is_valid(o,top_or_node,choice))
goto TREE_IS_EXHAUSTED;
nook= FSTACK_PUSH(t->t_nook_stack);
tree_or_node_try(t,top_or_id);
OR_of_NOOK(nook)= top_or_node;
Choice_of_NOOK(nook)= choice;
Parent_of_NOOK(nook)= -1;
NOOK_Cause_is_Expanded(nook)= 0;
NOOK_is_Cause(nook)= 0;
NOOK_Predecessor_is_Expanded(nook)= 0;
NOOK_is_Predecessor(nook)= 0;
}

/*:1148*/
#line 13407 "./marpa.w"

}else{
/*1149:*/
#line 13481 "./marpa.w"
{
while(1){
OR iteration_candidate_or_node;
const NOOK iteration_candidate= FSTACK_TOP(t->t_nook_stack,NOOK_Object);
int choice;
if(!iteration_candidate)break;
iteration_candidate_or_node= OR_of_NOOK(iteration_candidate);
choice= Choice_of_NOOK(iteration_candidate)+1;
MARPA_ASSERT(choice> 0);
if(and_order_ix_is_valid(o,iteration_candidate_or_node,choice)){





Choice_of_NOOK(iteration_candidate)= choice;
NOOK_Cause_is_Expanded(iteration_candidate)= 0;
NOOK_Predecessor_is_Expanded(iteration_candidate)= 0;
break;
}
{


const int parent_nook_ix= Parent_of_NOOK(iteration_candidate);
if(parent_nook_ix>=0){
NOOK parent_nook= NOOK_of_TREE_by_IX(t,parent_nook_ix);
if(NOOK_is_Cause(iteration_candidate)){
NOOK_Cause_is_Expanded(parent_nook)= 0;
}
if(NOOK_is_Predecessor(iteration_candidate)){
NOOK_Predecessor_is_Expanded(parent_nook)= 0;
}
}


tree_or_node_release(t,ID_of_OR(iteration_candidate_or_node));
FSTACK_POP(t->t_nook_stack);
}
}
if(Size_of_T(t)<=0)goto TREE_IS_EXHAUSTED;
}

/*:1149*/
#line 13409 "./marpa.w"

}
/*1150:*/
#line 13523 "./marpa.w"
{
{
const int stack_length= Size_of_T(t);
int i;


FSTACK_CLEAR(t->t_nook_worklist);
for(i= 0;i<stack_length;i++){
*(FSTACK_PUSH(t->t_nook_worklist))= i;
}
}
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
if(FSTACK_LENGTH(t->t_nook_worklist)<=0){goto TREE_IS_FINISHED;}
p_work_nook_id= FSTACK_TOP(t->t_nook_worklist,NOOKID);
work_nook= NOOK_of_TREE_by_IX(t,*p_work_nook_id);
work_or_node= OR_of_NOOK(work_nook);
work_and_node_id= and_order_get(o,work_or_node,Choice_of_NOOK(work_nook));
work_and_node= ands_of_b+work_and_node_id;
do
{
if(!NOOK_Cause_is_Expanded(work_nook))
{
const OR cause_or_node= Cause_OR_of_AND(work_and_node);
if(!OR_is_Token(cause_or_node))
{
child_or_node= cause_or_node;
child_is_cause= 1;
break;
}
}
NOOK_Cause_is_Expanded(work_nook)= 1;
if(!NOOK_Predecessor_is_Expanded(work_nook))
{
child_or_node= Predecessor_OR_of_AND(work_and_node);
if(child_or_node)
{
child_is_predecessor= 1;
break;
}
}
NOOK_Predecessor_is_Expanded(work_nook)= 1;
FSTACK_POP(t->t_nook_worklist);
goto NEXT_NOOK_ON_WORKLIST;
}
while(0);
if(!tree_or_node_try(t,ID_of_OR(child_or_node)))goto NEXT_TREE;
choice= 0;
if(!and_order_ix_is_valid(o,child_or_node,choice))goto NEXT_TREE;
/*1151:*/
#line 13586 "./marpa.w"

{
NOOKID new_nook_id= Size_of_T(t);
NOOK new_nook= FSTACK_PUSH(t->t_nook_stack);
*(FSTACK_PUSH(t->t_nook_worklist))= new_nook_id;
Parent_of_NOOK(new_nook)= *p_work_nook_id;
Choice_of_NOOK(new_nook)= choice;
OR_of_NOOK(new_nook)= child_or_node;
NOOK_Cause_is_Expanded(new_nook)= 0;
if((NOOK_is_Cause(new_nook)= child_is_cause)){
NOOK_Cause_is_Expanded(work_nook)= 1;
}
NOOK_Predecessor_is_Expanded(new_nook)= 0;
if((NOOK_is_Predecessor(new_nook)= child_is_predecessor)){
NOOK_Predecessor_is_Expanded(work_nook)= 1;
}
}

/*:1151*/
#line 13580 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1150*/
#line 13411 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return termination_indicator;

}

/*:1139*//*1146:*/
#line 13443 "./marpa.w"

PRIVATE int tree_or_node_try(TREE tree,ORID or_node_id)
{
return!bv_bit_test_then_set(tree->t_or_node_in_use,(unsigned int)or_node_id);
}
/*:1146*//*1147:*/
#line 13449 "./marpa.w"

PRIVATE void tree_or_node_release(TREE tree,ORID or_node_id)
{
bv_bit_clear(tree->t_or_node_in_use,(unsigned int)or_node_id);
}

/*:1147*//*1152:*/
#line 13605 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1152*//*1153:*/
#line 13613 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13616 "./marpa.w"

/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13617 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13618 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return failure_indicator;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1153*//*1160:*/
#line 13679 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13683 "./marpa.w"

/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13684 "./marpa.w"

/*1159:*/
#line 13661 "./marpa.w"
{
NOOK base_nook;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13663 "./marpa.w"

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

/*:1159*/
#line 13685 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1160*//*1161:*/
#line 13689 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13693 "./marpa.w"

/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13694 "./marpa.w"

/*1159:*/
#line 13661 "./marpa.w"
{
NOOK base_nook;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13663 "./marpa.w"

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

/*:1159*/
#line 13695 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1161*//*1162:*/
#line 13699 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13703 "./marpa.w"

/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13704 "./marpa.w"

/*1159:*/
#line 13661 "./marpa.w"
{
NOOK base_nook;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13663 "./marpa.w"

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

/*:1159*/
#line 13705 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1162*//*1163:*/
#line 13709 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13713 "./marpa.w"

/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13714 "./marpa.w"

/*1159:*/
#line 13661 "./marpa.w"
{
NOOK base_nook;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13663 "./marpa.w"

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

/*:1159*/
#line 13715 "./marpa.w"

return NOOK_Cause_is_Expanded(nook);
}

/*:1163*//*1164:*/
#line 13719 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13723 "./marpa.w"

/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13724 "./marpa.w"

/*1159:*/
#line 13661 "./marpa.w"
{
NOOK base_nook;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13663 "./marpa.w"

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

/*:1159*/
#line 13725 "./marpa.w"

return NOOK_Predecessor_is_Expanded(nook);
}

/*:1164*//*1165:*/
#line 13729 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13733 "./marpa.w"

/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13734 "./marpa.w"

/*1159:*/
#line 13661 "./marpa.w"
{
NOOK base_nook;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13663 "./marpa.w"

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

/*:1159*/
#line 13735 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1165*//*1166:*/
#line 13739 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 13743 "./marpa.w"

/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13744 "./marpa.w"

/*1159:*/
#line 13661 "./marpa.w"
{
NOOK base_nook;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13663 "./marpa.w"

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

/*:1159*/
#line 13745 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1166*//*1183:*/
#line 13922 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1345:*/
#line 16044 "./marpa.w"
void*const failure_indicator= NULL;
/*:1345*/
#line 13925 "./marpa.w"

/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 13926 "./marpa.w"
;
/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 13927 "./marpa.w"

if(t->t_parse_count<=0){
MARPA_ERROR(MARPA_ERR_BEFORE_FIRST_TREE);
return NULL;
}
if(!T_is_Exhausted(t))
{
const XSYID xsy_count= XSY_Count_of_G(g);
struct obstack*const obstack= my_obstack_init;
const VALUE v= my_obstack_new(obstack,struct s_value,1);
v->t_obs= obstack;
Step_Type_of_V(v)= Next_Value_Type_of_V(v)= MARPA_STEP_INITIAL;
/*1174:*/
#line 13848 "./marpa.w"

XSYID_of_V(v)= -1;
RULEID_of_V(v)= -1;
Token_Value_of_V(v)= -1;
Token_Type_of_V(v)= DUMMY_OR_NODE;
Arg_0_of_V(v)= -1;
Arg_N_of_V(v)= -1;
Result_of_V(v)= -1;
Rule_Start_of_V(v)= -1;
Token_Start_of_V(v)= -1;
ES_ID_of_V(v)= -1;

/*:1174*//*1181:*/
#line 13911 "./marpa.w"

DSTACK_SAFE(VStack_of_V(v));
/*:1181*//*1186:*/
#line 13959 "./marpa.w"

v->t_ref_count= 1;

/*:1186*//*1193:*/
#line 14012 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1193*//*1195:*/
#line 14019 "./marpa.w"

V_is_Trace(v)= 0;
/*:1195*//*1198:*/
#line 14040 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1198*//*1203:*/
#line 14067 "./marpa.w"

{
XSY_is_Valued_BV_of_V(v)= lbv_clone(v->t_obs,Valued_BV_of_B(b),xsy_count);
Valued_Locked_BV_of_V(v)= 
lbv_clone(v->t_obs,Valued_Locked_BV_of_B(b),xsy_count);
}

/*:1203*/
#line 13939 "./marpa.w"

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

/*:1183*//*1187:*/
#line 13963 "./marpa.w"

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

/*:1187*//*1188:*/
#line 13981 "./marpa.w"

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

/*:1188*//*1189:*/
#line 13995 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
/*1182:*/
#line 13913 "./marpa.w"

{
if(LIKELY(DSTACK_IS_INITIALIZED(VStack_of_V(v))!=NULL))
{
DSTACK_DESTROY(VStack_of_V(v));
}
}

/*:1182*/
#line 13999 "./marpa.w"

/*1176:*/
#line 13864 "./marpa.w"

my_obstack_free(v->t_obs);

/*:1176*/
#line 14000 "./marpa.w"

}

/*:1189*//*1196:*/
#line 14021 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 14024 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1190:*/
#line 14003 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 14005 "./marpa.w"


/*:1190*/
#line 14026 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 14027 "./marpa.w"

if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1196*//*1199:*/
#line 14043 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 14046 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1190:*/
#line 14003 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 14005 "./marpa.w"


/*:1190*/
#line 14048 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 14049 "./marpa.w"

if(UNLIKELY(V_is_Nulling(v)))return-1;
if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1199*//*1204:*/
#line 14075 "./marpa.w"

int marpa_v_symbol_is_valued(
Marpa_Value public_v,
Marpa_Symbol_ID xsy_id)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 14080 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1190:*/
#line 14003 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 14005 "./marpa.w"


/*:1190*/
#line 14082 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 14083 "./marpa.w"

/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 14084 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 14085 "./marpa.w"

return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
}

/*:1204*//*1205:*/
#line 14091 "./marpa.w"

PRIVATE int symbol_is_valued_set(
VALUE v,XSYID xsy_id,int value)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 14095 "./marpa.w"

const int old_value= lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
if(old_value==value){
lbv_bit_set(Valued_Locked_BV_of_V(v),xsy_id);
return value;
}

if(UNLIKELY(lbv_bit_test(Valued_Locked_BV_of_V(v),xsy_id))){
return failure_indicator;
}
lbv_bit_set(Valued_Locked_BV_of_V(v),xsy_id);
if(value){
lbv_bit_set(XSY_is_Valued_BV_of_V(v),xsy_id);
}else{
lbv_bit_clear(XSY_is_Valued_BV_of_V(v),xsy_id);
}
return value;
}

/*:1205*//*1206:*/
#line 14114 "./marpa.w"

int marpa_v_symbol_is_valued_set(
Marpa_Value public_v,Marpa_Symbol_ID xsy_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 14119 "./marpa.w"

/*1190:*/
#line 14003 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 14005 "./marpa.w"


/*:1190*/
#line 14120 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 14121 "./marpa.w"

if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1349:*/
#line 16063 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1349*/
#line 14127 "./marpa.w"

/*1350:*/
#line 16070 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1350*/
#line 14128 "./marpa.w"

return symbol_is_valued_set(v,xsy_id,value);
}

/*:1206*//*1207:*/
#line 14134 "./marpa.w"

int
marpa_v_valued_force(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 14139 "./marpa.w"

XSYID xsy_count;
XSYID xsy_id;
/*1190:*/
#line 14003 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 14005 "./marpa.w"


/*:1190*/
#line 14142 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 14143 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
for(xsy_id= 0;xsy_id<xsy_count;xsy_id++)
{
if(UNLIKELY(!lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id)&&
lbv_bit_test(Valued_Locked_BV_of_V(v),xsy_id)))
{
return failure_indicator;
}
lbv_bit_set(Valued_Locked_BV_of_V(v),xsy_id);
lbv_bit_set(XSY_is_Valued_BV_of_V(v),xsy_id);
}
return xsy_count;
}

/*:1207*//*1208:*/
#line 14158 "./marpa.w"

int marpa_v_rule_is_valued_set(
Marpa_Value public_v,Marpa_Rule_ID xrl_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 14163 "./marpa.w"

/*1190:*/
#line 14003 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 14005 "./marpa.w"


/*:1190*/
#line 14164 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 14165 "./marpa.w"

if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1356:*/
#line 16104 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1356*/
#line 14171 "./marpa.w"

/*1354:*/
#line 16093 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1354*/
#line 14172 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsy_id= LHS_ID_of_XRL(xrl);
return symbol_is_valued_set(v,xsy_id,value);
}
}

/*:1208*//*1210:*/
#line 14187 "./marpa.w"

Marpa_Step_Type marpa_v_step(Marpa_Value public_v)
{
/*1346:*/
#line 16047 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 14190 "./marpa.w"

const VALUE v= (VALUE)public_v;

if(V_is_Nulling(v)){
/*1190:*/
#line 14003 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 14005 "./marpa.w"


/*:1190*/
#line 14194 "./marpa.w"

/*1212:*/
#line 14275 "./marpa.w"

{
while(V_is_Active(v))
{
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case MARPA_STEP_INITIAL:
case STEP_GET_DATA:
{
Next_Value_Type_of_V(v)= MARPA_STEP_INACTIVE;
XSYID_of_V(v)= g->t_start_xsy_id;
Result_of_V(v)= Arg_0_of_V(v)= Arg_N_of_V(v)= 0;
if(lbv_bit_test(XSY_is_Valued_BV_of_V(v),XSYID_of_V(v)))
return Step_Type_of_V(v)= MARPA_STEP_NULLING_SYMBOL;
}



}
}
}

/*:1212*/
#line 14195 "./marpa.w"

return Step_Type_of_V(v)= MARPA_STEP_INACTIVE;
}

while(V_is_Active(v)){
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case MARPA_STEP_INITIAL:
{
XSYID xsy_count;
/*1190:*/
#line 14003 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 14005 "./marpa.w"


/*:1190*/
#line 14206 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
lbv_fill(Valued_Locked_BV_of_V(v),xsy_count);
/*1211:*/
#line 14259 "./marpa.w"

{
const LBV xsy_bv= XSY_is_Valued_BV_of_V(v);
const XRLID xrl_count= XRL_Count_of_G(g);
const LBV xrl_bv= lbv_obs_new0(v->t_obs,xrl_count);
XRLID xrlid;
XRL_is_Valued_BV_of_V(v)= xrl_bv;
for(xrlid= 0;xrlid<xrl_count;xrlid++){
const XRL xrl= XRL_by_ID(xrlid);
const XSYID lhs_xsy_id= LHS_ID_of_XRL(xrl);
if(lbv_bit_test(xsy_bv,lhs_xsy_id)){
lbv_bit_set(xrl_bv,xrlid);
}
}
}

/*:1211*/
#line 14209 "./marpa.w"

}

case STEP_GET_DATA:
/*1213:*/
#line 14298 "./marpa.w"

{
AND and_nodes;





int pop_arguments= 1;
/*1190:*/
#line 14003 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13214 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12404 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12824 "./marpa.w"


/*:1096*/
#line 13216 "./marpa.w"
;

/*:1123*/
#line 14005 "./marpa.w"


/*:1190*/
#line 14307 "./marpa.w"

/*1363:*/
#line 16143 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1363*/
#line 14308 "./marpa.w"

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


Arg_N_of_V(v)= Arg_0_of_V(v);
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
ES_ID_of_V(v)= ES_Ord_of_OR(or);
and_node_id= and_order_get(o,or,choice);
and_node= and_nodes+and_node_id;
token= and_node_token(and_node);
token_type= token?Type_of_TOK(token):DUMMY_OR_NODE;
Token_Type_of_V(v)= token_type;
if(token_type!=DUMMY_OR_NODE)
{
const ISYID token_isyid= ISYID_of_TOK(token);
Arg_0_of_V(v)= ++Arg_N_of_V(v);
if(token_type==VALUED_TOKEN_OR_NODE)
{
const OR predecessor= Predecessor_OR_of_AND(and_node);
XSYID_of_V(v)= ID_of_XSY(Source_XSY_of_ISYID(token_isyid));
Token_Start_of_V(v)= 
predecessor?ES_Ord_of_OR(predecessor):Origin_Ord_of_OR(or);
Token_Value_of_V(v)= Value_of_TOK(token);
}
else if(token_type==NULLING_TOKEN_OR_NODE)
{
const XSY source_xsy= Source_XSY_of_ISYID(token_isyid);
const XSYID source_xsy_id= ID_of_XSY(source_xsy);
if(bv_bit_test(XSY_is_Valued_BV_of_V(v),source_xsy_id))
{
XSYID_of_V(v)= source_xsy_id;
Token_Start_of_V(v)= ES_ID_of_V(v);
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
Arg_0_of_V(v)= Arg_N_of_V(v)-real_symbol_count+1;
pop_arguments= 1;
if(lbv_bit_test(XRL_is_Valued_BV_of_V(v),original_rule_id))
{
RULEID_of_V(v)= original_rule_id;
Rule_Start_of_V(v)= Origin_Ord_of_OR(or);
}
}

}
}
if(RULEID_of_V(v)>=0)break;
if(Token_Type_of_V(v)!=DUMMY_OR_NODE)break;
if(V_is_Trace(v))break;
}
}

/*:1213*/
#line 14213 "./marpa.w"

if(!V_is_Active(v))break;

case MARPA_STEP_TOKEN:
{
int token_type= Token_Type_of_V(v);
Next_Value_Type_of_V(v)= MARPA_STEP_RULE;
if(token_type==NULLING_TOKEN_OR_NODE)
{
if(lbv_bit_test(XSY_is_Valued_BV_of_V(v),XSYID_of_V(v))){
Result_of_V(v)= Arg_N_of_V(v);
return Step_Type_of_V(v)= MARPA_STEP_NULLING_SYMBOL;
}
}
else if(token_type!=DUMMY_OR_NODE)
{
Result_of_V(v)= Arg_N_of_V(v);
return Step_Type_of_V(v)= MARPA_STEP_TOKEN;
}
}

case MARPA_STEP_RULE:
if(RULEID_of_V(v)>=0)
{
Next_Value_Type_of_V(v)= MARPA_STEP_TRACE;
Result_of_V(v)= Arg_0_of_V(v);
return Step_Type_of_V(v)= MARPA_STEP_RULE;
}

case MARPA_STEP_TRACE:
Next_Value_Type_of_V(v)= STEP_GET_DATA;
if(V_is_Trace(v))
{
return Step_Type_of_V(v)= MARPA_STEP_TRACE;
}
}
}

Next_Value_Type_of_V(v)= MARPA_STEP_INACTIVE;
return Step_Type_of_V(v)= MARPA_STEP_INACTIVE;
}

/*:1210*//*1215:*/
#line 14441 "./marpa.w"

PRIVATE int lbv_bits_to_size(int bits)
{
return(bits+(lbv_wordbits-1))/lbv_wordbits;
}

/*:1215*//*1216:*/
#line 14448 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new(struct obstack*obs,int bits)
{
int size= lbv_bits_to_size(bits);
LBV lbv= my_obstack_new(obs,LBW,size);
return lbv;
}

/*:1216*//*1217:*/
#line 14458 "./marpa.w"

PRIVATE Bit_Vector
lbv_zero(Bit_Vector lbv,int bits)
{
int size= lbv_bits_to_size(bits);
if(size> 0){
LBW*addr= lbv;
while(size--)*addr++= 0u;
}
return lbv;
}

/*:1217*//*1218:*/
#line 14471 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new0(struct obstack*obs,int bits)
{
LBV lbv= lbv_obs_new(obs,bits);
return lbv_zero(lbv,bits);
}

/*:1218*//*1220:*/
#line 14490 "./marpa.w"

PRIVATE LBV lbv_clone(
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

/*:1220*//*1221:*/
#line 14506 "./marpa.w"

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

/*:1221*//*1224:*/
#line 14542 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(unsigned int bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1224*//*1225:*/
#line 14548 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(unsigned int bits)
{
unsigned int mask= bits&bv_modmask;
if(mask)mask= (unsigned int)~(~0uL<<mask);else mask= (unsigned int)~0uL;
return(mask);
}

/*:1225*//*1227:*/
#line 14562 "./marpa.w"

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

/*:1227*//*1229:*/
#line 14580 "./marpa.w"

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


/*:1229*//*1230:*/
#line 14601 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,BV_BITS(bv));
}

/*:1230*//*1231:*/
#line 14615 "./marpa.w"

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

/*:1231*//*1232:*/
#line 14633 "./marpa.w"

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

/*:1232*//*1233:*/
#line 14647 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1233*//*1234:*/
#line 14658 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1234*//*1235:*/
#line 14669 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1235*//*1237:*/
#line 14683 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,unsigned int bit)
{
unsigned int length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1237*//*1239:*/
#line 14691 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1239*//*1240:*/
#line 14698 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1240*//*1241:*/
#line 14705 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,unsigned int bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1241*//*1242:*/
#line 14716 "./marpa.w"

PRIVATE int
bv_bit_test_then_set(Bit_Vector vector,unsigned int bit)
{
Bit_Vector addr= vector+(bit/bv_wordbits);
unsigned int mask= bv_lsb<<(bit%bv_wordbits);
if((*addr&mask)!=0u)
return 1;
*addr|= mask;
return 0;
}

/*:1242*//*1243:*/
#line 14729 "./marpa.w"

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

/*:1243*//*1244:*/
#line 14743 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1244*//*1245:*/
#line 14753 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1245*//*1246:*/
#line 14763 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1246*//*1247:*/
#line 14773 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1247*//*1248:*/
#line 14783 "./marpa.w"

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

/*:1248*//*1249:*/
#line 14855 "./marpa.w"

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

/*:1249*//*1254:*/
#line 14903 "./marpa.w"

PRIVATE void
rhs_closure(GRAMMAR g,Bit_Vector bv,XRLID**xrl_list_x_rh_sym)
{
unsigned int min,max,start= 0;
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_DECLARE(stack,XSYID)
FSTACK_INIT(stack,XSYID,XSY_Count_of_G(g));
while(bv_scan(bv,start,&min,&max))
{
unsigned int xsy_id;
for(xsy_id= min;xsy_id<=max;xsy_id++)
{
*(FSTACK_PUSH(stack))= xsy_id;
}
start= max+2;
}
while((top_of_stack= FSTACK_POP(stack)))
{
const XSYID xsy_id= *top_of_stack;
XRLID*p_xrl= xrl_list_x_rh_sym[xsy_id];
const XRLID*p_one_past_rules= xrl_list_x_rh_sym[xsy_id+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{
const XRLID rule_id= *p_xrl;
const XRL rule= XRL_by_ID(rule_id);
int rule_length;
int rh_ix;
const XSYID lhs_id= LHS_ID_of_XRL(rule);

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
XSYID separator_id= Separator_of_XRL(rule);
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

/*:1254*//*1259:*/
#line 15009 "./marpa.w"

PRIVATE Bit_Matrix matrix_buffer_create(void*buffer,unsigned int rows,unsigned int columns)
{
unsigned int row;
const unsigned int bv_data_words= bv_bits_to_size(columns);
const unsigned int bv_mask= bv_bits_to_unused_mask(columns);

Bit_Matrix matrix_addr= buffer;
matrix_addr->t_row_count= rows;
for(row= 0;row<rows;row++){
const unsigned int row_start= row*(bv_data_words+bv_hiddenwords);
Bit_Vector_Word*p_current_word= matrix_addr->t_row_data+row_start;
int data_word_counter= bv_data_words;
*p_current_word++= columns;
*p_current_word++= bv_data_words;
*p_current_word++= bv_mask;
while(data_word_counter--)*p_current_word++= 0;
}
return matrix_addr;
}

/*:1259*//*1261:*/
#line 15031 "./marpa.w"

PRIVATE size_t matrix_sizeof(unsigned int rows,unsigned int columns)
{
const unsigned int bv_data_words= bv_bits_to_size(columns);
const unsigned int row_bytes= (bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
return offsetof(struct s_bit_matrix,t_row_data)+(rows)*row_bytes;
}

/*:1261*//*1263:*/
#line 15040 "./marpa.w"

PRIVATE Bit_Matrix matrix_obs_create(struct obstack*obs,unsigned int rows,unsigned int columns)
{
Bit_Matrix matrix_addr= 
my_obstack_alloc(obs,matrix_sizeof(rows,columns));
return matrix_buffer_create(matrix_addr,rows,columns);
}

/*:1263*//*1264:*/
#line 15049 "./marpa.w"

PRIVATE void matrix_clear(Bit_Matrix matrix)
{
Bit_Vector row;
int row_ix;
const int row_count= matrix->t_row_count;
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
unsigned int words_per_row= BV_SIZE(row0)+bv_hiddenwords;
row_ix= 0;row= row0;
while(row_ix<row_count){
bv_clear(row);
row_ix++;
row+= words_per_row;
}
}

/*:1264*//*1265:*/
#line 15071 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1265*//*1266:*/
#line 15087 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,unsigned int row)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
unsigned int words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1266*//*1268:*/
#line 15096 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1268*//*1270:*/
#line 15104 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1270*//*1272:*/
#line 15112 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1272*//*1273:*/
#line 15129 "./marpa.w"

PRIVATE_NOT_INLINE void transitive_closure(Bit_Matrix matrix)
{
unsigned int size= matrix_columns(matrix);
unsigned int outer_row;
for(outer_row= 0;outer_row<size;outer_row++)
{
Bit_Vector outer_row_v= matrix_row(matrix,outer_row);
unsigned int column;
for(column= 0;column<size;column++)
{
Bit_Vector inner_row_v= matrix_row(matrix,column);
if(bv_bit_test(inner_row_v,(unsigned int)outer_row))
{
bv_or_assign(inner_row_v,outer_row_v);
}
}
}
}

/*:1273*//*1282:*/
#line 15261 "./marpa.w"

PRIVATE_NOT_INLINE void*dstack_resize2(struct s_dstack*this,size_t type_bytes)
{
return dstack_resize(this,type_bytes,this->t_capacity*2);
}

/*:1282*//*1283:*/
#line 15270 "./marpa.w"

PRIVATE void*dstack_resize(struct s_dstack*this,size_t type_bytes,int new_size)
{
if(new_size> this->t_capacity)
{

this->t_capacity= new_size;
this->t_base= my_realloc(this->t_base,new_size*type_bytes);
}
return this->t_base;
}

/*:1283*//*1292:*/
#line 15368 "./marpa.w"

PRIVATE void
cilar_init(const CILAR cilar)
{
cilar->t_obs= my_obstack_init;
cilar->t_avl= _marpa_avl_create(cil_cmp,NULL,0);
DSTACK_INIT(cilar->t_buffer,int,2);
*DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}
/*:1292*//*1293:*/
#line 15382 "./marpa.w"

PRIVATE void
cilar_reinit(const CILAR cilar)
{
DSTACK_DESTROY(cilar->t_buffer);
DSTACK_INIT(cilar->t_buffer,int,2);
*DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}

/*:1293*//*1294:*/
#line 15391 "./marpa.w"

PRIVATE void cilar_destroy(const CILAR cilar)
{
_marpa_avl_destroy(cilar->t_avl);
my_obstack_free(cilar->t_obs);
DSTACK_DESTROY((cilar->t_buffer));
}

/*:1294*//*1295:*/
#line 15400 "./marpa.w"

PRIVATE CIL cil_empty(CILAR cilar)
{
CIL cil= DSTACK_BASE(cilar->t_buffer,int);
Count_of_CIL(cil)= 0;
return cil_buffer_add(cilar);
}

/*:1295*//*1296:*/
#line 15409 "./marpa.w"

PRIVATE CIL cil_singleton(CILAR cilar,int element)
{
CIL cil= DSTACK_BASE(cilar->t_buffer,int);
Count_of_CIL(cil)= 1;
Item_of_CIL(cil,0)= element;

return cil_buffer_add(cilar);
}

/*:1296*//*1297:*/
#line 15425 "./marpa.w"

PRIVATE CIL cil_buffer_add(CILAR cilar)
{

CIL cil_in_buffer= DSTACK_BASE(cilar->t_buffer,int);
CIL found_cil= _marpa_avl_find(cilar->t_avl,cil_in_buffer);
if(!found_cil)
{
int i;
const int cil_size_in_ints= Count_of_CIL(cil_in_buffer)+1;
found_cil= my_obstack_new(cilar->t_obs,int,cil_size_in_ints);
for(i= 0;i<cil_size_in_ints;i++)
{
found_cil[i]= cil_in_buffer[i];
}
_marpa_avl_insert(cilar->t_avl,found_cil);
}
return found_cil;
}

/*:1297*//*1298:*/
#line 15453 "./marpa.w"

PRIVATE CIL cil_bv_add(CILAR cilar,Bit_Vector bv)
{
unsigned int min,max,start= 0;
cil_buffer_clear(cilar);
for(start= 0;bv_scan(bv,start,&min,&max);start= max+2)
{
int new_item;
for(new_item= (int)min;new_item<=(int)max;new_item++)
{
cil_buffer_push(cilar,new_item);
}
}
return cil_buffer_add(cilar);
}

/*:1298*//*1299:*/
#line 15470 "./marpa.w"

PRIVATE void cil_buffer_clear(CILAR cilar)
{
const DSTACK dstack= &cilar->t_buffer;
DSTACK_CLEAR(*dstack);



*DSTACK_PUSH(*dstack,int)= 0;
}

/*:1299*//*1300:*/
#line 15484 "./marpa.w"

PRIVATE CIL cil_buffer_push(CILAR cilar,int new_item)
{
CIL cil_in_buffer;
DSTACK dstack= &cilar->t_buffer;
*DSTACK_PUSH(*dstack,int)= new_item;


cil_in_buffer= DSTACK_BASE(*dstack,int);
Count_of_CIL(cil_in_buffer)++;
return cil_in_buffer;
}

/*:1300*//*1301:*/
#line 15499 "./marpa.w"

PRIVATE CIL cil_buffer_reserve(CILAR cilar,int element_count)
{
const int desired_dstack_capacity= element_count+1;
const int old_dstack_capacity= DSTACK_CAPACITY(cilar->t_buffer);
if(old_dstack_capacity<desired_dstack_capacity)
{
const int target_capacity= 
MAX(old_dstack_capacity*2,desired_dstack_capacity);
DSTACK_RESIZE(&(cilar->t_buffer),int,target_capacity);
}
return DSTACK_BASE(cilar->t_buffer,int);
}

/*:1301*//*1302:*/
#line 15517 "./marpa.w"

PRIVATE CIL cil_merge(CILAR cilar,CIL cil1,CIL cil2)
{
const int cil1_count= Count_of_CIL(cil1);
const int cil2_count= Count_of_CIL(cil2);
CIL new_cil= cil_buffer_reserve(cilar,cil1_count+cil2_count);
int new_cil_ix= 0;
int cil1_ix= 0;
int cil2_ix= 0;
while(cil1_ix<cil1_count&&cil2_ix<cil2_count)
{
const int item1= Item_of_CIL(cil1,cil1_ix);
const int item2= Item_of_CIL(cil2,cil2_ix);
if(item1<item2)
{
Item_of_CIL(new_cil,new_cil_ix)= item1;
cil1_ix++;
new_cil_ix++;
continue;
}
if(item2<item1)
{
Item_of_CIL(new_cil,new_cil_ix)= item2;
cil2_ix++;
new_cil_ix++;
continue;
}
Item_of_CIL(new_cil,new_cil_ix)= item1;
cil1_ix++;
cil2_ix++;
new_cil_ix++;
}
while(cil1_ix<cil1_count){
const int item1= Item_of_CIL(cil1,cil1_ix);
Item_of_CIL(new_cil,new_cil_ix)= item1;
cil1_ix++;
new_cil_ix++;
}
while(cil2_ix<cil2_count){
const int item2= Item_of_CIL(cil2,cil2_ix);
Item_of_CIL(new_cil,new_cil_ix)= item2;
cil2_ix++;
new_cil_ix++;
}
Count_of_CIL(new_cil)= new_cil_ix;
return cil_buffer_add(cilar);
}

/*:1302*//*1303:*/
#line 15570 "./marpa.w"

PRIVATE CIL cil_merge_one(CILAR cilar,CIL cil,int new_element)
{
const int cil_count= Count_of_CIL(cil);
CIL new_cil= cil_buffer_reserve(cilar,cil_count+1);
int new_cil_ix= 0;
int cil_ix= 0;
while(cil_ix<cil_count)
{
const int cil_item= Item_of_CIL(cil,cil_ix);
if(cil_item==new_element)
{


return NULL;
}
if(cil_item> new_element)
break;
Item_of_CIL(new_cil,new_cil_ix)= cil_item;
cil_ix++;
new_cil_ix++;
}
Item_of_CIL(new_cil,new_cil_ix)= new_element;
new_cil_ix++;
while(cil_ix<cil_count)
{
const int cil_item= Item_of_CIL(cil,cil_ix);
Item_of_CIL(new_cil,new_cil_ix)= cil_item;
cil_ix++;
new_cil_ix++;
}
Count_of_CIL(new_cil)= new_cil_ix;
return cil_buffer_add(cilar);
}

/*:1303*//*1304:*/
#line 15605 "./marpa.w"

PRIVATE_NOT_INLINE int
cil_cmp(const void*ap,const void*bp,void*param UNUSED)
{
int ix;
CIL cil1= (CIL)ap;
CIL cil2= (CIL)bp;
int count1= Count_of_CIL(cil1);
int count2= Count_of_CIL(cil2);
if(count1!=count2)
{
return count1> count2?1:-1;
}
for(ix= 0;ix<count1;ix++)
{
const int item1= Item_of_CIL(cil1,ix);
const int item2= Item_of_CIL(cil2,ix);
if(item1==item2)
continue;
return item1> item2?1:-1;
}
return 0;
}

/*:1304*//*1317:*/
#line 15733 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1317*//*1318:*/
#line 15740 "./marpa.w"

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
/*:1318*//*1319:*/
#line 15754 "./marpa.w"

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
/*:1319*//*1322:*/
#line 15785 "./marpa.w"

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

/*:1322*//*1324:*/
#line 15803 "./marpa.w"

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

/*:1324*//*1326:*/
#line 15823 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1326*//*1328:*/
#line 15847 "./marpa.w"

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

/*:1328*//*1331:*/
#line 15873 "./marpa.w"

PRIVATE_NOT_INLINE void*
_marpa_default_out_of_memory(void)
{
abort();
}
void*(*_marpa_out_of_memory)(void)= _marpa_default_out_of_memory;

/*:1331*//*1366:*/
#line 16187 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}
/*:1366*//*1367:*/
#line 16206 "./marpa.w"

PRIVATE Marpa_Error_Code
clear_error(GRAMMAR g)
{
if(!IS_G_OK(g))
{
if(g->t_error==MARPA_ERR_NONE)
g->t_error= MARPA_ERR_I_AM_NOT_OK;
return g->t_error;
}
g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
return MARPA_ERR_NONE;
}

/*:1367*//*1375:*/
#line 16283 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
_marpa_debug_handler= debug_handler;
}

/*:1375*//*1377:*/
#line 16291 "./marpa.w"

void marpa_debug_level_set(int level)
{
_marpa_debug_level= level;
}

/*:1377*/
#line 16525 "./marpa.w"


/*:1392*/
