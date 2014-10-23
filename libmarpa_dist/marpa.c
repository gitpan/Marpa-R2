/*
 * Copyright 2014 Jeffrey Kegler
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

/*1327:*/
#line 15783 "./marpa.w"


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
#define IRL_by_ID(id) (*MARPA_DSTACK_INDEX((g) ->t_irl_stack,IRL,(id) ) )  \

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
#define Nulling_OR_by_NSYID(nsyid) ((OR) &NSY_by_ID(nsyid) ->t_nulling_or_node) 
#define Unvalued_OR_by_NSYID(nsyid) ((OR) &NSY_by_ID(nsyid) ->t_unvalued_or_node) 
#define NSY_by_ID(id) (*MARPA_DSTACK_INDEX(g->t_nsy_stack,NSY,(id) ) ) 
#define ID_of_NSY(nsy) ((nsy) ->t_nulling_or_node.t_nsyid)  \

#define NSY_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_nsy_stack) ) 
#define NSY_is_Start(nsy) ((nsy) ->t_is_start) 
#define NSY_is_LHS(nsy) ((nsy) ->t_is_lhs) 
#define NSY_is_Nulling(nsy) ((nsy) ->t_nsy_is_nulling) 
#define LHS_CIL_of_NSY(nsy) ((nsy) ->t_lhs_cil) 
#define LHS_CIL_of_NSYID(nsyid) LHS_CIL_of_NSY(NSY_by_ID(nsyid) ) 
#define NSY_is_Semantic(nsy) ((nsy) ->t_is_semantic) 
#define NSYID_is_Semantic(nsyid) (NSY_is_Semantic(NSY_by_ID(nsyid) ) ) 
#define Source_XSY_of_NSY(nsy) ((nsy) ->t_source_xsy) 
#define Source_XSY_of_NSYID(nsyid) (Source_XSY_of_NSY(NSY_by_ID(nsyid) ) ) 
#define Source_XSYID_of_NSYID(nsyid)  \
ID_of_XSY(Source_XSY_of_NSYID(nsyid) ) 
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
#define IRL_is_Unit_Rule(irl) ((irl) ->t_ahm_count==2) 
#define AHM_Count_of_IRL(irl) ((irl) ->t_ahm_count) 
#define IRL_has_Virtual_LHS(irl) ((irl) ->t_is_virtual_lhs) 
#define IRL_has_Virtual_RHS(irl) ((irl) ->t_is_virtual_rhs) 
#define IRL_is_Right_Recursive(irl) ((irl) ->t_is_right_recursive) 
#define IRL_is_Leo(irl) IRL_is_Right_Recursive(irl) 
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
#define First_AHM_of_IRL(irl) ((irl) ->t_first_ahm) 
#define First_AHM_of_IRLID(irlid) (IRL_by_ID(irlid) ->t_first_ahm) 
#define AHM_by_ID(id) (g->t_ahms+(id) ) 
#define ID_of_AHM(ahm) ((ahm) -g->t_ahms) 
#define Next_AHM_of_AHM(ahm) ((ahm) +1) 
#define Prev_AHM_of_AHM(ahm) ((ahm) -1)  \

#define AHM_Count_of_G(g) ((g) ->t_ahm_count) 
#define IRL_of_AHM(ahm) ((ahm) ->t_irl) 
#define IRLID_of_AHM(item) ID_of_IRL(IRL_of_AHM(item) ) 
#define LHS_NSYID_of_AHM(item) LHSID_of_IRL(IRL_of_AHM(item) ) 
#define LHSID_of_AHM(item) LHS_NSYID_of_AHM(item) 
#define Postdot_NSYID_of_AHM(item) ((item) ->t_postdot_nsyid) 
#define AHM_is_Completion(ahm) (Postdot_NSYID_of_AHM(ahm) <0) 
#define AHM_is_Leo(ahm) (IRL_is_Leo(IRL_of_AHM(ahm) ) ) 
#define AHM_is_Leo_Completion(ahm)  \
(AHM_is_Completion(ahm) &&AHM_is_Leo(ahm) ) 
#define Null_Count_of_AHM(ahm) ((ahm) ->t_leading_nulls) 
#define Position_of_AHM(ahm) ((ahm) ->t_position) 
#define Raw_Position_of_AHM(ahm)  \
(Position_of_AHM(ahm) <0?Length_of_IRL(IRL_of_AHM(ahm) ) ) 
#define AHM_is_Prediction(ahm) (Quasi_Position_of_AHM(ahm) ==0)  \

#define Quasi_Position_of_AHM(ahm) ((ahm) ->t_quasi_position) 
#define SYMI_of_AHM(ahm) ((ahm) ->t_symbol_instance) 
#define SYMI_Count_of_G(g) ((g) ->t_symbol_instance_count) 
#define SYMI_of_IRL(irl) ((irl) ->t_symbol_instance_base) 
#define Last_Proper_SYMI_of_IRL(irl) ((irl) ->t_last_proper_symi) 
#define SYMI_of_Completed_IRL(irl)  \
(SYMI_of_IRL(irl) +Length_of_IRL(irl) -1) 
#define Predicted_IRL_CIL_of_AHM(ahm) ((ahm) ->t_predicted_irl_cil) 
#define LHS_CIL_of_AHM(ahm) ((ahm) ->t_lhs_cil) 
#define ZWA_CIL_of_AHM(ahm) ((ahm) ->t_zwa_cil) 
#define AHM_predicts_ZWA(ahm) ((ahm) ->t_predicts_zwa) 
#define Completion_XSYIDs_of_AHM(ahm) ((ahm) ->t_completion_xsyids) 
#define Nulled_XSYIDs_of_AHM(ahm) ((ahm) ->t_nulled_xsyids) 
#define Prediction_XSYIDs_of_AHM(ahm) ((ahm) ->t_prediction_xsyids) 
#define AHM_was_Predicted(ahm) ((ahm) ->t_was_predicted) 
#define YIM_was_Predicted(yim) AHM_was_Predicted(AHM_of_YIM(yim) ) 
#define AHM_is_Initial(ahm) ((ahm) ->t_is_initial) 
#define YIM_is_Initial(yim) AHM_is_Initial(AHM_of_YIM(yim) ) 
#define XRL_of_AHM(ahm) ((ahm) ->t_xrl) 
#define XRL_Position_of_AHM(ahm) ((ahm) ->t_xrl_position) 
#define Raw_XRL_Position_of_AHM(ahm) ( \
XRL_Position_of_AHM(ahm) <0 \
?Length_of_XRL(XRL_of_AHM(ahm) )  \
:XRL_Position_of_AHM(ahm)  \
) 
#define Event_Group_Size_of_AHM(ahm) ((ahm) ->t_event_group_size) 
#define Event_AHMIDs_of_AHM(ahm) ((ahm) ->t_event_ahmids) 
#define AHM_has_Event(ahm) (Count_of_CIL(Event_AHMIDs_of_AHM(ahm) ) !=0) 
#define ZWAID_is_Malformed(zwaid) ((zwaid) <0) 
#define ZWAID_of_G_Exists(zwaid) ((zwaid) <ZWA_Count_of_G(g) ) 
#define ZWA_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_gzwa_stack) ) 
#define GZWA_by_ID(id) (*MARPA_DSTACK_INDEX((g) ->t_gzwa_stack,GZWA,(id) ) ) 
#define ID_of_GZWA(zwa) ((zwa) ->t_id) 
#define Default_Value_of_GZWA(zwa) ((zwa) ->t_default_value) 
#define XRLID_of_ZWP(zwp) ((zwp) ->t_xrl_id) 
#define Dot_of_ZWP(zwp) ((zwp) ->t_dot) 
#define ZWAID_of_ZWP(zwp) ((zwp) ->t_zwaid) 
#define G_of_R(r) ((r) ->t_grammar) 
#define R_BEFORE_INPUT 0x1
#define R_DURING_INPUT 0x2
#define R_AFTER_INPUT 0x3
#define Input_Phase_of_R(r) ((r) ->t_input_phase) 
#define First_YS_of_R(r) ((r) ->t_first_earley_set) 
#define Latest_YS_of_R(r) ((r) ->t_latest_earley_set) 
#define Current_Earleme_of_R(r) ((r) ->t_current_earleme) 
#define YS_at_Current_Earleme_of_R(r) ys_at_current_earleme(r) 
#define DEFAULT_YIM_WARNING_THRESHOLD (100) 
#define Furthest_Earleme_of_R(r) ((r) ->t_furthest_earleme) 
#define R_is_Exhausted(r) ((r) ->t_is_exhausted) 
#define First_Inconsistent_YS_of_R(r) ((r) ->t_first_inconsistent_ys) 
#define R_is_Consistent(r) ((r) ->t_first_inconsistent_ys<0) 
#define ID_of_ZWA(zwa) ((zwa) ->t_id) 
#define Memo_YSID_of_ZWA(zwa) ((zwa) ->t_memoized_ysid) 
#define Memo_Value_of_ZWA(zwa) ((zwa) ->t_memoized_value) 
#define Default_Value_of_ZWA(zwa) ((zwa) ->t_default_value) 
#define ZWA_Count_of_R(r) (ZWA_Count_of_G(G_of_R(r) ) ) 
#define RZWA_by_ID(id) (&(r) ->t_zwas[(zwaid) ]) 
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
#define LHS_NSYID_of_YIM(yim)  \
LHS_NSYID_of_AHM(AHM_of_YIM(yim) ) 
#define YIM_is_Completion(item)  \
(AHM_is_Completion(AHM_of_YIM(item) ) ) 
#define YS_of_YIM(yim) ((yim) ->t_key.t_set) 
#define YS_Ord_of_YIM(yim) (Ord_of_YS(YS_of_YIM(yim) ) ) 
#define Ord_of_YIM(yim) ((yim) ->t_ordinal) 
#define Earleme_of_YIM(yim) Earleme_of_YS(YS_of_YIM(yim) ) 
#define AHM_of_YIM(yim) ((yim) ->t_key.t_ahm) 
#define AHMID_of_YIM(yim) ID_of_AHM(AHM_of_YIM(yim) ) 
#define Postdot_NSYID_of_YIM(yim) Postdot_NSYID_of_AHM(AHM_of_YIM(yim) ) 
#define IRL_of_YIM(yim) IRL_of_AHM(AHM_of_YIM(yim) ) 
#define IRLID_of_YIM(yim) ID_of_IRL(IRL_of_YIM(yim) ) 
#define Origin_Earleme_of_YIM(yim) (Earleme_of_YS(Origin_of_YIM(yim) ) ) 
#define Origin_Ord_of_YIM(yim) (Ord_of_YS(Origin_of_YIM(yim) ) ) 
#define Origin_of_YIM(yim) ((yim) ->t_key.t_origin) 
#define YIM_ORDINAL_WIDTH 16
#define YIM_ORDINAL_CLAMP(x) (((1<<(YIM_ORDINAL_WIDTH) ) -1) &(x) ) 
#define YIM_FATAL_THRESHOLD ((1<<(YIM_ORDINAL_WIDTH) ) -2) 
#define YIM_is_Rejected(yim) ((yim) ->t_is_rejected) 
#define YIM_is_Active(yim) ((yim) ->t_is_active) 
#define YIM_was_Scanned(yim) ((yim) ->t_was_scanned) 
#define YIM_was_Fusion(yim) ((yim) ->t_was_fusion) 
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
#define Top_AHM_of_LIM(leo) ((leo) ->t_top_ahm) 
#define Trailhead_AHM_of_LIM(leo) ((leo) ->t_trailhead_ahm) 
#define Predecessor_LIM_of_LIM(leo) ((leo) ->t_predecessor) 
#define Trailhead_YIM_of_LIM(leo) ((leo) ->t_base) 
#define YS_of_LIM(leo) ((leo) ->t_set) 
#define Earleme_of_LIM(lim) Earleme_of_YS(YS_of_LIM(lim) ) 
#define LIM_is_Rejected(lim) ((lim) ->t_is_rejected) 
#define LIM_is_Active(lim) ((lim) ->t_is_active) 
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
#define SRC_of_SRCL(link) (&Source_of_SRCL(link) ) 
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
#define NSYID_of_Source(srcd) ((srcd) .t_cause.t_token.t_nsyid) 
#define NSYID_of_SRC(source) NSYID_of_Source(*(source) ) 
#define NSYID_of_YIM(yim) NSYID_of_Source(Source_of_YIM(yim) ) 
#define NSYID_of_SRCL(link) NSYID_of_Source(Source_of_SRCL(link) ) 
#define Value_of_Source(srcd) ((srcd) .t_cause.t_token.t_value) 
#define Value_of_SRC(source) Value_of_Source(*(source) ) 
#define Value_of_SRCL(link) Value_of_Source(Source_of_SRCL(link) )  \

#define SRC_is_Active(src) ((src) ->t_is_active) 
#define SRC_is_Rejected(src) ((src) ->t_is_rejected) 
#define SRCL_is_Active(link) ((link) ->t_source.t_is_active) 
#define SRCL_is_Rejected(link) ((link) ->t_source.t_is_rejected)  \

#define Cause_AHMID_of_SRCL(srcl)  \
AHMID_of_YIM((YIM) Cause_of_SRCL(srcl) ) 
#define Leo_Transition_NSYID_of_SRCL(leo_source_link)  \
Postdot_NSYID_of_LIM(LIM_of_SRCL(leo_source_link) )  \

#define LV_First_Completion_SRCL_of_YIM(item) ((item) ->t_container.t_ambiguous.t_completion) 
#define First_Completion_SRCL_of_YIM(item)  \
(Source_Type_of_YIM(item) ==SOURCE_IS_COMPLETION?(SRCL) SRCL_of_YIM(item) : \
Source_Type_of_YIM(item) ==SOURCE_IS_AMBIGUOUS? \
LV_First_Completion_SRCL_of_YIM(item) :NULL)  \

#define LV_First_Token_SRCL_of_YIM(item) ((item) ->t_container.t_ambiguous.t_token) 
#define First_Token_SRCL_of_YIM(item)  \
(Source_Type_of_YIM(item) ==SOURCE_IS_TOKEN?(SRCL) SRCL_of_YIM(item) : \
Source_Type_of_YIM(item) ==SOURCE_IS_AMBIGUOUS? \
LV_First_Token_SRCL_of_YIM(item) :NULL)  \

#define LV_First_Leo_SRCL_of_YIM(item) ((item) ->t_container.t_ambiguous.t_leo) 
#define First_Leo_SRCL_of_YIM(item)  \
(Source_Type_of_YIM(item) ==SOURCE_IS_LEO?(SRCL) SRCL_of_YIM(item) : \
Source_Type_of_YIM(item) ==SOURCE_IS_AMBIGUOUS? \
LV_First_Leo_SRCL_of_YIM(item) :NULL)  \

#define NSYID_of_ALT(alt) ((alt) ->t_nsyid) 
#define Value_of_ALT(alt) ((alt) ->t_value) 
#define ALT_is_Valued(alt) ((alt) ->t_is_valued) 
#define Start_YS_of_ALT(alt) ((alt) ->t_start_earley_set) 
#define Start_Earleme_of_ALT(alt) Earleme_of_YS(Start_YS_of_ALT(alt) ) 
#define End_Earleme_of_ALT(alt) ((alt) ->t_end_earleme) 
#define Work_YIMs_of_R(r) MARPA_DSTACK_BASE((r) ->t_yim_work_stack,YIM) 
#define Work_YIM_Count_of_R(r) MARPA_DSTACK_LENGTH((r) ->t_yim_work_stack) 
#define WORK_YIMS_CLEAR(r) MARPA_DSTACK_CLEAR((r) ->t_yim_work_stack) 
#define WORK_YIM_PUSH(r) MARPA_DSTACK_PUSH((r) ->t_yim_work_stack,YIM) 
#define WORK_YIM_ITEM(r,ix) (*MARPA_DSTACK_INDEX((r) ->t_yim_work_stack,YIM,ix) ) 
#define P_YS_of_R_by_Ord(r,ord) MARPA_DSTACK_INDEX((r) ->t_earley_set_stack,YS,(ord) ) 
#define YS_of_R_by_Ord(r,ord) (*P_YS_of_R_by_Ord((r) ,(ord) ) ) 
#define LIM_is_Populated(leo) (Origin_of_LIM(leo) !=NULL) 
#define RULEID_of_PROGRESS(report) ((report) ->t_rule_id) 
#define Position_of_PROGRESS(report) ((report) ->t_position) 
#define Origin_of_PROGRESS(report) ((report) ->t_origin)  \

#define Prev_UR_of_UR(ur) ((ur) ->t_prev) 
#define Next_UR_of_UR(ur) ((ur) ->t_next) 
#define YIM_of_UR(ur) ((ur) ->t_earley_item)  \

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
#define IRLID_of_OR(or) ID_of_IRL(IRL_of_OR(or) ) 
#define Origin_Ord_of_OR(or) ((or) ->t_final.t_start_set_ordinal) 
#define ID_of_OR(or) ((or) ->t_final.t_id) 
#define YS_Ord_of_OR(or) ((or) ->t_draft.t_end_set_ordinal) 
#define DANDs_of_OR(or) ((or) ->t_draft.t_draft_and_node) 
#define First_ANDID_of_OR(or) ((or) ->t_final.t_first_and_node_id) 
#define AND_Count_of_OR(or) ((or) ->t_final.t_and_node_count) 
#define NSYID_of_OR(or) ((or) ->t_token.t_nsyid) 
#define Value_of_OR(or) ((or) ->t_token.t_value) 
#define ORs_of_B(b) ((b) ->t_or_nodes) 
#define OR_of_B_by_ID(b,id) (ORs_of_B(b) [(id) ]) 
#define OR_Count_of_B(b) ((b) ->t_or_node_count) 
#define OR_Capacity_of_B(b) ((b) ->t_or_node_capacity) 
#define ANDs_of_B(b) ((b) ->t_and_nodes) 
#define AND_Count_of_B(b) ((b) ->t_and_node_count) 
#define Top_ORID_of_B(b) ((b) ->t_top_or_node_id) 
#define G_of_B(b) ((b) ->t_grammar) 
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
#define OR_of_AND(and) ((and) ->t_current) 
#define Predecessor_OR_of_AND(and) ((and) ->t_predecessor) 
#define Cause_OR_of_AND(and) ((and) ->t_cause) 
#define OBS_of_B(b) ((b) ->t_obs) 
#define Valued_BV_of_B(b) ((b) ->t_valued_bv) 
#define Valued_Locked_BV_of_B(b) ((b) ->t_valued_locked_bv) 
#define XSYID_is_Valued_in_B(b,xsyid)  \
(lbv_bit_test(Valued_BV_of_B(b) ,(xsyid) ) ) 
#define NSYID_is_Valued_in_B(b,nsyid)  \
XSYID_is_Valued_in_B((b) ,Source_XSYID_of_NSYID(nsyid) ) 
#define OR_by_PSI(psi_data,set_ordinal,item_ordinal)  \
(((psi_data) [(set_ordinal) ].t_or_node_by_item) [(item_ordinal) ]) 
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

#line 15793 "./marpa.w"

#include "marpa_obs.h"
#include "marpa_avl.h"
/*107:*/
#line 1014 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:107*//*143:*/
#line 1243 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef const struct s_xsy*XSY_Const;

/*:143*//*444:*/
#line 4673 "./marpa.w"

struct s_ahm;
typedef struct s_ahm*AHM;
typedef Marpa_AHM_ID AHMID;

/*:444*//*518:*/
#line 5554 "./marpa.w"

struct s_g_zwa;
struct s_r_zwa;
/*:518*//*525:*/
#line 5591 "./marpa.w"

struct s_zwp;
/*:525*//*618:*/
#line 6462 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*YS;
typedef const struct s_earley_set*YS_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*YSK;
/*:618*//*640:*/
#line 6677 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*YIM;
typedef const struct s_earley_item*YIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*YIK;

/*:640*//*649:*/
#line 6846 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*YIX;
union u_postdot_item;
/*:649*//*652:*/
#line 6883 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:652*//*684:*/
#line 7273 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:684*//*840:*/
#line 9641 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:840*//*861:*/
#line 9903 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:861*//*889:*/
#line 10313 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:889*//*915:*/
#line 10712 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:915*//*921:*/
#line 10775 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:921*//*931:*/
#line 10871 "./marpa.w"

struct s_bocage_setup_per_ys;
/*:931*//*994:*/
#line 11549 "./marpa.w"

typedef Marpa_Tree TREE;
/*:994*//*1029:*/
#line 11996 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1029*//*1033:*/
#line 12041 "./marpa.w"

typedef struct s_value*VALUE;
/*:1033*//*1141:*/
#line 13519 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1141*//*1147:*/
#line 13573 "./marpa.w"

struct s_cil_arena;
/*:1147*//*1167:*/
#line 13908 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1167*//*1169:*/
#line 13923 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1169*/
#line 15796 "./marpa.w"

/*49:*/
#line 664 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:49*//*142:*/
#line 1241 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
/*:142*//*210:*/
#line 1751 "./marpa.w"

struct s_nsy;
typedef struct s_nsy*NSY;
typedef Marpa_NSY_ID NSYID;

/*:210*//*249:*/
#line 2036 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:249*//*322:*/
#line 2756 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:322*//*460:*/
#line 4785 "./marpa.w"
typedef int SYMI;
/*:460*//*519:*/
#line 5563 "./marpa.w"

typedef Marpa_Assertion_ID ZWAID;
typedef struct s_g_zwa*GZWA;
typedef struct s_r_zwa*ZWA;

/*:519*//*526:*/
#line 5594 "./marpa.w"

typedef struct s_zwp*ZWP;
typedef const struct s_zwp*ZWP_Const;
/*:526*//*539:*/
#line 5790 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:539*//*615:*/
#line 6452 "./marpa.w"
typedef Marpa_Earleme JEARLEME;

/*:615*//*617:*/
#line 6456 "./marpa.w"
typedef Marpa_Earley_Set_ID YSID;
/*:617*//*642:*/
#line 6718 "./marpa.w"

typedef int YIMID;

/*:642*//*665:*/
#line 7004 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
typedef const struct s_source*SRC_Const;
/*:665*//*668:*/
#line 7029 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:668*//*808:*/
#line 9301 "./marpa.w"

typedef struct marpa_progress_item*PROGRESS;
/*:808*//*860:*/
#line 9900 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:860*//*888:*/
#line 10302 "./marpa.w"

typedef int WHEID;

/*:888*//*914:*/
#line 10708 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:914*//*1028:*/
#line 11992 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1028*//*1078:*/
#line 12729 "./marpa.w"

typedef unsigned int LBW;
typedef LBW*LBV;

/*:1078*//*1086:*/
#line 12821 "./marpa.w"

typedef LBW Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1086*//*1144:*/
#line 13540 "./marpa.w"

typedef int*CIL;

/*:1144*//*1148:*/
#line 13576 "./marpa.w"

typedef struct s_cil_arena*CILAR;
/*:1148*/
#line 15797 "./marpa.w"

/*1146:*/
#line 13565 "./marpa.w"

struct s_cil_arena{
struct marpa_obstack*t_obs;
MARPA_AVL_TREE t_avl;
MARPA_DSTACK_DECLARE(t_buffer);
};
typedef struct s_cil_arena CILAR_Object;

/*:1146*/
#line 15798 "./marpa.w"

/*48:*/
#line 658 "./marpa.w"
struct marpa_g{
/*133:*/
#line 1188 "./marpa.w"

int t_is_ok;

/*:133*/
#line 659 "./marpa.w"

/*59:*/
#line 741 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xsy_stack);
MARPA_DSTACK_DECLARE(t_nsy_stack);

/*:59*//*68:*/
#line 798 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xrl_stack);
MARPA_DSTACK_DECLARE(t_irl_stack);
/*:68*//*103:*/
#line 989 "./marpa.w"
Bit_Vector t_bv_nsyid_is_terminal;
/*:103*//*105:*/
#line 998 "./marpa.w"

Bit_Vector t_lbv_xsyid_is_completion_event;
Bit_Vector t_lbv_xsyid_is_nulled_event;
Bit_Vector t_lbv_xsyid_is_prediction_event;
/*:105*//*112:*/
#line 1036 "./marpa.w"

MARPA_DSTACK_DECLARE(t_events);
/*:112*//*120:*/
#line 1110 "./marpa.w"

MARPA_AVL_TREE t_xrl_tree;
/*:120*//*124:*/
#line 1140 "./marpa.w"

struct marpa_obstack*t_obs;
struct marpa_obstack*t_xrl_obs;
/*:124*//*127:*/
#line 1157 "./marpa.w"

CILAR_Object t_cilar;
/*:127*//*135:*/
#line 1203 "./marpa.w"

const char*t_error_string;
/*:135*//*446:*/
#line 4690 "./marpa.w"

AHM t_ahms;
/*:446*//*520:*/
#line 5570 "./marpa.w"

MARPA_DSTACK_DECLARE(t_gzwa_stack);
/*:520*//*528:*/
#line 5609 "./marpa.w"

MARPA_AVL_TREE t_zwp_tree;
/*:528*/
#line 660 "./marpa.w"

/*53:*/
#line 688 "./marpa.w"
int t_ref_count;
/*:53*//*78:*/
#line 848 "./marpa.w"
XSYID t_start_xsy_id;
/*:78*//*82:*/
#line 881 "./marpa.w"

IRL t_start_irl;
/*:82*//*85:*/
#line 895 "./marpa.w"

int t_external_size;
/*:85*//*88:*/
#line 909 "./marpa.w"
int t_max_rule_length;
/*:88*//*92:*/
#line 922 "./marpa.w"
Marpa_Rank t_default_rank;
/*:92*//*136:*/
#line 1205 "./marpa.w"

Marpa_Error_Code t_error;
/*:136*//*447:*/
#line 4694 "./marpa.w"

int t_ahm_count;
/*:447*//*461:*/
#line 4787 "./marpa.w"

int t_symbol_instance_count;
/*:461*/
#line 661 "./marpa.w"

/*97:*/
#line 957 "./marpa.w"
BITFIELD t_is_precomputed:1;
/*:97*//*100:*/
#line 969 "./marpa.w"
BITFIELD t_has_cycle:1;
/*:100*/
#line 662 "./marpa.w"

};
/*:48*//*111:*/
#line 1029 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:111*//*144:*/
#line 1248 "./marpa.w"

struct s_xsy{
/*196:*/
#line 1651 "./marpa.w"

CIL t_nulled_event_xsyids;
/*:196*//*199:*/
#line 1678 "./marpa.w"
NSY t_nsy_equivalent;
/*:199*//*203:*/
#line 1710 "./marpa.w"
NSY t_nulling_nsy;
/*:203*/
#line 1250 "./marpa.w"

/*145:*/
#line 1257 "./marpa.w"
XSYID t_symbol_id;

/*:145*//*151:*/
#line 1291 "./marpa.w"

Marpa_Rank t_rank;
/*:151*/
#line 1251 "./marpa.w"

/*148:*/
#line 1278 "./marpa.w"
BITFIELD t_is_start:1;
/*:148*//*155:*/
#line 1338 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:155*//*157:*/
#line 1345 "./marpa.w"
BITFIELD t_is_sequence_lhs:1;
/*:157*//*159:*/
#line 1359 "./marpa.w"

BITFIELD t_is_valued:1;
BITFIELD t_is_valued_locked:1;
/*:159*//*163:*/
#line 1403 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:163*//*166:*/
#line 1424 "./marpa.w"
BITFIELD t_is_counted:1;
/*:166*//*169:*/
#line 1440 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:169*//*172:*/
#line 1457 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:172*//*175:*/
#line 1478 "./marpa.w"

BITFIELD t_is_terminal:1;
BITFIELD t_is_locked_terminal:1;
/*:175*//*180:*/
#line 1525 "./marpa.w"
BITFIELD t_is_productive:1;
/*:180*//*183:*/
#line 1544 "./marpa.w"
BITFIELD t_is_completion_event:1;
/*:183*//*187:*/
#line 1579 "./marpa.w"
BITFIELD t_is_nulled_event:1;
/*:187*//*191:*/
#line 1614 "./marpa.w"
BITFIELD t_is_prediction_event:1;
/*:191*/
#line 1252 "./marpa.w"

};

/*:144*//*211:*/
#line 1766 "./marpa.w"

struct s_unvalued_token_or_node{
int t_or_node_type;
NSYID t_nsyid;
};

struct s_nsy{
/*230:*/
#line 1903 "./marpa.w"
CIL t_lhs_cil;
/*:230*//*235:*/
#line 1934 "./marpa.w"
XSY t_source_xsy;
/*:235*//*239:*/
#line 1957 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:239*/
#line 1773 "./marpa.w"

/*244:*/
#line 2010 "./marpa.w"
Marpa_Rank t_rank;
/*:244*/
#line 1774 "./marpa.w"

/*221:*/
#line 1858 "./marpa.w"
BITFIELD t_is_start:1;
/*:221*//*224:*/
#line 1872 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:224*//*227:*/
#line 1886 "./marpa.w"
BITFIELD t_nsy_is_nulling:1;
/*:227*//*232:*/
#line 1911 "./marpa.w"
BITFIELD t_is_semantic:1;
/*:232*/
#line 1775 "./marpa.w"

struct s_unvalued_token_or_node t_nulling_or_node;
struct s_unvalued_token_or_node t_unvalued_or_node;
};
/*:211*//*248:*/
#line 2027 "./marpa.w"

