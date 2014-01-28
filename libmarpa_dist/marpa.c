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

/*1303:*/
#line 15216 "./marpa.w"


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
#define IRL_is_Unit_Rule(irl) ((irl) ->t_aim_count==2) 
#define AHM_Count_of_IRL(irl) ((irl) ->t_aim_count) 
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
#define First_AHM_of_IRL(irl) ((irl) ->t_first_aim) 
#define SYMI_Count_of_G(g) ((g) ->t_symbol_instance_count) 
#define SYMI_of_IRL(irl) ((irl) ->t_symbol_instance_base) 
#define Last_Proper_SYMI_of_IRL(irl) ((irl) ->t_last_proper_symi) 
#define SYMI_of_Completed_IRL(irl)  \
(SYMI_of_IRL(irl) +Length_of_IRL(irl) -1) 
#define SYMI_of_AHM(aim) (symbol_instance_of_aim_get(aim) ) 
#define AHM_by_ID(id) (g->t_aims+(id) ) 
#define ID_of_AHM(aim) ((aim) -g->t_aims) 
#define Next_AHM_of_AHM(aim) ((aim) +1) 
#define Prev_AHM_of_AHM(aim) ((aim) -1)  \

#define AHM_Count_of_G(g) ((g) ->t_aim_count) 
#define IRL_of_AHM(aim) ((aim) ->t_irl) 
#define IRLID_of_AHM(item) ID_of_IRL(IRL_of_AHM(item) ) 
#define LHS_NSYID_of_AHM(item) LHSID_of_IRL(IRL_of_AHM(item) ) 
#define LHSID_of_AHM(item) LHS_NSYID_of_AHM(item) 
#define Postdot_NSYID_of_AHM(item) ((item) ->t_postdot_nsyid) 
#define AHM_is_Completion(aim) (Postdot_NSYID_of_AHM(aim) <0) 
#define AHM_is_Leo(aim) (IRL_is_Leo(IRL_of_AHM(aim) ) ) 
#define AHM_is_Leo_Completion(aim)  \
(AHM_is_Completion(aim) &&AHM_is_Leo(aim) ) 
#define Null_Count_of_AHM(aim) ((aim) ->t_leading_nulls) 
#define Position_of_AHM(aim) ((aim) ->t_position) 
#define AHM_is_Prediction(aim) (Quasi_Position_of_AHM(aim) ==0)  \

#define Quasi_Position_of_AHM(aim) ((aim) ->t_quasi_position) 
#define Predicted_IRL_CIL_of_AHM(aim) ((aim) ->t_predicted_irl_cil) 
#define Completion_XSYIDs_of_AHM(aim) ((aim) ->t_completion_xsyids) 
#define Nulled_XSYIDs_of_AHM(aim) ((aim) ->t_nulled_xsyids) 
#define Prediction_XSYIDs_of_AHM(aim) ((aim) ->t_prediction_xsyids) 
#define AHM_was_Predicted(aim) ((aim) ->t_was_predicted) 
#define YIM_was_Predicted(yim) AHM_was_Predicted(AHM_of_YIM(yim) ) 
#define Event_Group_Size_of_AHM(aim) ((aim) ->t_event_group_size) 
#define Event_AHMIDs_of_AHM(aim) ((aim) ->t_event_aimids) 
#define AHM_has_Event(aim) (Count_of_CIL(Event_AHMIDs_of_AHM(aim) ) !=0) 
#define TOK_Obs_of_I(i)  \
((i) ->t_token_obs) 
#define G_of_I(i) ((i) ->t_grammar) 
#define I_of_R(r) ((r) ->t_input) 
#define G_of_R(r) (G_of_I((r) ->t_input) ) 
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
#define LHS_NSYID_of_YIM(yim)  \
LHS_NSYID_of_AHM(AHM_of_YIM(yim) ) 
#define Earley_Item_is_Completion(item)  \
(AHM_is_Completion(AHM_of_YIM(item) ) ) 
#define YS_of_YIM(item) ((item) ->t_key.t_set) 
#define YS_Ord_of_YIM(item) (Ord_of_YS(YS_of_YIM(item) ) ) 
#define Ord_of_YIM(item) ((item) ->t_ordinal) 
#define Earleme_of_YIM(item) Earleme_of_YS(YS_of_YIM(item) ) 
#define AHM_of_YIM(item) ((item) ->t_key.t_aim) 
#define AHMID_of_YIM(item) ID_of_AHM(AHM_of_YIM(item) ) 
#define Origin_Earleme_of_YIM(item) (Earleme_of_YS(Origin_of_YIM(item) ) ) 
#define Origin_Ord_of_YIM(item) (Ord_of_YS(Origin_of_YIM(item) ) ) 
#define Origin_of_YIM(item) ((item) ->t_key.t_origin) 
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
#define Top_AHM_of_LIM(leo) ((leo) ->t_top_aim) 
#define Base_to_AHM_of_LIM(leo) ((leo) ->t_base_to_aim) 
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

#define Cause_AHMID_of_SRCL(srcl)  \
AHMID_of_YIM((YIM) Cause_of_SRCL(srcl) ) 
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
#define WORK_YIM_ITEM(r,ix) (*MARPA_DSTACK_INDEX((r) ->t_yim_work_stack,YIM,ix) ) 
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
#define Set_OR_from_YIM(psia_or,psia_yim) { \
const YIM psia_earley_item= psia_yim; \
const int psia_earley_set_ordinal= YS_Ord_of_YIM(psia_earley_item) ; \
OR**const psia_nodes_by_item=  \
per_ys_data[psia_earley_set_ordinal].t_aexes_by_item; \
const int psia_item_ordinal= Ord_of_YIM(psia_earley_item) ; \
OR*const psia_nodes_by_aex= psia_nodes_by_item[psia_item_ordinal]; \
psia_or= psia_nodes_by_aex?psia_nodes_by_aex[0]:NULL; \
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

#line 15226 "./marpa.w"

#include "marpa_obs.h"
#include "marpa_avl.h"
/*107:*/
#line 1010 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:107*//*143:*/
#line 1237 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef const struct s_xsy*XSY_Const;

/*:143*//*458:*/
#line 4835 "./marpa.w"

struct s_aim;
typedef struct s_aim*AHM;
typedef Marpa_AHM_ID AHMID;

/*:458*//*611:*/
#line 6292 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*YS;
typedef const struct s_earley_set*YS_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*YSK;
/*:611*//*650:*/
#line 6716 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*YIM;
typedef const struct s_earley_item*YIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*YIK;

/*:650*//*658:*/
#line 6867 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*YIX;
union u_postdot_item;
/*:658*//*661:*/
#line 6902 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:661*//*737:*/
#line 7947 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:737*//*741:*/
#line 7974 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:741*//*851:*/
#line 9543 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:851*//*880:*/
#line 9938 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:880*//*921:*/
#line 10554 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:921*//*947:*/
#line 10946 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:947*//*979:*/
#line 11409 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:979*//*990:*/
#line 11512 "./marpa.w"

struct s_bocage_setup_per_ys;
/*:990*//*1053:*/
#line 12188 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1053*//*1088:*/
#line 12635 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1088*//*1101:*/
#line 12772 "./marpa.w"

typedef struct s_value*VALUE;
/*:1101*//*1209:*/
#line 14228 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1209*//*1215:*/
#line 14282 "./marpa.w"

struct s_cil_arena;
/*:1215*//*1235:*/
#line 14615 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1235*//*1237:*/
#line 14630 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1237*/
#line 15229 "./marpa.w"

/*48:*/
#line 659 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:48*//*142:*/
#line 1235 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
/*:142*//*210:*/
#line 1745 "./marpa.w"

struct s_nsy;
typedef struct s_nsy*NSY;
typedef Marpa_NSY_ID NSYID;

/*:210*//*247:*/
#line 2011 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:247*//*320:*/
#line 2730 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:320*//*359:*/
#line 2988 "./marpa.w"
typedef int SYMI;
/*:359*//*492:*/
#line 5089 "./marpa.w"
typedef int AEX;

/*:492*//*525:*/
#line 5600 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:525*//*540:*/
#line 5691 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:540*//*608:*/
#line 6282 "./marpa.w"
typedef Marpa_Earleme JEARLEME;

/*:608*//*610:*/
#line 6286 "./marpa.w"
typedef Marpa_Earley_Set_ID YSID;
/*:610*//*685:*/
#line 7228 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:685*//*687:*/
#line 7240 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:687*//*872:*/
#line 9874 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:872*//*920:*/
#line 10543 "./marpa.w"

typedef int WHEID;

/*:920*//*946:*/
#line 10942 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:946*//*961:*/
#line 11151 "./marpa.w"

typedef struct marpa_progress_item*PROGRESS;
/*:961*//*1087:*/
#line 12631 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1087*//*1146:*/
#line 13438 "./marpa.w"

typedef unsigned int LBW;
typedef LBW*LBV;

/*:1146*//*1154:*/
#line 13530 "./marpa.w"

typedef LBW Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1154*//*1212:*/
#line 14249 "./marpa.w"

typedef int*CIL;

/*:1212*//*1216:*/
#line 14285 "./marpa.w"

typedef struct s_cil_arena*CILAR;
/*:1216*/
#line 15230 "./marpa.w"

/*1214:*/
#line 14274 "./marpa.w"

struct s_cil_arena{
struct marpa_obstack*t_obs;
MARPA_AVL_TREE t_avl;
MARPA_DSTACK_DECLARE(t_buffer);
};
typedef struct s_cil_arena CILAR_Object;

/*:1214*/
#line 15231 "./marpa.w"

/*47:*/
#line 653 "./marpa.w"
struct marpa_g{
/*133:*/
#line 1182 "./marpa.w"

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
#line 985 "./marpa.w"
Bit_Vector t_bv_nsyid_is_terminal;
/*:103*//*105:*/
#line 994 "./marpa.w"

Bit_Vector t_lbv_xsyid_is_completion_event;
Bit_Vector t_lbv_xsyid_is_nulled_event;
Bit_Vector t_lbv_xsyid_is_prediction_event;
/*:105*//*112:*/
#line 1032 "./marpa.w"

MARPA_DSTACK_DECLARE(t_events);
/*:112*//*120:*/
#line 1104 "./marpa.w"

MARPA_AVL_TREE t_xrl_tree;
/*:120*//*124:*/
#line 1134 "./marpa.w"

struct marpa_obstack*t_obs;
struct marpa_obstack*t_xrl_obs;
/*:124*//*127:*/
#line 1151 "./marpa.w"

CILAR_Object t_cilar;
/*:127*//*135:*/
#line 1197 "./marpa.w"

const char*t_error_string;
/*:135*//*460:*/
#line 4852 "./marpa.w"

AHM t_aims;
/*:460*/
#line 655 "./marpa.w"

/*52:*/
#line 681 "./marpa.w"
int t_ref_count;
/*:52*//*77:*/
#line 841 "./marpa.w"
XSYID t_start_xsy_id;
/*:77*//*81:*/
#line 874 "./marpa.w"

IRL t_start_irl;
/*:81*//*85:*/
#line 891 "./marpa.w"

int t_external_size;
/*:85*//*88:*/
#line 905 "./marpa.w"
int t_max_rule_length;
/*:88*//*92:*/
#line 918 "./marpa.w"
Marpa_Rank t_default_rank;
/*:92*//*136:*/
#line 1199 "./marpa.w"

Marpa_Error_Code t_error;
/*:136*//*360:*/
#line 2990 "./marpa.w"

int t_symbol_instance_count;
/*:360*//*461:*/
#line 4856 "./marpa.w"

int t_aim_count;
/*:461*/
#line 656 "./marpa.w"

/*97:*/
#line 953 "./marpa.w"
BITFIELD t_is_precomputed:1;
/*:97*//*100:*/
#line 965 "./marpa.w"
BITFIELD t_has_cycle:1;
/*:100*/
#line 657 "./marpa.w"

};
/*:47*//*111:*/
#line 1025 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:111*//*144:*/
#line 1242 "./marpa.w"

struct s_xsy{
/*196:*/
#line 1645 "./marpa.w"

CIL t_nulled_event_xsyids;
/*:196*//*199:*/
#line 1672 "./marpa.w"
NSY t_nsy_equivalent;
/*:199*//*203:*/
#line 1704 "./marpa.w"
NSY t_nulling_nsy;
/*:203*/
#line 1244 "./marpa.w"

/*145:*/
#line 1251 "./marpa.w"
XSYID t_symbol_id;

/*:145*//*151:*/
#line 1285 "./marpa.w"

Marpa_Rank t_rank;
/*:151*/
#line 1245 "./marpa.w"

/*148:*/
#line 1272 "./marpa.w"
BITFIELD t_is_start:1;
/*:148*//*155:*/
#line 1332 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:155*//*157:*/
#line 1339 "./marpa.w"
BITFIELD t_is_sequence_lhs:1;
/*:157*//*159:*/
#line 1353 "./marpa.w"

BITFIELD t_is_valued:1;
BITFIELD t_is_valued_locked:1;
/*:159*//*163:*/
#line 1397 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:163*//*166:*/
#line 1418 "./marpa.w"
BITFIELD t_is_counted:1;
/*:166*//*169:*/
#line 1434 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:169*//*172:*/
#line 1451 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:172*//*175:*/
#line 1472 "./marpa.w"

BITFIELD t_is_terminal:1;
BITFIELD t_is_locked_terminal:1;
/*:175*//*180:*/
#line 1519 "./marpa.w"
BITFIELD t_is_productive:1;
/*:180*//*183:*/
#line 1538 "./marpa.w"
BITFIELD t_is_completion_event:1;
/*:183*//*187:*/
#line 1573 "./marpa.w"
BITFIELD t_is_nulled_event:1;
/*:187*//*191:*/
#line 1608 "./marpa.w"
BITFIELD t_is_prediction_event:1;
/*:191*/
#line 1246 "./marpa.w"

};

/*:144*//*211:*/
#line 1759 "./marpa.w"

struct s_nsy{
int t_or_node_type;
NSYID t_nsyid;
/*233:*/
#line 1909 "./marpa.w"
XSY t_source_xsy;
/*:233*//*237:*/
#line 1932 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:237*/
#line 1763 "./marpa.w"

/*242:*/
#line 1985 "./marpa.w"
Marpa_Rank t_rank;
/*:242*/
#line 1764 "./marpa.w"

/*221:*/
#line 1843 "./marpa.w"
BITFIELD t_is_start:1;
/*:221*//*224:*/
#line 1857 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:224*//*227:*/
#line 1871 "./marpa.w"
BITFIELD t_nsy_is_nulling:1;
/*:227*//*230:*/
#line 1888 "./marpa.w"
BITFIELD t_is_semantic:1;
/*:230*/
#line 1765 "./marpa.w"

};
/*:211*//*246:*/
#line 2002 "./marpa.w"

struct s_xrl{
/*259:*/
#line 2304 "./marpa.w"
int t_rhs_length;
/*:259*//*267:*/
#line 2369 "./marpa.w"
Marpa_Rule_ID t_id;

/*:267*//*268:*/
#line 2372 "./marpa.w"

Marpa_Rank t_rank;
/*:268*/
#line 2004 "./marpa.w"

/*272:*/
#line 2420 "./marpa.w"

BITFIELD t_null_ranks_high:1;
/*:272*//*276:*/
#line 2461 "./marpa.w"
BITFIELD t_is_bnf:1;
/*:276*//*278:*/
#line 2467 "./marpa.w"
BITFIELD t_is_sequence:1;
/*:278*//*280:*/
#line 2481 "./marpa.w"
int t_minimum;
/*:280*//*283:*/
#line 2506 "./marpa.w"
XSYID t_separator_id;
/*:283*//*288:*/
#line 2539 "./marpa.w"
BITFIELD t_is_discard:1;
/*:288*//*292:*/
#line 2579 "./marpa.w"
BITFIELD t_is_proper_separation:1;
/*:292*//*296:*/
#line 2600 "./marpa.w"
BITFIELD t_is_loop:1;
/*:296*//*299:*/
#line 2617 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:299*//*302:*/
#line 2635 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:302*//*306:*/
#line 2653 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:306*//*309:*/
#line 2671 "./marpa.w"
BITFIELD t_is_productive:1;
/*:309*//*312:*/
#line 2688 "./marpa.w"
BITFIELD t_is_used:1;
/*:312*/
#line 2005 "./marpa.w"

/*260:*/
#line 2307 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];


/*:260*/
#line 2006 "./marpa.w"

};
/*:246*//*318:*/
#line 2719 "./marpa.w"

struct s_irl{
/*351:*/
#line 2932 "./marpa.w"
XRL t_source_xrl;
/*:351*//*357:*/
#line 2980 "./marpa.w"
AHM t_first_aim;
/*:357*/
#line 2721 "./marpa.w"

/*321:*/
#line 2741 "./marpa.w"
IRLID t_irl_id;

/*:321*//*328:*/
#line 2778 "./marpa.w"
int t_length;
/*:328*//*330:*/
#line 2793 "./marpa.w"
int t_aim_count;

/*:330*//*342:*/
#line 2872 "./marpa.w"
int t_real_symbol_count;
/*:342*//*345:*/
#line 2890 "./marpa.w"
int t_virtual_start;
/*:345*//*348:*/
#line 2910 "./marpa.w"
int t_virtual_end;
/*:348*//*354:*/
#line 2959 "./marpa.w"
Marpa_Rank t_rank;
/*:354*//*361:*/
#line 2997 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:361*/
#line 2722 "./marpa.w"

/*333:*/
#line 2826 "./marpa.w"
BITFIELD t_is_virtual_lhs:1;
/*:333*//*336:*/
#line 2842 "./marpa.w"
BITFIELD t_is_virtual_rhs:1;
/*:336*//*339:*/
#line 2861 "./marpa.w"
BITFIELD t_is_right_recursive:1;
/*:339*/
#line 2723 "./marpa.w"

/*323:*/
#line 2746 "./marpa.w"

NSYID t_nsyid_array[1];

/*:323*/
#line 2724 "./marpa.w"

};
typedef struct s_irl IRL_Object;

/*:318*//*374:*/
#line 3188 "./marpa.w"

struct sym_rule_pair
{
XSYID t_symid;
RULEID t_ruleid;
};

/*:374*//*457:*/
#line 4829 "./marpa.w"

struct s_aim{
/*466:*/
#line 4879 "./marpa.w"

IRL t_irl;

/*:466*//*472:*/
#line 4927 "./marpa.w"

CIL t_predicted_irl_cil;

/*:472*//*490:*/
#line 5082 "./marpa.w"

CIL t_completion_xsyids;
CIL t_nulled_xsyids;
CIL t_prediction_xsyids;

/*:490*//*496:*/
#line 5120 "./marpa.w"

CIL t_event_aimids;
/*:496*/
#line 4831 "./marpa.w"

/*467:*/
#line 4889 "./marpa.w"
NSYID t_postdot_nsyid;

/*:467*//*468:*/
#line 4898 "./marpa.w"

int t_leading_nulls;

/*:468*//*469:*/
#line 4905 "./marpa.w"

int t_position;

/*:469*//*471:*/
#line 4920 "./marpa.w"

int t_quasi_position;

/*:471*//*497:*/
#line 5124 "./marpa.w"

int t_event_group_size;
/*:497*/
#line 4832 "./marpa.w"

/*494:*/
#line 5099 "./marpa.w"

BITFIELD t_was_predicted:1;

/*:494*/
#line 4833 "./marpa.w"

};
/*:457*//*526:*/
#line 5603 "./marpa.w"

struct s_input{
/*535:*/
#line 5673 "./marpa.w"

struct marpa_obstack*t_token_obs;

/*:535*//*537:*/
#line 5678 "./marpa.w"

GRAMMAR t_grammar;
/*:537*/
#line 5605 "./marpa.w"

/*529:*/
#line 5619 "./marpa.w"

int t_ref_count;
/*:529*/
#line 5606 "./marpa.w"

};

/*:526*//*612:*/
#line 6298 "./marpa.w"

struct s_earley_set_key{
JEARLEME t_earleme;
};
typedef struct s_earley_set_key YSK_Object;
/*:612*//*613:*/
#line 6303 "./marpa.w"

struct s_earley_set{
YSK_Object t_key;
union u_postdot_item**t_postdot_ary;
YS t_next_earley_set;
/*615:*/
#line 6319 "./marpa.w"

YIM*t_earley_items;

/*:615*//*1246:*/
#line 14718 "./marpa.w"

PSL t_dot_psl;
/*:1246*/
#line 6308 "./marpa.w"

int t_postdot_sym_count;
/*614:*/
#line 6316 "./marpa.w"

int t_yim_count;
/*:614*//*616:*/
#line 6330 "./marpa.w"

int t_ordinal;
/*:616*//*620:*/
#line 6348 "./marpa.w"

int t_value;
void*t_pvalue;
/*:620*/
#line 6310 "./marpa.w"

};
typedef struct s_earley_set YS_Object;

/*:613*//*659:*/
#line 6871 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
NSYID t_postdot_nsyid;
YIM t_earley_item;
};
typedef struct s_earley_ix YIX_Object;

/*:659*//*662:*/
#line 6905 "./marpa.w"

struct s_leo_item{
YIX_Object t_earley_ix;
/*663:*/
#line 6919 "./marpa.w"

CIL t_cil;

/*:663*/
#line 6908 "./marpa.w"

YS t_origin;
AHM t_top_aim;
AHM t_base_to_aim;
LIM t_predecessor;
YIM t_base;
YS t_set;
};
typedef struct s_leo_item LIM_Object;

