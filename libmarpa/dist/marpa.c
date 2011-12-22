/*1347:*/
#line 13481 "./marpa.w"

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

/*:1347*//*1348:*/
#line 13504 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1334:*/
#line 13311 "./marpa.w"

#define MARPA_DEBUG  0 
#define MARPA_ENABLE_ASSERT  0 
#if MARPA_DEBUG
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

/*:1334*/
#line 13507 "./marpa.w"

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
#define Phase_of_R(r) ((r) ->t_phase) 
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
#define B_of_R(r) ((r) ->t_bocage) 
#define I_of_B(b) ((b) ->t_input) 
#define R_of_B(b) ((b) ->t_recce) 
#define OBS_of_B(b) ((b) ->t_obs) 
#define TREE_is_Initialized(tree) ((tree) ->t_parse_count>=0) 
#define TREE_is_Exhausted(tree) (TREE_is_Initialized(tree)  \
&&!FSTACK_IS_INITIALIZED((tree) ->t_fork_stack) ) 
#define VALUE_of_TREE(tree) (&(tree) ->t_val) 
#define Size_of_TREE(tree) FSTACK_LENGTH((tree) ->t_fork_stack) 
#define FORK_of_TREE_by_IX(tree,fork_id)  \
FSTACK_INDEX((tree) ->t_fork_stack,FORK_Object,fork_id) 
#define TREE_of_ORDER(order) (&(order) ->t_tree) 
#define OBS_of_ORDER(order) ((order) ->t_obs) 
#define ORDER_of_B(b) (&(b) ->t_order) 
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
#define VALUE_is_Active(val) ((val) ->t_active) 
#define VALUE_is_Trace(val) ((val) ->t_trace) 
#define FORK_of_VALUE(val) ((val) ->t_fork) 
#define TOS_of_VALUE(val) ((val) ->t_tos) 
#define VStack_of_VALUE(val) ((val) ->t_virtual_stack) 
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

#line 13508 "./marpa.w"

#include "marpa_obs.h"
/*1332:*/
#line 13258 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1332*/
#line 13510 "./marpa.w"

/*111:*/
#line 952 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:111*//*137:*/
#line 1130 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:137*//*432:*/
#line 3551 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:432*//*477:*/
#line 3955 "./marpa.w"
struct s_AHFA_state;
/*:477*//*564:*/
#line 5157 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:564*//*669:*/
#line 5823 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:669*//*695:*/
#line 6050 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:695*//*719:*/
#line 6348 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:719*//*722:*/
#line 6383 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:722*//*811:*/
#line 7521 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:811*//*819:*/
#line 7606 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:819*//*917:*/
#line 8752 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:917*//*952:*/
#line 9208 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:952*//*981:*/
#line 9659 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:981*//*1009:*/
#line 10087 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:1009*//*1031:*/
#line 10290 "./marpa.w"

typedef struct s_bocage*BOCAGE;
/*:1031*//*1047:*/
#line 10411 "./marpa.w"

struct s_bocage_setup_per_es;
/*:1047*//*1092:*/
#line 10841 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1092*//*1137:*/
#line 11469 "./marpa.w"

struct s_fork;
typedef struct s_fork*FORK;
/*:1137*//*1159:*/
#line 11662 "./marpa.w"

typedef struct s_value*VALUE;
/*:1159*//*1262:*/
#line 12661 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1262*//*1266:*/
#line 12696 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1266*//*1273:*/
#line 12761 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1273*//*1275:*/
#line 12776 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1275*/
#line 13511 "./marpa.w"

/*40:*/
#line 611 "./marpa.w"

typedef struct marpa_g*GRAMMAR;
typedef const struct marpa_g*GRAMMAR_Const;

/*:40*//*136:*/
#line 1128 "./marpa.w"

typedef gint SYMID;
/*:136*//*211:*/
#line 1564 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:211*//*324:*/
#line 2366 "./marpa.w"
typedef gint SYMI;
/*:324*//*489:*/
#line 4036 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:489*//*565:*/
#line 5162 "./marpa.w"
typedef gint AEX;
/*:565*//*588:*/
#line 5326 "./marpa.w"

typedef struct marpa_r*RECCE;
typedef struct marpa_input*INPUT;
/*:588*//*666:*/
#line 5814 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:666*//*668:*/
#line 5818 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:668*//*752:*/
#line 6769 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:752*//*754:*/
#line 6781 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:754*//*944:*/
#line 9144 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:944*//*980:*/
#line 9647 "./marpa.w"

typedef gint WHEID;


/*:980*//*1008:*/
#line 10083 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:1008*//*1136:*/
#line 11466 "./marpa.w"

typedef Marpa_Fork_ID FORKID;
/*:1136*//*1157:*/
#line 11640 "./marpa.w"

typedef Marpa_Event*EVE;

/*:1157*//*1177:*/
#line 11936 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1177*//*1235:*/
#line 12422 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1235*/
#line 13512 "./marpa.w"

/*35:*/
#line 550 "./marpa.w"

const guint marpa_major_version= MARPA_MAJOR_VERSION;
const guint marpa_minor_version= MARPA_MINOR_VERSION;
const guint marpa_micro_version= MARPA_MICRO_VERSION;
const guint marpa_interface_age= MARPA_INTERFACE_AGE;
const guint marpa_binary_age= MARPA_BINARY_AGE;
/*:35*//*958:*/
#line 9262 "./marpa.w"

static const gint dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:958*//*1178:*/
#line 11943 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1178*/
#line 13513 "./marpa.w"

/*1263:*/
#line 12664 "./marpa.w"

struct s_dstack{gint t_count;gint t_capacity;gpointer t_base;};
/*:1263*/
#line 13514 "./marpa.w"

/*39:*/
#line 604 "./marpa.w"
struct marpa_g{
/*128:*/
#line 1079 "./marpa.w"

gint t_is_ok;

/*:128*/
#line 605 "./marpa.w"

/*53:*/
#line 688 "./marpa.w"
GArray*t_symbols;
/*:53*//*62:*/
#line 733 "./marpa.w"
GArray*t_rules;
/*:62*//*71:*/
#line 771 "./marpa.w"
gpointer t_default_value;
/*:71*//*107:*/
#line 933 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:107*//*115:*/
#line 969 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:115*//*124:*/
#line 1049 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:124*//*130:*/
#line 1094 "./marpa.w"

const gchar*t_error_string;
/*:130*//*434:*/
#line 3568 "./marpa.w"

AIM t_AHFA_items;
AIM*t_AHFA_items_by_rule;
/*:434*//*490:*/
#line 4040 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:490*/
#line 606 "./marpa.w"

/*45:*/
#line 629 "./marpa.w"
gint ref_count;
/*:45*//*77:*/
#line 791 "./marpa.w"
Marpa_Symbol_ID t_start_symid;
/*:77*//*83:*/
#line 819 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:83*//*87:*/
#line 848 "./marpa.w"
int t_size;
/*:87*//*90:*/
#line 861 "./marpa.w"
gint t_max_rule_length;
/*:90*//*131:*/
#line 1096 "./marpa.w"

Marpa_Error_Code t_error;
/*:131*//*325:*/
#line 2368 "./marpa.w"

gint t_symbol_instance_count;
/*:325*//*435:*/
#line 3573 "./marpa.w"

guint t_aim_count;
/*:435*//*491:*/
#line 4043 "./marpa.w"
gint t_AHFA_len;
/*:491*/
#line 607 "./marpa.w"

/*94:*/
#line 869 "./marpa.w"
guint t_is_precomputed:1;
/*:94*//*97:*/
#line 881 "./marpa.w"
guint t_has_loop:1;
/*:97*//*101:*/
#line 899 "./marpa.w"
guint t_is_lhs_terminal_ok:1;
/*:101*/
#line 608 "./marpa.w"

};
typedef struct marpa_g GRAMMARD;
/*:39*//*114:*/
#line 962 "./marpa.w"

struct s_g_event{
gint t_type;
gint t_value;
};
typedef struct s_g_event GEV_Object;
/*:114*//*138:*/
#line 1137 "./marpa.w"

struct s_symbol{
/*147:*/
#line 1188 "./marpa.w"
GArray*t_lhs;
/*:147*//*154:*/
#line 1240 "./marpa.w"
GArray*t_rhs;
/*:154*//*193:*/
#line 1431 "./marpa.w"

struct s_symbol*t_alias;
/*:193*//*205:*/
#line 1527 "./marpa.w"

RULE t_virtual_lhs_rule;
/*:205*/
#line 1139 "./marpa.w"

/*145:*/
#line 1179 "./marpa.w"
SYMID t_symbol_id;
/*:145*/
#line 1140 "./marpa.w"

/*161:*/
#line 1283 "./marpa.w"
guint t_is_accessible:1;
/*:161*//*165:*/
#line 1301 "./marpa.w"
guint t_is_counted:1;
/*:165*//*169:*/
#line 1319 "./marpa.w"
guint t_is_nullable:1;
/*:169*//*173:*/
#line 1338 "./marpa.w"
guint t_is_nulling:1;
/*:173*//*177:*/
#line 1358 "./marpa.w"
guint t_is_terminal:1;
/*:177*//*183:*/
#line 1384 "./marpa.w"
guint t_is_productive:1;
/*:183*//*187:*/
#line 1402 "./marpa.w"
guint t_is_start:1;
/*:187*//*192:*/
#line 1428 "./marpa.w"

guint t_is_proper_alias:1;
guint t_is_nulling_alias:1;
/*:192*/
#line 1141 "./marpa.w"

};
typedef struct s_symbol SYM_Object;

/*:138*//*210:*/
#line 1555 "./marpa.w"

struct s_rule{
/*239:*/
#line 1970 "./marpa.w"
gint t_rhs_length;
/*:239*//*256:*/
#line 2042 "./marpa.w"
Marpa_Rule_ID t_id;
/*:256*//*301:*/
#line 2274 "./marpa.w"
gint t_virtual_start;
/*:301*//*305:*/
#line 2290 "./marpa.w"
gint t_virtual_end;
/*:305*//*310:*/
#line 2306 "./marpa.w"
Marpa_Rule_ID t_original;
/*:310*//*315:*/
#line 2325 "./marpa.w"
gint t_real_symbol_count;
/*:315*//*326:*/
#line 2379 "./marpa.w"

gint t_symbol_instance_base;
gint t_last_proper_symi;
/*:326*/
#line 1557 "./marpa.w"

/*259:*/
#line 2054 "./marpa.w"
guint t_is_discard:1;
/*:259*//*273:*/
#line 2138 "./marpa.w"
guint t_is_loop:1;
/*:273*//*278:*/
#line 2159 "./marpa.w"
guint t_is_virtual_loop:1;
/*:278*//*285:*/
#line 2195 "./marpa.w"
guint t_is_used:1;
/*:285*//*289:*/
#line 2211 "./marpa.w"
guint t_is_start:1;
/*:289*//*293:*/
#line 2242 "./marpa.w"
guint t_is_virtual_lhs:1;
/*:293*//*297:*/
#line 2257 "./marpa.w"
guint t_is_virtual_rhs:1;
/*:297*//*319:*/
#line 2338 "./marpa.w"
guint t_is_semantic_equivalent:1;
/*:319*/
#line 1558 "./marpa.w"

/*240:*/
#line 1973 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:240*/
#line 1559 "./marpa.w"

};
/*:210*//*431:*/
#line 3545 "./marpa.w"

struct s_AHFA_item{
gint t_sort_key;
/*441:*/
#line 3599 "./marpa.w"

RULE t_rule;

/*:441*/
#line 3548 "./marpa.w"

/*442:*/
#line 3605 "./marpa.w"

gint t_position;

/*:442*//*443:*/
#line 3614 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:443*//*444:*/
#line 3623 "./marpa.w"

gint t_leading_nulls;

/*:444*/
#line 3549 "./marpa.w"

};
/*:431*//*478:*/
#line 3956 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*481:*/
#line 3975 "./marpa.w"

SYMID*t_complete_symbols;

/*:481*//*483:*/
#line 3983 "./marpa.w"

AIM*t_items;
/*:483*//*498:*/
#line 4082 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:498*//*567:*/
#line 5174 "./marpa.w"

TRANS*t_transitions;
/*:567*/
#line 3963 "./marpa.w"

/*480:*/
#line 3973 "./marpa.w"

guint t_complete_symbol_count;
/*:480*//*484:*/
#line 3985 "./marpa.w"

gint t_item_count;
/*:484*//*499:*/
#line 4083 "./marpa.w"
guint t_postdot_sym_count;

/*:499*//*513:*/
#line 4214 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:513*/
#line 3964 "./marpa.w"

guint t_has_completed_start_rule:1;
/*488:*/
#line 4033 "./marpa.w"

guint t_is_predict:1;

/*:488*/
#line 3966 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:478*//*566:*/
#line 5163 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
gint t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:566*//*670:*/
#line 5829 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:670*//*671:*/
#line 5834 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
gint t_postdot_sym_count;
/*672:*/
#line 5846 "./marpa.w"

gint t_eim_count;
/*:672*//*674:*/
#line 5860 "./marpa.w"

gint t_ordinal;
/*:674*/
#line 5838 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*673:*/
#line 5849 "./marpa.w"

EIM*t_earley_items;

/*:673*//*1284:*/
#line 12852 "./marpa.w"

PSL t_dot_psl;
/*:1284*/
#line 5841 "./marpa.w"

};

/*:671*//*720:*/
#line 6352 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:720*//*723:*/
#line 6386 "./marpa.w"

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

/*:723*//*733:*/
#line 6525 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:733*//*812:*/
#line 7529 "./marpa.w"

struct s_token{
gint t_type;
SYMID t_symbol_id;
gpointer t_value;
};

/*:812*//*820:*/
#line 7616 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:820*//*918:*/
#line 8769 "./marpa.w"

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
/*:918*//*955:*/
#line 9237 "./marpa.w"

struct s_draft_or_node
{
/*954:*/
#line 9231 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:954*/
#line 9240 "./marpa.w"

DAND t_draft_and_node;
};
/*:955*//*956:*/
#line 9243 "./marpa.w"

struct s_final_or_node
{
/*954:*/
#line 9231 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:954*/
#line 9246 "./marpa.w"

gint t_first_and_node_id;
gint t_and_node_count;
};
/*:956*//*957:*/
#line 9254 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:957*//*982:*/
#line 9666 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:982*//*1010:*/
#line 10094 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:1010*//*1048:*/
#line 10413 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:1048*//*1093:*/
#line 10856 "./marpa.w"

/*1138:*/
#line 11480 "./marpa.w"

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

/*:1138*/
#line 10857 "./marpa.w"

/*1160:*/
#line 11678 "./marpa.w"

struct s_value{
DSTACK_DECLARE(t_virtual_stack);
FORKID t_fork;
gint t_tos;
guint t_trace:1;
guint t_active:1;
};

/*:1160*/
#line 10858 "./marpa.w"

struct s_tree{
FSTACK_DECLARE(t_fork_stack,FORK_Object)
FSTACK_DECLARE(t_fork_worklist,gint)
Bit_Vector t_and_node_in_use;
gint t_parse_count;
struct s_value t_val;
};
typedef struct s_tree TREE_Object;

/*:1093*//*1119:*/
#line 11219 "./marpa.w"

struct s_order{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
TREE_Object t_tree;
};

/*:1119*//*1267:*/
#line 12699 "./marpa.w"

struct s_dqueue{gint t_current;struct s_dstack t_stack;};

/*:1267*//*1274:*/
#line 12767 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
gpointer t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1274*//*1276:*/
#line 12792 "./marpa.w"

