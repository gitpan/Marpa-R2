/*1376:*/
#line 16282 "./marpa.w"

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

/*:1376*//*1377:*/
#line 16305 "./marpa.w"

#include "config.h"
#include "marpa.h"
#include "marpa_int.h"
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
#include "marpa_ami.h"
#define PRIVATE_NOT_INLINE static
#define PRIVATE static inline \

#define XSY_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_xsy_stack) ) 
#define XSY_by_ID(id) (*MARPA_DSTACK_INDEX(g->t_xsy_stack,XSY,(id) ) )  \

#define XSYID_is_Malformed(xsy_id) ((xsy_id) <0) 
#define XSYID_of_G_Exists(xsy_id) ((xsy_id) <XSY_Count_of_G(g) ) 
#define XRL_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_xrl_stack) ) 
#define IRL_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_irl_stack) ) 
#define XRL_by_ID(id) (*MARPA_DSTACK_INDEX((g) ->t_xrl_stack,XRL,(id) ) ) 
#define IRL_by_ID(id) (*MARPA_DSTACK_INDEX((g) ->t_irl_stack,IRL,(id) ) ) 
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
#define G_EVENT_COUNT(g) MARPA_DSTACK_LENGTH((g) ->t_events) 
#define INITIAL_G_EVENTS_CAPACITY (1024/sizeof(int) ) 
#define G_EVENTS_CLEAR(g) MARPA_DSTACK_CLEAR((g) ->t_events) 
#define G_EVENT_PUSH(g) MARPA_DSTACK_PUSH((g) ->t_events,GEV_Object) 
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
#define NSY_of_XSY(xsy) ((xsy) ->t_nsy_equivalent) 
#define NSYID_of_XSY(xsy) ID_of_NSY(NSY_of_XSY(xsy) ) 
#define NSY_by_XSYID(xsy_id) (XSY_by_ID(xsy_id) ->t_nsy_equivalent) 
#define NSYID_by_XSYID(xsy_id) ID_of_NSY(NSY_of_XSY(XSY_by_ID(xsy_id) ) ) 
#define Nulling_NSY_of_XSY(xsy) ((xsy) ->t_nulling_nsy) 
#define Nulling_NSY_by_XSYID(xsy) (XSY_by_ID(xsy) ->t_nulling_nsy) 
#define Nulling_NSYID_by_XSYID(xsy) ID_of_NSY(XSY_by_ID(xsy) ->t_nulling_nsy) 
#define Nulling_OR_by_NSYID(nsyid) ((OR) NSY_by_ID(nsyid) ) 
#define NSY_by_ID(id) (*MARPA_DSTACK_INDEX(g->t_nsy_stack,NSY,(id) ) ) 
#define ID_of_NSY(nsy) ((nsy) ->t_nsyid)  \

#define NSY_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_nsy_stack) ) 
#define NSY_is_Start(nsy) ((nsy) ->t_is_start) 
#define NSY_is_LHS(nsy) ((nsy) ->t_is_lhs) 
#define NSY_is_Nulling(nsy) ((nsy) ->t_nsy_is_nulling) 
#define NSY_is_Semantic(nsy) ((nsy) ->t_is_semantic) 
#define NSYID_is_Semantic(nsyid) (NSY_is_Semantic(NSY_by_ID(nsyid) ) ) 
#define Source_XSY_of_NSY(nsy) ((nsy) ->t_source_xsy) 
#define Source_XSY_of_NSYID(nsyid) (Source_XSY_of_NSY(NSY_by_ID(nsyid) ) ) 
#define LHS_XRL_of_NSY(nsy) ((nsy) ->t_lhs_xrl) 
#define XRL_Offset_of_NSY(nsy) ((nsy) ->t_xrl_offset) 
#define NSY_Rank_by_XSY(xsy)  \
((xsy) ->t_rank*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK) 
#define Rank_of_NSY(nsy) ((nsy) ->t_rank) 
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
#define LHSID_of_IRL(irlid) ((irlid) ->t_nsyid_array[0]) 
#define LHS_of_IRL(irl) (NSY_by_ID(LHSID_of_IRL(irl) ) )  \

#define RHSID_of_IRL(irl,position) ((irl) ->t_nsyid_array[(position) +1]) 
#define RHS_of_IRL(irl,position) NSY_by_ID(RHSID_of_IRL((irl) ,(position) ) ) 
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
#define LHS_NSYID_of_AIM(item) LHSID_of_IRL(IRL_of_AIM(item) ) 
#define Position_of_AIM(aim) ((aim) ->t_position) 
#define Postdot_NSYID_of_AIM(item) ((item) ->t_postdot_nsyid) 
#define AIM_is_Completion(aim) (Postdot_NSYID_of_AIM(aim) <0) 
#define Null_Count_of_AIM(aim) ((aim) ->t_leading_nulls) 
#define Completion_XSYIDs_of_AHFA(state) ((state) ->t_completion_xsyids) 
#define Nulled_XSYIDs_of_AHFA(state) ((state) ->t_nulled_xsyids) 
#define Prediction_XSYIDs_of_AHFA(state) ((state) ->t_prediction_xsyids) 
#define Completion_CIL_of_AHFA(state) ((state) ->t_complete_nsyids) 
#define Complete_NSYID_of_AHFA(state,ix)  \
Item_of_CIL(Completion_CIL_of_AHFA(state) ,(ix) ) 
#define Complete_NSY_Count_of_AHFA(state)  \
Count_of_CIL(Completion_CIL_of_AHFA(state) )  \

#define AIMs_of_AHFA(ahfa) ((ahfa) ->t_items) 
#define AIM_of_AHFA_by_AEX(ahfa,aex) (AIMs_of_AHFA(ahfa) [aex]) 
#define AEX_of_AHFA_by_AIM(ahfa,aim) aex_of_ahfa_by_aim_get((ahfa) ,(aim) ) 
#define AIM_Count_of_AHFA(ahfa) ((ahfa) ->t_item_count) 
#define AHFA_is_Predicted(ahfa) ((ahfa) ->t_is_predict) 
#define YIM_is_Predicted(yim) AHFA_is_Predicted(AHFA_of_YIM(yim) ) 
#define AHFA_is_Potential_Leo_Base(ahfa) ((ahfa) ->t_is_potential_leo_base) 
#define YIM_is_Potential_Leo_Base(yim) AHFA_is_Potential_Leo_Base(AHFA_of_YIM(yim) ) 
#define Event_Group_Size_of_AHFA(ahfa) ((ahfa) ->t_event_group_size) 
#define Event_AHFAIDs_of_AHFA(ahfa) ((ahfa) ->t_event_ahfaids) 
#define AHFA_has_Event(ahfa) (Count_of_CIL(Event_AHFAIDs_of_AHFA(ahfa) ) !=0) 
#define AHFA_of_G_by_ID(g,id) ((g) ->t_AHFA+(id) ) 
#define AHFA_by_ID(id) (g->t_AHFA+(id) ) 
#define AHFA_Count_of_G(g) ((g) ->t_AHFA_len) 
#define ID_of_AHFA(state) ((state) ->t_key.t_id)  \

#define Postdot_NSY_Count_of_AHFA(state) ((state) ->t_postdot_nsy_count) 
#define Postdot_NSYIDAry_of_AHFA(state) ((state) ->t_postdot_nsyidary) 
#define AIMID_of_AHFA_by_AEX(g,ahfa,aex)  \
((ahfa) ->t_items[aex]-(g) ->t_AHFA_items) 
#define Leo_LHS_NSYID_of_AHFA(state) ((state) ->t_leo_lhs_nsyid) 
#define Leo_IRLID_of_AHFA(state) ((state) ->t_leo_irlid) 
#define AHFA_is_Leo_Completion(state) (Leo_IRLID_of_AHFA(state) >=0) 
#define SET_1ST_PASS_SORT_KEY_FOR_IRL(sort_key,irl) { \
const AIM aim= First_AIM_of_IRL(irl) ; \
(sort_key) = Postdot_NSYID_of_AIM(aim) ; \
}
#define TRANS_of_AHFA_by_NSYID(from_ahfa,nsyid)  \
(*(TRANSs_of_AHFA(from_ahfa) +(nsyid) ) ) 
#define TRANS_of_YIM_by_NSYID(yim,nsyid) TRANS_of_AHFA_by_NSYID(AHFA_of_YIM(yim) ,(nsyid) ) 
#define To_AHFA_of_TRANS(trans) (to_ahfa_of_transition_get(trans) ) 
#define LV_To_AHFA_of_TRANS(trans) ((trans) ->t_ur.t_to_ahfa) 
#define Completion_Count_of_TRANS(trans)  \
(completion_count_of_transition_get(trans) ) 
#define LV_Completion_Count_of_TRANS(trans) ((trans) ->t_ur.t_completion_count) 
#define To_AHFA_of_AHFA_by_NSYID(from_ahfa,id)  \
(To_AHFA_of_TRANS(TRANS_of_AHFA_by_NSYID((from_ahfa) ,(id) ) ) ) 
#define To_AHFA_of_YIM_by_NSYID(yim,id) To_AHFA_of_AHFA_by_NSYID(AHFA_of_YIM(yim) ,(id) ) 
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
#define First_YS_of_R(r) ((r) ->t_first_earley_set) 
#define Latest_YS_of_R(r) ((r) ->t_latest_earley_set) 
#define Current_Earleme_of_R(r) ((r) ->t_current_earleme) 
#define Current_YS_of_R(r) current_ys_of_r(r) 
#define DEFAULT_YIM_WARNING_THRESHOLD (100) 
#define Furthest_Earleme_of_R(r) ((r) ->t_furthest_earleme) 
#define R_is_Exhausted(r) ((r) ->t_is_exhausted) 
#define JEARLEME_THRESHOLD (INT_MAX/4) 
#define Next_YS_of_YS(set) ((set) ->t_next_earley_set) 
#define Postdot_SYM_Count_of_YS(set) ((set) ->t_postdot_sym_count) 
#define First_PIM_of_YS_by_NSYID(set,nsyid) (first_pim_of_ys_by_nsyid((set) ,(nsyid) ) ) 
#define PIM_NSY_P_of_YS_by_NSYID(set,nsyid) (pim_nsy_p_find((set) ,(nsyid) ) ) 
#define YIM_Count_of_YS(set) ((set) ->t_yim_count) 
#define YIMs_of_YS(set) ((set) ->t_earley_items) 
#define YS_Count_of_R(r) ((r) ->t_earley_set_count) 
#define Ord_of_YS(set) ((set) ->t_ordinal) 
#define YS_Ord_is_Valid(r,ordinal)  \
((ordinal) >=0&&(ordinal) <YS_Count_of_R(r) ) 
#define Earleme_of_YS(set) ((set) ->t_key.t_earleme)  \

#define Value_of_YS(set) ((set) ->t_value) 
#define PValue_of_YS(set) ((set) ->t_pvalue) 
#define YIM_FATAL_THRESHOLD (INT_MAX/4) 
#define Complete_NSYID_of_YIM(item,ix)  \
Complete_NSYID_of_AHFA(AHFA_of_YIM(item) ,(ix) ) 
#define Complete_NSY_Count_of_YIM(item)  \
Complete_NSY_Count_of_AHFA(AHFA_of_YIM(item) ) 
#define Leo_IRLID_of_YIM(yim) Leo_IRLID_of_AHFA(AHFA_of_YIM(yim) ) 
#define Earley_Item_is_Completion(item)  \
(Complete_NSY_Count_of_YIM(item) > 0) 
#define YS_of_YIM(item) ((item) ->t_key.t_set) 
#define YS_Ord_of_YIM(item) (Ord_of_YS(YS_of_YIM(item) ) ) 
#define Ord_of_YIM(item) ((item) ->t_ordinal) 
#define Earleme_of_YIM(item) Earleme_of_YS(YS_of_YIM(item) ) 
#define AHFAID_of_YIM(item) (ID_of_AHFA(AHFA_of_YIM(item) ) ) 
#define AHFA_of_YIM(item) ((item) ->t_key.t_state) 
#define AIM_Count_of_YIM(item) (AIM_Count_of_AHFA(AHFA_of_YIM(item) ) ) 
#define Origin_Earleme_of_YIM(item) (Earleme_of_YS(Origin_of_YIM(item) ) ) 
#define Origin_Ord_of_YIM(item) (Ord_of_YS(Origin_of_YIM(item) ) ) 
#define Origin_of_YIM(item) ((item) ->t_key.t_origin) 
#define AIM_of_YIM_by_AEX(yim,aex) AIM_of_AHFA_by_AEX(AHFA_of_YIM(yim) ,(aex) ) 
#define AEX_of_YIM_by_AIM(yim,aim) AEX_of_AHFA_by_AIM(AHFA_of_YIM(yim) ,(aim) ) 
#define NO_SOURCE (0U) 
#define SOURCE_IS_TOKEN (1U) 
#define SOURCE_IS_COMPLETION (2U) 
#define SOURCE_IS_LEO (3U) 
#define SOURCE_IS_AMBIGUOUS (4U) 
#define Source_Type_of_YIM(item) ((item) ->t_source_type) 
#define Earley_Item_has_No_Source(item) ((item) ->t_source_type==NO_SOURCE) 
#define Earley_Item_has_Token_Source(item) ((item) ->t_source_type==SOURCE_IS_TOKEN) 
#define Earley_Item_has_Complete_Source(item) ((item) ->t_source_type==SOURCE_IS_COMPLETION) 
#define Earley_Item_has_Leo_Source(item) ((item) ->t_source_type==SOURCE_IS_LEO) 
#define Earley_Item_is_Ambiguous(item) ((item) ->t_source_type==SOURCE_IS_AMBIGUOUS) 
#define Next_PIM_of_YIX(yix) ((yix) ->t_next) 
#define YIM_of_YIX(yix) ((yix) ->t_earley_item) 
#define Postdot_NSYID_of_YIX(yix) ((yix) ->t_postdot_nsyid) 
#define YIX_of_LIM(lim) ((YIX) (lim) ) 
#define Postdot_NSYID_of_LIM(leo) (Postdot_NSYID_of_YIX(YIX_of_LIM(leo) ) ) 
#define Next_PIM_of_LIM(leo) (Next_PIM_of_YIX(YIX_of_LIM(leo) ) ) 
#define Origin_of_LIM(leo) ((leo) ->t_origin) 
#define Top_AHFA_of_LIM(leo) ((leo) ->t_top_ahfa) 
#define Predecessor_LIM_of_LIM(leo) ((leo) ->t_predecessor) 
#define Base_YIM_of_LIM(leo) ((leo) ->t_base) 
#define YS_of_LIM(leo) ((leo) ->t_set) 
#define Earleme_of_LIM(lim) Earleme_of_YS(YS_of_LIM(lim) ) 
#define CIL_of_LIM(lim) ((lim) ->t_cil) 
#define LIM_of_PIM(pim) ((LIM) (pim) ) 
#define YIX_of_PIM(pim) ((YIX) (pim) ) 
#define Postdot_NSYID_of_PIM(pim) (Postdot_NSYID_of_YIX(YIX_of_PIM(pim) ) ) 
#define YIM_of_PIM(pim) (YIM_of_YIX(YIX_of_PIM(pim) ) ) 
#define Next_PIM_of_PIM(pim) (Next_PIM_of_YIX(YIX_of_PIM(pim) ) )  \

#define PIM_of_LIM(pim) ((PIM) (pim) ) 
#define PIM_is_LIM(pim) (YIM_of_YIX(YIX_of_PIM(pim) ) ==NULL) 
#define Next_SRCL_of_SRCL(link) ((link) ->t_next) 
#define Source_of_SRCL(link) ((link) ->t_source) 
#define SRCL_of_YIM(yim) (&(yim) ->t_container.t_unique) 
#define Source_of_YIM(yim) ((yim) ->t_container.t_unique.t_source) 
#define SRC_of_YIM(yim) (&Source_of_YIM(yim) ) 
#define Predecessor_of_Source(srcd) ((srcd) .t_predecessor) 
#define Predecessor_of_SRC(source) Predecessor_of_Source(*(source) ) 
#define Predecessor_of_YIM(item) Predecessor_of_Source(Source_of_YIM(item) ) 
#define Predecessor_of_SRCL(link) Predecessor_of_Source(Source_of_SRCL(link) ) 
#define LIM_of_SRCL(link) ((LIM) Predecessor_of_SRCL(link) ) 
#define Cause_of_Source(srcd) ((srcd) .t_cause.t_completion) 
#define Cause_of_SRC(source) Cause_of_Source(*(source) ) 
#define Cause_of_YIM(item) Cause_of_Source(Source_of_YIM(item) ) 
#define Cause_of_SRCL(link) Cause_of_Source(Source_of_SRCL(link) ) 
#define TOK_of_Source(srcd) ((srcd) .t_cause.t_token) 
#define TOK_of_SRC(source) TOK_of_Source(*(source) ) 
#define TOK_of_YIM(yim) TOK_of_Source(Source_of_YIM(yim) ) 
#define TOK_of_SRCL(link) TOK_of_Source(Source_of_SRCL(link) ) 
#define NSYID_of_Source(srcd) NSYID_of_TOK(TOK_of_Source(srcd) ) 
#define NSYID_of_SRC(source) NSYID_of_Source(*(source) ) 
#define NSYID_of_YIM(yim) NSYID_of_Source(Source_of_YIM(yim) ) 
#define NSYID_of_SRCL(link) NSYID_of_Source(Source_of_SRCL(link) )  \

#define Cause_AHFAID_of_SRCL(srcl)  \
AHFAID_of_YIM((YIM) Cause_of_SRCL(srcl) ) 
#define Leo_Transition_NSYID_of_SRCL(leo_source_link)  \
Postdot_NSYID_of_LIM(LIM_of_SRCL(leo_source_link) )  \

#define LV_First_Completion_SRCL_of_YIM(item) ((item) ->t_container.t_ambiguous.t_completion) 
#define LV_First_Token_SRCL_of_YIM(item) ((item) ->t_container.t_ambiguous.t_token) 
#define LV_First_Leo_SRCL_of_YIM(item) ((item) ->t_container.t_ambiguous.t_leo) 
#define First_Leo_SRCL_of_YIM(item)  \
(Source_Type_of_YIM(item) ==SOURCE_IS_LEO?(SRCL) SRCL_of_YIM(item) : \
Source_Type_of_YIM(item) ==SOURCE_IS_AMBIGUOUS? \
LV_First_Leo_SRCL_of_YIM(item) :NULL)  \

#define Type_of_TOK(tok) ((tok) ->t_unvalued.t_type) 
#define NSYID_of_TOK(tok) ((tok) ->t_unvalued.t_nsyid) 
#define Value_of_TOK(tok) ((tok) ->t_value) 
#define TOK_Obs_of_R(r) TOK_Obs_of_I(I_of_R(r) ) 
#define TOK_of_ALT(alt) ((alt) ->t_token) 
#define NSYID_of_ALT(alt) NSYID_of_TOK(TOK_of_ALT(alt) ) 
#define Start_YS_of_ALT(alt) ((alt) ->t_start_earley_set) 
#define Start_Earleme_of_ALT(alt) Earleme_of_YS(Start_YS_of_ALT(alt) ) 
#define End_Earleme_of_ALT(alt) ((alt) ->t_end_earleme) 
#define Work_YIMs_of_R(r) MARPA_DSTACK_BASE((r) ->t_yim_work_stack,YIM) 
#define Work_YIM_Count_of_R(r) MARPA_DSTACK_LENGTH((r) ->t_yim_work_stack) 
#define WORK_YIMS_CLEAR(r) MARPA_DSTACK_CLEAR((r) ->t_yim_work_stack) 
#define WORK_YIM_PUSH(r) MARPA_DSTACK_PUSH((r) ->t_yim_work_stack,YIM) 
#define P_YS_of_R_by_Ord(r,ord) MARPA_DSTACK_INDEX((r) ->t_earley_set_stack,YS,(ord) ) 
#define YS_of_R_by_Ord(r,ord) (*P_YS_of_R_by_Ord((r) ,(ord) ) ) 
#define LIM_is_Populated(leo) (Origin_of_LIM(leo) !=NULL) 
#define Prev_UR_of_UR(ur) ((ur) ->t_prev) 
#define Next_UR_of_UR(ur) ((ur) ->t_next) 
#define YIM_of_UR(ur) ((ur) ->t_earley_item) 
#define AEX_of_UR(ur) ((ur) ->t_aex)  \

#define URS_of_R(r) (&(r) ->t_ur_node_stack) 
#define Set_boolean_in_PSIA_for_initial_nulls(yim,aim) { \
 \
if(Position_of_AIM(aim) > 0) { \
const int null_count= Null_Count_of_AIM(aim) ; \
 \
if(null_count) { \
AEX aex= AEX_of_YIM_by_AIM((yim) , \
(aim) ) ; \
 \
or_node_estimate+= null_count; \
psia_test_and_set(bocage_setup_obs,per_ys_data, \
(yim) ,aex) ; \
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
#define YS_Ord_of_OR(or) ((or) ->t_draft.t_end_set_ordinal) 
#define DANDs_of_OR(or) ((or) ->t_draft.t_draft_and_node) 
#define First_ANDID_of_OR(or) ((or) ->t_final.t_first_and_node_id) 
#define AND_Count_of_OR(or) ((or) ->t_final.t_and_node_count) 
#define TOK_of_OR(or) (&(or) ->t_token) 
#define NSYID_of_OR(or) NSYID_of_TOK(TOK_of_OR(or) ) 
#define Value_of_OR(or) Value_of_TOK(TOK_of_OR(or) ) 
#define ORs_of_B(b) ((b) ->t_or_nodes) 
#define OR_of_B_by_ID(b,id) (ORs_of_B(b) [(id) ]) 
#define OR_Count_of_B(b) ((b) ->t_or_node_count) 
#define ANDs_of_B(b) ((b) ->t_and_nodes) 
#define AND_Count_of_B(b) ((b) ->t_and_node_count) 
#define Top_ORID_of_B(b) ((b) ->t_top_or_node_id) 
#define Path_AIM_of_LIM(lim) (base_aim_of_lim(lim) +1) 
#define Base_AIM_of_LIM(lim) (base_aim_of_lim(lim) ) 
#define WHEID_of_NSYID(nsyid) (irl_count+(nsyid) ) 
#define WHEID_of_IRLID(irlid) (irlid) 
#define WHEID_of_IRL(irl) WHEID_of_IRLID(ID_of_IRL(irl) ) 
#define WHEID_of_OR(or) ( \
wheid= OR_is_Token(or) ? \
WHEID_of_NSYID(NSYID_of_OR(or) ) : \
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
YS_Ord_of_OR(predecessor_or) !=work_earley_set_ordinal)  \
break; \
or_node= predecessor_or; \
} \
} \

#define Set_OR_from_Ord_and_SYMI(or_node,origin,symbol_instance) { \
const PSL or_psl_at_origin= per_ys_data[(origin) ].t_or_psl; \
(or_node) = PSL_Datum(or_psl_at_origin,(symbol_instance) ) ; \
} \

#define Set_OR_from_YIM_and_AEX(psia_or,psia_yim,psia_aex) { \
const YIM psia_earley_item= psia_yim; \
const int psia_earley_set_ordinal= YS_Ord_of_YIM(psia_earley_item) ; \
OR**const psia_nodes_by_item=  \
per_ys_data[psia_earley_set_ordinal].t_aexes_by_item; \
const int psia_item_ordinal= Ord_of_YIM(psia_earley_item) ; \
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
#define Rule_Start_of_V(val) ((val) ->public.t_rule_start_ys_id) 
#define Token_Start_of_V(val) ((val) ->public.t_token_start_ys_id) 
#define YS_ID_of_V(val) ((val) ->public.t_ys_id) 
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
#define FSTACK_INIT(stack,type,n) (FSTACK_CLEAR(stack) ,((stack) .t_base= marpa_new(type,n) ) ) 
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
#define FSTACK_DESTROY(stack) (marpa_free((stack) .t_base) )  \

#define DQUEUE_DECLARE(this) struct s_dqueue this
#define DQUEUE_INIT(this,type,initial_size)  \
((this.t_current= 0) ,MARPA_DSTACK_INIT(this.t_stack,type,initial_size) ) 
#define DQUEUE_PUSH(this,type) MARPA_DSTACK_PUSH(this.t_stack,type) 
#define DQUEUE_POP(this,type) MARPA_DSTACK_POP(this.t_stack,type) 
#define DQUEUE_NEXT(this,type) (this.t_current>=MARPA_DSTACK_LENGTH(this.t_stack)  \
?NULL \
:(MARPA_DSTACK_BASE(this.t_stack,type) ) +this.t_current++) 
#define DQUEUE_BASE(this,type) MARPA_DSTACK_BASE(this.t_stack,type) 
#define DQUEUE_END(this) MARPA_DSTACK_LENGTH(this.t_stack) 
#define STOLEN_DQUEUE_DATA_FREE(data) MARPA_STOLEN_DSTACK_DATA_FREE(data)  \

#define Count_of_CIL(cil) (cil[0]) 
#define Item_of_CIL(cil,ix) (cil[1+(ix) ]) 
#define Sizeof_CIL(ix) (sizeof(int) *(1+(ix) ) ) 
#define CAPACITY_OF_CILAR(cilar) (CAPACITY_OF_DSTACK(cilar->t_buffer) -1) 
#define Sizeof_PSL(psar)  \
(sizeof(PSL_Object) +(psar->t_psl_length-1) *sizeof(void*) ) 
#define PSL_Datum(psl,i) ((psl) ->t_data[(i) ]) 
#define Dot_PSAR_of_R(r) (&(r) ->t_dot_psar_object) 
#define Dot_PSL_of_YS(ys) ((ys) ->t_dot_psl) 
#define FATAL_FLAG (0x1u) 
#define MARPA_DEV_ERROR(message) (set_error(g,MARPA_ERR_DEVELOPMENT,(message) ,0u) ) 
#define MARPA_INTERNAL_ERROR(message) (set_error(g,MARPA_ERR_INTERNAL,(message) ,0u) ) 
#define MARPA_ERROR(code) (set_error(g,(code) ,NULL,0u) ) 
#define MARPA_FATAL(code) (set_error(g,(code) ,NULL,FATAL_FLAG) ) 

#line 16325 "./marpa.w"

#include "marpa_obs.h"
#include "marpa_avl.h"
/*104:*/
#line 1024 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:104*//*138:*/
#line 1247 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef const struct s_xsy*XSY_Const;

/*:138*//*444:*/
#line 4727 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:444*//*485:*/
#line 5097 "./marpa.w"
struct s_AHFA_state;
/*:485*//*577:*/
#line 6389 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:577*//*683:*/
#line 7397 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*YS;
typedef const struct s_earley_set*YS_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*YSK;
/*:683*//*724:*/
#line 7839 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*YIM;
typedef const struct s_earley_item*YIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*YIK;

/*:724*//*732:*/
#line 7980 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*YIX;
union u_postdot_item;
/*:732*//*735:*/
#line 8014 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:735*//*812:*/
#line 9047 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:812*//*816:*/
#line 9074 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:816*//*918:*/
#line 10525 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:918*//*946:*/
#line 10938 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:946*//*989:*/
#line 11559 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:989*//*1015:*/
#line 11955 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:1015*//*1047:*/
#line 12426 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:1047*//*1058:*/
#line 12531 "./marpa.w"

struct s_bocage_setup_per_ys;
/*:1058*//*1122:*/
#line 13225 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1122*//*1157:*/
#line 13670 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1157*//*1170:*/
#line 13807 "./marpa.w"

typedef struct s_value*VALUE;
/*:1170*//*1278:*/
#line 15244 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1278*//*1284:*/
#line 15298 "./marpa.w"

struct s_cil_arena;
/*:1284*//*1304:*/
#line 15629 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1304*//*1306:*/
#line 15644 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1306*/
#line 16328 "./marpa.w"

/*45:*/
#line 672 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:45*//*137:*/
#line 1245 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
/*:137*//*205:*/
#line 1754 "./marpa.w"

struct s_nsy;
typedef struct s_nsy*NSY;
typedef Marpa_NSY_ID NSYID;

/*:205*//*242:*/
#line 2020 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:242*//*315:*/
#line 2736 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:315*//*353:*/
#line 2984 "./marpa.w"
typedef int SYMI;
/*:353*//*484:*/
#line 5094 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef int AHFAID;
/*:484*//*578:*/
#line 6395 "./marpa.w"
typedef int AEX;
/*:578*//*599:*/
#line 6724 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:599*//*614:*/
#line 6815 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:614*//*680:*/
#line 7388 "./marpa.w"
typedef Marpa_Earleme JEARLEME;

/*:680*//*682:*/
#line 7392 "./marpa.w"
typedef Marpa_Earley_Set_ID YSID;
/*:682*//*759:*/
#line 8336 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:759*//*761:*/
#line 8348 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:761*//*938:*/
#line 10874 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:938*//*988:*/
#line 11548 "./marpa.w"

typedef int WHEID;

/*:988*//*1014:*/
#line 11951 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:1014*//*1029:*/
#line 12161 "./marpa.w"

typedef struct marpa_progress_item*PROGRESS;
/*:1029*//*1156:*/
#line 13666 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1156*//*1215:*/
#line 14473 "./marpa.w"

typedef unsigned int LBW;
typedef LBW*LBV;

/*:1215*//*1223:*/
#line 14564 "./marpa.w"

typedef LBW Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1223*//*1281:*/
#line 15265 "./marpa.w"

typedef int*CIL;

/*:1281*//*1285:*/
#line 15301 "./marpa.w"

typedef struct s_cil_arena*CILAR;
/*:1285*/
#line 16329 "./marpa.w"

/*1283:*/
#line 15290 "./marpa.w"

struct s_cil_arena{
struct marpa_obstack*t_obs;
MARPA_AVL_TREE t_avl;
MARPA_DSTACK_DECLARE(t_buffer);
};
typedef struct s_cil_arena CILAR_Object;

/*:1283*/
#line 16330 "./marpa.w"

/*44:*/
#line 666 "./marpa.w"
struct marpa_g{
/*128:*/
#line 1192 "./marpa.w"

int t_is_ok;

/*:128*/
#line 667 "./marpa.w"

/*55:*/
#line 747 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xsy_stack);
MARPA_DSTACK_DECLARE(t_nsy_stack);

/*:55*//*64:*/
#line 804 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xrl_stack);
MARPA_DSTACK_DECLARE(t_irl_stack);
/*:64*//*100:*/
#line 999 "./marpa.w"
Bit_Vector t_bv_nsyid_is_terminal;
/*:100*//*102:*/
#line 1008 "./marpa.w"

Bit_Vector t_lbv_xsyid_is_completion_event;
Bit_Vector t_lbv_xsyid_is_nulled_event;
Bit_Vector t_lbv_xsyid_is_prediction_event;
/*:102*//*109:*/
#line 1046 "./marpa.w"

MARPA_DSTACK_DECLARE(t_events);
/*:109*//*117:*/
#line 1118 "./marpa.w"

MARPA_AVL_TREE t_xrl_tree;
/*:117*//*121:*/
#line 1148 "./marpa.w"

struct marpa_obstack*t_obs;
struct marpa_obstack*t_xrl_obs;
/*:121*//*124:*/
#line 1165 "./marpa.w"

CILAR_Object t_cilar;
/*:124*//*130:*/
#line 1207 "./marpa.w"

const char*t_error_string;
/*:130*//*446:*/
#line 4744 "./marpa.w"

AIM t_AHFA_items;
/*:446*//*510:*/
#line 5242 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:510*/
#line 668 "./marpa.w"

/*49:*/
#line 694 "./marpa.w"
int t_ref_count;
/*:49*//*74:*/
#line 855 "./marpa.w"
XSYID t_start_xsy_id;
/*:74*//*78:*/
#line 888 "./marpa.w"

IRL t_start_irl;
/*:78*//*82:*/
#line 905 "./marpa.w"

int t_external_size;
/*:82*//*85:*/
#line 919 "./marpa.w"
int t_max_rule_length;
/*:85*//*89:*/
#line 932 "./marpa.w"
Marpa_Rank t_default_rank;
/*:89*//*131:*/
#line 1209 "./marpa.w"

Marpa_Error_Code t_error;
/*:131*//*354:*/
#line 2986 "./marpa.w"

int t_symbol_instance_count;
/*:354*//*447:*/
#line 4748 "./marpa.w"

unsigned int t_aim_count;
/*:447*//*511:*/
#line 5247 "./marpa.w"
int t_AHFA_len;
/*:511*/
#line 669 "./marpa.w"

/*94:*/
#line 967 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:94*//*97:*/
#line 979 "./marpa.w"
unsigned int t_has_cycle:1;
/*:97*/
#line 670 "./marpa.w"

};
/*:44*//*108:*/
#line 1039 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:108*//*139:*/
#line 1252 "./marpa.w"

