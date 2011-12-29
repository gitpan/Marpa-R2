/*1381:*/
#line 13648 "./marpa.w"

/*
 * Copyright 2011 Jeffrey Kegler
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

/*:1381*//*1382:*/
#line 13671 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1368:*/
#line 13476 "./marpa.w"

#if MARPA_DEBUG

#undef MARPA_ENABLE_ASSERT
#define MARPA_ENABLE_ASSERT 1

#define MARPA_DEBUG1(a)  g_debug((a)); 
#define MARPA_DEBUG2(a, b)  g_debug((a),(b)); 
#define MARPA_DEBUG3(a, b, c)  g_debug((a),(b),(c)); 
#define MARPA_DEBUG4(a, b, c, d)  g_debug((a),(b),(c),(d)); 
#define MARPA_DEBUG5(a, b, c, d, e)  g_debug((a),(b),(c),(d),(e)); 
#define MARPA_ASSERT(expr) do { if G_LIKELY (expr) ; else \
       g_error ("%s: assertion failed %s", G_STRLOC, #expr); } while (0);
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
#define MARPA_ASSERT(expr) do { if G_LIKELY (expr) ; else \
       g_error ("%s: assertion failed %s", G_STRLOC, #expr); } while (0);
#endif

/*:1368*/
#line 13674 "./marpa.w"

#define PRIVATE_NOT_INLINE static \

#define SYM_Count_of_G(g) ((g) ->t_symbols->len) 
#define SYM_by_ID(id) (g_array_index(g->t_symbols,SYM,(id) ) )  \

#define RULE_Count_of_G(g) ((g) ->t_rules->len) 
#define RULE_by_ID(g,id) (g_array_index((g) ->t_rules,RULE,(id) ) )  \

#define RULEID_of_G_is_Valid(g,rule_id)  \
((rule_id) >=0&&(guint) (rule_id) <(g) ->t_rules->len)  \

#define Default_Value_of_G(g) ((g) ->t_default_value) 
#define G_is_Trivial(g) (!(g) ->t_proper_start_rule) 
#define Size_of_G(g) ((g) ->t_size) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define G_EVENT_COUNT(g) DSTACK_LENGTH((g) ->t_events) 
#define INITIAL_G_EVENTS_CAPACITY 1
#define G_EVENTS_CLEAR(g) DSTACK_CLEAR((g) ->t_events) 
#define G_EVENT_PUSH(g) DSTACK_PUSH((g) ->t_events,GEV_Object) 
#define I_AM_OK 0x69734f4b
#define IS_G_OK(g) ((g) ->t_is_ok==I_AM_OK) 
#define ID_of_SYM(sym) ((sym) ->t_symbol_id) 
#define SYMBOL_LHS_RULE_COUNT(symbol) ((symbol) ->t_lhs->len) 
#define SYM_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define SYM_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
#define SYMID_is_Terminal(id) (SYM_is_Terminal(SYM_by_ID(id) ) ) 
#define MAX_RHS_LENGTH (G_MAXINT>>(2) ) 
#define Length_of_RULE(rule) ((rule) ->t_rhs_length) 
#define LHS_ID_of_RULE(rule) ((rule) ->t_symbols[0]) 
#define RHS_ID_of_RULE(rule,position)  \
((rule) ->t_symbols[(position) +1])  \

#define ID_of_RULE(rule) ((rule) ->t_id) 
#define RULE_is_Used(rule) ((rule) ->t_is_used) 
#define RULE_is_Start(rule) ((rule) ->t_is_start) 
#define RULE_is_Virtual_LHS(rule) ((rule) ->t_is_virtual_lhs) 
#define RULE_is_Virtual_RHS(rule) ((rule) ->t_is_virtual_rhs) 
#define Real_SYM_Count_of_RULE(rule) ((rule) ->t_real_symbol_count) 
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
#define AIM_has_Completed_Start_Rule(aim)  \
(AIM_is_Completion(aim) &&RULE_is_Start(RULE_of_AIM(aim) ) ) 
#define Null_Count_of_AIM(aim) ((aim) ->t_leading_nulls) 
#define AHFA_of_G_by_ID(g,id) ((g) ->t_AHFA+(id) ) 
#define AHFA_has_Completed_Start_Rule(ahfa) ((ahfa) ->t_has_completed_start_rule) 
#define Complete_SYMIDs_of_AHFA(state) ((state) ->t_complete_symbols) 
#define Complete_SYM_Count_of_AHFA(state) ((state) ->t_complete_symbol_count) 
#define AIMs_of_AHFA(ahfa) ((ahfa) ->t_items) 
#define AIM_of_AHFA_by_AEX(ahfa,aex) (AIMs_of_AHFA(ahfa) [aex]) 
#define AIM_Count_of_AHFA(ahfa) ((ahfa) ->t_item_count) 
#define AEX_of_AHFA_by_AIM(ahfa,aim) aex_of_ahfa_by_aim_get((ahfa) ,(aim) ) 
#define AHFA_is_Predicted(ahfa) ((ahfa) ->t_is_predict) 
#define EIM_is_Predicted(eim) AHFA_is_Predicted(AHFA_of_EIM(eim) ) 
#define AHFA_Count_of_G(g) ((g) ->t_AHFA_len) 
#define ID_of_AHFA(state) ((state) ->t_key.t_id)  \

#define Postdot_SYM_Count_of_AHFA(state) ((state) ->t_postdot_sym_count) 
#define Postdot_SYMID_Ary_of_AHFA(state) ((state) ->t_postdot_symid_ary) 
#define AIMID_of_AHFA_by_AEX(g,ahfa,aex)  \
((ahfa) ->t_items[aex]-(g) ->t_AHFA_items) 
#define Leo_LHS_ID_of_AHFA(state) ((state) ->t_leo_lhs_sym) 
#define AHFA_is_Leo_Completion(state) (Leo_LHS_ID_of_AHFA(state) >=0) 
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
#define I_of_R(r) (&(r) ->t_input) 
#define G_of_R(r) (G_of_I(&((r) ->t_input) ) ) 
#define AHFA_Count_of_R(r) AHFA_Count_of_G(G_of_R(r) ) 
#define G_of_I(i) ((i) ->t_grammar) 
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
#define EARLEME_THRESHOLD (G_MAXINT/4) 
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

#define EIM_FATAL_THRESHOLD (G_MAXINT/4) 
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

#define Type_of_TOK(tok) ((tok) ->t_type) 
#define SYMID_of_TOK(tok) ((tok) ->t_symbol_id) 
#define Value_of_TOK(tok) ((tok) ->t_value) 
#define TOK_Obs_of_I(i)  \
(&(i) ->t_token_obs) 
#define TOKs_by_SYMID_of_I(i)  \
((i) ->t_tokens_by_symid) 
#define TOK_by_ID_of_I(i,symbol_id)  \
(TOKs_by_SYMID_of_I(i) [symbol_id]) 
#define TOK_Obs_of_R(r) TOK_Obs_of_I(I_of_R(r) ) 
#define TOKs_by_SYMID_of_R(r) TOKs_by_SYMID_of_I(I_of_R(r) ) 
#define TOK_by_ID_of_R(r,symbol_id) TOK_by_ID_of_I(I_of_R(r) ,(symbol_id) ) 
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
MARPA_OFF_DEBUG3("%s: setting boolean for initial nulls, eim=%s", \
G_STRLOC,eim_tag(eim) ) ; \
MARPA_OFF_DEBUG3("%s: setting boolean for initial nulls, aim=%s", \
G_STRLOC,aim_tag(aim) ) ; \
 \
if(Position_of_AIM(aim) > 0) { \
const gint null_count= Null_Count_of_AIM(aim) ; \
 \
MARPA_OFF_DEBUG4("%s: setting boolean for initial nulls, eim=%s, null count = %d", \
G_STRLOC,eim_tag(eim) ,null_count) ; \
 \
if(null_count) { \
AEX aex= AEX_of_EIM_by_AIM((eim) , \
(aim) ) ; \
 \
MARPA_OFF_DEBUG4("%s: setting boolean for initial nulls, eim=%s, aex=%d", \
G_STRLOC,eim_tag(eim) ,aex) ; \
 \
or_node_estimate+= null_count; \
psia_test_and_set(&bocage_setup_obs,per_es_data, \
(eim) ,aex) ; \
} \
} \
} \

#define DUMMY_OR_NODE -1
#define TOKEN_OR_NODE -2
#define OR_is_Token(or) (Type_of_OR(or) ==TOKEN_OR_NODE) 
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
const gint psia_earley_set_ordinal= ES_Ord_of_EIM(psia_earley_item) ; \
OR**const psia_nodes_by_item=  \
per_es_data[psia_earley_set_ordinal].t_aexes_by_item; \
const gint psia_item_ordinal= Ord_of_EIM(psia_earley_item) ; \
OR*const psia_nodes_by_aex= psia_nodes_by_item[psia_item_ordinal]; \
psia_or= psia_nodes_by_aex?psia_nodes_by_aex[psia_aex]:NULL; \
} \

#define OR_of_AND(and) ((and) ->t_current) 
#define Predecessor_OR_of_AND(and) ((and) ->t_predecessor) 
#define Cause_OR_of_AND(and) ((and) ->t_cause) 
#define I_of_B(b) ((b) ->t_input) 
#define R_of_B(b) ((b) ->t_recce) 
#define OBS_of_B(b) ((b) ->t_obs) 
#define T_is_Exhausted(tree)  \
(!FSTACK_IS_INITIALIZED((tree) ->t_fork_stack) ) 
#define Size_of_TREE(tree) FSTACK_LENGTH((tree) ->t_fork_stack) 
#define FORK_of_TREE_by_IX(tree,fork_id)  \
FSTACK_INDEX((tree) ->t_fork_stack,FORK_Object,fork_id) 
#define O_of_T(t) ((t) ->t_order) 
#define T_is_Paused(t) ((t) ->t_pause_counter> 0) 
#define Size_of_T(t) FSTACK_LENGTH((t) ->t_fork_stack) 
#define OBS_of_O(order) ((order) ->t_obs) 
#define O_is_Frozen(o) ((o) ->t_is_frozen) 
#define B_of_O(b) ((b) ->t_bocage) 
#define OR_of_FORK(fork) ((fork) ->t_or_node) 
#define Choice_of_FORK(fork) ((fork) ->t_choice) 
#define Parent_of_FORK(fork) ((fork) ->t_parent) 
#define FORK_Cause_is_Ready(fork) ((fork) ->t_is_cause_ready) 
#define FORK_is_Cause(fork) ((fork) ->t_is_cause_of_parent) 
#define FORK_Predecessor_is_Ready(fork) ((fork) ->t_is_predecessor_ready) 
#define FORK_is_Predecessor(fork) ((fork) ->t_is_predecessor_of_parent) 
#define SYMID_of_EVE(eve) ((eve) ->marpa_token_id) 
#define Value_of_EVE(eve) ((eve) ->marpa_value) 
#define RULEID_of_EVE(eve) ((eve) ->marpa_rule_id) 
#define Arg0_of_EVE(eve) ((eve) ->marpa_arg_0) 
#define ArgN_of_EVE(eve) ((eve) ->marpa_arg_n) 
#define V_is_Active(val) ((val) ->t_active) 
#define V_is_Trace(val) ((val) ->t_trace) 
#define FORK_of_V(val) ((val) ->t_fork) 
#define TOS_of_V(val) ((val) ->t_tos) 
#define VStack_of_V(val) ((val) ->t_virtual_stack) 
#define T_of_V(v) ((v) ->t_tree) 
#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DECLARE(stack,type) struct{gint t_count;type*t_base;}stack;
#define FSTACK_CLEAR(stack) ((stack) .t_count= 0) 
#define FSTACK_INIT(stack,type,n) (FSTACK_CLEAR(stack) ,((stack) .t_base= g_new(type,n) ) ) 
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
#define FSTACK_DESTROY(stack) (g_free((stack) .t_base) )  \

#define DSTACK_DECLARE(this) struct s_dstack this
#define DSTACK_INIT(this,type,initial_size)  \
(((this) .t_count= 0) , \
((this) .t_base= g_new(type,((this) .t_capacity= (initial_size) ) ) ) )  \

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

#define STOLEN_DSTACK_DATA_FREE(data) ((data) &&(g_free(data) ,1) ) 
#define DSTACK_DESTROY(this) STOLEN_DSTACK_DATA_FREE(this.t_base)  \

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
(sizeof(PSL_Object) +(psar->t_psl_length-1) *sizeof(gpointer) ) 
#define PSL_Datum(psl,i) ((psl) ->t_data[(i) ]) 
#define Dot_PSAR_of_R(r) (&(r) ->t_dot_psar_object) 
#define Dot_PSL_of_ES(es) ((es) ->t_dot_psl) 
#define obstack_chunk_alloc g_malloc
#define obstack_chunk_free g_free \

#define FATAL_FLAG (0x1u) 
#define MARPA_DEV_ERROR(message) (set_error(g,MARPA_ERR_DEVELOPMENT,(message) ,0u) ) 
#define MARPA_ERROR(code) (set_error(g,(code) ,NULL,0u) ) 
#define R_DEV_ERROR(message) (r_error(r,MARPA_ERR_DEVELOPMENT,(message) ,0u) ) 
#define R_ERROR(code,message) (r_error(r,(code) ,(message) ,0u) ) 
#define R_FATAL(code,message) (r_error(r,(code) ,(message) ,FATAL_FLAG) ) 
#define MARPA_OFF_DEBUG1(a) 
#define MARPA_OFF_DEBUG2(a,b) 
#define MARPA_OFF_DEBUG3(a,b,c) 
#define MARPA_OFF_DEBUG4(a,b,c,d) 
#define MARPA_OFF_DEBUG5(a,b,c,d,e) 
#define MARPA_OFF_ASSERT(expr) 

#line 13675 "./marpa.w"

#include "marpa_obs.h"
/*1366:*/
#line 13420 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1366*/
#line 13677 "./marpa.w"

/*111:*/
#line 954 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:111*//*137:*/
#line 1132 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:137*//*432:*/
#line 3553 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:432*//*477:*/
#line 3957 "./marpa.w"
struct s_AHFA_state;
/*:477*//*564:*/
#line 5159 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:564*//*667:*/
#line 5805 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:667*//*693:*/
#line 6032 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:693*//*717:*/
#line 6330 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:717*//*720:*/
#line 6365 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:720*//*809:*/
#line 7503 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:809*//*817:*/
#line 7588 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:817*//*915:*/
#line 8735 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:915*//*950:*/
#line 9191 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:950*//*979:*/
#line 9642 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:979*//*1007:*/
#line 10070 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:1007*//*1029:*/
#line 10273 "./marpa.w"

typedef struct s_bocage*BOCAGE;
/*:1029*//*1044:*/
#line 10385 "./marpa.w"

struct s_bocage_setup_per_es;
/*:1044*//*1088:*/
#line 10799 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1088*//*1163:*/
#line 11610 "./marpa.w"

struct s_fork;
typedef struct s_fork*FORK;
/*:1163*//*1186:*/
#line 11792 "./marpa.w"

typedef struct s_value*VALUE;
/*:1186*//*1297:*/
#line 12835 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1297*//*1301:*/
#line 12870 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1301*//*1308:*/
#line 12935 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1308*//*1310:*/
#line 12950 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1310*/
#line 13678 "./marpa.w"

/*40:*/
#line 611 "./marpa.w"

typedef struct marpa_g*GRAMMAR;
typedef const struct marpa_g*GRAMMAR_Const;

/*:40*//*136:*/
#line 1130 "./marpa.w"

typedef gint SYMID;
/*:136*//*211:*/
#line 1566 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:211*//*324:*/
#line 2368 "./marpa.w"
typedef gint SYMI;
/*:324*//*489:*/
#line 4038 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:489*//*565:*/
#line 5164 "./marpa.w"
typedef gint AEX;
/*:565*//*588:*/
#line 5328 "./marpa.w"

typedef struct marpa_r*RECCE;
typedef struct marpa_input*INPUT;
/*:588*//*664:*/
#line 5796 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:664*//*666:*/
#line 5800 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:666*//*750:*/
#line 6751 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:750*//*752:*/
#line 6763 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:752*//*942:*/
#line 9127 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:942*//*978:*/
#line 9630 "./marpa.w"

typedef gint WHEID;


/*:978*//*1006:*/
#line 10066 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:1006*//*1162:*/
#line 11607 "./marpa.w"

typedef Marpa_Fork_ID FORKID;
/*:1162*//*1183:*/
#line 11770 "./marpa.w"

typedef Marpa_Event*EVE;

/*:1183*//*1212:*/
#line 12110 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1212*//*1270:*/
#line 12596 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1270*/
#line 13679 "./marpa.w"

/*35:*/
#line 550 "./marpa.w"

const guint marpa_major_version= MARPA_MAJOR_VERSION;
const guint marpa_minor_version= MARPA_MINOR_VERSION;
const guint marpa_micro_version= MARPA_MICRO_VERSION;
const guint marpa_interface_age= MARPA_INTERFACE_AGE;
const guint marpa_binary_age= MARPA_BINARY_AGE;
/*:35*//*956:*/
#line 9245 "./marpa.w"

static const gint dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:956*//*1213:*/
#line 12117 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1213*/
#line 13680 "./marpa.w"

/*1298:*/
#line 12838 "./marpa.w"

struct s_dstack{gint t_count;gint t_capacity;gpointer t_base;};
/*:1298*/
#line 13681 "./marpa.w"

/*39:*/
#line 604 "./marpa.w"
struct marpa_g{
/*128:*/
#line 1081 "./marpa.w"

gint t_is_ok;

/*:128*/
#line 605 "./marpa.w"

/*53:*/
#line 690 "./marpa.w"
GArray*t_symbols;
/*:53*//*62:*/
#line 735 "./marpa.w"
GArray*t_rules;
/*:62*//*71:*/
#line 773 "./marpa.w"
gpointer t_default_value;
/*:71*//*107:*/
#line 935 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:107*//*115:*/
#line 971 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:115*//*124:*/
#line 1051 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:124*//*130:*/
#line 1096 "./marpa.w"

const gchar*t_error_string;
/*:130*//*434:*/
#line 3570 "./marpa.w"

AIM t_AHFA_items;
AIM*t_AHFA_items_by_rule;
/*:434*//*490:*/
#line 4042 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:490*/
#line 606 "./marpa.w"

/*45:*/
#line 629 "./marpa.w"
gint t_ref_count;
/*:45*//*77:*/
#line 793 "./marpa.w"
Marpa_Symbol_ID t_start_symid;
/*:77*//*83:*/
#line 821 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:83*//*87:*/
#line 850 "./marpa.w"
int t_size;
/*:87*//*90:*/
#line 863 "./marpa.w"
gint t_max_rule_length;
/*:90*//*131:*/
#line 1098 "./marpa.w"

Marpa_Error_Code t_error;
/*:131*//*325:*/
#line 2370 "./marpa.w"

gint t_symbol_instance_count;
/*:325*//*435:*/
#line 3575 "./marpa.w"

guint t_aim_count;
/*:435*//*491:*/
#line 4045 "./marpa.w"
gint t_AHFA_len;
/*:491*/
#line 607 "./marpa.w"

/*94:*/
#line 871 "./marpa.w"
guint t_is_precomputed:1;
/*:94*//*97:*/
#line 883 "./marpa.w"
guint t_has_loop:1;
/*:97*//*101:*/
#line 901 "./marpa.w"
guint t_is_lhs_terminal_ok:1;
/*:101*/
#line 608 "./marpa.w"

};
typedef struct marpa_g GRAMMARD;
/*:39*//*114:*/
#line 964 "./marpa.w"

struct s_g_event{
gint t_type;
gint t_value;
};
typedef struct s_g_event GEV_Object;
/*:114*//*138:*/
#line 1139 "./marpa.w"

struct s_symbol{
/*147:*/
#line 1190 "./marpa.w"
GArray*t_lhs;
/*:147*//*154:*/
#line 1242 "./marpa.w"
GArray*t_rhs;
/*:154*//*193:*/
#line 1433 "./marpa.w"

struct s_symbol*t_alias;
/*:193*//*205:*/
#line 1529 "./marpa.w"

RULE t_virtual_lhs_rule;
/*:205*/
#line 1141 "./marpa.w"

/*145:*/
#line 1181 "./marpa.w"
SYMID t_symbol_id;
/*:145*/
#line 1142 "./marpa.w"

/*161:*/
#line 1285 "./marpa.w"
guint t_is_accessible:1;
/*:161*//*165:*/
#line 1303 "./marpa.w"
guint t_is_counted:1;
/*:165*//*169:*/
#line 1321 "./marpa.w"
guint t_is_nullable:1;
/*:169*//*173:*/
#line 1340 "./marpa.w"
guint t_is_nulling:1;
/*:173*//*177:*/
#line 1360 "./marpa.w"
guint t_is_terminal:1;
/*:177*//*183:*/
#line 1386 "./marpa.w"
guint t_is_productive:1;
/*:183*//*187:*/
#line 1404 "./marpa.w"
guint t_is_start:1;
/*:187*//*192:*/
#line 1430 "./marpa.w"

guint t_is_proper_alias:1;
guint t_is_nulling_alias:1;
/*:192*/
#line 1143 "./marpa.w"

};
typedef struct s_symbol SYM_Object;

/*:138*//*210:*/
#line 1557 "./marpa.w"

struct s_rule{
/*239:*/
#line 1972 "./marpa.w"
gint t_rhs_length;
/*:239*//*256:*/
#line 2044 "./marpa.w"
Marpa_Rule_ID t_id;
/*:256*//*301:*/
#line 2276 "./marpa.w"
gint t_virtual_start;
/*:301*//*305:*/
#line 2292 "./marpa.w"
gint t_virtual_end;
/*:305*//*310:*/
#line 2308 "./marpa.w"
Marpa_Rule_ID t_original;
/*:310*//*315:*/
#line 2327 "./marpa.w"
gint t_real_symbol_count;
/*:315*//*326:*/
#line 2381 "./marpa.w"

gint t_symbol_instance_base;
gint t_last_proper_symi;
/*:326*/
#line 1559 "./marpa.w"

/*259:*/
#line 2056 "./marpa.w"
guint t_is_discard:1;
/*:259*//*273:*/
#line 2140 "./marpa.w"
guint t_is_loop:1;
/*:273*//*278:*/
#line 2161 "./marpa.w"
guint t_is_virtual_loop:1;
/*:278*//*285:*/
#line 2197 "./marpa.w"
guint t_is_used:1;
/*:285*//*289:*/
#line 2213 "./marpa.w"
guint t_is_start:1;
/*:289*//*293:*/
#line 2244 "./marpa.w"
guint t_is_virtual_lhs:1;
/*:293*//*297:*/
#line 2259 "./marpa.w"
guint t_is_virtual_rhs:1;
/*:297*//*319:*/
#line 2340 "./marpa.w"
guint t_is_semantic_equivalent:1;
/*:319*/
#line 1560 "./marpa.w"

/*240:*/
#line 1975 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:240*/
#line 1561 "./marpa.w"

};
/*:210*//*431:*/
#line 3547 "./marpa.w"

struct s_AHFA_item{
gint t_sort_key;
/*441:*/
#line 3601 "./marpa.w"

RULE t_rule;

/*:441*/
#line 3550 "./marpa.w"

/*442:*/
#line 3607 "./marpa.w"

gint t_position;

/*:442*//*443:*/
#line 3616 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:443*//*444:*/
#line 3625 "./marpa.w"

gint t_leading_nulls;

/*:444*/
#line 3551 "./marpa.w"

};
/*:431*//*478:*/
#line 3958 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*481:*/
#line 3977 "./marpa.w"

SYMID*t_complete_symbols;

/*:481*//*483:*/
#line 3985 "./marpa.w"

AIM*t_items;
/*:483*//*498:*/
#line 4084 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:498*//*567:*/
#line 5176 "./marpa.w"

TRANS*t_transitions;
/*:567*/
#line 3965 "./marpa.w"

/*480:*/
#line 3975 "./marpa.w"

guint t_complete_symbol_count;
/*:480*//*484:*/
#line 3987 "./marpa.w"

gint t_item_count;
/*:484*//*499:*/
#line 4085 "./marpa.w"
guint t_postdot_sym_count;

/*:499*//*513:*/
#line 4216 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:513*/
#line 3966 "./marpa.w"

guint t_has_completed_start_rule:1;
/*488:*/
#line 4035 "./marpa.w"

guint t_is_predict:1;

/*:488*/
#line 3968 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:478*//*566:*/
#line 5165 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
gint t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:566*//*668:*/
#line 5811 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:668*//*669:*/
#line 5816 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
gint t_postdot_sym_count;
/*670:*/
#line 5828 "./marpa.w"

gint t_eim_count;
/*:670*//*672:*/
#line 5842 "./marpa.w"

gint t_ordinal;
/*:672*/
#line 5820 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*671:*/
#line 5831 "./marpa.w"

EIM*t_earley_items;

/*:671*//*1319:*/
#line 13026 "./marpa.w"