/*:662*//*669:*/
#line 7001 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
YIX_Object t_earley;
};
typedef union u_postdot_item PIM_Object;
typedef union u_postdot_item*PIM;

/*:669*//*738:*/
#line 7955 "./marpa.w"

struct s_token_unvalued{
int t_type;
NSYID t_nsyid;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:738*//*742:*/
#line 7984 "./marpa.w"

struct s_alternative{
TOK t_token;
YS t_start_earley_set;
JEARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:742*//*852:*/
#line 9560 "./marpa.w"

struct s_ur_node_stack{
struct marpa_obstack*t_obs;
UR t_base;
UR t_top;
};

/*:852*//*853:*/
#line 9567 "./marpa.w"

struct s_ur_node{
UR t_prev;
UR t_next;
YIM t_earley_item;
AEX t_aex;
};
typedef struct s_ur_node UR_Object;

/*:853*//*883:*/
#line 9976 "./marpa.w"

struct s_draft_or_node
{
/*882:*/
#line 9970 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:882*/
#line 9979 "./marpa.w"

DAND t_draft_and_node;
};
/*:883*//*884:*/
#line 9982 "./marpa.w"

struct s_final_or_node
{
/*882:*/
#line 9970 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:882*/
#line 9985 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:884*//*885:*/
#line 9993 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:885*//*922:*/
#line 10561 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:922*//*948:*/
#line 10953 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:948*//*991:*/
#line 11514 "./marpa.w"

struct s_bocage_setup_per_ys{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:991*//*1017:*/
#line 11738 "./marpa.w"

struct marpa_order{
struct marpa_obstack*t_ordering_obs;
ANDID**t_and_node_orderings;
/*1020:*/
#line 11756 "./marpa.w"

BOCAGE t_bocage;

/*:1020*/
#line 11742 "./marpa.w"

/*1023:*/
#line 11776 "./marpa.w"
int t_ref_count;
/*:1023*//*1030:*/
#line 11832 "./marpa.w"
int t_ambiguity_metric;

/*:1030*//*1035:*/
#line 11864 "./marpa.w"
int t_high_rank_count;
/*:1035*/
#line 11743 "./marpa.w"

/*1033:*/
#line 11846 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1033*/
#line 11744 "./marpa.w"

BITFIELD t_is_frozen:1;
};
/*:1017*//*1054:*/
#line 12200 "./marpa.w"

/*1089:*/
#line 12646 "./marpa.w"

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

/*:1089*/
#line 12201 "./marpa.w"

/*1103:*/
#line 12786 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1107:*/
#line 12864 "./marpa.w"

struct marpa_obstack*t_obs;
/*:1107*//*1112:*/
#line 12911 "./marpa.w"

MARPA_DSTACK_DECLARE(t_virtual_stack);
/*:1112*//*1134:*/
#line 13064 "./marpa.w"

LBV t_xsy_is_valued;
LBV t_xrl_is_valued;
LBV t_valued_locked;

/*:1134*/
#line 12790 "./marpa.w"

/*1117:*/
#line 12959 "./marpa.w"

int t_ref_count;
/*:1117*//*1129:*/
#line 13040 "./marpa.w"

NOOKID t_nook;
/*:1129*/
#line 12791 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1124:*/
#line 13012 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1124*//*1126:*/
#line 13019 "./marpa.w"

BITFIELD t_trace:1;
/*:1126*/
#line 12794 "./marpa.w"

};

/*:1103*/
#line 12202 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_or_node_in_use;
Marpa_Order t_order;
/*1060:*/
#line 12273 "./marpa.w"

int t_ref_count;
/*:1060*//*1067:*/
#line 12353 "./marpa.w"
int t_pause_counter;
/*:1067*/
#line 12208 "./marpa.w"

/*1073:*/
#line 12424 "./marpa.w"

BITFIELD t_is_exhausted:1;
/*:1073*//*1076:*/
#line 12432 "./marpa.w"

BITFIELD t_is_nulling:1;

/*:1076*/
#line 12209 "./marpa.w"

int t_parse_count;
};

/*:1054*//*1189:*/
#line 14013 "./marpa.w"

struct s_bit_matrix{
int t_row_count;
Bit_Vector_Word t_row_data[1];
};
typedef struct s_bit_matrix*Bit_Matrix;
typedef struct s_bit_matrix Bit_Matrix_Object;

/*:1189*//*1210:*/
#line 14231 "./marpa.w"

struct s_dqueue{int t_current;struct marpa_dstack_s t_stack;};

/*:1210*//*1236:*/
#line 14621 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1236*//*1238:*/
#line 14646 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1238*/
#line 15232 "./marpa.w"


/*:1303*//*1304:*/
#line 15237 "./marpa.w"

/*39:*/
#line 586 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;

/*:39*//*886:*/
#line 10001 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:886*//*967:*/
#line 11177 "./marpa.w"

static const struct marpa_progress_item progress_report_not_ready= {-2,-2,-2};

/*:967*//*1155:*/
#line 13537 "./marpa.w"

static const unsigned int bv_wordbits= lbv_wordbits;
static const unsigned int bv_modmask= lbv_wordbits-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= lbv_lsb;
static const unsigned int bv_msb= lbv_msb;

/*:1155*/
#line 15238 "./marpa.w"


/*:1304*//*1305:*/
#line 15240 "./marpa.w"

/*541:*/
#line 5694 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*554:*/
#line 5796 "./marpa.w"

YS t_first_earley_set;
YS t_latest_earley_set;
JEARLEME t_current_earleme;
/*:554*//*566:*/
#line 5869 "./marpa.w"

Bit_Vector t_lbv_xsyid_completion_event_is_active;
Bit_Vector t_lbv_xsyid_nulled_event_is_active;
Bit_Vector t_lbv_xsyid_prediction_event_is_active;
/*:566*//*569:*/
#line 5885 "./marpa.w"
Bit_Vector t_bv_nsyid_is_expected;
/*:569*//*573:*/
#line 5942 "./marpa.w"
LBV t_nsy_expected_is_event;
/*:573*//*595:*/
#line 6214 "./marpa.w"
Bit_Vector t_bv_irl_is_predicted;
/*:595*//*601:*/
#line 6253 "./marpa.w"
struct marpa_obstack*t_obs;
/*:601*//*627:*/
#line 6460 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:627*//*634:*/
#line 6535 "./marpa.w"

YIM t_trace_earley_item;
/*:634*//*672:*/
#line 7048 "./marpa.w"

union u_postdot_item**t_trace_pim_nsy_p;
union u_postdot_item*t_trace_postdot_item;
/*:672*//*706:*/
#line 7508 "./marpa.w"

SRCL t_trace_source_link;
/*:706*//*743:*/
#line 7992 "./marpa.w"

MARPA_DSTACK_DECLARE(t_alternatives);
/*:743*//*758:*/
#line 8212 "./marpa.w"

LBV t_valued_terminal;
LBV t_unvalued_terminal;
LBV t_valued;
LBV t_unvalued;
LBV t_valued_locked;

/*:758*//*766:*/
#line 8430 "./marpa.w"
MARPA_DSTACK_DECLARE(t_yim_work_stack);
/*:766*//*770:*/
#line 8445 "./marpa.w"
MARPA_DSTACK_DECLARE(t_completion_stack);
/*:770*//*774:*/
#line 8456 "./marpa.w"
MARPA_DSTACK_DECLARE(t_earley_set_stack);
/*:774*//*809:*/
#line 8990 "./marpa.w"

Bit_Vector t_bv_lim_symbols;
Bit_Vector t_bv_pim_symbols;
void**t_pim_workarea;
/*:809*//*828:*/
#line 9272 "./marpa.w"

void**t_lim_chain;
/*:828*//*854:*/
#line 9577 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:854*//*962:*/
#line 11153 "./marpa.w"

const struct marpa_progress_item*t_current_report_item;
MARPA_AVL_TRAV t_progress_report_traverser;
/*:962*//*1239:*/
#line 14654 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1239*/
#line 5697 "./marpa.w"

/*544:*/
#line 5724 "./marpa.w"
int t_ref_count;
/*:544*//*558:*/
#line 5823 "./marpa.w"
int t_earley_item_warning_threshold;
/*:558*//*562:*/
#line 5852 "./marpa.w"
JEARLEME t_furthest_earleme;
/*:562*//*567:*/
#line 5873 "./marpa.w"

int t_active_event_count;
/*:567*//*617:*/
#line 6334 "./marpa.w"

int t_earley_set_count;
/*:617*/
#line 5698 "./marpa.w"

/*551:*/
#line 5787 "./marpa.w"

BITFIELD t_input_phase:2;
/*:551*//*591:*/
#line 6181 "./marpa.w"

BITFIELD t_use_leo_flag:1;
BITFIELD t_is_using_leo:1;
/*:591*//*597:*/
#line 6228 "./marpa.w"
BITFIELD t_is_exhausted:1;
/*:597*//*707:*/
#line 7510 "./marpa.w"

BITFIELD t_trace_source_type:3;
/*:707*/
#line 5699 "./marpa.w"

};

/*:541*/
#line 15241 "./marpa.w"

/*686:*/
#line 7231 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:686*//*688:*/
#line 7243 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};
typedef struct s_source_link SRCL_Object;

/*:688*//*689:*/
#line 7250 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:689*//*690:*/
#line 7257 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source_link t_unique;
};

/*:690*/
#line 15242 "./marpa.w"

/*651:*/
#line 6732 "./marpa.w"

struct s_earley_item_key{
AHM t_aim;
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

/*:651*/
#line 15243 "./marpa.w"

/*980:*/
#line 11411 "./marpa.w"

struct marpa_bocage{
/*887:*/
#line 10012 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:887*//*982:*/
#line 11420 "./marpa.w"

INPUT t_input;

/*:982*//*984:*/
#line 11430 "./marpa.w"

struct marpa_obstack*t_obs;
/*:984*//*987:*/
#line 11489 "./marpa.w"

LBV t_valued_bv;
LBV t_valued_locked_bv;

/*:987*/
#line 11413 "./marpa.w"

/*888:*/
#line 10015 "./marpa.w"

int t_or_node_capacity;
int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:888*//*1001:*/
#line 11637 "./marpa.w"
int t_ambiguity_metric;
/*:1001*//*1005:*/
#line 11651 "./marpa.w"
int t_ref_count;
/*:1005*/
#line 11414 "./marpa.w"

/*1012:*/
#line 11710 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1012*/
#line 11415 "./marpa.w"

};

/*:980*/
#line 15244 "./marpa.w"


/*:1305*/

#line 1 "./marpa.c.p40"
static RULE rule_new(GRAMMAR g,
const XSYID lhs, const XSYID *rhs, int length);
static int
duplicate_rule_cmp (const void *ap, const void *bp, void *param  UNUSED);
static int sym_rule_cmp(
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
static inline int
symbol_instance_of_aim_get (AHM aim);
static inline int aim_is_valid(
GRAMMAR g, AHMID item_id);
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
                    const AHM aim);
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
				       *per_ys_data, YIM yim, AHM aim);
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
psar_safe (const PSAR psar);
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

/*1306:*/
#line 15246 "./marpa.w"

/*1284:*/
#line 15051 "./marpa.w"

extern void*(*const marpa__out_of_memory)(void);

/*:1284*//*1286:*/
#line 15063 "./marpa.w"

extern int marpa__default_debug_handler(const char*format,...);
extern int(*marpa__debug_handler)(const char*,...);
extern int marpa__debug_level;

/*:1286*/
#line 15247 "./marpa.w"

#if MARPA_DEBUG
/*1291:*/
#line 15095 "./marpa.w"

static const char*yim_tag_safe(char*buffer,YIM yim)UNUSED;
static const char*yim_tag(YIM yim)UNUSED;
/*:1291*//*1293:*/
#line 15120 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1293*//*1295:*/
#line 15146 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1295*//*1297:*/
#line 15178 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AHM aim)UNUSED;
static const char*aim_tag(AHM aim)UNUSED;
/*:1297*/
#line 15249 "./marpa.w"

/*1292:*/
#line 15099 "./marpa.w"

static const char*
yim_tag_safe(char*buffer,YIM yim)
{
if(!yim)return"NULL";
sprintf(buffer,"S%d@%d-%d",
AHMID_of_YIM(yim),Origin_Earleme_of_YIM(yim),
Earleme_of_YIM(yim));
return buffer;
}

static char DEBUG_yim_tag_buffer[1000];
static const char*
yim_tag(YIM yim)
{
return yim_tag_safe(DEBUG_yim_tag_buffer,yim);
}

/*:1292*//*1294:*/
#line 15125 "./marpa.w"

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

/*:1294*//*1296:*/
#line 15150 "./marpa.w"

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

/*:1296*//*1298:*/
#line 15181 "./marpa.w"

static const char*
aim_tag_safe(char*buffer,AHM aim)
{
if(!aim)return"NULL";
const int aim_position= Position_of_AHM(aim);
if(aim_position>=0){
sprintf(buffer,"R%d@%d",IRLID_of_AHM(aim),Position_of_AHM(aim));
}else{
sprintf(buffer,"R%d@end",IRLID_of_AHM(aim));
}
return buffer;
}

static char DEBUG_aim_tag_buffer[1000];
static const char*
aim_tag(AHM aim)
{
return aim_tag_safe(DEBUG_aim_tag_buffer,aim);
}

/*:1298*/
#line 15250 "./marpa.w"

#endif
/*1290:*/
#line 15087 "./marpa.w"

int(*marpa__debug_handler)(const char*,...)= 
marpa__default_debug_handler;
int marpa__debug_level= 0;

/*:1290*/
#line 15252 "./marpa.w"

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
#line 842 "./marpa.w"

g->t_start_xsy_id= -1;
/*:78*//*82:*/
#line 876 "./marpa.w"

g->t_start_irl= NULL;
/*:82*//*86:*/
#line 893 "./marpa.w"

External_Size_of_G(g)= 0;

/*:86*//*89:*/
#line 906 "./marpa.w"

g->t_max_rule_length= 0;

/*:89*//*93:*/
#line 919 "./marpa.w"

g->t_default_rank= 0;
/*:93*//*98:*/
#line 954 "./marpa.w"

g->t_is_precomputed= 0;
/*:98*//*101:*/
#line 966 "./marpa.w"

g->t_has_cycle= 0;
/*:101*//*104:*/
#line 986 "./marpa.w"
g->t_bv_nsyid_is_terminal= NULL;

/*:104*//*106:*/
#line 998 "./marpa.w"

g->t_lbv_xsyid_is_completion_event= NULL;
g->t_lbv_xsyid_is_nulled_event= NULL;
g->t_lbv_xsyid_is_prediction_event= NULL;

/*:106*//*113:*/
#line 1036 "./marpa.w"

MARPA_DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:113*//*121:*/
#line 1106 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL);
/*:121*//*125:*/
#line 1137 "./marpa.w"

g->t_obs= marpa_obs_init;
g->t_xrl_obs= marpa_obs_init;
/*:125*//*128:*/
#line 1153 "./marpa.w"

cilar_init(&(g)->t_cilar);
/*:128*//*137:*/
#line 1201 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:137*//*463:*/
#line 4861 "./marpa.w"

g->t_aims= NULL;
/*:463*/
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
#line 1038 "./marpa.w"
MARPA_DSTACK_DESTROY(g->t_events);

/*:114*//*123:*/
#line 1113 "./marpa.w"

/*122:*/
#line 1108 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 1114 "./marpa.w"


/*:123*//*126:*/
#line 1140 "./marpa.w"

marpa_obs_free(g->t_obs);
marpa_obs_free(g->t_xrl_obs);

/*:126*//*129:*/
#line 1155 "./marpa.w"

cilar_destroy(&(g)->t_cilar);

/*:129*//*464:*/
#line 4863 "./marpa.w"

my_free(g->t_aims);

/*:464*/
#line 725 "./marpa.w"

my_free(g);
}

/*:57*//*62:*/
#line 750 "./marpa.w"

int marpa_g_highest_symbol_id(Marpa_Grammar g){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 752 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
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
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 807 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 808 "./marpa.w"

return XRL_Count_of_G(g)-1;
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 812 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 813 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:73*//*75:*/
#line 823 "./marpa.w"

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
#line 844 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 847 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 848 "./marpa.w"

return g->t_start_xsy_id;
}
/*:79*//*80:*/
#line 857 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 860 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 861 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 862 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 863 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 864 "./marpa.w"

return g->t_start_xsy_id= xsy_id;
}

/*:80*//*94:*/
#line 921 "./marpa.w"

Marpa_Rank marpa_g_default_rank(Marpa_Grammar g)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 924 "./marpa.w"

clear_error(g);
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 926 "./marpa.w"

return Default_Rank_of_G(g);
}
/*:94*//*95:*/
#line 931 "./marpa.w"

Marpa_Rank marpa_g_default_rank_set(Marpa_Grammar g,Marpa_Rank rank)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 934 "./marpa.w"

clear_error(g);
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 936 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 937 "./marpa.w"

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
#line 956 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 959 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 960 "./marpa.w"

return G_is_Precomputed(g);
}

/*:99*//*102:*/
#line 968 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 971 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 972 "./marpa.w"

return g->t_has_cycle;
}

/*:102*//*116:*/
#line 1048 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{

GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= 0;
}
/*:116*//*117:*/
#line 1057 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{

GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= value;
}

/*:117*//*118:*/
#line 1067 "./marpa.w"

Marpa_Event_Type
marpa_g_event(Marpa_Grammar g,Marpa_Event*public_event,
int ix)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1072 "./marpa.w"

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
#line 1092 "./marpa.w"

Marpa_Event_Type
marpa_g_event_count(Marpa_Grammar g)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1096 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1097 "./marpa.w"

return MARPA_DSTACK_LENGTH(g->t_events);
}

/*:119*//*139:*/
#line 1212 "./marpa.w"

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
#line 1223 "./marpa.w"

Marpa_Error_Code
marpa_g_error_clear(Marpa_Grammar g)
{
clear_error(g);
return g->t_error;
}

/*:140*//*146:*/
#line 1253 "./marpa.w"

PRIVATE XSY
symbol_new(GRAMMAR g)
{
XSY xsy= marpa_obs_new(g->t_obs,struct s_xsy,1);
/*149:*/
#line 1273 "./marpa.w"
xsy->t_is_start= 0;
/*:149*//*152:*/
#line 1287 "./marpa.w"

xsy->t_rank= Default_Rank_of_G(g);
/*:152*//*156:*/
#line 1333 "./marpa.w"

XSY_is_LHS(xsy)= 0;

/*:156*//*158:*/
#line 1340 "./marpa.w"

XSY_is_Sequence_LHS(xsy)= 0;

/*:158*//*160:*/
#line 1356 "./marpa.w"

XSY_is_Valued(xsy)= 0;
XSY_is_Valued_Locked(xsy)= 0;

/*:160*//*164:*/
#line 1398 "./marpa.w"

xsy->t_is_accessible= 0;
/*:164*//*167:*/
#line 1419 "./marpa.w"

xsy->t_is_counted= 0;
/*:167*//*170:*/
#line 1435 "./marpa.w"

xsy->t_is_nulling= 0;
/*:170*//*173:*/
#line 1452 "./marpa.w"

xsy->t_is_nullable= 0;
/*:173*//*176:*/
#line 1475 "./marpa.w"

xsy->t_is_terminal= 0;
xsy->t_is_locked_terminal= 0;
/*:176*//*181:*/
#line 1520 "./marpa.w"

xsy->t_is_productive= 0;
/*:181*//*184:*/
#line 1539 "./marpa.w"

xsy->t_is_completion_event= 0;
/*:184*//*188:*/
#line 1574 "./marpa.w"

xsy->t_is_nulled_event= 0;
/*:188*//*192:*/
#line 1609 "./marpa.w"

xsy->t_is_prediction_event= 0;
/*:192*//*197:*/
#line 1657 "./marpa.w"

Nulled_XSYIDs_of_XSY(xsy)= NULL;

/*:197*//*200:*/
#line 1673 "./marpa.w"
NSY_of_XSY(xsy)= NULL;
/*:200*//*204:*/
#line 1705 "./marpa.w"
Nulling_NSY_of_XSY(xsy)= NULL;
/*:204*/
#line 1258 "./marpa.w"

symbol_add(g,xsy);
return xsy;
}

/*:146*//*147:*/
#line 1263 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const XSY symbol= symbol_new(g);
return ID_of_XSY(symbol);
}

/*:147*//*150:*/
#line 1274 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1277 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1278 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1279 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1280 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_start;
}

/*:150*//*153:*/
#line 1290 "./marpa.w"

int marpa_g_symbol_rank(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1295 "./marpa.w"

clear_error(g);
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1297 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1298 "./marpa.w"

/*1264:*/
#line 14869 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1264*/
#line 1299 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
return Rank_of_XSY(xsy);
}
/*:153*//*154:*/
#line 1303 "./marpa.w"

int marpa_g_symbol_rank_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,Marpa_Rank rank)
{
XSY xsy;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1308 "./marpa.w"

clear_error(g);
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1310 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 1311 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1312 "./marpa.w"

/*1264:*/
#line 14869 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1264*/
#line 1313 "./marpa.w"

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
#line 1360 "./marpa.w"

int marpa_g_symbol_is_valued(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1365 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1366 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1367 "./marpa.w"

return XSY_is_Valued(XSY_by_ID(xsy_id));
}

/*:161*//*162:*/
#line 1371 "./marpa.w"

int marpa_g_symbol_is_valued_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1376 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1377 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1378 "./marpa.w"

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
#line 1406 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1409 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1410 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 1411 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1412 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1413 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(xsy_id));
}