struct s_xrl{
/*261:*/
#line 2330 "./marpa.w"
int t_rhs_length;
/*:261*//*269:*/
#line 2395 "./marpa.w"
Marpa_Rule_ID t_id;

/*:269*//*270:*/
#line 2398 "./marpa.w"

Marpa_Rank t_rank;
/*:270*/
#line 2029 "./marpa.w"

/*274:*/
#line 2446 "./marpa.w"

BITFIELD t_null_ranks_high:1;
/*:274*//*278:*/
#line 2487 "./marpa.w"
BITFIELD t_is_bnf:1;
/*:278*//*280:*/
#line 2493 "./marpa.w"
BITFIELD t_is_sequence:1;
/*:280*//*282:*/
#line 2507 "./marpa.w"
int t_minimum;
/*:282*//*285:*/
#line 2532 "./marpa.w"
XSYID t_separator_id;
/*:285*//*290:*/
#line 2565 "./marpa.w"
BITFIELD t_is_discard:1;
/*:290*//*294:*/
#line 2605 "./marpa.w"
BITFIELD t_is_proper_separation:1;
/*:294*//*298:*/
#line 2626 "./marpa.w"
BITFIELD t_is_loop:1;
/*:298*//*301:*/
#line 2643 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:301*//*304:*/
#line 2661 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:304*//*308:*/
#line 2679 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:308*//*311:*/
#line 2697 "./marpa.w"
BITFIELD t_is_productive:1;
/*:311*//*314:*/
#line 2714 "./marpa.w"
BITFIELD t_is_used:1;
/*:314*/
#line 2030 "./marpa.w"

/*262:*/
#line 2333 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];


/*:262*/
#line 2031 "./marpa.w"

};
/*:248*//*320:*/
#line 2745 "./marpa.w"

struct s_irl{
/*353:*/
#line 2958 "./marpa.w"
XRL t_source_xrl;
/*:353*//*359:*/
#line 3007 "./marpa.w"
AHM t_first_ahm;
/*:359*/
#line 2747 "./marpa.w"

/*323:*/
#line 2767 "./marpa.w"
IRLID t_irl_id;

/*:323*//*330:*/
#line 2804 "./marpa.w"
int t_length;
/*:330*//*332:*/
#line 2819 "./marpa.w"
int t_ahm_count;

/*:332*//*344:*/
#line 2898 "./marpa.w"
int t_real_symbol_count;
/*:344*//*347:*/
#line 2916 "./marpa.w"
int t_virtual_start;
/*:347*//*350:*/
#line 2936 "./marpa.w"
int t_virtual_end;
/*:350*//*356:*/
#line 2985 "./marpa.w"
Marpa_Rank t_rank;
/*:356*//*462:*/
#line 4793 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:462*/
#line 2748 "./marpa.w"

/*335:*/
#line 2852 "./marpa.w"
BITFIELD t_is_virtual_lhs:1;
/*:335*//*338:*/
#line 2868 "./marpa.w"
BITFIELD t_is_virtual_rhs:1;
/*:338*//*341:*/
#line 2887 "./marpa.w"
BITFIELD t_is_right_recursive:1;
/*:341*/
#line 2749 "./marpa.w"

/*325:*/
#line 2772 "./marpa.w"

NSYID t_nsyid_array[1];

/*:325*/
#line 2750 "./marpa.w"

};
typedef struct s_irl IRL_Object;

/*:320*//*372:*/
#line 3191 "./marpa.w"

struct sym_rule_pair
{
XSYID t_symid;
RULEID t_ruleid;
};

/*:372*//*443:*/
#line 4667 "./marpa.w"

struct s_ahm{
/*452:*/
#line 4717 "./marpa.w"

IRL t_irl;

/*:452*//*465:*/
#line 4808 "./marpa.w"

CIL t_predicted_irl_cil;
CIL t_lhs_cil;

/*:465*//*466:*/
#line 4816 "./marpa.w"

CIL t_zwa_cil;

/*:466*//*486:*/
#line 5027 "./marpa.w"

CIL t_completion_xsyids;
CIL t_nulled_xsyids;
CIL t_prediction_xsyids;

/*:486*//*490:*/
#line 5057 "./marpa.w"

XRL t_xrl;
/*:490*//*493:*/
#line 5086 "./marpa.w"

CIL t_event_ahmids;
/*:493*/
#line 4669 "./marpa.w"

/*453:*/
#line 4727 "./marpa.w"
NSYID t_postdot_nsyid;

/*:453*//*454:*/
#line 4736 "./marpa.w"

int t_leading_nulls;

/*:454*//*455:*/
#line 4747 "./marpa.w"

int t_position;

/*:455*//*457:*/
#line 4763 "./marpa.w"

int t_quasi_position;

/*:457*//*459:*/
#line 4783 "./marpa.w"

int t_symbol_instance;
/*:459*//*491:*/
#line 5065 "./marpa.w"

int t_xrl_position;

/*:491*//*494:*/
#line 5090 "./marpa.w"

int t_event_group_size;
/*:494*/
#line 4670 "./marpa.w"

/*467:*/
#line 4825 "./marpa.w"

BITFIELD t_predicts_zwa:1;

/*:467*//*489:*/
#line 5048 "./marpa.w"

BITFIELD t_was_predicted:1;
BITFIELD t_is_initial:1;

/*:489*/
#line 4671 "./marpa.w"

};
/*:443*//*524:*/
#line 5584 "./marpa.w"

struct s_g_zwa{
ZWAID t_id;
BITFIELD t_default_value:1;
};
typedef struct s_g_zwa GZWA_Object;

/*:524*//*527:*/
#line 5601 "./marpa.w"

struct s_zwp{
XRLID t_xrl_id;
int t_dot;
ZWAID t_zwaid;
};
typedef struct s_zwp ZWP_Object;

/*:527*//*608:*/
#line 6398 "./marpa.w"

struct s_r_zwa{
ZWAID t_id;
YSID t_memoized_ysid;
BITFIELD t_default_value:1;
BITFIELD t_memoized_value:1;
};
typedef struct s_r_zwa ZWA_Object;

/*:608*//*619:*/
#line 6468 "./marpa.w"

struct s_earley_set_key{
JEARLEME t_earleme;
};
typedef struct s_earley_set_key YSK_Object;
/*:619*//*620:*/
#line 6473 "./marpa.w"

struct s_earley_set{
YSK_Object t_key;
union u_postdot_item**t_postdot_ary;
YS t_next_earley_set;
/*622:*/
#line 6489 "./marpa.w"

YIM*t_earley_items;

/*:622*//*1178:*/
#line 14011 "./marpa.w"

PSL t_dot_psl;
/*:1178*/
#line 6478 "./marpa.w"

int t_postdot_sym_count;
/*621:*/
#line 6486 "./marpa.w"

int t_yim_count;
/*:621*//*623:*/
#line 6500 "./marpa.w"

int t_ordinal;
/*:623*//*627:*/
#line 6518 "./marpa.w"

int t_value;
void*t_pvalue;
/*:627*/
#line 6480 "./marpa.w"

};
typedef struct s_earley_set YS_Object;

/*:620*//*650:*/
#line 6850 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
NSYID t_postdot_nsyid;
YIM t_earley_item;
};
typedef struct s_earley_ix YIX_Object;

/*:650*//*653:*/
#line 6886 "./marpa.w"

struct s_leo_item{
YIX_Object t_earley_ix;
/*654:*/
#line 6902 "./marpa.w"

CIL t_cil;

/*:654*/
#line 6889 "./marpa.w"

YS t_origin;
AHM t_top_ahm;
AHM t_trailhead_ahm;
LIM t_predecessor;
YIM t_base;
YS t_set;
BITFIELD t_is_rejected:1;
BITFIELD t_is_active:1;
};
typedef struct s_leo_item LIM_Object;

/*:653*//*656:*/
#line 6920 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
YIX_Object t_earley;
};
typedef union u_postdot_item PIM_Object;
typedef union u_postdot_item*PIM;

/*:656*//*685:*/
#line 7284 "./marpa.w"

struct s_alternative{
YS t_start_earley_set;
JEARLEME t_end_earleme;
NSYID t_nsyid;
int t_value;
BITFIELD t_is_valued:1;
};
typedef struct s_alternative ALT_Object;

/*:685*//*841:*/
#line 9657 "./marpa.w"

struct s_ur_node_stack{
struct marpa_obstack*t_obs;
UR t_base;
UR t_top;
};

/*:841*//*842:*/
#line 9664 "./marpa.w"

struct s_ur_node{
UR t_prev;
UR t_next;
YIM t_earley_item;
};
typedef struct s_ur_node UR_Object;

/*:842*//*865:*/
#line 9946 "./marpa.w"

struct s_draft_or_node
{
/*864:*/
#line 9939 "./marpa.w"

/*863:*/
#line 9936 "./marpa.w"

int t_position;

/*:863*/
#line 9940 "./marpa.w"

int t_end_set_ordinal;
int t_start_set_ordinal;
ORID t_id;
IRL t_irl;

/*:864*/
#line 9949 "./marpa.w"

DAND t_draft_and_node;
};

/*:865*//*866:*/
#line 9953 "./marpa.w"

struct s_final_or_node
{
/*864:*/
#line 9939 "./marpa.w"

/*863:*/
#line 9936 "./marpa.w"

int t_position;

/*:863*/
#line 9940 "./marpa.w"

int t_end_set_ordinal;
int t_start_set_ordinal;
ORID t_id;
IRL t_irl;

/*:864*/
#line 9956 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};

/*:866*//*867:*/
#line 9961 "./marpa.w"

struct s_valued_token_or_node
{
/*863:*/
#line 9936 "./marpa.w"

int t_position;

/*:863*/
#line 9964 "./marpa.w"

NSYID t_nsyid;
int t_value;
};

/*:867*//*868:*/
#line 9972 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_valued_token_or_node t_token;
};
typedef union u_or_node OR_Object;

/*:868*//*890:*/
#line 10320 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:890*//*916:*/
#line 10719 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:916*//*932:*/
#line 10877 "./marpa.w"

struct s_bocage_setup_per_ys{
OR*t_or_node_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:932*//*958:*/
#line 11099 "./marpa.w"

struct marpa_order{
struct marpa_obstack*t_ordering_obs;
ANDID**t_and_node_orderings;
/*961:*/
#line 11117 "./marpa.w"

BOCAGE t_bocage;

/*:961*/
#line 11103 "./marpa.w"

/*964:*/
#line 11137 "./marpa.w"
int t_ref_count;
/*:964*//*971:*/
#line 11193 "./marpa.w"
int t_ambiguity_metric;

/*:971*//*976:*/
#line 11225 "./marpa.w"
int t_high_rank_count;
/*:976*/
#line 11104 "./marpa.w"

/*974:*/
#line 11207 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:974*/
#line 11105 "./marpa.w"

BITFIELD t_is_frozen:1;
};
/*:958*//*995:*/
#line 11561 "./marpa.w"

/*1030:*/
#line 12007 "./marpa.w"

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

/*:1030*/
#line 11562 "./marpa.w"

/*1035:*/
#line 12055 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1039:*/
#line 12133 "./marpa.w"

struct marpa_obstack*t_obs;
/*:1039*//*1044:*/
#line 12180 "./marpa.w"

MARPA_DSTACK_DECLARE(t_virtual_stack);
/*:1044*//*1066:*/
#line 12333 "./marpa.w"

LBV t_xsy_is_valued;
LBV t_xrl_is_valued;
LBV t_valued_locked;

/*:1066*/
#line 12059 "./marpa.w"

/*1049:*/
#line 12228 "./marpa.w"

int t_ref_count;
/*:1049*//*1061:*/
#line 12309 "./marpa.w"

NOOKID t_nook;
/*:1061*/
#line 12060 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1056:*/
#line 12281 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1056*//*1058:*/
#line 12288 "./marpa.w"

BITFIELD t_trace:1;
/*:1058*/
#line 12063 "./marpa.w"

};

/*:1035*/
#line 11563 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_or_node_in_use;
Marpa_Order t_order;
/*1001:*/
#line 11634 "./marpa.w"

int t_ref_count;
/*:1001*//*1008:*/
#line 11714 "./marpa.w"
int t_pause_counter;
/*:1008*/
#line 11569 "./marpa.w"

/*1014:*/
#line 11785 "./marpa.w"

BITFIELD t_is_exhausted:1;
/*:1014*//*1017:*/
#line 11793 "./marpa.w"

BITFIELD t_is_nulling:1;

/*:1017*/
#line 11570 "./marpa.w"

int t_parse_count;
};

/*:995*//*1121:*/
#line 13304 "./marpa.w"

struct s_bit_matrix{
int t_row_count;
Bit_Vector_Word t_row_data[1];
};
typedef struct s_bit_matrix*Bit_Matrix;
typedef struct s_bit_matrix Bit_Matrix_Object;

/*:1121*//*1142:*/
#line 13522 "./marpa.w"

struct s_dqueue{int t_current;struct marpa_dstack_s t_stack;};

/*:1142*//*1168:*/
#line 13914 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1168*//*1170:*/
#line 13939 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1170*/
#line 15799 "./marpa.w"


/*:1327*//*1328:*/
#line 15804 "./marpa.w"

/*40:*/
#line 591 "./marpa.w"

const int marpa_major_version= MARPA_MAJOR_VERSION;
const int marpa_minor_version= MARPA_MINOR_VERSION;
const int marpa_micro_version= MARPA_MICRO_VERSION;

/*:40*//*814:*/
#line 9327 "./marpa.w"

static const struct marpa_progress_item progress_report_not_ready= {-2,-2,-2};

/*:814*//*869:*/
#line 9980 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:869*//*1087:*/
#line 12828 "./marpa.w"

static const unsigned int bv_wordbits= lbv_wordbits;
static const unsigned int bv_modmask= lbv_wordbits-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= lbv_lsb;
static const unsigned int bv_msb= lbv_msb;

/*:1087*/
#line 15805 "./marpa.w"


/*:1328*//*1329:*/
#line 15807 "./marpa.w"

/*540:*/
#line 5792 "./marpa.w"

struct marpa_r{
/*548:*/
#line 5871 "./marpa.w"

GRAMMAR t_grammar;
/*:548*//*555:*/
#line 5898 "./marpa.w"

YS t_first_earley_set;
YS t_latest_earley_set;
JEARLEME t_current_earleme;
/*:555*//*567:*/
#line 5974 "./marpa.w"

Bit_Vector t_lbv_xsyid_completion_event_is_active;
Bit_Vector t_lbv_xsyid_nulled_event_is_active;
Bit_Vector t_lbv_xsyid_prediction_event_is_active;
/*:567*//*570:*/
#line 5990 "./marpa.w"
Bit_Vector t_bv_nsyid_is_expected;
/*:570*//*574:*/
#line 6063 "./marpa.w"
LBV t_nsy_expected_is_event;
/*:574*//*596:*/
#line 6335 "./marpa.w"

Bit_Vector t_bv_irl_seen;
MARPA_DSTACK_DECLARE(t_irl_cil_stack);
/*:596*//*605:*/
#line 6389 "./marpa.w"
struct marpa_obstack*t_obs;
/*:605*//*609:*/
#line 6410 "./marpa.w"

ZWA t_zwas;
/*:609*//*686:*/
#line 7294 "./marpa.w"

MARPA_DSTACK_DECLARE(t_alternatives);
/*:686*//*703:*/
#line 7589 "./marpa.w"

LBV t_valued_terminal;
LBV t_unvalued_terminal;
LBV t_valued;
LBV t_unvalued;
LBV t_valued_locked;

/*:703*//*711:*/
#line 7797 "./marpa.w"
MARPA_DSTACK_DECLARE(t_yim_work_stack);
/*:711*//*715:*/
#line 7812 "./marpa.w"
MARPA_DSTACK_DECLARE(t_completion_stack);
/*:715*//*719:*/
#line 7823 "./marpa.w"
MARPA_DSTACK_DECLARE(t_earley_set_stack);
/*:719*//*755:*/
#line 8402 "./marpa.w"

Bit_Vector t_bv_lim_symbols;
Bit_Vector t_bv_pim_symbols;
void**t_pim_workarea;
/*:755*//*774:*/
#line 8686 "./marpa.w"

void**t_lim_chain;
/*:774*//*809:*/
#line 9303 "./marpa.w"

const struct marpa_progress_item*t_current_report_item;
MARPA_AVL_TRAV t_progress_report_traverser;
/*:809*//*843:*/
#line 9673 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:843*//*1171:*/
#line 13947 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1171*//*1221:*/
#line 14385 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:1221*//*1228:*/
#line 14460 "./marpa.w"

YIM t_trace_earley_item;
/*:1228*//*1242:*/
#line 14659 "./marpa.w"

union u_postdot_item**t_trace_pim_nsy_p;
union u_postdot_item*t_trace_postdot_item;
/*:1242*//*1249:*/
#line 14803 "./marpa.w"

SRCL t_trace_source_link;
/*:1249*/
#line 5794 "./marpa.w"

/*543:*/
#line 5821 "./marpa.w"
int t_ref_count;
/*:543*//*559:*/
#line 5928 "./marpa.w"
int t_earley_item_warning_threshold;
/*:559*//*563:*/
#line 5957 "./marpa.w"
JEARLEME t_furthest_earleme;
/*:563*//*568:*/
#line 5978 "./marpa.w"

int t_active_event_count;
/*:568*//*603:*/
#line 6382 "./marpa.w"
YSID t_first_inconsistent_ys;
/*:603*//*624:*/
#line 6504 "./marpa.w"

int t_earley_set_count;
/*:624*/
#line 5795 "./marpa.w"

/*552:*/
#line 5889 "./marpa.w"

BITFIELD t_input_phase:2;
/*:552*//*592:*/
#line 6302 "./marpa.w"

BITFIELD t_use_leo_flag:1;
BITFIELD t_is_using_leo:1;
/*:592*//*599:*/
#line 6354 "./marpa.w"
BITFIELD t_is_exhausted:1;
/*:599*//*1250:*/
#line 14805 "./marpa.w"

BITFIELD t_trace_source_type:3;
/*:1250*/
#line 5796 "./marpa.w"

};

/*:540*/
#line 15808 "./marpa.w"

/*666:*/
#line 7008 "./marpa.w"

struct s_token_source{
NSYID t_nsyid;
int t_value;
};

/*:666*//*667:*/
#line 7017 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
struct s_token_source t_token;
}t_cause;
BITFIELD t_is_rejected:1;
BITFIELD t_is_active:1;

};

/*:667*//*669:*/
#line 7032 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};
typedef struct s_source_link SRCL_Object;

/*:669*//*670:*/
#line 7039 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:670*//*671:*/
#line 7046 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source_link t_unique;
};

/*:671*/
#line 15809 "./marpa.w"

/*641:*/
#line 6697 "./marpa.w"

struct s_earley_item_key{
AHM t_ahm;
YS t_origin;
YS t_set;
};
typedef struct s_earley_item_key YIK_Object;
struct s_earley_item{
YIK_Object t_key;
union u_source_container t_container;
BITFIELD t_ordinal:YIM_ORDINAL_WIDTH;
BITFIELD t_source_type:3;
BITFIELD t_is_rejected:1;
BITFIELD t_is_active:1;
BITFIELD t_was_scanned:1;
BITFIELD t_was_fusion:1;
};
typedef struct s_earley_item YIM_Object;

/*:641*/
#line 15810 "./marpa.w"

/*922:*/
#line 10777 "./marpa.w"

struct marpa_bocage{
/*870:*/
#line 9991 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:870*//*874:*/
#line 10020 "./marpa.w"

GRAMMAR t_grammar;

/*:874*//*925:*/
#line 10792 "./marpa.w"

struct marpa_obstack*t_obs;
/*:925*//*928:*/
#line 10851 "./marpa.w"

LBV t_valued_bv;
LBV t_valued_locked_bv;

/*:928*/
#line 10779 "./marpa.w"

/*871:*/
#line 9994 "./marpa.w"

int t_or_node_capacity;
int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:871*//*942:*/
#line 10999 "./marpa.w"
int t_ambiguity_metric;
/*:942*//*946:*/
#line 11013 "./marpa.w"
int t_ref_count;
/*:946*/
#line 10780 "./marpa.w"

/*953:*/
#line 11071 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:953*/
#line 10781 "./marpa.w"

};

/*:922*/
#line 15811 "./marpa.w"


/*:1329*/

#line 1 "./marpa.c.p40"
static RULE rule_new(GRAMMAR g,
const XSYID lhs, const XSYID *rhs, int length);
static int
duplicate_rule_cmp (const void *ap, const void *bp, void *param  UNUSED);
static int sym_rule_cmp(
    const void* ap,
    const void* bp,
    void *param  UNUSED);
static int zwp_cmp (
    const void* ap,
    const void* bp,
    void *param  UNUSED);
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
static inline int ahm_is_valid(
GRAMMAR g, AHMID item_id);
static inline void
recce_unref (RECCE r);
static inline RECCE recce_ref (RECCE r);
static inline void recce_free(struct marpa_r *r);
static inline YS ys_at_current_earleme(RECCE r);
static inline YS
earley_set_new( RECCE r, JEARLEME id);
static inline YIM earley_item_create(const RECCE r,
    const YIK_Object key);
static inline YIM
earley_item_assign (const RECCE r, const YS set, const YS origin,
                    const AHM ahm);
static inline PIM*
pim_nsy_p_find (YS set, NSYID nsyid);
static inline PIM first_pim_of_ys_by_nsyid(YS set, NSYID nsyid);
static inline SRCL unique_srcl_new( struct marpa_obstack* t_obs);
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
static inline int
alternative_insertion_point (RECCE r, ALT new_alternative);
static inline int alternative_cmp(const ALT_Const a, const ALT_Const b);
static inline ALT alternative_pop(RECCE r, JEARLEME earleme);
static inline int alternative_insert(RECCE r, ALT new_alternative);
static inline int evaluate_zwas(RECCE r, YSID ysid, AHM ahm);
static inline void trigger_events(RECCE r);
static inline void earley_set_update_items(RECCE r, YS set);
static inline void r_update_earley_sets(RECCE r);
static inline int alternative_is_acceptable(ALT alternative);
static inline void
progress_report_item_insert(MARPA_AVL_TREE report_tree,
  AHM report_ahm, 
    YSID report_origin);
static inline void ur_node_stack_init(URS stack);
static inline void ur_node_stack_reset(URS stack);
static inline void ur_node_stack_destroy(URS stack);
static inline UR ur_node_new(URS stack, UR prev);
static inline void
ur_node_push (URS stack, YIM earley_item);
static inline UR
ur_node_pop (URS stack);
static inline void push_ur_if_new(
    struct s_bocage_setup_per_ys* per_ys_data,
    URS ur_node_stack, YIM yim);
static inline int psi_test_and_set(
    struct s_bocage_setup_per_ys* per_ys_data,
    YIM earley_item
    );
static inline void
Set_boolean_in_PSI_for_initial_nulls (struct s_bocage_setup_per_ys *per_ys_data,
  YIM yim);
static inline OR or_node_new(BOCAGE b);
static inline DAND draft_and_node_new(struct marpa_obstack *obs, OR predecessor, OR cause);
static inline void draft_and_node_add(struct marpa_obstack *obs, OR parent, OR predecessor, OR cause);
static inline OR or_by_origin_and_symi ( struct s_bocage_setup_per_ys *per_ys_data,
    YSID origin,
    SYMI symbol_instance);
static inline int dands_are_equal(OR predecessor_a, OR cause_a,
  OR predecessor_b, OR cause_b);
static inline int dand_is_duplicate(OR parent, OR predecessor, OR cause);
static inline OR set_or_from_yim ( struct s_bocage_setup_per_ys *per_ys_data,
  YIM psi_yim);
static inline OR safe_or_from_yim(
  struct s_bocage_setup_per_ys* per_ys_data,
  YIM yim);
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
cilar_buffer_reinit (const CILAR cilar);
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
psar_safe (const PSAR psar);
static inline void
psar_init (const PSAR psar, int length);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
static inline void psar_reset(const PSAR psar);
static inline void psar_dealloc(const PSAR psar);
static inline void psl_claim(
    PSL* const psl_owner, const PSAR psar);
static inline PSL psl_claim_by_es(
    PSAR or_psar,
    struct s_bocage_setup_per_ys* per_ys_data,
    YSID ysid);
static inline PSL psl_alloc(const PSAR psar);
static inline Marpa_Error_Code
clear_error (GRAMMAR g);
static inline void trace_earley_item_clear(RECCE r);
static inline void trace_source_link_clear(RECCE r);

/*1330:*/
#line 15813 "./marpa.w"

/*1218:*/
#line 14369 "./marpa.w"

extern void*(*const marpa__out_of_memory)(void);

/*:1218*//*1310:*/
#line 15629 "./marpa.w"

extern int marpa__default_debug_handler(const char*format,...);
extern int(*marpa__debug_handler)(const char*,...);
extern int marpa__debug_level;

/*:1310*/
#line 15814 "./marpa.w"

#if MARPA_DEBUG
/*1315:*/
#line 15661 "./marpa.w"

static const char*yim_tag_safe(
char*buffer,GRAMMAR g,YIM yim)UNUSED;
static const char*yim_tag(GRAMMAR g,YIM yim)UNUSED;
/*:1315*//*1317:*/
#line 15687 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1317*//*1319:*/
#line 15713 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1319*//*1321:*/
#line 15745 "./marpa.w"

static const char*ahm_tag_safe(char*buffer,AHM ahm)UNUSED;
static const char*ahm_tag(AHM ahm)UNUSED;
/*:1321*/
#line 15816 "./marpa.w"

/*1316:*/
#line 15666 "./marpa.w"

static const char*
yim_tag_safe(char*buffer,GRAMMAR g,YIM yim)
{
if(!yim)return"NULL";
sprintf(buffer,"S%d@%d-%d",
AHMID_of_YIM(yim),Origin_Earleme_of_YIM(yim),
Earleme_of_YIM(yim));
return buffer;
}

static char DEBUG_yim_tag_buffer[1000];
static const char*
yim_tag(GRAMMAR g,YIM yim)
{
return yim_tag_safe(DEBUG_yim_tag_buffer,g,yim);
}

/*:1316*//*1318:*/
#line 15692 "./marpa.w"

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

/*:1318*//*1320:*/
#line 15717 "./marpa.w"

