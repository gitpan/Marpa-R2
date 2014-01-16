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
 * This file is written by the Marpa build process
 * It is not intended to be modified directly
 */

/*1371:*/
#line 16142 "./marpa.w"


#include "config.h"

#ifndef MARPA_DEBUG
#define MARPA_DEBUG 0
#endif

#include "marpa.h"
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
#define AIM_by_ID(id) (g->t_AHFA_items+(id) ) 
#define ID_of_AIM(aim) ((aim) -g->t_AHFA_items) 
#define Next_AIM_of_AIM(aim) ((aim) +1) 
#define Prev_AIM_of_AIM(aim) ((aim) -1)  \

#define AIM_Count_of_G(g) ((g) ->t_aim_count) 
#define IRL_of_AIM(aim) ((aim) ->t_irl) 
#define IRLID_of_AIM(item) ID_of_IRL(IRL_of_AIM(item) ) 
#define LHS_NSYID_of_AIM(item) LHSID_of_IRL(IRL_of_AIM(item) ) 
#define Postdot_NSYID_of_AIM(item) ((item) ->t_postdot_nsyid) 
#define AIM_is_Completion(aim) (Postdot_NSYID_of_AIM(aim) <0) 
#define Null_Count_of_AIM(aim) ((aim) ->t_leading_nulls) 
#define Position_of_AIM(aim) ((aim) ->t_position) 
#define AIM_is_Prediction(aim) ( \
Position_of_AIM(aim) >=0 \
&&Position_of_AIM(aim) <=Null_Count_of_AIM(aim) ) 
#define AHFA_of_AIM(aim) ((aim) ->t_singleton_ahfa) 
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
#define YIM_ORDINAL_WIDTH 16
#define YIM_ORDINAL_CLAMP(x) (((1<<(YIM_ORDINAL_WIDTH) ) -1) &(x) ) 
#define YIM_FATAL_THRESHOLD ((1<<(YIM_ORDINAL_WIDTH) ) -2) 
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
#define Earley_Item_is_Ambiguous(item) ((item) ->t_source_type==SOURCE_IS_AMBIGUOUS)  \

#define Next_PIM_of_YIX(yix) ((yix) ->t_next) 
#define YIM_of_YIX(yix) ((yix) ->t_earley_item) 
#define Postdot_NSYID_of_YIX(yix) ((yix) ->t_postdot_nsyid) 
#define YIX_of_LIM(lim) ((YIX) (lim) ) 
#define Postdot_NSYID_of_LIM(leo) (Postdot_NSYID_of_YIX(YIX_of_LIM(leo) ) ) 
#define Next_PIM_of_LIM(leo) (Next_PIM_of_YIX(YIX_of_LIM(leo) ) ) 
#define Origin_of_LIM(leo) ((leo) ->t_origin) 
#define Top_AHFA_of_LIM(leo) ((leo) ->t_top_ahfa) 
#define Base_to_AHFA_of_LIM(leo) ((leo) ->t_base_to_ahfa) 
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
#define OR_Capacity_of_B(b) ((b) ->t_or_node_capacity) 
#define ANDs_of_B(b) ((b) ->t_and_nodes) 
#define AND_Count_of_B(b) ((b) ->t_and_node_count) 
#define Top_ORID_of_B(b) ((b) ->t_top_or_node_id) 
#define Path_AIM_of_LIM(lim) (AIM_of_AHFA_by_AEX(Base_to_AHFA_of_LIM(lim) ,0) ) 
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
(*lbv_w((lbv) ,(LBW) (bit) ) |= lbv_b((LBW) (bit) ) ) 
#define lbv_bit_clear(lbv,bit)  \
(*lbv_w((lbv) ,((LBW) (bit) ) ) &= ~lbv_b((LBW) (bit) ) ) 
#define lbv_bit_test(lbv,bit)  \
((*lbv_w((lbv) ,((LBW) (bit) ) ) &lbv_b((LBW) (bit) ) ) !=0U)  \

#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DECLARE(stack,type) struct{int t_count;type*t_base;}stack;
#define FSTACK_CLEAR(stack) ((stack) .t_count= 0) 
#define FSTACK_INIT(stack,type,n) (FSTACK_CLEAR(stack) , \
((stack) .t_base= marpa_new(type,n) ) ) 
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
(sizeof(PSL_Object) +((size_t) psar->t_psl_length-1) *sizeof(void*) ) 
#define PSL_Datum(psl,i) ((psl) ->t_data[(i) ]) 
#define Dot_PSAR_of_R(r) (&(r) ->t_dot_psar_object) 
#define Dot_PSL_of_YS(ys) ((ys) ->t_dot_psl) 
#define FATAL_FLAG (0x1u) 
#define MARPA_DEV_ERROR(message) (set_error(g,MARPA_ERR_DEVELOPMENT,(message) ,0u) ) 
#define MARPA_INTERNAL_ERROR(message) (set_error(g,MARPA_ERR_INTERNAL,(message) ,0u) ) 
#define MARPA_ERROR(code) (set_error(g,(code) ,NULL,0u) ) 
#define MARPA_FATAL(code) (set_error(g,(code) ,NULL,FATAL_FLAG) ) 

#line 16152 "./marpa.w"

#include "marpa_obs.h"
#include "marpa_avl.h"
/*107:*/
#line 1011 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:107*//*143:*/
#line 1238 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef const struct s_xsy*XSY_Const;

/*:143*//*457:*/
#line 4830 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:457*//*500:*/
#line 5218 "./marpa.w"
struct s_AHFA_state;
/*:500*//*677:*/
#line 7165 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*YS;
typedef const struct s_earley_set*YS_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*YSK;
/*:677*//*716:*/
#line 7595 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*YIM;
typedef const struct s_earley_item*YIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*YIK;

/*:716*//*724:*/
#line 7745 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*YIX;
union u_postdot_item;
/*:724*//*727:*/
#line 7780 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:727*//*803:*/
#line 8822 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:803*//*807:*/
#line 8849 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:807*//*916:*/
#line 10424 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:916*//*945:*/
#line 10825 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:945*//*988:*/
#line 11474 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:988*//*1014:*/
#line 11871 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:1014*//*1046:*/
#line 12338 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:1046*//*1057:*/
#line 12441 "./marpa.w"

struct s_bocage_setup_per_ys;
/*:1057*//*1121:*/
#line 13132 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1121*//*1156:*/
#line 13579 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1156*//*1169:*/
#line 13716 "./marpa.w"

typedef struct s_value*VALUE;
/*:1169*//*1277:*/
#line 15172 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1277*//*1283:*/
#line 15226 "./marpa.w"

struct s_cil_arena;
/*:1283*//*1303:*/
#line 15559 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1303*//*1305:*/
#line 15574 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1305*/
#line 16155 "./marpa.w"

/*48:*/
#line 659 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:48*//*142:*/
#line 1236 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
/*:142*//*210:*/
#line 1746 "./marpa.w"

struct s_nsy;
typedef struct s_nsy*NSY;
typedef Marpa_NSY_ID NSYID;

/*:210*//*247:*/
#line 2012 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:247*//*320:*/
#line 2732 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:320*//*358:*/
#line 2980 "./marpa.w"
typedef int SYMI;
/*:358*//*499:*/
#line 5215 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef int AHFAID;
/*:499*//*510:*/
#line 5273 "./marpa.w"
typedef int AEX;
/*:510*//*593:*/
#line 6481 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:593*//*608:*/
#line 6572 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:608*//*674:*/
#line 7155 "./marpa.w"
typedef Marpa_Earleme JEARLEME;

/*:674*//*676:*/
#line 7159 "./marpa.w"
typedef Marpa_Earley_Set_ID YSID;
/*:676*//*751:*/
#line 8105 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:751*//*753:*/
#line 8117 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:753*//*937:*/
#line 10761 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:937*//*987:*/
#line 11463 "./marpa.w"

typedef int WHEID;

/*:987*//*1013:*/
#line 11867 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:1013*//*1028:*/
#line 12076 "./marpa.w"

typedef struct marpa_progress_item*PROGRESS;
/*:1028*//*1155:*/
#line 13575 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1155*//*1214:*/
#line 14382 "./marpa.w"

typedef unsigned int LBW;
typedef LBW*LBV;

/*:1214*//*1222:*/
#line 14474 "./marpa.w"

typedef LBW Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1222*//*1280:*/
#line 15193 "./marpa.w"

typedef int*CIL;

/*:1280*//*1284:*/
#line 15229 "./marpa.w"

typedef struct s_cil_arena*CILAR;
/*:1284*/
#line 16156 "./marpa.w"

/*1282:*/
#line 15218 "./marpa.w"

struct s_cil_arena{
struct marpa_obstack*t_obs;
MARPA_AVL_TREE t_avl;
MARPA_DSTACK_DECLARE(t_buffer);
};
typedef struct s_cil_arena CILAR_Object;

/*:1282*/
#line 16157 "./marpa.w"

/*47:*/
#line 653 "./marpa.w"
struct marpa_g{
/*133:*/
#line 1183 "./marpa.w"

int t_is_ok;

/*:133*/
#line 654 "./marpa.w"

/*58:*/
#line 734 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xsy_stack);
MARPA_DSTACK_DECLARE(t_nsy_stack);

/*:58*//*67:*/
#line 791 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xrl_stack);
MARPA_DSTACK_DECLARE(t_irl_stack);
/*:67*//*103:*/
#line 986 "./marpa.w"
Bit_Vector t_bv_nsyid_is_terminal;
/*:103*//*105:*/
#line 995 "./marpa.w"

Bit_Vector t_lbv_xsyid_is_completion_event;
Bit_Vector t_lbv_xsyid_is_nulled_event;
Bit_Vector t_lbv_xsyid_is_prediction_event;
/*:105*//*112:*/
#line 1033 "./marpa.w"

MARPA_DSTACK_DECLARE(t_events);
/*:112*//*120:*/
#line 1105 "./marpa.w"

MARPA_AVL_TREE t_xrl_tree;
/*:120*//*124:*/
#line 1135 "./marpa.w"

struct marpa_obstack*t_obs;
struct marpa_obstack*t_xrl_obs;
/*:124*//*127:*/
#line 1152 "./marpa.w"

CILAR_Object t_cilar;
/*:127*//*135:*/
#line 1198 "./marpa.w"

const char*t_error_string;
/*:135*//*460:*/
#line 4852 "./marpa.w"

AIM t_AHFA_items;
/*:460*//*527:*/
#line 5379 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:527*/
#line 655 "./marpa.w"

/*52:*/
#line 681 "./marpa.w"
int t_ref_count;
/*:52*//*77:*/
#line 842 "./marpa.w"
XSYID t_start_xsy_id;
/*:77*//*81:*/
#line 875 "./marpa.w"

IRL t_start_irl;
/*:81*//*85:*/
#line 892 "./marpa.w"

int t_external_size;
/*:85*//*88:*/
#line 906 "./marpa.w"
int t_max_rule_length;
/*:88*//*92:*/
#line 919 "./marpa.w"
Marpa_Rank t_default_rank;
/*:92*//*136:*/
#line 1200 "./marpa.w"

Marpa_Error_Code t_error;
/*:136*//*359:*/
#line 2982 "./marpa.w"

int t_symbol_instance_count;
/*:359*//*461:*/
#line 4856 "./marpa.w"

int t_aim_count;
/*:461*//*528:*/
#line 5384 "./marpa.w"
int t_AHFA_len;
/*:528*/
#line 656 "./marpa.w"

/*97:*/
#line 954 "./marpa.w"
BITFIELD t_is_precomputed:1;
/*:97*//*100:*/
#line 966 "./marpa.w"
BITFIELD t_has_cycle:1;
/*:100*/
#line 657 "./marpa.w"

};
/*:47*//*111:*/
#line 1026 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:111*//*144:*/
#line 1243 "./marpa.w"

struct s_xsy{
/*196:*/
#line 1646 "./marpa.w"

CIL t_nulled_event_xsyids;
/*:196*//*199:*/
#line 1673 "./marpa.w"
NSY t_nsy_equivalent;
/*:199*//*203:*/
#line 1705 "./marpa.w"
NSY t_nulling_nsy;
/*:203*/
#line 1245 "./marpa.w"

/*145:*/
#line 1252 "./marpa.w"
XSYID t_symbol_id;

/*:145*//*151:*/
#line 1286 "./marpa.w"

Marpa_Rank t_rank;
/*:151*/
#line 1246 "./marpa.w"

/*148:*/
#line 1273 "./marpa.w"
BITFIELD t_is_start:1;
/*:148*//*155:*/
#line 1333 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:155*//*157:*/
#line 1340 "./marpa.w"
BITFIELD t_is_sequence_lhs:1;
/*:157*//*159:*/
#line 1354 "./marpa.w"

BITFIELD t_is_valued:1;
BITFIELD t_is_valued_locked:1;
/*:159*//*163:*/
#line 1398 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:163*//*166:*/
#line 1419 "./marpa.w"
BITFIELD t_is_counted:1;
/*:166*//*169:*/
#line 1435 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:169*//*172:*/
#line 1452 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:172*//*175:*/
#line 1473 "./marpa.w"

BITFIELD t_is_terminal:1;
BITFIELD t_is_locked_terminal:1;
/*:175*//*180:*/
#line 1520 "./marpa.w"
BITFIELD t_is_productive:1;
/*:180*//*183:*/
#line 1539 "./marpa.w"
BITFIELD t_is_completion_event:1;
/*:183*//*187:*/
#line 1574 "./marpa.w"
BITFIELD t_is_nulled_event:1;
/*:187*//*191:*/
#line 1609 "./marpa.w"
BITFIELD t_is_prediction_event:1;
/*:191*/
#line 1247 "./marpa.w"

};

/*:144*//*211:*/
#line 1760 "./marpa.w"

struct s_nsy{
int t_or_node_type;
NSYID t_nsyid;
/*233:*/
#line 1910 "./marpa.w"
XSY t_source_xsy;
/*:233*//*237:*/
#line 1933 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:237*/
#line 1764 "./marpa.w"

/*242:*/
#line 1986 "./marpa.w"
Marpa_Rank t_rank;
/*:242*/
#line 1765 "./marpa.w"

/*221:*/
#line 1844 "./marpa.w"
BITFIELD t_is_start:1;
/*:221*//*224:*/
#line 1858 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:224*//*227:*/
#line 1872 "./marpa.w"
BITFIELD t_nsy_is_nulling:1;
/*:227*//*230:*/
#line 1889 "./marpa.w"
BITFIELD t_is_semantic:1;
/*:230*/
#line 1766 "./marpa.w"

};
/*:211*//*246:*/
#line 2003 "./marpa.w"

struct s_xrl{
/*259:*/
#line 2305 "./marpa.w"
int t_rhs_length;
/*:259*//*267:*/
#line 2370 "./marpa.w"
Marpa_Rule_ID t_id;

/*:267*//*268:*/
#line 2373 "./marpa.w"

Marpa_Rank t_rank;
/*:268*/
#line 2005 "./marpa.w"

/*272:*/
#line 2421 "./marpa.w"

BITFIELD t_null_ranks_high:1;
/*:272*//*276:*/
#line 2462 "./marpa.w"
BITFIELD t_is_bnf:1;
/*:276*//*278:*/
#line 2468 "./marpa.w"
BITFIELD t_is_sequence:1;
/*:278*//*280:*/
#line 2482 "./marpa.w"
int t_minimum;
/*:280*//*283:*/
#line 2507 "./marpa.w"
XSYID t_separator_id;
/*:283*//*288:*/
#line 2540 "./marpa.w"
BITFIELD t_is_discard:1;
/*:288*//*292:*/
#line 2580 "./marpa.w"
BITFIELD t_is_proper_separation:1;
/*:292*//*296:*/
#line 2601 "./marpa.w"
BITFIELD t_is_loop:1;
/*:296*//*299:*/
#line 2618 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:299*//*302:*/
#line 2636 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:302*//*306:*/
#line 2654 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:306*//*309:*/
#line 2672 "./marpa.w"
BITFIELD t_is_productive:1;
/*:309*//*312:*/
#line 2690 "./marpa.w"
BITFIELD t_is_used:1;
/*:312*/
#line 2006 "./marpa.w"

/*260:*/
#line 2308 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];


/*:260*/
#line 2007 "./marpa.w"

};
/*:246*//*318:*/
#line 2721 "./marpa.w"

struct s_irl{
/*350:*/
#line 2924 "./marpa.w"
XRL t_source_xrl;
/*:350*//*356:*/
#line 2972 "./marpa.w"
AIM t_first_aim;
/*:356*/
#line 2723 "./marpa.w"

/*321:*/
#line 2743 "./marpa.w"
IRLID t_irl_id;

/*:321*//*328:*/
#line 2780 "./marpa.w"
int t_length;
/*:328*//*341:*/
#line 2864 "./marpa.w"
int t_real_symbol_count;
/*:341*//*344:*/
#line 2882 "./marpa.w"
int t_virtual_start;
/*:344*//*347:*/
#line 2902 "./marpa.w"
int t_virtual_end;
/*:347*//*353:*/
#line 2951 "./marpa.w"
Marpa_Rank t_rank;
/*:353*//*360:*/
#line 2989 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:360*/
#line 2724 "./marpa.w"

/*332:*/
#line 2821 "./marpa.w"
BITFIELD t_is_virtual_lhs:1;
/*:332*//*335:*/
#line 2837 "./marpa.w"
BITFIELD t_is_virtual_rhs:1;
/*:335*//*338:*/
#line 2853 "./marpa.w"
BITFIELD t_is_right_recursive:1;
/*:338*/
#line 2725 "./marpa.w"

/*323:*/
#line 2748 "./marpa.w"

NSYID t_nsyid_array[1];

/*:323*/
#line 2726 "./marpa.w"

};
typedef struct s_irl IRL_Object;

/*:318*//*373:*/
#line 3178 "./marpa.w"

struct sym_rule_pair
{
XSYID t_symid;
RULEID t_ruleid;
};

/*:373*//*456:*/
#line 4824 "./marpa.w"

struct s_AHFA_item{
int t_sort_key;
/*466:*/
#line 4878 "./marpa.w"

IRL t_irl;

/*:466*//*470:*/
#line 4910 "./marpa.w"

AHFA t_singleton_ahfa;

/*:470*/
#line 4827 "./marpa.w"

/*467:*/
#line 4885 "./marpa.w"
NSYID t_postdot_nsyid;

/*:467*//*468:*/
#line 4894 "./marpa.w"

int t_leading_nulls;

/*:468*//*469:*/
#line 4903 "./marpa.w"

int t_position;

/*:469*/
#line 4828 "./marpa.w"

};
/*:456*//*501:*/
#line 5219 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*505:*/
#line 5248 "./marpa.w"

CIL t_completion_xsyids;
CIL t_nulled_xsyids;
CIL t_prediction_xsyids;

/*:505*//*508:*/
#line 5266 "./marpa.w"

CIL t_indirect_completion_event_nsyids;
CIL t_direct_completion_event_nsyids;
CIL t_complete_nsyids;

/*:508*//*511:*/
#line 5277 "./marpa.w"

AIM*t_items;
/*:511*//*523:*/
#line 5368 "./marpa.w"

CIL t_event_ahfaids;
/*:523*//*533:*/
#line 5412 "./marpa.w"
Marpa_Symbol_ID*t_postdot_nsyidary;
/*:533*/
#line 5226 "./marpa.w"

/*512:*/
#line 5280 "./marpa.w"

int t_item_count;
/*:512*//*524:*/
#line 5372 "./marpa.w"

int t_event_group_size;
/*:524*//*534:*/
#line 5413 "./marpa.w"
int t_postdot_nsy_count;

/*:534*//*545:*/
#line 5576 "./marpa.w"

NSYID t_leo_lhs_nsyid;
IRLID t_leo_irlid;
/*:545*/
#line 5227 "./marpa.w"

/*517:*/
#line 5337 "./marpa.w"

BITFIELD t_is_predict:1;

/*:517*//*520:*/
#line 5345 "./marpa.w"

BITFIELD t_is_potential_leo_base:1;
/*:520*/
#line 5228 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:501*//*594:*/
#line 6484 "./marpa.w"

struct s_input{
/*603:*/
#line 6554 "./marpa.w"

struct marpa_obstack*t_token_obs;

/*:603*//*605:*/
#line 6559 "./marpa.w"

GRAMMAR t_grammar;
/*:605*/
#line 6486 "./marpa.w"

/*597:*/
#line 6500 "./marpa.w"

int t_ref_count;
/*:597*/
#line 6487 "./marpa.w"

};

/*:594*//*678:*/
#line 7171 "./marpa.w"

struct s_earley_set_key{
JEARLEME t_earleme;
};
typedef struct s_earley_set_key YSK_Object;
/*:678*//*679:*/
#line 7176 "./marpa.w"

struct s_earley_set{
YSK_Object t_key;
union u_postdot_item**t_postdot_ary;
YS t_next_earley_set;
/*681:*/
#line 7192 "./marpa.w"

YIM*t_earley_items;

/*:681*//*1313:*/
#line 15644 "./marpa.w"

PSL t_dot_psl;
/*:1313*/
#line 7181 "./marpa.w"

int t_postdot_sym_count;
/*680:*/
#line 7189 "./marpa.w"

int t_yim_count;
/*:680*//*682:*/
#line 7203 "./marpa.w"

int t_ordinal;
/*:682*//*686:*/
#line 7221 "./marpa.w"

int t_value;
void*t_pvalue;
/*:686*/
#line 7183 "./marpa.w"

};
typedef struct s_earley_set YS_Object;

/*:679*//*725:*/
#line 7749 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
NSYID t_postdot_nsyid;
YIM t_earley_item;
};
typedef struct s_earley_ix YIX_Object;

/*:725*//*728:*/
#line 7783 "./marpa.w"

struct s_leo_item{
YIX_Object t_earley_ix;
/*729:*/
#line 7797 "./marpa.w"

CIL t_cil;

/*:729*/
#line 7786 "./marpa.w"

YS t_origin;
AHFA t_top_ahfa;
AHFA t_base_to_ahfa;
LIM t_predecessor;
YIM t_base;
YS t_set;
};
typedef struct s_leo_item LIM_Object;

/*:728*//*735:*/
#line 7878 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
YIX_Object t_earley;
};
typedef union u_postdot_item PIM_Object;
typedef union u_postdot_item*PIM;

/*:735*//*804:*/
#line 8830 "./marpa.w"

struct s_token_unvalued{
int t_type;
NSYID t_nsyid;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:804*//*808:*/
#line 8859 "./marpa.w"

struct s_alternative{
TOK t_token;
YS t_start_earley_set;
JEARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:808*//*917:*/
#line 10441 "./marpa.w"

struct s_ur_node_stack{
struct marpa_obstack*t_obs;
UR t_base;
UR t_top;
};

/*:917*//*918:*/
#line 10448 "./marpa.w"

struct s_ur_node{
UR t_prev;
UR t_next;
YIM t_earley_item;
AEX t_aex;
};
typedef struct s_ur_node UR_Object;

/*:918*//*948:*/
#line 10863 "./marpa.w"

struct s_draft_or_node
{
/*947:*/
#line 10857 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:947*/
#line 10866 "./marpa.w"

DAND t_draft_and_node;
};
/*:948*//*949:*/
#line 10869 "./marpa.w"

struct s_final_or_node
{
/*947:*/
#line 10857 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:947*/
#line 10872 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:949*//*950:*/
#line 10880 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:950*//*989:*/
#line 11481 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:989*//*1015:*/
#line 11878 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:1015*//*1058:*/
#line 12443 "./marpa.w"

struct s_bocage_setup_per_ys{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:1058*//*1085:*/
#line 12682 "./marpa.w"

struct marpa_order{
struct marpa_obstack*t_ordering_obs;
ANDID**t_and_node_orderings;
/*1088:*/
#line 12700 "./marpa.w"

BOCAGE t_bocage;

/*:1088*/
#line 12686 "./marpa.w"

/*1091:*/
#line 12720 "./marpa.w"
int t_ref_count;
/*:1091*//*1098:*/
#line 12776 "./marpa.w"
int t_ambiguity_metric;

/*:1098*//*1103:*/
#line 12808 "./marpa.w"
int t_high_rank_count;
/*:1103*/
#line 12687 "./marpa.w"

/*1101:*/
#line 12790 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1101*/
#line 12688 "./marpa.w"

BITFIELD t_is_frozen:1;
};
/*:1085*//*1122:*/
#line 13144 "./marpa.w"

/*1157:*/
#line 13590 "./marpa.w"

struct s_nook{
OR t_or_node;
int t_choice;
NOOKID t_parent;
BITFIELD t_is_cause_ready:1;
BITFIELD t_is_predecessor_ready:1;
BITFIELD t_is_cause_of_parent:1;
BITFIELD t_is_predecessor_of_parent:1;
};
typedef struct s_nook NOOK_Object;

/*:1157*/
#line 13145 "./marpa.w"

/*1171:*/
#line 13730 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1175:*/
#line 13808 "./marpa.w"

struct marpa_obstack*t_obs;
/*:1175*//*1180:*/
#line 13855 "./marpa.w"

MARPA_DSTACK_DECLARE(t_virtual_stack);
/*:1180*//*1202:*/
#line 14008 "./marpa.w"

LBV t_xsy_is_valued;
LBV t_xrl_is_valued;
LBV t_valued_locked;

/*:1202*/
#line 13734 "./marpa.w"

/*1185:*/
#line 13903 "./marpa.w"

int t_ref_count;
/*:1185*//*1197:*/
#line 13984 "./marpa.w"

NOOKID t_nook;
/*:1197*/
#line 13735 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1192:*/
#line 13956 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1192*//*1194:*/
#line 13963 "./marpa.w"

BITFIELD t_trace:1;
/*:1194*/
#line 13738 "./marpa.w"

};

/*:1171*/
#line 13146 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_or_node_in_use;
Marpa_Order t_order;
/*1128:*/
#line 13217 "./marpa.w"

int t_ref_count;
/*:1128*//*1135:*/
#line 13297 "./marpa.w"
int t_pause_counter;
/*:1135*/
#line 13152 "./marpa.w"

/*1141:*/
#line 13368 "./marpa.w"

BITFIELD t_is_exhausted:1;
/*:1141*//*1144:*/
#line 13376 "./marpa.w"

BITFIELD t_is_nulling:1;

/*:1144*/
#line 13153 "./marpa.w"

int t_parse_count;
};

/*:1122*//*1257:*/
#line 14957 "./marpa.w"

struct s_bit_matrix{
int t_row_count;
Bit_Vector_Word t_row_data[1];
};
typedef struct s_bit_matrix*Bit_Matrix;
typedef struct s_bit_matrix Bit_Matrix_Object;

/*:1257*//*1278:*/
#line 15175 "./marpa.w"

struct s_dqueue{int t_current;struct marpa_dstack_s t_stack;};

/*:1278*//*1304:*/
#line 15565 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1304*//*1306:*/
#line 15590 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1306*/
#line 16158 "./marpa.w"


/*:1371*//*1372:*/
#line 16163 "./marpa.w"

/*39:*/
#line 586 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;

/*:39*//*951:*/
#line 10888 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:951*//*1034:*/
#line 12102 "./marpa.w"

static const struct marpa_progress_item progress_report_not_ready= {-2,-2,-2};

/*:1034*//*1223:*/
#line 14481 "./marpa.w"

static const unsigned int bv_wordbits= lbv_wordbits;
static const unsigned int bv_modmask= lbv_wordbits-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= lbv_lsb;
static const unsigned int bv_msb= lbv_msb;

/*:1223*/
#line 16164 "./marpa.w"


/*:1372*//*1373:*/
#line 16166 "./marpa.w"

/*609:*/
#line 6575 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*622:*/
#line 6675 "./marpa.w"

YS t_first_earley_set;
YS t_latest_earley_set;
JEARLEME t_current_earleme;
/*:622*//*634:*/
#line 6748 "./marpa.w"

Bit_Vector t_lbv_xsyid_completion_event_is_active;
Bit_Vector t_lbv_xsyid_nulled_event_is_active;
Bit_Vector t_lbv_xsyid_prediction_event_is_active;
/*:634*//*637:*/
#line 6768 "./marpa.w"
Bit_Vector t_bv_nsyid_is_expected;
/*:637*//*641:*/
#line 6824 "./marpa.w"
LBV t_nsy_expected_is_event;
/*:641*//*667:*/
#line 7126 "./marpa.w"
struct marpa_obstack*t_obs;
/*:667*//*693:*/
#line 7333 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:693*//*700:*/
#line 7408 "./marpa.w"

YIM t_trace_earley_item;
/*:700*//*738:*/
#line 7925 "./marpa.w"

union u_postdot_item**t_trace_pim_nsy_p;
union u_postdot_item*t_trace_postdot_item;
/*:738*//*772:*/
#line 8385 "./marpa.w"

SRCL t_trace_source_link;
/*:772*//*809:*/
#line 8867 "./marpa.w"

MARPA_DSTACK_DECLARE(t_alternatives);
/*:809*//*824:*/
#line 9065 "./marpa.w"

LBV t_valued_terminal;
LBV t_unvalued_terminal;
LBV t_valued;
LBV t_unvalued;
LBV t_valued_locked;

/*:824*//*832:*/
#line 9282 "./marpa.w"
MARPA_DSTACK_DECLARE(t_yim_work_stack);
/*:832*//*836:*/
#line 9297 "./marpa.w"
MARPA_DSTACK_DECLARE(t_completion_stack);
/*:836*//*840:*/
#line 9308 "./marpa.w"
MARPA_DSTACK_DECLARE(t_earley_set_stack);
/*:840*//*874:*/
#line 9871 "./marpa.w"

Bit_Vector t_bv_lim_symbols;
Bit_Vector t_bv_pim_symbols;
void**t_pim_workarea;
/*:874*//*893:*/
#line 10153 "./marpa.w"

void**t_lim_chain;
/*:893*//*919:*/
#line 10458 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:919*//*1029:*/
#line 12078 "./marpa.w"

const struct marpa_progress_item*t_current_report_item;
MARPA_AVL_TRAV t_progress_report_traverser;
/*:1029*//*1307:*/
#line 15598 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1307*/
#line 6578 "./marpa.w"

/*612:*/
#line 6602 "./marpa.w"
int t_ref_count;
/*:612*//*626:*/
#line 6702 "./marpa.w"
int t_earley_item_warning_threshold;
/*:626*//*630:*/
#line 6731 "./marpa.w"
JEARLEME t_furthest_earleme;
/*:630*//*635:*/
#line 6752 "./marpa.w"

int t_active_event_count;
/*:635*//*683:*/
#line 7207 "./marpa.w"

int t_earley_set_count;
/*:683*/
#line 6579 "./marpa.w"

/*619:*/
#line 6666 "./marpa.w"

BITFIELD t_input_phase:2;
/*:619*//*659:*/
#line 7063 "./marpa.w"

BITFIELD t_use_leo_flag:1;
BITFIELD t_is_using_leo:1;
/*:659*//*663:*/
#line 7101 "./marpa.w"
BITFIELD t_is_exhausted:1;
/*:663*//*773:*/
#line 8387 "./marpa.w"

BITFIELD t_trace_source_type:3;
/*:773*/
#line 6580 "./marpa.w"

};

/*:609*/
#line 16167 "./marpa.w"

/*752:*/
#line 8108 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:752*//*754:*/
#line 8120 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};
typedef struct s_source_link SRCL_Object;

/*:754*//*755:*/
#line 8127 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:755*//*756:*/
#line 8134 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source_link t_unique;
};