struct s_per_earley_set_arena{
gint t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1276*/
#line 13515 "./marpa.w"

/*589:*/
#line 5330 "./marpa.w"

struct marpa_input{
/*603:*/
#line 5445 "./marpa.w"

struct marpa_g*t_grammar;

/*:603*//*813:*/
#line 7557 "./marpa.w"

struct obstack t_token_obs;
TOK*t_tokens_by_symid;
/*:813*/
#line 5332 "./marpa.w"

};
struct marpa_r{
struct marpa_input t_input;
/*609:*/
#line 5483 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:609*//*622:*/
#line 5552 "./marpa.w"
gpointer*t_sym_workarea;
/*:622*//*626:*/
#line 5567 "./marpa.w"
gpointer*t_workarea2;
/*:626*//*630:*/
#line 5588 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:630*//*634:*/
#line 5614 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:634*//*655:*/
#line 5768 "./marpa.w"
struct obstack t_obs;
/*:655*//*681:*/
#line 5913 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:681*//*706:*/
#line 6192 "./marpa.w"

EIM t_trace_earley_item;
/*:706*//*739:*/
#line 6578 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:739*//*777:*/
#line 7050 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:777*//*821:*/
#line 7624 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:821*//*844:*/
#line 7923 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:844*//*848:*/
#line 7935 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:848*//*852:*/
#line 7947 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:852*//*919:*/
#line 8782 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:919*//*1033:*/
#line 10299 "./marpa.w"

Marpa_Bocage t_bocage;
/*:1033*//*1277:*/
#line 12800 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1277*/
#line 5336 "./marpa.w"

/*594:*/
#line 5379 "./marpa.w"
gint ref_count;
/*:594*//*606:*/
#line 5473 "./marpa.w"

Marpa_Phase t_phase;
/*:606*//*614:*/
#line 5512 "./marpa.w"
gint t_earley_item_warning_threshold;
/*:614*//*618:*/
#line 5535 "./marpa.w"
EARLEME t_furthest_earleme;
/*:618*//*675:*/
#line 5864 "./marpa.w"

gint t_earley_set_count;
/*:675*/
#line 5337 "./marpa.w"

/*648:*/
#line 5709 "./marpa.w"

guint t_use_leo_flag:1;
guint t_is_using_leo:1;
/*:648*//*652:*/
#line 5750 "./marpa.w"
guint t_is_exhausted:1;
/*:652*//*778:*/
#line 7053 "./marpa.w"

guint t_trace_source_type:3;
/*:778*/
#line 5338 "./marpa.w"

};

/*:589*/
#line 13516 "./marpa.w"

/*753:*/
#line 6772 "./marpa.w"

struct s_source{
gpointer t_predecessor;
union{
gpointer t_completion;
TOK t_token;
}t_cause;
};

/*:753*//*755:*/
#line 6784 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:755*//*756:*/
#line 6790 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:756*//*757:*/
#line 6797 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:757*/
#line 13517 "./marpa.w"

/*696:*/
#line 6057 "./marpa.w"

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
/*703:*/
#line 6163 "./marpa.w"

guint t_source_type:3;

/*:703*/
#line 6068 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:696*/
#line 13518 "./marpa.w"

/*1032:*/
#line 10292 "./marpa.w"

struct s_bocage{
/*959:*/
#line 9272 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:959*//*1037:*/
#line 10307 "./marpa.w"

INPUT t_input;

RECCE t_recce;
/*:1037*//*1039:*/
#line 10320 "./marpa.w"

struct obstack t_obs;
/*:1039*//*1120:*/
#line 11229 "./marpa.w"

struct s_order t_order;
/*:1120*/
#line 10294 "./marpa.w"

/*960:*/
#line 9275 "./marpa.w"

gint t_or_node_count;
gint t_and_node_count;
ORID t_top_or_node_id;

/*:960*//*1066:*/
#line 10645 "./marpa.w"
gint ref_count;
/*:1066*/
#line 10295 "./marpa.w"

/*1040:*/
#line 10322 "./marpa.w"

unsigned int is_obstack_initialized:1;
/*:1040*/
#line 10296 "./marpa.w"

};
/*:1032*/
#line 13519 "./marpa.w"

/*47:*/
#line 640 "./marpa.w"

void grammar_unref(GRAMMAR g);
/*:47*//*49:*/
#line 658 "./marpa.w"

static inline GRAMMAR grammar_ref(GRAMMAR g);
/*:49*//*52:*/
#line 679 "./marpa.w"

static inline void
grammar_free(struct marpa_g*g);

/*:52*//*61:*/
#line 726 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid);

/*:61*//*118:*/
#line 989 "./marpa.w"

static inline
void event_new(struct marpa_g*g,gint type);
/*:118*//*120:*/
#line 1001 "./marpa.w"

static inline
void int_event_new(struct marpa_g*g,gint type,gint value);
/*:120*//*139:*/
#line 1145 "./marpa.w"

static inline
SYM symbol_new(struct marpa_g*g);
/*:139*//*144:*/
#line 1174 "./marpa.w"

static inline void symbol_free(SYM symbol);

/*:144*//*153:*/
#line 1231 "./marpa.w"

void
marpa_g_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id);

/*:153*//*160:*/
#line 1279 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id);

/*:160*//*190:*/
#line 1415 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol);
/*:190*//*196:*/
#line 1456 "./marpa.w"

static inline SYM symbol_proper_alias(SYM symbol);
/*:196*//*199:*/
#line 1483 "./marpa.w"

static inline SYM symbol_null_alias(SYM symbol);
/*:199*//*202:*/
#line 1494 "./marpa.w"

static inline
SYM symbol_alias_create(GRAMMAR g,SYM symbol);
/*:202*//*214:*/
#line 1574 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length);
/*:214*//*232:*/
#line 1815 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length);
/*:232*//*244:*/
#line 1995 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
/*:244*//*248:*/
#line 2007 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule);
/*:248*//*252:*/
#line 2023 "./marpa.w"

static inline gsize rule_length_get(RULE rule);
/*:252*//*266:*/
#line 2103 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule);
/*:266*//*270:*/
#line 2127 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule);
/*:270*//*284:*/
#line 2189 "./marpa.w"

static inline gint rule_is_nulling(GRAMMAR g,RULE rule);

/*:284*//*328:*/
#line 2384 "./marpa.w"

static inline gint symbol_instance_of_ahfa_item_get(AIM aim);
/*:328*//*335:*/
#line 2507 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:335*//*372:*/
#line 2843 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:372*//*411:*/
#line 3224 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:411*//*412:*/
#line 3231 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);
/*:412*//*422:*/
#line 3373 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:422*//*440:*/
#line 3591 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id);

/*:440*//*457:*/
#line 3712 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:457*//*462:*/
#line 3787 "./marpa.w"

static gint cmp_by_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:462*//*465:*/
#line 3806 "./marpa.w"

static gint cmp_by_postdot_and_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:465*//*485:*/
#line 3989 "./marpa.w"

static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM aim_sought);
/*:485*//*497:*/
#line 4074 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id);


/*:497*//*517:*/
#line 4245 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b);
/*:517*//*520:*/
#line 4274 "./marpa.w"

PRIVATE_NOT_INLINE void create_AHFA_states(struct marpa_g*g);
/*:520*//*539:*/
#line 4747 "./marpa.w"

static inline AHFA assign_AHFA_state(
AHFA state_p,GTree*duplicates);
/*:539*//*552:*/
#line 4946 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:552*//*555:*/
#line 5003 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
);
/*:555*//*568:*/
#line 5176 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition);
/*:568*//*570:*/
#line 5183 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition);
/*:570*//*572:*/
#line 5191 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix);
/*:572*//*574:*/
#line 5204 "./marpa.w"
static inline
TRANS*transitions_new(struct marpa_g*g);
/*:574*//*576:*/
#line 5218 "./marpa.w"

static inline
void transition_add(struct obstack*obstack,AHFA from_ahfa,SYMID symid,AHFA to_ahfa);
/*:576*//*578:*/
#line 5235 "./marpa.w"

static inline
void completion_count_inc(struct obstack*obstack,AHFA from_ahfa,SYMID symid);
/*:578*//*596:*/
#line 5384 "./marpa.w"

static inline void r_unref(RECCE r);
/*:596*//*598:*/
#line 5404 "./marpa.w"

static inline RECCE r_ref(RECCE r);
/*:598*//*601:*/
#line 5433 "./marpa.w"

static inline
void r_free(struct marpa_r*r);

/*:601*//*612:*/
#line 5500 "./marpa.w"

static inline ES current_es_of_r(RECCE r);
/*:612*//*677:*/
#line 5870 "./marpa.w"

static inline ES earley_set_new(RECCE r,EARLEME id);
/*:677*//*697:*/
#line 6078 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key);
/*:697*//*699:*/
#line 6101 "./marpa.w"

static inline
EIM earley_item_assign(const RECCE r,const ES set,const ES origin,const AHFA state);
/*:699*//*704:*/
#line 6166 "./marpa.w"

static const char*invalid_source_type_message(guint type);
/*:704*//*716:*/
#line 6314 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r);
/*:716*//*735:*/
#line 6541 "./marpa.w"

static inline PIM*pim_sym_p_find(ES set,SYMID symid);
/*:735*//*737:*/
#line 6563 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid);
/*:737*//*761:*/
#line 6833 "./marpa.w"
static inline void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
TOK token);
/*:761*//*763:*/
#line 6865 "./marpa.w"
static inline void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause);
/*:763*//*770:*/
#line 6972 "./marpa.w"
static inline void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause);

/*:770*//*773:*/
#line 7013 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item);

/*:773*//*797:*/
#line 7302 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r);
/*:797*//*816:*/
#line 7583 "./marpa.w"

static inline
TOK token_new(struct marpa_r*r,SYMID symbol_id,gpointer value);
/*:816*//*824:*/
#line 7639 "./marpa.w"

static inline gint alternative_insertion_point(RECCE r,ALT new_alternative);
/*:824*//*826:*/
#line 7680 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b);
/*:826*//*828:*/
#line 7704 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme);
/*:828*//*830:*/
#line 7721 "./marpa.w"

static inline gint alternative_insert(RECCE r,ALT alternative);
/*:830*//*869:*/
#line 8174 "./marpa.w"

static inline void earley_set_update_items(RECCE r,ES set);
/*:869*//*871:*/
#line 8198 "./marpa.w"

static inline void r_update_earley_sets(RECCE r);
/*:871*//*874:*/
#line 8224 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES set);
/*:874*//*922:*/
#line 8793 "./marpa.w"

static inline void ur_node_stack_init(URS stack);
/*:922*//*924:*/
#line 8803 "./marpa.w"

static inline void ur_node_stack_reset(URS stack);
/*:924*//*926:*/
#line 8810 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack);
/*:926*//*928:*/
#line 8820 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev);
/*:928*//*930:*/
#line 8831 "./marpa.w"

static inline void ur_node_push(URS stack,EIM earley_item,AEX aex);
/*:930*//*932:*/
#line 8849 "./marpa.w"

static inline UR ur_node_pop(URS stack);
/*:932*//*937:*/
#line 8914 "./marpa.w"

static inline gint psia_test_and_set(
struct obstack*obs,
struct s_bocage_setup_per_es*per_es_data,
EIM earley_item,
AEX ahfa_element_ix);
/*:937*//*974:*/
#line 9539 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base);
/*:974*//*976:*/
#line 9553 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item);
/*:976*//*983:*/
#line 9674 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause);
/*:983*//*986:*/
#line 9700 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause);
/*:986*//*1027:*/
#line 10267 "./marpa.w"

static inline SYMID and_node_token(AND and_node,gpointer*value_p);
/*:1027*//*1053:*/
#line 10484 "./marpa.w"

PRIVATE_NOT_INLINE BOCAGE r_create_null_bocage(RECCE r,BOCAGE b);
/*:1053*//*1068:*/
#line 10650 "./marpa.w"

static inline void b_unref(BOCAGE b);
/*:1068*//*1070:*/
#line 10670 "./marpa.w"

static inline BOCAGE b_ref(BOCAGE b);
/*:1070*//*1073:*/
#line 10694 "./marpa.w"

void
b_free(BOCAGE b);
/*:1073*//*1094:*/
#line 10868 "./marpa.w"

static inline void tree_exhaust(TREE tree);
/*:1094*//*1096:*/
#line 10889 "./marpa.w"

static inline void tree_safe(TREE tree);
/*:1096*//*1100:*/
#line 10948 "./marpa.w"

static inline void tree_and_node_claim(TREE tree,ANDID and_node_id);
static inline void tree_and_node_release(TREE tree,ANDID and_node_id);
static inline gint tree_and_node_try(TREE tree,ANDID and_node_id);
/*:1100*//*1107:*/
#line 11103 "./marpa.w"

static inline gint or_node_next_choice(BOCAGE b,TREE tree,OR or_node,gint start_choice);
/*:1107*//*1111:*/
#line 11145 "./marpa.w"

static inline void tree_destroy(TREE tree);
/*:1111*//*1122:*/
#line 11234 "./marpa.w"

static inline void order_safe(ORDER order);
/*:1122*//*1125:*/
#line 11246 "./marpa.w"

static inline void order_freeze(ORDER order);
static inline void order_destroy(ORDER order);
/*:1125*//*1133:*/
#line 11406 "./marpa.w"

static inline ANDID and_order_get(BOCAGE b,OR or_node,gint ix);
/*:1133*//*1161:*/
#line 11687 "./marpa.w"

static inline void val_safe(VALUE val);
/*:1161*//*1167:*/
#line 11770 "./marpa.w"

static inline void val_destroy(VALUE val);
/*:1167*//*1180:*/
#line 11956 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:1180*//*1182:*/
#line 11966 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:1182*//*1183:*/
#line 11970 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);
/*:1183*//*1185:*/
#line 11990 "./marpa.w"

static inline Bit_Vector bv_obs_create(struct obstack*obs,guint bits);
/*:1185*//*1188:*/
#line 12023 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:1188*//*1190:*/
#line 12042 "./marpa.w"

static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from);

/*:1190*//*1192:*/
#line 12055 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:1192*//*1194:*/
#line 12065 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:1194*//*1196:*/
#line 12073 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:1196*//*1198:*/
#line 12086 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:1198*//*1200:*/
#line 12090 "./marpa.w"

static inline void bv_clear(Bit_Vector bv);
/*:1200*//*1202:*/
#line 12106 "./marpa.w"

static inline void bv_over_clear(Bit_Vector bv,guint bit);
/*:1202*//*1206:*/
#line 12120 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:1206*//*1208:*/
#line 12128 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:1208*//*1210:*/
#line 12136 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:1210*//*1212:*/
#line 12141 "./marpa.w"

static inline gboolean bv_bit_test_and_set(Bit_Vector vector,guint bit);
/*:1212*//*1215:*/
#line 12168 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:1215*//*1217:*/
#line 12181 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:1217*//*1219:*/
#line 12193 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1219*//*1221:*/
#line 12205 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1221*//*1223:*/
#line 12217 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:1223*//*1225:*/
#line 12291 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:1225*//*1227:*/
#line 12309 "./marpa.w"

static inline guint bv_count(Bit_Vector v);

/*:1227*//*1233:*/
#line 12398 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:1233*//*1238:*/
#line 12446 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:1238*//*1240:*/
#line 12454 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:1240*//*1242:*/
#line 12468 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:1242*//*1244:*/
#line 12486 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:1244*//*1247:*/
#line 12495 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:1247*//*1250:*/
#line 12504 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:1250*//*1253:*/
#line 12513 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:1253*//*1255:*/
#line 12566 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:1255*//*1265:*/
#line 12672 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_size);

/*:1265*//*1280:*/
#line 12806 "./marpa.w"

static inline void psar_init(const PSAR psar,gint length);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
/*:1280*//*1286:*/
#line 12864 "./marpa.w"

static inline void psar_reset(const PSAR psar);
/*:1286*//*1288:*/
#line 12883 "./marpa.w"

static inline void psar_dealloc(const PSAR psar);
/*:1288*//*1290:*/
#line 12904 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar);
/*:1290*//*1294:*/
#line 12930 "./marpa.w"

static inline PSL psl_alloc(const PSAR psar);
/*:1294*//*1329:*/
#line 13216 "./marpa.w"

