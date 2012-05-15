/*1246:*/
#line 14119 "./marpa.w"

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

/*:1246*//*1247:*/
#line 14142 "./marpa.w"

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
#define ISY_of_XSY(xsy) ((xsy) ->t_isy_equivalent) 
#define ISYID_of_XSY(xsy) ID_of_ISY(ISY_of_XSY(xsy) ) 
#define ISY_by_XSYID(xsyid) (XSY_by_ID(xsyid) ->t_isy_equivalent) 
#define ISYID_by_XSYID(xsyid) ID_of_ISY(ISY_of_XSY(XSY_by_ID(xsyid) ) ) 
#define ISYID_by_SYMID(xsyid) ISYID_by_XSYID(xsyid) 
#define Nulling_ISY_of_XSY(xsy) ((xsy) ->t_nulling_isy) 
#define Nulling_ISY_by_XSYID(xsy) (XSY_by_ID(xsy) ->t_nulling_isy) 
#define Nulling_ISYID_by_XSYID(xsy) ID_of_ISY(XSY_by_ID(xsy) ->t_nulling_isy) 
#define Source_XSY_of_ISY(isy) (Buddy_of_ISY(isy) ->t_source_xsy) 
#define Source_XSY_of_SYM(symbol) ((symbol) ->t_source_xsy) 
#define Nulling_OR_by_ISYID(isyid) ((OR) ISY_by_ID(isyid) ) 
#define Buddy_of_ISY(isy) ((isy) ->t_buddy) 
#define XSYID_by_ISYID(isyid) ID_of_XSY(Buddy_of_ISY(ISY_by_ID(isyid) ) ) 
#define ISY_by_ID(id) (*DSTACK_INDEX(g->t_isy_stack,ISY,(id) ) ) 
#define ID_of_ISY(isy) ((isy) ->t_isyid)  \

#define ISY_Count_of_G(g) (DSTACK_LENGTH((g) ->t_isy_stack) ) 
#define ISY_is_Start(isy) ((isy) ->t_is_start) 
#define ISY_is_LHS(isy) ((isy) ->t_is_lhs) 
#define ISY_is_Nulling(isy) ((isy) ->t_isy_is_nulling) 
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
#define XRL_is_Accessible(rule) ((rule) ->t_is_accessible) 
#define XRL_is_Productive(rule) ((rule) ->t_is_productive) 
#define XRL_is_Used(xrl) ( \
XRL_is_Accessible(xrl) &&XRL_is_Productive(xrl) &&!XRL_is_Nulling(xrl)  \
) 
#define XRL_is_Ask_Me(rule) ((rule) ->t_is_ask_me) 
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
const AIM aim= First_AIM_of_IRL(irl) ; \
(sort_key) = Postdot_SYMID_of_AIM(aim) ; \
} \

#define TRANS_of_AHFA_by_SYMID(from_ahfa,id)  \
(*(TRANSs_of_AHFA(from_ahfa) +ISYID_by_SYMID(id) ) ) 
#define TRANS_of_EIM_by_SYMID(eim,id) TRANS_of_AHFA_by_SYMID(AHFA_of_EIM(eim) ,(id) ) 
#define To_AHFA_of_TRANS(trans) (to_ahfa_of_transition_get(trans) ) 
#define LV_To_AHFA_of_TRANS(trans) ((trans) ->t_ur.t_to_ahfa) 
#define Completion_Count_of_TRANS(trans)  \
(completion_count_of_transition_get(trans) ) 
#define LV_Completion_Count_of_TRANS(trans) ((trans) ->t_ur.t_completion_count) 
#define To_AHFA_of_AHFA_by_SYMID(from_ahfa,id)  \
(To_AHFA_of_TRANS(TRANS_of_AHFA_by_SYMID((from_ahfa) ,(id) ) ) ) 
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
#define ISYID_of_TOK(tok) ((tok) ->t_unvalued.t_isyid) 
#define SYMID_of_TOK(tok) ID_of_XSY(Source_XSY_of_ISY(ISY_by_ID(ISYID_of_TOK(tok) ) ) ) 
#define Value_of_TOK(tok) ((tok) ->t_value) 
#define TOK_Obs_of_R(r) TOK_Obs_of_I(I_of_R(r) ) 
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
#define IRL_of_OR(or) ((or) ->t_final.t_irl) 
#define Origin_Ord_of_OR(or) ((or) ->t_final.t_start_set_ordinal) 
#define ID_of_OR(or) ((or) ->t_final.t_id) 
#define ES_Ord_of_OR(or) ((or) ->t_draft.t_end_set_ordinal) 
#define DANDs_of_OR(or) ((or) ->t_draft.t_draft_and_node) 
#define First_ANDID_of_OR(or) ((or) ->t_final.t_first_and_node_id) 
#define AND_Count_of_OR(or) ((or) ->t_final.t_and_node_count) 
#define TOK_of_OR(or) (&(or) ->t_token) 
#define SYMID_of_OR(or) SYMID_of_TOK(TOK_of_OR(or) ) 
#define ISYID_of_OR(or) ISYID_of_TOK(TOK_of_OR(or) ) 
#define Value_of_OR(or) Value_of_TOK(TOK_of_OR(or) ) 
#define ORs_of_B(b) ((b) ->t_or_nodes) 
#define OR_of_B_by_ID(b,id) (ORs_of_B(b) [(id) ]) 
#define OR_Count_of_B(b) ((b) ->t_or_node_count) 
#define ANDs_of_B(b) ((b) ->t_and_nodes) 
#define AND_Count_of_B(b) ((b) ->t_and_node_count) 
#define Top_ORID_of_B(b) ((b) ->t_top_or_node_id) 
#define Path_AIM_of_LIM(lim) (base_aim_of_lim(g,lim) +1) 
#define Base_AIM_of_LIM(lim) (base_aim_of_lim(g,lim) ) 
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

#line 14160 "./marpa.w"

#include "marpa_obs.h"
#include "avl.h"
/*93:*/
#line 904 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:93*//*121:*/
#line 1088 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef XSY SYM;
typedef const struct s_xsy*XSY_Const;

/*:121*//*385:*/
#line 4047 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:385*//*424:*/
#line 4418 "./marpa.w"
struct s_AHFA_state;
/*:424*//*505:*/
#line 5580 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:505*//*612:*/
#line 6273 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:612*//*636:*/
#line 6487 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:636*//*656:*/
#line 6777 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:656*//*659:*/
#line 6812 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:659*//*740:*/
#line 7930 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:740*//*744:*/
#line 7958 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:744*//*843:*/
#line 9144 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:843*//*871:*/
#line 9572 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:871*//*898:*/
#line 10009 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:898*//*924:*/
#line 10424 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:924*//*939:*/
#line 10609 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:939*//*952:*/
#line 10717 "./marpa.w"

struct s_bocage_setup_per_es;
/*:952*//*1011:*/
#line 11388 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1011*//*1050:*/
#line 11863 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1050*//*1063:*/
#line 11999 "./marpa.w"

typedef struct s_value*VALUE;
/*:1063*//*1154:*/
#line 13233 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1154*//*1157:*/
#line 13269 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1157*//*1164:*/
#line 13334 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1164*//*1166:*/
#line 13349 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1166*/
#line 14163 "./marpa.w"

/*40:*/
#line 604 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:40*//*120:*/
#line 1085 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
typedef XSYID SYMID;
/*:120*//*172:*/
#line 1436 "./marpa.w"

struct s_isy;
typedef struct s_isy*ISY;
typedef Marpa_ISY_ID ISYID;

/*:172*//*202:*/
#line 1645 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:202*//*266:*/
#line 2286 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:266*//*297:*/
#line 2482 "./marpa.w"
typedef int SYMI;
/*:297*//*441:*/
#line 4509 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef int AHFAID;

/*:441*//*506:*/
#line 5586 "./marpa.w"
typedef int AEX;
/*:506*//*522:*/
#line 5739 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:522*//*537:*/
#line 5831 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:537*//*609:*/
#line 6264 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:609*//*611:*/
#line 6268 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:611*//*687:*/
#line 7194 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:687*//*689:*/
#line 7206 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:689*//*863:*/
#line 9508 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:863*//*897:*/
#line 9998 "./marpa.w"

typedef int WHEID;

/*:897*//*923:*/
#line 10420 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:923*//*1049:*/
#line 11860 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1049*//*1101:*/
#line 12513 "./marpa.w"

typedef unsigned int Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1101*//*1136:*/
#line 12987 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1136*/
#line 14164 "./marpa.w"

/*34:*/
#line 523 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:34*//*877:*/
#line 9636 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:877*//*1102:*/
#line 12520 "./marpa.w"

static const unsigned int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const unsigned int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= 1u;
static const unsigned int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1102*//*1187:*/
#line 13530 "./marpa.w"


/*:1187*//*1228:*/
#line 13937 "./marpa.w"

int(*_marpa_debug_handler)(const char*,...)= 
MARPA_DEFAULT_DEBUG_HANDLER;
int _marpa_debug_level= 0;

/*:1228*/
#line 14165 "./marpa.w"

/*1155:*/
#line 13236 "./marpa.w"

struct s_dstack{int t_count;int t_capacity;void*t_base;};
/*:1155*/
#line 14166 "./marpa.w"

/*39:*/
#line 598 "./marpa.w"
struct marpa_g{
/*112:*/
#line 1040 "./marpa.w"

int t_is_ok;

/*:112*/
#line 599 "./marpa.w"

/*50:*/
#line 679 "./marpa.w"

DSTACK_DECLARE(t_xsy_stack);
DSTACK_DECLARE(t_isy_stack);

/*:50*//*59:*/
#line 736 "./marpa.w"

DSTACK_DECLARE(t_xrl_stack);
DSTACK_DECLARE(t_irl_stack);
struct marpa_avl_table*t_rule_tree;
/*:59*//*90:*/
#line 892 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:90*//*97:*/
#line 923 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:97*//*104:*/
#line 987 "./marpa.w"

AVL_TREE t_xrl_tree;
/*:104*//*108:*/
#line 1010 "./marpa.w"

struct obstack t_obs;
struct obstack t_xrl_obs;
/*:108*//*114:*/
#line 1055 "./marpa.w"

const char*t_error_string;
/*:114*//*387:*/
#line 4064 "./marpa.w"

AIM t_AHFA_items;
/*:387*//*442:*/
#line 4513 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:442*/
#line 600 "./marpa.w"

/*44:*/
#line 626 "./marpa.w"
int t_ref_count;
/*:44*//*70:*/
#line 795 "./marpa.w"
XSYID t_start_xsyid;
/*:70*//*74:*/
#line 823 "./marpa.w"

IRL t_start_irl;
/*:74*//*78:*/
#line 840 "./marpa.w"

int t_external_size;
/*:78*//*81:*/
#line 854 "./marpa.w"
int t_max_rule_length;
/*:81*//*115:*/
#line 1057 "./marpa.w"

Marpa_Error_Code t_error;
/*:115*//*298:*/
#line 2484 "./marpa.w"

int t_symbol_instance_count;
/*:298*//*388:*/
#line 4068 "./marpa.w"

unsigned int t_aim_count;
/*:388*//*443:*/
#line 4516 "./marpa.w"
int t_AHFA_len;
/*:443*/
#line 601 "./marpa.w"

/*84:*/
#line 860 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:84*//*87:*/
#line 872 "./marpa.w"
unsigned int t_has_cycle:1;
/*:87*/
#line 602 "./marpa.w"

};
/*:39*//*96:*/
#line 916 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:96*//*122:*/
#line 1094 "./marpa.w"

struct s_xsy{
/*159:*/
#line 1340 "./marpa.w"
ISY t_isy_equivalent;
/*:159*//*162:*/
#line 1368 "./marpa.w"
ISY t_nulling_isy;
/*:162*//*165:*/
#line 1392 "./marpa.w"
XSY t_source_xsy;
/*:165*/
#line 1096 "./marpa.w"

/*123:*/
#line 1104 "./marpa.w"
XSYID t_symbol_id;

/*:123*/
#line 1097 "./marpa.w"

/*126:*/
#line 1130 "./marpa.w"
unsigned int t_is_lhs:1;
/*:126*//*128:*/
#line 1137 "./marpa.w"
unsigned int t_is_sequence_lhs:1;
/*:128*//*130:*/
#line 1145 "./marpa.w"
unsigned int t_is_semantic:1;
/*:130*//*133:*/
#line 1167 "./marpa.w"
unsigned int t_is_ask_me_when_null:1;
/*:133*//*136:*/
#line 1192 "./marpa.w"
unsigned int t_is_accessible:1;
/*:136*//*139:*/
#line 1212 "./marpa.w"
unsigned int t_is_counted:1;
/*:139*//*142:*/
#line 1228 "./marpa.w"
unsigned int t_is_nulling:1;
/*:142*//*145:*/
#line 1244 "./marpa.w"
unsigned int t_is_nullable:1;
/*:145*//*148:*/
#line 1264 "./marpa.w"

unsigned int t_is_terminal:1;
unsigned int t_is_marked_terminal:1;
/*:148*//*153:*/
#line 1303 "./marpa.w"
unsigned int t_is_productive:1;
/*:153*//*156:*/
#line 1319 "./marpa.w"
unsigned int t_is_start:1;
/*:156*/
#line 1098 "./marpa.w"

};

/*:122*//*173:*/
#line 1449 "./marpa.w"

struct s_isy{
int t_or_node_type;
ISYID t_isyid;
/*180:*/
#line 1505 "./marpa.w"

XSY t_buddy;
/*:180*//*195:*/
#line 1584 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:195*/
#line 1453 "./marpa.w"

/*185:*/
#line 1536 "./marpa.w"
unsigned int t_is_start:1;
/*:185*//*188:*/
#line 1550 "./marpa.w"
unsigned int t_is_lhs:1;
/*:188*//*191:*/
#line 1564 "./marpa.w"
unsigned int t_isy_is_nulling:1;
/*:191*/
#line 1454 "./marpa.w"

};
/*:173*//*201:*/
#line 1636 "./marpa.w"

struct s_xrl{
/*214:*/
#line 1917 "./marpa.w"
int t_rhs_length;
/*:214*//*224:*/
#line 2005 "./marpa.w"
Marpa_Rule_ID t_id;

/*:224*/
#line 1638 "./marpa.w"

/*225:*/
#line 2011 "./marpa.w"
unsigned int t_is_bnf:1;
/*:225*//*227:*/
#line 2018 "./marpa.w"
unsigned int t_is_sequence:1;
/*:227*//*230:*/
#line 2036 "./marpa.w"
int t_minimum;
/*:230*//*232:*/
#line 2044 "./marpa.w"
SYMID t_separator_id;
/*:232*//*236:*/
#line 2063 "./marpa.w"
unsigned int t_is_discard:1;
/*:236*//*240:*/
#line 2102 "./marpa.w"
unsigned int t_is_proper_separation:1;
/*:240*//*244:*/
#line 2122 "./marpa.w"
unsigned int t_is_loop:1;
/*:244*//*247:*/
#line 2138 "./marpa.w"
unsigned int t_is_nulling:1;
/*:247*//*250:*/
#line 2145 "./marpa.w"
unsigned int t_is_accessible:1;
/*:250*//*253:*/
#line 2162 "./marpa.w"
unsigned int t_is_productive:1;
/*:253*//*257:*/
#line 2203 "./marpa.w"
unsigned int t_is_ask_me:1;
/*:257*/
#line 1639 "./marpa.w"

/*215:*/
#line 1920 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:215*/
#line 1640 "./marpa.w"

};
/*:201*//*264:*/
#line 2277 "./marpa.w"