static const char*
or_tag_safe(char*buffer,OR or)
{
if(!or)return"NULL";
if(OR_is_Token(or))return"TOKEN";
if(Type_of_OR(or)==DUMMY_OR_NODE)return"DUMMY";
sprintf(buffer,"R%d:%d@%d-%d",
IRLID_of_OR(or),Position_of_OR(or),
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

/*:1320*//*1322:*/
#line 15748 "./marpa.w"

static const char*
ahm_tag_safe(char*buffer,AHM ahm)
{
if(!ahm)return"NULL";
const int ahm_position= Position_of_AHM(ahm);
if(ahm_position>=0){
sprintf(buffer,"R%d@%d",IRLID_of_AHM(ahm),Position_of_AHM(ahm));
}else{
sprintf(buffer,"R%d@end",IRLID_of_AHM(ahm));
}
return buffer;
}

static char DEBUG_ahm_tag_buffer[1000];
static const char*
ahm_tag(AHM ahm)
{
return ahm_tag_safe(DEBUG_ahm_tag_buffer,ahm);
}

/*:1322*/
#line 15817 "./marpa.w"

#endif
/*1314:*/
#line 15653 "./marpa.w"

int(*marpa__debug_handler)(const char*,...)= 
marpa__default_debug_handler;
int marpa__debug_level= 0;

/*:1314*/
#line 15819 "./marpa.w"

/*41:*/
#line 596 "./marpa.w"

Marpa_Error_Code
marpa_check_version(int required_major,
int required_minor,
int required_micro)
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

/*:41*//*42:*/
#line 614 "./marpa.w"

Marpa_Error_Code
marpa_version(int*version)
{
*version++= MARPA_MAJOR_VERSION;
*version++= MARPA_MINOR_VERSION;
*version= MARPA_MICRO_VERSION;
return 0;
}

/*:42*//*45:*/
#line 633 "./marpa.w"

int marpa_c_init(Marpa_Config*config)
{
config->t_is_ok= I_AM_OK;
config->t_error= MARPA_ERR_NONE;
config->t_error_string= NULL;
return 0;
}

/*:45*//*46:*/
#line 642 "./marpa.w"

Marpa_Error_Code marpa_c_error(Marpa_Config*config,const char**p_error_string)
{
const Marpa_Error_Code error_code= config->t_error;
const char*error_string= config->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:46*//*51:*/
#line 668 "./marpa.w"

Marpa_Grammar marpa_g_new(Marpa_Config*configuration)
{
GRAMMAR g;
if(configuration&&configuration->t_is_ok!=I_AM_OK){
configuration->t_error= MARPA_ERR_I_AM_NOT_OK;
return NULL;
}
g= my_malloc(sizeof(struct marpa_g));


g->t_is_ok= 0;
/*54:*/
#line 689 "./marpa.w"

g->t_ref_count= 1;

/*:54*//*60:*/
#line 745 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xsy_stack,XSY);
MARPA_DSTACK_SAFE(g->t_nsy_stack);

/*:60*//*69:*/
#line 801 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xrl_stack,RULE);
MARPA_DSTACK_SAFE(g->t_irl_stack);

/*:69*//*79:*/
#line 849 "./marpa.w"

g->t_start_xsy_id= -1;
/*:79*//*83:*/
#line 883 "./marpa.w"

g->t_start_irl= NULL;

/*:83*//*86:*/
#line 897 "./marpa.w"

External_Size_of_G(g)= 0;

/*:86*//*89:*/
#line 910 "./marpa.w"

g->t_max_rule_length= 0;

/*:89*//*93:*/
#line 923 "./marpa.w"

g->t_default_rank= 0;
/*:93*//*98:*/
#line 958 "./marpa.w"

g->t_is_precomputed= 0;
/*:98*//*101:*/
#line 970 "./marpa.w"

g->t_has_cycle= 0;
/*:101*//*104:*/
#line 990 "./marpa.w"
g->t_bv_nsyid_is_terminal= NULL;

/*:104*//*106:*/
#line 1002 "./marpa.w"

g->t_lbv_xsyid_is_completion_event= NULL;
g->t_lbv_xsyid_is_nulled_event= NULL;
g->t_lbv_xsyid_is_prediction_event= NULL;

/*:106*//*113:*/
#line 1040 "./marpa.w"

MARPA_DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:113*//*121:*/
#line 1112 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL);
/*:121*//*125:*/
#line 1143 "./marpa.w"

g->t_obs= marpa_obs_init;
g->t_xrl_obs= marpa_obs_init;
/*:125*//*128:*/
#line 1159 "./marpa.w"

cilar_init(&(g)->t_cilar);
/*:128*//*137:*/
#line 1207 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:137*//*449:*/
#line 4699 "./marpa.w"

g->t_ahms= NULL;
/*:449*//*521:*/
#line 5572 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_gzwa_stack,GZWA);
/*:521*//*529:*/
#line 5611 "./marpa.w"

(g)->t_zwp_tree= _marpa_avl_create(zwp_cmp,NULL);
/*:529*/
#line 680 "./marpa.w"



g->t_is_ok= I_AM_OK;
return g;
}

/*:51*//*55:*/
#line 699 "./marpa.w"

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

/*:55*//*57:*/
#line 716 "./marpa.w"

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

/*:57*//*58:*/
#line 728 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
/*61:*/
#line 749 "./marpa.w"

{
MARPA_DSTACK_DESTROY(g->t_xsy_stack);
MARPA_DSTACK_DESTROY(g->t_nsy_stack);
}

/*:61*//*70:*/
#line 805 "./marpa.w"

MARPA_DSTACK_DESTROY(g->t_irl_stack);
MARPA_DSTACK_DESTROY(g->t_xrl_stack);

/*:70*//*114:*/
#line 1042 "./marpa.w"
MARPA_DSTACK_DESTROY(g->t_events);

/*:114*//*123:*/
#line 1119 "./marpa.w"

/*122:*/
#line 1114 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 1120 "./marpa.w"


/*:123*//*126:*/
#line 1146 "./marpa.w"

marpa_obs_free(g->t_obs);
marpa_obs_free(g->t_xrl_obs);

/*:126*//*129:*/
#line 1161 "./marpa.w"

cilar_destroy(&(g)->t_cilar);

/*:129*//*450:*/
#line 4701 "./marpa.w"

my_free(g->t_ahms);

/*:450*//*522:*/
#line 5574 "./marpa.w"

MARPA_DSTACK_DESTROY(g->t_gzwa_stack);

/*:522*//*530:*/
#line 5613 "./marpa.w"

{
_marpa_avl_destroy((g)->t_zwp_tree);
(g)->t_zwp_tree= NULL;
}

/*:530*//*531:*/
#line 5619 "./marpa.w"

/*122:*/
#line 1114 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 5620 "./marpa.w"


/*:531*/
#line 732 "./marpa.w"

my_free(g);
}

/*:58*//*63:*/
#line 757 "./marpa.w"

int marpa_g_highest_symbol_id(Marpa_Grammar g){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 759 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 760 "./marpa.w"

return XSY_Count_of_G(g)-1;
}

/*:63*//*65:*/
#line 769 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,XSY symbol)
{
const XSYID new_id= MARPA_DSTACK_LENGTH((g)->t_xsy_stack);
*MARPA_DSTACK_PUSH((g)->t_xsy_stack,XSY)= symbol;
symbol->t_symbol_id= new_id;
}

/*:65*//*66:*/
#line 781 "./marpa.w"

PRIVATE int xsy_id_is_valid(GRAMMAR g,XSYID xsy_id)
{
return!XSYID_is_Malformed(xsy_id)&&XSYID_of_G_Exists(xsy_id);
}

/*:66*//*67:*/
#line 788 "./marpa.w"

PRIVATE int nsy_is_valid(GRAMMAR g,NSYID nsyid)
{
return nsyid>=0&&nsyid<NSY_Count_of_G(g);
}

/*:67*//*74:*/
#line 812 "./marpa.w"

int marpa_g_highest_rule_id(Marpa_Grammar g){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 814 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 815 "./marpa.w"

return XRL_Count_of_G(g)-1;
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 819 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 820 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:74*//*76:*/
#line 830 "./marpa.w"

PRIVATE void
rule_add(GRAMMAR g,RULE rule)
{
const RULEID new_id= MARPA_DSTACK_LENGTH((g)->t_xrl_stack);
*MARPA_DSTACK_PUSH((g)->t_xrl_stack,RULE)= rule;
rule->t_id= new_id;
External_Size_of_G(g)+= 1+Length_of_XRL(rule);
g->t_max_rule_length= MAX(Length_of_XRL(rule),g->t_max_rule_length);
}

/*:76*//*80:*/
#line 851 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 854 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 855 "./marpa.w"

return g->t_start_xsy_id;
}
/*:80*//*81:*/
#line 864 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 867 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 868 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 869 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 870 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 871 "./marpa.w"

return g->t_start_xsy_id= xsy_id;
}

/*:81*//*94:*/
#line 925 "./marpa.w"

Marpa_Rank marpa_g_default_rank(Marpa_Grammar g)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 928 "./marpa.w"

clear_error(g);
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 930 "./marpa.w"

return Default_Rank_of_G(g);
}
/*:94*//*95:*/
#line 935 "./marpa.w"

Marpa_Rank marpa_g_default_rank_set(Marpa_Grammar g,Marpa_Rank rank)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 938 "./marpa.w"

clear_error(g);
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 940 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 941 "./marpa.w"

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
#line 960 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 963 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 964 "./marpa.w"

return G_is_Precomputed(g);
}

/*:99*//*102:*/
#line 972 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 975 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 976 "./marpa.w"

return g->t_has_cycle;
}

/*:102*//*116:*/
#line 1052 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{


GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= 0;
}
/*:116*//*117:*/
#line 1062 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{


GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= value;
}

/*:117*//*118:*/
#line 1073 "./marpa.w"

Marpa_Event_Type
marpa_g_event(Marpa_Grammar g,Marpa_Event*public_event,
int ix)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1078 "./marpa.w"

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
#line 1098 "./marpa.w"

Marpa_Event_Type
marpa_g_event_count(Marpa_Grammar g)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1102 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1103 "./marpa.w"

return MARPA_DSTACK_LENGTH(g->t_events);
}

/*:119*//*139:*/
#line 1218 "./marpa.w"

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
#line 1229 "./marpa.w"

Marpa_Error_Code
marpa_g_error_clear(Marpa_Grammar g)
{
clear_error(g);
return g->t_error;
}

/*:140*//*146:*/
#line 1259 "./marpa.w"

PRIVATE XSY
symbol_new(GRAMMAR g)
{
XSY xsy= marpa_obs_new(g->t_obs,struct s_xsy,1);
/*149:*/
#line 1279 "./marpa.w"
xsy->t_is_start= 0;
/*:149*//*152:*/
#line 1293 "./marpa.w"

xsy->t_rank= Default_Rank_of_G(g);
/*:152*//*156:*/
#line 1339 "./marpa.w"

XSY_is_LHS(xsy)= 0;

/*:156*//*158:*/
#line 1346 "./marpa.w"

XSY_is_Sequence_LHS(xsy)= 0;

/*:158*//*160:*/
#line 1362 "./marpa.w"

XSY_is_Valued(xsy)= 0;
XSY_is_Valued_Locked(xsy)= 0;

/*:160*//*164:*/
#line 1404 "./marpa.w"

xsy->t_is_accessible= 0;
/*:164*//*167:*/
#line 1425 "./marpa.w"

xsy->t_is_counted= 0;
/*:167*//*170:*/
#line 1441 "./marpa.w"

xsy->t_is_nulling= 0;
/*:170*//*173:*/
#line 1458 "./marpa.w"

xsy->t_is_nullable= 0;
/*:173*//*176:*/
#line 1481 "./marpa.w"

xsy->t_is_terminal= 0;
xsy->t_is_locked_terminal= 0;
/*:176*//*181:*/
#line 1526 "./marpa.w"

xsy->t_is_productive= 0;
/*:181*//*184:*/
#line 1545 "./marpa.w"

xsy->t_is_completion_event= 0;
/*:184*//*188:*/
#line 1580 "./marpa.w"

xsy->t_is_nulled_event= 0;
/*:188*//*192:*/
#line 1615 "./marpa.w"

xsy->t_is_prediction_event= 0;
/*:192*//*197:*/
#line 1663 "./marpa.w"

Nulled_XSYIDs_of_XSY(xsy)= NULL;

/*:197*//*200:*/
#line 1679 "./marpa.w"
NSY_of_XSY(xsy)= NULL;
/*:200*//*204:*/
#line 1711 "./marpa.w"
Nulling_NSY_of_XSY(xsy)= NULL;
/*:204*/
#line 1264 "./marpa.w"

symbol_add(g,xsy);
return xsy;
}

/*:146*//*147:*/
#line 1269 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const XSY symbol= symbol_new(g);
return ID_of_XSY(symbol);
}

/*:147*//*150:*/
#line 1280 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1283 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1284 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1285 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1286 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_start;
}

/*:150*//*153:*/
#line 1296 "./marpa.w"

int marpa_g_symbol_rank(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1301 "./marpa.w"

clear_error(g);
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1303 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1304 "./marpa.w"

/*1196:*/
#line 14167 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1196*/
#line 1305 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
return Rank_of_XSY(xsy);
}
/*:153*//*154:*/
#line 1309 "./marpa.w"

int marpa_g_symbol_rank_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,Marpa_Rank rank)
{
XSY xsy;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1314 "./marpa.w"

clear_error(g);
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1316 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 1317 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1318 "./marpa.w"

/*1196:*/
#line 14167 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1196*/
#line 1319 "./marpa.w"

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
#line 1366 "./marpa.w"

int marpa_g_symbol_is_valued(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1371 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1372 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1373 "./marpa.w"

return XSY_is_Valued(XSY_by_ID(xsy_id));
}

/*:161*//*162:*/
#line 1377 "./marpa.w"

int marpa_g_symbol_is_valued_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1382 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1383 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1384 "./marpa.w"

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
#line 1412 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1415 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1416 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 1417 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1418 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1419 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(xsy_id));
}

/*:165*//*168:*/
#line 1427 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1431 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1432 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1433 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1434 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_counted;
}

/*:168*//*171:*/
#line 1443 "./marpa.w"

int marpa_g_symbol_is_nulling(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1446 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1447 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 1448 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1449 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1450 "./marpa.w"

return XSY_is_Nulling(XSY_by_ID(xsy_id));
}

/*:171*//*174:*/
#line 1460 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1463 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1464 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 1465 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1466 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1467 "./marpa.w"

return XSYID_is_Nullable(xsy_id);
}

/*:174*//*178:*/
#line 1487 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1491 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1492 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1493 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1494 "./marpa.w"

return XSYID_is_Terminal(xsy_id);
}
/*:178*//*179:*/
#line 1497 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1502 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1503 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 1504 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1505 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1506 "./marpa.w"

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
#line 1528 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1533 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1534 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 1535 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1536 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1537 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(xsy_id));
}

/*:182*//*185:*/
#line 1547 "./marpa.w"

int marpa_g_symbol_is_completion_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1551 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1552 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1553 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1554 "./marpa.w"

return XSYID_is_Completion_Event(xsy_id);
}
/*:185*//*186:*/
#line 1557 "./marpa.w"

int marpa_g_symbol_is_completion_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1562 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1563 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 1564 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1565 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1566 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Completion_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:186*//*189:*/
#line 1582 "./marpa.w"

int marpa_g_symbol_is_nulled_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1586 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1587 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1588 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1589 "./marpa.w"

return XSYID_is_Nulled_Event(xsy_id);
}
/*:189*//*190:*/
#line 1592 "./marpa.w"

int marpa_g_symbol_is_nulled_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1597 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1598 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 1599 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1600 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1601 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Nulled_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:190*//*193:*/
#line 1617 "./marpa.w"

int marpa_g_symbol_is_prediction_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1621 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1622 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1623 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1624 "./marpa.w"

return XSYID_is_Prediction_Event(xsy_id);
}
/*:193*//*194:*/
#line 1627 "./marpa.w"

int marpa_g_symbol_is_prediction_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1632 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1633 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 1634 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1635 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1636 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Prediction_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:194*//*195:*/
#line 1646 "./marpa.w"

/*:195*//*201:*/
#line 1680 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1687 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1688 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1689 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:201*//*205:*/
#line 1712 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nulling_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1719 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 1720 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 1721 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= Nulling_NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:205*//*207:*/
#line 1733 "./marpa.w"

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
#line 1791 "./marpa.w"

PRIVATE NSY
nsy_start(GRAMMAR g)
{
const NSY nsy= marpa_obs_new(g->t_obs,struct s_nsy,1);
ID_of_NSY(nsy)= MARPA_DSTACK_LENGTH((g)->t_nsy_stack);
*MARPA_DSTACK_PUSH((g)->t_nsy_stack,NSY)= nsy;
/*212:*/
#line 1783 "./marpa.w"

nsy->t_nulling_or_node.t_or_node_type= NULLING_TOKEN_OR_NODE;

nsy->t_unvalued_or_node.t_or_node_type= UNVALUED_TOKEN_OR_NODE;
nsy->t_unvalued_or_node.t_nsyid= ID_of_NSY(nsy);

/*:212*//*222:*/
#line 1859 "./marpa.w"
NSY_is_Start(nsy)= 0;
/*:222*//*225:*/
#line 1873 "./marpa.w"
NSY_is_LHS(nsy)= 0;
/*:225*//*228:*/
#line 1887 "./marpa.w"
NSY_is_Nulling(nsy)= 0;
/*:228*//*231:*/
#line 1904 "./marpa.w"
LHS_CIL_of_NSY(nsy)= NULL;

/*:231*//*233:*/
#line 1912 "./marpa.w"
NSY_is_Semantic(nsy)= 0;
/*:233*//*236:*/
#line 1935 "./marpa.w"
Source_XSY_of_NSY(nsy)= NULL;
/*:236*//*240:*/
#line 1960 "./marpa.w"

LHS_XRL_of_NSY(nsy)= NULL;
XRL_Offset_of_NSY(nsy)= -1;

/*:240*//*245:*/
#line 2011 "./marpa.w"

Rank_of_NSY(nsy)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:245*/
#line 1798 "./marpa.w"

return nsy;
}

/*:214*//*215:*/
#line 1804 "./marpa.w"

PRIVATE NSY
nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_start(g);
Source_XSY_of_NSY(new_nsy)= source;
Rank_of_NSY(new_nsy)= NSY_Rank_by_XSY(source);
return new_nsy;
}

/*:215*//*216:*/
#line 1816 "./marpa.w"

PRIVATE NSY
semantic_nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_new(g,source);
NSY_is_Semantic(new_nsy)= 1;
return new_nsy;
}

/*:216*//*217:*/
#line 1827 "./marpa.w"

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
#line 1849 "./marpa.w"

int _marpa_g_nsy_count(Marpa_Grammar g){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1851 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1852 "./marpa.w"

return NSY_Count_of_G(g);
}

/*:220*//*223:*/
#line 1860 "./marpa.w"

int _marpa_g_nsy_is_start(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1863 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1864 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 1865 "./marpa.w"

/*1197:*/
#line 14172 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1197*/
#line 1866 "./marpa.w"

return NSY_is_Start(NSY_by_ID(nsy_id));
}

/*:223*//*226:*/
#line 1874 "./marpa.w"

int _marpa_g_nsy_is_lhs(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1877 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1878 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 1879 "./marpa.w"

/*1197:*/
#line 14172 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1197*/
#line 1880 "./marpa.w"

return NSY_is_LHS(NSY_by_ID(nsy_id));
}

/*:226*//*229:*/
#line 1888 "./marpa.w"

int _marpa_g_nsy_is_nulling(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1891 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 1892 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 1893 "./marpa.w"

/*1197:*/
#line 14172 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1197*/
#line 1894 "./marpa.w"

return NSY_is_Nulling(NSY_by_ID(nsy_id));
}

/*:229*//*234:*/
#line 1913 "./marpa.w"

int _marpa_g_nsy_is_semantic(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1918 "./marpa.w"

/*1197:*/
#line 14172 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1197*/
#line 1919 "./marpa.w"

return NSYID_is_Semantic(nsy_id);
}

/*:234*//*237:*/
#line 1936 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
XSY source_xsy;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1942 "./marpa.w"

/*1197:*/
#line 14172 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1197*/
#line 1943 "./marpa.w"

source_xsy= Source_XSY_of_NSYID(nsy_id);
return ID_of_XSY(source_xsy);
}

/*:237*//*242:*/
#line 1971 "./marpa.w"

Marpa_Rule_ID _marpa_g_nsy_lhs_xrl(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1974 "./marpa.w"

/*1197:*/
#line 14172 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1197*/
#line 1975 "./marpa.w"

{
const NSY nsy= NSY_by_ID(nsy_id);
const XRL lhs_xrl= LHS_XRL_of_NSY(nsy);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:242*//*243:*/
#line 1995 "./marpa.w"

int _marpa_g_nsy_xrl_offset(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 1998 "./marpa.w"

NSY nsy;
/*1197:*/
#line 14172 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1197*/
#line 2000 "./marpa.w"

nsy= NSY_by_ID(nsy_id);
return XRL_Offset_of_NSY(nsy);
}

/*:243*//*246:*/
#line 2013 "./marpa.w"

Marpa_Rank _marpa_g_nsy_rank(
Marpa_Grammar g,
Marpa_NSY_ID nsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2018 "./marpa.w"

/*1197:*/
#line 14172 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1197*/
#line 2019 "./marpa.w"

return Rank_of_NSY(NSY_by_ID(nsy_id));
}

/*:246*//*252:*/
#line 2054 "./marpa.w"

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
/*271:*/
#line 2400 "./marpa.w"

rule->t_rank= Default_Rank_of_G(g);
/*:271*//*275:*/
#line 2448 "./marpa.w"

rule->t_null_ranks_high= 0;
/*:275*//*279:*/
#line 2488 "./marpa.w"

rule->t_is_bnf= 0;

/*:279*//*281:*/
#line 2494 "./marpa.w"

rule->t_is_sequence= 0;

/*:281*//*283:*/
#line 2508 "./marpa.w"

rule->t_minimum= -1;
/*:283*//*286:*/
#line 2533 "./marpa.w"

Separator_of_XRL(rule)= -1;
/*:286*//*291:*/
#line 2566 "./marpa.w"

rule->t_is_discard= 0;
/*:291*//*295:*/
#line 2606 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:295*//*299:*/
#line 2627 "./marpa.w"

rule->t_is_loop= 0;
/*:299*//*302:*/
#line 2644 "./marpa.w"

XRL_is_Nulling(rule)= 0;
/*:302*//*305:*/
#line 2662 "./marpa.w"

XRL_is_Nullable(rule)= 0;
/*:305*//*309:*/
#line 2680 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:309*//*312:*/
#line 2698 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:312*//*315:*/
#line 2716 "./marpa.w"

XRL_is_Used(rule)= 0;
/*:315*/
#line 2078 "./marpa.w"

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

/*:252*//*253:*/
#line 2094 "./marpa.w"

PRIVATE IRL
irl_start(GRAMMAR g,int length)
{
IRL irl;
const size_t sizeof_irl= offsetof(struct s_irl,t_nsyid_array)+
((size_t)length+1)*sizeof(irl->t_nsyid_array[0]);


irl= marpa__obs_alloc(g->t_obs,sizeof_irl,ALIGNOF(IRL_Object));

ID_of_IRL(irl)= MARPA_DSTACK_LENGTH((g)->t_irl_stack);
Length_of_IRL(irl)= length;
/*336:*/
#line 2853 "./marpa.w"

IRL_has_Virtual_LHS(irl)= 0;
/*:336*//*339:*/
#line 2869 "./marpa.w"

IRL_has_Virtual_RHS(irl)= 0;
/*:339*//*342:*/
#line 2888 "./marpa.w"

IRL_is_Right_Recursive(irl)= 0;

/*:342*//*345:*/
#line 2899 "./marpa.w"
Real_SYM_Count_of_IRL(irl)= 0;
/*:345*//*348:*/
#line 2917 "./marpa.w"
irl->t_virtual_start= -1;
/*:348*//*351:*/
#line 2937 "./marpa.w"
irl->t_virtual_end= -1;
/*:351*//*354:*/
#line 2959 "./marpa.w"
Source_XRL_of_IRL(irl)= NULL;
/*:354*//*357:*/
#line 2986 "./marpa.w"

Rank_of_IRL(irl)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:357*//*360:*/
#line 3008 "./marpa.w"

First_AHM_of_IRL(irl)= NULL;

/*:360*//*463:*/
#line 4796 "./marpa.w"

Last_Proper_SYMI_of_IRL(irl)= -1;

/*:463*/
#line 2107 "./marpa.w"

*MARPA_DSTACK_PUSH((g)->t_irl_stack,IRL)= irl;
return irl;
}

PRIVATE void
irl_finish(GRAMMAR g,IRL irl)
{
const NSY lhs_nsy= LHS_of_IRL(irl);
NSY_is_LHS(lhs_nsy)= 1;
}

/*:253*//*255:*/
#line 2133 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,int length)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2138 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2141 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 2142 "./marpa.w"

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

/*:255*//*256:*/
#line 2187 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2194 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2195 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 2196 "./marpa.w"

/*258:*/
#line 2227 "./marpa.w"

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

/*:258*/
#line 2197 "./marpa.w"

/*257:*/
#line 2205 "./marpa.w"

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

/*:257*/
#line 2198 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:256*//*260:*/
#line 2280 "./marpa.w"

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

/*:260*//*263:*/
#line 2336 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:263*//*264:*/
#line 2340 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2342 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2343 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2344 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2345 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:264*//*265:*/
#line 2348 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:265*//*266:*/
#line 2352 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2355 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2356 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2357 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2358 "./marpa.w"

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

/*:266*//*267:*/
#line 2371 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2373 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2374 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2375 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2376 "./marpa.w"

return Length_of_XRL(XRL_by_ID(xrl_id));
}

/*:267*//*272:*/
#line 2403 "./marpa.w"

int marpa_g_rule_rank(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2408 "./marpa.w"

clear_error(g);
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2410 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2411 "./marpa.w"

/*1200:*/
#line 14191 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1200*/
#line 2412 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Rank_of_XRL(xrl);
}
/*:272*//*273:*/
#line 2416 "./marpa.w"

int marpa_g_rule_rank_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,Marpa_Rank rank)
{
XRL xrl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2421 "./marpa.w"

clear_error(g);
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2423 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 2424 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2425 "./marpa.w"

/*1200:*/
#line 14191 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1200*/
#line 2426 "./marpa.w"

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

/*:273*//*276:*/
#line 2452 "./marpa.w"

int marpa_g_rule_null_high(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2457 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2458 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2459 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2460 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Null_Ranks_High_of_RULE(xrl);
}
/*:276*//*277:*/
#line 2464 "./marpa.w"

int marpa_g_rule_null_high_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,int flag)
{
XRL xrl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2469 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2470 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 2471 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2472 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2473 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(_MARPA_UNLIKELY(flag<0||flag> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return Null_Ranks_High_of_RULE(xrl)= Boolean(flag);
}

/*:277*//*284:*/
#line 2510 "./marpa.w"

int marpa_g_sequence_min(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2515 "./marpa.w"

XRL xrl;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2517 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2518 "./marpa.w"

/*1200:*/
#line 14191 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1200*/
#line 2519 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Minimum_of_XRL(xrl);
}

/*:284*//*287:*/
#line 2535 "./marpa.w"

Marpa_Symbol_ID marpa_g_sequence_separator(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2540 "./marpa.w"

XRL xrl;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2542 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2543 "./marpa.w"

/*1200:*/
#line 14191 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1200*/
#line 2544 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Separator_of_XRL(xrl);
}

/*:287*//*292:*/
#line 2568 "./marpa.w"

int _marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2573 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2574 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2575 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2576 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:292*//*296:*/
#line 2608 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2613 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2614 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2615 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2616 "./marpa.w"

return!XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:296*//*300:*/
#line 2629 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2632 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2633 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2634 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2635 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 2636 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:300*//*303:*/
#line 2646 "./marpa.w"

int marpa_g_rule_is_nulling(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2649 "./marpa.w"

XRL xrl;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2651 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2652 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2653 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nulling(xrl);
}

/*:303*//*306:*/
#line 2664 "./marpa.w"

int marpa_g_rule_is_nullable(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2667 "./marpa.w"

XRL xrl;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2669 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2670 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2671 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nullable(xrl);
}

/*:306*//*310:*/
#line 2682 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2685 "./marpa.w"

XRL xrl;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2687 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2688 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2689 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:310*//*313:*/
#line 2700 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2703 "./marpa.w"

XRL xrl;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2705 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2706 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2707 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:313*//*316:*/
#line 2718 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2722 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 2723 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 2724 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:316*//*318:*/
#line 2731 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2736 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2737 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:318*//*327:*/
#line 2778 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
IRL irl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2781 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2782 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 2783 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2784 "./marpa.w"

irl= IRL_by_ID(irl_id);
return LHSID_of_IRL(irl);
}

/*:327*//*329:*/
#line 2791 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_rhs(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2794 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2795 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 2796 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2797 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHSID_of_IRL(irl,ix);
}

/*:329*//*331:*/
#line 2805 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2807 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 2808 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 2809 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2810 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}

/*:331*//*337:*/
#line 2855 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2860 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 2861 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2862 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:337*//*340:*/
#line 2871 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2876 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 2877 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2878 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:340*//*346:*/
#line 2900 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2905 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 2906 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2907 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:346*//*349:*/
#line 2918 "./marpa.w"

int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2924 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 2925 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2926 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:349*//*352:*/
#line 2938 "./marpa.w"

int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2944 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 2945 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2946 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:352*//*355:*/
#line 2960 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2966 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2967 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:355*//*358:*/
#line 2988 "./marpa.w"

Marpa_Rank _marpa_g_irl_rank(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 2993 "./marpa.w"

/*1198:*/
#line 14177 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1198*/
#line 2994 "./marpa.w"

return Rank_of_IRL(IRL_by_ID(irl_id));
}

/*:358*//*362:*/
#line 3028 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 3031 "./marpa.w"

int return_value= failure_indicator;
struct marpa_obstack*obs_precompute= marpa_obs_init;
/*367:*/
#line 3154 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);

/*:367*//*371:*/
#line 3187 "./marpa.w"

XSYID start_xsy_id= g->t_start_xsy_id;

/*:371*//*384:*/
#line 3490 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:384*/
#line 3034 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 3035 "./marpa.w"

G_EVENTS_CLEAR(g);
/*368:*/
#line 3158 "./marpa.w"

if(_MARPA_UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
goto FAILURE;
}

/*:368*/
#line 3037 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 3038 "./marpa.w"

/*370:*/
#line 3168 "./marpa.w"

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

/*:370*/
#line 3039 "./marpa.w"





/*122:*/
#line 1114 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 3044 "./marpa.w"




{
/*376:*/
#line 3369 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:376*//*377:*/
#line 3372 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;

/*:377*//*378:*/
#line 3377 "./marpa.w"

RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:378*//*382:*/
#line 3436 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:382*/
#line 3049 "./marpa.w"

/*366:*/
#line 3139 "./marpa.w"

{
/*374:*/
#line 3211 "./marpa.w"

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

/*:374*/
#line 3141 "./marpa.w"

/*375:*/
#line 3338 "./marpa.w"

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

/*:375*/
#line 3142 "./marpa.w"

/*383:*/
#line 3458 "./marpa.w"

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
#line 3143 "./marpa.w"

/*379:*/
#line 3381 "./marpa.w"

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
#line 3144 "./marpa.w"

/*380:*/
#line 3409 "./marpa.w"

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
#line 3145 "./marpa.w"

/*381:*/
#line 3430 "./marpa.w"

if(_MARPA_UNLIKELY(!bv_bit_test(productive_v,start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:381*/
#line 3146 "./marpa.w"

/*385:*/
#line 3495 "./marpa.w"

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
#line 3147 "./marpa.w"

/*386:*/
#line 3515 "./marpa.w"

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
#line 3148 "./marpa.w"

/*387:*/
#line 3554 "./marpa.w"

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
#line 3605 "./marpa.w"

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
#line 3565 "./marpa.w"

continue;
}
/*388:*/
#line 3574 "./marpa.w"

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
#line 3568 "./marpa.w"

}
}

/*:387*/
#line 3149 "./marpa.w"

/*390:*/
#line 3670 "./marpa.w"

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
#line 3150 "./marpa.w"

/*391:*/
#line 3699 "./marpa.w"

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
#line 3151 "./marpa.w"

}

/*:366*/
#line 3050 "./marpa.w"

/*438:*/
#line 4553 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,xrl_count,
xrl_count);
/*439:*/
#line 4574 "./marpa.w"

{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule= XRL_by_ID(rule_id);
XSYID nonnullable_id= -1;
int nonnullable_count= 0;
int rhs_ix,rule_length;
rule_length= Length_of_XRL(rule);



for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
XSYID xsy_id= RHS_ID_of_RULE(rule,rhs_ix);
if(bv_bit_test(nullable_v,xsy_id))
continue;
nonnullable_id= xsy_id;
nonnullable_count++;
}

if(nonnullable_count==1)
{



/*440:*/
#line 4629 "./marpa.w"

{
RULEID*p_xrl= xrl_list_x_lh_sym[nonnullable_id];
const RULEID*p_one_past_rules= xrl_list_x_lh_sym[nonnullable_id+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{


const RULEID to_rule_id= *p_xrl;
matrix_bit_set(unit_transition_matrix,rule_id,
to_rule_id);
}
}

/*:440*/
#line 4602 "./marpa.w"

}
else if(nonnullable_count==0)
{
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{




nonnullable_id= RHS_ID_of_RULE(rule,rhs_ix);

if(XSY_is_Nulling(XSY_by_ID(nonnullable_id)))
continue;



/*440:*/
#line 4629 "./marpa.w"

{
RULEID*p_xrl= xrl_list_x_lh_sym[nonnullable_id];
const RULEID*p_one_past_rules= xrl_list_x_lh_sym[nonnullable_id+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{


const RULEID to_rule_id= *p_xrl;
matrix_bit_set(unit_transition_matrix,rule_id,
to_rule_id);
}
}

/*:440*/
#line 4620 "./marpa.w"

}
}
}
}

/*:439*/
#line 4559 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*441:*/
#line 4643 "./marpa.w"

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
#line 4561 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:438*/
#line 3051 "./marpa.w"

}



/*502:*/
#line 5205 "./marpa.w"