PSL t_dot_psl;
/*:1319*/
#line 5823 "./marpa.w"

};

/*:669*//*718:*/
#line 6334 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:718*//*721:*/
#line 6368 "./marpa.w"

struct s_leo_item{
EIX_Object t_earley_ix;
ES t_origin;
AHFA t_top_ahfa;
LIM t_predecessor;
EIM t_base;
ES t_set;
gint t_chain_length;
};
typedef struct s_leo_item LIM_Object;

/*:721*//*731:*/
#line 6507 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:731*//*810:*/
#line 7511 "./marpa.w"

struct s_token{
gint t_type;
SYMID t_symbol_id;
gpointer t_value;
};

/*:810*//*818:*/
#line 7598 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:818*//*916:*/
#line 8752 "./marpa.w"

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
/*:916*//*953:*/
#line 9220 "./marpa.w"

struct s_draft_or_node
{
/*952:*/
#line 9214 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:952*/
#line 9223 "./marpa.w"

DAND t_draft_and_node;
};
/*:953*//*954:*/
#line 9226 "./marpa.w"

struct s_final_or_node
{
/*952:*/
#line 9214 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:952*/
#line 9229 "./marpa.w"

gint t_first_and_node_id;
gint t_and_node_count;
};
/*:954*//*955:*/
#line 9237 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:955*//*980:*/
#line 9649 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:980*//*1008:*/
#line 10077 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:1008*//*1045:*/
#line 10387 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:1045*//*1089:*/
#line 10813 "./marpa.w"

/*1164:*/
#line 11621 "./marpa.w"

struct s_fork{
OR t_or_node;
gint t_choice;
FORKID t_parent;
guint t_is_cause_ready:1;
guint t_is_predecessor_ready:1;
guint t_is_cause_of_parent:1;
guint t_is_predecessor_of_parent:1;
};
typedef struct s_fork FORK_Object;

/*:1164*/
#line 10814 "./marpa.w"

/*1187:*/
#line 11809 "./marpa.w"

struct s_value{
DSTACK_DECLARE(t_virtual_stack);
FORKID t_fork;
Marpa_Tree t_tree;
/*1193:*/
#line 11888 "./marpa.w"

int t_ref_count;
/*:1193*/
#line 11814 "./marpa.w"

gint t_tos;
guint t_trace:1;
guint t_active:1;
};

/*:1187*/
#line 10815 "./marpa.w"

struct s_tree{
FSTACK_DECLARE(t_fork_stack,FORK_Object)
FSTACK_DECLARE(t_fork_worklist,gint)
Bit_Vector t_and_node_in_use;
Marpa_Order t_order;
/*1097:*/
#line 10880 "./marpa.w"

gint t_ref_count;
/*:1097*//*1107:*/
#line 10968 "./marpa.w"
gint t_pause_counter;
/*:1107*/
#line 10821 "./marpa.w"

gint t_parse_count;
};

/*:1089*//*1132:*/
#line 11286 "./marpa.w"

struct s_order{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
/*1135:*/
#line 11304 "./marpa.w"

BOCAGE t_bocage;

/*:1135*/
#line 11291 "./marpa.w"

/*1138:*/
#line 11322 "./marpa.w"
gint t_ref_count;
/*:1138*/
#line 11292 "./marpa.w"

guint t_is_frozen:1;
};
/*:1132*//*1302:*/
#line 12873 "./marpa.w"

struct s_dqueue{gint t_current;struct s_dstack t_stack;};

/*:1302*//*1309:*/
#line 12941 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
gpointer t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1309*//*1311:*/
#line 12966 "./marpa.w"

struct s_per_earley_set_arena{
gint t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1311*/
#line 13682 "./marpa.w"

/*589:*/
#line 5332 "./marpa.w"

struct marpa_input{
/*602:*/
#line 5440 "./marpa.w"

struct marpa_g*t_grammar;

/*:602*//*811:*/
#line 7539 "./marpa.w"

struct obstack t_token_obs;
TOK*t_tokens_by_symid;
/*:811*/
#line 5334 "./marpa.w"

};
struct marpa_r{
struct marpa_input t_input;
/*606:*/
#line 5459 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:606*//*619:*/
#line 5528 "./marpa.w"
gpointer*t_sym_workarea;
/*:619*//*623:*/
#line 5543 "./marpa.w"
gpointer*t_workarea2;
/*:623*//*627:*/
#line 5564 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:627*//*631:*/
#line 5590 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:631*//*653:*/
#line 5750 "./marpa.w"
struct obstack t_obs;
/*:653*//*679:*/
#line 5895 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:679*//*704:*/
#line 6174 "./marpa.w"

EIM t_trace_earley_item;
/*:704*//*737:*/
#line 6560 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:737*//*775:*/
#line 7032 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:775*//*819:*/
#line 7606 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:819*//*842:*/
#line 7907 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:842*//*846:*/
#line 7919 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:846*//*850:*/
#line 7931 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:850*//*917:*/
#line 8765 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:917*//*1312:*/
#line 12974 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1312*/
#line 5338 "./marpa.w"

/*593:*/
#line 5371 "./marpa.w"
gint t_ref_count;
/*:593*//*611:*/
#line 5488 "./marpa.w"
gint t_earley_item_warning_threshold;
/*:611*//*615:*/
#line 5511 "./marpa.w"
EARLEME t_furthest_earleme;
/*:615*//*673:*/
#line 5846 "./marpa.w"

gint t_earley_set_count;
/*:673*/
#line 5339 "./marpa.w"

/*603:*/
#line 5451 "./marpa.w"

guint t_input_phase:2;
/*:603*//*645:*/
#line 5685 "./marpa.w"

guint t_use_leo_flag:1;
guint t_is_using_leo:1;
/*:645*//*649:*/
#line 5726 "./marpa.w"
guint t_is_exhausted:1;
/*:649*//*776:*/
#line 7035 "./marpa.w"

guint t_trace_source_type:3;
/*:776*/
#line 5340 "./marpa.w"

};

/*:589*/
#line 13683 "./marpa.w"

/*751:*/
#line 6754 "./marpa.w"

struct s_source{
gpointer t_predecessor;
union{
gpointer t_completion;
TOK t_token;
}t_cause;
};

/*:751*//*753:*/
#line 6766 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:753*//*754:*/
#line 6772 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:754*//*755:*/
#line 6779 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:755*/
#line 13684 "./marpa.w"

/*694:*/
#line 6039 "./marpa.w"

struct s_earley_item_key{
AHFA t_state;
ES t_origin;
ES t_set;
};
typedef struct s_earley_item_key EIK_Object;
struct s_earley_item{
EIK_Object t_key;
union u_source_container t_container;
gint t_ordinal;
/*701:*/
#line 6145 "./marpa.w"

guint t_source_type:3;

/*:701*/
#line 6050 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:694*/
#line 13685 "./marpa.w"

/*1030:*/
#line 10275 "./marpa.w"

struct s_bocage{
/*957:*/
#line 9255 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:957*//*1034:*/
#line 10287 "./marpa.w"

INPUT t_input;
RECCE t_recce;

/*:1034*//*1036:*/
#line 10298 "./marpa.w"

struct obstack t_obs;
/*:1036*/
#line 10277 "./marpa.w"

/*958:*/
#line 9258 "./marpa.w"

gint t_or_node_count;
gint t_and_node_count;
ORID t_top_or_node_id;

/*:958*//*1062:*/
#line 10601 "./marpa.w"
gint t_ref_count;
/*:1062*/
#line 10278 "./marpa.w"

/*1037:*/
#line 10300 "./marpa.w"

unsigned int is_obstack_initialized:1;
/*:1037*/
#line 10279 "./marpa.w"

};

/*:1030*/
#line 13686 "./marpa.w"

/*47:*/
#line 640 "./marpa.w"

void grammar_unref(GRAMMAR g);
/*:47*//*49:*/
#line 659 "./marpa.w"

static inline GRAMMAR grammar_ref(GRAMMAR g);
/*:49*//*52:*/
#line 681 "./marpa.w"

static inline void
grammar_free(struct marpa_g*g);

/*:52*//*61:*/
#line 728 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid);

/*:61*//*118:*/
#line 991 "./marpa.w"

static inline
void event_new(struct marpa_g*g,gint type);
/*:118*//*120:*/
#line 1003 "./marpa.w"

static inline
void int_event_new(struct marpa_g*g,gint type,gint value);
/*:120*//*139:*/
#line 1147 "./marpa.w"

static inline
SYM symbol_new(struct marpa_g*g);
/*:139*//*144:*/
#line 1176 "./marpa.w"

static inline void symbol_free(SYM symbol);

/*:144*//*153:*/
#line 1233 "./marpa.w"

void
marpa_g_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id);

/*:153*//*160:*/
#line 1281 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id);

/*:160*//*190:*/
#line 1417 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol);
/*:190*//*196:*/
#line 1458 "./marpa.w"

static inline SYM symbol_proper_alias(SYM symbol);
/*:196*//*199:*/
#line 1485 "./marpa.w"

static inline SYM symbol_null_alias(SYM symbol);
/*:199*//*202:*/
#line 1496 "./marpa.w"

static inline
SYM symbol_alias_create(GRAMMAR g,SYM symbol);
/*:202*//*214:*/
#line 1576 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length);
/*:214*//*232:*/
#line 1817 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length);
/*:232*//*244:*/
#line 1997 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
/*:244*//*248:*/
#line 2009 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule);
/*:248*//*252:*/
#line 2025 "./marpa.w"

static inline gsize rule_length_get(RULE rule);
/*:252*//*266:*/
#line 2105 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule);
/*:266*//*270:*/
#line 2129 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule);
/*:270*//*284:*/
#line 2191 "./marpa.w"

static inline gint rule_is_nulling(GRAMMAR g,RULE rule);

/*:284*//*328:*/
#line 2386 "./marpa.w"

static inline gint symbol_instance_of_ahfa_item_get(AIM aim);
/*:328*//*335:*/
#line 2509 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:335*//*372:*/
#line 2845 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:372*//*411:*/
#line 3226 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:411*//*412:*/
#line 3233 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);
/*:412*//*422:*/
#line 3375 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:422*//*440:*/
#line 3593 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id);

/*:440*//*457:*/
#line 3714 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:457*//*462:*/
#line 3789 "./marpa.w"

static gint cmp_by_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:462*//*465:*/
#line 3808 "./marpa.w"

static gint cmp_by_postdot_and_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:465*//*485:*/
#line 3991 "./marpa.w"

static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM aim_sought);
/*:485*//*497:*/
#line 4076 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id);


/*:497*//*517:*/
#line 4247 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b);
/*:517*//*520:*/
#line 4276 "./marpa.w"

PRIVATE_NOT_INLINE void create_AHFA_states(struct marpa_g*g);
/*:520*//*539:*/
#line 4749 "./marpa.w"

static inline AHFA assign_AHFA_state(
AHFA state_p,GTree*duplicates);
/*:539*//*552:*/
#line 4948 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:552*//*555:*/
#line 5005 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
);
/*:555*//*568:*/
#line 5178 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition);
/*:568*//*570:*/
#line 5185 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition);
/*:570*//*572:*/
#line 5193 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix);
/*:572*//*574:*/
#line 5206 "./marpa.w"
static inline
TRANS*transitions_new(struct marpa_g*g);
/*:574*//*576:*/
#line 5220 "./marpa.w"

static inline
void transition_add(struct obstack*obstack,AHFA from_ahfa,SYMID symid,AHFA to_ahfa);
/*:576*//*578:*/
#line 5237 "./marpa.w"

static inline
void completion_count_inc(struct obstack*obstack,AHFA from_ahfa,SYMID symid);
/*:578*//*595:*/
#line 5376 "./marpa.w"

static inline void recce_unref(RECCE r);
/*:595*//*597:*/
#line 5397 "./marpa.w"

static inline RECCE recce_ref(RECCE r);
/*:597*//*600:*/
#line 5428 "./marpa.w"

static inline
void recce_free(struct marpa_r*r);

/*:600*//*609:*/
#line 5476 "./marpa.w"

static inline ES current_es_of_r(RECCE r);
/*:609*//*675:*/
#line 5852 "./marpa.w"

static inline ES earley_set_new(RECCE r,EARLEME id);
/*:675*//*695:*/
#line 6060 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key);
/*:695*//*697:*/
#line 6083 "./marpa.w"

static inline
EIM earley_item_assign(const RECCE r,const ES set,const ES origin,const AHFA state);
/*:697*//*702:*/
#line 6148 "./marpa.w"

static const char*invalid_source_type_message(guint type);
/*:702*//*714:*/
#line 6296 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r);
/*:714*//*733:*/
#line 6523 "./marpa.w"

static inline PIM*pim_sym_p_find(ES set,SYMID symid);
/*:733*//*735:*/
#line 6545 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid);
/*:735*//*759:*/
#line 6815 "./marpa.w"
static inline void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
TOK token);
/*:759*//*761:*/
#line 6847 "./marpa.w"
static inline void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause);
/*:761*//*768:*/
#line 6954 "./marpa.w"
static inline void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause);

/*:768*//*771:*/
#line 6995 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item);

/*:771*//*795:*/
#line 7284 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r);
/*:795*//*814:*/
#line 7565 "./marpa.w"

static inline
TOK token_new(struct marpa_r*r,SYMID symbol_id,gpointer value);
/*:814*//*822:*/
#line 7621 "./marpa.w"

static inline gint alternative_insertion_point(RECCE r,ALT new_alternative);
/*:822*//*824:*/
#line 7662 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b);
/*:824*//*826:*/
#line 7686 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme);
/*:826*//*828:*/
#line 7703 "./marpa.w"

static inline gint alternative_insert(RECCE r,ALT alternative);
/*:828*//*867:*/
#line 8157 "./marpa.w"

static inline void earley_set_update_items(RECCE r,ES set);
/*:867*//*869:*/
#line 8181 "./marpa.w"

static inline void r_update_earley_sets(RECCE r);
/*:869*//*872:*/
#line 8207 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES set);
/*:872*//*920:*/
#line 8776 "./marpa.w"

static inline void ur_node_stack_init(URS stack);
/*:920*//*922:*/
#line 8786 "./marpa.w"

static inline void ur_node_stack_reset(URS stack);
/*:922*//*924:*/
#line 8793 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack);
/*:924*//*926:*/
#line 8803 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev);
/*:926*//*928:*/
#line 8814 "./marpa.w"

static inline void ur_node_push(URS stack,EIM earley_item,AEX aex);
/*:928*//*930:*/
#line 8832 "./marpa.w"

static inline UR ur_node_pop(URS stack);
/*:930*//*935:*/
#line 8897 "./marpa.w"

static inline gint psia_test_and_set(
struct obstack*obs,
struct s_bocage_setup_per_es*per_es_data,
EIM earley_item,
AEX ahfa_element_ix);
/*:935*//*972:*/
#line 9522 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base);
/*:972*//*974:*/
#line 9536 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item);
/*:974*//*981:*/
#line 9657 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause);
/*:981*//*984:*/
#line 9683 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause);
/*:984*//*1025:*/
#line 10250 "./marpa.w"

static inline SYMID and_node_token(AND and_node,gpointer*value_p);
/*:1025*//*1049:*/
#line 10440 "./marpa.w"

PRIVATE_NOT_INLINE BOCAGE r_create_null_bocage(RECCE r,BOCAGE b);
/*:1049*//*1064:*/
#line 10606 "./marpa.w"

static inline void bocage_unref(BOCAGE b);
/*:1064*//*1066:*/
#line 10627 "./marpa.w"

static inline BOCAGE bocage_ref(BOCAGE b);
/*:1066*//*1069:*/
#line 10652 "./marpa.w"

void
bocage_free(BOCAGE b);
/*:1069*//*1091:*/
#line 10829 "./marpa.w"

static inline void tree_exhaust(TREE t);
/*:1091*//*1099:*/
#line 10886 "./marpa.w"

static inline void tree_unref(TREE t);
/*:1099*//*1101:*/
#line 10907 "./marpa.w"

static inline TREE tree_ref(TREE t);
/*:1101*//*1103:*/
#line 10924 "./marpa.w"

static inline void tree_free(TREE t);
/*:1103*//*1108:*/
#line 10969 "./marpa.w"

static inline void tree_pause(TREE t);
static inline void tree_unpause(TREE t);
/*:1108*//*1116:*/
#line 11056 "./marpa.w"

static inline void tree_and_node_claim(TREE tree,ANDID and_node_id);
static inline void tree_and_node_release(TREE tree,ANDID and_node_id);
static inline gint tree_and_node_try(TREE tree,ANDID and_node_id);
/*:1116*//*1123:*/
#line 11208 "./marpa.w"

static inline gint or_node_next_choice(ORDER o,TREE tree,OR or_node,gint start_choice);
/*:1123*//*1140:*/
#line 11327 "./marpa.w"

static inline void order_unref(ORDER o);
/*:1140*//*1142:*/
#line 11348 "./marpa.w"

static inline ORDER order_ref(ORDER o);
/*:1142*//*1144:*/
#line 11365 "./marpa.w"

static inline void order_strip(ORDER o);
/*:1144*//*1146:*/
#line 11376 "./marpa.w"

static inline void order_freeze(ORDER o);
/*:1146*//*1148:*/
#line 11384 "./marpa.w"

static inline void order_free(ORDER o);
/*:1148*//*1158:*/
#line 11552 "./marpa.w"

static inline ANDID and_order_get(ORDER o,OR or_node,gint ix);
/*:1158*//*1195:*/
#line 11894 "./marpa.w"

static inline void value_unref(VALUE v);
/*:1195*//*1197:*/
#line 11915 "./marpa.w"

static inline VALUE value_ref(VALUE v);
/*:1197*//*1199:*/
#line 11932 "./marpa.w"

static inline void value_free(VALUE v);
/*:1199*//*1215:*/
#line 12130 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:1215*//*1217:*/
#line 12140 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:1217*//*1218:*/
#line 12144 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);
/*:1218*//*1220:*/
#line 12164 "./marpa.w"

static inline Bit_Vector bv_obs_create(struct obstack*obs,guint bits);
/*:1220*//*1223:*/
#line 12197 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:1223*//*1225:*/
#line 12216 "./marpa.w"

static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from);

/*:1225*//*1227:*/
#line 12229 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:1227*//*1229:*/
#line 12239 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:1229*//*1231:*/
#line 12247 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:1231*//*1233:*/
#line 12260 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:1233*//*1235:*/
#line 12264 "./marpa.w"

static inline void bv_clear(Bit_Vector bv);
/*:1235*//*1237:*/
#line 12280 "./marpa.w"

static inline void bv_over_clear(Bit_Vector bv,guint bit);
/*:1237*//*1241:*/
#line 12294 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:1241*//*1243:*/
#line 12302 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:1243*//*1245:*/
#line 12310 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:1245*//*1247:*/
#line 12315 "./marpa.w"

static inline gboolean bv_bit_test_and_set(Bit_Vector vector,guint bit);
/*:1247*//*1250:*/
#line 12342 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:1250*//*1252:*/
#line 12355 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:1252*//*1254:*/
#line 12367 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1254*//*1256:*/
#line 12379 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1256*//*1258:*/
#line 12391 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:1258*//*1260:*/
#line 12465 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:1260*//*1262:*/
#line 12483 "./marpa.w"

static inline guint bv_count(Bit_Vector v);

/*:1262*//*1268:*/
#line 12572 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:1268*//*1273:*/
#line 12620 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:1273*//*1275:*/
#line 12628 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:1275*//*1277:*/
#line 12642 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:1277*//*1279:*/
#line 12660 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:1279*//*1282:*/
#line 12669 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:1282*//*1285:*/
#line 12678 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:1285*//*1288:*/
#line 12687 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:1288*//*1290:*/
#line 12740 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:1290*//*1300:*/
#line 12846 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_size);

/*:1300*//*1315:*/
#line 12980 "./marpa.w"

static inline void psar_init(const PSAR psar,gint length);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
/*:1315*//*1321:*/
#line 13038 "./marpa.w"

static inline void psar_reset(const PSAR psar);
/*:1321*//*1323:*/
#line 13057 "./marpa.w"

static inline void psar_dealloc(const PSAR psar);
/*:1323*//*1325:*/
#line 13078 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar);
/*:1325*//*1329:*/
#line 13104 "./marpa.w"

static inline PSL psl_alloc(const PSAR psar);
/*:1329*//*1363:*/
#line 13378 "./marpa.w"

static void set_error(struct marpa_g*g,Marpa_Error_Code code,
const char*message,guint flags);
static void r_error(struct marpa_r*r,Marpa_Error_Code code,
const char*message,guint flags);
/*:1363*//*1369:*/
#line 13507 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*eim_tag_safe(gchar*buffer,EIM eim);
PRIVATE_NOT_INLINE gchar*eim_tag(EIM eim);
#endif
/*:1369*//*1371:*/
#line 13536 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*lim_tag_safe(gchar*buffer,LIM lim);
PRIVATE_NOT_INLINE gchar*lim_tag(LIM lim);
#endif
/*:1371*//*1373:*/
#line 13566 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*or_tag_safe(gchar*buffer,OR or);
PRIVATE_NOT_INLINE const gchar*or_tag(OR or);
#endif
/*:1373*//*1375:*/
#line 13602 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*aim_tag_safe(gchar*buffer,AIM aim);
PRIVATE_NOT_INLINE const gchar*aim_tag(AIM aim);
#endif
/*:1375*/
#line 13687 "./marpa.w"

/*59:*/
#line 712 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symid,
SYM symbol)
{
g_array_insert_val(g->t_symbols,(unsigned)symid,symbol);
}

/*:59*//*69:*/
#line 755 "./marpa.w"

static inline
void rule_add(
struct marpa_g*g,
RULEID rule_id,
RULE rule)
{
g_array_insert_val(g->t_rules,(unsigned)rule_id,rule);
Size_of_G(g)+= 1+Length_of_RULE(rule);
g->t_max_rule_length= MAX(Length_of_RULE(rule),g->t_max_rule_length);
}

/*:69*/
#line 13688 "./marpa.w"

/*36:*/
#line 556 "./marpa.w"

const gchar*
marpa_check_version(guint required_major,
guint required_minor,
guint required_micro)
{
gint marpa_effective_micro= 100*MARPA_MINOR_VERSION+MARPA_MICRO_VERSION;
gint required_effective_micro= 100*required_minor+required_micro;

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
#line 616 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);

g->t_is_ok= 0;
/*46:*/
#line 630 "./marpa.w"

g->t_ref_count= 1;

/*:46*//*54:*/
#line 691 "./marpa.w"

g->t_symbols= g_array_new(FALSE,FALSE,sizeof(SYM));
/*:54*//*63:*/
#line 736 "./marpa.w"

g->t_rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:63*//*72:*/
#line 774 "./marpa.w"

Default_Value_of_G(g)= NULL;
/*:72*//*78:*/
#line 794 "./marpa.w"

g->t_start_symid= -1;
/*:78*//*84:*/
#line 824 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;
/*:84*//*88:*/
#line 851 "./marpa.w"

Size_of_G(g)= 0;

/*:88*//*91:*/
#line 864 "./marpa.w"

g->t_max_rule_length= 0;

/*:91*//*95:*/
#line 872 "./marpa.w"

g->t_is_precomputed= FALSE;
/*:95*//*98:*/
#line 884 "./marpa.w"

g->t_has_loop= FALSE;
/*:98*//*102:*/
#line 902 "./marpa.w"

g->t_is_lhs_terminal_ok= TRUE;
/*:102*//*108:*/
#line 936 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:108*//*116:*/
#line 979 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:116*//*125:*/
#line 1054 "./marpa.w"

obstack_init(&g->t_obs);
obstack_init(&g->t_obs_tricky);
/*:125*//*132:*/
#line 1100 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:132*//*437:*/
#line 3580 "./marpa.w"

g->t_AHFA_items= NULL;
g->t_AHFA_items_by_rule= NULL;
/*:437*//*492:*/
#line 4046 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:492*/
#line 621 "./marpa.w"


g->t_is_ok= I_AM_OK;
return g;}
/*:42*//*48:*/
#line 642 "./marpa.w"

void
grammar_unref(GRAMMAR g)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,g->t_ref_count);
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

/*:48*//*50:*/
#line 661 "./marpa.w"

static inline GRAMMAR
grammar_ref(GRAMMAR g)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,g->t_ref_count);
MARPA_ASSERT(g->t_ref_count> 0)
g->t_ref_count++;
return g;
}
Marpa_Grammar
marpa_g_ref(Marpa_Grammar g)
{return grammar_ref(g);}

/*:50*//*51:*/
#line 674 "./marpa.w"

void grammar_free(struct marpa_g*g)
{
MARPA_DEBUG3("%s: Destroying grammar %p",G_STRLOC,g);
/*55:*/
#line 693 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->t_symbols->len;id++)
{symbol_free(SYM_by_ID(id));}}
g_array_free(g->t_symbols,TRUE);