/*:756*/
#line 16168 "./marpa.w"

/*717:*/
#line 7611 "./marpa.w"

struct s_earley_item_key{
AHFA t_state;
YS t_origin;
YS t_set;
};
typedef struct s_earley_item_key YIK_Object;
struct s_earley_item{
YIK_Object t_key;
union u_source_container t_container;
BITFIELD t_ordinal:YIM_ORDINAL_WIDTH;
BITFIELD t_source_type:3;
BITFIELD t_rejected:1;
};
typedef struct s_earley_item YIM_Object;

/*:717*/
#line 16169 "./marpa.w"

/*1047:*/
#line 12340 "./marpa.w"

struct marpa_bocage{
/*952:*/
#line 10899 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:952*//*1049:*/
#line 12349 "./marpa.w"

INPUT t_input;

/*:1049*//*1051:*/
#line 12359 "./marpa.w"

struct marpa_obstack*t_obs;
/*:1051*//*1054:*/
#line 12418 "./marpa.w"

LBV t_valued_bv;
LBV t_valued_locked_bv;

/*:1054*/
#line 12342 "./marpa.w"

/*953:*/
#line 10902 "./marpa.w"

int t_or_node_capacity;
int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:953*//*1069:*/
#line 12581 "./marpa.w"
int t_ambiguity_metric;
/*:1069*//*1073:*/
#line 12595 "./marpa.w"
int t_ref_count;
/*:1073*/
#line 12343 "./marpa.w"

/*1080:*/
#line 12654 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1080*/
#line 12344 "./marpa.w"

};

/*:1047*/
#line 16170 "./marpa.w"


/*:1373*/

#line 1 "./marpa.c.p40"
static RULE rule_new(GRAMMAR g,
const XSYID lhs, const XSYID *rhs, int length);
static int
duplicate_rule_cmp (const void *ap, const void *bp, void *param  UNUSED);
static int sym_rule_cmp(
    const void* ap,
    const void* bp,
    void *param  UNUSED);
static int cmp_by_aimid (const void* ap,
        const void* bp);
static int cmp_by_postdot_and_aimid (const void* ap,
        const void* bp);
static int AHFA_state_cmp(
    const void* ap,
    const void* bp,
    void *param  UNUSED);
static int
cmp_by_irl_sort_key(const void* ap, const void* bp);
static AHFA
create_predicted_AHFA_state(
     GRAMMAR g,
     Bit_Vector prediction_rule_vector,
     IRL* irl_by_sort_key,
     DQUEUE states_p,
     MARPA_AVL_TREE duplicates,
     AIM* item_list_working_buffer
     );
static Marpa_Error_Code invalid_source_type_code(unsigned int type);
static void earley_item_ambiguate (struct marpa_r * r, YIM item);
static void
postdot_items_create (RECCE r,
  Bit_Vector bv_ok_for_chain,
  const YS current_earley_set);
static int report_item_cmp (
    const void* ap,
    const void* bp,
    void *param  UNUSED);
static int bv_scan(Bit_Vector bv, int raw_start, int* raw_min, int* raw_max);
static void transitive_closure(Bit_Matrix matrix);
static int
cil_cmp (const void *ap, const void *bp, void *param  UNUSED);
static void
set_error (GRAMMAR g, Marpa_Error_Code code, const char* message, unsigned int flags);
static void*
marpa__default_out_of_memory(void);
static inline void
grammar_unref (GRAMMAR g);
static inline GRAMMAR
grammar_ref (GRAMMAR g);
static inline void grammar_free(GRAMMAR g);
static inline void symbol_add( GRAMMAR g, XSY symbol);
static inline int xsy_id_is_valid(GRAMMAR g, XSYID xsy_id);
static inline int nsy_is_valid(GRAMMAR g, NSYID nsyid);
static inline void
rule_add (GRAMMAR g, RULE rule);
static inline void event_new(GRAMMAR g, int type);
static inline void int_event_new(GRAMMAR g, int type, int value);
static inline XSY
symbol_new (GRAMMAR g);
static inline NSY symbol_alias_create(GRAMMAR g, XSY symbol);
static inline NSY
nsy_start(GRAMMAR g);
static inline NSY
nsy_new(GRAMMAR g, XSY source);
static inline NSY
semantic_nsy_new(GRAMMAR g, XSY source);
static inline NSY
nsy_clone(GRAMMAR g, XSY xsy);
static inline   XRL xrl_start (GRAMMAR g, const XSYID lhs, const XSYID * rhs, int length);
static inline XRL xrl_finish(GRAMMAR g, XRL rule);
static inline IRL
irl_start(GRAMMAR g, int length);
static inline void
irl_finish( GRAMMAR g, IRL irl);
static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
static inline Marpa_Symbol_ID* rule_rhs_get(RULE rule);
static inline int
symbol_instance_of_ahfa_item_get (AIM aim);
static inline int aim_is_valid(
GRAMMAR g, AIMID item_id);
static inline void AHFA_initialize(GRAMMAR g, AHFA ahfa);
static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa, AIM sought_aim);
static inline AEX aex_of_ahfa_by_postdot_get(AHFA ahfa, NSYID sought_nsyid);
static inline int AHFA_state_id_is_valid(GRAMMAR g, AHFAID AHFA_state_id);
static inline AHFA
create_singleton_AHFA_state(
    GRAMMAR g,
    AIM base_aim,
      AHFA* singleton_duplicates,
     IRL* irl_by_sort_key,
     DQUEUE states_p,
     MARPA_AVL_TREE duplicates,
     AIM* item_list_working_buffer,
   Bit_Matrix prediction_matrix
);
static inline AHFA
assign_AHFA_state (AHFA sought_state, MARPA_AVL_TREE duplicates);
static inline INPUT input_new (GRAMMAR g);
static inline void
input_unref (INPUT input);
static inline INPUT
input_ref (INPUT input);
static inline void input_free(INPUT input);
static inline void
recce_unref (RECCE r);
static inline RECCE recce_ref (RECCE r);
static inline void recce_free(struct marpa_r *r);
static inline YS current_ys_of_r(RECCE r);
static inline YS
earley_set_new( RECCE r, JEARLEME id);
static inline void trace_earley_item_clear(RECCE r);
static inline YIM earley_item_create(const RECCE r,
    const YIK_Object key);
static inline YIM
earley_item_assign (const RECCE r, const YS set, const YS origin,
                    const AHFA state);
static inline PIM*
pim_nsy_p_find (YS set, NSYID nsyid);
static inline PIM first_pim_of_ys_by_nsyid(YS set, NSYID nsyid);
static inline void
completion_link_add (RECCE r,
                YIM item,
                YIM predecessor,
                YIM cause);
static inline void
leo_link_add (RECCE r,
                YIM item,
                LIM predecessor,
                YIM cause);
static inline void trace_source_link_clear(RECCE r);
static inline int
alternative_insertion_point (RECCE r, ALT new_alternative);
static inline int alternative_cmp(const ALT_Const a, const ALT_Const b);
static inline ALT alternative_pop(RECCE r, JEARLEME earleme);
static inline int alternative_insert(RECCE r, ALT new_alternative);
static inline void trigger_events(RECCE r);
static inline void earley_set_update_items(RECCE r, YS set);
static inline void r_update_earley_sets(RECCE r);
static inline void ur_node_stack_init(URS stack);
static inline void ur_node_stack_reset(URS stack);
static inline void ur_node_stack_destroy(URS stack);
static inline UR ur_node_new(URS stack, UR prev);
static inline void
ur_node_push (URS stack, YIM earley_item, AEX aex);
static inline UR
ur_node_pop (URS stack);
static inline int psia_test_and_set(
    struct marpa_obstack* obs,
    struct s_bocage_setup_per_ys* per_ys_data,
    YIM earley_item,
    AEX ahfa_element_ix);
static inline int
Set_boolean_in_PSIA_for_initial_nulls (struct marpa_obstack *bocage_setup_obs,
				       struct s_bocage_setup_per_ys
				       *per_ys_data, YIM yim, AIM aim);
static inline AEX lim_base_data_get(LIM leo_item, YIM* p_base);
static inline AIM base_aim_of_lim(LIM leo_item);
static inline DAND draft_and_node_new(struct marpa_obstack *obs, OR predecessor, OR cause);
static inline void draft_and_node_add(struct marpa_obstack *obs, OR parent, OR predecessor, OR cause);
static inline TOK and_node_token(AND and_node);
static inline void
bocage_unref (BOCAGE b);
static inline BOCAGE
bocage_ref (BOCAGE b);
static inline void
bocage_free (BOCAGE b);
static inline void
order_unref (ORDER o);
static inline ORDER
order_ref (ORDER o);
static inline void order_free(ORDER o);
static inline ANDID and_order_ix_is_valid(ORDER o, OR or_node, int ix);
static inline ANDID and_order_get(ORDER o, OR or_node, int ix);
static inline void tree_exhaust(TREE t);
static inline void
tree_unref (TREE t);
static inline TREE
tree_ref (TREE t);
static inline void tree_free(TREE t);
static inline void
tree_pause (TREE t);
static inline void
tree_unpause (TREE t);
static inline int tree_or_node_try(TREE tree, ORID or_node_id);
static inline void tree_or_node_release(TREE tree, ORID or_node_id);
static inline void
value_unref (VALUE v);
static inline VALUE
value_ref (VALUE v);
static inline void value_free(VALUE v);
static inline int symbol_is_valued_set (
    VALUE v, XSYID xsy_id, int value);
static inline int lbv_bits_to_size(int bits);
static inline Bit_Vector
lbv_obs_new (struct marpa_obstack *obs, int bits);
static inline Bit_Vector
lbv_zero (Bit_Vector lbv, int bits);
static inline Bit_Vector
lbv_obs_new0 (struct marpa_obstack *obs, int bits);
static inline LBV lbv_clone(
  struct marpa_obstack* obs, LBV old_lbv, int bits);
static inline LBV lbv_fill(
  LBV lbv, int bits);
static inline unsigned int bv_bits_to_size(int bits);
static inline unsigned int bv_bits_to_unused_mask(int bits);
static inline Bit_Vector bv_create(int bits);
static inline Bit_Vector
bv_obs_create (struct marpa_obstack *obs, int bits);
static inline Bit_Vector bv_shadow(Bit_Vector bv);
static inline Bit_Vector bv_obs_shadow(struct marpa_obstack * obs, Bit_Vector bv);
static inline Bit_Vector bv_copy(Bit_Vector bv_to, Bit_Vector bv_from);
static inline Bit_Vector bv_clone(Bit_Vector bv);
static inline Bit_Vector bv_obs_clone(struct marpa_obstack *obs, Bit_Vector bv);
static inline void bv_free(Bit_Vector vector);
static inline void bv_fill(Bit_Vector bv);
static inline void bv_clear(Bit_Vector bv);
static inline void bv_over_clear(Bit_Vector bv, int raw_bit);
static inline void bv_bit_set(Bit_Vector vector, int raw_bit);
static inline void bv_bit_clear(Bit_Vector vector, int raw_bit);
static inline int bv_bit_test(Bit_Vector vector, int raw_bit);
static inline int
bv_bit_test_then_set (Bit_Vector vector, int raw_bit);
static inline int bv_is_empty(Bit_Vector addr);
static inline void bv_not(Bit_Vector X, Bit_Vector Y);
static inline void bv_and(Bit_Vector X, Bit_Vector Y, Bit_Vector Z);
static inline void bv_or(Bit_Vector X, Bit_Vector Y, Bit_Vector Z);
static inline void bv_or_assign(Bit_Vector X, Bit_Vector Y);
static inline int
bv_count (Bit_Vector v);
static inline void
rhs_closure (GRAMMAR g, Bit_Vector bv, XRLID ** xrl_list_x_rh_sym);
static inline Bit_Matrix
matrix_buffer_create (void *buffer, int rows, int columns);
static inline size_t matrix_sizeof(int rows, int columns);
static inline Bit_Matrix matrix_obs_create(
  struct marpa_obstack *obs,
  int rows,
  int columns);
static inline void matrix_clear(Bit_Matrix matrix);
static inline int matrix_columns(Bit_Matrix matrix);
static inline Bit_Vector matrix_row(Bit_Matrix matrix, int row);
static inline void matrix_bit_set(Bit_Matrix matrix, int row, int column);
static inline void matrix_bit_clear(Bit_Matrix matrix, int row, int column);
static inline int matrix_bit_test(Bit_Matrix matrix, int row, int column);
static inline void
cilar_init (const CILAR cilar);
static inline void
cilar_reinit (const CILAR cilar);
static inline void cilar_destroy(const CILAR cilar);
static inline CIL cil_empty(CILAR cilar);
static inline CIL cil_singleton(CILAR cilar, int element);
static inline CIL cil_buffer_add(CILAR cilar);
static inline CIL cil_bv_add(CILAR cilar, Bit_Vector bv);
static inline void cil_buffer_clear(CILAR cilar);
static inline CIL cil_buffer_push(CILAR cilar, int new_item);
static inline CIL cil_buffer_reserve(CILAR cilar, int element_count);
static inline CIL cil_merge(CILAR cilar, CIL cil1, CIL cil2);
static inline CIL cil_merge_one(CILAR cilar, CIL cil, int new_element);
static inline void
psar_init (const PSAR psar, int length);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
static inline void psar_reset(const PSAR psar);
static inline void psar_dealloc(const PSAR psar);
static inline void psl_claim(
    PSL* const psl_owner, const PSAR psar);
static inline PSL psl_alloc(const PSAR psar);
static inline Marpa_Error_Code
clear_error (GRAMMAR g);

/*1374:*/
#line 16172 "./marpa.w"

/*1352:*/
#line 15977 "./marpa.w"

extern void*(*const marpa__out_of_memory)(void);

/*:1352*//*1354:*/
#line 15989 "./marpa.w"

extern int marpa__default_debug_handler(const char*format,...);
extern int(*marpa__debug_handler)(const char*,...);
extern int marpa__debug_level;

/*:1354*/
#line 16173 "./marpa.w"

#if MARPA_DEBUG
/*1359:*/
#line 16021 "./marpa.w"

static const char*yim_tag_safe(char*buffer,YIM yim)UNUSED;
static const char*yim_tag(YIM yim)UNUSED;
/*:1359*//*1361:*/
#line 16046 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1361*//*1363:*/
#line 16072 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1363*//*1365:*/
#line 16104 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AIM aim)UNUSED;
static const char*aim_tag(AIM aim)UNUSED;
/*:1365*/
#line 16175 "./marpa.w"

/*1360:*/
#line 16025 "./marpa.w"

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

/*:1360*//*1362:*/
#line 16051 "./marpa.w"

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

/*:1362*//*1364:*/
#line 16076 "./marpa.w"

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

/*:1364*//*1366:*/
#line 16107 "./marpa.w"

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

/*:1366*/
#line 16176 "./marpa.w"

#endif
/*1358:*/
#line 16013 "./marpa.w"

int(*marpa__debug_handler)(const char*,...)= 
marpa__default_debug_handler;
int marpa__debug_level= 0;

/*:1358*/
#line 16178 "./marpa.w"

/*40:*/
#line 591 "./marpa.w"

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

/*:40*//*41:*/
#line 609 "./marpa.w"

Marpa_Error_Code
marpa_version(unsigned int*version)
{
*version++= MARPA_MAJOR_VERSION;
*version++= MARPA_MINOR_VERSION;
*version= MARPA_MICRO_VERSION;
return 0;
}

/*:41*//*44:*/
#line 628 "./marpa.w"

int marpa_c_init(Marpa_Config*config)
{
config->t_is_ok= I_AM_OK;
config->t_error= MARPA_ERR_NONE;
config->t_error_string= NULL;
return 0;
}

/*:44*//*45:*/
#line 637 "./marpa.w"

Marpa_Error_Code marpa_c_error(Marpa_Config*config,const char**p_error_string)
{
const Marpa_Error_Code error_code= config->t_error;
const char*error_string= config->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:45*//*50:*/
#line 663 "./marpa.w"

Marpa_Grammar marpa_g_new(Marpa_Config*configuration)
{
GRAMMAR g;
if(configuration&&configuration->t_is_ok!=I_AM_OK){
configuration->t_error= MARPA_ERR_I_AM_NOT_OK;
return NULL;
}
g= my_malloc(sizeof(struct marpa_g));

g->t_is_ok= 0;
/*53:*/
#line 682 "./marpa.w"

g->t_ref_count= 1;

/*:53*//*59:*/
#line 738 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xsy_stack,XSY);
MARPA_DSTACK_SAFE(g->t_nsy_stack);

/*:59*//*68:*/
#line 794 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xrl_stack,RULE);
MARPA_DSTACK_SAFE(g->t_irl_stack);

/*:68*//*78:*/
#line 843 "./marpa.w"

g->t_start_xsy_id= -1;
/*:78*//*82:*/
#line 877 "./marpa.w"

g->t_start_irl= NULL;
/*:82*//*86:*/
#line 894 "./marpa.w"

External_Size_of_G(g)= 0;

/*:86*//*89:*/
#line 907 "./marpa.w"

g->t_max_rule_length= 0;

/*:89*//*93:*/
#line 920 "./marpa.w"

g->t_default_rank= 0;
/*:93*//*98:*/
#line 955 "./marpa.w"

g->t_is_precomputed= 0;
/*:98*//*101:*/
#line 967 "./marpa.w"

g->t_has_cycle= 0;
/*:101*//*104:*/
#line 987 "./marpa.w"
g->t_bv_nsyid_is_terminal= NULL;

/*:104*//*106:*/
#line 999 "./marpa.w"

g->t_lbv_xsyid_is_completion_event= NULL;
g->t_lbv_xsyid_is_nulled_event= NULL;
g->t_lbv_xsyid_is_prediction_event= NULL;

/*:106*//*113:*/
#line 1037 "./marpa.w"

MARPA_DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:113*//*121:*/
#line 1107 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL);
/*:121*//*125:*/
#line 1138 "./marpa.w"

g->t_obs= marpa_obs_init;
g->t_xrl_obs= marpa_obs_init;
/*:125*//*128:*/
#line 1154 "./marpa.w"

cilar_init(&(g)->t_cilar);
/*:128*//*137:*/
#line 1202 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:137*//*463:*/
#line 4861 "./marpa.w"

g->t_AHFA_items= NULL;
/*:463*//*529:*/
#line 5385 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:529*/
#line 674 "./marpa.w"


g->t_is_ok= I_AM_OK;
return g;
}

/*:50*//*54:*/
#line 692 "./marpa.w"

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

/*:54*//*56:*/
#line 709 "./marpa.w"

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

/*:56*//*57:*/
#line 721 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
/*60:*/
#line 742 "./marpa.w"

{
MARPA_DSTACK_DESTROY(g->t_xsy_stack);
MARPA_DSTACK_DESTROY(g->t_nsy_stack);
}

/*:60*//*69:*/
#line 798 "./marpa.w"

MARPA_DSTACK_DESTROY(g->t_irl_stack);
MARPA_DSTACK_DESTROY(g->t_xrl_stack);

/*:69*//*114:*/
#line 1039 "./marpa.w"
MARPA_DSTACK_DESTROY(g->t_events);

/*:114*//*123:*/
#line 1114 "./marpa.w"

/*122:*/
#line 1109 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 1115 "./marpa.w"


/*:123*//*126:*/
#line 1141 "./marpa.w"

marpa_obs_free(g->t_obs);
marpa_obs_free(g->t_xrl_obs);

/*:126*//*129:*/
#line 1156 "./marpa.w"

cilar_destroy(&(g)->t_cilar);

/*:129*//*464:*/
#line 4863 "./marpa.w"

my_free(g->t_AHFA_items);

/*:464*//*530:*/
#line 5389 "./marpa.w"

{
if(g->t_AHFA)
{
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}
}

/*:530*/
#line 725 "./marpa.w"

my_free(g);
}

/*:57*//*62:*/
#line 750 "./marpa.w"

int marpa_g_highest_symbol_id(Marpa_Grammar g){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 752 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 753 "./marpa.w"

return XSY_Count_of_G(g)-1;
}

/*:62*//*64:*/
#line 762 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,XSY symbol)
{
const XSYID new_id= MARPA_DSTACK_LENGTH((g)->t_xsy_stack);
*MARPA_DSTACK_PUSH((g)->t_xsy_stack,XSY)= symbol;
symbol->t_symbol_id= new_id;
}

/*:64*//*65:*/
#line 774 "./marpa.w"

PRIVATE int xsy_id_is_valid(GRAMMAR g,XSYID xsy_id)
{
return!XSYID_is_Malformed(xsy_id)&&XSYID_of_G_Exists(xsy_id);
}

/*:65*//*66:*/
#line 781 "./marpa.w"

PRIVATE int nsy_is_valid(GRAMMAR g,NSYID nsyid)
{
return nsyid>=0&&nsyid<NSY_Count_of_G(g);
}

/*:66*//*73:*/
#line 805 "./marpa.w"

int marpa_g_highest_rule_id(Marpa_Grammar g){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 807 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 808 "./marpa.w"

return XRL_Count_of_G(g)-1;
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 812 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 813 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:73*//*75:*/
#line 824 "./marpa.w"

PRIVATE void
rule_add(GRAMMAR g,RULE rule)
{
const RULEID new_id= MARPA_DSTACK_LENGTH((g)->t_xrl_stack);
*MARPA_DSTACK_PUSH((g)->t_xrl_stack,RULE)= rule;
rule->t_id= new_id;
External_Size_of_G(g)+= 1+Length_of_XRL(rule);
g->t_max_rule_length= MAX(Length_of_XRL(rule),g->t_max_rule_length);
}

/*:75*//*79:*/
#line 845 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 848 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 849 "./marpa.w"

return g->t_start_xsy_id;
}
/*:79*//*80:*/
#line 858 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 861 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 862 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 863 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 864 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 865 "./marpa.w"

return g->t_start_xsy_id= xsy_id;
}

/*:80*//*94:*/
#line 922 "./marpa.w"

Marpa_Rank marpa_g_default_rank(Marpa_Grammar g)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 925 "./marpa.w"

clear_error(g);
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 927 "./marpa.w"

return Default_Rank_of_G(g);
}
/*:94*//*95:*/
#line 932 "./marpa.w"

Marpa_Rank marpa_g_default_rank_set(Marpa_Grammar g,Marpa_Rank rank)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 935 "./marpa.w"

clear_error(g);
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 937 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 938 "./marpa.w"

if(_MARPA_UNLIKELY(rank<MINIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_LOW);
return failure_indicator;
}
if(_MARPA_UNLIKELY(rank> MAXIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_HIGH);
return failure_indicator;
}
return Default_Rank_of_G(g)= rank;
}

/*:95*//*99:*/
#line 957 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 960 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 961 "./marpa.w"

return G_is_Precomputed(g);
}

/*:99*//*102:*/
#line 969 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 972 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 973 "./marpa.w"

return g->t_has_cycle;
}

/*:102*//*116:*/
#line 1049 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{

GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= 0;
}
/*:116*//*117:*/
#line 1058 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{

GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= value;
}

/*:117*//*118:*/
#line 1068 "./marpa.w"

Marpa_Event_Type
marpa_g_event(Marpa_Grammar g,Marpa_Event*public_event,
int ix)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1073 "./marpa.w"

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

/*:118*//*119:*/
#line 1093 "./marpa.w"

Marpa_Event_Type
marpa_g_event_count(Marpa_Grammar g)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1097 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1098 "./marpa.w"

return MARPA_DSTACK_LENGTH(g->t_events);
}

/*:119*//*139:*/
#line 1213 "./marpa.w"