MARPA_DSTACK_INIT(g->t_irl_stack,IRL,2*MARPA_DSTACK_CAPACITY(g->t_xrl_stack));

/*:502*/
#line 3056 "./marpa.w"

/*503:*/
#line 5213 "./marpa.w"

{
MARPA_DSTACK_INIT(g->t_nsy_stack,NSY,2*MARPA_DSTACK_CAPACITY(g->t_xsy_stack));
}

/*:503*/
#line 3057 "./marpa.w"

/*403:*/
#line 3899 "./marpa.w"

{
/*404:*/
#line 3930 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:404*//*407:*/
#line 3988 "./marpa.w"

int factor_count;
int*factor_positions;
/*:407*/
#line 3901 "./marpa.w"

/*408:*/
#line 3991 "./marpa.w"

factor_positions= marpa_obs_new(obs_precompute,int,g->t_max_rule_length);

/*:408*/
#line 3902 "./marpa.w"

/*405:*/
#line 3936 "./marpa.w"

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
#line 3903 "./marpa.w"

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
#line 3752 "./marpa.w"

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
#line 3781 "./marpa.w"

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
#line 3773 "./marpa.w"

if(separator_nsyid>=0&&!XRL_is_Proper_Separation(rule)){
/*394:*/
#line 3794 "./marpa.w"

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
#line 3775 "./marpa.w"

}
/*395:*/
#line 3811 "./marpa.w"

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
#line 3777 "./marpa.w"

/*396:*/
#line 3822 "./marpa.w"

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
#line 3778 "./marpa.w"

}

/*:392*/
#line 3916 "./marpa.w"

continue;
}
/*406:*/
#line 3967 "./marpa.w"

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
#line 3919 "./marpa.w"


if(factor_count> 0)
{
/*409:*/
#line 3995 "./marpa.w"

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
#line 4031 "./marpa.w"

NSY chaf_virtual_nsy;
NSYID chaf_virtual_nsyid;
int first_factor_position= factor_positions[factor_position_ix];
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;



/*410:*/
#line 4021 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:410*/
#line 4041 "./marpa.w"

/*413:*/
#line 4060 "./marpa.w"

{
{
const int real_symbol_count= piece_end-piece_start+1;
/*418:*/
#line 4158 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4172 "./marpa.w"

}

/*:418*/
#line 4064 "./marpa.w"
;
}
/*414:*/
#line 4074 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4096 "./marpa.w"

}

/*:414*/
#line 4066 "./marpa.w"
;
{
const int real_symbol_count= piece_end-piece_start+1;
/*420:*/
#line 4204 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4228 "./marpa.w"

}

/*:420*/
#line 4069 "./marpa.w"
;
}
/*415:*/
#line 4104 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4142 "./marpa.w"

}
}

/*:415*/
#line 4071 "./marpa.w"
;
}

/*:413*/
#line 4042 "./marpa.w"

factor_position_ix++;
}else{
piece_end= second_factor_position;
/*410:*/
#line 4021 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:410*/
#line 4046 "./marpa.w"

/*417:*/
#line 4148 "./marpa.w"

{
const int real_symbol_count= piece_end-piece_start+1;
/*418:*/
#line 4158 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4172 "./marpa.w"

}

/*:418*/
#line 4151 "./marpa.w"

/*419:*/
#line 4176 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4200 "./marpa.w"

}

/*:419*/
#line 4152 "./marpa.w"

/*420:*/
#line 4204 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4228 "./marpa.w"

}

/*:420*/
#line 4153 "./marpa.w"

/*421:*/
#line 4232 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4266 "./marpa.w"

}

/*:421*/
#line 4154 "./marpa.w"

}

/*:417*/
#line 4047 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_nsy= chaf_virtual_nsy;
current_lhs_nsyid= chaf_virtual_nsyid;
piece_start= piece_end+1;

/*:412*/
#line 4012 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*422:*/
#line 4271 "./marpa.w"

{
const int first_factor_position= factor_positions[factor_position_ix];
const int second_factor_position= factor_positions[factor_position_ix+1];
const int real_symbol_count= Length_of_XRL(rule)-piece_start;
piece_end= Length_of_XRL(rule)-1;
/*423:*/
#line 4284 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4297 "./marpa.w"

}

/*:423*/
#line 4277 "./marpa.w"

/*424:*/
#line 4301 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4324 "./marpa.w"

}

/*:424*/
#line 4278 "./marpa.w"

/*425:*/
#line 4328 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4351 "./marpa.w"

}

/*:425*/
#line 4279 "./marpa.w"

/*426:*/
#line 4356 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4393 "./marpa.w"

}
}

/*:426*/
#line 4280 "./marpa.w"

}

/*:422*/
#line 4015 "./marpa.w"

}else{
/*427:*/
#line 4398 "./marpa.w"

{
int real_symbol_count;
const int first_factor_position= factor_positions[factor_position_ix];
piece_end= Length_of_XRL(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*428:*/
#line 4409 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4422 "./marpa.w"

}

/*:428*/
#line 4404 "./marpa.w"

/*429:*/
#line 4427 "./marpa.w"

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
#line 4461 "./marpa.w"

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
#line 4453 "./marpa.w"

}
}

/*:429*/
#line 4405 "./marpa.w"

}

/*:427*/
#line 4017 "./marpa.w"

}
}

/*:409*/
#line 3923 "./marpa.w"

continue;
}
/*254:*/
#line 2119 "./marpa.w"

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

/*:254*/
#line 3926 "./marpa.w"

}
}

/*:403*/
#line 3058 "./marpa.w"

/*432:*/
#line 4478 "./marpa.w"

{
const XSY start_xsy= XSY_by_ID(start_xsy_id);
if(_MARPA_LIKELY(!XSY_is_Nulling(start_xsy))){
/*433:*/
#line 4486 "./marpa.w"
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
#line 4482 "./marpa.w"

}
}

/*:432*/
#line 3059 "./marpa.w"




if(!G_is_Trivial(g)){
/*501:*/
#line 5195 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
const NSYID nsy_count= NSY_Count_of_G(g);
const XSYID xsy_count= XSY_Count_of_G(g);
Bit_Matrix nsy_by_right_nsy_matrix;
Bit_Matrix prediction_nsy_by_irl_matrix;

/*:501*/
#line 3065 "./marpa.w"

/*504:*/
#line 5218 "./marpa.w"

{
NSYID lhsid;




void*matrix_buffer= my_malloc(matrix_sizeof(
nsy_count,irl_count));
Bit_Matrix irl_by_lhs_matrix= 
matrix_buffer_create(matrix_buffer,nsy_count,irl_count);

IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
const IRL irl= IRL_by_ID(irl_id);
const NSYID lhs_nsyid= LHSID_of_IRL(irl);
matrix_bit_set(irl_by_lhs_matrix,lhs_nsyid,irl_id);
}




for(lhsid= 0;lhsid<nsy_count;lhsid++)
{
IRLID irlid;
int min,max,start;
cil_buffer_clear(&g->t_cilar);
for(start= 0;
bv_scan(matrix_row
(irl_by_lhs_matrix,lhsid),
start,&min,&max);start= max+2)
{
for(irlid= min;irlid<=max;irlid++)
{
cil_buffer_push(&g->t_cilar,irlid);
}
}
LHS_CIL_of_NSYID(lhsid)= cil_buffer_add(&g->t_cilar);
}

my_free(matrix_buffer);

}

/*:504*/
#line 3066 "./marpa.w"

/*475:*/
#line 4866 "./marpa.w"

{
IRLID irl_id;
int ahm_count= 0;
AHM base_item;
AHM current_item;
int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*477:*/
#line 4918 "./marpa.w"

{
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
const NSY nsy= NSY_by_ID(rh_nsyid);
if(!NSY_is_Nulling(nsy))ahm_count++;
}
ahm_count++;
}

/*:477*/
#line 4875 "./marpa.w"

}
current_item= base_item= marpa_new(struct s_ahm,ahm_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
SYMI_of_IRL(irl)= symbol_instance_of_next_rule;
/*476:*/
#line 4893 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
const AHM first_ahm_of_irl= current_item;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{
Last_Proper_SYMI_of_IRL(irl)= symbol_instance_of_next_rule+rhs_ix;
/*478:*/
#line 4930 "./marpa.w"

{
/*480:*/
#line 4953 "./marpa.w"

{
IRL_of_AHM(current_item)= irl;
Null_Count_of_AHM(current_item)= leading_nulls;
Quasi_Position_of_AHM(current_item)= current_item-first_ahm_of_irl;
if(Quasi_Position_of_AHM(current_item)==0){
if(ID_of_IRL(irl)==ID_of_IRL(g->t_start_irl))
{
AHM_was_Predicted(current_item)= 0;
AHM_is_Initial(current_item)= 1;
}else{
AHM_was_Predicted(current_item)= 1;
AHM_is_Initial(current_item)= 0;
}
}else{
AHM_was_Predicted(current_item)= 0;
AHM_is_Initial(current_item)= 0;
}
/*495:*/
#line 5092 "./marpa.w"

Event_AHMIDs_of_AHM(current_item)= NULL;
Event_Group_Size_of_AHM(current_item)= 0;

/*:495*/
#line 4971 "./marpa.w"

}

/*:480*/
#line 4932 "./marpa.w"

AHM_predicts_ZWA(current_item)= 0;

Postdot_NSYID_of_AHM(current_item)= rh_nsyid;
Position_of_AHM(current_item)= rhs_ix;
SYMI_of_AHM(current_item)
= AHM_is_Prediction(current_item)
?-1
:SYMI_of_IRL(irl)+Position_of_AHM(current_item-1);
/*481:*/
#line 4974 "./marpa.w"

{
XRL source_xrl= Source_XRL_of_IRL(irl);
XRL_of_AHM(current_item)= source_xrl;
if(!source_xrl){


XRL_Position_of_AHM(current_item)= -2;
}else{
const int virtual_start= Virtual_Start_of_IRL(irl);
const int irl_position= Position_of_AHM(current_item);
int xrl_position= irl_position;
if(virtual_start>=0)
{
xrl_position+= virtual_start;
}
if(XRL_is_Sequence(source_xrl))
{




xrl_position= irl_position> 0?-1:0;
}
XRL_Position_of_AHM(current_item)= xrl_position;
}
}

/*:481*/
#line 4941 "./marpa.w"

}

/*:478*/
#line 4904 "./marpa.w"

current_item++;
leading_nulls= 0;
}
else
{
leading_nulls++;
}
}
/*479:*/
#line 4944 "./marpa.w"

{
/*480:*/
#line 4953 "./marpa.w"

{
IRL_of_AHM(current_item)= irl;
Null_Count_of_AHM(current_item)= leading_nulls;
Quasi_Position_of_AHM(current_item)= current_item-first_ahm_of_irl;
if(Quasi_Position_of_AHM(current_item)==0){
if(ID_of_IRL(irl)==ID_of_IRL(g->t_start_irl))
{
AHM_was_Predicted(current_item)= 0;
AHM_is_Initial(current_item)= 1;
}else{
AHM_was_Predicted(current_item)= 1;
AHM_is_Initial(current_item)= 0;
}
}else{
AHM_was_Predicted(current_item)= 0;
AHM_is_Initial(current_item)= 0;
}
/*495:*/
#line 5092 "./marpa.w"

Event_AHMIDs_of_AHM(current_item)= NULL;
Event_Group_Size_of_AHM(current_item)= 0;

/*:495*/
#line 4971 "./marpa.w"

}

/*:480*/
#line 4946 "./marpa.w"

Postdot_NSYID_of_AHM(current_item)= -1;
Position_of_AHM(current_item)= -1;
SYMI_of_AHM(current_item)= SYMI_of_IRL(irl)+Position_of_AHM(current_item-1);
/*481:*/
#line 4974 "./marpa.w"

{
XRL source_xrl= Source_XRL_of_IRL(irl);
XRL_of_AHM(current_item)= source_xrl;
if(!source_xrl){


XRL_Position_of_AHM(current_item)= -2;
}else{
const int virtual_start= Virtual_Start_of_IRL(irl);
const int irl_position= Position_of_AHM(current_item);
int xrl_position= irl_position;
if(virtual_start>=0)
{
xrl_position+= virtual_start;
}
if(XRL_is_Sequence(source_xrl))
{




xrl_position= irl_position> 0?-1:0;
}
XRL_Position_of_AHM(current_item)= xrl_position;
}
}

/*:481*/
#line 4950 "./marpa.w"

}

/*:479*/
#line 4913 "./marpa.w"

current_item++;
AHM_Count_of_IRL(irl)= current_item-first_ahm_of_irl;
}

/*:476*/
#line 4881 "./marpa.w"

{
symbol_instance_of_next_rule+= Length_of_IRL(irl);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(ahm_count==current_item-base_item);
AHM_Count_of_G(g)= ahm_count;
g->t_ahms= marpa_renew(struct s_ahm,base_item,ahm_count);
/*483:*/
#line 5010 "./marpa.w"

{
AHM items= g->t_ahms;
AHMID item_id= (AHMID)ahm_count;
for(item_id--;item_id>=0;item_id--)
{
AHM item= items+item_id;
IRL irl= IRL_of_AHM(item);
First_AHM_of_IRL(irl)= item;
}
}

/*:483*/
#line 4890 "./marpa.w"

}

/*:475*/
#line 3067 "./marpa.w"

/*507:*/
#line 5271 "./marpa.w"
{
Bit_Matrix prediction_nsy_by_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*508:*/
#line 5279 "./marpa.w"

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

const AHM item= First_AHM_of_IRL(irl);
to_nsyid= Postdot_NSYID_of_AHM(item);

if(to_nsyid<0)
continue;

from_nsyid= LHS_NSYID_of_AHM(item);
matrix_bit_set(prediction_nsy_by_nsy_matrix,
from_nsyid,
to_nsyid);
}
}

/*:508*/
#line 5274 "./marpa.w"

transitive_closure(prediction_nsy_by_nsy_matrix);
/*509:*/
#line 5316 "./marpa.w"
{
/*510:*/
#line 5320 "./marpa.w"

{
NSYID from_nsyid;
prediction_nsy_by_irl_matrix= 
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
int cil_ix;
const CIL lhs_cil= LHS_CIL_of_NSYID(to_nsyid);
const int cil_count= Count_of_CIL(lhs_cil);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
const IRLID irlid= Item_of_CIL(lhs_cil,cil_ix);
matrix_bit_set(prediction_nsy_by_irl_matrix,
from_nsyid,irlid);
}
}
}
}
}

/*:510*/
#line 5317 "./marpa.w"

}

/*:509*/
#line 5276 "./marpa.w"

}

/*:507*/
#line 3068 "./marpa.w"

/*497:*/
#line 5105 "./marpa.w"
{
nsy_by_right_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*498:*/
#line 5116 "./marpa.w"

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

/*:498*/
#line 5108 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
/*499:*/
#line 5141 "./marpa.w"

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

/*:499*/
#line 5110 "./marpa.w"

matrix_clear(nsy_by_right_nsy_matrix);
/*500:*/
#line 5168 "./marpa.w"

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

/*:500*/
#line 5112 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
}

/*:497*/
#line 3069 "./marpa.w"

/*512:*/
#line 5357 "./marpa.w"

{
AHMID ahm_id;
const int ahm_count= AHM_Count_of_G(g);
for(ahm_id= 0;ahm_id<ahm_count;ahm_id++)
{
const AHM ahm= AHM_by_ID(ahm_id);
const NSYID postdot_nsyid= Postdot_NSYID_of_AHM(ahm);
if(postdot_nsyid<0)
{
Predicted_IRL_CIL_of_AHM(ahm)= cil_empty(&g->t_cilar);
LHS_CIL_of_AHM(ahm)= cil_empty(&g->t_cilar);
}
else
{
Predicted_IRL_CIL_of_AHM(ahm)= 
cil_bv_add(&g->t_cilar,
matrix_row(prediction_nsy_by_irl_matrix,postdot_nsyid));
LHS_CIL_of_AHM(ahm)= LHS_CIL_of_NSYID(postdot_nsyid);
}
}
}

/*:512*/
#line 3070 "./marpa.w"

/*513:*/
#line 5381 "./marpa.w"

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

/*:513*/
#line 3071 "./marpa.w"

/*514:*/
#line 5402 "./marpa.w"

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

/*:514*/
#line 3072 "./marpa.w"

/*515:*/
#line 5425 "./marpa.w"

{
AHMID ahm_id;
const int ahm_count_of_g= AHM_Count_of_G(g);
const LBV bv_completion_xsyid= bv_create(xsy_count);
const LBV bv_prediction_xsyid= bv_create(xsy_count);
const LBV bv_nulled_xsyid= bv_create(xsy_count);
const CILAR cilar= &g->t_cilar;
for(ahm_id= 0;ahm_id<ahm_count_of_g;ahm_id++)
{
const AHM ahm= AHM_by_ID(ahm_id);
const NSYID postdot_nsyid= Postdot_NSYID_of_AHM(ahm);
const IRL irl= IRL_of_AHM(ahm);
bv_clear(bv_completion_xsyid);
bv_clear(bv_prediction_xsyid);
bv_clear(bv_nulled_xsyid);
{
int rhs_ix;
int raw_position= Position_of_AHM(ahm);
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
for(rhs_ix= raw_position-Null_Count_of_AHM(ahm);
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
Completion_XSYIDs_of_AHM(ahm)= 
cil_bv_add(cilar,bv_completion_xsyid);
Nulled_XSYIDs_of_AHM(ahm)= cil_bv_add(cilar,bv_nulled_xsyid);
Prediction_XSYIDs_of_AHM(ahm)= 
cil_bv_add(cilar,bv_prediction_xsyid);
}
bv_free(bv_completion_xsyid);
bv_free(bv_prediction_xsyid);
bv_free(bv_nulled_xsyid);
}

/*:515*/
#line 3074 "./marpa.w"

/*516:*/
#line 5491 "./marpa.w"

{
AHMID ahm_id;
for(ahm_id= 0;ahm_id<AHM_Count_of_G(g);ahm_id++)
{
const CILAR cilar= &g->t_cilar;
const AHM ahm= AHM_by_ID(ahm_id);
const int ahm_is_event= 
Count_of_CIL(Completion_XSYIDs_of_AHM(ahm))
||Count_of_CIL(Nulled_XSYIDs_of_AHM(ahm))
||Count_of_CIL(Prediction_XSYIDs_of_AHM(ahm));
Event_AHMIDs_of_AHM(ahm)= 
ahm_is_event?cil_singleton(cilar,ahm_id):cil_empty(cilar);
}
}

/*:516*/
#line 3075 "./marpa.w"

/*517:*/
#line 5507 "./marpa.w"

{
const int ahm_count_of_g= AHM_Count_of_G(g);
AHMID outer_ahm_id;
for(outer_ahm_id= 0;outer_ahm_id<ahm_count_of_g;outer_ahm_id++)
{
AHMID inner_ahm_id;
const AHM outer_ahm= AHM_by_ID(outer_ahm_id);




NSYID outer_nsyid;
if(!AHM_is_Leo_Completion(outer_ahm)){
if(AHM_has_Event(outer_ahm)){
Event_Group_Size_of_AHM(outer_ahm)= 1;
}
continue;

}
outer_nsyid= LHSID_of_AHM(outer_ahm);
for(inner_ahm_id= 0;inner_ahm_id<ahm_count_of_g;
inner_ahm_id++)
{
NSYID inner_nsyid;
const AHM inner_ahm= AHM_by_ID(inner_ahm_id);
if(!AHM_has_Event(inner_ahm))
continue;

if(!AHM_is_Leo_Completion(inner_ahm))
continue;

inner_nsyid= LHSID_of_AHM(inner_ahm);
if(matrix_bit_test(nsy_by_right_nsy_matrix,
outer_nsyid,
inner_nsyid))
{



Event_Group_Size_of_AHM(outer_ahm)++;
}
}
}
}

/*:517*/
#line 3076 "./marpa.w"

/*536:*/
#line 5712 "./marpa.w"

{
AHMID ahm_id;
const int ahm_count_of_g= AHM_Count_of_G(g);
for(ahm_id= 0;ahm_id<ahm_count_of_g;ahm_id++)
{
ZWP_Object sought_zwp_object;
ZWP sought_zwp= &sought_zwp_object;
ZWP found_zwp;
MARPA_AVL_TRAV traverser;
const AHM ahm= AHM_by_ID(ahm_id);
const XRL ahm_xrl= XRL_of_AHM(ahm);
cil_buffer_clear(&g->t_cilar);
if(ahm_xrl)
{
const int xrl_dot_end= Raw_XRL_Position_of_AHM(ahm);
const int xrl_dot_start= xrl_dot_end-Null_Count_of_AHM(ahm);


const XRLID sought_xrlid= ID_of_XRL(ahm_xrl);
XRLID_of_ZWP(sought_zwp)= sought_xrlid;
Dot_of_ZWP(sought_zwp)= xrl_dot_start;
ZWAID_of_ZWP(sought_zwp)= 0;
traverser= _marpa_avl_t_init((g)->t_zwp_tree);
found_zwp= _marpa_avl_t_at_or_after(traverser,sought_zwp);



while(
found_zwp
&&XRLID_of_ZWP(found_zwp)==sought_xrlid
&&Dot_of_ZWP(found_zwp)<=xrl_dot_end)
{
cil_buffer_push(&g->t_cilar,ZWAID_of_ZWP(found_zwp));
found_zwp= _marpa_avl_t_next(traverser);
}
}
ZWA_CIL_of_AHM(ahm)= cil_buffer_add(&g->t_cilar);
}
}

/*:536*/
#line 3077 "./marpa.w"

/*537:*/
#line 5757 "./marpa.w"

{
AHMID ahm_id;
const int ahm_count_of_g= AHM_Count_of_G(g);
for(ahm_id= 0;ahm_id<ahm_count_of_g;ahm_id++)
{
const AHM ahm_to_populate= AHM_by_ID(ahm_id);




const CIL prediction_cil= Predicted_IRL_CIL_of_AHM(ahm_to_populate);
const int prediction_count= Count_of_CIL(prediction_cil);

int cil_ix;
for(cil_ix= 0;cil_ix<prediction_count;cil_ix++)
{
const IRLID prediction_irlid= Item_of_CIL(prediction_cil,cil_ix);
const AHM prediction_ahm_of_irl= First_AHM_of_IRLID(prediction_irlid);
const CIL zwaids_of_prediction= ZWA_CIL_of_AHM(prediction_ahm_of_irl);
if(Count_of_CIL(zwaids_of_prediction)> 0){
AHM_predicts_ZWA(ahm_to_populate)= 1;
break;
}
}
}
}

/*:537*/
#line 3078 "./marpa.w"

}
g->t_is_precomputed= 1;
if(g->t_has_cycle)
{
MARPA_ERROR(MARPA_ERR_GRAMMAR_HAS_CYCLE);
goto FAILURE;
}
/*363:*/
#line 3100 "./marpa.w"

{cilar_buffer_reinit(&g->t_cilar);}
/*:363*/
#line 3086 "./marpa.w"

return_value= 0;
goto CLEANUP;
FAILURE:;
goto CLEANUP;
CLEANUP:;
marpa_obs_free(obs_precompute);
return return_value;
}

/*:362*//*373:*/
#line 3198 "./marpa.w"

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

/*:373*//*451:*/
#line 4705 "./marpa.w"

PRIVATE int ahm_is_valid(
GRAMMAR g,AHMID item_id)
{
return item_id<(AHMID)AHM_Count_of_G(g)&&item_id>=0;
}

/*:451*//*468:*/
#line 4829 "./marpa.w"

int _marpa_g_ahm_count(Marpa_Grammar g){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 4831 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 4832 "./marpa.w"

return AHM_Count_of_G(g);
}

/*:468*//*469:*/
#line 4836 "./marpa.w"

Marpa_IRL_ID _marpa_g_ahm_irl(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 4839 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 4840 "./marpa.w"

/*1204:*/
#line 14220 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1204*/
#line 4841 "./marpa.w"

return IRLID_of_AHM(AHM_by_ID(item_id));
}

/*:469*//*471:*/
#line 4846 "./marpa.w"

int _marpa_g_ahm_position(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 4849 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 4850 "./marpa.w"

/*1204:*/
#line 14220 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1204*/
#line 4851 "./marpa.w"

return Position_of_AHM(AHM_by_ID(item_id));
}

/*:471*//*473:*/
#line 4856 "./marpa.w"

Marpa_Symbol_ID _marpa_g_ahm_postdot(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 4859 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 4860 "./marpa.w"

/*1204:*/
#line 14220 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1204*/
#line 4861 "./marpa.w"

return Postdot_NSYID_of_AHM(AHM_by_ID(item_id));
}

/*:473*//*532:*/
#line 5622 "./marpa.w"

PRIVATE_NOT_INLINE int zwp_cmp(
const void*ap,
const void*bp,
void*param UNUSED)
{
const ZWP_Const zwp_a= ap;
const ZWP_Const zwp_b= bp;
int subkey= XRLID_of_ZWP(zwp_a)-XRLID_of_ZWP(zwp_b);
if(subkey)return subkey;
subkey= Dot_of_ZWP(zwp_a)-Dot_of_ZWP(zwp_b);
if(subkey)return subkey;
return ZWAID_of_ZWP(zwp_a)-ZWAID_of_ZWP(zwp_b);
}

/*:532*//*533:*/
#line 5637 "./marpa.w"

Marpa_Assertion_ID
marpa_g_zwa_new(Marpa_Grammar g,int default_value)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 5641 "./marpa.w"

ZWAID zwa_id;
GZWA gzwa;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 5644 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 5645 "./marpa.w"

if(_MARPA_UNLIKELY(default_value<0||default_value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
gzwa= marpa_obs_new(g->t_obs,GZWA_Object,1);
zwa_id= MARPA_DSTACK_LENGTH((g)->t_gzwa_stack);
*MARPA_DSTACK_PUSH((g)->t_gzwa_stack,GZWA)= gzwa;
gzwa->t_id= zwa_id;
gzwa->t_default_value= default_value?1:0;
return zwa_id;
}

/*:533*//*534:*/
#line 5659 "./marpa.w"

Marpa_Assertion_ID
marpa_g_highest_zwa_id(Marpa_Grammar g)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 5663 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 5664 "./marpa.w"

return ZWA_Count_of_G(g)-1;
}

/*:534*//*535:*/
#line 5671 "./marpa.w"

int
marpa_g_zwa_place(Marpa_Grammar g,
Marpa_Assertion_ID zwaid,
Marpa_Rule_ID xrl_id,int rhs_ix)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 5677 "./marpa.w"

void*avl_insert_result;
ZWP zwp;
XRL xrl;
int xrl_length;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 5682 "./marpa.w"

/*1192:*/
#line 14144 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1192*/
#line 5683 "./marpa.w"

/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 5684 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 5685 "./marpa.w"

/*1203:*/
#line 14209 "./marpa.w"

if(_MARPA_UNLIKELY(ZWAID_is_Malformed(zwaid))){
MARPA_ERROR(MARPA_ERR_INVALID_ASSERTION_ID);
return failure_indicator;
}

/*:1203*/
#line 5686 "./marpa.w"

/*1202:*/
#line 14203 "./marpa.w"

if(_MARPA_UNLIKELY(!ZWAID_of_G_Exists(zwaid))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_ASSERTION_ID);
return failure_indicator;
}
/*:1202*/
#line 5687 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(rhs_ix<-1){
MARPA_ERROR(MARPA_ERR_RHS_IX_NEGATIVE);
return failure_indicator;
}
xrl_length= Length_of_XRL(xrl);
if(xrl_length<=rhs_ix){
MARPA_ERROR(MARPA_ERR_RHS_IX_OOB);
return failure_indicator;
}
if(rhs_ix==-1){
rhs_ix= XRL_is_Sequence(xrl)?1:xrl_length;
}
zwp= marpa_obs_new(g->t_obs,ZWP_Object,1);
XRLID_of_ZWP(zwp)= xrl_id;
Dot_of_ZWP(zwp)= rhs_ix;
ZWAID_of_ZWP(zwp)= zwaid;
avl_insert_result= _marpa_avl_insert(g->t_zwp_tree,zwp);
return avl_insert_result?-1:0;
}

/*:535*//*541:*/
#line 5803 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
int nsy_count;
int irl_count;
/*1190:*/
#line 14136 "./marpa.w"
void*const failure_indicator= NULL;
/*:1190*/
#line 5809 "./marpa.w"

/*1193:*/
#line 14150 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1193*/
#line 5810 "./marpa.w"

nsy_count= NSY_Count_of_G(g);
irl_count= IRL_Count_of_G(g);
r= my_malloc(sizeof(struct marpa_r));
/*606:*/
#line 6390 "./marpa.w"
r->t_obs= marpa_obs_init;
/*:606*/
#line 5814 "./marpa.w"

/*544:*/
#line 5822 "./marpa.w"

r->t_ref_count= 1;

/*:544*//*549:*/
#line 5873 "./marpa.w"

{
G_of_R(r)= g;
grammar_ref(g);
}
/*:549*//*554:*/
#line 5892 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:554*//*556:*/
#line 5902 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:556*//*560:*/
#line 5929 "./marpa.w"

r->t_earley_item_warning_threshold= 
MAX(DEFAULT_YIM_WARNING_THRESHOLD,AHM_Count_of_G(g)*3);
/*:560*//*564:*/
#line 5958 "./marpa.w"
r->t_furthest_earleme= 0;
/*:564*//*569:*/
#line 5980 "./marpa.w"

r->t_lbv_xsyid_completion_event_is_active= NULL;
r->t_lbv_xsyid_nulled_event_is_active= NULL;
r->t_lbv_xsyid_prediction_event_is_active= NULL;
r->t_active_event_count= 0;

/*:569*//*571:*/
#line 5991 "./marpa.w"

r->t_bv_nsyid_is_expected= bv_obs_create(r->t_obs,nsy_count);
/*:571*//*575:*/
#line 6064 "./marpa.w"

r->t_nsy_expected_is_event= lbv_obs_new0(r->t_obs,nsy_count);
/*:575*//*593:*/
#line 6305 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:593*//*597:*/
#line 6338 "./marpa.w"