/*:55*//*64:*/
#line 738 "./marpa.w"

g_array_free(g->t_rules,TRUE);

/*:64*//*109:*/
#line 937 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:109*//*117:*/
#line 981 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:117*//*126:*/
#line 1057 "./marpa.w"

obstack_free(&g->t_obs,NULL);
obstack_free(&g->t_obs_tricky,NULL);

/*:126*//*438:*/
#line 3583 "./marpa.w"

if(g->t_AHFA_items){g_free(g->t_AHFA_items);};
if(g->t_AHFA_items_by_rule){g_free(g->t_AHFA_items_by_rule);};

/*:438*//*493:*/
#line 4050 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*494:*/
#line 4060 "./marpa.w"
{
TRANS*ahfa_transitions= TRANSs_of_AHFA(ahfa_state);
if(ahfa_transitions)
g_free(TRANSs_of_AHFA(ahfa_state));
}

/*:494*/
#line 4054 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:493*/
#line 678 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:51*//*57:*/
#line 702 "./marpa.w"

gint marpa_g_symbol_count(struct marpa_g*g){
return SYM_Count_of_G(g);
}

/*:57*//*60:*/
#line 723 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid){
return symid>=0&&(guint)symid<g->t_symbols->len;
}
/*:60*//*67:*/
#line 745 "./marpa.w"

gint marpa_g_rule_count(struct marpa_g*g){
return RULE_Count_of_G(g);
}

/*:67*//*74:*/
#line 778 "./marpa.w"

gpointer marpa_g_default_value(struct marpa_g*g)
{return Default_Value_of_G(g);}
/*:74*//*76:*/
#line 783 "./marpa.w"

gboolean marpa_g_default_value_set(struct marpa_g*g,gpointer default_value)
{
/*1344:*/
#line 13254 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1344*/
#line 786 "./marpa.w"

/*1347:*/
#line 13264 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1347*/
#line 787 "./marpa.w"

Default_Value_of_G(g)= default_value;
return TRUE;
}

/*:76*//*79:*/
#line 796 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(struct marpa_g*g)
{return g->t_start_symid;}
/*:79*//*81:*/
#line 803 "./marpa.w"

gboolean marpa_g_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1344:*/
#line 13254 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1344*/
#line 806 "./marpa.w"

/*1347:*/
#line 13264 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1347*/
#line 807 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 808 "./marpa.w"

g->t_start_symid= symid;
return TRUE;
}
/*:81*//*96:*/
#line 874 "./marpa.w"

gboolean marpa_g_is_precomputed(struct marpa_g*g)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 877 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 878 "./marpa.w"

return G_is_Precomputed(g);
}

/*:96*//*100:*/
#line 888 "./marpa.w"

gboolean marpa_g_has_loop(struct marpa_g*g)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 891 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 892 "./marpa.w"

return g->t_has_loop;
}

/*:100*//*103:*/
#line 905 "./marpa.w"

gboolean marpa_g_is_lhs_terminal_ok(struct marpa_g*g)
{return g->t_is_lhs_terminal_ok;}
/*:103*//*105:*/
#line 912 "./marpa.w"

gboolean marpa_g_is_lhs_terminal_ok_set(
struct marpa_g*g,gboolean value)
{
if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return FALSE;
}
g->t_is_lhs_terminal_ok= value;
return TRUE;
}
/*:105*//*119:*/
#line 994 "./marpa.w"

static inline
void event_new(struct marpa_g*g,gint type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:119*//*121:*/
#line 1006 "./marpa.w"

void int_event_new(struct marpa_g*g,gint type,gint value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:121*//*123:*/
#line 1017 "./marpa.w"

gint
marpa_g_event(struct marpa_g*g,struct marpa_g_event*public_event,
gint ix)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1022 "./marpa.w"

const gint index_out_of_bounds= -1;
DSTACK events= &g->t_events;
GEV internal_event;
gint type;

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

/*:123*//*134:*/
#line 1111 "./marpa.w"

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

/*:134*//*140:*/
#line 1150 "./marpa.w"

static inline SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= g_malloc(sizeof(SYM_Object));
/*146:*/
#line 1182 "./marpa.w"
ID_of_SYM(symbol)= g->t_symbols->len;

/*:146*//*148:*/
#line 1191 "./marpa.w"

symbol->t_lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:148*//*155:*/
#line 1243 "./marpa.w"

symbol->t_rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:155*//*162:*/
#line 1286 "./marpa.w"

symbol->t_is_accessible= FALSE;
/*:162*//*166:*/
#line 1304 "./marpa.w"

symbol->t_is_counted= FALSE;
/*:166*//*170:*/
#line 1322 "./marpa.w"

symbol->t_is_nullable= FALSE;
/*:170*//*174:*/
#line 1341 "./marpa.w"

symbol->t_is_nulling= FALSE;
/*:174*//*178:*/
#line 1361 "./marpa.w"

symbol->t_is_terminal= FALSE;
/*:178*//*184:*/
#line 1387 "./marpa.w"

symbol->t_is_productive= FALSE;
/*:184*//*188:*/
#line 1405 "./marpa.w"
symbol->t_is_start= FALSE;
/*:188*//*194:*/
#line 1435 "./marpa.w"

symbol->t_is_proper_alias= FALSE;
symbol->t_is_nulling_alias= FALSE;
symbol->t_alias= NULL;

/*:194*//*206:*/
#line 1531 "./marpa.w"

symbol->t_virtual_lhs_rule= NULL;

/*:206*/
#line 1155 "./marpa.w"

{
SYMID id= ID_of_SYM(symbol);
g_symbol_add(g,id,symbol);
}
return symbol;
}

/*:140*//*142:*/
#line 1165 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(struct marpa_g*g)
{
SYMID id= ID_of_SYM(symbol_new(g));
return id;
}

/*:142*//*143:*/
#line 1173 "./marpa.w"

static inline void symbol_free(SYM symbol)
{/*149:*/
#line 1193 "./marpa.w"

g_array_free(symbol->t_lhs,TRUE);

/*:149*//*156:*/
#line 1245 "./marpa.w"
g_array_free(symbol->t_rhs,TRUE);

/*:156*/
#line 1175 "./marpa.w"
g_free(symbol);}
/*:143*//*151:*/
#line 1199 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_lhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1202 "./marpa.w"

GArray*symbol_lh_rules;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 1204 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1205 "./marpa.w"

symbol_lh_rules= SYM_by_ID(symid)->t_lhs;
return symbol_lh_rules->len;
}
Marpa_Rule_ID marpa_g_symbol_lhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1211 "./marpa.w"

GArray*symbol_lh_rules;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 1213 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1214 "./marpa.w"

if(ix<0){
MARPA_DEV_ERROR("symbol lhs index negative");
return failure_indicator;
}
symbol_lh_rules= SYM_by_ID(symid)->t_lhs;
if((guint)ix>=symbol_lh_rules->len){
MARPA_DEV_ERROR("symbol lhs index out of bounds");
return-1;
}
return g_array_index(symbol_lh_rules,RULEID,ix);
}

/*:151*//*152:*/
#line 1227 "./marpa.w"
static inline
void symbol_lhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_lhs,rule_id);}
void
marpa_g_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id)
{symbol_lhs_add(SYM_by_ID(symid),rule_id);}
/*:152*//*158:*/
#line 1250 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_rhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1253 "./marpa.w"

GArray*symbol_rh_rules;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 1255 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1256 "./marpa.w"

symbol_rh_rules= SYM_by_ID(symid)->t_rhs;
return symbol_rh_rules->len;
}
Marpa_Rule_ID marpa_g_symbol_rhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1262 "./marpa.w"

GArray*symbol_rh_rules;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 1264 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1265 "./marpa.w"

if(ix<0){
MARPA_DEV_ERROR("symbol rhs index negative");
return failure_indicator;
}
symbol_rh_rules= SYM_by_ID(symid)->t_rhs;
if((guint)ix>=symbol_rh_rules->len){
MARPA_DEV_ERROR("symbol rhs index out of bounds");
return-1;
}
return g_array_index(symbol_rh_rules,RULEID,ix);
}

/*:158*//*159:*/
#line 1278 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_rhs,rule_id);}
/*:159*//*163:*/
#line 1296 "./marpa.w"

gboolean marpa_g_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_accessible;}
/*:163*//*167:*/
#line 1314 "./marpa.w"

gboolean marpa_g_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_counted;}
/*:167*//*171:*/
#line 1332 "./marpa.w"

gboolean marpa_g_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_nullable;}
/*:171*//*175:*/
#line 1351 "./marpa.w"

gint marpa_g_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1353 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1354 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));}
/*:175*//*179:*/
#line 1373 "./marpa.w"

gboolean marpa_g_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYMID_is_Terminal(id);}
/*:179*//*181:*/
#line 1378 "./marpa.w"

void marpa_g_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYMID_is_Terminal(id)= value;}
/*:181*//*185:*/
#line 1397 "./marpa.w"

gboolean marpa_g_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_productive;}
/*:185*//*189:*/
#line 1408 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol)
{return symbol->t_is_start;}
gint marpa_g_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1413 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1414 "./marpa.w"

return symbol_is_start(SYM_by_ID(symid));
}
/*:189*//*195:*/
#line 1444 "./marpa.w"

static inline
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1452 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1453 "./marpa.w"

symbol= SYM_by_ID(symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}
/*:195*//*198:*/
#line 1467 "./marpa.w"

static inline
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1475 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1476 "./marpa.w"

symbol= SYM_by_ID(symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
MARPA_DEV_ERROR("no alias");
return-1;
}
return ID_of_SYM(alias);
}
/*:198*//*203:*/
#line 1499 "./marpa.w"
static inline
SYM symbol_alias_create(GRAMMAR g,SYM symbol)
{
SYM alias= symbol_new(g);
symbol->t_is_proper_alias= TRUE;
SYM_is_Nulling(symbol)= FALSE;
symbol->t_is_nullable= FALSE;
symbol->t_alias= alias;
alias->t_is_nulling_alias= TRUE;
SYM_is_Nulling(alias)= TRUE;
alias->t_is_nullable= TRUE;
alias->t_is_productive= TRUE;
alias->t_is_accessible= symbol->t_is_accessible;
alias->t_alias= symbol;
return alias;
}

/*:203*//*208:*/
#line 1541 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_virtual_lhs_rule(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
RULE virtual_lhs_rule;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1546 "./marpa.w"

/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1547 "./marpa.w"

symbol= SYM_by_ID(symid);
virtual_lhs_rule= symbol->t_virtual_lhs_rule;
return virtual_lhs_rule==NULL?-1:ID_of_RULE(virtual_lhs_rule);
}

/*:208*//*215:*/
#line 1582 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length)
{
/*1345:*/
#line 13256 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1345*/
#line 1587 "./marpa.w"

RULE rule;
const gint rule_sizeof= G_STRUCT_OFFSET(struct s_rule,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
/*241:*/
#line 1977 "./marpa.w"

{
SYMID symid= lhs;
/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1980 "./marpa.w"

}
{gint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1349:*/
#line 13274 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1349*/
#line 1985 "./marpa.w"

}
}

/*:241*/
#line 1591 "./marpa.w"

rule= obstack_alloc(&g->t_obs,rule_sizeof);
/*242:*/
#line 1989 "./marpa.w"

Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
{gint i;for(i= 0;i<length;i++){
rule->t_symbols[i+1]= rhs[i];}}
/*:242*/
#line 1593 "./marpa.w"

/*257:*/
#line 2045 "./marpa.w"
rule->t_id= g->t_rules->len;

/*:257*//*260:*/
#line 2057 "./marpa.w"

rule->t_is_discard= FALSE;
/*:260*//*274:*/
#line 2141 "./marpa.w"

rule->t_is_loop= FALSE;
/*:274*//*279:*/
#line 2162 "./marpa.w"

rule->t_is_virtual_loop= FALSE;
/*:279*//*286:*/
#line 2198 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:286*//*290:*/
#line 2214 "./marpa.w"

rule->t_is_start= FALSE;
/*:290*//*294:*/
#line 2245 "./marpa.w"

RULE_is_Virtual_LHS(rule)= FALSE;
/*:294*//*298:*/
#line 2260 "./marpa.w"

RULE_is_Virtual_RHS(rule)= FALSE;
/*:298*//*302:*/
#line 2277 "./marpa.w"
rule->t_virtual_start= -1;
/*:302*//*306:*/
#line 2293 "./marpa.w"
rule->t_virtual_end= -1;
/*:306*//*311:*/
#line 2309 "./marpa.w"
rule->t_original= -1;
/*:311*//*316:*/
#line 2328 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:316*//*320:*/
#line 2341 "./marpa.w"

rule->t_is_semantic_equivalent= FALSE;
/*:320*//*327:*/
#line 2384 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:327*/
#line 1594 "./marpa.w"

rule_add(g,rule->t_id,rule);
/*234:*/
#line 1855 "./marpa.w"

symbol_lhs_add(SYM_by_ID(rule->t_symbols[0]),rule->t_id);
if(Length_of_RULE(rule)> 0){
gint rh_list_ix;
const guint alloc_size= Length_of_RULE(rule)*sizeof(SYMID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*238:*/
#line 1922 "./marpa.w"

{

gint rhs_ix= Length_of_RULE(rule)-1;
rh_symbol_list[0]= RHS_ID_of_RULE(rule,(unsigned)rhs_ix);
rh_symbol_list_length= 1;
rhs_ix--;
for(;rhs_ix>=0;rhs_ix--){
gint higher_ix;
Marpa_Symbol_ID new_symid= RHS_ID_of_RULE(rule,(unsigned)rhs_ix);
gint next_highest_ix= rh_symbol_list_length-1;
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

/*:238*/
#line 1863 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(rh_symbol_list[rh_list_ix]),
rule->t_id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:234*/
#line 1596 "./marpa.w"

return rule;
}

/*:215*//*217:*/
#line 1603 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
Marpa_Rule_ID rule_id;
RULE rule;
if(length> MAX_RHS_LENGTH){
MARPA_DEV_ERROR("rhs too long");
return-1;
}
if(is_rule_duplicate(g,lhs,rhs,length)==TRUE){
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
return-1;
}
rule= rule_start(g,lhs,rhs,length);
if(!rule){return-1;}
rule_id= rule->t_id;
return rule_id;
}

/*:217*//*219:*/
#line 1627 "./marpa.w"

gint marpa_g_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags)
{
RULE original_rule;
RULEID original_rule_id;
SYM internal_lhs;
SYMID internal_lhs_id,*temp_rhs;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 1636 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 1637 "./marpa.w"

/*1347:*/
#line 13264 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1347*/
#line 1638 "./marpa.w"

if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE)
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
return failure_indicator;
}
G_EVENTS_CLEAR(g);

/*220:*/
#line 1664 "./marpa.w"

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
int_event_new(g,MARPA_G_EV_NEW_RULE,original_rule_id);
}

/*:220*/
#line 1646 "./marpa.w"

/*221:*/
#line 1679 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
MARPA_DEV_ERROR("bad separator");
return failure_indicator;
}

/*:221*/
#line 1647 "./marpa.w"

/*222:*/
#line 1685 "./marpa.w"

SYM_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(separator_id)->t_is_counted= 1;}
/*:222*/
#line 1648 "./marpa.w"

if(min==0){/*223:*/
#line 1688 "./marpa.w"

{
RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1354:*/
#line 13299 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1354*/
#line 1691 "./marpa.w"
}
rule->t_is_semantic_equivalent= TRUE;
rule->t_original= original_rule_id;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}
/*:223*/
#line 1649 "./marpa.w"
}
min= 1;
/*224:*/
#line 1696 "./marpa.w"

{
internal_lhs= symbol_new(g);
internal_lhs_id= ID_of_SYM(internal_lhs);
int_event_new(g,MARPA_G_EV_NEW_SYMBOL,internal_lhs_id);
}

/*:224*/
#line 1651 "./marpa.w"

/*225:*/
#line 1714 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:225*/
#line 1652 "./marpa.w"

/*227:*/
#line 1717 "./marpa.w"

{
RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1354:*/
#line 13299 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1354*/
#line 1722 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;

RULE_is_Virtual_RHS(rule)= TRUE;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}

/*:227*/
#line 1653 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*228:*/
#line 1731 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1354:*/
#line 13299 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1354*/
#line 1736 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;
RULE_is_Virtual_RHS(rule)= TRUE;
Real_SYM_Count_of_RULE(rule)= 1;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}
/*:228*/
#line 1655 "./marpa.w"

}
/*229:*/
#line 1746 "./marpa.w"

{RULE rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1354:*/
#line 13299 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1354*/
#line 1756 "./marpa.w"
}
RULE_is_Virtual_LHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}
/*:229*/
#line 1657 "./marpa.w"

/*230:*/
#line 1761 "./marpa.w"

{RULE rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1354:*/
#line 13299 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1354*/
#line 1768 "./marpa.w"
}
RULE_is_Virtual_LHS(rule)= 1;
RULE_is_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix-1;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}

/*:230*/
#line 1658 "./marpa.w"

/*226:*/
#line 1716 "./marpa.w"
g_free(temp_rhs);
/*:226*/
#line 1659 "./marpa.w"

return G_EVENT_COUNT(g);
}

/*:219*//*233:*/
#line 1821 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length)
{
gint ix;
SYM lhs= SYM_by_ID(lhs_id);
GArray*same_lhs_array= lhs->t_lhs;
gint same_lhs_count= same_lhs_array->len;
for(ix= 0;ix<same_lhs_count;ix++){
RULEID same_lhs_rule_id= ((RULEID*)(same_lhs_array->data))[ix];
gint rhs_position;
RULE rule= RULE_by_ID(g,same_lhs_rule_id);
const gint rule_length= Length_of_RULE(rule);
if(rule_length!=length){goto RULE_IS_NOT_DUPLICATE;}
for(rhs_position= 0;rhs_position<rule_length;rhs_position++){
if(RHS_ID_of_RULE(rule,rhs_position)!=rhs_ids[rhs_position]){
goto RULE_IS_NOT_DUPLICATE;
}
}
return TRUE;
RULE_IS_NOT_DUPLICATE:;
}
return FALSE;
}

/*:233*//*243:*/
#line 1994 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule){
return rule->t_symbols[0];}
/*:243*//*245:*/
#line 1999 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2001 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2002 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));}
/*:245*//*247:*/
#line 2006 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule){
return rule->t_symbols+1;}
/*:247*//*250:*/
#line 2013 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix){
RULE rule;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2016 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2017 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:250*//*251:*/
#line 2022 "./marpa.w"

static inline gsize rule_length_get(RULE rule){
return Length_of_RULE(rule);}
/*:251*//*253:*/
#line 2027 "./marpa.w"

gint marpa_g_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2029 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2030 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}
/*:253*//*261:*/
#line 2059 "./marpa.w"

gboolean marpa_g_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_discard;}
/*:261*//*265:*/
#line 2092 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(lhs_id)->t_is_accessible;}
gint marpa_g_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2099 "./marpa.w"

RULE rule;
/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2101 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:265*//*269:*/
#line 2112 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++){
Marpa_Symbol_ID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_by_ID(rhs_id)->t_is_productive)return FALSE;
}
return TRUE;}
gint marpa_g_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2123 "./marpa.w"

RULE rule;
/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2125 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}
/*:269*//*275:*/
#line 2145 "./marpa.w"

gint marpa_g_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2148 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2149 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}
/*:275*//*280:*/
#line 2166 "./marpa.w"

gint marpa_g_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2169 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2170 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;}
/*:280*//*283:*/
#line 2178 "./marpa.w"

static inline gint
rule_is_nulling(GRAMMAR g,RULE rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++)
{
SYMID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_is_Nulling(SYM_by_ID(rhs_id)))
return FALSE;
}
return TRUE;
}
/*:283*//*287:*/
#line 2202 "./marpa.w"

gint marpa_g_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2205 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2206 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}
/*:287*//*291:*/
#line 2218 "./marpa.w"

gint marpa_g_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2221 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2222 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_start;}
/*:291*//*295:*/
#line 2248 "./marpa.w"

gboolean marpa_g_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2251 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2252 "./marpa.w"

return RULE_is_Virtual_LHS(RULE_by_ID(g,rule_id));}
/*:295*//*299:*/
#line 2263 "./marpa.w"

gboolean marpa_g_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2266 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2267 "./marpa.w"

return RULE_is_Virtual_RHS(RULE_by_ID(g,rule_id));}
/*:299*//*303:*/
#line 2278 "./marpa.w"

guint marpa_g_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2281 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2282 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}
/*:303*//*307:*/
#line 2294 "./marpa.w"

guint marpa_g_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2297 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2298 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}
/*:307*//*312:*/
#line 2310 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2313 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2314 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_original;
}
/*:312*//*318:*/
#line 2331 "./marpa.w"

gint marpa_g_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2334 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2335 "./marpa.w"

return Real_SYM_Count_of_RULE(RULE_by_ID(g,rule_id));
}

/*:318*//*323:*/
#line 2354 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2359 "./marpa.w"

/*1350:*/
#line 13279 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1350*/
#line 2360 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(RULE_is_Virtual_LHS(rule))return-1;
if(rule->t_is_semantic_equivalent)return rule->t_original;
return rule_id;
}

/*:323*//*330:*/
#line 2400 "./marpa.w"

static inline gint
symbol_instance_of_ahfa_item_get(AIM aim)
{
gint position= Position_of_AIM(aim);
const gint null_count= Null_Count_of_AIM(aim);
if(position<0||position-null_count> 0){

const RULE rule= RULE_of_AIM(aim);
position= Position_of_AIM(aim-1);
return SYMI_of_RULE(rule)+position;
}
return-1;
}

/*:330*//*331:*/
#line 2426 "./marpa.w"

gint marpa_g_precompute(struct marpa_g*g)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 2429 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 2430 "./marpa.w"

G_EVENTS_CLEAR(g);
if(!census(g))return failure_indicator;
if(!CHAF_rewrite(g))return failure_indicator;
if(!g_augment(g))return failure_indicator;
if(!G_is_Trivial(g)){
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*586:*/
#line 5312 "./marpa.w"
{
gint symbol_count= SYM_Count_of_G(g);
gint symid;
Bit_Vector bv_is_terminal= bv_create((guint)symbol_count);
g->t_bv_symid_is_terminal= bv_is_terminal;
for(symid= 0;symid<symbol_count;symid++){
if(!SYMID_is_Terminal(symid))continue;
bv_bit_set(bv_is_terminal,(guint)symid);
}
}

/*:586*/
#line 2439 "./marpa.w"

}
return G_EVENT_COUNT(g);
}
/*:331*//*334:*/
#line 2478 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*1345:*/
#line 13256 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1345*/
#line 2481 "./marpa.w"

/*336:*/
#line 2511 "./marpa.w"

guint pre_rewrite_rule_count= g->t_rules->len;
guint pre_rewrite_symbol_count= g->t_symbols->len;

/*:336*//*341:*/
#line 2545 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_start_symid;
SYM original_start_symbol;

/*:341*//*345:*/
#line 2584 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:345*//*351:*/
#line 2635 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:351*//*353:*/
#line 2659 "./marpa.w"

Bit_Vector nullable_v;
/*:353*//*357:*/
#line 2684 "./marpa.w"

Bit_Vector productive_v;
/*:357*//*360:*/
#line 2725 "./marpa.w"
Bit_Matrix reach_matrix;
/*:360*//*363:*/
#line 2743 "./marpa.w"

Bit_Vector accessible_v;

/*:363*/
#line 2482 "./marpa.w"

/*337:*/
#line 2515 "./marpa.w"

if(g->t_rules->len<=0){MARPA_ERROR(MARPA_ERR_NO_RULES);return NULL;}
/*:337*/
#line 2483 "./marpa.w"

/*338:*/
#line 2522 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return NULL;}
/*:338*/
#line 2484 "./marpa.w"

/*340:*/
#line 2530 "./marpa.w"

if(original_start_symid<0){
MARPA_ERROR(MARPA_ERR_NO_START_SYMBOL);
return failure_indicator;
}
if(!symbol_is_valid(g,original_start_symid)){
MARPA_DEV_ERROR("invalid start symbol");
return failure_indicator;
}
original_start_symbol= SYM_by_ID(original_start_symid);
if(original_start_symbol->t_lhs->len<=0){
MARPA_ERROR(MARPA_ERR_START_NOT_LHS);
return failure_indicator;
}

/*:340*/
#line 2485 "./marpa.w"

/*342:*/
#line 2549 "./marpa.w"

{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;
rule_id<(Marpa_Rule_ID)pre_rewrite_rule_count;
rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
bv_bit_set(lhs_v,(guint)lhs_id);
if(Length_of_RULE(rule)<=0){
bv_bit_set(empty_lhs_v,(guint)lhs_id);
have_empty_rule= 1;
}
}
}
/*:342*/
#line 2486 "./marpa.w"

/*343:*/
#line 2568 "./marpa.w"