/*:165*//*168:*/
#line 1421 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1425 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1426 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1427 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1428 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_counted;
}

/*:168*//*171:*/
#line 1437 "./marpa.w"

int marpa_g_symbol_is_nulling(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1440 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1441 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 1442 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1443 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1444 "./marpa.w"

return XSY_is_Nulling(XSY_by_ID(xsy_id));
}

/*:171*//*174:*/
#line 1454 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1457 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1458 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 1459 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1460 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1461 "./marpa.w"

return XSYID_is_Nullable(xsy_id);
}

/*:174*//*178:*/
#line 1481 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1485 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1486 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1487 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1488 "./marpa.w"

return XSYID_is_Terminal(xsy_id);
}
/*:178*//*179:*/
#line 1491 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1496 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1497 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 1498 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1499 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1500 "./marpa.w"

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
#line 1522 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1527 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1528 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 1529 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1530 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1531 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(xsy_id));
}

/*:182*//*185:*/
#line 1541 "./marpa.w"

int marpa_g_symbol_is_completion_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1545 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1546 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1547 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1548 "./marpa.w"

return XSYID_is_Completion_Event(xsy_id);
}
/*:185*//*186:*/
#line 1551 "./marpa.w"

int marpa_g_symbol_is_completion_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1556 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1557 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 1558 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1559 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1560 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Completion_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:186*//*189:*/
#line 1576 "./marpa.w"

int marpa_g_symbol_is_nulled_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1580 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1581 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1582 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1583 "./marpa.w"

return XSYID_is_Nulled_Event(xsy_id);
}
/*:189*//*190:*/
#line 1586 "./marpa.w"

int marpa_g_symbol_is_nulled_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1591 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1592 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 1593 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1594 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1595 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Nulled_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:190*//*193:*/
#line 1611 "./marpa.w"

int marpa_g_symbol_is_prediction_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1615 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1616 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1617 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1618 "./marpa.w"

return XSYID_is_Prediction_Event(xsy_id);
}
/*:193*//*194:*/
#line 1621 "./marpa.w"

int marpa_g_symbol_is_prediction_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1626 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1627 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 1628 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1629 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1630 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
return XSY_is_Prediction_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:194*//*195:*/
#line 1640 "./marpa.w"

/*:195*//*201:*/
#line 1674 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1681 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1682 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1683 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:201*//*205:*/
#line 1706 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nulling_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1713 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 1714 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 1715 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= Nulling_NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:205*//*207:*/
#line 1727 "./marpa.w"

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
#line 1776 "./marpa.w"

PRIVATE NSY
nsy_start(GRAMMAR g)
{
const NSY nsy= marpa_obs_new(g->t_obs,struct s_nsy,1);
ID_of_NSY(nsy)= MARPA_DSTACK_LENGTH((g)->t_nsy_stack);
*MARPA_DSTACK_PUSH((g)->t_nsy_stack,NSY)= nsy;
/*212:*/
#line 1771 "./marpa.w"

nsy->t_or_node_type= NULLING_TOKEN_OR_NODE;

/*:212*//*222:*/
#line 1844 "./marpa.w"
NSY_is_Start(nsy)= 0;
/*:222*//*225:*/
#line 1858 "./marpa.w"
NSY_is_LHS(nsy)= 0;
/*:225*//*228:*/
#line 1872 "./marpa.w"
NSY_is_Nulling(nsy)= 0;
/*:228*//*231:*/
#line 1889 "./marpa.w"
NSY_is_Semantic(nsy)= 0;
/*:231*//*234:*/
#line 1910 "./marpa.w"
Source_XSY_of_NSY(nsy)= NULL;
/*:234*//*238:*/
#line 1935 "./marpa.w"

LHS_XRL_of_NSY(nsy)= NULL;
XRL_Offset_of_NSY(nsy)= -1;

/*:238*//*243:*/
#line 1986 "./marpa.w"

Rank_of_NSY(nsy)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:243*/
#line 1783 "./marpa.w"

return nsy;
}

/*:214*//*215:*/
#line 1789 "./marpa.w"

PRIVATE NSY
nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_start(g);
Source_XSY_of_NSY(new_nsy)= source;
Rank_of_NSY(new_nsy)= NSY_Rank_by_XSY(source);
return new_nsy;
}

/*:215*//*216:*/
#line 1801 "./marpa.w"

PRIVATE NSY
semantic_nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_new(g,source);
NSY_is_Semantic(new_nsy)= 1;
return new_nsy;
}

/*:216*//*217:*/
#line 1812 "./marpa.w"

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
#line 1834 "./marpa.w"

int _marpa_g_nsy_count(Marpa_Grammar g){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1836 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1837 "./marpa.w"

return NSY_Count_of_G(g);
}

/*:220*//*223:*/
#line 1845 "./marpa.w"

int _marpa_g_nsy_is_start(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1848 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1849 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 1850 "./marpa.w"

/*1265:*/
#line 14874 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1265*/
#line 1851 "./marpa.w"

return NSY_is_Start(NSY_by_ID(nsy_id));
}

/*:223*//*226:*/
#line 1859 "./marpa.w"

int _marpa_g_nsy_is_lhs(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1862 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1863 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 1864 "./marpa.w"

/*1265:*/
#line 14874 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1265*/
#line 1865 "./marpa.w"

return NSY_is_LHS(NSY_by_ID(nsy_id));
}

/*:226*//*229:*/
#line 1873 "./marpa.w"

int _marpa_g_nsy_is_nulling(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1876 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 1877 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 1878 "./marpa.w"

/*1265:*/
#line 14874 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1265*/
#line 1879 "./marpa.w"

return NSY_is_Nulling(NSY_by_ID(nsy_id));
}

/*:229*//*232:*/
#line 1890 "./marpa.w"

int _marpa_g_nsy_is_semantic(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1895 "./marpa.w"

/*1265:*/
#line 14874 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1265*/
#line 1896 "./marpa.w"

return NSYID_is_Semantic(nsy_id);
}

/*:232*//*235:*/
#line 1911 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
XSY source_xsy;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1917 "./marpa.w"

/*1265:*/
#line 14874 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1265*/
#line 1918 "./marpa.w"

source_xsy= Source_XSY_of_NSYID(nsy_id);
return ID_of_XSY(source_xsy);
}

/*:235*//*240:*/
#line 1946 "./marpa.w"

Marpa_Rule_ID _marpa_g_nsy_lhs_xrl(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1949 "./marpa.w"

/*1265:*/
#line 14874 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1265*/
#line 1950 "./marpa.w"

{
const NSY nsy= NSY_by_ID(nsy_id);
const XRL lhs_xrl= LHS_XRL_of_NSY(nsy);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:240*//*241:*/
#line 1970 "./marpa.w"

int _marpa_g_nsy_xrl_offset(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1973 "./marpa.w"

NSY nsy;
/*1265:*/
#line 14874 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1265*/
#line 1975 "./marpa.w"

nsy= NSY_by_ID(nsy_id);
return XRL_Offset_of_NSY(nsy);
}

/*:241*//*244:*/
#line 1988 "./marpa.w"

Marpa_Rank _marpa_g_nsy_rank(
Marpa_Grammar g,
Marpa_NSY_ID nsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 1993 "./marpa.w"

/*1265:*/
#line 14874 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1265*/
#line 1994 "./marpa.w"

return Rank_of_NSY(NSY_by_ID(nsy_id));
}

/*:244*//*250:*/
#line 2029 "./marpa.w"

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
#line 2374 "./marpa.w"

rule->t_rank= Default_Rank_of_G(g);
/*:269*//*273:*/
#line 2422 "./marpa.w"

rule->t_null_ranks_high= 0;
/*:273*//*277:*/
#line 2462 "./marpa.w"

rule->t_is_bnf= 0;

/*:277*//*279:*/
#line 2468 "./marpa.w"

rule->t_is_sequence= 0;

/*:279*//*281:*/
#line 2482 "./marpa.w"

rule->t_minimum= -1;
/*:281*//*284:*/
#line 2507 "./marpa.w"

Separator_of_XRL(rule)= -1;
/*:284*//*289:*/
#line 2540 "./marpa.w"

rule->t_is_discard= 0;
/*:289*//*293:*/
#line 2580 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:293*//*297:*/
#line 2601 "./marpa.w"

rule->t_is_loop= 0;
/*:297*//*300:*/
#line 2618 "./marpa.w"

XRL_is_Nulling(rule)= 0;
/*:300*//*303:*/
#line 2636 "./marpa.w"

XRL_is_Nullable(rule)= 0;
/*:303*//*307:*/
#line 2654 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:307*//*310:*/
#line 2672 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:310*//*313:*/
#line 2690 "./marpa.w"

XRL_is_Used(rule)= 0;
/*:313*/
#line 2053 "./marpa.w"

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
#line 2069 "./marpa.w"

PRIVATE IRL
irl_start(GRAMMAR g,int length)
{
IRL irl;
const size_t sizeof_irl= offsetof(struct s_irl,t_nsyid_array)+
((size_t)length+1)*sizeof(irl->t_nsyid_array[0]);


irl= marpa__obs_alloc(g->t_obs,sizeof_irl,ALIGNOF(IRL_Object));

ID_of_IRL(irl)= MARPA_DSTACK_LENGTH((g)->t_irl_stack);
Length_of_IRL(irl)= length;
/*334:*/
#line 2827 "./marpa.w"

IRL_has_Virtual_LHS(irl)= 0;
/*:334*//*337:*/
#line 2843 "./marpa.w"

IRL_has_Virtual_RHS(irl)= 0;
/*:337*//*340:*/
#line 2862 "./marpa.w"

IRL_is_Right_Recursive(irl)= 0;

/*:340*//*343:*/
#line 2873 "./marpa.w"
Real_SYM_Count_of_IRL(irl)= 0;
/*:343*//*346:*/
#line 2891 "./marpa.w"
irl->t_virtual_start= -1;
/*:346*//*349:*/
#line 2911 "./marpa.w"
irl->t_virtual_end= -1;
/*:349*//*352:*/
#line 2933 "./marpa.w"
Source_XRL_of_IRL(irl)= NULL;
/*:352*//*355:*/
#line 2960 "./marpa.w"

Rank_of_IRL(irl)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:355*//*358:*/
#line 2981 "./marpa.w"

First_AHM_of_IRL(irl)= NULL;

/*:358*//*362:*/
#line 3000 "./marpa.w"

Last_Proper_SYMI_of_IRL(irl)= -1;
/*:362*/
#line 2082 "./marpa.w"

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
#line 2108 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,int length)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2113 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2116 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 2117 "./marpa.w"

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
#line 2162 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2169 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2170 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 2171 "./marpa.w"

/*256:*/
#line 2202 "./marpa.w"

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
#line 2172 "./marpa.w"

/*255:*/
#line 2180 "./marpa.w"

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
#line 2173 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:254*//*258:*/
#line 2255 "./marpa.w"

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
#line 2310 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:261*//*262:*/
#line 2314 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2316 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2317 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2318 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2319 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:262*//*263:*/
#line 2322 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:263*//*264:*/
#line 2326 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2329 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2330 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2331 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2332 "./marpa.w"

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
#line 2345 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2347 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2348 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2349 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2350 "./marpa.w"

return Length_of_XRL(XRL_by_ID(xrl_id));
}

/*:265*//*270:*/
#line 2377 "./marpa.w"

int marpa_g_rule_rank(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2382 "./marpa.w"

clear_error(g);
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2384 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2385 "./marpa.w"

/*1268:*/
#line 14892 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1268*/
#line 2386 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Rank_of_XRL(xrl);
}
/*:270*//*271:*/
#line 2390 "./marpa.w"

int marpa_g_rule_rank_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,Marpa_Rank rank)
{
XRL xrl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2395 "./marpa.w"

clear_error(g);
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2397 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 2398 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2399 "./marpa.w"

/*1268:*/
#line 14892 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1268*/
#line 2400 "./marpa.w"

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
#line 2426 "./marpa.w"

int marpa_g_rule_null_high(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2431 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2432 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2433 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2434 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Null_Ranks_High_of_RULE(xrl);
}
/*:274*//*275:*/
#line 2438 "./marpa.w"

int marpa_g_rule_null_high_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,int flag)
{
XRL xrl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2443 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2444 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 2445 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2446 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2447 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(_MARPA_UNLIKELY(flag<0||flag> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return Null_Ranks_High_of_RULE(xrl)= Boolean(flag);
}

/*:275*//*282:*/
#line 2484 "./marpa.w"

int marpa_g_sequence_min(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2489 "./marpa.w"

XRL xrl;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2491 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2492 "./marpa.w"

/*1268:*/
#line 14892 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1268*/
#line 2493 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Minimum_of_XRL(xrl);
}

/*:282*//*285:*/
#line 2509 "./marpa.w"

Marpa_Symbol_ID marpa_g_sequence_separator(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2514 "./marpa.w"

XRL xrl;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2516 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2517 "./marpa.w"

/*1268:*/
#line 14892 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1268*/
#line 2518 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))return-1;
return Separator_of_XRL(xrl);
}

/*:285*//*290:*/
#line 2542 "./marpa.w"

int _marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2547 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2548 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2549 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2550 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:290*//*294:*/
#line 2582 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2587 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2588 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2589 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2590 "./marpa.w"

return!XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:294*//*298:*/
#line 2603 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2606 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2607 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2608 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2609 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 2610 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:298*//*301:*/
#line 2620 "./marpa.w"

int marpa_g_rule_is_nulling(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2623 "./marpa.w"

XRL xrl;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2625 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2626 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2627 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nulling(xrl);
}

/*:301*//*304:*/
#line 2638 "./marpa.w"

int marpa_g_rule_is_nullable(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2641 "./marpa.w"

XRL xrl;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2643 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2644 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2645 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nullable(xrl);
}

/*:304*//*308:*/
#line 2656 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2659 "./marpa.w"

XRL xrl;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2661 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2662 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2663 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:308*//*311:*/
#line 2674 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2677 "./marpa.w"

XRL xrl;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2679 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2680 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2681 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:311*//*314:*/
#line 2692 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2696 "./marpa.w"

/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 2697 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 2698 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:314*//*316:*/
#line 2705 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2710 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2711 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:316*//*325:*/
#line 2752 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
IRL irl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2755 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2756 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 2757 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2758 "./marpa.w"

irl= IRL_by_ID(irl_id);
return LHSID_of_IRL(irl);
}

/*:325*//*327:*/
#line 2765 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_rhs(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2768 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2769 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 2770 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2771 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHSID_of_IRL(irl,ix);
}

/*:327*//*329:*/
#line 2779 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2781 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 2782 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 2783 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2784 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}

/*:329*//*335:*/
#line 2829 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2834 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 2835 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2836 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:335*//*338:*/
#line 2845 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2850 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 2851 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2852 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:338*//*344:*/
#line 2874 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2879 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 2880 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2881 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:344*//*347:*/
#line 2892 "./marpa.w"

int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2898 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 2899 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2900 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:347*//*350:*/
#line 2912 "./marpa.w"

int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2918 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 2919 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2920 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:350*//*353:*/
#line 2934 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2940 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2941 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:353*//*356:*/
#line 2962 "./marpa.w"

Marpa_Rank _marpa_g_irl_rank(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 2967 "./marpa.w"

/*1266:*/
#line 14879 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1266*/
#line 2968 "./marpa.w"

return Rank_of_IRL(IRL_by_ID(irl_id));
}

/*:356*//*364:*/
#line 3014 "./marpa.w"

PRIVATE int
symbol_instance_of_aim_get(AHM aim)
{
if(!AHM_is_Prediction(aim)){
const IRL irl= IRL_of_AHM(aim);
return SYMI_of_IRL(irl)+Position_of_AHM(aim-1);
}
return-1;
}

/*:364*//*366:*/
#line 3042 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 3045 "./marpa.w"

int return_value= failure_indicator;
struct marpa_obstack*obs_precompute= marpa_obs_init;
/*369:*/
#line 3151 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);

/*:369*//*373:*/
#line 3184 "./marpa.w"

XSYID start_xsy_id= g->t_start_xsy_id;

/*:373*//*385:*/
#line 3476 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:385*/
#line 3048 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 3049 "./marpa.w"

G_EVENTS_CLEAR(g);
/*370:*/
#line 3155 "./marpa.w"

if(_MARPA_UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
goto FAILURE;
}

/*:370*/
#line 3051 "./marpa.w"

/*1260:*/
#line 14846 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1260*/
#line 3052 "./marpa.w"

/*372:*/
#line 3165 "./marpa.w"

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

/*:372*/
#line 3053 "./marpa.w"




/*122:*/
#line 1108 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 3057 "./marpa.w"


{
/*378:*/
#line 3358 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:378*//*379:*/
#line 3361 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;
RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:379*//*383:*/
#line 3422 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:383*/
#line 3060 "./marpa.w"

/*368:*/
#line 3134 "./marpa.w"

{
/*376:*/
#line 3208 "./marpa.w"

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

/*:376*/
#line 3136 "./marpa.w"

/*377:*/
#line 3329 "./marpa.w"

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

/*:377*/
#line 3137 "./marpa.w"

/*384:*/
#line 3444 "./marpa.w"

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

/*:384*/
#line 3138 "./marpa.w"

/*380:*/
#line 3367 "./marpa.w"

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

/*:380*/
#line 3139 "./marpa.w"

/*381:*/
#line 3395 "./marpa.w"

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

/*:381*/
#line 3140 "./marpa.w"

/*382:*/
#line 3416 "./marpa.w"

if(_MARPA_UNLIKELY(!bv_bit_test(productive_v,start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:382*/
#line 3141 "./marpa.w"

/*386:*/
#line 3481 "./marpa.w"

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

/*:386*/
#line 3142 "./marpa.w"

/*387:*/
#line 3501 "./marpa.w"

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

/*:387*/
#line 3143 "./marpa.w"

/*388:*/
#line 3540 "./marpa.w"

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
/*390:*/
#line 3591 "./marpa.w"

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

/*:390*/
#line 3551 "./marpa.w"

continue;
}
/*389:*/
#line 3560 "./marpa.w"

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

/*:389*/
#line 3554 "./marpa.w"

}
}

/*:388*/
#line 3144 "./marpa.w"

/*391:*/
#line 3646 "./marpa.w"

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

/*:391*/
#line 3145 "./marpa.w"

if(1){
/*392:*/
#line 3674 "./marpa.w"

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

/*:392*/
#line 3147 "./marpa.w"

}
}

/*:368*/
#line 3061 "./marpa.w"

/*439:*/
#line 4522 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,xrl_count,
xrl_count);
/*440:*/
#line 4543 "./marpa.w"

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
/*441:*/
#line 4586 "./marpa.w"

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

/*:441*/
#line 4564 "./marpa.w"

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

/*441:*/
#line 4586 "./marpa.w"

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

/*:441*/
#line 4577 "./marpa.w"

}
}
}
}

/*:440*/
#line 4528 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*442:*/
#line 4600 "./marpa.w"

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

/*:442*/
#line 4530 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:439*/
#line 3062 "./marpa.w"

}


/*506:*/
#line 5241 "./marpa.w"

MARPA_DSTACK_INIT(g->t_irl_stack,IRL,2*MARPA_DSTACK_CAPACITY(g->t_xrl_stack));

/*:506*/
#line 3066 "./marpa.w"

/*507:*/
#line 5249 "./marpa.w"

{
MARPA_DSTACK_INIT(g->t_nsy_stack,NSY,2*MARPA_DSTACK_CAPACITY(g->t_xsy_stack));
}

/*:507*/
#line 3067 "./marpa.w"

/*404:*/
#line 3869 "./marpa.w"

{
/*405:*/
#line 3900 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:405*//*408:*/
#line 3958 "./marpa.w"

int factor_count;
int*factor_positions;
/*:408*/
#line 3871 "./marpa.w"

/*409:*/
#line 3961 "./marpa.w"

factor_positions= marpa_obs_new(obs_precompute,int,g->t_max_rule_length);

/*:409*/
#line 3872 "./marpa.w"

/*406:*/
#line 3906 "./marpa.w"

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

/*:406*/
#line 3873 "./marpa.w"

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
/*393:*/
#line 3722 "./marpa.w"

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
/*394:*/
#line 3751 "./marpa.w"

{
IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= lhs_nsyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);

IRL_has_Virtual_RHS(rewrite_irl)= 1;
}

/*:394*/
#line 3743 "./marpa.w"

if(separator_nsyid>=0&&!XRL_is_Proper_Separation(rule)){
/*395:*/
#line 3764 "./marpa.w"

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

/*:395*/
#line 3745 "./marpa.w"

}
/*396:*/
#line 3781 "./marpa.w"

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
/*:396*/
#line 3747 "./marpa.w"

/*397:*/
#line 3792 "./marpa.w"

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

/*:397*/
#line 3748 "./marpa.w"

}

/*:393*/
#line 3886 "./marpa.w"

continue;
}
/*407:*/
#line 3937 "./marpa.w"

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
/*:407*/
#line 3889 "./marpa.w"


if(factor_count> 0)
{
/*410:*/
#line 3965 "./marpa.w"

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
/*413:*/
#line 4001 "./marpa.w"

NSY chaf_virtual_nsy;
NSYID chaf_virtual_nsyid;
int first_factor_position= factor_positions[factor_position_ix];
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;


/*411:*/
#line 3991 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:411*/
#line 4010 "./marpa.w"

/*414:*/
#line 4029 "./marpa.w"

{
{
const int real_symbol_count= piece_end-piece_start+1;
/*419:*/
#line 4127 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4141 "./marpa.w"

}

/*:419*/
#line 4033 "./marpa.w"
;
}
/*415:*/
#line 4043 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4065 "./marpa.w"

}