r->t_bv_irl_seen= bv_obs_create(r->t_obs,irl_count);
MARPA_DSTACK_INIT2(r->t_irl_cil_stack,CIL);
/*:597*//*600:*/
#line 6355 "./marpa.w"
r->t_is_exhausted= 0;
/*:600*//*604:*/
#line 6383 "./marpa.w"
r->t_first_inconsistent_ys= -1;

/*:604*//*610:*/
#line 6412 "./marpa.w"

{
ZWAID zwaid;
const int zwa_count= ZWA_Count_of_R(r);
(r)->t_zwas= marpa_obs_new(r->t_obs,ZWA_Object,ZWA_Count_of_R(r));
for(zwaid= 0;zwaid<zwa_count;zwaid++){
const GZWA gzwa= GZWA_by_ID(zwaid);
const ZWA zwa= RZWA_by_ID(zwaid);
ID_of_ZWA(zwa)= ID_of_GZWA(gzwa);
Default_Value_of_ZWA(zwa)= Default_Value_of_GZWA(gzwa);
Memo_Value_of_ZWA(zwa)= Default_Value_of_GZWA(gzwa);
Memo_YSID_of_ZWA(zwa)= -1;
}
}

/*:610*//*625:*/
#line 6506 "./marpa.w"

r->t_earley_set_count= 0;

/*:625*//*687:*/
#line 7297 "./marpa.w"

MARPA_DSTACK_INIT2(r->t_alternatives,ALT_Object);
/*:687*//*712:*/
#line 7798 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_yim_work_stack);
/*:712*//*716:*/
#line 7813 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_completion_stack);
/*:716*//*720:*/
#line 7824 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_earley_set_stack);
/*:720*//*810:*/
#line 9306 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
r->t_progress_report_traverser= NULL;
/*:810*//*844:*/
#line 9679 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:844*//*1222:*/
#line 14387 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:1222*//*1229:*/
#line 14462 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1229*//*1243:*/
#line 14662 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;
/*:1243*//*1251:*/
#line 14807 "./marpa.w"

r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:1251*/
#line 5815 "./marpa.w"

/*1172:*/
#line 13949 "./marpa.w"

{
if(G_is_Trivial(g)){
psar_safe(Dot_PSAR_of_R(r));
}else{
psar_init(Dot_PSAR_of_R(r),AHM_Count_of_G(g));
}
}
/*:1172*/
#line 5816 "./marpa.w"

return r;
}

/*:541*//*545:*/
#line 5826 "./marpa.w"

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

/*:545*//*546:*/
#line 5844 "./marpa.w"

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

/*:546*//*547:*/
#line 5858 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 5862 "./marpa.w"

/*551:*/
#line 5880 "./marpa.w"
grammar_unref(g);

/*:551*//*598:*/
#line 6341 "./marpa.w"

MARPA_DSTACK_DESTROY(r->t_irl_cil_stack);

/*:598*//*688:*/
#line 7299 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_alternatives);

/*:688*//*714:*/
#line 7806 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_yim_work_stack);

/*:714*//*718:*/
#line 7821 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_completion_stack);

/*:718*//*721:*/
#line 7825 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_earley_set_stack);

/*:721*//*812:*/
#line 9315 "./marpa.w"

/*811:*/
#line 9309 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:811*/
#line 9316 "./marpa.w"
;
/*:812*//*845:*/
#line 9681 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:845*//*1173:*/
#line 13957 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1173*/
#line 5863 "./marpa.w"

/*607:*/
#line 6391 "./marpa.w"
marpa_obs_free(r->t_obs);

/*:607*/
#line 5864 "./marpa.w"

my_free(r);
}

/*:547*//*557:*/
#line 5910 "./marpa.w"

unsigned int marpa_r_current_earleme(Marpa_Recognizer r)
{return(unsigned int)Current_Earleme_of_R(r);}

/*:557*//*558:*/
#line 5918 "./marpa.w"

PRIVATE YS ys_at_current_earleme(RECCE r)
{
const YS latest= Latest_YS_of_R(r);
if(Earleme_of_YS(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:558*//*561:*/
#line 5932 "./marpa.w"

int
marpa_r_earley_item_warning_threshold(Marpa_Recognizer r)
{
return r->t_earley_item_warning_threshold;
}

/*:561*//*562:*/
#line 5941 "./marpa.w"

int
marpa_r_earley_item_warning_threshold_set(Marpa_Recognizer r,int threshold)
{
const int new_threshold= threshold<=0?YIM_FATAL_THRESHOLD:threshold;
r->t_earley_item_warning_threshold= new_threshold;
return new_threshold;
}

/*:562*//*565:*/
#line 5959 "./marpa.w"

unsigned int marpa_r_furthest_earleme(Marpa_Recognizer r)
{return(unsigned int)Furthest_Earleme_of_R(r);}

/*:565*//*572:*/
#line 5999 "./marpa.w"

int marpa_r_terminals_expected(Marpa_Recognizer r,Marpa_Symbol_ID*buffer)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6002 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6003 "./marpa.w"

NSYID xsy_count;
Bit_Vector bv_terminals;
int min,max,start;
int next_buffer_ix= 0;

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6009 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 6010 "./marpa.w"


xsy_count= XSY_Count_of_G(g);
bv_terminals= bv_create(xsy_count);
for(start= 0;bv_scan(r->t_bv_nsyid_is_expected,start,&min,&max);
start= max+2)
{
NSYID nsyid;
for(nsyid= min;nsyid<=max;nsyid++)
{
const XSY xsy= Source_XSY_of_NSYID(nsyid);
bv_bit_set(bv_terminals,ID_of_XSY(xsy));
}
}

for(start= 0;bv_scan(bv_terminals,start,&min,&max);start= max+2)
{
XSYID xsyid;
for(xsyid= min;xsyid<=max;xsyid++)
{
buffer[next_buffer_ix++]= xsyid;
}
}
bv_free(bv_terminals);
return next_buffer_ix;
}

/*:572*//*573:*/
#line 6037 "./marpa.w"

int marpa_r_terminal_is_expected(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6041 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6042 "./marpa.w"

XSY xsy;
NSY nsy;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6045 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 6046 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 6047 "./marpa.w"

/*1196:*/
#line 14167 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1196*/
#line 6048 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(!XSY_is_Terminal(xsy))){
return 0;
}
nsy= NSY_of_XSY(xsy);
if(_MARPA_UNLIKELY(!nsy))return 0;
return bv_bit_test(r->t_bv_nsyid_is_expected,ID_of_NSY(nsy));
}

/*:573*//*576:*/
#line 6067 "./marpa.w"

int
marpa_r_expected_symbol_event_set(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int value)
{
XSY xsy;
NSY nsy;
NSYID nsyid;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6075 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6076 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6077 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 6078 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 6079 "./marpa.w"

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

/*:576*//*578:*/
#line 6116 "./marpa.w"

int
marpa_r_completion_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6121 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6122 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6123 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 6124 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 6125 "./marpa.w"

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

/*:578*//*580:*/
#line 6163 "./marpa.w"

int
marpa_r_nulled_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6168 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6169 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6170 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 6171 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 6172 "./marpa.w"

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

/*:580*//*582:*/
#line 6210 "./marpa.w"

int
marpa_r_prediction_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6215 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6216 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6217 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 6218 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 6219 "./marpa.w"

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

/*:582*//*594:*/
#line 6311 "./marpa.w"

int _marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6314 "./marpa.w"

/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6315 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6316 "./marpa.w"

return r->t_use_leo_flag;
}
/*:594*//*595:*/
#line 6319 "./marpa.w"

int _marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6323 "./marpa.w"

/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6324 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6325 "./marpa.w"

/*1205:*/
#line 14229 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1205*/
#line 6326 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:595*//*602:*/
#line 6366 "./marpa.w"

int marpa_r_is_exhausted(Marpa_Recognizer r)
{
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6369 "./marpa.w"

/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6370 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6371 "./marpa.w"

return R_is_Exhausted(r);
}

/*:602*//*629:*/
#line 6525 "./marpa.w"

int marpa_r_earley_set_value(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6528 "./marpa.w"

YS earley_set;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6530 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6531 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 6532 "./marpa.w"

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

/*:629*//*630:*/
#line 6548 "./marpa.w"

int
marpa_r_earley_set_values(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id,
int*p_value,void**p_pvalue)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6553 "./marpa.w"

YS earley_set;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6555 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6556 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 6557 "./marpa.w"

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

/*:630*//*631:*/
#line 6575 "./marpa.w"

int marpa_r_latest_earley_set_value_set(Marpa_Recognizer r,int value)
{
YS earley_set;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6579 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6580 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6581 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 6582 "./marpa.w"

earley_set= Latest_YS_of_R(r);
return Value_of_YS(earley_set)= value;
}

/*:631*//*632:*/
#line 6587 "./marpa.w"

int marpa_r_latest_earley_set_values_set(Marpa_Recognizer r,int value,
void*pvalue)
{
YS earley_set;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 6592 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6593 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 6594 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 6595 "./marpa.w"

earley_set= Latest_YS_of_R(r);
Value_of_YS(earley_set)= value;
PValue_of_YS(earley_set)= pvalue;
return 1;
}

/*:632*//*633:*/
#line 6603 "./marpa.w"

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
/*628:*/
#line 6521 "./marpa.w"

Value_of_YS(set)= -1;
PValue_of_YS(set)= NULL;

/*:628*//*1179:*/
#line 14013 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1179*/
#line 6618 "./marpa.w"

return set;
}

/*:633*//*643:*/
#line 6727 "./marpa.w"

PRIVATE YIM earley_item_create(const RECCE r,
const YIK_Object key)
{
/*1190:*/
#line 14136 "./marpa.w"
void*const failure_indicator= NULL;
/*:1190*/
#line 6731 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 6732 "./marpa.w"

YIM new_item;
YIM*end_of_work_stack;
const YS set= key.t_set;
const int count= ++YIM_Count_of_YS(set);
/*645:*/
#line 6787 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(_MARPA_UNLIKELY(count>=YIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_YIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:645*/
#line 6737 "./marpa.w"

new_item= marpa_obs_new(r->t_obs,struct s_earley_item,1);
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
YIM_is_Rejected(new_item)= 0;
YIM_is_Active(new_item)= 1;
{
SRC unique_yim_src= SRC_of_YIM(new_item);
SRC_is_Rejected(unique_yim_src)= 0;
SRC_is_Active(unique_yim_src)= 1;
}
Ord_of_YIM(new_item)= YIM_ORDINAL_CLAMP((unsigned int)count-1);
end_of_work_stack= WORK_YIM_PUSH(r);
*end_of_work_stack= new_item;
return new_item;
}

/*:643*//*644:*/
#line 6754 "./marpa.w"

PRIVATE YIM
earley_item_assign(const RECCE r,const YS set,const YS origin,
const AHM ahm)
{
const GRAMMAR g= G_of_R(r);
YIK_Object key;
YIM yim;
PSL psl;
AHMID ahm_id= ID_of_AHM(ahm);
PSL*psl_owner= &Dot_PSL_of_YS(origin);
if(!*psl_owner)
{
psl_claim(psl_owner,Dot_PSAR_of_R(r));
}
psl= *psl_owner;
yim= PSL_Datum(psl,ahm_id);
if(yim
&&Earleme_of_YIM(yim)==Earleme_of_YS(set)
&&Earleme_of_YS(Origin_of_YIM(yim))==Earleme_of_YS(origin))
{
return yim;
}
key.t_origin= origin;
key.t_ahm= ahm;
key.t_set= set;
yim= earley_item_create(r,key);
PSL_Datum(psl,ahm_id)= yim;
return yim;
}

/*:644*//*648:*/
#line 6817 "./marpa.w"

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

/*:648*//*657:*/
#line 6934 "./marpa.w"

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
/*:657*//*658:*/
#line 6954 "./marpa.w"

PRIVATE PIM first_pim_of_ys_by_nsyid(YS set,NSYID nsyid)
{
PIM*pim_nsy_p= pim_nsy_p_find(set,nsyid);
return pim_nsy_p?*pim_nsy_p:NULL;
}

/*:658*//*675:*/
#line 7109 "./marpa.w"

PRIVATE
SRCL unique_srcl_new(struct marpa_obstack*t_obs)
{
const SRCL new_srcl= marpa_obs_new(t_obs,SRCL_Object,1);
SRCL_is_Rejected(new_srcl)= 0;
SRCL_is_Active(new_srcl)= 1;
return new_srcl;
}

/*:675*//*676:*/
#line 7119 "./marpa.w"
PRIVATE
void
tkn_link_add(RECCE r,
YIM item,
YIM predecessor,
ALT alternative)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_YIM(item);
if(previous_source_type==NO_SOURCE)
{
const SRCL source_link= SRCL_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_TOKEN;
Predecessor_of_SRCL(source_link)= predecessor;
NSYID_of_SRCL(source_link)= NSYID_of_ALT(alternative);
Value_of_SRCL(source_link)= Value_of_ALT(alternative);
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= unique_srcl_new(r->t_obs);
new_link->t_next= LV_First_Token_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
NSYID_of_Source(new_link->t_source)= NSYID_of_ALT(alternative);
Value_of_Source(new_link->t_source)= Value_of_ALT(alternative);
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:676*//*677:*/
#line 7150 "./marpa.w"

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
new_link= unique_srcl_new(r->t_obs);
new_link->t_next= LV_First_Completion_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
}

/*:677*//*678:*/
#line 7180 "./marpa.w"

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
new_link= unique_srcl_new(r->t_obs);
new_link->t_next= LV_First_Leo_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Leo_SRCL_of_YIM(item)= new_link;
}

/*:678*//*680:*/
#line 7229 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,YIM item)
{
unsigned int previous_source_type= Source_Type_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*681:*/
#line 7246 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:681*/
#line 7237 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*682:*/
#line 7254 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:682*/
#line 7239 "./marpa.w"

return;
case SOURCE_IS_LEO:/*683:*/
#line 7262 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= new_link;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:683*/
#line 7241 "./marpa.w"

return;
}
}

/*:680*//*690:*/
#line 7305 "./marpa.w"

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

/*:690*//*692:*/
#line 7349 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= NSYID_of_ALT(a)-NSYID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:692*//*693:*/
#line 7366 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,JEARLEME earleme)
{
MARPA_DSTACK alternatives= &r->t_alternatives;
ALT end_of_stack= MARPA_DSTACK_TOP(*alternatives,ALT_Object);

if(!end_of_stack)return NULL;






if(earleme<End_Earleme_of_ALT(end_of_stack))
return NULL;

return MARPA_DSTACK_POP(*alternatives,ALT_Object);
}

/*:693*//*695:*/
#line 7393 "./marpa.w"

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

/*:695*//*696:*/
#line 7416 "./marpa.w"
int marpa_r_start_input(Marpa_Recognizer r)
{
int return_value= 1;
YS set0;
YIK_Object key;

IRL start_irl;
AHM start_ahm;

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 7425 "./marpa.w"

/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 7426 "./marpa.w"



/*1205:*/
#line 14229 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1205*/
#line 7429 "./marpa.w"

{
/*698:*/
#line 7554 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
const NSYID xsy_count= XSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
/*:698*/
#line 7431 "./marpa.w"

Current_Earleme_of_R(r)= 0;
/*704:*/
#line 7596 "./marpa.w"

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

/*:704*/
#line 7433 "./marpa.w"

G_EVENTS_CLEAR(g);
if(G_is_Trivial(g)){
/*601:*/
#line 6356 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:601*/
#line 7436 "./marpa.w"

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
/*756:*/
#line 8406 "./marpa.w"

r->t_bv_lim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_bv_pim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_pim_workarea= marpa_obs_new(r->t_obs,void*,nsy_count);
/*:756*//*775:*/
#line 8688 "./marpa.w"

r->t_lim_chain= marpa_obs_new(r->t_obs,void*,2*nsy_count);
/*:775*/
#line 7451 "./marpa.w"

/*713:*/
#line 7799 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_yim_work_stack))
{
MARPA_DSTACK_INIT2(r->t_yim_work_stack,YIM);
}
}
/*:713*//*717:*/
#line 7814 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_completion_stack))
{
MARPA_DSTACK_INIT2(r->t_completion_stack,YIM);
}
}
/*:717*/
#line 7452 "./marpa.w"

set0= earley_set_new(r,0);
Latest_YS_of_R(r)= set0;
First_YS_of_R(r)= set0;

start_irl= g->t_start_irl;
start_ahm= First_AHM_of_IRL(start_irl);



key.t_origin= set0;
key.t_set= set0;

key.t_ahm= start_ahm;
earley_item_create(r,key);

bv_clear(r->t_bv_irl_seen);
bv_bit_set(r->t_bv_irl_seen,ID_of_IRL(start_irl));
MARPA_DSTACK_CLEAR(r->t_irl_cil_stack);
*MARPA_DSTACK_PUSH(r->t_irl_cil_stack,CIL)= LHS_CIL_of_AHM(start_ahm);

while(1)
{
const CIL*const p_cil= MARPA_DSTACK_POP(r->t_irl_cil_stack,CIL);
if(!p_cil)
break;
{
int cil_ix;
const CIL this_cil= *p_cil;
const int prediction_count= Count_of_CIL(this_cil);
for(cil_ix= 0;cil_ix<prediction_count;cil_ix++)
{
const IRLID prediction_irlid= Item_of_CIL(this_cil,cil_ix);
if(!bv_bit_test_then_set(r->t_bv_irl_seen,prediction_irlid))
{
const IRL prediction_irl= IRL_by_ID(prediction_irlid);
const AHM prediction_ahm= First_AHM_of_IRL(prediction_irl);



if(!evaluate_zwas(r,0,prediction_ahm))continue;
key.t_ahm= prediction_ahm;
earley_item_create(r,key);
*MARPA_DSTACK_PUSH(r->t_irl_cil_stack,CIL)
= LHS_CIL_of_AHM(prediction_ahm);
}
}
}
}

postdot_items_create(r,bv_ok_for_chain,set0);
earley_set_update_items(r,set0);
r->t_is_using_leo= r->t_use_leo_flag;
trigger_events(r);
CLEANUP:;
/*699:*/
#line 7558 "./marpa.w"

bv_free(bv_ok_for_chain);

/*:699*/
#line 7507 "./marpa.w"

}
return return_value;
}

/*:696*//*697:*/
#line 7512 "./marpa.w"

PRIVATE
int evaluate_zwas(RECCE r,YSID ysid,AHM ahm)
{
int cil_ix;
const CIL zwa_cil= ZWA_CIL_of_AHM(ahm);
const int cil_count= Count_of_CIL(zwa_cil);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
int value;
const ZWAID zwaid= Item_of_CIL(zwa_cil,cil_ix);
const ZWA zwa= RZWA_by_ID(zwaid);


MARPA_DEBUG3("At %s, evaluating assertion %ld",STRLOC,(long)zwaid);
if(Memo_YSID_of_ZWA(zwa)==ysid){
if(Memo_Value_of_ZWA(zwa))continue;
MARPA_DEBUG3("At %s: returning 0 for assertion %ld",STRLOC,(long)zwaid);
return 0;
}




value= Memo_Value_of_ZWA(zwa)= Default_Value_of_ZWA(zwa);
Memo_YSID_of_ZWA(zwa)= ysid;





if(!value){
MARPA_DEBUG3("At %s: returning 0 for assertion %ld",STRLOC,(long)zwaid);
return 0;
}

MARPA_DEBUG3("At %s: value is 1 for assertion %ld",STRLOC,(long)zwaid);
}
return 1;
}


/*:697*//*705:*/
#line 7636 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID tkn_xsy_id,
int value,
int length)
{
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 7643 "./marpa.w"

YS current_earley_set;
const JEARLEME current_earleme= Current_Earleme_of_R(r);
JEARLEME target_earleme;
NSYID tkn_nsyid;
if(_MARPA_UNLIKELY(!R_is_Consistent(r)))
{
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return MARPA_ERR_RECCE_IS_INCONSISTENT;
}
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
/*706:*/
#line 7670 "./marpa.w"
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

/*:706*/
#line 7663 "./marpa.w"

/*709:*/
#line 7730 "./marpa.w"

{
NSY tkn_nsy= NSY_by_XSYID(tkn_xsy_id);
if(_MARPA_UNLIKELY(!tkn_nsy))
{
MARPA_ERROR(MARPA_ERR_INACCESSIBLE_TOKEN);
return MARPA_ERR_INACCESSIBLE_TOKEN;
}
tkn_nsyid= ID_of_NSY(tkn_nsy);
current_earley_set= YS_at_Current_Earleme_of_R(r);
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

/*:709*/
#line 7664 "./marpa.w"

/*707:*/
#line 7710 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=JEARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return MARPA_ERR_PARSE_TOO_LONG;
}
}

/*:707*/
#line 7665 "./marpa.w"

/*710:*/
#line 7768 "./marpa.w"

{
ALT_Object alternative_object;


const ALT alternative= &alternative_object;
NSYID_of_ALT(alternative)= tkn_nsyid;
Value_of_ALT(alternative)= value;
ALT_is_Valued(alternative)= value?1:0;
if(Furthest_Earleme_of_R(r)<target_earleme)
Furthest_Earleme_of_R(r)= target_earleme;
alternative->t_start_earley_set= current_earley_set;
End_Earleme_of_ALT(alternative)= target_earleme;
if(alternative_insert(r,alternative)<0)
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_TOKEN);
return MARPA_ERR_DUPLICATE_TOKEN;
}
}

/*:710*/
#line 7666 "./marpa.w"

return MARPA_ERR_NONE;
}

/*:705*//*723:*/
#line 7845 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 7849 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 7850 "./marpa.w"

YIM*cause_p;
YS current_earley_set;
JEARLEME current_earleme;





JEARLEME return_value= -2;

/*1207:*/
#line 14239 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

if(_MARPA_UNLIKELY(!R_is_Consistent(r))){
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return failure_indicator;
}

/*:1207*/
#line 7861 "./marpa.w"

if(_MARPA_UNLIKELY(!R_is_Consistent(r))){
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return failure_indicator;
}

{
int count_of_expected_terminals;
/*724:*/
#line 7910 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
struct marpa_obstack*const earleme_complete_obs= marpa_obs_init;
/*:724*/
#line 7869 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_nsyid_is_expected);
bv_clear(r->t_bv_irl_seen);
/*726:*/
#line 7918 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*601:*/
#line 6356 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:601*/
#line 7922 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:726*/
#line 7874 "./marpa.w"

/*728:*/
#line 7940 "./marpa.w"
{
ALT end_of_stack= MARPA_DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!end_of_stack||current_earleme!=End_Earleme_of_ALT(end_of_stack))
{
return_value= 0;
goto CLEANUP;
}
}

/*:728*/
#line 7875 "./marpa.w"

/*727:*/
#line 7930 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_YS_of_YS(Latest_YS_of_R(r))= current_earley_set;
Latest_YS_of_R(r)= current_earley_set;
}

/*:727*/
#line 7876 "./marpa.w"

/*729:*/
#line 7949 "./marpa.w"

{
ALT alternative;


while((alternative= alternative_pop(r,current_earleme)))
/*731:*/
#line 7968 "./marpa.w"

{
YS start_earley_set= Start_YS_of_ALT(alternative);
PIM pim= First_PIM_of_YS_by_NSYID(start_earley_set,
NSYID_of_ALT(alternative));
for(;pim;pim= Next_PIM_of_PIM(pim))
{


const YIM predecessor= YIM_of_PIM(pim);
if(predecessor&&YIM_is_Active(predecessor))
{
const AHM predecessor_ahm= AHM_of_YIM(predecessor);
const AHM scanned_ahm= Next_AHM_of_AHM(predecessor_ahm);
/*732:*/
#line 7987 "./marpa.w"

{
const YIM scanned_earley_item= earley_item_assign(r,
current_earley_set,
Origin_of_YIM
(predecessor),
scanned_ahm);
YIM_was_Scanned(scanned_earley_item)= 1;
tkn_link_add(r,scanned_earley_item,predecessor,alternative);
}

/*:732*/
#line 7982 "./marpa.w"

}
}
}

/*:731*/
#line 7955 "./marpa.w"

}

/*:729*/
#line 7877 "./marpa.w"

/*733:*/
#line 8003 "./marpa.w"
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
if(!YIM_is_Completion(earley_item))
continue;
end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= earley_item;
}
}

/*:733*/
#line 7878 "./marpa.w"

while((cause_p= MARPA_DSTACK_POP(r->t_completion_stack,YIM))){
YIM cause= *cause_p;
/*734:*/
#line 8024 "./marpa.w"

{
if(YIM_is_Active(cause)&&YIM_is_Completion(cause))
{
NSYID complete_nsyid= LHS_NSYID_of_YIM(cause);
const YS middle= Origin_of_YIM(cause);
/*735:*/
#line 8034 "./marpa.w"

{
PIM postdot_item;
for(postdot_item= First_PIM_of_YS_by_NSYID(middle,complete_nsyid);
postdot_item;postdot_item= Next_PIM_of_PIM(postdot_item))
{
const YIM predecessor= YIM_of_PIM(postdot_item);
if(!predecessor){


const LIM leo_item= LIM_of_PIM(postdot_item);








if(!LIM_is_Active(leo_item))goto NEXT_PIM;

/*738:*/
#line 8101 "./marpa.w"
{
const YS origin= Origin_of_LIM(leo_item);
const AHM effect_ahm= Top_AHM_of_LIM(leo_item);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_ahm);
YIM_was_Fusion(effect)= 1;
if(Earley_Item_has_No_Source(effect))
{


/*737:*/
#line 8095 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:737*/
#line 8111 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:738*/
#line 8055 "./marpa.w"





goto LAST_PIM;
}else{


if(!YIM_is_Active(predecessor))continue;



/*736:*/
#line 8075 "./marpa.w"

{
const AHM predecessor_ahm= AHM_of_YIM(predecessor);
const AHM effect_ahm= Next_AHM_of_AHM(predecessor_ahm);
const YS origin= Origin_of_YIM(predecessor);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_ahm);
YIM_was_Fusion(effect)= 1;
if(Earley_Item_has_No_Source(effect)){


if(YIM_is_Completion(effect)){
/*737:*/
#line 8095 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:737*/
#line 8087 "./marpa.w"

}
}
completion_link_add(r,effect,predecessor,cause);
}

/*:736*/
#line 8068 "./marpa.w"

}
NEXT_PIM:;
}
LAST_PIM:;
}

/*:735*/
#line 8030 "./marpa.w"

}
}

/*:734*/
#line 7881 "./marpa.w"

}
/*739:*/
#line 8116 "./marpa.w"

{
int ix;
const int no_of_work_earley_items= 
MARPA_DSTACK_LENGTH(r->t_yim_work_stack);
for(ix= 0;ix<no_of_work_earley_items;ix++)
{
YIM earley_item= WORK_YIM_ITEM(r,ix);

int cil_ix;
const AHM ahm= AHM_of_YIM(earley_item);
const CIL prediction_cil= Predicted_IRL_CIL_of_AHM(ahm);
const int prediction_count= Count_of_CIL(prediction_cil);
for(cil_ix= 0;cil_ix<prediction_count;cil_ix++)
{
const IRLID prediction_irlid= Item_of_CIL(prediction_cil,cil_ix);
const IRL prediction_irl= IRL_by_ID(prediction_irlid);
const AHM prediction_ahm= First_AHM_of_IRL(prediction_irl);
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_ahm);
}

}
}

/*:739*/
#line 7883 "./marpa.w"

postdot_items_create(r,bv_ok_for_chain,current_earley_set);





count_of_expected_terminals= bv_count(r->t_bv_nsyid_is_expected);
if(count_of_expected_terminals<=0
&&MARPA_DSTACK_LENGTH(r->t_alternatives)<=0)
{
/*601:*/
#line 6356 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:601*/
#line 7894 "./marpa.w"

}
earley_set_update_items(r,current_earley_set);
if(r->t_active_event_count> 0){
trigger_events(r);
}
return_value= G_EVENT_COUNT(g);
CLEANUP:;
/*725:*/
#line 7914 "./marpa.w"

bv_free(bv_ok_for_chain);
marpa_obs_free(earleme_complete_obs);

/*:725*/
#line 7902 "./marpa.w"

}
return return_value;
}

/*:723*//*740:*/
#line 8141 "./marpa.w"