struct s_irl{
/*292:*/
#line 2455 "./marpa.w"
XRL t_source_xrl;
/*:292*//*295:*/
#line 2477 "./marpa.w"
AIM t_first_aim;
/*:295*/
#line 2279 "./marpa.w"

/*267:*/
#line 2297 "./marpa.w"
IRLID t_irl_id;

/*:267*//*274:*/
#line 2332 "./marpa.w"
int t_length;
/*:274*//*283:*/
#line 2395 "./marpa.w"
int t_real_symbol_count;
/*:283*//*286:*/
#line 2413 "./marpa.w"
int t_virtual_start;
/*:286*//*289:*/
#line 2433 "./marpa.w"
int t_virtual_end;
/*:289*//*299:*/
#line 2491 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:299*/
#line 2280 "./marpa.w"

/*276:*/
#line 2358 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:276*//*279:*/
#line 2374 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:279*/
#line 2281 "./marpa.w"

/*269:*/
#line 2302 "./marpa.w"

ISYID t_isyid_array[1];

/*:269*/
#line 2282 "./marpa.w"

};
/*:264*//*313:*/
#line 2665 "./marpa.w"

struct sym_rule_pair
{
SYMID t_symid;
RULEID t_ruleid;
};

/*:313*//*384:*/
#line 4041 "./marpa.w"

struct s_AHFA_item{
int t_sort_key;
/*393:*/
#line 4090 "./marpa.w"

IRL t_irl;

/*:393*/
#line 4044 "./marpa.w"

/*394:*/
#line 4096 "./marpa.w"

int t_position;

/*:394*//*395:*/
#line 4103 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:395*//*396:*/
#line 4112 "./marpa.w"

int t_leading_nulls;

/*:396*/
#line 4045 "./marpa.w"

};
/*:384*//*425:*/
#line 4419 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*429:*/
#line 4446 "./marpa.w"

SYMID*t_complete_symbols;

/*:429*//*431:*/
#line 4453 "./marpa.w"

AIM*t_items;
/*:431*//*448:*/
#line 4544 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:448*//*508:*/
#line 5598 "./marpa.w"

TRANS*t_transitions;
/*:508*/
#line 4426 "./marpa.w"

/*428:*/
#line 4444 "./marpa.w"

unsigned int t_complete_symbol_count;
/*:428*//*432:*/
#line 4456 "./marpa.w"

int t_item_count;
/*:432*//*449:*/
#line 4545 "./marpa.w"
unsigned int t_postdot_sym_count;

/*:449*//*455:*/
#line 4606 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:455*/
#line 4427 "./marpa.w"

/*436:*/
#line 4497 "./marpa.w"

unsigned int t_is_predict:1;

/*:436*//*439:*/
#line 4505 "./marpa.w"

unsigned int t_is_potential_leo_base:1;
/*:439*/
#line 4428 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:425*//*507:*/
#line 5587 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
int t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:507*//*523:*/
#line 5742 "./marpa.w"

struct s_input{
/*532:*/
#line 5813 "./marpa.w"

struct obstack t_token_obs;

/*:532*//*534:*/
#line 5818 "./marpa.w"

GRAMMAR t_grammar;
/*:534*/
#line 5744 "./marpa.w"

/*526:*/
#line 5759 "./marpa.w"

int t_ref_count;
/*:526*/
#line 5745 "./marpa.w"

};

/*:523*//*613:*/
#line 6279 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:613*//*614:*/
#line 6284 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
int t_postdot_sym_count;
/*615:*/
#line 6296 "./marpa.w"

int t_eim_count;
/*:615*//*617:*/
#line 6310 "./marpa.w"

int t_ordinal;
/*:617*/
#line 6288 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*616:*/
#line 6299 "./marpa.w"

EIM*t_earley_items;

/*:616*//*1174:*/
#line 13419 "./marpa.w"

PSL t_dot_psl;
/*:1174*/
#line 6291 "./marpa.w"

};

/*:614*//*657:*/
#line 6781 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:657*//*660:*/
#line 6815 "./marpa.w"

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

/*:660*//*670:*/
#line 6954 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:670*//*741:*/
#line 7939 "./marpa.w"

struct s_token_unvalued{
int t_type;
ISYID t_isyid;
};
struct s_token{
struct s_token_unvalued t_unvalued;
int t_value;
};

/*:741*//*745:*/
#line 7968 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:745*//*844:*/
#line 9161 "./marpa.w"

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
/*:844*//*874:*/
#line 9610 "./marpa.w"

struct s_draft_or_node
{
/*873:*/
#line 9604 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:873*/
#line 9613 "./marpa.w"

DAND t_draft_and_node;
};
/*:874*//*875:*/
#line 9616 "./marpa.w"

struct s_final_or_node
{
/*873:*/
#line 9604 "./marpa.w"

int t_position;
int t_end_set_ordinal;
IRL t_irl;
int t_start_set_ordinal;
ORID t_id;
/*:873*/
#line 9619 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};
/*:875*//*876:*/
#line 9628 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:876*//*899:*/
#line 10016 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:899*//*925:*/
#line 10431 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:925*//*953:*/
#line 10719 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:953*//*986:*/
#line 11071 "./marpa.w"

struct marpa_order{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
/*989:*/
#line 11090 "./marpa.w"

BOCAGE t_bocage;

/*:989*/
#line 11076 "./marpa.w"

/*992:*/
#line 11109 "./marpa.w"
int t_ref_count;
/*:992*/
#line 11077 "./marpa.w"

/*1003:*/
#line 11200 "./marpa.w"

unsigned int t_is_nulling:1;

/*:1003*/
#line 11078 "./marpa.w"

unsigned int t_is_frozen:1;
};
/*:986*//*1012:*/
#line 11400 "./marpa.w"

/*1051:*/
#line 11874 "./marpa.w"

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

/*:1051*/
#line 11401 "./marpa.w"

/*1065:*/
#line 12013 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1072:*/
#line 12100 "./marpa.w"

DSTACK_DECLARE(t_virtual_stack);
/*:1072*//*1093:*/
#line 12250 "./marpa.w"

Bit_Vector t_nulling_ask_bv;
/*:1093*/
#line 12017 "./marpa.w"

/*1076:*/
#line 12134 "./marpa.w"

int t_ref_count;
/*:1076*//*1089:*/
#line 12228 "./marpa.w"

NOOKID t_nook;
/*:1089*/
#line 12018 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1084:*/
#line 12200 "./marpa.w"

unsigned int t_is_nulling:1;
/*:1084*//*1086:*/
#line 12207 "./marpa.w"

unsigned int t_trace:1;
/*:1086*/
#line 12021 "./marpa.w"

};

/*:1065*/
#line 11402 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_and_node_in_use;
Marpa_Order t_order;
/*1018:*/
#line 11472 "./marpa.w"

int t_ref_count;
/*:1018*//*1025:*/
#line 11552 "./marpa.w"
int t_pause_counter;
/*:1025*/
#line 11408 "./marpa.w"

/*1033:*/
#line 11644 "./marpa.w"

unsigned int t_is_exhausted:1;
/*:1033*//*1036:*/
#line 11652 "./marpa.w"

unsigned int t_is_nulling:1;

/*:1036*/
#line 11409 "./marpa.w"

int t_parse_count;
};

/*:1012*//*1158:*/
#line 13272 "./marpa.w"

struct s_dqueue{int t_current;struct s_dstack t_stack;};

/*:1158*//*1165:*/
#line 13340 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1165*//*1167:*/
#line 13365 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1167*/
#line 14167 "./marpa.w"

/*538:*/
#line 5834 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*551:*/
#line 5939 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:551*//*563:*/
#line 6002 "./marpa.w"
void**t_sym_workarea;
/*:563*//*567:*/
#line 6013 "./marpa.w"
void**t_workarea2;
/*:567*//*571:*/
#line 6030 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:571*//*575:*/
#line 6056 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:575*//*598:*/
#line 6217 "./marpa.w"
struct obstack t_obs;
/*:598*//*623:*/
#line 6360 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:623*//*644:*/
#line 6622 "./marpa.w"

EIM t_trace_earley_item;
/*:644*//*674:*/
#line 7003 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:674*//*708:*/
#line 7460 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:708*//*746:*/
#line 7976 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:746*//*768:*/
#line 8303 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:768*//*772:*/
#line 8314 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:772*//*776:*/
#line 8325 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:776*//*845:*/
#line 9174 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:845*//*1168:*/
#line 13373 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1168*/
#line 5837 "./marpa.w"

/*541:*/
#line 5863 "./marpa.w"
int t_ref_count;
/*:541*//*555:*/
#line 5966 "./marpa.w"
int t_earley_item_warning_threshold;
/*:555*//*559:*/
#line 5989 "./marpa.w"
EARLEME t_furthest_earleme;
/*:559*//*618:*/
#line 6314 "./marpa.w"

int t_earley_set_count;
/*:618*/
#line 5838 "./marpa.w"

/*548:*/
#line 5931 "./marpa.w"

unsigned int t_input_phase:2;
/*:548*//*590:*/
#line 6155 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:590*//*594:*/
#line 6193 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:594*//*709:*/
#line 7463 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:709*/
#line 5839 "./marpa.w"

};

/*:538*/
#line 14168 "./marpa.w"

/*688:*/
#line 7197 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
TOK t_token;
}t_cause;
};

/*:688*//*690:*/
#line 7209 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:690*//*691:*/
#line 7215 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:691*//*692:*/
#line 7222 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:692*/
#line 14169 "./marpa.w"

/*637:*/
#line 6494 "./marpa.w"

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
/*642:*/
#line 6594 "./marpa.w"

unsigned int t_source_type:3;

/*:642*/
#line 6505 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:637*/
#line 14170 "./marpa.w"

/*940:*/
#line 10611 "./marpa.w"

struct marpa_bocage{
/*878:*/
#line 9646 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:878*//*942:*/
#line 10620 "./marpa.w"

INPUT t_input;

/*:942*//*944:*/
#line 10630 "./marpa.w"

struct obstack t_obs;
/*:944*/
#line 10613 "./marpa.w"

/*879:*/
#line 9649 "./marpa.w"

int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:879*//*966:*/
#line 10873 "./marpa.w"
int t_ref_count;
/*:966*/
#line 10614 "./marpa.w"

/*945:*/
#line 10632 "./marpa.w"

unsigned int t_is_obstack_initialized:1;
/*:945*//*973:*/
#line 10934 "./marpa.w"

unsigned int t_is_nulling:1;
/*:973*/
#line 10615 "./marpa.w"

};

/*:940*/
#line 14171 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1234:*/
#line 13995 "./marpa.w"

static const char*eim_tag_safe(char*buffer,EIM eim)UNUSED;
static const char*eim_tag(EIM eim)UNUSED;
/*:1234*//*1236:*/
#line 14020 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1236*//*1238:*/
#line 14046 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1238*//*1240:*/
#line 14078 "./marpa.w"

static const char*aim_tag_safe(char*buffer,AIM aim)UNUSED;
static const char*aim_tag(AIM aim)UNUSED;
/*:1240*/
#line 14174 "./marpa.w"

/*1225:*/
#line 13910 "./marpa.w"

int _marpa_default_debug_handler(const char*format,...)
{
va_list args;
va_start(args,format);
vfprintf(stderr,format,args);
va_end(args);
putc('\n',stderr);
return 1;
}


/*:1225*//*1235:*/
#line 13999 "./marpa.w"

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

/*:1235*//*1237:*/
#line 14025 "./marpa.w"

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

/*:1237*//*1239:*/
#line 14050 "./marpa.w"

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

/*:1239*//*1241:*/
#line 14081 "./marpa.w"

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

/*:1241*/
#line 14175 "./marpa.w"

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
#line 740 "./marpa.w"

DSTACK_INIT2(g->t_xrl_stack,RULE);
DSTACK_SAFE(g->t_irl_stack);
g->t_rule_tree= _marpa_avl_create(duplicate_rule_cmp,NULL,alignof(RULE));

/*:60*//*71:*/
#line 796 "./marpa.w"

g->t_start_xsyid= -1;
/*:71*//*75:*/
#line 825 "./marpa.w"

g->t_start_irl= NULL;
/*:75*//*79:*/
#line 842 "./marpa.w"

External_Size_of_G(g)= 0;

/*:79*//*82:*/
#line 855 "./marpa.w"

g->t_max_rule_length= 0;

/*:82*//*85:*/
#line 861 "./marpa.w"

g->t_is_precomputed= 0;
/*:85*//*88:*/
#line 873 "./marpa.w"

g->t_has_cycle= 0;
/*:88*//*91:*/
#line 893 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:91*//*98:*/
#line 931 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:98*//*105:*/
#line 989 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL,0);
/*:105*//*109:*/
#line 1013 "./marpa.w"

my_obstack_init(&g->t_obs);
my_obstack_begin(&g->t_xrl_obs,0,alignof(struct s_xrl));
/*:109*//*116:*/
#line 1059 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:116*//*390:*/
#line 4073 "./marpa.w"

g->t_AHFA_items= NULL;
/*:390*//*444:*/
#line 4517 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:444*/
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
#line 749 "./marpa.w"

DSTACK_DESTROY(g->t_irl_stack);
DSTACK_DESTROY(g->t_xrl_stack);
/*61:*/
#line 745 "./marpa.w"

_marpa_avl_destroy(g->t_rule_tree);
g->t_rule_tree= NULL;

/*:61*/
#line 752 "./marpa.w"


/*:62*//*92:*/
#line 894 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:92*//*99:*/
#line 933 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:99*//*107:*/
#line 996 "./marpa.w"

/*106:*/
#line 991 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:106*/
#line 997 "./marpa.w"


/*:107*//*110:*/
#line 1016 "./marpa.w"

my_obstack_free(&g->t_obs);
my_obstack_free(&g->t_xrl_obs);

/*:110*//*391:*/
#line 4075 "./marpa.w"

my_free(g->t_AHFA_items);

/*:391*//*445:*/
#line 4521 "./marpa.w"

{
if(g->t_AHFA)
{
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}
}

/*:445*/
#line 670 "./marpa.w"

my_slice_free(struct marpa_g,g);
}

/*:49*//*54:*/
#line 696 "./marpa.w"

int marpa_g_symbol_count(Marpa_Grammar g){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 698 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 699 "./marpa.w"

return SYM_Count_of_G(g);
}

/*:54*//*56:*/
#line 709 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,SYM symbol)
{
const SYMID new_id= DSTACK_LENGTH((g)->t_xsy_stack);
*DSTACK_PUSH((g)->t_xsy_stack,SYM)= symbol;
symbol->t_symbol_id= new_id;
}

/*:56*//*57:*/
#line 719 "./marpa.w"

PRIVATE int symbol_is_valid(GRAMMAR g,SYMID symid)
{
return symid>=0&&symid<SYM_Count_of_G(g);
}

/*:57*//*58:*/
#line 726 "./marpa.w"

PRIVATE int isy_is_valid(GRAMMAR g,ISYID isyid)
{
return isyid>=0&&isyid<ISY_Count_of_G(g);
}

/*:58*//*66:*/
#line 757 "./marpa.w"

int marpa_g_rule_count(Marpa_Grammar g){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 759 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 760 "./marpa.w"

return XRL_Count_of_G(g);
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 764 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 765 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:66*//*68:*/
#line 776 "./marpa.w"

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
#line 798 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 801 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 802 "./marpa.w"

return g->t_start_xsyid;
}
/*:72*//*73:*/
#line 807 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 810 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 811 "./marpa.w"

/*1206:*/
#line 13728 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1206*/
#line 812 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 813 "./marpa.w"

return g->t_start_xsyid= symid;
}

/*:73*//*86:*/
#line 863 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 866 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 867 "./marpa.w"

return G_is_Precomputed(g);
}

/*:86*//*89:*/
#line 875 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 878 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 879 "./marpa.w"