Marpa_Error_Code marpa_g_error(Marpa_Grammar g,const char**p_error_string)
{
const Marpa_Error_Code error_code= g->t_error;
const char*error_string= g->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:139*//*140:*/
#line 1224 "./marpa.w"

Marpa_Error_Code
marpa_g_error_clear(Marpa_Grammar g)
{
clear_error(g);
return g->t_error;
}

/*:140*//*146:*/
#line 1254 "./marpa.w"

PRIVATE XSY
symbol_new(GRAMMAR g)
{
XSY xsy= marpa_obs_new(g->t_obs,struct s_xsy,1);
/*149:*/
#line 1274 "./marpa.w"
xsy->t_is_start= 0;
/*:149*//*152:*/
#line 1288 "./marpa.w"

xsy->t_rank= Default_Rank_of_G(g);
/*:152*//*156:*/
#line 1334 "./marpa.w"

XSY_is_LHS(xsy)= 0;

/*:156*//*158:*/
#line 1341 "./marpa.w"

XSY_is_Sequence_LHS(xsy)= 0;

/*:158*//*160:*/
#line 1357 "./marpa.w"

XSY_is_Valued(xsy)= 0;
XSY_is_Valued_Locked(xsy)= 0;

/*:160*//*164:*/
#line 1399 "./marpa.w"

xsy->t_is_accessible= 0;
/*:164*//*167:*/
#line 1420 "./marpa.w"

xsy->t_is_counted= 0;
/*:167*//*170:*/
#line 1436 "./marpa.w"

xsy->t_is_nulling= 0;
/*:170*//*173:*/
#line 1453 "./marpa.w"

xsy->t_is_nullable= 0;
/*:173*//*176:*/
#line 1476 "./marpa.w"

xsy->t_is_terminal= 0;
xsy->t_is_locked_terminal= 0;
/*:176*//*181:*/
#line 1521 "./marpa.w"

xsy->t_is_productive= 0;
/*:181*//*184:*/
#line 1540 "./marpa.w"

xsy->t_is_completion_event= 0;
/*:184*//*188:*/
#line 1575 "./marpa.w"

xsy->t_is_nulled_event= 0;
/*:188*//*192:*/
#line 1610 "./marpa.w"

xsy->t_is_prediction_event= 0;
/*:192*//*197:*/
#line 1658 "./marpa.w"

Nulled_XSYIDs_of_XSY(xsy)= NULL;

/*:197*//*200:*/
#line 1674 "./marpa.w"
NSY_of_XSY(xsy)= NULL;
/*:200*//*204:*/
#line 1706 "./marpa.w"
Nulling_NSY_of_XSY(xsy)= NULL;
/*:204*/
#line 1259 "./marpa.w"

symbol_add(g,xsy);
return xsy;
}

/*:146*//*147:*/
#line 1264 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const XSY symbol= symbol_new(g);
return ID_of_XSY(symbol);
}

/*:147*//*150:*/
#line 1275 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1278 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1279 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1280 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1281 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_start;
}

/*:150*//*153:*/
#line 1291 "./marpa.w"

int marpa_g_symbol_rank(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1296 "./marpa.w"

clear_error(g);
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1298 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1299 "./marpa.w"

/*1331:*/
#line 15795 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1331*/
#line 1300 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
return Rank_of_XSY(xsy);
}
/*:153*//*154:*/
#line 1304 "./marpa.w"

int marpa_g_symbol_rank_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,Marpa_Rank rank)
{
XSY xsy;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1309 "./marpa.w"

clear_error(g);
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1311 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 1312 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1313 "./marpa.w"

/*1331:*/
#line 15795 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1331*/
#line 1314 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(rank<MINIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_LOW);
return failure_indicator;
}
if(_MARPA_UNLIKELY(rank> MAXIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_HIGH);
return failure_indicator;
}
return Rank_of_XSY(xsy)= rank;
}

/*:154*//*161:*/
#line 1361 "./marpa.w"

int marpa_g_symbol_is_valued(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1366 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1367 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1368 "./marpa.w"

return XSY_is_Valued(XSY_by_ID(xsy_id));
}

/*:161*//*162:*/
#line 1372 "./marpa.w"

int marpa_g_symbol_is_valued_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1377 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1378 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1379 "./marpa.w"

symbol= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
if(_MARPA_UNLIKELY(XSY_is_Valued_Locked(symbol)
&&value!=XSY_is_Valued(symbol)))
{
MARPA_ERROR(MARPA_ERR_VALUED_IS_LOCKED);
return failure_indicator;
}
XSY_is_Valued(symbol)= Boolean(value);
return value;
}

/*:162*//*165:*/
#line 1407 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1410 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1411 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 1412 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1413 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1414 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(xsy_id));
}

/*:165*//*168:*/
#line 1422 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1426 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1427 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1428 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1429 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_counted;
}

/*:168*//*171:*/
#line 1438 "./marpa.w"

int marpa_g_symbol_is_nulling(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1441 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1442 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 1443 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1444 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1445 "./marpa.w"

return XSY_is_Nulling(XSY_by_ID(xsy_id));
}

/*:171*//*174:*/
#line 1455 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1458 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1459 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 1460 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1461 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1462 "./marpa.w"

return XSYID_is_Nullable(xsy_id);
}

/*:174*//*178:*/
#line 1482 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1486 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1487 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1488 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1489 "./marpa.w"

return XSYID_is_Terminal(xsy_id);
}
/*:178*//*179:*/
#line 1492 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1497 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1498 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 1499 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1500 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1501 "./marpa.w"

symbol= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
if(_MARPA_UNLIKELY(XSY_is_Locked_Terminal(symbol))
&&XSY_is_Terminal(symbol)!=value)
{
MARPA_ERROR(MARPA_ERR_TERMINAL_IS_LOCKED);
return failure_indicator;
}
XSY_is_Locked_Terminal(symbol)= 1;
return XSY_is_Terminal(symbol)= Boolean(value);
}

/*:179*//*182:*/
#line 1523 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1528 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1529 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 1530 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1531 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1532 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(xsy_id));
}

/*:182*//*185:*/
#line 1542 "./marpa.w"

int marpa_g_symbol_is_completion_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1546 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1547 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1548 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1549 "./marpa.w"

return XSYID_is_Completion_Event(xsy_id);
}
/*:185*//*186:*/
#line 1552 "./marpa.w"

int marpa_g_symbol_is_completion_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1557 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1558 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 1559 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1560 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1561 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Completion_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:186*//*189:*/
#line 1577 "./marpa.w"

int marpa_g_symbol_is_nulled_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1581 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1582 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1583 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1584 "./marpa.w"

return XSYID_is_Nulled_Event(xsy_id);
}
/*:189*//*190:*/
#line 1587 "./marpa.w"

int marpa_g_symbol_is_nulled_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1592 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1593 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 1594 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1595 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1596 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Nulled_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:190*//*193:*/
#line 1612 "./marpa.w"

int marpa_g_symbol_is_prediction_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1616 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1617 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1618 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1619 "./marpa.w"

return XSYID_is_Prediction_Event(xsy_id);
}
/*:193*//*194:*/
#line 1622 "./marpa.w"

int marpa_g_symbol_is_prediction_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1627 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1628 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 1629 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1630 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1631 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Prediction_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:194*//*195:*/
#line 1641 "./marpa.w"

/*:195*//*201:*/
#line 1675 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1682 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1683 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1684 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:201*//*205:*/
#line 1707 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nulling_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1714 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 1715 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 1716 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= Nulling_NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:205*//*207:*/
#line 1728 "./marpa.w"

PRIVATE
NSY symbol_alias_create(GRAMMAR g,XSY symbol)
{
NSY alias_nsy= semantic_nsy_new(g,symbol);
XSY_is_Nulling(symbol)= 0;
XSY_is_Nullable(symbol)= 1;
NSY_is_Nulling(alias_nsy)= 1;
return alias_nsy;
}

/*:207*//*214:*/
#line 1777 "./marpa.w"

PRIVATE NSY
nsy_start(GRAMMAR g)
{
const NSY nsy= marpa_obs_new(g->t_obs,struct s_nsy,1);
ID_of_NSY(nsy)= MARPA_DSTACK_LENGTH((g)->t_nsy_stack);
*MARPA_DSTACK_PUSH((g)->t_nsy_stack,NSY)= nsy;
/*212:*/
#line 1772 "./marpa.w"

nsy->t_or_node_type= NULLING_TOKEN_OR_NODE;

/*:212*//*222:*/
#line 1845 "./marpa.w"
NSY_is_Start(nsy)= 0;
/*:222*//*225:*/
#line 1859 "./marpa.w"
NSY_is_LHS(nsy)= 0;
/*:225*//*228:*/
#line 1873 "./marpa.w"
NSY_is_Nulling(nsy)= 0;
/*:228*//*231:*/
#line 1890 "./marpa.w"
NSY_is_Semantic(nsy)= 0;
/*:231*//*234:*/
#line 1911 "./marpa.w"
Source_XSY_of_NSY(nsy)= NULL;
/*:234*//*238:*/
#line 1936 "./marpa.w"

LHS_XRL_of_NSY(nsy)= NULL;
XRL_Offset_of_NSY(nsy)= -1;

/*:238*//*243:*/
#line 1987 "./marpa.w"

Rank_of_NSY(nsy)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:243*/
#line 1784 "./marpa.w"

return nsy;
}

/*:214*//*215:*/
#line 1790 "./marpa.w"

PRIVATE NSY
nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_start(g);
Source_XSY_of_NSY(new_nsy)= source;
Rank_of_NSY(new_nsy)= NSY_Rank_by_XSY(source);
return new_nsy;
}

/*:215*//*216:*/
#line 1802 "./marpa.w"

PRIVATE NSY
semantic_nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_new(g,source);
NSY_is_Semantic(new_nsy)= 1;
return new_nsy;
}

/*:216*//*217:*/
#line 1813 "./marpa.w"

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

/*:217*//*220:*/
#line 1835 "./marpa.w"

int _marpa_g_nsy_count(Marpa_Grammar g){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1837 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1838 "./marpa.w"

return NSY_Count_of_G(g);
}

/*:220*//*223:*/
#line 1846 "./marpa.w"

int _marpa_g_nsy_is_start(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1849 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1850 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 1851 "./marpa.w"

/*1332:*/
#line 15800 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1332*/
#line 1852 "./marpa.w"

return NSY_is_Start(NSY_by_ID(nsy_id));
}

/*:223*//*226:*/
#line 1860 "./marpa.w"

int _marpa_g_nsy_is_lhs(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1863 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1864 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 1865 "./marpa.w"

/*1332:*/
#line 15800 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1332*/
#line 1866 "./marpa.w"

return NSY_is_LHS(NSY_by_ID(nsy_id));
}

/*:226*//*229:*/
#line 1874 "./marpa.w"

int _marpa_g_nsy_is_nulling(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1877 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 1878 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 1879 "./marpa.w"

/*1332:*/
#line 15800 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1332*/
#line 1880 "./marpa.w"

return NSY_is_Nulling(NSY_by_ID(nsy_id));
}

/*:229*//*232:*/
#line 1891 "./marpa.w"

int _marpa_g_nsy_is_semantic(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1896 "./marpa.w"

/*1332:*/
#line 15800 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1332*/
#line 1897 "./marpa.w"

return NSYID_is_Semantic(nsy_id);
}

/*:232*//*235:*/
#line 1912 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
XSY source_xsy;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1918 "./marpa.w"

/*1332:*/
#line 15800 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1332*/
#line 1919 "./marpa.w"

source_xsy= Source_XSY_of_NSYID(nsy_id);
return ID_of_XSY(source_xsy);
}

/*:235*//*240:*/
#line 1947 "./marpa.w"

Marpa_Rule_ID _marpa_g_nsy_lhs_xrl(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1950 "./marpa.w"

/*1332:*/
#line 15800 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1332*/
#line 1951 "./marpa.w"

{
const NSY nsy= NSY_by_ID(nsy_id);
const XRL lhs_xrl= LHS_XRL_of_NSY(nsy);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:240*//*241:*/
#line 1971 "./marpa.w"

int _marpa_g_nsy_xrl_offset(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1974 "./marpa.w"

NSY nsy;
/*1332:*/
#line 15800 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1332*/
#line 1976 "./marpa.w"

nsy= NSY_by_ID(nsy_id);
return XRL_Offset_of_NSY(nsy);
}

/*:241*//*244:*/
#line 1989 "./marpa.w"

Marpa_Rank _marpa_g_nsy_rank(
Marpa_Grammar g,
Marpa_NSY_ID nsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 1994 "./marpa.w"

/*1332:*/
#line 15800 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1332*/
#line 1995 "./marpa.w"

return Rank_of_NSY(NSY_by_ID(nsy_id));
}

/*:244*//*250:*/
#line 2030 "./marpa.w"

PRIVATE
XRL xrl_start(GRAMMAR g,const XSYID lhs,const XSYID*rhs,int length)
{
XRL xrl;
const size_t sizeof_xrl= offsetof(struct s_xrl,t_symbols)+
((size_t)length+1)*sizeof(xrl->t_symbols[0]);
xrl= marpa_obs_start(g->t_xrl_obs,sizeof_xrl,ALIGNOF(XRL));
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
/*269:*/
#line 2375 "./marpa.w"

rule->t_rank= Default_Rank_of_G(g);
/*:269*//*273:*/
#line 2423 "./marpa.w"

rule->t_null_ranks_high= 0;
/*:273*//*277:*/
#line 2463 "./marpa.w"

rule->t_is_bnf= 0;

/*:277*//*279:*/
#line 2469 "./marpa.w"

rule->t_is_sequence= 0;

/*:279*//*281:*/
#line 2483 "./marpa.w"

rule->t_minimum= -1;
/*:281*//*284:*/
#line 2508 "./marpa.w"

Separator_of_XRL(rule)= -1;
/*:284*//*289:*/
#line 2541 "./marpa.w"

rule->t_is_discard= 0;
/*:289*//*293:*/
#line 2581 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:293*//*297:*/
#line 2602 "./marpa.w"

rule->t_is_loop= 0;
/*:297*//*300:*/
#line 2619 "./marpa.w"

XRL_is_Nulling(rule)= 0;
/*:300*//*303:*/
#line 2637 "./marpa.w"

XRL_is_Nullable(rule)= 0;
/*:303*//*307:*/
#line 2655 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:307*//*310:*/
#line 2673 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:310*//*313:*/
#line 2692 "./marpa.w"

XRL_is_Used(rule)= 0;
/*:313*/
#line 2054 "./marpa.w"

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

/*:250*//*251:*/
#line 2070 "./marpa.w"

PRIVATE IRL
irl_start(GRAMMAR g,int length)
{
IRL irl;
const size_t sizeof_irl= offsetof(struct s_irl,t_nsyid_array)+
((size_t)length+1)*sizeof(irl->t_nsyid_array[0]);


irl= marpa__obs_alloc(g->t_obs,sizeof_irl,ALIGNOF(IRL_Object));

ID_of_IRL(irl)= MARPA_DSTACK_LENGTH((g)->t_irl_stack);
Length_of_IRL(irl)= length;
/*333:*/
#line 2822 "./marpa.w"

IRL_has_Virtual_LHS(irl)= 0;
/*:333*//*336:*/
#line 2838 "./marpa.w"

IRL_has_Virtual_RHS(irl)= 0;
/*:336*//*339:*/
#line 2854 "./marpa.w"

IRL_is_Right_Recursive(irl)= 0;

/*:339*//*342:*/
#line 2865 "./marpa.w"
Real_SYM_Count_of_IRL(irl)= 0;
/*:342*//*345:*/
#line 2883 "./marpa.w"
irl->t_virtual_start= -1;
/*:345*//*348:*/
#line 2903 "./marpa.w"
irl->t_virtual_end= -1;
/*:348*//*351:*/
#line 2925 "./marpa.w"
Source_XRL_of_IRL(irl)= NULL;
/*:351*//*354:*/
#line 2952 "./marpa.w"

Rank_of_IRL(irl)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:354*//*357:*/
#line 2973 "./marpa.w"

First_AIM_of_IRL(irl)= NULL;

/*:357*//*361:*/
#line 2992 "./marpa.w"

Last_Proper_SYMI_of_IRL(irl)= -1;
/*:361*/
#line 2083 "./marpa.w"

*MARPA_DSTACK_PUSH((g)->t_irl_stack,IRL)= irl;
return irl;
}

PRIVATE void
irl_finish(GRAMMAR g,IRL irl)
{
const NSY lhs_nsy= LHS_of_IRL(irl);
NSY_is_LHS(lhs_nsy)= 1;
}

/*:251*//*253:*/
#line 2109 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,int length)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2114 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2117 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 2118 "./marpa.w"

if(_MARPA_UNLIKELY(length> MAX_RHS_LENGTH))
{
MARPA_ERROR(MARPA_ERR_RHS_TOO_LONG);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
{
int rh_index;
for(rh_index= 0;rh_index<length;rh_index++)
{
const XSYID rhs_id= rhs_ids[rh_index];
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
}
}
{
const XSY lhs= XSY_by_ID(lhs_id);
if(_MARPA_UNLIKELY(XSY_is_Sequence_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
return failure_indicator;
}
}
rule= xrl_start(g,lhs_id,rhs_ids,length);
if(_MARPA_UNLIKELY(_marpa_avl_insert(g->t_xrl_tree,rule)!=NULL))
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

/*:253*//*254:*/
#line 2163 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2170 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2171 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 2172 "./marpa.w"

/*256:*/
#line 2203 "./marpa.w"

{
if(separator_id!=-1)
{
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,separator_id)))
{
MARPA_ERROR(MARPA_ERR_BAD_SEPARATOR);
goto FAILURE;
}
}
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
goto FAILURE;
}
{
const XSY lhs= XSY_by_ID(lhs_id);
if(_MARPA_UNLIKELY(XSY_is_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
goto FAILURE;
}
}
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
goto FAILURE;
}
}

/*:256*/
#line 2173 "./marpa.w"

/*255:*/
#line 2181 "./marpa.w"

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

/*:255*/
#line 2174 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:254*//*258:*/
#line 2256 "./marpa.w"

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

/*:258*//*261:*/
#line 2311 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:261*//*262:*/
#line 2315 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2317 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2318 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2319 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2320 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:262*//*263:*/
#line 2323 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:263*//*264:*/
#line 2327 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2330 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2331 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2332 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2333 "./marpa.w"

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

/*:264*//*265:*/
#line 2346 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2348 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2349 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2350 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2351 "./marpa.w"

return Length_of_XRL(XRL_by_ID(xrl_id));
}

/*:265*//*270:*/
#line 2378 "./marpa.w"

int marpa_g_rule_rank(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2383 "./marpa.w"

clear_error(g);
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2385 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2386 "./marpa.w"

/*1335:*/
#line 15818 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1335*/
#line 2387 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Rank_of_XRL(xrl);
}
/*:270*//*271:*/
#line 2391 "./marpa.w"

int marpa_g_rule_rank_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,Marpa_Rank rank)
{
XRL xrl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2396 "./marpa.w"

clear_error(g);
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2398 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 2399 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2400 "./marpa.w"

/*1335:*/
#line 15818 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1335*/
#line 2401 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(_MARPA_UNLIKELY(rank<MINIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_LOW);
return failure_indicator;
}
if(_MARPA_UNLIKELY(rank> MAXIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_HIGH);
return failure_indicator;
}
return Rank_of_XRL(xrl)= rank;
}

/*:271*//*274:*/
#line 2427 "./marpa.w"

int marpa_g_rule_null_high(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2432 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2433 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2434 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2435 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Null_Ranks_High_of_RULE(xrl);
}
/*:274*//*275:*/
#line 2439 "./marpa.w"

int marpa_g_rule_null_high_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,int flag)
{
XRL xrl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2444 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2445 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 2446 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2447 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2448 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(_MARPA_UNLIKELY(flag<0||flag> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return Null_Ranks_High_of_RULE(xrl)= Boolean(flag);
}

/*:275*//*282:*/
#line 2485 "./marpa.w"

int marpa_g_sequence_min(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2490 "./marpa.w"

XRL xrl;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2492 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2493 "./marpa.w"

/*1335:*/
#line 15818 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1335*/
#line 2494 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Minimum_of_XRL(xrl);
}

/*:282*//*285:*/
#line 2510 "./marpa.w"

Marpa_Symbol_ID marpa_g_sequence_separator(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2515 "./marpa.w"

XRL xrl;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2517 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2518 "./marpa.w"

/*1335:*/
#line 15818 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1335*/
#line 2519 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Separator_of_XRL(xrl);
}

/*:285*//*290:*/
#line 2543 "./marpa.w"

int _marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2548 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2549 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2550 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2551 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:290*//*294:*/
#line 2583 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2588 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2589 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2590 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2591 "./marpa.w"

return!XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:294*//*298:*/
#line 2604 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2607 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2608 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2609 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2610 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 2611 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:298*//*301:*/
#line 2621 "./marpa.w"

int marpa_g_rule_is_nulling(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2624 "./marpa.w"

XRL xrl;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2626 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2627 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2628 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nulling(xrl);
}

/*:301*//*304:*/
#line 2639 "./marpa.w"

int marpa_g_rule_is_nullable(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2642 "./marpa.w"

XRL xrl;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2644 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2645 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2646 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nullable(xrl);
}

/*:304*//*308:*/
#line 2657 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2660 "./marpa.w"

XRL xrl;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2662 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2663 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2664 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:308*//*311:*/
#line 2675 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2678 "./marpa.w"

XRL xrl;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2680 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2681 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2682 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:311*//*314:*/
#line 2694 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2698 "./marpa.w"

/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 2699 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 2700 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:314*//*316:*/
#line 2707 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2712 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2713 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:316*//*325:*/
#line 2754 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
IRL irl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2757 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2758 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 2759 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2760 "./marpa.w"

irl= IRL_by_ID(irl_id);
return LHSID_of_IRL(irl);
}

/*:325*//*327:*/
#line 2767 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_rhs(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2770 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2771 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 2772 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2773 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHSID_of_IRL(irl,ix);
}

/*:327*//*329:*/
#line 2781 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2783 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 2784 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 2785 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2786 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}

/*:329*//*334:*/
#line 2824 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2829 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 2830 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2831 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:334*//*337:*/
#line 2840 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2845 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 2846 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2847 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:337*//*343:*/
#line 2866 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2871 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 2872 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2873 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:343*//*346:*/
#line 2884 "./marpa.w"

int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2890 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 2891 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2892 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:346*//*349:*/
#line 2904 "./marpa.w"

int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2910 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 2911 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2912 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:349*//*352:*/
#line 2926 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2932 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2933 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:352*//*355:*/
#line 2954 "./marpa.w"

Marpa_Rank _marpa_g_irl_rank(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 2959 "./marpa.w"

/*1333:*/
#line 15805 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1333*/
#line 2960 "./marpa.w"

return Rank_of_IRL(IRL_by_ID(irl_id));
}

/*:355*//*363:*/
#line 3006 "./marpa.w"

PRIVATE int
symbol_instance_of_ahfa_item_get(AIM aim)
{
if(!AIM_is_Prediction(aim)){
const IRL irl= IRL_of_AIM(aim);
return SYMI_of_IRL(irl)+Position_of_AIM(aim-1);
}
return-1;
}

/*:363*//*365:*/
#line 3034 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 3037 "./marpa.w"

int return_value= failure_indicator;
struct marpa_obstack*obs_precompute= marpa_obs_init;
/*368:*/
#line 3141 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);

/*:368*//*372:*/
#line 3174 "./marpa.w"

XSYID start_xsy_id= g->t_start_xsy_id;

/*:372*//*384:*/
#line 3466 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:384*/
#line 3040 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 3041 "./marpa.w"

G_EVENTS_CLEAR(g);
/*369:*/
#line 3145 "./marpa.w"

if(_MARPA_UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
goto FAILURE;
}

/*:369*/
#line 3043 "./marpa.w"

/*1327:*/
#line 15772 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1327*/
#line 3044 "./marpa.w"

/*371:*/
#line 3155 "./marpa.w"

{
if(_MARPA_UNLIKELY(start_xsy_id<0))
{
MARPA_ERROR(MARPA_ERR_NO_START_SYMBOL);
goto FAILURE;
}
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_START_SYMBOL);
goto FAILURE;
}
if(_MARPA_UNLIKELY(!XSY_is_LHS(XSY_by_ID(start_xsy_id))))
{
MARPA_ERROR(MARPA_ERR_START_NOT_LHS);
goto FAILURE;
}
}

/*:371*/
#line 3045 "./marpa.w"




/*122:*/
#line 1109 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 3049 "./marpa.w"


{
/*377:*/
#line 3348 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:377*//*378:*/
#line 3351 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;
RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:378*//*382:*/
#line 3412 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:382*/
#line 3052 "./marpa.w"

/*367:*/
#line 3124 "./marpa.w"

{
/*375:*/
#line 3198 "./marpa.w"

{
Marpa_Rule_ID rule_id;


const MARPA_AVL_TREE rhs_avl_tree= _marpa_avl_create(sym_rule_cmp,NULL);


struct sym_rule_pair*const p_rh_sym_rule_pair_base= 
marpa_obs_new(MARPA_AVL_OBSTACK(rhs_avl_tree),struct sym_rule_pair,
(size_t)External_Size_of_G(g));
struct sym_rule_pair*p_rh_sym_rule_pairs= p_rh_sym_rule_pair_base;


const MARPA_AVL_TREE lhs_avl_tree= _marpa_avl_create(sym_rule_cmp,NULL);
struct sym_rule_pair*const p_lh_sym_rule_pair_base= 
marpa_obs_new(MARPA_AVL_OBSTACK(lhs_avl_tree),struct sym_rule_pair,
(size_t)xrl_count);
struct sym_rule_pair*p_lh_sym_rule_pairs= p_lh_sym_rule_pair_base;

lhs_v= bv_obs_create(obs_precompute,pre_census_xsy_count);
empty_lhs_v= bv_obs_shadow(obs_precompute,lhs_v);
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
const XRL rule= XRL_by_ID(rule_id);
const Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
const int rule_length= Length_of_XRL(rule);
const int is_sequence= XRL_is_Sequence(rule);

bv_bit_set(lhs_v,lhs_id);


p_lh_sym_rule_pairs->t_symid= lhs_id;
p_lh_sym_rule_pairs->t_ruleid= rule_id;
_marpa_avl_insert(lhs_avl_tree,p_lh_sym_rule_pairs);
p_lh_sym_rule_pairs++;

if(is_sequence)
{
const XSYID separator_id= Separator_of_XRL(rule);
if(Minimum_of_XRL(rule)<=0)
{
bv_bit_set(empty_lhs_v,lhs_id);
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
bv_bit_set(empty_lhs_v,lhs_id);
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
marpa_obs_new(obs_precompute,RULEID,(size_t)External_Size_of_G(g));
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(rhs_avl_tree);

xrl_list_x_rh_sym= 
marpa_obs_new(obs_precompute,RULEID*,(size_t)pre_census_xsy_count+1);
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
marpa_obs_new(obs_precompute,RULEID,(size_t)xrl_count);
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(lhs_avl_tree);

xrl_list_x_lh_sym= 
marpa_obs_new(obs_precompute,RULEID*,(size_t)pre_census_xsy_count+1);
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

/*:375*/
#line 3126 "./marpa.w"

/*376:*/
#line 3319 "./marpa.w"

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
bv_bit_set(terminal_v,symid);
continue;
}
bv_bit_clear(terminal_v,symid);
continue;
}



if(bv_bit_test(terminal_v,symid))
XSY_is_Terminal(symbol)= 1;
}
}

/*:376*/
#line 3127 "./marpa.w"

/*383:*/
#line 3434 "./marpa.w"

{
XRLID rule_id;
reach_matrix= 
matrix_obs_create(obs_precompute,pre_census_xsy_count,
pre_census_xsy_count);
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule= XRL_by_ID(rule_id);
XSYID lhs_id= LHS_ID_of_RULE(rule);
int rhs_ix;
int rule_length= Length_of_XRL(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
matrix_bit_set(reach_matrix,
lhs_id,
RHS_ID_of_RULE(rule,rhs_ix));
}
if(XRL_is_Sequence(rule))
{
const XSYID separator_id= Separator_of_XRL(rule);
if(separator_id>=0)
{
matrix_bit_set(reach_matrix,
lhs_id,
separator_id);
}
}
}
transitive_closure(reach_matrix);
}