{Marpa_Symbol_ID symid;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symid= 0;
symid<(Marpa_Symbol_ID)pre_rewrite_symbol_count;
symid++){
SYM symbol= SYM_by_ID(symid);
if(SYM_is_Terminal(symbol)){
bv_bit_set(terminal_v,(guint)symid);
have_marked_terminals= 1;
}
}}
/*:343*/
#line 2487 "./marpa.w"

if(have_marked_terminals){
/*347:*/
#line 2602 "./marpa.w"

if(!g->t_is_lhs_terminal_ok){
gint no_lhs_terminals;
Bit_Vector bad_lhs_v= bv_clone(terminal_v);
bv_and(bad_lhs_v,bad_lhs_v,lhs_v);
no_lhs_terminals= bv_is_empty(bad_lhs_v);
bv_free(bad_lhs_v);
if(!no_lhs_terminals){
MARPA_ERROR(MARPA_ERR_LHS_IS_TERMINAL);
return NULL;
}
}

/*:347*/
#line 2489 "./marpa.w"

}else{
/*346:*/
#line 2588 "./marpa.w"

if(have_empty_rule&&g->t_is_lhs_terminal_ok){
MARPA_ERROR(MARPA_ERR_NULL_RULE_UNMARKED_TERMINALS);
return NULL;
}
/*:346*/
#line 2491 "./marpa.w"
;
if(g->t_is_lhs_terminal_ok){
/*348:*/
#line 2615 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->t_symbols->len;symid++)
{SYMID_is_Terminal(symid)= 1;}}
/*:348*/
#line 2493 "./marpa.w"

}else{
/*349:*/
#line 2620 "./marpa.w"

{guint start= 0;
guint min,max;
bv_not(terminal_v,lhs_v);
while(bv_scan(terminal_v,start,&min,&max)){
Marpa_Symbol_ID symid;
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
SYMID_is_Terminal(symid)= 1;
}
start= max+2;
}
}
/*:349*/
#line 2495 "./marpa.w"

}
}
/*352:*/
#line 2640 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
SYM symbol= SYM_by_ID(symid);
if(symbol->t_is_counted){
counted_nullables++;
}
symbol->t_is_nullable= 1;
}}
if(counted_nullables){
MARPA_ERROR(MARPA_ERR_COUNTED_NULLABLE);
return NULL;
}
}
/*:352*/
#line 2498 "./marpa.w"

/*355:*/
#line 2664 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(symid);
symbol->t_is_productive= 1;
}}
}
/*:355*/
#line 2499 "./marpa.w"

/*356:*/
#line 2678 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->t_start_symid))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
return NULL;
}
/*:356*/
#line 2500 "./marpa.w"

/*359:*/
#line 2707 "./marpa.w"

reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{guint symid,no_of_symbols= SYM_Count_of_G(g);
for(symid= 0;symid<no_of_symbols;symid++){
matrix_bit_set(reach_matrix,symid,symid);
}}
{Marpa_Rule_ID rule_id;
guint no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
guint rhs_ix,rule_length= Length_of_RULE(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,
(guint)lhs_id,(guint)RHS_ID_of_RULE(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:359*/
#line 2501 "./marpa.w"

/*362:*/
#line 2729 "./marpa.w"

accessible_v= matrix_row(reach_matrix,(guint)original_start_symid);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(symid);
symbol->t_is_accessible= 1;
}}
}
/*:362*/
#line 2502 "./marpa.w"

/*364:*/
#line 2748 "./marpa.w"

{
Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
guint min,max,start;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID productive_id;
for(productive_id= (Marpa_Symbol_ID)min;
productive_id<=(Marpa_Symbol_ID)max;productive_id++)
{
bv_and(reaches_terminal_v,terminal_v,
matrix_row(reach_matrix,(guint)productive_id));
if(bv_is_empty(reaches_terminal_v))
SYM_is_Nulling(SYM_by_ID(productive_id))= 1;
}
}
bv_free(reaches_terminal_v);
}

/*:364*/
#line 2503 "./marpa.w"

/*344:*/
#line 2580 "./marpa.w"

bv_free(terminal_v);
/*:344*//*350:*/
#line 2632 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:350*//*354:*/
#line 2661 "./marpa.w"

bv_free(nullable_v);

/*:354*//*358:*/
#line 2686 "./marpa.w"

bv_free(productive_v);

/*:358*/
#line 2504 "./marpa.w"

/*361:*/
#line 2726 "./marpa.w"

matrix_free(reach_matrix);

/*:361*/
#line 2505 "./marpa.w"

g->t_is_precomputed= TRUE;
return g;
}
/*:334*//*371:*/
#line 2824 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*373:*/
#line 2847 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:373*//*377:*/
#line 2897 "./marpa.w"

gint factor_count;
gint*factor_positions;
/*:377*//*382:*/
#line 2947 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:382*/
#line 2827 "./marpa.w"

/*378:*/
#line 2900 "./marpa.w"

factor_positions= g_new(gint,g->t_max_rule_length);
/*:378*//*383:*/
#line 2950 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:383*/
#line 2828 "./marpa.w"

/*375:*/
#line 2859 "./marpa.w"

{gint no_of_symbols= SYM_Count_of_G(g);
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

/*:375*/
#line 2829 "./marpa.w"

no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const gint rule_length= Length_of_RULE(rule);
gint nullable_suffix_ix= 0;
/*374:*/
#line 2851 "./marpa.w"

if(!RULE_is_Used(rule)){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}

/*:374*/
#line 2835 "./marpa.w"

/*376:*/
#line 2881 "./marpa.w"

{gint rhs_ix;
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
/*:376*/
#line 2836 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*380:*/
#line 2906 "./marpa.w"

RULE_is_Used(rule)= 0;
{


gint unprocessed_factor_count;

gint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);


gint piece_end,piece_start= 0;
for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*386:*/
#line 2960 "./marpa.w"

SYMID chaf_virtual_symid;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*381:*/
#line 2930 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:381*/
#line 2968 "./marpa.w"

/*387:*/
#line 2987 "./marpa.w"

{
gint remaining_rhs_length,piece_rhs_length;
/*388:*/
#line 2999 "./marpa.w"

{
gint real_symbol_count= piece_end-piece_start+1;
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
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3014 "./marpa.w"

}

/*:388*/
#line 2990 "./marpa.w"
;
/*389:*/
#line 3017 "./marpa.w"

{
gint chaf_rule_length= Length_of_RULE(rule)-piece_start;
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
gint real_symbol_count= remaining_rhs_length;
chaf_rule= 
rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3035 "./marpa.w"

}

/*:389*/
#line 2991 "./marpa.w"
;
/*390:*/
#line 3040 "./marpa.w"
{
Marpa_Symbol_ID proper_id= RHS_ID_of_RULE(rule,first_factor_position);
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
ID_of_SYM(alias);
}
{RULE chaf_rule;
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3050 "./marpa.w"

}

/*:390*/
#line 2992 "./marpa.w"
;
/*391:*/
#line 3059 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3064 "./marpa.w"

}

/*:391*/
#line 2993 "./marpa.w"
;
}

/*:387*/
#line 2969 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*381:*/
#line 2930 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:381*/
#line 2974 "./marpa.w"

/*393:*/
#line 3069 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
gint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:393*//*394:*/
#line 3078 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3084 "./marpa.w"


/*:394*//*395:*/
#line 3087 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3092 "./marpa.w"


/*:395*//*396:*/
#line 3095 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3101 "./marpa.w"


/*:396*//*397:*/
#line 3104 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3107 "./marpa.w"


/*:397*//*398:*/
#line 3110 "./marpa.w"
}

/*:398*/
#line 2975 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:386*/
#line 2921 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*399:*/
#line 3114 "./marpa.w"
{
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
gint second_factor_piece_position= second_factor_position-piece_start;
gint real_symbol_count;
gint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:399*//*400:*/
#line 3128 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3133 "./marpa.w"


/*:400*//*401:*/
#line 3136 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3141 "./marpa.w"


/*:401*//*402:*/
#line 3144 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3150 "./marpa.w"


/*:402*//*403:*/
#line 3154 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3158 "./marpa.w"

}

/*:403*//*404:*/
#line 3162 "./marpa.w"
}

/*:404*/
#line 2924 "./marpa.w"

}else{
/*405:*/
#line 3165 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
gint real_symbol_count;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:405*//*406:*/
#line 3176 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3181 "./marpa.w"


/*:406*//*407:*/
#line 3185 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3201 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_is_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:409*/
#line 3191 "./marpa.w"

}

/*:407*//*408:*/
#line 3195 "./marpa.w"
}

/*:408*/
#line 2926 "./marpa.w"

}
}

/*:380*/
#line 2839 "./marpa.w"

NEXT_RULE:;
}
/*379:*/
#line 2902 "./marpa.w"

g_free(factor_positions);

/*:379*//*384:*/
#line 2953 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:384*/
#line 2842 "./marpa.w"

return g;
}
/*:371*//*410:*/
#line 3220 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
return ID_of_SYM(alias);
}
/*:410*//*413:*/
#line 3235 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g->t_start_symid);
/*414:*/
#line 3249 "./marpa.w"

if(SYM_is_Nulling(old_start)){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:414*/
#line 3243 "./marpa.w"

if(proper_old_start){/*415:*/
#line 3259 "./marpa.w"
{
RULE new_start_rule;
proper_old_start->t_is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= ID_of_SYM(proper_new_start);
g->t_start_symid= proper_new_start_id;
proper_new_start->t_is_accessible= TRUE;
proper_new_start->t_is_productive= TRUE;
proper_new_start->t_is_start= TRUE;
new_start_rule= rule_start(g,proper_new_start_id,&ID_of_SYM(old_start),1);
new_start_rule->t_is_start= 1;
RULE_is_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= 1;
g->t_proper_start_rule= new_start_rule;
}

/*:415*/
#line 3244 "./marpa.w"
}
if(nulling_old_start){/*416:*/
#line 3280 "./marpa.w"
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
g->t_start_symid= nulling_new_start_id;
SYM_is_Nulling(nulling_new_start)= TRUE;
nulling_new_start->t_is_nullable= TRUE;
nulling_new_start->t_is_productive= TRUE;
nulling_new_start->t_is_accessible= TRUE;
}
nulling_new_start->t_is_start= TRUE;
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
new_start_rule->t_is_start= 1;
RULE_is_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= FALSE;
g->t_null_start_rule= new_start_rule;
}

/*:416*/
#line 3245 "./marpa.w"
}
return g;
}

/*:413*//*421:*/
#line 3357 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{
gint no_of_rules= RULE_Count_of_G(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_create((guint)no_of_rules,(guint)no_of_rules);
/*423:*/
#line 3384 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID proper_id;
gint rhs_ix,rule_length;
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
GArray*lhs_rules= rhs_symbol->t_lhs;
gint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,(guint)rule_id,
(guint)g_array_index(lhs_rules,Marpa_Rule_ID,ix));
}}
NEXT_RULE:;
}}

/*:423*/
#line 3365 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*424:*/
#line 3423 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule;
if(!matrix_bit_test(unit_transition_matrix,(guint)rule_id,(guint)rule_id))
continue;
loop_rule_count++;
rule= RULE_by_ID(g,rule_id);
rule->t_is_loop= TRUE;
rule->t_is_virtual_loop= rule->t_virtual_start<0||!RULE_is_Virtual_RHS(rule);
}}

/*:424*/
#line 3367 "./marpa.w"

if(loop_rule_count)
{
g->t_has_loop= TRUE;
int_event_new(g,MARPA_G_EV_LOOP_RULES,loop_rule_count);
}
matrix_free(unit_transition_matrix);
}
/*:421*//*439:*/
#line 3588 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id){
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}
/*:439*//*445:*/
#line 3629 "./marpa.w"

gint marpa_g_AHFA_item_count(struct marpa_g*g){
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 3631 "./marpa.w"

/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 3632 "./marpa.w"

return AIM_Count_of_G(g);
}
/*:445*//*447:*/
#line 3638 "./marpa.w"

Marpa_Rule_ID marpa_g_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 3641 "./marpa.w"

/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 3642 "./marpa.w"

/*1351:*/
#line 13284 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1351*/
#line 3643 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(item_id))->t_id;
}
/*:447*//*450:*/
#line 3652 "./marpa.w"

gint marpa_g_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 3655 "./marpa.w"

/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 3656 "./marpa.w"

/*1351:*/
#line 13284 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1351*/
#line 3657 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:450*//*452:*/
#line 3664 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 3667 "./marpa.w"

/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 3668 "./marpa.w"

/*1351:*/
#line 13284 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1351*/
#line 3669 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:452*//*454:*/
#line 3675 "./marpa.w"

gint marpa_g_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 3678 "./marpa.w"

/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 3679 "./marpa.w"

/*1351:*/
#line 13284 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1351*/
#line 3680 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:454*//*456:*/
#line 3691 "./marpa.w"

static inline
void create_AHFA_items(GRAMMAR g){
RULEID rule_id;
guint no_of_items;
guint no_of_rules= RULE_Count_of_G(g);
AIM base_item= g_new(struct s_AHFA_item,Size_of_G(g));
AIM current_item= base_item;
guint symbol_instance_of_next_rule= 0;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
if(RULE_is_Used(rule)){
/*458:*/
#line 3717 "./marpa.w"

{
gint leading_nulls= 0;
gint rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_RULE(rule);rhs_ix++)
{
SYMID rh_symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(rh_symid);
if(!symbol->t_is_nullable)
{
Last_Proper_SYMI_of_RULE(rule)= symbol_instance_of_next_rule+rhs_ix;
/*459:*/
#line 3741 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:459*/
#line 3728 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*460:*/
#line 3750 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:460*/
#line 3737 "./marpa.w"

current_item++;
}

/*:458*/
#line 3703 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
no_of_items= AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*461:*/
#line 3764 "./marpa.w"

{
AIM*items_by_rule= g_new(AIM,no_of_rules);
AIM items= g->t_AHFA_items;

Marpa_Rule_ID highest_found_rule_id= -1;
Marpa_AHFA_Item_ID item_id;


for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++)
{
items_by_rule[rule_id]= NULL;
}
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
AIM item= items+item_id;
Marpa_Rule_ID rule_id_for_item= RULE_of_AIM(item)->t_id;
if(rule_id_for_item<=highest_found_rule_id)
continue;
items_by_rule[rule_id_for_item]= item;
highest_found_rule_id= rule_id_for_item;
}
g->t_AHFA_items_by_rule= items_by_rule;
}

/*:461*/
#line 3711 "./marpa.w"

/*468:*/
#line 3840 "./marpa.w"

{
Marpa_AHFA_Item_ID item_id;
AIM*sort_array= g_new(struct s_AHFA_item*,no_of_items);
AIM items= g->t_AHFA_items;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
sort_array[item_id]= items+item_id;
}
g_qsort_with_data(sort_array,
(gint)no_of_items,sizeof(AIM),cmp_by_postdot_and_aimid,
(gpointer)NULL);
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
Sort_Key_of_AIM(sort_array[item_id])= item_id;
}
g_free(sort_array);
}

/*:468*/
#line 3712 "./marpa.w"

}
/*:456*//*464:*/
#line 3799 "./marpa.w"

static gint cmp_by_aimid(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED){
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:464*//*467:*/
#line 3817 "./marpa.w"

static gint cmp_by_postdot_and_aimid(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED){
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
gint a_postdot= Postdot_SYMID_of_AIM(a);
gint b_postdot= Postdot_SYMID_of_AIM(b);
if(a_postdot==b_postdot)
return Sort_Key_of_AIM(a)-Sort_Key_of_AIM(b);
if(a_postdot<0)return 1;
if(b_postdot<0)return-1;
return a_postdot-b_postdot;
}

/*:467*//*486:*/
#line 4001 "./marpa.w"

static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM sought_aim)
{
AIM*const aims= AIMs_of_AHFA(ahfa);
gint aim_count= AIM_Count_of_AHFA(ahfa);
gint hi= aim_count-1;
gint lo= 0;
while(hi>=lo){
gint trial_aex= lo+(hi-lo)/2;
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

/*:486*//*496:*/
#line 4071 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id){
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}
/*:496*//*500:*/
#line 4088 "./marpa.w"

gint marpa_g_AHFA_state_count(struct marpa_g*g){
return AHFA_Count_of_G(g);
}
/*:500*//*502:*/
#line 4095 "./marpa.w"

gint
marpa_g_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4098 "./marpa.w"

AHFA state;
/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 4100 "./marpa.w"

/*1352:*/
#line 13289 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1352*/
#line 4101 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}
/*:502*//*505:*/
#line 4114 "./marpa.w"

Marpa_AHFA_Item_ID marpa_g_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
gint item_ix){
AHFA state;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4119 "./marpa.w"

/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 4120 "./marpa.w"

/*1352:*/
#line 13289 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1352*/
#line 4121 "./marpa.w"

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

/*:505*//*506:*/
#line 4134 "./marpa.w"

gint marpa_g_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4138 "./marpa.w"

/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 4139 "./marpa.w"

/*1352:*/
#line 13289 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1352*/
#line 4140 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}
/*:506*//*511:*/
#line 4179 "./marpa.w"

Marpa_Rule_ID marpa_g_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
const gint no_completed_start_rule= -1;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4183 "./marpa.w"

AHFA state;
/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 4185 "./marpa.w"

/*1352:*/
#line 13289 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1352*/
#line 4186 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
if(AHFA_has_Completed_Start_Rule(state)){
const gint ahfa_item_count= state->t_item_count;
const AIM*ahfa_items= state->t_items;
gint ahfa_ix;
for(ahfa_ix= 0;ahfa_ix<ahfa_item_count;ahfa_ix++)
{
const AIM ahfa_item= ahfa_items[ahfa_ix];
if(AIM_is_Completion(ahfa_item))
{
const RULE rule= RULE_of_AIM(ahfa_item);
if(RULE_is_Start(rule))
return ID_of_RULE(rule);
}
}
/*1354:*/
#line 13299 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1354*/
#line 4202 "./marpa.w"

}
return no_completed_start_rule;
}

/*:511*//*515:*/
#line 4220 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 4223 "./marpa.w"

AHFA state;
/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 4225 "./marpa.w"

/*1352:*/
#line 13289 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1352*/
#line 4226 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:515*//*518:*/
#line 4249 "./marpa.w"

static gint AHFA_state_cmp(
gconstpointer ap,
gconstpointer bp)
{
AIM*items_a;
AIM*items_b;
const AHFA state_a= (AHFA)ap;
const AHFA state_b= (AHFA)bp;
const gint length_a= state_a->t_item_count;
const gint length_b= state_b->t_item_count;
gint major_key= length_a-length_b;
if(major_key)return major_key;
{
gint i,minor_key;
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

/*:518*//*521:*/
#line 4278 "./marpa.w"

PRIVATE_NOT_INLINE
void create_AHFA_states(struct marpa_g*g){
/*522:*/
#line 4297 "./marpa.w"

AHFA p_working_state;
const guint initial_no_of_states= 2*Size_of_G(g);
AIM AHFA_item_0_p= g->t_AHFA_items;
const guint symbol_count_of_g= SYM_Count_of_G(g);
const guint rule_count_of_g= RULE_Count_of_G(g);
Bit_Matrix prediction_matrix;
RULE*rule_by_sort_key= g_new(RULE,rule_count_of_g);
GTree*duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
struct obstack ahfa_work_obs;
gint ahfa_count_of_g;
AHFA ahfas_of_g;

/*:522*/
#line 4281 "./marpa.w"

/*523:*/
#line 4312 "./marpa.w"

/*524:*/
#line 4316 "./marpa.w"

{
guint item_id;
guint no_of_items_in_grammar= AIM_Count_of_G(g);
obstack_init(&ahfa_work_obs);
duplicates= g_tree_new(AHFA_state_cmp);
singleton_duplicates= g_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++)
{
singleton_duplicates[item_id]= NULL;
}
}

/*:524*/
#line 4313 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:523*/
#line 4282 "./marpa.w"

/*546:*/
#line 4825 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_create(symbol_count_of_g,symbol_count_of_g);
/*547:*/
#line 4834 "./marpa.w"

{
RULEID rule_id;
SYMID symid;
AIM*items_by_rule= g->t_AHFA_items_by_rule;
for(symid= 0;symid<(SYMID)symbol_count_of_g;symid++)
{

SYM symbol= SYM_by_ID(symid);
if(!SYMBOL_LHS_RULE_COUNT(symbol))
continue;
matrix_bit_set(symbol_by_symbol_matrix,(guint)symid,(guint)symid);
}
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
SYMID from,to;

AIM item= items_by_rule[rule_id];

if(!item)
continue;
from= LHS_ID_of_AIM(item);
to= Postdot_SYMID_of_AIM(item);

if(to<0)
continue;

matrix_bit_set(symbol_by_symbol_matrix,(guint)from,(guint)to);
}
}

/*:547*/
#line 4828 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*548:*/
#line 4871 "./marpa.w"
{
AIM*items_by_rule= g->t_AHFA_items_by_rule;
SYMID from_symid;
guint*sort_key_by_rule_id= g_new(guint,rule_count_of_g);
guint no_of_predictable_rules= 0;
/*549:*/
#line 4903 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
AIM item= items_by_rule[rule_id];
SYMID postdot;
if(!item)
goto NOT_A_PREDICTABLE_RULE;
postdot= Postdot_SYMID_of_AIM(item);
if(postdot<0)
goto NOT_A_PREDICTABLE_RULE;
sort_key_by_rule_id[rule_id]= postdot;
no_of_predictable_rules++;
continue;
NOT_A_PREDICTABLE_RULE:
sort_key_by_rule_id[rule_id]= G_MAXINT;
}
}

/*:549*/
#line 4877 "./marpa.w"

/*550:*/
#line 4923 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
rule_by_sort_key[rule_id]= RULE_by_ID(g,rule_id);
}
g_qsort_with_data(rule_by_sort_key,(gint)rule_count_of_g,
sizeof(RULE),cmp_by_rule_sort_key,
(gpointer)sort_key_by_rule_id);
}

/*:550*/
#line 4878 "./marpa.w"

/*553:*/
#line 4955 "./marpa.w"

{
guint sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:553*/
#line 4879 "./marpa.w"

/*554:*/
#line 4965 "./marpa.w"

{
prediction_matrix= matrix_create(symbol_count_of_g,no_of_predictable_rules);
for(from_symid= 0;from_symid<(SYMID)symbol_count_of_g;
from_symid++)
{

guint min,max,start;
for(start= 0;
bv_scan(matrix_row
(symbol_by_symbol_matrix,(guint)from_symid),start,
&min,&max);start= max+2)
{
Marpa_Symbol_ID to_symid;
for(to_symid= min;to_symid<=(Marpa_Symbol_ID)max;
to_symid++)
{

SYM to_symbol= SYM_by_ID(to_symid);
GArray*lhs_rules= to_symbol->t_lhs;
guint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++)
{

Marpa_Rule_ID rule_with_this_lhs_symbol= 
g_array_index(lhs_rules,Marpa_Rule_ID,ix);
guint sort_key= 
sort_key_by_rule_id[rule_with_this_lhs_symbol];
if(sort_key>=no_of_predictable_rules)
continue;

matrix_bit_set(prediction_matrix,(guint)from_symid,
sort_key);

}
}
}
}
}

/*:554*/
#line 4880 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:548*/
#line 4830 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:546*/
#line 4283 "./marpa.w"

/*531:*/
#line 4450 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
Marpa_Rule_ID start_rule_id;
SYMID*postdot_symbol_ids;
AIM start_item;
SYM start_symbol= SYM_by_ID(g->t_start_symid);
AIM*item_list= obstack_alloc(&g->t_obs,sizeof(AIM));

start_rule_id= g_array_index(start_symbol->t_lhs,Marpa_Rule_ID,0);

start_item= g->t_AHFA_items_by_rule[start_rule_id];
item_list[0]= start_item;
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= 1;
p_initial_state->t_key.t_id= 0;
AHFA_is_Predicted(p_initial_state)= 0;
Leo_LHS_ID_of_AHFA(p_initial_state)= -1;
TRANSs_of_AHFA(p_initial_state)= transitions_new(g);
Postdot_SYM_Count_of_AHFA(p_initial_state)= 1;
postdot_symbol_ids= Postdot_SYMID_Ary_of_AHFA(p_initial_state)= 
obstack_alloc(&g->t_obs,sizeof(SYMID));
*postdot_symbol_ids= Postdot_SYMID_of_AIM(start_item);
Complete_SYM_Count_of_AHFA(p_initial_state)= 0;
p_initial_state->t_has_completed_start_rule= 0;
p_initial_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(guint)
Postdot_SYMID_of_AIM
(start_item)),rule_by_sort_key,
&states,duplicates);
}