static void set_error(struct marpa_g*g,Marpa_Error_Code code,
const char*message,guint flags);
static void r_error(struct marpa_r*r,Marpa_Error_Code code,
const char*message,guint flags);
/*:1329*//*1335:*/
#line 13340 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*eim_tag_safe(gchar*buffer,EIM eim);
PRIVATE_NOT_INLINE gchar*eim_tag(EIM eim);
#endif
/*:1335*//*1337:*/
#line 13369 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*lim_tag_safe(gchar*buffer,LIM lim);
PRIVATE_NOT_INLINE gchar*lim_tag(LIM lim);
#endif
/*:1337*//*1339:*/
#line 13399 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*or_tag_safe(gchar*buffer,OR or);
PRIVATE_NOT_INLINE const gchar*or_tag(OR or);
#endif
/*:1339*//*1341:*/
#line 13435 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*aim_tag_safe(gchar*buffer,AIM aim);
PRIVATE_NOT_INLINE const gchar*aim_tag(AIM aim);
#endif
/*:1341*/
#line 13520 "./marpa.w"

/*59:*/
#line 710 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symid,
SYM symbol)
{
g_array_insert_val(g->t_symbols,(unsigned)symid,symbol);
}

/*:59*//*69:*/
#line 753 "./marpa.w"

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
#line 13521 "./marpa.w"

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

g->ref_count= 1;

/*:46*//*54:*/
#line 689 "./marpa.w"

g->t_symbols= g_array_new(FALSE,FALSE,sizeof(SYM));
/*:54*//*63:*/
#line 734 "./marpa.w"

g->t_rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:63*//*72:*/
#line 772 "./marpa.w"

Default_Value_of_G(g)= NULL;
/*:72*//*78:*/
#line 792 "./marpa.w"

g->t_start_symid= -1;
/*:78*//*84:*/
#line 822 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;
/*:84*//*88:*/
#line 849 "./marpa.w"

Size_of_G(g)= 0;

/*:88*//*91:*/
#line 862 "./marpa.w"

g->t_max_rule_length= 0;

/*:91*//*95:*/
#line 870 "./marpa.w"

g->t_is_precomputed= FALSE;
/*:95*//*98:*/
#line 882 "./marpa.w"

g->t_has_loop= FALSE;
/*:98*//*102:*/
#line 900 "./marpa.w"

g->t_is_lhs_terminal_ok= TRUE;
/*:102*//*108:*/
#line 934 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:108*//*116:*/
#line 977 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:116*//*125:*/
#line 1052 "./marpa.w"

obstack_init(&g->t_obs);
obstack_init(&g->t_obs_tricky);
/*:125*//*132:*/
#line 1098 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:132*//*437:*/
#line 3578 "./marpa.w"

g->t_AHFA_items= NULL;
g->t_AHFA_items_by_rule= NULL;
/*:437*//*492:*/
#line 4044 "./marpa.w"

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
MARPA_ASSERT(g->ref_count> 0)
g->ref_count--;
if(g->ref_count<=0)
{
grammar_free(g);
}
}
void
marpa_g_unref(Marpa_Grammar g)
{grammar_unref(g);}

/*:48*//*50:*/
#line 660 "./marpa.w"

static inline GRAMMAR
grammar_ref(GRAMMAR g)
{
MARPA_ASSERT(g->ref_count> 0)
g->ref_count++;
return g;
}
Marpa_Grammar
marpa_g_ref(Marpa_Grammar g)
{return grammar_ref(g);}

/*:50*//*51:*/
#line 672 "./marpa.w"

void grammar_free(struct marpa_g*g)
{
MARPA_DEBUG3("%s: Destroying grammar %p",G_STRLOC,g);
/*55:*/
#line 691 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->t_symbols->len;id++)
{symbol_free(SYM_by_ID(id));}}
g_array_free(g->t_symbols,TRUE);

/*:55*//*64:*/
#line 736 "./marpa.w"

g_array_free(g->t_rules,TRUE);

/*:64*//*109:*/
#line 935 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:109*//*117:*/
#line 979 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:117*//*126:*/
#line 1055 "./marpa.w"

obstack_free(&g->t_obs,NULL);
obstack_free(&g->t_obs_tricky,NULL);

/*:126*//*438:*/
#line 3581 "./marpa.w"

if(g->t_AHFA_items){g_free(g->t_AHFA_items);};
if(g->t_AHFA_items_by_rule){g_free(g->t_AHFA_items_by_rule);};

/*:438*//*493:*/
#line 4048 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*494:*/
#line 4058 "./marpa.w"
{
TRANS*ahfa_transitions= TRANSs_of_AHFA(ahfa_state);
if(ahfa_transitions)
g_free(TRANSs_of_AHFA(ahfa_state));
}

/*:494*/
#line 4052 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:493*/
#line 676 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:51*//*57:*/
#line 700 "./marpa.w"

gint marpa_g_symbol_count(struct marpa_g*g){
return SYM_Count_of_G(g);
}

/*:57*//*60:*/
#line 721 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid){
return symid>=0&&(guint)symid<g->t_symbols->len;
}
/*:60*//*67:*/
#line 743 "./marpa.w"

gint marpa_g_rule_count(struct marpa_g*g){
return RULE_Count_of_G(g);
}

/*:67*//*74:*/
#line 776 "./marpa.w"

gpointer marpa_g_default_value(struct marpa_g*g)
{return Default_Value_of_G(g);}
/*:74*//*76:*/
#line 781 "./marpa.w"

gboolean marpa_g_default_value_set(struct marpa_g*g,gpointer default_value)
{
/*1309:*/
#line 13080 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1309*/
#line 784 "./marpa.w"

/*1312:*/
#line 13090 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1312*/
#line 785 "./marpa.w"

Default_Value_of_G(g)= default_value;
return TRUE;
}

/*:76*//*79:*/
#line 794 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(struct marpa_g*g)
{return g->t_start_symid;}
/*:79*//*81:*/
#line 801 "./marpa.w"

gboolean marpa_g_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1309:*/
#line 13080 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1309*/
#line 804 "./marpa.w"

/*1312:*/
#line 13090 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1312*/
#line 805 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 806 "./marpa.w"

g->t_start_symid= symid;
return TRUE;
}
/*:81*//*96:*/
#line 872 "./marpa.w"

gboolean marpa_g_is_precomputed(struct marpa_g*g)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 875 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 876 "./marpa.w"

return G_is_Precomputed(g);
}

/*:96*//*100:*/
#line 886 "./marpa.w"

gboolean marpa_g_has_loop(struct marpa_g*g)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 889 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 890 "./marpa.w"

return g->t_has_loop;
}

/*:100*//*103:*/
#line 903 "./marpa.w"

gboolean marpa_g_is_lhs_terminal_ok(struct marpa_g*g)
{return g->t_is_lhs_terminal_ok;}
/*:103*//*105:*/
#line 910 "./marpa.w"

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
#line 992 "./marpa.w"

static inline
void event_new(struct marpa_g*g,gint type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:119*//*121:*/
#line 1004 "./marpa.w"

void int_event_new(struct marpa_g*g,gint type,gint value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:121*//*123:*/
#line 1015 "./marpa.w"

gint
marpa_g_event(struct marpa_g*g,struct marpa_g_event*public_event,
gint ix)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1020 "./marpa.w"

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
#line 1109 "./marpa.w"

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
#line 1148 "./marpa.w"

static inline SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= g_malloc(sizeof(SYM_Object));
/*146:*/
#line 1180 "./marpa.w"
ID_of_SYM(symbol)= g->t_symbols->len;

/*:146*//*148:*/
#line 1189 "./marpa.w"

symbol->t_lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:148*//*155:*/
#line 1241 "./marpa.w"

symbol->t_rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:155*//*162:*/
#line 1284 "./marpa.w"

symbol->t_is_accessible= FALSE;
/*:162*//*166:*/
#line 1302 "./marpa.w"

symbol->t_is_counted= FALSE;
/*:166*//*170:*/
#line 1320 "./marpa.w"

symbol->t_is_nullable= FALSE;
/*:170*//*174:*/
#line 1339 "./marpa.w"

symbol->t_is_nulling= FALSE;
/*:174*//*178:*/
#line 1359 "./marpa.w"

symbol->t_is_terminal= FALSE;
/*:178*//*184:*/
#line 1385 "./marpa.w"

symbol->t_is_productive= FALSE;
/*:184*//*188:*/
#line 1403 "./marpa.w"
symbol->t_is_start= FALSE;
/*:188*//*194:*/
#line 1433 "./marpa.w"

symbol->t_is_proper_alias= FALSE;
symbol->t_is_nulling_alias= FALSE;
symbol->t_alias= NULL;

/*:194*//*206:*/
#line 1529 "./marpa.w"

symbol->t_virtual_lhs_rule= NULL;

/*:206*/
#line 1153 "./marpa.w"

{
SYMID id= ID_of_SYM(symbol);
g_symbol_add(g,id,symbol);
}
return symbol;
}

/*:140*//*142:*/
#line 1163 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(struct marpa_g*g)
{
SYMID id= ID_of_SYM(symbol_new(g));
return id;
}

/*:142*//*143:*/
#line 1171 "./marpa.w"

static inline void symbol_free(SYM symbol)
{/*149:*/
#line 1191 "./marpa.w"

g_array_free(symbol->t_lhs,TRUE);

/*:149*//*156:*/
#line 1243 "./marpa.w"
g_array_free(symbol->t_rhs,TRUE);

/*:156*/
#line 1173 "./marpa.w"
g_free(symbol);}
/*:143*//*151:*/
#line 1197 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_lhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1200 "./marpa.w"

GArray*symbol_lh_rules;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 1202 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1203 "./marpa.w"

symbol_lh_rules= SYM_by_ID(symid)->t_lhs;
return symbol_lh_rules->len;
}
Marpa_Rule_ID marpa_g_symbol_lhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1209 "./marpa.w"

GArray*symbol_lh_rules;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 1211 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1212 "./marpa.w"

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
#line 1225 "./marpa.w"
static inline
void symbol_lhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_lhs,rule_id);}
void
marpa_g_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id)
{symbol_lhs_add(SYM_by_ID(symid),rule_id);}
/*:152*//*158:*/
#line 1248 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_rhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1251 "./marpa.w"

GArray*symbol_rh_rules;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 1253 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1254 "./marpa.w"

symbol_rh_rules= SYM_by_ID(symid)->t_rhs;
return symbol_rh_rules->len;
}
Marpa_Rule_ID marpa_g_symbol_rhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1260 "./marpa.w"

GArray*symbol_rh_rules;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 1262 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1263 "./marpa.w"

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
#line 1276 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_rhs,rule_id);}
/*:159*//*163:*/
#line 1294 "./marpa.w"

gboolean marpa_g_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_accessible;}
/*:163*//*167:*/
#line 1312 "./marpa.w"

gboolean marpa_g_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_counted;}
/*:167*//*171:*/
#line 1330 "./marpa.w"

gboolean marpa_g_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_nullable;}
/*:171*//*175:*/
#line 1349 "./marpa.w"

gint marpa_g_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1351 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1352 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));}
/*:175*//*179:*/
#line 1371 "./marpa.w"

gboolean marpa_g_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYMID_is_Terminal(id);}
/*:179*//*181:*/
#line 1376 "./marpa.w"

void marpa_g_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYMID_is_Terminal(id)= value;}
/*:181*//*185:*/
#line 1395 "./marpa.w"

gboolean marpa_g_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_productive;}
/*:185*//*189:*/
#line 1406 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol)
{return symbol->t_is_start;}
gint marpa_g_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1411 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1412 "./marpa.w"

return symbol_is_start(SYM_by_ID(symid));
}
/*:189*//*195:*/
#line 1442 "./marpa.w"

static inline
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1450 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1451 "./marpa.w"

symbol= SYM_by_ID(symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}
/*:195*//*198:*/
#line 1465 "./marpa.w"

static inline
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1473 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1474 "./marpa.w"

symbol= SYM_by_ID(symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
MARPA_DEV_ERROR("no alias");
return-1;
}
return ID_of_SYM(alias);
}
/*:198*//*203:*/
#line 1497 "./marpa.w"
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
#line 1539 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_virtual_lhs_rule(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
RULE virtual_lhs_rule;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1544 "./marpa.w"

/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1545 "./marpa.w"

symbol= SYM_by_ID(symid);
virtual_lhs_rule= symbol->t_virtual_lhs_rule;
return virtual_lhs_rule==NULL?-1:ID_of_RULE(virtual_lhs_rule);
}

/*:208*//*215:*/
#line 1580 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length)
{
/*1310:*/
#line 13082 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1310*/
#line 1585 "./marpa.w"

RULE rule;
const gint rule_sizeof= G_STRUCT_OFFSET(struct s_rule,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
/*241:*/
#line 1975 "./marpa.w"

{
SYMID symid= lhs;
/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1978 "./marpa.w"

}
{gint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1314:*/
#line 13100 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1314*/
#line 1983 "./marpa.w"

}
}

/*:241*/
#line 1589 "./marpa.w"

rule= obstack_alloc(&g->t_obs,rule_sizeof);
/*242:*/
#line 1987 "./marpa.w"

Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
{gint i;for(i= 0;i<length;i++){
rule->t_symbols[i+1]= rhs[i];}}
/*:242*/
#line 1591 "./marpa.w"

/*257:*/
#line 2043 "./marpa.w"
rule->t_id= g->t_rules->len;

/*:257*//*260:*/
#line 2055 "./marpa.w"

rule->t_is_discard= FALSE;
/*:260*//*274:*/
#line 2139 "./marpa.w"

rule->t_is_loop= FALSE;
/*:274*//*279:*/
#line 2160 "./marpa.w"

rule->t_is_virtual_loop= FALSE;
/*:279*//*286:*/
#line 2196 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:286*//*290:*/
#line 2212 "./marpa.w"

rule->t_is_start= FALSE;
/*:290*//*294:*/
#line 2243 "./marpa.w"

RULE_is_Virtual_LHS(rule)= FALSE;
/*:294*//*298:*/
#line 2258 "./marpa.w"

RULE_is_Virtual_RHS(rule)= FALSE;
/*:298*//*302:*/
#line 2275 "./marpa.w"
rule->t_virtual_start= -1;
/*:302*//*306:*/
#line 2291 "./marpa.w"
rule->t_virtual_end= -1;
/*:306*//*311:*/
#line 2307 "./marpa.w"
rule->t_original= -1;
/*:311*//*316:*/
#line 2326 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:316*//*320:*/
#line 2339 "./marpa.w"

rule->t_is_semantic_equivalent= FALSE;
/*:320*//*327:*/
#line 2382 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:327*/
#line 1592 "./marpa.w"

rule_add(g,rule->t_id,rule);
/*234:*/
#line 1853 "./marpa.w"

symbol_lhs_add(SYM_by_ID(rule->t_symbols[0]),rule->t_id);
if(Length_of_RULE(rule)> 0){
gint rh_list_ix;
const guint alloc_size= Length_of_RULE(rule)*sizeof(SYMID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*238:*/
#line 1920 "./marpa.w"

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
#line 1861 "./marpa.w"

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
#line 1594 "./marpa.w"

return rule;
}

/*:215*//*217:*/
#line 1601 "./marpa.w"

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
#line 1625 "./marpa.w"

gint marpa_g_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags)
{
RULE original_rule;
RULEID original_rule_id;
SYM internal_lhs;
SYMID internal_lhs_id,*temp_rhs;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1634 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 1635 "./marpa.w"

/*1312:*/
#line 13090 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1312*/
#line 1636 "./marpa.w"

if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE)
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
return failure_indicator;
}
G_EVENTS_CLEAR(g);

/*220:*/
#line 1662 "./marpa.w"

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
#line 1644 "./marpa.w"

/*221:*/
#line 1677 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
MARPA_DEV_ERROR("bad separator");
return failure_indicator;
}

/*:221*/
#line 1645 "./marpa.w"

/*222:*/
#line 1683 "./marpa.w"