/*:383*/
#line 3128 "./marpa.w"

/*379:*/
#line 3357 "./marpa.w"

{
int min,max,start;
XSYID xsy_id;
int counted_nullables= 0;
nullable_v= bv_obs_clone(obs_precompute,empty_lhs_v);
rhs_closure(g,nullable_v,xrl_list_x_rh_sym);
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2)
{
for(xsy_id= min;xsy_id<=max;
xsy_id++)
{
XSY xsy= XSY_by_ID(xsy_id);
XSY_is_Nullable(xsy)= 1;
if(_MARPA_UNLIKELY(xsy->t_is_counted))
{
counted_nullables++;
int_event_new(g,MARPA_EVENT_COUNTED_NULLABLE,xsy_id);
}
}
}
if(_MARPA_UNLIKELY(counted_nullables))
{
MARPA_ERROR(MARPA_ERR_COUNTED_NULLABLE);
goto FAILURE;
}
}

/*:379*/
#line 3129 "./marpa.w"

/*380:*/
#line 3385 "./marpa.w"

{
productive_v= bv_obs_shadow(obs_precompute,nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v,xrl_list_x_rh_sym);
{
int min,max,start;
XSYID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);
start= max+2)
{
for(symid= min;
symid<=max;symid++)
{
XSY symbol= XSY_by_ID(symid);
symbol->t_is_productive= 1;
}
}
}
}

/*:380*/
#line 3130 "./marpa.w"

/*381:*/
#line 3406 "./marpa.w"

if(_MARPA_UNLIKELY(!bv_bit_test(productive_v,start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:381*/
#line 3131 "./marpa.w"

/*385:*/
#line 3471 "./marpa.w"

{
Bit_Vector accessible_v= 
matrix_row(reach_matrix,start_xsy_id);
int min,max,start;
XSYID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2)
{
for(symid= min;
symid<=max;symid++)
{
XSY symbol= XSY_by_ID(symid);
symbol->t_is_accessible= 1;
}
}
XSY_by_ID(start_xsy_id)->t_is_accessible= 1;
}

/*:385*/
#line 3132 "./marpa.w"

/*386:*/
#line 3491 "./marpa.w"

{
Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
int nulling_terminal_found= 0;
int min,max,start;
for(start= 0;bv_scan(lhs_v,start,&min,&max);start= max+2)
{
XSYID productive_id;
for(productive_id= min;
productive_id<=max;productive_id++)
{
bv_and(reaches_terminal_v,terminal_v,
matrix_row(reach_matrix,productive_id));
if(bv_is_empty(reaches_terminal_v))
{
const XSY symbol= XSY_by_ID(productive_id);
XSY_is_Nulling(symbol)= 1;
if(_MARPA_UNLIKELY(XSY_is_Terminal(symbol)))
{
nulling_terminal_found= 1;
int_event_new(g,MARPA_EVENT_NULLING_TERMINAL,
productive_id);
}
}
}
}
bv_free(reaches_terminal_v);
if(_MARPA_UNLIKELY(nulling_terminal_found))
{
MARPA_ERROR(MARPA_ERR_NULLING_TERMINAL);
goto FAILURE;
}
}

/*:386*/
#line 3133 "./marpa.w"

/*387:*/
#line 3530 "./marpa.w"

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
/*389:*/
#line 3581 "./marpa.w"

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



if(_MARPA_UNLIKELY(!XSY_is_Productive(separator_xsy)))
{
XRL_is_Productive(xrl)= XRL_is_Nullable(xrl);


XRL_is_Used(xrl)= 0;
}
}


if(XRL_is_Nulling(xrl))XRL_is_Used(xrl)= 0;
}

/*:389*/
#line 3541 "./marpa.w"

continue;
}
/*388:*/
#line 3550 "./marpa.w"

{
int rh_ix;
int is_nulling= 1;
int is_nullable= 1;
int is_productive= 1;
for(rh_ix= 0;rh_ix<Length_of_XRL(xrl);rh_ix++)
{
const XSYID rhs_id= RHS_ID_of_XRL(xrl,rh_ix);
const XSY rh_xsy= XSY_by_ID(rhs_id);
if(_MARPA_LIKELY(!XSY_is_Nulling(rh_xsy)))
is_nulling= 0;
if(_MARPA_LIKELY(!XSY_is_Nullable(rh_xsy)))
is_nullable= 0;
if(_MARPA_UNLIKELY(!XSY_is_Productive(rh_xsy)))
is_productive= 0;
}
XRL_is_Nulling(xrl)= Boolean(is_nulling);
XRL_is_Nullable(xrl)= Boolean(is_nullable);
XRL_is_Productive(xrl)= Boolean(is_productive);
XRL_is_Used(xrl)= XRL_is_Accessible(xrl)&&XRL_is_Productive(xrl)
&&!XRL_is_Nulling(xrl);
}

/*:388*/
#line 3544 "./marpa.w"

}
}

/*:387*/
#line 3134 "./marpa.w"

/*390:*/
#line 3636 "./marpa.w"

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

/*:390*/
#line 3135 "./marpa.w"

if(1){
/*391:*/
#line 3664 "./marpa.w"

{
XSYID xsyid;
XRLID xrlid;
int nullable_xsy_count= 0;

void*matrix_buffer= my_malloc(matrix_sizeof(
pre_census_xsy_count,
pre_census_xsy_count));

Bit_Matrix nullification_matrix= 
matrix_buffer_create(matrix_buffer,pre_census_xsy_count,
pre_census_xsy_count);
for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++)
{
if(!XSYID_is_Nullable(xsyid))
continue;
nullable_xsy_count++;
matrix_bit_set(nullification_matrix,xsyid,
xsyid);
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
matrix_bit_set(nullification_matrix,lhs_id,
rhs_id);
}
}
}
transitive_closure(nullification_matrix);
for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++)
{
Bit_Vector bv_nullifications_by_to_xsy= 
matrix_row(nullification_matrix,xsyid);
Nulled_XSYIDs_of_XSYID(xsyid)= 
cil_bv_add(&g->t_cilar,bv_nullifications_by_to_xsy);
}
my_free(matrix_buffer);
}

/*:391*/
#line 3137 "./marpa.w"

}
}

/*:367*/
#line 3053 "./marpa.w"

/*438:*/
#line 4512 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,xrl_count,
xrl_count);
/*439:*/
#line 4533 "./marpa.w"

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
/*440:*/
#line 4576 "./marpa.w"

{
RULEID*p_xrl= xrl_list_x_lh_sym[nonnulling_id];
const RULEID*p_one_past_rules= xrl_list_x_lh_sym[nonnulling_id+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{


const RULEID to_rule_id= *p_xrl;
matrix_bit_set(unit_transition_matrix,rule_id,
to_rule_id);
}
}

/*:440*/
#line 4554 "./marpa.w"

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

/*440:*/
#line 4576 "./marpa.w"

{
RULEID*p_xrl= xrl_list_x_lh_sym[nonnulling_id];
const RULEID*p_one_past_rules= xrl_list_x_lh_sym[nonnulling_id+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{


const RULEID to_rule_id= *p_xrl;
matrix_bit_set(unit_transition_matrix,rule_id,
to_rule_id);
}
}

/*:440*/
#line 4567 "./marpa.w"

}
}
}
}

/*:439*/
#line 4518 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*441:*/
#line 4590 "./marpa.w"

{
XRLID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule;
if(!matrix_bit_test
(unit_transition_matrix,rule_id,
rule_id))
continue;
loop_rule_count++;
rule= XRL_by_ID(rule_id);
rule->t_is_loop= 1;
}
}

/*:441*/
#line 4520 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:438*/
#line 3054 "./marpa.w"

}


/*564:*/
#line 5922 "./marpa.w"

MARPA_DSTACK_INIT(g->t_irl_stack,IRL,2*MARPA_DSTACK_CAPACITY(g->t_xrl_stack));

/*:564*/
#line 3058 "./marpa.w"

/*565:*/
#line 5930 "./marpa.w"

{
MARPA_DSTACK_INIT(g->t_nsy_stack,NSY,2*MARPA_DSTACK_CAPACITY(g->t_xsy_stack));
}

/*:565*/
#line 3059 "./marpa.w"

/*403:*/
#line 3859 "./marpa.w"

{
/*404:*/
#line 3890 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:404*//*407:*/
#line 3948 "./marpa.w"

int factor_count;
int*factor_positions;
/*:407*/
#line 3861 "./marpa.w"

/*408:*/
#line 3951 "./marpa.w"

factor_positions= marpa_obs_new(obs_precompute,int,g->t_max_rule_length);

/*:408*/
#line 3862 "./marpa.w"

/*405:*/
#line 3896 "./marpa.w"

{
XSYID xsy_id;
for(xsy_id= 0;xsy_id<pre_census_xsy_count;xsy_id++)
{
const XSY xsy_to_clone= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(!xsy_to_clone->t_is_accessible))
continue;
if(_MARPA_UNLIKELY(!xsy_to_clone->t_is_productive))
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

/*:405*/
#line 3863 "./marpa.w"

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
/*392:*/
#line 3712 "./marpa.w"

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
/*393:*/
#line 3741 "./marpa.w"

{
IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= lhs_nsyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);

IRL_has_Virtual_RHS(rewrite_irl)= 1;
}

/*:393*/
#line 3733 "./marpa.w"

if(separator_nsyid>=0&&!XRL_is_Proper_Separation(rule)){
/*394:*/
#line 3754 "./marpa.w"

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

/*:394*/
#line 3735 "./marpa.w"

}
/*395:*/
#line 3771 "./marpa.w"

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
/*:395*/
#line 3737 "./marpa.w"

/*396:*/
#line 3782 "./marpa.w"

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

/*:396*/
#line 3738 "./marpa.w"

}

/*:392*/
#line 3876 "./marpa.w"

continue;
}
/*406:*/
#line 3927 "./marpa.w"

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
/*:406*/
#line 3879 "./marpa.w"


if(factor_count> 0)
{
/*409:*/
#line 3955 "./marpa.w"

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
/*412:*/
#line 3991 "./marpa.w"

NSY chaf_virtual_nsy;
NSYID chaf_virtual_nsyid;
int first_factor_position= factor_positions[factor_position_ix];
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;


/*410:*/
#line 3981 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:410*/
#line 4000 "./marpa.w"

/*413:*/
#line 4019 "./marpa.w"

{
{
const int real_symbol_count= piece_end-piece_start+1;
/*418:*/
#line 4117 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4131 "./marpa.w"

}

/*:418*/
#line 4023 "./marpa.w"
;
}
/*414:*/
#line 4033 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4055 "./marpa.w"

}

/*:414*/
#line 4025 "./marpa.w"
;
{
const int real_symbol_count= piece_end-piece_start+1;
/*420:*/
#line 4163 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4187 "./marpa.w"

}

/*:420*/
#line 4028 "./marpa.w"
;
}
/*415:*/
#line 4063 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4101 "./marpa.w"

}
}

/*:415*/
#line 4030 "./marpa.w"
;
}

/*:413*/
#line 4001 "./marpa.w"

factor_position_ix++;
}else{
piece_end= second_factor_position;
/*410:*/
#line 3981 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:410*/
#line 4005 "./marpa.w"

/*417:*/
#line 4107 "./marpa.w"

{
const int real_symbol_count= piece_end-piece_start+1;
/*418:*/
#line 4117 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4131 "./marpa.w"

}

/*:418*/
#line 4110 "./marpa.w"

/*419:*/
#line 4135 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4159 "./marpa.w"

}

/*:419*/
#line 4111 "./marpa.w"

/*420:*/
#line 4163 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4187 "./marpa.w"

}

/*:420*/
#line 4112 "./marpa.w"

/*421:*/
#line 4191 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4225 "./marpa.w"

}

/*:421*/
#line 4113 "./marpa.w"

}

/*:417*/
#line 4006 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_nsy= chaf_virtual_nsy;
current_lhs_nsyid= chaf_virtual_nsyid;
piece_start= piece_end+1;

/*:412*/
#line 3972 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*422:*/
#line 4230 "./marpa.w"

{
const int first_factor_position= factor_positions[factor_position_ix];
const int second_factor_position= factor_positions[factor_position_ix+1];
const int real_symbol_count= Length_of_XRL(rule)-piece_start;
piece_end= Length_of_XRL(rule)-1;
/*423:*/
#line 4243 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4256 "./marpa.w"

}

/*:423*/
#line 4236 "./marpa.w"

/*424:*/
#line 4260 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4283 "./marpa.w"

}

/*:424*/
#line 4237 "./marpa.w"

/*425:*/
#line 4287 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4310 "./marpa.w"

}

/*:425*/
#line 4238 "./marpa.w"

/*426:*/
#line 4315 "./marpa.w"

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
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}

irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4352 "./marpa.w"

}
}

/*:426*/
#line 4239 "./marpa.w"

}

/*:422*/
#line 3975 "./marpa.w"

}else{
/*427:*/
#line 4357 "./marpa.w"

{
int real_symbol_count;
const int first_factor_position= factor_positions[factor_position_ix];
piece_end= Length_of_XRL(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*428:*/
#line 4368 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4381 "./marpa.w"

}

/*:428*/
#line 4363 "./marpa.w"

/*429:*/
#line 4386 "./marpa.w"

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
/*430:*/
#line 4420 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:430*/
#line 4412 "./marpa.w"

}
}

/*:429*/
#line 4364 "./marpa.w"

}

/*:427*/
#line 3977 "./marpa.w"

}
}

/*:409*/
#line 3883 "./marpa.w"

continue;
}
/*252:*/
#line 2095 "./marpa.w"

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

/*:252*/
#line 3886 "./marpa.w"

}
}

/*:403*/
#line 3060 "./marpa.w"

/*432:*/
#line 4437 "./marpa.w"

{
const XSY start_xsy= XSY_by_ID(start_xsy_id);
if(_MARPA_LIKELY(!XSY_is_Nulling(start_xsy))){
/*433:*/
#line 4445 "./marpa.w"
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

/*:433*/
#line 4441 "./marpa.w"

}
}

/*:432*/
#line 3061 "./marpa.w"



if(!G_is_Trivial(g)){
/*563:*/
#line 5910 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
AIM*const item_list_working_buffer
= marpa_obs_new(obs_precompute,AIM,irl_count);
const NSYID nsy_count= NSY_Count_of_G(g);
const XSYID xsy_count= XSY_Count_of_G(g);
IRLID**irl_list_x_lh_nsy= NULL;
Bit_Matrix nsy_by_right_nsy_matrix;

/*:563*/
#line 3066 "./marpa.w"

/*566:*/
#line 5935 "./marpa.w"

{
IRLID irl_id;
const MARPA_AVL_TREE lhs_avl_tree= 
_marpa_avl_create(sym_rule_cmp,NULL);
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

/*:566*/
#line 3067 "./marpa.w"

/*479:*/
#line 4960 "./marpa.w"

{
IRLID irl_id;
int ahfa_item_count= 0;
AIM base_item;
AIM current_item;
int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*481:*/
#line 5011 "./marpa.w"

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

/*:481*/
#line 4969 "./marpa.w"

}
current_item= base_item= marpa_new(struct s_AHFA_item,ahfa_item_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*480:*/
#line 4988 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{
Last_Proper_SYMI_of_IRL(irl)= symbol_instance_of_next_rule+rhs_ix;
/*482:*/
#line 5023 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_NSYID_of_AIM(current_item)= rh_nsyid;
Position_of_AIM(current_item)= rhs_ix;
AHFA_of_AIM(current_item)= NULL;
}

/*:482*/
#line 4998 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*483:*/
#line 5033 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_NSYID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
AHFA_of_AIM(current_item)= NULL;
}

/*:483*/
#line 5007 "./marpa.w"

current_item++;
}

/*:480*/
#line 4974 "./marpa.w"

{
SYMI_of_IRL(irl)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_IRL(irl);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(ahfa_item_count==current_item-base_item);
AIM_Count_of_G(g)= ahfa_item_count;
g->t_AHFA_items= marpa_renew(struct s_AHFA_item,base_item,ahfa_item_count);
/*484:*/
#line 5048 "./marpa.w"

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

/*:484*/
#line 4984 "./marpa.w"

/*489:*/
#line 5106 "./marpa.w"

{
Marpa_AHFA_Item_ID item_id;
AIM*sort_array= marpa_new(struct s_AHFA_item*,ahfa_item_count);
AIM items= g->t_AHFA_items;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)ahfa_item_count;item_id++)
{
sort_array[item_id]= items+item_id;
}
qsort(sort_array,(size_t)ahfa_item_count,
sizeof(AIM),cmp_by_postdot_and_aimid);
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)ahfa_item_count;item_id++)
{
Sort_Key_of_AIM(sort_array[item_id])= item_id;
}
my_free(sort_array);
}

/*:489*/
#line 4985 "./marpa.w"

}

/*:479*/
#line 3068 "./marpa.w"

/*551:*/
#line 5637 "./marpa.w"

{
/*552:*/
#line 5676 "./marpa.w"

const int initial_no_of_states= 2*AIM_Count_of_G(g);
Bit_Matrix prediction_matrix;
IRL*irl_by_sort_key= marpa_new(IRL,irl_count);
MARPA_AVL_TREE duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
int ahfa_count_of_g;

/*:552*/
#line 5639 "./marpa.w"

/*553:*/
#line 5685 "./marpa.w"

/*554:*/
#line 5689 "./marpa.w"

{
int item_id;
int no_of_items_in_grammar= AIM_Count_of_G(g);
duplicates= _marpa_avl_create(AHFA_state_cmp,NULL);
singleton_duplicates= marpa_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++)
{
singleton_duplicates[item_id]= NULL;

}
}

/*:554*/
#line 5686 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:553*/
#line 5640 "./marpa.w"

/*572:*/
#line 6025 "./marpa.w"
{
Bit_Matrix prediction_nsy_by_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*573:*/
#line 6033 "./marpa.w"

{
IRLID irl_id;
NSYID nsyid;
for(nsyid= 0;nsyid<nsy_count;nsyid++)
{

NSY nsy= NSY_by_ID(nsyid);
if(!NSY_is_LHS(nsy))continue;
matrix_bit_set(prediction_nsy_by_nsy_matrix,nsyid,
nsyid);
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
from_nsyid,
to_nsyid);
}
}

/*:573*/
#line 6028 "./marpa.w"

transitive_closure(prediction_nsy_by_nsy_matrix);
/*574:*/
#line 6069 "./marpa.w"
{
int*sort_key_by_irl_id= marpa_new(int,irl_count);
/*576:*/
#line 6087 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
irl_by_sort_key[irl_id]= IRL_by_ID(irl_id);
}
qsort(irl_by_sort_key,(size_t)irl_count,
sizeof(RULE),cmp_by_irl_sort_key);
}

/*:576*/
#line 6071 "./marpa.w"

/*578:*/
#line 6125 "./marpa.w"

{
IRLID sort_ordinal;
for(sort_ordinal= 0;sort_ordinal<irl_count;sort_ordinal++)
{
IRL irl= irl_by_sort_key[sort_ordinal];
sort_key_by_irl_id[ID_of_IRL(irl)]= sort_ordinal;
}
}

/*:578*/
#line 6072 "./marpa.w"

/*579:*/
#line 6135 "./marpa.w"

{
NSYID from_nsyid;
prediction_matrix= 
matrix_obs_create(obs_precompute,nsy_count,
irl_count);
for(from_nsyid= 0;from_nsyid<nsy_count;from_nsyid++)
{

int min,max,start;
for(start= 0;
bv_scan(matrix_row
(prediction_nsy_by_nsy_matrix,from_nsyid),
start,&min,&max);start= max+2)
{
NSYID to_nsyid;
for(to_nsyid= min;to_nsyid<=max;to_nsyid++)
{

RULEID*p_irl_x_lh_nsy= irl_list_x_lh_nsy[to_nsyid];
const RULEID*p_one_past_rules= irl_list_x_lh_nsy[to_nsyid+1];
for(;p_irl_x_lh_nsy<p_one_past_rules;p_irl_x_lh_nsy++)
{

const IRLID irl_with_this_lhs= *p_irl_x_lh_nsy;
int sort_ordinal= 
sort_key_by_irl_id[irl_with_this_lhs];
matrix_bit_set(prediction_matrix,
from_nsyid,sort_ordinal);

}
}
}
}
}

/*:579*/
#line 6073 "./marpa.w"

my_free(sort_key_by_irl_id);
}

/*:574*/
#line 6030 "./marpa.w"

}

/*:572*/
#line 5641 "./marpa.w"

/*540:*/
#line 5474 "./marpa.w"
{
nsy_by_right_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*541:*/
#line 5485 "./marpa.w"

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
LHSID_of_IRL(irl),
rh_nsyid);
break;
}
}
}
}

/*:541*/
#line 5477 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
/*542:*/
#line 5510 "./marpa.w"

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
rh_nsyid,
LHSID_of_IRL(irl)))
{
IRL_is_Right_Recursive(irl)= 1;
}
break;
}
}
}
}

/*:542*/
#line 5479 "./marpa.w"

matrix_clear(nsy_by_right_nsy_matrix);
/*543:*/
#line 5537 "./marpa.w"

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
LHSID_of_IRL(irl),
rh_nsyid);
break;
}
}
}
}

/*:543*/
#line 5481 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
}

/*:540*/
#line 5642 "./marpa.w"

/*558:*/
#line 5748 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
const IRL start_irl= g->t_start_irl;
NSYID*postdot_nsyidary;
AIM start_item;
NSYID postdot_nsyid;
AIM*item_list= marpa_obs_new(g->t_obs,AIM,1);

start_item= First_AIM_of_IRL(start_irl);
item_list[0]= start_item;
AHFA_initialize(g,p_initial_state);
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= 1;
singleton_duplicates[0]= p_initial_state;
AHFA_is_Predicted(p_initial_state)= 0;
Postdot_NSY_Count_of_AHFA(p_initial_state)= 1;
postdot_nsyidary= Postdot_NSYIDAry_of_AHFA(p_initial_state)= 
marpa_obs_new(g->t_obs,NSYID,1);
postdot_nsyid= Postdot_NSYID_of_AIM(start_item);
*postdot_nsyidary= postdot_nsyid;
Completion_CIL_of_AHFA(p_initial_state)= 
cil_empty(&g->t_cilar);
p_initial_state->t_empty_transition= create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
postdot_nsyid),
irl_by_sort_key,&states,duplicates,
item_list_working_buffer);
}

/*:558*/
#line 5643 "./marpa.w"


{
AIMID aim_id;
const int aim_count= AIM_Count_of_G(g);
for(aim_id= 0;aim_id<aim_count;aim_id++)
{
const AIM aim= AIM_by_ID(aim_id);
if(!AIM_is_Prediction(aim))
{
create_singleton_AHFA_state(g,aim,singleton_duplicates,
irl_by_sort_key,&states,duplicates,
item_list_working_buffer,
prediction_matrix);
}
}
}

g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g);
/*555:*/
#line 5702 "./marpa.w"

{
int ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++)
{
AHFA from_ahfa= AHFA_of_G_by_ID(g,ahfa_id);
AIM*aims= AIMs_of_AHFA(from_ahfa);
int aim_count= AIM_Count_of_AHFA(from_ahfa);
qsort(aims,(size_t)aim_count,sizeof(AIM*),cmp_by_aimid);
}
}

/*:555*/
#line 5664 "./marpa.w"

/*556:*/
#line 5714 "./marpa.w"

{
int ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++)
{
AHFA from_ahfa= AHFA_of_G_by_ID(g,ahfa_id);
AIM*aims= AIMs_of_AHFA(from_ahfa);
int aim_count= AIM_Count_of_AHFA(from_ahfa);
AEX aex;
for(aex= 0;aex<aim_count;aex++)
{
AIM from_ahfa_item= aims[aex];
NSYID postdot_nsyid= Postdot_NSYID_of_AIM(from_ahfa_item);
if(postdot_nsyid>=0)
{

AIM next_aim= Next_AIM_of_AIM(from_ahfa_item);
AHFA to_ahfa= AHFA_of_AIM(next_aim);
if(to_ahfa&&AHFA_is_Leo_Completion(to_ahfa))
{
AHFA_is_Potential_Leo_Base(from_ahfa)= 1;
}
}
}
}
}

/*:556*/
#line 5665 "./marpa.w"

/*557:*/
#line 5741 "./marpa.w"

my_free(irl_by_sort_key);
my_free(singleton_duplicates);
_marpa_avl_destroy(duplicates);

/*:557*/
#line 5666 "./marpa.w"

}

/*:551*/
#line 3069 "./marpa.w"

/*585:*/
#line 6288 "./marpa.w"

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
ID_of_NSY(nsy));
}
}
}
}

/*:585*/
#line 3070 "./marpa.w"

/*586:*/
#line 6309 "./marpa.w"

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

/*:586*/
#line 3071 "./marpa.w"

/*587:*/
#line 6332 "./marpa.w"

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

/*:587*/
#line 3073 "./marpa.w"

/*588:*/
#line 6402 "./marpa.w"

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

/*:588*/
#line 3074 "./marpa.w"

/*589:*/
#line 6418 "./marpa.w"

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
outer_nsyid,
inner_nsyid))
{



Event_Group_Size_of_AHFA(outer_ahfa)++;
}
}
}
}

/*:589*/
#line 3075 "./marpa.w"

}
g->t_is_precomputed= 1;
if(g->t_has_cycle)
{
MARPA_ERROR(MARPA_ERR_GRAMMAR_HAS_CYCLE);
goto FAILURE;
}
/*590:*/
#line 6467 "./marpa.w"

{cilar_reinit(&g->t_cilar);}
/*:590*/
#line 3083 "./marpa.w"

return_value= 0;
goto CLEANUP;
FAILURE:;
goto CLEANUP;
CLEANUP:;
marpa_obs_free(obs_precompute);
return return_value;
}

/*:365*//*374:*/
#line 3185 "./marpa.w"

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

/*:374*//*465:*/
#line 4867 "./marpa.w"

PRIVATE int aim_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:465*//*471:*/
#line 4914 "./marpa.w"