struct s_xsy{
/*191:*/
#line 1655 "./marpa.w"

CIL t_nulled_event_xsyids;
/*:191*//*194:*/
#line 1682 "./marpa.w"
NSY t_nsy_equivalent;
/*:194*//*198:*/
#line 1714 "./marpa.w"
NSY t_nulling_nsy;
/*:198*/
#line 1254 "./marpa.w"

/*140:*/
#line 1261 "./marpa.w"
XSYID t_symbol_id;

/*:140*//*146:*/
#line 1295 "./marpa.w"

Marpa_Rank t_rank;
/*:146*/
#line 1255 "./marpa.w"

/*143:*/
#line 1282 "./marpa.w"
unsigned int t_is_start:1;
/*:143*//*150:*/
#line 1342 "./marpa.w"
unsigned int t_is_lhs:1;
/*:150*//*152:*/
#line 1349 "./marpa.w"
unsigned int t_is_sequence_lhs:1;
/*:152*//*154:*/
#line 1363 "./marpa.w"

unsigned int t_is_valued:1;
unsigned int t_is_valued_locked:1;
/*:154*//*158:*/
#line 1407 "./marpa.w"
unsigned int t_is_accessible:1;
/*:158*//*161:*/
#line 1428 "./marpa.w"
unsigned int t_is_counted:1;
/*:161*//*164:*/
#line 1444 "./marpa.w"
unsigned int t_is_nulling:1;
/*:164*//*167:*/
#line 1461 "./marpa.w"
unsigned int t_is_nullable:1;
/*:167*//*170:*/
#line 1482 "./marpa.w"

unsigned int t_is_terminal:1;
unsigned int t_is_locked_terminal:1;
/*:170*//*175:*/
#line 1529 "./marpa.w"
unsigned int t_is_productive:1;
/*:175*//*178:*/
#line 1548 "./marpa.w"
unsigned int t_is_completion_event:1;
/*:178*//*182:*/
#line 1583 "./marpa.w"
unsigned int t_is_nulled_event:1;
/*:182*//*186:*/
#line 1618 "./marpa.w"
unsigned int t_is_prediction_event:1;
/*:186*/
#line 1256 "./marpa.w"

};

/*:139*//*206:*/
#line 1768 "./marpa.w"

struct s_nsy{
int t_or_node_type;
NSYID t_nsyid;
/*228:*/
#line 1918 "./marpa.w"
XSY t_source_xsy;
/*:228*//*232:*/
#line 1941 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:232*/
#line 1772 "./marpa.w"

/*237:*/
#line 1994 "./marpa.w"
Marpa_Rank t_rank;
/*:237*/
#line 1773 "./marpa.w"

/*216:*/
#line 1852 "./marpa.w"
unsigned int t_is_start:1;
/*:216*//*219:*/
#line 1866 "./marpa.w"
unsigned int t_is_lhs:1;
/*:219*//*222:*/
#line 1880 "./marpa.w"
unsigned int t_nsy_is_nulling:1;
/*:222*//*225:*/
#line 1897 "./marpa.w"
unsigned int t_is_semantic:1;
/*:225*/
#line 1774 "./marpa.w"

};
/*:206*//*241:*/
#line 2011 "./marpa.w"

struct s_xrl{
/*254:*/
#line 2311 "./marpa.w"
int t_rhs_length;
/*:254*//*262:*/
#line 2376 "./marpa.w"
Marpa_Rule_ID t_id;

/*:262*//*263:*/
#line 2379 "./marpa.w"

Marpa_Rank t_rank;
/*:263*/
#line 2013 "./marpa.w"

/*267:*/
#line 2427 "./marpa.w"

unsigned int t_null_ranks_high:1;
/*:267*//*271:*/
#line 2468 "./marpa.w"
unsigned int t_is_bnf:1;
/*:271*//*273:*/
#line 2474 "./marpa.w"
unsigned int t_is_sequence:1;
/*:273*//*275:*/
#line 2488 "./marpa.w"
int t_minimum;
/*:275*//*278:*/
#line 2513 "./marpa.w"
XSYID t_separator_id;
/*:278*//*283:*/
#line 2546 "./marpa.w"
unsigned int t_is_discard:1;
/*:283*//*287:*/
#line 2586 "./marpa.w"
unsigned int t_is_proper_separation:1;
/*:287*//*291:*/
#line 2607 "./marpa.w"
unsigned int t_is_loop:1;
/*:291*//*294:*/
#line 2624 "./marpa.w"
unsigned int t_is_nulling:1;
/*:294*//*297:*/
#line 2642 "./marpa.w"
unsigned int t_is_nullable:1;
/*:297*//*301:*/
#line 2660 "./marpa.w"
unsigned int t_is_accessible:1;
/*:301*//*304:*/
#line 2678 "./marpa.w"
unsigned int t_is_productive:1;
/*:304*//*307:*/
#line 2696 "./marpa.w"
unsigned int t_is_used:1;
/*:307*/
#line 2014 "./marpa.w"

/*255:*/
#line 2314 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];


/*:255*/
#line 2015 "./marpa.w"

};
/*:241*//*313:*/
#line 2727 "./marpa.w"

struct s_irl{
/*345:*/
#line 2928 "./marpa.w"
XRL t_source_xrl;
/*:345*//*351:*/
#line 2976 "./marpa.w"
AIM t_first_aim;
/*:351*/
#line 2729 "./marpa.w"

/*316:*/
#line 2747 "./marpa.w"
IRLID t_irl_id;

/*:316*//*323:*/
#line 2784 "./marpa.w"
int t_length;
/*:323*//*336:*/
#line 2868 "./marpa.w"
int t_real_symbol_count;
/*:336*//*339:*/
#line 2886 "./marpa.w"
int t_virtual_start;
/*:339*//*342:*/
#line 2906 "./marpa.w"
int t_virtual_end;
/*:342*//*348:*/
#line 2955 "./marpa.w"
Marpa_Rank t_rank;
/*:348*//*355:*/
#line 2993 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:355*/
#line 2730 "./marpa.w"

/*327:*/
#line 2825 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:327*//*330:*/
#line 2841 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:330*//*333:*/
#line 2857 "./marpa.w"
unsigned int t_is_right_recursive:1;
/*:333*/
#line 2731 "./marpa.w"

/*318:*/
#line 2752 "./marpa.w"

NSYID t_nsyid_array[1];

/*:318*/
#line 2732 "./marpa.w"

};
/*:313*//*368:*/
#line 3186 "./marpa.w"

struct sym_rule_pair
{
XSYID t_symid;
RULEID t_ruleid;
};

/*:368*//*443:*/
#line 4721 "./marpa.w"

struct s_AHFA_item{
int t_sort_key;
/*452:*/
#line 4770 "./marpa.w"

IRL t_irl;

/*:452*/
#line 4724 "./marpa.w"

/*453:*/
#line 4776 "./marpa.w"

int t_position;

/*:453*//*454:*/
#line 4783 "./marpa.w"
NSYID t_postdot_nsyid;

/*:454*//*455:*/
#line 4792 "./marpa.w"

int t_leading_nulls;

/*:455*/
#line 4725 "./marpa.w"

};
/*:443*//*486:*/
#line 5098 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*490:*/
#line 5125 "./marpa.w"

CIL t_completion_xsyids;
CIL t_nulled_xsyids;
CIL t_prediction_xsyids;

/*:490*//*493:*/
#line 5147 "./marpa.w"

CIL t_indirect_completion_event_nsyids;
CIL t_direct_completion_event_nsyids;
CIL t_complete_nsyids;

/*:493*//*495:*/
#line 5156 "./marpa.w"

AIM*t_items;
/*:495*//*506:*/
#line 5231 "./marpa.w"

CIL t_event_ahfaids;
/*:506*//*516:*/
#line 5275 "./marpa.w"
Marpa_Symbol_ID*t_postdot_nsyidary;
/*:516*//*580:*/
#line 6407 "./marpa.w"

TRANS*t_transitions;
/*:580*/
#line 5105 "./marpa.w"

/*496:*/
#line 5159 "./marpa.w"

int t_item_count;
/*:496*//*507:*/
#line 5235 "./marpa.w"

int t_event_group_size;
/*:507*//*517:*/
#line 5276 "./marpa.w"
unsigned int t_postdot_nsy_count;

/*:517*//*528:*/
#line 5439 "./marpa.w"

NSYID t_leo_lhs_nsyid;
IRLID t_leo_irlid;
/*:528*/
#line 5106 "./marpa.w"

/*500:*/
#line 5200 "./marpa.w"

unsigned int t_is_predict:1;

/*:500*//*503:*/
#line 5208 "./marpa.w"

unsigned int t_is_potential_leo_base:1;
/*:503*/
#line 5107 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:486*//*579:*/
#line 6396 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
int t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:579*//*600:*/
#line 6727 "./marpa.w"

struct s_input{
/*609:*/
#line 6797 "./marpa.w"

struct marpa_obstack*t_token_obs;

/*:609*//*611:*/
#line 6802 "./marpa.w"

GRAMMAR t_grammar;
/*:611*/
#line 6729 "./marpa.w"

/*603:*/
#line 6743 "./marpa.w"

int t_ref_count;
/*:603*/
#line 6730 "./marpa.w"

};

/*:600*//*684:*/
#line 7403 "./marpa.w"

struct s_earley_set_key{
JEARLEME t_earleme;
};
typedef struct s_earley_set_key YSK_Object;
/*:684*//*685:*/
#line 7408 "./marpa.w"

struct s_earley_set{
YSK_Object t_key;
union u_postdot_item**t_postdot_ary;
YS t_next_earley_set;
/*687:*/
#line 7423 "./marpa.w"

YIM*t_earley_items;

/*:687*//*1314:*/
#line 15714 "./marpa.w"

PSL t_dot_psl;
/*:1314*/
#line 7413 "./marpa.w"

int t_postdot_sym_count;
/*686:*/
#line 7420 "./marpa.w"

int t_yim_count;
/*:686*//*688:*/
#line 7434 "./marpa.w"

int t_ordinal;
/*:688*//*692:*/
#line 7452 "./marpa.w"

int t_value;
void*t_pvalue;
/*:692*/
#line 7415 "./marpa.w"

};

/*:685*//*733:*/
#line 7984 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
NSYID t_postdot_nsyid;
YIM t_earley_item;
};
typedef struct s_earley_ix YIX_Object;

/*:733*//*736:*/
#line 8017 "./marpa.w"

struct s_leo_item{
YIX_Object t_earley_ix;
/*737:*/
#line 8030 "./marpa.w"

CIL t_cil;

/*:737*/
#line 8020 "./marpa.w"

YS t_origin;
AHFA t_top_ahfa;
LIM t_predecessor;
YIM t_base;
YS t_set;
};
typedef struct s_leo_item LIM_Object;

/*:736*//*743:*/
#line 8111 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
YIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:743*//*813:*/
#line 9055 "./marpa.w"

struct s_token_unvalued{
int t_type;
NSYID t_nsyid;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:813*//*817:*/
#line 9084 "./marpa.w"

struct s_alternative{
TOK t_token;
YS t_start_earley_set;
JEARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:817*//*919:*/
#line 10542 "./marpa.w"

struct s_ur_node_stack{
struct marpa_obstack*t_obs;
UR t_base;
UR t_top;
};
struct s_ur_node{
UR t_prev;
UR t_next;
YIM t_earley_item;
AEX t_aex;
};
/*:919*//*949:*/
#line 10976 "./marpa.w"

struct s_draft_or_node
{
/*948:*/
#line 10970 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:948*/
#line 10979 "./marpa.w"

DAND t_draft_and_node;
};
/*:949*//*950:*/
#line 10982 "./marpa.w"

struct s_final_or_node
{
/*948:*/
#line 10970 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:948*/
#line 10985 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:950*//*951:*/
#line 10993 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:951*//*990:*/
#line 11566 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:990*//*1016:*/
#line 11962 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:1016*//*1059:*/
#line 12533 "./marpa.w"

struct s_bocage_setup_per_ys{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:1059*//*1086:*/
#line 12774 "./marpa.w"

struct marpa_order{
struct marpa_obstack*t_ordering_obs;
ANDID**t_and_node_orderings;
/*1089:*/
#line 12792 "./marpa.w"

BOCAGE t_bocage;

/*:1089*/
#line 12778 "./marpa.w"

/*1092:*/
#line 12812 "./marpa.w"
int t_ref_count;
/*:1092*//*1099:*/
#line 12868 "./marpa.w"
int t_ambiguity_metric;

/*:1099*//*1104:*/
#line 12900 "./marpa.w"
int t_high_rank_count;
/*:1104*/
#line 12779 "./marpa.w"

/*1102:*/
#line 12882 "./marpa.w"

unsigned int t_is_nulling:1;
/*:1102*/
#line 12780 "./marpa.w"

unsigned int t_is_frozen:1;
};
/*:1086*//*1123:*/
#line 13237 "./marpa.w"

/*1158:*/
#line 13681 "./marpa.w"

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

/*:1158*/
#line 13238 "./marpa.w"

/*1172:*/
#line 13821 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1176:*/
#line 13899 "./marpa.w"

struct marpa_obstack*t_obs;
/*:1176*//*1181:*/
#line 13946 "./marpa.w"

MARPA_DSTACK_DECLARE(t_virtual_stack);
/*:1181*//*1203:*/
#line 14099 "./marpa.w"

LBV t_xsy_is_valued;
LBV t_xrl_is_valued;
LBV t_valued_locked;

/*:1203*/
#line 13825 "./marpa.w"

/*1186:*/
#line 13994 "./marpa.w"

int t_ref_count;
/*:1186*//*1198:*/
#line 14075 "./marpa.w"

NOOKID t_nook;
/*:1198*/
#line 13826 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1193:*/
#line 14047 "./marpa.w"

unsigned int t_is_nulling:1;
/*:1193*//*1195:*/
#line 14054 "./marpa.w"

unsigned int t_trace:1;
/*:1195*/
#line 13829 "./marpa.w"

};

/*:1172*/
#line 13239 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_or_node_in_use;
Marpa_Order t_order;
/*1129:*/
#line 13310 "./marpa.w"

int t_ref_count;
/*:1129*//*1136:*/
#line 13390 "./marpa.w"
int t_pause_counter;
/*:1136*/
#line 13245 "./marpa.w"

/*1142:*/
#line 13461 "./marpa.w"

unsigned int t_is_exhausted:1;
/*:1142*//*1145:*/
#line 13469 "./marpa.w"

unsigned int t_is_nulling:1;

/*:1145*/
#line 13246 "./marpa.w"

int t_parse_count;
};

/*:1123*//*1258:*/
#line 15034 "./marpa.w"

struct s_bit_matrix{
int t_row_count;
Bit_Vector_Word t_row_data[1];
};
typedef struct s_bit_matrix*Bit_Matrix;

/*:1258*//*1279:*/
#line 15247 "./marpa.w"

struct s_dqueue{int t_current;struct marpa_dstack_s t_stack;};

/*:1279*//*1305:*/
#line 15635 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1305*//*1307:*/
#line 15660 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1307*/
#line 16331 "./marpa.w"

/*35:*/
#line 575 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;

/*:35*//*952:*/
#line 11001 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:952*//*1035:*/
#line 12187 "./marpa.w"

static const struct marpa_progress_item progress_report_not_ready= {-2,-2,-2};

/*:1035*//*1224:*/
#line 14571 "./marpa.w"

static const unsigned int bv_wordbits= lbv_wordbits;
static const unsigned int bv_modmask= lbv_wordbits-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= lbv_lsb;
static const unsigned int bv_msb= lbv_msb;

/*:1224*//*1358:*/
#line 16091 "./marpa.w"

int(*_marpa_debug_handler)(const char*,...)= 
MARPA_DEFAULT_DEBUG_HANDLER;
int _marpa_debug_level= 0;

/*:1358*/
#line 16332 "./marpa.w"

/*615:*/
#line 6818 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*628:*/
#line 6917 "./marpa.w"

YS t_first_earley_set;
YS t_latest_earley_set;
JEARLEME t_current_earleme;
/*:628*//*640:*/
#line 6989 "./marpa.w"

Bit_Vector t_lbv_xsyid_completion_event_is_active;
Bit_Vector t_lbv_xsyid_nulled_event_is_active;
Bit_Vector t_lbv_xsyid_prediction_event_is_active;
/*:640*//*643:*/
#line 7009 "./marpa.w"
Bit_Vector t_bv_nsyid_is_expected;
/*:643*//*647:*/
#line 7065 "./marpa.w"
LBV t_nsy_expected_is_event;
/*:647*//*673:*/
#line 7359 "./marpa.w"
struct marpa_obstack*t_obs;
/*:673*//*699:*/
#line 7564 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:699*//*706:*/
#line 7638 "./marpa.w"

YIM t_trace_earley_item;
/*:706*//*746:*/
#line 8157 "./marpa.w"

union u_postdot_item**t_trace_pim_nsy_p;
union u_postdot_item*t_trace_postdot_item;
/*:746*//*780:*/
#line 8612 "./marpa.w"

SRCL t_trace_source_link;
/*:780*//*818:*/
#line 9092 "./marpa.w"

MARPA_DSTACK_DECLARE(t_alternatives);
/*:818*//*833:*/
#line 9288 "./marpa.w"

LBV t_valued_terminal;
LBV t_unvalued_terminal;
LBV t_valued;
LBV t_unvalued;
LBV t_valued_locked;

/*:833*//*841:*/
#line 9504 "./marpa.w"
MARPA_DSTACK_DECLARE(t_yim_work_stack);
/*:841*//*845:*/
#line 9519 "./marpa.w"
MARPA_DSTACK_DECLARE(t_completion_stack);
/*:845*//*849:*/
#line 9530 "./marpa.w"
MARPA_DSTACK_DECLARE(t_earley_set_stack);
/*:849*//*874:*/
#line 9984 "./marpa.w"

Bit_Vector t_bv_lim_symbols;
Bit_Vector t_bv_pim_symbols;
void**t_pim_workarea;
/*:874*//*895:*/
#line 10253 "./marpa.w"

void**t_lim_chain;
/*:895*//*920:*/
#line 10555 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:920*//*1030:*/
#line 12163 "./marpa.w"

const struct marpa_progress_item*t_current_report_item;
MARPA_AVL_TRAV t_progress_report_traverser;
/*:1030*//*1308:*/
#line 15668 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1308*/
#line 6821 "./marpa.w"

/*618:*/
#line 6845 "./marpa.w"
int t_ref_count;
/*:618*//*632:*/
#line 6944 "./marpa.w"
int t_earley_item_warning_threshold;
/*:632*//*636:*/
#line 6972 "./marpa.w"
JEARLEME t_furthest_earleme;
/*:636*//*641:*/
#line 6993 "./marpa.w"

int t_active_event_count;
/*:641*//*689:*/
#line 7438 "./marpa.w"

int t_earley_set_count;
/*:689*/
#line 6822 "./marpa.w"

/*625:*/
#line 6909 "./marpa.w"

unsigned int t_input_phase:2;
/*:625*//*665:*/
#line 7296 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:665*//*669:*/
#line 7334 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:669*//*781:*/
#line 8614 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:781*/
#line 6823 "./marpa.w"

};

/*:615*/
#line 16333 "./marpa.w"

/*760:*/
#line 8339 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:760*//*762:*/
#line 8351 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:762*//*763:*/
#line 8357 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:763*//*764:*/
#line 8364 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source_link t_unique;
};

/*:764*/
#line 16334 "./marpa.w"

/*725:*/
#line 7846 "./marpa.w"

struct s_earley_item_key{
AHFA t_state;
YS t_origin;
YS t_set;
};
typedef struct s_earley_item_key YIK_Object;
struct s_earley_item{
YIK_Object t_key;
union u_source_container t_container;
int t_ordinal;
/*730:*/
#line 7946 "./marpa.w"

unsigned int t_source_type:3;

/*:730*/
#line 7857 "./marpa.w"

};
typedef struct s_earley_item YIM_Object;

/*:725*/
#line 16335 "./marpa.w"

/*1048:*/
#line 12428 "./marpa.w"

struct marpa_bocage{
/*953:*/
#line 11011 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:953*//*1050:*/
#line 12437 "./marpa.w"

INPUT t_input;

/*:1050*//*1052:*/
#line 12447 "./marpa.w"

struct marpa_obstack*t_obs;
/*:1052*//*1055:*/
#line 12506 "./marpa.w"

LBV t_valued_bv;
LBV t_valued_locked_bv;

/*:1055*/
#line 12430 "./marpa.w"

/*954:*/
#line 11014 "./marpa.w"

int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:954*//*1070:*/
#line 12673 "./marpa.w"
int t_ambiguity_metric;
/*:1070*//*1074:*/
#line 12687 "./marpa.w"
int t_ref_count;
/*:1074*/
#line 12431 "./marpa.w"

/*1081:*/
#line 12746 "./marpa.w"

unsigned int t_is_nulling:1;
/*:1081*/
#line 12432 "./marpa.w"

};

/*:1048*/
#line 16336 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1364:*/
#line 16158 "./marpa.w"

static const char*yim_tag_safe(char*buffer,YIM yim)UNUSED;
static const char*yim_tag(YIM yim)UNUSED;
/*:1364*//*1366:*/
#line 16183 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1366*//*1368:*/
#line 16209 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1368*//*1370:*/
#line 16241 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AIM aim)UNUSED;
static const char*aim_tag(AIM aim)UNUSED;
/*:1370*/
#line 16339 "./marpa.w"

/*1355:*/
#line 16064 "./marpa.w"

int _marpa_default_debug_handler(const char*format,...)
{
va_list args;
va_start(args,format);
vfprintf(stderr,format,args);
va_end(args);
putc('\n',stderr);
return 1;
}


/*:1355*//*1365:*/
#line 16162 "./marpa.w"

static const char*
yim_tag_safe(char*buffer,YIM yim)
{
if(!yim)return"NULL";
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_YIM(yim),Origin_Earleme_of_YIM(yim),
Earleme_of_YIM(yim));
return buffer;
}

static char DEBUG_yim_tag_buffer[1000];
static const char*
yim_tag(YIM yim)
{
return yim_tag_safe(DEBUG_yim_tag_buffer,yim);
}

/*:1365*//*1367:*/
#line 16188 "./marpa.w"

static char*
lim_tag_safe(char*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_NSYID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}

static char DEBUG_lim_tag_buffer[1000];
static char*
lim_tag(LIM lim)
{
return lim_tag_safe(DEBUG_lim_tag_buffer,lim);
}

/*:1367*//*1369:*/
#line 16213 "./marpa.w"

static const char*
or_tag_safe(char*buffer,OR or)
{
if(!or)return"NULL";
if(OR_is_Token(or))return"TOKEN";
if(Type_of_OR(or)==DUMMY_OR_NODE)return"DUMMY";
sprintf(buffer,"R%d:%d@%d-%d",
ID_of_IRL(IRL_of_OR(or)),Position_of_OR(or),
Origin_Ord_of_OR(or),
YS_Ord_of_OR(or));
return buffer;
}

static char DEBUG_or_tag_buffer[1000];
static const char*
or_tag(OR or)
{
return or_tag_safe(DEBUG_or_tag_buffer,or);
}

/*:1369*//*1371:*/
#line 16244 "./marpa.w"

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

/*:1371*/
#line 16340 "./marpa.w"

#endif
/*36:*/
#line 580 "./marpa.w"

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

/*:36*//*37:*/
#line 598 "./marpa.w"

Marpa_Error_Code
marpa_version(unsigned int*version)
{
*version++= MARPA_MAJOR_VERSION;
*version++= MARPA_MINOR_VERSION;
*version= MARPA_MICRO_VERSION;
return 0;
}

/*:37*//*41:*/
#line 641 "./marpa.w"

int marpa_c_init(Marpa_Config*config)
{
config->t_is_ok= I_AM_OK;
config->t_error= MARPA_ERR_NONE;
config->t_error_string= NULL;
return 0;
}

/*:41*//*42:*/
#line 650 "./marpa.w"

Marpa_Error_Code marpa_c_error(Marpa_Config*config,const char**p_error_string)
{
const Marpa_Error_Code error_code= config->t_error;
const char*error_string= config->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:42*//*47:*/
#line 676 "./marpa.w"

Marpa_Grammar marpa_g_new(Marpa_Config*configuration)
{
GRAMMAR g;
if(configuration&&configuration->t_is_ok!=I_AM_OK){
configuration->t_error= MARPA_ERR_I_AM_NOT_OK;
return NULL;
}
g= marpa_malloc(sizeof(struct marpa_g));

g->t_is_ok= 0;
/*50:*/
#line 695 "./marpa.w"

g->t_ref_count= 1;

/*:50*//*56:*/
#line 751 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xsy_stack,XSY);
MARPA_DSTACK_SAFE(g->t_nsy_stack);

/*:56*//*65:*/
#line 807 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xrl_stack,RULE);
MARPA_DSTACK_SAFE(g->t_irl_stack);

/*:65*//*75:*/
#line 856 "./marpa.w"

g->t_start_xsy_id= -1;
/*:75*//*79:*/
#line 890 "./marpa.w"

g->t_start_irl= NULL;
/*:79*//*83:*/
#line 907 "./marpa.w"

External_Size_of_G(g)= 0;

/*:83*//*86:*/
#line 920 "./marpa.w"

g->t_max_rule_length= 0;

/*:86*//*90:*/
#line 933 "./marpa.w"

g->t_default_rank= 0;
/*:90*//*95:*/
#line 968 "./marpa.w"

g->t_is_precomputed= 0;
/*:95*//*98:*/
#line 980 "./marpa.w"

g->t_has_cycle= 0;
/*:98*//*101:*/
#line 1000 "./marpa.w"
g->t_bv_nsyid_is_terminal= NULL;

/*:101*//*103:*/
#line 1012 "./marpa.w"

g->t_lbv_xsyid_is_completion_event= NULL;
g->t_lbv_xsyid_is_nulled_event= NULL;
g->t_lbv_xsyid_is_prediction_event= NULL;

/*:103*//*110:*/
#line 1050 "./marpa.w"

MARPA_DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:110*//*118:*/
#line 1120 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL,0);
/*:118*//*122:*/
#line 1151 "./marpa.w"

g->t_obs= marpa_obs_init;
g->t_xrl_obs= marpa_obs_begin(0,alignof(struct s_xrl));
/*:122*//*125:*/
#line 1167 "./marpa.w"

cilar_init(&(g)->t_cilar);
/*:125*//*132:*/
#line 1211 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:132*//*449:*/
#line 4753 "./marpa.w"

g->t_AHFA_items= NULL;
/*:449*//*512:*/
#line 5248 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:512*/
#line 687 "./marpa.w"


g->t_is_ok= I_AM_OK;
return g;
}

/*:47*//*51:*/
#line 705 "./marpa.w"

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

/*:51*//*53:*/
#line 722 "./marpa.w"

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

/*:53*//*54:*/
#line 734 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
/*57:*/
#line 755 "./marpa.w"

{
MARPA_DSTACK_DESTROY(g->t_xsy_stack);
MARPA_DSTACK_DESTROY(g->t_nsy_stack);
}

/*:57*//*66:*/
#line 811 "./marpa.w"

MARPA_DSTACK_DESTROY(g->t_irl_stack);
MARPA_DSTACK_DESTROY(g->t_xrl_stack);

/*:66*//*111:*/
#line 1052 "./marpa.w"
MARPA_DSTACK_DESTROY(g->t_events);

/*:111*//*120:*/
#line 1127 "./marpa.w"

/*119:*/
#line 1122 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:119*/
#line 1128 "./marpa.w"


/*:120*//*123:*/
#line 1154 "./marpa.w"

marpa_obs_free(g->t_obs);
marpa_obs_free(g->t_xrl_obs);

/*:123*//*126:*/
#line 1169 "./marpa.w"

cilar_destroy(&(g)->t_cilar);

/*:126*//*450:*/
#line 4755 "./marpa.w"

marpa_free(g->t_AHFA_items);

/*:450*//*513:*/
#line 5252 "./marpa.w"

{
if(g->t_AHFA)
{
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}
}

/*:513*/
#line 738 "./marpa.w"

marpa_free(g);
}

/*:54*//*59:*/
#line 763 "./marpa.w"

int marpa_g_highest_symbol_id(Marpa_Grammar g){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 765 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 766 "./marpa.w"

return XSY_Count_of_G(g)-1;
}

/*:59*//*61:*/
#line 775 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,XSY symbol)
{
const XSYID new_id= MARPA_DSTACK_LENGTH((g)->t_xsy_stack);
*MARPA_DSTACK_PUSH((g)->t_xsy_stack,XSY)= symbol;
symbol->t_symbol_id= new_id;
}

/*:61*//*62:*/
#line 787 "./marpa.w"

PRIVATE int xsy_id_is_valid(GRAMMAR g,XSYID xsy_id)
{
return!XSYID_is_Malformed(xsy_id)&&XSYID_of_G_Exists(xsy_id);
}

/*:62*//*63:*/
#line 794 "./marpa.w"

PRIVATE int nsy_is_valid(GRAMMAR g,NSYID nsyid)
{
return nsyid>=0&&nsyid<NSY_Count_of_G(g);
}

/*:63*//*70:*/
#line 818 "./marpa.w"

int marpa_g_highest_rule_id(Marpa_Grammar g){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 820 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 821 "./marpa.w"

return XRL_Count_of_G(g)-1;
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 825 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 826 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:70*//*72:*/
#line 837 "./marpa.w"

PRIVATE void
rule_add(GRAMMAR g,RULE rule)
{
const RULEID new_id= MARPA_DSTACK_LENGTH((g)->t_xrl_stack);
*MARPA_DSTACK_PUSH((g)->t_xrl_stack,RULE)= rule;
rule->t_id= new_id;
External_Size_of_G(g)+= 1+Length_of_XRL(rule);
g->t_max_rule_length= MAX(Length_of_XRL(rule),g->t_max_rule_length);
}

/*:72*//*76:*/
#line 858 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 861 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 862 "./marpa.w"

return g->t_start_xsy_id;
}
/*:76*//*77:*/
#line 871 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 874 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 875 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 876 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 877 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 878 "./marpa.w"

return g->t_start_xsy_id= xsy_id;
}

/*:77*//*91:*/
#line 935 "./marpa.w"

Marpa_Rank marpa_g_default_rank(Marpa_Grammar g)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 938 "./marpa.w"

clear_error(g);
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 940 "./marpa.w"

return Default_Rank_of_G(g);
}
/*:91*//*92:*/
#line 945 "./marpa.w"

Marpa_Rank marpa_g_default_rank_set(Marpa_Grammar g,Marpa_Rank rank)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 948 "./marpa.w"

clear_error(g);
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 950 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 951 "./marpa.w"

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

/*:92*//*96:*/
#line 970 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 973 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 974 "./marpa.w"

return G_is_Precomputed(g);
}

/*:96*//*99:*/
#line 982 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 985 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 986 "./marpa.w"

return g->t_has_cycle;
}

/*:99*//*113:*/
#line 1062 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{

GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= 0;
}
/*:113*//*114:*/
#line 1071 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{

GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= value;
}

/*:114*//*115:*/
#line 1081 "./marpa.w"

Marpa_Event_Type
marpa_g_event(Marpa_Grammar g,Marpa_Event*public_event,
int ix)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1086 "./marpa.w"