/*:415*/
#line 4035 "./marpa.w"
;
{
const int real_symbol_count= piece_end-piece_start+1;
/*421:*/
#line 4173 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4197 "./marpa.w"

}

/*:421*/
#line 4038 "./marpa.w"
;
}
/*416:*/
#line 4073 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4111 "./marpa.w"

}
}

/*:416*/
#line 4040 "./marpa.w"
;
}

/*:414*/
#line 4011 "./marpa.w"

factor_position_ix++;
}else{
piece_end= second_factor_position;
/*411:*/
#line 3991 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:411*/
#line 4015 "./marpa.w"

/*418:*/
#line 4117 "./marpa.w"

{
const int real_symbol_count= piece_end-piece_start+1;
/*419:*/
#line 4127 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4141 "./marpa.w"

}

/*:419*/
#line 4120 "./marpa.w"

/*420:*/
#line 4145 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4169 "./marpa.w"

}

/*:420*/
#line 4121 "./marpa.w"

/*421:*/
#line 4173 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4197 "./marpa.w"

}

/*:421*/
#line 4122 "./marpa.w"

/*422:*/
#line 4201 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4235 "./marpa.w"

}

/*:422*/
#line 4123 "./marpa.w"

}

/*:418*/
#line 4016 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_nsy= chaf_virtual_nsy;
current_lhs_nsyid= chaf_virtual_nsyid;
piece_start= piece_end+1;

/*:413*/
#line 3982 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*423:*/
#line 4240 "./marpa.w"

{
const int first_factor_position= factor_positions[factor_position_ix];
const int second_factor_position= factor_positions[factor_position_ix+1];
const int real_symbol_count= Length_of_XRL(rule)-piece_start;
piece_end= Length_of_XRL(rule)-1;
/*424:*/
#line 4253 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4266 "./marpa.w"

}

/*:424*/
#line 4246 "./marpa.w"

/*425:*/
#line 4270 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4293 "./marpa.w"

}

/*:425*/
#line 4247 "./marpa.w"

/*426:*/
#line 4297 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4320 "./marpa.w"

}

/*:426*/
#line 4248 "./marpa.w"

/*427:*/
#line 4325 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4362 "./marpa.w"

}
}

/*:427*/
#line 4249 "./marpa.w"

}

/*:423*/
#line 3985 "./marpa.w"

}else{
/*428:*/
#line 4367 "./marpa.w"

{
int real_symbol_count;
const int first_factor_position= factor_positions[factor_position_ix];
piece_end= Length_of_XRL(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*429:*/
#line 4378 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4391 "./marpa.w"

}

/*:429*/
#line 4373 "./marpa.w"

/*430:*/
#line 4396 "./marpa.w"

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
/*431:*/
#line 4430 "./marpa.w"

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

/*:431*/
#line 4422 "./marpa.w"

}
}

/*:430*/
#line 4374 "./marpa.w"

}

/*:428*/
#line 3987 "./marpa.w"

}
}

/*:410*/
#line 3893 "./marpa.w"

continue;
}
/*252:*/
#line 2094 "./marpa.w"

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
#line 3896 "./marpa.w"

}
}

/*:404*/
#line 3068 "./marpa.w"

/*433:*/
#line 4447 "./marpa.w"

{
const XSY start_xsy= XSY_by_ID(start_xsy_id);
if(_MARPA_LIKELY(!XSY_is_Nulling(start_xsy))){
/*434:*/
#line 4455 "./marpa.w"
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

/*:434*/
#line 4451 "./marpa.w"

}
}

/*:433*/
#line 3069 "./marpa.w"



if(!G_is_Trivial(g)){
/*505:*/
#line 5230 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
const NSYID nsy_count= NSY_Count_of_G(g);
const XSYID xsy_count= XSY_Count_of_G(g);
IRLID**irl_list_x_lh_nsy= NULL;
Bit_Matrix nsy_by_right_nsy_matrix;
Bit_Matrix prediction_nsy_by_irl_matrix;

/*:505*/
#line 3074 "./marpa.w"

/*508:*/
#line 5254 "./marpa.w"

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

/*:508*/
#line 3075 "./marpa.w"

/*480:*/
#line 4968 "./marpa.w"

{
IRLID irl_id;
int aim_count= 0;
AHM base_item;
AHM current_item;
int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*482:*/
#line 5020 "./marpa.w"

{
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
const NSY nsy= NSY_by_ID(rh_nsyid);
if(!NSY_is_Nulling(nsy))aim_count++;
}
aim_count++;
}

/*:482*/
#line 4977 "./marpa.w"

}
current_item= base_item= marpa_new(struct s_aim,aim_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*481:*/
#line 4995 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
const AHM first_aim_of_irl= current_item;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{
Last_Proper_SYMI_of_IRL(irl)= symbol_instance_of_next_rule+rhs_ix;
/*483:*/
#line 5032 "./marpa.w"

{
/*485:*/
#line 5046 "./marpa.w"

{
IRL_of_AHM(current_item)= irl;
Null_Count_of_AHM(current_item)= leading_nulls;
Quasi_Position_of_AHM(current_item)= current_item-first_aim_of_irl;
AHM_was_Predicted(current_item)= 
((Quasi_Position_of_AHM(current_item)==0)
&&(ID_of_IRL(irl)!=ID_of_IRL(g->t_start_irl)));
/*498:*/
#line 5126 "./marpa.w"

Event_AHMIDs_of_AHM(current_item)= NULL;
Event_Group_Size_of_AHM(current_item)= 0;

/*:498*/
#line 5054 "./marpa.w"

}

/*:485*/
#line 5034 "./marpa.w"

Postdot_NSYID_of_AHM(current_item)= rh_nsyid;
Position_of_AHM(current_item)= rhs_ix;
}

/*:483*/
#line 5006 "./marpa.w"

current_item++;
leading_nulls= 0;
}
else
{
leading_nulls++;
}
}
/*484:*/
#line 5039 "./marpa.w"

{
/*485:*/
#line 5046 "./marpa.w"

{
IRL_of_AHM(current_item)= irl;
Null_Count_of_AHM(current_item)= leading_nulls;
Quasi_Position_of_AHM(current_item)= current_item-first_aim_of_irl;
AHM_was_Predicted(current_item)= 
((Quasi_Position_of_AHM(current_item)==0)
&&(ID_of_IRL(irl)!=ID_of_IRL(g->t_start_irl)));
/*498:*/
#line 5126 "./marpa.w"

Event_AHMIDs_of_AHM(current_item)= NULL;
Event_Group_Size_of_AHM(current_item)= 0;

/*:498*/
#line 5054 "./marpa.w"

}

/*:485*/
#line 5041 "./marpa.w"

Postdot_NSYID_of_AHM(current_item)= -1;
Position_of_AHM(current_item)= -1;
}

/*:484*/
#line 5015 "./marpa.w"

current_item++;
AHM_Count_of_IRL(irl)= current_item-first_aim_of_irl;
}

/*:481*/
#line 4982 "./marpa.w"

{
SYMI_of_IRL(irl)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_IRL(irl);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(aim_count==current_item-base_item);
AHM_Count_of_G(g)= aim_count;
g->t_aims= marpa_renew(struct s_aim,base_item,aim_count);
/*487:*/
#line 5065 "./marpa.w"

{
AHM items= g->t_aims;
AHMID item_id= (AHMID)aim_count;
for(item_id--;item_id>=0;item_id--)
{
AHM item= items+item_id;
IRL irl= IRL_of_AHM(item);
First_AHM_of_IRL(irl)= item;
}
}

/*:487*/
#line 4992 "./marpa.w"

}

/*:480*/
#line 3076 "./marpa.w"

/*511:*/
#line 5305 "./marpa.w"
{
Bit_Matrix prediction_nsy_by_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*512:*/
#line 5313 "./marpa.w"

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

/*:512*/
#line 5308 "./marpa.w"

transitive_closure(prediction_nsy_by_nsy_matrix);
/*513:*/
#line 5350 "./marpa.w"
{
/*514:*/
#line 5354 "./marpa.w"

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

RULEID*p_irl_x_lh_nsy= irl_list_x_lh_nsy[to_nsyid];
const RULEID*p_one_past_rules= irl_list_x_lh_nsy[to_nsyid+1];
for(;p_irl_x_lh_nsy<p_one_past_rules;p_irl_x_lh_nsy++)
{

const IRLID irl_with_this_lhs= *p_irl_x_lh_nsy;
matrix_bit_set(prediction_nsy_by_irl_matrix,
from_nsyid,irl_with_this_lhs);
}
}
}
}
}

/*:514*/
#line 5351 "./marpa.w"

}

/*:513*/
#line 5310 "./marpa.w"

}

/*:511*/
#line 3077 "./marpa.w"

/*500:*/
#line 5139 "./marpa.w"
{
nsy_by_right_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*501:*/
#line 5150 "./marpa.w"

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

/*:501*/
#line 5142 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
/*502:*/
#line 5175 "./marpa.w"

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

/*:502*/
#line 5144 "./marpa.w"

matrix_clear(nsy_by_right_nsy_matrix);
/*503:*/
#line 5202 "./marpa.w"

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

/*:503*/
#line 5146 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
}

/*:500*/
#line 3078 "./marpa.w"

/*516:*/
#line 5388 "./marpa.w"

{
AHMID aim_id;
const int aim_count= AHM_Count_of_G(g);
for(aim_id= 0;aim_id<aim_count;aim_id++)
{
const AHM aim= AHM_by_ID(aim_id);
const NSYID postdot_nsyid= Postdot_NSYID_of_AHM(aim);
if(postdot_nsyid<0)
{
Predicted_IRL_CIL_of_AHM(aim)= cil_empty(&g->t_cilar);
}
else
{
Predicted_IRL_CIL_of_AHM(aim)= 
cil_bv_add(&g->t_cilar,
matrix_row(prediction_nsy_by_irl_matrix,postdot_nsyid));
}
}
}

/*:516*/
#line 3079 "./marpa.w"

/*517:*/
#line 5410 "./marpa.w"

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

/*:517*/
#line 3080 "./marpa.w"

/*518:*/
#line 5431 "./marpa.w"

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

/*:518*/
#line 3081 "./marpa.w"

/*519:*/
#line 5454 "./marpa.w"

{
AHMID aim_id;
const int aim_count_of_g= AHM_Count_of_G(g);
const LBV bv_completion_xsyid= bv_create(xsy_count);
const LBV bv_prediction_xsyid= bv_create(xsy_count);
const LBV bv_nulled_xsyid= bv_create(xsy_count);
const CILAR cilar= &g->t_cilar;
for(aim_id= 0;aim_id<aim_count_of_g;aim_id++)
{
const AHM aim= AHM_by_ID(aim_id);
const NSYID postdot_nsyid= Postdot_NSYID_of_AHM(aim);
const IRL irl= IRL_of_AHM(aim);
bv_clear(bv_completion_xsyid);
bv_clear(bv_prediction_xsyid);
bv_clear(bv_nulled_xsyid);
{
int rhs_ix;
int raw_position= Position_of_AHM(aim);
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
for(rhs_ix= raw_position-Null_Count_of_AHM(aim);
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
Completion_XSYIDs_of_AHM(aim)= 
cil_bv_add(cilar,bv_completion_xsyid);
Nulled_XSYIDs_of_AHM(aim)= cil_bv_add(cilar,bv_nulled_xsyid);
Prediction_XSYIDs_of_AHM(aim)= 
cil_bv_add(cilar,bv_prediction_xsyid);
}
bv_free(bv_completion_xsyid);
bv_free(bv_prediction_xsyid);
bv_free(bv_nulled_xsyid);
}

/*:519*/
#line 3083 "./marpa.w"

/*520:*/
#line 5520 "./marpa.w"

{
AHMID aim_id;
for(aim_id= 0;aim_id<AHM_Count_of_G(g);aim_id++)
{
const CILAR cilar= &g->t_cilar;
const AHM aim= AHM_by_ID(aim_id);
const int aim_is_event= 
Count_of_CIL(Completion_XSYIDs_of_AHM(aim))
||Count_of_CIL(Nulled_XSYIDs_of_AHM(aim))
||Count_of_CIL(Prediction_XSYIDs_of_AHM(aim));
Event_AHMIDs_of_AHM(aim)= 
aim_is_event?cil_singleton(cilar,aim_id):cil_empty(cilar);
}
}

/*:520*/
#line 3084 "./marpa.w"

/*521:*/
#line 5536 "./marpa.w"

{
const int aim_count_of_g= AHM_Count_of_G(g);
AHMID outer_aim_id;
for(outer_aim_id= 0;outer_aim_id<aim_count_of_g;outer_aim_id++)
{
AHMID inner_aim_id;
const AHM outer_aim= AHM_by_ID(outer_aim_id);




NSYID outer_nsyid;
if(!AHM_is_Leo_Completion(outer_aim)){
if(AHM_has_Event(outer_aim)){
Event_Group_Size_of_AHM(outer_aim)= 1;
}
continue;

}
outer_nsyid= LHSID_of_AHM(outer_aim);
for(inner_aim_id= 0;inner_aim_id<aim_count_of_g;
inner_aim_id++)
{
NSYID inner_nsyid;
const AHM inner_aim= AHM_by_ID(inner_aim_id);
if(!AHM_has_Event(inner_aim))
continue;

if(!AHM_is_Leo_Completion(inner_aim))
continue;

inner_nsyid= LHSID_of_AHM(inner_aim);
if(matrix_bit_test(nsy_by_right_nsy_matrix,
outer_nsyid,
inner_nsyid))
{



Event_Group_Size_of_AHM(outer_aim)++;
}
}
}
}

/*:521*/
#line 3085 "./marpa.w"

}
g->t_is_precomputed= 1;
if(g->t_has_cycle)
{
MARPA_ERROR(MARPA_ERR_GRAMMAR_HAS_CYCLE);
goto FAILURE;
}
/*522:*/
#line 5586 "./marpa.w"

{cilar_reinit(&g->t_cilar);}
/*:522*/
#line 3093 "./marpa.w"

return_value= 0;
goto CLEANUP;
FAILURE:;
goto CLEANUP;
CLEANUP:;
marpa_obs_free(obs_precompute);
return return_value;
}

/*:366*//*375:*/
#line 3195 "./marpa.w"

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

/*:375*//*465:*/
#line 4867 "./marpa.w"

PRIVATE int aim_is_valid(
GRAMMAR g,AHMID item_id)
{
return item_id<(AHMID)AHM_Count_of_G(g)&&item_id>=0;
}

/*:465*//*473:*/
#line 4931 "./marpa.w"

int _marpa_g_ahm_count(Marpa_Grammar g){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 4933 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 4934 "./marpa.w"

return AHM_Count_of_G(g);
}

/*:473*//*474:*/
#line 4938 "./marpa.w"

Marpa_IRL_ID _marpa_g_ahm_irl(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 4941 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 4942 "./marpa.w"

/*1270:*/
#line 14907 "./marpa.w"

if(_MARPA_UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1270*/
#line 4943 "./marpa.w"

return IRLID_of_AHM(AHM_by_ID(item_id));
}

/*:474*//*476:*/
#line 4948 "./marpa.w"

int _marpa_g_ahm_position(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 4951 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 4952 "./marpa.w"

/*1270:*/
#line 14907 "./marpa.w"

if(_MARPA_UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1270*/
#line 4953 "./marpa.w"

return Position_of_AHM(AHM_by_ID(item_id));
}

/*:476*//*478:*/
#line 4958 "./marpa.w"

Marpa_Symbol_ID _marpa_g_ahm_postdot(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 4961 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 4962 "./marpa.w"

/*1270:*/
#line 14907 "./marpa.w"

if(_MARPA_UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1270*/
#line 4963 "./marpa.w"

return Postdot_NSYID_of_AHM(AHM_by_ID(item_id));
}

/*:478*//*527:*/
#line 5609 "./marpa.w"

PRIVATE INPUT input_new(GRAMMAR g)
{
INPUT input= my_malloc(sizeof(struct s_input));
TOK_Obs_of_I(input)= marpa_obs_init;
/*530:*/
#line 5621 "./marpa.w"

input->t_ref_count= 1;

/*:530*//*538:*/
#line 5680 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:538*/
#line 5614 "./marpa.w"

return input;
}

/*:527*//*531:*/
#line 5625 "./marpa.w"

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

/*:531*//*532:*/
#line 5638 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:532*//*533:*/
#line 5651 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
marpa_obs_free(TOK_Obs_of_I(input));
my_free(input);
}

/*:533*//*542:*/
#line 5706 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
int nsy_count;
int irl_count;
/*1258:*/
#line 14838 "./marpa.w"
void*const failure_indicator= NULL;
/*:1258*/
#line 5712 "./marpa.w"

/*1261:*/
#line 14852 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1261*/
#line 5713 "./marpa.w"

nsy_count= NSY_Count_of_G(g);
irl_count= IRL_Count_of_G(g);
r= my_malloc(sizeof(struct marpa_r));
/*602:*/
#line 6254 "./marpa.w"
r->t_obs= marpa_obs_init;
/*:602*/
#line 5717 "./marpa.w"

/*545:*/
#line 5725 "./marpa.w"

r->t_ref_count= 1;

/*:545*//*553:*/
#line 5790 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:553*//*555:*/
#line 5800 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:555*//*559:*/
#line 5824 "./marpa.w"

r->t_earley_item_warning_threshold= 
MAX(DEFAULT_YIM_WARNING_THRESHOLD,AHM_Count_of_G(g)*3);
/*:559*//*563:*/
#line 5853 "./marpa.w"
r->t_furthest_earleme= 0;
/*:563*//*568:*/
#line 5875 "./marpa.w"

r->t_lbv_xsyid_completion_event_is_active= NULL;
r->t_lbv_xsyid_nulled_event_is_active= NULL;
r->t_lbv_xsyid_prediction_event_is_active= NULL;
r->t_active_event_count= 0;

/*:568*//*570:*/
#line 5886 "./marpa.w"

r->t_bv_nsyid_is_expected= bv_obs_create(r->t_obs,nsy_count);
/*:570*//*574:*/
#line 5943 "./marpa.w"

r->t_nsy_expected_is_event= lbv_obs_new0(r->t_obs,nsy_count);
/*:574*//*592:*/
#line 6184 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:592*//*596:*/
#line 6215 "./marpa.w"

r->t_bv_irl_is_predicted= bv_obs_create(r->t_obs,irl_count);

/*:596*//*598:*/
#line 6229 "./marpa.w"
r->t_is_exhausted= 0;
/*:598*//*618:*/
#line 6336 "./marpa.w"

r->t_earley_set_count= 0;

/*:618*//*628:*/
#line 6462 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:628*//*635:*/
#line 6537 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:635*//*673:*/
#line 7051 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;
/*:673*//*708:*/
#line 7512 "./marpa.w"

r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:708*//*740:*/
#line 7966 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:740*//*744:*/
#line 7995 "./marpa.w"

MARPA_DSTACK_INIT2(r->t_alternatives,ALT_Object);
/*:744*//*767:*/
#line 8431 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_yim_work_stack);
/*:767*//*771:*/
#line 8446 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_completion_stack);
/*:771*//*775:*/
#line 8457 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_earley_set_stack);
/*:775*//*855:*/
#line 9583 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:855*//*963:*/
#line 11156 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
r->t_progress_report_traverser= NULL;
/*:963*/
#line 5718 "./marpa.w"

/*1240:*/
#line 14656 "./marpa.w"

{
if(G_is_Trivial(g)){
psar_safe(Dot_PSAR_of_R(r));
}else{
psar_init(Dot_PSAR_of_R(r),AHM_Count_of_G(g));
}
}
/*:1240*/
#line 5719 "./marpa.w"

return r;
}

/*:542*//*546:*/
#line 5729 "./marpa.w"

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

/*:546*//*547:*/
#line 5747 "./marpa.w"

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

/*:547*//*548:*/
#line 5761 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 5765 "./marpa.w"

/*550:*/
#line 5778 "./marpa.w"
input_unref(input);

/*:550*//*745:*/
#line 7997 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_alternatives);

/*:745*//*769:*/
#line 8439 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_yim_work_stack);

/*:769*//*773:*/
#line 8454 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_completion_stack);

/*:773*//*776:*/
#line 8458 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_earley_set_stack);

/*:776*//*856:*/
#line 9585 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:856*//*965:*/
#line 11165 "./marpa.w"

/*964:*/
#line 11159 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:964*/
#line 11166 "./marpa.w"
;
/*:965*//*1241:*/
#line 14664 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1241*/
#line 5766 "./marpa.w"

grammar_unref(g);
/*603:*/
#line 6255 "./marpa.w"
marpa_obs_free(r->t_obs);

/*:603*/
#line 5768 "./marpa.w"

my_free(r);
}

/*:548*//*556:*/
#line 5808 "./marpa.w"

unsigned int marpa_r_current_earleme(Marpa_Recognizer r)
{return(unsigned int)Current_Earleme_of_R(r);}

/*:556*//*557:*/
#line 5813 "./marpa.w"