return g->t_has_cycle;
}

/*:89*//*101:*/
#line 943 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:101*//*102:*/
#line 952 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:102*//*103:*/
#line 962 "./marpa.w"

int
marpa_g_event(Marpa_Grammar g,Marpa_Event public_event,
int ix)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 967 "./marpa.w"

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
#line 1070 "./marpa.w"

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
#line 1106 "./marpa.w"

PRIVATE SYM
symbol_new(GRAMMAR g,XSY source)
{
SYM symbol= my_obstack_new(&g->t_obs,struct s_xsy,1);
/*127:*/
#line 1131 "./marpa.w"

SYM_is_LHS(symbol)= 0;

/*:127*//*129:*/
#line 1138 "./marpa.w"

SYM_is_Sequence_LHS(symbol)= 0;

/*:129*//*131:*/
#line 1146 "./marpa.w"

SYM_is_Semantic(symbol)= 1;
/*:131*//*134:*/
#line 1168 "./marpa.w"

SYM_is_Ask_Me_When_Null(symbol)= 0;
/*:134*//*137:*/
#line 1193 "./marpa.w"

symbol->t_is_accessible= 0;
/*:137*//*140:*/
#line 1213 "./marpa.w"

symbol->t_is_counted= 0;
/*:140*//*143:*/
#line 1229 "./marpa.w"

symbol->t_is_nulling= 0;
/*:143*//*146:*/
#line 1245 "./marpa.w"

symbol->t_is_nullable= 0;
/*:146*//*149:*/
#line 1267 "./marpa.w"

symbol->t_is_terminal= 0;
symbol->t_is_marked_terminal= 0;
/*:149*//*154:*/
#line 1304 "./marpa.w"

symbol->t_is_productive= 0;
/*:154*//*157:*/
#line 1320 "./marpa.w"
symbol->t_is_start= 0;
/*:157*//*160:*/
#line 1341 "./marpa.w"
ISY_of_XSY(symbol)= NULL;
/*:160*//*163:*/
#line 1369 "./marpa.w"
Nulling_ISY_of_XSY(symbol)= NULL;
/*:163*//*166:*/
#line 1393 "./marpa.w"
Source_XSY_of_SYM(symbol)= NULL;
/*:166*/
#line 1111 "./marpa.w"

Source_XSY_of_SYM(symbol)= source?source:symbol;
symbol_add(g,symbol);
return symbol;
}

/*:124*//*125:*/
#line 1117 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const SYM symbol= symbol_new(g,0);
return ID_of_SYM(symbol);
}

/*:125*//*132:*/
#line 1148 "./marpa.w"

int _marpa_g_symbol_is_semantic(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1153 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1154 "./marpa.w"

return SYM_is_Semantic(SYM_by_ID(symid));
}

/*:132*//*135:*/
#line 1170 "./marpa.w"

int marpa_g_symbol_is_ask_me_when_null(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1175 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1176 "./marpa.w"

return SYM_is_Ask_Me_When_Null(SYM_by_ID(symid));
}
int marpa_g_symbol_ask_me_when_null_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1183 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1184 "./marpa.w"

symbol= SYM_by_ID(symid);
return SYM_is_Ask_Me_When_Null(symbol)= value?1:0;
}

/*:135*//*138:*/
#line 1201 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1204 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1205 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 1206 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1207 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(symid));
}

/*:138*//*141:*/
#line 1215 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1219 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1220 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1221 "./marpa.w"

return SYM_by_ID(symid)->t_is_counted;
}

/*:141*//*144:*/
#line 1231 "./marpa.w"

int marpa_g_symbol_is_nulling(GRAMMAR g,SYMID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1234 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1235 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 1236 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1237 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));
}

/*:144*//*147:*/
#line 1247 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1250 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1251 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 1252 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1253 "./marpa.w"

return XSY_is_Nullable(SYM_by_ID(symid));
}

/*:147*//*151:*/
#line 1273 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1277 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1278 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1279 "./marpa.w"

return SYMID_is_Terminal(symid);
}
/*:151*//*152:*/
#line 1282 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1287 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1288 "./marpa.w"

/*1206:*/
#line 13728 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1206*/
#line 1289 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1290 "./marpa.w"

symbol= SYM_by_ID(symid);
if(UNLIKELY(value<0||value> 1)){
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
SYM_is_Marked_Terminal(symbol)= 1;
return SYM_is_Terminal(symbol)= value;
}

/*:152*//*155:*/
#line 1306 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1311 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1312 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 1313 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1314 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(symid));
}

/*:155*//*158:*/
#line 1321 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1324 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1325 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1326 "./marpa.w"

return SYM_by_ID(symid)->t_is_start;
}

/*:158*//*161:*/
#line 1342 "./marpa.w"

Marpa_ISY_ID _marpa_g_xsy_isy(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
XSY xsy;
ISY isy;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1349 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1350 "./marpa.w"

xsy= XSY_by_ID(symid);
isy= ISY_of_XSY(xsy);
return isy?ID_of_ISY(isy):-1;
}

/*:161*//*164:*/
#line 1370 "./marpa.w"

Marpa_ISY_ID _marpa_g_xsy_nulling_isy(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
XSY xsy;
ISY isy;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1377 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 1378 "./marpa.w"

xsy= XSY_by_ID(symid);
isy= Nulling_ISY_of_XSY(xsy);
return isy?ID_of_ISY(isy):-1;
}

/*:164*//*167:*/
#line 1394 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_IRL_ID isy_id)
{
XSY source_xsy;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1400 "./marpa.w"

/*1209:*/
#line 13744 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1209*/
#line 1401 "./marpa.w"

source_xsy= Source_XSY_of_ISY(ISY_by_ID(isy_id));
return source_xsy?ID_of_XSY(source_xsy):-1;
}

/*:167*//*169:*/
#line 1412 "./marpa.w"

PRIVATE
ISY symbol_alias_create(GRAMMAR g,SYM symbol)
{
ISY alias_isy= isy_new(g,symbol);
SYM alias= Buddy_of_ISY(alias_isy);
SYM_is_Nulling(symbol)= 0;
XSY_is_Nullable(symbol)= 1;
SYM_is_Nulling(alias)= 1;
ISY_is_Nulling(alias_isy)= 1;
XSY_is_Nullable(alias)= 1;
SYM_is_Ask_Me_When_Null(alias)
= SYM_is_Ask_Me_When_Null(symbol);
alias->t_is_productive= 1;
alias->t_is_accessible= symbol->t_is_accessible;
return alias_isy;
}

/*:169*//*176:*/
#line 1465 "./marpa.w"

PRIVATE ISY
isy_start(GRAMMAR g)
{
const ISY isy= my_obstack_new(&g->t_obs,struct s_isy,1);
ID_of_ISY(isy)= DSTACK_LENGTH((g)->t_isy_stack);
*DSTACK_PUSH((g)->t_isy_stack,ISY)= isy;
/*174:*/
#line 1460 "./marpa.w"

isy->t_or_node_type= NULLING_TOKEN_OR_NODE;

/*:174*//*186:*/
#line 1537 "./marpa.w"
ISY_is_Start(isy)= 0;
/*:186*//*189:*/
#line 1551 "./marpa.w"
ISY_is_LHS(isy)= 0;
/*:189*//*192:*/
#line 1565 "./marpa.w"
ISY_is_Nulling(isy)= 0;
/*:192*//*196:*/
#line 1587 "./marpa.w"

LHS_XRL_of_ISY(isy)= NULL;
XRL_Offset_of_ISY(isy)= -1;

/*:196*/
#line 1472 "./marpa.w"

return isy;
}

/*:176*//*177:*/
#line 1477 "./marpa.w"

PRIVATE ISY
isy_new(GRAMMAR g,XSY source)
{
const XSY xsy= symbol_new(g,source);
const ISY new_isy= isy_start(g);
Buddy_of_ISY(new_isy)= xsy;
ISY_of_XSY(xsy)= new_isy;
return new_isy;
}

/*:177*//*178:*/
#line 1489 "./marpa.w"

PRIVATE ISY
isy_clone(GRAMMAR g,XSY xsy)
{
const ISY new_isy= isy_start(g);
Buddy_of_ISY(new_isy)= xsy;
ISY_is_Nulling(new_isy)= XSY_is_Nulling(xsy);
return new_isy;
}

/*:178*//*181:*/
#line 1507 "./marpa.w"

Marpa_Symbol_ID _marpa_g_isy_buddy(
Marpa_Grammar g,
Marpa_ISY_ID isy_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1512 "./marpa.w"

/*1209:*/
#line 13744 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1209*/
#line 1513 "./marpa.w"

return ID_of_XSY(Buddy_of_ISY(ISY_by_ID(isy_id)));
}

/*:181*//*184:*/
#line 1527 "./marpa.w"

int _marpa_g_isy_count(Marpa_Grammar g){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1529 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1530 "./marpa.w"

return ISY_Count_of_G(g);
}

/*:184*//*187:*/
#line 1538 "./marpa.w"

int _marpa_g_isy_is_start(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1541 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1542 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 1543 "./marpa.w"

/*1209:*/
#line 13744 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1209*/
#line 1544 "./marpa.w"

return ISY_is_Start(ISY_by_ID(isy_id));
}

/*:187*//*190:*/
#line 1552 "./marpa.w"

int _marpa_g_isy_is_lhs(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1555 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1556 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 1557 "./marpa.w"

/*1209:*/
#line 13744 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1209*/
#line 1558 "./marpa.w"

return ISY_is_LHS(ISY_by_ID(isy_id));
}

/*:190*//*193:*/
#line 1566 "./marpa.w"

int _marpa_g_isy_is_nulling(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1569 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1570 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 1571 "./marpa.w"

/*1209:*/
#line 13744 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1209*/
#line 1572 "./marpa.w"

return ISY_is_Nulling(ISY_by_ID(isy_id));
}

/*:193*//*198:*/
#line 1598 "./marpa.w"

Marpa_Rule_ID _marpa_g_isy_lhs_xrl(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1601 "./marpa.w"

/*1209:*/
#line 13744 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1209*/
#line 1602 "./marpa.w"

{
const ISY isy= ISY_by_ID(isy_id);
const XRL lhs_xrl= LHS_XRL_of_ISY(isy);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:198*//*199:*/
#line 1622 "./marpa.w"

int _marpa_g_isy_xrl_offset(Marpa_Grammar g,Marpa_ISY_ID isy_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1625 "./marpa.w"

ISY isy;
/*1209:*/
#line 13744 "./marpa.w"

if(UNLIKELY(!isy_is_valid(g,isy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_ISYID);
return failure_indicator;
}
/*:1209*/
#line 1627 "./marpa.w"

isy= ISY_by_ID(isy_id);
return XRL_Offset_of_ISY(isy);
}

/*:199*//*205:*/
#line 1663 "./marpa.w"

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
/*226:*/
#line 2012 "./marpa.w"

rule->t_is_bnf= 0;

/*:226*//*228:*/
#line 2019 "./marpa.w"

rule->t_is_sequence= 0;
/*:228*//*231:*/
#line 2037 "./marpa.w"

rule->t_minimum= -1;

/*:231*//*233:*/
#line 2045 "./marpa.w"

Separator_of_XRL(rule)= -1;

/*:233*//*237:*/
#line 2064 "./marpa.w"

rule->t_is_discard= 0;
/*:237*//*241:*/
#line 2103 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:241*//*245:*/
#line 2123 "./marpa.w"

rule->t_is_loop= 0;
/*:245*//*248:*/
#line 2139 "./marpa.w"

XRL_is_Nulling(rule)= 0;

/*:248*//*251:*/
#line 2146 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:251*//*254:*/
#line 2163 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:254*//*258:*/
#line 2204 "./marpa.w"

XRL_is_Ask_Me(rule)= 0;
/*:258*/
#line 1688 "./marpa.w"

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

/*:205*//*206:*/
#line 1704 "./marpa.w"

PRIVATE IRL
irl_start(GRAMMAR g,int length)
{
IRL irl;
const int sizeof_irl= offsetof(struct s_irl,t_isyid_array)+
(length+1)*sizeof(irl->t_isyid_array[0]);
irl= my_obstack_alloc(&g->t_obs,sizeof_irl);
ID_of_IRL(irl)= DSTACK_LENGTH((g)->t_irl_stack);
Length_of_IRL(irl)= length;
/*277:*/
#line 2359 "./marpa.w"

IRL_has_Virtual_LHS(irl)= 0;
/*:277*//*280:*/
#line 2375 "./marpa.w"

IRL_has_Virtual_RHS(irl)= 0;
/*:280*//*284:*/
#line 2396 "./marpa.w"
Real_SYM_Count_of_IRL(irl)= 0;
/*:284*//*287:*/
#line 2414 "./marpa.w"
irl->t_virtual_start= -1;
/*:287*//*290:*/
#line 2434 "./marpa.w"
irl->t_virtual_end= -1;
/*:290*//*293:*/
#line 2456 "./marpa.w"
Source_XRL_of_IRL(irl)= NULL;
/*:293*//*296:*/
#line 2478 "./marpa.w"

First_AIM_of_IRL(irl)= NULL;

/*:296*//*300:*/
#line 2494 "./marpa.w"

Last_Proper_SYMI_of_IRL(irl)= -1;
/*:300*/
#line 1714 "./marpa.w"

*DSTACK_PUSH((g)->t_irl_stack,IRL)= irl;
return irl;
}

PRIVATE void
irl_finish(GRAMMAR g,IRL irl)
{
const ISY lhs_isy= LHS_of_IRL(irl);
const XSY lhs_xsy= Buddy_of_ISY(lhs_isy);
ISY_is_LHS(lhs_isy)= 1;
XSY_is_LHS(lhs_xsy)= 1;
}

/*:206*//*208:*/
#line 1741 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,int length)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1746 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1749 "./marpa.w"

/*1206:*/
#line 13728 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1206*/
#line 1750 "./marpa.w"

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

/*:208*//*209:*/
#line 1774 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1781 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1782 "./marpa.w"

/*1206:*/
#line 13728 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1206*/
#line 1783 "./marpa.w"

/*211:*/
#line 1814 "./marpa.w"

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

/*:211*/
#line 1784 "./marpa.w"

/*210:*/
#line 1792 "./marpa.w"

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

/*:210*/
#line 1785 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:209*//*213:*/
#line 1867 "./marpa.w"

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

/*:213*//*216:*/
#line 1922 "./marpa.w"

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

/*:216*//*217:*/
#line 1954 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:217*//*218:*/
#line 1958 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1960 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1961 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 1962 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:218*//*219:*/
#line 1965 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:219*//*220:*/
#line 1969 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1972 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1973 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 1974 "./marpa.w"

rule= XRL_by_ID(xrl_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:220*//*221:*/
#line 1979 "./marpa.w"

PRIVATE size_t rule_length_get(RULE rule)
{
return Length_of_RULE(rule);}
/*:221*//*222:*/
#line 1983 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 1985 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 1986 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 1987 "./marpa.w"

return rule_length_get(XRL_by_ID(xrl_id));}

/*:222*//*229:*/
#line 2021 "./marpa.w"

int marpa_g_rule_is_sequence(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2026 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2027 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2028 "./marpa.w"

return XRL_is_Sequence(XRL_by_ID(xrl_id));
}


/*:229*//*238:*/
#line 2066 "./marpa.w"

int marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2071 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2072 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2073 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:238*//*242:*/
#line 2105 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2110 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2111 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2112 "./marpa.w"

return!XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:242*//*246:*/
#line 2125 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2128 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2129 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2130 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 2131 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:246*//*252:*/
#line 2148 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2151 "./marpa.w"

XRL xrl;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2153 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2154 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:252*//*255:*/
#line 2165 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2168 "./marpa.w"

XRL xrl;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2170 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2171 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:255*//*256:*/
#line 2181 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2185 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2186 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:256*//*259:*/
#line 2206 "./marpa.w"

int marpa_g_rule_is_ask_me(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2211 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2212 "./marpa.w"

return XRL_is_Ask_Me(XRL_by_ID(xrl_id));
}
/*:259*//*260:*/
#line 2231 "./marpa.w"

int marpa_g_rule_whatever_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2236 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2237 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Ask_Me(xrl)= 0;
}
int marpa_g_rule_ask_me_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2245 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2246 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Ask_Me(xrl)= 1;
}
int marpa_g_rule_first_child_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2254 "./marpa.w"

/*1211:*/
#line 13754 "./marpa.w"

if(UNLIKELY(!XRLID_of_G_is_Valid(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_XRLID);
return failure_indicator;
}
/*:1211*/
#line 2255 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Ask_Me(xrl)= 0;
}

/*:260*//*262:*/
#line 2263 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2268 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2269 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:262*//*271:*/
#line 2308 "./marpa.w"

Marpa_ISY_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
IRL irl;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2311 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2312 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2313 "./marpa.w"

irl= IRL_by_ID(irl_id);
return LHSID_of_IRL(irl);
}