MARPA_DSTACK events= &g->t_events;
GEV internal_event;
int type;

if(ix<0){
MARPA_ERROR(MARPA_ERR_EVENT_IX_NEGATIVE);
return failure_indicator;
}
if(ix>=MARPA_DSTACK_LENGTH(*events)){
MARPA_ERROR(MARPA_ERR_EVENT_IX_OOB);
return failure_indicator;
}
internal_event= MARPA_DSTACK_INDEX(*events,GEV_Object,ix);
type= internal_event->t_type;
public_event->t_type= type;
public_event->t_value= internal_event->t_value;
return type;
}

/*:115*//*116:*/
#line 1106 "./marpa.w"

Marpa_Event_Type
marpa_g_event_count(Marpa_Grammar g)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1110 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1111 "./marpa.w"

return MARPA_DSTACK_LENGTH(g->t_events);
}

/*:116*//*134:*/
#line 1222 "./marpa.w"

Marpa_Error_Code marpa_g_error(Marpa_Grammar g,const char**p_error_string)
{
const Marpa_Error_Code error_code= g->t_error;
const char*error_string= g->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:134*//*135:*/
#line 1233 "./marpa.w"

Marpa_Error_Code
marpa_g_error_clear(Marpa_Grammar g)
{
clear_error(g);
return g->t_error;
}

/*:135*//*141:*/
#line 1263 "./marpa.w"

PRIVATE XSY
symbol_new(GRAMMAR g)
{
XSY xsy= marpa_obs_new(g->t_obs,struct s_xsy,1);
/*144:*/
#line 1283 "./marpa.w"
xsy->t_is_start= 0;
/*:144*//*147:*/
#line 1297 "./marpa.w"

xsy->t_rank= Default_Rank_of_G(g);
/*:147*//*151:*/
#line 1343 "./marpa.w"

XSY_is_LHS(xsy)= 0;

/*:151*//*153:*/
#line 1350 "./marpa.w"

XSY_is_Sequence_LHS(xsy)= 0;

/*:153*//*155:*/
#line 1366 "./marpa.w"

XSY_is_Valued(xsy)= 0;
XSY_is_Valued_Locked(xsy)= 0;

/*:155*//*159:*/
#line 1408 "./marpa.w"

xsy->t_is_accessible= 0;
/*:159*//*162:*/
#line 1429 "./marpa.w"

xsy->t_is_counted= 0;
/*:162*//*165:*/
#line 1445 "./marpa.w"

xsy->t_is_nulling= 0;
/*:165*//*168:*/
#line 1462 "./marpa.w"

xsy->t_is_nullable= 0;
/*:168*//*171:*/
#line 1485 "./marpa.w"

xsy->t_is_terminal= 0;
xsy->t_is_locked_terminal= 0;
/*:171*//*176:*/
#line 1530 "./marpa.w"

xsy->t_is_productive= 0;
/*:176*//*179:*/
#line 1549 "./marpa.w"

xsy->t_is_completion_event= 0;
/*:179*//*183:*/
#line 1584 "./marpa.w"

xsy->t_is_nulled_event= 0;
/*:183*//*187:*/
#line 1619 "./marpa.w"

xsy->t_is_prediction_event= 0;
/*:187*//*192:*/
#line 1667 "./marpa.w"

Nulled_XSYIDs_of_XSY(xsy)= NULL;

/*:192*//*195:*/
#line 1683 "./marpa.w"
NSY_of_XSY(xsy)= NULL;
/*:195*//*199:*/
#line 1715 "./marpa.w"
Nulling_NSY_of_XSY(xsy)= NULL;
/*:199*/
#line 1268 "./marpa.w"

symbol_add(g,xsy);
return xsy;
}

/*:141*//*142:*/
#line 1273 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const XSY symbol= symbol_new(g);
return ID_of_XSY(symbol);
}

/*:142*//*145:*/
#line 1284 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1287 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1288 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1289 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1290 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_start;
}

/*:145*//*148:*/
#line 1300 "./marpa.w"

int marpa_g_symbol_rank(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1305 "./marpa.w"

clear_error(g);
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1307 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1308 "./marpa.w"

/*1336:*/
#line 15890 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1336*/
#line 1309 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
return Rank_of_XSY(xsy);
}
/*:148*//*149:*/
#line 1313 "./marpa.w"

int marpa_g_symbol_rank_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,Marpa_Rank rank)
{
XSY xsy;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1318 "./marpa.w"

clear_error(g);
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1320 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 1321 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1322 "./marpa.w"

/*1336:*/
#line 15890 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1336*/
#line 1323 "./marpa.w"

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

/*:149*//*156:*/
#line 1370 "./marpa.w"

int marpa_g_symbol_is_valued(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1375 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1376 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1377 "./marpa.w"

return XSY_is_Valued(XSY_by_ID(xsy_id));
}

/*:156*//*157:*/
#line 1381 "./marpa.w"

int marpa_g_symbol_is_valued_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1386 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1387 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1388 "./marpa.w"

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

/*:157*//*160:*/
#line 1416 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1419 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1420 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 1421 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1422 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1423 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(xsy_id));
}

/*:160*//*163:*/
#line 1431 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1435 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1436 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1437 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1438 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_counted;
}

/*:163*//*166:*/
#line 1447 "./marpa.w"

int marpa_g_symbol_is_nulling(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1450 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1451 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 1452 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1453 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1454 "./marpa.w"

return XSY_is_Nulling(XSY_by_ID(xsy_id));
}

/*:166*//*169:*/
#line 1464 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1467 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1468 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 1469 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1470 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1471 "./marpa.w"

return XSYID_is_Nullable(xsy_id);
}

/*:169*//*173:*/
#line 1491 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1495 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1496 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1497 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1498 "./marpa.w"

return XSYID_is_Terminal(xsy_id);
}
/*:173*//*174:*/
#line 1501 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1506 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1507 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 1508 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1509 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1510 "./marpa.w"

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

/*:174*//*177:*/
#line 1532 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1537 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1538 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 1539 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1540 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1541 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(xsy_id));
}

/*:177*//*180:*/
#line 1551 "./marpa.w"

int marpa_g_symbol_is_completion_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1555 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1556 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1557 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1558 "./marpa.w"

return XSYID_is_Completion_Event(xsy_id);
}
/*:180*//*181:*/
#line 1561 "./marpa.w"

int marpa_g_symbol_is_completion_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1566 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1567 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 1568 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1569 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1570 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Completion_Event(xsy)= value;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:181*//*184:*/
#line 1586 "./marpa.w"

int marpa_g_symbol_is_nulled_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1590 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1591 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1592 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1593 "./marpa.w"

return XSYID_is_Nulled_Event(xsy_id);
}
/*:184*//*185:*/
#line 1596 "./marpa.w"

int marpa_g_symbol_is_nulled_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1601 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1602 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 1603 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1604 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1605 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Nulled_Event(xsy)= value;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:185*//*188:*/
#line 1621 "./marpa.w"

int marpa_g_symbol_is_prediction_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1625 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1626 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1627 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1628 "./marpa.w"

return XSYID_is_Prediction_Event(xsy_id);
}
/*:188*//*189:*/
#line 1631 "./marpa.w"

int marpa_g_symbol_is_prediction_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1636 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1637 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 1638 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1639 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1640 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Prediction_Event(xsy)= value;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:189*//*190:*/
#line 1650 "./marpa.w"

/*:190*//*196:*/
#line 1684 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1691 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1692 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1693 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:196*//*200:*/
#line 1716 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nulling_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1723 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 1724 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 1725 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= Nulling_NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:200*//*202:*/
#line 1737 "./marpa.w"

PRIVATE
NSY symbol_alias_create(GRAMMAR g,XSY symbol)
{
NSY alias_nsy= semantic_nsy_new(g,symbol);
XSY_is_Nulling(symbol)= 0;
XSY_is_Nullable(symbol)= 1;
NSY_is_Nulling(alias_nsy)= 1;
return alias_nsy;
}

/*:202*//*209:*/
#line 1785 "./marpa.w"

PRIVATE NSY
nsy_start(GRAMMAR g)
{
const NSY nsy= marpa_obs_new(g->t_obs,struct s_nsy,1);
ID_of_NSY(nsy)= MARPA_DSTACK_LENGTH((g)->t_nsy_stack);
*MARPA_DSTACK_PUSH((g)->t_nsy_stack,NSY)= nsy;
/*207:*/
#line 1780 "./marpa.w"

nsy->t_or_node_type= NULLING_TOKEN_OR_NODE;

/*:207*//*217:*/
#line 1853 "./marpa.w"
NSY_is_Start(nsy)= 0;
/*:217*//*220:*/
#line 1867 "./marpa.w"
NSY_is_LHS(nsy)= 0;
/*:220*//*223:*/
#line 1881 "./marpa.w"
NSY_is_Nulling(nsy)= 0;
/*:223*//*226:*/
#line 1898 "./marpa.w"
NSY_is_Semantic(nsy)= 0;
/*:226*//*229:*/
#line 1919 "./marpa.w"
Source_XSY_of_NSY(nsy)= NULL;
/*:229*//*233:*/
#line 1944 "./marpa.w"

LHS_XRL_of_NSY(nsy)= NULL;
XRL_Offset_of_NSY(nsy)= -1;

/*:233*//*238:*/
#line 1995 "./marpa.w"

Rank_of_NSY(nsy)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:238*/
#line 1792 "./marpa.w"

return nsy;
}

/*:209*//*210:*/
#line 1798 "./marpa.w"

PRIVATE NSY
nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_start(g);
Source_XSY_of_NSY(new_nsy)= source;
Rank_of_NSY(new_nsy)= NSY_Rank_by_XSY(source);
return new_nsy;
}

/*:210*//*211:*/
#line 1810 "./marpa.w"

PRIVATE NSY
semantic_nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_new(g,source);
NSY_is_Semantic(new_nsy)= 1;
return new_nsy;
}

/*:211*//*212:*/
#line 1821 "./marpa.w"

PRIVATE NSY
nsy_clone(GRAMMAR g,XSY xsy)
{
const NSY new_nsy= nsy_start(g);
Source_XSY_of_NSY(new_nsy)= xsy;
NSY_is_Semantic(new_nsy)= 1;
Rank_of_NSY(new_nsy)= NSY_Rank_by_XSY(xsy);
NSY_is_Nulling(new_nsy)= XSY_is_Nulling(xsy);
return new_nsy;
}

/*:212*//*215:*/
#line 1843 "./marpa.w"

int _marpa_g_nsy_count(Marpa_Grammar g){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1845 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1846 "./marpa.w"

return NSY_Count_of_G(g);
}

/*:215*//*218:*/
#line 1854 "./marpa.w"

int _marpa_g_nsy_is_start(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1857 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1858 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 1859 "./marpa.w"

/*1337:*/
#line 15895 "./marpa.w"

if(UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1337*/
#line 1860 "./marpa.w"

return NSY_is_Start(NSY_by_ID(nsy_id));
}

/*:218*//*221:*/
#line 1868 "./marpa.w"

int _marpa_g_nsy_is_lhs(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1871 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1872 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 1873 "./marpa.w"

/*1337:*/
#line 15895 "./marpa.w"

if(UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1337*/
#line 1874 "./marpa.w"

return NSY_is_LHS(NSY_by_ID(nsy_id));
}

/*:221*//*224:*/
#line 1882 "./marpa.w"

int _marpa_g_nsy_is_nulling(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1885 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 1886 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 1887 "./marpa.w"

/*1337:*/
#line 15895 "./marpa.w"

if(UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1337*/
#line 1888 "./marpa.w"

return NSY_is_Nulling(NSY_by_ID(nsy_id));
}

/*:224*//*227:*/
#line 1899 "./marpa.w"

int _marpa_g_nsy_is_semantic(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1904 "./marpa.w"

/*1337:*/
#line 15895 "./marpa.w"

if(UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1337*/
#line 1905 "./marpa.w"

return NSYID_is_Semantic(nsy_id);
}

/*:227*//*230:*/
#line 1920 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
XSY source_xsy;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1926 "./marpa.w"

/*1337:*/
#line 15895 "./marpa.w"

if(UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1337*/
#line 1927 "./marpa.w"

source_xsy= Source_XSY_of_NSYID(nsy_id);
return ID_of_XSY(source_xsy);
}

/*:230*//*235:*/
#line 1955 "./marpa.w"

Marpa_Rule_ID _marpa_g_nsy_lhs_xrl(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1958 "./marpa.w"

/*1337:*/
#line 15895 "./marpa.w"

if(UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1337*/
#line 1959 "./marpa.w"

{
const NSY nsy= NSY_by_ID(nsy_id);
const XRL lhs_xrl= LHS_XRL_of_NSY(nsy);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:235*//*236:*/
#line 1979 "./marpa.w"

int _marpa_g_nsy_xrl_offset(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 1982 "./marpa.w"

NSY nsy;
/*1337:*/
#line 15895 "./marpa.w"

if(UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1337*/
#line 1984 "./marpa.w"

nsy= NSY_by_ID(nsy_id);
return XRL_Offset_of_NSY(nsy);
}

/*:236*//*239:*/
#line 1997 "./marpa.w"

Marpa_Rank _marpa_g_nsy_rank(
Marpa_Grammar g,
Marpa_NSY_ID nsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2002 "./marpa.w"

/*1337:*/
#line 15895 "./marpa.w"

if(UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1337*/
#line 2003 "./marpa.w"

return Rank_of_NSY(NSY_by_ID(nsy_id));
}

/*:239*//*245:*/
#line 2038 "./marpa.w"

PRIVATE
XRL xrl_start(GRAMMAR g,const XSYID lhs,const XSYID*rhs,int length)
{
XRL xrl;
const int sizeof_xrl= offsetof(struct s_xrl,t_symbols)+
(length+1)*sizeof(xrl->t_symbols[0]);
marpa_obs_reserve(g->t_xrl_obs,sizeof_xrl);
xrl= marpa_obs_base(g->t_xrl_obs);
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
/*264:*/
#line 2381 "./marpa.w"

rule->t_rank= Default_Rank_of_G(g);
/*:264*//*268:*/
#line 2429 "./marpa.w"

rule->t_null_ranks_high= 0;
/*:268*//*272:*/
#line 2469 "./marpa.w"

rule->t_is_bnf= 0;

/*:272*//*274:*/
#line 2475 "./marpa.w"

rule->t_is_sequence= 0;

/*:274*//*276:*/
#line 2489 "./marpa.w"

rule->t_minimum= -1;
/*:276*//*279:*/
#line 2514 "./marpa.w"

Separator_of_XRL(rule)= -1;
/*:279*//*284:*/
#line 2547 "./marpa.w"

rule->t_is_discard= 0;
/*:284*//*288:*/
#line 2587 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:288*//*292:*/
#line 2608 "./marpa.w"

rule->t_is_loop= 0;
/*:292*//*295:*/
#line 2625 "./marpa.w"

XRL_is_Nulling(rule)= 0;
/*:295*//*298:*/
#line 2643 "./marpa.w"

XRL_is_Nullable(rule)= 0;
/*:298*//*302:*/
#line 2661 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:302*//*305:*/
#line 2679 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:305*//*308:*/
#line 2698 "./marpa.w"

XRL_is_Used(rule)= 0;
/*:308*/
#line 2063 "./marpa.w"

rule_add(g,rule);
return rule;
}

PRIVATE_NOT_INLINE
RULE rule_new(GRAMMAR g,
const XSYID lhs,const XSYID*rhs,int length)
{
RULE rule= xrl_start(g,lhs,rhs,length);
xrl_finish(g,rule);
rule= marpa_obs_finish(g->t_xrl_obs);
return rule;
}

/*:245*//*246:*/
#line 2079 "./marpa.w"

PRIVATE IRL
irl_start(GRAMMAR g,int length)
{
IRL irl;
const int sizeof_irl= offsetof(struct s_irl,t_nsyid_array)+
(length+1)*sizeof(irl->t_nsyid_array[0]);
irl= marpa_obs_alloc(g->t_obs,sizeof_irl);
ID_of_IRL(irl)= MARPA_DSTACK_LENGTH((g)->t_irl_stack);
Length_of_IRL(irl)= length;
/*328:*/
#line 2826 "./marpa.w"

IRL_has_Virtual_LHS(irl)= 0;
/*:328*//*331:*/
#line 2842 "./marpa.w"

IRL_has_Virtual_RHS(irl)= 0;
/*:331*//*334:*/
#line 2858 "./marpa.w"

IRL_is_Right_Recursive(irl)= 0;

/*:334*//*337:*/
#line 2869 "./marpa.w"
Real_SYM_Count_of_IRL(irl)= 0;
/*:337*//*340:*/
#line 2887 "./marpa.w"
irl->t_virtual_start= -1;
/*:340*//*343:*/
#line 2907 "./marpa.w"
irl->t_virtual_end= -1;
/*:343*//*346:*/
#line 2929 "./marpa.w"
Source_XRL_of_IRL(irl)= NULL;
/*:346*//*349:*/
#line 2956 "./marpa.w"

Rank_of_IRL(irl)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:349*//*352:*/
#line 2977 "./marpa.w"

First_AIM_of_IRL(irl)= NULL;

/*:352*//*356:*/
#line 2996 "./marpa.w"

Last_Proper_SYMI_of_IRL(irl)= -1;
/*:356*/
#line 2089 "./marpa.w"

*MARPA_DSTACK_PUSH((g)->t_irl_stack,IRL)= irl;
return irl;
}

PRIVATE void
irl_finish(GRAMMAR g,IRL irl)
{
const NSY lhs_nsy= LHS_of_IRL(irl);
NSY_is_LHS(lhs_nsy)= 1;
}

/*:246*//*248:*/
#line 2115 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,int length)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2120 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2123 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 2124 "./marpa.w"

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
marpa_obs_reject(g->t_xrl_obs);
return failure_indicator;
}
rule= xrl_finish(g,rule);
rule= marpa_obs_finish(g->t_xrl_obs);
XRL_is_BNF(rule)= 1;
rule_id= rule->t_id;
return rule_id;
}

/*:248*//*249:*/
#line 2169 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2176 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2177 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 2178 "./marpa.w"

/*251:*/
#line 2209 "./marpa.w"

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

/*:251*/
#line 2179 "./marpa.w"

/*250:*/
#line 2187 "./marpa.w"

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

/*:250*/
#line 2180 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:249*//*253:*/
#line 2262 "./marpa.w"

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

/*:253*//*256:*/
#line 2317 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:256*//*257:*/
#line 2321 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2323 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2324 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2325 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2326 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:257*//*258:*/
#line 2329 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:258*//*259:*/
#line 2333 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2336 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2337 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2338 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2339 "./marpa.w"

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

/*:259*//*260:*/
#line 2352 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2354 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2355 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2356 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2357 "./marpa.w"

return Length_of_XRL(XRL_by_ID(xrl_id));
}

/*:260*//*265:*/
#line 2384 "./marpa.w"

int marpa_g_rule_rank(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2389 "./marpa.w"

clear_error(g);
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2391 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2392 "./marpa.w"

/*1340:*/
#line 15913 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1340*/
#line 2393 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Rank_of_XRL(xrl);
}
/*:265*//*266:*/
#line 2397 "./marpa.w"

int marpa_g_rule_rank_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,Marpa_Rank rank)
{
XRL xrl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2402 "./marpa.w"

clear_error(g);
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2404 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 2405 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2406 "./marpa.w"

/*1340:*/
#line 15913 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1340*/
#line 2407 "./marpa.w"

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

/*:266*//*269:*/
#line 2433 "./marpa.w"

int marpa_g_rule_null_high(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2438 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2439 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2440 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2441 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Null_Ranks_High_of_RULE(xrl);
}
/*:269*//*270:*/
#line 2445 "./marpa.w"

int marpa_g_rule_null_high_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,int flag)
{
XRL xrl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2450 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2451 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 2452 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2453 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2454 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(UNLIKELY(flag<0||flag> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return Null_Ranks_High_of_RULE(xrl)= flag;
}

/*:270*//*277:*/
#line 2491 "./marpa.w"

int marpa_g_sequence_min(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2496 "./marpa.w"

XRL xrl;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2498 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2499 "./marpa.w"

/*1340:*/
#line 15913 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1340*/
#line 2500 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Minimum_of_XRL(xrl);
}

/*:277*//*280:*/
#line 2516 "./marpa.w"

Marpa_Symbol_ID marpa_g_sequence_separator(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2521 "./marpa.w"

XRL xrl;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2523 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2524 "./marpa.w"

/*1340:*/
#line 15913 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1340*/
#line 2525 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Separator_of_XRL(xrl);
}

/*:280*//*285:*/
#line 2549 "./marpa.w"

int _marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2554 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2555 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2556 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2557 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:285*//*289:*/
#line 2589 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2594 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2595 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2596 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2597 "./marpa.w"

return!XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:289*//*293:*/
#line 2610 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2613 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2614 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2615 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2616 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 2617 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:293*//*296:*/
#line 2627 "./marpa.w"

int marpa_g_rule_is_nulling(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2630 "./marpa.w"

XRL xrl;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2632 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2633 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2634 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nulling(xrl);
}

/*:296*//*299:*/
#line 2645 "./marpa.w"

int marpa_g_rule_is_nullable(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2648 "./marpa.w"

XRL xrl;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2650 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2651 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2652 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nullable(xrl);
}

/*:299*//*303:*/
#line 2663 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2666 "./marpa.w"

XRL xrl;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2668 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2669 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2670 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:303*//*306:*/
#line 2681 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2684 "./marpa.w"

XRL xrl;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2686 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2687 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2688 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:306*//*309:*/
#line 2700 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2704 "./marpa.w"

/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 2705 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 2706 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:309*//*311:*/
#line 2713 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2718 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2719 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:311*//*320:*/
#line 2758 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
IRL irl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2761 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2762 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 2763 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2764 "./marpa.w"

irl= IRL_by_ID(irl_id);
return LHSID_of_IRL(irl);
}

/*:320*//*322:*/
#line 2771 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_rhs(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2774 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2775 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 2776 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2777 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHSID_of_IRL(irl,ix);
}

/*:322*//*324:*/
#line 2785 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2787 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 2788 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 2789 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2790 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}

/*:324*//*329:*/
#line 2828 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2833 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 2834 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2835 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:329*//*332:*/
#line 2844 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2849 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 2850 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2851 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:332*//*338:*/
#line 2870 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2875 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 2876 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2877 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:338*//*341:*/
#line 2888 "./marpa.w"

unsigned int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2894 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 2895 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2896 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:341*//*344:*/
#line 2908 "./marpa.w"

unsigned int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2914 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 2915 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2916 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:344*//*347:*/
#line 2930 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2936 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2937 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:347*//*350:*/
#line 2958 "./marpa.w"

Marpa_Rank _marpa_g_irl_rank(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 2963 "./marpa.w"

/*1338:*/
#line 15900 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1338*/
#line 2964 "./marpa.w"

return Rank_of_IRL(IRL_by_ID(irl_id));
}

/*:350*//*358:*/
#line 3010 "./marpa.w"

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

/*:358*//*360:*/
#line 3042 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 3045 "./marpa.w"

int return_value= failure_indicator;
struct marpa_obstack*obs_precompute= marpa_obs_init;
/*363:*/
#line 3149 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);

/*:363*//*367:*/
#line 3182 "./marpa.w"

XSYID start_xsy_id= g->t_start_xsy_id;

/*:367*//*379:*/
#line 3472 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:379*/
#line 3048 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 3049 "./marpa.w"

G_EVENTS_CLEAR(g);
/*364:*/
#line 3153 "./marpa.w"

if(UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
goto FAILURE;
}

/*:364*/
#line 3051 "./marpa.w"

/*1332:*/
#line 15867 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1332*/
#line 3052 "./marpa.w"

/*366:*/
#line 3163 "./marpa.w"

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

/*:366*/
#line 3053 "./marpa.w"




/*119:*/
#line 1122 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:119*/
#line 3057 "./marpa.w"


{
/*372:*/
#line 3357 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:372*//*373:*/
#line 3360 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;
RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:373*//*377:*/
#line 3421 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:377*/
#line 3060 "./marpa.w"

/*362:*/
#line 3132 "./marpa.w"

{
/*370:*/
#line 3206 "./marpa.w"

{
Marpa_Rule_ID rule_id;


const MARPA_AVL_TREE rhs_avl_tree= 
_marpa_avl_create(sym_rule_cmp,NULL,alignof(struct sym_rule_pair));


struct sym_rule_pair*const p_rh_sym_rule_pair_base= 
marpa_obs_new(MARPA_AVL_OBSTACK(rhs_avl_tree),struct sym_rule_pair,
External_Size_of_G(g));
struct sym_rule_pair*p_rh_sym_rule_pairs= p_rh_sym_rule_pair_base;


const MARPA_AVL_TREE lhs_avl_tree= 
_marpa_avl_create(sym_rule_cmp,NULL,alignof(struct sym_rule_pair));
struct sym_rule_pair*const p_lh_sym_rule_pair_base= 
marpa_obs_new(MARPA_AVL_OBSTACK(lhs_avl_tree),struct sym_rule_pair,
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
MARPA_AVL_TRAV traverser;
struct sym_rule_pair*pair;
XSYID seen_symid= -1;
RULEID*const rule_data_base= 
marpa_obs_new(obs_precompute,RULEID,External_Size_of_G(g));
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(rhs_avl_tree);

xrl_list_x_rh_sym= marpa_obs_new(obs_precompute,RULEID*,pre_census_xsy_count+1);
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
MARPA_AVL_TRAV traverser;
struct sym_rule_pair*pair;
XSYID seen_symid= -1;
RULEID*const rule_data_base= 
marpa_obs_new(obs_precompute,RULEID,xrl_count);
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(lhs_avl_tree);

xrl_list_x_lh_sym= 
marpa_obs_new(obs_precompute,RULEID*,pre_census_xsy_count+1);
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

/*:370*/
#line 3134 "./marpa.w"

/*371:*/
#line 3328 "./marpa.w"

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

/*:371*/
#line 3135 "./marpa.w"

/*378:*/
#line 3443 "./marpa.w"

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

/*:378*/
#line 3136 "./marpa.w"

/*374:*/
#line 3366 "./marpa.w"

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

/*:374*/
#line 3137 "./marpa.w"

/*375:*/
#line 3394 "./marpa.w"

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

/*:375*/
#line 3138 "./marpa.w"

/*376:*/
#line 3415 "./marpa.w"

if(UNLIKELY(!bv_bit_test(productive_v,(unsigned int)start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:376*/
#line 3139 "./marpa.w"

/*380:*/
#line 3477 "./marpa.w"

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

/*:380*/
#line 3140 "./marpa.w"

/*381:*/
#line 3497 "./marpa.w"

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

/*:381*/
#line 3141 "./marpa.w"

/*382:*/
#line 3536 "./marpa.w"

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
/*384:*/
#line 3587 "./marpa.w"

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

/*:384*/
#line 3547 "./marpa.w"

continue;
}
/*383:*/
#line 3556 "./marpa.w"

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

/*:383*/
#line 3550 "./marpa.w"

}
}

/*:382*/
#line 3142 "./marpa.w"

/*385:*/
#line 3641 "./marpa.w"

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

/*:385*/
#line 3143 "./marpa.w"

if(1){
/*386:*/
#line 3669 "./marpa.w"

{
XSYID xsyid;
XRLID xrlid;
int nullable_xsy_count= 0;

void*matrix_buffer= marpa_malloc(matrix_sizeof(
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
marpa_free(matrix_buffer);
}

/*:386*/
#line 3145 "./marpa.w"

}
}

/*:362*/
#line 3061 "./marpa.w"

/*433:*/
#line 4514 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,(unsigned int)xrl_count,
(unsigned int)xrl_count);
/*434:*/
#line 4535 "./marpa.w"

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
/*435:*/
#line 4578 "./marpa.w"

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

/*:435*/
#line 4556 "./marpa.w"

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

/*435:*/
#line 4578 "./marpa.w"

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

/*:435*/
#line 4569 "./marpa.w"

}
}
}
}

/*:434*/
#line 4520 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*436:*/
#line 4592 "./marpa.w"

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

/*:436*/
#line 4522 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:433*/
#line 3062 "./marpa.w"

}


/*550:*/
#line 5854 "./marpa.w"

MARPA_DSTACK_INIT(g->t_irl_stack,IRL,2*MARPA_DSTACK_CAPACITY(g->t_xrl_stack));

/*:550*/
#line 3066 "./marpa.w"

/*551:*/
#line 5862 "./marpa.w"

{
MARPA_DSTACK_INIT(g->t_nsy_stack,NSY,2*MARPA_DSTACK_CAPACITY(g->t_xsy_stack));
}

/*:551*/
#line 3067 "./marpa.w"

/*398:*/
#line 3864 "./marpa.w"

{
/*399:*/
#line 3895 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:399*//*402:*/
#line 3953 "./marpa.w"

int factor_count;
int*factor_positions;
/*:402*/
#line 3866 "./marpa.w"

/*403:*/
#line 3956 "./marpa.w"

factor_positions= marpa_obs_new(obs_precompute,int,g->t_max_rule_length);

/*:403*/
#line 3867 "./marpa.w"

/*400:*/
#line 3901 "./marpa.w"

{
XSYID xsy_id;
for(xsy_id= 0;xsy_id<pre_census_xsy_count;xsy_id++)
{
const XSY xsy_to_clone= XSY_by_ID(xsy_id);
if(UNLIKELY(!xsy_to_clone->t_is_accessible))
continue;
if(UNLIKELY(!xsy_to_clone->t_is_productive))
continue;
NSY_of_XSY(xsy_to_clone)= nsy_clone(g,xsy_to_clone);
if(XSY_is_Nulling(xsy_to_clone))
{
Nulling_NSY_of_XSY(xsy_to_clone)= NSY_of_XSY(xsy_to_clone);
continue;
}
if(XSY_is_Nullable(xsy_to_clone))
{
Nulling_NSY_of_XSY(xsy_to_clone)= symbol_alias_create(g,xsy_to_clone);
}
}
}

/*:400*/
#line 3868 "./marpa.w"

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
/*387:*/
#line 3717 "./marpa.w"

{
const XSYID lhs_id= LHS_ID_of_RULE(rule);
const NSY lhs_nsy= NSY_by_XSYID(lhs_id);
const NSYID lhs_nsyid= ID_of_NSY(lhs_nsy);

const NSY internal_lhs_nsy= nsy_new(g,XSY_by_ID(lhs_id));
const NSYID internal_lhs_nsyid= ID_of_NSY(internal_lhs_nsy);

const XSYID rhs_id= RHS_ID_of_RULE(rule,0);
const NSY rhs_nsy= NSY_by_XSYID(rhs_id);
const NSYID rhs_nsyid= ID_of_NSY(rhs_nsy);

const XSYID separator_id= Separator_of_XRL(rule);
NSYID separator_nsyid= -1;
if(separator_id>=0){
const NSY separator_nsy= NSY_by_XSYID(separator_id);
separator_nsyid= ID_of_NSY(separator_nsy);
}

LHS_XRL_of_NSY(internal_lhs_nsy)= rule;
/*388:*/
#line 3746 "./marpa.w"

{
IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= lhs_nsyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);

IRL_has_Virtual_RHS(rewrite_irl)= 1;
}

/*:388*/
#line 3738 "./marpa.w"

if(separator_nsyid>=0&&!XRL_is_Proper_Separation(rule)){
/*389:*/
#line 3759 "./marpa.w"

{
IRL rewrite_irl;
rewrite_irl= irl_start(g,2);
LHSID_of_IRL(rewrite_irl)= lhs_nsyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_nsyid;
RHSID_of_IRL(rewrite_irl,1)= separator_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);
IRL_has_Virtual_RHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= 1;
}

/*:389*/
#line 3740 "./marpa.w"

}
/*390:*/
#line 3776 "./marpa.w"

{
const IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= internal_lhs_nsyid;
RHSID_of_IRL(rewrite_irl,0)= rhs_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);
IRL_has_Virtual_LHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= 1;
}
/*:390*/
#line 3742 "./marpa.w"

/*391:*/
#line 3787 "./marpa.w"

{
IRL rewrite_irl;
int rhs_ix= 0;
const int length= separator_nsyid>=0?3:2;
rewrite_irl= irl_start(g,length);
LHSID_of_IRL(rewrite_irl)= internal_lhs_nsyid;
RHSID_of_IRL(rewrite_irl,rhs_ix++)= internal_lhs_nsyid;
if(separator_nsyid>=0)
RHSID_of_IRL(rewrite_irl,rhs_ix++)= separator_nsyid;
RHSID_of_IRL(rewrite_irl,rhs_ix)= rhs_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);
IRL_has_Virtual_LHS(rewrite_irl)= 1;
IRL_has_Virtual_RHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= length-1;
}

/*:391*/
#line 3743 "./marpa.w"

}

/*:387*/
#line 3881 "./marpa.w"

continue;
}
/*401:*/
#line 3932 "./marpa.w"

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
/*:401*/
#line 3884 "./marpa.w"