int _marpa_g_AHFA_item_count(Marpa_Grammar g){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 4916 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 4917 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:471*//*472:*/
#line 4921 "./marpa.w"

Marpa_IRL_ID _marpa_g_AHFA_item_irl(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 4924 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 4925 "./marpa.w"

/*1337:*/
#line 15829 "./marpa.w"

if(_MARPA_UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1337*/
#line 4926 "./marpa.w"

return IRLID_of_AIM(AIM_by_ID(item_id));
}

/*:472*//*474:*/
#line 4931 "./marpa.w"

int _marpa_g_AHFA_item_position(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 4934 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 4935 "./marpa.w"

/*1337:*/
#line 15829 "./marpa.w"

if(_MARPA_UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1337*/
#line 4936 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:474*//*476:*/
#line 4941 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_item_postdot(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 4944 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 4945 "./marpa.w"

/*1337:*/
#line 15829 "./marpa.w"

if(_MARPA_UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1337*/
#line 4946 "./marpa.w"

return Postdot_NSYID_of_AIM(AIM_by_ID(item_id));
}

/*:476*//*477:*/
#line 4950 "./marpa.w"

int _marpa_g_AHFA_item_sort_key(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 4953 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 4954 "./marpa.w"

/*1337:*/
#line 15829 "./marpa.w"

if(_MARPA_UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1337*/
#line 4955 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:477*//*486:*/
#line 5067 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:486*//*488:*/
#line 5082 "./marpa.w"

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

/*:488*//*502:*/
#line 5235 "./marpa.w"

PRIVATE void AHFA_initialize(GRAMMAR g,AHFA ahfa)
{
const AHFAID new_AHFA_id= AHFA_Count_of_G(g)++;
/*521:*/
#line 5347 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;


/*:521*//*525:*/
#line 5374 "./marpa.w"

Event_AHFAIDs_of_AHFA(ahfa)= NULL;
Event_Group_Size_of_AHFA(ahfa)= 0;

/*:525*//*546:*/
#line 5579 "./marpa.w"

Leo_LHS_NSYID_of_AHFA(ahfa)= -1;
Leo_IRLID_of_AHFA(ahfa)= -1;
/*:546*/
#line 5239 "./marpa.w"

ahfa->t_key.t_id= new_AHFA_id;
}

/*:502*//*514:*/
#line 5292 "./marpa.w"

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

/*:514*//*515:*/
#line 5315 "./marpa.w"

PRIVATE AEX aex_of_ahfa_by_postdot_get(AHFA ahfa,NSYID sought_nsyid)
{
const AIM*const aims= AIMs_of_AHFA(ahfa);
const int aim_count= AIM_Count_of_AHFA(ahfa);
int i;
for(i= 0;i<aim_count;i++){
const NSYID working_nsyid= Postdot_NSYID_of_AIM(aims[i]);
if(working_nsyid==sought_nsyid)return i;
}
return-1;
}

/*:515*//*532:*/
#line 5402 "./marpa.w"

PRIVATE int AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:532*//*535:*/
#line 5416 "./marpa.w"

int _marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:535*//*536:*/
#line 5421 "./marpa.w"

int
_marpa_g_AHFA_state_item_count(Marpa_Grammar g,AHFAID AHFA_state_id)
{/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 5424 "./marpa.w"

AHFA state;
/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 5426 "./marpa.w"

/*1338:*/
#line 15834 "./marpa.w"

if(_MARPA_UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1338*/
#line 5427 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:536*//*537:*/
#line 5434 "./marpa.w"

Marpa_AHFA_Item_ID _marpa_g_AHFA_state_item(Marpa_Grammar g,
AHFAID AHFA_state_id,
int item_ix){
AHFA state;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 5439 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 5440 "./marpa.w"

/*1338:*/
#line 15834 "./marpa.w"

if(_MARPA_UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1338*/
#line 5441 "./marpa.w"

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

/*:537*//*538:*/
#line 5454 "./marpa.w"

int _marpa_g_AHFA_state_is_predict(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 5458 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 5459 "./marpa.w"

/*1338:*/
#line 15834 "./marpa.w"

if(_MARPA_UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1338*/
#line 5460 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:538*//*547:*/
#line 5582 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_state_leo_lhs_symbol(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 5585 "./marpa.w"

AHFA state;
/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 5587 "./marpa.w"

/*1338:*/
#line 15834 "./marpa.w"

if(_MARPA_UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1338*/
#line 5588 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_NSYID_of_AHFA(state);
}

/*:547*//*550:*/
#line 5609 "./marpa.w"

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

/*:550*//*561:*/
#line 5806 "./marpa.w"

PRIVATE AHFA
create_singleton_AHFA_state(
GRAMMAR g,
AIM base_aim,
AHFA*singleton_duplicates,
IRL*irl_by_sort_key,
DQUEUE states_p,
MARPA_AVL_TREE duplicates,
AIM*item_list_working_buffer,
Bit_Matrix prediction_matrix
)
{


const AIM AHFA_item_0_p= g->t_AHFA_items;
AHFA new_ahfa;
AIM*new_state_item_list;
NSYID postdot_nsyid;
const Marpa_AHFA_Item_ID working_aim_id= base_aim-AHFA_item_0_p;

new_ahfa= singleton_duplicates[working_aim_id];

if(new_ahfa)
{
return new_ahfa;
}

MARPA_OFF_DEBUG2("Creating singleton AHFA for AIM %d",working_aim_id);

new_ahfa= DQUEUE_PUSH((*states_p),AHFA_Object);

AHFA_initialize(g,new_ahfa);
singleton_duplicates[working_aim_id]= new_ahfa;
new_state_item_list= new_ahfa->t_items= 
marpa_obs_new(g->t_obs,AIM,1);
new_state_item_list[0]= base_aim;
new_ahfa->t_item_count= 1;
AHFA_is_Predicted(new_ahfa)= 0;
postdot_nsyid= Postdot_NSYID_of_AIM(base_aim);
if(postdot_nsyid>=0)
{
NSYID*p_postdot_nsyidary= Postdot_NSYIDAry_of_AHFA(new_ahfa)= 
marpa_obs_new(g->t_obs,NSYID,1);
Completion_CIL_of_AHFA(new_ahfa)
= cil_empty(&g->t_cilar);
Postdot_NSY_Count_of_AHFA(new_ahfa)= 1;
*p_postdot_nsyidary= postdot_nsyid;


new_ahfa->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
postdot_nsyid),
irl_by_sort_key,states_p,duplicates,
item_list_working_buffer);
}
else
{

const IRL irl= IRL_of_AIM(base_aim);
const NSYID lhs_nsyid= LHSID_of_IRL(irl);
Completion_CIL_of_AHFA(new_ahfa)= cil_singleton(&g->t_cilar,lhs_nsyid);

Postdot_NSY_Count_of_AHFA(new_ahfa)= 0;
new_ahfa->t_empty_transition= NULL;
/*562:*/
#line 5884 "./marpa.w"

{
const IRL aim_irl= IRL_of_AIM(base_aim);
if(IRL_is_Right_Recursive(aim_irl))
{
Leo_LHS_NSYID_of_AHFA(new_ahfa)= lhs_nsyid;
Leo_IRLID_of_AHFA(new_ahfa)= ID_of_IRL(aim_irl);
}
}

/*:562*/
#line 5873 "./marpa.w"

}
AHFA_of_AIM(base_aim)= new_ahfa;
return new_ahfa;
}

/*:561*//*567:*/
#line 5984 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,MARPA_AVL_TREE duplicates)
{
const AHFA state_found= _marpa_avl_insert(duplicates,sought_state);
return state_found;
}

/*:567*//*577:*/
#line 6103 "./marpa.w"

PRIVATE_NOT_INLINE int
cmp_by_irl_sort_key(const void*ap,const void*bp)
{
const IRL irl_a= *(IRL*)ap;
const IRL irl_b= *(IRL*)bp;
int sort_key_a;
int sort_key_b;
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

/*:577*//*580:*/
#line 6171 "./marpa.w"

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
int start,min,max;

for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2)
{
int sort_ordinal;
for(sort_ordinal= min;sort_ordinal<=max;sort_ordinal++)
{

const IRL irl= irl_by_sort_key[sort_ordinal];
item_list_working_buffer[item_list_ix++]= First_AIM_of_IRL(irl);
}
}
}
p_new_state= DQUEUE_PUSH((*states_p),AHFA_Object);
AHFA_initialize(g,p_new_state);
p_new_state->t_items= item_list_working_buffer;
p_new_state->t_item_count= no_of_items_in_new_state;
{
AHFA queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state)
{


(void)DQUEUE_POP((*states_p),AHFA_Object);
AHFA_Count_of_G(g)--;
return queued_AHFA_state;
}
}

{
int i;
AIM*const final_aim_list= p_new_state->t_items= 
marpa_obs_new(g->t_obs,AIM,no_of_items_in_new_state);
for(i= 0;i<no_of_items_in_new_state;i++)
{
final_aim_list[i]= item_list_working_buffer[i];
}
}
AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_empty_transition= NULL;
Completion_CIL_of_AHFA(p_new_state)= cil_empty(&g->t_cilar);
/*581:*/
#line 6234 "./marpa.w"

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
bv_bit_set(postdot_v,postdot_nsyid);
}
if((no_of_postdot_nsys= Postdot_NSY_Count_of_AHFA(p_new_state)= 
bv_count(postdot_v)))
{
int min,max,start;
NSYID*p_nsyid= Postdot_NSYIDAry_of_AHFA(p_new_state)= 
marpa_obs_new(g->t_obs,NSYID,no_of_postdot_nsys);
for(start= 0;bv_scan(postdot_v,start,&min,&max);start= max+2)
{
NSYID postdot_nsyid;
for(postdot_nsyid= min;
postdot_nsyid<=max;postdot_nsyid++)
{
*p_nsyid++= postdot_nsyid;
}
}
}
bv_free(postdot_v);
}

/*:581*/
#line 6230 "./marpa.w"

return p_new_state;
}

/*:580*//*584:*/
#line 6272 "./marpa.w"

AHFAID _marpa_g_AHFA_state_empty_transition(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 6277 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 6278 "./marpa.w"

/*1338:*/
#line 15834 "./marpa.w"

if(_MARPA_UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1338*/
#line 6279 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}

/*:584*//*595:*/
#line 6490 "./marpa.w"

PRIVATE INPUT input_new(GRAMMAR g)
{
INPUT input= my_malloc(sizeof(struct s_input));
TOK_Obs_of_I(input)= marpa_obs_init;
/*598:*/
#line 6502 "./marpa.w"

input->t_ref_count= 1;

/*:598*//*606:*/
#line 6561 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:606*/
#line 6495 "./marpa.w"

return input;
}

/*:595*//*599:*/
#line 6506 "./marpa.w"

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

/*:599*//*600:*/
#line 6519 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:600*//*601:*/
#line 6532 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
marpa_obs_free(TOK_Obs_of_I(input));
my_free(input);
}

/*:601*//*610:*/
#line 6587 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
NSYID nsy_count;
/*1325:*/
#line 15764 "./marpa.w"
void*const failure_indicator= NULL;
/*:1325*/
#line 6592 "./marpa.w"

/*1328:*/
#line 15778 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1328*/
#line 6593 "./marpa.w"

nsy_count= NSY_Count_of_G(g);
r= my_malloc(sizeof(struct marpa_r));
/*668:*/
#line 7127 "./marpa.w"
r->t_obs= marpa_obs_init;
/*:668*/
#line 6596 "./marpa.w"

/*613:*/
#line 6603 "./marpa.w"

r->t_ref_count= 1;

/*:613*//*621:*/
#line 6669 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:621*//*623:*/
#line 6679 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:623*//*627:*/
#line 6703 "./marpa.w"

r->t_earley_item_warning_threshold= 
MAX(DEFAULT_YIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*3);
/*:627*//*631:*/
#line 6732 "./marpa.w"
r->t_furthest_earleme= 0;
/*:631*//*636:*/
#line 6754 "./marpa.w"

r->t_lbv_xsyid_completion_event_is_active= NULL;
r->t_lbv_xsyid_nulled_event_is_active= NULL;
r->t_lbv_xsyid_prediction_event_is_active= NULL;
r->t_active_event_count= 0;

/*:636*//*638:*/
#line 6769 "./marpa.w"

r->t_bv_nsyid_is_expected= bv_obs_create(r->t_obs,nsy_count);
/*:638*//*642:*/
#line 6825 "./marpa.w"

r->t_nsy_expected_is_event= lbv_obs_new0(r->t_obs,nsy_count);
/*:642*//*660:*/
#line 7066 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:660*//*664:*/
#line 7102 "./marpa.w"
r->t_is_exhausted= 0;
/*:664*//*684:*/
#line 7209 "./marpa.w"

r->t_earley_set_count= 0;

/*:684*//*694:*/
#line 7335 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:694*//*701:*/
#line 7410 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:701*//*739:*/
#line 7928 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;
/*:739*//*774:*/
#line 8389 "./marpa.w"

r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:774*//*806:*/
#line 8841 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:806*//*810:*/
#line 8870 "./marpa.w"

MARPA_DSTACK_INIT2(r->t_alternatives,ALT_Object);
/*:810*//*833:*/
#line 9283 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_yim_work_stack);
/*:833*//*837:*/
#line 9298 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_completion_stack);
/*:837*//*841:*/
#line 9309 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_earley_set_stack);
/*:841*//*920:*/
#line 10464 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:920*//*1030:*/
#line 12081 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
r->t_progress_report_traverser= NULL;
/*:1030*//*1308:*/
#line 15600 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1308*/
#line 6597 "./marpa.w"

return r;
}

/*:610*//*614:*/
#line 6607 "./marpa.w"

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

/*:614*//*615:*/
#line 6625 "./marpa.w"

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

/*:615*//*616:*/
#line 6639 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 6643 "./marpa.w"

/*618:*/
#line 6657 "./marpa.w"
input_unref(input);

/*:618*//*811:*/
#line 8872 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_alternatives);

/*:811*//*835:*/
#line 9291 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_yim_work_stack);

/*:835*//*839:*/
#line 9306 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_completion_stack);

/*:839*//*842:*/
#line 9310 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_earley_set_stack);

/*:842*//*921:*/
#line 10466 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:921*//*1032:*/
#line 12090 "./marpa.w"

/*1031:*/
#line 12084 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:1031*/
#line 12091 "./marpa.w"
;
/*:1032*//*1309:*/
#line 15602 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1309*/
#line 6644 "./marpa.w"

grammar_unref(g);
/*669:*/
#line 7128 "./marpa.w"
marpa_obs_free(r->t_obs);

/*:669*/
#line 6646 "./marpa.w"

my_free(r);
}

/*:616*//*624:*/
#line 6687 "./marpa.w"

unsigned int marpa_r_current_earleme(Marpa_Recognizer r)
{return(unsigned int)Current_Earleme_of_R(r);}

/*:624*//*625:*/
#line 6692 "./marpa.w"

PRIVATE YS current_ys_of_r(RECCE r)
{
const YS latest= Latest_YS_of_R(r);
if(Earleme_of_YS(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:625*//*628:*/
#line 6706 "./marpa.w"

int
marpa_r_earley_item_warning_threshold(Marpa_Recognizer r)
{
return r->t_earley_item_warning_threshold;
}

/*:628*//*629:*/
#line 6715 "./marpa.w"

int
marpa_r_earley_item_warning_threshold_set(Marpa_Recognizer r,int threshold)
{
const int new_threshold= threshold<=0?YIM_FATAL_THRESHOLD:threshold;
r->t_earley_item_warning_threshold= new_threshold;
return new_threshold;
}

/*:629*//*632:*/
#line 6733 "./marpa.w"

unsigned int marpa_r_furthest_earleme(Marpa_Recognizer r)
{return(unsigned int)Furthest_Earleme_of_R(r);}

/*:632*//*639:*/
#line 6777 "./marpa.w"

int marpa_r_terminals_expected(Marpa_Recognizer r,Marpa_Symbol_ID*buffer)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 6780 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 6781 "./marpa.w"

int min,max,start;
int ix= 0;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 6784 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 6785 "./marpa.w"

for(start= 0;bv_scan(r->t_bv_nsyid_is_expected,start,&min,&max);
start= max+2)
{
NSYID nsyid;
for(nsyid= min;nsyid<=max;nsyid++)
{
const XSY xsy= Source_XSY_of_NSYID(nsyid);
buffer[ix++]= ID_of_XSY(xsy);
}
}
return ix;
}
/*:639*//*640:*/
#line 6798 "./marpa.w"

int marpa_r_terminal_is_expected(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 6802 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 6803 "./marpa.w"

XSY xsy;
NSY nsy;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 6806 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 6807 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 6808 "./marpa.w"

/*1331:*/
#line 15795 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1331*/
#line 6809 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(!XSY_is_Terminal(xsy))){
return 0;
}
nsy= NSY_of_XSY(xsy);
if(_MARPA_UNLIKELY(!nsy))return 0;
return bv_bit_test(r->t_bv_nsyid_is_expected,ID_of_NSY(nsy));
}

/*:640*//*643:*/
#line 6828 "./marpa.w"

int
marpa_r_expected_symbol_event_set(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int value)
{
XSY xsy;
NSY nsy;
NSYID nsyid;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 6836 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 6837 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 6838 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 6839 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 6840 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
xsy= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(XSY_is_Nulling(xsy))){
MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NULLING);
}
nsy= NSY_of_XSY(xsy);
if(_MARPA_UNLIKELY(!nsy)){
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

/*:643*//*645:*/
#line 6877 "./marpa.w"

int
marpa_r_completion_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 6882 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 6883 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 6884 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 6885 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 6886 "./marpa.w"

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

/*:645*//*647:*/
#line 6924 "./marpa.w"

int
marpa_r_nulled_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 6929 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 6930 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 6931 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 6932 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 6933 "./marpa.w"

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

/*:647*//*649:*/
#line 6971 "./marpa.w"

int
marpa_r_prediction_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 6976 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 6977 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 6978 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 6979 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 6980 "./marpa.w"

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

/*:649*//*661:*/
#line 7072 "./marpa.w"

int _marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7075 "./marpa.w"

/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7076 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 7077 "./marpa.w"

return r->t_use_leo_flag;
}
/*:661*//*662:*/
#line 7080 "./marpa.w"

int _marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7084 "./marpa.w"

/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7085 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 7086 "./marpa.w"

/*1339:*/
#line 15843 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1339*/
#line 7087 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:662*//*666:*/
#line 7113 "./marpa.w"

int marpa_r_is_exhausted(Marpa_Recognizer r)
{
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7116 "./marpa.w"

/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7117 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 7118 "./marpa.w"

return R_is_Exhausted(r);
}

/*:666*//*688:*/
#line 7228 "./marpa.w"

int marpa_r_earley_set_value(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7231 "./marpa.w"

YS earley_set;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7233 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 7234 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 7235 "./marpa.w"

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

/*:688*//*689:*/
#line 7251 "./marpa.w"

int
marpa_r_earley_set_values(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id,
int*p_value,void**p_pvalue)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7256 "./marpa.w"

YS earley_set;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7258 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 7259 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 7260 "./marpa.w"

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

/*:689*//*690:*/
#line 7278 "./marpa.w"

int marpa_r_latest_earley_set_value_set(Marpa_Recognizer r,int value)
{
YS earley_set;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7282 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7283 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 7284 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 7285 "./marpa.w"

earley_set= Latest_YS_of_R(r);
return Value_of_YS(earley_set)= value;
}

/*:690*//*691:*/
#line 7290 "./marpa.w"

int marpa_r_latest_earley_set_values_set(Marpa_Recognizer r,int value,
void*pvalue)
{
YS earley_set;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7295 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7296 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 7297 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 7298 "./marpa.w"

earley_set= Latest_YS_of_R(r);
Value_of_YS(earley_set)= value;
PValue_of_YS(earley_set)= pvalue;
return 1;
}

/*:691*//*692:*/
#line 7306 "./marpa.w"

PRIVATE YS
earley_set_new(RECCE r,JEARLEME id)
{
YSK_Object key;
YS set;
set= marpa_obs_new(r->t_obs,YS_Object,1);
key.t_earleme= id;
set->t_key= key;
set->t_postdot_ary= NULL;
set->t_postdot_sym_count= 0;
YIM_Count_of_YS(set)= 0;
set->t_ordinal= r->t_earley_set_count++;
YIMs_of_YS(set)= NULL;
Next_YS_of_YS(set)= NULL;
/*687:*/
#line 7224 "./marpa.w"

Value_of_YS(set)= -1;
PValue_of_YS(set)= NULL;

/*:687*//*1314:*/
#line 15646 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1314*/
#line 7321 "./marpa.w"

return set;
}

/*:692*//*695:*/
#line 7338 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_trace_earley_set(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7341 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7342 "./marpa.w"

YS trace_earley_set= r->t_trace_earley_set;
/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7344 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
return Ord_of_YS(trace_earley_set);
}

/*:695*//*696:*/
#line 7352 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7355 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7356 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7357 "./marpa.w"

return Ord_of_YS(Latest_YS_of_R(r));
}

/*:696*//*697:*/
#line 7361 "./marpa.w"

Marpa_Earleme marpa_r_earleme(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7364 "./marpa.w"

/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7365 "./marpa.w"

YS earley_set;
/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 7367 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 7368 "./marpa.w"

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

/*:697*//*699:*/
#line 7386 "./marpa.w"

int _marpa_r_earley_set_size(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7389 "./marpa.w"

YS earley_set;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7391 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 7392 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 7393 "./marpa.w"

r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return YIM_Count_of_YS(earley_set);
}

/*:699*//*704:*/
#line 7435 "./marpa.w"

Marpa_Earleme
_marpa_r_earley_set_trace(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
YS earley_set;
const int es_does_not_exist= -1;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7441 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7442 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7443 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_YS(r->t_trace_earley_set)==set_id)
{


return Earleme_of_YS(r->t_trace_earley_set);
}
/*705:*/
#line 7466 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*741:*/
#line 7968 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:741*/
#line 7469 "./marpa.w"

}

/*:705*/
#line 7450 "./marpa.w"

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

/*:704*//*706:*/
#line 7472 "./marpa.w"

Marpa_AHFA_State_ID
_marpa_r_earley_item_trace(Marpa_Recognizer r,Marpa_Earley_Item_ID item_id)
{
const int yim_does_not_exist= -1;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7477 "./marpa.w"

YS trace_earley_set;
YIM earley_item;
YIM*earley_items;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7481 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7482 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*705:*/
#line 7466 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*741:*/
#line 7968 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:741*/
#line 7469 "./marpa.w"

}

/*:705*/
#line 7486 "./marpa.w"

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

/*:706*//*708:*/
#line 7515 "./marpa.w"

PRIVATE void trace_earley_item_clear(RECCE r)
{
/*707:*/
#line 7512 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:707*/
#line 7518 "./marpa.w"

trace_source_link_clear(r);
}

/*:708*//*709:*/
#line 7522 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_earley_item_origin(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7525 "./marpa.w"

YIM item= r->t_trace_earley_item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7527 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7528 "./marpa.w"

if(!item){
/*707:*/
#line 7512 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:707*/
#line 7530 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}
return Origin_Ord_of_YIM(item);
}

/*:709*//*718:*/
#line 7633 "./marpa.w"

PRIVATE YIM earley_item_create(const RECCE r,
const YIK_Object key)
{
/*1325:*/
#line 15764 "./marpa.w"
void*const failure_indicator= NULL;
/*:1325*/
#line 7637 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7638 "./marpa.w"

YIM new_item;
YIM*end_of_work_stack;
const YS set= key.t_set;
const int count= ++YIM_Count_of_YS(set);
/*720:*/
#line 7686 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(_MARPA_UNLIKELY(count>=YIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_YIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:720*/
#line 7643 "./marpa.w"

new_item= marpa_obs_new(r->t_obs,struct s_earley_item,1);
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
new_item->t_rejected= 0;
Ord_of_YIM(new_item)= YIM_ORDINAL_CLAMP((unsigned int)count-1);
end_of_work_stack= WORK_YIM_PUSH(r);
*end_of_work_stack= new_item;
return new_item;
}

/*:718*//*719:*/
#line 7654 "./marpa.w"

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

/*:719*//*723:*/
#line 7716 "./marpa.w"

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

/*:723*//*731:*/
#line 7805 "./marpa.w"

Marpa_Symbol_ID _marpa_r_leo_predecessor_symbol(Marpa_Recognizer r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7809 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7812 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7813 "./marpa.w"

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

/*:731*//*732:*/
#line 7827 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_leo_base_origin(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7831 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7833 "./marpa.w"

YIM base_earley_item;
/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7835 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_YIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_YIM(base_earley_item);
}

/*:732*//*733:*/
#line 7845 "./marpa.w"

Marpa_AHFA_State_ID _marpa_r_leo_base_state(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7849 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
YIM base_earley_item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7852 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7853 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_YIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_YIM(base_earley_item);
}

/*:733*//*736:*/
#line 7892 "./marpa.w"

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
/*:736*//*737:*/
#line 7912 "./marpa.w"

PRIVATE PIM first_pim_of_ys_by_nsyid(YS set,NSYID nsyid)
{
PIM*pim_nsy_p= pim_nsy_p_find(set,nsyid);
return pim_nsy_p?*pim_nsy_p:NULL;
}

/*:737*//*740:*/
#line 7942 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_postdot_symbol_trace(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7947 "./marpa.w"

YS current_ys= r->t_trace_earley_set;
PIM*pim_nsy_p;
PIM pim;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7951 "./marpa.w"

/*741:*/
#line 7968 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:741*/
#line 7952 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7953 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 7954 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 7955 "./marpa.w"

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

/*:740*//*742:*/
#line 7978 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_postdot_item_trace(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 7982 "./marpa.w"

YS current_earley_set= r->t_trace_earley_set;
PIM pim;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 7985 "./marpa.w"

PIM*pim_nsy_p;
/*741:*/
#line 7968 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:741*/
#line 7987 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 7988 "./marpa.w"

if(!current_earley_set){
/*707:*/
#line 7512 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:707*/
#line 7990 "./marpa.w"

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

/*:742*//*743:*/
#line 8009 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_postdot_item_trace(Marpa_Recognizer r)
{
const XSYID no_more_postdot_symbols= -1;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8014 "./marpa.w"

YS current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_nsy_p;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8018 "./marpa.w"


pim_nsy_p= r->t_trace_pim_nsy_p;
pim= r->t_trace_postdot_item;
/*741:*/
#line 7968 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:741*/
#line 8022 "./marpa.w"

if(!pim_nsy_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8027 "./marpa.w"

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

/*:743*//*744:*/
#line 8047 "./marpa.w"

Marpa_AHFA_State_ID _marpa_r_postdot_item_symbol(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8050 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8052 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8053 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_NSYID_of_PIM(postdot_item);
}


/*:744*//*760:*/
#line 8177 "./marpa.w"
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
new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
new_link->t_next= LV_First_Token_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
TOK_of_Source(new_link->t_source)= tkn;
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:760*//*765:*/
#line 8257 "./marpa.w"

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
new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
new_link->t_next= LV_First_Completion_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
}

/*:765*//*766:*/
#line 8287 "./marpa.w"

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
new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
new_link->t_next= LV_First_Leo_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Leo_SRCL_of_YIM(item)= new_link;
}

/*:766*//*768:*/
#line 8336 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,YIM item)
{
unsigned int previous_source_type= Source_Type_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*769:*/
#line 8353 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:769*/
#line 8344 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*770:*/
#line 8361 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:770*/
#line 8346 "./marpa.w"

return;
case SOURCE_IS_LEO:/*771:*/
#line 8369 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= new_link;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:771*/
#line 8348 "./marpa.w"

return;
}
}

/*:768*//*776:*/
#line 8399 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_token_link_trace(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8402 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8406 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8407 "./marpa.w"

/*790:*/
#line 8594 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:790*/
#line 8408 "./marpa.w"

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

/*:776*//*779:*/
#line 8440 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_token_link_trace(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8443 "./marpa.w"

SRCL source_link;
YIM item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8446 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8447 "./marpa.w"

/*790:*/
#line 8594 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:790*/
#line 8448 "./marpa.w"

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

/*:779*//*781:*/
#line 8470 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_completion_link_trace(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8473 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8477 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8478 "./marpa.w"

/*790:*/
#line 8594 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:790*/
#line 8479 "./marpa.w"

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

/*:781*//*784:*/
#line 8510 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_completion_link_trace(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8513 "./marpa.w"

SRCL source_link;
YIM item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8516 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8517 "./marpa.w"

/*790:*/
#line 8594 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:790*/
#line 8518 "./marpa.w"

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

/*:784*//*786:*/
#line 8540 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_leo_link_trace(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8544 "./marpa.w"

SRCL source_link;
YIM item= r->t_trace_earley_item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8547 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8548 "./marpa.w"

/*790:*/
#line 8594 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:790*/
#line 8549 "./marpa.w"

source_link= First_Leo_SRCL_of_YIM(item);
if(source_link){
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_source_link= source_link;
return Cause_AHFAID_of_SRCL(source_link);
}
trace_source_link_clear(r);
return-1;
}

/*:786*//*789:*/
#line 8568 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_leo_link_trace(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8572 "./marpa.w"

SRCL source_link;
YIM item;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8575 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8576 "./marpa.w"

/*790:*/
#line 8594 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:790*/
#line 8577 "./marpa.w"

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

/*:789*//*791:*/
#line 8603 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:791*//*792:*/
#line 8618 "./marpa.w"

AHFAID _marpa_r_source_predecessor_state(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8621 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8624 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8625 "./marpa.w"

source_type= r->t_trace_source_type;
/*798:*/
#line 8771 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:798*/
#line 8627 "./marpa.w"

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

/*:792*//*793:*/
#line 8659 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_token(Marpa_Recognizer r,int*value_p)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8662 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8665 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8666 "./marpa.w"

source_type= r->t_trace_source_type;
/*798:*/
#line 8771 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:798*/
#line 8668 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK tkn= TOK_of_SRCL(source_link);
if(value_p)*value_p= Value_of_TOK(tkn);
return NSYID_of_TOK(tkn);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:793*//*795:*/
#line 8691 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_leo_transition_symbol(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8694 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8697 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8698 "./marpa.w"

source_type= r->t_trace_source_type;
/*798:*/
#line 8771 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:798*/
#line 8700 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_NSYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:795*//*797:*/
#line 8734 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_source_middle(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8737 "./marpa.w"

YIM predecessor_yim= NULL;
unsigned int source_type;
SRCL source_link;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8741 "./marpa.w"

/*1342:*/
#line 15859 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 15860 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 15861 "./marpa.w"


/*:1342*/
#line 8742 "./marpa.w"

source_type= r->t_trace_source_type;
/*798:*/
#line 8771 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:798*/
#line 8744 "./marpa.w"


switch(source_type)
{
case SOURCE_IS_LEO:
{
LIM predecessor= LIM_of_SRCL(source_link);
if(predecessor)
predecessor_yim= Base_YIM_of_LIM(predecessor);
break;
}
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:
{
predecessor_yim= Predecessor_of_SRCL(source_link);
break;
}
default:
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

if(predecessor_yim)
return YS_Ord_of_YIM(predecessor_yim);
return Origin_Ord_of_YIM(r->t_trace_earley_item);
}

/*:797*//*813:*/
#line 8878 "./marpa.w"

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

/*:813*//*815:*/
#line 8922 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= NSYID_of_ALT(a)-NSYID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:815*//*816:*/
#line 8939 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,JEARLEME earleme)
{
MARPA_DSTACK alternatives= &r->t_alternatives;
ALT end_of_stack= MARPA_DSTACK_TOP(*alternatives,ALT_Object);
if(!end_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(end_of_stack))return NULL;
return MARPA_DSTACK_POP(*alternatives,ALT_Object);
}

/*:816*//*817:*/
#line 8954 "./marpa.w"

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

/*:817*//*818:*/
#line 8975 "./marpa.w"
int marpa_r_start_input(Marpa_Recognizer r)
{
int return_value= 1;
YS set0;
YIK_Object key;
AHFA state;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 8981 "./marpa.w"

/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 8982 "./marpa.w"

/*1339:*/
#line 15843 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1339*/
#line 8983 "./marpa.w"

{
/*819:*/
#line 9030 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
const NSYID xsy_count= XSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
/*:819*/
#line 8985 "./marpa.w"

Current_Earleme_of_R(r)= 0;
/*825:*/
#line 9072 "./marpa.w"

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

/*:825*/
#line 8987 "./marpa.w"

G_EVENTS_CLEAR(g);
if(G_is_Trivial(g)){
/*665:*/
#line 7103 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:665*/
#line 8990 "./marpa.w"

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
#line 9875 "./marpa.w"

r->t_bv_lim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_bv_pim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_pim_workarea= marpa_obs_new(r->t_obs,void*,nsy_count);
/*:875*//*894:*/
#line 10155 "./marpa.w"

r->t_lim_chain= marpa_obs_new(r->t_obs,void*,2*nsy_count);
/*:894*/
#line 9005 "./marpa.w"

/*834:*/
#line 9284 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_yim_work_stack))
{
MARPA_DSTACK_INIT2(r->t_yim_work_stack,YIM);
}
}
/*:834*//*838:*/
#line 9299 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_completion_stack))
{
MARPA_DSTACK_INIT2(r->t_completion_stack,YIM);
}
}
/*:838*/
#line 9006 "./marpa.w"

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
/*820:*/
#line 9034 "./marpa.w"

bv_free(bv_ok_for_chain);

/*:820*/
#line 9025 "./marpa.w"

}
return return_value;
}

/*:818*//*826:*/
#line 9112 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID tkn_xsy_id,
int value,
int length)
{
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 9119 "./marpa.w"

YS current_earley_set;
const JEARLEME current_earleme= Current_Earleme_of_R(r);
JEARLEME target_earleme;
NSYID tkn_nsyid;
if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT))
{
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT;
}
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,tkn_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return MARPA_ERR_INVALID_SYMBOL_ID;
}
/*827:*/
#line 9141 "./marpa.w"
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
if(value&&_MARPA_UNLIKELY(!lbv_bit_test(r->t_valued_terminal,tkn_xsy_id)))
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
if(!value&&_MARPA_UNLIKELY(!lbv_bit_test(r->t_unvalued_terminal,tkn_xsy_id)))
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