PRIVATE void trigger_events(RECCE r)
{
const GRAMMAR g= G_of_R(r);
const YS current_earley_set= Latest_YS_of_R(r);
int min,max,start;
int yim_ix;
struct marpa_obstack*const trigger_events_obs= marpa_obs_init;
const YIM*yims= YIMs_of_YS(current_earley_set);
const XSYID xsy_count= XSY_Count_of_G(g);
const int ahm_count= AHM_Count_of_G(g);
Bit_Vector bv_completion_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_nulled_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_prediction_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_ahm_event_trigger= 
bv_obs_create(trigger_events_obs,ahm_count);
const int working_earley_item_count= YIM_Count_of_YS(current_earley_set);
for(yim_ix= 0;yim_ix<working_earley_item_count;yim_ix++)
{
const YIM yim= yims[yim_ix];
const AHM root_ahm= AHM_of_YIM(yim);
if(AHM_has_Event(root_ahm))
{

bv_bit_set(bv_ahm_event_trigger,ID_of_AHM(root_ahm));
}
{

const SRCL first_leo_source_link= First_Leo_SRCL_of_YIM(yim);
SRCL setup_source_link;
for(setup_source_link= first_leo_source_link;setup_source_link;
setup_source_link= Next_SRCL_of_SRCL(setup_source_link))
{
int cil_ix;
const LIM lim= LIM_of_SRCL(setup_source_link);
const CIL event_ahmids= CIL_of_LIM(lim);
const int event_ahm_count= Count_of_CIL(event_ahmids);
for(cil_ix= 0;cil_ix<event_ahm_count;cil_ix++)
{
const NSYID leo_path_ahmid= 
Item_of_CIL(event_ahmids,cil_ix);
bv_bit_set(bv_ahm_event_trigger,leo_path_ahmid);


}
}
}
}

for(start= 0;bv_scan(bv_ahm_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_ahmid;
for(event_ahmid= (NSYID)min;event_ahmid<=(NSYID)max;
event_ahmid++)
{
int cil_ix;
const AHM event_ahm= AHM_by_ID(event_ahmid);
{
const CIL completion_xsyids= 
Completion_XSYIDs_of_AHM(event_ahm);
const int event_xsy_count= Count_of_CIL(completion_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(completion_xsyids,cil_ix);
bv_bit_set(bv_completion_event_trigger,event_xsyid);
}
}
{
const CIL nulled_xsyids= Nulled_XSYIDs_of_AHM(event_ahm);
const int event_xsy_count= Count_of_CIL(nulled_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(nulled_xsyids,cil_ix);
bv_bit_set(bv_nulled_event_trigger,event_xsyid);
}
}
{
const CIL prediction_xsyids= 
Prediction_XSYIDs_of_AHM(event_ahm);
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

/*:740*//*741:*/
#line 8280 "./marpa.w"

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

/*:741*//*742:*/
#line 8309 "./marpa.w"

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

/*:742*//*758:*/
#line 8413 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,
Bit_Vector bv_ok_for_chain,
const YS current_earley_set)
{
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 8419 "./marpa.w"

/*757:*/
#line 8410 "./marpa.w"

bv_clear(r->t_bv_lim_symbols);
bv_clear(r->t_bv_pim_symbols);
/*:757*/
#line 8420 "./marpa.w"

/*759:*/
#line 8432 "./marpa.w"
{

YIM*work_earley_items= MARPA_DSTACK_BASE(r->t_yim_work_stack,YIM);
int no_of_work_earley_items= MARPA_DSTACK_LENGTH(r->t_yim_work_stack);
int ix;
for(ix= 0;
ix<no_of_work_earley_items;
ix++)
{
YIM earley_item= work_earley_items[ix];
AHM ahm= AHM_of_YIM(earley_item);
const NSYID postdot_nsyid= Postdot_NSYID_of_AHM(ahm);
if(postdot_nsyid<0)continue;
{
PIM old_pim= NULL;
PIM new_pim;


new_pim= marpa__obs_alloc(r->t_obs,
sizeof(YIX_Object),ALIGNOF(PIM_Object));

Postdot_NSYID_of_PIM(new_pim)= postdot_nsyid;
YIM_of_PIM(new_pim)= earley_item;
if(bv_bit_test(r->t_bv_pim_symbols,postdot_nsyid))
old_pim= r->t_pim_workarea[postdot_nsyid];
Next_PIM_of_PIM(new_pim)= old_pim;
if(!old_pim)current_earley_set->t_postdot_sym_count++;
r->t_pim_workarea[postdot_nsyid]= new_pim;
bv_bit_set(r->t_bv_pim_symbols,postdot_nsyid);
}
}
}

/*:759*/
#line 8421 "./marpa.w"

if(r->t_is_using_leo){
/*761:*/
#line 8475 "./marpa.w"

{
int min,max,start;
for(start= 0;bv_scan(r->t_bv_pim_symbols,start,&min,&max);
start= max+2)
{
NSYID nsyid;
for(nsyid= (NSYID)min;nsyid<=(NSYID)max;nsyid++)
{
const PIM this_pim= r->t_pim_workarea[nsyid];
if(Next_PIM_of_PIM(this_pim))
goto NEXT_NSYID;


{
const YIM leo_base= YIM_of_PIM(this_pim);
AHM potential_leo_penult_ahm= NULL;
const AHM leo_base_ahm= AHM_of_YIM(leo_base);
const IRL leo_base_irl= IRL_of_AHM(leo_base_ahm);

if(!IRL_is_Leo(leo_base_irl))
goto NEXT_NSYID;
potential_leo_penult_ahm= leo_base_ahm;
MARPA_ASSERT(potential_leo_penult_ahm);
{
const AHM trailhead_ahm= 
Next_AHM_of_AHM(potential_leo_penult_ahm);
if(AHM_is_Leo_Completion(trailhead_ahm))
{
/*762:*/
#line 8519 "./marpa.w"
{
LIM new_lim;
new_lim= marpa_obs_new(r->t_obs,LIM_Object,1);
LIM_is_Active(new_lim)= 1;
LIM_is_Rejected(new_lim)= 1;
Postdot_NSYID_of_LIM(new_lim)= nsyid;
YIM_of_PIM(new_lim)= NULL;
Predecessor_LIM_of_LIM(new_lim)= NULL;
Origin_of_LIM(new_lim)= NULL;
CIL_of_LIM(new_lim)= NULL;
Top_AHM_of_LIM(new_lim)= trailhead_ahm;
Trailhead_AHM_of_LIM(new_lim)= trailhead_ahm;
Trailhead_YIM_of_LIM(new_lim)= leo_base;
YS_of_LIM(new_lim)= current_earley_set;
Next_PIM_of_LIM(new_lim)= this_pim;
r->t_pim_workarea[nsyid]= new_lim;
bv_bit_set(r->t_bv_lim_symbols,nsyid);
}

/*:762*/
#line 8504 "./marpa.w"

}
}
}
NEXT_NSYID:;
}
}
}

/*:761*/
#line 8423 "./marpa.w"

/*771:*/
#line 8607 "./marpa.w"
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

/*773:*/
#line 8663 "./marpa.w"

{
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
LHSID_of_AHM(trailhead_ahm);
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

/*:773*/
#line 8624 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*781:*/
#line 8782 "./marpa.w"

{
const AHM new_top_ahm= Top_AHM_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);



CIL_of_LIM(lim_to_process)= predecessor_cil;
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHM(new_top_ahm)> Count_of_CIL(predecessor_cil))
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const CIL trailhead_ahm_event_ahmids= 
Event_AHMIDs_of_AHM(trailhead_ahm);
if(Count_of_CIL(trailhead_ahm_event_ahmids))
{
CIL new_cil= cil_merge_one(&g->t_cilar,predecessor_cil,
Item_of_CIL
(trailhead_ahm_event_ahmids,0));
if(new_cil)
{
CIL_of_LIM(lim_to_process)= new_cil;
}
}
}
Top_AHM_of_LIM(lim_to_process)= new_top_ahm;
}

/*:781*/
#line 8626 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*783:*/
#line 8823 "./marpa.w"
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHMIDs_of_AHM(trailhead_ahm);
}

/*:783*/
#line 8632 "./marpa.w"

continue;
}
/*776:*/
#line 8690 "./marpa.w"
{
int lim_chain_ix;
/*779:*/
#line 8710 "./marpa.w"

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

/*773:*/
#line 8663 "./marpa.w"

{
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
LHSID_of_AHM(trailhead_ahm);
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

/*:773*/
#line 8743 "./marpa.w"


r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,
postdot_nsyid_of_lim_to_process);





if(!predecessor_lim)
break;
if(LIM_is_Populated(predecessor_lim))
break;



}
}

/*:779*/
#line 8692 "./marpa.w"

/*780:*/
#line 8765 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= r->t_lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*781:*/
#line 8782 "./marpa.w"

{
const AHM new_top_ahm= Top_AHM_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);



CIL_of_LIM(lim_to_process)= predecessor_cil;
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHM(new_top_ahm)> Count_of_CIL(predecessor_cil))
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const CIL trailhead_ahm_event_ahmids= 
Event_AHMIDs_of_AHM(trailhead_ahm);
if(Count_of_CIL(trailhead_ahm_event_ahmids))
{
CIL new_cil= cil_merge_one(&g->t_cilar,predecessor_cil,
Item_of_CIL
(trailhead_ahm_event_ahmids,0));
if(new_cil)
{
CIL_of_LIM(lim_to_process)= new_cil;
}
}
}
Top_AHM_of_LIM(lim_to_process)= new_top_ahm;
}

/*:781*/
#line 8769 "./marpa.w"

}else{
/*783:*/
#line 8823 "./marpa.w"
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHMIDs_of_AHM(trailhead_ahm);
}

/*:783*/
#line 8771 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:780*/
#line 8693 "./marpa.w"

}

/*:776*/
#line 8635 "./marpa.w"

}
}
}

/*:771*/
#line 8424 "./marpa.w"

}
/*784:*/
#line 8830 "./marpa.w"
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


/*:784*/
#line 8426 "./marpa.w"

bv_and(r->t_bv_nsyid_is_expected,r->t_bv_pim_symbols,g->t_bv_nsyid_is_terminal);
}

/*:758*//*787:*/
#line 8866 "./marpa.w"

Marpa_Earleme
marpa_r_clean(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 8870 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 8871 "./marpa.w"

YSID ysid_to_clean;


const YS current_ys= Latest_YS_of_R(r);
const YSID current_ys_id= Ord_of_YS(current_ys);

int count_of_expected_terminals;
/*788:*/
#line 8927 "./marpa.w"




struct marpa_obstack*const method_obstack= marpa_obs_init;

YIMID*prediction_by_irl= 
marpa_obs_new(method_obstack,YIMID,IRL_Count_of_G(g));

/*:788*/
#line 8879 "./marpa.w"






const JEARLEME return_value= -2;

/*1207:*/
#line 14239 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

if(_MARPA_UNLIKELY(!R_is_Consistent(r))){
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return failure_indicator;
}

/*:1207*/
#line 8887 "./marpa.w"


G_EVENTS_CLEAR(g);



if(R_is_Consistent(r))return 0;





earley_set_update_items(r,current_ys);

for(ysid_to_clean= First_Inconsistent_YS_of_R(r);
ysid_to_clean<=current_ys_id;
ysid_to_clean++){
/*790:*/
#line 8941 "./marpa.w"

{
const YS ys_to_clean= YS_of_R_by_Ord(r,ysid_to_clean);
const YIM*yims_to_clean= YIMs_of_YS(ys_to_clean);
const int yim_to_clean_count= YIM_Count_of_YS(ys_to_clean);
Bit_Matrix acceptance_matrix= matrix_obs_create(method_obstack,
yim_to_clean_count,
yim_to_clean_count);
/*791:*/
#line 8961 "./marpa.w"

{
int yim_ix= yim_to_clean_count-1;
YIM yim= yims_to_clean[yim_ix];






while(YIM_was_Predicted(yim)){
prediction_by_irl[IRLID_of_YIM(yim)]= yim_ix;
yim= yims_to_clean[--yim_ix];
}
}

/*:791*/
#line 8949 "./marpa.w"

/*792:*/
#line 8977 "./marpa.w"
{
int yim_to_clean_ix;
for(yim_to_clean_ix= 0;
yim_to_clean_ix<yim_to_clean_count;
yim_to_clean_ix++)
{
const YIM yim_to_clean= yims_to_clean[yim_to_clean_ix];




MARPA_ASSERT(!YIM_is_Initial(yim_to_clean)||
(YIM_is_Active(yim_to_clean)&&!YIM_is_Rejected(yim_to_clean)));



if(!YIM_is_Initial(yim_to_clean))YIM_is_Active(yim_to_clean)= 0;






if(YIM_is_Rejected(yim_to_clean))continue;



/*793:*/
#line 9014 "./marpa.w"

{
const NSYID postdot_nsyid= Postdot_NSYID_of_YIM(yim_to_clean);
if(postdot_nsyid>=0)
{
int cil_ix;
const CIL lhs_cil= LHS_CIL_of_NSYID(postdot_nsyid);
const int cil_count= Count_of_CIL(lhs_cil);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
const IRLID irlid= Item_of_CIL(lhs_cil,cil_ix);
const int predicted_yim_ix= prediction_by_irl[irlid];
const YIM predicted_yim= yims_to_clean[predicted_yim_ix];
if(YIM_is_Rejected(predicted_yim))continue;
matrix_bit_set(acceptance_matrix,yim_to_clean_ix,
predicted_yim_ix);
}
}
}

/*:793*/
#line 9004 "./marpa.w"







}
}

/*:792*/
#line 8950 "./marpa.w"

transitive_closure(acceptance_matrix);
/*798:*/
#line 9074 "./marpa.w"
{
int cause_yim_ix;
for(cause_yim_ix= 0;cause_yim_ix<yim_to_clean_count;cause_yim_ix++){
const YIM cause_yim= yims_to_clean[cause_yim_ix];





if(!YIM_is_Initial(cause_yim)&&
!YIM_was_Scanned(cause_yim))break;





if(YIM_is_Rejected(cause_yim))continue;

{
const Bit_Vector bv_yims_to_accept
= matrix_row(acceptance_matrix,cause_yim_ix);
int min,max,start;
for(start= 0;bv_scan(bv_yims_to_accept,start,&min,&max);
start= max+2)
{
int yim_to_accept_ix;
for(yim_to_accept_ix= min;
yim_to_accept_ix<=max;yim_to_accept_ix++)
{
const YIM yim_to_accept= yims_to_clean[yim_to_accept_ix];
YIM_is_Active(yim_to_accept)= 1;
}
}
}
}
}

/*:798*/
#line 8952 "./marpa.w"

/*799:*/
#line 9115 "./marpa.w"
{
int yim_ix;
for(yim_ix= 0;yim_ix<yim_to_clean_count;yim_ix++){
const YIM yim= yims_to_clean[yim_ix];
if(!YIM_is_Active(yim))continue;
YIM_is_Rejected(yim)= 1;
}
}

/*:799*/
#line 8953 "./marpa.w"

/*801:*/
#line 9129 "./marpa.w"
{}

/*:801*/
#line 8954 "./marpa.w"

/*802:*/
#line 9133 "./marpa.w"

{
int postdot_sym_ix;
const int postdot_sym_count= Postdot_SYM_Count_of_YS(ys_to_clean);
const PIM*postdot_array= ys_to_clean->t_postdot_ary;



for(postdot_sym_ix= 0;postdot_sym_ix<postdot_sym_count;postdot_sym_ix++){



const PIM first_pim= postdot_array[postdot_sym_ix];
if(PIM_is_LIM(first_pim)){
const LIM lim= LIM_of_PIM(first_pim);



LIM_is_Rejected(lim)= 1;
LIM_is_Active(lim)= 0;



if(!YIM_is_Active(Trailhead_YIM_of_LIM(lim)))continue;
{
const LIM predecessor_lim= Predecessor_LIM_of_LIM(lim);


if(predecessor_lim&&!LIM_is_Active(predecessor_lim))continue;
}



LIM_is_Rejected(lim)= 0;
LIM_is_Active(lim)= 1;
}
}
}

/*:802*/
#line 8955 "./marpa.w"

}

/*:790*/
#line 8904 "./marpa.w"

}




/*803:*/
#line 9178 "./marpa.w"
{
int old_alt_ix;
int no_of_alternatives= MARPA_DSTACK_LENGTH(r->t_alternatives);






for(old_alt_ix= 0;
old_alt_ix<no_of_alternatives;
old_alt_ix++)
{
const ALT alternative= MARPA_DSTACK_INDEX(
r->t_alternatives,ALT_Object,old_alt_ix);
if(!alternative_is_acceptable(alternative))break;
}





if(old_alt_ix<no_of_alternatives){



int empty_alt_ix= old_alt_ix;
for(old_alt_ix++;old_alt_ix<no_of_alternatives;old_alt_ix++)
{
const ALT alternative= MARPA_DSTACK_INDEX(
r->t_alternatives,ALT_Object,old_alt_ix);
if(!alternative_is_acceptable(alternative))continue;
*MARPA_DSTACK_INDEX(r->t_alternatives,ALT_Object,empty_alt_ix)
= *alternative;
empty_alt_ix++;
}




MARPA_DSTACK_COUNT_SET(r->t_alternatives,empty_alt_ix);

if(empty_alt_ix){
Furthest_Earleme_of_R(r)= Earleme_of_YS(current_ys);
}else{
const ALT furthest_alternative
= MARPA_DSTACK_INDEX(r->t_alternatives,ALT_Object,0);
Furthest_Earleme_of_R(r)= End_Earleme_of_ALT(furthest_alternative);
}

}

}

/*:803*/
#line 8910 "./marpa.w"


bv_clear(r->t_bv_nsyid_is_expected);
/*805:*/
#line 9258 "./marpa.w"
{}

/*:805*/
#line 8913 "./marpa.w"

count_of_expected_terminals= bv_count(r->t_bv_nsyid_is_expected);
if(count_of_expected_terminals<=0
&&MARPA_DSTACK_LENGTH(r->t_alternatives)<=0)
{
/*601:*/
#line 6356 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:601*/
#line 8918 "./marpa.w"

}

First_Inconsistent_YS_of_R(r)= -1;

/*789:*/
#line 8936 "./marpa.w"

{
marpa_obs_free(method_obstack);
}

/*:789*/
#line 8923 "./marpa.w"

return return_value;
}

/*:787*//*804:*/
#line 9232 "./marpa.w"

PRIVATE int alternative_is_acceptable(ALT alternative)
{
PIM pim;
const NSYID token_symbol_id= NSYID_of_ALT(alternative);
const YS start_ys= Start_YS_of_ALT(alternative);
for(pim= First_PIM_of_YS_by_NSYID(start_ys,token_symbol_id);
pim;
pim= Next_PIM_of_PIM(pim))
{
YIM predecessor_yim= YIM_of_PIM(pim);






if(!predecessor_yim)continue;



if(YIM_is_Active(predecessor_yim))return 1;
}
return 0;
}

/*:804*//*806:*/
#line 9261 "./marpa.w"

int
marpa_r_zwa_default_set(Marpa_Recognizer r,
Marpa_Assertion_ID zwaid,
int default_value)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 9267 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 9268 "./marpa.w"

ZWA zwa;
int old_default_value;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 9271 "./marpa.w"

/*1203:*/
#line 14209 "./marpa.w"

if(_MARPA_UNLIKELY(ZWAID_is_Malformed(zwaid))){
MARPA_ERROR(MARPA_ERR_INVALID_ASSERTION_ID);
return failure_indicator;
}

/*:1203*/
#line 9272 "./marpa.w"

/*1202:*/
#line 14203 "./marpa.w"

if(_MARPA_UNLIKELY(!ZWAID_of_G_Exists(zwaid))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_ASSERTION_ID);
return failure_indicator;
}
/*:1202*/
#line 9273 "./marpa.w"

if(_MARPA_UNLIKELY(default_value<0||default_value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
zwa= RZWA_by_ID(zwaid);
old_default_value= Default_Value_of_ZWA(zwa);
Default_Value_of_ZWA(zwa)= default_value?1:0;
return old_default_value;
}

/*:806*//*807:*/
#line 9285 "./marpa.w"

int
marpa_r_zwa_default(Marpa_Recognizer r,
Marpa_Assertion_ID zwaid)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 9290 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 9291 "./marpa.w"

ZWA zwa;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 9293 "./marpa.w"

/*1203:*/
#line 14209 "./marpa.w"

if(_MARPA_UNLIKELY(ZWAID_is_Malformed(zwaid))){
MARPA_ERROR(MARPA_ERR_INVALID_ASSERTION_ID);
return failure_indicator;
}

/*:1203*/
#line 9294 "./marpa.w"

/*1202:*/
#line 14203 "./marpa.w"

if(_MARPA_UNLIKELY(!ZWAID_of_G_Exists(zwaid))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_ASSERTION_ID);
return failure_indicator;
}
/*:1202*/
#line 9295 "./marpa.w"

zwa= RZWA_by_ID(zwaid);
return Default_Value_of_ZWA(zwa);
}

/*:807*//*816:*/
#line 9335 "./marpa.w"

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

/*:816*//*817:*/
#line 9352 "./marpa.w"

int marpa_r_progress_report_start(
Marpa_Recognizer r,
Marpa_Earley_Set_ID set_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 9357 "./marpa.w"

YS earley_set;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 9359 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 9360 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 9361 "./marpa.w"

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
/*811:*/
#line 9309 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:811*/
#line 9374 "./marpa.w"

{
const MARPA_AVL_TREE report_tree= 
_marpa_avl_create(report_item_cmp,NULL);
const YIM*const earley_items= YIMs_of_YS(earley_set);
const int earley_item_count= YIM_Count_of_YS(earley_set);
int earley_item_id;
for(earley_item_id= 0;earley_item_id<earley_item_count;
earley_item_id++)
{
const YIM earley_item= earley_items[earley_item_id];
if(!YIM_is_Active(earley_item))continue;
/*819:*/
#line 9407 "./marpa.w"

{
SRCL leo_source_link= NULL;
progress_report_item_insert(report_tree,AHM_of_YIM(earley_item),
Origin_Ord_of_YIM(earley_item));
for(leo_source_link= First_Leo_SRCL_of_YIM(earley_item);
leo_source_link;leo_source_link= Next_SRCL_of_SRCL(leo_source_link))
{
LIM leo_item;
if(!SRCL_is_Active(leo_source_link))continue;




for(leo_item= LIM_of_SRCL(leo_source_link);
leo_item;leo_item= Predecessor_LIM_of_LIM(leo_item))
{
const YSID report_origin= Ord_of_YS(YS_of_LIM(leo_item));
const AHM report_ahm= Trailhead_AHM_of_LIM(leo_item);
progress_report_item_insert(report_tree,report_ahm,
report_origin);
}
}
}

/*:819*/
#line 9386 "./marpa.w"

}
r->t_progress_report_traverser= _marpa_avl_t_init(report_tree);
return(int)marpa_avl_count(report_tree);
}
}
/*:817*//*818:*/
#line 9393 "./marpa.w"

int marpa_r_progress_report_reset(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 9396 "./marpa.w"

MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 9398 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 9399 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 9400 "./marpa.w"

/*823:*/
#line 9499 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:823*/
#line 9401 "./marpa.w"

_marpa_avl_t_reset(traverser);
return 1;
}

/*:818*//*820:*/
#line 9432 "./marpa.w"

PRIVATE void
progress_report_item_insert(MARPA_AVL_TREE report_tree,
AHM report_ahm,
YSID report_origin)
{
PROGRESS new_report_item;
const XRL source_xrl= XRL_of_AHM(report_ahm);
const int xrl_position= XRL_Position_of_AHM(report_ahm);
if(!source_xrl)
return;




if(XRL_is_Sequence(source_xrl)
&&Position_of_AHM(report_ahm)<=0
&&IRL_has_Virtual_LHS(IRL_of_AHM(report_ahm)))
return;

new_report_item= 
marpa_obs_new(MARPA_AVL_OBSTACK(report_tree),
struct marpa_progress_item,1);
Position_of_PROGRESS(new_report_item)= xrl_position;
Origin_of_PROGRESS(new_report_item)= report_origin;
RULEID_of_PROGRESS(new_report_item)= ID_of_XRL(source_xrl);
_marpa_avl_insert(report_tree,new_report_item);
return;
}

/*:820*//*821:*/
#line 9462 "./marpa.w"

int marpa_r_progress_report_finish(Marpa_Recognizer r){
const int success= 1;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 9465 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 9466 "./marpa.w"

const MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*823:*/
#line 9499 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:823*/
#line 9468 "./marpa.w"

/*811:*/
#line 9309 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:811*/
#line 9469 "./marpa.w"

return success;
}

/*:821*//*822:*/
#line 9473 "./marpa.w"

Marpa_Rule_ID marpa_r_progress_item(
Marpa_Recognizer r,int*position,Marpa_Earley_Set_ID*origin
){
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 9477 "./marpa.w"

PROGRESS report_item;
MARPA_AVL_TRAV traverser;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 9480 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 9481 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 9482 "./marpa.w"

traverser= r->t_progress_report_traverser;
if(_MARPA_UNLIKELY(!position||!origin)){
MARPA_ERROR(MARPA_ERR_POINTER_ARG_NULL);
return failure_indicator;
}
/*823:*/
#line 9499 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:823*/
#line 9488 "./marpa.w"

report_item= _marpa_avl_t_next(traverser);
if(!report_item){
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_EXHAUSTED);
return-1;
}
*position= Position_of_PROGRESS(report_item);
*origin= Origin_of_PROGRESS(report_item);
return RULEID_of_PROGRESS(report_item);
}

/*:822*//*846:*/
#line 9684 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
stack->t_obs= marpa_obs_init;
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:846*//*847:*/
#line 9692 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:847*//*848:*/
#line 9698 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)marpa_obs_free(stack->t_obs);
stack->t_base= NULL;
}

/*:848*//*849:*/
#line 9705 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= marpa_obs_new(stack->t_obs,UR_Object,1);
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:849*//*850:*/
#line 9715 "./marpa.w"

PRIVATE void
ur_node_push(URS stack,YIM earley_item)
{
UR old_top= stack->t_top;
UR new_top= Next_UR_of_UR(old_top);
YIM_of_UR(old_top)= earley_item;
if(!new_top)
{
new_top= ur_node_new(stack,old_top);
Next_UR_of_UR(old_top)= new_top;
}
stack->t_top= new_top;
}

/*:850*//*851:*/
#line 9730 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:851*//*853:*/
#line 9767 "./marpa.w"

PRIVATE void push_ur_if_new(
struct s_bocage_setup_per_ys*per_ys_data,
URS ur_node_stack,YIM yim)
{
if(!psi_test_and_set(per_ys_data,yim))
{
ur_node_push(ur_node_stack,yim);
}
}

/*:853*//*854:*/
#line 9783 "./marpa.w"

PRIVATE int psi_test_and_set(
struct s_bocage_setup_per_ys*per_ys_data,
YIM earley_item
)
{
const YSID set_ordinal= YS_Ord_of_YIM(earley_item);
const int item_ordinal= Ord_of_YIM(earley_item);
const OR previous_or_node= 
OR_by_PSI(per_ys_data,set_ordinal,item_ordinal);
if(!previous_or_node)
{
OR_by_PSI(per_ys_data,set_ordinal,item_ordinal)= dummy_or_node;
return 0;
}
return 1;
}

/*:854*//*856:*/
#line 9825 "./marpa.w"

PRIVATE void
Set_boolean_in_PSI_for_initial_nulls(struct s_bocage_setup_per_ys*per_ys_data,
YIM yim)
{
const AHM ahm= AHM_of_YIM(yim);
if(Null_Count_of_AHM(ahm))
psi_test_and_set(per_ys_data,(yim));
}

/*:856*//*881:*/
#line 10128 "./marpa.w"

PRIVATE OR or_node_new(BOCAGE b)
{
const int or_node_id= OR_Count_of_B(b)++;
const OR new_or_node= (OR)marpa_obs_new(OBS_of_B(b),OR_Object,1);
ID_of_OR(new_or_node)= or_node_id;
DANDs_of_OR(new_or_node)= NULL;
if(_MARPA_UNLIKELY(or_node_id>=OR_Capacity_of_B(b)))
{
OR_Capacity_of_B(b)*= 2;
ORs_of_B(b)= 
marpa_renew(OR,ORs_of_B(b),OR_Capacity_of_B(b));
}
OR_of_B_by_ID(b,or_node_id)= new_or_node;
return new_or_node;
}

/*:881*//*891:*/
#line 10328 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct marpa_obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= marpa_obs_new(obs,DAND_Object,1);
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:891*//*892:*/
#line 10339 "./marpa.w"