if(factor_count> 0)
{
/*404:*/
#line 3960 "./marpa.w"

{
const XRL chaf_xrl= rule;


int unprocessed_factor_count;

int factor_position_ix= 0;
NSY current_lhs_nsy= NSY_by_XSYID(LHS_ID_of_RULE(rule));
NSYID current_lhs_nsyid= ID_of_NSY(current_lhs_nsy);


int piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*407:*/
#line 3996 "./marpa.w"

NSY chaf_virtual_nsy;
NSYID chaf_virtual_nsyid;
int first_factor_position= factor_positions[factor_position_ix];
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*405:*/
#line 3986 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:405*/
#line 4004 "./marpa.w"

/*408:*/
#line 4023 "./marpa.w"

{
{
const int real_symbol_count= piece_end-piece_start+1;
/*413:*/
#line 4121 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4135 "./marpa.w"

}

/*:413*/
#line 4027 "./marpa.w"
;
}
/*409:*/
#line 4037 "./marpa.w"

{
int piece_ix;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= rewrite_xrl_length-piece_start;
const int real_symbol_count= chaf_irl_length;

IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
for(piece_ix= second_nulling_piece_ix;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,2);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4059 "./marpa.w"

}

/*:409*/
#line 4029 "./marpa.w"
;
{
const int real_symbol_count= piece_end-piece_start+1;
/*415:*/
#line 4167 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,1);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4191 "./marpa.w"

}

/*:415*/
#line 4032 "./marpa.w"
;
}
/*410:*/
#line 4067 "./marpa.w"

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
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
for(piece_ix= second_nulling_piece_ix;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4105 "./marpa.w"

}
}

/*:410*/
#line 4034 "./marpa.w"
;
}

/*:408*/
#line 4005 "./marpa.w"

factor_position_ix++;
}else{
piece_end= second_factor_position;
/*405:*/
#line 3986 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:405*/
#line 4009 "./marpa.w"

/*412:*/
#line 4111 "./marpa.w"

{
const int real_symbol_count= piece_end-piece_start+1;
/*413:*/
#line 4121 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4135 "./marpa.w"

}

/*:413*/
#line 4114 "./marpa.w"

/*414:*/
#line 4139 "./marpa.w"

{
int piece_ix;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;
piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,2);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4163 "./marpa.w"

}

/*:414*/
#line 4115 "./marpa.w"

/*415:*/
#line 4167 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,1);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4191 "./marpa.w"

}

/*:415*/
#line 4116 "./marpa.w"

/*416:*/
#line 4195 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length-1;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4229 "./marpa.w"

}

/*:416*/
#line 4117 "./marpa.w"

}

/*:412*/
#line 4010 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_nsy= chaf_virtual_nsy;
current_lhs_nsyid= chaf_virtual_nsyid;
piece_start= piece_end+1;

/*:407*/
#line 3977 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*417:*/
#line 4234 "./marpa.w"

{
const int first_factor_position= factor_positions[factor_position_ix];
const int second_factor_position= factor_positions[factor_position_ix+1];
const int real_symbol_count= Length_of_XRL(rule)-piece_start;
piece_end= Length_of_XRL(rule)-1;
/*418:*/
#line 4247 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<chaf_irl_length;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4260 "./marpa.w"

}

/*:418*/
#line 4240 "./marpa.w"

/*419:*/
#line 4264 "./marpa.w"

{
int piece_ix;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,2);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4287 "./marpa.w"

}

/*:419*/
#line 4241 "./marpa.w"

/*420:*/
#line 4291 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,1);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4314 "./marpa.w"

}

/*:420*/
#line 4242 "./marpa.w"

/*421:*/
#line 4319 "./marpa.w"

{
if(piece_start<nullable_suffix_ix){
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;piece_ix<second_nulling_piece_ix;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4354 "./marpa.w"

}
}

/*:421*/
#line 4243 "./marpa.w"

}

/*:417*/
#line 3980 "./marpa.w"

}else{
/*422:*/
#line 4359 "./marpa.w"

{
int real_symbol_count;
const int first_factor_position= factor_positions[factor_position_ix];
piece_end= Length_of_XRL(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*423:*/
#line 4370 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<chaf_irl_length;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4383 "./marpa.w"

}

/*:423*/
#line 4365 "./marpa.w"

/*424:*/
#line 4388 "./marpa.w"

{
if(piece_start<nullable_suffix_ix)
{
int piece_ix;
const int nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+nulling_piece_ix));
for(piece_ix= nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*425:*/
#line 4422 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= is_virtual_lhs;
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:425*/
#line 4414 "./marpa.w"

}
}

/*:424*/
#line 4366 "./marpa.w"

}

/*:422*/
#line 3982 "./marpa.w"

}
}

/*:404*/
#line 3888 "./marpa.w"

continue;
}
/*247:*/
#line 2101 "./marpa.w"

{
int symbol_ix;
const IRL new_irl= irl_start(g,rewrite_xrl_length);
Source_XRL_of_IRL(new_irl)= rule;
Rank_of_IRL(new_irl)= IRL_Rank_by_XRL(rule);
for(symbol_ix= 0;symbol_ix<=rewrite_xrl_length;symbol_ix++)
{
new_irl->t_nsyid_array[symbol_ix]= 
NSYID_by_XSYID(rule->t_symbols[symbol_ix]);
}
irl_finish(g,new_irl);
}

/*:247*/
#line 3891 "./marpa.w"

}
}

/*:398*/
#line 3068 "./marpa.w"

/*427:*/
#line 4439 "./marpa.w"

{
const XSY start_xsy= XSY_by_ID(start_xsy_id);
if(LIKELY(!XSY_is_Nulling(start_xsy))){
/*428:*/
#line 4447 "./marpa.w"
{
IRL new_start_irl;

const NSY new_start_nsy= nsy_new(g,start_xsy);
NSY_is_Start(new_start_nsy)= 1;

start_xsy->t_is_start= 0;

new_start_irl= irl_start(g,1);
LHSID_of_IRL(new_start_irl)= ID_of_NSY(new_start_nsy);
RHSID_of_IRL(new_start_irl,0)= NSYID_of_XSY(start_xsy);
irl_finish(g,new_start_irl);
IRL_has_Virtual_LHS(new_start_irl)= 1;
Real_SYM_Count_of_IRL(new_start_irl)= 1;
g->t_start_irl= new_start_irl;

}

/*:428*/
#line 4443 "./marpa.w"

}
}

/*:427*/
#line 3069 "./marpa.w"



if(!G_is_Trivial(g)){
/*549:*/
#line 5842 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
AIM*const item_list_working_buffer
= marpa_obs_alloc(obs_precompute,irl_count*sizeof(AIM));
const NSYID nsy_count= NSY_Count_of_G(g);
const XSYID xsy_count= XSY_Count_of_G(g);
IRLID**irl_list_x_lh_nsy= NULL;
Bit_Matrix nsy_by_right_nsy_matrix;

/*:549*/
#line 3074 "./marpa.w"

/*552:*/
#line 5867 "./marpa.w"

{
IRLID irl_id;
const MARPA_AVL_TREE lhs_avl_tree= 
_marpa_avl_create(sym_rule_cmp,NULL,alignof(struct sym_rule_pair));
struct sym_rule_pair*const p_sym_rule_pair_base= 
marpa_obs_new(MARPA_AVL_OBSTACK(lhs_avl_tree),struct sym_rule_pair,
irl_count);
struct sym_rule_pair*p_sym_rule_pairs= p_sym_rule_pair_base;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
const IRL irl= IRL_by_ID(irl_id);
const NSYID lhs_nsyid= LHSID_of_IRL(irl);
p_sym_rule_pairs->t_symid= lhs_nsyid;
p_sym_rule_pairs->t_ruleid= irl_id;
_marpa_avl_insert(lhs_avl_tree,p_sym_rule_pairs);
p_sym_rule_pairs++;
}
{
MARPA_AVL_TRAV traverser;
struct sym_rule_pair*pair;
NSYID seen_nsyid= -1;
IRLID*const rule_data_base= 
marpa_obs_new(obs_precompute,IRLID,irl_count);
IRLID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(lhs_avl_tree);

irl_list_x_lh_nsy= 
marpa_obs_new(obs_precompute,IRLID*,nsy_count+1);
for(pair= _marpa_avl_t_first(traverser);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(traverser))
{
const NSYID current_nsyid= pair->t_symid;
while(seen_nsyid<current_nsyid)
irl_list_x_lh_nsy[++seen_nsyid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(++seen_nsyid<=nsy_count)
irl_list_x_lh_nsy[seen_nsyid]= p_rule_data;
}
_marpa_avl_destroy(lhs_avl_tree);
}

/*:552*/
#line 3075 "./marpa.w"

/*464:*/
#line 4842 "./marpa.w"

{
IRLID irl_id;
AIMID ahfa_item_count= 0;
AIM base_item;
AIM current_item;
unsigned int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*466:*/
#line 4893 "./marpa.w"

{
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
const NSY nsy= NSY_by_ID(rh_nsyid);
if(!NSY_is_Nulling(nsy))ahfa_item_count++;
}
ahfa_item_count++;
}

/*:466*/
#line 4851 "./marpa.w"

}
current_item= base_item= marpa_new(struct s_AHFA_item,ahfa_item_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*465:*/
#line 4870 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{
Last_Proper_SYMI_of_IRL(irl)= symbol_instance_of_next_rule+rhs_ix;
/*467:*/
#line 4905 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_NSYID_of_AIM(current_item)= rh_nsyid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:467*/
#line 4880 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*468:*/
#line 4914 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_NSYID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:468*/
#line 4889 "./marpa.w"

current_item++;
}

/*:465*/
#line 4856 "./marpa.w"

{
SYMI_of_IRL(irl)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_IRL(irl);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(ahfa_item_count==current_item-base_item);
AIM_Count_of_G(g)= ahfa_item_count;
g->t_AHFA_items= marpa_renew(struct s_AHFA_item,base_item,ahfa_item_count);
/*469:*/
#line 4928 "./marpa.w"

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

/*:469*/
#line 4866 "./marpa.w"

/*474:*/
#line 4986 "./marpa.w"

{
Marpa_AHFA_Item_ID item_id;
AIM*sort_array= marpa_new(struct s_AHFA_item*,ahfa_item_count);
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
marpa_free(sort_array);
}

/*:474*/
#line 4867 "./marpa.w"

}

/*:464*/
#line 3076 "./marpa.w"

/*534:*/
#line 5500 "./marpa.w"

{
/*535:*/
#line 5519 "./marpa.w"

AHFA p_working_state;
const unsigned int initial_no_of_states= 2*AIM_Count_of_G(g);
AIM AHFA_item_0_p= g->t_AHFA_items;
Bit_Matrix prediction_matrix;
IRL*irl_by_sort_key= marpa_new(IRL,irl_count);
Bit_Vector per_ahfa_complete_v= bv_obs_create(obs_precompute,nsy_count);
Bit_Vector per_ahfa_postdot_v= bv_obs_create(obs_precompute,nsy_count);
MARPA_AVL_TREE duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
int ahfa_count_of_g;

/*:535*/
#line 5502 "./marpa.w"

/*536:*/
#line 5532 "./marpa.w"

/*537:*/
#line 5536 "./marpa.w"

{
unsigned int item_id;
unsigned int no_of_items_in_grammar= AIM_Count_of_G(g);
duplicates= _marpa_avl_create(AHFA_state_cmp,NULL,0);
singleton_duplicates= marpa_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++)
{
singleton_duplicates[item_id]= NULL;
}
}

/*:537*/
#line 5533 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:536*/
#line 5503 "./marpa.w"

/*561:*/
#line 6094 "./marpa.w"
{
Bit_Matrix prediction_nsy_by_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*562:*/
#line 6102 "./marpa.w"

{
IRLID irl_id;
NSYID nsyid;
for(nsyid= 0;nsyid<nsy_count;nsyid++)
{

NSY nsy= NSY_by_ID(nsyid);
if(!NSY_is_LHS(nsy))continue;
matrix_bit_set(prediction_nsy_by_nsy_matrix,(unsigned int)nsyid,(unsigned int)nsyid);
}
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
NSYID from_nsyid,to_nsyid;
const IRL irl= IRL_by_ID(irl_id);

const AIM item= First_AIM_of_IRL(irl);
to_nsyid= Postdot_NSYID_of_AIM(item);

if(to_nsyid<0)
continue;

from_nsyid= LHS_NSYID_of_AIM(item);
matrix_bit_set(prediction_nsy_by_nsy_matrix,
(unsigned int)from_nsyid,
(unsigned int)to_nsyid);
}
}

/*:562*/
#line 6097 "./marpa.w"

transitive_closure(prediction_nsy_by_nsy_matrix);
/*563:*/
#line 6137 "./marpa.w"
{
unsigned int*sort_key_by_irl_id= marpa_new(unsigned int,irl_count);
/*565:*/
#line 6155 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
irl_by_sort_key[irl_id]= IRL_by_ID(irl_id);
}
qsort(irl_by_sort_key,(int)irl_count,
sizeof(RULE),cmp_by_irl_sort_key);
}

/*:565*/
#line 6139 "./marpa.w"

/*567:*/
#line 6193 "./marpa.w"

{
IRLID sort_ordinal;
for(sort_ordinal= 0;sort_ordinal<irl_count;sort_ordinal++)
{
IRL irl= irl_by_sort_key[sort_ordinal];
sort_key_by_irl_id[ID_of_IRL(irl)]= sort_ordinal;
}
}

/*:567*/
#line 6140 "./marpa.w"

/*568:*/
#line 6203 "./marpa.w"

{
NSYID from_nsyid;
prediction_matrix= 
matrix_obs_create(obs_precompute,nsy_count,
irl_count);
for(from_nsyid= 0;from_nsyid<nsy_count;from_nsyid++)
{

unsigned int min,max,start;
for(start= 0;
bv_scan(matrix_row
(prediction_nsy_by_nsy_matrix,(unsigned int)from_nsyid),
start,&min,&max);start= max+2)
{
NSYID to_nsyid;
for(to_nsyid= min;to_nsyid<=(NSYID)max;to_nsyid++)
{

RULEID*p_irl_x_lh_nsy= irl_list_x_lh_nsy[to_nsyid];
const RULEID*p_one_past_rules= irl_list_x_lh_nsy[to_nsyid+1];
for(;p_irl_x_lh_nsy<p_one_past_rules;p_irl_x_lh_nsy++)
{

const IRLID irl_with_this_lhs= *p_irl_x_lh_nsy;
unsigned int sort_ordinal= 
sort_key_by_irl_id[irl_with_this_lhs];
matrix_bit_set(prediction_matrix,
(unsigned int)from_nsyid,sort_ordinal);

}
}
}
}
}

/*:568*/
#line 6141 "./marpa.w"

marpa_free(sort_key_by_irl_id);
}

/*:563*/
#line 6099 "./marpa.w"

}

/*:561*/
#line 5504 "./marpa.w"

/*523:*/
#line 5337 "./marpa.w"
{
nsy_by_right_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*524:*/
#line 5348 "./marpa.w"

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


const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{
matrix_bit_set(nsy_by_right_nsy_matrix,
(unsigned int)LHSID_of_IRL(irl),
(unsigned int)rh_nsyid);
break;
}
}
}
}

/*:524*/
#line 5340 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
/*525:*/
#line 5373 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
const IRL irl= IRL_by_ID(irl_id);
int rhs_ix;
for(rhs_ix= Length_of_IRL(irl)-1;rhs_ix>=0;rhs_ix--)
{
const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{



if(matrix_bit_test(nsy_by_right_nsy_matrix,
(unsigned int)rh_nsyid,
(unsigned int)LHSID_of_IRL(irl)))
{
IRL_is_Right_Recursive(irl)= 1;
}
break;
}
}
}
}

/*:525*/
#line 5342 "./marpa.w"

matrix_clear(nsy_by_right_nsy_matrix);
/*526:*/
#line 5400 "./marpa.w"

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


const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{
matrix_bit_set(nsy_by_right_nsy_matrix,
(unsigned int)LHSID_of_IRL(irl),
(unsigned int)rh_nsyid);
break;
}
}
}
}

/*:526*/
#line 5344 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
}

/*:523*/
#line 5505 "./marpa.w"

/*544:*/
#line 5693 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
const IRL start_irl= g->t_start_irl;
NSYID*postdot_nsyidary;
AIM start_item;
NSYID postdot_nsyid;
AIM*item_list= marpa_obs_alloc(g->t_obs,sizeof(AIM));

start_item= First_AIM_of_IRL(start_irl);
item_list[0]= start_item;
AHFA_initialize(p_initial_state);
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= 1;
p_initial_state->t_key.t_id= 0;
AHFA_is_Predicted(p_initial_state)= 0;
TRANSs_of_AHFA(p_initial_state)= transitions_new(g,nsy_count);
Postdot_NSY_Count_of_AHFA(p_initial_state)= 1;
postdot_nsyidary= Postdot_NSYIDAry_of_AHFA(p_initial_state)= 
marpa_obs_alloc(g->t_obs,sizeof(NSYID));
postdot_nsyid= Postdot_NSYID_of_AIM(start_item);
*postdot_nsyidary= postdot_nsyid;
Completion_CIL_of_AHFA(p_initial_state)= 
cil_empty(&g->t_cilar);
p_initial_state->t_empty_transition= create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(unsigned int)postdot_nsyid),
irl_by_sort_key,&states,duplicates,
item_list_working_buffer);
}

/*:544*/
#line 5506 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*538:*/
#line 5548 "./marpa.w"

{
unsigned int no_of_items= p_working_state->t_item_count;
unsigned int current_item_ix= 0;
AIM*item_list;
NSYID working_nsyid;
item_list= p_working_state->t_items;
working_nsyid= Postdot_NSYID_of_AIM(item_list[0]);

if(working_nsyid<0)
goto NEXT_AHFA_STATE;

while(1)
{
int first_working_item_ix= current_item_ix;
int no_of_items_in_new_state;
for(current_item_ix++;
current_item_ix<no_of_items;current_item_ix++)
{
if(Postdot_NSYID_of_AIM(item_list[current_item_ix])!=
working_nsyid)
break;
}
no_of_items_in_new_state= current_item_ix-first_working_item_ix;
if(no_of_items_in_new_state==1)
{
/*547:*/
#line 5752 "./marpa.w"
{
AHFA p_new_state;
AIM*new_state_item_list;
AIM working_aim_p= item_list[first_working_item_ix];
Marpa_AHFA_Item_ID working_aim_id;
NSYID postdot_nsyid;
working_aim_p++;
working_aim_id= working_aim_p-AHFA_item_0_p;
p_new_state= singleton_duplicates[working_aim_id];
if(p_new_state)
{
transition_add(obs_precompute,p_working_state,working_nsyid,p_new_state);
goto NEXT_WORKING_SYMBOL;
}
p_new_state= DQUEUE_PUSH(states,AHFA_Object);

AHFA_initialize(p_new_state);
singleton_duplicates[working_aim_id]= p_new_state;
new_state_item_list= p_new_state->t_items= 
marpa_obs_alloc(g->t_obs,sizeof(AIM));
new_state_item_list[0]= working_aim_p;
p_new_state->t_item_count= 1;
AHFA_is_Predicted(p_new_state)= 0;
p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
TRANSs_of_AHFA(p_new_state)= transitions_new(g,nsy_count);
transition_add(obs_precompute,p_working_state,working_nsyid,p_new_state);
postdot_nsyid= Postdot_NSYID_of_AIM(working_aim_p);
if(postdot_nsyid>=0)
{
NSYID*p_postdot_nsyidary= Postdot_NSYIDAry_of_AHFA(p_new_state)= 
marpa_obs_alloc(g->t_obs,sizeof(NSYID));
Completion_CIL_of_AHFA(p_new_state)
= cil_empty(&g->t_cilar);
Postdot_NSY_Count_of_AHFA(p_new_state)= 1;
*p_postdot_nsyidary= postdot_nsyid;


p_new_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(unsigned int)postdot_nsyid),
irl_by_sort_key,&states,duplicates,
item_list_working_buffer);
}
else
{

const IRL irl= IRL_of_AIM(working_aim_p);
const NSYID lhs_nsyid= LHSID_of_IRL(irl);
Completion_CIL_of_AHFA(p_new_state)= cil_singleton(&g->t_cilar,lhs_nsyid);
completion_count_inc(obs_precompute,p_new_state,lhs_nsyid);

Postdot_NSY_Count_of_AHFA(p_new_state)= 0;
p_new_state->t_empty_transition= NULL;
/*548:*/
#line 5816 "./marpa.w"

{
const IRL aim_irl= IRL_of_AIM(working_aim_p);
if(IRL_is_Right_Recursive(aim_irl))
{
Leo_LHS_NSYID_of_AHFA(p_new_state)= lhs_nsyid;
Leo_IRLID_of_AHFA(p_new_state)= ID_of_IRL(aim_irl);
}
}

/*:548*/
#line 5807 "./marpa.w"

}
}

/*:547*/
#line 5574 "./marpa.w"

}
else
{
/*553:*/
#line 5910 "./marpa.w"

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
transition_add(obs_precompute,p_working_state,working_nsyid,
queued_AHFA_state);
goto NEXT_WORKING_SYMBOL;
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
{
int i;
AIM*const final_aim_list= p_new_state->t_items= 
marpa_obs_alloc(g->t_obs,no_of_items_in_new_state*sizeof(AIM));
for(i= 0;i<no_of_items_in_new_state;i++){
final_aim_list[i]= item_list_working_buffer[i];
}
}
AHFA_initialize(p_new_state);
AHFA_is_Predicted(p_new_state)= 0;
TRANSs_of_AHFA(p_new_state)= transitions_new(g,nsy_count);
/*554:*/
#line 5968 "./marpa.w"

{
int item_ix;
int no_of_postdot_nsys;
bv_clear(per_ahfa_complete_v);
bv_clear(per_ahfa_postdot_v);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_working_buffer[item_ix];
NSYID postdot_nsyid= Postdot_NSYID_of_AIM(item);
if(postdot_nsyid<0)
{
NSYID complete_symbol_nsyid= LHS_NSYID_of_AIM(item);
completion_count_inc(obs_precompute,p_new_state,
complete_symbol_nsyid);
bv_bit_set(per_ahfa_complete_v,
(unsigned int)complete_symbol_nsyid);
}
else
{
bv_bit_set(per_ahfa_postdot_v,(unsigned int)postdot_nsyid);
}
}
if((no_of_postdot_nsys= Postdot_NSY_Count_of_AHFA(p_new_state)= 
bv_count(per_ahfa_postdot_v)))
{
unsigned int min,max,start;
NSYID*p_nsyid= Postdot_NSYIDAry_of_AHFA(p_new_state)= 
marpa_obs_alloc(g->t_obs,
no_of_postdot_nsys*sizeof(NSYID));
for(start= 0;bv_scan(per_ahfa_postdot_v,start,&min,&max);
start= max+2)
{
NSYID postdot_nsyid;
for(postdot_nsyid= (NSYID)min;
postdot_nsyid<=(NSYID)max;postdot_nsyid++)
{
*p_nsyid++= postdot_nsyid;
}
}
}
Completion_CIL_of_AHFA(p_new_state)= cil_bv_add(&g->t_cilar,per_ahfa_complete_v);
}

/*:554*/
#line 5960 "./marpa.w"

transition_add(obs_precompute,p_working_state,working_nsyid,
p_new_state);
/*556:*/
#line 6027 "./marpa.w"

{
int item_ix;
NSYID postdot_nsyid= -1;
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
postdot_nsyid= Postdot_NSYID_of_AIM(item_list_working_buffer[item_ix]);
if(postdot_nsyid>=0)
break;
}
p_new_state->t_empty_transition= NULL;
if(postdot_nsyid>=0)
{
Bit_Vector predicted_rule_vector
= bv_shadow(matrix_row(prediction_matrix,postdot_nsyid));
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{

postdot_nsyid= Postdot_NSYID_of_AIM(item_list_working_buffer[item_ix]);
if(postdot_nsyid<0)
continue;
bv_or_assign(predicted_rule_vector,
matrix_row(prediction_matrix,postdot_nsyid));
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

/*:556*/
#line 5964 "./marpa.w"

}

/*:553*/
#line 5578 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)
break;
working_nsyid= Postdot_NSYID_of_AIM(item_list[current_item_ix]);
if(working_nsyid<0)
break;
}
NEXT_AHFA_STATE:;
}

/*:538*/
#line 5508 "./marpa.w"

}
g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*539:*/
#line 5591 "./marpa.w"

{
int ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
NSYID nsyid;
AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
for(nsyid= 0;nsyid<nsy_count;nsyid++){
TRANS working_transition= transitions[nsyid];
if(working_transition){
int completion_count= Completion_Count_of_TRANS(working_transition);
int sizeof_transition= 
offsetof(struct s_transition,t_aex)+completion_count*
sizeof(transitions[0]->t_aex[0]);
TRANS new_transition= marpa_obs_alloc(g->t_obs,sizeof_transition);
LV_To_AHFA_of_TRANS(new_transition)= To_AHFA_of_TRANS(working_transition);
LV_Completion_Count_of_TRANS(new_transition)= 0;
transitions[nsyid]= new_transition;
}
}
}
}

/*:539*/
#line 5513 "./marpa.w"

/*541:*/
#line 5652 "./marpa.w"

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
NSYID postdot_nsyid= Postdot_NSYID_of_AIM(ahfa_item);
if(postdot_nsyid>=0)
{
TRANS transition= transitions[postdot_nsyid];
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

/*:541*/
#line 5514 "./marpa.w"

/*540:*/
#line 5621 "./marpa.w"

{
int ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
const AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
if(Complete_NSY_Count_of_AHFA(ahfa)> 0){
AIM*aims= AIMs_of_AHFA(ahfa);
int aim_count= AIM_Count_of_AHFA(ahfa);
AEX aex;
for(aex= 0;aex<aim_count;aex++){
AIM ahfa_item= aims[aex];
if(AIM_is_Completion(ahfa_item)){
NSYID completed_nsyid= LHS_NSYID_of_AIM(ahfa_item);
TRANS transition= transitions[completed_nsyid];
AEX*aexes= AEXs_of_TRANS(transition);
int aex_ix= LV_Completion_Count_of_TRANS(transition)++;
aexes[aex_ix]= aex;
}
}
}
}
}

/*:540*/
#line 5515 "./marpa.w"

/*542:*/
#line 5685 "./marpa.w"

marpa_free(irl_by_sort_key);
/*543:*/
#line 5689 "./marpa.w"

marpa_free(singleton_duplicates);
_marpa_avl_destroy(duplicates);

/*:543*/
#line 5687 "./marpa.w"


/*:542*/
#line 5516 "./marpa.w"

}

/*:534*/
#line 3077 "./marpa.w"

/*591:*/
#line 6533 "./marpa.w"

{
int xsy_id;
g->t_bv_nsyid_is_terminal= bv_obs_create(g->t_obs,nsy_count);
for(xsy_id= 0;xsy_id<xsy_count;xsy_id++)
{
if(XSYID_is_Terminal(xsy_id))
{


const NSY nsy= NSY_of_XSY(XSY_by_ID(xsy_id));
if(nsy)
{
bv_bit_set(g->t_bv_nsyid_is_terminal,
(unsigned int)ID_of_NSY(nsy));
}
}
}
}

/*:591*/
#line 3078 "./marpa.w"

/*592:*/
#line 6554 "./marpa.w"

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

/*:592*/
#line 3079 "./marpa.w"

/*593:*/
#line 6577 "./marpa.w"

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
const NSYID postdot_nsyid= Postdot_NSYID_of_AIM(aim);
const IRL irl= IRL_of_AIM(aim);
int raw_position= Position_of_AIM(aim);
if(raw_position<0)
{
raw_position= Length_of_IRL(irl);
if(!IRL_has_Virtual_LHS(irl))
{
const NSY lhs= LHS_of_IRL(irl);
const XSY xsy= Source_XSY_of_NSY(lhs);
if(XSY_is_Completion_Event(xsy))
{
const XSYID xsyid= ID_of_XSY(xsy);
bv_bit_set(bv_completion_xsyid,xsyid);
}
}
}
if(postdot_nsyid>=0)
{
const XSY xsy= Source_XSY_of_NSYID(postdot_nsyid);
const XSYID xsyid= ID_of_XSY(xsy);
bv_bit_set(bv_prediction_xsyid,xsyid);
}
for(rhs_ix= raw_position-Null_Count_of_AIM(aim);
rhs_ix<raw_position;rhs_ix++)
{
int cil_ix;
const NSYID rhs_nsyid= RHSID_of_IRL(irl,rhs_ix);
const XSY xsy= Source_XSY_of_NSYID(rhs_nsyid);
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

/*:593*/
#line 3081 "./marpa.w"

/*594:*/
#line 6647 "./marpa.w"

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

/*:594*/
#line 3082 "./marpa.w"

/*595:*/
#line 6663 "./marpa.w"

{
const AHFAID ahfa_count_of_g= AHFA_Count_of_G(g);
AHFAID outer_ahfa_id;
for(outer_ahfa_id= 0;outer_ahfa_id<ahfa_count_of_g;outer_ahfa_id++)
{
AHFAID inner_ahfa_id;
const AHFA outer_ahfa= AHFA_by_ID(outer_ahfa_id);




const NSYID outer_nsyid= Leo_LHS_NSYID_of_AHFA(outer_ahfa);
if(outer_nsyid<0){
if(AHFA_has_Event(outer_ahfa)){
Event_Group_Size_of_AHFA(outer_ahfa)= 1;
}
continue;

}
for(inner_ahfa_id= 0;inner_ahfa_id<ahfa_count_of_g;
inner_ahfa_id++)
{
IRLID inner_nsyid;
const AHFA inner_ahfa= AHFA_by_ID(inner_ahfa_id);
if(!AHFA_has_Event(inner_ahfa))
continue;

inner_nsyid= Leo_LHS_NSYID_of_AHFA(inner_ahfa);
if(inner_nsyid<0)
continue;

if(matrix_bit_test(nsy_by_right_nsy_matrix,
(unsigned int)outer_nsyid,
(unsigned int)inner_nsyid))
{
Event_Group_Size_of_AHFA(outer_ahfa)++;

}
}
}
}

/*:595*/
#line 3083 "./marpa.w"

}
g->t_is_precomputed= 1;
if(g->t_has_cycle)
{
MARPA_ERROR(MARPA_ERR_GRAMMAR_HAS_CYCLE);
goto FAILURE;
}
/*596:*/
#line 6710 "./marpa.w"

{cilar_reinit(&g->t_cilar);}
/*:596*/
#line 3091 "./marpa.w"

return_value= 0;
goto CLEANUP;
FAILURE:;
goto CLEANUP;
CLEANUP:;
marpa_obs_free(obs_precompute);
return return_value;
}

/*:360*//*369:*/
#line 3193 "./marpa.w"

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

/*:369*//*451:*/
#line 4759 "./marpa.w"

PRIVATE int aim_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:451*//*456:*/
#line 4796 "./marpa.w"