/*:271*//*273:*/
#line 2320 "./marpa.w"

Marpa_ISY_ID _marpa_g_irl_rh_symbol(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2323 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2324 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2325 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHSID_of_IRL(irl,ix);
}

/*:273*//*275:*/
#line 2333 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2335 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2336 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2337 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}

/*:275*//*278:*/
#line 2361 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2366 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 2367 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2368 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:278*//*281:*/
#line 2377 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2382 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 2383 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2384 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:281*//*285:*/
#line 2397 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2402 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 2403 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2404 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:285*//*288:*/
#line 2415 "./marpa.w"

unsigned int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2421 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 2422 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2423 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:288*//*291:*/
#line 2435 "./marpa.w"

unsigned int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2441 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 2442 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2443 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:291*//*294:*/
#line 2457 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2463 "./marpa.w"

/*1210:*/
#line 13749 "./marpa.w"

if(UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1210*/
#line 2464 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:294*//*302:*/
#line 2508 "./marpa.w"

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

/*:302*//*304:*/
#line 2540 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 2543 "./marpa.w"

int return_value= failure_indicator;
struct obstack obs_precompute;
/*308:*/
#line 2628 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);

/*:308*//*312:*/
#line 2661 "./marpa.w"

XSYID start_xsyid= g->t_start_xsyid;

/*:312*//*324:*/
#line 2952 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:324*/
#line 2546 "./marpa.w"

my_obstack_init(&obs_precompute);
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 2548 "./marpa.w"

G_EVENTS_CLEAR(g);
/*309:*/
#line 2632 "./marpa.w"

if(UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
return failure_indicator;
}

/*:309*/
#line 2550 "./marpa.w"

/*1206:*/
#line 13728 "./marpa.w"

if(UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1206*/
#line 2551 "./marpa.w"

/*311:*/
#line 2642 "./marpa.w"

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

/*:311*/
#line 2552 "./marpa.w"


g->t_is_precomputed= 1;
/*106:*/
#line 991 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:106*/
#line 2555 "./marpa.w"


{
/*317:*/
#line 2837 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:317*//*318:*/
#line 2840 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;
RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:318*//*322:*/
#line 2901 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:322*/
#line 2558 "./marpa.w"

/*307:*/
#line 2615 "./marpa.w"

{
/*315:*/
#line 2685 "./marpa.w"

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

/*:315*/
#line 2617 "./marpa.w"

/*316:*/
#line 2808 "./marpa.w"

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

/*:316*/
#line 2618 "./marpa.w"

/*323:*/
#line 2923 "./marpa.w"

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

/*:323*/
#line 2619 "./marpa.w"

/*319:*/
#line 2846 "./marpa.w"

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

/*:319*/
#line 2620 "./marpa.w"

/*320:*/
#line 2874 "./marpa.w"

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

/*:320*/
#line 2621 "./marpa.w"

/*321:*/
#line 2895 "./marpa.w"

if(UNLIKELY(!bv_bit_test(productive_v,(unsigned int)start_xsyid)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:321*/
#line 2622 "./marpa.w"

/*325:*/
#line 2957 "./marpa.w"

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

/*:325*/
#line 2623 "./marpa.w"

/*326:*/
#line 2977 "./marpa.w"

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

/*:326*/
#line 2624 "./marpa.w"

/*327:*/
#line 3016 "./marpa.w"

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

/*:327*/
#line 2625 "./marpa.w"

}

/*:307*/
#line 2559 "./marpa.w"

/*374:*/
#line 3834 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(&obs_precompute,(unsigned int)xrl_count,
(unsigned int)xrl_count);
/*375:*/
#line 3855 "./marpa.w"

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
/*376:*/
#line 3898 "./marpa.w"

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

/*:376*/
#line 3876 "./marpa.w"

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

/*376:*/
#line 3898 "./marpa.w"

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

/*:376*/
#line 3889 "./marpa.w"

}
}
}
}

/*:375*/
#line 3840 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*377:*/
#line 3912 "./marpa.w"

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

/*:377*/
#line 3842 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:374*/
#line 2560 "./marpa.w"

}

/*478:*/
#line 5020 "./marpa.w"

DSTACK_INIT(g->t_irl_stack,IRL,2*DSTACK_CAPACITY(g->t_xrl_stack));

/*:478*/
#line 2563 "./marpa.w"

/*479:*/
#line 5028 "./marpa.w"

{
DSTACK_INIT(g->t_isy_stack,ISY,2*DSTACK_CAPACITY(g->t_xsy_stack));
}

/*:479*/
#line 2564 "./marpa.w"

/*339:*/
#line 3186 "./marpa.w"

{
/*340:*/
#line 3215 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:340*//*343:*/
#line 3273 "./marpa.w"

int factor_count;
int*factor_positions;
/*:343*/
#line 3188 "./marpa.w"

/*344:*/
#line 3276 "./marpa.w"

factor_positions= my_obstack_new(&obs_precompute,int,g->t_max_rule_length);

/*:344*/
#line 3189 "./marpa.w"

/*341:*/
#line 3221 "./marpa.w"

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

/*:341*/
#line 3190 "./marpa.w"

pre_chaf_rule_count= XRL_Count_of_G(g);
for(rule_id= 0;rule_id<pre_chaf_rule_count;rule_id++){

XRL rule= XRL_by_ID(rule_id);
XRL rewrite_xrl= rule;
const int rewrite_xrl_length= Length_of_XRL(rewrite_xrl);
int nullable_suffix_ix= 0;
if(XRL_is_Sequence(rule)&&XRL_is_Used(rule))
{
/*328:*/
#line 3041 "./marpa.w"

{
const SYMID lhs_id= LHS_ID_of_RULE(rule);
const ISY lhs_isy= ISY_by_XSYID(lhs_id);
const ISYID lhs_isyid= ID_of_ISY(lhs_isy);

const ISY internal_lhs_isy= isy_new(g,SYM_by_ID(lhs_id));
const ISYID internal_lhs_isyid= ID_of_ISY(internal_lhs_isy);
const SYM internal_lhs= Buddy_of_ISY(internal_lhs_isy);

const SYMID rhs_id= RHS_ID_of_RULE(rule,0);
const ISY rhs_isy= ISY_by_XSYID(rhs_id);
const ISYID rhs_isyid= ID_of_ISY(rhs_isy);

const SYMID separator_id= Separator_of_XRL(rule);
ISYID separator_isyid= -1;
if(separator_id>=0){
const ISY separator_isy= ISY_by_XSYID(separator_id);
separator_isyid= ID_of_ISY(separator_isy);
}

SYM_is_Semantic(internal_lhs)= 0;
LHS_XRL_of_ISY(internal_lhs_isy)= rule;
/*329:*/
#line 3072 "./marpa.w"

{
IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= lhs_isyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_isyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;

IRL_has_Virtual_RHS(rewrite_irl)= 1;
}

/*:329*/
#line 3064 "./marpa.w"

if(separator_isyid>=0&&!XRL_is_Proper_Separation(rule)){
/*330:*/
#line 3084 "./marpa.w"

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

/*:330*/
#line 3066 "./marpa.w"

}
/*331:*/
#line 3100 "./marpa.w"

{
const IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= internal_lhs_isyid;
RHSID_of_IRL(rewrite_irl,0)= rhs_isyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
IRL_has_Virtual_LHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= 1;
}
/*:331*/
#line 3068 "./marpa.w"

/*332:*/
#line 3110 "./marpa.w"

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

/*:332*/
#line 3069 "./marpa.w"

}

/*:328*/
#line 3200 "./marpa.w"

goto NEXT_XRL;
}
if(XRL_is_BNF(rule)&&XRL_is_Used(rule)){
/*342:*/
#line 3252 "./marpa.w"

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
/*:342*/
#line 3204 "./marpa.w"


if(factor_count> 0){
/*345:*/
#line 3280 "./marpa.w"

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
/*348:*/
#line 3321 "./marpa.w"

ISY chaf_virtual_isy;
ISYID chaf_virtual_isyid;
int first_factor_position= factor_positions[factor_position_ix];
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*346:*/
#line 3306 "./marpa.w"

{
SYM chaf_virtual_symbol;
const SYMID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_isy= isy_new(g,SYM_by_ID(chaf_xrl_lhs_id));
chaf_virtual_isyid= ID_of_ISY(chaf_virtual_isy);
chaf_virtual_symbol= Buddy_of_ISY(chaf_virtual_isy);
SYM_is_Semantic(chaf_virtual_symbol)= 0;
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
}

/*:346*/
#line 3329 "./marpa.w"

/*349:*/
#line 3348 "./marpa.w"

{
{
const int real_symbol_count= piece_end-piece_start+1;
/*354:*/
#line 3444 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3457 "./marpa.w"

}

/*:354*/
#line 3352 "./marpa.w"
;
}
/*350:*/
#line 3362 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3383 "./marpa.w"

}

/*:350*/
#line 3354 "./marpa.w"
;
{
const int real_symbol_count= piece_end-piece_start+1;
/*356:*/
#line 3488 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3511 "./marpa.w"

}

/*:356*/
#line 3357 "./marpa.w"
;
}
/*351:*/
#line 3391 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3428 "./marpa.w"

}
}

/*:351*/
#line 3359 "./marpa.w"
;
}

/*:349*/
#line 3330 "./marpa.w"

factor_position_ix++;
}else{
piece_end= second_factor_position;
/*346:*/
#line 3306 "./marpa.w"

{
SYM chaf_virtual_symbol;
const SYMID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_isy= isy_new(g,SYM_by_ID(chaf_xrl_lhs_id));
chaf_virtual_isyid= ID_of_ISY(chaf_virtual_isy);
chaf_virtual_symbol= Buddy_of_ISY(chaf_virtual_isy);
SYM_is_Semantic(chaf_virtual_symbol)= 0;
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
}

/*:346*/
#line 3334 "./marpa.w"

/*353:*/
#line 3434 "./marpa.w"

{
const int real_symbol_count= piece_end-piece_start+1;
/*354:*/
#line 3444 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3457 "./marpa.w"

}

/*:354*/
#line 3437 "./marpa.w"

/*355:*/
#line 3461 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3484 "./marpa.w"

}

/*:355*/
#line 3438 "./marpa.w"

/*356:*/
#line 3488 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3511 "./marpa.w"

}

/*:356*/
#line 3439 "./marpa.w"

/*357:*/
#line 3515 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3548 "./marpa.w"

}

/*:357*/
#line 3440 "./marpa.w"

}

/*:353*/
#line 3335 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_isy= chaf_virtual_isy;
current_lhs_isyid= chaf_virtual_isyid;
piece_start= piece_end+1;

/*:348*/
#line 3297 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*358:*/
#line 3553 "./marpa.w"

{
const int first_factor_position= factor_positions[factor_position_ix];
const int second_factor_position= factor_positions[factor_position_ix+1];
const int real_symbol_count= Length_of_RULE(rule)-piece_start;
piece_end= Length_of_RULE(rule)-1;
/*359:*/
#line 3566 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3578 "./marpa.w"

}

/*:359*/
#line 3559 "./marpa.w"

/*360:*/
#line 3582 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3604 "./marpa.w"

}

/*:360*/
#line 3560 "./marpa.w"

/*361:*/
#line 3608 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3630 "./marpa.w"

}

/*:361*/
#line 3561 "./marpa.w"

/*362:*/
#line 3635 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3669 "./marpa.w"

}
}

/*:362*/
#line 3562 "./marpa.w"

}

/*:358*/
#line 3300 "./marpa.w"

}else{
/*363:*/
#line 3674 "./marpa.w"

{
int real_symbol_count;
const int first_factor_position= factor_positions[factor_position_ix];
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*364:*/
#line 3685 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3697 "./marpa.w"

}

/*:364*/
#line 3680 "./marpa.w"

/*365:*/
#line 3702 "./marpa.w"

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
/*366:*/
#line 3735 "./marpa.w"

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

/*:366*/
#line 3727 "./marpa.w"

}
}

/*:365*/
#line 3681 "./marpa.w"

}

/*:363*/
#line 3302 "./marpa.w"

}
}

/*:345*/
#line 3207 "./marpa.w"

}else{
/*207:*/
#line 1728 "./marpa.w"

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

/*:207*/
#line 3209 "./marpa.w"

}
}
NEXT_XRL:;
}
}
/*:339*/
#line 2565 "./marpa.w"

/*368:*/
#line 3752 "./marpa.w"

{
const XSY start_xsy= SYM_by_ID(start_xsyid);
if(LIKELY(!SYM_is_Nulling(start_xsy))){
/*369:*/
#line 3760 "./marpa.w"
{
IRL new_start_irl;

XSYID new_start_xsyid= -1;
const ISY new_start_isy= isy_new(g,start_xsy);
const XSY new_start_xsy= Buddy_of_ISY(new_start_isy);
ISY_is_Start(new_start_isy)= 1;
new_start_xsyid= ID_of_SYM(new_start_xsy);
SYM_is_Semantic(new_start_xsy)= 0;
new_start_xsy->t_is_accessible= 1;
new_start_xsy->t_is_productive= 1;
new_start_xsy->t_is_start= 1;

start_xsy->t_is_start= 0;

new_start_irl= irl_start(g,1);
LHSID_of_IRL(new_start_irl)= ID_of_ISY(new_start_isy);
RHSID_of_IRL(new_start_irl,0)= ISYID_of_XSY(start_xsy);
irl_finish(g,new_start_irl);
IRL_has_Virtual_LHS(new_start_irl)= 1;
Real_SYM_Count_of_IRL(new_start_irl)= 1;
g->t_start_irl= new_start_irl;

}

/*:369*/
#line 3756 "./marpa.w"

}
}

/*:368*/
#line 2566 "./marpa.w"