SYM_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(separator_id)->t_is_counted= 1;}
/*:222*/
#line 1646 "./marpa.w"

if(min==0){/*223:*/
#line 1686 "./marpa.w"

{
RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1319:*/
#line 13125 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1319*/
#line 1689 "./marpa.w"
}
rule->t_is_semantic_equivalent= TRUE;
rule->t_original= original_rule_id;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}
/*:223*/
#line 1647 "./marpa.w"
}
min= 1;
/*224:*/
#line 1694 "./marpa.w"

{
internal_lhs= symbol_new(g);
internal_lhs_id= ID_of_SYM(internal_lhs);
int_event_new(g,MARPA_G_EV_NEW_SYMBOL,internal_lhs_id);
}

/*:224*/
#line 1649 "./marpa.w"

/*225:*/
#line 1712 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:225*/
#line 1650 "./marpa.w"

/*227:*/
#line 1715 "./marpa.w"

{
RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1319:*/
#line 13125 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1319*/
#line 1720 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;

RULE_is_Virtual_RHS(rule)= TRUE;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}

/*:227*/
#line 1651 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*228:*/
#line 1729 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1319:*/
#line 13125 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1319*/
#line 1734 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;
RULE_is_Virtual_RHS(rule)= TRUE;
Real_SYM_Count_of_RULE(rule)= 1;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}
/*:228*/
#line 1653 "./marpa.w"

}
/*229:*/
#line 1744 "./marpa.w"

{RULE rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1319:*/
#line 13125 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1319*/
#line 1754 "./marpa.w"
}
RULE_is_Virtual_LHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}
/*:229*/
#line 1655 "./marpa.w"

/*230:*/
#line 1759 "./marpa.w"

{RULE rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1319:*/
#line 13125 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1319*/
#line 1766 "./marpa.w"
}
RULE_is_Virtual_LHS(rule)= 1;
RULE_is_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix-1;
int_event_new(g,MARPA_G_EV_NEW_RULE,rule->t_id);
}

/*:230*/
#line 1656 "./marpa.w"

/*226:*/
#line 1714 "./marpa.w"
g_free(temp_rhs);
/*:226*/
#line 1657 "./marpa.w"

return G_EVENT_COUNT(g);
}

/*:219*//*233:*/
#line 1819 "./marpa.w"

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
#line 1992 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule){
return rule->t_symbols[0];}
/*:243*//*245:*/
#line 1997 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 1999 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2000 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));}
/*:245*//*247:*/
#line 2004 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule){
return rule->t_symbols+1;}
/*:247*//*250:*/
#line 2011 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix){
RULE rule;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2014 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2015 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:250*//*251:*/
#line 2020 "./marpa.w"

static inline gsize rule_length_get(RULE rule){
return Length_of_RULE(rule);}
/*:251*//*253:*/
#line 2025 "./marpa.w"

gint marpa_g_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2027 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2028 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}
/*:253*//*261:*/
#line 2057 "./marpa.w"

gboolean marpa_g_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_discard;}
/*:261*//*265:*/
#line 2090 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(lhs_id)->t_is_accessible;}
gint marpa_g_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2097 "./marpa.w"

RULE rule;
/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2099 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:265*//*269:*/
#line 2110 "./marpa.w"

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
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2121 "./marpa.w"

RULE rule;
/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2123 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}
/*:269*//*275:*/
#line 2143 "./marpa.w"

gint marpa_g_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2146 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2147 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}
/*:275*//*280:*/
#line 2164 "./marpa.w"

gint marpa_g_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2167 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2168 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;}
/*:280*//*283:*/
#line 2176 "./marpa.w"

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
#line 2200 "./marpa.w"

gint marpa_g_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2203 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2204 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}
/*:287*//*291:*/
#line 2216 "./marpa.w"

gint marpa_g_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2219 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2220 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_start;}
/*:291*//*295:*/
#line 2246 "./marpa.w"

gboolean marpa_g_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2249 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2250 "./marpa.w"

return RULE_is_Virtual_LHS(RULE_by_ID(g,rule_id));}
/*:295*//*299:*/
#line 2261 "./marpa.w"

gboolean marpa_g_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2264 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2265 "./marpa.w"

return RULE_is_Virtual_RHS(RULE_by_ID(g,rule_id));}
/*:299*//*303:*/
#line 2276 "./marpa.w"

guint marpa_g_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2279 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2280 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}
/*:303*//*307:*/
#line 2292 "./marpa.w"

guint marpa_g_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2295 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2296 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}
/*:307*//*312:*/
#line 2308 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2311 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2312 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_original;
}
/*:312*//*318:*/
#line 2329 "./marpa.w"

gint marpa_g_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2332 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2333 "./marpa.w"

return Real_SYM_Count_of_RULE(RULE_by_ID(g,rule_id));
}

/*:318*//*323:*/
#line 2352 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2357 "./marpa.w"

/*1315:*/
#line 13105 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1315*/
#line 2358 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(RULE_is_Virtual_LHS(rule))return-1;
if(rule->t_is_semantic_equivalent)return rule->t_original;
return rule_id;
}

/*:323*//*330:*/
#line 2398 "./marpa.w"

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
#line 2424 "./marpa.w"

gint marpa_g_precompute(struct marpa_g*g)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 2427 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 2428 "./marpa.w"

G_EVENTS_CLEAR(g);
if(!census(g))return failure_indicator;
if(!CHAF_rewrite(g))return failure_indicator;
if(!g_augment(g))return failure_indicator;
if(!G_is_Trivial(g)){
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*586:*/
#line 5310 "./marpa.w"
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
#line 2437 "./marpa.w"

}
return G_EVENT_COUNT(g);
}
/*:331*//*334:*/
#line 2476 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*1310:*/
#line 13082 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1310*/
#line 2479 "./marpa.w"

/*336:*/
#line 2509 "./marpa.w"

guint pre_rewrite_rule_count= g->t_rules->len;
guint pre_rewrite_symbol_count= g->t_symbols->len;

/*:336*//*341:*/
#line 2543 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_start_symid;
SYM original_start_symbol;

/*:341*//*345:*/
#line 2582 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:345*//*351:*/
#line 2633 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:351*//*353:*/
#line 2657 "./marpa.w"

Bit_Vector nullable_v;
/*:353*//*357:*/
#line 2682 "./marpa.w"

Bit_Vector productive_v;
/*:357*//*360:*/
#line 2723 "./marpa.w"
Bit_Matrix reach_matrix;
/*:360*//*363:*/
#line 2741 "./marpa.w"

Bit_Vector accessible_v;

/*:363*/
#line 2480 "./marpa.w"

/*337:*/
#line 2513 "./marpa.w"

if(g->t_rules->len<=0){MARPA_ERROR(MARPA_ERR_NO_RULES);return NULL;}
/*:337*/
#line 2481 "./marpa.w"

/*338:*/
#line 2520 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return NULL;}
/*:338*/
#line 2482 "./marpa.w"

/*340:*/
#line 2528 "./marpa.w"

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
#line 2483 "./marpa.w"

/*342:*/
#line 2547 "./marpa.w"

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
#line 2484 "./marpa.w"

/*343:*/
#line 2566 "./marpa.w"

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
#line 2485 "./marpa.w"

if(have_marked_terminals){
/*347:*/
#line 2600 "./marpa.w"

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
#line 2487 "./marpa.w"

}else{
/*346:*/
#line 2586 "./marpa.w"

if(have_empty_rule&&g->t_is_lhs_terminal_ok){
MARPA_ERROR(MARPA_ERR_NULL_RULE_UNMARKED_TERMINALS);
return NULL;
}
/*:346*/
#line 2489 "./marpa.w"
;
if(g->t_is_lhs_terminal_ok){
/*348:*/
#line 2613 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->t_symbols->len;symid++)
{SYMID_is_Terminal(symid)= 1;}}
/*:348*/
#line 2491 "./marpa.w"

}else{
/*349:*/
#line 2618 "./marpa.w"

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
#line 2493 "./marpa.w"

}
}
/*352:*/
#line 2638 "./marpa.w"

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
#line 2496 "./marpa.w"

/*355:*/
#line 2662 "./marpa.w"

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
#line 2497 "./marpa.w"

/*356:*/
#line 2676 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->t_start_symid))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
return NULL;
}
/*:356*/
#line 2498 "./marpa.w"

/*359:*/
#line 2705 "./marpa.w"

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
#line 2499 "./marpa.w"

/*362:*/
#line 2727 "./marpa.w"

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
#line 2500 "./marpa.w"

/*364:*/
#line 2746 "./marpa.w"

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
#line 2501 "./marpa.w"

/*344:*/
#line 2578 "./marpa.w"

bv_free(terminal_v);
/*:344*//*350:*/
#line 2630 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:350*//*354:*/
#line 2659 "./marpa.w"

bv_free(nullable_v);

/*:354*//*358:*/
#line 2684 "./marpa.w"

bv_free(productive_v);

/*:358*/
#line 2502 "./marpa.w"

/*361:*/
#line 2724 "./marpa.w"

matrix_free(reach_matrix);

/*:361*/
#line 2503 "./marpa.w"

g->t_is_precomputed= TRUE;
return g;
}
/*:334*//*371:*/
#line 2822 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*373:*/
#line 2845 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:373*//*377:*/
#line 2895 "./marpa.w"

gint factor_count;
gint*factor_positions;
/*:377*//*382:*/
#line 2945 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:382*/
#line 2825 "./marpa.w"

/*378:*/
#line 2898 "./marpa.w"

factor_positions= g_new(gint,g->t_max_rule_length);
/*:378*//*383:*/
#line 2948 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:383*/
#line 2826 "./marpa.w"

/*375:*/
#line 2857 "./marpa.w"

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
#line 2827 "./marpa.w"

no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const gint rule_length= Length_of_RULE(rule);
gint nullable_suffix_ix= 0;
/*374:*/
#line 2849 "./marpa.w"

if(!RULE_is_Used(rule)){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}

/*:374*/
#line 2833 "./marpa.w"

/*376:*/
#line 2879 "./marpa.w"

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
#line 2834 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*380:*/
#line 2904 "./marpa.w"

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
#line 2958 "./marpa.w"

SYMID chaf_virtual_symid;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*381:*/
#line 2928 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:381*/
#line 2966 "./marpa.w"

/*387:*/
#line 2985 "./marpa.w"

{
gint remaining_rhs_length,piece_rhs_length;
/*388:*/
#line 2997 "./marpa.w"

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
#line 3199 "./marpa.w"

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
#line 3012 "./marpa.w"

}

/*:388*/
#line 2988 "./marpa.w"
;
/*389:*/
#line 3015 "./marpa.w"

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
#line 3199 "./marpa.w"

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
#line 3033 "./marpa.w"

}

/*:389*/
#line 2989 "./marpa.w"
;
/*390:*/
#line 3038 "./marpa.w"
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
#line 3199 "./marpa.w"

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
#line 3048 "./marpa.w"

}

/*:390*/
#line 2990 "./marpa.w"
;
/*391:*/
#line 3057 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3062 "./marpa.w"

}

/*:391*/
#line 2991 "./marpa.w"
;
}

/*:387*/
#line 2967 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*381:*/
#line 2928 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:381*/
#line 2972 "./marpa.w"

/*393:*/
#line 3067 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
gint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:393*//*394:*/
#line 3076 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3082 "./marpa.w"


/*:394*//*395:*/
#line 3085 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3090 "./marpa.w"


/*:395*//*396:*/
#line 3093 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3099 "./marpa.w"


/*:396*//*397:*/
#line 3102 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3105 "./marpa.w"


/*:397*//*398:*/
#line 3108 "./marpa.w"
}

/*:398*/
#line 2973 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:386*/
#line 2919 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*399:*/
#line 3112 "./marpa.w"
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
#line 3126 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3131 "./marpa.w"


/*:400*//*401:*/
#line 3134 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3139 "./marpa.w"


/*:401*//*402:*/
#line 3142 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3148 "./marpa.w"


/*:402*//*403:*/
#line 3152 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3156 "./marpa.w"

}

/*:403*//*404:*/
#line 3160 "./marpa.w"
}

/*:404*/
#line 2922 "./marpa.w"

}else{
/*405:*/
#line 3163 "./marpa.w"
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
#line 3174 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3179 "./marpa.w"


/*:406*//*407:*/
#line 3183 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*409:*/
#line 3199 "./marpa.w"

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
#line 3189 "./marpa.w"

}

/*:407*//*408:*/
#line 3193 "./marpa.w"
}

/*:408*/
#line 2924 "./marpa.w"

}
}

/*:380*/
#line 2837 "./marpa.w"

NEXT_RULE:;
}
/*379:*/
#line 2900 "./marpa.w"

g_free(factor_positions);

/*:379*//*384:*/
#line 2951 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:384*/
#line 2840 "./marpa.w"

return g;
}
/*:371*//*410:*/
#line 3218 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
return ID_of_SYM(alias);
}
/*:410*//*413:*/
#line 3233 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g->t_start_symid);
/*414:*/
#line 3247 "./marpa.w"

if(SYM_is_Nulling(old_start)){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:414*/
#line 3241 "./marpa.w"

if(proper_old_start){/*415:*/
#line 3257 "./marpa.w"
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
#line 3242 "./marpa.w"
}
if(nulling_old_start){/*416:*/
#line 3278 "./marpa.w"
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
#line 3243 "./marpa.w"
}
return g;
}

/*:413*//*421:*/
#line 3355 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{
gint no_of_rules= RULE_Count_of_G(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_create((guint)no_of_rules,(guint)no_of_rules);
/*423:*/
#line 3382 "./marpa.w"
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
#line 3363 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*424:*/
#line 3421 "./marpa.w"
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
#line 3365 "./marpa.w"

if(loop_rule_count)
{
g->t_has_loop= TRUE;
int_event_new(g,MARPA_G_EV_LOOP_RULES,loop_rule_count);
}
matrix_free(unit_transition_matrix);
}
/*:421*//*439:*/
#line 3586 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id){
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}
/*:439*//*445:*/
#line 3627 "./marpa.w"

gint marpa_g_AHFA_item_count(struct marpa_g*g){
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 3629 "./marpa.w"

/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 3630 "./marpa.w"

return AIM_Count_of_G(g);
}
/*:445*//*447:*/
#line 3636 "./marpa.w"

Marpa_Rule_ID marpa_g_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 3639 "./marpa.w"

/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 3640 "./marpa.w"

/*1316:*/
#line 13110 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1316*/
#line 3641 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(item_id))->t_id;
}
/*:447*//*450:*/
#line 3650 "./marpa.w"

gint marpa_g_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 3653 "./marpa.w"

/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 3654 "./marpa.w"

/*1316:*/
#line 13110 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1316*/
#line 3655 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:450*//*452:*/
#line 3662 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 3665 "./marpa.w"

/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 3666 "./marpa.w"

/*1316:*/
#line 13110 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1316*/
#line 3667 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:452*//*454:*/
#line 3673 "./marpa.w"

gint marpa_g_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 3676 "./marpa.w"

/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 3677 "./marpa.w"

/*1316:*/
#line 13110 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1316*/
#line 3678 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:454*//*456:*/
#line 3689 "./marpa.w"

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
#line 3715 "./marpa.w"

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
#line 3739 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:459*/
#line 3726 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*460:*/
#line 3748 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:460*/
#line 3735 "./marpa.w"

current_item++;
}

/*:458*/
#line 3701 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
no_of_items= AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*461:*/
#line 3762 "./marpa.w"

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
#line 3709 "./marpa.w"

/*468:*/
#line 3838 "./marpa.w"

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
#line 3710 "./marpa.w"

}
/*:456*//*464:*/
#line 3797 "./marpa.w"

static gint cmp_by_aimid(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED){
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:464*//*467:*/
#line 3815 "./marpa.w"

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
#line 3999 "./marpa.w"

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
#line 4069 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id){
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}
/*:496*//*500:*/
#line 4086 "./marpa.w"