int _marpa_g_AHFA_item_count(Marpa_Grammar g){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 4798 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 4799 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:456*//*457:*/
#line 4803 "./marpa.w"

Marpa_IRL_ID _marpa_g_AHFA_item_irl(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 4806 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 4807 "./marpa.w"

/*1342:*/
#line 15924 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1342*/
#line 4808 "./marpa.w"

return IRLID_of_AIM(AIM_by_ID(item_id));
}

/*:457*//*459:*/
#line 4813 "./marpa.w"

int _marpa_g_AHFA_item_position(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 4816 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 4817 "./marpa.w"

/*1342:*/
#line 15924 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1342*/
#line 4818 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:459*//*461:*/
#line 4823 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_item_postdot(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 4826 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 4827 "./marpa.w"

/*1342:*/
#line 15924 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1342*/
#line 4828 "./marpa.w"

return Postdot_NSYID_of_AIM(AIM_by_ID(item_id));
}

/*:461*//*462:*/
#line 4832 "./marpa.w"

int _marpa_g_AHFA_item_sort_key(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 4835 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 4836 "./marpa.w"

/*1342:*/
#line 15924 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1342*/
#line 4837 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:462*//*471:*/
#line 4947 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:471*//*473:*/
#line 4962 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_postdot_and_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
int a_postdot= Postdot_NSYID_of_AIM(a);
int b_postdot= Postdot_NSYID_of_AIM(b);
if(a_postdot==b_postdot)
return Sort_Key_of_AIM(a)-Sort_Key_of_AIM(b);
if(a_postdot<0)return 1;
if(b_postdot<0)return-1;
return a_postdot-b_postdot;
}

/*:473*//*487:*/
#line 5114 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*504:*/
#line 5210 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;


/*:504*//*508:*/
#line 5237 "./marpa.w"

Event_AHFAIDs_of_AHFA(ahfa)= NULL;
Event_Group_Size_of_AHFA(ahfa)= 0;

/*:508*//*529:*/
#line 5442 "./marpa.w"

Leo_LHS_NSYID_of_AHFA(ahfa)= -1;
Leo_IRLID_of_AHFA(ahfa)= -1;
/*:529*/
#line 5117 "./marpa.w"

}

/*:487*//*498:*/
#line 5171 "./marpa.w"

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

/*:498*//*515:*/
#line 5265 "./marpa.w"

PRIVATE int AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:515*//*518:*/
#line 5279 "./marpa.w"

int _marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:518*//*519:*/
#line 5284 "./marpa.w"

int
_marpa_g_AHFA_state_item_count(Marpa_Grammar g,AHFAID AHFA_state_id)
{/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 5287 "./marpa.w"

AHFA state;
/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 5289 "./marpa.w"

/*1343:*/
#line 15929 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1343*/
#line 5290 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:519*//*520:*/
#line 5297 "./marpa.w"

Marpa_AHFA_Item_ID _marpa_g_AHFA_state_item(Marpa_Grammar g,
AHFAID AHFA_state_id,
int item_ix){
AHFA state;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 5302 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 5303 "./marpa.w"

/*1343:*/
#line 15929 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1343*/
#line 5304 "./marpa.w"

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

/*:520*//*521:*/
#line 5317 "./marpa.w"

int _marpa_g_AHFA_state_is_predict(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 5321 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 5322 "./marpa.w"

/*1343:*/
#line 15929 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1343*/
#line 5323 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:521*//*530:*/
#line 5445 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_state_leo_lhs_symbol(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 5448 "./marpa.w"

AHFA state;
/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 5450 "./marpa.w"

/*1343:*/
#line 15929 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1343*/
#line 5451 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_NSYID_of_AHFA(state);
}

/*:530*//*533:*/
#line 5472 "./marpa.w"

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

/*:533*//*555:*/
#line 6018 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,MARPA_AVL_TREE duplicates)
{
const AHFA state_found= _marpa_avl_insert(duplicates,sought_state);
return state_found;
}

/*:555*//*566:*/
#line 6171 "./marpa.w"

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

/*:566*//*569:*/
#line 6239 "./marpa.w"

PRIVATE_NOT_INLINE AHFA
create_predicted_AHFA_state(
GRAMMAR g,
Bit_Vector prediction_rule_vector,
IRL*irl_by_sort_key,
DQUEUE states_p,
MARPA_AVL_TREE duplicates,
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
marpa_obs_alloc(g->t_obs,no_of_items_in_new_state*sizeof(AIM));
for(i= 0;i<no_of_items_in_new_state;i++)
{
final_aim_list[i]= item_list_working_buffer[i];
}
}
AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_empty_transition= NULL;
TRANSs_of_AHFA(p_new_state)= transitions_new(g,NSY_Count_of_G(g));
Completion_CIL_of_AHFA(p_new_state)= cil_empty(&g->t_cilar);
/*570:*/
#line 6303 "./marpa.w"

{
NSYID nsy_count= NSY_Count_of_G(g);
int item_ix;
NSYID no_of_postdot_nsys;
Bit_Vector postdot_v= bv_create(nsy_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_working_buffer[item_ix];
NSYID postdot_nsyid= Postdot_NSYID_of_AIM(item);
if(postdot_nsyid>=0)
bv_bit_set(postdot_v,(unsigned int)postdot_nsyid);
}
if((no_of_postdot_nsys= Postdot_NSY_Count_of_AHFA(p_new_state)= 
bv_count(postdot_v)))
{
unsigned int min,max,start;
NSYID*p_nsyid= Postdot_NSYIDAry_of_AHFA(p_new_state)= 
marpa_obs_alloc(g->t_obs,
no_of_postdot_nsys*sizeof(NSYID));
for(start= 0;bv_scan(postdot_v,start,&min,&max);start= max+2)
{
NSYID postdot_nsyid;
for(postdot_nsyid= (NSYID)min;
postdot_nsyid<=(NSYID)max;postdot_nsyid++)
{
*p_nsyid++= postdot_nsyid;
}
}
}
bv_free(postdot_v);
}

/*:570*/
#line 6299 "./marpa.w"

return p_new_state;
}

/*:569*//*581:*/
#line 6409 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:581*//*582:*/
#line 6415 "./marpa.w"

PRIVATE int completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:582*//*583:*/
#line 6422 "./marpa.w"

PRIVATE
URTRANS transition_new(struct marpa_obstack*obstack,AHFA to_ahfa,int aim_ix)
{
URTRANS transition;
transition= marpa_obs_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:583*//*584:*/
#line 6433 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g,int nsy_count)
{
int nsyid= 0;
TRANS*transitions= marpa_obs_new(g->t_obs,TRANS,nsy_count);
while(nsyid<nsy_count)transitions[nsyid++]= NULL;


return transitions;
}

/*:584*//*585:*/
#line 6444 "./marpa.w"

PRIVATE
void transition_add(struct marpa_obstack*obstack,AHFA from_ahfa,NSYID nsyid,AHFA to_ahfa)
{
TRANS*transitions= TRANSs_of_AHFA(from_ahfa);
TRANS transition= transitions[nsyid];
if(!transition){
transitions[nsyid]= (TRANS)transition_new(obstack,to_ahfa,0);
return;
}
LV_To_AHFA_of_TRANS(transition)= to_ahfa;
return;
}

/*:585*//*586:*/
#line 6462 "./marpa.w"

PRIVATE
void completion_count_inc(struct marpa_obstack*obstack,AHFA from_ahfa,NSYID nsyid)
{
TRANS*transitions= TRANSs_of_AHFA(from_ahfa);
TRANS transition= transitions[nsyid];
if(!transition){
transitions[nsyid]= (TRANS)transition_new(obstack,NULL,1);
return;
}
LV_Completion_Count_of_TRANS(transition)++;
return;
}

/*:586*//*588:*/
#line 6477 "./marpa.w"

int _marpa_g_AHFA_state_transitions(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id,
int*buffer,
int buffer_size
){

/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 6484 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
XSYID nsyid;
int nsy_count;
int ix= 0;
const int max_ix= buffer_size/sizeof(*buffer);
const int max_results= max_ix/2;





/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 6497 "./marpa.w"

/*1343:*/
#line 15929 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1343*/
#line 6498 "./marpa.w"

if(max_results<=0)return 0;
from_ahfa_state= AHFA_of_G_by_ID(g,AHFA_state_id);
transitions= TRANSs_of_AHFA(from_ahfa_state);
nsy_count= NSY_Count_of_G(g);
for(nsyid= 0;nsyid<nsy_count;nsyid++){
AHFA to_ahfa_state= To_AHFA_of_TRANS(transitions[nsyid]);
if(!to_ahfa_state)continue;
buffer[ix++]= nsyid;
buffer[ix++]= ID_of_AHFA(to_ahfa_state);
if(ix/2>=max_results)break;
}
return ix/2;
}

/*:588*//*590:*/
#line 6517 "./marpa.w"

AHFAID _marpa_g_AHFA_state_empty_transition(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 6522 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 6523 "./marpa.w"

/*1343:*/
#line 15929 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1343*/
#line 6524 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}

/*:590*//*601:*/
#line 6733 "./marpa.w"

PRIVATE INPUT input_new(GRAMMAR g)
{
INPUT input= marpa_malloc(sizeof(struct s_input));
TOK_Obs_of_I(input)= marpa_obs_init;
/*604:*/
#line 6745 "./marpa.w"

input->t_ref_count= 1;

/*:604*//*612:*/
#line 6804 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:612*/
#line 6738 "./marpa.w"

return input;
}

/*:601*//*605:*/
#line 6749 "./marpa.w"

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

/*:605*//*606:*/
#line 6762 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:606*//*607:*/
#line 6775 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
marpa_obs_free(TOK_Obs_of_I(input));
marpa_free(input);
}

/*:607*//*616:*/
#line 6830 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
NSYID nsy_count;
/*1330:*/
#line 15859 "./marpa.w"
void*const failure_indicator= NULL;
/*:1330*/
#line 6835 "./marpa.w"

/*1333:*/
#line 15873 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1333*/
#line 6836 "./marpa.w"

nsy_count= NSY_Count_of_G(g);
r= marpa_malloc(sizeof(struct marpa_r));
/*674:*/
#line 7360 "./marpa.w"
r->t_obs= marpa_obs_init;
/*:674*/
#line 6839 "./marpa.w"

/*619:*/
#line 6846 "./marpa.w"

r->t_ref_count= 1;

/*:619*//*627:*/
#line 6912 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:627*//*629:*/
#line 6921 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:629*//*633:*/
#line 6945 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_YIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:633*//*637:*/
#line 6973 "./marpa.w"
r->t_furthest_earleme= 0;
/*:637*//*642:*/
#line 6995 "./marpa.w"

r->t_lbv_xsyid_completion_event_is_active= NULL;
r->t_lbv_xsyid_nulled_event_is_active= NULL;
r->t_lbv_xsyid_prediction_event_is_active= NULL;
r->t_active_event_count= 0;

/*:642*//*644:*/
#line 7010 "./marpa.w"

r->t_bv_nsyid_is_expected= bv_obs_create(r->t_obs,(unsigned int)nsy_count);
/*:644*//*648:*/
#line 7066 "./marpa.w"

r->t_nsy_expected_is_event= lbv_obs_new0(r->t_obs,nsy_count);
/*:648*//*666:*/
#line 7299 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:666*//*670:*/
#line 7335 "./marpa.w"
r->t_is_exhausted= 0;
/*:670*//*690:*/
#line 7440 "./marpa.w"

r->t_earley_set_count= 0;

/*:690*//*700:*/
#line 7566 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:700*//*707:*/
#line 7640 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:707*//*747:*/
#line 8160 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;
/*:747*//*782:*/
#line 8616 "./marpa.w"

r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:782*//*815:*/
#line 9066 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:815*//*819:*/
#line 9095 "./marpa.w"

MARPA_DSTACK_INIT2(r->t_alternatives,ALT_Object);
/*:819*//*842:*/
#line 9505 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_yim_work_stack);
/*:842*//*846:*/
#line 9520 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_completion_stack);
/*:846*//*850:*/
#line 9531 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_earley_set_stack);
/*:850*//*921:*/
#line 10561 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:921*//*1031:*/
#line 12166 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
r->t_progress_report_traverser= NULL;
/*:1031*//*1309:*/
#line 15670 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1309*/
#line 6840 "./marpa.w"

return r;
}

/*:616*//*620:*/
#line 6850 "./marpa.w"

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

/*:620*//*621:*/
#line 6868 "./marpa.w"

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

/*:621*//*622:*/
#line 6882 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 6886 "./marpa.w"

/*624:*/
#line 6900 "./marpa.w"
input_unref(input);

/*:624*//*820:*/
#line 9097 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_alternatives);

/*:820*//*844:*/
#line 9513 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_yim_work_stack);

/*:844*//*848:*/
#line 9528 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_completion_stack);

/*:848*//*851:*/
#line 9532 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_earley_set_stack);

/*:851*//*922:*/
#line 10563 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:922*//*1033:*/
#line 12175 "./marpa.w"

/*1032:*/
#line 12169 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:1032*/
#line 12176 "./marpa.w"
;
/*:1033*//*1310:*/
#line 15672 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1310*/
#line 6887 "./marpa.w"

grammar_unref(g);
/*675:*/
#line 7361 "./marpa.w"
marpa_obs_free(r->t_obs);

/*:675*/
#line 6889 "./marpa.w"

marpa_free(r);
}

/*:622*//*630:*/
#line 6929 "./marpa.w"

unsigned int marpa_r_current_earleme(Marpa_Recognizer r)
{return Current_Earleme_of_R(r);}

/*:630*//*631:*/
#line 6934 "./marpa.w"

PRIVATE YS current_ys_of_r(RECCE r)
{
const YS latest= Latest_YS_of_R(r);
if(Earleme_of_YS(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:631*//*634:*/
#line 6947 "./marpa.w"

int
marpa_r_earley_item_warning_threshold(Marpa_Recognizer r)
{
return r->t_earley_item_warning_threshold;
}

/*:634*//*635:*/
#line 6956 "./marpa.w"

int
marpa_r_earley_item_warning_threshold_set(Marpa_Recognizer r,int threshold)
{
const int new_threshold= threshold<=0?YIM_FATAL_THRESHOLD:threshold;
r->t_earley_item_warning_threshold= new_threshold;
return new_threshold;
}

/*:635*//*638:*/
#line 6974 "./marpa.w"

unsigned int marpa_r_furthest_earleme(Marpa_Recognizer r)
{return Furthest_Earleme_of_R(r);}

/*:638*//*645:*/
#line 7018 "./marpa.w"

int marpa_r_terminals_expected(Marpa_Recognizer r,Marpa_Symbol_ID*buffer)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7021 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7022 "./marpa.w"

unsigned int min,max,start;
int ix= 0;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7025 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 7026 "./marpa.w"

for(start= 0;bv_scan(r->t_bv_nsyid_is_expected,start,&min,&max);
start= max+2)
{
NSYID nsyid;
for(nsyid= (NSYID)min;nsyid<=(NSYID)max;nsyid++)
{
const XSY xsy= Source_XSY_of_NSYID(nsyid);
buffer[ix++]= ID_of_XSY(xsy);
}
}
return ix;
}
/*:645*//*646:*/
#line 7039 "./marpa.w"

int marpa_r_terminal_is_expected(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7043 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7044 "./marpa.w"

XSY xsy;
NSY nsy;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7047 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 7048 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 7049 "./marpa.w"

/*1336:*/
#line 15890 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1336*/
#line 7050 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(UNLIKELY(!XSY_is_Terminal(xsy))){
return 0;
}
nsy= NSY_of_XSY(xsy);
if(UNLIKELY(!nsy))return 0;
return bv_bit_test(r->t_bv_nsyid_is_expected,ID_of_NSY(nsy));
}

/*:646*//*649:*/
#line 7069 "./marpa.w"

int marpa_r_expected_symbol_event_set(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
NSY nsy;
NSYID nsyid;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7075 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7076 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7077 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 7078 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 7079 "./marpa.w"

if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
xsy= XSY_by_ID(xsy_id);
if(UNLIKELY(XSY_is_Nulling(xsy))){
MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NULLING);
}
nsy= NSY_of_XSY(xsy);
if(UNLIKELY(!nsy)){
MARPA_ERROR(MARPA_ERR_SYMBOL_IS_UNUSED);
}
nsyid= ID_of_NSY(nsy);
if(value){
lbv_bit_set(r->t_nsy_expected_is_event,nsyid);
}else{
lbv_bit_clear(r->t_nsy_expected_is_event,nsyid);
}
return value;
}

/*:649*//*651:*/
#line 7116 "./marpa.w"

int marpa_r_completion_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7119 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7120 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7121 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 7122 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 7123 "./marpa.w"

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

/*:651*//*653:*/
#line 7161 "./marpa.w"

int marpa_r_nulled_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7164 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7165 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7166 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 7167 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 7168 "./marpa.w"

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

/*:653*//*655:*/
#line 7206 "./marpa.w"

int marpa_r_prediction_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7209 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7210 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7211 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 7212 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 7213 "./marpa.w"

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

/*:655*//*667:*/
#line 7305 "./marpa.w"

int _marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7308 "./marpa.w"

/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7309 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7310 "./marpa.w"

return r->t_use_leo_flag;
}
/*:667*//*668:*/
#line 7313 "./marpa.w"

int _marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7317 "./marpa.w"

/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7318 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7319 "./marpa.w"

/*1344:*/
#line 15938 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1344*/
#line 7320 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:668*//*672:*/
#line 7346 "./marpa.w"

int marpa_r_is_exhausted(Marpa_Recognizer r)
{
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7349 "./marpa.w"

/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7350 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7351 "./marpa.w"

return R_is_Exhausted(r);
}

/*:672*//*694:*/
#line 7459 "./marpa.w"

int marpa_r_earley_set_value(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7462 "./marpa.w"

YS earley_set;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7464 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7465 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 7466 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return Value_of_YS(earley_set);
}

/*:694*//*695:*/
#line 7482 "./marpa.w"

int
marpa_r_earley_set_values(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id,
int*p_value,void**p_pvalue)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7487 "./marpa.w"

YS earley_set;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7489 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7490 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 7491 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
if(p_value)*p_value= Value_of_YS(earley_set);
if(p_pvalue)*p_pvalue= PValue_of_YS(earley_set);
return 1;
}

/*:695*//*696:*/
#line 7509 "./marpa.w"

int marpa_r_latest_earley_set_value_set(Marpa_Recognizer r,int value)
{
YS earley_set;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7513 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7514 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7515 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 7516 "./marpa.w"

earley_set= Latest_YS_of_R(r);
return Value_of_YS(earley_set)= value;
}

/*:696*//*697:*/
#line 7521 "./marpa.w"

int marpa_r_latest_earley_set_values_set(Marpa_Recognizer r,int value,
void*pvalue)
{
YS earley_set;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7526 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7527 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7528 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 7529 "./marpa.w"

earley_set= Latest_YS_of_R(r);
Value_of_YS(earley_set)= value;
PValue_of_YS(earley_set)= pvalue;
return 1;
}

/*:697*//*698:*/
#line 7537 "./marpa.w"

PRIVATE YS
earley_set_new(RECCE r,JEARLEME id)
{
YSK_Object key;
YS set;
set= marpa_obs_alloc(r->t_obs,sizeof(*set));
key.t_earleme= id;
set->t_key= key;
set->t_postdot_ary= NULL;
set->t_postdot_sym_count= 0;
YIM_Count_of_YS(set)= 0;
set->t_ordinal= r->t_earley_set_count++;
YIMs_of_YS(set)= NULL;
Next_YS_of_YS(set)= NULL;
/*693:*/
#line 7455 "./marpa.w"

Value_of_YS(set)= -1;
PValue_of_YS(set)= NULL;

/*:693*//*1315:*/
#line 15716 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1315*/
#line 7552 "./marpa.w"

return set;
}

/*:698*//*701:*/
#line 7569 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_trace_earley_set(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7572 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7573 "./marpa.w"

YS trace_earley_set= r->t_trace_earley_set;
/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 7575 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
return Ord_of_YS(trace_earley_set);
}

/*:701*//*702:*/
#line 7583 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7586 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7587 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 7588 "./marpa.w"

return Ord_of_YS(Latest_YS_of_R(r));
}

/*:702*//*703:*/
#line 7592 "./marpa.w"

Marpa_Earleme marpa_r_earleme(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7595 "./marpa.w"

/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7596 "./marpa.w"

YS earley_set;
/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 7598 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7599 "./marpa.w"

if(set_id<0){
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return Earleme_of_YS(earley_set);
}

/*:703*//*705:*/
#line 7616 "./marpa.w"

int _marpa_r_earley_set_size(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7619 "./marpa.w"

YS earley_set;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7621 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 7622 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 7623 "./marpa.w"

r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return YIM_Count_of_YS(earley_set);
}

/*:705*//*712:*/
#line 7680 "./marpa.w"

Marpa_Earleme
_marpa_r_earley_set_trace(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
YS earley_set;
const int es_does_not_exist= -1;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7686 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7687 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 7688 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_YS(r->t_trace_earley_set)==set_id)
{


return Earleme_of_YS(r->t_trace_earley_set);
}
/*713:*/
#line 7711 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*749:*/
#line 8200 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:749*/
#line 7714 "./marpa.w"

}

/*:713*/
#line 7695 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(set_id>=MARPA_DSTACK_LENGTH(r->t_earley_set_stack))
{
return es_does_not_exist;
}
earley_set= YS_of_R_by_Ord(r,set_id);
r->t_trace_earley_set= earley_set;
return Earleme_of_YS(earley_set);
}

/*:712*//*714:*/
#line 7717 "./marpa.w"

Marpa_AHFA_State_ID
_marpa_r_earley_item_trace(Marpa_Recognizer r,Marpa_Earley_Item_ID item_id)
{
const int yim_does_not_exist= -1;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7722 "./marpa.w"

YS trace_earley_set;
YIM earley_item;
YIM*earley_items;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7726 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 7727 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*713:*/
#line 7711 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*749:*/
#line 8200 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:749*/
#line 7714 "./marpa.w"

}

/*:713*/
#line 7731 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
trace_earley_item_clear(r);
if(item_id<0)
{
MARPA_ERROR(MARPA_ERR_YIM_ID_INVALID);
return failure_indicator;
}
if(item_id>=YIM_Count_of_YS(trace_earley_set))
{
return yim_does_not_exist;
}
earley_items= YIMs_of_YS(trace_earley_set);
earley_item= earley_items[item_id];
r->t_trace_earley_item= earley_item;
return AHFAID_of_YIM(earley_item);
}

/*:714*//*716:*/
#line 7760 "./marpa.w"

PRIVATE void trace_earley_item_clear(RECCE r)
{
/*715:*/
#line 7757 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:715*/
#line 7763 "./marpa.w"

trace_source_link_clear(r);
}

/*:716*//*717:*/
#line 7767 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_earley_item_origin(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 7770 "./marpa.w"

YIM item= r->t_trace_earley_item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7772 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 7773 "./marpa.w"

if(!item){
/*715:*/
#line 7757 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:715*/
#line 7775 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}
return Origin_Ord_of_YIM(item);
}

/*:717*//*726:*/
#line 7867 "./marpa.w"

PRIVATE YIM earley_item_create(const RECCE r,
const YIK_Object key)
{
/*1330:*/
#line 15859 "./marpa.w"
void*const failure_indicator= NULL;
/*:1330*/
#line 7871 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 7872 "./marpa.w"

YIM new_item;
YIM*end_of_work_stack;
const YS set= key.t_set;
const int count= ++YIM_Count_of_YS(set);
/*728:*/
#line 7919 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(UNLIKELY(count>=YIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_YIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:728*/
#line 7877 "./marpa.w"

new_item= marpa_obs_new(r->t_obs,struct s_earley_item,1);
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_YIM(new_item)= count-1;
end_of_work_stack= WORK_YIM_PUSH(r);
*end_of_work_stack= new_item;
return new_item;
}

/*:726*//*727:*/
#line 7887 "./marpa.w"

PRIVATE YIM
earley_item_assign(const RECCE r,const YS set,const YS origin,
const AHFA state)
{
YIK_Object key;
YIM yim;
PSL psl;
AHFAID ahfa_id= ID_of_AHFA(state);
PSL*psl_owner= &Dot_PSL_of_YS(origin);
if(!*psl_owner)
{
psl_claim(psl_owner,Dot_PSAR_of_R(r));
}
psl= *psl_owner;
yim= PSL_Datum(psl,ahfa_id);
if(yim
&&Earleme_of_YIM(yim)==Earleme_of_YS(set)
&&Earleme_of_YS(Origin_of_YIM(yim))==Earleme_of_YS(origin))
{
return yim;
}
key.t_origin= origin;
key.t_state= state;
key.t_set= set;
yim= earley_item_create(r,key);
PSL_Datum(psl,ahfa_id)= yim;
return yim;
}

/*:727*//*731:*/
#line 7951 "./marpa.w"

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

/*:731*//*739:*/
#line 8038 "./marpa.w"

Marpa_Symbol_ID _marpa_r_leo_predecessor_symbol(Marpa_Recognizer r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8042 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8045 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8046 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item)){
MARPA_ERROR(MARPA_ERR_PIM_IS_NOT_LIM);
return failure_indicator;
}
predecessor_leo_item= Predecessor_LIM_of_LIM(LIM_of_PIM(postdot_item));
if(!predecessor_leo_item)return no_predecessor;
return Postdot_NSYID_of_LIM(predecessor_leo_item);
}

/*:739*//*740:*/
#line 8060 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_leo_base_origin(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8064 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8066 "./marpa.w"

YIM base_earley_item;
/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8068 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_YIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_YIM(base_earley_item);
}

/*:740*//*741:*/
#line 8078 "./marpa.w"

Marpa_AHFA_State_ID _marpa_r_leo_base_state(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8082 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
YIM base_earley_item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8085 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8086 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_YIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_YIM(base_earley_item);
}

/*:741*//*744:*/
#line 8124 "./marpa.w"

PRIVATE PIM*
pim_nsy_p_find(YS set,NSYID nsyid)
{
int lo= 0;
int hi= Postdot_SYM_Count_of_YS(set)-1;
PIM*postdot_array= set->t_postdot_ary;
while(hi>=lo){
int trial= lo+(hi-lo)/2;
PIM trial_pim= postdot_array[trial];
NSYID trial_nsyid= Postdot_NSYID_of_PIM(trial_pim);
if(trial_nsyid==nsyid)return postdot_array+trial;
if(trial_nsyid<nsyid){
lo= trial+1;
}else{
hi= trial-1;
}
}
return NULL;
}
/*:744*//*745:*/
#line 8144 "./marpa.w"

PRIVATE PIM first_pim_of_ys_by_nsyid(YS set,NSYID nsyid)
{
PIM*pim_nsy_p= pim_nsy_p_find(set,nsyid);
return pim_nsy_p?*pim_nsy_p:NULL;
}

/*:745*//*748:*/
#line 8174 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_postdot_symbol_trace(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8179 "./marpa.w"

YS current_ys= r->t_trace_earley_set;
PIM*pim_nsy_p;
PIM pim;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8183 "./marpa.w"

/*749:*/
#line 8200 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:749*/
#line 8184 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8185 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 8186 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 8187 "./marpa.w"

if(!current_ys){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
pim_nsy_p= PIM_NSY_P_of_YS_by_NSYID(current_ys,NSYID_by_XSYID(xsy_id));
pim= *pim_nsy_p;
if(!pim)return-1;
r->t_trace_pim_nsy_p= pim_nsy_p;
r->t_trace_postdot_item= pim;
return xsy_id;
}

/*:748*//*750:*/
#line 8210 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_postdot_item_trace(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8214 "./marpa.w"

YS current_earley_set= r->t_trace_earley_set;
PIM pim;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8217 "./marpa.w"

PIM*pim_nsy_p;
/*749:*/
#line 8200 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:749*/
#line 8219 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8220 "./marpa.w"

if(!current_earley_set){
/*715:*/
#line 7757 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:715*/
#line 8222 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
if(current_earley_set->t_postdot_sym_count<=0)return-1;
pim_nsy_p= current_earley_set->t_postdot_ary+0;
pim= pim_nsy_p[0];
r->t_trace_pim_nsy_p= pim_nsy_p;
r->t_trace_postdot_item= pim;
return Postdot_NSYID_of_PIM(pim);
}