PRIVATE YS current_ys_of_r(RECCE r)
{
const YS latest= Latest_YS_of_R(r);
if(Earleme_of_YS(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:557*//*560:*/
#line 5827 "./marpa.w"

int
marpa_r_earley_item_warning_threshold(Marpa_Recognizer r)
{
return r->t_earley_item_warning_threshold;
}

/*:560*//*561:*/
#line 5836 "./marpa.w"

int
marpa_r_earley_item_warning_threshold_set(Marpa_Recognizer r,int threshold)
{
const int new_threshold= threshold<=0?YIM_FATAL_THRESHOLD:threshold;
r->t_earley_item_warning_threshold= new_threshold;
return new_threshold;
}

/*:561*//*564:*/
#line 5854 "./marpa.w"

unsigned int marpa_r_furthest_earleme(Marpa_Recognizer r)
{return(unsigned int)Furthest_Earleme_of_R(r);}

/*:564*//*571:*/
#line 5894 "./marpa.w"

int marpa_r_terminals_expected(Marpa_Recognizer r,Marpa_Symbol_ID*buffer)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 5897 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 5898 "./marpa.w"

int min,max,start;
int ix= 0;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 5901 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 5902 "./marpa.w"

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

/*:571*//*572:*/
#line 5916 "./marpa.w"

int marpa_r_terminal_is_expected(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 5920 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 5921 "./marpa.w"

XSY xsy;
NSY nsy;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 5924 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 5925 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 5926 "./marpa.w"

/*1264:*/
#line 14869 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}
/*:1264*/
#line 5927 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(!XSY_is_Terminal(xsy))){
return 0;
}
nsy= NSY_of_XSY(xsy);
if(_MARPA_UNLIKELY(!nsy))return 0;
return bv_bit_test(r->t_bv_nsyid_is_expected,ID_of_NSY(nsy));
}

/*:572*//*575:*/
#line 5946 "./marpa.w"

int
marpa_r_expected_symbol_event_set(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int value)
{
XSY xsy;
NSY nsy;
NSYID nsyid;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 5954 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 5955 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 5956 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 5957 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 5958 "./marpa.w"

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

/*:575*//*577:*/
#line 5995 "./marpa.w"

int
marpa_r_completion_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6000 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6001 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6002 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 6003 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 6004 "./marpa.w"

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

/*:577*//*579:*/
#line 6042 "./marpa.w"

int
marpa_r_nulled_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6047 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6048 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6049 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 6050 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 6051 "./marpa.w"

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

/*:579*//*581:*/
#line 6089 "./marpa.w"

int
marpa_r_prediction_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6094 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6095 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6096 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 6097 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 6098 "./marpa.w"

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

/*:581*//*593:*/
#line 6190 "./marpa.w"

int _marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6193 "./marpa.w"

/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6194 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6195 "./marpa.w"

return r->t_use_leo_flag;
}
/*:593*//*594:*/
#line 6198 "./marpa.w"

int _marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6202 "./marpa.w"

/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6203 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6204 "./marpa.w"

/*1271:*/
#line 14916 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1271*/
#line 6205 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:594*//*600:*/
#line 6240 "./marpa.w"

int marpa_r_is_exhausted(Marpa_Recognizer r)
{
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6243 "./marpa.w"

/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6244 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6245 "./marpa.w"

return R_is_Exhausted(r);
}

/*:600*//*622:*/
#line 6355 "./marpa.w"

int marpa_r_earley_set_value(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6358 "./marpa.w"

YS earley_set;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6360 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6361 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 6362 "./marpa.w"

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

/*:622*//*623:*/
#line 6378 "./marpa.w"

int
marpa_r_earley_set_values(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id,
int*p_value,void**p_pvalue)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6383 "./marpa.w"

YS earley_set;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6385 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6386 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 6387 "./marpa.w"

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

/*:623*//*624:*/
#line 6405 "./marpa.w"

int marpa_r_latest_earley_set_value_set(Marpa_Recognizer r,int value)
{
YS earley_set;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6409 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6410 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6411 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 6412 "./marpa.w"

earley_set= Latest_YS_of_R(r);
return Value_of_YS(earley_set)= value;
}

/*:624*//*625:*/
#line 6417 "./marpa.w"

int marpa_r_latest_earley_set_values_set(Marpa_Recognizer r,int value,
void*pvalue)
{
YS earley_set;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6422 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6423 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6424 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 6425 "./marpa.w"

earley_set= Latest_YS_of_R(r);
Value_of_YS(earley_set)= value;
PValue_of_YS(earley_set)= pvalue;
return 1;
}

/*:625*//*626:*/
#line 6433 "./marpa.w"

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
/*621:*/
#line 6351 "./marpa.w"

Value_of_YS(set)= -1;
PValue_of_YS(set)= NULL;

/*:621*//*1247:*/
#line 14720 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1247*/
#line 6448 "./marpa.w"

return set;
}

/*:626*//*629:*/
#line 6465 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_trace_earley_set(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6468 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6469 "./marpa.w"

YS trace_earley_set= r->t_trace_earley_set;
/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 6471 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
return Ord_of_YS(trace_earley_set);
}

/*:629*//*630:*/
#line 6479 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6482 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6483 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 6484 "./marpa.w"

return Ord_of_YS(Latest_YS_of_R(r));
}

/*:630*//*631:*/
#line 6488 "./marpa.w"

Marpa_Earleme marpa_r_earleme(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6491 "./marpa.w"

/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6492 "./marpa.w"

YS earley_set;
/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 6494 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6495 "./marpa.w"

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

/*:631*//*633:*/
#line 6513 "./marpa.w"

int _marpa_r_earley_set_size(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6516 "./marpa.w"

YS earley_set;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6518 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 6519 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 6520 "./marpa.w"

r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return YIM_Count_of_YS(earley_set);
}

/*:633*//*638:*/
#line 6562 "./marpa.w"

Marpa_Earleme
_marpa_r_earley_set_trace(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
YS earley_set;
const int es_does_not_exist= -1;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6568 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6569 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 6570 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_YS(r->t_trace_earley_set)==set_id)
{


return Earleme_of_YS(r->t_trace_earley_set);
}
/*639:*/
#line 6593 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*675:*/
#line 7091 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:675*/
#line 6596 "./marpa.w"

}

/*:639*/
#line 6577 "./marpa.w"

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

/*:638*//*640:*/
#line 6599 "./marpa.w"

Marpa_AHM_ID
_marpa_r_earley_item_trace(Marpa_Recognizer r,Marpa_Earley_Item_ID item_id)
{
const int yim_does_not_exist= -1;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6604 "./marpa.w"

YS trace_earley_set;
YIM earley_item;
YIM*earley_items;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6608 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 6609 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*639:*/
#line 6593 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*675:*/
#line 7091 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:675*/
#line 6596 "./marpa.w"

}

/*:639*/
#line 6613 "./marpa.w"

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

/*:640*//*642:*/
#line 6642 "./marpa.w"

PRIVATE void trace_earley_item_clear(RECCE r)
{
/*641:*/
#line 6639 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:641*/
#line 6645 "./marpa.w"

trace_source_link_clear(r);
}

/*:642*//*643:*/
#line 6649 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_earley_item_origin(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6652 "./marpa.w"

YIM item= r->t_trace_earley_item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6654 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 6655 "./marpa.w"

if(!item){
/*641:*/
#line 6639 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:641*/
#line 6657 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}
return Origin_Ord_of_YIM(item);
}

/*:643*//*652:*/
#line 6754 "./marpa.w"

PRIVATE YIM earley_item_create(const RECCE r,
const YIK_Object key)
{
/*1258:*/
#line 14838 "./marpa.w"
void*const failure_indicator= NULL;
/*:1258*/
#line 6758 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6759 "./marpa.w"

YIM new_item;
YIM*end_of_work_stack;
const YS set= key.t_set;
const int count= ++YIM_Count_of_YS(set);
/*654:*/
#line 6808 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(_MARPA_UNLIKELY(count>=YIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_YIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:654*/
#line 6764 "./marpa.w"

new_item= marpa_obs_new(r->t_obs,struct s_earley_item,1);
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
new_item->t_rejected= 0;
Ord_of_YIM(new_item)= YIM_ORDINAL_CLAMP((unsigned int)count-1);
end_of_work_stack= WORK_YIM_PUSH(r);
*end_of_work_stack= new_item;
return new_item;
}

/*:652*//*653:*/
#line 6775 "./marpa.w"

PRIVATE YIM
earley_item_assign(const RECCE r,const YS set,const YS origin,
const AHM aim)
{
const GRAMMAR g= G_of_R(r);
YIK_Object key;
YIM yim;
PSL psl;
AHMID aim_id= ID_of_AHM(aim);
PSL*psl_owner= &Dot_PSL_of_YS(origin);
if(!*psl_owner)
{
psl_claim(psl_owner,Dot_PSAR_of_R(r));
}
psl= *psl_owner;
yim= PSL_Datum(psl,aim_id);
if(yim
&&Earleme_of_YIM(yim)==Earleme_of_YS(set)
&&Earleme_of_YS(Origin_of_YIM(yim))==Earleme_of_YS(origin))
{
return yim;
}
key.t_origin= origin;
key.t_aim= aim;
key.t_set= set;
yim= earley_item_create(r,key);
PSL_Datum(psl,aim_id)= yim;
return yim;
}

/*:653*//*657:*/
#line 6838 "./marpa.w"

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

/*:657*//*665:*/
#line 6927 "./marpa.w"

Marpa_Symbol_ID _marpa_r_leo_predecessor_symbol(Marpa_Recognizer r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6931 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6934 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 6935 "./marpa.w"

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

/*:665*//*666:*/
#line 6949 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_leo_base_origin(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6953 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6955 "./marpa.w"

YIM base_earley_item;
/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 6957 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_YIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_YIM(base_earley_item);
}

/*:666*//*667:*/
#line 6968 "./marpa.w"

Marpa_AHM_ID _marpa_r_leo_base_state(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 6972 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
YIM base_earley_item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 6975 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 6976 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_YIM_of_LIM(LIM_of_PIM(postdot_item));
return AHMID_of_YIM(base_earley_item);
}

/*:667*//*670:*/
#line 7015 "./marpa.w"

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
/*:670*//*671:*/
#line 7035 "./marpa.w"

PRIVATE PIM first_pim_of_ys_by_nsyid(YS set,NSYID nsyid)
{
PIM*pim_nsy_p= pim_nsy_p_find(set,nsyid);
return pim_nsy_p?*pim_nsy_p:NULL;
}

/*:671*//*674:*/
#line 7065 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_postdot_symbol_trace(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7070 "./marpa.w"

YS current_ys= r->t_trace_earley_set;
PIM*pim_nsy_p;
PIM pim;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7074 "./marpa.w"

/*675:*/
#line 7091 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:675*/
#line 7075 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7076 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 7077 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 7078 "./marpa.w"

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

/*:674*//*676:*/
#line 7101 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_postdot_item_trace(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7105 "./marpa.w"

YS current_earley_set= r->t_trace_earley_set;
PIM pim;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7108 "./marpa.w"

PIM*pim_nsy_p;
/*675:*/
#line 7091 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:675*/
#line 7110 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7111 "./marpa.w"

if(!current_earley_set){
/*641:*/
#line 6639 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:641*/
#line 7113 "./marpa.w"

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

/*:676*//*677:*/
#line 7132 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_postdot_item_trace(Marpa_Recognizer r)
{
const XSYID no_more_postdot_symbols= -1;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7137 "./marpa.w"

YS current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_nsy_p;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7141 "./marpa.w"


pim_nsy_p= r->t_trace_pim_nsy_p;
pim= r->t_trace_postdot_item;
/*675:*/
#line 7091 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:675*/
#line 7145 "./marpa.w"

if(!pim_nsy_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7150 "./marpa.w"

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

/*:677*//*678:*/
#line 7170 "./marpa.w"

Marpa_Symbol_ID _marpa_r_postdot_item_symbol(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7173 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7175 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7176 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_NSYID_of_PIM(postdot_item);
}


/*:678*//*694:*/
#line 7300 "./marpa.w"
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

/*:694*//*699:*/
#line 7380 "./marpa.w"

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

/*:699*//*700:*/
#line 7410 "./marpa.w"

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

/*:700*//*702:*/
#line 7459 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,YIM item)
{
unsigned int previous_source_type= Source_Type_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*703:*/
#line 7476 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:703*/
#line 7467 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*704:*/
#line 7484 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:704*/
#line 7469 "./marpa.w"

return;
case SOURCE_IS_LEO:/*705:*/
#line 7492 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= new_link;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:705*/
#line 7471 "./marpa.w"

return;
}
}

/*:702*//*710:*/
#line 7522 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_token_link_trace(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7525 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7529 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7530 "./marpa.w"

/*724:*/
#line 7719 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:724*/
#line 7531 "./marpa.w"

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

/*:710*//*713:*/
#line 7563 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_token_link_trace(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7566 "./marpa.w"

SRCL source_link;
YIM item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7569 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7570 "./marpa.w"

/*724:*/
#line 7719 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:724*/
#line 7571 "./marpa.w"

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

/*:713*//*715:*/
#line 7594 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_completion_link_trace(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7597 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7601 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7602 "./marpa.w"

/*724:*/
#line 7719 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:724*/
#line 7603 "./marpa.w"

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

/*:715*//*718:*/
#line 7634 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_completion_link_trace(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7637 "./marpa.w"

SRCL source_link;
YIM item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7640 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7641 "./marpa.w"

/*724:*/
#line 7719 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:724*/
#line 7642 "./marpa.w"

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

/*:718*//*720:*/
#line 7665 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_leo_link_trace(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7669 "./marpa.w"

SRCL source_link;
YIM item= r->t_trace_earley_item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7672 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7673 "./marpa.w"

/*724:*/
#line 7719 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:724*/
#line 7674 "./marpa.w"

source_link= First_Leo_SRCL_of_YIM(item);
if(source_link){
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
}
trace_source_link_clear(r);
return-1;
}

/*:720*//*723:*/
#line 7693 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_leo_link_trace(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7697 "./marpa.w"

SRCL source_link;
YIM item;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7700 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7701 "./marpa.w"

/*724:*/
#line 7719 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:724*/
#line 7702 "./marpa.w"

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

/*:723*//*725:*/
#line 7728 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:725*//*726:*/
#line 7743 "./marpa.w"

AHMID _marpa_r_source_predecessor_state(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7746 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7749 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7750 "./marpa.w"

source_type= r->t_trace_source_type;
/*732:*/
#line 7896 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:732*/
#line 7752 "./marpa.w"

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

/*:726*//*727:*/
#line 7784 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_token(Marpa_Recognizer r,int*value_p)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7787 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7790 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7791 "./marpa.w"

source_type= r->t_trace_source_type;
/*732:*/
#line 7896 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:732*/
#line 7793 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK tkn= TOK_of_SRCL(source_link);
if(value_p)*value_p= Value_of_TOK(tkn);
return NSYID_of_TOK(tkn);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:727*//*729:*/
#line 7816 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_leo_transition_symbol(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7819 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7822 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7823 "./marpa.w"

source_type= r->t_trace_source_type;
/*732:*/
#line 7896 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:732*/
#line 7825 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_NSYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:729*//*731:*/
#line 7859 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_source_middle(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 7862 "./marpa.w"

YIM predecessor_yim= NULL;
unsigned int source_type;
SRCL source_link;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 7866 "./marpa.w"

/*1274:*/
#line 14932 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 14933 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 14934 "./marpa.w"


/*:1274*/
#line 7867 "./marpa.w"

source_type= r->t_trace_source_type;
/*732:*/
#line 7896 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:732*/
#line 7869 "./marpa.w"


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

/*:731*//*747:*/
#line 8003 "./marpa.w"

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

/*:747*//*749:*/
#line 8047 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= NSYID_of_ALT(a)-NSYID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:749*//*750:*/
#line 8064 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,JEARLEME earleme)
{
MARPA_DSTACK alternatives= &r->t_alternatives;
ALT end_of_stack= MARPA_DSTACK_TOP(*alternatives,ALT_Object);
if(!end_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(end_of_stack))return NULL;
return MARPA_DSTACK_POP(*alternatives,ALT_Object);
}

/*:750*//*751:*/
#line 8079 "./marpa.w"

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

/*:751*//*752:*/
#line 8100 "./marpa.w"
int marpa_r_start_input(Marpa_Recognizer r)
{
int return_value= 1;
YS set0;
YIK_Object key;

IRL start_irl;
AHM start_aim;

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 8109 "./marpa.w"

/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 8110 "./marpa.w"



/*1271:*/
#line 14916 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1271*/
#line 8113 "./marpa.w"

{
/*753:*/
#line 8177 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
const NSYID xsy_count= XSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
/*:753*/
#line 8115 "./marpa.w"

Current_Earleme_of_R(r)= 0;
/*759:*/
#line 8219 "./marpa.w"

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

/*:759*/
#line 8117 "./marpa.w"

G_EVENTS_CLEAR(g);
if(G_is_Trivial(g)){
/*599:*/
#line 6230 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:599*/
#line 8120 "./marpa.w"

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
/*810:*/
#line 8994 "./marpa.w"

r->t_bv_lim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_bv_pim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_pim_workarea= marpa_obs_new(r->t_obs,void*,nsy_count);
/*:810*//*829:*/
#line 9274 "./marpa.w"

r->t_lim_chain= marpa_obs_new(r->t_obs,void*,2*nsy_count);
/*:829*/
#line 8135 "./marpa.w"

/*768:*/
#line 8432 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_yim_work_stack))
{
MARPA_DSTACK_INIT2(r->t_yim_work_stack,YIM);
}
}
/*:768*//*772:*/
#line 8447 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_completion_stack))
{
MARPA_DSTACK_INIT2(r->t_completion_stack,YIM);
}
}
/*:772*/
#line 8136 "./marpa.w"

set0= earley_set_new(r,0);
Latest_YS_of_R(r)= set0;
First_YS_of_R(r)= set0;

start_irl= g->t_start_irl;
start_aim= First_AHM_of_IRL(start_irl);

key.t_origin= set0;
key.t_aim= start_aim;
key.t_set= set0;
earley_item_create(r,key);
bv_clear(r->t_bv_irl_is_predicted);
bv_bit_set(r->t_bv_irl_is_predicted,ID_of_IRL(start_irl));

{
int cil_ix;
const CIL prediction_cil= Predicted_IRL_CIL_of_AHM(start_aim);
const int prediction_count= Count_of_CIL(prediction_cil);
for(cil_ix= 0;cil_ix<prediction_count;cil_ix++)
{
const IRLID prediction_irlid= Item_of_CIL(prediction_cil,cil_ix);
if(!bv_bit_test_then_set(r->t_bv_irl_is_predicted,prediction_irlid)){
const IRL prediction_irl= IRL_by_ID(prediction_irlid);
const AHM prediction_aim= First_AHM_of_IRL(prediction_irl);
key.t_aim= prediction_aim;
if(1){earley_item_create(r,key);}
}
}
}

postdot_items_create(r,bv_ok_for_chain,set0);
earley_set_update_items(r,set0);
r->t_is_using_leo= r->t_use_leo_flag;
trigger_events(r);
CLEANUP:;
/*754:*/
#line 8181 "./marpa.w"

bv_free(bv_ok_for_chain);

/*:754*/
#line 8172 "./marpa.w"

}
return return_value;
}

/*:752*//*760:*/
#line 8259 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID tkn_xsy_id,
int value,
int length)
{
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 8266 "./marpa.w"

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
/*761:*/
#line 8288 "./marpa.w"
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

/*:761*/
#line 8281 "./marpa.w"

/*764:*/
#line 8348 "./marpa.w"

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

/*:764*/
#line 8282 "./marpa.w"

/*762:*/
#line 8328 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=JEARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return MARPA_ERR_PARSE_TOO_LONG;
}
}

/*:762*/
#line 8283 "./marpa.w"

/*765:*/
#line 8386 "./marpa.w"

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

/*:765*/
#line 8284 "./marpa.w"

return MARPA_ERR_NONE;
}

/*:760*//*778:*/
#line 8478 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 8482 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 8483 "./marpa.w"

YIM*cause_p;
YS current_earley_set;
JEARLEME current_earleme;




JEARLEME return_value= -2;

/*1273:*/
#line 14926 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1273*/
#line 8493 "./marpa.w"

{
int count_of_expected_terminals;
/*779:*/
#line 8536 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
struct marpa_obstack*const earleme_complete_obs= marpa_obs_init;
/*:779*/
#line 8496 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_nsyid_is_expected);
bv_clear(r->t_bv_irl_is_predicted);
/*781:*/
#line 8544 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*599:*/
#line 6230 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:599*/
#line 8548 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:781*/
#line 8501 "./marpa.w"

/*783:*/
#line 8566 "./marpa.w"
{
ALT end_of_stack= MARPA_DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!end_of_stack||current_earleme!=End_Earleme_of_ALT(end_of_stack))
{
return_value= 0;
goto CLEANUP;
}
}

/*:783*/
#line 8502 "./marpa.w"

/*782:*/
#line 8556 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_YS_of_YS(Latest_YS_of_R(r))= current_earley_set;
Latest_YS_of_R(r)= current_earley_set;
}

/*:782*/
#line 8503 "./marpa.w"

/*784:*/
#line 8575 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*785:*/
#line 8582 "./marpa.w"

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

{
const AHM predecessor_aim= AHM_of_YIM(predecessor);
const AHM scanned_aim= Next_AHM_of_AHM(predecessor_aim);
/*786:*/
#line 8602 "./marpa.w"

{
const YIM scanned_earley_item= earley_item_assign(r,
current_earley_set,
Origin_of_YIM
(predecessor),
scanned_aim);
tkn_link_add(r,scanned_earley_item,predecessor,tkn);
}

/*:786*/
#line 8597 "./marpa.w"

}
}
}