if(!G_is_Trivial(g)){
/*477:*/
#line 5009 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
AIM*const item_list_working_buffer
= my_obstack_alloc(&obs_precompute,irl_count*sizeof(AIM));
const ISYID isy_count= ISY_Count_of_G(g);
const SYMID ins_count= SYM_Count_of_G(g);
RULEID**irl_list_x_lh_sym= NULL;

/*:477*/
#line 2570 "./marpa.w"

/*480:*/
#line 5033 "./marpa.w"

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
const XSY lhs_xsy= Buddy_of_ISY(ISY_by_ID(lhs_isyid));
p_sym_rule_pairs->t_symid= ID_of_XSY(lhs_xsy);
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

/*:480*/
#line 2571 "./marpa.w"

/*405:*/
#line 4162 "./marpa.w"

{
IRLID irl_id;
AIMID ahfa_item_count= 0;
AIM base_item;
AIM current_item;
unsigned int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*407:*/
#line 4215 "./marpa.w"

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

/*:407*/
#line 4171 "./marpa.w"

}
current_item= base_item= my_new(struct s_AHFA_item,ahfa_item_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*406:*/
#line 4190 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
ISYID rh_isyid= RHSID_of_IRL(irl,rhs_ix);
XSY rh_xsy= Buddy_of_ISY(ISY_by_ID(rh_isyid));
XSYID rh_xsyid= ID_of_XSY(rh_xsy);
if(!SYM_is_Nulling(rh_xsy))
{
Last_Proper_SYMI_of_IRL(irl)= symbol_instance_of_next_rule+rhs_ix;
/*408:*/
#line 4227 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_xsyid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:408*/
#line 4202 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*409:*/
#line 4236 "./marpa.w"

{
IRL_of_AIM(current_item)= irl;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:409*/
#line 4211 "./marpa.w"

current_item++;
}

/*:406*/
#line 4176 "./marpa.w"

{
SYMI_of_IRL(irl)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_IRL(irl);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(ahfa_item_count==current_item-base_item);
AIM_Count_of_G(g)= ahfa_item_count;
g->t_AHFA_items= my_renew(struct s_AHFA_item,base_item,ahfa_item_count);
/*410:*/
#line 4250 "./marpa.w"

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

/*:410*/
#line 4186 "./marpa.w"

/*415:*/
#line 4308 "./marpa.w"

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

/*:415*/
#line 4187 "./marpa.w"

}

/*:405*/
#line 2572 "./marpa.w"

/*461:*/
#line 4663 "./marpa.w"

{
/*462:*/
#line 4681 "./marpa.w"

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

/*:462*/
#line 4665 "./marpa.w"

/*463:*/
#line 4694 "./marpa.w"

/*464:*/
#line 4698 "./marpa.w"

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

/*:464*/
#line 4695 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:463*/
#line 4666 "./marpa.w"

/*489:*/
#line 5284 "./marpa.w"
{
Bit_Matrix isy_by_isy_matrix= 
matrix_obs_create(&obs_precompute,isy_count,isy_count);
/*490:*/
#line 5292 "./marpa.w"

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
XSYID to_xsyid;
ISYID from,to;
const IRL irl= IRL_by_ID(irl_id);

const AIM item= First_AIM_of_IRL(irl);
to_xsyid= Postdot_SYMID_of_AIM(item);

if(to_xsyid<0)
continue;

from= LHS_ISYID_of_AIM(item);
to= ISYID_by_XSYID(to_xsyid);
matrix_bit_set(isy_by_isy_matrix,(unsigned int)from,(unsigned int)to);
}
}

/*:490*/
#line 5287 "./marpa.w"

transitive_closure(isy_by_isy_matrix);
/*491:*/
#line 5327 "./marpa.w"
{
unsigned int*sort_key_by_irl_id= my_new(unsigned int,irl_count);
/*493:*/
#line 5349 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
irl_by_sort_key[irl_id]= IRL_by_ID(irl_id);
}
qsort(irl_by_sort_key,(int)irl_count,
sizeof(RULE),cmp_by_irl_sort_key);
}

/*:493*/
#line 5329 "./marpa.w"

/*495:*/
#line 5382 "./marpa.w"

{
IRLID sort_ordinal;
for(sort_ordinal= 0;sort_ordinal<irl_count;sort_ordinal++)
{
IRL irl= irl_by_sort_key[sort_ordinal];
sort_key_by_irl_id[ID_of_IRL(irl)]= sort_ordinal;
}
}

/*:495*/
#line 5330 "./marpa.w"

/*496:*/
#line 5392 "./marpa.w"

{
ISYID from_isyid;
prediction_matrix= 
matrix_obs_create(&obs_precompute,symbol_count_of_g,
irl_count);
for(from_isyid= 0;from_isyid<isy_count;from_isyid++)
{
XSYID from_xsyid= XSYID_by_ISYID(from_isyid);

unsigned int min,max,start;
for(start= 0;
bv_scan(matrix_row
(isy_by_isy_matrix,(unsigned int)from_isyid),
start,&min,&max);start= max+2)
{
ISYID to_isyid;
for(to_isyid= min;to_isyid<=(ISYID)max;to_isyid++)
{
XSYID to_xsyid= XSYID_by_ISYID(to_isyid);

RULEID*p_irl_x_lh_sym= irl_list_x_lh_sym[to_xsyid];
const RULEID*p_one_past_rules= irl_list_x_lh_sym[to_xsyid+1];
for(;p_irl_x_lh_sym<p_one_past_rules;p_irl_x_lh_sym++)
{

const RULEID rule_with_this_lhs_symbol= *p_irl_x_lh_sym;
unsigned int sort_ordinal= 
sort_key_by_irl_id[rule_with_this_lhs_symbol];
matrix_bit_set(prediction_matrix,
(unsigned int)from_xsyid,sort_ordinal);

}
}
}
}
}

/*:496*/
#line 5331 "./marpa.w"

my_free(sort_key_by_irl_id);
}

/*:491*/
#line 5289 "./marpa.w"

}

/*:489*/
#line 4667 "./marpa.w"

/*471:*/
#line 4838 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
const IRL start_irl= g->t_start_irl;
SYMID*postdot_symbol_ids;
AIM start_item;
AIM*item_list= my_obstack_alloc(&g->t_obs,sizeof(AIM));

start_item= First_AIM_of_IRL(start_irl);
item_list[0]= start_item;
AHFA_initialize(p_initial_state);
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= 1;
p_initial_state->t_key.t_id= 0;
AHFA_is_Predicted(p_initial_state)= 0;
TRANSs_of_AHFA(p_initial_state)= transitions_new(g,isy_count);
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

/*:471*/
#line 4668 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*465:*/
#line 4710 "./marpa.w"
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
/*474:*/
#line 4897 "./marpa.w"
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
transition_add(&obs_precompute,p_working_state,ISYID_by_SYMID(working_symbol),p_new_state);
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
TRANSs_of_AHFA(p_new_state)= transitions_new(g,isy_count);
transition_add(&obs_precompute,p_working_state,ISYID_by_SYMID(working_symbol),p_new_state);
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
SYMID lhs_isyid= LHS_ISYID_of_AIM(single_item_p);
SYMID*complete_symids= my_obstack_alloc(&g->t_obs,sizeof(SYMID));
*complete_symids= XSYID_by_ISYID(lhs_isyid);
Complete_SYMIDs_of_AHFA(p_new_state)= complete_symids;
completion_count_inc(&obs_precompute,p_new_state,lhs_isyid);
Complete_SYM_Count_of_AHFA(p_new_state)= 1;
p_new_state->t_postdot_sym_count= 0;
p_new_state->t_empty_transition= NULL;
/*476:*/
#line 4983 "./marpa.w"

{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYM_is_LHS(SYM_by_ID(predot_symid)))
{
Leo_LHS_ID_of_AHFA(p_new_state)= XSYID_by_ISYID(lhs_isyid);
}
}

/*:476*/
#line 4951 "./marpa.w"

}
}

/*:474*/
#line 4730 "./marpa.w"

}else{
/*481:*/
#line 5079 "./marpa.w"

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
transition_add(&obs_precompute,p_working_state,ISYID_by_SYMID(working_symbol),
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
TRANSs_of_AHFA(p_new_state)= transitions_new(g,isy_count);
/*482:*/
#line 5136 "./marpa.w"

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
ISYID complete_symbol_isyid= LHS_ISYID_of_AIM(item);
XSYID complete_symbol_xsyid= XSYID_by_ISYID(complete_symbol_isyid);
completion_count_inc(&obs_precompute,p_new_state,complete_symbol_isyid);
bv_bit_set(complete_v,(unsigned int)complete_symbol_xsyid);
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

/*:482*/
#line 5129 "./marpa.w"

transition_add(&obs_precompute,p_working_state,ISYID_by_SYMID(working_symbol),
p_new_state);
/*484:*/
#line 5216 "./marpa.w"

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

/*:484*/
#line 5133 "./marpa.w"

}

/*:481*/
#line 4732 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:465*/
#line 4670 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*466:*/
#line 4742 "./marpa.w"

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
TRANS new_transition= my_obstack_alloc(&g->t_obs,sizeof_transition);
LV_To_AHFA_of_TRANS(new_transition)= To_AHFA_of_TRANS(working_transition);
LV_Completion_Count_of_TRANS(new_transition)= 0;
transitions[isyid]= new_transition;
}
}
}
}

/*:466*/
#line 4675 "./marpa.w"

/*468:*/
#line 4796 "./marpa.w"

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
ISYID postdot_isyid= ISYID_by_SYMID(postdot);
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

/*:468*/
#line 4676 "./marpa.w"

/*467:*/
#line 4765 "./marpa.w"

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

/*:467*/
#line 4677 "./marpa.w"

/*469:*/
#line 4830 "./marpa.w"

my_free(irl_by_sort_key);
/*470:*/
#line 4834 "./marpa.w"

my_free(singleton_duplicates);
_marpa_avl_destroy(duplicates);

/*:470*/
#line 4832 "./marpa.w"


/*:469*/
#line 4678 "./marpa.w"

}

/*:461*/
#line 2573 "./marpa.w"

/*520:*/
#line 5722 "./marpa.w"
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

/*:520*/
#line 2574 "./marpa.w"

}
return_value= G_EVENT_COUNT(g);
FAILURE:;
my_obstack_free(&obs_precompute);
return return_value;
}
/*:304*//*314:*/
#line 2672 "./marpa.w"

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

/*:314*//*392:*/
#line 4079 "./marpa.w"

PRIVATE int aim_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:392*//*397:*/
#line 4116 "./marpa.w"