/*:531*/
#line 4284 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*525:*/
#line 4329 "./marpa.w"
{
guint no_of_items= p_working_state->t_item_count;
guint current_item_ix= 0;
AIM*item_list;
Marpa_Symbol_ID working_symbol;
item_list= p_working_state->t_items;
working_symbol= Postdot_SYMID_of_AIM(item_list[0]);

if(working_symbol<0)goto NEXT_AHFA_STATE;

while(1){
guint first_working_item_ix= current_item_ix;
guint no_of_items_in_new_state;
for(current_item_ix++;
current_item_ix<no_of_items;
current_item_ix++){
if(Postdot_SYMID_of_AIM(item_list[current_item_ix])!=working_symbol)break;
}
no_of_items_in_new_state= current_item_ix-first_working_item_ix;
if(no_of_items_in_new_state==1){
/*533:*/
#line 4514 "./marpa.w"
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

singleton_duplicates[single_item_id]= p_new_state;
new_state_item_list= p_new_state->t_items= 
obstack_alloc(&g->t_obs,sizeof(AIM));
new_state_item_list[0]= single_item_p;
p_new_state->t_item_count= 1;
AHFA_is_Predicted(p_new_state)= 0;
if(AIM_has_Completed_Start_Rule(single_item_p)){
p_new_state->t_has_completed_start_rule= 1;
}else{
p_new_state->t_has_completed_start_rule= 0;
}
Leo_LHS_ID_of_AHFA(p_new_state)= -1;
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
(guint)postdot),
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
/*535:*/
#line 4604 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(predot_symid))
> 0)
{
Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:535*/
#line 4572 "./marpa.w"

}
}

/*:533*/
#line 4349 "./marpa.w"

}else{
/*536:*/
#line 4629 "./marpa.w"
{
AHFA p_new_state;
guint predecessor_ix;
guint no_of_new_items_so_far= 0;
AIM*item_list_for_new_state;
AHFA queued_AHFA_state;
p_new_state= DQUEUE_PUSH(states,AHFA_Object);
item_list_for_new_state= p_new_state->t_items= obstack_alloc(&g->t_obs_tricky,
no_of_items_in_new_state*sizeof(AIM));
p_new_state->t_item_count= no_of_items_in_new_state;
for(predecessor_ix= first_working_item_ix;
predecessor_ix<current_item_ix;predecessor_ix++)
{
gint pre_insertion_point_ix= no_of_new_items_so_far-1;
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
AHFA_is_Predicted(p_new_state)= 0;
p_new_state->t_has_completed_start_rule= 0;
Leo_LHS_ID_of_AHFA(p_new_state)= -1;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
/*537:*/
#line 4680 "./marpa.w"

{
guint symbol_count= SYM_Count_of_G(g);
guint item_ix;
guint no_of_postdot_symbols;
guint no_of_complete_symbols;
Bit_Vector complete_v= bv_create(symbol_count);
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_for_new_state[item_ix];
Marpa_Symbol_ID postdot= Postdot_SYMID_of_AIM(item);
if(postdot<0)
{
gint complete_symbol_id= LHS_ID_of_AIM(item);
completion_count_inc(&ahfa_work_obs,p_new_state,complete_symbol_id);
bv_bit_set(complete_v,(guint)complete_symbol_id);
}
else
{
bv_bit_set(postdot_v,(guint)postdot);
}
}
if((no_of_postdot_symbols= p_new_state->t_postdot_sym_count= 
bv_count(postdot_v)))
{
guint min,max,start;
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
guint min,max,start;
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

/*:537*/
#line 4674 "./marpa.w"

transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
/*541:*/
#line 4763 "./marpa.w"
{
guint item_ix;
Marpa_Symbol_ID postdot= -1;
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++){
postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot>=0)break;
}
p_new_state->t_empty_transition= NULL;
if(postdot>=0)
{
Bit_Vector predicted_rule_vector
= bv_shadow(matrix_row(prediction_matrix,(guint)postdot));
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{

postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot<0)
continue;
bv_or_assign(predicted_rule_vector,
matrix_row(prediction_matrix,(guint)postdot));
}

p_new_state->t_empty_transition= create_predicted_AHFA_state(g,
predicted_rule_vector,
rule_by_sort_key,
&states,
duplicates);
bv_free(predicted_rule_vector);
}
}

/*:541*/
#line 4677 "./marpa.w"

}

/*:536*/
#line 4351 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:525*/
#line 4286 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*526:*/
#line 4361 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
guint symbol_id;
AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
for(symbol_id= 0;symbol_id<symbol_count_of_g;symbol_id++){
TRANS working_transition= transitions[symbol_id];
if(working_transition){
gint completion_count= Completion_Count_of_TRANS(working_transition);
gint sizeof_transition= 
G_STRUCT_OFFSET(struct s_transition,t_aex)+completion_count*
sizeof(transitions[0]->t_aex[0]);
TRANS new_transition= obstack_alloc(&g->t_obs,sizeof_transition);
LV_To_AHFA_of_TRANS(new_transition)= To_AHFA_of_TRANS(working_transition);
LV_Completion_Count_of_TRANS(new_transition)= 0;
transitions[symbol_id]= new_transition;
}
}
}
}

/*:526*/
#line 4291 "./marpa.w"

/*528:*/
#line 4413 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++)
{
AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
AIM*aims= AIMs_of_AHFA(ahfa);
gint aim_count= AIM_Count_of_AHFA(ahfa);
AEX aex;
g_qsort_with_data(aims,aim_count,sizeof(AIM*),cmp_by_aimid,NULL);
for(aex= 0;aex<aim_count;aex++)
{
AIM ahfa_item= aims[aex];
SYMID postdot= Postdot_SYMID_of_AIM(ahfa_item);
if(postdot>=0)
{
TRANS transition= transitions[postdot];
AHFA to_ahfa= To_AHFA_of_TRANS(transition);
if(!AHFA_is_Leo_Completion(to_ahfa))
continue;
Leo_Base_AEX_of_TRANS(transition)= aex;
}
}
}
}

/*:528*/
#line 4292 "./marpa.w"

/*527:*/
#line 4384 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
const AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
if(Complete_SYM_Count_of_AHFA(ahfa)> 0){
AIM*aims= AIMs_of_AHFA(ahfa);
gint aim_count= AIM_Count_of_AHFA(ahfa);
AEX aex;
for(aex= 0;aex<aim_count;aex++){
AIM ahfa_item= aims[aex];
if(AIM_is_Completion(ahfa_item)){
SYMID completed_symbol_id= LHS_ID_of_AIM(ahfa_item);
TRANS transition= transitions[completed_symbol_id];
AEX*aexes= AEXs_of_TRANS(transition);
gint aex_ix= LV_Completion_Count_of_TRANS(transition)++;
MARPA_OFF_DEBUG4("Added completion aex at %d for ahfa_id=%d sym=%d",
aex_ix,ahfa_id,completed_symbol_id);
aexes[aex_ix]= aex;
}
}
}
}
}

/*:527*/
#line 4293 "./marpa.w"

/*529:*/
#line 4440 "./marpa.w"

g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*530:*/
#line 4446 "./marpa.w"

g_free(singleton_duplicates);
g_tree_destroy(duplicates);

/*:530*/
#line 4443 "./marpa.w"

obstack_free(&ahfa_work_obs,NULL);

/*:529*/
#line 4294 "./marpa.w"

}

/*:521*//*540:*/
#line 4752 "./marpa.w"

static inline AHFA
assign_AHFA_state(AHFA sought_state,GTree*duplicates)
{
const AHFA state_found= g_tree_lookup(duplicates,sought_state);
if(state_found)return state_found;
g_tree_insert(duplicates,sought_state,sought_state);
return NULL;
}

/*:540*//*551:*/
#line 4935 "./marpa.w"
static gint
cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data){
RULE a= *(RULE*)ap;
RULE b= *(RULE*)bp;
guint*sort_key_by_rule_id= (guint*)user_data;
Marpa_Rule_ID a_id= a->t_id;
Marpa_Rule_ID b_id= b->t_id;
guint sort_key_a= sort_key_by_rule_id[a_id];
guint sort_key_b= sort_key_by_rule_id[b_id];
if(sort_key_a==sort_key_b)return a_id-b_id;
return sort_key_a-sort_key_b;
}
/*:551*//*556:*/
#line 5014 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
){
AIM*item_list_for_new_state;
AHFA p_new_state;
guint item_list_ix= 0;
guint no_of_items_in_new_state= bv_count(prediction_rule_vector);
if(no_of_items_in_new_state==0)return NULL;
item_list_for_new_state= obstack_alloc(&g->t_obs,
no_of_items_in_new_state*sizeof(AIM));
{
guint start,min,max;
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2)
{
guint rule_sort_key;
for(rule_sort_key= min;rule_sort_key<=max;rule_sort_key++)
{

RULE rule= rule_by_sort_key[rule_sort_key];
item_list_for_new_state[item_list_ix++]= 
g->t_AHFA_items_by_rule[rule->t_id];
}
}
}
p_new_state= DQUEUE_PUSH((*states_p),AHFA_Object);
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
p_new_state->t_has_completed_start_rule= 0;
Leo_LHS_ID_of_AHFA(p_new_state)= -1;
p_new_state->t_empty_transition= NULL;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
Complete_SYM_Count_of_AHFA(p_new_state)= 0;
/*557:*/
#line 5069 "./marpa.w"

{
guint symbol_count= SYM_Count_of_G(g);
guint item_ix;
guint no_of_postdot_symbols;
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_for_new_state[item_ix];
SYMID postdot= Postdot_SYMID_of_AIM(item);
if(postdot>=0)
bv_bit_set(postdot_v,(guint)postdot);
}
if((no_of_postdot_symbols= p_new_state->t_postdot_sym_count= 
bv_count(postdot_v)))
{
guint min,max,start;
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

/*:557*/
#line 5065 "./marpa.w"

return p_new_state;
}

/*:556*//*569:*/
#line 5180 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition){
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:569*//*571:*/
#line 5187 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition){
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:571*//*573:*/
#line 5196 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix){
URTRANS transition;
transition= obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:573*//*575:*/
#line 5208 "./marpa.w"
static inline
TRANS*transitions_new(struct marpa_g*g){
gint symbol_count= SYM_Count_of_G(g);
gint symid= 0;
TRANS*transitions;
transitions= g_malloc(symbol_count*sizeof(transitions[0]));
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:575*//*577:*/
#line 5223 "./marpa.w"

static inline
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

/*:577*//*579:*/
#line 5240 "./marpa.w"

static inline
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

/*:579*//*581:*/
#line 5259 "./marpa.w"

gint marpa_g_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5264 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
gint symbol_count;

/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 5270 "./marpa.w"

/*1352:*/
#line 13289 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1352*/
#line 5271 "./marpa.w"

/*1353:*/
#line 13294 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
MARPA_DEV_ERROR("garray size mismatch");
return failure_indicator;
}
/*:1353*/
#line 5272 "./marpa.w"

from_ahfa_state= AHFA_of_G_by_ID(g,AHFA_state_id);
transitions= TRANSs_of_AHFA(from_ahfa_state);
symbol_count= SYM_Count_of_G(g);
g_array_set_size(result,0);
for(symid= 0;symid<symbol_count;symid++){
AHFA to_ahfa_state= To_AHFA_of_TRANS(transitions[symid]);
if(!to_ahfa_state)continue;
g_array_append_val(result,symid);
g_array_append_val(result,ID_of_AHFA(to_ahfa_state));
}
return result->len;
}

/*:581*//*585:*/
#line 5295 "./marpa.w"

AHFAID marpa_g_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5300 "./marpa.w"

/*1348:*/
#line 13269 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1348*/
#line 5301 "./marpa.w"

/*1352:*/
#line 13289 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1352*/
#line 5302 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:585*//*591:*/
#line 5351 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
gint symbol_count_of_g;
/*1345:*/
#line 13256 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1345*/
#line 5356 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
r= g_slice_new(struct marpa_r);
G_of_R(r)= g;
grammar_ref(g);
symbol_count_of_g= SYM_Count_of_G(g);
/*654:*/
#line 5751 "./marpa.w"
obstack_init(&r->t_obs);
/*:654*/
#line 5365 "./marpa.w"

/*594:*/
#line 5372 "./marpa.w"

r->t_ref_count= 1;

/*:594*//*605:*/
#line 5454 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:605*//*607:*/
#line 5463 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:607*//*612:*/
#line 5489 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:612*//*616:*/
#line 5512 "./marpa.w"
r->t_furthest_earleme= 0;
/*:616*//*620:*/
#line 5529 "./marpa.w"
r->t_sym_workarea= NULL;
/*:620*//*624:*/
#line 5544 "./marpa.w"
r->t_workarea2= NULL;
/*:624*//*628:*/
#line 5568 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:628*//*632:*/
#line 5591 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:632*//*646:*/
#line 5688 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:646*//*650:*/
#line 5727 "./marpa.w"
r->t_is_exhausted= 0;
/*:650*//*674:*/
#line 5848 "./marpa.w"

r->t_earley_set_count= 0;

/*:674*//*680:*/
#line 5897 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:680*//*705:*/
#line 6176 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:705*//*738:*/
#line 6563 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:738*//*777:*/
#line 7037 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:777*//*812:*/
#line 7542 "./marpa.w"

{
gpointer default_value= Default_Value_of_G(g);
gint i;
TOK*tokens_by_symid;
obstack_init(TOK_Obs_of_R(r));
tokens_by_symid= 
obstack_alloc(TOK_Obs_of_R(r),sizeof(TOK)*symbol_count_of_g);
for(i= 0;i<symbol_count_of_g;i++)
{
tokens_by_symid[i]= token_new(r,i,default_value);
}
TOKs_by_SYMID_of_R(r)= tokens_by_symid;
}
/*:812*//*820:*/
#line 7614 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:820*//*843:*/
#line 7908 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:843*//*847:*/
#line 7920 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:847*//*851:*/
#line 7932 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:851*//*918:*/
#line 8771 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:918*//*1313:*/
#line 12976 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1313*/
#line 5366 "./marpa.w"

return r;
}

/*:591*//*596:*/
#line 5378 "./marpa.w"

static inline void
recce_unref(RECCE r)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,r->t_ref_count);
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

/*:596*//*598:*/
#line 5399 "./marpa.w"

static inline
RECCE recce_ref(RECCE r)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,r->t_ref_count);
MARPA_ASSERT(r->t_ref_count> 0)
r->t_ref_count++;
return r;
}
Marpa_Recognizer
marpa_r_ref(Marpa_Recognizer r)
{
return recce_ref(r);
}

/*:598*//*599:*/
#line 5414 "./marpa.w"

static inline
void recce_free(struct marpa_r*r)
{
MARPA_DEBUG4("%s %s: Destroying %p",G_STRFUNC,G_STRLOC,r)
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5419 "./marpa.w"

/*677:*/
#line 5874 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
if(EIMs_of_ES(set))
g_free(EIMs_of_ES(set));
}
}

/*:677*//*813:*/
#line 7556 "./marpa.w"

{
TOK*tokens_by_symid= TOKs_by_SYMID_of_R(r);
if(tokens_by_symid){
obstack_free(TOK_Obs_of_R(r),NULL);
TOKs_by_SYMID_of_R(r)= NULL;
}
}

/*:813*//*821:*/
#line 7616 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:821*//*845:*/
#line 7913 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:845*//*849:*/
#line 7925 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:849*//*852:*/
#line 7933 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:852*//*919:*/
#line 8773 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:919*//*1314:*/
#line 12978 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1314*/
#line 5420 "./marpa.w"

grammar_unref(g);
if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*630:*/
#line 5577 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:630*//*634:*/
#line 5594 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:634*/
#line 5424 "./marpa.w"

/*655:*/
#line 5752 "./marpa.w"
obstack_free(&r->t_obs,NULL);

/*:655*/
#line 5425 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:599*//*608:*/
#line 5471 "./marpa.w"

guint marpa_r_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:608*//*610:*/
#line 5478 "./marpa.w"

static inline ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:610*//*613:*/
#line 5491 "./marpa.w"

gint marpa_r_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:613*//*614:*/
#line 5497 "./marpa.w"

gint marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,gint threshold)
{
r->t_earley_item_warning_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:614*//*617:*/
#line 5513 "./marpa.w"

guint marpa_r_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:617*//*635:*/
#line 5604 "./marpa.w"

gint marpa_r_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5607 "./marpa.w"

/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5608 "./marpa.w"

guint min,max,start;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 5610 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 5611 "./marpa.w"

/*1361:*/
#line 13338 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
R_DEV_ERROR("garray size mismatch");
return failure_indicator;
}

/*:1361*/
#line 5612 "./marpa.w"

g_array_set_size(result,0);
for(start= 0;bv_scan(r->t_bv_symid_is_expected,start,&min,&max);
start= max+2)
{
gint symid;
for(symid= (gint)min;symid<=(gint)max;symid++)
{
g_array_append_val(result,symid);
}
}
return(gint)result->len;
}

/*:635*//*647:*/
#line 5694 "./marpa.w"

gint marpa_r_is_use_leo(struct marpa_r*r)
{
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5697 "./marpa.w"

/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5698 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 5699 "./marpa.w"

return r->t_use_leo_flag?1:0;
}
/*:647*//*648:*/
#line 5704 "./marpa.w"

gboolean marpa_r_is_use_leo_set(
struct marpa_r*r,gboolean value)
{
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5708 "./marpa.w"

/*1344:*/
#line 13254 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1344*/
#line 5709 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 5710 "./marpa.w"

/*1355:*/
#line 13307 "./marpa.w"

if(Input_Phase_of_R(r)!=R_BEFORE_INPUT){
R_DEV_ERROR("recce started");
return failure_indicator;
}
/*:1355*/
#line 5711 "./marpa.w"

r->t_use_leo_flag= value;
return TRUE;
}

/*:648*//*652:*/
#line 5737 "./marpa.w"

gint marpa_r_is_exhausted(struct marpa_r*r)
{
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5740 "./marpa.w"

/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5741 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 5742 "./marpa.w"

return R_is_Exhausted(r);
}

/*:652*//*657:*/
#line 5756 "./marpa.w"

Marpa_Error_Code marpa_r_error(const struct marpa_r*r,const char**p_error_string)
{
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5759 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:657*//*659:*/
#line 5765 "./marpa.w"

gint marpa_r_event(const struct marpa_r*r,struct marpa_g_event*public_event,gint ix)
{
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5768 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:659*//*676:*/
#line 5854 "./marpa.w"

static inline ES
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
/*1320:*/
#line 13028 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1320*/
#line 5869 "./marpa.w"

return set;
}

/*:676*//*681:*/
#line 5900 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5903 "./marpa.w"

/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5904 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 5906 "./marpa.w"

if(!trace_earley_set){
R_DEV_ERROR("no trace es");
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:681*//*682:*/
#line 5914 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5917 "./marpa.w"

/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5918 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 5919 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:682*//*684:*/
#line 5933 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const gint es_does_not_exist= -1;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5937 "./marpa.w"

/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5938 "./marpa.w"

ES earley_set;
/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 5940 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 5941 "./marpa.w"

if(set_id<0){
R_DEV_ERROR("invalid es ordinal");
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

/*:684*//*686:*/
#line 5957 "./marpa.w"

gint marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 5960 "./marpa.w"

ES earley_set;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 5962 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 5963 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 5964 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
R_DEV_ERROR("invalid es ordinal");
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:686*//*696:*/
#line 6063 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1345:*/
#line 13256 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1345*/
#line 6067 "./marpa.w"

/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6068 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const gint count= ++EIM_Count_of_ES(set);
/*699:*/
#line 6118 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(G_UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
R_FATAL(MARPA_ERR_EIM_COUNT,"eim count exceeds fatal threshold");
return failure_indicator;
}
int_event_new(g,MARPA_G_EV_EARLEY_ITEM_THRESHOLD,count);
}

/*:699*/
#line 6073 "./marpa.w"

new_item= obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:696*//*698:*/
#line 6086 "./marpa.w"

static inline EIM
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

/*:698*//*703:*/
#line 6152 "./marpa.w"

static const char*invalid_source_type_message(guint type){
switch(type){
case NO_SOURCE:
return"invalid source type: none";
case SOURCE_IS_TOKEN:
return"invalid source type: token";
case SOURCE_IS_COMPLETION:
return"invalid source type: completion";
case SOURCE_IS_LEO:
return"invalid source type: leo";
case SOURCE_IS_AMBIGUOUS:
return"invalid source type: ambiguous";
}
return"unknown source type";
}

/*:703*//*710:*/
#line 6216 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const gint es_does_not_exist= -1;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6222 "./marpa.w"

/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6223 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6224 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*711:*/
#line 6247 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*740:*/
#line 6602 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:740*/
#line 6250 "./marpa.w"

}

/*:711*/
#line 6231 "./marpa.w"

if(set_id<0)
{
R_DEV_ERROR("invalid es ordinal");
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

/*:710*//*712:*/
#line 6253 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const gint eim_does_not_exist= -1;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6258 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6262 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6263 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*711:*/
#line 6247 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*740:*/
#line 6602 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:740*/
#line 6250 "./marpa.w"

}

/*:711*/
#line 6267 "./marpa.w"

R_DEV_ERROR("no trace es");
return failure_indicator;
}
trace_earley_item_clear(r);
if(item_id<0)
{
R_DEV_ERROR("invalid eim ordinal");
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

/*:712*//*715:*/
#line 6298 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r)
{
/*713:*/
#line 6293 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:713*/
#line 6301 "./marpa.w"

trace_source_link_clear(r);
}

/*:715*//*716:*/
#line 6305 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6308 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 6310 "./marpa.w"

if(!item){
/*713:*/
#line 6293 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:713*/
#line 6312 "./marpa.w"

R_DEV_ERROR("no trace eim");
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:716*//*723:*/
#line 6385 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6389 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6392 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6393 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item)){
R_DEV_ERROR("pim is not lim");
return failure_indicator;
}
predecessor_leo_item= Predecessor_LIM_of_LIM(LIM_of_PIM(postdot_item));
if(!predecessor_leo_item)return no_predecessor;
return Postdot_SYMID_of_LIM(predecessor_leo_item);
}

/*:723*//*724:*/
#line 6407 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6411 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6413 "./marpa.w"

EIM base_earley_item;
/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6415 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:724*//*725:*/
#line 6425 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6429 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6432 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6433 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:725*//*729:*/
#line 6467 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6471 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6473 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6474 "./marpa.w"

if(!postdot_item)
{
R_DEV_ERROR("no trace pim");
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


/*:729*//*734:*/
#line 6525 "./marpa.w"

static inline PIM*
pim_sym_p_find(ES set,SYMID symid)
{
gint lo= 0;
gint hi= Postdot_SYM_Count_of_ES(set)-1;
PIM*postdot_array= set->t_postdot_ary;
while(hi>=lo){
gint trial= lo+(hi-lo)/2;
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
/*:734*//*736:*/
#line 6547 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:736*//*739:*/
#line 6577 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6582 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6586 "./marpa.w"

/*740:*/
#line 6602 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:740*/
#line 6587 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6588 "./marpa.w"

/*1360:*/
#line 13333 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
R_DEV_ERROR("invalid symid");
return failure_indicator;
}
/*:1360*/
#line 6589 "./marpa.w"

if(!current_es){
R_DEV_ERROR("no pim");
return failure_indicator;
}
pim_sym_p= PIM_SYM_P_of_ES_by_SYMID(current_es,symid);
pim= *pim_sym_p;
if(!pim)return-1;
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return symid;
}

/*:739*//*741:*/
#line 6612 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6616 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6619 "./marpa.w"

PIM*pim_sym_p;
/*740:*/
#line 6602 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:740*/
#line 6621 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6622 "./marpa.w"

if(!current_earley_set){
/*713:*/
#line 6293 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:713*/
#line 6624 "./marpa.w"

R_DEV_ERROR("no trace es");
return failure_indicator;
}
if(current_earley_set->t_postdot_sym_count<=0)return-1;
pim_sym_p= current_earley_set->t_postdot_ary+0;
pim= pim_sym_p[0];
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return Postdot_SYMID_of_PIM(pim);
}

/*:741*//*742:*/
#line 6643 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6648 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6652 "./marpa.w"


pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*740:*/
#line 6602 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:740*/
#line 6656 "./marpa.w"

if(!pim_sym_p||!pim){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6661 "./marpa.w"

if(!current_set){
R_DEV_ERROR("no trace es");
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

/*:742*//*743:*/
#line 6681 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_postdot_item_symbol(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 6684 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 6686 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 6687 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:743*//*760:*/
#line 6820 "./marpa.w"
static inline
void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
TOK token)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
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

/*:760*//*766:*/
#line 6901 "./marpa.w"
static inline
void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
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

/*:766*//*767:*/
#line 6928 "./marpa.w"
static inline
void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
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
/*:767*//*770:*/
#line 6980 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
guint previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*772:*/
#line 6998 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= new_link;
}

/*:772*/
#line 6987 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*773:*/
#line 7007 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= new_link;
First_Token_Link_of_EIM(item)= NULL;
}

/*:773*/
#line 6989 "./marpa.w"

return;
case SOURCE_IS_LEO:/*774:*/
#line 7016 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= new_link;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= NULL;
}

/*:774*/
#line 6991 "./marpa.w"

return;
}
}
/*:770*//*779:*/
#line 7048 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7051 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7055 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7056 "./marpa.w"