/*:785*/
#line 8579 "./marpa.w"

}

/*:784*/
#line 8504 "./marpa.w"

/*787:*/
#line 8612 "./marpa.w"
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

/*:787*/
#line 8505 "./marpa.w"

while((cause_p= MARPA_DSTACK_POP(r->t_completion_stack,YIM))){
YIM cause= *cause_p;
/*788:*/
#line 8632 "./marpa.w"

{
if(Earley_Item_is_Completion(cause))
{
NSYID complete_nsyid= LHS_NSYID_of_YIM(cause);
const YS middle= Origin_of_YIM(cause);
/*789:*/
#line 8642 "./marpa.w"

{
PIM postdot_item;
for(postdot_item= First_PIM_of_YS_by_NSYID(middle,complete_nsyid);
postdot_item;postdot_item= Next_PIM_of_PIM(postdot_item))
{
const YIM predecessor= YIM_of_PIM(postdot_item);
if(predecessor)
{
const AHM predecessor_aim= AHM_of_YIM(predecessor);
const AHM effect_aim= Next_AHM_of_AHM(predecessor_aim);
/*790:*/
#line 8666 "./marpa.w"

{
const YS origin= Origin_of_YIM(predecessor);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_aim);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*791:*/
#line 8680 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:791*/
#line 8674 "./marpa.w"

}
}
completion_link_add(r,effect,predecessor,cause);
}

/*:790*/
#line 8654 "./marpa.w"

}
else
{
/*792:*/
#line 8685 "./marpa.w"
{
const LIM leo_item= LIM_of_PIM(postdot_item);
const YS origin= Origin_of_LIM(leo_item);
const AHM effect_aim= Top_AHM_of_LIM(leo_item);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_aim);
if(Earley_Item_has_No_Source(effect))
{

/*791:*/
#line 8680 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:791*/
#line 8694 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:792*/
#line 8658 "./marpa.w"

break;


}
}
}

/*:789*/
#line 8638 "./marpa.w"

}
}

/*:788*/
#line 8508 "./marpa.w"

}
/*793:*/
#line 8701 "./marpa.w"

{
int ix;
const int no_of_work_earley_items= MARPA_DSTACK_LENGTH(r->t_yim_work_stack);
for(ix= 0;ix<no_of_work_earley_items;ix++)
{
YIM earley_item= WORK_YIM_ITEM(r,ix);

if(1)
{
int cil_ix;
const AHM aim= AHM_of_YIM(earley_item);
const CIL prediction_cil= Predicted_IRL_CIL_of_AHM(aim);
const int prediction_count= Count_of_CIL(prediction_cil);
for(cil_ix= 0;cil_ix<prediction_count;cil_ix++)
{
const IRLID prediction_irlid= 
Item_of_CIL(prediction_cil,cil_ix);
const IRL prediction_irl= IRL_by_ID(prediction_irlid);
const AHM prediction_aim= First_AHM_of_IRL(prediction_irl);
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_aim);
}
}

}
}

/*:793*/
#line 8510 "./marpa.w"

postdot_items_create(r,bv_ok_for_chain,current_earley_set);




count_of_expected_terminals= bv_count(r->t_bv_nsyid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_YS(current_earley_set)>=Furthest_Earleme_of_R(r))
{
/*599:*/
#line 6230 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:599*/
#line 8520 "./marpa.w"

}
earley_set_update_items(r,current_earley_set);
if(r->t_active_event_count> 0){
trigger_events(r);
}
return_value= G_EVENT_COUNT(g);
CLEANUP:;
/*780:*/
#line 8540 "./marpa.w"

bv_free(bv_ok_for_chain);
marpa_obs_free(earleme_complete_obs);

/*:780*/
#line 8528 "./marpa.w"

}
return return_value;
}

/*:778*//*794:*/
#line 8729 "./marpa.w"

PRIVATE void trigger_events(RECCE r)
{
const GRAMMAR g= G_of_R(r);
const YS current_earley_set= Latest_YS_of_R(r);
int min,max,start;
int yim_ix;
struct marpa_obstack*const trigger_events_obs= marpa_obs_init;
const YIM*yims= YIMs_of_YS(current_earley_set);
const XSYID xsy_count= XSY_Count_of_G(g);
const int aim_count= AHM_Count_of_G(g);
Bit_Vector bv_completion_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_nulled_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_prediction_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_aim_event_trigger= 
bv_obs_create(trigger_events_obs,aim_count);
const int working_earley_item_count= YIM_Count_of_YS(current_earley_set);
for(yim_ix= 0;yim_ix<working_earley_item_count;yim_ix++)
{
const YIM yim= yims[yim_ix];
const AHM root_aim= AHM_of_YIM(yim);
if(AHM_has_Event(root_aim))
{

bv_bit_set(bv_aim_event_trigger,ID_of_AHM(root_aim));
}
{

const SRCL first_leo_source_link= First_Leo_SRCL_of_YIM(yim);
SRCL setup_source_link;
for(setup_source_link= first_leo_source_link;setup_source_link;
setup_source_link= Next_SRCL_of_SRCL(setup_source_link))
{
int cil_ix;
const LIM lim= LIM_of_SRCL(setup_source_link);
const CIL event_aimids= CIL_of_LIM(lim);
const int event_aim_count= Count_of_CIL(event_aimids);
for(cil_ix= 0;cil_ix<event_aim_count;cil_ix++)
{
const NSYID leo_path_aimid= 
Item_of_CIL(event_aimids,cil_ix);
bv_bit_set(bv_aim_event_trigger,leo_path_aimid);


}
}
}
}

for(start= 0;bv_scan(bv_aim_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_aimid;
for(event_aimid= (NSYID)min;event_aimid<=(NSYID)max;
event_aimid++)
{
int cil_ix;
const AHM event_aim= AHM_by_ID(event_aimid);
{
const CIL completion_xsyids= 
Completion_XSYIDs_of_AHM(event_aim);
const int event_xsy_count= Count_of_CIL(completion_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(completion_xsyids,cil_ix);
bv_bit_set(bv_completion_event_trigger,event_xsyid);
}
}
{
const CIL nulled_xsyids= Nulled_XSYIDs_of_AHM(event_aim);
const int event_xsy_count= Count_of_CIL(nulled_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(nulled_xsyids,cil_ix);
bv_bit_set(bv_nulled_event_trigger,event_xsyid);
}
}
{
const CIL prediction_xsyids= 
Prediction_XSYIDs_of_AHM(event_aim);
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

/*:794*//*795:*/
#line 8868 "./marpa.w"

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

/*:795*//*796:*/
#line 8897 "./marpa.w"

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

/*:796*//*812:*/
#line 9001 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,
Bit_Vector bv_ok_for_chain,
const YS current_earley_set)
{
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 9007 "./marpa.w"

/*811:*/
#line 8998 "./marpa.w"

bv_clear(r->t_bv_lim_symbols);
bv_clear(r->t_bv_pim_symbols);
/*:811*/
#line 9008 "./marpa.w"

/*813:*/
#line 9020 "./marpa.w"
{

YIM*work_earley_items= MARPA_DSTACK_BASE(r->t_yim_work_stack,YIM);
int no_of_work_earley_items= MARPA_DSTACK_LENGTH(r->t_yim_work_stack);
int ix;
for(ix= 0;
ix<no_of_work_earley_items;
ix++)
{
YIM earley_item= work_earley_items[ix];
AHM aim= AHM_of_YIM(earley_item);
const NSYID postdot_nsyid= Postdot_NSYID_of_AHM(aim);
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

/*:813*/
#line 9009 "./marpa.w"

if(r->t_is_using_leo){
/*815:*/
#line 9063 "./marpa.w"

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
AHM potential_leo_penult_aim= NULL;
const AHM leo_base_aim= AHM_of_YIM(leo_base);
const IRL leo_base_irl= IRL_of_AHM(leo_base_aim);

if(!IRL_is_Leo(leo_base_irl))
goto NEXT_NSYID;
potential_leo_penult_aim= leo_base_aim;
MARPA_ASSERT(potential_leo_penult_aim);
{
const AHM base_to_aim= 
Next_AHM_of_AHM(potential_leo_penult_aim);
if(AHM_is_Leo_Completion(base_to_aim))
{
/*816:*/
#line 9107 "./marpa.w"
{
LIM new_lim;
new_lim= marpa_obs_new(r->t_obs,LIM_Object,1);
Postdot_NSYID_of_LIM(new_lim)= nsyid;
YIM_of_PIM(new_lim)= NULL;
Predecessor_LIM_of_LIM(new_lim)= NULL;
Origin_of_LIM(new_lim)= NULL;
CIL_of_LIM(new_lim)= NULL;
Top_AHM_of_LIM(new_lim)= base_to_aim;
Base_to_AHM_of_LIM(new_lim)= base_to_aim;
Base_YIM_of_LIM(new_lim)= leo_base;
YS_of_LIM(new_lim)= current_earley_set;
Next_PIM_of_LIM(new_lim)= this_pim;
r->t_pim_workarea[nsyid]= new_lim;
bv_bit_set(r->t_bv_lim_symbols,nsyid);
}

/*:816*/
#line 9092 "./marpa.w"

}
}
}
NEXT_NSYID:;
}
}
}

/*:815*/
#line 9011 "./marpa.w"

/*825:*/
#line 9193 "./marpa.w"
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

/*827:*/
#line 9249 "./marpa.w"

{
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHM base_to_aim= Base_to_AHM_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
LHSID_of_AHM(base_to_aim);
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

/*:827*/
#line 9210 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*835:*/
#line 9366 "./marpa.w"

{
const AHM new_top_aim= Top_AHM_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);


CIL_of_LIM(lim_to_process)= predecessor_cil;
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHM(new_top_aim)> Count_of_CIL(predecessor_cil))
{
const AHM base_to_aim= Base_to_AHM_of_LIM(lim_to_process);
const CIL base_to_aim_event_aimids= 
Event_AHMIDs_of_AHM(base_to_aim);
if(Count_of_CIL(base_to_aim_event_aimids))
{
CIL new_cil= cil_merge_one(&g->t_cilar,predecessor_cil,
Item_of_CIL
(base_to_aim_event_aimids,0));
if(new_cil)
{
CIL_of_LIM(lim_to_process)= new_cil;
}
}
}
Top_AHM_of_LIM(lim_to_process)= new_top_aim;
}

/*:835*/
#line 9212 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*837:*/
#line 9406 "./marpa.w"
{
const AHM base_to_aim= Base_to_AHM_of_LIM(lim_to_process);
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHMIDs_of_AHM(base_to_aim);
}

/*:837*/
#line 9218 "./marpa.w"

continue;
}
/*830:*/
#line 9276 "./marpa.w"
{
int lim_chain_ix;
/*833:*/
#line 9296 "./marpa.w"

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

/*827:*/
#line 9249 "./marpa.w"

{
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHM base_to_aim= Base_to_AHM_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
LHSID_of_AHM(base_to_aim);
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

/*:827*/
#line 9328 "./marpa.w"


r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,
postdot_nsyid_of_lim_to_process);




if(!predecessor_lim)
break;
if(LIM_is_Populated(predecessor_lim))
break;



}
}

/*:833*/
#line 9278 "./marpa.w"

/*834:*/
#line 9349 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= r->t_lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*835:*/
#line 9366 "./marpa.w"

{
const AHM new_top_aim= Top_AHM_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);


CIL_of_LIM(lim_to_process)= predecessor_cil;
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHM(new_top_aim)> Count_of_CIL(predecessor_cil))
{
const AHM base_to_aim= Base_to_AHM_of_LIM(lim_to_process);
const CIL base_to_aim_event_aimids= 
Event_AHMIDs_of_AHM(base_to_aim);
if(Count_of_CIL(base_to_aim_event_aimids))
{
CIL new_cil= cil_merge_one(&g->t_cilar,predecessor_cil,
Item_of_CIL
(base_to_aim_event_aimids,0));
if(new_cil)
{
CIL_of_LIM(lim_to_process)= new_cil;
}
}
}
Top_AHM_of_LIM(lim_to_process)= new_top_aim;
}

/*:835*/
#line 9353 "./marpa.w"

}else{
/*837:*/
#line 9406 "./marpa.w"
{
const AHM base_to_aim= Base_to_AHM_of_LIM(lim_to_process);
const YIM base_yim= Base_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHMIDs_of_AHM(base_to_aim);
}

/*:837*/
#line 9355 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:834*/
#line 9279 "./marpa.w"

}

/*:830*/
#line 9221 "./marpa.w"

}
}
}

/*:825*/
#line 9012 "./marpa.w"

}
/*838:*/
#line 9413 "./marpa.w"
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

/*:838*/
#line 9014 "./marpa.w"

bv_and(r->t_bv_nsyid_is_expected,r->t_bv_pim_symbols,g->t_bv_nsyid_is_terminal);
}

/*:812*//*857:*/
#line 9588 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
stack->t_obs= marpa_obs_init;
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:857*//*858:*/
#line 9596 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:858*//*859:*/
#line 9602 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)marpa_obs_free(stack->t_obs);
stack->t_base= NULL;
}

/*:859*//*860:*/
#line 9609 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= marpa_obs_new(stack->t_obs,UR_Object,1);
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:860*//*861:*/
#line 9619 "./marpa.w"

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

/*:861*//*862:*/
#line 9635 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:862*//*866:*/
#line 9696 "./marpa.w"

PRIVATE int psia_test_and_set(
struct marpa_obstack*obs,
struct s_bocage_setup_per_ys*per_ys_data,
YIM earley_item,
AEX ahfa_element_ix)
{
const Marpa_Earley_Set_ID set_ordinal= YS_Ord_of_YIM(earley_item);
OR**nodes_by_item= per_ys_data[set_ordinal].t_aexes_by_item;
const int item_ordinal= Ord_of_YIM(earley_item);
OR*nodes_by_aex= nodes_by_item[item_ordinal];
if(!nodes_by_aex){
nodes_by_aex= nodes_by_item[item_ordinal]= 
marpa_obs_new(obs,OR,1);
nodes_by_aex[0]= NULL;
}
if(!nodes_by_aex[ahfa_element_ix]){
nodes_by_aex[ahfa_element_ix]= dummy_or_node;
return 0;
}
return 1;
}

/*:866*//*868:*/
#line 9763 "./marpa.w"

PRIVATE int
Set_boolean_in_PSIA_for_initial_nulls(struct marpa_obstack*bocage_setup_obs,
struct s_bocage_setup_per_ys
*per_ys_data,YIM yim,AHM aim)
{
int null_count= 0;
if(Position_of_AHM(aim)> 0)
{
null_count= Null_Count_of_AHM(aim);
if(null_count)
{

const int aex= 0;
psia_test_and_set(bocage_setup_obs,per_ys_data,(yim),aex);
}
}
return null_count;
}

/*:868*//*907:*/
#line 10356 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10361 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 10362 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10363 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10364 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10365 "./marpa.w"

return YS_Ord_of_OR(or_node);
}

/*:907*//*908:*/
#line 10369 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10374 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 10375 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10376 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10377 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10378 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:908*//*909:*/
#line 10382 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10387 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 10388 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10389 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10390 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10391 "./marpa.w"

return ID_of_IRL(IRL_of_OR(or_node));
}

/*:909*//*910:*/
#line 10395 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10400 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 10401 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10402 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10403 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10404 "./marpa.w"

return Position_of_OR(or_node);
}

/*:910*//*911:*/
#line 10408 "./marpa.w"

int _marpa_b_or_node_is_whole(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10413 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 10414 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10415 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10416 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10417 "./marpa.w"

return Position_of_OR(or_node)>=Length_of_IRL(IRL_of_OR(or_node))?1:0;
}

/*:911*//*912:*/
#line 10421 "./marpa.w"

int _marpa_b_or_node_is_semantic(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10426 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 10427 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10428 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10429 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10430 "./marpa.w"

return!IRL_has_Virtual_LHS(IRL_of_OR(or_node));
}

/*:912*//*913:*/
#line 10434 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10439 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 10440 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10441 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10442 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10443 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:913*//*914:*/
#line 10447 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10452 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 10453 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10454 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10455 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10456 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:914*//*915:*/
#line 10461 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10466 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 10467 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10468 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10469 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10470 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:915*//*918:*/
#line 10484 "./marpa.w"

int _marpa_o_or_node_and_node_count(Marpa_Order o,
Marpa_Or_Node_ID or_node_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10488 "./marpa.w"

/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 10489 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10490 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10491 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[0];
}
{
OR or_node;
/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10500 "./marpa.w"

return AND_Count_of_OR(or_node);
}
}

/*:918*//*919:*/
#line 10505 "./marpa.w"

int _marpa_o_or_node_and_node_id_by_ix(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 10509 "./marpa.w"

/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 10510 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 10511 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 10512 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[1+ix];
}
{
OR or_node;
/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 10521 "./marpa.w"

return First_ANDID_of_OR(or_node)+ix;
}
}

/*:919*//*923:*/
#line 10569 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct marpa_obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= marpa_obs_new(obs,DAND_Object,1);
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:923*//*925:*/
#line 10592 "./marpa.w"

PRIVATE
void draft_and_node_add(struct marpa_obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:925*//*952:*/
#line 11007 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11010 "./marpa.w"

/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11011 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11012 "./marpa.w"

return AND_Count_of_B(b);
}

/*:952*//*954:*/
#line 11038 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11043 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11044 "./marpa.w"

/*953:*/
#line 11016 "./marpa.w"

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

/*:953*/
#line 11045 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:954*//*955:*/
#line 11049 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11054 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11055 "./marpa.w"

/*953:*/
#line 11016 "./marpa.w"

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

/*:953*/
#line 11056 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:955*//*956:*/
#line 11065 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11070 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11071 "./marpa.w"

/*953:*/
#line 11016 "./marpa.w"

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

/*:953*/
#line 11072 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:956*//*957:*/
#line 11081 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11086 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11087 "./marpa.w"

/*953:*/
#line 11016 "./marpa.w"

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

/*:953*/
#line 11088 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const XSYID symbol_id= 
OR_is_Token(cause_or)?NSYID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:957*//*958:*/
#line 11097 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK tkn;
AND and_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11103 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11104 "./marpa.w"

/*953:*/
#line 11016 "./marpa.w"

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

/*:953*/
#line 11105 "./marpa.w"

tkn= and_node_token(and_node);
if(tkn){
if(value_p)
*value_p= Value_of_TOK(tkn);
return NSYID_of_TOK(tkn);
}
return-1;
}
/*:958*//*959:*/
#line 11114 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:959*//*960:*/
#line 11132 "./marpa.w"

Marpa_Earley_Set_ID _marpa_b_and_node_middle(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11137 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11138 "./marpa.w"

/*953:*/
#line 11016 "./marpa.w"

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

/*:953*/
#line 11139 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
if(predecessor_or)
{
return YS_Ord_of_OR(predecessor_or);
}
}
return Origin_Ord_of_OR(OR_of_AND(and_node));
}

/*:960*//*969:*/
#line 11185 "./marpa.w"

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

/*:969*//*970:*/
#line 11202 "./marpa.w"

int marpa_r_progress_report_start(
Marpa_Recognizer r,
Marpa_Earley_Set_ID set_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11207 "./marpa.w"

YS earley_set;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 11209 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11210 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 11211 "./marpa.w"

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
/*964:*/
#line 11159 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:964*/
#line 11224 "./marpa.w"

{
const MARPA_AVL_TREE report_tree= 
_marpa_avl_create(report_item_cmp,NULL);
const YIM*const earley_items= YIMs_of_YS(earley_set);
const int earley_item_count= YIM_Count_of_YS(earley_set);
int earley_item_id;
for(earley_item_id= 0;earley_item_id<earley_item_count;
earley_item_id++)
{
/*972:*/
#line 11254 "./marpa.w"

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
AHM report_aim;
while(1)
{
const int phase= next_phase;
if(phase==initial_phase)
{
report_origin= Origin_Ord_of_YIM(earley_item);
report_aim= AHM_of_YIM(earley_item);
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
report_aim= Base_to_AHM_of_LIM(leo_item);
next_leo_item= Predecessor_LIM_of_LIM(leo_item);
goto INSERT_ITEMS_INTO_TREE;
}
}
NEXT_PHASE:;
}
INSERT_ITEMS_INTO_TREE:
/*973:*/
#line 11315 "./marpa.w"

{
const IRL irl= IRL_of_AHM(report_aim);
const XRL source_xrl= Source_XRL_of_IRL(irl);
if(source_xrl)
{
const int irl_position= Position_of_AHM(report_aim);
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
if(irl_position<=0)
goto NEXT_AHM;
xrl_position= -1;
}
else
{
xrl_position= irl_position> 0?-1:0;
}
}
{
const PROGRESS new_report_item= 
marpa_obs_new(MARPA_AVL_OBSTACK(report_tree),
struct marpa_progress_item,
1);
Position_of_PROGRESS(new_report_item)= xrl_position;
Origin_of_PROGRESS(new_report_item)= report_origin;
RULEID_of_PROGRESS(new_report_item)= ID_of_XRL(source_xrl);
_marpa_avl_insert(report_tree,new_report_item);
}
}
NEXT_AHM:;
}

/*:973*/
#line 11310 "./marpa.w"

}
NEXT_EARLEY_ITEM:;
}

/*:972*/
#line 11234 "./marpa.w"

}
r->t_progress_report_traverser= _marpa_avl_t_init(report_tree);
return(int)marpa_avl_count(report_tree);
}
}
/*:970*//*971:*/
#line 11241 "./marpa.w"