int _marpa_g_AHFA_item_count(Marpa_Grammar g){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 4118 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 4119 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:397*//*398:*/
#line 4123 "./marpa.w"

Marpa_IRL_ID _marpa_g_AHFA_item_irl(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 4126 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 4127 "./marpa.w"

/*1212:*/
#line 13759 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1212*/
#line 4128 "./marpa.w"

return IRLID_of_AIM(AIM_by_ID(item_id));
}

/*:398*//*400:*/
#line 4133 "./marpa.w"

int _marpa_g_AHFA_item_position(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 4136 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 4137 "./marpa.w"

/*1212:*/
#line 13759 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1212*/
#line 4138 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:400*//*402:*/
#line 4143 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_item_postdot(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 4146 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 4147 "./marpa.w"

/*1212:*/
#line 13759 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1212*/
#line 4148 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:402*//*403:*/
#line 4152 "./marpa.w"

int _marpa_g_AHFA_item_sort_key(Marpa_Grammar g,
Marpa_AHFA_Item_ID item_id){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 4155 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 4156 "./marpa.w"

/*1212:*/
#line 13759 "./marpa.w"

if(UNLIKELY(!aim_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}
/*:1212*/
#line 4157 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:403*//*412:*/
#line 4269 "./marpa.w"

PRIVATE_NOT_INLINE int cmp_by_aimid(const void*ap,
const void*bp)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:412*//*414:*/
#line 4284 "./marpa.w"

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

/*:414*//*426:*/
#line 4435 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*440:*/
#line 4507 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;

/*:440*//*456:*/
#line 4607 "./marpa.w"
Leo_LHS_ID_of_AHFA(ahfa)= -1;
/*:456*/
#line 4438 "./marpa.w"

}

/*:426*//*434:*/
#line 4468 "./marpa.w"

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

/*:434*//*447:*/
#line 4534 "./marpa.w"

PRIVATE int AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:447*//*450:*/
#line 4548 "./marpa.w"

int _marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:450*//*451:*/
#line 4553 "./marpa.w"

int
_marpa_g_AHFA_state_item_count(Marpa_Grammar g,AHFAID AHFA_state_id)
{/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 4556 "./marpa.w"

AHFA state;
/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 4558 "./marpa.w"

/*1213:*/
#line 13764 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1213*/
#line 4559 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:451*//*452:*/
#line 4566 "./marpa.w"

Marpa_AHFA_Item_ID _marpa_g_AHFA_state_item(Marpa_Grammar g,
AHFAID AHFA_state_id,
int item_ix){
AHFA state;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 4571 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 4572 "./marpa.w"

/*1213:*/
#line 13764 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1213*/
#line 4573 "./marpa.w"

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

/*:452*//*453:*/
#line 4586 "./marpa.w"

int _marpa_g_AHFA_state_is_predict(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 4590 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 4591 "./marpa.w"

/*1213:*/
#line 13764 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1213*/
#line 4592 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:453*//*457:*/
#line 4608 "./marpa.w"

Marpa_Symbol_ID _marpa_g_AHFA_state_leo_lhs_symbol(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 4611 "./marpa.w"

AHFA state;
/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 4613 "./marpa.w"

/*1213:*/
#line 13764 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1213*/
#line 4614 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:457*//*460:*/
#line 4635 "./marpa.w"

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

/*:460*//*483:*/
#line 5207 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,AVL_TREE duplicates)
{
const AHFA state_found= _marpa_avl_insert(duplicates,sought_state);
return state_found;
}

/*:483*//*494:*/
#line 5360 "./marpa.w"

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

/*:494*//*497:*/
#line 5430 "./marpa.w"

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
my_obstack_alloc(&g->t_obs,no_of_items_in_new_state*sizeof(AIM));
for(i= 0;i<no_of_items_in_new_state;i++)
{
final_aim_list[i]= item_list_working_buffer[i];
}
}
AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_empty_transition= NULL;
TRANSs_of_AHFA(p_new_state)= transitions_new(g,ISY_Count_of_G(g));
Complete_SYM_Count_of_AHFA(p_new_state)= 0;
/*498:*/
#line 5494 "./marpa.w"

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

/*:498*/
#line 5490 "./marpa.w"

return p_new_state;
}

/*:497*//*509:*/
#line 5600 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:509*//*510:*/
#line 5606 "./marpa.w"

PRIVATE int completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:510*//*511:*/
#line 5613 "./marpa.w"

PRIVATE
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,int aim_ix)
{
URTRANS transition;
transition= my_obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:511*//*512:*/
#line 5624 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g,int isy_count)
{
int isyid= 0;
TRANS*transitions= my_obstack_new(&g->t_obs,TRANS,isy_count);
while(isyid<isy_count)transitions[isyid++]= NULL;


return transitions;
}

/*:512*//*513:*/
#line 5635 "./marpa.w"

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

/*:513*//*514:*/
#line 5649 "./marpa.w"

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

/*:514*//*516:*/
#line 5664 "./marpa.w"

int _marpa_g_AHFA_state_transitions(Marpa_Grammar g,
Marpa_AHFA_State_ID AHFA_state_id,
int*buffer,
int buffer_size
){

/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 5671 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID isyid;
int isy_count;
int ix= 0;
const int max_ix= buffer_size/sizeof(*buffer);
const int max_results= max_ix/2;





/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 5684 "./marpa.w"

/*1213:*/
#line 13764 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1213*/
#line 5685 "./marpa.w"

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

/*:516*//*519:*/
#line 5705 "./marpa.w"

AHFAID _marpa_g_AHFA_state_empty_transition(Marpa_Grammar g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 5710 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 5711 "./marpa.w"

/*1213:*/
#line 13764 "./marpa.w"

if(UNLIKELY(!AHFA_state_id_is_valid(g,AHFA_state_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AHFA_ID);
return failure_indicator;
}

/*:1213*/
#line 5712 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:519*//*524:*/
#line 5748 "./marpa.w"

PRIVATE INPUT
input_new(GRAMMAR g)
{
INPUT input= my_slice_new(struct s_input);
my_obstack_init(TOK_Obs_of_I(input));
/*527:*/
#line 5761 "./marpa.w"

input->t_ref_count= 1;

/*:527*//*535:*/
#line 5820 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:535*/
#line 5754 "./marpa.w"

return input;
}

/*:524*//*528:*/
#line 5765 "./marpa.w"

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

/*:528*//*529:*/
#line 5778 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:529*//*530:*/
#line 5791 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
my_obstack_free(TOK_Obs_of_I(input));
my_slice_free(struct s_input,input);
}

/*:530*//*539:*/
#line 5848 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
int symbol_count_of_g;
/*1204:*/
#line 13720 "./marpa.w"
void*const failure_indicator= NULL;
/*:1204*/
#line 5853 "./marpa.w"

/*1207:*/
#line 13734 "./marpa.w"

if(UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1207*/
#line 5854 "./marpa.w"

r= my_slice_new(struct marpa_r);
symbol_count_of_g= SYM_Count_of_G(g);
/*599:*/
#line 6218 "./marpa.w"
my_obstack_init(&r->t_obs);
/*:599*/
#line 5857 "./marpa.w"

/*542:*/
#line 5864 "./marpa.w"

r->t_ref_count= 1;

/*:542*//*550:*/
#line 5934 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:550*//*552:*/
#line 5943 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:552*//*556:*/
#line 5967 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:556*//*560:*/
#line 5990 "./marpa.w"
r->t_furthest_earleme= 0;
/*:560*//*564:*/
#line 6003 "./marpa.w"
r->t_sym_workarea= NULL;
/*:564*//*568:*/
#line 6014 "./marpa.w"
r->t_workarea2= NULL;
/*:568*//*572:*/
#line 6034 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:572*//*576:*/
#line 6057 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:576*//*591:*/
#line 6158 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:591*//*595:*/
#line 6194 "./marpa.w"
r->t_is_exhausted= 0;
/*:595*//*619:*/
#line 6316 "./marpa.w"

r->t_earley_set_count= 0;

/*:619*//*624:*/
#line 6362 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:624*//*645:*/
#line 6624 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:645*//*675:*/
#line 7006 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:675*//*710:*/
#line 7465 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:710*//*743:*/
#line 7950 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:743*//*747:*/
#line 7984 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:747*//*769:*/
#line 8304 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:769*//*773:*/
#line 8315 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:773*//*777:*/
#line 8326 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:777*//*846:*/
#line 9180 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:846*//*1169:*/
#line 13375 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1169*/
#line 5858 "./marpa.w"

return r;
}

/*:539*//*543:*/
#line 5868 "./marpa.w"

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

/*:543*//*544:*/
#line 5886 "./marpa.w"

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

/*:544*//*545:*/
#line 5900 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 5904 "./marpa.w"

/*547:*/
#line 5921 "./marpa.w"
input_unref(input);

/*:547*//*621:*/
#line 6340 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
my_free(EIMs_of_ES(set));
}
}

/*:621*//*748:*/
#line 7986 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:748*//*771:*/
#line 8308 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:771*//*775:*/
#line 8319 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:775*//*778:*/
#line 8327 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:778*//*847:*/
#line 9182 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:847*//*1170:*/
#line 13377 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1170*/
#line 5905 "./marpa.w"

grammar_unref(g);
my_free(r->t_sym_workarea);
my_free(r->t_workarea2);
/*574:*/
#line 6043 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:574*//*578:*/
#line 6060 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:578*/
#line 5909 "./marpa.w"

/*600:*/
#line 6219 "./marpa.w"
my_obstack_free(&r->t_obs);

/*:600*/
#line 5910 "./marpa.w"

my_slice_free(struct marpa_r,r);
}

/*:545*//*553:*/
#line 5951 "./marpa.w"

unsigned int marpa_r_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:553*//*554:*/
#line 5956 "./marpa.w"

PRIVATE ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:554*//*557:*/
#line 5969 "./marpa.w"

int marpa_r_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:557*//*558:*/
#line 5975 "./marpa.w"

int marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,int threshold)
{
r->t_earley_item_warning_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
return 1;
}

/*:558*//*561:*/
#line 5991 "./marpa.w"

unsigned int marpa_r_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:561*//*580:*/
#line 6075 "./marpa.w"

int marpa_r_terminals_expected(struct marpa_r*r,Marpa_Symbol_ID*buffer)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6078 "./marpa.w"

/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6079 "./marpa.w"

unsigned int min,max,start;
int ix= 0;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 6082 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 6083 "./marpa.w"

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

/*:580*//*592:*/
#line 6164 "./marpa.w"

int marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6167 "./marpa.w"

/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6168 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 6169 "./marpa.w"

return r->t_use_leo_flag;
}
/*:592*//*593:*/
#line 6172 "./marpa.w"

int marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6176 "./marpa.w"

/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6177 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 6178 "./marpa.w"

/*1214:*/
#line 13773 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1214*/
#line 6179 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:593*//*597:*/
#line 6204 "./marpa.w"

int marpa_r_is_exhausted(struct marpa_r*r)
{
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6207 "./marpa.w"

/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6208 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 6209 "./marpa.w"

return R_is_Exhausted(r);
}

/*:597*//*602:*/
#line 6223 "./marpa.w"

Marpa_Error_Code marpa_r_error(Marpa_Recognizer r,const char**p_error_string)
{
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6226 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:602*//*604:*/
#line 6232 "./marpa.w"

int marpa_r_event(Marpa_Recognizer r,Marpa_Event public_event,int ix)
{
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6235 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:604*//*620:*/
#line 6320 "./marpa.w"

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
/*1175:*/
#line 13421 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1175*/
#line 6335 "./marpa.w"

return set;
}

/*:620*//*625:*/
#line 6365 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6368 "./marpa.w"

/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6369 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 6371 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_ES);
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:625*//*626:*/
#line 6379 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6382 "./marpa.w"

/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6383 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 6384 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:626*//*627:*/
#line 6388 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const int es_does_not_exist= -1;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6392 "./marpa.w"

/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6393 "./marpa.w"

ES earley_set;
/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 6395 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 6396 "./marpa.w"

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

/*:627*//*629:*/
#line 6412 "./marpa.w"

int marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6415 "./marpa.w"

ES earley_set;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6417 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 6418 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 6419 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_ES_ORDINAL);
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:629*//*638:*/
#line 6515 "./marpa.w"

PRIVATE EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1204:*/
#line 13720 "./marpa.w"
void*const failure_indicator= NULL;
/*:1204*/
#line 6519 "./marpa.w"

/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6520 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const int count= ++EIM_Count_of_ES(set);
/*640:*/
#line 6567 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_EIM_COUNT);
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:640*/
#line 6525 "./marpa.w"

new_item= my_obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:638*//*639:*/
#line 6535 "./marpa.w"

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

/*:639*//*643:*/
#line 6599 "./marpa.w"

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

/*:643*//*650:*/
#line 6664 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const int es_does_not_exist= -1;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6670 "./marpa.w"

/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6671 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 6672 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*651:*/
#line 6695 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*677:*/
#line 7045 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:677*/
#line 6698 "./marpa.w"

}

/*:651*/
#line 6679 "./marpa.w"

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

/*:650*//*652:*/
#line 6701 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const int eim_does_not_exist= -1;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6706 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6710 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 6711 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*651:*/
#line 6695 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*677:*/
#line 7045 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:677*/
#line 6698 "./marpa.w"

}

/*:651*/
#line 6715 "./marpa.w"

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

/*:652*//*654:*/
#line 6744 "./marpa.w"

PRIVATE void trace_earley_item_clear(struct marpa_r*r)
{
/*653:*/
#line 6741 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:653*/
#line 6747 "./marpa.w"

trace_source_link_clear(r);
}

/*:654*//*655:*/
#line 6751 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6754 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6756 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 6757 "./marpa.w"

if(!item){
/*653:*/
#line 6741 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:653*/
#line 6759 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:655*//*662:*/
#line 6832 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6836 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6839 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 6840 "./marpa.w"

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

/*:662*//*663:*/
#line 6854 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6858 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6860 "./marpa.w"

EIM base_earley_item;
/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 6862 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:663*//*664:*/
#line 6872 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6876 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6879 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 6880 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:664*//*668:*/
#line 6914 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 6918 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 6920 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 6921 "./marpa.w"

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


/*:668*//*672:*/
#line 6970 "./marpa.w"

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
/*:672*//*673:*/
#line 6990 "./marpa.w"

PRIVATE PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:673*//*676:*/
#line 7020 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7025 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7029 "./marpa.w"

/*677:*/
#line 7045 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:677*/
#line 7030 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7031 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 7032 "./marpa.w"

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

/*:676*//*678:*/
#line 7055 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7059 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7062 "./marpa.w"

PIM*pim_sym_p;
/*677:*/
#line 7045 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:677*/
#line 7064 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7065 "./marpa.w"

if(!current_earley_set){
/*653:*/
#line 6741 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:653*/
#line 7067 "./marpa.w"

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

/*:678*//*679:*/
#line 7086 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7091 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7095 "./marpa.w"


pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*677:*/
#line 7045 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:677*/
#line 7099 "./marpa.w"

if(!pim_sym_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7104 "./marpa.w"

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

/*:679*//*680:*/
#line 7124 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_postdot_item_symbol(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7127 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7129 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7130 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:680*//*696:*/
#line 7258 "./marpa.w"
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

/*:696*//*701:*/
#line 7334 "./marpa.w"

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

/*:701*//*702:*/
#line 7362 "./marpa.w"

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

/*:702*//*704:*/
#line 7409 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*705:*/
#line 7426 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= new_link;
}

/*:705*/
#line 7417 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*706:*/
#line 7435 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= new_link;
First_Token_Link_of_EIM(item)= NULL;
}

/*:706*/
#line 7419 "./marpa.w"

return;
case SOURCE_IS_LEO:/*707:*/
#line 7444 "./marpa.w"
{
SRCL new_link= my_obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= new_link;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= NULL;
}

/*:707*/
#line 7421 "./marpa.w"

return;
}
}

/*:704*//*712:*/
#line 7476 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7479 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7483 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7484 "./marpa.w"

/*726:*/
#line 7703 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:726*/
#line 7485 "./marpa.w"

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

/*:712*//*715:*/
#line 7520 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7523 "./marpa.w"

SRCL full_link;
EIM item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7526 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7527 "./marpa.w"

/*726:*/
#line 7703 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:726*/
#line 7528 "./marpa.w"

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

/*:715*//*717:*/
#line 7551 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7554 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7558 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7559 "./marpa.w"

/*726:*/
#line 7703 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:726*/
#line 7560 "./marpa.w"

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

/*:717*//*720:*/
#line 7594 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7597 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7601 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7602 "./marpa.w"

/*726:*/
#line 7703 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:726*/
#line 7603 "./marpa.w"

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

/*:720*//*722:*/
#line 7627 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_leo_link_trace(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7631 "./marpa.w"

SRC source;
unsigned int source_type;
EIM item= r->t_trace_earley_item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7635 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7636 "./marpa.w"

/*726:*/
#line 7703 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:726*/
#line 7637 "./marpa.w"

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

/*:722*//*725:*/
#line 7673 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_leo_link_trace(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7677 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7681 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7682 "./marpa.w"

/*726:*/
#line 7703 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_EIM);
return failure_indicator;
}

/*:726*/
#line 7683 "./marpa.w"

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

/*:725*//*727:*/
#line 7712 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:727*//*728:*/
#line 7728 "./marpa.w"

AHFAID marpa_r_source_predecessor_state(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7731 "./marpa.w"

unsigned int source_type;
SRC source;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7734 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7735 "./marpa.w"

source_type= r->t_trace_source_type;
/*735:*/
#line 7879 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:735*/
#line 7737 "./marpa.w"

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

/*:728*//*729:*/
#line 7769 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,int*value_p)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7772 "./marpa.w"

unsigned int source_type;
SRC source;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7775 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7776 "./marpa.w"

source_type= r->t_trace_source_type;
/*735:*/
#line 7879 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:735*/
#line 7778 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:729*//*731:*/
#line 7801 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7804 "./marpa.w"

unsigned int source_type;
SRC source;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7807 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7808 "./marpa.w"

source_type= r->t_trace_source_type;
/*735:*/
#line 7879 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:735*/
#line 7810 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:731*//*734:*/
#line 7847 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 7850 "./marpa.w"

const EARLEME no_predecessor= -1;
unsigned int source_type;
SRC source;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 7854 "./marpa.w"

/*1217:*/
#line 13789 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 13790 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 13791 "./marpa.w"


/*:1217*/
#line 7855 "./marpa.w"

source_type= r->t_trace_source_type;
/*735:*/
#line 7879 "./marpa.w"

source= r->t_trace_source;
if(!source){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:735*/
#line 7857 "./marpa.w"

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

/*:734*//*750:*/
#line 7992 "./marpa.w"

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
outcome= alternative_cmp(r,new_alternative,alternative+trial);
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

/*:750*//*752:*/
#line 8036 "./marpa.w"

PRIVATE int alternative_cmp(RECCE r,const ALT_Const a,const ALT_Const b)
{
GRAMMAR g= G_of_R(r);
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:752*//*753:*/
#line 8054 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:753*//*754:*/
#line 8069 "./marpa.w"

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

/*:754*//*755:*/
#line 8088 "./marpa.w"
int marpa_r_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 8094 "./marpa.w"

const int symbol_count_of_g= SYM_Count_of_G(g);
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 8096 "./marpa.w"

/*1214:*/
#line 13773 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1214*/
#line 8097 "./marpa.w"

Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g)){
/*596:*/
#line 6195 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:596*/
#line 8100 "./marpa.w"

return 1;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
/*569:*/
#line 6015 "./marpa.w"

{
const unsigned int sym_workarea_size= sizeof(void*)*symbol_count_of_g;
/*565:*/
#line 6004 "./marpa.w"

r->t_sym_workarea= my_malloc(sym_workarea_size);

/*:565*/
#line 6018 "./marpa.w"

r->t_workarea2= my_malloc(2u*sym_workarea_size);
}

/*:569*/
#line 8104 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*573:*/
#line 6038 "./marpa.w"
{
r->t_bv_sym= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym2= bv_create((unsigned int)symbol_count_of_g);
r->t_bv_sym3= bv_create((unsigned int)symbol_count_of_g);
}
/*:573*//*577:*/
#line 6058 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((unsigned int)symbol_count_of_g);
/*:577*/
#line 8106 "./marpa.w"

/*770:*/
#line 8305 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT2(r->t_eim_work_stack,EIM);
/*:770*//*774:*/
#line 8316 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT2(r->t_completion_stack,EIM);
/*:774*/
#line 8107 "./marpa.w"

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

/*:755*//*762:*/
#line 8175 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID token_xsyid,
int value,
int length)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 8182 "./marpa.w"

/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 8183 "./marpa.w"

const int duplicate_token_indicator= -3;
const int unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
ISYID token_isyid;
/*1216:*/
#line 13783 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1216*/
#line 8190 "./marpa.w"

/*763:*/
#line 8198 "./marpa.w"
{
const XSY_Const token= SYM_by_ID(token_xsyid);
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

/*:763*/
#line 8191 "./marpa.w"

/*766:*/
#line 8234 "./marpa.w"
{
ISY token_isy= ISY_by_XSYID(token_xsyid);
if(UNLIKELY(!token_isy)){
return unexpected_token_indicator;
}
token_isyid= ID_of_ISY(token_isy);
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_xsyid))
return unexpected_token_indicator;
}

/*:766*/
#line 8192 "./marpa.w"

/*764:*/
#line 8214 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return failure_indicator;
}
}

/*:764*/
#line 8193 "./marpa.w"

/*767:*/
#line 8262 "./marpa.w"

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

/*:767*/
#line 8194 "./marpa.w"