/*793:*/
#line 7275 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:793*/
#line 7057 "./marpa.w"

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

/*:779*//*782:*/
#line 7092 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7095 "./marpa.w"

SRCL full_link;
EIM item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7098 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7099 "./marpa.w"

/*793:*/
#line 7275 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:793*/
#line 7100 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_TOKEN){
trace_source_link_clear(r);
R_DEV_ERROR("not tracing token links");
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

/*:782*//*784:*/
#line 7123 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7126 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7130 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7131 "./marpa.w"

/*793:*/
#line 7275 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:793*/
#line 7132 "./marpa.w"

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

/*:784*//*787:*/
#line 7166 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7169 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7173 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7174 "./marpa.w"

/*793:*/
#line 7275 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:793*/
#line 7175 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_COMPLETION){
trace_source_link_clear(r);
R_DEV_ERROR("not tracing completion links");
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

/*:787*//*789:*/
#line 7199 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_leo_link_trace(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7203 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7207 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7208 "./marpa.w"

/*793:*/
#line 7275 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:793*/
#line 7209 "./marpa.w"

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

/*:789*//*792:*/
#line 7245 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_leo_link_trace(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7249 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7253 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7254 "./marpa.w"

/*793:*/
#line 7275 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:793*/
#line 7255 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_LEO)
{
trace_source_link_clear(r);
R_DEV_ERROR("not tracing leo links");
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

/*:792*//*796:*/
#line 7286 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r){
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:796*//*797:*/
#line 7301 "./marpa.w"

AHFAID marpa_r_source_predecessor_state(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7304 "./marpa.w"

guint source_type;
SRC source;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7307 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7308 "./marpa.w"

source_type= r->t_trace_source_type;
/*804:*/
#line 7452 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:804*/
#line 7310 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:{
EIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return-1;
return AHFAID_of_EIM(predecessor);
}
}
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:797*//*798:*/
#line 7342 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,gpointer*value_p)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7345 "./marpa.w"

guint source_type;
SRC source;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7348 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7349 "./marpa.w"

source_type= r->t_trace_source_type;
/*804:*/
#line 7452 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:804*/
#line 7351 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:798*//*800:*/
#line 7374 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7377 "./marpa.w"

guint source_type;
SRC source;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7380 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7381 "./marpa.w"

source_type= r->t_trace_source_type;
/*804:*/
#line 7452 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:804*/
#line 7383 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:800*//*803:*/
#line 7420 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7423 "./marpa.w"

const EARLEME no_predecessor= -1;
guint source_type;
SRC source;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7427 "./marpa.w"

/*1358:*/
#line 13323 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 13324 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 13325 "./marpa.w"


/*:1358*/
#line 7428 "./marpa.w"

source_type= r->t_trace_source_type;
/*804:*/
#line 7452 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:804*/
#line 7430 "./marpa.w"

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
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:803*//*815:*/
#line 7568 "./marpa.w"

static inline
TOK token_new(struct marpa_r*r,SYMID symbol_id,gpointer value)
{
TOK token;
token= obstack_alloc(TOK_Obs_of_R(r),sizeof(*token));
Type_of_TOK(token)= TOKEN_OR_NODE;
SYMID_of_TOK(token)= symbol_id;
Value_of_TOK(token)= value;
return token;
}

/*:815*//*823:*/
#line 7624 "./marpa.w"

static inline gint
alternative_insertion_point(RECCE r,ALT new_alternative)
{
DSTACK alternatives= &r->t_alternatives;
ALT alternative;
gint hi= DSTACK_LENGTH(*alternatives)-1;
gint lo= 0;
gint trial;

if(hi<0)
return 0;
alternative= DSTACK_BASE(*alternatives,ALT_Object);
for(;;)
{
gint outcome;
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

/*:823*//*825:*/
#line 7670 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b){
gint subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:825*//*827:*/
#line 7688 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:827*//*829:*/
#line 7705 "./marpa.w"

static inline gint alternative_insert(RECCE r,ALT new_alternative)
{
ALT top_of_stack,base_of_stack;
DSTACK alternatives= &r->t_alternatives;
gint ix;
gint insertion_point= alternative_insertion_point(r,new_alternative);
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

/*:829*//*830:*/
#line 7724 "./marpa.w"
gboolean marpa_r_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7730 "./marpa.w"

const gint symbol_count_of_g= SYM_Count_of_G(g);
/*1344:*/
#line 13254 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1344*/
#line 7732 "./marpa.w"

/*1355:*/
#line 13307 "./marpa.w"

if(Input_Phase_of_R(r)!=R_BEFORE_INPUT){
R_DEV_ERROR("recce started");
return failure_indicator;
}
/*:1355*/
#line 7733 "./marpa.w"

Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g)){
/*651:*/
#line 5728 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:651*/
#line 7736 "./marpa.w"

return TRUE;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
/*625:*/
#line 5545 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*621:*/
#line 5530 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:621*/
#line 5548 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:625*/
#line 7740 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*629:*/
#line 5572 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:629*//*633:*/
#line 5592 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:633*/
#line 7742 "./marpa.w"

/*844:*/
#line 7909 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT(r->t_eim_work_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:844*//*848:*/
#line 7921 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT(r->t_completion_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:848*/
#line 7743 "./marpa.w"

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
return TRUE;
}

/*:830*//*837:*/
#line 7811 "./marpa.w"

gboolean marpa_r_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length){
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7814 "./marpa.w"

/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7815 "./marpa.w"

const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1357:*/
#line 13317 "./marpa.w"

if(Input_Phase_of_R(r)!=R_DURING_INPUT){
R_DEV_ERROR("recce not accepting input");
return failure_indicator;
}

/*:1357*/
#line 7821 "./marpa.w"

/*838:*/
#line 7829 "./marpa.w"
{
const SYM_Const token= SYM_by_ID(token_id);
if(!SYM_is_Terminal(token)){
R_DEV_ERROR("token is not a terminal");
return failure_indicator;
}
if(length<=0){
R_DEV_ERROR("token length negative or zero");
return failure_indicator;
}
if(length>=EARLEME_THRESHOLD){
R_DEV_ERROR("token too long");
return failure_indicator;
}
}

/*:838*/
#line 7822 "./marpa.w"

/*840:*/
#line 7860 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:840*/
#line 7823 "./marpa.w"

/*839:*/
#line 7845 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
R_DEV_ERROR("parse too long");
return failure_indicator;
}
}

/*:839*/
#line 7824 "./marpa.w"

/*841:*/
#line 7883 "./marpa.w"

{
TOK token= token_new(r,token_id,value);
ALT_Object alternative;
if(Furthest_Earleme_of_R(r)<target_earleme)
Furthest_Earleme_of_R(r)= target_earleme;
alternative.t_token= token;
alternative.t_start_earley_set= current_earley_set;
alternative.t_end_earleme= target_earleme;
if(alternative_insert(r,&alternative)<0)
{
/*816:*/
#line 7583 "./marpa.w"
obstack_free(TOK_Obs_of_R(r),token);

/*:816*/
#line 7894 "./marpa.w"

return duplicate_token_indicator;
}
}

/*:841*/
#line 7825 "./marpa.w"

return current_earleme;
}

/*:837*//*854:*/
#line 7952 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(struct marpa_r*r)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 7956 "./marpa.w"

/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 7957 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
gint count_of_expected_terminals;
/*1357:*/
#line 13317 "./marpa.w"

if(Input_Phase_of_R(r)!=R_DURING_INPUT){
R_DEV_ERROR("recce not accepting input");
return failure_indicator;
}

/*:1357*/
#line 7962 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*855:*/
#line 7990 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*651:*/
#line 5728 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:651*/
#line 7994 "./marpa.w"

R_DEV_ERROR("parse exhausted");
return failure_indicator;
}
}

/*:855*/
#line 7966 "./marpa.w"

/*857:*/
#line 8015 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:857*/
#line 7967 "./marpa.w"

/*856:*/
#line 8002 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:856*/
#line 7968 "./marpa.w"

/*858:*/
#line 8021 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*859:*/
#line 8028 "./marpa.w"

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

/*:859*/
#line 8025 "./marpa.w"

}

/*:858*/
#line 7969 "./marpa.w"

/*860:*/
#line 8055 "./marpa.w"
{
EIM*work_earley_items= DSTACK_BASE(r->t_eim_work_stack,EIM);
gint no_of_work_earley_items= DSTACK_LENGTH(r->t_eim_work_stack);
gint ix;
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
#line 7970 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*861:*/
#line 8074 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*862:*/
#line 8087 "./marpa.w"

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
/*863:*/
#line 8110 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*864:*/
#line 8126 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:864*/
#line 8119 "./marpa.w"

}
/*865:*/
#line 8133 "./marpa.w"
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
#line 8121 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:863*/
#line 8098 "./marpa.w"

}
else
{
/*866:*/
#line 8143 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*864:*/
#line 8126 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:864*/
#line 8152 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:866*/
#line 8102 "./marpa.w"

break;


}
}
}

/*:862*/
#line 8083 "./marpa.w"

}
}

/*:861*/
#line 7973 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


/*651:*/
#line 5728 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:651*/
#line 7983 "./marpa.w"

event_new(g,MARPA_G_EV_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:854*//*868:*/
#line 8159 "./marpa.w"

static inline void earley_set_update_items(RECCE r,ES set){
EIM*working_earley_items;
EIM*finished_earley_items;
gint working_earley_item_count;
gint i;
if(!EIMs_of_ES(set)){
EIMs_of_ES(set)= g_new(EIM,EIM_Count_of_ES(set));
}else{
EIMs_of_ES(set)= g_renew(EIM,EIMs_of_ES(set),EIM_Count_of_ES(set));
}
finished_earley_items= EIMs_of_ES(set);
working_earley_items= Work_EIMs_of_R(r);
working_earley_item_count= Work_EIM_Count_of_R(r);
for(i= 0;i<working_earley_item_count;i++){
EIM earley_item= working_earley_items[i];
gint ordinal= Ord_of_EIM(earley_item);
finished_earley_items[ordinal]= earley_item;
}
WORK_EIMS_CLEAR(r);
}

/*:868*//*870:*/
#line 8185 "./marpa.w"

static inline void r_update_earley_sets(RECCE r){
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

/*:870*//*874:*/
#line 8223 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES current_earley_set)
{
gpointer*const pim_workarea= r->t_sym_workarea;
/*601:*/
#line 5436 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:601*/
#line 8228 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*875:*/
#line 8245 "./marpa.w"
{
EIM*work_earley_items= DSTACK_BASE(r->t_eim_work_stack,EIM);
gint no_of_work_earley_items= DSTACK_LENGTH(r->t_eim_work_stack);
gint ix;
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
EIM earley_item= work_earley_items[ix];
AHFA state= AHFA_of_EIM(earley_item);
gint symbol_ix;
gint postdot_symbol_count= Postdot_SYM_Count_of_AHFA(state);
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
if(bv_bit_test(bv_pim_symbols,(guint)symid))
old_pim= pim_workarea[symid];
if(old_pim){
Next_PIM_of_PIM(new_pim)= old_pim;
}else{
Next_PIM_of_PIM(new_pim)= NULL;
current_earley_set->t_postdot_sym_count++;
}
pim_workarea[symid]= new_pim;
bv_bit_set(bv_pim_symbols,(guint)symid);
}
}
}

/*:875*/
#line 8234 "./marpa.w"

if(r->t_is_using_leo){
/*877:*/
#line 8291 "./marpa.w"

{
guint min,max,start;
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
AHFA base_to_ahfa= To_AHFA_of_EIM_by_SYMID(leo_base,symid);
if(AHFA_is_Leo_Completion(base_to_ahfa))
{
/*878:*/
#line 8321 "./marpa.w"
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
bv_bit_set(bv_lim_symbols,(guint)symid);
}

/*:878*/
#line 8308 "./marpa.w"

}
}
}
}
}

/*:877*/
#line 8236 "./marpa.w"

/*887:*/
#line 8406 "./marpa.w"
{
const Bit_Vector bv_ok_for_chain= r->t_bv_sym3;
guint min,max,start;

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

/*890:*/
#line 8465 "./marpa.w"
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

/*:890*/
#line 8424 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*896:*/
#line 8557 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:896*/
#line 8426 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*898:*/
#line 8578 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:898*/
#line 8432 "./marpa.w"

continue;
}
/*891:*/
#line 8480 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*894:*/
#line 8501 "./marpa.w"
{
SYMID postdot_symid_of_lim_to_process
= Postdot_SYMID_of_LIM(lim_to_process);
lim_chain_ix= 0;
lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);
bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);


while(1){
lim_to_process= predecessor_lim;






postdot_symid_of_lim_to_process= Postdot_SYMID_of_LIM(lim_to_process);
if(!bv_bit_test(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process)){





break;
}

/*890:*/
#line 8465 "./marpa.w"
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

/*:890*/
#line 8527 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:894*/
#line 8483 "./marpa.w"

/*895:*/
#line 8546 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*896:*/
#line 8557 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:896*/
#line 8550 "./marpa.w"

}else{
/*898:*/
#line 8578 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:898*/
#line 8552 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:895*/
#line 8484 "./marpa.w"

}

/*:891*/
#line 8435 "./marpa.w"

}
}
}

/*:887*/
#line 8237 "./marpa.w"

}
/*899:*/
#line 8584 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= obstack_alloc(&r->t_obs,
current_earley_set->t_postdot_sym_count*sizeof(PIM));
guint min,max,start;
gint postdot_array_ix= 0;
for(start= 0;bv_scan(bv_pim_symbols,start,&min,&max);start= max+2){
SYMID symid;
for(symid= (SYMID)min;symid<=(SYMID)max;symid++){
PIM this_pim= pim_workarea[symid];
if(this_pim)postdot_array[postdot_array_ix++]= this_pim;
}
}
}

/*:899*/
#line 8239 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:874*//*921:*/
#line 8778 "./marpa.w"

static inline void ur_node_stack_init(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_init %s",G_STRLOC);
obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:921*//*923:*/
#line 8788 "./marpa.w"

static inline void ur_node_stack_reset(URS stack){
stack->t_top= stack->t_base;
}

/*:923*//*925:*/
#line 8795 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
if(stack->t_base)obstack_free(&stack->t_obs,NULL);
stack->t_base= NULL;
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
}

/*:925*//*927:*/
#line 8805 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev){
UR new_ur_node;
new_ur_node= obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:927*//*929:*/
#line 8816 "./marpa.w"

static inline void
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

/*:929*//*931:*/
#line 8834 "./marpa.w"

static inline UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:931*//*936:*/
#line 8903 "./marpa.w"

static inline gint psia_test_and_set(
struct obstack*obs,
struct s_bocage_setup_per_es*per_es_data,
EIM earley_item,
AEX ahfa_element_ix)
{
const gint aim_count_of_item= AIM_Count_of_EIM(earley_item);
const Marpa_Earley_Set_ID set_ordinal= ES_Ord_of_EIM(earley_item);
OR**nodes_by_item= per_es_data[set_ordinal].t_aexes_by_item;
const gint item_ordinal= Ord_of_EIM(earley_item);
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

/*:936*//*973:*/
#line 9524 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:973*//*975:*/
#line 9538 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:975*//*982:*/
#line 9660 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause);
return draft_and_node;
}

/*:982*//*985:*/
#line 9686 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:985*//*1013:*/
#line 10132 "./marpa.w"

gint marpa_b_and_node_count(Marpa_Bocage b)
{
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10135 "./marpa.w"

/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10136 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10137 "./marpa.w"

return AND_Count_of_B(b);
}

/*:1013*//*1016:*/
#line 10160 "./marpa.w"

gint marpa_b_and_node_parent(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10164 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10165 "./marpa.w"

/*1014:*/
#line 10141 "./marpa.w"
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

/*:1014*/
#line 10166 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1016*//*1018:*/
#line 10172 "./marpa.w"

gint marpa_b_and_node_predecessor(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10176 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10177 "./marpa.w"

/*1014:*/
#line 10141 "./marpa.w"
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

/*:1014*/
#line 10178 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1018*//*1020:*/
#line 10189 "./marpa.w"

gint marpa_b_and_node_cause(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10193 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10194 "./marpa.w"

/*1014:*/
#line 10141 "./marpa.w"
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

/*:1014*/
#line 10195 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1020*//*1022:*/
#line 10206 "./marpa.w"

gint marpa_b_and_node_symbol(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10210 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10211 "./marpa.w"

/*1014:*/
#line 10141 "./marpa.w"
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

/*:1014*/
#line 10212 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1022*//*1024:*/
#line 10240 "./marpa.w"

Marpa_Symbol_ID marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,gpointer*value_p)
{
AND and_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10245 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10246 "./marpa.w"

/*1014:*/
#line 10141 "./marpa.w"
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

/*:1014*/
#line 10247 "./marpa.w"

return and_node_token(and_node,value_p);
}
/*:1024*//*1026:*/
#line 10252 "./marpa.w"

static inline SYMID and_node_token(AND and_node,gpointer*value_p)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
const TOK token= TOK_of_OR(cause_or);
if(value_p)
*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
return-1;
}

/*:1026*//*1042:*/
#line 10323 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Rule_ID rule_id,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1345:*/
#line 13256 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1345*/
#line 10328 "./marpa.w"

/*1043:*/
#line 10369 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const gint rule_count_of_g= RULE_Count_of_G(g);
const gint symbol_count_of_g= SYM_Count_of_G(g);
BOCAGE b= NULL;
ES end_of_parse_earley_set;
EARLEME end_of_parse_earleme;
RULE completed_start_rule;
EIM start_eim= NULL;
AIM start_aim= NULL;
AEX start_aex= -1;
struct obstack bocage_setup_obs;
gint total_earley_items_in_parse;
gint or_node_estimate= 0;
const gint earley_set_count_of_r= ES_Count_of_R(r);

/*:1043*//*1046:*/
#line 10393 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:1046*/
#line 10329 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10330 "./marpa.w"

/*1356:*/
#line 13312 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1356*/
#line 10331 "./marpa.w"

b= g_slice_new(struct s_bocage);
/*959:*/
#line 9263 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;

/*:959*//*1038:*/
#line 10302 "./marpa.w"

b->is_obstack_initialized= 1;
obstack_init(&OBS_of_B(b));
/*:1038*//*1063:*/
#line 10602 "./marpa.w"

b->t_ref_count= 1;

/*:1063*/
#line 10333 "./marpa.w"

I_of_B(b)= I_of_R(r);


R_of_B(b)= r;
recce_ref(r);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
r_update_earley_sets(r);
/*1047:*/
#line 10396 "./marpa.w"

{
if(ordinal_arg==-1)
{
end_of_parse_earley_set= Current_ES_of_R(r);
}
else
{
if(!ES_Ord_is_Valid(r,ordinal_arg))
{
R_DEV_ERROR("invalid es ordinal");
return failure_indicator;
}
end_of_parse_earley_set= ES_of_R_by_Ord(r,ordinal_arg);
}

if(!end_of_parse_earley_set)
goto B_NEW_RETURN_ERROR;
end_of_parse_earleme= Earleme_of_ES(end_of_parse_earley_set);
}

/*:1047*/
#line 10345 "./marpa.w"

if(end_of_parse_earleme==0){
if(!g->t_null_start_rule)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
/*1048:*/
#line 10417 "./marpa.w"

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
R_DEV_ERROR("invalid rule id");
return failure_indicator;
}
completed_start_rule= RULE_by_ID(g,rule_id);
}
MARPA_OFF_DEBUG2("ordinal=%d",ordinal);
}

/*:1048*/
#line 10350 "./marpa.w"

/*1054:*/
#line 10529 "./marpa.w"

{
gint eim_ix;
EIM*const earley_items= EIMs_of_ES(end_of_parse_earley_set);
const RULEID sought_rule_id= ID_of_RULE(completed_start_rule);
const gint earley_item_count= EIM_Count_of_ES(end_of_parse_earley_set);
for(eim_ix= 0;eim_ix<earley_item_count;eim_ix++){
const EIM earley_item= earley_items[eim_ix];
const AHFA ahfa_state= AHFA_of_EIM(earley_item);
if(Origin_Earleme_of_EIM(earley_item)> 0)continue;
if(!AHFA_is_Predicted(ahfa_state)){
gint aex;
AIM*const ahfa_items= AIMs_of_AHFA(ahfa_state);
const gint ahfa_item_count= AIM_Count_of_AHFA(ahfa_state);
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

/*:1054*/
#line 10351 "./marpa.w"

if(!start_eim)goto B_NEW_RETURN_ERROR;
obstack_init(&bocage_setup_obs);
/*1051:*/
#line 10477 "./marpa.w"

{
guint ix;
guint earley_set_count= ES_Count_of_R(r);
total_earley_items_in_parse= 0;
per_es_data= 
obstack_alloc(&bocage_setup_obs,
sizeof(struct s_bocage_setup_per_es)*earley_set_count);
for(ix= 0;ix<earley_set_count;ix++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,ix);
const guint item_count= EIM_Count_of_ES(earley_set);
total_earley_items_in_parse+= item_count;
{
struct s_bocage_setup_per_es*per_es= per_es_data+ix;
OR**const per_eim_eixes= per_es->t_aexes_by_item= 
obstack_alloc(&bocage_setup_obs,sizeof(OR*)*item_count);
guint item_ordinal;
per_es->t_or_psl= NULL;
per_es->t_and_psl= NULL;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
per_eim_eixes[item_ordinal]= NULL;
}
}
}
}

/*:1051*/
#line 10354 "./marpa.w"

/*933:*/
#line 8856 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*934:*/
#line 8884 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:934*/
#line 8865 "./marpa.w"

}
while((ur_node= ur_node_pop(ur_node_stack)))
{
const EIM_Const parent_earley_item= EIM_of_UR(ur_node);
const AEX parent_aex= AEX_of_UR(ur_node);
const AIM parent_aim= AIM_of_EIM_by_AEX(parent_earley_item,parent_aex);
MARPA_ASSERT(parent_aim>=AIM_by_ID(1))
const AIM predecessor_aim= parent_aim-1;


guint source_type= Source_Type_of_EIM(parent_earley_item);
MARPA_ASSERT(!EIM_is_Predicted(parent_earley_item))
/*937:*/
#line 8931 "./marpa.w"

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
/*934:*/
#line 8884 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:934*/
#line 8959 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:937*/
#line 8878 "./marpa.w"

/*939:*/
#line 9000 "./marpa.w"

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
/*934:*/
#line 8884 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:934*/
#line 9036 "./marpa.w"

}
}
{
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
const EIM ur_earley_item= cause_earley_item;
gint ix;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*934:*/
#line 8884 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:934*/
#line 9049 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:939*/
#line 8879 "./marpa.w"

/*940:*/
#line 9059 "./marpa.w"

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
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
gint ix;
EIM ur_earley_item= cause_earley_item;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*934:*/
#line 8884 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:934*/
#line 9092 "./marpa.w"

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
/*934:*/
#line 8884 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:934*/
#line 9108 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:940*/
#line 8880 "./marpa.w"

}
}

/*:933*/
#line 10355 "./marpa.w"

/*961:*/
#line 9286 "./marpa.w"