/*:827*/
#line 9134 "./marpa.w"

/*830:*/
#line 9201 "./marpa.w"

{
NSY tkn_nsy= NSY_by_XSYID(tkn_xsy_id);
if(_MARPA_UNLIKELY(!tkn_nsy))
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

/*:830*/
#line 9135 "./marpa.w"

/*828:*/
#line 9181 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=JEARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return MARPA_ERR_PARSE_TOO_LONG;
}
}

/*:828*/
#line 9136 "./marpa.w"

/*831:*/
#line 9239 "./marpa.w"

{
TOK tkn;
ALT_Object alternative;
struct marpa_obstack*const tkn_obstack= TOK_Obs_of_I(input);
if(value)
{
tkn= 
marpa_obs_start(TOK_Obs_of_I(input),sizeof(*tkn),ALIGNOF(TOK));
NSYID_of_TOK(tkn)= tkn_nsyid;
Type_of_TOK(tkn)= VALUED_TOKEN_OR_NODE;
Value_of_TOK(tkn)= value;
}
else
{
tkn= 
marpa_obs_start(TOK_Obs_of_I(input),sizeof(tkn->t_unvalued),
ALIGNOF(struct s_token_unvalued));
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

/*:831*/
#line 9137 "./marpa.w"

return MARPA_ERR_NONE;
}

/*:826*//*844:*/
#line 9330 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 9334 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 9335 "./marpa.w"

YIM*cause_p;
YS current_earley_set;
JEARLEME current_earleme;




JEARLEME return_value= -2;

/*1341:*/
#line 15853 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1341*/
#line 9345 "./marpa.w"

{
int count_of_expected_terminals;
/*845:*/
#line 9386 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
struct marpa_obstack*const earleme_complete_obs= marpa_obs_init;
/*:845*/
#line 9348 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_nsyid_is_expected);
/*847:*/
#line 9394 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*665:*/
#line 7103 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:665*/
#line 9398 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:847*/
#line 9352 "./marpa.w"

/*849:*/
#line 9416 "./marpa.w"
{
ALT end_of_stack= MARPA_DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!end_of_stack||current_earleme!=End_Earleme_of_ALT(end_of_stack))
{
return_value= 0;
goto CLEANUP;
}
}

/*:849*/
#line 9353 "./marpa.w"

/*848:*/
#line 9406 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_YS_of_YS(Latest_YS_of_R(r))= current_earley_set;
Latest_YS_of_R(r)= current_earley_set;
}

/*:848*/
#line 9354 "./marpa.w"

/*850:*/
#line 9425 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*851:*/
#line 9432 "./marpa.w"

{
YS start_earley_set= Start_YS_of_ALT(alternative);
TOK tkn= TOK_of_ALT(alternative);
NSYID tkn_nsyid= NSYID_of_TOK(tkn);
PIM pim= First_PIM_of_YS_by_NSYID(start_earley_set,tkn_nsyid);
for(;pim;pim= Next_PIM_of_PIM(pim))
{
const YIM predecessor= YIM_of_PIM(pim);
if(!predecessor)
continue;

if(YIM_is_Predicted(predecessor))
{
const AHFA predecessor_ahfa= AHFA_of_YIM(predecessor);
AIM*const aims= AIMs_of_AHFA(predecessor_ahfa);
const int aim_count= AIM_Count_of_AHFA(predecessor_ahfa);
AEX aex;
for(aex= 0;aex<aim_count;aex++){
const AIM predecessor_aim= aims[aex];
if(Postdot_NSYID_of_AIM(predecessor_aim)==tkn_nsyid){
const AIM next_aim= Next_AIM_of_AIM(predecessor_aim);


const AHFA scanned_AHFA= AHFA_of_AIM(next_aim);
MARPA_ASSERT(scanned_AHFA);


/*852:*/
#line 9475 "./marpa.w"

{
const AHFA prediction_AHFA= Empty_Transition_of_AHFA(scanned_AHFA);
const YIM scanned_earley_item= earley_item_assign(r,
current_earley_set,
Origin_of_YIM
(predecessor),
scanned_AHFA);
tkn_link_add(r,scanned_earley_item,predecessor,tkn);
if(prediction_AHFA)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA);
}
}

/*:852*/
#line 9460 "./marpa.w"

}
}
}
else
{
const AHFA predecessor_ahfa= AHFA_of_YIM(predecessor);
const AIM predecessor_aim= AIM_of_AHFA_by_AEX(predecessor_ahfa,0);
const AIM scanned_aim= Next_AIM_of_AIM(predecessor_aim);
const AHFA scanned_AHFA= AHFA_of_AIM(scanned_aim);
/*852:*/
#line 9475 "./marpa.w"

{
const AHFA prediction_AHFA= Empty_Transition_of_AHFA(scanned_AHFA);
const YIM scanned_earley_item= earley_item_assign(r,
current_earley_set,
Origin_of_YIM
(predecessor),
scanned_AHFA);
tkn_link_add(r,scanned_earley_item,predecessor,tkn);
if(prediction_AHFA)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA);
}
}

/*:852*/
#line 9470 "./marpa.w"

}
}
}

/*:851*/
#line 9429 "./marpa.w"

}

/*:850*/
#line 9355 "./marpa.w"

/*853:*/
#line 9491 "./marpa.w"
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

/*:853*/
#line 9356 "./marpa.w"

while((cause_p= MARPA_DSTACK_POP(r->t_completion_stack,YIM))){
YIM cause= *cause_p;
/*854:*/
#line 9510 "./marpa.w"

{
int count= Complete_NSY_Count_of_YIM(cause);
YS middle= Origin_of_YIM(cause);
int nsy_ix;
for(nsy_ix= 0;nsy_ix<count;nsy_ix++)
{
NSYID complete_nsyid= Complete_NSYID_of_YIM(cause,nsy_ix);
/*855:*/
#line 9522 "./marpa.w"

{
PIM postdot_item;
for(postdot_item= First_PIM_of_YS_by_NSYID(middle,complete_nsyid);
postdot_item;postdot_item= Next_PIM_of_PIM(postdot_item))
{
const YIM predecessor= YIM_of_PIM(postdot_item);
if(predecessor)
{
if(YIM_is_Predicted(predecessor))
{
const AHFA predecessor_ahfa= AHFA_of_YIM(predecessor);
AIM*const aims= AIMs_of_AHFA(predecessor_ahfa);
const int aim_count= AIM_Count_of_AHFA(predecessor_ahfa);
AEX aex;
for(aex= 0;aex<aim_count;aex++){
const AIM predecessor_aim= aims[aex];
if(Postdot_NSYID_of_AIM(predecessor_aim)==complete_nsyid){
const AIM next_aim= Next_AIM_of_AIM(predecessor_aim);


const AHFA effect_AHFA= AHFA_of_AIM(next_aim);
MARPA_ASSERT(effect_AHFA);


/*856:*/
#line 9570 "./marpa.w"

{
const YS origin= Origin_of_YIM(predecessor);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA);
if(Earley_Item_has_No_Source(effect)){
const AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA);

if(Earley_Item_is_Completion(effect)){
/*857:*/
#line 9591 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:857*/
#line 9580 "./marpa.w"

}
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}
completion_link_add(r,effect,predecessor,cause);
}

/*:856*/
#line 9548 "./marpa.w"

}
}
}else{
const AHFA predecessor_ahfa= AHFA_of_YIM(predecessor);
const AIM predecessor_aim= AIM_of_AHFA_by_AEX(predecessor_ahfa,0);
const AIM effect_aim= Next_AIM_of_AIM(predecessor_aim);
const AHFA effect_AHFA= AHFA_of_AIM(effect_aim);
/*856:*/
#line 9570 "./marpa.w"

{
const YS origin= Origin_of_YIM(predecessor);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA);
if(Earley_Item_has_No_Source(effect)){
const AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA);

if(Earley_Item_is_Completion(effect)){
/*857:*/
#line 9591 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:857*/
#line 9580 "./marpa.w"

}
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}
completion_link_add(r,effect,predecessor,cause);
}

/*:856*/
#line 9557 "./marpa.w"

}
}
else
{
/*858:*/
#line 9596 "./marpa.w"
{
const LIM leo_item= LIM_of_PIM(postdot_item);
const YS origin= Origin_of_LIM(leo_item);
const AHFA effect_AHFA= Top_AHFA_of_LIM(leo_item);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA);
if(Earley_Item_has_No_Source(effect))
{

/*857:*/
#line 9591 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:857*/
#line 9605 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:858*/
#line 9562 "./marpa.w"

break;


}
}
}

/*:855*/
#line 9518 "./marpa.w"

}
}

/*:854*/
#line 9359 "./marpa.w"

}
postdot_items_create(r,bv_ok_for_chain,current_earley_set);




count_of_expected_terminals= bv_count(r->t_bv_nsyid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_YS(current_earley_set)>=Furthest_Earleme_of_R(r))
{
/*665:*/
#line 7103 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:665*/
#line 9370 "./marpa.w"

}
earley_set_update_items(r,current_earley_set);
if(r->t_active_event_count> 0){
trigger_events(r);
}
return_value= G_EVENT_COUNT(g);
CLEANUP:;
/*846:*/
#line 9390 "./marpa.w"

bv_free(bv_ok_for_chain);
marpa_obs_free(earleme_complete_obs);

/*:846*/
#line 9378 "./marpa.w"

}
return return_value;
}

/*:844*//*859:*/
#line 9610 "./marpa.w"

PRIVATE void trigger_events(RECCE r)
{
const GRAMMAR g= G_of_R(r);
const YS current_earley_set= Latest_YS_of_R(r);
int min,max,start;
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
for(event_xsyid= min;event_xsyid<=max;
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
for(event_xsyid= min;event_xsyid<=max;
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

/*:859*//*860:*/
#line 9750 "./marpa.w"

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

/*:860*//*861:*/
#line 9778 "./marpa.w"

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

/*:861*//*877:*/
#line 9882 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,
Bit_Vector bv_ok_for_chain,
const YS current_earley_set)
{
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 9888 "./marpa.w"

/*876:*/
#line 9879 "./marpa.w"

bv_clear(r->t_bv_lim_symbols);
bv_clear(r->t_bv_pim_symbols);
/*:876*/
#line 9889 "./marpa.w"

/*878:*/
#line 9901 "./marpa.w"
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


new_pim= marpa__obs_alloc(r->t_obs,sizeof(YIX_Object),ALIGNOF(PIM_Object));

nsyid= postdot_nsyidary[nsy_ix];
Postdot_NSYID_of_PIM(new_pim)= nsyid;
YIM_of_PIM(new_pim)= earley_item;
if(bv_bit_test(r->t_bv_pim_symbols,nsyid))
old_pim= r->t_pim_workarea[nsyid];
Next_PIM_of_PIM(new_pim)= old_pim;
if(!old_pim)current_earley_set->t_postdot_sym_count++;
r->t_pim_workarea[nsyid]= new_pim;
bv_bit_set(r->t_bv_pim_symbols,nsyid);
}
}
}

/*:878*/
#line 9890 "./marpa.w"

if(r->t_is_using_leo){
/*880:*/
#line 9946 "./marpa.w"

{
int min,max,start;
for(start= 0;bv_scan(r->t_bv_pim_symbols,start,&min,&max);
start= max+2)
{
NSYID nsyid;
for(nsyid= (NSYID)min;nsyid<=(NSYID)max;nsyid++)
{
const PIM this_pim= r->t_pim_workarea[nsyid];
if(!Next_PIM_of_PIM(this_pim))
{

const YIM leo_base= YIM_of_PIM(this_pim);
if(YIM_is_Potential_Leo_Base(leo_base))
{
const AHFA leo_base_ahfa= AHFA_of_YIM(leo_base);
const AEX potential_leo_aex= 
aex_of_ahfa_by_postdot_get(leo_base_ahfa,nsyid);
if(potential_leo_aex>=0)
{
const AIM base_from_aim= 
AIM_of_AHFA_by_AEX(leo_base_ahfa,potential_leo_aex);
const AIM base_to_aim= Next_AIM_of_AIM(base_from_aim);
const AHFA base_to_ahfa= AHFA_of_AIM(base_to_aim);
if(AHFA_is_Leo_Completion(base_to_ahfa))
{
/*881:*/
#line 9988 "./marpa.w"
{
LIM new_lim;
new_lim= marpa_obs_new(r->t_obs,LIM_Object,1);
Postdot_NSYID_of_LIM(new_lim)= nsyid;
YIM_of_PIM(new_lim)= NULL;
Predecessor_LIM_of_LIM(new_lim)= NULL;
Origin_of_LIM(new_lim)= NULL;
CIL_of_LIM(new_lim)= NULL;
Top_AHFA_of_LIM(new_lim)= base_to_ahfa;
Base_to_AHFA_of_LIM(new_lim)= base_to_ahfa;
Base_YIM_of_LIM(new_lim)= leo_base;
YS_of_LIM(new_lim)= current_earley_set;
Next_PIM_of_LIM(new_lim)= this_pim;
r->t_pim_workarea[nsyid]= new_lim;
bv_bit_set(r->t_bv_lim_symbols,nsyid);
}

/*:881*/
#line 9973 "./marpa.w"

}
}
}
}
}
}
}

/*:880*/
#line 9892 "./marpa.w"

/*890:*/
#line 10074 "./marpa.w"
{
int min,max,start;

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

/*892:*/
#line 10130 "./marpa.w"

{
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHFA base_to_ahfa= Base_to_AHFA_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
Leo_LHS_NSYID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Ord_of_YS(predecessor_set)<Ord_of_YS(current_earley_set))
{
predecessor_pim
= 
First_PIM_of_YS_by_NSYID(predecessor_set,
predecessor_transition_nsyid);
}
else
{
predecessor_pim= r->t_pim_workarea[predecessor_transition_nsyid];
}
predecessor_lim= 
PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:892*/
#line 10091 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*900:*/
#line 10247 "./marpa.w"

{
const AHFA new_top_ahfa= Top_AHFA_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);


CIL_of_LIM(lim_to_process)= predecessor_cil;
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHFA(new_top_ahfa)> Count_of_CIL(predecessor_cil))
{
const AHFA base_to_ahfa= Base_to_AHFA_of_LIM(lim_to_process);
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
Top_AHFA_of_LIM(lim_to_process)= new_top_ahfa;
}

/*:900*/
#line 10093 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*902:*/
#line 10287 "./marpa.w"
{
const AHFA base_to_AHFA= Base_to_AHFA_of_LIM(lim_to_process);
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHFAIDs_of_AHFA(base_to_AHFA);
}

/*:902*/
#line 10099 "./marpa.w"

continue;
}
/*895:*/
#line 10157 "./marpa.w"
{
int lim_chain_ix;
/*898:*/
#line 10177 "./marpa.w"

{
NSYID postdot_nsyid_of_lim_to_process
= Postdot_NSYID_of_LIM(lim_to_process);
lim_chain_ix= 0;
r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);
bv_bit_clear(bv_ok_for_chain,
postdot_nsyid_of_lim_to_process);


while(1)
{







lim_to_process= predecessor_lim;
postdot_nsyid_of_lim_to_process= Postdot_NSYID_of_LIM(lim_to_process);
if(!bv_bit_test
(bv_ok_for_chain,postdot_nsyid_of_lim_to_process))
{





break;
}

/*892:*/
#line 10130 "./marpa.w"

{
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHFA base_to_ahfa= Base_to_AHFA_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
Leo_LHS_NSYID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Ord_of_YS(predecessor_set)<Ord_of_YS(current_earley_set))
{
predecessor_pim
= 
First_PIM_of_YS_by_NSYID(predecessor_set,
predecessor_transition_nsyid);
}
else
{
predecessor_pim= r->t_pim_workarea[predecessor_transition_nsyid];
}
predecessor_lim= 
PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:892*/
#line 10209 "./marpa.w"


r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,
postdot_nsyid_of_lim_to_process);




if(!predecessor_lim)
break;
if(LIM_is_Populated(predecessor_lim))
break;



}
}

/*:898*/
#line 10159 "./marpa.w"

/*899:*/
#line 10230 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= r->t_lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*900:*/
#line 10247 "./marpa.w"

{
const AHFA new_top_ahfa= Top_AHFA_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);


CIL_of_LIM(lim_to_process)= predecessor_cil;
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHFA(new_top_ahfa)> Count_of_CIL(predecessor_cil))
{
const AHFA base_to_ahfa= Base_to_AHFA_of_LIM(lim_to_process);
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
Top_AHFA_of_LIM(lim_to_process)= new_top_ahfa;
}

/*:900*/
#line 10234 "./marpa.w"

}else{
/*902:*/
#line 10287 "./marpa.w"
{
const AHFA base_to_AHFA= Base_to_AHFA_of_LIM(lim_to_process);
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHFAIDs_of_AHFA(base_to_AHFA);
}

/*:902*/
#line 10236 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:899*/
#line 10160 "./marpa.w"

}

/*:895*/
#line 10102 "./marpa.w"

}
}
}

/*:890*/
#line 9893 "./marpa.w"

}
/*903:*/
#line 10294 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= marpa_obs_new(r->t_obs,PIM,current_earley_set->t_postdot_sym_count);
int min,max,start;
int postdot_array_ix= 0;
for(start= 0;bv_scan(r->t_bv_pim_symbols,start,&min,&max);start= max+2){
NSYID nsyid;
for(nsyid= min;nsyid<=max;nsyid++){
PIM this_pim= r->t_pim_workarea[nsyid];
if(lbv_bit_test(r->t_nsy_expected_is_event,nsyid)){
XSY xsy= Source_XSY_of_NSYID(nsyid);
int_event_new(g,MARPA_EVENT_SYMBOL_EXPECTED,ID_of_XSY(xsy));
}
if(this_pim)postdot_array[postdot_array_ix++]= this_pim;
}
}
}

/*:903*/
#line 9895 "./marpa.w"

bv_and(r->t_bv_nsyid_is_expected,r->t_bv_pim_symbols,g->t_bv_nsyid_is_terminal);
}

/*:877*//*922:*/
#line 10469 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
stack->t_obs= marpa_obs_init;
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:922*//*923:*/
#line 10477 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:923*//*924:*/
#line 10483 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)marpa_obs_free(stack->t_obs);
stack->t_base= NULL;
}

/*:924*//*925:*/
#line 10490 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= marpa_obs_new(stack->t_obs,UR_Object,1);
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:925*//*926:*/
#line 10500 "./marpa.w"

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

/*:926*//*927:*/
#line 10516 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:927*//*931:*/
#line 10578 "./marpa.w"

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
marpa_obs_new(obs,OR,aim_count_of_item);
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

/*:931*//*933:*/
#line 10650 "./marpa.w"

PRIVATE int
Set_boolean_in_PSIA_for_initial_nulls(struct marpa_obstack*bocage_setup_obs,
struct s_bocage_setup_per_ys
*per_ys_data,YIM yim,AIM aim)
{
int null_count= 0;
if(Position_of_AIM(aim)> 0)
{
null_count= Null_Count_of_AIM(aim);
if(null_count)
{
AEX aex= AEX_of_YIM_by_AIM((yim),(aim));
psia_test_and_set(bocage_setup_obs,per_ys_data,(yim),aex);
}
}
return null_count;
}

/*:933*//*967:*/
#line 11150 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,YIM*p_base)
{
const YIM base= Base_YIM_of_LIM(leo_item);
*p_base= base;
if(YIM_is_Predicted(base)){
const AHFA base_to_ahfa= Base_to_AHFA_of_LIM(leo_item);
const AIM base_to_aim= AIM_of_AHFA_by_AEX(base_to_ahfa,0);
const AIM base_aim= Prev_AIM_of_AIM(base_to_aim);
const AHFA base_ahfa= AHFA_of_YIM(base);

return AEX_of_AHFA_by_AIM(base_ahfa,base_aim);
}
return 0;
}

/*:967*//*968:*/
#line 11169 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
YIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_YIM_by_AEX(base,base_aex);
}

/*:968*//*974:*/
#line 11276 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11281 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11282 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11283 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11284 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11285 "./marpa.w"

return YS_Ord_of_OR(or_node);
}

/*:974*//*975:*/
#line 11289 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11294 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11295 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11296 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11297 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11298 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:975*//*976:*/
#line 11302 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11307 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11308 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11309 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11310 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11311 "./marpa.w"

return ID_of_IRL(IRL_of_OR(or_node));
}

/*:976*//*977:*/
#line 11315 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11320 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11321 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11322 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11323 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11324 "./marpa.w"

return Position_of_OR(or_node);
}

/*:977*//*978:*/
#line 11328 "./marpa.w"

int _marpa_b_or_node_is_whole(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11333 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11334 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11335 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11336 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11337 "./marpa.w"

return Position_of_OR(or_node)>=Length_of_IRL(IRL_of_OR(or_node))?1:0;
}

/*:978*//*979:*/
#line 11341 "./marpa.w"

int _marpa_b_or_node_is_semantic(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11346 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11347 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11348 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11349 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11350 "./marpa.w"

return!IRL_has_Virtual_LHS(IRL_of_OR(or_node));
}

/*:979*//*980:*/
#line 11354 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11359 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11360 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11361 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11362 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11363 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:980*//*981:*/
#line 11367 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11372 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11373 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11374 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11375 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11376 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:981*//*982:*/
#line 11381 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11386 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11387 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11388 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11389 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11390 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:982*//*985:*/
#line 11404 "./marpa.w"

int _marpa_o_or_node_and_node_count(Marpa_Order o,
Marpa_Or_Node_ID or_node_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11408 "./marpa.w"

/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 11409 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11410 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11411 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[0];
}
{
OR or_node;
/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11420 "./marpa.w"

return AND_Count_of_OR(or_node);
}
}

/*:985*//*986:*/
#line 11425 "./marpa.w"

int _marpa_o_or_node_and_node_id_by_ix(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11429 "./marpa.w"

/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 11430 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11431 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 11432 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[1+ix];
}
{
OR or_node;
/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 11441 "./marpa.w"

return First_ANDID_of_OR(or_node)+ix;
}
}