return current_earleme;
}

/*:762*//*780:*/
#line 8346 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(struct marpa_r*r)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 8350 "./marpa.w"

/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 8351 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
int count_of_expected_terminals;
/*1216:*/
#line 13783 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

/*:1216*/
#line 8356 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*781:*/
#line 8384 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*596:*/
#line 6195 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:596*/
#line 8388 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return failure_indicator;
}
}

/*:781*/
#line 8360 "./marpa.w"

/*783:*/
#line 8409 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:783*/
#line 8361 "./marpa.w"

/*782:*/
#line 8396 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:782*/
#line 8362 "./marpa.w"

/*784:*/
#line 8415 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*785:*/
#line 8422 "./marpa.w"

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

/*:785*/
#line 8419 "./marpa.w"

}

/*:784*/
#line 8363 "./marpa.w"

/*786:*/
#line 8449 "./marpa.w"
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

/*:786*/
#line 8364 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*787:*/
#line 8468 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
int count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
int symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*788:*/
#line 8481 "./marpa.w"

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
/*789:*/
#line 8504 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*790:*/
#line 8520 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:790*/
#line 8513 "./marpa.w"

}
/*791:*/
#line 8527 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:791*/
#line 8515 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:789*/
#line 8492 "./marpa.w"

}
else
{
/*792:*/
#line 8537 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*790:*/
#line 8520 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:790*/
#line 8546 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:792*/
#line 8496 "./marpa.w"

break;


}
}
}

/*:788*/
#line 8477 "./marpa.w"

}
}

/*:787*/
#line 8367 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


/*596:*/
#line 6195 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:596*/
#line 8377 "./marpa.w"

event_new(g,MARPA_EVENT_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:780*//*793:*/
#line 8551 "./marpa.w"

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

/*:793*//*794:*/
#line 8572 "./marpa.w"

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

/*:794*//*800:*/
#line 8616 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,ES current_earley_set)
{
void**const pim_workarea= r->t_sym_workarea;
/*546:*/
#line 5918 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:546*/
#line 8621 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*801:*/
#line 8638 "./marpa.w"
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

/*:801*/
#line 8627 "./marpa.w"

if(r->t_is_using_leo){
/*805:*/
#line 8696 "./marpa.w"

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
/*806:*/
#line 8730 "./marpa.w"
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

/*:806*/
#line 8716 "./marpa.w"

}
}
}
}
}
}

/*:805*/
#line 8629 "./marpa.w"

/*815:*/
#line 8815 "./marpa.w"
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

/*818:*/
#line 8874 "./marpa.w"
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

/*:818*/
#line 8833 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*824:*/
#line 8966 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:824*/
#line 8835 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*826:*/
#line 8987 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:826*/
#line 8841 "./marpa.w"

continue;
}
/*819:*/
#line 8889 "./marpa.w"
{
void**const lim_chain= r->t_workarea2;
int lim_chain_ix;
/*822:*/
#line 8910 "./marpa.w"
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

/*818:*/
#line 8874 "./marpa.w"
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

/*:818*/
#line 8936 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(unsigned int)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:822*/
#line 8892 "./marpa.w"

/*823:*/
#line 8955 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*824:*/
#line 8966 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:824*/
#line 8959 "./marpa.w"

}else{
/*826:*/
#line 8987 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:826*/
#line 8961 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:823*/
#line 8893 "./marpa.w"

}

/*:819*/
#line 8844 "./marpa.w"

}
}
}

/*:815*/
#line 8630 "./marpa.w"

}
/*827:*/
#line 8993 "./marpa.w"
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

/*:827*/
#line 8632 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:800*//*848:*/
#line 9185 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
my_obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:848*//*849:*/
#line 9193 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:849*//*850:*/
#line 9199 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)my_obstack_free(&stack->t_obs);
stack->t_base= NULL;
}

/*:850*//*851:*/
#line 9206 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= my_obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:851*//*852:*/
#line 9216 "./marpa.w"

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

/*:852*//*853:*/
#line 9232 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:853*//*857:*/
#line 9295 "./marpa.w"

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

/*:857*//*893:*/
#line 9897 "./marpa.w"

PRIVATE AEX lim_base_data_get(GRAMMAR g,LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:893*//*894:*/
#line 9909 "./marpa.w"

PRIVATE AIM base_aim_of_lim(GRAMMAR g,LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(g,leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:894*//*900:*/
#line 10024 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= my_obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:900*//*902:*/
#line 10047 "./marpa.w"

PRIVATE
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:902*//*929:*/
#line 10484 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10487 "./marpa.w"

/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10488 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 10489 "./marpa.w"

return AND_Count_of_B(b);
}

/*:929*//*931:*/
#line 10515 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10520 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10521 "./marpa.w"

/*930:*/
#line 10493 "./marpa.w"

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

/*:930*/
#line 10522 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:931*//*932:*/
#line 10526 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10531 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10532 "./marpa.w"

/*930:*/
#line 10493 "./marpa.w"

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

/*:930*/
#line 10533 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:932*//*933:*/
#line 10542 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10547 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10548 "./marpa.w"

/*930:*/
#line 10493 "./marpa.w"

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

/*:930*/
#line 10549 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:933*//*934:*/
#line 10558 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10563 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10564 "./marpa.w"

/*930:*/
#line 10493 "./marpa.w"

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

/*:930*/
#line 10565 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?ISYID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:934*//*935:*/
#line 10574 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
TOK token;
AND and_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10580 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10581 "./marpa.w"

/*930:*/
#line 10493 "./marpa.w"

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

/*:930*/
#line 10582 "./marpa.w"

token= and_node_token(and_node);
if(token){
if(value_p)
*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
return-1;
}
/*:935*//*936:*/
#line 10591 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:936*//*950:*/
#line 10655 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1204:*/
#line 13720 "./marpa.w"
void*const failure_indicator= NULL;
/*:1204*/
#line 10659 "./marpa.w"

/*951:*/
#line 10702 "./marpa.w"

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

/*:951*//*954:*/
#line 10725 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:954*/
#line 10660 "./marpa.w"

INPUT input;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 10662 "./marpa.w"

/*1215:*/
#line 13778 "./marpa.w"

if(UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1215*/
#line 10663 "./marpa.w"

b= my_slice_new(*b);
/*880:*/
#line 9654 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:880*//*946:*/
#line 10634 "./marpa.w"

b->t_is_obstack_initialized= 1;
my_obstack_init(&OBS_of_B(b));
/*:946*//*967:*/
#line 10874 "./marpa.w"

b->t_ref_count= 1;

/*:967*//*974:*/
#line 10936 "./marpa.w"

B_is_Nulling(b)= 0;

/*:974*/
#line 10665 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*955:*/
#line 10728 "./marpa.w"

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

/*:955*/
#line 10675 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(SYM_by_ID(g->t_start_xsyid)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*959:*/
#line 10802 "./marpa.w"

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

/*:959*/
#line 10683 "./marpa.w"

if(!start_eim)goto NO_PARSE;
my_obstack_init(&bocage_setup_obs);
/*956:*/
#line 10750 "./marpa.w"

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

/*:956*/
#line 10686 "./marpa.w"

/*855:*/
#line 9254 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*856:*/
#line 9282 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:856*/
#line 9263 "./marpa.w"

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
/*858:*/
#line 9323 "./marpa.w"

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
/*856:*/
#line 9282 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:856*/
#line 9351 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:858*/
#line 9276 "./marpa.w"

/*860:*/
#line 9381 "./marpa.w"

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
/*856:*/
#line 9282 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:856*/
#line 9417 "./marpa.w"

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
/*856:*/
#line 9282 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:856*/
#line 9430 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:860*/
#line 9277 "./marpa.w"

/*861:*/
#line 9440 "./marpa.w"

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
/*856:*/
#line 9282 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:856*/
#line 9473 "./marpa.w"

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
/*856:*/
#line 9282 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:856*/
#line 9489 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:861*/
#line 9278 "./marpa.w"

}
}

/*:855*/
#line 10687 "./marpa.w"

/*882:*/
#line 9672 "./marpa.w"

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
/*1181:*/
#line 13478 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1181*/
#line 9692 "./marpa.w"

/*883:*/
#line 9700 "./marpa.w"

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
/*884:*/
#line 9720 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1181:*/
#line 13478 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1181*/
#line 9730 "./marpa.w"

/*886:*/
#line 9748 "./marpa.w"

{
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const IRL irl= IRL_of_AIM(ahfa_item);
/*887:*/
#line 9777 "./marpa.w"

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


/*:887*/
#line 9758 "./marpa.w"

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

/*:886*/
#line 9731 "./marpa.w"

/*889:*/
#line 9802 "./marpa.w"

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
/*887:*/
#line 9777 "./marpa.w"

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


/*:887*/
#line 9821 "./marpa.w"

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

/*:889*/
#line 9732 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*890:*/
#line 9839 "./marpa.w"
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
#line 9879 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const IRL path_irl= IRL_of_AIM(path_ahfa_item);
const int symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*895:*/
#line 9920 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1181:*/
#line 13478 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1181*/
#line 9927 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*887:*/
#line 9777 "./marpa.w"

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


/*:887*/
#line 9931 "./marpa.w"

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

/*:895*/
#line 9889 "./marpa.w"

/*896:*/
#line 9947 "./marpa.w"

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
/*887:*/
#line 9777 "./marpa.w"

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


/*:887*/
#line 9964 "./marpa.w"

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
SYMI_of_IRL(path_irl)+Length_of_IRL(path_irl))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_IRL(path_irl))
}
}

/*:896*/
#line 9890 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:892*/
#line 9861 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:890*/
#line 9740 "./marpa.w"

}

/*:884*/
#line 9714 "./marpa.w"

}
}
}
}

/*:883*/
#line 9693 "./marpa.w"

/*903:*/
#line 10057 "./marpa.w"

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
/*905:*/
#line 10094 "./marpa.w"

{
unsigned int work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const int work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*906:*/
#line 10110 "./marpa.w"
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
/*907:*/
#line 10142 "./marpa.w"

{

IRL path_irl= NULL;

IRL previous_path_irl;
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);


OR dand_predecessor;
OR path_or_node;
EIM base_earley_item;
AEX base_aex= lim_base_data_get(g,path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*908:*/
#line 10171 "./marpa.w"

{
if(higher_path_leo_item){
/*912:*/
#line 10215 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:912*/
#line 10174 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:908*/
#line 10157 "./marpa.w"

/*910:*/
#line 10185 "./marpa.w"

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

/*:910*/
#line 10158 "./marpa.w"

previous_path_irl= path_irl;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(g,path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*908:*/
#line 10171 "./marpa.w"

{
if(higher_path_leo_item){
/*912:*/
#line 10215 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_irl= IRL_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:912*/
#line 10174 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:908*/
#line 10165 "./marpa.w"

/*913:*/
#line 10225 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_IRL(previous_path_irl);
const int origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:913*/
#line 10166 "./marpa.w"

previous_path_irl= path_irl;
}
}

/*:907*/
#line 10132 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:906*/
#line 10105 "./marpa.w"

/*914:*/
#line 10235 "./marpa.w"

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
/*915:*/
#line 10265 "./marpa.w"

{
OR dand_predecessor;
/*916:*/
#line 10273 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:916*/
#line 10268 "./marpa.w"

draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:915*/
#line 10257 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:914*/
#line 10106 "./marpa.w"

/*917:*/
#line 10284 "./marpa.w"

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
/*918:*/
#line 10324 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const int middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_IRL(IRL_of_AIM(cause_ahfa_item));
/*916:*/
#line 10273 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:916*/
#line 10332 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:918*/
#line 10315 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:917*/
#line 10107 "./marpa.w"

}

/*:905*/
#line 10072 "./marpa.w"

}
}
}
}
}

/*:903*/
#line 9694 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= my_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:882*/
#line 10688 "./marpa.w"

/*926:*/
#line 10439 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*919:*/
#line 10338 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
int or_node_id= 0;
psar_init(and_psar,irl_count+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*921:*/
#line 10370 "./marpa.w"

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

/*:921*/
#line 10348 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:919*/
#line 10442 "./marpa.w"

/*927:*/
#line 10446 "./marpa.w"

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

/*:927*/
#line 10443 "./marpa.w"

}

/*:926*/
#line 10689 "./marpa.w"

/*960:*/
#line 10831 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const int start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:960*/
#line 10690 "./marpa.w"
;
my_obstack_free(&bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
input_unref(input);
if(b){
/*970:*/
#line 10911 "./marpa.w"

/*881:*/
#line 9661 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:881*/
#line 10912 "./marpa.w"
;
/*947:*/
#line 10637 "./marpa.w"

if(b->t_is_obstack_initialized){
my_obstack_free(&OBS_of_B(b));
b->t_is_obstack_initialized= 0;
}

/*:947*/
#line 10913 "./marpa.w"
;

/*:970*/
#line 10697 "./marpa.w"
;
}
return NULL;
}

/*:950*//*962:*/
#line 10854 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10857 "./marpa.w"

return g;
}

/*:962*//*964:*/
#line 10863 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10866 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10867 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 10868 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:964*//*968:*/
#line 10878 "./marpa.w"

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

/*:968*//*969:*/
#line 10896 "./marpa.w"

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

/*:969*//*971:*/
#line 10918 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10922 "./marpa.w"

input_unref(input);
if(b)
{
/*970:*/
#line 10911 "./marpa.w"

/*881:*/
#line 9661 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:881*/
#line 10912 "./marpa.w"
;
/*947:*/
#line 10637 "./marpa.w"

if(b->t_is_obstack_initialized){
my_obstack_free(&OBS_of_B(b));
b->t_is_obstack_initialized= 0;
}

/*:947*/
#line 10913 "./marpa.w"
;

/*:970*/
#line 10926 "./marpa.w"
;
my_slice_free(*b,b);
}
}

/*:971*//*977:*/
#line 10970 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10975 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10976 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 10977 "./marpa.w"

/*976:*/
#line 10948 "./marpa.w"

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

/*:976*/
#line 10978 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:977*//*978:*/
#line 10982 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10987 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 10988 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 10989 "./marpa.w"

/*976:*/
#line 10948 "./marpa.w"

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

/*:976*/
#line 10990 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:978*//*979:*/
#line 10994 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 10999 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11000 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11001 "./marpa.w"

/*976:*/
#line 10948 "./marpa.w"

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

/*:976*/
#line 11002 "./marpa.w"

return ID_of_IRL(IRL_of_OR(or_node));
}

/*:979*//*980:*/
#line 11006 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11011 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11012 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11013 "./marpa.w"

/*976:*/
#line 10948 "./marpa.w"

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

/*:976*/
#line 11014 "./marpa.w"

return Position_of_OR(or_node);
}

/*:980*//*981:*/
#line 11018 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11023 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11024 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11025 "./marpa.w"

/*976:*/
#line 10948 "./marpa.w"

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

/*:976*/
#line 11026 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:981*//*982:*/
#line 11030 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11035 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11036 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11037 "./marpa.w"

/*976:*/
#line 10948 "./marpa.w"

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

/*:976*/
#line 11038 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:982*//*983:*/
#line 11043 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11048 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11049 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11050 "./marpa.w"

/*976:*/
#line 10948 "./marpa.w"

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

/*:976*/
#line 11051 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:983*//*990:*/
#line 11093 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1204:*/
#line 13720 "./marpa.w"
void*const failure_indicator= NULL;
/*:1204*/
#line 11096 "./marpa.w"

/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11097 "./marpa.w"

ORDER o;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11099 "./marpa.w"

o= my_slice_new(*o);
B_of_O(o)= b;
bocage_ref(b);
/*987:*/
#line 11081 "./marpa.w"

{
o->t_and_node_in_use= NULL;
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
}