{
PSAR_Object or_per_es_arena;
const PSAR or_psar= &or_per_es_arena;
gint work_earley_set_ordinal;
OR last_or_node= NULL;
ORs_of_B(b)= g_new(OR,or_node_estimate);
psar_init(or_psar,SYMI_Count_of_G(g));
for(work_earley_set_ordinal= 0;
work_earley_set_ordinal<earley_set_count_of_r;
work_earley_set_ordinal++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,work_earley_set_ordinal);
EIM*const eims_of_es= EIMs_of_ES(earley_set);
const gint item_count= EIM_Count_of_ES(earley_set);
PSL this_earley_set_psl;
OR**const nodes_by_item= per_es_data[work_earley_set_ordinal].t_aexes_by_item;
psar_dealloc(or_psar);
#define PSL_ES_ORD work_earley_set_ordinal
#define CLAIMED_PSL this_earley_set_psl
/*1327:*/
#line 13089 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1327*/
#line 9306 "./marpa.w"

/*962:*/
#line 9314 "./marpa.w"

{
gint item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const work_nodes_by_aex= nodes_by_item[item_ordinal];
if(work_nodes_by_aex){
const EIM work_earley_item= eims_of_es[item_ordinal];
const gint work_ahfa_item_count= AIM_Count_of_EIM(work_earley_item);
AEX work_aex;
const gint work_origin_ordinal= Ord_of_ES(Origin_of_EIM(work_earley_item));
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
if(!work_nodes_by_aex[work_aex])continue;
/*963:*/
#line 9334 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
MARPA_OFF_DEBUG4("%s: adding or-nodes for eim %s, aex=%d",
G_STRLOC,eim_tag(work_earley_item),work_aex);
MARPA_OFF_DEBUG3("%s: adding or-nodes for aim=%s",G_STRLOC,aim_tag(ahfa_item));
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1327:*/
#line 13089 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1327*/
#line 9347 "./marpa.w"

/*965:*/
#line 9365 "./marpa.w"

{
MARPA_OFF_DEBUG3("%s ahfa_item_symbol_instance = %d",G_STRLOC,ahfa_item_symbol_instance);
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const RULE rule= RULE_of_AIM(ahfa_item);
/*966:*/
#line 9395 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:966*/
#line 9376 "./marpa.w"

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

/*:965*/
#line 9348 "./marpa.w"

/*968:*/
#line 9420 "./marpa.w"

{
const gint null_count= Null_Count_of_AIM(ahfa_item);
if(null_count> 0)
{
const RULE rule= RULE_of_AIM(ahfa_item);
const gint symbol_instance_of_rule= SYMI_of_RULE(rule);
const gint first_null_symbol_instance= 
ahfa_item_symbol_instance<0?symbol_instance_of_rule:ahfa_item_symbol_instance+1;
gint i;
MARPA_OFF_DEBUG3("about to add nulling token ORs rule=%d null_count=%d",
ID_of_RULE(rule),null_count);
for(i= 0;i<null_count;i++)
{
const gint symbol_instance= first_null_symbol_instance+i;
OR or_node= PSL_Datum(or_psl,symbol_instance);
MARPA_OFF_DEBUG3("adding nulling token or-node rule=%d i=%d",
ID_of_RULE(rule),
(symbol_instance-SYMI_of_RULE(rule)));
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal){
DAND draft_and_node;
const gint rhs_ix= symbol_instance-SYMI_of_RULE(rule);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_ID_of_R(r,RHS_ID_of_RULE(rule,rhs_ix));
/*966:*/
#line 9395 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:966*/
#line 9444 "./marpa.w"

or_node= PSL_Datum(or_psl,symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= work_origin_ordinal;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= rule;
MARPA_OFF_DEBUG3("Added rule %p to or-node %p",RULE_of_OR(or_node),or_node);
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
draft_and_node= DANDs_of_OR(or_node)= 
draft_and_node_new(&bocage_setup_obs,predecessor,
cause);
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,DANDs_of_OR(or_node));
Next_DAND_of_DAND(draft_and_node)= NULL;
}
psia_or_node= or_node;
}
}
}

/*:968*/
#line 9349 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*969:*/
#line 9464 "./marpa.w"
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
/*971:*/
#line 9504 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const gint ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const gint symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*976:*/
#line 9549 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1327:*/
#line 13089 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1327*/
#line 9556 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*966:*/
#line 9395 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:966*/
#line 9560 "./marpa.w"

PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= path_rule;
Position_of_OR(or_node)= 
symbol_instance_of_path_ahfa_item-SYMI_of_RULE(path_rule)+1;
MARPA_OFF_DEBUG3("Created or-node %s at %s",or_tag(or_node),G_STRLOC);
DANDs_of_OR(or_node)= NULL;
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,DANDs_of_OR(or_node));
}
}
}

/*:976*/
#line 9514 "./marpa.w"

/*977:*/
#line 9578 "./marpa.w"

{
gint i;
const gint null_count= Null_Count_of_AIM(path_ahfa_item);
for(i= 1;i<=null_count;i++)
{
const gint symbol_instance= symbol_instance_of_path_ahfa_item+i;
OR or_node= PSL_Datum(this_earley_set_psl,symbol_instance);
MARPA_ASSERT(symbol_instance<SYMI_Count_of_G(g))
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
DAND draft_and_node;
const gint rhs_ix= symbol_instance-SYMI_of_RULE(path_rule);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_ID_of_R(r,RHS_ID_of_RULE(path_rule,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_RULE(path_rule))
MARPA_ASSERT(symbol_instance>=0)
/*966:*/
#line 9395 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:966*/
#line 9595 "./marpa.w"

PSL_Datum(this_earley_set_psl,symbol_instance)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= path_rule;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
DANDs_of_OR(or_node)= draft_and_node= 
draft_and_node_new(&bocage_setup_obs,predecessor,cause);
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,
DANDs_of_OR(or_node));
Next_DAND_of_DAND(draft_and_node)= NULL;
}
MARPA_ASSERT(Position_of_OR(or_node)<=
SYMI_of_RULE(path_rule)+Length_of_RULE(path_rule))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_RULE(path_rule))
}
}

/*:977*/
#line 9515 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:971*/
#line 9486 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:969*/
#line 9357 "./marpa.w"

}

/*:963*/
#line 9328 "./marpa.w"

}
}
}
}

/*:962*/
#line 9307 "./marpa.w"

/*986:*/
#line 9696 "./marpa.w"

{
gint item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const nodes_by_aex= nodes_by_item[item_ordinal];
if(nodes_by_aex){
const EIM work_earley_item= eims_of_es[item_ordinal];
const gint work_ahfa_item_count= AIM_Count_of_EIM(work_earley_item);
const gint work_origin_ordinal= Ord_of_ES(Origin_of_EIM(work_earley_item));
AEX work_aex;
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
OR or_node= nodes_by_aex[work_aex];
Move_OR_to_Proper_OR(or_node);
if(or_node){
/*988:*/
#line 9733 "./marpa.w"

{
guint work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const gint work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*989:*/
#line 9749 "./marpa.w"
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
/*990:*/
#line 9781 "./marpa.w"

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
/*991:*/
#line 9810 "./marpa.w"

{
if(higher_path_leo_item){
/*995:*/
#line 9858 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:995*/
#line 9813 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:991*/
#line 9796 "./marpa.w"

/*993:*/
#line 9824 "./marpa.w"

{
const SYMID transition_symbol_id= Postdot_SYMID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
gint ix;
for(ix= 0;ix<aex_count;ix++)
{
const AEX cause_aex= aexes[ix];
OR dand_cause;
Set_OR_from_EIM_and_AEX(dand_cause,cause_earley_item,cause_aex);
MARPA_OFF_DEBUG3("%s eim=%s",G_STRLOC,eim_tag(cause_earley_item));
MARPA_OFF_DEBUG3("%s path or=%s",G_STRLOC,or_tag(path_or_node));
MARPA_OFF_DEBUG3("%s dand_predecessor=%s",G_STRLOC,or_tag(dand_predecessor));
MARPA_OFF_DEBUG3("%s dand_cause=%s",G_STRLOC,or_tag(dand_cause));
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:993*/
#line 9797 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*991:*/
#line 9810 "./marpa.w"

{
if(higher_path_leo_item){
/*995:*/
#line 9858 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:995*/
#line 9813 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:991*/
#line 9804 "./marpa.w"

/*996:*/
#line 9868 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const gint origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
MARPA_OFF_DEBUG2("lim=%s",lim_tag(path_leo_item));
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:996*/
#line 9805 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:990*/
#line 9771 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:989*/
#line 9744 "./marpa.w"

/*997:*/
#line 9879 "./marpa.w"

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
/*998:*/
#line 9909 "./marpa.w"

{
OR dand_predecessor;
/*999:*/
#line 9918 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:999*/
#line 9912 "./marpa.w"

MARPA_OFF_DEBUG2("or=%s",or_tag(work_proper_or_node));
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:998*/
#line 9901 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:997*/
#line 9745 "./marpa.w"

/*1000:*/
#line 9929 "./marpa.w"

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
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
gint ix;
for(ix= 0;ix<aex_count;ix++){
const AEX cause_aex= aexes[ix];
/*1001:*/
#line 9969 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const gint middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*999:*/
#line 9918 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:999*/
#line 9977 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
MARPA_OFF_DEBUG2("completion source, or=%s",or_tag(work_proper_or_node));
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:1001*/
#line 9960 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1000*/
#line 9746 "./marpa.w"

}

/*:988*/
#line 9711 "./marpa.w"

}
}
}
}
}

/*:986*/
#line 9308 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= g_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:961*/
#line 10356 "./marpa.w"

/*1009:*/
#line 10085 "./marpa.w"

{
gint unique_draft_and_node_count= 0;
/*1002:*/
#line 9984 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const gint or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
gint or_node_id= 0;
psar_init(and_psar,rule_count_of_g+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*1004:*/
#line 10016 "./marpa.w"

{
DAND dand= DANDs_of_OR(work_or_node);
DAND next_dand= Next_DAND_of_DAND(dand);
ORID work_or_node_id= ID_of_OR(work_or_node);

if(next_dand)
{
gint origin_ordinal= Origin_Ord_of_OR(work_or_node);
psar_dealloc(and_psar);
while(dand)
{
OR psl_or_node;
OR predecessor= Predecessor_OR_of_DAND(dand);
WHEID wheid= WHEID_of_OR(Cause_OR_of_DAND(dand));
const gint middle_ordinal= 
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

/*:1004*/
#line 9994 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:1002*/
#line 10088 "./marpa.w"

/*1010:*/
#line 10092 "./marpa.w"

{
const gint or_count_of_b= OR_Count_of_B(b);
gint or_node_id;
gint and_node_id= 0;
const OR*ors_of_b= ORs_of_B(b);
const AND ands_of_b= ANDs_of_B(b)= 
g_new(AND_Object,unique_draft_and_node_count);
for(or_node_id= 0;or_node_id<or_count_of_b;or_node_id++)
{
gint and_count_of_parent_or= 0;
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

/*:1010*/
#line 10089 "./marpa.w"

}

/*:1009*/
#line 10357 "./marpa.w"

/*1055:*/
#line 10557 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const gint start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:1055*/
#line 10358 "./marpa.w"
;
obstack_free(&bocage_setup_obs,NULL);
return b;
B_NEW_RETURN_ERROR:;
recce_unref(r);
if(b){
/*1068:*/
#line 10645 "./marpa.w"

/*960:*/
#line 9269 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
if(or_nodes)
{
g_free(or_nodes);
ORs_of_B(b)= NULL;
}
if(and_nodes)
{
g_free(and_nodes);
ANDs_of_B(b)= NULL;
}
}

/*:960*/
#line 10646 "./marpa.w"
;
/*1039:*/
#line 10305 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:1039*/
#line 10647 "./marpa.w"
;

/*:1068*/
#line 10364 "./marpa.w"
;
}
return NULL;
}

/*:1042*//*1050:*/
#line 10443 "./marpa.w"

PRIVATE_NOT_INLINE BOCAGE r_create_null_bocage(RECCE r,BOCAGE b)
{
const GRAMMAR g= G_of_R(r);
const RULE null_start_rule= g->t_null_start_rule;
gint rule_length= Length_of_RULE(g->t_null_start_rule);
OR*or_nodes= ORs_of_B(b)= g_new(OR,1);
AND and_nodes= ANDs_of_B(b)= g_new(AND_Object,1);
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
(OR)TOK_by_ID_of_R(r,
RHS_ID_of_RULE(null_start_rule,rule_length-1));

return b;
}

/*:1050*//*1057:*/
#line 10580 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10583 "./marpa.w"

return g;
}

/*:1057*//*1060:*/
#line 10591 "./marpa.w"

Marpa_Or_Node_ID marpa_b_top_or_node(Marpa_Bocage b)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10594 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10595 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10596 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:1060*//*1065:*/
#line 10608 "./marpa.w"

static inline void
bocage_unref(BOCAGE b)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,b->t_ref_count);
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

/*:1065*//*1067:*/
#line 10629 "./marpa.w"

static inline BOCAGE
bocage_ref(BOCAGE b)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,b->t_ref_count);
MARPA_ASSERT(b->t_ref_count> 0)
b->t_ref_count++;
return b;
}
Marpa_Bocage
marpa_b_ref(Marpa_Bocage b)
{
return bocage_ref(b);
}

/*:1067*//*1070:*/
#line 10655 "./marpa.w"

void
bocage_free(BOCAGE b)
{
MARPA_DEBUG4("%s %s: Destroying %p",G_STRFUNC,G_STRLOC,b)
const RECCE r= R_of_B(b);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10661 "./marpa.w"

recce_unref(r);
if(b)
{
/*1068:*/
#line 10645 "./marpa.w"

/*960:*/
#line 9269 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
if(or_nodes)
{
g_free(or_nodes);
ORs_of_B(b)= NULL;
}
if(and_nodes)
{
g_free(and_nodes);
ANDs_of_B(b)= NULL;
}
}

/*:960*/
#line 10646 "./marpa.w"
;
/*1039:*/
#line 10305 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:1039*/
#line 10647 "./marpa.w"
;

/*:1068*/
#line 10665 "./marpa.w"
;
g_slice_free(struct s_bocage,b);
}
}

/*:1070*//*1074:*/
#line 10694 "./marpa.w"

gint marpa_b_or_node_set(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10698 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10699 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10700 "./marpa.w"

/*1072:*/
#line 10673 "./marpa.w"
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

/*:1072*/
#line 10701 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:1074*//*1076:*/
#line 10707 "./marpa.w"

gint marpa_b_or_node_origin(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10711 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10712 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10713 "./marpa.w"

/*1072:*/
#line 10673 "./marpa.w"
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

/*:1072*/
#line 10714 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:1076*//*1078:*/
#line 10720 "./marpa.w"

gint marpa_b_or_node_rule(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10724 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10725 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10726 "./marpa.w"

/*1072:*/
#line 10673 "./marpa.w"
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

/*:1072*/
#line 10727 "./marpa.w"

return ID_of_RULE(RULE_of_OR(or_node));
}

/*:1078*//*1080:*/
#line 10733 "./marpa.w"

gint marpa_b_or_node_position(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10737 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10738 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10739 "./marpa.w"

/*1072:*/
#line 10673 "./marpa.w"
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

/*:1072*/
#line 10740 "./marpa.w"

return Position_of_OR(or_node);
}

/*:1080*//*1082:*/
#line 10746 "./marpa.w"

gint marpa_b_or_node_first_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10750 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10751 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10752 "./marpa.w"

/*1072:*/
#line 10673 "./marpa.w"
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

/*:1072*/
#line 10753 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:1082*//*1084:*/
#line 10759 "./marpa.w"

gint marpa_b_or_node_last_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10763 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10764 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10765 "./marpa.w"

/*1072:*/
#line 10673 "./marpa.w"
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

/*:1072*/
#line 10766 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:1084*//*1086:*/
#line 10773 "./marpa.w"

gint marpa_b_or_node_and_count(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 10777 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 10778 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10779 "./marpa.w"

/*1072:*/
#line 10673 "./marpa.w"
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

/*:1072*/
#line 10780 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:1086*//*1092:*/
#line 10831 "./marpa.w"

static inline void tree_exhaust(TREE t)
{
if(FSTACK_IS_INITIALIZED(t->t_fork_stack))
{
FSTACK_DESTROY(t->t_fork_stack);
FSTACK_SAFE(t->t_fork_stack);
}
if(FSTACK_IS_INITIALIZED(t->t_fork_worklist))
{
FSTACK_DESTROY(t->t_fork_worklist);
FSTACK_SAFE(t->t_fork_worklist);
}
if(t->t_and_node_in_use){
bv_free(t->t_and_node_in_use);
t->t_and_node_in_use= NULL;
}
}

/*:1092*//*1094:*/
#line 10855 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1345:*/
#line 13256 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1345*/
#line 10858 "./marpa.w"

TREE t;
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10860 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 10861 "./marpa.w"

t= g_slice_new(struct s_tree);
O_of_T(t)= o;
order_ref(o);
order_freeze(o);
/*1095:*/
#line 10870 "./marpa.w"

{
const gint and_count= AND_Count_of_B(b);
t->t_parse_count= 0;
t->t_and_node_in_use= bv_create((guint)and_count);
FSTACK_INIT(t->t_fork_stack,FORK_Object,and_count);
FSTACK_INIT(t->t_fork_worklist,gint,and_count);
}

/*:1095*//*1098:*/
#line 10882 "./marpa.w"

t->t_ref_count= 1;

/*:1098*//*1109:*/
#line 10972 "./marpa.w"
t->t_pause_counter= 0;
/*:1109*/
#line 10866 "./marpa.w"

return t;
}

/*:1094*//*1100:*/
#line 10888 "./marpa.w"

static inline void
tree_unref(TREE t)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,t->t_ref_count);
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

/*:1100*//*1102:*/
#line 10909 "./marpa.w"

static inline TREE
tree_ref(TREE t)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,t->t_ref_count);
MARPA_ASSERT(t->t_ref_count> 0)
t->t_ref_count++;
return t;
}
Marpa_Tree
marpa_t_ref(Marpa_Tree t)
{
return tree_ref(t);
}

/*:1102*//*1104:*/
#line 10926 "./marpa.w"

static inline void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
g_slice_free(struct s_tree,t);
}

/*:1104*//*1110:*/
#line 10973 "./marpa.w"

static inline void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1110*//*1111:*/
#line 10982 "./marpa.w"

static inline void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1111*//*1113:*/
#line 11004 "./marpa.w"

Marpa_Grammar marpa_t_g(Marpa_Tree t)
{
/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11007 "./marpa.w"

return g;
}

/*:1113*//*1115:*/
#line 11013 "./marpa.w"

gint marpa_t_next(Marpa_Tree t)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11016 "./marpa.w"

gint is_first_tree_attempt= 0;
/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11018 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11019 "./marpa.w"

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
/*1120:*/
#line 11081 "./marpa.w"

{
ORID top_or_id= Top_ORID_of_B(b);
OR top_or_node= OR_of_B_by_ID(b,top_or_id);
FORK fork;
gint choice;
choice= or_node_next_choice(o,t,top_or_node,0);


MARPA_DEBUG3("%s %s",G_STRFUNC,G_STRLOC);
if(choice<0)
goto TREE_IS_EXHAUSTED;
MARPA_DEBUG3("%s %s",G_STRFUNC,G_STRLOC);
fork= FSTACK_PUSH(t->t_fork_stack);
OR_of_FORK(fork)= top_or_node;
Choice_of_FORK(fork)= choice;
Parent_of_FORK(fork)= -1;
FORK_Cause_is_Ready(fork)= 0;
FORK_is_Cause(fork)= 0;
FORK_Predecessor_is_Ready(fork)= 0;
FORK_is_Predecessor(fork)= 0;
*(FSTACK_PUSH(t->t_fork_worklist))= 0;
}

/*:1120*/
#line 11032 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
}else{
/*1121:*/
#line 11108 "./marpa.w"
{
while(1){
FORK iteration_candidate= FSTACK_TOP(t->t_fork_stack,FORK_Object);
gint choice;
if(!iteration_candidate)break;
choice= Choice_of_FORK(iteration_candidate);
MARPA_ASSERT(choice>=0);
{
OR or_node= OR_of_FORK(iteration_candidate);
ANDID and_node_id= and_order_get(o,or_node,choice);
tree_and_node_release(t,and_node_id);
choice= or_node_next_choice(o,t,or_node,choice+1);
}
if(choice>=0){





Choice_of_FORK(iteration_candidate)= choice;
FORK_Cause_is_Ready(iteration_candidate)= 0;
FORK_Predecessor_is_Ready(iteration_candidate)= 0;
break;
}
{

const gint parent_fork_ix= Parent_of_FORK(iteration_candidate);
if(parent_fork_ix>=0){
FORK parent_fork= FORK_of_TREE_by_IX(t,parent_fork_ix);
if(FORK_is_Cause(iteration_candidate)){
FORK_Cause_is_Ready(parent_fork)= 0;
}
if(FORK_is_Predecessor(iteration_candidate)){
FORK_Predecessor_is_Ready(parent_fork)= 0;
}
}


FSTACK_POP(t->t_fork_stack);
}
}
{
gint stack_length= Size_of_T(t);
gint i;
if(stack_length<=0)goto TREE_IS_EXHAUSTED;
FSTACK_CLEAR(t->t_fork_worklist);
for(i= 0;i<stack_length;i++){
*(FSTACK_PUSH(t->t_fork_worklist))= i;
}
}
}

/*:1121*/
#line 11039 "./marpa.w"

}
/*1122:*/
#line 11160 "./marpa.w"
{
while(1){
FORKID*p_work_fork_id;
FORK work_fork;
ANDID work_and_node_id;
AND work_and_node;
OR work_or_node;
OR child_or_node= NULL;
gint choice;
gint child_is_cause= 0;
gint child_is_predecessor= 0;
p_work_fork_id= FSTACK_TOP(t->t_fork_worklist,FORKID);
if(!p_work_fork_id){
goto TREE_IS_FINISHED;
}
work_fork= FORK_of_TREE_by_IX(t,*p_work_fork_id);
work_or_node= OR_of_FORK(work_fork);
work_and_node_id= and_order_get(o,work_or_node,Choice_of_FORK(work_fork));
work_and_node= ands_of_b+work_and_node_id;
if(!FORK_Cause_is_Ready(work_fork)){
child_or_node= Cause_OR_of_AND(work_and_node);
if(child_or_node&&OR_is_Token(child_or_node))child_or_node= NULL;
if(child_or_node){
child_is_cause= 1;
}else{
FORK_Cause_is_Ready(work_fork)= 1;
}
}
if(!child_or_node&&!FORK_Predecessor_is_Ready(work_fork)){
child_or_node= Predecessor_OR_of_AND(work_and_node);
if(child_or_node){
child_is_predecessor= 1;
}else{
FORK_Predecessor_is_Ready(work_fork)= 1;
}
}
if(!child_or_node){
FSTACK_POP(t->t_fork_worklist);
goto NEXT_FORK_ON_WORKLIST;
}
choice= or_node_next_choice(o,t,child_or_node,0);
if(choice<0)goto NEXT_TREE;
/*1125:*/
#line 11223 "./marpa.w"

{
FORKID new_fork_id= Size_of_T(t);
FORK new_fork= FSTACK_PUSH(t->t_fork_stack);
*(FSTACK_PUSH(t->t_fork_worklist))= new_fork_id;
Parent_of_FORK(new_fork)= *p_work_fork_id;
Choice_of_FORK(new_fork)= choice;
OR_of_FORK(new_fork)= child_or_node;
FORK_Cause_is_Ready(new_fork)= 0;
if((FORK_is_Cause(new_fork)= child_is_cause)){
FORK_Cause_is_Ready(work_fork)= 1;
}
FORK_Predecessor_is_Ready(new_fork)= 0;
if((FORK_is_Predecessor(new_fork)= child_is_predecessor)){
FORK_Predecessor_is_Ready(work_fork)= 1;
}
}

/*:1125*/
#line 11202 "./marpa.w"
;
NEXT_FORK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1122*/
#line 11041 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_fork_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return-1;

}

/*:1115*//*1117:*/
#line 11061 "./marpa.w"

static inline void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1117*//*1118:*/
#line 11067 "./marpa.w"

static inline void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1118*//*1119:*/
#line 11075 "./marpa.w"

static inline gint tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(guint)and_node_id);
}

/*:1119*//*1124:*/
#line 11210 "./marpa.w"

static inline gint or_node_next_choice(ORDER o,TREE tree,OR or_node,gint start_choice)
{
gint choice= start_choice;
while(1){
ANDID and_node_id= and_order_get(o,or_node,choice);
if(and_node_id<0)return-1;
if(tree_and_node_try(tree,and_node_id))return choice;
choice++;
}
return-1;
}

/*:1124*//*1127:*/
#line 11243 "./marpa.w"

gint marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1127*//*1129:*/
#line 11258 "./marpa.w"

gint marpa_t_size(Marpa_Tree t)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11261 "./marpa.w"

/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11262 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11263 "./marpa.w"

if(T_is_Exhausted(t)){
return-1;
}
return Size_of_T(t);
}

/*:1129*//*1136:*/
#line 11307 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1345:*/
#line 13256 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1345*/
#line 11310 "./marpa.w"

/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11311 "./marpa.w"

ORDER o;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11313 "./marpa.w"

o= g_slice_new(struct s_order);
B_of_O(o)= b;
bocage_ref(b);
/*1133:*/
#line 11295 "./marpa.w"

{
o->t_and_node_in_use= NULL;
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
}

/*:1133*//*1139:*/
#line 11323 "./marpa.w"

o->t_ref_count= 1;

/*:1139*/
#line 11317 "./marpa.w"

return o;
}

/*:1136*//*1141:*/
#line 11329 "./marpa.w"

static inline void
order_unref(ORDER o)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,o->t_ref_count);
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

/*:1141*//*1143:*/
#line 11350 "./marpa.w"

static inline ORDER
order_ref(ORDER o)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,o->t_ref_count);
MARPA_ASSERT(o->t_ref_count> 0)
o->t_ref_count++;
return o;
}
Marpa_Order
marpa_o_ref(Marpa_Order o)
{
return order_ref(o);
}

/*:1143*//*1145:*/
#line 11367 "./marpa.w"

static inline void order_strip(ORDER o)
{
if(o->t_and_node_in_use)
{
bv_free(o->t_and_node_in_use);
o->t_and_node_in_use= NULL;
}
}
/*:1145*//*1147:*/
#line 11378 "./marpa.w"

static inline void order_freeze(ORDER o)
{
order_strip(o);
O_is_Frozen(o)= 0;
}
/*:1147*//*1149:*/
#line 11386 "./marpa.w"