gint marpa_g_AHFA_state_count(struct marpa_g*g){
return AHFA_Count_of_G(g);
}
/*:500*//*502:*/
#line 4093 "./marpa.w"

gint
marpa_g_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 4096 "./marpa.w"

AHFA state;
/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 4098 "./marpa.w"

/*1317:*/
#line 13115 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1317*/
#line 4099 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}
/*:502*//*505:*/
#line 4112 "./marpa.w"

Marpa_AHFA_Item_ID marpa_g_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
gint item_ix){
AHFA state;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 4117 "./marpa.w"

/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 4118 "./marpa.w"

/*1317:*/
#line 13115 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1317*/
#line 4119 "./marpa.w"

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
#line 4132 "./marpa.w"

gint marpa_g_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 4136 "./marpa.w"

/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 4137 "./marpa.w"

/*1317:*/
#line 13115 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1317*/
#line 4138 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}
/*:506*//*511:*/
#line 4177 "./marpa.w"

Marpa_Rule_ID marpa_g_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
const gint no_completed_start_rule= -1;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 4181 "./marpa.w"

AHFA state;
/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 4183 "./marpa.w"

/*1317:*/
#line 13115 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1317*/
#line 4184 "./marpa.w"

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
/*1319:*/
#line 13125 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1319*/
#line 4200 "./marpa.w"

}
return no_completed_start_rule;
}

/*:511*//*515:*/
#line 4218 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 4221 "./marpa.w"

AHFA state;
/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 4223 "./marpa.w"

/*1317:*/
#line 13115 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1317*/
#line 4224 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:515*//*518:*/
#line 4247 "./marpa.w"

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
#line 4276 "./marpa.w"

PRIVATE_NOT_INLINE
void create_AHFA_states(struct marpa_g*g){
/*522:*/
#line 4295 "./marpa.w"

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
#line 4279 "./marpa.w"

/*523:*/
#line 4310 "./marpa.w"

/*524:*/
#line 4314 "./marpa.w"

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
#line 4311 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:523*/
#line 4280 "./marpa.w"

/*546:*/
#line 4823 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_create(symbol_count_of_g,symbol_count_of_g);
/*547:*/
#line 4832 "./marpa.w"

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
#line 4826 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*548:*/
#line 4869 "./marpa.w"
{
AIM*items_by_rule= g->t_AHFA_items_by_rule;
SYMID from_symid;
guint*sort_key_by_rule_id= g_new(guint,rule_count_of_g);
guint no_of_predictable_rules= 0;
/*549:*/
#line 4901 "./marpa.w"

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
#line 4875 "./marpa.w"

/*550:*/
#line 4921 "./marpa.w"

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
#line 4876 "./marpa.w"

/*553:*/
#line 4953 "./marpa.w"

{
guint sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:553*/
#line 4877 "./marpa.w"

/*554:*/
#line 4963 "./marpa.w"

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
#line 4878 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:548*/
#line 4828 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:546*/
#line 4281 "./marpa.w"

/*531:*/
#line 4448 "./marpa.w"

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
#line 4282 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*525:*/
#line 4327 "./marpa.w"
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
#line 4512 "./marpa.w"
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
#line 4602 "./marpa.w"
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
#line 4570 "./marpa.w"

}
}

/*:533*/
#line 4347 "./marpa.w"

}else{
/*536:*/
#line 4627 "./marpa.w"
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
#line 4678 "./marpa.w"

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
#line 4672 "./marpa.w"

transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
/*541:*/
#line 4761 "./marpa.w"
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
#line 4675 "./marpa.w"

}

/*:536*/
#line 4349 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:525*/
#line 4284 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*526:*/
#line 4359 "./marpa.w"

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
#line 4289 "./marpa.w"

/*528:*/
#line 4411 "./marpa.w"

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
#line 4290 "./marpa.w"

/*527:*/
#line 4382 "./marpa.w"

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
#line 4291 "./marpa.w"

/*529:*/
#line 4438 "./marpa.w"

g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*530:*/
#line 4444 "./marpa.w"

g_free(singleton_duplicates);
g_tree_destroy(duplicates);

/*:530*/
#line 4441 "./marpa.w"

obstack_free(&ahfa_work_obs,NULL);

/*:529*/
#line 4292 "./marpa.w"

}

/*:521*//*540:*/
#line 4750 "./marpa.w"

static inline AHFA
assign_AHFA_state(AHFA sought_state,GTree*duplicates)
{
const AHFA state_found= g_tree_lookup(duplicates,sought_state);
if(state_found)return state_found;
g_tree_insert(duplicates,sought_state,sought_state);
return NULL;
}

/*:540*//*551:*/
#line 4933 "./marpa.w"
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
#line 5012 "./marpa.w"

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
#line 5067 "./marpa.w"

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
#line 5063 "./marpa.w"

return p_new_state;
}

/*:556*//*569:*/
#line 5178 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition){
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:569*//*571:*/
#line 5185 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition){
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:571*//*573:*/
#line 5194 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix){
URTRANS transition;
transition= obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:573*//*575:*/
#line 5206 "./marpa.w"
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
#line 5221 "./marpa.w"

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
#line 5238 "./marpa.w"

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
#line 5257 "./marpa.w"

gint marpa_g_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 5262 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
gint symbol_count;

/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 5268 "./marpa.w"

/*1317:*/
#line 13115 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1317*/
#line 5269 "./marpa.w"

/*1318:*/
#line 13120 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
MARPA_DEV_ERROR("garray size mismatch");
return failure_indicator;
}
/*:1318*/
#line 5270 "./marpa.w"

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
#line 5293 "./marpa.w"

AHFAID marpa_g_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 5298 "./marpa.w"

/*1313:*/
#line 13095 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1313*/
#line 5299 "./marpa.w"

/*1317:*/
#line 13115 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1317*/
#line 5300 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:585*//*591:*/
#line 5349 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
gint symbol_count_of_g;
/*1310:*/
#line 13082 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1310*/
#line 5354 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
r= g_slice_new(struct marpa_r);
G_of_R(r)= g;
grammar_ref(g);
symbol_count_of_g= SYM_Count_of_G(g);
/*656:*/
#line 5769 "./marpa.w"
obstack_init(&r->t_obs);
/*:656*/
#line 5363 "./marpa.w"

/*595:*/
#line 5380 "./marpa.w"

r->ref_count= 1;

/*:595*//*607:*/
#line 5475 "./marpa.w"

Phase_of_R(r)= initial_phase;
/*:607*//*610:*/
#line 5487 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:610*//*615:*/
#line 5513 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:615*//*619:*/
#line 5536 "./marpa.w"
r->t_furthest_earleme= 0;
/*:619*//*623:*/
#line 5553 "./marpa.w"
r->t_sym_workarea= NULL;
/*:623*//*627:*/
#line 5568 "./marpa.w"
r->t_workarea2= NULL;
/*:627*//*631:*/
#line 5592 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:631*//*635:*/
#line 5615 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:635*//*649:*/
#line 5712 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:649*//*653:*/
#line 5751 "./marpa.w"
r->t_is_exhausted= 0;
/*:653*//*676:*/
#line 5866 "./marpa.w"

r->t_earley_set_count= 0;

/*:676*//*682:*/
#line 5915 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:682*//*707:*/
#line 6194 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:707*//*740:*/
#line 6581 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:740*//*779:*/
#line 7055 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:779*//*814:*/
#line 7560 "./marpa.w"

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
/*:814*//*822:*/
#line 7632 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:822*//*845:*/
#line 7924 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:845*//*849:*/
#line 7936 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:849*//*853:*/
#line 7948 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:853*//*920:*/
#line 8788 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:920*//*1034:*/
#line 10301 "./marpa.w"

B_of_R(r)= NULL;

/*:1034*//*1278:*/
#line 12802 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1278*/
#line 5364 "./marpa.w"

/*592:*/
#line 5371 "./marpa.w"

{
if(G_is_Trivial(g)){
R_is_Exhausted(r)= 1;
}
}

/*:592*/
#line 5365 "./marpa.w"

return r;
}

/*:591*//*597:*/
#line 5386 "./marpa.w"

static inline void
r_unref(RECCE r)
{
MARPA_ASSERT(r->ref_count> 0)
r->ref_count--;
if(r->ref_count<=0)
{
r_free(r);
}
}
void
marpa_r_unref(Marpa_Recognizer r)
{
r_unref(r);
}

/*:597*//*599:*/
#line 5406 "./marpa.w"

static inline
RECCE r_ref(RECCE r)
{
MARPA_ASSERT(r->ref_count> 0)
r->ref_count++;
return r;
}
Marpa_Recognizer
marpa_r_ref(Marpa_Recognizer r)
{
return r_ref(r);
}

/*:599*//*600:*/
#line 5420 "./marpa.w"

static inline
void r_free(struct marpa_r*r)
{
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5424 "./marpa.w"

/*679:*/
#line 5892 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
if(EIMs_of_ES(set))
g_free(EIMs_of_ES(set));
}
}

/*:679*//*815:*/
#line 7574 "./marpa.w"

{
TOK*tokens_by_symid= TOKs_by_SYMID_of_R(r);
if(tokens_by_symid){
obstack_free(TOK_Obs_of_R(r),NULL);
TOKs_by_SYMID_of_R(r)= NULL;
}
}

/*:815*//*823:*/
#line 7634 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:823*//*847:*/
#line 7929 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:847*//*851:*/
#line 7941 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:851*//*854:*/
#line 7949 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:854*//*921:*/
#line 8790 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:921*//*1279:*/
#line 12804 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1279*/
#line 5425 "./marpa.w"

grammar_unref(g);
if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*633:*/
#line 5601 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:633*//*637:*/
#line 5618 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:637*/
#line 5429 "./marpa.w"

/*657:*/
#line 5770 "./marpa.w"
obstack_free(&r->t_obs,NULL);

/*:657*/
#line 5430 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:600*//*608:*/
#line 5477 "./marpa.w"

Marpa_Phase marpa_r_phase(struct marpa_r*r)
{return Phase_of_R(r);}

/*:608*//*611:*/
#line 5495 "./marpa.w"

guint marpa_r_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:611*//*613:*/
#line 5502 "./marpa.w"

static inline ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:613*//*616:*/
#line 5515 "./marpa.w"

gint marpa_r_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:616*//*617:*/
#line 5521 "./marpa.w"

gint marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,gint threshold)
{
r->t_earley_item_warning_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:617*//*620:*/
#line 5537 "./marpa.w"

guint marpa_r_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:620*//*638:*/
#line 5628 "./marpa.w"

gint marpa_r_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 5631 "./marpa.w"

/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5632 "./marpa.w"

guint min,max,start;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 5634 "./marpa.w"

/*1323:*/
#line 13148 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_DEV_ERROR("recce not in input phase");
return failure_indicator;
}

/*:1323*/
#line 5635 "./marpa.w"

/*1327:*/
#line 13176 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
R_DEV_ERROR("garray size mismatch");
return failure_indicator;
}

/*:1327*/
#line 5636 "./marpa.w"

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

/*:638*//*650:*/
#line 5718 "./marpa.w"

gint marpa_r_is_use_leo(struct marpa_r*r)
{
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5721 "./marpa.w"

/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 5722 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 5723 "./marpa.w"

return r->t_use_leo_flag?1:0;
}
/*:650*//*651:*/
#line 5728 "./marpa.w"

gboolean marpa_r_is_use_leo_set(
struct marpa_r*r,gboolean value)
{
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5732 "./marpa.w"

/*1309:*/
#line 13080 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1309*/
#line 5733 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 5734 "./marpa.w"

/*1320:*/
#line 13133 "./marpa.w"

if(Phase_of_R(r)!=initial_phase){
R_DEV_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1320*/
#line 5735 "./marpa.w"

r->t_use_leo_flag= value;
return TRUE;
}

/*:651*//*654:*/
#line 5755 "./marpa.w"

gint marpa_r_is_exhausted(struct marpa_r*r)
{
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5758 "./marpa.w"

/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 5759 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 5760 "./marpa.w"

return r->t_is_exhausted?1:0;
}

/*:654*//*659:*/
#line 5774 "./marpa.w"

Marpa_Error_Code marpa_r_error(const struct marpa_r*r,const char**p_error_string)
{
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5777 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:659*//*661:*/
#line 5783 "./marpa.w"

gint marpa_r_event(const struct marpa_r*r,struct marpa_g_event*public_event,gint ix)
{
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5786 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:661*//*678:*/
#line 5872 "./marpa.w"

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
/*1285:*/
#line 12854 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1285*/
#line 5887 "./marpa.w"

return set;
}

/*:678*//*683:*/
#line 5918 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 5921 "./marpa.w"

/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5922 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 5924 "./marpa.w"

if(!trace_earley_set){
R_DEV_ERROR("no trace es");
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:683*//*684:*/
#line 5932 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 5935 "./marpa.w"

/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5936 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 5937 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:684*//*686:*/
#line 5951 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const gint es_does_not_exist= -1;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5955 "./marpa.w"

/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 5956 "./marpa.w"

ES earley_set;
/*1321:*/
#line 13138 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_DEV_ERROR("initial recce phase");
return failure_indicator;
}
/*:1321*/
#line 5958 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 5959 "./marpa.w"

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

/*:686*//*688:*/
#line 5975 "./marpa.w"

gint marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 5978 "./marpa.w"

ES earley_set;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 5980 "./marpa.w"

/*1321:*/
#line 13138 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_DEV_ERROR("initial recce phase");
return failure_indicator;
}
/*:1321*/
#line 5981 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 5982 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
R_DEV_ERROR("invalid es ordinal");
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:688*//*698:*/
#line 6081 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1310:*/
#line 13082 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1310*/
#line 6085 "./marpa.w"

/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6086 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const gint count= ++EIM_Count_of_ES(set);
/*701:*/
#line 6136 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(G_UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
R_FATAL(MARPA_ERR_EIM_COUNT,"eim count exceeds fatal threshold");
return failure_indicator;
}
int_event_new(g,MARPA_G_EV_EARLEY_ITEM_THRESHOLD,count);
}

/*:701*/
#line 6091 "./marpa.w"

new_item= obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:698*//*700:*/
#line 6104 "./marpa.w"

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

/*:700*//*705:*/
#line 6170 "./marpa.w"

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

/*:705*//*712:*/
#line 6234 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const gint es_does_not_exist= -1;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6240 "./marpa.w"

/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6241 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6242 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*713:*/
#line 6265 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*742:*/
#line 6620 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:742*/
#line 6268 "./marpa.w"

}

/*:713*/
#line 6249 "./marpa.w"

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

/*:712*//*714:*/
#line 6271 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const gint eim_does_not_exist= -1;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6276 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6280 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6281 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*713:*/
#line 6265 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*742:*/
#line 6620 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:742*/
#line 6268 "./marpa.w"

}

/*:713*/
#line 6285 "./marpa.w"

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

/*:714*//*717:*/
#line 6316 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r)
{
/*715:*/
#line 6311 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:715*/
#line 6319 "./marpa.w"

trace_source_link_clear(r);
}

/*:717*//*718:*/
#line 6323 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6326 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1321:*/
#line 13138 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_DEV_ERROR("initial recce phase");
return failure_indicator;
}
/*:1321*/
#line 6328 "./marpa.w"

if(!item){
/*715:*/
#line 6311 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:715*/
#line 6330 "./marpa.w"

R_DEV_ERROR("no trace eim");
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:718*//*725:*/
#line 6403 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6407 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6410 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6411 "./marpa.w"

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

/*:725*//*726:*/
#line 6425 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6429 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6431 "./marpa.w"

EIM base_earley_item;
/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6433 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:726*//*727:*/
#line 6443 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6447 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6450 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6451 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:727*//*731:*/
#line 6485 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6489 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6491 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6492 "./marpa.w"

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


/*:731*//*736:*/
#line 6543 "./marpa.w"

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
/*:736*//*738:*/
#line 6565 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:738*//*741:*/
#line 6595 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6600 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6604 "./marpa.w"

/*742:*/
#line 6620 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:742*/
#line 6605 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6606 "./marpa.w"

/*1326:*/
#line 13171 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
R_DEV_ERROR("invalid symid");
return failure_indicator;
}
/*:1326*/
#line 6607 "./marpa.w"

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