/*:750*//*751:*/
#line 8241 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_postdot_item_trace(Marpa_Recognizer r)
{
const XSYID no_more_postdot_symbols= -1;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8246 "./marpa.w"

YS current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_nsy_p;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8250 "./marpa.w"


pim_nsy_p= r->t_trace_pim_nsy_p;
pim= r->t_trace_postdot_item;
/*749:*/
#line 8200 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:749*/
#line 8254 "./marpa.w"

if(!pim_nsy_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8259 "./marpa.w"

if(!current_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
pim= Next_PIM_of_PIM(pim);
if(!pim){

pim_nsy_p++;
if(pim_nsy_p-current_set->t_postdot_ary
>=current_set->t_postdot_sym_count){
return no_more_postdot_symbols;
}
pim= *pim_nsy_p;
}
r->t_trace_pim_nsy_p= pim_nsy_p;
r->t_trace_postdot_item= pim;
return Postdot_NSYID_of_PIM(pim);
}

/*:751*//*752:*/
#line 8279 "./marpa.w"

Marpa_AHFA_State_ID _marpa_r_postdot_item_symbol(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8282 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8284 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8285 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_NSYID_of_PIM(postdot_item);
}


/*:752*//*768:*/
#line 8407 "./marpa.w"
PRIVATE
void
tkn_link_add(RECCE r,
YIM item,
YIM predecessor,
TOK tkn)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_YIM(item);
if(previous_source_type==NO_SOURCE)
{
const SRCL source_link= SRCL_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_TOKEN;
Predecessor_of_SRCL(source_link)= predecessor;
TOK_of_SRCL(source_link)= tkn;
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= marpa_obs_alloc(r->t_obs,sizeof(*new_link));
new_link->t_next= LV_First_Token_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
TOK_of_Source(new_link->t_source)= tkn;
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:768*//*773:*/
#line 8485 "./marpa.w"

PRIVATE
void
completion_link_add(RECCE r,
YIM item,
YIM predecessor,
YIM cause)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_YIM(item);
if(previous_source_type==NO_SOURCE)
{
const SRCL source_link= SRCL_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_COMPLETION;
Predecessor_of_SRCL(source_link)= predecessor;
Cause_of_SRCL(source_link)= cause;
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= marpa_obs_alloc(r->t_obs,sizeof(*new_link));
new_link->t_next= LV_First_Completion_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
}

/*:773*//*774:*/
#line 8515 "./marpa.w"

PRIVATE void
leo_link_add(RECCE r,
YIM item,
LIM predecessor,
YIM cause)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_YIM(item);
if(previous_source_type==NO_SOURCE)
{
const SRCL source_link= SRCL_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_LEO;
Predecessor_of_SRCL(source_link)= predecessor;
Cause_of_SRCL(source_link)= cause;
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= marpa_obs_alloc(r->t_obs,sizeof(*new_link));
new_link->t_next= LV_First_Leo_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Leo_SRCL_of_YIM(item)= new_link;
}

/*:774*//*776:*/
#line 8564 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,YIM item)
{
unsigned int previous_source_type= Source_Type_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*777:*/
#line 8581 "./marpa.w"
{
SRCL new_link= marpa_obs_alloc(r->t_obs,sizeof(*new_link));
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:777*/
#line 8572 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*778:*/
#line 8589 "./marpa.w"
{
SRCL new_link= marpa_obs_alloc(r->t_obs,sizeof(*new_link));
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:778*/
#line 8574 "./marpa.w"

return;
case SOURCE_IS_LEO:/*779:*/
#line 8597 "./marpa.w"
{
SRCL new_link= marpa_obs_alloc(r->t_obs,sizeof(*new_link));
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= new_link;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:779*/
#line 8576 "./marpa.w"

return;
}
}

/*:776*//*784:*/
#line 8626 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_token_link_trace(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8629 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8633 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8634 "./marpa.w"

/*798:*/
#line 8821 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:798*/
#line 8635 "./marpa.w"

source_type= Source_Type_of_YIM(item);
switch(source_type)
{
case SOURCE_IS_TOKEN:
r->t_trace_source_type= SOURCE_IS_TOKEN;
source_link= SRCL_of_YIM(item);
r->t_trace_source_link= source_link;
return NSYID_of_SRCL(source_link);
case SOURCE_IS_AMBIGUOUS:
{
source_link= LV_First_Token_SRCL_of_YIM(item);
if(source_link)
{
r->t_trace_source_type= SOURCE_IS_TOKEN;
r->t_trace_source_link= source_link;
return NSYID_of_SRCL(source_link);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:784*//*787:*/
#line 8667 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_token_link_trace(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8670 "./marpa.w"

SRCL source_link;
YIM item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8673 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8674 "./marpa.w"

/*798:*/
#line 8821 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:798*/
#line 8675 "./marpa.w"

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
return NSYID_of_SRCL(source_link);
}

/*:787*//*789:*/
#line 8697 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_completion_link_trace(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8700 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8704 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8705 "./marpa.w"

/*798:*/
#line 8821 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:798*/
#line 8706 "./marpa.w"

switch((source_type= Source_Type_of_YIM(item)))
{
case SOURCE_IS_COMPLETION:
r->t_trace_source_type= SOURCE_IS_COMPLETION;
source_link= SRCL_of_YIM(item);
r->t_trace_source_link= source_link;
return Cause_AHFAID_of_SRCL(source_link);
case SOURCE_IS_AMBIGUOUS:
{
source_link= LV_First_Completion_SRCL_of_YIM(item);
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

/*:789*//*792:*/
#line 8737 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_completion_link_trace(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8740 "./marpa.w"

SRCL source_link;
YIM item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8743 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8744 "./marpa.w"

/*798:*/
#line 8821 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:798*/
#line 8745 "./marpa.w"

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

/*:792*//*794:*/
#line 8767 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_leo_link_trace(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8771 "./marpa.w"

SRCL source_link;
YIM item= r->t_trace_earley_item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8774 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8775 "./marpa.w"

/*798:*/
#line 8821 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:798*/
#line 8776 "./marpa.w"

source_link= First_Leo_SRCL_of_YIM(item);
if(source_link){
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_source_link= source_link;
return Cause_AHFAID_of_SRCL(source_link);
}
trace_source_link_clear(r);
return-1;
}

/*:794*//*797:*/
#line 8795 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_leo_link_trace(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8799 "./marpa.w"

SRCL source_link;
YIM item;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8802 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8803 "./marpa.w"

/*798:*/
#line 8821 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:798*/
#line 8804 "./marpa.w"

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

/*:797*//*799:*/
#line 8830 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:799*//*800:*/
#line 8845 "./marpa.w"

AHFAID _marpa_r_source_predecessor_state(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8848 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8851 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8852 "./marpa.w"

source_type= r->t_trace_source_type;
/*807:*/
#line 8996 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:807*/
#line 8854 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:{
YIM predecessor= Predecessor_of_SRCL(source_link);
if(!predecessor)return-1;
return AHFAID_of_YIM(predecessor);
}
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:800*//*801:*/
#line 8886 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_token(Marpa_Recognizer r,int*value_p)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8889 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8892 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8893 "./marpa.w"

source_type= r->t_trace_source_type;
/*807:*/
#line 8996 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:807*/
#line 8895 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK tkn= TOK_of_SRCL(source_link);
if(value_p)*value_p= Value_of_TOK(tkn);
return NSYID_of_TOK(tkn);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:801*//*803:*/
#line 8918 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_leo_transition_symbol(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8921 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8924 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8925 "./marpa.w"

source_type= r->t_trace_source_type;
/*807:*/
#line 8996 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:807*/
#line 8927 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_NSYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:803*//*806:*/
#line 8964 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_source_middle(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 8967 "./marpa.w"

const JEARLEME no_predecessor= -1;
unsigned int source_type;
SRCL source_link;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 8971 "./marpa.w"

/*1347:*/
#line 15954 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 15955 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 15956 "./marpa.w"


/*:1347*/
#line 8972 "./marpa.w"

source_type= r->t_trace_source_type;
/*807:*/
#line 8996 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:807*/
#line 8974 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
{
LIM predecessor= LIM_of_SRCL(source_link);
if(!predecessor)return no_predecessor;
return
YS_Ord_of_YIM(Base_YIM_of_LIM(predecessor));
}
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:
{
YIM predecessor= Predecessor_of_SRCL(source_link);
if(!predecessor)return no_predecessor;
return YS_Ord_of_YIM(predecessor);
}
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:806*//*822:*/
#line 9103 "./marpa.w"

PRIVATE int
alternative_insertion_point(RECCE r,ALT new_alternative)
{
MARPA_DSTACK alternatives= &r->t_alternatives;
ALT alternative;
int hi= MARPA_DSTACK_LENGTH(*alternatives)-1;
int lo= 0;
int trial;

if(hi<0)
return 0;
alternative= MARPA_DSTACK_BASE(*alternatives,ALT_Object);
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

/*:822*//*824:*/
#line 9147 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= NSYID_of_ALT(a)-NSYID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:824*//*825:*/
#line 9164 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,JEARLEME earleme)
{
MARPA_DSTACK alternatives= &r->t_alternatives;
ALT end_of_stack= MARPA_DSTACK_TOP(*alternatives,ALT_Object);
if(!end_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(end_of_stack))return NULL;
return MARPA_DSTACK_POP(*alternatives,ALT_Object);
}

/*:825*//*826:*/
#line 9179 "./marpa.w"

PRIVATE int alternative_insert(RECCE r,ALT new_alternative)
{
ALT end_of_stack,base_of_stack;
MARPA_DSTACK alternatives= &r->t_alternatives;
int ix;
int insertion_point= alternative_insertion_point(r,new_alternative);
if(insertion_point<0)
return insertion_point;
end_of_stack= MARPA_DSTACK_PUSH(*alternatives,ALT_Object);
base_of_stack= MARPA_DSTACK_BASE(*alternatives,ALT_Object);
for(ix= end_of_stack-base_of_stack;ix> insertion_point;ix--){
base_of_stack[ix]= base_of_stack[ix-1];
}
base_of_stack[insertion_point]= *new_alternative;
return insertion_point;
}

/*:826*//*827:*/
#line 9198 "./marpa.w"
int marpa_r_start_input(Marpa_Recognizer r)
{
int return_value= 1;
YS set0;
YIK_Object key;
AHFA state;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 9204 "./marpa.w"

/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 9205 "./marpa.w"

/*1344:*/
#line 15938 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1344*/
#line 9206 "./marpa.w"

{
/*828:*/
#line 9253 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
const NSYID xsy_count= XSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
/*:828*/
#line 9208 "./marpa.w"

Current_Earleme_of_R(r)= 0;
/*834:*/
#line 9295 "./marpa.w"

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

/*:834*/
#line 9210 "./marpa.w"

G_EVENTS_CLEAR(g);
if(G_is_Trivial(g)){
/*671:*/
#line 7336 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:671*/
#line 9213 "./marpa.w"

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
/*875:*/
#line 9988 "./marpa.w"

r->t_bv_lim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_bv_pim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_pim_workarea= marpa_obs_new(r->t_obs,void*,nsy_count);
/*:875*//*896:*/
#line 10255 "./marpa.w"

r->t_lim_chain= marpa_obs_new(r->t_obs,void*,2*nsy_count);
/*:896*/
#line 9228 "./marpa.w"

/*843:*/
#line 9506 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_yim_work_stack))
{
MARPA_DSTACK_INIT2(r->t_yim_work_stack,YIM);
}
}
/*:843*//*847:*/
#line 9521 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_completion_stack))
{
MARPA_DSTACK_INIT2(r->t_completion_stack,YIM);
}
}
/*:847*/
#line 9229 "./marpa.w"

set0= earley_set_new(r,0);
Latest_YS_of_R(r)= set0;
First_YS_of_R(r)= set0;
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
/*829:*/
#line 9257 "./marpa.w"

bv_free(bv_ok_for_chain);

/*:829*/
#line 9248 "./marpa.w"

}
return return_value;
}

/*:827*//*835:*/
#line 9335 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID tkn_xsy_id,
int value,
int length)
{
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 9342 "./marpa.w"

YS current_earley_set;
const JEARLEME current_earleme= Current_Earleme_of_R(r);
JEARLEME target_earleme;
NSYID tkn_nsyid;
if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT))
{
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT;
}
if(UNLIKELY(!xsy_id_is_valid(g,tkn_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return MARPA_ERR_INVALID_SYMBOL_ID;
}
/*836:*/
#line 9364 "./marpa.w"
{
const XSY_Const tkn= XSY_by_ID(tkn_xsy_id);
if(length<=0){
MARPA_ERROR(MARPA_ERR_TOKEN_LENGTH_LE_ZERO);
return MARPA_ERR_TOKEN_LENGTH_LE_ZERO;
}
if(length>=JEARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_TOKEN_TOO_LONG);
return MARPA_ERR_TOKEN_TOO_LONG;
}
if(value&&UNLIKELY(!lbv_bit_test(r->t_valued_terminal,tkn_xsy_id)))
{
if(!XSY_is_Terminal(tkn)){
MARPA_ERROR(MARPA_ERR_TOKEN_IS_NOT_TERMINAL);
return MARPA_ERR_TOKEN_IS_NOT_TERMINAL;
}
if(lbv_bit_test(r->t_valued_locked,tkn_xsy_id)){
MARPA_ERROR(MARPA_ERR_SYMBOL_VALUED_CONFLICT);
return MARPA_ERR_SYMBOL_VALUED_CONFLICT;
}
lbv_bit_set(r->t_valued_locked,tkn_xsy_id);
lbv_bit_set(r->t_valued_terminal,tkn_xsy_id);
lbv_bit_set(r->t_valued,tkn_xsy_id);
}
if(!value&&UNLIKELY(!lbv_bit_test(r->t_unvalued_terminal,tkn_xsy_id)))
{
if(!XSY_is_Terminal(tkn)){
MARPA_ERROR(MARPA_ERR_TOKEN_IS_NOT_TERMINAL);
return MARPA_ERR_TOKEN_IS_NOT_TERMINAL;
}
if(lbv_bit_test(r->t_valued_locked,tkn_xsy_id)){
MARPA_ERROR(MARPA_ERR_SYMBOL_VALUED_CONFLICT);
return MARPA_ERR_SYMBOL_VALUED_CONFLICT;
}
lbv_bit_set(r->t_valued_locked,tkn_xsy_id);
lbv_bit_set(r->t_unvalued_terminal,tkn_xsy_id);
lbv_bit_set(r->t_unvalued,tkn_xsy_id);
}
}

/*:836*/
#line 9357 "./marpa.w"

/*839:*/
#line 9424 "./marpa.w"

{
NSY tkn_nsy= NSY_by_XSYID(tkn_xsy_id);
if(UNLIKELY(!tkn_nsy))
{
MARPA_ERROR(MARPA_ERR_INACCESSIBLE_TOKEN);
return MARPA_ERR_INACCESSIBLE_TOKEN;
}
tkn_nsyid= ID_of_NSY(tkn_nsy);
current_earley_set= Current_YS_of_R(r);
if(!current_earley_set)
{
MARPA_ERROR(MARPA_ERR_NO_TOKEN_EXPECTED_HERE);
return MARPA_ERR_NO_TOKEN_EXPECTED_HERE;
}
if(!First_PIM_of_YS_by_NSYID(current_earley_set,tkn_nsyid))
{
MARPA_ERROR(MARPA_ERR_UNEXPECTED_TOKEN_ID);
return MARPA_ERR_UNEXPECTED_TOKEN_ID;
}
}

/*:839*/
#line 9358 "./marpa.w"

/*837:*/
#line 9404 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=JEARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return MARPA_ERR_PARSE_TOO_LONG;
}
}

/*:837*/
#line 9359 "./marpa.w"

/*840:*/
#line 9462 "./marpa.w"

{
TOK tkn;
ALT_Object alternative;
struct marpa_obstack*const tkn_obstack= TOK_Obs_of_I(input);
if(value)
{
marpa_obs_reserve(TOK_Obs_of_I(input),sizeof(*tkn));
tkn= marpa_obs_base(tkn_obstack);
NSYID_of_TOK(tkn)= tkn_nsyid;
Type_of_TOK(tkn)= VALUED_TOKEN_OR_NODE;
Value_of_TOK(tkn)= value;
}
else
{
marpa_obs_reserve(TOK_Obs_of_I(input),sizeof(tkn->t_unvalued));
tkn= marpa_obs_base(tkn_obstack);
NSYID_of_TOK(tkn)= tkn_nsyid;
Type_of_TOK(tkn)= UNVALUED_TOKEN_OR_NODE;
}
if(Furthest_Earleme_of_R(r)<target_earleme)
Furthest_Earleme_of_R(r)= target_earleme;
alternative.t_token= tkn;
alternative.t_start_earley_set= current_earley_set;
alternative.t_end_earleme= target_earleme;
if(alternative_insert(r,&alternative)<0)
{
marpa_obs_reject(tkn_obstack);
MARPA_ERROR(MARPA_ERR_DUPLICATE_TOKEN);
return MARPA_ERR_DUPLICATE_TOKEN;
}
tkn= marpa_obs_finish(tkn_obstack);
}

/*:840*/
#line 9360 "./marpa.w"

return MARPA_ERR_NONE;
}

/*:835*//*853:*/
#line 9551 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 9555 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 9556 "./marpa.w"

YIM*cause_p;
YS current_earley_set;
JEARLEME current_earleme;




JEARLEME return_value= -2;

/*1346:*/
#line 15948 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1346*/
#line 9566 "./marpa.w"

{
int count_of_expected_terminals;
/*854:*/
#line 9607 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
struct marpa_obstack*const earleme_complete_obs= marpa_obs_init;
/*:854*/
#line 9569 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_nsyid_is_expected);
/*856:*/
#line 9615 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*671:*/
#line 7336 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:671*/
#line 9619 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:856*/
#line 9573 "./marpa.w"

/*858:*/
#line 9637 "./marpa.w"
{
ALT end_of_stack= MARPA_DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!end_of_stack||current_earleme!=End_Earleme_of_ALT(end_of_stack))
{
return_value= 0;
goto CLEANUP;
}
}

/*:858*/
#line 9574 "./marpa.w"

/*857:*/
#line 9627 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_YS_of_YS(Latest_YS_of_R(r))= current_earley_set;
Latest_YS_of_R(r)= current_earley_set;
}

/*:857*/
#line 9575 "./marpa.w"

/*859:*/
#line 9646 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*860:*/
#line 9653 "./marpa.w"

{
YS start_earley_set= Start_YS_of_ALT(alternative);
TOK tkn= TOK_of_ALT(alternative);
NSYID tkn_nsyid= NSYID_of_TOK(tkn);
PIM pim= First_PIM_of_YS_by_NSYID(start_earley_set,tkn_nsyid);
for(;pim;pim= Next_PIM_of_PIM(pim)){
AHFA scanned_AHFA,prediction_AHFA;
YIM scanned_earley_item;
YIM predecessor= YIM_of_PIM(pim);
if(!predecessor)
continue;
scanned_AHFA= To_AHFA_of_YIM_by_NSYID(predecessor,tkn_nsyid);
scanned_earley_item= earley_item_assign(r,
current_earley_set,
Origin_of_YIM(predecessor),
scanned_AHFA);
tkn_link_add(r,scanned_earley_item,predecessor,tkn);
prediction_AHFA= Empty_Transition_of_AHFA(scanned_AHFA);
if(!prediction_AHFA)continue;
scanned_earley_item= earley_item_assign(r,
current_earley_set,
current_earley_set,
prediction_AHFA);
}
}

/*:860*/
#line 9650 "./marpa.w"

}

/*:859*/
#line 9576 "./marpa.w"

/*861:*/
#line 9680 "./marpa.w"
{
YIM*work_earley_items= MARPA_DSTACK_BASE(r->t_yim_work_stack,YIM);
int no_of_work_earley_items= MARPA_DSTACK_LENGTH(r->t_yim_work_stack);
int ix;
MARPA_DSTACK_CLEAR(r->t_completion_stack);
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
YIM earley_item= work_earley_items[ix];
YIM*end_of_stack;
if(!Earley_Item_is_Completion(earley_item))
continue;
end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= earley_item;
}
}

/*:861*/
#line 9577 "./marpa.w"

while((cause_p= MARPA_DSTACK_POP(r->t_completion_stack,YIM))){
YIM cause= *cause_p;
/*862:*/
#line 9699 "./marpa.w"

{
int count= Complete_NSY_Count_of_YIM(cause);
YS middle= Origin_of_YIM(cause);
int nsy_ix;
for(nsy_ix= 0;nsy_ix<count;nsy_ix++)
{
NSYID complete_nsyid= Complete_NSYID_of_YIM(cause,nsy_ix);
/*863:*/
#line 9711 "./marpa.w"

{
PIM postdot_item;
for(postdot_item= First_PIM_of_YS_by_NSYID(middle,complete_nsyid);
postdot_item;postdot_item= Next_PIM_of_PIM(postdot_item))
{
YIM predecessor= YIM_of_PIM(postdot_item);
YIM effect;
AHFA effect_AHFA_state;
if(predecessor)
{
/*864:*/
#line 9734 "./marpa.w"

{
YS origin= Origin_of_YIM(predecessor);
effect_AHFA_state= To_AHFA_of_YIM_by_NSYID(predecessor,complete_nsyid);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*865:*/
#line 9750 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}



/*:865*/
#line 9743 "./marpa.w"

}
/*866:*/
#line 9757 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:866*/
#line 9745 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:864*/
#line 9722 "./marpa.w"

}
else
{
/*867:*/
#line 9767 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
YS origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*865:*/
#line 9750 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}



/*:865*/
#line 9776 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:867*/
#line 9726 "./marpa.w"

break;


}
}
}

/*:863*/
#line 9707 "./marpa.w"

}
}

/*:862*/
#line 9580 "./marpa.w"

}
postdot_items_create(r,bv_ok_for_chain,current_earley_set);




count_of_expected_terminals= bv_count(r->t_bv_nsyid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_YS(current_earley_set)>=Furthest_Earleme_of_R(r))
{
/*671:*/
#line 7336 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:671*/
#line 9591 "./marpa.w"

}
earley_set_update_items(r,current_earley_set);
if(r->t_active_event_count> 0){
trigger_events(r);
}
return_value= G_EVENT_COUNT(g);
CLEANUP:;
/*855:*/
#line 9611 "./marpa.w"

bv_free(bv_ok_for_chain);
marpa_obs_free(earleme_complete_obs);

/*:855*/
#line 9599 "./marpa.w"

}
return return_value;
}

/*:853*//*868:*/
#line 9781 "./marpa.w"

PRIVATE void trigger_events(RECCE r)
{
const GRAMMAR g= G_of_R(r);
const YS current_earley_set= Latest_YS_of_R(r);
unsigned int min,max,start;
int yim_ix;
struct marpa_obstack*const trigger_events_obs= marpa_obs_init;
const YIM*yims= YIMs_of_YS(current_earley_set);
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
const int working_earley_item_count= YIM_Count_of_YS(current_earley_set);
for(yim_ix= 0;yim_ix<working_earley_item_count;yim_ix++)
{
const YIM yim= yims[yim_ix];
const AHFA root_ahfa= AHFA_of_YIM(yim);
const AHFAID root_ahfaid= ID_of_AHFA(root_ahfa);
if(AHFA_has_Event(root_ahfa))
{

bv_bit_set(bv_ahfa_event_trigger,root_ahfaid);
}
{

const SRCL first_leo_source_link= First_Leo_SRCL_of_YIM(yim);
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
const NSYID leo_path_ahfaid= 
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
for(event_ahfaid= (NSYID)min;event_ahfaid<=(NSYID)max;
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
for(event_xsyid= (NSYID)min;event_xsyid<=(NSYID)max;
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
for(event_xsyid= (NSYID)min;event_xsyid<=(NSYID)max;
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
for(event_xsyid= (NSYID)min;event_xsyid<=(NSYID)max;
event_xsyid++)
{
if(lbv_bit_test
(r->t_lbv_xsyid_prediction_event_is_active,event_xsyid))
{
int_event_new(g,MARPA_EVENT_SYMBOL_PREDICTED,event_xsyid);
}
}
}
marpa_obs_free(trigger_events_obs);
}

/*:868*//*869:*/
#line 9921 "./marpa.w"

PRIVATE void earley_set_update_items(RECCE r,YS set)
{
YIM*working_earley_items;
YIM*finished_earley_items;
int working_earley_item_count;
int i;
YIMs_of_YS(set)= marpa_obs_new(r->t_obs,YIM,YIM_Count_of_YS(set));
finished_earley_items= YIMs_of_YS(set);
working_earley_items= Work_YIMs_of_R(r);
working_earley_item_count= Work_YIM_Count_of_R(r);
for(i= 0;i<working_earley_item_count;i++){
YIM earley_item= working_earley_items[i];
int ordinal= Ord_of_YIM(earley_item);
finished_earley_items[ordinal]= earley_item;
}
WORK_YIMS_CLEAR(r);
}

/*:869*//*870:*/
#line 9942 "./marpa.w"

PRIVATE void r_update_earley_sets(RECCE r)
{
YS set;
YS first_unstacked_earley_set;
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_earley_set_stack)){
first_unstacked_earley_set= First_YS_of_R(r);
MARPA_DSTACK_INIT(r->t_earley_set_stack,YS,
MAX(1024,YS_Count_of_R(r)));
}else{
YS*end_of_stack= MARPA_DSTACK_TOP(r->t_earley_set_stack,YS);
first_unstacked_earley_set= Next_YS_of_YS(*end_of_stack);
}
for(set= first_unstacked_earley_set;set;set= Next_YS_of_YS(set)){
YS*end_of_stack= MARPA_DSTACK_PUSH(r->t_earley_set_stack,YS);
(*end_of_stack)= set;
}
}

/*:870*//*877:*/
#line 9995 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,
Bit_Vector bv_ok_for_chain,
YS current_earley_set)
{
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 10001 "./marpa.w"

JEARLEME current_earley_set_id= Earleme_of_YS(current_earley_set);
/*876:*/
#line 9992 "./marpa.w"

bv_clear(r->t_bv_lim_symbols);
bv_clear(r->t_bv_pim_symbols);
/*:876*/
#line 10003 "./marpa.w"

/*878:*/
#line 10015 "./marpa.w"
{
YIM*work_earley_items= MARPA_DSTACK_BASE(r->t_yim_work_stack,YIM);
int no_of_work_earley_items= MARPA_DSTACK_LENGTH(r->t_yim_work_stack);
int ix;
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
YIM earley_item= work_earley_items[ix];
AHFA state= AHFA_of_YIM(earley_item);
int nsy_ix;
NSYID postdot_nsy_count= Postdot_NSY_Count_of_AHFA(state);
NSYID*postdot_nsyidary= 
Postdot_NSYIDAry_of_AHFA(state);
for(nsy_ix= 0;nsy_ix<postdot_nsy_count;nsy_ix++)
{
PIM old_pim= NULL;
PIM new_pim;
NSYID nsyid;
new_pim= marpa_obs_alloc(r->t_obs,sizeof(YIX_Object));
nsyid= postdot_nsyidary[nsy_ix];
Postdot_NSYID_of_PIM(new_pim)= nsyid;
YIM_of_PIM(new_pim)= earley_item;
if(bv_bit_test(r->t_bv_pim_symbols,(unsigned int)nsyid))
old_pim= r->t_pim_workarea[nsyid];
Next_PIM_of_PIM(new_pim)= old_pim;
if(!old_pim)current_earley_set->t_postdot_sym_count++;
r->t_pim_workarea[nsyid]= new_pim;
bv_bit_set(r->t_bv_pim_symbols,(unsigned int)nsyid);
}
}
}

/*:878*/
#line 10004 "./marpa.w"

if(r->t_is_using_leo){
/*881:*/
#line 10060 "./marpa.w"

{
unsigned int min,max,start;
for(start= 0;bv_scan(r->t_bv_pim_symbols,start,&min,&max);
start= max+2)
{
NSYID nsyid;
for(nsyid= (NSYID)min;nsyid<=(NSYID)max;nsyid++)
{
PIM this_pim= r->t_pim_workarea[nsyid];
if(!Next_PIM_of_PIM(this_pim))
{

YIM leo_base= YIM_of_PIM(this_pim);
if(YIM_is_Potential_Leo_Base(leo_base))
{
AHFA base_to_ahfa= 
To_AHFA_of_YIM_by_NSYID(leo_base,nsyid);
if(AHFA_is_Leo_Completion(base_to_ahfa))
{
/*882:*/
#line 10094 "./marpa.w"
{
LIM new_lim;
new_lim= marpa_obs_alloc(r->t_obs,sizeof(*new_lim));
Postdot_NSYID_of_LIM(new_lim)= nsyid;
YIM_of_PIM(new_lim)= NULL;
Predecessor_LIM_of_LIM(new_lim)= NULL;
Origin_of_LIM(new_lim)= NULL;
CIL_of_LIM(new_lim)= NULL;
Top_AHFA_of_LIM(new_lim)= base_to_ahfa;
Base_YIM_of_LIM(new_lim)= leo_base;
YS_of_LIM(new_lim)= current_earley_set;
Next_PIM_of_LIM(new_lim)= this_pim;
r->t_pim_workarea[nsyid]= new_lim;
bv_bit_set(r->t_bv_lim_symbols,(unsigned int)nsyid);
}

/*:882*/
#line 10080 "./marpa.w"

}
}
}
}
}
}

/*:881*/
#line 10006 "./marpa.w"

/*891:*/
#line 10179 "./marpa.w"
{
unsigned int min,max,start;

bv_copy(bv_ok_for_chain,r->t_bv_lim_symbols);
for(start= 0;bv_scan(r->t_bv_lim_symbols,start,&min,&max);
start= max+2)
{

NSYID main_loop_nsyid;
for(main_loop_nsyid= (NSYID)min;
main_loop_nsyid<=(NSYID)max;
main_loop_nsyid++)
{
LIM predecessor_lim;
LIM lim_to_process= r->t_pim_workarea[main_loop_nsyid];
if(LIM_is_Populated(lim_to_process))continue;

/*894:*/
#line 10237 "./marpa.w"
{
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
Leo_LHS_NSYID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Earleme_of_YS(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_YS_by_NSYID(predecessor_set,predecessor_transition_nsyid);
}else{
predecessor_pim= r->t_pim_workarea[predecessor_transition_nsyid];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:894*/
#line 10196 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*902:*/
#line 10344 "./marpa.w"

{
const AHFA root_ahfa= Top_AHFA_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);
CIL_of_LIM(lim_to_process)= predecessor_cil;


Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHFA(root_ahfa)> Count_of_CIL(predecessor_cil))
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
Top_AHFA_of_LIM(lim_to_process)= root_ahfa;
}

/*:902*/
#line 10198 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*904:*/
#line 10387 "./marpa.w"
{
const AHFA root_AHFA= Top_AHFA_of_LIM(lim_to_process);
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHFAIDs_of_AHFA(root_AHFA);
}

/*:904*/
#line 10204 "./marpa.w"

continue;
}
/*897:*/
#line 10257 "./marpa.w"
{
int lim_chain_ix;
/*900:*/
#line 10277 "./marpa.w"

{
NSYID postdot_nsyid_of_lim_to_process
= Postdot_NSYID_of_LIM(lim_to_process);
lim_chain_ix= 0;
r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);
bv_bit_clear(bv_ok_for_chain,
(unsigned int)postdot_nsyid_of_lim_to_process);


while(1)
{
lim_to_process= predecessor_lim;





postdot_nsyid_of_lim_to_process= Postdot_NSYID_of_LIM(lim_to_process);
if(!bv_bit_test
(bv_ok_for_chain,(unsigned int)postdot_nsyid_of_lim_to_process))
{





break;
}

/*894:*/
#line 10237 "./marpa.w"
{
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
Leo_LHS_NSYID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Earleme_of_YS(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_YS_by_NSYID(predecessor_set,predecessor_transition_nsyid);
}else{
predecessor_pim= r->t_pim_workarea[predecessor_transition_nsyid];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:894*/
#line 10307 "./marpa.w"


r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,
(unsigned int)postdot_nsyid_of_lim_to_process);


if(!predecessor_lim)
break;

if(LIM_is_Populated(predecessor_lim))
break;



}
}

/*:900*/
#line 10259 "./marpa.w"

/*901:*/
#line 10327 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= r->t_lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*902:*/
#line 10344 "./marpa.w"

{
const AHFA root_ahfa= Top_AHFA_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);
CIL_of_LIM(lim_to_process)= predecessor_cil;


Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHFA(root_ahfa)> Count_of_CIL(predecessor_cil))
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
Top_AHFA_of_LIM(lim_to_process)= root_ahfa;
}

/*:902*/
#line 10331 "./marpa.w"

}else{
/*904:*/
#line 10387 "./marpa.w"
{
const AHFA root_AHFA= Top_AHFA_of_LIM(lim_to_process);
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHFAIDs_of_AHFA(root_AHFA);
}

/*:904*/
#line 10333 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:901*/
#line 10260 "./marpa.w"

}

/*:897*/
#line 10207 "./marpa.w"

}
}
}

/*:891*/
#line 10007 "./marpa.w"

}
/*905:*/
#line 10394 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= marpa_obs_alloc(r->t_obs,
current_earley_set->t_postdot_sym_count*sizeof(PIM));
unsigned int min,max,start;
int postdot_array_ix= 0;
for(start= 0;bv_scan(r->t_bv_pim_symbols,start,&min,&max);start= max+2){
NSYID nsyid;
for(nsyid= (NSYID)min;nsyid<=(NSYID)max;nsyid++){
PIM this_pim= r->t_pim_workarea[nsyid];
if(lbv_bit_test(r->t_nsy_expected_is_event,nsyid)){
XSY xsy= Source_XSY_of_NSYID(nsyid);
int_event_new(g,MARPA_EVENT_SYMBOL_EXPECTED,ID_of_XSY(xsy));
}
if(this_pim)postdot_array[postdot_array_ix++]= this_pim;
}
}
}

/*:905*/
#line 10009 "./marpa.w"

bv_and(r->t_bv_nsyid_is_expected,r->t_bv_pim_symbols,g->t_bv_nsyid_is_terminal);
}

/*:877*//*923:*/
#line 10566 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
stack->t_obs= marpa_obs_init;
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:923*//*924:*/
#line 10574 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:924*//*925:*/
#line 10580 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)marpa_obs_free(stack->t_obs);
stack->t_base= NULL;
}

/*:925*//*926:*/
#line 10587 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= marpa_obs_alloc(stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:926*//*927:*/
#line 10597 "./marpa.w"

PRIVATE void
ur_node_push(URS stack,YIM earley_item,AEX aex)
{
UR old_top= stack->t_top;
UR new_top= Next_UR_of_UR(old_top);
YIM_of_UR(old_top)= earley_item;
AEX_of_UR(old_top)= aex;
if(!new_top)
{
new_top= ur_node_new(stack,old_top);
Next_UR_of_UR(old_top)= new_top;
}
stack->t_top= new_top;
}

/*:927*//*928:*/
#line 10613 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:928*//*932:*/
#line 10676 "./marpa.w"