/*:986*//*990:*/
#line 11489 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct marpa_obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= marpa_obs_new(obs,DAND_Object,1);
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:990*//*992:*/
#line 11512 "./marpa.w"

PRIVATE
void draft_and_node_add(struct marpa_obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:992*//*1019:*/
#line 11932 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11935 "./marpa.w"

/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11936 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 11937 "./marpa.w"

return AND_Count_of_B(b);
}

/*:1019*//*1021:*/
#line 11963 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11968 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11969 "./marpa.w"

/*1020:*/
#line 11941 "./marpa.w"

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
#line 11970 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1021*//*1022:*/
#line 11974 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11979 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11980 "./marpa.w"

/*1020:*/
#line 11941 "./marpa.w"

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
#line 11981 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1022*//*1023:*/
#line 11990 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 11995 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 11996 "./marpa.w"

/*1020:*/
#line 11941 "./marpa.w"

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
#line 11997 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1023*//*1024:*/
#line 12006 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12011 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12012 "./marpa.w"

/*1020:*/
#line 11941 "./marpa.w"

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
#line 12013 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const XSYID symbol_id= 
OR_is_Token(cause_or)?NSYID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1024*//*1025:*/
#line 12022 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK tkn;
AND and_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12028 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12029 "./marpa.w"

/*1020:*/
#line 11941 "./marpa.w"

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

tkn= and_node_token(and_node);
if(tkn){
if(value_p)
*value_p= Value_of_TOK(tkn);
return NSYID_of_TOK(tkn);
}
return-1;
}
/*:1025*//*1026:*/
#line 12039 "./marpa.w"

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
#line 12057 "./marpa.w"

Marpa_Earley_Set_ID _marpa_b_and_node_middle(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12062 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12063 "./marpa.w"

/*1020:*/
#line 11941 "./marpa.w"

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
#line 12064 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
if(predecessor_or)
{
return YS_Ord_of_OR(predecessor_or);
}
}
return Origin_Ord_of_OR(OR_of_AND(and_node));
}

/*:1027*//*1036:*/
#line 12110 "./marpa.w"

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
#line 12127 "./marpa.w"

int marpa_r_progress_report_start(
Marpa_Recognizer r,
Marpa_Earley_Set_ID set_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12132 "./marpa.w"

YS earley_set;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 12134 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12135 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 12136 "./marpa.w"

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
/*1031:*/
#line 12084 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:1031*/
#line 12149 "./marpa.w"

{
const MARPA_AVL_TREE report_tree= 
_marpa_avl_create(report_item_cmp,NULL);
const YIM*const earley_items= YIMs_of_YS(earley_set);
const int earley_item_count= YIM_Count_of_YS(earley_set);
int earley_item_id;
for(earley_item_id= 0;earley_item_id<earley_item_count;
earley_item_id++)
{
/*1039:*/
#line 12179 "./marpa.w"

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
report_origin= Ord_of_YS(YS_of_LIM(leo_item));
report_AHFA_state= Base_to_AHFA_of_LIM(leo_item);
next_leo_item= Predecessor_LIM_of_LIM(leo_item);
goto INSERT_ITEMS_INTO_TREE;
}
}
NEXT_PHASE:;
}
INSERT_ITEMS_INTO_TREE:
/*1040:*/
#line 12240 "./marpa.w"

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

/*:1040*/
#line 12235 "./marpa.w"

}
NEXT_EARLEY_ITEM:;
}

/*:1039*/
#line 12159 "./marpa.w"

}
r->t_progress_report_traverser= _marpa_avl_t_init(report_tree);
return(int)marpa_avl_count(report_tree);
}
}
/*:1037*//*1038:*/
#line 12166 "./marpa.w"

int marpa_r_progress_report_reset(Marpa_Recognizer r)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12169 "./marpa.w"

MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 12171 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12172 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 12173 "./marpa.w"

/*1043:*/
#line 12321 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:1043*/
#line 12174 "./marpa.w"

_marpa_avl_t_reset(traverser);
return 1;
}

/*:1038*//*1041:*/
#line 12284 "./marpa.w"

int marpa_r_progress_report_finish(Marpa_Recognizer r){
const int success= 1;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12287 "./marpa.w"

/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 12288 "./marpa.w"

const MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*1043:*/
#line 12321 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:1043*/
#line 12290 "./marpa.w"

/*1031:*/
#line 12084 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:1031*/
#line 12291 "./marpa.w"

return success;
}

/*:1041*//*1042:*/
#line 12295 "./marpa.w"

Marpa_Rule_ID marpa_r_progress_item(
Marpa_Recognizer r,int*position,Marpa_Earley_Set_ID*origin
){
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12299 "./marpa.w"

PROGRESS report_item;
MARPA_AVL_TRAV traverser;
/*617:*/
#line 6654 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:617*/
#line 12302 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12303 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 12304 "./marpa.w"

traverser= r->t_progress_report_traverser;
if(_MARPA_UNLIKELY(!position||!origin)){
MARPA_ERROR(MARPA_ERR_POINTER_ARG_NULL);
return failure_indicator;
}
/*1043:*/
#line 12321 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:1043*/
#line 12310 "./marpa.w"

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
#line 12365 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1325:*/
#line 15764 "./marpa.w"
void*const failure_indicator= NULL;
/*:1325*/
#line 12369 "./marpa.w"

/*1056:*/
#line 12427 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int nsy_count= NSY_Count_of_G(g);
const int xsy_count= XSY_Count_of_G(g);
const IRLID irl_count= IRL_Count_of_G(g);
BOCAGE b= NULL;
YS end_of_parse_earley_set;
JEARLEME end_of_parse_earleme;
YIM start_yim= NULL;
AEX start_aex= -1;
struct marpa_obstack*bocage_setup_obs= NULL;
int count_of_earley_items_in_parse;
const int earley_set_count_of_r= YS_Count_of_R(r);

/*:1056*//*1059:*/
#line 12449 "./marpa.w"

struct s_bocage_setup_per_ys*per_ys_data= NULL;

/*:1059*/
#line 12370 "./marpa.w"

INPUT input;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12372 "./marpa.w"

/*1340:*/
#line 15848 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1340*/
#line 12373 "./marpa.w"

{
struct marpa_obstack*const obstack= marpa_obs_init;
b= marpa_obs_new(obstack,struct marpa_bocage,1);
OBS_of_B(b)= obstack;
}
/*954:*/
#line 10908 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:954*//*1055:*/
#line 12422 "./marpa.w"

Valued_BV_of_B(b)= lbv_clone(b->t_obs,r->t_valued,xsy_count);
Valued_Locked_BV_of_B(b)= 
lbv_clone(b->t_obs,r->t_valued_locked,xsy_count);

/*:1055*//*1070:*/
#line 12582 "./marpa.w"

Ambiguity_Metric_of_B(b)= 1;

/*:1070*//*1074:*/
#line 12596 "./marpa.w"

b->t_ref_count= 1;
/*:1074*//*1081:*/
#line 12656 "./marpa.w"

B_is_Nulling(b)= 0;
/*:1081*/
#line 12379 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*1060:*/
#line 12452 "./marpa.w"

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

/*:1060*/
#line 12389 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(XSY_by_ID(g->t_start_xsy_id)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*1064:*/
#line 12525 "./marpa.w"

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
start_yim= earley_item;
start_aex= aex;
break;
}
}
}
if(start_yim)break;
}
}

/*:1064*/
#line 12397 "./marpa.w"

if(!start_yim)goto NO_PARSE;
bocage_setup_obs= marpa_obs_init;
/*1061:*/
#line 12474 "./marpa.w"

{
int ix;
int earley_set_count= YS_Count_of_R(r);
count_of_earley_items_in_parse= 0;
per_ys_data= 
marpa_obs_new(bocage_setup_obs,struct s_bocage_setup_per_ys,earley_set_count);
for(ix= 0;ix<earley_set_count;ix++)
{
const YS_Const earley_set= YS_of_R_by_Ord(r,ix);
const int item_count= YIM_Count_of_YS(earley_set);
count_of_earley_items_in_parse+= item_count;
{
struct s_bocage_setup_per_ys*per_ys= per_ys_data+ix;
OR**const per_yim_yixes= per_ys->t_aexes_by_item= 
marpa_obs_new(bocage_setup_obs,OR*,item_count);
int item_ordinal;
per_ys->t_or_psl= NULL;
per_ys->t_and_psl= NULL;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
per_yim_yixes[item_ordinal]= NULL;
}
}
}
}

/*:1061*/
#line 12400 "./marpa.w"

/*929:*/
#line 10538 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const YIM ur_earley_item= start_yim;
/*930:*/
#line 10566 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:930*/
#line 10545 "./marpa.w"

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
/*932:*/
#line 10606 "./marpa.w"

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
if(YIM_is_Predicted(predecessor_earley_item))
{
Set_boolean_in_PSIA_for_initial_nulls(bocage_setup_obs,per_ys_data,
predecessor_earley_item,
predecessor_aim);
}
else
{
const YIM ur_earley_item= predecessor_earley_item;
/*930:*/
#line 10566 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:930*/
#line 10636 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:932*/
#line 10558 "./marpa.w"

/*934:*/
#line 10669 "./marpa.w"

{
SRCL source_link= NULL;
YIM predecessor_earley_item= NULL;
YIM cause_earley_item= NULL;
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
Set_boolean_in_PSIA_for_initial_nulls
(bocage_setup_obs,per_ys_data,
predecessor_earley_item,predecessor_aim);
}
else
{
const YIM ur_earley_item= predecessor_earley_item;
/*930:*/
#line 10566 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:930*/
#line 10703 "./marpa.w"

}
}
{
const YIM ur_earley_item= cause_earley_item;

/*930:*/
#line 10566 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:930*/
#line 10709 "./marpa.w"

}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:934*/
#line 10559 "./marpa.w"

/*935:*/
#line 10719 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
const YIM cause_earley_item= Cause_of_SRCL(source_link);
LIM leo_predecessor= LIM_of_SRCL(source_link);
{
const YIM ur_earley_item= cause_earley_item;

/*930:*/
#line 10566 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:930*/
#line 10730 "./marpa.w"

}
while(leo_predecessor)
{
const YIM leo_base_yim= Base_YIM_of_LIM(leo_predecessor);
if(YIM_is_Predicted(leo_base_yim))
{
const AHFA leo_final_ahfa= Base_to_AHFA_of_LIM(leo_predecessor);
const AIM leo_final_aim= AIM_of_AHFA_by_AEX(leo_final_ahfa,0);
const AIM prediction_aim= Prev_AIM_of_AIM(leo_final_aim);
Set_boolean_in_PSIA_for_initial_nulls(bocage_setup_obs,per_ys_data,
leo_base_yim,prediction_aim);
}
else
{
const YIM ur_earley_item= leo_base_yim;
/*930:*/
#line 10566 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:930*/
#line 10746 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
}
}

/*:935*/
#line 10560 "./marpa.w"

}
}

/*:929*/
#line 12401 "./marpa.w"

/*956:*/
#line 10926 "./marpa.w"

{
PSAR_Object or_per_ys_arena;
const PSAR or_psar= &or_per_ys_arena;
int work_earley_set_ordinal;
OR last_or_node= NULL;
OR_Capacity_of_B(b)= count_of_earley_items_in_parse;
ORs_of_B(b)= marpa_new(OR,OR_Capacity_of_B(b));
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
{
const int psl_ys_ord= work_earley_set_ordinal;
PSL claimed_psl;
/*1320:*/
#line 15703 "./marpa.w"

{
PSL*psl_owner= &per_ys_data[psl_ys_ord].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
claimed_psl= *psl_owner;
}

/*:1320*/
#line 10948 "./marpa.w"

this_earley_set_psl= claimed_psl;
}
/*957:*/
#line 10958 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;
item_ordinal++)
{
OR*const work_nodes_by_aex= 
nodes_by_item[item_ordinal];
if(work_nodes_by_aex)
{
const YIM work_earley_item= 
yims_of_ys[item_ordinal];
const int work_ahfa_item_count= 
AIM_Count_of_YIM(work_earley_item);
AEX work_aex;
const int work_origin_ordinal= 
Ord_of_YS(Origin_of_YIM(work_earley_item));
for(work_aex= 0;
work_aex<work_ahfa_item_count;work_aex++)
{
if(!work_nodes_by_aex[work_aex])
continue;
/*958:*/
#line 10987 "./marpa.w"

{
AIM ahfa_item= AIM_of_YIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
{
const int psl_ys_ord= work_origin_ordinal;
PSL claimed_psl;
/*1320:*/
#line 15703 "./marpa.w"

{
PSL*psl_owner= &per_ys_data[psl_ys_ord].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
claimed_psl= *psl_owner;
}

/*:1320*/
#line 10998 "./marpa.w"

or_psl= claimed_psl;
}
/*960:*/
#line 11018 "./marpa.w"

{
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const IRL irl= IRL_of_AIM(ahfa_item);
/*961:*/
#line 11048 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
last_or_node= (OR)marpa_obs_new(OBS_of_B(b),OR_Object,1);
ID_of_OR(last_or_node)= or_node_id;
if(_MARPA_UNLIKELY(or_node_id>=OR_Capacity_of_B(b)))
{
OR_Capacity_of_B(b)*= 2;
ORs_of_B(b)= 
marpa_renew(OR,ORs_of_B(b),OR_Capacity_of_B(b));
}
OR_of_B_by_ID(b,or_node_id)= last_or_node;
}


/*:961*/
#line 11028 "./marpa.w"

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

/*:960*/
#line 11001 "./marpa.w"

/*963:*/
#line 11072 "./marpa.w"

{
const int null_count= Null_Count_of_AIM(ahfa_item);
if(null_count> 0)
{
const IRL irl= IRL_of_AIM(ahfa_item);
const int symbol_instance_of_rule= SYMI_of_IRL(irl);
const int first_null_symbol_instance= 
ahfa_item_symbol_instance<
0?symbol_instance_of_rule:ahfa_item_symbol_instance+1;
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
/*961:*/
#line 11048 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
last_or_node= (OR)marpa_obs_new(OBS_of_B(b),OR_Object,1);
ID_of_OR(last_or_node)= or_node_id;
if(_MARPA_UNLIKELY(or_node_id>=OR_Capacity_of_B(b)))
{
OR_Capacity_of_B(b)*= 2;
ORs_of_B(b)= 
marpa_renew(OR,ORs_of_B(b),OR_Capacity_of_B(b));
}
OR_of_B_by_ID(b,or_node_id)= last_or_node;
}


/*:961*/
#line 11092 "./marpa.w"

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

/*:963*/
#line 11002 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*964:*/
#line 11110 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*966:*/
#line 11132 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_YS(YS_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const IRL path_irl= IRL_of_AIM(path_ahfa_item);
const int symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*969:*/
#line 11180 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
{
const int psl_ys_ord= ordinal_of_set_of_this_leo_item;
PSL claimed_psl;
/*1320:*/
#line 15703 "./marpa.w"

{
PSL*psl_owner= &per_ys_data[psl_ys_ord].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
claimed_psl= *psl_owner;
}

/*:1320*/
#line 11188 "./marpa.w"

leo_psl= claimed_psl;
}
or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*961:*/
#line 11048 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
last_or_node= (OR)marpa_obs_new(OBS_of_B(b),OR_Object,1);
ID_of_OR(last_or_node)= or_node_id;
if(_MARPA_UNLIKELY(or_node_id>=OR_Capacity_of_B(b)))
{
OR_Capacity_of_B(b)*= 2;
ORs_of_B(b)= 
marpa_renew(OR,ORs_of_B(b),OR_Capacity_of_B(b));
}
OR_of_B_by_ID(b,or_node_id)= last_or_node;
}


/*:961*/
#line 11194 "./marpa.w"

PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item)= or_node= 
last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= 
symbol_instance_of_path_ahfa_item-SYMI_of_IRL(path_irl)+1;
DANDs_of_OR(or_node)= NULL;
}
}
}

/*:969*/
#line 11142 "./marpa.w"

/*970:*/
#line 11211 "./marpa.w"

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
/*961:*/
#line 11048 "./marpa.w"

{
const int or_node_id= OR_Count_of_B(b)++;
last_or_node= (OR)marpa_obs_new(OBS_of_B(b),OR_Object,1);
ID_of_OR(last_or_node)= or_node_id;
if(_MARPA_UNLIKELY(or_node_id>=OR_Capacity_of_B(b)))
{
OR_Capacity_of_B(b)*= 2;
ORs_of_B(b)= 
marpa_renew(OR,ORs_of_B(b),OR_Capacity_of_B(b));
}
OR_of_B_by_ID(b,or_node_id)= last_or_node;
}


/*:961*/
#line 11228 "./marpa.w"

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

/*:970*/
#line 11143 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:966*/
#line 11118 "./marpa.w"

}
}
}

/*:964*/
#line 11010 "./marpa.w"

}

/*:958*/
#line 10981 "./marpa.w"

}
}
}
}

/*:957*/
#line 10951 "./marpa.w"

/*993:*/
#line 11522 "./marpa.w"

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
/*994:*/
#line 11546 "./marpa.w"

{
while(or_node){
DAND draft_and_node= DANDs_of_OR(or_node);
OR predecessor_or;
if(!draft_and_node)break;
predecessor_or= Predecessor_OR_of_DAND(draft_and_node);
if(predecessor_or&&
YS_Ord_of_OR(predecessor_or)!=work_earley_set_ordinal)
break;
or_node= predecessor_or;
}
}

/*:994*/
#line 11535 "./marpa.w"

if(or_node){
/*995:*/
#line 11560 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_YIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_YIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const int work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
{
const int origin= work_origin_ordinal;
const SYMI symbol_instance= work_symbol_instance;
OR*const p_or_node= &work_proper_or_node;
/*999:*/
#line 11630 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:999*/
#line 11572 "./marpa.w"

}
/*996:*/
#line 11579 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM cause_earley_item= Cause_of_SRCL(source_link);
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*997:*/
#line 11594 "./marpa.w"

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
/*998:*/
#line 11621 "./marpa.w"

{
if(higher_path_leo_item){
/*1002:*/
#line 11657 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AIM aim= AIM_of_YIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
{
OR*const p_or_node= &path_or_node;
const int origin= origin_ordinal;
/*999:*/
#line 11630 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:999*/
#line 11667 "./marpa.w"

}
}

/*:1002*/
#line 11624 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:998*/
#line 11607 "./marpa.w"

/*1000:*/
#line 11636 "./marpa.w"

{
OR dand_cause;

Set_OR_from_YIM_and_AEX(dand_cause,cause_earley_item,0);
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:1000*/
#line 11608 "./marpa.w"

previous_path_irl= path_irl;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_YIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*998:*/
#line 11621 "./marpa.w"

{
if(higher_path_leo_item){
/*1002:*/
#line 11657 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AIM aim= AIM_of_YIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
{
OR*const p_or_node= &path_or_node;
const int origin= origin_ordinal;
/*999:*/
#line 11630 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:999*/
#line 11667 "./marpa.w"

}
}

/*:1002*/
#line 11624 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:998*/
#line 11615 "./marpa.w"

/*1003:*/
#line 11671 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_IRL(previous_path_irl);
const int origin= Ord_of_YS(YS_of_LIM(path_leo_item));
OR*const p_or_node= &dand_cause;
/*999:*/
#line 11630 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:999*/
#line 11677 "./marpa.w"

draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:1003*/
#line 11616 "./marpa.w"

previous_path_irl= path_irl;
}
}

/*:997*/
#line 11588 "./marpa.w"

}
}
}

/*:996*/
#line 11574 "./marpa.w"

/*1004:*/
#line 11682 "./marpa.w"

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
/*1005:*/
#line 11712 "./marpa.w"

{
OR dand_predecessor;
/*1006:*/
#line 11720 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1)
{
dand_predecessor= NULL;
}
else
{
const AEX predecessor_aex= 
AEX_of_YIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_YIM_and_AEX(dand_predecessor,predecessor_earley_item,
predecessor_aex);
}
}

/*:1006*/
#line 11715 "./marpa.w"

draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)tkn);
}

/*:1005*/
#line 11704 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
tkn= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1004*/
#line 11575 "./marpa.w"

/*1007:*/
#line 11735 "./marpa.w"

{
SRCL source_link= NULL;
YIM predecessor_earley_item= NULL;
YIM cause_earley_item= NULL;
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
/*1008:*/
#line 11766 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_YIM(cause_earley_item);

const AIM cause_ahfa_item= AIM_of_YIM_by_AEX(cause_earley_item,0);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_IRL(IRL_of_AIM(cause_ahfa_item));
/*1006:*/
#line 11720 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1)
{
dand_predecessor= NULL;
}
else
{
const AEX predecessor_aex= 
AEX_of_YIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_YIM_and_AEX(dand_predecessor,predecessor_earley_item,
predecessor_aex);
}
}

/*:1006*/
#line 11775 "./marpa.w"

{
const int origin= middle_ordinal;
const SYMI symbol_instance= cause_symbol_instance;
OR*const p_or_node= &dand_cause;
/*999:*/
#line 11630 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:999*/
#line 11780 "./marpa.w"

}
draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:1008*/
#line 11758 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1007*/
#line 11576 "./marpa.w"

}

/*:995*/
#line 11537 "./marpa.w"

}
}
}
}
}

/*:993*/
#line 10952 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= marpa_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:956*/
#line 12402 "./marpa.w"

/*1016:*/
#line 11886 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*1009:*/
#line 11786 "./marpa.w"

{
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_ys_arena;
const PSAR and_psar= &and_per_ys_arena;
int or_node_id= 0;
psar_init(and_psar,irl_count+nsy_count);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
/*1011:*/
#line 11817 "./marpa.w"

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

/*:1011*/
#line 11795 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:1009*/
#line 11889 "./marpa.w"

/*1017:*/
#line 11893 "./marpa.w"

{
const int or_count_of_b= OR_Count_of_B(b);
int or_node_id;
int and_node_id= 0;
const AND ands_of_b= ANDs_of_B(b)= 
marpa_new(AND_Object,unique_draft_and_node_count);
for(or_node_id= 0;or_node_id<or_count_of_b;or_node_id++)
{
int and_count_of_parent_or= 0;
const OR or_node= OR_of_B_by_ID(b,or_node_id);
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
#line 11890 "./marpa.w"

}

/*:1016*/
#line 12403 "./marpa.w"

/*1065:*/
#line 12553 "./marpa.w"

{
const YSID end_of_parse_ordinal= Ord_of_YS(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_ys_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_YIM(start_yim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR root_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(root_or_node);
}

/*:1065*/
#line 12404 "./marpa.w"
;
marpa_obs_free(bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
input_unref(input);
if(b){
/*1077:*/
#line 12632 "./marpa.w"

/*955:*/
#line 10915 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:955*/
#line 12633 "./marpa.w"
;
/*1052:*/
#line 12361 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:1052*/
#line 12634 "./marpa.w"
;

/*:1077*/
#line 12411 "./marpa.w"
;
}
return NULL;
}

/*:1053*//*1067:*/
#line 12566 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12569 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12570 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12571 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:1067*//*1071:*/
#line 12585 "./marpa.w"

int marpa_b_ambiguity_metric(Marpa_Bocage b)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12588 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12589 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12590 "./marpa.w"

return Ambiguity_Metric_of_B(b);
}

/*:1071*//*1075:*/
#line 12599 "./marpa.w"

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
#line 12617 "./marpa.w"

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
#line 12639 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12643 "./marpa.w"

input_unref(input);
if(b)
{
/*1077:*/
#line 12632 "./marpa.w"

/*955:*/
#line 10915 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:955*/
#line 12633 "./marpa.w"
;
/*1052:*/
#line 12361 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:1052*/
#line 12634 "./marpa.w"
;

/*:1077*/
#line 12647 "./marpa.w"
;
}
}

/*:1078*//*1082:*/
#line 12658 "./marpa.w"

int marpa_b_is_null(Marpa_Bocage b)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12661 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12662 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12663 "./marpa.w"

return B_is_Nulling(b);
}

/*:1082*//*1089:*/
#line 12703 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1325:*/
#line 15764 "./marpa.w"
void*const failure_indicator= NULL;
/*:1325*/
#line 12706 "./marpa.w"

/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12707 "./marpa.w"

ORDER o;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12709 "./marpa.w"

o= my_malloc(sizeof(*o));
B_of_O(o)= b;
bocage_ref(b);
/*1086:*/
#line 12691 "./marpa.w"

{
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
OBS_of_O(o)= NULL;
}

/*:1086*//*1092:*/
#line 12721 "./marpa.w"

o->t_ref_count= 1;

/*:1092*//*1104:*/
#line 12809 "./marpa.w"

High_Rank_Count_of_O(o)= 1;
/*:1104*/
#line 12713 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
Ambiguity_Metric_of_O(o)= Ambiguity_Metric_of_B(b);
return o;
}

/*:1089*//*1093:*/
#line 12725 "./marpa.w"

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
#line 12743 "./marpa.w"

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
#line 12757 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 12760 "./marpa.w"

bocage_unref(b);
marpa_obs_free(OBS_of_O(o));
my_free(o);
}

/*:1095*//*1099:*/
#line 12778 "./marpa.w"

int marpa_o_ambiguity_metric(Marpa_Order o)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12781 "./marpa.w"

/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 12782 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12783 "./marpa.w"

return Ambiguity_Metric_of_O(o);
}

/*:1099*//*1102:*/
#line 12792 "./marpa.w"

int marpa_o_is_null(Marpa_Order o)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12795 "./marpa.w"

/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 12796 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12797 "./marpa.w"

return O_is_Nulling(o);
}

/*:1102*//*1105:*/
#line 12811 "./marpa.w"

int marpa_o_high_rank_only_set(
Marpa_Order o,
int count)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12816 "./marpa.w"

/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 12817 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12818 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
if(_MARPA_UNLIKELY(count<0||count> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return High_Rank_Count_of_O(o)= count;
}

/*:1105*//*1106:*/
#line 12833 "./marpa.w"

int marpa_o_high_rank_only(Marpa_Order o)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12836 "./marpa.w"

/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 12837 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12838 "./marpa.w"

return High_Rank_Count_of_O(o);
}

/*:1106*//*1110:*/
#line 12875 "./marpa.w"

int marpa_o_rank(Marpa_Order o)
{
ANDID**and_node_orderings;
struct marpa_obstack*obs;
int bocage_was_reordered= 0;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 12881 "./marpa.w"

/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 12882 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 12883 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*1116:*/
#line 13047 "./marpa.w"

{
int and_id;
const int and_count_of_r= AND_Count_of_B(b);
obs= OBS_of_O(o)= marpa_obs_init;
o->t_and_node_orderings= 
and_node_orderings= 
marpa_obs_new(obs,ANDID*,and_count_of_r);
for(and_id= 0;and_id<and_count_of_r;and_id++)
{
and_node_orderings[and_id]= (ANDID*)NULL;
}
}

/*:1116*/
#line 12889 "./marpa.w"

if(High_Rank_Count_of_O(o)){
/*1111:*/
#line 12904 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
int or_node_id= 0;
int ambiguity_metric= 1;

while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1112:*/
#line 12921 "./marpa.w"

{
if(and_count_of_or> 1)
{
int high_rank_so_far= INT_MIN;
const ANDID first_and_node_id= First_ANDID_of_OR(work_or_node);
const ANDID last_and_node_id= 
(first_and_node_id+and_count_of_or)-1;
ANDID*const order_base= 
marpa_obs_start(obs,
sizeof(ANDID)*((size_t)and_count_of_or+1),
ALIGNOF(ANDID));
ANDID*order= order_base+1;
ANDID and_node_id;
bocage_was_reordered= 1;
for(and_node_id= first_and_node_id;and_node_id<=last_and_node_id;
and_node_id++)
{
const AND and_node= and_nodes+and_node_id;
int and_node_rank;
/*1113:*/
#line 12960 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1113*/
#line 12941 "./marpa.w"

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
marpa_obs_confirm_fast(obs,(int)sizeof(ANDID)*(final_count+1));
and_node_orderings[or_node_id]= marpa_obs_finish(obs);
}
}
}

/*:1112*/
#line 12915 "./marpa.w"

or_node_id++;
}
Ambiguity_Metric_of_O(o)= ambiguity_metric;
}