/*:741*//*743:*/
#line 6630 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6634 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6637 "./marpa.w"

PIM*pim_sym_p;
/*742:*/
#line 6620 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:742*/
#line 6639 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6640 "./marpa.w"

if(!current_earley_set){
/*715:*/
#line 6311 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:715*/
#line 6642 "./marpa.w"

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

/*:743*//*744:*/
#line 6661 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6666 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6670 "./marpa.w"


pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*742:*/
#line 6620 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:742*/
#line 6674 "./marpa.w"

if(!pim_sym_p||!pim){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6679 "./marpa.w"

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

/*:744*//*745:*/
#line 6699 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_postdot_item_symbol(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 6702 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 6704 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 6705 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:745*//*762:*/
#line 6838 "./marpa.w"
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

/*:762*//*768:*/
#line 6919 "./marpa.w"
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

/*:768*//*769:*/
#line 6946 "./marpa.w"
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
/*:769*//*772:*/
#line 6998 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
guint previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*774:*/
#line 7016 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= new_link;
}

/*:774*/
#line 7005 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*775:*/
#line 7025 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= new_link;
First_Token_Link_of_EIM(item)= NULL;
}

/*:775*/
#line 7007 "./marpa.w"

return;
case SOURCE_IS_LEO:/*776:*/
#line 7034 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= new_link;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= NULL;
}

/*:776*/
#line 7009 "./marpa.w"

return;
}
}
/*:772*//*781:*/
#line 7066 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7069 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7073 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7074 "./marpa.w"

/*795:*/
#line 7293 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:795*/
#line 7075 "./marpa.w"

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

/*:781*//*784:*/
#line 7110 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7113 "./marpa.w"

SRCL full_link;
EIM item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7116 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7117 "./marpa.w"

/*795:*/
#line 7293 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:795*/
#line 7118 "./marpa.w"

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

/*:784*//*786:*/
#line 7141 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7144 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7148 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7149 "./marpa.w"

/*795:*/
#line 7293 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:795*/
#line 7150 "./marpa.w"

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

/*:786*//*789:*/
#line 7184 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7187 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7191 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7192 "./marpa.w"

/*795:*/
#line 7293 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:795*/
#line 7193 "./marpa.w"

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

/*:789*//*791:*/
#line 7217 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_leo_link_trace(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7221 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7225 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7226 "./marpa.w"

/*795:*/
#line 7293 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:795*/
#line 7227 "./marpa.w"

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

/*:791*//*794:*/
#line 7263 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_leo_link_trace(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7267 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7271 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7272 "./marpa.w"

/*795:*/
#line 7293 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:795*/
#line 7273 "./marpa.w"

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

/*:794*//*798:*/
#line 7304 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r){
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:798*//*799:*/
#line 7319 "./marpa.w"

AHFAID marpa_r_source_predecessor_state(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7322 "./marpa.w"

guint source_type;
SRC source;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7325 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7326 "./marpa.w"

source_type= r->t_trace_source_type;
/*806:*/
#line 7470 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:806*/
#line 7328 "./marpa.w"

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

/*:799*//*800:*/
#line 7360 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,gpointer*value_p)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7363 "./marpa.w"

guint source_type;
SRC source;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7366 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7367 "./marpa.w"

source_type= r->t_trace_source_type;
/*806:*/
#line 7470 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:806*/
#line 7369 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:800*//*802:*/
#line 7392 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7395 "./marpa.w"

guint source_type;
SRC source;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7398 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7399 "./marpa.w"

source_type= r->t_trace_source_type;
/*806:*/
#line 7470 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:806*/
#line 7401 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:802*//*805:*/
#line 7438 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7441 "./marpa.w"

const EARLEME no_predecessor= -1;
guint source_type;
SRC source;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7445 "./marpa.w"

/*1324:*/
#line 13154 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 13155 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
break;
}

/*:1324*/
#line 7446 "./marpa.w"

source_type= r->t_trace_source_type;
/*806:*/
#line 7470 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:806*/
#line 7448 "./marpa.w"

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

/*:805*//*817:*/
#line 7586 "./marpa.w"

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

/*:817*//*825:*/
#line 7642 "./marpa.w"

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

/*:825*//*827:*/
#line 7688 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b){
gint subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:827*//*829:*/
#line 7706 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:829*//*831:*/
#line 7723 "./marpa.w"

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

/*:831*//*832:*/
#line 7742 "./marpa.w"
gboolean marpa_r_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7748 "./marpa.w"

const gint symbol_count_of_g= SYM_Count_of_G(g);
/*1309:*/
#line 13080 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1309*/
#line 7750 "./marpa.w"

/*1320:*/
#line 13133 "./marpa.w"

if(Phase_of_R(r)!=initial_phase){
R_DEV_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1320*/
#line 7751 "./marpa.w"

Phase_of_R(r)= input_phase;
Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g))return TRUE;
/*628:*/
#line 5569 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*624:*/
#line 5554 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:624*/
#line 5572 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:628*/
#line 7755 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*632:*/
#line 5596 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:632*//*636:*/
#line 5616 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:636*/
#line 7757 "./marpa.w"

/*846:*/
#line 7925 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT(r->t_eim_work_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:846*//*850:*/
#line 7937 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT(r->t_completion_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:850*/
#line 7758 "./marpa.w"

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

/*:832*//*839:*/
#line 7826 "./marpa.w"

gboolean marpa_r_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length){
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7829 "./marpa.w"

/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7830 "./marpa.w"

const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1323:*/
#line 13148 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_DEV_ERROR("recce not in input phase");
return failure_indicator;
}

/*:1323*/
#line 7836 "./marpa.w"

/*1322:*/
#line 13143 "./marpa.w"

if(R_is_Exhausted(r)){
R_DEV_ERROR("recce exhausted");
return failure_indicator;
}
/*:1322*/
#line 7837 "./marpa.w"

/*840:*/
#line 7845 "./marpa.w"
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

/*:840*/
#line 7838 "./marpa.w"

/*842:*/
#line 7876 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:842*/
#line 7839 "./marpa.w"

/*841:*/
#line 7861 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
R_DEV_ERROR("parse too long");
return failure_indicator;
}
}

/*:841*/
#line 7840 "./marpa.w"

/*843:*/
#line 7899 "./marpa.w"

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
/*818:*/
#line 7601 "./marpa.w"
obstack_free(TOK_Obs_of_R(r),token);

/*:818*/
#line 7910 "./marpa.w"

return duplicate_token_indicator;
}
}

/*:843*/
#line 7841 "./marpa.w"

return current_earleme;
}

/*:839*//*856:*/
#line 7968 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 7972 "./marpa.w"

/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 7973 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
gint count_of_expected_terminals;
/*1323:*/
#line 13148 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_DEV_ERROR("recce not in input phase");
return failure_indicator;
}

/*:1323*/
#line 7978 "./marpa.w"

/*1322:*/
#line 13143 "./marpa.w"

if(R_is_Exhausted(r)){
R_DEV_ERROR("recce exhausted");
return failure_indicator;
}
/*:1322*/
#line 7979 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*857:*/
#line 8007 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
R_is_Exhausted(r)= 1;
R_DEV_ERROR("parse exhausted");
return failure_indicator;
}
}

/*:857*/
#line 7983 "./marpa.w"

/*859:*/
#line 8032 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:859*/
#line 7984 "./marpa.w"

/*858:*/
#line 8019 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:858*/
#line 7985 "./marpa.w"

/*860:*/
#line 8038 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*861:*/
#line 8045 "./marpa.w"

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

/*:861*/
#line 8042 "./marpa.w"

}

/*:860*/
#line 7986 "./marpa.w"

/*862:*/
#line 8072 "./marpa.w"
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

/*:862*/
#line 7987 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*863:*/
#line 8091 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*864:*/
#line 8104 "./marpa.w"

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
/*865:*/
#line 8127 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*866:*/
#line 8143 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:866*/
#line 8136 "./marpa.w"

}
/*867:*/
#line 8150 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:867*/
#line 8138 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:865*/
#line 8115 "./marpa.w"

}
else
{
/*868:*/
#line 8160 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*866:*/
#line 8143 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:866*/
#line 8169 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:868*/
#line 8119 "./marpa.w"

break;


}
}
}

/*:864*/
#line 8100 "./marpa.w"

}
}

/*:863*/
#line 7990 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


R_is_Exhausted(r)= 1;
event_new(g,MARPA_G_EV_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:856*//*870:*/
#line 8176 "./marpa.w"

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

/*:870*//*872:*/
#line 8202 "./marpa.w"

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

/*:872*//*876:*/
#line 8240 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES current_earley_set)
{
gpointer*const pim_workarea= r->t_sym_workarea;
/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 8245 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*877:*/
#line 8262 "./marpa.w"
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

/*:877*/
#line 8251 "./marpa.w"

if(r->t_is_using_leo){
/*879:*/
#line 8308 "./marpa.w"

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
/*880:*/
#line 8338 "./marpa.w"
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

/*:880*/
#line 8325 "./marpa.w"

}
}
}
}
}

/*:879*/
#line 8253 "./marpa.w"

/*889:*/
#line 8423 "./marpa.w"
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

/*892:*/
#line 8482 "./marpa.w"
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

/*:892*/
#line 8441 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*898:*/
#line 8574 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:898*/
#line 8443 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*900:*/
#line 8595 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:900*/
#line 8449 "./marpa.w"

continue;
}
/*893:*/
#line 8497 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*896:*/
#line 8518 "./marpa.w"
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

/*892:*/
#line 8482 "./marpa.w"
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

/*:892*/
#line 8544 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:896*/
#line 8500 "./marpa.w"

/*897:*/
#line 8563 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*898:*/
#line 8574 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:898*/
#line 8567 "./marpa.w"

}else{
/*900:*/
#line 8595 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:900*/
#line 8569 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:897*/
#line 8501 "./marpa.w"

}

/*:893*/
#line 8452 "./marpa.w"

}
}
}

/*:889*/
#line 8254 "./marpa.w"

}
/*901:*/
#line 8601 "./marpa.w"
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

/*:901*/
#line 8256 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:876*//*923:*/
#line 8795 "./marpa.w"

static inline void ur_node_stack_init(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_init %s",G_STRLOC);
obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:923*//*925:*/
#line 8805 "./marpa.w"

static inline void ur_node_stack_reset(URS stack){
stack->t_top= stack->t_base;
}

/*:925*//*927:*/
#line 8812 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
if(stack->t_base)obstack_free(&stack->t_obs,NULL);
stack->t_base= NULL;
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
}

/*:927*//*929:*/
#line 8822 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev){
UR new_ur_node;
new_ur_node= obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:929*//*931:*/
#line 8833 "./marpa.w"

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

/*:931*//*933:*/
#line 8851 "./marpa.w"

static inline UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:933*//*938:*/
#line 8920 "./marpa.w"

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

/*:938*//*975:*/
#line 9541 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:975*//*977:*/
#line 9555 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:977*//*984:*/
#line 9677 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause);
return draft_and_node;
}

/*:984*//*987:*/
#line 9703 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:987*//*1015:*/
#line 10149 "./marpa.w"

gint marpa_b_and_node_count(Marpa_Bocage b)
{
/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10152 "./marpa.w"

/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10153 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10154 "./marpa.w"

return AND_Count_of_B(b);
}

/*:1015*//*1018:*/
#line 10177 "./marpa.w"

gint marpa_b_and_node_parent(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10181 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10182 "./marpa.w"

/*1016:*/
#line 10158 "./marpa.w"
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

/*:1016*/
#line 10183 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1018*//*1020:*/
#line 10189 "./marpa.w"

gint marpa_b_and_node_predecessor(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10193 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10194 "./marpa.w"

/*1016:*/
#line 10158 "./marpa.w"
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

/*:1016*/
#line 10195 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1020*//*1022:*/
#line 10206 "./marpa.w"

gint marpa_b_and_node_cause(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10210 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10211 "./marpa.w"

/*1016:*/
#line 10158 "./marpa.w"
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

/*:1016*/
#line 10212 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1022*//*1024:*/
#line 10223 "./marpa.w"

gint marpa_b_and_node_symbol(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10227 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10228 "./marpa.w"

/*1016:*/
#line 10158 "./marpa.w"
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

/*:1016*/
#line 10229 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1024*//*1026:*/
#line 10257 "./marpa.w"

Marpa_Symbol_ID marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,gpointer*value_p)
{
AND and_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10262 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10263 "./marpa.w"

/*1016:*/
#line 10158 "./marpa.w"
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

/*:1016*/
#line 10264 "./marpa.w"

return and_node_token(and_node,value_p);
}
/*:1026*//*1028:*/
#line 10269 "./marpa.w"

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

/*:1028*//*1045:*/
#line 10345 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Rule_ID rule_id,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1310:*/
#line 13082 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1310*/
#line 10350 "./marpa.w"

/*1046:*/
#line 10395 "./marpa.w"

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

/*:1046*//*1049:*/
#line 10419 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:1049*/
#line 10351 "./marpa.w"

/*1050:*/
#line 10422 "./marpa.w"

{
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10424 "./marpa.w"

if(B_of_R(r))
{
R_DEV_ERROR("bocage in use");
return failure_indicator;
}
switch(Phase_of_R(r))
{
default:
R_DEV_ERROR("recce not evaluation-ready");
return failure_indicator;
case input_phase:
break;
}
}

/*:1050*/
#line 10352 "./marpa.w"

if(B_of_R(r)){
R_DEV_ERROR("bocage already set");
goto B_NEW_RETURN_ERROR;
}
b= B_of_R(r)= g_slice_new(struct s_bocage);
/*961:*/
#line 9280 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;

/*:961*//*1041:*/
#line 10324 "./marpa.w"

b->is_obstack_initialized= 1;
obstack_init(&OBS_of_B(b));
/*:1041*//*1067:*/
#line 10646 "./marpa.w"

b->ref_count= 1;

/*:1067*//*1121:*/
#line 11231 "./marpa.w"

MARPA_OFF_DEBUG3("%s order_safe where b=%p",G_STRLOC,b);
order_safe(ORDER_of_B(b));
/*:1121*/
#line 10358 "./marpa.w"

I_of_B(b)= I_of_R(r);


R_of_B(b)= r;
r_ref(r);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
r_update_earley_sets(r);
/*1051:*/
#line 10440 "./marpa.w"

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

/*:1051*/
#line 10370 "./marpa.w"

if(end_of_parse_earleme==0){
if(!g->t_null_start_rule)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
/*1052:*/
#line 10461 "./marpa.w"

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

/*:1052*/
#line 10375 "./marpa.w"

/*1058:*/
#line 10573 "./marpa.w"

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

/*:1058*/
#line 10376 "./marpa.w"

if(!start_eim)goto B_NEW_RETURN_ERROR;
obstack_init(&bocage_setup_obs);
/*1055:*/
#line 10521 "./marpa.w"

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

/*:1055*/
#line 10379 "./marpa.w"

/*935:*/
#line 8873 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*936:*/
#line 8901 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:936*/
#line 8882 "./marpa.w"

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
/*939:*/
#line 8948 "./marpa.w"

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
/*936:*/
#line 8901 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:936*/
#line 8976 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:939*/
#line 8895 "./marpa.w"

/*941:*/
#line 9017 "./marpa.w"

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
/*936:*/
#line 8901 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:936*/
#line 9053 "./marpa.w"

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
/*936:*/
#line 8901 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:936*/
#line 9066 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:941*/
#line 8896 "./marpa.w"

/*942:*/
#line 9076 "./marpa.w"

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
/*936:*/
#line 8901 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:936*/
#line 9109 "./marpa.w"

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
/*936:*/
#line 8901 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:936*/
#line 9125 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:942*/
#line 8897 "./marpa.w"

}
}

/*:935*/
#line 10380 "./marpa.w"

/*963:*/
#line 9303 "./marpa.w"

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
/*1292:*/
#line 12915 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1292*/
#line 9323 "./marpa.w"

/*964:*/
#line 9331 "./marpa.w"

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
/*965:*/
#line 9351 "./marpa.w"

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
/*1292:*/
#line 12915 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1292*/
#line 9364 "./marpa.w"

/*967:*/
#line 9382 "./marpa.w"

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
/*968:*/
#line 9412 "./marpa.w"

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


/*:968*/
#line 9393 "./marpa.w"

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

/*:967*/
#line 9365 "./marpa.w"

/*970:*/
#line 9437 "./marpa.w"

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
/*968:*/
#line 9412 "./marpa.w"

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


/*:968*/
#line 9461 "./marpa.w"

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

/*:970*/
#line 9366 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*971:*/
#line 9481 "./marpa.w"
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
/*973:*/
#line 9521 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const gint ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const gint symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*978:*/
#line 9566 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1292:*/
#line 12915 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1292*/
#line 9573 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*968:*/
#line 9412 "./marpa.w"

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


/*:968*/
#line 9577 "./marpa.w"

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

/*:978*/
#line 9531 "./marpa.w"

/*979:*/
#line 9595 "./marpa.w"

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
/*968:*/
#line 9412 "./marpa.w"

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


/*:968*/
#line 9612 "./marpa.w"

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

/*:979*/
#line 9532 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:973*/
#line 9503 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:971*/
#line 9374 "./marpa.w"

}

/*:965*/
#line 9345 "./marpa.w"

}
}
}
}