PRIVATE int psia_test_and_set(
struct marpa_obstack*obs,
struct s_bocage_setup_per_ys*per_ys_data,
YIM earley_item,
AEX ahfa_element_ix)
{
const int aim_count_of_item= AIM_Count_of_YIM(earley_item);
const Marpa_Earley_Set_ID set_ordinal= YS_Ord_of_YIM(earley_item);
OR**nodes_by_item= per_ys_data[set_ordinal].t_aexes_by_item;
const int item_ordinal= Ord_of_YIM(earley_item);
OR*nodes_by_aex= nodes_by_item[item_ordinal];
MARPA_ASSERT(ahfa_element_ix<aim_count_of_item)
if(!nodes_by_aex){
AEX aex;
nodes_by_aex= nodes_by_item[item_ordinal]= 
marpa_obs_alloc(obs,aim_count_of_item*sizeof(OR));
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

/*:932*//*968:*/
#line 11245 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,YIM*p_base)
{
const NSYID postdot_nsyid= Postdot_NSYID_of_LIM(leo_item);
const YIM base= Base_YIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_YIM_by_NSYID(base,postdot_nsyid);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:968*//*969:*/
#line 11257 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
YIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_YIM_by_AEX(base,base_aex);
}

/*:969*//*975:*/
#line 11361 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11366 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 11367 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11368 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11369 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11370 "./marpa.w"

return YS_Ord_of_OR(or_node);
}

/*:975*//*976:*/
#line 11374 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11379 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 11380 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11381 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11382 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11383 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:976*//*977:*/
#line 11387 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11392 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 11393 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11394 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11395 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11396 "./marpa.w"

return ID_of_IRL(IRL_of_OR(or_node));
}

/*:977*//*978:*/
#line 11400 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11405 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 11406 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11407 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11408 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11409 "./marpa.w"

return Position_of_OR(or_node);
}

/*:978*//*979:*/
#line 11413 "./marpa.w"

int _marpa_b_or_node_is_whole(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11418 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 11419 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11420 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11421 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11422 "./marpa.w"

return Position_of_OR(or_node)>=Length_of_IRL(IRL_of_OR(or_node))?1:0;
}

/*:979*//*980:*/
#line 11426 "./marpa.w"

int _marpa_b_or_node_is_semantic(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11431 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 11432 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11433 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11434 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11435 "./marpa.w"

return!IRL_has_Virtual_LHS(IRL_of_OR(or_node));
}

/*:980*//*981:*/
#line 11439 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11444 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 11445 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11446 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11447 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11448 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:981*//*982:*/
#line 11452 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11457 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 11458 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11459 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11460 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11461 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:982*//*983:*/
#line 11466 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11471 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 11472 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11473 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11474 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11475 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:983*//*986:*/
#line 11489 "./marpa.w"

int _marpa_o_or_node_and_node_count(Marpa_Order o,
Marpa_Or_Node_ID or_node_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11493 "./marpa.w"

/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 11494 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11495 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11496 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[0];
}
{
OR or_node;
/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11505 "./marpa.w"

return AND_Count_of_OR(or_node);
}
}

/*:986*//*987:*/
#line 11510 "./marpa.w"

int _marpa_o_or_node_and_node_id_by_ix(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 11514 "./marpa.w"

/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 11515 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 11516 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 11517 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[1+ix];
}
{
OR or_node;
/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 11526 "./marpa.w"

return First_ANDID_of_OR(or_node)+ix;
}
}

/*:987*//*991:*/
#line 11574 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct marpa_obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= marpa_obs_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:991*//*993:*/
#line 11597 "./marpa.w"

PRIVATE
void draft_and_node_add(struct marpa_obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:993*//*1020:*/
#line 12017 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12020 "./marpa.w"

/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12021 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12022 "./marpa.w"

return AND_Count_of_B(b);
}

/*:1020*//*1022:*/
#line 12048 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12053 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12054 "./marpa.w"

/*1021:*/
#line 12026 "./marpa.w"

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

/*:1021*/
#line 12055 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1022*//*1023:*/
#line 12059 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12064 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12065 "./marpa.w"

/*1021:*/
#line 12026 "./marpa.w"

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

/*:1021*/
#line 12066 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1023*//*1024:*/
#line 12075 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12080 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12081 "./marpa.w"

/*1021:*/
#line 12026 "./marpa.w"

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

/*:1021*/
#line 12082 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1024*//*1025:*/
#line 12091 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12096 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12097 "./marpa.w"

/*1021:*/
#line 12026 "./marpa.w"

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

/*:1021*/
#line 12098 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const XSYID symbol_id= 
OR_is_Token(cause_or)?NSYID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1025*//*1026:*/
#line 12107 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK tkn;
AND and_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12113 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12114 "./marpa.w"

/*1021:*/
#line 12026 "./marpa.w"

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

/*:1021*/
#line 12115 "./marpa.w"

tkn= and_node_token(and_node);
if(tkn){
if(value_p)
*value_p= Value_of_TOK(tkn);
return NSYID_of_TOK(tkn);
}
return-1;
}
/*:1026*//*1027:*/
#line 12124 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:1027*//*1028:*/
#line 12142 "./marpa.w"

Marpa_Earley_Set_ID _marpa_b_and_node_middle(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12147 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12148 "./marpa.w"

/*1021:*/
#line 12026 "./marpa.w"

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

/*:1021*/
#line 12149 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
if(predecessor_or)
{
return YS_Ord_of_OR(predecessor_or);
}
}
return Origin_Ord_of_OR(OR_of_AND(and_node));
}

/*:1028*//*1037:*/
#line 12195 "./marpa.w"

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

/*:1037*//*1038:*/
#line 12212 "./marpa.w"

int marpa_r_progress_report_start(
Marpa_Recognizer r,
Marpa_Earley_Set_ID set_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12217 "./marpa.w"

YS earley_set;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 12219 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12220 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 12221 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
/*1032:*/
#line 12169 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:1032*/
#line 12234 "./marpa.w"

{
const MARPA_AVL_TREE report_tree= 
_marpa_avl_create(report_item_cmp,NULL,alignof(PROGRESS));
const YIM*const earley_items= YIMs_of_YS(earley_set);
const int earley_item_count= YIM_Count_of_YS(earley_set);
int earley_item_id;
for(earley_item_id= 0;earley_item_id<earley_item_count;
earley_item_id++)
{
/*1040:*/
#line 12264 "./marpa.w"

{
const int initial_phase= 1;
const int leo_source_link_phase= 2;
const int leo_path_item_phase= 3;
int next_phase= initial_phase;
SRCL leo_source_link= NULL;
LIM next_leo_item= NULL;
const YIM earley_item= earley_items[earley_item_id];
while(1)
{
YSID report_origin;
AHFA report_AHFA_state;
while(1)
{
const int phase= next_phase;
if(phase==initial_phase)
{
report_origin= Origin_Ord_of_YIM(earley_item);
report_AHFA_state= AHFA_of_YIM(earley_item);
next_phase= leo_source_link_phase;
goto INSERT_ITEMS_INTO_TREE;
}
if(phase==leo_source_link_phase)
{
leo_source_link= leo_source_link?
Next_SRCL_of_SRCL(leo_source_link):
First_Leo_SRCL_of_YIM(earley_item);
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
const YIM base_earley_item= Base_YIM_of_LIM(leo_item);
const NSYID postdot_nsyid= Postdot_NSYID_of_LIM(leo_item);
report_origin= Ord_of_YS(YS_of_LIM(leo_item));
report_AHFA_state= 
To_AHFA_of_YIM_by_NSYID(base_earley_item,postdot_nsyid);
next_leo_item= Predecessor_LIM_of_LIM(leo_item);
goto INSERT_ITEMS_INTO_TREE;
}
}
NEXT_PHASE:;
}
INSERT_ITEMS_INTO_TREE:
/*1041:*/
#line 12328 "./marpa.w"

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
marpa_obs_new(MARPA_AVL_OBSTACK(report_tree),struct marpa_progress_item,
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

/*:1041*/
#line 12323 "./marpa.w"

}
NEXT_EARLEY_ITEM:;
}

/*:1040*/
#line 12244 "./marpa.w"

}
r->t_progress_report_traverser= _marpa_avl_t_init(report_tree);
return marpa_avl_count(report_tree);
}
}
/*:1038*//*1039:*/
#line 12251 "./marpa.w"

int marpa_r_progress_report_reset(Marpa_Recognizer r)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12254 "./marpa.w"

MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 12256 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12257 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 12258 "./marpa.w"

/*1044:*/
#line 12409 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:1044*/
#line 12259 "./marpa.w"

_marpa_avl_t_reset(traverser);
return 1;
}

/*:1039*//*1042:*/
#line 12372 "./marpa.w"

int marpa_r_progress_report_finish(Marpa_Recognizer r){
const int success= 1;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12375 "./marpa.w"

/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 12376 "./marpa.w"

const MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*1044:*/
#line 12409 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:1044*/
#line 12378 "./marpa.w"

/*1032:*/
#line 12169 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:1032*/
#line 12379 "./marpa.w"

return success;
}

/*:1042*//*1043:*/
#line 12383 "./marpa.w"

Marpa_Rule_ID marpa_r_progress_item(
Marpa_Recognizer r,int*position,Marpa_Earley_Set_ID*origin
){
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12387 "./marpa.w"

PROGRESS report_item;
MARPA_AVL_TRAV traverser;
/*623:*/
#line 6897 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:623*/
#line 12390 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12391 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 12392 "./marpa.w"

traverser= r->t_progress_report_traverser;
if(UNLIKELY(!position||!origin)){
MARPA_ERROR(MARPA_ERR_POINTER_ARG_NULL);
return failure_indicator;
}
/*1044:*/
#line 12409 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:1044*/
#line 12398 "./marpa.w"

report_item= _marpa_avl_t_next(traverser);
if(!report_item){
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_EXHAUSTED);
return-1;
}
*position= Position_of_PROGRESS(report_item);
*origin= Origin_of_PROGRESS(report_item);
return RULEID_of_PROGRESS(report_item);
}

/*:1043*//*1054:*/
#line 12453 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1330:*/
#line 15859 "./marpa.w"
void*const failure_indicator= NULL;
/*:1330*/
#line 12457 "./marpa.w"

/*1057:*/
#line 12515 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int nsy_count= NSY_Count_of_G(g);
const int xsy_count= XSY_Count_of_G(g);
const IRLID irl_count= IRL_Count_of_G(g);
BOCAGE b= NULL;
YS end_of_parse_earley_set;
JEARLEME end_of_parse_earleme;
YIM start_yim= NULL;
AIM start_aim= NULL;
AEX start_aex= -1;
struct marpa_obstack*bocage_setup_obs= NULL;
int count_of_earley_items_in_parse;
int or_node_estimate= 0;
const int earley_set_count_of_r= YS_Count_of_R(r);

/*:1057*//*1060:*/
#line 12539 "./marpa.w"

struct s_bocage_setup_per_ys*per_ys_data= NULL;

/*:1060*/
#line 12458 "./marpa.w"

INPUT input;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12460 "./marpa.w"

/*1345:*/
#line 15943 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1345*/
#line 12461 "./marpa.w"

{
struct marpa_obstack*const obstack= marpa_obs_init;
b= marpa_obs_new(obstack,struct marpa_bocage,1);
OBS_of_B(b)= obstack;
}
/*955:*/
#line 11019 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:955*//*1056:*/
#line 12510 "./marpa.w"

Valued_BV_of_B(b)= lbv_clone(b->t_obs,r->t_valued,xsy_count);
Valued_Locked_BV_of_B(b)= 
lbv_clone(b->t_obs,r->t_valued_locked,xsy_count);

/*:1056*//*1071:*/
#line 12674 "./marpa.w"

Ambiguity_Metric_of_B(b)= 1;

/*:1071*//*1075:*/
#line 12688 "./marpa.w"

b->t_ref_count= 1;
/*:1075*//*1082:*/
#line 12748 "./marpa.w"

B_is_Nulling(b)= 0;
/*:1082*/
#line 12467 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*1061:*/
#line 12542 "./marpa.w"

{
if(ordinal_arg==-1)
{
end_of_parse_earley_set= Current_YS_of_R(r);
}
else
{
if(!YS_Ord_is_Valid(r,ordinal_arg))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
end_of_parse_earley_set= YS_of_R_by_Ord(r,ordinal_arg);
}

if(!end_of_parse_earley_set)
goto NO_PARSE;
end_of_parse_earleme= Earleme_of_YS(end_of_parse_earley_set);
}

/*:1061*/
#line 12477 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(XSY_by_ID(g->t_start_xsy_id)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*1065:*/
#line 12616 "./marpa.w"

{
int yim_ix;
YIM*const earley_items= YIMs_of_YS(end_of_parse_earley_set);
const IRL start_irl= g->t_start_irl;
const IRLID sought_irl_id= ID_of_IRL(start_irl);
const int earley_item_count= YIM_Count_of_YS(end_of_parse_earley_set);
for(yim_ix= 0;yim_ix<earley_item_count;yim_ix++){
const YIM earley_item= earley_items[yim_ix];
const AHFA ahfa_state= AHFA_of_YIM(earley_item);
if(Origin_Earleme_of_YIM(earley_item)> 0)continue;
if(!AHFA_is_Predicted(ahfa_state)){
int aex;
AIM*const ahfa_items= AIMs_of_AHFA(ahfa_state);
const int ahfa_item_count= AIM_Count_of_AHFA(ahfa_state);
for(aex= 0;aex<ahfa_item_count;aex++){
const AIM ahfa_item= ahfa_items[aex];
if(IRLID_of_AIM(ahfa_item)==sought_irl_id){
start_aim= ahfa_item;
start_yim= earley_item;
start_aex= aex;
break;
}
}
}
if(start_yim)break;
}
}

/*:1065*/
#line 12485 "./marpa.w"

if(!start_yim)goto NO_PARSE;
bocage_setup_obs= marpa_obs_init;
/*1062:*/
#line 12564 "./marpa.w"

{
unsigned int ix;
unsigned int earley_set_count= YS_Count_of_R(r);
count_of_earley_items_in_parse= 0;
per_ys_data= 
marpa_obs_alloc(bocage_setup_obs,
sizeof(struct s_bocage_setup_per_ys)*earley_set_count);
for(ix= 0;ix<earley_set_count;ix++)
{
const YS_Const earley_set= YS_of_R_by_Ord(r,ix);
const unsigned int item_count= YIM_Count_of_YS(earley_set);
count_of_earley_items_in_parse+= item_count;
{
struct s_bocage_setup_per_ys*per_ys= per_ys_data+ix;
OR**const per_yim_yixes= per_ys->t_aexes_by_item= 
marpa_obs_alloc(bocage_setup_obs,sizeof(OR*)*item_count);
unsigned int item_ordinal;
per_ys->t_or_psl= NULL;
per_ys->t_and_psl= NULL;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
per_yim_yixes[item_ordinal]= NULL;
}
}
}
}

/*:1062*/
#line 12488 "./marpa.w"

/*930:*/
#line 10635 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const YIM ur_earley_item= start_yim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*931:*/
#line 10663 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:931*/
#line 10644 "./marpa.w"

}
while((ur_node= ur_node_pop(ur_node_stack)))
{
const YIM_Const parent_earley_item= YIM_of_UR(ur_node);
const AEX parent_aex= AEX_of_UR(ur_node);
const AIM parent_aim= AIM_of_YIM_by_AEX(parent_earley_item,parent_aex);
MARPA_ASSERT(parent_aim>=AIM_by_ID(1))
const AIM predecessor_aim= parent_aim-1;


unsigned int source_type= Source_Type_of_YIM(parent_earley_item);
MARPA_ASSERT(!YIM_is_Predicted(parent_earley_item))
/*933:*/
#line 10704 "./marpa.w"

{
SRCL source_link= NULL;
YIM predecessor_earley_item= NULL;
switch(source_type)
{
case SOURCE_IS_TOKEN:
predecessor_earley_item= Predecessor_of_YIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= LV_First_Token_SRCL_of_YIM(parent_earley_item);
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
if(YIM_is_Predicted(predecessor_earley_item)){
Set_boolean_in_PSIA_for_initial_nulls(predecessor_earley_item,predecessor_aim);
}else{
const YIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_YIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
/*931:*/
#line 10663 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:931*/
#line 10732 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:933*/
#line 10657 "./marpa.w"

/*935:*/
#line 10762 "./marpa.w"

{
SRCL source_link= NULL;
YIM predecessor_earley_item= NULL;
YIM cause_earley_item= NULL;
const NSYID transition_symbol_nsyid= Postdot_NSYID_of_AIM(predecessor_aim);
switch(source_type)
{
case SOURCE_IS_COMPLETION:
predecessor_earley_item= Predecessor_of_YIM(parent_earley_item);
cause_earley_item= Cause_of_YIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= LV_First_Completion_SRCL_of_YIM(parent_earley_item);
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
if(YIM_is_Predicted(predecessor_earley_item))
{
Set_boolean_in_PSIA_for_initial_nulls(predecessor_earley_item,predecessor_aim);
}
else
{
const YIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_YIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
/*931:*/
#line 10663 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:931*/
#line 10798 "./marpa.w"

}
}
{
const TRANS cause_completion_data= 
TRANS_of_YIM_by_NSYID(cause_earley_item,transition_symbol_nsyid);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
const YIM ur_earley_item= cause_earley_item;
int ix;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_YIM_by_AEX(ur_earley_item,ur_aex);
/*931:*/
#line 10663 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:931*/
#line 10811 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:935*/
#line 10658 "./marpa.w"

/*936:*/
#line 10821 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
const YIM cause_earley_item= Cause_of_SRCL(source_link);
LIM leo_predecessor= LIM_of_SRCL(source_link);
const NSYID transition_nsyid= Postdot_NSYID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_YIM_by_NSYID(cause_earley_item,transition_nsyid);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
int ix;
YIM ur_earley_item= cause_earley_item;
for(ix= 0;ix<aex_count;ix++)
{
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_YIM_by_AEX(ur_earley_item,ur_aex);
/*931:*/
#line 10663 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:931*/
#line 10840 "./marpa.w"

}
while(leo_predecessor)
{
NSYID postdot_nsyid= Postdot_NSYID_of_LIM(leo_predecessor);
YIM leo_base= Base_YIM_of_LIM(leo_predecessor);
TRANS transition= TRANS_of_YIM_by_NSYID(leo_base,postdot_nsyid);
const AEX ur_aex= Leo_Base_AEX_of_TRANS(transition);
const AIM ur_aim= AIM_of_YIM_by_AEX(leo_base,ur_aex);
ur_earley_item= leo_base;


or_node_estimate+= 1+Null_Count_of_AIM(ur_aim+1);
if(YIM_is_Predicted(ur_earley_item))
{
Set_boolean_in_PSIA_for_initial_nulls(ur_earley_item,ur_aim);
}
else
{
/*931:*/
#line 10663 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:931*/
#line 10859 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
}
}

/*:936*/
#line 10659 "./marpa.w"

}
}

/*:930*/
#line 12489 "./marpa.w"

/*957:*/
#line 11037 "./marpa.w"

{
PSAR_Object or_per_ys_arena;
const PSAR or_psar= &or_per_ys_arena;
int work_earley_set_ordinal;
OR last_or_node= NULL;
ORs_of_B(b)= marpa_new(OR,or_node_estimate);
psar_init(or_psar,SYMI_Count_of_G(g));
for(work_earley_set_ordinal= 0;
work_earley_set_ordinal<earley_set_count_of_r;
work_earley_set_ordinal++)
{
const YS_Const earley_set= YS_of_R_by_Ord(r,work_earley_set_ordinal);
YIM*const yims_of_ys= YIMs_of_YS(earley_set);
const int item_count= YIM_Count_of_YS(earley_set);
PSL this_earley_set_psl;
OR**const nodes_by_item= per_ys_data[work_earley_set_ordinal].t_aexes_by_item;
psar_dealloc(or_psar);
#define PSL_YS_ORD work_earley_set_ordinal
#define CLAIMED_PSL this_earley_set_psl
/*1321:*/
#line 15773 "./marpa.w"

{
PSL*psl_owner= &per_ys_data[PSL_YS_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_YS_ORD
#undef CLAIMED_PSL

/*:1321*/
#line 11057 "./marpa.w"

/*958:*/
#line 11065 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const work_nodes_by_aex= nodes_by_item[item_ordinal];
if(work_nodes_by_aex){
const YIM work_earley_item= yims_of_ys[item_ordinal];
const int work_ahfa_item_count= AIM_Count_of_YIM(work_earley_item);
AEX work_aex;
const int work_origin_ordinal= Ord_of_YS(Origin_of_YIM(work_earley_item));
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
if(!work_nodes_by_aex[work_aex])continue;
/*959:*/
#line 11085 "./marpa.w"

{
AIM ahfa_item= AIM_of_YIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_YS_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1321:*/
#line 15773 "./marpa.w"

{
PSL*psl_owner= &per_ys_data[PSL_YS_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_YS_ORD
#undef CLAIMED_PSL

/*:1321*/
#line 11095 "./marpa.w"

/*961:*/
#line 11113 "./marpa.w"

{
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const IRL irl= IRL_of_AIM(ahfa_item);
/*962:*/
#line 11142 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)marpa_obs_alloc(OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
marpa_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:962*/
#line 11123 "./marpa.w"

or_node= last_or_node;
PSL_Datum(or_psl,ahfa_item_symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= Origin_Ord_of_YIM(work_earley_item);
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= irl;
Position_of_OR(or_node)= 
ahfa_item_symbol_instance-SYMI_of_IRL(irl)+1;
DANDs_of_OR(or_node)= NULL;
}
psia_or_node= or_node;
}
}

/*:961*/
#line 11096 "./marpa.w"

/*964:*/
#line 11168 "./marpa.w"

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
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal){
DAND draft_and_node;
const int rhs_ix= symbol_instance-symbol_instance_of_rule;
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= Nulling_OR_by_NSYID(RHSID_of_IRL(irl,rhs_ix));
/*962:*/
#line 11142 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)marpa_obs_alloc(OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
marpa_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:962*/
#line 11187 "./marpa.w"

or_node= PSL_Datum(or_psl,symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= work_origin_ordinal;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
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

/*:964*/
#line 11097 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*965:*/
#line 11205 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*967:*/
#line 11227 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_YS(YS_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const IRL path_irl= IRL_of_AIM(path_ahfa_item);
const int symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*970:*/
#line 11268 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_YS_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1321:*/
#line 15773 "./marpa.w"

{
PSL*psl_owner= &per_ys_data[PSL_YS_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_YS_ORD
#undef CLAIMED_PSL

/*:1321*/
#line 11275 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*962:*/
#line 11142 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)marpa_obs_alloc(OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
marpa_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:962*/
#line 11279 "./marpa.w"

PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= 
symbol_instance_of_path_ahfa_item-SYMI_of_IRL(path_irl)+1;
DANDs_of_OR(or_node)= NULL;
}
}
}

/*:970*/
#line 11237 "./marpa.w"

/*971:*/
#line 11295 "./marpa.w"

{
int i;
const int null_count= Null_Count_of_AIM(path_ahfa_item);
for(i= 1;i<=null_count;i++)
{
const int symbol_instance= symbol_instance_of_path_ahfa_item+i;
OR or_node= PSL_Datum(this_earley_set_psl,symbol_instance);
MARPA_ASSERT(symbol_instance<SYMI_Count_of_G(g))
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
DAND draft_and_node;
const int rhs_ix= symbol_instance-SYMI_of_IRL(path_irl);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= Nulling_OR_by_NSYID(RHSID_of_IRL(path_irl,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_IRL(path_irl))
MARPA_ASSERT(symbol_instance>=0)
/*962:*/
#line 11142 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)marpa_obs_alloc(OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
marpa_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:962*/
#line 11312 "./marpa.w"

PSL_Datum(this_earley_set_psl,symbol_instance)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
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

/*:971*/
#line 11238 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:967*/
#line 11213 "./marpa.w"

}
}
}

/*:965*/
#line 11105 "./marpa.w"

}

/*:959*/
#line 11079 "./marpa.w"

}
}
}
}

/*:958*/
#line 11058 "./marpa.w"

/*994:*/
#line 11607 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const nodes_by_aex= nodes_by_item[item_ordinal];
if(nodes_by_aex){
const YIM work_earley_item= yims_of_ys[item_ordinal];
const int work_ahfa_item_count= AIM_Count_of_YIM(work_earley_item);
const int work_origin_ordinal= Ord_of_YS(Origin_of_YIM(work_earley_item));
AEX work_aex;
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
OR or_node= nodes_by_aex[work_aex];
Move_OR_to_Proper_OR(or_node);
if(or_node){
/*996:*/
#line 11644 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_YIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_YIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const int work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*997:*/
#line 11660 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM cause_earley_item= Cause_of_SRCL(source_link);
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*998:*/
#line 11675 "./marpa.w"

{

IRL path_irl= NULL;

IRL previous_path_irl;
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
OR dand_predecessor;
OR path_or_node;
YIM base_earley_item;
AEX base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_YIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*999:*/
#line 11702 "./marpa.w"

{
if(higher_path_leo_item){
/*1003:*/
#line 11746 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AIM aim= AIM_of_YIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:1003*/
#line 11705 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:999*/
#line 11688 "./marpa.w"

/*1001:*/
#line 11716 "./marpa.w"

{
const NSYID transition_nsyid= Postdot_NSYID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_YIM_by_NSYID(cause_earley_item,transition_nsyid);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
int ix;
for(ix= 0;ix<aex_count;ix++)
{
const AEX cause_aex= aexes[ix];
OR dand_cause;
Set_OR_from_YIM_and_AEX(dand_cause,cause_earley_item,cause_aex);
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:1001*/
#line 11689 "./marpa.w"

previous_path_irl= path_irl;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_YIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*999:*/
#line 11702 "./marpa.w"

{
if(higher_path_leo_item){
/*1003:*/
#line 11746 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AIM aim= AIM_of_YIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:1003*/
#line 11705 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:999*/
#line 11696 "./marpa.w"

/*1004:*/
#line 11756 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_IRL(previous_path_irl);
const int origin_ordinal= Ord_of_YS(YS_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:1004*/
#line 11697 "./marpa.w"

previous_path_irl= path_irl;
}
}

/*:998*/
#line 11669 "./marpa.w"

}
}
}

/*:997*/
#line 11655 "./marpa.w"

/*1005:*/
#line 11766 "./marpa.w"

{
SRCL source_link= NULL;
YIM predecessor_earley_item= NULL;
TOK tkn= NULL;
switch(work_source_type)
{
case SOURCE_IS_TOKEN:
predecessor_earley_item= Predecessor_of_YIM(work_earley_item);
tkn= TOK_of_YIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= LV_First_Token_SRCL_of_YIM(work_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
tkn= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
while(tkn)
{
/*1006:*/
#line 11796 "./marpa.w"

{
OR dand_predecessor;
/*1007:*/
#line 11804 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_YIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_YIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1007*/
#line 11799 "./marpa.w"

draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)tkn);
}

/*:1006*/
#line 11788 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
tkn= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1005*/
#line 11656 "./marpa.w"

/*1008:*/
#line 11815 "./marpa.w"

{
SRCL source_link= NULL;
YIM predecessor_earley_item= NULL;
YIM cause_earley_item= NULL;
const NSYID transition_symbol_nsyid= Postdot_NSYID_of_AIM(work_predecessor_aim);
switch(work_source_type)
{
case SOURCE_IS_COMPLETION:
predecessor_earley_item= Predecessor_of_YIM(work_earley_item);
cause_earley_item= Cause_of_YIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= LV_First_Completion_SRCL_of_YIM(work_earley_item);
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
TRANS_of_YIM_by_NSYID(cause_earley_item,transition_symbol_nsyid);
const int aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
int ix;
for(ix= 0;ix<aex_count;ix++){
const AEX cause_aex= aexes[ix];
/*1009:*/
#line 11855 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_YIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_YIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_IRL(IRL_of_AIM(cause_ahfa_item));
/*1007:*/
#line 11804 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_YIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_YIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1007*/
#line 11863 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:1009*/
#line 11846 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1008*/
#line 11657 "./marpa.w"

}

/*:996*/
#line 11622 "./marpa.w"

}
}
}
}
}

/*:994*/
#line 11059 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= marpa_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:957*/
#line 12490 "./marpa.w"

/*1017:*/
#line 11970 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*1010:*/
#line 11869 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_ys_arena;
const PSAR and_psar= &and_per_ys_arena;
int or_node_id= 0;
psar_init(and_psar,irl_count+nsy_count);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*1012:*/
#line 11901 "./marpa.w"

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
predecessor?YS_Ord_of_OR(predecessor):origin_ordinal;
PSL and_psl;
PSL*psl_owner= &per_ys_data[middle_ordinal].t_and_psl;

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

/*:1012*/
#line 11879 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:1010*/
#line 11973 "./marpa.w"

/*1018:*/
#line 11977 "./marpa.w"

{
const int or_count_of_b= OR_Count_of_B(b);
int or_node_id;
int and_node_id= 0;
const OR*ors_of_b= ORs_of_B(b);
const AND ands_of_b= ANDs_of_B(b)= 
marpa_new(AND_Object,unique_draft_and_node_count);
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

/*:1018*/
#line 11974 "./marpa.w"

}

/*:1017*/
#line 12491 "./marpa.w"

/*1066:*/
#line 12645 "./marpa.w"

{
const YSID end_of_parse_ordinal= Ord_of_YS(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_ys_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_YIM(start_yim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR root_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(root_or_node);
}

/*:1066*/
#line 12492 "./marpa.w"
;
marpa_obs_free(bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
input_unref(input);
if(b){
/*1078:*/
#line 12724 "./marpa.w"

/*956:*/
#line 11026 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
marpa_free(or_nodes);
ORs_of_B(b)= NULL;
marpa_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:956*/
#line 12725 "./marpa.w"
;
/*1053:*/
#line 12449 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:1053*/
#line 12726 "./marpa.w"
;

/*:1078*/
#line 12499 "./marpa.w"
;
}
return NULL;
}

/*:1054*//*1068:*/
#line 12658 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12661 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12662 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12663 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:1068*//*1072:*/
#line 12677 "./marpa.w"

int marpa_b_ambiguity_metric(Marpa_Bocage b)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12680 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12681 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12682 "./marpa.w"

return Ambiguity_Metric_of_B(b);
}

/*:1072*//*1076:*/
#line 12691 "./marpa.w"

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

/*:1076*//*1077:*/
#line 12709 "./marpa.w"

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

/*:1077*//*1079:*/
#line 12731 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12735 "./marpa.w"

input_unref(input);
if(b)
{
/*1078:*/
#line 12724 "./marpa.w"

/*956:*/
#line 11026 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
marpa_free(or_nodes);
ORs_of_B(b)= NULL;
marpa_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:956*/
#line 12725 "./marpa.w"
;
/*1053:*/
#line 12449 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:1053*/
#line 12726 "./marpa.w"
;

/*:1078*/
#line 12739 "./marpa.w"
;
}
}

/*:1079*//*1083:*/
#line 12750 "./marpa.w"

int marpa_b_is_null(Marpa_Bocage b)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12753 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12754 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12755 "./marpa.w"

return B_is_Nulling(b);
}

/*:1083*//*1090:*/
#line 12795 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1330:*/
#line 15859 "./marpa.w"
void*const failure_indicator= NULL;
/*:1330*/
#line 12798 "./marpa.w"

/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12799 "./marpa.w"

ORDER o;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12801 "./marpa.w"

o= marpa_malloc(sizeof(*o));
B_of_O(o)= b;
bocage_ref(b);
/*1087:*/
#line 12783 "./marpa.w"

{
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
OBS_of_O(o)= NULL;
}

/*:1087*//*1093:*/
#line 12813 "./marpa.w"

o->t_ref_count= 1;

/*:1093*//*1105:*/
#line 12901 "./marpa.w"

High_Rank_Count_of_O(o)= 1;
/*:1105*/
#line 12805 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
Ambiguity_Metric_of_O(o)= Ambiguity_Metric_of_B(b);
return o;
}

/*:1090*//*1094:*/
#line 12817 "./marpa.w"

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

/*:1094*//*1095:*/
#line 12835 "./marpa.w"

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

/*:1095*//*1096:*/
#line 12849 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 12852 "./marpa.w"

bocage_unref(b);
marpa_obs_free(OBS_of_O(o));
marpa_free(o);
}

/*:1096*//*1100:*/
#line 12870 "./marpa.w"

int marpa_o_ambiguity_metric(Marpa_Order o)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12873 "./marpa.w"

/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 12874 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12875 "./marpa.w"

return Ambiguity_Metric_of_O(o);
}

/*:1100*//*1103:*/
#line 12884 "./marpa.w"

int marpa_o_is_null(Marpa_Order o)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12887 "./marpa.w"

/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 12888 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12889 "./marpa.w"

return O_is_Nulling(o);
}

/*:1103*//*1106:*/
#line 12903 "./marpa.w"

int marpa_o_high_rank_only_set(
Marpa_Order o,
int count)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12908 "./marpa.w"

/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 12909 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12910 "./marpa.w"

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

/*:1106*//*1107:*/
#line 12925 "./marpa.w"

int marpa_o_high_rank_only(Marpa_Order o)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12928 "./marpa.w"

/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 12929 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12930 "./marpa.w"

return High_Rank_Count_of_O(o);
}

/*:1107*//*1111:*/
#line 12967 "./marpa.w"

int marpa_o_rank(Marpa_Order o)
{
ANDID**and_node_orderings;
struct marpa_obstack*obs;
int bocage_was_reordered= 0;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 12973 "./marpa.w"

/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 12974 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 12975 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*1117:*/
#line 13140 "./marpa.w"

{
int and_id;
const int and_count_of_r= AND_Count_of_B(b);
obs= OBS_of_O(o)= marpa_obs_init;
o->t_and_node_orderings= 
and_node_orderings= 
marpa_obs_alloc(obs,sizeof(ANDID*)*and_count_of_r);
for(and_id= 0;and_id<and_count_of_r;and_id++)
{
and_node_orderings[and_id]= (ANDID*)NULL;
}
}

/*:1117*/
#line 12981 "./marpa.w"

if(High_Rank_Count_of_O(o)){
/*1112:*/
#line 12996 "./marpa.w"

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
/*1113:*/
#line 13014 "./marpa.w"

{
if(and_count_of_or> 1)
{
int high_rank_so_far= INT_MIN;
const ANDID first_and_node_id= First_ANDID_of_OR(work_or_node);
const ANDID last_and_node_id= 
(first_and_node_id+and_count_of_or)-1;
ANDID*const order_base= 
(marpa_obs_reserve(obs,sizeof(ANDID)*(and_count_of_or+1)),
marpa_obs_base(obs));
ANDID*order= order_base+1;
ANDID and_node_id;
bocage_was_reordered= 1;
for(and_node_id= first_and_node_id;and_node_id<=last_and_node_id;
and_node_id++)
{
const AND and_node= and_nodes+and_node_id;
int and_node_rank;
/*1114:*/
#line 13052 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1114*/
#line 13033 "./marpa.w"

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
marpa_obs_confirm_fast(obs,sizeof(ANDID)*(final_count+1));
and_node_orderings[or_node_id]= marpa_obs_finish(obs);
}
}
}

/*:1113*/
#line 13008 "./marpa.w"

or_node_id++;
}
Ambiguity_Metric_of_O(o)= ambiguity_metric;
}

/*:1112*/
#line 12983 "./marpa.w"

}else{
/*1115:*/
#line 13063 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
OR*const or_nodes= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
const int and_node_count_of_b= AND_Count_of_B(b);
int or_node_id= 0;
int*rank_by_and_id= marpa_new(int,and_node_count_of_b);
int and_node_id;
for(and_node_id= 0;and_node_id<and_node_count_of_b;and_node_id++)
{
const AND and_node= and_nodes+and_node_id;
int and_node_rank;
/*1114:*/
#line 13052 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1114*/
#line 13076 "./marpa.w"

rank_by_and_id[and_node_id]= and_node_rank;
}
while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= or_nodes[or_node_id];
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1116:*/
#line 13109 "./marpa.w"

{
if(and_count_of_or> 1)
{
const ANDID first_and_node_id= First_ANDID_of_OR(work_or_node);
ANDID*const order_base= 
marpa_obs_alloc(obs,sizeof(ANDID)*(and_count_of_or+1));
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

/*:1116*/
#line 13083 "./marpa.w"

or_node_id++;
}
marpa_free(rank_by_and_id);
}

/*:1115*/
#line 12985 "./marpa.w"

}
if(!bocage_was_reordered){
marpa_obs_free(obs);
OBS_of_O(o)= NULL;
o->t_and_node_orderings= NULL;
}
O_is_Frozen(o)= 1;
return 1;
}

/*:1111*//*1118:*/
#line 13157 "./marpa.w"

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

/*:1118*//*1119:*/
#line 13178 "./marpa.w"

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

/*:1119*//*1120:*/
#line 13192 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13197 "./marpa.w"

/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13198 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13199 "./marpa.w"

/*973:*/
#line 11338 "./marpa.w"

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
/*:973*/
#line 13200 "./marpa.w"

/*974:*/
#line 11350 "./marpa.w"

{
OR*const or_nodes= ORs_of_B(b);
if(UNLIKELY(!or_nodes))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= or_nodes[or_node_id];
}

/*:974*/
#line 13201 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
if(!and_order_ix_is_valid(o,or_node,ix))return-1;
return and_order_get(o,or_node,ix);
}

/*:1120*//*1125:*/
#line 13254 "./marpa.w"

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

/*:1125*//*1126:*/
#line 13272 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1330:*/
#line 15859 "./marpa.w"
void*const failure_indicator= NULL;
/*:1330*/
#line 13275 "./marpa.w"

TREE t;
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13277 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13278 "./marpa.w"

t= marpa_malloc(sizeof(*t));
O_of_T(t)= o;
order_ref(o);
O_is_Frozen(o)= 1;
/*1143:*/
#line 13463 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1143*/
#line 13283 "./marpa.w"

/*1127:*/
#line 13288 "./marpa.w"

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

/*:1127*//*1130:*/
#line 13312 "./marpa.w"

t->t_ref_count= 1;

/*:1130*//*1137:*/
#line 13391 "./marpa.w"
t->t_pause_counter= 0;
/*:1137*/
#line 13284 "./marpa.w"

return t;
}