/*:987*//*993:*/
#line 11110 "./marpa.w"

o->t_ref_count= 1;

/*:993*/
#line 11103 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
return o;
}

/*:990*//*994:*/
#line 11114 "./marpa.w"

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

/*:994*//*995:*/
#line 11132 "./marpa.w"

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

/*:995*//*996:*/
#line 11146 "./marpa.w"

PRIVATE void order_strip(ORDER o)
{
if(o->t_and_node_in_use)
{
bv_free(o->t_and_node_in_use);
o->t_and_node_in_use= NULL;
}
}
/*:996*//*997:*/
#line 11155 "./marpa.w"

PRIVATE void order_freeze(ORDER o)
{
order_strip(o);
O_is_Frozen(o)= 0;
}
/*:997*//*998:*/
#line 11161 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11164 "./marpa.w"

bocage_unref(b);
order_strip(o);
if(o->t_and_node_orderings){
o->t_and_node_orderings= NULL;
my_obstack_free(&OBS_of_O(o));
}
my_slice_free(*o,o);
}

/*:998*//*1001:*/
#line 11190 "./marpa.w"

Marpa_Grammar marpa_o_g(Marpa_Order o)
{
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11193 "./marpa.w"

return g;
}

/*:1001*//*1007:*/
#line 11252 "./marpa.w"

int _marpa_o_and_order_set(
Marpa_Order o,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
int length)
{
OR or_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11260 "./marpa.w"

/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11261 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11262 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*976:*/
#line 10948 "./marpa.w"

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

/*:976*/
#line 11268 "./marpa.w"

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

/*:1007*//*1008:*/
#line 11332 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,int ix)
{
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11335 "./marpa.w"

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

/*:1008*//*1009:*/
#line 11357 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11362 "./marpa.w"

/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11363 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11364 "./marpa.w"

/*976:*/
#line 10948 "./marpa.w"

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

/*:976*/
#line 11365 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
return and_order_get(o,or_node,ix);
}

/*:1009*//*1014:*/
#line 11417 "./marpa.w"

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

/*:1014*//*1015:*/
#line 11435 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1204:*/
#line 13720 "./marpa.w"
void*const failure_indicator= NULL;
/*:1204*/
#line 11438 "./marpa.w"

TREE t;
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11440 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11441 "./marpa.w"

t= my_slice_new(*t);
O_of_T(t)= o;
order_ref(o);
order_freeze(o);
/*1034:*/
#line 11646 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1034*/
#line 11446 "./marpa.w"

/*1016:*/
#line 11451 "./marpa.w"

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

/*:1016*//*1019:*/
#line 11474 "./marpa.w"

t->t_ref_count= 1;

/*:1019*//*1026:*/
#line 11553 "./marpa.w"
t->t_pause_counter= 0;
/*:1026*/
#line 11447 "./marpa.w"

return t;
}

/*:1015*//*1020:*/
#line 11478 "./marpa.w"

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

/*:1020*//*1021:*/
#line 11496 "./marpa.w"

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

/*:1021*//*1022:*/
#line 11510 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_slice_free(*t,t);
}

/*:1022*//*1027:*/
#line 11554 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1027*//*1028:*/
#line 11563 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1028*//*1030:*/
#line 11585 "./marpa.w"

Marpa_Grammar marpa_t_g(Marpa_Tree t)
{
/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11588 "./marpa.w"

return g;
}

/*:1030*//*1031:*/
#line 11592 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11595 "./marpa.w"

int is_first_tree_attempt= 0;
/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11597 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11598 "./marpa.w"

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
/*1041:*/
#line 11680 "./marpa.w"

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

/*:1041*/
#line 11621 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
}else{
/*1042:*/
#line 11705 "./marpa.w"
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

/*:1042*/
#line 11628 "./marpa.w"

}
/*1043:*/
#line 11757 "./marpa.w"
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
/*1045:*/
#line 11818 "./marpa.w"

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

/*:1045*/
#line 11799 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1043*/
#line 11630 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return-1;

}

/*:1031*//*1038:*/
#line 11660 "./marpa.w"

PRIVATE void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:1038*//*1039:*/
#line 11666 "./marpa.w"

PRIVATE void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(unsigned int)and_node_id);
}
/*:1039*//*1040:*/
#line 11674 "./marpa.w"

PRIVATE int tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(unsigned int)and_node_id);
}

/*:1040*//*1044:*/
#line 11805 "./marpa.w"

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

/*:1044*//*1046:*/
#line 11836 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1046*//*1047:*/
#line 11844 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11847 "./marpa.w"

/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11848 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11849 "./marpa.w"

if(T_is_Exhausted(t)){
return-1;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1047*//*1054:*/
#line 11908 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11912 "./marpa.w"

/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11913 "./marpa.w"

/*1053:*/
#line 11890 "./marpa.w"
{
NOOK base_nook;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11892 "./marpa.w"

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

/*:1053*/
#line 11914 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1054*//*1055:*/
#line 11918 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11922 "./marpa.w"

/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11923 "./marpa.w"

/*1053:*/
#line 11890 "./marpa.w"
{
NOOK base_nook;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11892 "./marpa.w"

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

/*:1053*/
#line 11924 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1055*//*1056:*/
#line 11928 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11932 "./marpa.w"

/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11933 "./marpa.w"

/*1053:*/
#line 11890 "./marpa.w"
{
NOOK base_nook;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11892 "./marpa.w"

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

/*:1053*/
#line 11934 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1056*//*1057:*/
#line 11938 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11942 "./marpa.w"

/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11943 "./marpa.w"

/*1053:*/
#line 11890 "./marpa.w"
{
NOOK base_nook;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11892 "./marpa.w"

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

/*:1053*/
#line 11944 "./marpa.w"

return NOOK_Cause_is_Ready(nook);
}

/*:1057*//*1058:*/
#line 11948 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11952 "./marpa.w"

/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11953 "./marpa.w"

/*1053:*/
#line 11890 "./marpa.w"
{
NOOK base_nook;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11892 "./marpa.w"

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

/*:1053*/
#line 11954 "./marpa.w"

return NOOK_Predecessor_is_Ready(nook);
}

/*:1058*//*1059:*/
#line 11958 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11962 "./marpa.w"

/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11963 "./marpa.w"

/*1053:*/
#line 11890 "./marpa.w"
{
NOOK base_nook;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11892 "./marpa.w"

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

/*:1053*/
#line 11964 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1059*//*1060:*/
#line 11968 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 11972 "./marpa.w"

/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 11973 "./marpa.w"

/*1053:*/
#line 11890 "./marpa.w"
{
NOOK base_nook;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 11892 "./marpa.w"

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

/*:1053*/
#line 11974 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1060*//*1074:*/
#line 12106 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1204:*/
#line 13720 "./marpa.w"
void*const failure_indicator= NULL;
/*:1204*/
#line 12109 "./marpa.w"

/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 12110 "./marpa.w"
;
/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 12111 "./marpa.w"

if(!T_is_Exhausted(t))
{
VALUE v= my_slice_new(struct s_value);
Next_Value_Type_of_V(v)= V_GET_DATA;
/*1068:*/
#line 12050 "./marpa.w"

SYMID_of_V(v)= -1;
RULEID_of_V(v)= -1;
Token_Value_of_V(v)= -1;
Token_Type_of_V(v)= DUMMY_OR_NODE;
TOS_of_V(v)= -1;
Arg_N_of_V(v)= -1;

/*:1068*//*1073:*/
#line 12102 "./marpa.w"

DSTACK_SAFE(VStack_of_V(v));

/*:1073*//*1077:*/
#line 12136 "./marpa.w"

v->t_ref_count= 1;

/*:1077*//*1085:*/
#line 12202 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1085*//*1087:*/
#line 12209 "./marpa.w"

V_is_Trace(v)= 0;
/*:1087*//*1090:*/
#line 12230 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1090*//*1094:*/
#line 12252 "./marpa.w"

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

/*:1094*/
#line 12116 "./marpa.w"

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

/*:1074*//*1078:*/
#line 12140 "./marpa.w"

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

/*:1078*//*1079:*/
#line 12158 "./marpa.w"

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

/*:1079*//*1080:*/
#line 12172 "./marpa.w"

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

/*:1080*//*1082:*/
#line 12189 "./marpa.w"

Marpa_Grammar marpa_v_g(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1081:*/
#line 12184 "./marpa.w"

TREE t= T_of_V(v);
/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 12186 "./marpa.w"


/*:1081*/
#line 12193 "./marpa.w"

return g;
}

/*:1082*//*1088:*/
#line 12211 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 12214 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1081:*/
#line 12184 "./marpa.w"

TREE t= T_of_V(v);
/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 12186 "./marpa.w"


/*:1081*/
#line 12216 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 12217 "./marpa.w"

if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1088*//*1091:*/
#line 12233 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 12236 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1081:*/
#line 12184 "./marpa.w"

TREE t= T_of_V(v);
/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 12186 "./marpa.w"


/*:1081*/
#line 12238 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 12239 "./marpa.w"

if(UNLIKELY(V_is_Nulling(v)))return-1;
if(UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1091*//*1095:*/
#line 12268 "./marpa.w"

int marpa_v_symbol_is_ask_me_when_null(
Marpa_Value public_v,
Marpa_Symbol_ID symid)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 12273 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1081:*/
#line 12184 "./marpa.w"

TREE t= T_of_V(v);
/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 12186 "./marpa.w"


/*:1081*/
#line 12275 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 12276 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 12277 "./marpa.w"

return bv_bit_test(Nulling_Ask_BV_of_V(v),symid);
}
/*:1095*//*1096:*/
#line 12290 "./marpa.w"

int marpa_v_symbol_ask_me_when_null_set(
Marpa_Value public_v,Marpa_Symbol_ID symid,int value)
{
SYM symbol;
const VALUE v= (VALUE)public_v;
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 12296 "./marpa.w"

/*1081:*/
#line 12184 "./marpa.w"

TREE t= T_of_V(v);
/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 12186 "./marpa.w"


/*:1081*/
#line 12297 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 12298 "./marpa.w"

/*1208:*/
#line 13739 "./marpa.w"

if(UNLIKELY(!symbol_is_valid(g,symid))){
MARPA_ERROR(MARPA_ERR_INVALID_XSYID);
return failure_indicator;
}
/*:1208*/
#line 12299 "./marpa.w"

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

/*:1096*//*1098:*/
#line 12319 "./marpa.w"

Marpa_Value_Type marpa_v_step(Marpa_Value public_v)
{
/*1205:*/
#line 13723 "./marpa.w"
const int failure_indicator= -2;

/*:1205*/
#line 12322 "./marpa.w"

const VALUE v= (VALUE)public_v;

if(V_is_Nulling(v)){
/*1081:*/
#line 12184 "./marpa.w"

TREE t= T_of_V(v);
/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 12186 "./marpa.w"


/*:1081*/
#line 12326 "./marpa.w"

/*1099:*/
#line 12374 "./marpa.w"

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

/*:1099*/
#line 12327 "./marpa.w"

return MARPA_VALUE_INACTIVE;
}

while(V_is_Active(v)){
Marpa_Value_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case V_GET_DATA:
/*1100:*/
#line 12395 "./marpa.w"

{
AND and_nodes;
/*1081:*/
#line 12184 "./marpa.w"

TREE t= T_of_V(v);
/*1013:*/
#line 11413 "./marpa.w"

ORDER o= O_of_T(t);
/*999:*/
#line 11174 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*943:*/
#line 10623 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g UNUSED= G_of_I(input);

/*:943*/
#line 11176 "./marpa.w"


/*:999*/
#line 11415 "./marpa.w"
;

/*:1013*/
#line 12186 "./marpa.w"


/*:1081*/
#line 12398 "./marpa.w"

/*1218:*/
#line 13793 "./marpa.w"

if(UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1218*/
#line 12399 "./marpa.w"

and_nodes= ANDs_of_B(B_of_O(o));

Arg_N_of_V(v)= TOS_of_V(v);
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

/*:1100*/
#line 12336 "./marpa.w"

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

/*:1098*//*1103:*/
#line 12528 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(unsigned int bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1103*//*1104:*/
#line 12534 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(unsigned int bits)
{
unsigned int mask= bits&bv_modmask;
if(mask)mask= (unsigned int)~(~0uL<<mask);else mask= (unsigned int)~0uL;
return(mask);
}

/*:1104*//*1106:*/
#line 12548 "./marpa.w"

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

/*:1106*//*1108:*/
#line 12566 "./marpa.w"

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


/*:1108*//*1109:*/
#line 12587 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,BV_BITS(bv));
}

/*:1109*//*1110:*/
#line 12601 "./marpa.w"

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

/*:1110*//*1111:*/
#line 12619 "./marpa.w"

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

/*:1111*//*1112:*/
#line 12633 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1112*//*1113:*/
#line 12644 "./marpa.w"

PRIVATE int bv_bytes(Bit_Vector bv)
{
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}

/*:1113*//*1114:*/
#line 12651 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1114*//*1115:*/
#line 12662 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
unsigned int size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1115*//*1117:*/
#line 12676 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,unsigned int bit)
{
unsigned int length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1117*//*1119:*/
#line 12684 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1119*//*1120:*/
#line 12691 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,unsigned int bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1120*//*1121:*/
#line 12698 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,unsigned int bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1121*//*1122:*/
#line 12706 "./marpa.w"

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

/*:1122*//*1123:*/
#line 12719 "./marpa.w"

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

/*:1123*//*1124:*/
#line 12733 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1124*//*1125:*/
#line 12743 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1125*//*1126:*/
#line 12753 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1126*//*1127:*/
#line 12763 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
unsigned int size= BV_SIZE(X);
unsigned int mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1127*//*1128:*/
#line 12773 "./marpa.w"

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

/*:1128*//*1129:*/
#line 12845 "./marpa.w"

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

/*:1129*//*1134:*/
#line 12893 "./marpa.w"

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

/*:1134*//*1138:*/
#line 12995 "./marpa.w"

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

/*:1138*//*1139:*/
#line 13022 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1139*//*1140:*/
#line 13038 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,unsigned int row)
{
Bit_Vector row0= matrix+bv_hiddenwords;
unsigned int words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1140*//*1142:*/
#line 13047 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1142*//*1144:*/
#line 13055 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1144*//*1146:*/
#line 13063 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,unsigned int row,unsigned int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1146*//*1147:*/
#line 13076 "./marpa.w"

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

/*:1147*//*1156:*/
#line 13240 "./marpa.w"

PRIVATE_NOT_INLINE void*dstack_resize(struct s_dstack*this,size_t type_bytes)
{
this->t_capacity*= 2;
this->t_base= my_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}

/*:1156*//*1171:*/
#line 13379 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1171*//*1172:*/
#line 13386 "./marpa.w"

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
/*:1172*//*1173:*/
#line 13400 "./marpa.w"

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
/*:1173*//*1176:*/
#line 13431 "./marpa.w"

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

/*:1176*//*1178:*/
#line 13449 "./marpa.w"

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

/*:1178*//*1180:*/
#line 13469 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1180*//*1182:*/
#line 13493 "./marpa.w"

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

/*:1182*//*1185:*/
#line 13519 "./marpa.w"

PRIVATE_NOT_INLINE void*
_marpa_default_out_of_memory(void)
{
abort();
}
void*(*_marpa_out_of_memory)(void)= _marpa_default_out_of_memory;

/*:1185*//*1221:*/
#line 13837 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}

/*:1221*//*1230:*/
#line 13944 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
_marpa_debug_handler= debug_handler;
}

/*:1230*//*1232:*/
#line 13952 "./marpa.w"

void marpa_debug_level_set(int level)
{
_marpa_debug_level= level;
}

/*:1232*/
#line 14177 "./marpa.w"


/*:1247*/