int marpa_r_progress_report_reset(Marpa_Recognizer r)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11244 "./marpa.w"

MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 11246 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11247 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 11248 "./marpa.w"

/*976:*/
#line 11392 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:976*/
#line 11249 "./marpa.w"

_marpa_avl_t_reset(traverser);
return 1;
}

/*:971*//*974:*/
#line 11355 "./marpa.w"

int marpa_r_progress_report_finish(Marpa_Recognizer r){
const int success= 1;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11358 "./marpa.w"

/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 11359 "./marpa.w"

const MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*976:*/
#line 11392 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:976*/
#line 11361 "./marpa.w"

/*964:*/
#line 11159 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:964*/
#line 11362 "./marpa.w"

return success;
}

/*:974*//*975:*/
#line 11366 "./marpa.w"

Marpa_Rule_ID marpa_r_progress_item(
Marpa_Recognizer r,int*position,Marpa_Earley_Set_ID*origin
){
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11370 "./marpa.w"

PROGRESS report_item;
MARPA_AVL_TRAV traverser;
/*549:*/
#line 5775 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:549*/
#line 11373 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11374 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 11375 "./marpa.w"

traverser= r->t_progress_report_traverser;
if(_MARPA_UNLIKELY(!position||!origin)){
MARPA_ERROR(MARPA_ERR_POINTER_ARG_NULL);
return failure_indicator;
}
/*976:*/
#line 11392 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:976*/
#line 11381 "./marpa.w"

report_item= _marpa_avl_t_next(traverser);
if(!report_item){
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_EXHAUSTED);
return-1;
}
*position= Position_of_PROGRESS(report_item);
*origin= Origin_of_PROGRESS(report_item);
return RULEID_of_PROGRESS(report_item);
}

/*:975*//*986:*/
#line 11436 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1258:*/
#line 14838 "./marpa.w"
void*const failure_indicator= NULL;
/*:1258*/
#line 11440 "./marpa.w"

/*989:*/
#line 11498 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int nsy_count= NSY_Count_of_G(g);
const int xsy_count= XSY_Count_of_G(g);
const IRLID irl_count= IRL_Count_of_G(g);
BOCAGE b= NULL;
YS end_of_parse_earley_set;
JEARLEME end_of_parse_earleme;
YIM start_yim= NULL;
const AEX start_aex= 0;
struct marpa_obstack*bocage_setup_obs= NULL;
int count_of_earley_items_in_parse;
const int earley_set_count_of_r= YS_Count_of_R(r);

/*:989*//*992:*/
#line 11520 "./marpa.w"

struct s_bocage_setup_per_ys*per_ys_data= NULL;

/*:992*/
#line 11441 "./marpa.w"

INPUT input;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11443 "./marpa.w"

/*1272:*/
#line 14921 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1272*/
#line 11444 "./marpa.w"

{
struct marpa_obstack*const obstack= marpa_obs_init;
b= marpa_obs_new(obstack,struct marpa_bocage,1);
OBS_of_B(b)= obstack;
}
/*889:*/
#line 10021 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:889*//*988:*/
#line 11493 "./marpa.w"

Valued_BV_of_B(b)= lbv_clone(b->t_obs,r->t_valued,xsy_count);
Valued_Locked_BV_of_B(b)= 
lbv_clone(b->t_obs,r->t_valued_locked,xsy_count);

/*:988*//*1002:*/
#line 11638 "./marpa.w"

Ambiguity_Metric_of_B(b)= 1;

/*:1002*//*1006:*/
#line 11652 "./marpa.w"

b->t_ref_count= 1;
/*:1006*//*1013:*/
#line 11712 "./marpa.w"

B_is_Nulling(b)= 0;
/*:1013*/
#line 11450 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*993:*/
#line 11523 "./marpa.w"

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

/*:993*/
#line 11460 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(XSY_by_ID(g->t_start_xsy_id)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*996:*/
#line 11588 "./marpa.w"

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
const AHM aim= AHM_of_YIM(earley_item);
if(IRLID_of_AHM(aim)==sought_irl_id){
start_yim= earley_item;
break;
}
}
}
}

/*:996*/
#line 11468 "./marpa.w"

if(!start_yim)goto NO_PARSE;
bocage_setup_obs= marpa_obs_init;
/*994:*/
#line 11545 "./marpa.w"

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

/*:994*/
#line 11471 "./marpa.w"

/*864:*/
#line 9657 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const YIM ur_earley_item= start_yim;
/*865:*/
#line 9684 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:865*/
#line 9664 "./marpa.w"

}
while((ur_node= ur_node_pop(ur_node_stack)))
{
const YIM_Const parent_earley_item= YIM_of_UR(ur_node);
const AHM parent_aim= AHM_of_YIM(parent_earley_item);
MARPA_ASSERT(parent_aim>=AHM_by_ID(1))
const AHM predecessor_aim= parent_aim-1;


unsigned int source_type= Source_Type_of_YIM(parent_earley_item);
MARPA_ASSERT(!YIM_was_Predicted(parent_earley_item))
/*867:*/
#line 9719 "./marpa.w"

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
if(YIM_was_Predicted(predecessor_earley_item))
{
Set_boolean_in_PSIA_for_initial_nulls(bocage_setup_obs,per_ys_data,
predecessor_earley_item,
predecessor_aim);
}
else
{
const YIM ur_earley_item= predecessor_earley_item;
/*865:*/
#line 9684 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:865*/
#line 9749 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:867*/
#line 9676 "./marpa.w"

/*869:*/
#line 9783 "./marpa.w"

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
if(YIM_was_Predicted(predecessor_earley_item))
{
Set_boolean_in_PSIA_for_initial_nulls
(bocage_setup_obs,per_ys_data,
predecessor_earley_item,predecessor_aim);
}
else
{
const YIM ur_earley_item= predecessor_earley_item;
/*865:*/
#line 9684 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:865*/
#line 9817 "./marpa.w"

}
}
{
const YIM ur_earley_item= cause_earley_item;

/*865:*/
#line 9684 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:865*/
#line 9823 "./marpa.w"

}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:869*/
#line 9677 "./marpa.w"

/*870:*/
#line 9833 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
const YIM cause_earley_item= Cause_of_SRCL(source_link);
LIM leo_predecessor= LIM_of_SRCL(source_link);
{
const YIM ur_earley_item= cause_earley_item;

/*865:*/
#line 9684 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:865*/
#line 9844 "./marpa.w"

}
while(leo_predecessor)
{
const YIM leo_base_yim= Base_YIM_of_LIM(leo_predecessor);
if(YIM_was_Predicted(leo_base_yim))
{
const AHM leo_final_aim= Base_to_AHM_of_LIM(leo_predecessor);
const AHM prediction_aim= Prev_AHM_of_AHM(leo_final_aim);
Set_boolean_in_PSIA_for_initial_nulls(bocage_setup_obs,per_ys_data,
leo_base_yim,prediction_aim);
}
else
{
const YIM ur_earley_item= leo_base_yim;
/*865:*/
#line 9684 "./marpa.w"
{
if(!psia_test_and_set
(bocage_setup_obs,per_ys_data,ur_earley_item,0))
{
ur_node_push(ur_node_stack,ur_earley_item,0);
}
}

/*:865*/
#line 9859 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
}
}

/*:870*/
#line 9678 "./marpa.w"

}
}

/*:864*/
#line 11472 "./marpa.w"

/*891:*/
#line 10039 "./marpa.w"

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
/*1253:*/
#line 14777 "./marpa.w"

{
PSL*psl_owner= &per_ys_data[psl_ys_ord].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
claimed_psl= *psl_owner;
}

/*:1253*/
#line 10061 "./marpa.w"

this_earley_set_psl= claimed_psl;
}
/*892:*/
#line 10071 "./marpa.w"

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
const AEX work_aex= 0;
const int work_origin_ordinal= 
Ord_of_YS(Origin_of_YIM(work_earley_item));
if(work_nodes_by_aex[work_aex])
{
/*893:*/
#line 10095 "./marpa.w"

{
AHM aim= AHM_of_YIM(work_earley_item);
SYMI aim_symbol_instance;
OR psia_or_node= NULL;
aim_symbol_instance= SYMI_of_AHM(aim);
{
PSL or_psl;
{
const int psl_ys_ord= work_origin_ordinal;
PSL claimed_psl;
/*1253:*/
#line 14777 "./marpa.w"

{
PSL*psl_owner= &per_ys_data[psl_ys_ord].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
claimed_psl= *psl_owner;
}

/*:1253*/
#line 10106 "./marpa.w"

or_psl= claimed_psl;
}
/*895:*/
#line 10126 "./marpa.w"

{
if(aim_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(aim_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,aim_symbol_instance);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const IRL irl= IRL_of_AHM(aim);
/*896:*/
#line 10156 "./marpa.w"

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


/*:896*/
#line 10136 "./marpa.w"

or_node= last_or_node;
PSL_Datum(or_psl,aim_symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= Origin_Ord_of_YIM(work_earley_item);
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= irl;
Position_of_OR(or_node)= 
aim_symbol_instance-SYMI_of_IRL(irl)+1;
DANDs_of_OR(or_node)= NULL;
}
psia_or_node= or_node;
}
}

/*:895*/
#line 10109 "./marpa.w"

/*898:*/
#line 10180 "./marpa.w"

{
const int null_count= Null_Count_of_AHM(aim);
if(null_count> 0)
{
const IRL irl= IRL_of_AHM(aim);
const int symbol_instance_of_rule= SYMI_of_IRL(irl);
const int first_null_symbol_instance= 
aim_symbol_instance<
0?symbol_instance_of_rule:aim_symbol_instance+1;
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
/*896:*/
#line 10156 "./marpa.w"

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


/*:896*/
#line 10200 "./marpa.w"

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

/*:898*/
#line 10110 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*899:*/
#line 10218 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*901:*/
#line 10240 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_YS(YS_of_LIM(this_leo_item));
const AHM path_aim= Base_to_AHM_of_LIM(previous_leo_item);
const IRL path_irl= IRL_of_AHM(path_aim);
const int symbol_instance_of_path_aim= SYMI_of_AHM(path_aim);
/*902:*/
#line 10259 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
{
const int psl_ys_ord= ordinal_of_set_of_this_leo_item;
PSL claimed_psl;
/*1253:*/
#line 14777 "./marpa.w"

{
PSL*psl_owner= &per_ys_data[psl_ys_ord].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
claimed_psl= *psl_owner;
}

/*:1253*/
#line 10267 "./marpa.w"

leo_psl= claimed_psl;
}
or_node= PSL_Datum(leo_psl,symbol_instance_of_path_aim);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*896:*/
#line 10156 "./marpa.w"

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


/*:896*/
#line 10273 "./marpa.w"

PSL_Datum(leo_psl,symbol_instance_of_path_aim)= or_node= 
last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= 
symbol_instance_of_path_aim-SYMI_of_IRL(path_irl)+1;
DANDs_of_OR(or_node)= NULL;
}
}
}

/*:902*/
#line 10250 "./marpa.w"

/*903:*/
#line 10290 "./marpa.w"

{
int i;
const int null_count= Null_Count_of_AHM(path_aim);
for(i= 1;i<=null_count;i++)
{
const int symbol_instance= symbol_instance_of_path_aim+i;
OR or_node= PSL_Datum(this_earley_set_psl,symbol_instance);
MARPA_ASSERT(symbol_instance<SYMI_Count_of_G(g))
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
DAND draft_and_node;
const int rhs_ix= symbol_instance-SYMI_of_IRL(path_irl);
MARPA_ASSERT(rhs_ix<Length_of_IRL(path_irl))
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= Nulling_OR_by_NSYID(RHSID_of_IRL(path_irl,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_IRL(path_irl))
MARPA_ASSERT(symbol_instance>=0)
/*896:*/
#line 10156 "./marpa.w"

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


/*:896*/
#line 10308 "./marpa.w"

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

/*:903*/
#line 10251 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:901*/
#line 10226 "./marpa.w"

}
}
}

/*:899*/
#line 10118 "./marpa.w"

}

/*:893*/
#line 10089 "./marpa.w"

}
}
}
}

/*:892*/
#line 10064 "./marpa.w"

/*926:*/
#line 10602 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const nodes_by_aex= nodes_by_item[item_ordinal];
if(nodes_by_aex){
const YIM work_earley_item= yims_of_ys[item_ordinal];
const int work_origin_ordinal= Ord_of_YS(Origin_of_YIM(work_earley_item));
const AEX work_aex= 0;
OR or_node= nodes_by_aex[work_aex];
/*927:*/
#line 10623 "./marpa.w"

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

/*:927*/
#line 10613 "./marpa.w"

if(or_node){
/*928:*/
#line 10637 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_YIM(work_earley_item);
const AHM work_aim= AHM_of_YIM(work_earley_item);
MARPA_ASSERT(work_aim>=AHM_by_ID(1))
const AHM work_predecessor_aim= work_aim-1;
const int work_symbol_instance= SYMI_of_AHM(work_aim);
OR work_proper_or_node;
{
const int origin= work_origin_ordinal;
const SYMI symbol_instance= work_symbol_instance;
OR*const p_or_node= &work_proper_or_node;
/*932:*/
#line 10706 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:932*/
#line 10649 "./marpa.w"

}
/*929:*/
#line 10656 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM cause_earley_item= Cause_of_SRCL(source_link);
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*930:*/
#line 10671 "./marpa.w"

{

IRL path_irl= NULL;

IRL previous_path_irl;
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
OR dand_predecessor;
OR path_or_node;
YIM base_earley_item= Base_YIM_of_LIM(path_leo_item);
Set_OR_from_YIM(dand_predecessor,base_earley_item);
/*931:*/
#line 10697 "./marpa.w"

{
if(higher_path_leo_item){
/*935:*/
#line 10735 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AHM aim= AHM_of_YIM(base_earley_item);
path_irl= IRL_of_AHM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
{
OR*const p_or_node= &path_or_node;
const int origin= origin_ordinal;
/*932:*/
#line 10706 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:932*/
#line 10745 "./marpa.w"

}
}

/*:935*/
#line 10700 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:931*/
#line 10683 "./marpa.w"

/*933:*/
#line 10712 "./marpa.w"

{
OR dand_cause;

Set_OR_from_YIM(dand_cause,cause_earley_item);
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:933*/
#line 10684 "./marpa.w"

previous_path_irl= path_irl;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_earley_item= Base_YIM_of_LIM(path_leo_item);
Set_OR_from_YIM(dand_predecessor,base_earley_item);
/*931:*/
#line 10697 "./marpa.w"

{
if(higher_path_leo_item){
/*935:*/
#line 10735 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AHM aim= AHM_of_YIM(base_earley_item);
path_irl= IRL_of_AHM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
{
OR*const p_or_node= &path_or_node;
const int origin= origin_ordinal;
/*932:*/
#line 10706 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:932*/
#line 10745 "./marpa.w"

}
}

/*:935*/
#line 10700 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:931*/
#line 10691 "./marpa.w"

/*936:*/
#line 10749 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_IRL(previous_path_irl);
const int origin= Ord_of_YS(YS_of_LIM(path_leo_item));
OR*const p_or_node= &dand_cause;
/*932:*/
#line 10706 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:932*/
#line 10755 "./marpa.w"

draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:936*/
#line 10692 "./marpa.w"

previous_path_irl= path_irl;
}
}

/*:930*/
#line 10665 "./marpa.w"

}
}
}

/*:929*/
#line 10651 "./marpa.w"

/*937:*/
#line 10760 "./marpa.w"

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
/*938:*/
#line 10790 "./marpa.w"

{
OR dand_predecessor;
/*939:*/
#line 10798 "./marpa.w"

{
if(Position_of_AHM(work_predecessor_aim)<1)
{
dand_predecessor= NULL;
}
else
{
Set_OR_from_YIM(dand_predecessor,predecessor_earley_item);
}
}

/*:939*/
#line 10793 "./marpa.w"

draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)tkn);
}

/*:938*/
#line 10782 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
tkn= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:937*/
#line 10652 "./marpa.w"

/*940:*/
#line 10810 "./marpa.w"

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
/*941:*/
#line 10841 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_YIM(cause_earley_item);

const AHM cause_aim= AHM_of_YIM(cause_earley_item);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_IRL(IRL_of_AHM(cause_aim));
/*939:*/
#line 10798 "./marpa.w"

{
if(Position_of_AHM(work_predecessor_aim)<1)
{
dand_predecessor= NULL;
}
else
{
Set_OR_from_YIM(dand_predecessor,predecessor_earley_item);
}
}

/*:939*/
#line 10850 "./marpa.w"

{
const int origin= middle_ordinal;
const SYMI symbol_instance= cause_symbol_instance;
OR*const p_or_node= &dand_cause;
/*932:*/
#line 10706 "./marpa.w"

{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
(*p_or_node)= PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:932*/
#line 10855 "./marpa.w"

}
draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:941*/
#line 10833 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:940*/
#line 10653 "./marpa.w"

}

/*:928*/
#line 10615 "./marpa.w"

}
}
}
}

/*:926*/
#line 10065 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= marpa_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:891*/
#line 11473 "./marpa.w"

/*949:*/
#line 10961 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*942:*/
#line 10861 "./marpa.w"

{
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_ys_arena;
const PSAR and_psar= &and_per_ys_arena;
int or_node_id= 0;
psar_init(and_psar,irl_count+nsy_count);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
/*944:*/
#line 10892 "./marpa.w"

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

/*:944*/
#line 10870 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:942*/
#line 10964 "./marpa.w"

/*950:*/
#line 10968 "./marpa.w"

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

/*:950*/
#line 10965 "./marpa.w"

}

/*:949*/
#line 11474 "./marpa.w"

/*997:*/
#line 11609 "./marpa.w"

{
const YSID end_of_parse_ordinal= Ord_of_YS(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_ys_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_YIM(start_yim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR root_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(root_or_node);
}

/*:997*/
#line 11475 "./marpa.w"
;
marpa_obs_free(bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
input_unref(input);
if(b){
/*1009:*/
#line 11688 "./marpa.w"

/*890:*/
#line 10028 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:890*/
#line 11689 "./marpa.w"
;
/*985:*/
#line 11432 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:985*/
#line 11690 "./marpa.w"
;

/*:1009*/
#line 11482 "./marpa.w"
;
}
return NULL;
}

/*:986*//*999:*/
#line 11622 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11625 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11626 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11627 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:999*//*1003:*/
#line 11641 "./marpa.w"

int marpa_b_ambiguity_metric(Marpa_Bocage b)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11644 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11645 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11646 "./marpa.w"

return Ambiguity_Metric_of_B(b);
}

/*:1003*//*1007:*/
#line 11655 "./marpa.w"

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

/*:1007*//*1008:*/
#line 11673 "./marpa.w"

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

/*:1008*//*1010:*/
#line 11695 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11699 "./marpa.w"

input_unref(input);
if(b)
{
/*1009:*/
#line 11688 "./marpa.w"

/*890:*/
#line 10028 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:890*/
#line 11689 "./marpa.w"
;
/*985:*/
#line 11432 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:985*/
#line 11690 "./marpa.w"
;

/*:1009*/
#line 11703 "./marpa.w"
;
}
}

/*:1010*//*1014:*/
#line 11714 "./marpa.w"

int marpa_b_is_null(Marpa_Bocage b)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11717 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11718 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11719 "./marpa.w"

return B_is_Nulling(b);
}

/*:1014*//*1021:*/
#line 11759 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1258:*/
#line 14838 "./marpa.w"
void*const failure_indicator= NULL;
/*:1258*/
#line 11762 "./marpa.w"

/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11763 "./marpa.w"

ORDER o;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11765 "./marpa.w"

o= my_malloc(sizeof(*o));
B_of_O(o)= b;
bocage_ref(b);
/*1018:*/
#line 11747 "./marpa.w"

{
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
OBS_of_O(o)= NULL;
}

/*:1018*//*1024:*/
#line 11777 "./marpa.w"

o->t_ref_count= 1;

/*:1024*//*1036:*/
#line 11865 "./marpa.w"

High_Rank_Count_of_O(o)= 1;
/*:1036*/
#line 11769 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
Ambiguity_Metric_of_O(o)= Ambiguity_Metric_of_B(b);
return o;
}

/*:1021*//*1025:*/
#line 11781 "./marpa.w"

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

/*:1025*//*1026:*/
#line 11799 "./marpa.w"

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

/*:1026*//*1027:*/
#line 11813 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 11816 "./marpa.w"

bocage_unref(b);
marpa_obs_free(OBS_of_O(o));
my_free(o);
}

/*:1027*//*1031:*/
#line 11834 "./marpa.w"

int marpa_o_ambiguity_metric(Marpa_Order o)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11837 "./marpa.w"

/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 11838 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11839 "./marpa.w"

return Ambiguity_Metric_of_O(o);
}

/*:1031*//*1034:*/
#line 11848 "./marpa.w"

int marpa_o_is_null(Marpa_Order o)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11851 "./marpa.w"

/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 11852 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11853 "./marpa.w"

return O_is_Nulling(o);
}

/*:1034*//*1037:*/
#line 11867 "./marpa.w"

int marpa_o_high_rank_only_set(
Marpa_Order o,
int count)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11872 "./marpa.w"

/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 11873 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11874 "./marpa.w"

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

/*:1037*//*1038:*/
#line 11889 "./marpa.w"

int marpa_o_high_rank_only(Marpa_Order o)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11892 "./marpa.w"

/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 11893 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11894 "./marpa.w"

return High_Rank_Count_of_O(o);
}