/*:1126*//*1131:*/
#line 13316 "./marpa.w"

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

/*:1131*//*1132:*/
#line 13334 "./marpa.w"

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

/*:1132*//*1133:*/
#line 13348 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
marpa_free(t);
}

/*:1133*//*1138:*/
#line 13392 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1138*//*1139:*/
#line 13401 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1139*//*1140:*/
#line 13411 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13414 "./marpa.w"

const int termination_indicator= -1;
int is_first_tree_attempt= (t->t_parse_count<1);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13417 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13418 "./marpa.w"

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
/*1149:*/
#line 13492 "./marpa.w"

{
ORID root_or_id= Top_ORID_of_B(b);
OR root_or_node= OR_of_B_by_ID(b,root_or_id);
NOOK nook;



const int choice= 0;
if(!and_order_ix_is_valid(o,root_or_node,choice))
goto TREE_IS_EXHAUSTED;
nook= FSTACK_PUSH(t->t_nook_stack);
tree_or_node_try(t,root_or_id);
OR_of_NOOK(nook)= root_or_node;
Choice_of_NOOK(nook)= choice;
Parent_of_NOOK(nook)= -1;
NOOK_Cause_is_Expanded(nook)= 0;
NOOK_is_Cause(nook)= 0;
NOOK_Predecessor_is_Expanded(nook)= 0;
NOOK_is_Predecessor(nook)= 0;
}

/*:1149*/
#line 13443 "./marpa.w"

}else{
/*1150:*/
#line 13517 "./marpa.w"
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

/*:1150*/
#line 13445 "./marpa.w"

}
/*1151:*/
#line 13559 "./marpa.w"
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
/*1152:*/
#line 13622 "./marpa.w"

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

/*:1152*/
#line 13616 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1151*/
#line 13447 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return termination_indicator;

}

/*:1140*//*1147:*/
#line 13479 "./marpa.w"

PRIVATE int tree_or_node_try(TREE tree,ORID or_node_id)
{
return!bv_bit_test_then_set(tree->t_or_node_in_use,(unsigned int)or_node_id);
}
/*:1147*//*1148:*/
#line 13485 "./marpa.w"

PRIVATE void tree_or_node_release(TREE tree,ORID or_node_id)
{
bv_bit_clear(tree->t_or_node_in_use,(unsigned int)or_node_id);
}

/*:1148*//*1153:*/
#line 13641 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1153*//*1154:*/
#line 13649 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13652 "./marpa.w"

/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13653 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13654 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return failure_indicator;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1154*//*1161:*/
#line 13715 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13719 "./marpa.w"

/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13720 "./marpa.w"

/*1160:*/
#line 13697 "./marpa.w"
{
NOOK base_nook;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13699 "./marpa.w"

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

/*:1160*/
#line 13721 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1161*//*1162:*/
#line 13725 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13729 "./marpa.w"

/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13730 "./marpa.w"

/*1160:*/
#line 13697 "./marpa.w"
{
NOOK base_nook;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13699 "./marpa.w"

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

/*:1160*/
#line 13731 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1162*//*1163:*/
#line 13735 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13739 "./marpa.w"

/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13740 "./marpa.w"

/*1160:*/
#line 13697 "./marpa.w"
{
NOOK base_nook;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13699 "./marpa.w"

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

/*:1160*/
#line 13741 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1163*//*1164:*/
#line 13745 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13749 "./marpa.w"

/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13750 "./marpa.w"

/*1160:*/
#line 13697 "./marpa.w"
{
NOOK base_nook;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13699 "./marpa.w"

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

/*:1160*/
#line 13751 "./marpa.w"

return NOOK_Cause_is_Expanded(nook);
}

/*:1164*//*1165:*/
#line 13755 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13759 "./marpa.w"

/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13760 "./marpa.w"

/*1160:*/
#line 13697 "./marpa.w"
{
NOOK base_nook;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13699 "./marpa.w"

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

/*:1160*/
#line 13761 "./marpa.w"

return NOOK_Predecessor_is_Expanded(nook);
}

/*:1165*//*1166:*/
#line 13765 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13769 "./marpa.w"

/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13770 "./marpa.w"

/*1160:*/
#line 13697 "./marpa.w"
{
NOOK base_nook;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13699 "./marpa.w"

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

/*:1160*/
#line 13771 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1166*//*1167:*/
#line 13775 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 13779 "./marpa.w"

/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13780 "./marpa.w"

/*1160:*/
#line 13697 "./marpa.w"
{
NOOK base_nook;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13699 "./marpa.w"

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

/*:1160*/
#line 13781 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1167*//*1184:*/
#line 13959 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1330:*/
#line 15859 "./marpa.w"
void*const failure_indicator= NULL;
/*:1330*/
#line 13962 "./marpa.w"

/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 13963 "./marpa.w"
;
/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 13964 "./marpa.w"

if(t->t_parse_count<=0){
MARPA_ERROR(MARPA_ERR_BEFORE_FIRST_TREE);
return NULL;
}
if(!T_is_Exhausted(t))
{
const XSYID xsy_count= XSY_Count_of_G(g);
struct marpa_obstack*const obstack= marpa_obs_init;
const VALUE v= marpa_obs_new(obstack,struct s_value,1);
v->t_obs= obstack;
Step_Type_of_V(v)= Next_Value_Type_of_V(v)= MARPA_STEP_INITIAL;
/*1175:*/
#line 13885 "./marpa.w"

XSYID_of_V(v)= -1;
RULEID_of_V(v)= -1;
Token_Value_of_V(v)= -1;
Token_Type_of_V(v)= DUMMY_OR_NODE;
Arg_0_of_V(v)= -1;
Arg_N_of_V(v)= -1;
Result_of_V(v)= -1;
Rule_Start_of_V(v)= -1;
Token_Start_of_V(v)= -1;
YS_ID_of_V(v)= -1;

/*:1175*//*1182:*/
#line 13948 "./marpa.w"

MARPA_DSTACK_SAFE(VStack_of_V(v));
/*:1182*//*1187:*/
#line 13996 "./marpa.w"

v->t_ref_count= 1;

/*:1187*//*1194:*/
#line 14049 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1194*//*1196:*/
#line 14056 "./marpa.w"

V_is_Trace(v)= 0;
/*:1196*//*1199:*/
#line 14077 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1199*//*1204:*/
#line 14104 "./marpa.w"

{
XSY_is_Valued_BV_of_V(v)= lbv_clone(v->t_obs,Valued_BV_of_B(b),xsy_count);
Valued_Locked_BV_of_V(v)= 
lbv_clone(v->t_obs,Valued_Locked_BV_of_B(b),xsy_count);
}

/*:1204*/
#line 13976 "./marpa.w"

tree_pause(t);
T_of_V(v)= t;
if(T_is_Nulling(o)){
V_is_Nulling(v)= 1;
}else{
const int minimum_stack_size= (8192/sizeof(int));
const int initial_stack_size= 
MAX(Size_of_TREE(t)/1024,minimum_stack_size);
MARPA_DSTACK_INIT(VStack_of_V(v),int,initial_stack_size);
}
return(Marpa_Value)v;
}
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return NULL;
}

/*:1184*//*1188:*/
#line 14000 "./marpa.w"

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

/*:1188*//*1189:*/
#line 14018 "./marpa.w"

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

/*:1189*//*1190:*/
#line 14032 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
/*1183:*/
#line 13950 "./marpa.w"

{
if(LIKELY(MARPA_DSTACK_IS_INITIALIZED(VStack_of_V(v))!=NULL))
{
MARPA_DSTACK_DESTROY(VStack_of_V(v));
}
}

/*:1183*/
#line 14036 "./marpa.w"

/*1177:*/
#line 13901 "./marpa.w"

marpa_obs_free(v->t_obs);

/*:1177*/
#line 14037 "./marpa.w"

}

/*:1190*//*1197:*/
#line 14058 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 14061 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1191:*/
#line 14040 "./marpa.w"

TREE t= T_of_V(v);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 14042 "./marpa.w"


/*:1191*/
#line 14063 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 14064 "./marpa.w"

if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1197*//*1200:*/
#line 14080 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 14083 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1191:*/
#line 14040 "./marpa.w"

TREE t= T_of_V(v);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 14042 "./marpa.w"


/*:1191*/
#line 14085 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 14086 "./marpa.w"

if(UNLIKELY(V_is_Nulling(v)))return-1;
if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1200*//*1205:*/
#line 14112 "./marpa.w"

int marpa_v_symbol_is_valued(
Marpa_Value public_v,
Marpa_Symbol_ID xsy_id)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 14117 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1191:*/
#line 14040 "./marpa.w"

TREE t= T_of_V(v);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 14042 "./marpa.w"


/*:1191*/
#line 14119 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 14120 "./marpa.w"

/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 14121 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 14122 "./marpa.w"

return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
}

/*:1205*//*1206:*/
#line 14128 "./marpa.w"

PRIVATE int symbol_is_valued_set(
VALUE v,XSYID xsy_id,int value)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 14132 "./marpa.w"

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

/*:1206*//*1207:*/
#line 14151 "./marpa.w"

int marpa_v_symbol_is_valued_set(
Marpa_Value public_v,Marpa_Symbol_ID xsy_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 14156 "./marpa.w"

/*1191:*/
#line 14040 "./marpa.w"

TREE t= T_of_V(v);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 14042 "./marpa.w"


/*:1191*/
#line 14157 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 14158 "./marpa.w"

if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1334:*/
#line 15878 "./marpa.w"

if(UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1334*/
#line 14164 "./marpa.w"

/*1335:*/
#line 15885 "./marpa.w"

if(UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1335*/
#line 14165 "./marpa.w"

return symbol_is_valued_set(v,xsy_id,value);
}

/*:1207*//*1208:*/
#line 14171 "./marpa.w"

int
marpa_v_valued_force(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 14176 "./marpa.w"

XSYID xsy_count;
XSYID xsy_id;
/*1191:*/
#line 14040 "./marpa.w"

TREE t= T_of_V(v);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 14042 "./marpa.w"


/*:1191*/
#line 14179 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 14180 "./marpa.w"

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

/*:1208*//*1209:*/
#line 14195 "./marpa.w"

int marpa_v_rule_is_valued_set(
Marpa_Value public_v,Marpa_Rule_ID xrl_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 14200 "./marpa.w"

/*1191:*/
#line 14040 "./marpa.w"

TREE t= T_of_V(v);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 14042 "./marpa.w"


/*:1191*/
#line 14201 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 14202 "./marpa.w"

if(UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1341:*/
#line 15919 "./marpa.w"

if(UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1341*/
#line 14208 "./marpa.w"

/*1339:*/
#line 15908 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1339*/
#line 14209 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsy_id= LHS_ID_of_XRL(xrl);
return symbol_is_valued_set(v,xsy_id,value);
}
}

/*:1209*//*1211:*/
#line 14224 "./marpa.w"

Marpa_Step_Type marpa_v_step(Marpa_Value public_v)
{
/*1331:*/
#line 15862 "./marpa.w"
const int failure_indicator= -2;

/*:1331*/
#line 14227 "./marpa.w"

const VALUE v= (VALUE)public_v;

if(V_is_Nulling(v)){
/*1191:*/
#line 14040 "./marpa.w"

TREE t= T_of_V(v);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 14042 "./marpa.w"


/*:1191*/
#line 14231 "./marpa.w"

/*1213:*/
#line 14312 "./marpa.w"

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

/*:1213*/
#line 14232 "./marpa.w"

return Step_Type_of_V(v)= MARPA_STEP_INACTIVE;
}

while(V_is_Active(v)){
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case MARPA_STEP_INITIAL:
{
XSYID xsy_count;
/*1191:*/
#line 14040 "./marpa.w"

TREE t= T_of_V(v);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 14042 "./marpa.w"


/*:1191*/
#line 14243 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
lbv_fill(Valued_Locked_BV_of_V(v),xsy_count);
/*1212:*/
#line 14296 "./marpa.w"

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

/*:1212*/
#line 14246 "./marpa.w"

}

case STEP_GET_DATA:
/*1214:*/
#line 14335 "./marpa.w"

{
AND and_nodes;





int pop_arguments= 1;
/*1191:*/
#line 14040 "./marpa.w"

TREE t= T_of_V(v);
/*1124:*/
#line 13250 "./marpa.w"

ORDER o= O_of_T(t);
/*1097:*/
#line 12858 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1051:*/
#line 12440 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1051*/
#line 12860 "./marpa.w"


/*:1097*/
#line 13252 "./marpa.w"
;

/*:1124*/
#line 14042 "./marpa.w"


/*:1191*/
#line 14344 "./marpa.w"

/*1348:*/
#line 15958 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1348*/
#line 14345 "./marpa.w"

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
TOK tkn;
int tkn_type;
const NOOK nook= NOOK_of_TREE_by_IX(t,NOOK_of_V(v));
const int choice= Choice_of_NOOK(nook);
or= OR_of_NOOK(nook);
YS_ID_of_V(v)= YS_Ord_of_OR(or);
and_node_id= and_order_get(o,or,choice);
and_node= and_nodes+and_node_id;
tkn= and_node_token(and_node);
tkn_type= tkn?Type_of_TOK(tkn):DUMMY_OR_NODE;
Token_Type_of_V(v)= tkn_type;
if(tkn_type!=DUMMY_OR_NODE)
{
const NSYID tkn_nsyid= NSYID_of_TOK(tkn);
Arg_0_of_V(v)= ++Arg_N_of_V(v);
if(tkn_type==VALUED_TOKEN_OR_NODE)
{
const OR predecessor= Predecessor_OR_of_AND(and_node);
XSYID_of_V(v)= ID_of_XSY(Source_XSY_of_NSYID(tkn_nsyid));
Token_Start_of_V(v)= 
predecessor?YS_Ord_of_OR(predecessor):Origin_Ord_of_OR(or);
Token_Value_of_V(v)= Value_of_TOK(tkn);
}
else if(tkn_type==NULLING_TOKEN_OR_NODE)
{
const XSY source_xsy= Source_XSY_of_NSYID(tkn_nsyid);
const XSYID source_xsy_id= ID_of_XSY(source_xsy);
if(bv_bit_test(XSY_is_Valued_BV_of_V(v),source_xsy_id))
{
XSYID_of_V(v)= source_xsy_id;
Token_Start_of_V(v)= YS_ID_of_V(v);
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
const MARPA_DSTACK virtual_stack= &VStack_of_V(v);
if(virtual_lhs){
real_symbol_count= Real_SYM_Count_of_IRL(nook_irl);
if(virtual_rhs){
*(MARPA_DSTACK_TOP(*virtual_stack,int))+= real_symbol_count;
}else{
*MARPA_DSTACK_PUSH(*virtual_stack,int)= real_symbol_count;
}
}else{

if(virtual_rhs){
real_symbol_count= Real_SYM_Count_of_IRL(nook_irl);
real_symbol_count+= *MARPA_DSTACK_POP(*virtual_stack,int);
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

/*:1214*/
#line 14250 "./marpa.w"

if(!V_is_Active(v))break;

case MARPA_STEP_TOKEN:
{
int tkn_type= Token_Type_of_V(v);
Next_Value_Type_of_V(v)= MARPA_STEP_RULE;
if(tkn_type==NULLING_TOKEN_OR_NODE)
{
if(lbv_bit_test(XSY_is_Valued_BV_of_V(v),XSYID_of_V(v))){
Result_of_V(v)= Arg_N_of_V(v);
return Step_Type_of_V(v)= MARPA_STEP_NULLING_SYMBOL;
}
}
else if(tkn_type!=DUMMY_OR_NODE)
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

/*:1211*//*1216:*/
#line 14478 "./marpa.w"

PRIVATE int lbv_bits_to_size(int bits)
{
return(bits+(lbv_wordbits-1))/lbv_wordbits;
}

/*:1216*//*1217:*/
#line 14485 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new(struct marpa_obstack*obs,int bits)
{
int size= lbv_bits_to_size(bits);
LBV lbv= marpa_obs_new(obs,LBW,size);
return lbv;
}

/*:1217*//*1218:*/
#line 14495 "./marpa.w"

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

/*:1218*//*1219:*/
#line 14508 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new0(struct marpa_obstack*obs,int bits)
{
LBV lbv= lbv_obs_new(obs,bits);
return lbv_zero(lbv,bits);
}

/*:1219*//*1221:*/
#line 14527 "./marpa.w"

PRIVATE LBV lbv_clone(
struct marpa_obstack*obs,LBV old_lbv,int bits)
{
int size= lbv_bits_to_size(bits);
const LBV new_lbv= marpa_obs_new(obs,LBW,size);
if(size> 0){
LBW*from_addr= old_lbv;
LBW*to_addr= new_lbv;
while(size--)*to_addr++= *from_addr++;
}
return new_lbv;
}

/*:1221*//*1222:*/
#line 14543 "./marpa.w"

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

/*:1222*//*1225:*/
#line 14579 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(unsigned int bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1225*//*1226:*/
#line 14585 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(unsigned int bits)
{
unsigned int mask= bits&bv_modmask;
if(mask)mask= (unsigned int)~(~0uL<<mask);else mask= (unsigned int)~0uL;
return(mask);
}

/*:1226*//*1228:*/
#line 14599 "./marpa.w"

PRIVATE Bit_Vector bv_create(unsigned int bits)
{
unsigned int size= bv_bits_to_size(bits);
unsigned int bytes= (size+bv_hiddenwords)*sizeof(Bit_Vector_Word);
unsigned int*addr= (Bit_Vector)marpa_malloc0((size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}

/*:1228*//*1230:*/
#line 14617 "./marpa.w"

PRIVATE Bit_Vector
bv_obs_create(struct marpa_obstack*obs,unsigned int bits)
{
unsigned int size= bv_bits_to_size(bits);
unsigned int bytes= (size+bv_hiddenwords)*sizeof(Bit_Vector_Word);
unsigned int*addr= (Bit_Vector)marpa_obs_alloc(obs,(size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
if(size> 0){
Bit_Vector bv= addr;
while(size--)*bv++= 0u;
}
return addr;
}


/*:1230*//*1231:*/
#line 14638 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct marpa_obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,BV_BITS(bv));
}

/*:1231*//*1232:*/
#line 14652 "./marpa.w"

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

/*:1232*//*1233:*/
#line 14670 "./marpa.w"

PRIVATE
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}

PRIVATE
Bit_Vector bv_obs_clone(struct marpa_obstack*obs,Bit_Vector bv)
{
return bv_copy(bv_obs_shadow(obs,bv),bv);
}

/*:1233*//*1234:*/
#line 14684 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
marpa_free(vector);
}
}

/*:1234*//*1235:*/
#line 14695 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1235*//*1236:*/
#line 14706 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1236*//*1238:*/
#line 14720 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,unsigned int bit)
{
unsigned int length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1238*//*1240:*/
#line 14728 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1240*//*1241:*/
#line 14735 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1241*//*1242:*/
#line 14742 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,unsigned int bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1242*//*1243:*/
#line 14753 "./marpa.w"

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

/*:1243*//*1244:*/
#line 14766 "./marpa.w"

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

/*:1244*//*1245:*/
#line 14780 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1245*//*1246:*/
#line 14790 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1246*//*1247:*/
#line 14800 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1247*//*1248:*/
#line 14810 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1248*//*1249:*/
#line 14820 "./marpa.w"

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

/*:1249*//*1250:*/
#line 14892 "./marpa.w"

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

/*:1250*//*1255:*/
#line 14940 "./marpa.w"

PRIVATE void
rhs_closure(GRAMMAR g,Bit_Vector bv,XRLID**xrl_list_x_rh_sym)
{
unsigned int min,max,start= 0;
Marpa_Symbol_ID*end_of_stack= NULL;
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
while((end_of_stack= FSTACK_POP(stack)))
{
const XSYID xsy_id= *end_of_stack;
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

/*:1255*//*1260:*/
#line 15046 "./marpa.w"

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

/*:1260*//*1262:*/
#line 15068 "./marpa.w"

PRIVATE size_t matrix_sizeof(unsigned int rows,unsigned int columns)
{
const unsigned int bv_data_words= bv_bits_to_size(columns);
const unsigned int row_bytes= (bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
return offsetof(struct s_bit_matrix,t_row_data)+(rows)*row_bytes;
}

/*:1262*//*1264:*/
#line 15077 "./marpa.w"

PRIVATE Bit_Matrix matrix_obs_create(
struct marpa_obstack*obs,
unsigned int rows,
unsigned int columns)
{
Bit_Matrix matrix_addr= 
marpa_obs_alloc(obs,matrix_sizeof(rows,columns));
return matrix_buffer_create(matrix_addr,rows,columns);
}

/*:1264*//*1265:*/
#line 15089 "./marpa.w"

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

/*:1265*//*1266:*/
#line 15111 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1266*//*1267:*/
#line 15127 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,unsigned int row)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
unsigned int words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1267*//*1269:*/
#line 15136 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1269*//*1271:*/
#line 15144 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1271*//*1273:*/
#line 15152 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1273*//*1274:*/
#line 15169 "./marpa.w"

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

/*:1274*//*1286:*/
#line 15309 "./marpa.w"

PRIVATE void
cilar_init(const CILAR cilar)
{
cilar->t_obs= marpa_obs_init;
cilar->t_avl= _marpa_avl_create(cil_cmp,NULL,0);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}
/*:1286*//*1287:*/
#line 15323 "./marpa.w"

PRIVATE void
cilar_reinit(const CILAR cilar)
{
MARPA_DSTACK_DESTROY(cilar->t_buffer);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}

/*:1287*//*1288:*/
#line 15332 "./marpa.w"

PRIVATE void cilar_destroy(const CILAR cilar)
{
_marpa_avl_destroy(cilar->t_avl);
marpa_obs_free(cilar->t_obs);
MARPA_DSTACK_DESTROY((cilar->t_buffer));
}

/*:1288*//*1289:*/
#line 15341 "./marpa.w"

PRIVATE CIL cil_empty(CILAR cilar)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);
Count_of_CIL(cil)= 0;
return cil_buffer_add(cilar);
}

/*:1289*//*1290:*/
#line 15350 "./marpa.w"

PRIVATE CIL cil_singleton(CILAR cilar,int element)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);
Count_of_CIL(cil)= 1;
Item_of_CIL(cil,0)= element;

return cil_buffer_add(cilar);
}

/*:1290*//*1291:*/
#line 15366 "./marpa.w"

PRIVATE CIL cil_buffer_add(CILAR cilar)
{

CIL cil_in_buffer= MARPA_DSTACK_BASE(cilar->t_buffer,int);
CIL found_cil= _marpa_avl_find(cilar->t_avl,cil_in_buffer);
if(!found_cil)
{
int i;
const int cil_size_in_ints= Count_of_CIL(cil_in_buffer)+1;
found_cil= marpa_obs_new(cilar->t_obs,int,cil_size_in_ints);
for(i= 0;i<cil_size_in_ints;i++)
{
found_cil[i]= cil_in_buffer[i];
}
_marpa_avl_insert(cilar->t_avl,found_cil);
}
return found_cil;
}

/*:1291*//*1292:*/
#line 15394 "./marpa.w"

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

/*:1292*//*1293:*/
#line 15411 "./marpa.w"

PRIVATE void cil_buffer_clear(CILAR cilar)
{
const MARPA_DSTACK dstack= &cilar->t_buffer;
MARPA_DSTACK_CLEAR(*dstack);



*MARPA_DSTACK_PUSH(*dstack,int)= 0;
}

/*:1293*//*1294:*/
#line 15425 "./marpa.w"

PRIVATE CIL cil_buffer_push(CILAR cilar,int new_item)
{
CIL cil_in_buffer;
MARPA_DSTACK dstack= &cilar->t_buffer;
*MARPA_DSTACK_PUSH(*dstack,int)= new_item;


cil_in_buffer= MARPA_DSTACK_BASE(*dstack,int);
Count_of_CIL(cil_in_buffer)++;
return cil_in_buffer;
}

/*:1294*//*1295:*/
#line 15440 "./marpa.w"

PRIVATE CIL cil_buffer_reserve(CILAR cilar,int element_count)
{
const int desired_dstack_capacity= element_count+1;
const int old_dstack_capacity= MARPA_DSTACK_CAPACITY(cilar->t_buffer);
if(old_dstack_capacity<desired_dstack_capacity)
{
const int target_capacity= 
MAX(old_dstack_capacity*2,desired_dstack_capacity);
MARPA_DSTACK_RESIZE(&(cilar->t_buffer),int,target_capacity);
}
return MARPA_DSTACK_BASE(cilar->t_buffer,int);
}

/*:1295*//*1296:*/
#line 15458 "./marpa.w"

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

/*:1296*//*1297:*/
#line 15511 "./marpa.w"

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

/*:1297*//*1298:*/
#line 15546 "./marpa.w"

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

/*:1298*//*1311:*/
#line 15674 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1311*//*1312:*/
#line 15681 "./marpa.w"

PRIVATE void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl)
{
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
if(owner)
*owner= NULL;
marpa_free(psl);
psl= next_psl;
}
}
/*:1312*//*1313:*/
#line 15695 "./marpa.w"

PRIVATE PSL psl_new(const PSAR psar)
{
int i;
PSL new_psl= marpa_malloc(Sizeof_PSL(psar));
new_psl->t_next= NULL;
new_psl->t_prev= NULL;
new_psl->t_owner= NULL;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(new_psl,i)= NULL;
}
return new_psl;
}
/*:1313*//*1316:*/
#line 15726 "./marpa.w"

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

/*:1316*//*1318:*/
#line 15744 "./marpa.w"

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

/*:1318*//*1320:*/
#line 15764 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1320*//*1322:*/
#line 15788 "./marpa.w"

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

/*:1322*//*1325:*/
#line 15814 "./marpa.w"

PRIVATE_NOT_INLINE void*
_marpa_default_out_of_memory(void)
{
abort();
}
void*(*const _marpa_out_of_memory)(void)= _marpa_default_out_of_memory;

/*:1325*//*1351:*/
#line 16002 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}
/*:1351*//*1352:*/
#line 16021 "./marpa.w"

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

/*:1352*//*1360:*/
#line 16098 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
_marpa_debug_handler= debug_handler;
}

/*:1360*//*1362:*/
#line 16106 "./marpa.w"

void marpa_debug_level_set(int level)
{
_marpa_debug_level= level;
}

/*:1362*/
#line 16342 "./marpa.w"


/*:1377*/