static inline void order_free(ORDER o)
{
MARPA_DEBUG4("%s %s: Destroying %p",G_STRFUNC,G_STRLOC,o)
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 11390 "./marpa.w"

bocage_unref(b);
order_strip(o);
if(o->t_and_node_orderings){
o->t_and_node_orderings= NULL;
obstack_free(&OBS_of_O(o),NULL);
}
g_slice_free(struct s_order,o);
}

/*:1149*//*1152:*/
#line 11416 "./marpa.w"

Marpa_Grammar marpa_o_g(Marpa_Order o)
{
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 11419 "./marpa.w"

return g;
}

/*:1152*//*1156:*/
#line 11472 "./marpa.w"

gint marpa_o_and_order_set(
Marpa_Order o,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length)
{
OR or_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11480 "./marpa.w"

/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 11481 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11482 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*1072:*/
#line 10673 "./marpa.w"
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

/*:1072*/
#line 11488 "./marpa.w"

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
gint and_id;
const gint and_count_of_r= AND_Count_of_B(b);
obstack_init(obs);
o->t_and_node_orderings= 
and_node_orderings= 
obstack_alloc(obs,sizeof(ANDID*)*and_count_of_r);
for(and_id= 0;and_id<and_count_of_r;and_id++)
{
and_node_orderings[and_id]= (ANDID*)NULL;
}
o->t_and_node_in_use= 
and_node_in_use= bv_create((guint)and_count_of_r);
}
first_and_node_id= First_ANDID_of_OR(or_node);
and_count_of_or= AND_Count_of_OR(or_node);
{
gint and_ix;
for(and_ix= 0;and_ix<length;and_ix++)
{
ANDID and_node_id= and_node_ids[and_ix];
if(and_node_id<first_and_node_id||
and_node_id-first_and_node_id>=and_count_of_or){
MARPA_DEV_ERROR("and node not in or node");
return failure_indicator;
}
if(bv_bit_test(and_node_in_use,(guint)and_node_id))
{
MARPA_DEV_ERROR("dup and node");
return failure_indicator;
}
bv_bit_set(and_node_in_use,(guint)and_node_id);
}
}
if(and_node_orderings[or_node_id]){
MARPA_DEV_ERROR("or node already ordered");
return failure_indicator;
}
{
ANDID*orderings= obstack_alloc(obs,sizeof(ANDID)*(length+1));
gint i;
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

/*:1156*//*1159:*/
#line 11554 "./marpa.w"

static inline ANDID and_order_get(ORDER o,OR or_node,gint ix)
{
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 11557 "./marpa.w"

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
gint length= ordering[0];
if(ix>=length)
return-1;
return ordering[1+ix];
}
}
return First_ANDID_of_OR(or_node)+ix;
}

/*:1159*//*1160:*/
#line 11579 "./marpa.w"

Marpa_And_Node_ID marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,gint ix)
{
OR or_node;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11584 "./marpa.w"

/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 11585 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11586 "./marpa.w"

/*1072:*/
#line 10673 "./marpa.w"
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

/*:1072*/
#line 11587 "./marpa.w"

if(ix<0){
MARPA_DEV_ERROR("negative and ix");
return failure_indicator;
}
return and_order_get(o,or_node,ix);
}

/*:1160*//*1168:*/
#line 11658 "./marpa.w"

gint marpa_t_fork_or_node(Marpa_Tree t,int fork_id)
{
FORK fork;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11662 "./marpa.w"

/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11663 "./marpa.w"

/*1166:*/
#line 11637 "./marpa.w"
{
FORK base_fork;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11639 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(t->t_fork_stack,FORK_Object);
if(fork_id<0){
MARPA_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=Size_of_T(t)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1166*/
#line 11664 "./marpa.w"

return ID_of_OR(OR_of_FORK(fork));
}

/*:1168*//*1170:*/
#line 11671 "./marpa.w"

gint marpa_t_fork_choice(Marpa_Tree t,int fork_id)
{
FORK fork;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11675 "./marpa.w"

/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11676 "./marpa.w"

/*1166:*/
#line 11637 "./marpa.w"
{
FORK base_fork;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11639 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(t->t_fork_stack,FORK_Object);
if(fork_id<0){
MARPA_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=Size_of_T(t)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1166*/
#line 11677 "./marpa.w"

return Choice_of_FORK(fork);
}

/*:1170*//*1172:*/
#line 11692 "./marpa.w"

gint marpa_t_fork_parent(Marpa_Tree t,int fork_id)
{
FORK fork;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11696 "./marpa.w"

/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11697 "./marpa.w"

/*1166:*/
#line 11637 "./marpa.w"
{
FORK base_fork;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11639 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(t->t_fork_stack,FORK_Object);
if(fork_id<0){
MARPA_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=Size_of_T(t)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1166*/
#line 11698 "./marpa.w"

return Parent_of_FORK(fork);
}

/*:1172*//*1174:*/
#line 11705 "./marpa.w"

gint marpa_t_fork_cause_is_ready(Marpa_Tree t,int fork_id)
{
FORK fork;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11709 "./marpa.w"

/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11710 "./marpa.w"

/*1166:*/
#line 11637 "./marpa.w"
{
FORK base_fork;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11639 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(t->t_fork_stack,FORK_Object);
if(fork_id<0){
MARPA_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=Size_of_T(t)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1166*/
#line 11711 "./marpa.w"

return FORK_Cause_is_Ready(fork);
}

/*:1174*//*1176:*/
#line 11718 "./marpa.w"

gint marpa_t_fork_predecessor_is_ready(Marpa_Tree t,int fork_id)
{
FORK fork;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11722 "./marpa.w"

/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11723 "./marpa.w"

/*1166:*/
#line 11637 "./marpa.w"
{
FORK base_fork;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11639 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(t->t_fork_stack,FORK_Object);
if(fork_id<0){
MARPA_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=Size_of_T(t)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1166*/
#line 11724 "./marpa.w"

return FORK_Predecessor_is_Ready(fork);
}

/*:1176*//*1178:*/
#line 11731 "./marpa.w"

gint marpa_t_fork_is_cause(Marpa_Tree t,int fork_id)
{
FORK fork;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11735 "./marpa.w"

/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11736 "./marpa.w"

/*1166:*/
#line 11637 "./marpa.w"
{
FORK base_fork;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11639 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(t->t_fork_stack,FORK_Object);
if(fork_id<0){
MARPA_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=Size_of_T(t)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1166*/
#line 11737 "./marpa.w"

return FORK_is_Cause(fork);
}

/*:1178*//*1180:*/
#line 11744 "./marpa.w"

gint marpa_t_fork_is_predecessor(Marpa_Tree t,int fork_id)
{
FORK fork;
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11748 "./marpa.w"

/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11749 "./marpa.w"

/*1166:*/
#line 11637 "./marpa.w"
{
FORK base_fork;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11639 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(t->t_fork_stack,FORK_Object);
if(fork_id<0){
MARPA_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=Size_of_T(t)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1166*/
#line 11750 "./marpa.w"

return FORK_is_Predecessor(fork);
}

/*:1180*//*1191:*/
#line 11861 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1345:*/
#line 13256 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1345*/
#line 11864 "./marpa.w"

/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11865 "./marpa.w"
;
/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11866 "./marpa.w"

if(!T_is_Exhausted(t))
{
VALUE v= g_slice_new(struct s_value);
const gint minimum_stack_size= (8192/sizeof(gint));
const gint initial_stack_size= 
MAX(Size_of_TREE(t)/1024,minimum_stack_size);
DSTACK_INIT(VStack_of_V(v),gint,initial_stack_size);
V_is_Active(v)= 1;
V_is_Trace(v)= 1;
TOS_of_V(v)= -1;
FORK_of_V(v)= -1;
/*1194:*/
#line 11890 "./marpa.w"

v->t_ref_count= 1;

/*:1194*/
#line 11878 "./marpa.w"

tree_pause(t);
T_of_V(v)= t;
return v;
}
MARPA_DEV_ERROR("tree is exhausted");
return NULL;
}

/*:1191*//*1196:*/
#line 11896 "./marpa.w"

static inline void
value_unref(VALUE v)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,v->t_ref_count);
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

/*:1196*//*1198:*/
#line 11917 "./marpa.w"

static inline VALUE
value_ref(VALUE v)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,v->t_ref_count);
MARPA_ASSERT(v->t_ref_count> 0)
v->t_ref_count++;
return v;
}
Marpa_Value
marpa_v_ref(Marpa_Value v)
{
return value_ref(v);
}

/*:1198*//*1200:*/
#line 11934 "./marpa.w"

static inline void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
if(DSTACK_IS_INITIALIZED(v->t_virtual_stack))
{
DSTACK_DESTROY(v->t_virtual_stack);
}
g_slice_free(struct s_value,v);
}

/*:1200*//*1203:*/
#line 11961 "./marpa.w"

Marpa_Grammar marpa_v_g(Marpa_Value v)
{
/*1201:*/
#line 11945 "./marpa.w"

TREE t= T_of_V(v);
/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11947 "./marpa.w"


/*:1201*/
#line 11964 "./marpa.w"

return g;
}

/*:1203*//*1205:*/
#line 11970 "./marpa.w"

gint marpa_v_trace(Marpa_Value v,gint flag)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11973 "./marpa.w"

/*1201:*/
#line 11945 "./marpa.w"

TREE t= T_of_V(v);
/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11947 "./marpa.w"


/*:1201*/
#line 11974 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11975 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1205*//*1207:*/
#line 11985 "./marpa.w"

Marpa_Fork_ID marpa_v_fork(Marpa_Value v)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 11988 "./marpa.w"

/*1201:*/
#line 11945 "./marpa.w"

TREE t= T_of_V(v);
/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11947 "./marpa.w"


/*:1201*/
#line 11989 "./marpa.w"

/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 11990 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
return FORK_of_V(v);
}

/*:1207*//*1209:*/
#line 11999 "./marpa.w"

Marpa_Fork_ID marpa_v_event(Marpa_Value v,Marpa_Event*event)
{
/*1346:*/
#line 13259 "./marpa.w"
const int failure_indicator= -2;

/*:1346*/
#line 12002 "./marpa.w"

AND and_nodes;
gint semantic_rule_id= -1;
gint token_id= -1;
gpointer token_value= NULL;
gint arg_0= -1;
gint arg_n= -1;
FORKID fork_ix;
gint continue_with_next_fork;
/*1201:*/
#line 11945 "./marpa.w"

TREE t= T_of_V(v);
/*1090:*/
#line 10825 "./marpa.w"

ORDER o= O_of_T(t);
/*1150:*/
#line 11400 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1035:*/
#line 10291 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1035*/
#line 11402 "./marpa.w"


/*:1150*/
#line 10827 "./marpa.w"
;

/*:1090*/
#line 11947 "./marpa.w"


/*:1201*/
#line 12011 "./marpa.w"



/*1359:*/
#line 13327 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1359*/
#line 12014 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}

and_nodes= ANDs_of_B(B_of_O(o));

arg_0= arg_n= TOS_of_V(v);
fork_ix= FORK_of_V(v);
if(fork_ix<0){
fork_ix= Size_of_TREE(t);
}
continue_with_next_fork= !V_is_Trace(v);

while(1){
OR or;
RULE fork_rule;
fork_ix--;
if(fork_ix<0)goto RETURN_SOFT_ERROR;
{
ANDID and_node_id;
AND and_node;
const FORK fork= FORK_of_TREE_by_IX(t,fork_ix);
const gint choice= Choice_of_FORK(fork);
or= OR_of_FORK(fork);
and_node_id= and_order_get(o,or,choice);
and_node= and_nodes+and_node_id;
token_id= and_node_token(and_node,&token_value);
}
if(token_id>=0){
arg_0= ++arg_n;
MARPA_OFF_DEBUG3("symbol %d at %d",token_id,arg_0);
continue_with_next_fork= 0;
}
fork_rule= RULE_of_OR(or);
if(Position_of_OR(or)==Length_of_RULE(fork_rule)){
gint virtual_rhs= RULE_is_Virtual_RHS(fork_rule);
gint virtual_lhs= RULE_is_Virtual_LHS(fork_rule);
gint real_symbol_count;
const DSTACK virtual_stack= &VStack_of_V(v);
if(virtual_lhs){
real_symbol_count= Real_SYM_Count_of_RULE(fork_rule);
if(virtual_rhs){
*(DSTACK_TOP(*virtual_stack,gint))+= real_symbol_count;
}else{
*DSTACK_PUSH(*virtual_stack,gint)= real_symbol_count;
}
goto NEXT_FORK;
}
if(virtual_rhs){
real_symbol_count= Real_SYM_Count_of_RULE(fork_rule);
real_symbol_count+= *DSTACK_POP(*virtual_stack,gint);
}else{
real_symbol_count= Length_of_RULE(fork_rule);
}
arg_0= arg_n-real_symbol_count+1;
semantic_rule_id= 
fork_rule->t_is_semantic_equivalent?
fork_rule->t_original:ID_of_RULE(fork_rule);
continue_with_next_fork= 0;
}
NEXT_FORK:;
if(!continue_with_next_fork)break;
}

/*1210:*/
#line 12088 "./marpa.w"

{
SYMID_of_EVE(event)= token_id;
Value_of_EVE(event)= token_value;
RULEID_of_EVE(event)= semantic_rule_id;
TOS_of_V(v)= Arg0_of_EVE(event)= arg_0;
FORK_of_V(v)= fork_ix;
ArgN_of_EVE(event)= arg_n;
}

/*:1210*/
#line 12079 "./marpa.w"

return FORK_of_V(v);

RETURN_SOFT_ERROR:;
/*1210:*/
#line 12088 "./marpa.w"

{
SYMID_of_EVE(event)= token_id;
Value_of_EVE(event)= token_value;
RULEID_of_EVE(event)= semantic_rule_id;
TOS_of_V(v)= Arg0_of_EVE(event)= arg_0;
FORK_of_V(v)= fork_ix;
ArgN_of_EVE(event)= arg_n;
}

/*:1210*/
#line 12083 "./marpa.w"

return-1;

}

/*:1209*//*1214:*/
#line 12125 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1214*//*1216:*/
#line 12133 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:1216*//*1219:*/
#line 12151 "./marpa.w"

static inline Bit_Vector bv_create(guint bits)
{
guint size= bv_bits_to_size(bits);
guint bytes= (size+bv_hiddenwords)<<sizeof(guint);
guint*addr= (Bit_Vector)g_malloc0((size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}

/*:1219*//*1221:*/
#line 12171 "./marpa.w"

static inline Bit_Vector
bv_obs_create(struct obstack*obs,guint bits)
{
guint size= bv_bits_to_size(bits);
guint bytes= (size+bv_hiddenwords)<<sizeof(guint);
guint*addr= (Bit_Vector)obstack_alloc(obs,(size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
if(size> 0){
Bit_Vector bv= addr;
while(size--)*bv++= 0u;
}
return addr;
}


/*:1221*//*1222:*/
#line 12192 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:1222*//*1224:*/
#line 12204 "./marpa.w"
static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from)
{
guint*p_to= bv_to;
const guint bits= BV_BITS(bv_to);
if(bits> 0)
{
gint count= BV_SIZE(bv_to);
while(count--)*p_to++= *bv_from++;
}
return(bv_to);
}
/*:1224*//*1226:*/
#line 12224 "./marpa.w"
static inline
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}
/*:1226*//*1228:*/
#line 12234 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:1228*//*1230:*/
#line 12243 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:1230*//*1232:*/
#line 12251 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:1232*//*1236:*/
#line 12266 "./marpa.w"

static inline void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1236*//*1238:*/
#line 12282 "./marpa.w"

static inline void bv_over_clear(Bit_Vector bv,guint bit)
{
guint length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1238*//*1240:*/
#line 12290 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:1240*//*1242:*/
#line 12298 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:1242*//*1244:*/
#line 12306 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:1244*//*1248:*/
#line 12317 "./marpa.w"

static inline gboolean
bv_bit_test_and_set(Bit_Vector vector,guint bit)
{
Bit_Vector addr= vector+(bit/bv_wordbits);
guint mask= bv_lsb<<(bit%bv_wordbits);
if((*addr&mask)!=0u)
return 1;
*addr|= mask;
return 0;
}

/*:1248*//*1249:*/
#line 12330 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr)
{
guint size= BV_SIZE(addr);
gboolean r= TRUE;
if(size> 0){
*(addr+size-1)&= BV_MASK(addr);
while(r&&(size--> 0))r= (*addr++==0);
}
return(r);
}
/*:1249*//*1251:*/
#line 12347 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:1251*//*1253:*/
#line 12359 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:1253*//*1255:*/
#line 12371 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:1255*//*1257:*/
#line 12383 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:1257*//*1259:*/
#line 12395 "./marpa.w"

static inline
gboolean bv_scan(Bit_Vector bv,guint start,
guint*min,guint*max)
{
guint size= BV_SIZE(bv);
guint mask= BV_MASK(bv);
guint offset;
guint bitmask;
guint value;
gboolean empty;

if(size==0)return FALSE;
if(start>=BV_BITS(bv))return FALSE;
*min= start;
*max= start;
offset= start/bv_wordbits;
*(bv+size-1)&= mask;
bv+= offset;
size-= offset;
bitmask= (guint)1<<(start&bv_modmask);
mask= ~(bitmask|(bitmask-(guint)1));
value= *bv++;
if((value&bitmask)==0)
{
value&= mask;
if(value==0)
{
offset++;
empty= TRUE;
while(empty&&(--size> 0))
{
if((value= *bv++))empty= FALSE;else offset++;
}
if(empty)return FALSE;
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
empty= TRUE;
while(empty&&(--size> 0))
{
if((value= ~*bv++))empty= FALSE;else offset++;
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
return TRUE;
}
/*:1259*//*1261:*/
#line 12471 "./marpa.w"

static inline guint
bv_count(Bit_Vector v)
{
guint start,min,max;
guint count= 0;
for(start= 0;bv_scan(v,start,&min,&max);start= max+2)
{
count+= max-min+1;
}
return count;
}
/*:1261*//*1267:*/
#line 12525 "./marpa.w"

static void
rhs_closure(struct marpa_g*g,Bit_Vector bv)
{
guint min,max,start= 0;
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_DECLARE(stack,Marpa_Symbol_ID)
FSTACK_INIT(stack,Marpa_Symbol_ID,SYM_Count_of_G(g));
while(bv_scan(bv,start,&min,&max))
{
guint symid;
for(symid= min;symid<=max;symid++)
{
*(FSTACK_PUSH(stack))= symid;
}
start= max+2;
}
while((top_of_stack= FSTACK_POP(stack)))
{
guint rule_ix;
GArray*rules= SYM_by_ID(*top_of_stack)->t_rhs;
for(rule_ix= 0;rule_ix<rules->len;rule_ix++)
{
Marpa_Rule_ID rule_id= 
g_array_index(rules,Marpa_Rule_ID,rule_ix);
RULE rule= RULE_by_ID(g,rule_id);
guint rule_length;
guint rh_ix;
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
if(bv_bit_test(bv,(guint)lhs_id))
goto NEXT_RULE;
rule_length= Length_of_RULE(rule);
for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test(bv,(guint)RHS_ID_of_RULE(rule,rh_ix)))
goto NEXT_RULE;
}



bv_bit_set(bv,(guint)lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}
/*:1267*//*1272:*/
#line 12604 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns)
{
guint bv_data_words= bv_bits_to_size(columns);
guint row_bytes= (bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
guint bv_mask= bv_bits_to_unused_mask(columns);
Bit_Vector_Word*matrix_addr= g_malloc0((size_t)(row_bytes*rows));
guint row;
for(row= 0;row<rows;row++){
guint row_start= row*(bv_data_words+bv_hiddenwords);
matrix_addr[row_start]= columns;
matrix_addr[row_start+1]= bv_data_words;
matrix_addr[row_start+2]= bv_mask;
}
return matrix_addr;
}
/*:1272*//*1274:*/
#line 12624 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:1274*//*1276:*/
#line 12637 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:1276*//*1278:*/
#line 12654 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:1278*//*1281:*/
#line 12664 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:1281*//*1284:*/
#line 12673 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:1284*//*1287:*/
#line 12682 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:1287*//*1289:*/
#line 12696 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix)
{
struct transition{guint from,to;}*top_of_stack= NULL;
guint size= matrix_columns(matrix);
guint row;
DSTACK_DECLARE(stack);
DSTACK_INIT(stack,struct transition,1024);
for(row= 0;row<size;row++){
guint min,max,start;
Bit_Vector row_vector= matrix_row(matrix,row);
for(start= 0;bv_scan(row_vector,start,&min,&max);start= max+2){
guint column;
for(column= min;column<=max;column++){
struct transition*t= DSTACK_PUSH(stack,struct transition);
t->from= row;
t->to= column;
}}}
while((top_of_stack= DSTACK_POP(stack,struct transition))){
guint old_from= top_of_stack->from;
guint old_to= top_of_stack->to;
guint new_ix;
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
/*:1289*//*1299:*/
#line 12840 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_bytes){
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}
/*:1299*//*1316:*/
#line 12984 "./marpa.w"

static inline void
psar_init(const PSAR psar,gint length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1316*//*1317:*/
#line 12991 "./marpa.w"

static inline void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
MARPA_OFF_DEBUG3("%s psl=%p",G_STRLOC,psl);
while(psl)
{
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
MARPA_OFF_DEBUG3("%s owner=%p",G_STRLOC,owner);
if(owner)
*owner= NULL;
g_slice_free1(Sizeof_PSL(psar),psl);
psl= next_psl;
MARPA_OFF_DEBUG3("%s psl=%p",G_STRLOC,psl);
}
}
/*:1317*//*1318:*/
#line 13008 "./marpa.w"

static inline PSL psl_new(const PSAR psar){
gint i;
PSL new_psl= g_slice_alloc(Sizeof_PSL(psar));
new_psl->t_next= NULL;
new_psl->t_prev= NULL;
new_psl->t_owner= NULL;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(new_psl,i)= NULL;
}
return new_psl;
}
/*:1318*//*1322:*/
#line 13040 "./marpa.w"

static inline void psar_reset(const PSAR psar){
PSL psl= psar->t_first_psl;
while(psl&&psl->t_owner){
gint i;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(psl,i)= NULL;
}
psl= psl->t_next;
}
psar_dealloc(psar);
}

/*:1322*//*1324:*/
#line 13059 "./marpa.w"

static inline void psar_dealloc(const PSAR psar){
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
#line 13081 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar){
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1326*//*1330:*/
#line 13106 "./marpa.w"

static inline PSL psl_alloc(const PSAR psar){
PSL free_psl= psar->t_first_free_psl;
PSL next_psl= free_psl->t_next;
if(!next_psl){
next_psl= free_psl->t_next= psl_new(psar);
next_psl->t_prev= free_psl;
}
psar->t_first_free_psl= next_psl;
return free_psl;
}

/*:1330*//*1364:*/
#line 13388 "./marpa.w"

static void
set_error(struct marpa_g*g,Marpa_Error_Code code,const char*message,guint flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}

static void
r_error(struct marpa_r*r,Marpa_Error_Code code,const char*message,guint flags)
{
set_error(G_of_R(r),code,message,flags);
}

/*:1364*//*1370:*/
#line 13513 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*
eim_tag_safe(gchar*buffer,EIM eim)
{
if(!eim)return"NULL";
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_EIM(eim),Origin_Earleme_of_EIM(eim),
Earleme_of_EIM(eim));
return buffer;
}

static char DEBUG_eim_tag_buffer[1000];
PRIVATE_NOT_INLINE gchar*
eim_tag(EIM eim)
{
return eim_tag_safe(DEBUG_eim_tag_buffer,eim);
}
#endif

/*:1370*//*1372:*/
#line 13543 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*
lim_tag_safe(gchar*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_SYMID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}

static char DEBUG_lim_tag_buffer[1000];
PRIVATE_NOT_INLINE gchar*
lim_tag(LIM lim)
{
return lim_tag_safe(DEBUG_lim_tag_buffer,lim);
}
#endif

/*:1372*//*1374:*/
#line 13572 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*
or_tag_safe(gchar*buffer,OR or)
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
PRIVATE_NOT_INLINE const gchar*
or_tag(OR or)
{
return or_tag_safe(DEBUG_or_tag_buffer,or);
}
#endif

/*:1374*//*1376:*/
#line 13607 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*
aim_tag_safe(gchar*buffer,AIM aim)
{
if(!aim)return"NULL";
const gint aim_position= Position_of_AIM(aim);
if(aim_position>=0){
sprintf(buffer,"R%d@%d",RULEID_of_AIM(aim),Position_of_AIM(aim));
}else{
sprintf(buffer,"R%d@end",RULEID_of_AIM(aim));
}
return buffer;
}

static char DEBUG_aim_tag_buffer[1000];
PRIVATE_NOT_INLINE const gchar*
aim_tag(AIM aim)
{
return aim_tag_safe(DEBUG_aim_tag_buffer,aim);
}
#endif


/*:1376*/
#line 13689 "./marpa.w"


/*:1382*/