/*:1038*//*1042:*/
#line 11931 "./marpa.w"

int marpa_o_rank(Marpa_Order o)
{
ANDID**and_node_orderings;
struct marpa_obstack*obs;
int bocage_was_reordered= 0;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 11937 "./marpa.w"

/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 11938 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 11939 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*1048:*/
#line 12103 "./marpa.w"

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

/*:1048*/
#line 11945 "./marpa.w"

if(High_Rank_Count_of_O(o)){
/*1043:*/
#line 11960 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
int or_node_id= 0;
int ambiguity_metric= 1;

while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1044:*/
#line 11977 "./marpa.w"

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
/*1045:*/
#line 12016 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1045*/
#line 11997 "./marpa.w"

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

/*:1044*/
#line 11971 "./marpa.w"

or_node_id++;
}
Ambiguity_Metric_of_O(o)= ambiguity_metric;
}

/*:1043*/
#line 11947 "./marpa.w"

}else{
/*1046:*/
#line 12027 "./marpa.w"

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
/*1045:*/
#line 12016 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1045*/
#line 12039 "./marpa.w"

rank_by_and_id[and_node_id]= and_node_rank;
}
while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1047:*/
#line 12072 "./marpa.w"

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

/*:1047*/
#line 12046 "./marpa.w"

or_node_id++;
}
my_free(rank_by_and_id);
}

/*:1046*/
#line 11949 "./marpa.w"

}
if(!bocage_was_reordered){
marpa_obs_free(obs);
OBS_of_O(o)= NULL;
o->t_and_node_orderings= NULL;
}
O_is_Frozen(o)= 1;
return 1;
}

/*:1042*//*1049:*/
#line 12120 "./marpa.w"

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

/*:1049*//*1050:*/
#line 12141 "./marpa.w"

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

/*:1050*//*1051:*/
#line 12155 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12160 "./marpa.w"

/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12161 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12162 "./marpa.w"

/*905:*/
#line 10334 "./marpa.w"

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
/*:905*/
#line 12163 "./marpa.w"

/*906:*/
#line 10346 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:906*/
#line 12164 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
if(!and_order_ix_is_valid(o,or_node,ix))return-1;
return and_order_get(o,or_node,ix);
}

/*:1051*//*1056:*/
#line 12217 "./marpa.w"

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

/*:1056*//*1057:*/
#line 12235 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1258:*/
#line 14838 "./marpa.w"
void*const failure_indicator= NULL;
/*:1258*/
#line 12238 "./marpa.w"

TREE t;
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12240 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12241 "./marpa.w"

t= my_malloc(sizeof(*t));
O_of_T(t)= o;
order_ref(o);
O_is_Frozen(o)= 1;
/*1074:*/
#line 12426 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1074*/
#line 12246 "./marpa.w"

/*1058:*/
#line 12251 "./marpa.w"

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

/*:1058*//*1061:*/
#line 12275 "./marpa.w"

t->t_ref_count= 1;

/*:1061*//*1068:*/
#line 12354 "./marpa.w"
t->t_pause_counter= 0;
/*:1068*/
#line 12247 "./marpa.w"

return t;
}

/*:1057*//*1062:*/
#line 12279 "./marpa.w"

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

/*:1062*//*1063:*/
#line 12297 "./marpa.w"

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

/*:1063*//*1064:*/
#line 12311 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_free(t);
}

/*:1064*//*1069:*/
#line 12355 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1069*//*1070:*/
#line 12364 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1070*//*1071:*/
#line 12374 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12377 "./marpa.w"

const int termination_indicator= -1;
int is_first_tree_attempt= (t->t_parse_count<1);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12380 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12381 "./marpa.w"

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
/*1080:*/
#line 12455 "./marpa.w"

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

/*:1080*/
#line 12406 "./marpa.w"

}else{
/*1081:*/
#line 12480 "./marpa.w"
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

/*:1081*/
#line 12408 "./marpa.w"

}
/*1082:*/
#line 12522 "./marpa.w"
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
/*1083:*/
#line 12585 "./marpa.w"

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

/*:1083*/
#line 12579 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1082*/
#line 12410 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return termination_indicator;

}

/*:1071*//*1078:*/
#line 12442 "./marpa.w"

PRIVATE int tree_or_node_try(TREE tree,ORID or_node_id)
{
return!bv_bit_test_then_set(tree->t_or_node_in_use,or_node_id);
}
/*:1078*//*1079:*/
#line 12448 "./marpa.w"

PRIVATE void tree_or_node_release(TREE tree,ORID or_node_id)
{
bv_bit_clear(tree->t_or_node_in_use,or_node_id);
}

/*:1079*//*1084:*/
#line 12606 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1084*//*1085:*/
#line 12614 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12617 "./marpa.w"

/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12618 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12619 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return failure_indicator;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1085*//*1092:*/
#line 12680 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12684 "./marpa.w"

/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12685 "./marpa.w"

/*1091:*/
#line 12662 "./marpa.w"
{
NOOK base_nook;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12664 "./marpa.w"

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

/*:1091*/
#line 12686 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1092*//*1093:*/
#line 12690 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12694 "./marpa.w"

/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12695 "./marpa.w"

/*1091:*/
#line 12662 "./marpa.w"
{
NOOK base_nook;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12664 "./marpa.w"

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

/*:1091*/
#line 12696 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1093*//*1094:*/
#line 12700 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12704 "./marpa.w"

/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12705 "./marpa.w"

/*1091:*/
#line 12662 "./marpa.w"
{
NOOK base_nook;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12664 "./marpa.w"

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

/*:1091*/
#line 12706 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1094*//*1095:*/
#line 12710 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12714 "./marpa.w"

/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12715 "./marpa.w"

/*1091:*/
#line 12662 "./marpa.w"
{
NOOK base_nook;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12664 "./marpa.w"

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

/*:1091*/
#line 12716 "./marpa.w"

return NOOK_Cause_is_Expanded(nook);
}

/*:1095*//*1096:*/
#line 12720 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12724 "./marpa.w"

/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12725 "./marpa.w"

/*1091:*/
#line 12662 "./marpa.w"
{
NOOK base_nook;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12664 "./marpa.w"

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

/*:1091*/
#line 12726 "./marpa.w"

return NOOK_Predecessor_is_Expanded(nook);
}

/*:1096*//*1097:*/
#line 12730 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12734 "./marpa.w"

/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12735 "./marpa.w"

/*1091:*/
#line 12662 "./marpa.w"
{
NOOK base_nook;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12664 "./marpa.w"

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

/*:1091*/
#line 12736 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1097*//*1098:*/
#line 12740 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 12744 "./marpa.w"

/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12745 "./marpa.w"

/*1091:*/
#line 12662 "./marpa.w"
{
NOOK base_nook;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12664 "./marpa.w"

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

/*:1091*/
#line 12746 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1098*//*1115:*/
#line 12924 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1258:*/
#line 14838 "./marpa.w"
void*const failure_indicator= NULL;
/*:1258*/
#line 12927 "./marpa.w"

/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 12928 "./marpa.w"
;
/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 12929 "./marpa.w"

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
/*1106:*/
#line 12850 "./marpa.w"

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

/*:1106*//*1113:*/
#line 12913 "./marpa.w"

MARPA_DSTACK_SAFE(VStack_of_V(v));
/*:1113*//*1118:*/
#line 12961 "./marpa.w"

v->t_ref_count= 1;

/*:1118*//*1125:*/
#line 13014 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1125*//*1127:*/
#line 13021 "./marpa.w"

V_is_Trace(v)= 0;
/*:1127*//*1130:*/
#line 13042 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1130*//*1135:*/
#line 13069 "./marpa.w"

{
XSY_is_Valued_BV_of_V(v)= lbv_clone(v->t_obs,Valued_BV_of_B(b),xsy_count);
Valued_Locked_BV_of_V(v)= 
lbv_clone(v->t_obs,Valued_Locked_BV_of_B(b),xsy_count);
}

/*:1135*/
#line 12941 "./marpa.w"

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

/*:1115*//*1119:*/
#line 12965 "./marpa.w"

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

/*:1119*//*1120:*/
#line 12983 "./marpa.w"

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

/*:1120*//*1121:*/
#line 12997 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
/*1114:*/
#line 12915 "./marpa.w"

{
if(_MARPA_LIKELY(MARPA_DSTACK_IS_INITIALIZED(VStack_of_V(v))!=NULL))
{
MARPA_DSTACK_DESTROY(VStack_of_V(v));
}
}

/*:1114*/
#line 13001 "./marpa.w"

/*1108:*/
#line 12866 "./marpa.w"

marpa_obs_free(v->t_obs);

/*:1108*/
#line 13002 "./marpa.w"

}

/*:1121*//*1128:*/
#line 13023 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 13026 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1122:*/
#line 13005 "./marpa.w"

TREE t= T_of_V(v);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 13007 "./marpa.w"


/*:1122*/
#line 13028 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 13029 "./marpa.w"

if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= Boolean(flag);
return 1;
}

/*:1128*//*1131:*/
#line 13045 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 13048 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1122:*/
#line 13005 "./marpa.w"

TREE t= T_of_V(v);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 13007 "./marpa.w"


/*:1122*/
#line 13050 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 13051 "./marpa.w"

if(_MARPA_UNLIKELY(V_is_Nulling(v)))return-1;
if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1131*//*1136:*/
#line 13077 "./marpa.w"

int marpa_v_symbol_is_valued(
Marpa_Value public_v,
Marpa_Symbol_ID xsy_id)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 13082 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1122:*/
#line 13005 "./marpa.w"

TREE t= T_of_V(v);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 13007 "./marpa.w"


/*:1122*/
#line 13084 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 13085 "./marpa.w"

/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 13086 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 13087 "./marpa.w"

return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
}

/*:1136*//*1137:*/
#line 13093 "./marpa.w"

PRIVATE int symbol_is_valued_set(
VALUE v,XSYID xsy_id,int value)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 13097 "./marpa.w"

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

/*:1137*//*1138:*/
#line 13116 "./marpa.w"

int marpa_v_symbol_is_valued_set(
Marpa_Value public_v,Marpa_Symbol_ID xsy_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 13121 "./marpa.w"

/*1122:*/
#line 13005 "./marpa.w"

TREE t= T_of_V(v);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 13007 "./marpa.w"


/*:1122*/
#line 13122 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 13123 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1262:*/
#line 14857 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1262*/
#line 13129 "./marpa.w"

/*1263:*/
#line 14864 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1263*/
#line 13130 "./marpa.w"

return symbol_is_valued_set(v,xsy_id,value);
}

/*:1138*//*1139:*/
#line 13136 "./marpa.w"

int
marpa_v_valued_force(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 13141 "./marpa.w"

XSYID xsy_count;
XSYID xsy_id;
/*1122:*/
#line 13005 "./marpa.w"

TREE t= T_of_V(v);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 13007 "./marpa.w"


/*:1122*/
#line 13144 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 13145 "./marpa.w"

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

/*:1139*//*1140:*/
#line 13160 "./marpa.w"

int marpa_v_rule_is_valued_set(
Marpa_Value public_v,Marpa_Rule_ID xrl_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 13165 "./marpa.w"

/*1122:*/
#line 13005 "./marpa.w"

TREE t= T_of_V(v);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 13007 "./marpa.w"


/*:1122*/
#line 13166 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 13167 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1269:*/
#line 14898 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1269*/
#line 13173 "./marpa.w"

/*1267:*/
#line 14887 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}
/*:1267*/
#line 13174 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsy_id= LHS_ID_of_XRL(xrl);
return symbol_is_valued_set(v,xsy_id,value);
}
}

/*:1140*//*1142:*/
#line 13189 "./marpa.w"

Marpa_Step_Type marpa_v_step(Marpa_Value public_v)
{
/*1259:*/
#line 14841 "./marpa.w"
const int failure_indicator= -2;

/*:1259*/
#line 13192 "./marpa.w"

const VALUE v= (VALUE)public_v;

if(V_is_Nulling(v)){
/*1122:*/
#line 13005 "./marpa.w"

TREE t= T_of_V(v);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 13007 "./marpa.w"


/*:1122*/
#line 13196 "./marpa.w"

/*1144:*/
#line 13277 "./marpa.w"

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

/*:1144*/
#line 13197 "./marpa.w"

return Step_Type_of_V(v)= MARPA_STEP_INACTIVE;
}

while(V_is_Active(v)){
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case MARPA_STEP_INITIAL:
{
XSYID xsy_count;
/*1122:*/
#line 13005 "./marpa.w"

TREE t= T_of_V(v);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 13007 "./marpa.w"


/*:1122*/
#line 13208 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
lbv_fill(Valued_Locked_BV_of_V(v),xsy_count);
/*1143:*/
#line 13261 "./marpa.w"

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

/*:1143*/
#line 13211 "./marpa.w"

}

case STEP_GET_DATA:
/*1145:*/
#line 13300 "./marpa.w"

{
AND and_nodes;





int pop_arguments= 1;
/*1122:*/
#line 13005 "./marpa.w"

TREE t= T_of_V(v);
/*1055:*/
#line 12213 "./marpa.w"

ORDER o= O_of_T(t);
/*1028:*/
#line 11822 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*983:*/
#line 11423 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:983*/
#line 11824 "./marpa.w"


/*:1028*/
#line 12215 "./marpa.w"
;

/*:1055*/
#line 13007 "./marpa.w"


/*:1122*/
#line 13309 "./marpa.w"

/*1275:*/
#line 14936 "./marpa.w"

if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1275*/
#line 13310 "./marpa.w"

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

/*:1145*/
#line 13215 "./marpa.w"

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

/*:1142*//*1147:*/
#line 13443 "./marpa.w"

PRIVATE int lbv_bits_to_size(int bits)
{
const LBW result= ((LBW)bits+(lbv_wordbits-1))/lbv_wordbits;
return(int)result;
}

/*:1147*//*1148:*/
#line 13451 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new(struct marpa_obstack*obs,int bits)
{
int size= lbv_bits_to_size(bits);
LBV lbv= marpa_obs_new(obs,LBW,size);
return lbv;
}

/*:1148*//*1149:*/
#line 13461 "./marpa.w"

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

/*:1149*//*1150:*/
#line 13474 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new0(struct marpa_obstack*obs,int bits)
{
LBV lbv= lbv_obs_new(obs,bits);
return lbv_zero(lbv,bits);
}

/*:1150*//*1152:*/
#line 13493 "./marpa.w"

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

/*:1152*//*1153:*/
#line 13509 "./marpa.w"

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

/*:1153*//*1156:*/
#line 13545 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(int bits)
{
return((LBW)bits+bv_modmask)/bv_wordbits;
}
/*:1156*//*1157:*/
#line 13551 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(int bits)
{
LBW mask= (LBW)bits&bv_modmask;
if(mask)mask= (LBW)~(~0uL<<mask);else mask= (LBW)~0uL;
return(mask);
}

/*:1157*//*1159:*/
#line 13565 "./marpa.w"

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

/*:1159*//*1161:*/
#line 13583 "./marpa.w"

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


/*:1161*//*1162:*/
#line 13604 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create((int)BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct marpa_obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,(int)BV_BITS(bv));
}

/*:1162*//*1163:*/
#line 13618 "./marpa.w"

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

/*:1163*//*1164:*/
#line 13636 "./marpa.w"

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

/*:1164*//*1165:*/
#line 13650 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(_MARPA_LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1165*//*1166:*/
#line 13661 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1166*//*1167:*/
#line 13672 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1167*//*1169:*/
#line 13686 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
LBW length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1169*//*1171:*/
#line 13695 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1171*//*1172:*/
#line 13703 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1172*//*1173:*/
#line 13711 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1173*//*1174:*/
#line 13723 "./marpa.w"

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

/*:1174*//*1175:*/
#line 13737 "./marpa.w"

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

/*:1175*//*1176:*/
#line 13751 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1176*//*1177:*/
#line 13761 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1177*//*1178:*/
#line 13771 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1178*//*1179:*/
#line 13781 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1179*//*1180:*/
#line 13791 "./marpa.w"

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

/*:1180*//*1181:*/
#line 13871 "./marpa.w"

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

/*:1181*//*1186:*/
#line 13919 "./marpa.w"

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

/*:1186*//*1191:*/
#line 14026 "./marpa.w"

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

/*:1191*//*1193:*/
#line 14049 "./marpa.w"

PRIVATE size_t matrix_sizeof(int rows,int columns)
{
const LBW bv_data_words= bv_bits_to_size(columns);
const LBW row_bytes= 
(bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
return offsetof(struct s_bit_matrix,t_row_data)+((size_t)rows)*row_bytes;
}

/*:1193*//*1195:*/
#line 14059 "./marpa.w"

PRIVATE Bit_Matrix matrix_obs_create(
struct marpa_obstack*obs,
int rows,
int columns)
{

Bit_Matrix matrix_addr= 
marpa__obs_alloc(obs,matrix_sizeof(rows,columns),ALIGNOF(Bit_Matrix_Object));
return matrix_buffer_create(matrix_addr,rows,columns);
}

/*:1195*//*1196:*/
#line 14072 "./marpa.w"

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

/*:1196*//*1197:*/
#line 14094 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
return(int)BV_BITS(row0);
}

/*:1197*//*1198:*/
#line 14110 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,int row)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
LBW words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+(LBW)row*words_per_row;
}

/*:1198*//*1200:*/
#line 14119 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1200*//*1202:*/
#line 14127 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1202*//*1204:*/
#line 14135 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1204*//*1205:*/
#line 14152 "./marpa.w"

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

/*:1205*//*1217:*/
#line 14293 "./marpa.w"

PRIVATE void
cilar_init(const CILAR cilar)
{
cilar->t_obs= marpa_obs_init;
cilar->t_avl= _marpa_avl_create(cil_cmp,NULL);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}
/*:1217*//*1218:*/
#line 14307 "./marpa.w"

PRIVATE void
cilar_reinit(const CILAR cilar)
{
MARPA_DSTACK_DESTROY(cilar->t_buffer);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}

/*:1218*//*1219:*/
#line 14316 "./marpa.w"

PRIVATE void cilar_destroy(const CILAR cilar)
{
_marpa_avl_destroy(cilar->t_avl);
marpa_obs_free(cilar->t_obs);
MARPA_DSTACK_DESTROY((cilar->t_buffer));
}

/*:1219*//*1220:*/
#line 14325 "./marpa.w"

PRIVATE CIL cil_empty(CILAR cilar)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);

Count_of_CIL(cil)= 0;
return cil_buffer_add(cilar);
}

/*:1220*//*1221:*/
#line 14335 "./marpa.w"

PRIVATE CIL cil_singleton(CILAR cilar,int element)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);
Count_of_CIL(cil)= 1;
Item_of_CIL(cil,0)= element;

return cil_buffer_add(cilar);
}

/*:1221*//*1222:*/
#line 14351 "./marpa.w"

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

/*:1222*//*1223:*/
#line 14379 "./marpa.w"

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

/*:1223*//*1224:*/
#line 14396 "./marpa.w"

PRIVATE void cil_buffer_clear(CILAR cilar)
{
const MARPA_DSTACK dstack= &cilar->t_buffer;
MARPA_DSTACK_CLEAR(*dstack);



*MARPA_DSTACK_PUSH(*dstack,int)= 0;
}

/*:1224*//*1225:*/
#line 14410 "./marpa.w"

PRIVATE CIL cil_buffer_push(CILAR cilar,int new_item)
{
CIL cil_in_buffer;
MARPA_DSTACK dstack= &cilar->t_buffer;
*MARPA_DSTACK_PUSH(*dstack,int)= new_item;


cil_in_buffer= MARPA_DSTACK_BASE(*dstack,int);
Count_of_CIL(cil_in_buffer)++;
return cil_in_buffer;
}

/*:1225*//*1226:*/
#line 14425 "./marpa.w"

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

/*:1226*//*1227:*/
#line 14444 "./marpa.w"

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

/*:1227*//*1228:*/
#line 14497 "./marpa.w"

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

/*:1228*//*1229:*/
#line 14532 "./marpa.w"

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

/*:1229*//*1242:*/
#line 14671 "./marpa.w"

PRIVATE void
psar_safe(const PSAR psar)
{
psar->t_psl_length= 0;
psar->t_first_psl= psar->t_first_free_psl= NULL;
}
/*:1242*//*1243:*/
#line 14678 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1243*//*1244:*/
#line 14685 "./marpa.w"

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
/*:1244*//*1245:*/
#line 14699 "./marpa.w"

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
/*:1245*//*1248:*/
#line 14730 "./marpa.w"

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

/*:1248*//*1250:*/
#line 14748 "./marpa.w"

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

/*:1250*//*1252:*/
#line 14768 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1252*//*1254:*/
#line 14790 "./marpa.w"

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

/*:1254*//*1278:*/
#line 14980 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}
/*:1278*//*1279:*/
#line 14999 "./marpa.w"

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

/*:1279*//*1283:*/
#line 15042 "./marpa.w"

PRIVATE_NOT_INLINE void*
marpa__default_out_of_memory(void)
{
abort();
return NULL;
}
void*(*const marpa__out_of_memory)(void)= marpa__default_out_of_memory;

/*:1283*//*1287:*/
#line 15068 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
marpa__debug_handler= debug_handler;
}

/*:1287*//*1288:*/
#line 15074 "./marpa.w"

int marpa_debug_level_set(int new_level)
{
const int old_level= marpa__debug_level;
marpa__debug_level= new_level;
return old_level;
}


/*:1288*/
#line 15253 "./marpa.w"


/*:1306*/