/*:1111*/
#line 12891 "./marpa.w"

}else{
/*1114:*/
#line 12971 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
const int and_node_count_of_b= AND_Count_of_B(b);
int or_node_id= 0;
int*rank_by_and_id= marpa_new(int,and_node_count_of_b);
int and_node_id;
for(and_node_id= 0;and_node_id<and_node_count_of_b;and_node_id++)
{
const AND and_node= and_nodes+and_node_id;
int and_node_rank;
/*1113:*/
#line 12960 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1113*/
#line 12983 "./marpa.w"

rank_by_and_id[and_node_id]= and_node_rank;
}
while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1115:*/
#line 13016 "./marpa.w"

{
if(and_count_of_or> 1)
{
const ANDID first_and_node_id= First_ANDID_of_OR(work_or_node);
ANDID*const order_base= 
marpa_obs_new(obs,ANDID,and_count_of_or+1);
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
#line 12990 "./marpa.w"

or_node_id++;
}
my_free(rank_by_and_id);
}

/*:1114*/
#line 12893 "./marpa.w"

}
if(!bocage_was_reordered){
marpa_obs_free(obs);
OBS_of_O(o)= NULL;
o->t_and_node_orderings= NULL;
}
O_is_Frozen(o)= 1;
return 1;
}

/*:1110*//*1117:*/
#line 13064 "./marpa.w"

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
#line 13085 "./marpa.w"

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
#line 13099 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13104 "./marpa.w"

/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13105 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13106 "./marpa.w"

/*972:*/
#line 11254 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:972*/
#line 13107 "./marpa.w"

/*973:*/
#line 11266 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:973*/
#line 13108 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
if(!and_order_ix_is_valid(o,or_node,ix))return-1;
return and_order_get(o,or_node,ix);
}

/*:1119*//*1124:*/
#line 13161 "./marpa.w"

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
#line 13179 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1325:*/
#line 15764 "./marpa.w"
void*const failure_indicator= NULL;
/*:1325*/
#line 13182 "./marpa.w"

TREE t;
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13184 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13185 "./marpa.w"

t= my_malloc(sizeof(*t));
O_of_T(t)= o;
order_ref(o);
O_is_Frozen(o)= 1;
/*1142:*/
#line 13370 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1142*/
#line 13190 "./marpa.w"

/*1126:*/
#line 13195 "./marpa.w"

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
t->t_or_node_in_use= bv_create(or_count);
FSTACK_INIT(t->t_nook_stack,NOOK_Object,and_count);
FSTACK_INIT(t->t_nook_worklist,int,and_count);
}
}

/*:1126*//*1129:*/
#line 13219 "./marpa.w"

t->t_ref_count= 1;

/*:1129*//*1136:*/
#line 13298 "./marpa.w"
t->t_pause_counter= 0;
/*:1136*/
#line 13191 "./marpa.w"

return t;
}

/*:1125*//*1130:*/
#line 13223 "./marpa.w"

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
#line 13241 "./marpa.w"

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
#line 13255 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_free(t);
}

/*:1132*//*1137:*/
#line 13299 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1137*//*1138:*/
#line 13308 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1138*//*1139:*/
#line 13318 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13321 "./marpa.w"

const int termination_indicator= -1;
int is_first_tree_attempt= (t->t_parse_count<1);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13324 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13325 "./marpa.w"

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
#line 13399 "./marpa.w"

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

/*:1148*/
#line 13350 "./marpa.w"

}else{
/*1149:*/
#line 13424 "./marpa.w"
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
#line 13352 "./marpa.w"

}
/*1150:*/
#line 13466 "./marpa.w"
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
#line 13529 "./marpa.w"

{
NOOKID new_nook_id= Size_of_T(t);
NOOK new_nook= FSTACK_PUSH(t->t_nook_stack);
*(FSTACK_PUSH(t->t_nook_worklist))= new_nook_id;
Parent_of_NOOK(new_nook)= *p_work_nook_id;
Choice_of_NOOK(new_nook)= choice;
OR_of_NOOK(new_nook)= child_or_node;
NOOK_Cause_is_Expanded(new_nook)= 0;
if((NOOK_is_Cause(new_nook)= Boolean(child_is_cause)))
{
NOOK_Cause_is_Expanded(work_nook)= 1;
}
NOOK_Predecessor_is_Expanded(new_nook)= 0;
if((NOOK_is_Predecessor(new_nook)= Boolean(child_is_predecessor)))
{
NOOK_Predecessor_is_Expanded(work_nook)= 1;
}
}

/*:1151*/
#line 13523 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1150*/
#line 13354 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return termination_indicator;

}

/*:1139*//*1146:*/
#line 13386 "./marpa.w"

PRIVATE int tree_or_node_try(TREE tree,ORID or_node_id)
{
return!bv_bit_test_then_set(tree->t_or_node_in_use,or_node_id);
}
/*:1146*//*1147:*/
#line 13392 "./marpa.w"

PRIVATE void tree_or_node_release(TREE tree,ORID or_node_id)
{
bv_bit_clear(tree->t_or_node_in_use,or_node_id);
}

/*:1147*//*1152:*/
#line 13550 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1152*//*1153:*/
#line 13558 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13561 "./marpa.w"

/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13562 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13563 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return failure_indicator;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1153*//*1160:*/
#line 13624 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13628 "./marpa.w"

/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13629 "./marpa.w"

/*1159:*/
#line 13606 "./marpa.w"
{
NOOK base_nook;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13608 "./marpa.w"

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
#line 13630 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1160*//*1161:*/
#line 13634 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13638 "./marpa.w"

/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13639 "./marpa.w"

/*1159:*/
#line 13606 "./marpa.w"
{
NOOK base_nook;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13608 "./marpa.w"

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
#line 13640 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1161*//*1162:*/
#line 13644 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13648 "./marpa.w"

/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13649 "./marpa.w"

/*1159:*/
#line 13606 "./marpa.w"
{
NOOK base_nook;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13608 "./marpa.w"

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
#line 13650 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1162*//*1163:*/
#line 13654 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13658 "./marpa.w"

/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13659 "./marpa.w"

/*1159:*/
#line 13606 "./marpa.w"
{
NOOK base_nook;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13608 "./marpa.w"

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
#line 13660 "./marpa.w"

return NOOK_Cause_is_Expanded(nook);
}

/*:1163*//*1164:*/
#line 13664 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13668 "./marpa.w"

/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13669 "./marpa.w"

/*1159:*/
#line 13606 "./marpa.w"
{
NOOK base_nook;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13608 "./marpa.w"

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
#line 13670 "./marpa.w"

return NOOK_Predecessor_is_Expanded(nook);
}

/*:1164*//*1165:*/
#line 13674 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13678 "./marpa.w"

/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13679 "./marpa.w"

/*1159:*/
#line 13606 "./marpa.w"
{
NOOK base_nook;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13608 "./marpa.w"

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
#line 13680 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1165*//*1166:*/
#line 13684 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13688 "./marpa.w"

/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13689 "./marpa.w"

/*1159:*/
#line 13606 "./marpa.w"
{
NOOK base_nook;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13608 "./marpa.w"

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
#line 13690 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1166*//*1183:*/
#line 13868 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1325:*/
#line 15764 "./marpa.w"
void*const failure_indicator= NULL;
/*:1325*/
#line 13871 "./marpa.w"

/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13872 "./marpa.w"
;
/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13873 "./marpa.w"

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
/*1174:*/
#line 13794 "./marpa.w"

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

/*:1174*//*1181:*/
#line 13857 "./marpa.w"

MARPA_DSTACK_SAFE(VStack_of_V(v));
/*:1181*//*1186:*/
#line 13905 "./marpa.w"

v->t_ref_count= 1;

/*:1186*//*1193:*/
#line 13958 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1193*//*1195:*/
#line 13965 "./marpa.w"

V_is_Trace(v)= 0;
/*:1195*//*1198:*/
#line 13986 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1198*//*1203:*/
#line 14013 "./marpa.w"

{
XSY_is_Valued_BV_of_V(v)= lbv_clone(v->t_obs,Valued_BV_of_B(b),xsy_count);
Valued_Locked_BV_of_V(v)= 
lbv_clone(v->t_obs,Valued_Locked_BV_of_B(b),xsy_count);
}

/*:1203*/
#line 13885 "./marpa.w"

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

/*:1183*//*1187:*/
#line 13909 "./marpa.w"

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
#line 13927 "./marpa.w"

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
#line 13941 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
/*1182:*/
#line 13859 "./marpa.w"

{
if(_MARPA_LIKELY(MARPA_DSTACK_IS_INITIALIZED(VStack_of_V(v))!=NULL))
{
MARPA_DSTACK_DESTROY(VStack_of_V(v));
}
}

/*:1182*/
#line 13945 "./marpa.w"

/*1176:*/
#line 13810 "./marpa.w"

marpa_obs_free(v->t_obs);

/*:1176*/
#line 13946 "./marpa.w"

}

/*:1189*//*1196:*/
#line 13967 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13970 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1190:*/
#line 13949 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13951 "./marpa.w"


/*:1190*/
#line 13972 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13973 "./marpa.w"

if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= Boolean(flag);
return 1;
}

/*:1196*//*1199:*/
#line 13989 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 13992 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1190:*/
#line 13949 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13951 "./marpa.w"


/*:1190*/
#line 13994 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 13995 "./marpa.w"

if(_MARPA_UNLIKELY(V_is_Nulling(v)))return-1;
if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1199*//*1204:*/
#line 14021 "./marpa.w"

int marpa_v_symbol_is_valued(
Marpa_Value public_v,
Marpa_Symbol_ID xsy_id)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 14026 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1190:*/
#line 13949 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13951 "./marpa.w"


/*:1190*/
#line 14028 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 14029 "./marpa.w"

/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 14030 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 14031 "./marpa.w"

return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
}

/*:1204*//*1205:*/
#line 14037 "./marpa.w"

PRIVATE int symbol_is_valued_set(
VALUE v,XSYID xsy_id,int value)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 14041 "./marpa.w"

const int old_value= lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
if(old_value==value){
lbv_bit_set(Valued_Locked_BV_of_V(v),xsy_id);
return value;
}

if(_MARPA_UNLIKELY(lbv_bit_test(Valued_Locked_BV_of_V(v),xsy_id))){
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
#line 14060 "./marpa.w"

int marpa_v_symbol_is_valued_set(
Marpa_Value public_v,Marpa_Symbol_ID xsy_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 14065 "./marpa.w"

/*1190:*/
#line 13949 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13951 "./marpa.w"


/*:1190*/
#line 14066 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 14067 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1329:*/
#line 15783 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1329*/
#line 14073 "./marpa.w"

/*1330:*/
#line 15790 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1330*/
#line 14074 "./marpa.w"

return symbol_is_valued_set(v,xsy_id,value);
}

/*:1206*//*1207:*/
#line 14080 "./marpa.w"

int
marpa_v_valued_force(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 14085 "./marpa.w"

XSYID xsy_count;
XSYID xsy_id;
/*1190:*/
#line 13949 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13951 "./marpa.w"


/*:1190*/
#line 14088 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 14089 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
for(xsy_id= 0;xsy_id<xsy_count;xsy_id++)
{
if(_MARPA_UNLIKELY(!lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id)&&
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
#line 14104 "./marpa.w"

int marpa_v_rule_is_valued_set(
Marpa_Value public_v,Marpa_Rule_ID xrl_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 14109 "./marpa.w"

/*1190:*/
#line 13949 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13951 "./marpa.w"


/*:1190*/
#line 14110 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 14111 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1336:*/
#line 15824 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}
/*:1336*/
#line 14117 "./marpa.w"

/*1334:*/
#line 15813 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1334*/
#line 14118 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsy_id= LHS_ID_of_XRL(xrl);
return symbol_is_valued_set(v,xsy_id,value);
}
}

/*:1208*//*1210:*/
#line 14133 "./marpa.w"

Marpa_Step_Type marpa_v_step(Marpa_Value public_v)
{
/*1326:*/
#line 15767 "./marpa.w"
const int failure_indicator= -2;

/*:1326*/
#line 14136 "./marpa.w"

const VALUE v= (VALUE)public_v;

if(V_is_Nulling(v)){
/*1190:*/
#line 13949 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13951 "./marpa.w"


/*:1190*/
#line 14140 "./marpa.w"

/*1212:*/
#line 14221 "./marpa.w"

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
#line 14141 "./marpa.w"

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
#line 13949 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13951 "./marpa.w"


/*:1190*/
#line 14152 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
lbv_fill(Valued_Locked_BV_of_V(v),xsy_count);
/*1211:*/
#line 14205 "./marpa.w"

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
#line 14155 "./marpa.w"

}

case STEP_GET_DATA:
/*1213:*/
#line 14244 "./marpa.w"

{
AND and_nodes;





int pop_arguments= 1;
/*1190:*/
#line 13949 "./marpa.w"

TREE t= T_of_V(v);
/*1123:*/
#line 13157 "./marpa.w"

ORDER o= O_of_T(t);
/*1096:*/
#line 12766 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1050:*/
#line 12352 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:1050*/
#line 12768 "./marpa.w"


/*:1096*/
#line 13159 "./marpa.w"
;

/*:1123*/
#line 13951 "./marpa.w"


/*:1190*/
#line 14253 "./marpa.w"

/*1343:*/
#line 15863 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1343*/
#line 14254 "./marpa.w"

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

/*:1213*/
#line 14159 "./marpa.w"

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

/*:1210*//*1215:*/
#line 14387 "./marpa.w"

PRIVATE int lbv_bits_to_size(int bits)
{
const LBW result= ((LBW)bits+(lbv_wordbits-1))/lbv_wordbits;
return(int)result;
}

/*:1215*//*1216:*/
#line 14395 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new(struct marpa_obstack*obs,int bits)
{
int size= lbv_bits_to_size(bits);
LBV lbv= marpa_obs_new(obs,LBW,size);
return lbv;
}

/*:1216*//*1217:*/
#line 14405 "./marpa.w"

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
#line 14418 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new0(struct marpa_obstack*obs,int bits)
{
LBV lbv= lbv_obs_new(obs,bits);
return lbv_zero(lbv,bits);
}

/*:1218*//*1220:*/
#line 14437 "./marpa.w"

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

/*:1220*//*1221:*/
#line 14453 "./marpa.w"

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
#line 14489 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(int bits)
{
return((LBW)bits+bv_modmask)/bv_wordbits;
}
/*:1224*//*1225:*/
#line 14495 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(int bits)
{
LBW mask= (LBW)bits&bv_modmask;
if(mask)mask= (LBW)~(~0uL<<mask);else mask= (LBW)~0uL;
return(mask);
}

/*:1225*//*1227:*/
#line 14509 "./marpa.w"

PRIVATE Bit_Vector bv_create(int bits)
{
LBW size= bv_bits_to_size(bits);
LBW bytes= (size+bv_hiddenwords)*sizeof(Bit_Vector_Word);
LBW*addr= (Bit_Vector)my_malloc0((size_t)bytes);
*addr++= (LBW)bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}

/*:1227*//*1229:*/
#line 14527 "./marpa.w"

PRIVATE Bit_Vector
bv_obs_create(struct marpa_obstack*obs,int bits)
{
LBW size= bv_bits_to_size(bits);
LBW bytes= (size+bv_hiddenwords)*sizeof(Bit_Vector_Word);
LBW*addr= (Bit_Vector)marpa__obs_alloc(obs,(size_t)bytes,ALIGNOF(LBW));
*addr++= (LBW)bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
if(size> 0){
Bit_Vector bv= addr;
while(size--)*bv++= 0u;
}
return addr;
}


/*:1229*//*1230:*/
#line 14548 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create((int)BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct marpa_obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,(int)BV_BITS(bv));
}

/*:1230*//*1231:*/
#line 14562 "./marpa.w"

PRIVATE
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from)
{
LBW*p_to= bv_to;
const LBW bits= BV_BITS(bv_to);
if(bits> 0)
{
LBW count= BV_SIZE(bv_to);
while(count--)*p_to++= *bv_from++;
}
return(bv_to);
}

/*:1231*//*1232:*/
#line 14580 "./marpa.w"

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

/*:1232*//*1233:*/
#line 14594 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(_MARPA_LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1233*//*1234:*/
#line 14605 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1234*//*1235:*/
#line 14616 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1235*//*1237:*/
#line 14630 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
LBW length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1237*//*1239:*/
#line 14639 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1239*//*1240:*/
#line 14647 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1240*//*1241:*/
#line 14655 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1241*//*1242:*/
#line 14667 "./marpa.w"

PRIVATE int
bv_bit_test_then_set(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
Bit_Vector addr= vector+(bit/bv_wordbits);
LBW mask= bv_lsb<<(bit%bv_wordbits);
if((*addr&mask)!=0u)
return 1;
*addr|= mask;
return 0;
}

/*:1242*//*1243:*/
#line 14681 "./marpa.w"

PRIVATE
int bv_is_empty(Bit_Vector addr)
{
LBW size= BV_SIZE(addr);
int r= 1;
if(size> 0){
*(addr+size-1)&= BV_MASK(addr);
while(r&&(size--> 0))r= (*addr++==0);
}
return(r);
}

/*:1243*//*1244:*/
#line 14695 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1244*//*1245:*/
#line 14705 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1245*//*1246:*/
#line 14715 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1246*//*1247:*/
#line 14725 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1247*//*1248:*/
#line 14735 "./marpa.w"

PRIVATE_NOT_INLINE
int bv_scan(Bit_Vector bv,int raw_start,int*raw_min,int*raw_max)
{
LBW start= (LBW)raw_start;
LBW min;
LBW max;
LBW size= BV_SIZE(bv);
LBW mask= BV_MASK(bv);
LBW offset;
LBW bitmask;
LBW value;
int empty;

if(size==0)return 0;
if(start>=BV_BITS(bv))return 0;
min= start;
max= start;
offset= start/bv_wordbits;
*(bv+size-1)&= mask;
bv+= offset;
size-= offset;
bitmask= (LBW)1<<(start&bv_modmask);
mask= ~(bitmask|(bitmask-(LBW)1));
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
if(empty){
*raw_min= (int)min;
*raw_max= (int)max;
return 0;
}
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
min= start;
max= start;
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
max= --start;
*raw_min= (int)min;
*raw_max= (int)max;
return 1;
}

/*:1248*//*1249:*/
#line 14815 "./marpa.w"

PRIVATE int
bv_count(Bit_Vector v)
{
int start,min,max;
int count= 0;
for(start= 0;bv_scan(v,start,&min,&max);start= max+2)
{
count+= max-min+1;
}
return count;
}

/*:1249*//*1254:*/
#line 14863 "./marpa.w"

PRIVATE void
rhs_closure(GRAMMAR g,Bit_Vector bv,XRLID**xrl_list_x_rh_sym)
{
int min,max,start= 0;
Marpa_Symbol_ID*end_of_stack= NULL;
FSTACK_DECLARE(stack,XSYID)
FSTACK_INIT(stack,XSYID,XSY_Count_of_G(g));
while(bv_scan(bv,start,&min,&max))
{
XSYID xsy_id;
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

if(bv_bit_test(bv,lhs_id))
goto NEXT_RULE;
rule_length= Length_of_XRL(rule);






for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test
(bv,RHS_ID_of_XRL(rule,rh_ix)))
goto NEXT_RULE;
}





if(is_sequence&&Minimum_of_XRL(rule)>=2)
{
XSYID separator_id= Separator_of_XRL(rule);
if(separator_id>=0)
{
if(!bv_bit_test(bv,separator_id))
goto NEXT_RULE;
}
}




bv_bit_set(bv,lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}

/*:1254*//*1259:*/
#line 14970 "./marpa.w"

PRIVATE Bit_Matrix
matrix_buffer_create(void*buffer,int rows,int columns)
{
int row;
const LBW bv_data_words= bv_bits_to_size(columns);
const LBW bv_mask= bv_bits_to_unused_mask(columns);

Bit_Matrix matrix_addr= buffer;
matrix_addr->t_row_count= rows;
for(row= 0;row<rows;row++){
const LBW row_start= (LBW)row*(bv_data_words+bv_hiddenwords);
LBW*p_current_word= matrix_addr->t_row_data+row_start;
LBW data_word_counter= bv_data_words;
*p_current_word++= (LBW)columns;
*p_current_word++= bv_data_words;
*p_current_word++= bv_mask;
while(data_word_counter--)*p_current_word++= 0;
}
return matrix_addr;
}

/*:1259*//*1261:*/
#line 14993 "./marpa.w"

PRIVATE size_t matrix_sizeof(int rows,int columns)
{
const LBW bv_data_words= bv_bits_to_size(columns);
const LBW row_bytes= 
(bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
return offsetof(struct s_bit_matrix,t_row_data)+((size_t)rows)*row_bytes;
}

/*:1261*//*1263:*/
#line 15003 "./marpa.w"

PRIVATE Bit_Matrix matrix_obs_create(
struct marpa_obstack*obs,
int rows,
int columns)
{

Bit_Matrix matrix_addr= 
marpa__obs_alloc(obs,matrix_sizeof(rows,columns),ALIGNOF(Bit_Matrix_Object));
return matrix_buffer_create(matrix_addr,rows,columns);
}

/*:1263*//*1264:*/
#line 15016 "./marpa.w"

PRIVATE void matrix_clear(Bit_Matrix matrix)
{
Bit_Vector row;
int row_ix;
const int row_count= matrix->t_row_count;
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
LBW words_per_row= BV_SIZE(row0)+bv_hiddenwords;
row_ix= 0;row= row0;
while(row_ix<row_count){
bv_clear(row);
row_ix++;
row+= words_per_row;
}
}

/*:1264*//*1265:*/
#line 15038 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
return(int)BV_BITS(row0);
}

/*:1265*//*1266:*/
#line 15054 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,int row)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
LBW words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+(LBW)row*words_per_row;
}

/*:1266*//*1268:*/
#line 15063 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1268*//*1270:*/
#line 15071 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1270*//*1272:*/
#line 15079 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1272*//*1273:*/
#line 15096 "./marpa.w"

PRIVATE_NOT_INLINE void transitive_closure(Bit_Matrix matrix)
{
int size= matrix_columns(matrix);
int outer_row;
for(outer_row= 0;outer_row<size;outer_row++)
{
Bit_Vector outer_row_v= matrix_row(matrix,outer_row);
int column;
for(column= 0;column<size;column++)
{
Bit_Vector inner_row_v= matrix_row(matrix,column);
if(bv_bit_test(inner_row_v,outer_row))
{
bv_or_assign(inner_row_v,outer_row_v);
}
}
}
}

/*:1273*//*1285:*/
#line 15237 "./marpa.w"

PRIVATE void
cilar_init(const CILAR cilar)
{
cilar->t_obs= marpa_obs_init;
cilar->t_avl= _marpa_avl_create(cil_cmp,NULL);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}
/*:1285*//*1286:*/
#line 15251 "./marpa.w"

PRIVATE void
cilar_reinit(const CILAR cilar)
{
MARPA_DSTACK_DESTROY(cilar->t_buffer);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}

/*:1286*//*1287:*/
#line 15260 "./marpa.w"

PRIVATE void cilar_destroy(const CILAR cilar)
{
_marpa_avl_destroy(cilar->t_avl);
marpa_obs_free(cilar->t_obs);
MARPA_DSTACK_DESTROY((cilar->t_buffer));
}

/*:1287*//*1288:*/
#line 15269 "./marpa.w"

PRIVATE CIL cil_empty(CILAR cilar)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);

Count_of_CIL(cil)= 0;
return cil_buffer_add(cilar);
}

/*:1288*//*1289:*/
#line 15279 "./marpa.w"

PRIVATE CIL cil_singleton(CILAR cilar,int element)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);
Count_of_CIL(cil)= 1;
Item_of_CIL(cil,0)= element;

return cil_buffer_add(cilar);
}

/*:1289*//*1290:*/
#line 15295 "./marpa.w"

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

/*:1290*//*1291:*/
#line 15323 "./marpa.w"

PRIVATE CIL cil_bv_add(CILAR cilar,Bit_Vector bv)
{
int min,max,start= 0;
cil_buffer_clear(cilar);
for(start= 0;bv_scan(bv,start,&min,&max);start= max+2)
{
int new_item;
for(new_item= min;new_item<=max;new_item++)
{
cil_buffer_push(cilar,new_item);
}
}
return cil_buffer_add(cilar);
}

/*:1291*//*1292:*/
#line 15340 "./marpa.w"

PRIVATE void cil_buffer_clear(CILAR cilar)
{
const MARPA_DSTACK dstack= &cilar->t_buffer;
MARPA_DSTACK_CLEAR(*dstack);



*MARPA_DSTACK_PUSH(*dstack,int)= 0;
}

/*:1292*//*1293:*/
#line 15354 "./marpa.w"

PRIVATE CIL cil_buffer_push(CILAR cilar,int new_item)
{
CIL cil_in_buffer;
MARPA_DSTACK dstack= &cilar->t_buffer;
*MARPA_DSTACK_PUSH(*dstack,int)= new_item;


cil_in_buffer= MARPA_DSTACK_BASE(*dstack,int);
Count_of_CIL(cil_in_buffer)++;
return cil_in_buffer;
}

/*:1293*//*1294:*/
#line 15369 "./marpa.w"

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

/*:1294*//*1295:*/
#line 15388 "./marpa.w"

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

/*:1295*//*1296:*/
#line 15441 "./marpa.w"

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

/*:1296*//*1297:*/
#line 15476 "./marpa.w"

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

/*:1297*//*1310:*/
#line 15604 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1310*//*1311:*/
#line 15611 "./marpa.w"

PRIVATE void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl)
{
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
if(owner)
*owner= NULL;
my_free(psl);
psl= next_psl;
}
}
/*:1311*//*1312:*/
#line 15625 "./marpa.w"

PRIVATE PSL psl_new(const PSAR psar)
{
int i;
PSL new_psl= my_malloc(Sizeof_PSL(psar));
new_psl->t_next= NULL;
new_psl->t_prev= NULL;
new_psl->t_owner= NULL;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(new_psl,i)= NULL;
}
return new_psl;
}
/*:1312*//*1315:*/
#line 15656 "./marpa.w"

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

/*:1315*//*1317:*/
#line 15674 "./marpa.w"

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

/*:1317*//*1319:*/
#line 15694 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1319*//*1321:*/
#line 15716 "./marpa.w"

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

/*:1321*//*1346:*/
#line 15907 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}
/*:1346*//*1347:*/
#line 15926 "./marpa.w"

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

/*:1347*//*1351:*/
#line 15969 "./marpa.w"

PRIVATE_NOT_INLINE void*
marpa__default_out_of_memory(void)
{
abort();
}
void*(*const marpa__out_of_memory)(void)= marpa__default_out_of_memory;

/*:1351*//*1355:*/
#line 15994 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
marpa__debug_handler= debug_handler;
}

/*:1355*//*1356:*/
#line 16000 "./marpa.w"

int marpa_debug_level_set(int new_level)
{
const int old_level= marpa__debug_level;
marpa__debug_level= new_level;
return old_level;
}


/*:1356*/
#line 16179 "./marpa.w"


/*:1374*/