PRIVATE
void draft_and_node_add(struct marpa_obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:892*//*900:*/
#line 10479 "./marpa.w"

PRIVATE
OR or_by_origin_and_symi(struct s_bocage_setup_per_ys*per_ys_data,
YSID origin,
SYMI symbol_instance)
{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
return PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:900*//*905:*/
#line 10538 "./marpa.w"

PRIVATE
int dands_are_equal(OR predecessor_a,OR cause_a,
OR predecessor_b,OR cause_b)
{
const int a_is_token= OR_is_Token(cause_a);
const int b_is_token= OR_is_Token(cause_b);
if(a_is_token!=b_is_token)return 0;
{


const int middle_of_a= predecessor_a?YS_Ord_of_OR(predecessor_a):-1;
const int middle_of_b= predecessor_b?YS_Ord_of_OR(predecessor_b):-1;
if(middle_of_a!=middle_of_b)
return 0;
}
if(a_is_token)
{
const NSYID nsyid_of_a= NSYID_of_OR(cause_a);
const NSYID nsyid_of_b= NSYID_of_OR(cause_b);
return nsyid_of_a==nsyid_of_b;
}
{

const IRLID irlid_of_a= IRLID_of_OR(cause_a);
const IRLID irlid_of_b= IRLID_of_OR(cause_b);
return irlid_of_a==irlid_of_b;
}

}

/*:905*//*906:*/
#line 10572 "./marpa.w"

PRIVATE
int dand_is_duplicate(OR parent,OR predecessor,OR cause)
{
DAND dand;
for(dand= DANDs_of_OR(parent);dand;dand= Next_DAND_of_DAND(dand)){
if(dands_are_equal(predecessor,cause,
Predecessor_OR_of_DAND(dand),Cause_OR_of_DAND(dand)))
{
return 1;
}
}
return 0;
}

/*:906*//*907:*/
#line 10587 "./marpa.w"

PRIVATE
OR set_or_from_yim(struct s_bocage_setup_per_ys*per_ys_data,
YIM psi_yim)
{
const YIM psi_earley_item= psi_yim;
const int psi_earley_set_ordinal= YS_Ord_of_YIM(psi_earley_item);
const int psi_item_ordinal= Ord_of_YIM(psi_earley_item);
return OR_by_PSI(per_ys_data,psi_earley_set_ordinal,psi_item_ordinal);
}

/*:907*//*910:*/
#line 10645 "./marpa.w"

PRIVATE
OR safe_or_from_yim(
struct s_bocage_setup_per_ys*per_ys_data,
YIM yim)
{
if(Position_of_AHM(AHM_of_YIM(yim))<1)return NULL;
return set_or_from_yim(per_ys_data,yim);
}

/*:910*//*927:*/
#line 10798 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1190:*/
#line 14136 "./marpa.w"
void*const failure_indicator= NULL;
/*:1190*/
#line 10802 "./marpa.w"

/*930:*/
#line 10860 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int xsy_count= XSY_Count_of_G(g);
BOCAGE b= NULL;
YS end_of_parse_earley_set;
JEARLEME end_of_parse_earleme;
YIM start_yim= NULL;
struct marpa_obstack*bocage_setup_obs= NULL;
int count_of_earley_items_in_parse;
const int earley_set_count_of_r= YS_Count_of_R(r);

/*:930*//*933:*/
#line 10883 "./marpa.w"

struct s_bocage_setup_per_ys*per_ys_data= NULL;

/*:933*/
#line 10803 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 10804 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 10805 "./marpa.w"

{
struct marpa_obstack*const obstack= marpa_obs_init;
b= marpa_obs_new(obstack,struct marpa_bocage,1);
OBS_of_B(b)= obstack;
}
/*872:*/
#line 10000 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:872*//*875:*/
#line 10023 "./marpa.w"

{
G_of_B(b)= G_of_R(r);
grammar_ref(g);
}

/*:875*//*929:*/
#line 10855 "./marpa.w"

Valued_BV_of_B(b)= lbv_clone(b->t_obs,r->t_valued,xsy_count);
Valued_Locked_BV_of_B(b)= 
lbv_clone(b->t_obs,r->t_valued_locked,xsy_count);

/*:929*//*943:*/
#line 11000 "./marpa.w"

Ambiguity_Metric_of_B(b)= 1;

/*:943*//*947:*/
#line 11014 "./marpa.w"

b->t_ref_count= 1;
/*:947*//*954:*/
#line 11073 "./marpa.w"

B_is_Nulling(b)= 0;
/*:954*/
#line 10811 "./marpa.w"


if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*934:*/
#line 10886 "./marpa.w"

{
if(ordinal_arg==-1)
{
end_of_parse_earley_set= YS_at_Current_Earleme_of_R(r);
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

/*:934*/
#line 10819 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(XSY_by_ID(g->t_start_xsy_id)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*937:*/
#line 10952 "./marpa.w"

{
int yim_ix;
YIM*const earley_items= YIMs_of_YS(end_of_parse_earley_set);
const IRL start_irl= g->t_start_irl;
const IRLID sought_irl_id= ID_of_IRL(start_irl);
const int earley_item_count= YIM_Count_of_YS(end_of_parse_earley_set);
for(yim_ix= 0;yim_ix<earley_item_count;yim_ix++){
const YIM earley_item= earley_items[yim_ix];
if(Origin_Earleme_of_YIM(earley_item)> 0)continue;
if(YIM_was_Predicted(earley_item))continue;
{
const AHM ahm= AHM_of_YIM(earley_item);
if(IRLID_of_AHM(ahm)==sought_irl_id){
start_yim= earley_item;
break;
}
}
}
}

/*:937*/
#line 10827 "./marpa.w"

if(!start_yim)goto NO_PARSE;
bocage_setup_obs= marpa_obs_init;
/*935:*/
#line 10908 "./marpa.w"

{
int earley_set_ordinal;
int earley_set_count= YS_Count_of_R(r);
count_of_earley_items_in_parse= 0;
per_ys_data= marpa_obs_new(
bocage_setup_obs,struct s_bocage_setup_per_ys,earley_set_count);
for(earley_set_ordinal= 0;earley_set_ordinal<earley_set_count;
earley_set_ordinal++)
{
const YS_Const earley_set= YS_of_R_by_Ord(r,earley_set_ordinal);
const int item_count= YIM_Count_of_YS(earley_set);
count_of_earley_items_in_parse+= item_count;
{
int item_ordinal;
struct s_bocage_setup_per_ys*per_ys= per_ys_data+earley_set_ordinal;
per_ys->t_or_node_by_item= 
marpa_obs_new(bocage_setup_obs,OR,item_count);
per_ys->t_or_psl= NULL;
per_ys->t_and_psl= NULL;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR_by_PSI(per_ys_data,earley_set_ordinal,item_ordinal)= NULL;
}
}
}
}

/*:935*/
#line 10830 "./marpa.w"

/*852:*/
#line 9748 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);


push_ur_if_new(per_ys_data,ur_node_stack,start_yim);
while((ur_node= ur_node_pop(ur_node_stack)))
{

const YIM parent_earley_item= YIM_of_UR(ur_node);
MARPA_ASSERT(!YIM_was_Predicted(parent_earley_item))
/*855:*/
#line 9801 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Token_SRCL_of_YIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM predecessor_earley_item;
if(!SRCL_is_Active(source_link))continue;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
if(!predecessor_earley_item)continue;
if(YIM_was_Predicted(predecessor_earley_item))
{
Set_boolean_in_PSI_for_initial_nulls(per_ys_data,
predecessor_earley_item);
continue;
}
push_ur_if_new(per_ys_data,ur_node_stack,predecessor_earley_item);
}
}

/*:855*/
#line 9761 "./marpa.w"

/*857:*/
#line 9835 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Completion_SRCL_of_YIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM predecessor_earley_item;
YIM cause_earley_item;
if(!SRCL_is_Active(source_link))continue;
cause_earley_item= Cause_of_SRCL(source_link);
push_ur_if_new(per_ys_data,ur_node_stack,cause_earley_item);
predecessor_earley_item= Predecessor_of_SRCL(source_link);
if(!predecessor_earley_item)continue;
if(YIM_was_Predicted(predecessor_earley_item))
{
Set_boolean_in_PSI_for_initial_nulls(per_ys_data,
predecessor_earley_item);
continue;
}
push_ur_if_new(per_ys_data,ur_node_stack,predecessor_earley_item);
}
}

/*:857*/
#line 9762 "./marpa.w"

/*858:*/
#line 9858 "./marpa.w"

{
SRCL source_link;

for(source_link= First_Leo_SRCL_of_YIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor;
YIM cause_earley_item;



if(!SRCL_is_Active(source_link))
continue;
cause_earley_item= Cause_of_SRCL(source_link);
push_ur_if_new(per_ys_data,ur_node_stack,cause_earley_item);
for(leo_predecessor= LIM_of_SRCL(source_link);leo_predecessor;

leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor))
{
const YIM leo_base_yim= Trailhead_YIM_of_LIM(leo_predecessor);
if(YIM_was_Predicted(leo_base_yim))
{
Set_boolean_in_PSI_for_initial_nulls(per_ys_data,
leo_base_yim);
}
else
{
push_ur_if_new(per_ys_data,ur_node_stack,leo_base_yim);
}
}
}
}

/*:858*/
#line 9763 "./marpa.w"

}
}

/*:852*/
#line 10831 "./marpa.w"

/*876:*/
#line 10030 "./marpa.w"

{
PSAR_Object or_per_ys_arena;
const PSAR or_psar= &or_per_ys_arena;
int work_earley_set_ordinal;
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
psar_dealloc(or_psar);
this_earley_set_psl
= psl_claim_by_es(or_psar,per_ys_data,work_earley_set_ordinal);
/*877:*/
#line 10056 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;
item_ordinal++)
{
if(OR_by_PSI(per_ys_data,work_earley_set_ordinal,item_ordinal))
{
const YIM work_earley_item= yims_of_ys[item_ordinal];
{
/*878:*/
#line 10072 "./marpa.w"

{
AHM ahm= AHM_of_YIM(work_earley_item);
const int working_ys_ordinal= YS_Ord_of_YIM(work_earley_item);
const int working_yim_ordinal= Ord_of_YIM(work_earley_item);
const int work_origin_ordinal= 
Ord_of_YS(Origin_of_YIM(work_earley_item));
SYMI ahm_symbol_instance;
OR psi_or_node= NULL;
ahm_symbol_instance= SYMI_of_AHM(ahm);
{
PSL or_psl= psl_claim_by_es(or_psar,per_ys_data,work_origin_ordinal);
OR last_or_node= NULL;
/*880:*/
#line 10106 "./marpa.w"

{
if(ahm_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahm_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahm_symbol_instance);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const IRL irl= IRL_of_AHM(ahm);
or_node= last_or_node= or_node_new(b);
PSL_Datum(or_psl,ahm_symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= Origin_Ord_of_YIM(work_earley_item);
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= irl;
Position_of_OR(or_node)= 
ahm_symbol_instance-SYMI_of_IRL(irl)+1;
}
psi_or_node= or_node;
}
}

/*:880*/
#line 10085 "./marpa.w"

/*883:*/
#line 10154 "./marpa.w"

{
const int null_count= Null_Count_of_AHM(ahm);
if(null_count> 0)
{
const IRL irl= IRL_of_AHM(ahm);
const int symbol_instance_of_rule= SYMI_of_IRL(irl);
const int first_null_symbol_instance= 
ahm_symbol_instance<
0?symbol_instance_of_rule:ahm_symbol_instance+1;
int i;
for(i= 0;i<null_count;i++)
{
const int symbol_instance= first_null_symbol_instance+i;
OR or_node= PSL_Datum(or_psl,symbol_instance);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal){
const int rhs_ix= symbol_instance-symbol_instance_of_rule;
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= Nulling_OR_by_NSYID(RHSID_of_IRL(irl,rhs_ix));
or_node= PSL_Datum(or_psl,symbol_instance)
= last_or_node= or_node_new(b);
Origin_Ord_of_OR(or_node)= work_origin_ordinal;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= irl;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
draft_and_node_add(bocage_setup_obs,or_node,predecessor,
cause);
}
psi_or_node= or_node;
}
}
}

/*:883*/
#line 10086 "./marpa.w"

}



MARPA_OFF_ASSERT(psi_or_node)




OR_by_PSI(per_ys_data,working_ys_ordinal,working_yim_ordinal)
= psi_or_node;
/*884:*/
#line 10189 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*885:*/
#line 10206 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_YS(YS_of_LIM(this_leo_item));
const AHM path_ahm= Trailhead_AHM_of_LIM(previous_leo_item);
const IRL path_irl= IRL_of_AHM(path_ahm);
const int symbol_instance_of_path_ahm= SYMI_of_AHM(path_ahm);
{
OR last_or_node= NULL;
/*886:*/
#line 10228 "./marpa.w"

{
{
OR or_node;
PSL leo_psl
= psl_claim_by_es(or_psar,per_ys_data,ordinal_of_set_of_this_leo_item);
or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahm);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
last_or_node= or_node_new(b);
PSL_Datum(leo_psl,symbol_instance_of_path_ahm)= or_node= 
last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= 
symbol_instance_of_path_ahm-SYMI_of_IRL(path_irl)+1;
}
}
}

/*:886*/
#line 10218 "./marpa.w"

/*887:*/
#line 10253 "./marpa.w"

{
int i;
const int null_count= Null_Count_of_AHM(path_ahm);
for(i= 1;i<=null_count;i++)
{
const int symbol_instance= symbol_instance_of_path_ahm+i;
OR or_node= PSL_Datum(this_earley_set_psl,symbol_instance);
MARPA_ASSERT(symbol_instance<SYMI_Count_of_G(g))
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const int rhs_ix= symbol_instance-SYMI_of_IRL(path_irl);
MARPA_ASSERT(rhs_ix<Length_of_IRL(path_irl))
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= Nulling_OR_by_NSYID(RHSID_of_IRL(path_irl,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_IRL(path_irl))
MARPA_ASSERT(symbol_instance>=0)
or_node= last_or_node= or_node_new(b);
PSL_Datum(this_earley_set_psl,symbol_instance)= or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
draft_and_node_add(bocage_setup_obs,or_node,predecessor,cause);
}
MARPA_ASSERT(Position_of_OR(or_node)<=
SYMI_of_IRL(path_irl)+Length_of_IRL(path_irl))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_IRL(path_irl))
}
}

/*:887*/
#line 10219 "./marpa.w"

}
previous_leo_item= this_leo_item;
}
}

/*:885*/
#line 10197 "./marpa.w"

}
}
}

/*:884*/
#line 10098 "./marpa.w"

}

/*:878*/
#line 10066 "./marpa.w"

}
}
}
}

/*:877*/
#line 10049 "./marpa.w"

/*893:*/
#line 10349 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR or_node= OR_by_PSI(per_ys_data,work_earley_set_ordinal,item_ordinal);
const YIM work_earley_item= yims_of_ys[item_ordinal];
const int work_origin_ordinal= Ord_of_YS(Origin_of_YIM(work_earley_item));
/*894:*/
#line 10366 "./marpa.w"

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

/*:894*/
#line 10357 "./marpa.w"

if(or_node){
/*895:*/
#line 10380 "./marpa.w"

{
const AHM work_ahm= AHM_of_YIM(work_earley_item);
MARPA_ASSERT(work_ahm>=AHM_by_ID(1))
const int work_symbol_instance= SYMI_of_AHM(work_ahm);
const OR work_proper_or_node= or_by_origin_and_symi(per_ys_data,
work_origin_ordinal,work_symbol_instance);
/*897:*/
#line 10422 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM cause_earley_item;
LIM leo_predecessor;



if(!SRCL_is_Active(source_link))continue;
cause_earley_item= Cause_of_SRCL(source_link);
leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*898:*/
#line 10443 "./marpa.w"

{

IRL path_irl= NULL;

IRL previous_path_irl;
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
OR dand_predecessor;
OR path_or_node;
YIM base_earley_item= Trailhead_YIM_of_LIM(path_leo_item);
dand_predecessor= set_or_from_yim(per_ys_data,base_earley_item);
/*899:*/
#line 10470 "./marpa.w"

{
if(higher_path_leo_item){
/*908:*/
#line 10598 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AHM ahm= AHM_of_YIM(base_earley_item);
path_irl= IRL_of_AHM(ahm);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
path_or_node= or_by_origin_and_symi(per_ys_data,origin_ordinal,symbol_instance);
}


/*:908*/
#line 10473 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:899*/
#line 10455 "./marpa.w"

/*901:*/
#line 10489 "./marpa.w"

{
const OR dand_cause
= set_or_from_yim(per_ys_data,cause_earley_item);
if(!dand_is_duplicate(path_or_node,dand_predecessor,dand_cause)){
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:901*/
#line 10456 "./marpa.w"

previous_path_irl= path_irl;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_earley_item= Trailhead_YIM_of_LIM(path_leo_item);
dand_predecessor
= set_or_from_yim(per_ys_data,base_earley_item);
/*899:*/
#line 10470 "./marpa.w"

{
if(higher_path_leo_item){
/*908:*/
#line 10598 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AHM ahm= AHM_of_YIM(base_earley_item);
path_irl= IRL_of_AHM(ahm);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
path_or_node= or_by_origin_and_symi(per_ys_data,origin_ordinal,symbol_instance);
}


/*:908*/
#line 10473 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:899*/
#line 10464 "./marpa.w"

/*904:*/
#line 10515 "./marpa.w"

{
const SYMI symbol_instance= SYMI_of_Completed_IRL(previous_path_irl);
const int origin= Ord_of_YS(YS_of_LIM(path_leo_item));
const OR dand_cause= or_by_origin_and_symi(per_ys_data,origin,symbol_instance);
if(!dand_is_duplicate(path_or_node,dand_predecessor,dand_cause)){
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:904*/
#line 10465 "./marpa.w"

previous_path_irl= path_irl;
}
}

/*:898*/
#line 10437 "./marpa.w"

}
}
}

/*:897*/
#line 10387 "./marpa.w"

/*909:*/
#line 10613 "./marpa.w"

{
SRCL tkn_source_link;
for(tkn_source_link= First_Token_SRCL_of_YIM(work_earley_item);
tkn_source_link;tkn_source_link= Next_SRCL_of_SRCL(tkn_source_link))
{
OR new_token_or_node;
const NSYID token_nsyid= NSYID_of_SRCL(tkn_source_link);
const YIM predecessor_earley_item= Predecessor_of_SRCL(tkn_source_link);
const OR dand_predecessor= safe_or_from_yim(per_ys_data,
predecessor_earley_item);
if(NSYID_is_Valued_in_B(b,token_nsyid))
{



new_token_or_node= (OR)marpa_obs_new(OBS_of_B(b),OR_Object,1);
Type_of_OR(new_token_or_node)= VALUED_TOKEN_OR_NODE;
NSYID_of_OR(new_token_or_node)= token_nsyid;
Value_of_OR(new_token_or_node)= Value_of_SRCL(tkn_source_link);
}
else
{
new_token_or_node= Unvalued_OR_by_NSYID(token_nsyid);
}
draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,new_token_or_node);
}
}

/*:909*/
#line 10388 "./marpa.w"

/*911:*/
#line 10655 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Completion_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM predecessor_earley_item= Predecessor_of_SRCL(source_link);
YIM cause_earley_item= Cause_of_SRCL(source_link);
const int middle_ordinal= Origin_Ord_of_YIM(cause_earley_item);
const AHM cause_ahm= AHM_of_YIM(cause_earley_item);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_IRL(IRL_of_AHM(cause_ahm));
OR dand_predecessor= safe_or_from_yim(per_ys_data,
predecessor_earley_item);
const OR dand_cause= 
or_by_origin_and_symi(per_ys_data,middle_ordinal,
cause_symbol_instance);
draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}
}

/*:911*/
#line 10389 "./marpa.w"

}

/*:895*/
#line 10359 "./marpa.w"

}
}
}

/*:893*/
#line 10050 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= marpa_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:876*/
#line 10832 "./marpa.w"

/*917:*/
#line 10727 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*912:*/
#line 10680 "./marpa.w"

{
const int or_node_count_of_b= OR_Count_of_B(b);
int or_node_id= 0;
while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
DAND dand= DANDs_of_OR(work_or_node);
while(dand)
{
unique_draft_and_node_count++;
dand= Next_DAND_of_DAND(dand);
}
or_node_id++;
}
}

/*:912*/
#line 10730 "./marpa.w"

/*918:*/
#line 10734 "./marpa.w"

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
const AND and_node= ands_of_b+and_node_id;
OR_of_AND(and_node)= or_node;
Predecessor_OR_of_AND(and_node)= Predecessor_OR_of_DAND(dand);
Cause_OR_of_AND(and_node)= cause_or_node;
and_node_id++;
and_count_of_parent_or++;
dand= Next_DAND_of_DAND(dand);
}
AND_Count_of_OR(or_node)= and_count_of_parent_or;
Ambiguity_Metric_of_B(b)= 
MAX(Ambiguity_Metric_of_B(b),and_count_of_parent_or);
}
AND_Count_of_B(b)= and_node_id;
MARPA_ASSERT(and_node_id==unique_draft_and_node_count);
}


/*:918*/
#line 10731 "./marpa.w"

}

/*:917*/
#line 10833 "./marpa.w"

/*938:*/
#line 10973 "./marpa.w"

{
const YSID end_of_parse_ordinal= Ord_of_YS(end_of_parse_earley_set);
const int start_earley_item_ordinal= Ord_of_YIM(start_yim);
const OR root_or_node= 
OR_by_PSI(per_ys_data,end_of_parse_ordinal,start_earley_item_ordinal);
Top_ORID_of_B(b)= ID_of_OR(root_or_node);
}

/*:938*/
#line 10834 "./marpa.w"
;
marpa_obs_free(bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
if(b){
/*950:*/
#line 11050 "./marpa.w"

/*873:*/
#line 10007 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);

grammar_unref(G_of_B(b));
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:873*/
#line 11051 "./marpa.w"
;
/*926:*/
#line 10794 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:926*/
#line 11052 "./marpa.w"
;

/*:950*/
#line 10840 "./marpa.w"
;
}
return NULL;
}

/*:927*//*940:*/
#line 10984 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 10987 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 10988 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 10989 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:940*//*944:*/
#line 11003 "./marpa.w"

int marpa_b_ambiguity_metric(Marpa_Bocage b)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11006 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11007 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11008 "./marpa.w"

return Ambiguity_Metric_of_B(b);
}

/*:944*//*948:*/
#line 11017 "./marpa.w"

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

/*:948*//*949:*/
#line 11035 "./marpa.w"

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

/*:949*//*951:*/
#line 11057 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11061 "./marpa.w"

if(b)
{
/*950:*/
#line 11050 "./marpa.w"

/*873:*/
#line 10007 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);

grammar_unref(G_of_B(b));
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:873*/
#line 11051 "./marpa.w"
;
/*926:*/
#line 10794 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:926*/
#line 11052 "./marpa.w"
;

/*:950*/
#line 11064 "./marpa.w"
;
}
}

/*:951*//*955:*/
#line 11075 "./marpa.w"

int marpa_b_is_null(Marpa_Bocage b)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11078 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11079 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11080 "./marpa.w"

return B_is_Nulling(b);
}

/*:955*//*962:*/
#line 11120 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1190:*/
#line 14136 "./marpa.w"
void*const failure_indicator= NULL;
/*:1190*/
#line 11123 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11124 "./marpa.w"

ORDER o;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11126 "./marpa.w"

o= my_malloc(sizeof(*o));
B_of_O(o)= b;
bocage_ref(b);
/*959:*/
#line 11108 "./marpa.w"

{
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
OBS_of_O(o)= NULL;
}

/*:959*//*965:*/
#line 11138 "./marpa.w"

o->t_ref_count= 1;

/*:965*//*977:*/
#line 11226 "./marpa.w"

High_Rank_Count_of_O(o)= 1;
/*:977*/
#line 11130 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
Ambiguity_Metric_of_O(o)= Ambiguity_Metric_of_B(b);
return o;
}

/*:962*//*966:*/
#line 11142 "./marpa.w"

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

/*:966*//*967:*/
#line 11160 "./marpa.w"

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

/*:967*//*968:*/
#line 11174 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11177 "./marpa.w"

bocage_unref(b);
marpa_obs_free(OBS_of_O(o));
my_free(o);
}

/*:968*//*972:*/
#line 11195 "./marpa.w"

int marpa_o_ambiguity_metric(Marpa_Order o)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11198 "./marpa.w"

/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11199 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11200 "./marpa.w"

return Ambiguity_Metric_of_O(o);
}

/*:972*//*975:*/
#line 11209 "./marpa.w"

int marpa_o_is_null(Marpa_Order o)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11212 "./marpa.w"

/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11213 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11214 "./marpa.w"

return O_is_Nulling(o);
}

/*:975*//*978:*/
#line 11228 "./marpa.w"

int marpa_o_high_rank_only_set(
Marpa_Order o,
int count)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11233 "./marpa.w"

/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11234 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11235 "./marpa.w"

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

/*:978*//*979:*/
#line 11250 "./marpa.w"

int marpa_o_high_rank_only(Marpa_Order o)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11253 "./marpa.w"

/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11254 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11255 "./marpa.w"

return High_Rank_Count_of_O(o);
}

/*:979*//*983:*/
#line 11292 "./marpa.w"

int marpa_o_rank(Marpa_Order o)
{
ANDID**and_node_orderings;
struct marpa_obstack*obs;
int bocage_was_reordered= 0;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11298 "./marpa.w"

/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11299 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11300 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*989:*/
#line 11464 "./marpa.w"

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

/*:989*/
#line 11306 "./marpa.w"

if(High_Rank_Count_of_O(o)){
/*984:*/
#line 11321 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
int or_node_id= 0;
int ambiguity_metric= 1;

while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*985:*/
#line 11338 "./marpa.w"

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
/*986:*/
#line 11377 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:986*/
#line 11358 "./marpa.w"

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

/*:985*/
#line 11332 "./marpa.w"

or_node_id++;
}
Ambiguity_Metric_of_O(o)= ambiguity_metric;
}

/*:984*/
#line 11308 "./marpa.w"

}else{
/*987:*/
#line 11388 "./marpa.w"

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
/*986:*/
#line 11377 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:986*/
#line 11400 "./marpa.w"

rank_by_and_id[and_node_id]= and_node_rank;
}
while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*988:*/
#line 11433 "./marpa.w"

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

/*:988*/
#line 11407 "./marpa.w"

or_node_id++;
}
my_free(rank_by_and_id);
}

/*:987*/
#line 11310 "./marpa.w"

}
if(!bocage_was_reordered){
marpa_obs_free(obs);
OBS_of_O(o)= NULL;
o->t_and_node_orderings= NULL;
}
O_is_Frozen(o)= 1;
return 1;
}

/*:983*//*990:*/
#line 11481 "./marpa.w"

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

/*:990*//*991:*/
#line 11502 "./marpa.w"

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

/*:991*//*992:*/
#line 11516 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11521 "./marpa.w"

/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11522 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11523 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 11524 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 11525 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
if(!and_order_ix_is_valid(o,or_node,ix))return-1;
return and_order_get(o,or_node,ix);
}

/*:992*//*997:*/
#line 11578 "./marpa.w"

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

/*:997*//*998:*/
#line 11596 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1190:*/
#line 14136 "./marpa.w"
void*const failure_indicator= NULL;
/*:1190*/
#line 11599 "./marpa.w"

TREE t;
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11601 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11602 "./marpa.w"

t= my_malloc(sizeof(*t));
O_of_T(t)= o;
order_ref(o);
O_is_Frozen(o)= 1;
/*1015:*/
#line 11787 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1015*/
#line 11607 "./marpa.w"

/*999:*/
#line 11612 "./marpa.w"

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

/*:999*//*1002:*/
#line 11636 "./marpa.w"

t->t_ref_count= 1;

/*:1002*//*1009:*/
#line 11715 "./marpa.w"
t->t_pause_counter= 0;
/*:1009*/
#line 11608 "./marpa.w"

return t;
}

/*:998*//*1003:*/
#line 11640 "./marpa.w"

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

/*:1003*//*1004:*/
#line 11658 "./marpa.w"

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

/*:1004*//*1005:*/
#line 11672 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_free(t);
}

/*:1005*//*1010:*/
#line 11716 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1010*//*1011:*/
#line 11725 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1011*//*1012:*/
#line 11735 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11738 "./marpa.w"

const int termination_indicator= -1;
int is_first_tree_attempt= (t->t_parse_count<1);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 11741 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11742 "./marpa.w"

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
/*1021:*/
#line 11816 "./marpa.w"

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

/*:1021*/
#line 11767 "./marpa.w"

}else{
/*1022:*/
#line 11841 "./marpa.w"
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

/*:1022*/
#line 11769 "./marpa.w"

}
/*1023:*/
#line 11883 "./marpa.w"
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
/*1024:*/
#line 11946 "./marpa.w"

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

/*:1024*/
#line 11940 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1023*/
#line 11771 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return termination_indicator;

}

/*:1012*//*1019:*/
#line 11803 "./marpa.w"

PRIVATE int tree_or_node_try(TREE tree,ORID or_node_id)
{
return!bv_bit_test_then_set(tree->t_or_node_in_use,or_node_id);
}
/*:1019*//*1020:*/
#line 11809 "./marpa.w"

PRIVATE void tree_or_node_release(TREE tree,ORID or_node_id)
{
bv_bit_clear(tree->t_or_node_in_use,or_node_id);
}

/*:1020*//*1025:*/
#line 11967 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1025*//*1026:*/
#line 11975 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 11978 "./marpa.w"

/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 11979 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 11980 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return failure_indicator;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1026*//*1047:*/
#line 12193 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1190:*/
#line 14136 "./marpa.w"
void*const failure_indicator= NULL;
/*:1190*/
#line 12196 "./marpa.w"

/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12197 "./marpa.w"
;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 12198 "./marpa.w"

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
/*1038:*/
#line 12119 "./marpa.w"

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

/*:1038*//*1045:*/
#line 12182 "./marpa.w"

MARPA_DSTACK_SAFE(VStack_of_V(v));
/*:1045*//*1050:*/
#line 12230 "./marpa.w"

v->t_ref_count= 1;

/*:1050*//*1057:*/
#line 12283 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1057*//*1059:*/
#line 12290 "./marpa.w"

V_is_Trace(v)= 0;
/*:1059*//*1062:*/
#line 12311 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1062*//*1067:*/
#line 12338 "./marpa.w"

{
XSY_is_Valued_BV_of_V(v)= lbv_clone(v->t_obs,Valued_BV_of_B(b),xsy_count);
Valued_Locked_BV_of_V(v)= 
lbv_clone(v->t_obs,Valued_Locked_BV_of_B(b),xsy_count);
}

/*:1067*/
#line 12210 "./marpa.w"

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

/*:1047*//*1051:*/
#line 12234 "./marpa.w"

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

/*:1051*//*1052:*/
#line 12252 "./marpa.w"

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

/*:1052*//*1053:*/
#line 12266 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
/*1046:*/
#line 12184 "./marpa.w"

{
if(_MARPA_LIKELY(MARPA_DSTACK_IS_INITIALIZED(VStack_of_V(v))!=NULL))
{
MARPA_DSTACK_DESTROY(VStack_of_V(v));
}
}

/*:1046*/
#line 12270 "./marpa.w"

/*1040:*/
#line 12135 "./marpa.w"

marpa_obs_free(v->t_obs);

/*:1040*/
#line 12271 "./marpa.w"

}

/*:1053*//*1060:*/
#line 12292 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 12295 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1054:*/
#line 12274 "./marpa.w"

TREE t= T_of_V(v);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12276 "./marpa.w"


/*:1054*/
#line 12297 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 12298 "./marpa.w"

if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= Boolean(flag);
return 1;
}

/*:1060*//*1063:*/
#line 12314 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 12317 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1054:*/
#line 12274 "./marpa.w"

TREE t= T_of_V(v);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12276 "./marpa.w"


/*:1054*/
#line 12319 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 12320 "./marpa.w"

if(_MARPA_UNLIKELY(V_is_Nulling(v)))return-1;
if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1063*//*1068:*/
#line 12346 "./marpa.w"

int marpa_v_symbol_is_valued(
Marpa_Value public_v,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 12351 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1054:*/
#line 12274 "./marpa.w"

TREE t= T_of_V(v);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12276 "./marpa.w"


/*:1054*/
#line 12353 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 12354 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 12355 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 12356 "./marpa.w"

return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
}

/*:1068*//*1069:*/
#line 12362 "./marpa.w"

PRIVATE int symbol_is_valued_set(
VALUE v,XSYID xsy_id,int value)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 12366 "./marpa.w"

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

/*:1069*//*1070:*/
#line 12385 "./marpa.w"

int marpa_v_symbol_is_valued_set(
Marpa_Value public_v,Marpa_Symbol_ID xsy_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 12390 "./marpa.w"

/*1054:*/
#line 12274 "./marpa.w"

TREE t= T_of_V(v);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12276 "./marpa.w"


/*:1054*/
#line 12391 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 12392 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 12398 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 12399 "./marpa.w"

return symbol_is_valued_set(v,xsy_id,value);
}