/*:964*/
#line 9324 "./marpa.w"

/*988:*/
#line 9713 "./marpa.w"

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
/*990:*/
#line 9750 "./marpa.w"

{
guint work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const gint work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*991:*/
#line 9766 "./marpa.w"
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
/*992:*/
#line 9798 "./marpa.w"

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
/*993:*/
#line 9827 "./marpa.w"

{
if(higher_path_leo_item){
/*997:*/
#line 9875 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:997*/
#line 9830 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:993*/
#line 9813 "./marpa.w"

/*995:*/
#line 9841 "./marpa.w"

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

/*:995*/
#line 9814 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*993:*/
#line 9827 "./marpa.w"

{
if(higher_path_leo_item){
/*997:*/
#line 9875 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:997*/
#line 9830 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:993*/
#line 9821 "./marpa.w"

/*998:*/
#line 9885 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const gint origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
MARPA_OFF_DEBUG2("lim=%s",lim_tag(path_leo_item));
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:998*/
#line 9822 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:992*/
#line 9788 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:991*/
#line 9761 "./marpa.w"

/*999:*/
#line 9896 "./marpa.w"

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
/*1000:*/
#line 9926 "./marpa.w"

{
OR dand_predecessor;
/*1001:*/
#line 9935 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1001*/
#line 9929 "./marpa.w"

MARPA_OFF_DEBUG2("or=%s",or_tag(work_proper_or_node));
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:1000*/
#line 9918 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:999*/
#line 9762 "./marpa.w"

/*1002:*/
#line 9946 "./marpa.w"

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
/*1003:*/
#line 9986 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const gint middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*1001:*/
#line 9935 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1001*/
#line 9994 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
MARPA_OFF_DEBUG2("completion source, or=%s",or_tag(work_proper_or_node));
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:1003*/
#line 9977 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1002*/
#line 9763 "./marpa.w"

}

/*:990*/
#line 9728 "./marpa.w"

}
}
}
}
}

/*:988*/
#line 9325 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= g_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:963*/
#line 10381 "./marpa.w"

/*1011:*/
#line 10102 "./marpa.w"

{
gint unique_draft_and_node_count= 0;
/*1004:*/
#line 10001 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const gint or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
gint or_node_id= 0;
psar_init(and_psar,rule_count_of_g+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*1006:*/
#line 10033 "./marpa.w"

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

/*:1006*/
#line 10011 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:1004*/
#line 10105 "./marpa.w"

/*1012:*/
#line 10109 "./marpa.w"

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

/*:1012*/
#line 10106 "./marpa.w"

}

/*:1011*/
#line 10382 "./marpa.w"

/*1059:*/
#line 10601 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const gint start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:1059*/
#line 10383 "./marpa.w"
;
obstack_free(&bocage_setup_obs,NULL);
return b;
B_NEW_RETURN_ERROR:;
r_unref(r);
B_of_R(r)= NULL;
if(b){
/*1072:*/
#line 10687 "./marpa.w"

/*962:*/
#line 9286 "./marpa.w"

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

/*:962*//*1124:*/
#line 11244 "./marpa.w"

order_destroy(ORDER_of_B(b));
/*:1124*/
#line 10688 "./marpa.w"
;
/*1042:*/
#line 10327 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:1042*/
#line 10689 "./marpa.w"
;

/*:1072*/
#line 10390 "./marpa.w"
;
}
return NULL;
}

/*:1045*//*1054:*/
#line 10487 "./marpa.w"

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

/*:1054*//*1061:*/
#line 10624 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10627 "./marpa.w"

return g;
}

/*:1061*//*1064:*/
#line 10635 "./marpa.w"

Marpa_Or_Node_ID marpa_b_top_or_node(Marpa_Bocage b)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10638 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10639 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10640 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:1064*//*1069:*/
#line 10652 "./marpa.w"

static inline void
b_unref(BOCAGE b)
{
MARPA_ASSERT(b->ref_count> 0)
b->ref_count--;
if(b->ref_count<=0)
{
b_free(b);
}
}
void
marpa_b_unref(Marpa_Bocage b)
{
b_unref(b);
}

/*:1069*//*1071:*/
#line 10672 "./marpa.w"

static inline BOCAGE
b_ref(BOCAGE b)
{
MARPA_ASSERT(b->ref_count> 0)
b->ref_count++;
return b;
}
Marpa_Bocage
marpa_b_ref(Marpa_Bocage b)
{
return b_ref(b);
}

/*:1071*//*1074:*/
#line 10697 "./marpa.w"

void
b_free(BOCAGE b)
{
const RECCE r= R_of_B(b);
/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10702 "./marpa.w"

B_of_R(r)= NULL;
r_unref(r);
if(b)
{
/*1072:*/
#line 10687 "./marpa.w"

/*962:*/
#line 9286 "./marpa.w"

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

/*:962*//*1124:*/
#line 11244 "./marpa.w"

order_destroy(ORDER_of_B(b));
/*:1124*/
#line 10688 "./marpa.w"
;
/*1042:*/
#line 10327 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:1042*/
#line 10689 "./marpa.w"
;

/*:1072*/
#line 10707 "./marpa.w"
;
g_slice_free(struct s_bocage,b);
}
}

/*:1074*//*1078:*/
#line 10736 "./marpa.w"

gint marpa_b_or_node_set(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10740 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10741 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10742 "./marpa.w"

/*1076:*/
#line 10715 "./marpa.w"
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

/*:1076*/
#line 10743 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:1078*//*1080:*/
#line 10749 "./marpa.w"

gint marpa_b_or_node_origin(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10753 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10754 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10755 "./marpa.w"

/*1076:*/
#line 10715 "./marpa.w"
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

/*:1076*/
#line 10756 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:1080*//*1082:*/
#line 10762 "./marpa.w"

gint marpa_b_or_node_rule(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10766 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10767 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10768 "./marpa.w"

/*1076:*/
#line 10715 "./marpa.w"
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

/*:1076*/
#line 10769 "./marpa.w"

return ID_of_RULE(RULE_of_OR(or_node));
}

/*:1082*//*1084:*/
#line 10775 "./marpa.w"

gint marpa_b_or_node_position(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10779 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10780 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10781 "./marpa.w"

/*1076:*/
#line 10715 "./marpa.w"
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

/*:1076*/
#line 10782 "./marpa.w"

return Position_of_OR(or_node);
}

/*:1084*//*1086:*/
#line 10788 "./marpa.w"

gint marpa_b_or_node_first_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10792 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10793 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10794 "./marpa.w"

/*1076:*/
#line 10715 "./marpa.w"
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

/*:1076*/
#line 10795 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:1086*//*1088:*/
#line 10801 "./marpa.w"

gint marpa_b_or_node_last_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10805 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10806 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10807 "./marpa.w"

/*1076:*/
#line 10715 "./marpa.w"
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

/*:1076*/
#line 10808 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:1088*//*1090:*/
#line 10815 "./marpa.w"

gint marpa_b_or_node_and_count(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10819 "./marpa.w"

/*1038:*/
#line 10313 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:1038*/
#line 10820 "./marpa.w"

/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10821 "./marpa.w"

/*1076:*/
#line 10715 "./marpa.w"
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

/*:1076*/
#line 10822 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:1090*//*1095:*/
#line 10870 "./marpa.w"

static inline void tree_exhaust(TREE tree)
{
if(FSTACK_IS_INITIALIZED(tree->t_fork_stack))
{
FSTACK_DESTROY(tree->t_fork_stack);
FSTACK_SAFE(tree->t_fork_stack);
}
if(FSTACK_IS_INITIALIZED(tree->t_fork_worklist))
{
FSTACK_DESTROY(tree->t_fork_worklist);
FSTACK_SAFE(tree->t_fork_worklist);
}
if(tree->t_and_node_in_use){
bv_free(tree->t_and_node_in_use);
tree->t_and_node_in_use= NULL;
}
}

/*:1095*//*1097:*/
#line 10891 "./marpa.w"

static inline void tree_safe(TREE tree)
{
FSTACK_SAFE(tree->t_fork_stack);
FSTACK_SAFE(tree->t_fork_worklist);
tree->t_and_node_in_use= NULL;
tree->t_parse_count= -1;
val_safe(VALUE_of_TREE(tree));
}

/*:1097*//*1099:*/
#line 10906 "./marpa.w"

int marpa_t_new(struct marpa_r*r)
{
BOCAGE b;
TREE tree;
gint first_tree_of_series= 0;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 10912 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 10914 "./marpa.w"

/*1110:*/
#line 11136 "./marpa.w"

{
b= B_of_R(r);
if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
}

/*:1110*/
#line 10915 "./marpa.w"

tree= TREE_of_ORDER(ORDER_of_B(b));
if(TREE_is_Exhausted(tree)){
return-1;
}
val_destroy(VALUE_of_TREE(tree));
if(!TREE_is_Initialized(tree))
{
first_tree_of_series= 1;
/*1104:*/
#line 10974 "./marpa.w"

{
ORID top_or_id= Top_ORID_of_B(b);
OR top_or_node= OR_of_B_by_ID(b,top_or_id);
FORK fork;
gint choice;
const gint and_count= AND_Count_of_B(b);
tree->t_parse_count= 0;
tree->t_and_node_in_use= bv_create((guint)and_count);
FSTACK_INIT(tree->t_fork_stack,FORK_Object,and_count);
FSTACK_INIT(tree->t_fork_worklist,gint,and_count);
choice= or_node_next_choice(b,tree,top_or_node,0);


if(choice<0)goto TREE_IS_EXHAUSTED;
fork= FSTACK_PUSH(tree->t_fork_stack);
OR_of_FORK(fork)= top_or_node;
Choice_of_FORK(fork)= choice;
Parent_of_FORK(fork)= -1;
FORK_Cause_is_Ready(fork)= 0;
FORK_is_Cause(fork)= 0;
FORK_Predecessor_is_Ready(fork)= 0;
FORK_is_Predecessor(fork)= 0;
*(FSTACK_PUSH(tree->t_fork_worklist))= 0;
}

/*:1104*/
#line 10926 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(!first_tree_of_series){
/*1105:*/
#line 11003 "./marpa.w"
{
while(1){
FORK iteration_candidate= FSTACK_TOP(tree->t_fork_stack,FORK_Object);
gint choice;
if(!iteration_candidate)break;
choice= Choice_of_FORK(iteration_candidate);
MARPA_ASSERT(choice>=0);
{
OR or_node= OR_of_FORK(iteration_candidate);
ANDID and_node_id= and_order_get(b,or_node,choice);
tree_and_node_release(tree,and_node_id);
choice= or_node_next_choice(b,tree,or_node,choice+1);
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
FORK parent_fork= FORK_of_TREE_by_IX(tree,parent_fork_ix);
if(FORK_is_Cause(iteration_candidate)){
FORK_Cause_is_Ready(parent_fork)= 0;
}
if(FORK_is_Predecessor(iteration_candidate)){
FORK_Predecessor_is_Ready(parent_fork)= 0;
}
}


FSTACK_POP(tree->t_fork_stack);
}
}
{
gint stack_length= FSTACK_LENGTH(tree->t_fork_stack);
gint i;
if(stack_length<=0)goto TREE_IS_EXHAUSTED;
FSTACK_CLEAR(tree->t_fork_worklist);
for(i= 0;i<stack_length;i++){
*(FSTACK_PUSH(tree->t_fork_worklist))= i;
}
}
}

/*:1105*/
#line 10931 "./marpa.w"

}
first_tree_of_series= 0;
/*1106:*/
#line 11055 "./marpa.w"
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
p_work_fork_id= FSTACK_TOP(tree->t_fork_worklist,FORKID);
if(!p_work_fork_id){
goto TREE_IS_FINISHED;
}
work_fork= FORK_of_TREE_by_IX(tree,*p_work_fork_id);
work_or_node= OR_of_FORK(work_fork);
work_and_node_id= and_order_get(b,work_or_node,Choice_of_FORK(work_fork));
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
FSTACK_POP(tree->t_fork_worklist);
goto NEXT_FORK_ON_WORKLIST;
}
choice= or_node_next_choice(b,tree,child_or_node,0);
if(choice<0)goto NEXT_TREE;
/*1109:*/
#line 11118 "./marpa.w"

{
FORKID new_fork_id= FSTACK_LENGTH(tree->t_fork_stack);
FORK new_fork= FSTACK_PUSH(tree->t_fork_stack);
*(FSTACK_PUSH(tree->t_fork_worklist))= new_fork_id;
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

/*:1109*/
#line 11097 "./marpa.w"
;
NEXT_FORK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1106*/
#line 10934 "./marpa.w"

}
TREE_IS_FINISHED:;
tree->t_parse_count++;
return FSTACK_LENGTH(tree->t_fork_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(tree);
return-1;
}

/*:1099*//*1101:*/
#line 10953 "./marpa.w"

static inline void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1101*//*1102:*/
#line 10959 "./marpa.w"

static inline void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1102*//*1103:*/
#line 10967 "./marpa.w"

static inline gint tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(guint)and_node_id);
}

/*:1103*//*1108:*/
#line 11105 "./marpa.w"

static inline gint or_node_next_choice(BOCAGE b,TREE tree,OR or_node,gint start_choice)
{
gint choice= start_choice;
while(1){
ANDID and_node_id= and_order_get(b,or_node,choice);
if(and_node_id<0)return-1;
if(tree_and_node_try(tree,and_node_id))return choice;
choice++;
}
return-1;
}

/*:1108*//*1112:*/
#line 11147 "./marpa.w"

static inline void tree_destroy(TREE tree)
{
tree_exhaust(tree);
tree->t_parse_count= -1;
MARPA_OFF_DEBUG4("%s tree=%p parse_count=%d",G_STRLOC,tree,tree->t_parse_count);
}

/*:1112*//*1114:*/
#line 11159 "./marpa.w"

gint marpa_t_parse_count(struct marpa_r*r)
{
BOCAGE b;
TREE tree;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11164 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11166 "./marpa.w"

b= B_of_R(r);
if(!b){
return-1;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
MARPA_OFF_DEBUG3("%s b=%p",G_STRLOC,b);
MARPA_OFF_DEBUG4("%s tree=%p parse_count=%d",G_STRLOC,tree,tree->t_parse_count);
return tree->t_parse_count;
}

/*:1114*//*1116:*/
#line 11184 "./marpa.w"

gint marpa_t_size(struct marpa_r*r)
{
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11187 "./marpa.w"

BOCAGE b= B_of_R(r);
TREE tree;
GRAMMAR g= G_of_R(r);
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11191 "./marpa.w"

if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
if(!TREE_is_Initialized(tree)){
R_DEV_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
return-1;
}
return FSTACK_LENGTH(tree->t_fork_stack);
}

/*:1116*//*1123:*/
#line 11236 "./marpa.w"

static inline void order_safe(ORDER order)
{
order->t_and_node_in_use= NULL;
order->t_and_node_orderings= NULL;
tree_safe(TREE_of_ORDER(order));
}

/*:1123*//*1126:*/
#line 11249 "./marpa.w"

static inline void order_freeze(ORDER order)
{
if(order->t_and_node_in_use)
{
bv_free(order->t_and_node_in_use);
order->t_and_node_in_use= NULL;
}
}
static inline void order_destroy(ORDER order)
{
tree_destroy(TREE_of_ORDER(order));
order_freeze(order);
if(order->t_and_node_orderings){
order->t_and_node_orderings= NULL;
obstack_free(&OBS_of_ORDER(order),NULL);
}
}

/*:1126*//*1131:*/
#line 11320 "./marpa.w"

gint marpa_o_and_order_set(Marpa_Recognizer r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length)
{
OR or_node;
ORDER order;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11328 "./marpa.w"

/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 11329 "./marpa.w"

BOCAGE b= B_of_R(r);
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11331 "./marpa.w"

if(!b){
MARPA_DEV_ERROR("no bocage");
return failure_indicator;
}
/*1076:*/
#line 10715 "./marpa.w"
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

/*:1076*/
#line 11336 "./marpa.w"

{
ANDID**and_node_orderings;
Bit_Vector and_node_in_use;
struct obstack*obs;
ANDID first_and_node_id;
ANDID and_count_of_or;
order= ORDER_of_B(b);
and_node_orderings= order->t_and_node_orderings;
and_node_in_use= order->t_and_node_in_use;
obs= &OBS_of_ORDER(order);
if(and_node_orderings&&!and_node_in_use)
{
MARPA_DEV_ERROR("order frozen");
return failure_indicator;
}
if(!and_node_orderings)
{
gint and_id;
const gint and_count_of_r= AND_Count_of_B(b);
obstack_init(obs);
order->t_and_node_orderings= 
and_node_orderings= 
obstack_alloc(obs,sizeof(ANDID*)*and_count_of_r);
for(and_id= 0;and_id<and_count_of_r;and_id++)
{
and_node_orderings[and_id]= (ANDID*)NULL;
}
order->t_and_node_in_use= 
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

/*:1131*//*1134:*/
#line 11408 "./marpa.w"

static inline ANDID and_order_get(BOCAGE b,OR or_node,gint ix)
{
ORDER order;
ANDID**and_node_orderings;
if(ix>=AND_Count_of_OR(or_node))
{
return-1;
}
order= ORDER_of_B(b);
and_node_orderings= order->t_and_node_orderings;
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

Marpa_And_Node_ID marpa_o_and_order_get(Marpa_Recognizer r,
Marpa_Or_Node_ID or_node_id,gint ix)
{
OR or_node;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11438 "./marpa.w"

/*602:*/
#line 5441 "./marpa.w"

const Marpa_Grammar g= G_of_R(r);

/*:602*/
#line 11439 "./marpa.w"

BOCAGE b= B_of_R(r);
if(!b){
MARPA_DEV_ERROR("no bocage");
return failure_indicator;
}
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11445 "./marpa.w"

/*1076:*/
#line 10715 "./marpa.w"
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

/*:1076*/
#line 11446 "./marpa.w"

if(ix<0){
MARPA_DEV_ERROR("negative and ix");
return failure_indicator;
}
return and_order_get(b,or_node,ix);
}

/*:1134*//*1142:*/
#line 11528 "./marpa.w"

gint marpa_t_fork_or_node(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11532 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1140:*/
#line 11496 "./marpa.w"
{
FORK base_fork;
BOCAGE b= B_of_R(r);
TREE tree;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11500 "./marpa.w"

if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
if(!TREE_is_Initialized(tree)){
R_DEV_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1140*/
#line 11534 "./marpa.w"

return ID_of_OR(OR_of_FORK(fork));
}

/*:1142*//*1144:*/
#line 11541 "./marpa.w"

gint marpa_t_fork_choice(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11545 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1140:*/
#line 11496 "./marpa.w"
{
FORK base_fork;
BOCAGE b= B_of_R(r);
TREE tree;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11500 "./marpa.w"

if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
if(!TREE_is_Initialized(tree)){
R_DEV_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1140*/
#line 11547 "./marpa.w"

return Choice_of_FORK(fork);
}

/*:1144*//*1146:*/
#line 11562 "./marpa.w"

gint marpa_t_fork_parent(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11566 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1140:*/
#line 11496 "./marpa.w"
{
FORK base_fork;
BOCAGE b= B_of_R(r);
TREE tree;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11500 "./marpa.w"

if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
if(!TREE_is_Initialized(tree)){
R_DEV_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1140*/
#line 11568 "./marpa.w"

return Parent_of_FORK(fork);
}

/*:1146*//*1148:*/
#line 11575 "./marpa.w"

gint marpa_t_fork_cause_is_ready(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11579 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1140:*/
#line 11496 "./marpa.w"
{
FORK base_fork;
BOCAGE b= B_of_R(r);
TREE tree;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11500 "./marpa.w"

if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
if(!TREE_is_Initialized(tree)){
R_DEV_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1140*/
#line 11581 "./marpa.w"

return FORK_Cause_is_Ready(fork);
}

/*:1148*//*1150:*/
#line 11588 "./marpa.w"

gint marpa_t_fork_predecessor_is_ready(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11592 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1140:*/
#line 11496 "./marpa.w"
{
FORK base_fork;
BOCAGE b= B_of_R(r);
TREE tree;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11500 "./marpa.w"

if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
if(!TREE_is_Initialized(tree)){
R_DEV_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1140*/
#line 11594 "./marpa.w"

return FORK_Predecessor_is_Ready(fork);
}

/*:1150*//*1152:*/
#line 11601 "./marpa.w"

gint marpa_t_fork_is_cause(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11605 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1140:*/
#line 11496 "./marpa.w"
{
FORK base_fork;
BOCAGE b= B_of_R(r);
TREE tree;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11500 "./marpa.w"

if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
if(!TREE_is_Initialized(tree)){
R_DEV_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1140*/
#line 11607 "./marpa.w"

return FORK_is_Cause(fork);
}

/*:1152*//*1154:*/
#line 11614 "./marpa.w"

gint marpa_t_fork_is_predecessor(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11618 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1140:*/
#line 11496 "./marpa.w"
{
FORK base_fork;
BOCAGE b= B_of_R(r);
TREE tree;
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11500 "./marpa.w"

if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
if(!TREE_is_Initialized(tree)){
R_DEV_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_DEV_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1140*/
#line 11620 "./marpa.w"

return FORK_is_Predecessor(fork);
}

/*:1154*//*1162:*/
#line 11689 "./marpa.w"

static inline void val_safe(VALUE val)
{
DSTACK_SAFE(val->t_virtual_stack);
VALUE_is_Active(val)= 0;
VALUE_is_Trace(val)= 0;
TOS_of_VALUE(val)= -1;
FORK_of_VALUE(val)= -1;
}

/*:1162*//*1166:*/
#line 11740 "./marpa.w"

int marpa_v_new(struct marpa_r*r)
{
BOCAGE b;
TREE tree;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11745 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11747 "./marpa.w"

/*1110:*/
#line 11136 "./marpa.w"

{
b= B_of_R(r);
if(!b){
R_DEV_ERROR("no bocage");
return failure_indicator;
}
}

/*:1110*/
#line 11748 "./marpa.w"

tree= TREE_of_ORDER(ORDER_of_B(b));
if(TREE_is_Exhausted(tree)){
return-1;
}
if(!TREE_is_Initialized(tree))
{
R_DEV_ERROR("tree not initialized");
return failure_indicator;
}
{
VALUE val= VALUE_of_TREE(tree);
const gint minimum_stack_size= (8192/sizeof(gint));
const gint initial_stack_size= 
MAX(Size_of_TREE(tree)/1024,minimum_stack_size);
val_destroy(val);
DSTACK_INIT(VStack_of_VALUE(val),gint,initial_stack_size);
VALUE_is_Active(val)= 1;
}
return 1;
}

/*:1166*//*1168:*/
#line 11772 "./marpa.w"

static inline void val_destroy(VALUE val)
{

if(DSTACK_IS_INITIALIZED(val->t_virtual_stack))
{
DSTACK_DESTROY(val->t_virtual_stack);
DSTACK_SAFE(val->t_virtual_stack);
}
val_safe(val);
}

/*:1168*//*1171:*/
#line 11800 "./marpa.w"

gint marpa_v_trace(struct marpa_r*r,gint flag)
{
BOCAGE b;
TREE tree;
VALUE val;
GRAMMAR g= G_of_R(r);
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11807 "./marpa.w"

/*1169:*/
#line 11785 "./marpa.w"
{
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11786 "./marpa.w"

b= B_of_R(r);
if(!b){
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
val= VALUE_of_TREE(tree);
if(!VALUE_is_Active(val)){
return failure_indicator;
}
}

/*:1169*/
#line 11808 "./marpa.w"

VALUE_is_Trace(val)= flag;
return 1;
}

/*:1171*//*1173:*/
#line 11815 "./marpa.w"

Marpa_Fork_ID marpa_v_fork(struct marpa_r*r)
{
BOCAGE b;
TREE tree;
VALUE val;
/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11821 "./marpa.w"

GRAMMAR g= G_of_R(r);
/*1169:*/
#line 11785 "./marpa.w"
{
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11786 "./marpa.w"

b= B_of_R(r);
if(!b){
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
val= VALUE_of_TREE(tree);
if(!VALUE_is_Active(val)){
return failure_indicator;
}
}

/*:1169*/
#line 11823 "./marpa.w"

return FORK_of_VALUE(val);
}

/*:1173*//*1175:*/
#line 11829 "./marpa.w"

Marpa_Fork_ID marpa_v_event(struct marpa_r*r,Marpa_Event*event)
{
BOCAGE b;
TREE tree;
VALUE val;
AND and_nodes;
gint semantic_rule_id= -1;
gint token_id= -1;
gpointer token_value= NULL;
gint arg_0= -1;
gint arg_n= -1;
FORKID fork_ix;
gint continue_with_next_fork;
GRAMMAR g= G_of_R(r);


/*1311:*/
#line 13085 "./marpa.w"
const int failure_indicator= -2;

/*:1311*/
#line 11846 "./marpa.w"

/*1169:*/
#line 11785 "./marpa.w"
{
/*1325:*/
#line 13165 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1325*/
#line 11786 "./marpa.w"

b= B_of_R(r);
if(!b){
return failure_indicator;
}
tree= TREE_of_ORDER(ORDER_of_B(b));
val= VALUE_of_TREE(tree);
if(!VALUE_is_Active(val)){
return failure_indicator;
}
}

/*:1169*/
#line 11847 "./marpa.w"

and_nodes= ANDs_of_B(b);

arg_0= arg_n= TOS_of_VALUE(val);
fork_ix= FORK_of_VALUE(val);
if(fork_ix<0){
fork_ix= Size_of_TREE(tree);
}
continue_with_next_fork= !VALUE_is_Trace(val);

while(1){
OR or;
RULE fork_rule;
fork_ix--;
if(fork_ix<0)goto RETURN_SOFT_ERROR;
{
ANDID and_node_id;
AND and_node;
const FORK fork= FORK_of_TREE_by_IX(tree,fork_ix);
const gint choice= Choice_of_FORK(fork);
or= OR_of_FORK(fork);
and_node_id= and_order_get(b,or,choice);
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
const DSTACK virtual_stack= &VStack_of_VALUE(val);
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

/*1176:*/
#line 11917 "./marpa.w"

{
SYMID_of_EVE(event)= token_id;
Value_of_EVE(event)= token_value;
RULEID_of_EVE(event)= semantic_rule_id;
TOS_of_VALUE(val)= Arg0_of_EVE(event)= arg_0;
FORK_of_VALUE(val)= fork_ix;
ArgN_of_EVE(event)= arg_n;
}

/*:1176*/
#line 11908 "./marpa.w"

return FORK_of_VALUE(val);

RETURN_SOFT_ERROR:;
/*1176:*/
#line 11917 "./marpa.w"

{
SYMID_of_EVE(event)= token_id;
Value_of_EVE(event)= token_value;
RULEID_of_EVE(event)= semantic_rule_id;
TOS_of_VALUE(val)= Arg0_of_EVE(event)= arg_0;
FORK_of_VALUE(val)= fork_ix;
ArgN_of_EVE(event)= arg_n;
}

/*:1176*/
#line 11912 "./marpa.w"

return-1;

}

/*:1175*//*1179:*/
#line 11951 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1179*//*1181:*/
#line 11959 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:1181*//*1184:*/
#line 11977 "./marpa.w"

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

/*:1184*//*1186:*/
#line 11997 "./marpa.w"

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


/*:1186*//*1187:*/
#line 12018 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:1187*//*1189:*/
#line 12030 "./marpa.w"
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
/*:1189*//*1191:*/
#line 12050 "./marpa.w"
static inline
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}
/*:1191*//*1193:*/
#line 12060 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:1193*//*1195:*/
#line 12069 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:1195*//*1197:*/
#line 12077 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:1197*//*1201:*/
#line 12092 "./marpa.w"

static inline void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1201*//*1203:*/
#line 12108 "./marpa.w"

static inline void bv_over_clear(Bit_Vector bv,guint bit)
{
guint length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1203*//*1205:*/
#line 12116 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:1205*//*1207:*/
#line 12124 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:1207*//*1209:*/
#line 12132 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:1209*//*1213:*/
#line 12143 "./marpa.w"

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

/*:1213*//*1214:*/
#line 12156 "./marpa.w"

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
/*:1214*//*1216:*/
#line 12173 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:1216*//*1218:*/
#line 12185 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:1218*//*1220:*/
#line 12197 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:1220*//*1222:*/
#line 12209 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:1222*//*1224:*/
#line 12221 "./marpa.w"

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
/*:1224*//*1226:*/
#line 12297 "./marpa.w"

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
/*:1226*//*1232:*/
#line 12351 "./marpa.w"

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
/*:1232*//*1237:*/
#line 12430 "./marpa.w"

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
/*:1237*//*1239:*/
#line 12450 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:1239*//*1241:*/
#line 12463 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:1241*//*1243:*/
#line 12480 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:1243*//*1246:*/
#line 12490 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:1246*//*1249:*/
#line 12499 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:1249*//*1252:*/
#line 12508 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:1252*//*1254:*/
#line 12522 "./marpa.w"

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
/*:1254*//*1264:*/
#line 12666 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_bytes){
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}
/*:1264*//*1281:*/
#line 12810 "./marpa.w"

static inline void
psar_init(const PSAR psar,gint length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1281*//*1282:*/
#line 12817 "./marpa.w"

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
/*:1282*//*1283:*/
#line 12834 "./marpa.w"

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
/*:1283*//*1287:*/
#line 12866 "./marpa.w"

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

/*:1287*//*1289:*/
#line 12885 "./marpa.w"

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

/*:1289*//*1291:*/
#line 12907 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar){
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1291*//*1295:*/
#line 12932 "./marpa.w"

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

/*:1295*//*1330:*/
#line 13226 "./marpa.w"

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

/*:1330*//*1336:*/
#line 13346 "./marpa.w"

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

/*:1336*//*1338:*/
#line 13376 "./marpa.w"

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

/*:1338*//*1340:*/
#line 13405 "./marpa.w"

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

/*:1340*//*1342:*/
#line 13440 "./marpa.w"

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


/*:1342*/
#line 13522 "./marpa.w"


/*:1348*/