/*:1070*//*1071:*/
#line 12405 "./marpa.w"

int
marpa_v_valued_force(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 12410 "./marpa.w"

XSYID xsy_count;
XSYID xsy_id;
/*1054:*/
#line 12274 "./marpa.w"

TREE t= T_of_V(v);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12276 "./marpa.w"


/*:1054*/
#line 12413 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 12414 "./marpa.w"

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

/*:1071*//*1072:*/
#line 12429 "./marpa.w"

int marpa_v_rule_is_valued_set(
Marpa_Value public_v,Marpa_Rule_ID xrl_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 12434 "./marpa.w"

/*1054:*/
#line 12274 "./marpa.w"

TREE t= T_of_V(v);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12276 "./marpa.w"


/*:1054*/
#line 12435 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 12436 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1201:*/
#line 14197 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1201*/
#line 12442 "./marpa.w"

/*1199:*/
#line 14185 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1199*/
#line 12443 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsy_id= LHS_ID_of_XRL(xrl);
return symbol_is_valued_set(v,xsy_id,value);
}
}

/*:1072*//*1074:*/
#line 12458 "./marpa.w"

Marpa_Step_Type marpa_v_step(Marpa_Value public_v)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 12461 "./marpa.w"

const VALUE v= (VALUE)public_v;

if(V_is_Nulling(v)){
/*1054:*/
#line 12274 "./marpa.w"

TREE t= T_of_V(v);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12276 "./marpa.w"


/*:1054*/
#line 12465 "./marpa.w"

/*1076:*/
#line 12546 "./marpa.w"

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

/*:1076*/
#line 12466 "./marpa.w"

return Step_Type_of_V(v)= MARPA_STEP_INACTIVE;
}

while(V_is_Active(v)){
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case MARPA_STEP_INITIAL:
{
XSYID xsy_count;
/*1054:*/
#line 12274 "./marpa.w"

TREE t= T_of_V(v);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12276 "./marpa.w"


/*:1054*/
#line 12477 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
lbv_fill(Valued_Locked_BV_of_V(v),xsy_count);
/*1075:*/
#line 12530 "./marpa.w"

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

/*:1075*/
#line 12480 "./marpa.w"

}

case STEP_GET_DATA:
/*1077:*/
#line 12571 "./marpa.w"

{
AND and_nodes;






int pop_arguments= 1;
/*1054:*/
#line 12274 "./marpa.w"

TREE t= T_of_V(v);
/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 12276 "./marpa.w"


/*:1054*/
#line 12581 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 12582 "./marpa.w"

and_nodes= ANDs_of_B(B_of_O(o));

if(NOOK_of_V(v)<0){
NOOK_of_V(v)= Size_of_TREE(t);
}

while(1)
{
OR or;
IRL nook_irl;
Token_Value_of_V(v)= -1;
RULEID_of_V(v)= -1;
NOOK_of_V(v)--;
if(NOOK_of_V(v)<0)
{
Next_Value_Type_of_V(v)= MARPA_STEP_INACTIVE;
break;
}
if(pop_arguments)
{


Arg_N_of_V(v)= Arg_0_of_V(v);
pop_arguments= 0;
}
{
ANDID and_node_id;
AND and_node;
int cause_or_node_type;
OR cause_or_node;
const NOOK nook= NOOK_of_TREE_by_IX(t,NOOK_of_V(v));
const int choice= Choice_of_NOOK(nook);
or= OR_of_NOOK(nook);
YS_ID_of_V(v)= YS_Ord_of_OR(or);
and_node_id= and_order_get(o,or,choice);
and_node= and_nodes+and_node_id;
cause_or_node= Cause_OR_of_AND(and_node);
cause_or_node_type= Type_of_OR(cause_or_node);
switch(cause_or_node_type)
{
case VALUED_TOKEN_OR_NODE:
Token_Type_of_V(v)= cause_or_node_type;
Arg_0_of_V(v)= ++Arg_N_of_V(v);
{
const OR predecessor= Predecessor_OR_of_AND(and_node);
XSYID_of_V(v)= 
ID_of_XSY(Source_XSY_of_NSYID(NSYID_of_OR(cause_or_node)));
Token_Start_of_V(v)= 
predecessor?YS_Ord_of_OR(predecessor):Origin_Ord_of_OR(or);
Token_Value_of_V(v)= Value_of_OR(cause_or_node);
}

break;
case NULLING_TOKEN_OR_NODE:
Token_Type_of_V(v)= cause_or_node_type;
Arg_0_of_V(v)= ++Arg_N_of_V(v);
{
const XSY source_xsy= 
Source_XSY_of_NSYID(NSYID_of_OR(cause_or_node));
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

break;
default:
Token_Type_of_V(v)= DUMMY_OR_NODE;
}
}
nook_irl= IRL_of_OR(or);
if(Position_of_OR(or)==Length_of_IRL(nook_irl))
{
int virtual_rhs= IRL_has_Virtual_RHS(nook_irl);
int virtual_lhs= IRL_has_Virtual_LHS(nook_irl);
int real_symbol_count;
const MARPA_DSTACK virtual_stack= &VStack_of_V(v);
if(virtual_lhs)
{
real_symbol_count= Real_SYM_Count_of_IRL(nook_irl);
if(virtual_rhs)
{
*(MARPA_DSTACK_TOP(*virtual_stack,int))+= real_symbol_count;
}
else
{
*MARPA_DSTACK_PUSH(*virtual_stack,int)= real_symbol_count;
}
}
else
{

if(virtual_rhs)
{
real_symbol_count= Real_SYM_Count_of_IRL(nook_irl);
real_symbol_count+= *MARPA_DSTACK_POP(*virtual_stack,int);
}
else
{
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
if(RULEID_of_V(v)>=0)
break;
if(Token_Type_of_V(v)!=DUMMY_OR_NODE)
break;
if(V_is_Trace(v))
break;
}
}

/*:1077*/
#line 12484 "./marpa.w"

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

/*:1074*//*1079:*/
#line 12734 "./marpa.w"

PRIVATE int lbv_bits_to_size(int bits)
{
const LBW result= ((LBW)bits+(lbv_wordbits-1))/lbv_wordbits;
return(int)result;
}

/*:1079*//*1080:*/
#line 12742 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new(struct marpa_obstack*obs,int bits)
{
int size= lbv_bits_to_size(bits);
LBV lbv= marpa_obs_new(obs,LBW,size);
return lbv;
}

/*:1080*//*1081:*/
#line 12752 "./marpa.w"

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

/*:1081*//*1082:*/
#line 12765 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new0(struct marpa_obstack*obs,int bits)
{
LBV lbv= lbv_obs_new(obs,bits);
return lbv_zero(lbv,bits);
}

/*:1082*//*1084:*/
#line 12784 "./marpa.w"

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

/*:1084*//*1085:*/
#line 12800 "./marpa.w"

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

/*:1085*//*1088:*/
#line 12836 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(int bits)
{
return((LBW)bits+bv_modmask)/bv_wordbits;
}
/*:1088*//*1089:*/
#line 12842 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(int bits)
{
LBW mask= (LBW)bits&bv_modmask;
if(mask)mask= (LBW)~(~0uL<<mask);else mask= (LBW)~0uL;
return(mask);
}

/*:1089*//*1091:*/
#line 12856 "./marpa.w"

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

/*:1091*//*1093:*/
#line 12874 "./marpa.w"

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


/*:1093*//*1094:*/
#line 12895 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create((int)BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct marpa_obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,(int)BV_BITS(bv));
}

/*:1094*//*1095:*/
#line 12909 "./marpa.w"

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

/*:1095*//*1096:*/
#line 12927 "./marpa.w"

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

/*:1096*//*1097:*/
#line 12941 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(_MARPA_LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1097*//*1098:*/
#line 12952 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1098*//*1099:*/
#line 12963 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1099*//*1101:*/
#line 12977 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
LBW length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1101*//*1103:*/
#line 12986 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1103*//*1104:*/
#line 12994 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1104*//*1105:*/
#line 13002 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1105*//*1106:*/
#line 13014 "./marpa.w"

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

/*:1106*//*1107:*/
#line 13028 "./marpa.w"

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

/*:1107*//*1108:*/
#line 13042 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1108*//*1109:*/
#line 13052 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1109*//*1110:*/
#line 13062 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1110*//*1111:*/
#line 13072 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1111*//*1112:*/
#line 13082 "./marpa.w"

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

/*:1112*//*1113:*/
#line 13162 "./marpa.w"

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

/*:1113*//*1118:*/
#line 13210 "./marpa.w"

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

/*:1118*//*1123:*/
#line 13317 "./marpa.w"

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

/*:1123*//*1125:*/
#line 13340 "./marpa.w"

PRIVATE size_t matrix_sizeof(int rows,int columns)
{
const LBW bv_data_words= bv_bits_to_size(columns);
const LBW row_bytes= 
(bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
return offsetof(struct s_bit_matrix,t_row_data)+((size_t)rows)*row_bytes;
}

/*:1125*//*1127:*/
#line 13350 "./marpa.w"

PRIVATE Bit_Matrix matrix_obs_create(
struct marpa_obstack*obs,
int rows,
int columns)
{

Bit_Matrix matrix_addr= 
marpa__obs_alloc(obs,matrix_sizeof(rows,columns),ALIGNOF(Bit_Matrix_Object));
return matrix_buffer_create(matrix_addr,rows,columns);
}

/*:1127*//*1128:*/
#line 13363 "./marpa.w"

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

/*:1128*//*1129:*/
#line 13385 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
return(int)BV_BITS(row0);
}

/*:1129*//*1130:*/
#line 13401 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,int row)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
LBW words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+(LBW)row*words_per_row;
}

/*:1130*//*1132:*/
#line 13410 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1132*//*1134:*/
#line 13418 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1134*//*1136:*/
#line 13426 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1136*//*1137:*/
#line 13443 "./marpa.w"

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

/*:1137*//*1149:*/
#line 13584 "./marpa.w"

PRIVATE void
cilar_init(const CILAR cilar)
{
cilar->t_obs= marpa_obs_init;
cilar->t_avl= _marpa_avl_create(cil_cmp,NULL);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}
/*:1149*//*1150:*/
#line 13598 "./marpa.w"

PRIVATE void
cilar_buffer_reinit(const CILAR cilar)
{
MARPA_DSTACK_DESTROY(cilar->t_buffer);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}

/*:1150*//*1151:*/
#line 13607 "./marpa.w"

PRIVATE void cilar_destroy(const CILAR cilar)
{
_marpa_avl_destroy(cilar->t_avl);
marpa_obs_free(cilar->t_obs);
MARPA_DSTACK_DESTROY((cilar->t_buffer));
}

/*:1151*//*1152:*/
#line 13616 "./marpa.w"

PRIVATE CIL cil_empty(CILAR cilar)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);

Count_of_CIL(cil)= 0;
return cil_buffer_add(cilar);
}

/*:1152*//*1153:*/
#line 13626 "./marpa.w"

PRIVATE CIL cil_singleton(CILAR cilar,int element)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);
Count_of_CIL(cil)= 1;
Item_of_CIL(cil,0)= element;

return cil_buffer_add(cilar);
}

/*:1153*//*1154:*/
#line 13642 "./marpa.w"

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

/*:1154*//*1155:*/
#line 13670 "./marpa.w"

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

/*:1155*//*1156:*/
#line 13687 "./marpa.w"

PRIVATE void cil_buffer_clear(CILAR cilar)
{
const MARPA_DSTACK dstack= &cilar->t_buffer;
MARPA_DSTACK_CLEAR(*dstack);




*MARPA_DSTACK_PUSH(*dstack,int)= 0;
}

/*:1156*//*1157:*/
#line 13702 "./marpa.w"

PRIVATE CIL cil_buffer_push(CILAR cilar,int new_item)
{
CIL cil_in_buffer;
MARPA_DSTACK dstack= &cilar->t_buffer;
*MARPA_DSTACK_PUSH(*dstack,int)= new_item;



cil_in_buffer= MARPA_DSTACK_BASE(*dstack,int);
Count_of_CIL(cil_in_buffer)++;
return cil_in_buffer;
}

/*:1157*//*1158:*/
#line 13718 "./marpa.w"

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

/*:1158*//*1159:*/
#line 13737 "./marpa.w"

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

/*:1159*//*1160:*/
#line 13790 "./marpa.w"

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

/*:1160*//*1161:*/
#line 13825 "./marpa.w"

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

/*:1161*//*1174:*/
#line 13964 "./marpa.w"

PRIVATE void
psar_safe(const PSAR psar)
{
psar->t_psl_length= 0;
psar->t_first_psl= psar->t_first_free_psl= NULL;
}
/*:1174*//*1175:*/
#line 13971 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1175*//*1176:*/
#line 13978 "./marpa.w"

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
/*:1176*//*1177:*/
#line 13992 "./marpa.w"

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
/*:1177*//*1180:*/
#line 14023 "./marpa.w"

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

/*:1180*//*1182:*/
#line 14041 "./marpa.w"

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

/*:1182*//*1184:*/
#line 14061 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}


/*:1184*//*1185:*/
#line 14071 "./marpa.w"

PRIVATE PSL psl_claim_by_es(
PSAR or_psar,
struct s_bocage_setup_per_ys*per_ys_data,
YSID ysid)
{
PSL*psl_owner= &(per_ys_data[ysid].t_or_psl);
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
return*psl_owner;
}

/*:1185*//*1186:*/
#line 14088 "./marpa.w"

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

/*:1186*//*1212:*/
#line 14298 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}
/*:1212*//*1213:*/
#line 14317 "./marpa.w"

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

/*:1213*//*1217:*/
#line 14360 "./marpa.w"

PRIVATE_NOT_INLINE void*
marpa__default_out_of_memory(void)
{
abort();
return NULL;
}
void*(*const marpa__out_of_memory)(void)= marpa__default_out_of_memory;

/*:1217*//*1223:*/
#line 14390 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_trace_earley_set(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14393 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14394 "./marpa.w"

YS trace_earley_set= r->t_trace_earley_set;
/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14396 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
return Ord_of_YS(trace_earley_set);
}

/*:1223*//*1224:*/
#line 14404 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14407 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14408 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14409 "./marpa.w"

return Ord_of_YS(Latest_YS_of_R(r));
}

/*:1224*//*1225:*/
#line 14413 "./marpa.w"

Marpa_Earleme marpa_r_earleme(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14416 "./marpa.w"

/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14417 "./marpa.w"

YS earley_set;
/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14419 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14420 "./marpa.w"

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

/*:1225*//*1227:*/
#line 14438 "./marpa.w"

int _marpa_r_earley_set_size(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14441 "./marpa.w"

YS earley_set;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14443 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14444 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14445 "./marpa.w"

r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return YIM_Count_of_YS(earley_set);
}

/*:1227*//*1232:*/
#line 14487 "./marpa.w"

Marpa_Earleme
_marpa_r_earley_set_trace(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
YS earley_set;
const int es_does_not_exist= -1;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14493 "./marpa.w"

/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14494 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14495 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_YS(r->t_trace_earley_set)==set_id)
{


return Earleme_of_YS(r->t_trace_earley_set);
}
/*1233:*/
#line 14518 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*1245:*/
#line 14702 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1245*/
#line 14521 "./marpa.w"

}

/*:1233*/
#line 14502 "./marpa.w"

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

/*:1232*//*1234:*/
#line 14524 "./marpa.w"

Marpa_AHM_ID
_marpa_r_earley_item_trace(Marpa_Recognizer r,Marpa_Earley_Item_ID item_id)
{
const int yim_does_not_exist= -1;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14529 "./marpa.w"

YS trace_earley_set;
YIM earley_item;
YIM*earley_items;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14533 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14534 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*1233:*/
#line 14518 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*1245:*/
#line 14702 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1245*/
#line 14521 "./marpa.w"

}

/*:1233*/
#line 14538 "./marpa.w"

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
return AHMID_of_YIM(earley_item);
}

/*:1234*//*1236:*/
#line 14567 "./marpa.w"

PRIVATE void trace_earley_item_clear(RECCE r)
{
/*1235:*/
#line 14564 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1235*/
#line 14570 "./marpa.w"

trace_source_link_clear(r);
}

/*:1236*//*1237:*/
#line 14574 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_earley_item_origin(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14577 "./marpa.w"

YIM item= r->t_trace_earley_item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14579 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14580 "./marpa.w"

if(!item){
/*1235:*/
#line 14564 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1235*/
#line 14582 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}
return Origin_Ord_of_YIM(item);
}

/*:1237*//*1239:*/
#line 14594 "./marpa.w"

Marpa_Symbol_ID _marpa_r_leo_predecessor_symbol(Marpa_Recognizer r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14598 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14601 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14602 "./marpa.w"

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

/*:1239*//*1240:*/
#line 14616 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_leo_base_origin(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14620 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14622 "./marpa.w"

YIM base_earley_item;
/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14624 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Trailhead_YIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_YIM(base_earley_item);
}

/*:1240*//*1241:*/
#line 14635 "./marpa.w"

Marpa_AHM_ID _marpa_r_leo_base_state(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14639 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
YIM base_earley_item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14642 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14643 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Trailhead_YIM_of_LIM(LIM_of_PIM(postdot_item));
return AHMID_of_YIM(base_earley_item);
}

/*:1241*//*1244:*/
#line 14676 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_postdot_symbol_trace(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14681 "./marpa.w"

YS current_ys= r->t_trace_earley_set;
PIM*pim_nsy_p;
PIM pim;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14685 "./marpa.w"

/*1245:*/
#line 14702 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1245*/
#line 14686 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14687 "./marpa.w"

/*1194:*/
#line 14155 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1194*/
#line 14688 "./marpa.w"

/*1195:*/
#line 14162 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1195*/
#line 14689 "./marpa.w"

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

/*:1244*//*1246:*/
#line 14712 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_postdot_item_trace(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14716 "./marpa.w"

YS current_earley_set= r->t_trace_earley_set;
PIM pim;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14719 "./marpa.w"

PIM*pim_nsy_p;
/*1245:*/
#line 14702 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1245*/
#line 14721 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14722 "./marpa.w"

if(!current_earley_set){
/*1235:*/
#line 14564 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1235*/
#line 14724 "./marpa.w"

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

/*:1246*//*1247:*/
#line 14743 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_postdot_item_trace(Marpa_Recognizer r)
{
const XSYID no_more_postdot_symbols= -1;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14748 "./marpa.w"

YS current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_nsy_p;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14752 "./marpa.w"


pim_nsy_p= r->t_trace_pim_nsy_p;
pim= r->t_trace_postdot_item;
/*1245:*/
#line 14702 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1245*/
#line 14756 "./marpa.w"

if(!pim_nsy_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14761 "./marpa.w"

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

/*:1247*//*1248:*/
#line 14781 "./marpa.w"

Marpa_Symbol_ID _marpa_r_postdot_item_symbol(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14784 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14786 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14787 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_NSYID_of_PIM(postdot_item);
}

/*:1248*//*1253:*/
#line 14817 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_token_link_trace(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14820 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14824 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14825 "./marpa.w"

/*1267:*/
#line 15014 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1267*/
#line 14826 "./marpa.w"

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

/*:1253*//*1256:*/
#line 14858 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_token_link_trace(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14861 "./marpa.w"

SRCL source_link;
YIM item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14864 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14865 "./marpa.w"

/*1267:*/
#line 15014 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1267*/
#line 14866 "./marpa.w"

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

/*:1256*//*1258:*/
#line 14889 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_completion_link_trace(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14892 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14896 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14897 "./marpa.w"

/*1267:*/
#line 15014 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1267*/
#line 14898 "./marpa.w"

switch((source_type= Source_Type_of_YIM(item)))
{
case SOURCE_IS_COMPLETION:
r->t_trace_source_type= SOURCE_IS_COMPLETION;
source_link= SRCL_of_YIM(item);
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
case SOURCE_IS_AMBIGUOUS:
{
source_link= LV_First_Completion_SRCL_of_YIM(item);
if(source_link)
{
r->t_trace_source_type= SOURCE_IS_COMPLETION;
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:1258*//*1261:*/
#line 14929 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_completion_link_trace(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14932 "./marpa.w"

SRCL source_link;
YIM item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14935 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14936 "./marpa.w"

/*1267:*/
#line 15014 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1267*/
#line 14937 "./marpa.w"

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
return Cause_AHMID_of_SRCL(source_link);
}

/*:1261*//*1263:*/
#line 14960 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_leo_link_trace(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14964 "./marpa.w"

SRCL source_link;
YIM item= r->t_trace_earley_item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14967 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14968 "./marpa.w"

/*1267:*/
#line 15014 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1267*/
#line 14969 "./marpa.w"

source_link= First_Leo_SRCL_of_YIM(item);
if(source_link){
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
}
trace_source_link_clear(r);
return-1;
}

/*:1263*//*1266:*/
#line 14988 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_leo_link_trace(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 14992 "./marpa.w"

SRCL source_link;
YIM item;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 14995 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 14996 "./marpa.w"

/*1267:*/
#line 15014 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1267*/
#line 14997 "./marpa.w"

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
return Cause_AHMID_of_SRCL(source_link);
}

/*:1266*//*1268:*/
#line 15023 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:1268*//*1269:*/
#line 15038 "./marpa.w"

AHMID _marpa_r_source_predecessor_state(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15041 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 15044 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 15045 "./marpa.w"

source_type= r->t_trace_source_type;
/*1275:*/
#line 15190 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1275*/
#line 15047 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:{
YIM predecessor= Predecessor_of_SRCL(source_link);
if(!predecessor)return-1;
return AHMID_of_YIM(predecessor);
}
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:1269*//*1270:*/
#line 15079 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_token(Marpa_Recognizer r,int*value_p)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15082 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 15085 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 15086 "./marpa.w"

source_type= r->t_trace_source_type;
/*1275:*/
#line 15190 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1275*/
#line 15088 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
if(value_p)*value_p= Value_of_SRCL(source_link);
return NSYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:1270*//*1272:*/
#line 15110 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_leo_transition_symbol(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15113 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 15116 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 15117 "./marpa.w"

source_type= r->t_trace_source_type;
/*1275:*/
#line 15190 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1275*/
#line 15119 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_NSYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:1272*//*1274:*/
#line 15153 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_source_middle(Marpa_Recognizer r)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15156 "./marpa.w"

YIM predecessor_yim= NULL;
unsigned int source_type;
SRCL source_link;
/*550:*/
#line 5878 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:550*/
#line 15160 "./marpa.w"

/*1208:*/
#line 14250 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 14251 "./marpa.w"

/*1206:*/
#line 14234 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1206*/
#line 14252 "./marpa.w"


/*:1208*/
#line 15161 "./marpa.w"

source_type= r->t_trace_source_type;
/*1275:*/
#line 15190 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1275*/
#line 15163 "./marpa.w"


switch(source_type)
{
case SOURCE_IS_LEO:
{
LIM predecessor= LIM_of_SRCL(source_link);
if(predecessor)
predecessor_yim= Trailhead_YIM_of_LIM(predecessor);
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

/*:1274*//*1279:*/
#line 15228 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15233 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15234 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15235 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15236 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15237 "./marpa.w"

return YS_Ord_of_OR(or_node);
}

/*:1279*//*1280:*/
#line 15241 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15246 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15247 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15248 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15249 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15250 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:1280*//*1281:*/
#line 15254 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15259 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15260 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15261 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15262 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15263 "./marpa.w"

return IRLID_of_OR(or_node);
}

/*:1281*//*1282:*/
#line 15267 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15272 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15273 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15274 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15275 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15276 "./marpa.w"

return Position_of_OR(or_node);
}

/*:1282*//*1283:*/
#line 15280 "./marpa.w"

int _marpa_b_or_node_is_whole(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15285 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15286 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15287 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15288 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15289 "./marpa.w"

return Position_of_OR(or_node)>=Length_of_IRL(IRL_of_OR(or_node))?1:0;
}

/*:1283*//*1284:*/
#line 15293 "./marpa.w"

int _marpa_b_or_node_is_semantic(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15298 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15299 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15300 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15301 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15302 "./marpa.w"

return!IRL_has_Virtual_LHS(IRL_of_OR(or_node));
}

/*:1284*//*1285:*/
#line 15306 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15311 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15312 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15313 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15314 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15315 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:1285*//*1286:*/
#line 15319 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15324 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15325 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15326 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15327 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15328 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:1286*//*1287:*/
#line 15333 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15338 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15339 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15340 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15341 "./marpa.w"

/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15342 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:1287*//*1290:*/
#line 15356 "./marpa.w"

int _marpa_o_or_node_and_node_count(Marpa_Order o,
Marpa_Or_Node_ID or_node_id)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15360 "./marpa.w"

/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 15361 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15362 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15363 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[0];
}
{
OR or_node;
/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15372 "./marpa.w"

return AND_Count_of_OR(or_node);
}
}

/*:1290*//*1291:*/
#line 15377 "./marpa.w"

int _marpa_o_or_node_and_node_id_by_ix(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15381 "./marpa.w"

/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 15382 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15383 "./marpa.w"

/*1277:*/
#line 15206 "./marpa.w"

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
/*:1277*/
#line 15384 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[1+ix];
}
{
OR or_node;
/*1278:*/
#line 15218 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1278*/
#line 15393 "./marpa.w"

return First_ANDID_of_OR(or_node)+ix;
}
}

/*:1291*//*1293:*/
#line 15400 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15403 "./marpa.w"

/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15404 "./marpa.w"

/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15405 "./marpa.w"

return AND_Count_of_B(b);
}

/*:1293*//*1295:*/
#line 15431 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15436 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15437 "./marpa.w"

/*1294:*/
#line 15409 "./marpa.w"

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

/*:1294*/
#line 15438 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1295*//*1296:*/
#line 15442 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15447 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15448 "./marpa.w"

/*1294:*/
#line 15409 "./marpa.w"

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

/*:1294*/
#line 15449 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1296*//*1297:*/
#line 15458 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15463 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15464 "./marpa.w"

/*1294:*/
#line 15409 "./marpa.w"

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

/*:1294*/
#line 15465 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1297*//*1298:*/
#line 15474 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15479 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15480 "./marpa.w"

/*1294:*/
#line 15409 "./marpa.w"

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

/*:1294*/
#line 15481 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const XSYID symbol_id= 
OR_is_Token(cause_or)?NSYID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1298*//*1299:*/
#line 15490 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
AND and_node;
OR cause_or;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15496 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15497 "./marpa.w"

/*1294:*/
#line 15409 "./marpa.w"

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

/*:1294*/
#line 15498 "./marpa.w"


cause_or= Cause_OR_of_AND(and_node);
if(!OR_is_Token(cause_or))return-1;
if(value_p)*value_p= Value_of_OR(cause_or);
return NSYID_of_OR(cause_or);
}

/*:1299*//*1300:*/
#line 15513 "./marpa.w"

Marpa_Earley_Set_ID _marpa_b_and_node_middle(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15518 "./marpa.w"

/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 15519 "./marpa.w"

/*1294:*/
#line 15409 "./marpa.w"

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

/*:1294*/
#line 15520 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
if(predecessor_or)
{
return YS_Ord_of_OR(predecessor_or);
}
}
return Origin_Ord_of_OR(OR_of_AND(and_node));
}

/*:1300*//*1303:*/
#line 15553 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15557 "./marpa.w"

/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 15558 "./marpa.w"

/*1302:*/
#line 15535 "./marpa.w"
{
NOOK base_nook;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15537 "./marpa.w"

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

/*:1302*/
#line 15559 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1303*//*1304:*/
#line 15563 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15567 "./marpa.w"

/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 15568 "./marpa.w"

/*1302:*/
#line 15535 "./marpa.w"
{
NOOK base_nook;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15537 "./marpa.w"

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

/*:1302*/
#line 15569 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1304*//*1305:*/
#line 15573 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15577 "./marpa.w"

/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 15578 "./marpa.w"

/*1302:*/
#line 15535 "./marpa.w"
{
NOOK base_nook;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15537 "./marpa.w"

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

/*:1302*/
#line 15579 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1305*//*1306:*/
#line 15583 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15587 "./marpa.w"

/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 15588 "./marpa.w"

/*1302:*/
#line 15535 "./marpa.w"
{
NOOK base_nook;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15537 "./marpa.w"

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

/*:1302*/
#line 15589 "./marpa.w"

return NOOK_Cause_is_Expanded(nook);
}

/*:1306*//*1307:*/
#line 15593 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15597 "./marpa.w"

/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 15598 "./marpa.w"

/*1302:*/
#line 15535 "./marpa.w"
{
NOOK base_nook;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15537 "./marpa.w"

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

/*:1302*/
#line 15599 "./marpa.w"

return NOOK_Predecessor_is_Expanded(nook);
}

/*:1307*//*1308:*/
#line 15603 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15607 "./marpa.w"

/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 15608 "./marpa.w"

/*1302:*/
#line 15535 "./marpa.w"
{
NOOK base_nook;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15537 "./marpa.w"

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

/*:1302*/
#line 15609 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1308*//*1309:*/
#line 15613 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1191:*/
#line 14139 "./marpa.w"
const int failure_indicator= -2;

/*:1191*/
#line 15617 "./marpa.w"

/*996:*/
#line 11574 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 11183 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*924:*/
#line 10786 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:924*/
#line 11185 "./marpa.w"


/*:969*/
#line 11576 "./marpa.w"
;

/*:996*/
#line 15618 "./marpa.w"

/*1302:*/
#line 15535 "./marpa.w"
{
NOOK base_nook;
/*1209:*/
#line 14254 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1209*/
#line 15537 "./marpa.w"

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

/*:1302*/
#line 15619 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1309*//*1311:*/
#line 15634 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
marpa__debug_handler= debug_handler;
}

/*:1311*//*1312:*/
#line 15640 "./marpa.w"

int marpa_debug_level_set(int new_level)
{
const int old_level= marpa__debug_level;
marpa__debug_level= new_level;
return old_level;
}


/*:1312*/
#line 15820 "./marpa.w"


/*:1330*/
