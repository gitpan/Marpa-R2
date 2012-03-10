/*1178:*/
#line 13196 "./marpa.w"

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

/*:1178*//*1179:*/
#line 13219 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1165:*/
#line 13041 "./marpa.w"

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

/*:1165*/
#line 13222 "./marpa.w"

#define PRIVATE_NOT_INLINE static
#define PRIVATE static inline \

#define SYM_Count_of_G(g) ((g) ->t_symbols->len) 
#define SYM_by_ID(id) (g_array_index(g->t_symbols,SYM,(id) ) )  \

#define RULE_Count_of_G(g) ((g) ->t_rules->len) 
#define RULE_by_ID(g,id) (g_array_index((g) ->t_rules,RULE,(id) ) )  \

#define RULEID_of_G_is_Valid(g,rule_id)  \
((rule_id) >=0&&(guint) (rule_id) <(g) ->t_rules->len)  \

#define G_is_Trivial(g) (!(g) ->t_proper_start_rule) 
#define Size_of_G(g) ((g) ->t_size) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define G_EVENT_COUNT(g) DSTACK_LENGTH((g) ->t_events) 
#define INITIAL_G_EVENTS_CAPACITY 1
#define G_EVENTS_CLEAR(g) DSTACK_CLEAR((g) ->t_events) 
#define G_EVENT_PUSH(g) DSTACK_PUSH((g) ->t_events,GEV_Object) 
#define I_AM_OK 0x69734f4b
#define IS_G_OK(g) ((g) ->t_is_ok==I_AM_OK) 
#define ID_of_SYM(sym) ((sym) ->t_symbol_id)  \

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
#define RULE_has_Virtual_LHS(rule) ((rule) ->t_is_virtual_lhs) 
#define RULE_has_Virtual_RHS(rule) ((rule) ->t_is_virtual_rhs) 
#define Real_SYM_Count_of_RULE(rule) ((rule) ->t_real_symbol_count) 
#define RULE_is_Ask_Me(rule) ((rule) ->t_is_ask_me) 
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
#define MAX_TOKEN_OR_NODE -2
#define VALUED_TOKEN_OR_NODE -2
#define NULLING_TOKEN_OR_NODE -3
#define UNVALUED_TOKEN_OR_NODE -4
#define OR_is_Token(or) (Type_of_OR(or) <=MAX_TOKEN_OR_NODE) 
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
#define OBS_of_B(b) ((b) ->t_obs) 
#define OBS_of_O(order) ((order) ->t_obs) 
#define O_is_Frozen(o) ((o) ->t_is_frozen) 
#define B_of_O(b) ((b) ->t_bocage) 
#define T_is_Exhausted(tree)  \
(!FSTACK_IS_INITIALIZED((tree) ->t_nook_stack) ) 
#define Size_of_TREE(tree) FSTACK_LENGTH((tree) ->t_nook_stack) 
#define NOOK_of_TREE_by_IX(tree,nook_id)  \
FSTACK_INDEX((tree) ->t_nook_stack,NOOK_Object,nook_id) 
#define O_of_T(t) ((t) ->t_order) 
#define T_is_Paused(t) ((t) ->t_pause_counter> 0) 
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
#define V_is_Trace(val) ((val) ->t_trace) 
#define NOOK_of_V(val) ((val) ->t_nook) 
#define SYMID_of_V(val) ((val) ->public.t_semantic_token_id) 
#define RULEID_of_V(val) ((val) ->public.t_semantic_rule_id) 
#define Token_Value_of_V(val) ((val) ->public.t_token_value) 
#define Token_Type_of_V(val) ((val) ->t_token_type) 
#define TOS_of_V(val) ((val) ->public.t_tos) 
#define Arg_N_of_V(val) ((val) ->public.t_arg_n) 
#define VStack_of_V(val) ((val) ->t_virtual_stack) 
#define T_of_V(v) ((v) ->t_tree) 
#define V_GET_DATA MARPA_VALUE_INTERNAL1 \

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
(sizeof(PSL_Object) +(psar->t_psl_length-1) *sizeof(gpointer) ) 
#define PSL_Datum(psl,i) ((psl) ->t_data[(i) ]) 
#define Dot_PSAR_of_R(r) (&(r) ->t_dot_psar_object) 
#define Dot_PSL_of_ES(es) ((es) ->t_dot_psl) 
#define obstack_chunk_alloc g_malloc
#define obstack_chunk_free g_free \

#define FATAL_FLAG (0x1u) 
#define MARPA_DEV_ERROR(message) (set_error(g,MARPA_ERR_DEVELOPMENT,(message) ,0u) ) 
#define MARPA_INTERNAL_ERROR(message) (set_error(g,MARPA_ERR_INTERNAL,(message) ,0u) ) 
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

#line 13223 "./marpa.w"

#include "marpa_obs.h"
/*1163:*/
#line 12985 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1163*/
#line 13225 "./marpa.w"

/*94:*/
#line 906 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:94*//*118:*/
#line 1079 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:118*//*360:*/
#line 3470 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:360*//*398:*/
#line 3854 "./marpa.w"
struct s_AHFA_state;
/*:398*//*475:*/
#line 4975 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:475*//*581:*/
#line 5660 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:581*//*605:*/
#line 5875 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:605*//*625:*/
#line 6164 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:625*//*628:*/
#line 6199 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:628*//*709:*/
#line 7317 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:709*//*715:*/
#line 7359 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:715*//*813:*/
#line 8522 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:813*//*841:*/
#line 8961 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:841*//*868:*/
#line 9417 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:868*//*894:*/
#line 9839 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:894*//*909:*/
#line 10015 "./marpa.w"

typedef struct s_bocage*BOCAGE;
/*:909*//*922:*/
#line 10121 "./marpa.w"

struct s_bocage_setup_per_es;
/*:922*//*979:*/
#line 10812 "./marpa.w"

typedef Marpa_Tree TREE;
/*:979*//*1013:*/
#line 11252 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1013*//*1026:*/
#line 11388 "./marpa.w"

typedef struct s_value*VALUE;
/*:1026*//*1100:*/
#line 12417 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1100*//*1103:*/
#line 12451 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1103*//*1110:*/
#line 12516 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1110*//*1112:*/
#line 12531 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1112*/
#line 13226 "./marpa.w"

/*40:*/
#line 611 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:40*//*117:*/
#line 1077 "./marpa.w"

typedef gint SYMID;
/*:117*//*170:*/
#line 1469 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:170*//*258:*/
#line 2295 "./marpa.w"
typedef gint SYMI;
/*:258*//*415:*/
#line 3945 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:415*//*476:*/
#line 4980 "./marpa.w"
typedef gint AEX;
/*:476*//*492:*/
#line 5126 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:492*//*507:*/
#line 5220 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:507*//*578:*/
#line 5651 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:578*//*580:*/
#line 5655 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:580*//*656:*/
#line 6581 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:656*//*658:*/
#line 6593 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:658*//*833:*/
#line 8897 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:833*//*867:*/
#line 9405 "./marpa.w"

typedef gint WHEID;


/*:867*//*893:*/
#line 9835 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:893*//*1012:*/
#line 11249 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1012*//*1046:*/
#line 11748 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1046*//*1081:*/
#line 12188 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1081*/
#line 13227 "./marpa.w"

/*34:*/
#line 532 "./marpa.w"

const guint marpa_major_version= MARPA_MAJOR_VERSION;
const guint marpa_minor_version= MARPA_MINOR_VERSION;
const guint marpa_micro_version= MARPA_MICRO_VERSION;
const guint marpa_interface_age= MARPA_INTERFACE_AGE;
const guint marpa_binary_age= MARPA_BINARY_AGE;
/*:34*//*847:*/
#line 9024 "./marpa.w"

static const gint dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:847*//*1047:*/
#line 11755 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1047*/
#line 13228 "./marpa.w"

/*1101:*/
#line 12420 "./marpa.w"

struct s_dstack{gint t_count;gint t_capacity;gpointer t_base;};
/*:1101*/
#line 13229 "./marpa.w"

/*39:*/
#line 605 "./marpa.w"
struct marpa_g{
/*109:*/
#line 1028 "./marpa.w"

gint t_is_ok;

/*:109*/
#line 606 "./marpa.w"

/*50:*/
#line 686 "./marpa.w"
GArray*t_symbols;
/*:50*//*58:*/
#line 723 "./marpa.w"
GArray*t_rules;
/*:58*//*91:*/
#line 894 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:91*//*98:*/
#line 925 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:98*//*105:*/
#line 998 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:105*//*111:*/
#line 1043 "./marpa.w"

const gchar*t_error_string;
/*:111*//*362:*/
#line 3487 "./marpa.w"

AIM t_AHFA_items;
AIM*t_AHFA_items_by_rule;
/*:362*//*416:*/
#line 3949 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:416*/
#line 607 "./marpa.w"

/*44:*/
#line 633 "./marpa.w"
gint t_ref_count;
/*:44*//*67:*/
#line 758 "./marpa.w"
Marpa_Symbol_ID t_original_start_symid;
/*:67*//*71:*/
#line 786 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:71*//*75:*/
#line 815 "./marpa.w"
int t_size;
/*:75*//*78:*/
#line 828 "./marpa.w"
gint t_max_rule_length;
/*:78*//*112:*/
#line 1045 "./marpa.w"

Marpa_Error_Code t_error;
/*:112*//*259:*/
#line 2297 "./marpa.w"

gint t_symbol_instance_count;
/*:259*//*363:*/
#line 3492 "./marpa.w"

guint t_aim_count;
/*:363*//*417:*/
#line 3952 "./marpa.w"
gint t_AHFA_len;
/*:417*/
#line 608 "./marpa.w"

/*81:*/
#line 834 "./marpa.w"
guint t_is_precomputed:1;
/*:81*//*84:*/
#line 846 "./marpa.w"
guint t_has_loop:1;
/*:84*//*87:*/
#line 862 "./marpa.w"
guint t_is_lhs_terminal_ok:1;
/*:87*/
#line 609 "./marpa.w"

};
/*:39*//*97:*/
#line 918 "./marpa.w"

struct s_g_event{
gint t_type;
gint t_value;
};
typedef struct s_g_event GEV_Object;
/*:97*//*119:*/
#line 1092 "./marpa.w"

struct s_symbol{
gint t_or_node_type;
SYMID t_symbol_id;
/*124:*/
#line 1137 "./marpa.w"
GArray*t_lhs;
/*:124*//*129:*/
#line 1183 "./marpa.w"
GArray*t_rhs;
/*:129*//*157:*/
#line 1348 "./marpa.w"

struct s_symbol*t_alias;
/*:157*//*164:*/
#line 1434 "./marpa.w"

RULE t_virtual_lhs_rule;
/*:164*/
#line 1096 "./marpa.w"

/*134:*/
#line 1222 "./marpa.w"
guint t_is_accessible:1;
/*:134*//*137:*/
#line 1244 "./marpa.w"
guint t_is_counted:1;
/*:137*//*140:*/
#line 1258 "./marpa.w"
guint t_is_nullable:1;
/*:140*//*143:*/
#line 1273 "./marpa.w"
guint t_is_nulling:1;
/*:143*//*146:*/
#line 1287 "./marpa.w"
guint t_is_terminal:1;
/*:146*//*150:*/
#line 1312 "./marpa.w"
guint t_is_productive:1;
/*:150*//*153:*/
#line 1327 "./marpa.w"
guint t_is_start:1;
/*:153*//*156:*/
#line 1345 "./marpa.w"

guint t_is_proper_alias:1;
guint t_is_nulling_alias:1;
/*:156*/
#line 1097 "./marpa.w"

};
typedef struct s_symbol SYM_Object;
/*:119*//*169:*/
#line 1460 "./marpa.w"

struct s_rule{
/*194:*/
#line 1860 "./marpa.w"
gint t_rhs_length;
/*:194*//*205:*/
#line 1923 "./marpa.w"
Marpa_Rule_ID t_id;
/*:205*//*235:*/
#line 2132 "./marpa.w"
gint t_virtual_start;
/*:235*//*238:*/
#line 2149 "./marpa.w"
gint t_virtual_end;
/*:238*//*242:*/
#line 2166 "./marpa.w"
Marpa_Rule_ID t_original;
/*:242*//*246:*/
#line 2185 "./marpa.w"
gint t_real_symbol_count;
/*:246*//*249:*/
#line 2211 "./marpa.w"
guint t_is_ask_me:1;
/*:249*//*260:*/
#line 2308 "./marpa.w"

gint t_symbol_instance_base;
gint t_last_proper_symi;
/*:260*/
#line 1462 "./marpa.w"

/*208:*/
#line 1935 "./marpa.w"
guint t_is_discard:1;
/*:208*//*217:*/
#line 2016 "./marpa.w"
guint t_is_loop:1;
/*:217*//*221:*/
#line 2035 "./marpa.w"
guint t_is_virtual_loop:1;
/*:221*//*226:*/
#line 2067 "./marpa.w"
guint t_is_used:1;
/*:226*//*229:*/
#line 2096 "./marpa.w"
guint t_is_virtual_lhs:1;
/*:229*//*232:*/
#line 2113 "./marpa.w"
guint t_is_virtual_rhs:1;
/*:232*//*253:*/
#line 2269 "./marpa.w"
guint t_is_semantic_equivalent:1;
/*:253*/
#line 1463 "./marpa.w"

/*195:*/
#line 1863 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:195*/
#line 1464 "./marpa.w"

};
/*:169*//*359:*/
#line 3464 "./marpa.w"

struct s_AHFA_item{
gint t_sort_key;
/*368:*/
#line 3516 "./marpa.w"

RULE t_rule;

/*:368*/
#line 3467 "./marpa.w"

/*369:*/
#line 3522 "./marpa.w"

gint t_position;

/*:369*//*370:*/
#line 3529 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:370*//*371:*/
#line 3538 "./marpa.w"

gint t_leading_nulls;

/*:371*/
#line 3468 "./marpa.w"

};
/*:359*//*399:*/
#line 3855 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*403:*/
#line 3882 "./marpa.w"

SYMID*t_complete_symbols;

/*:403*//*405:*/
#line 3889 "./marpa.w"

AIM*t_items;
/*:405*//*423:*/
#line 3988 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:423*//*478:*/
#line 4992 "./marpa.w"

TRANS*t_transitions;
/*:478*/
#line 3862 "./marpa.w"

/*402:*/
#line 3880 "./marpa.w"

guint t_complete_symbol_count;
/*:402*//*406:*/
#line 3892 "./marpa.w"

gint t_item_count;
/*:406*//*424:*/
#line 3989 "./marpa.w"
guint t_postdot_sym_count;

/*:424*//*430:*/
#line 4050 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:430*/
#line 3863 "./marpa.w"

/*410:*/
#line 3933 "./marpa.w"

guint t_is_predict:1;

/*:410*//*413:*/
#line 3941 "./marpa.w"

guint t_is_potential_leo_base:1;
/*:413*/
#line 3864 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:399*//*477:*/
#line 4981 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
gint t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:477*//*493:*/
#line 5129 "./marpa.w"

struct s_input{
/*502:*/
#line 5202 "./marpa.w"

struct obstack t_token_obs;

/*:502*//*504:*/
#line 5207 "./marpa.w"

GRAMMAR t_grammar;
/*:504*/
#line 5131 "./marpa.w"

/*496:*/
#line 5148 "./marpa.w"

int t_ref_count;
/*:496*/
#line 5132 "./marpa.w"

};

/*:493*//*582:*/
#line 5666 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:582*//*583:*/
#line 5671 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
gint t_postdot_sym_count;
/*584:*/
#line 5683 "./marpa.w"

gint t_eim_count;
/*:584*//*586:*/
#line 5697 "./marpa.w"

gint t_ordinal;
/*:586*/
#line 5675 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*585:*/
#line 5686 "./marpa.w"

EIM*t_earley_items;

/*:585*//*1120:*/
#line 12601 "./marpa.w"

PSL t_dot_psl;
/*:1120*/
#line 5678 "./marpa.w"

};

/*:583*//*626:*/
#line 6168 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:626*//*629:*/
#line 6202 "./marpa.w"

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

/*:629*//*639:*/
#line 6341 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:639*//*710:*/
#line 7325 "./marpa.w"

struct s_token{
gint t_type;
SYMID t_symbol_id;
gpointer t_value;
};

/*:710*//*716:*/
#line 7369 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:716*//*814:*/
#line 8539 "./marpa.w"

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
/*:814*//*844:*/
#line 8999 "./marpa.w"

struct s_draft_or_node
{
/*843:*/
#line 8993 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:843*/
#line 9002 "./marpa.w"

DAND t_draft_and_node;
};
/*:844*//*845:*/
#line 9005 "./marpa.w"

struct s_final_or_node
{
/*843:*/
#line 8993 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:843*/
#line 9008 "./marpa.w"

gint t_first_and_node_id;
gint t_and_node_count;
};
/*:845*//*846:*/
#line 9016 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:846*//*869:*/
#line 9424 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:869*//*895:*/
#line 9846 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:895*//*923:*/
#line 10123 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:923*//*956:*/
#line 10503 "./marpa.w"

struct s_order{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
/*959:*/
#line 10521 "./marpa.w"

BOCAGE t_bocage;

/*:959*/
#line 10508 "./marpa.w"

/*962:*/
#line 10539 "./marpa.w"
gint t_ref_count;
/*:962*/
#line 10509 "./marpa.w"

guint t_is_frozen:1;
};
/*:956*//*980:*/
#line 10826 "./marpa.w"

/*1014:*/
#line 11263 "./marpa.w"

struct s_nook{
OR t_or_node;
gint t_choice;
NOOKID t_parent;
guint t_is_cause_ready:1;
guint t_is_predecessor_ready:1;
guint t_is_cause_of_parent:1;
guint t_is_predecessor_of_parent:1;
};
typedef struct s_nook NOOK_Object;

/*:1014*/
#line 10827 "./marpa.w"

/*1028:*/
#line 11419 "./marpa.w"

struct s_value{
struct marpa_value public;
DSTACK_DECLARE(t_virtual_stack);
NOOKID t_nook;
Marpa_Tree t_tree;
/*1034:*/
#line 11514 "./marpa.w"

int t_ref_count;
/*:1034*/
#line 11425 "./marpa.w"

gint t_token_type;
gint t_next_value_type;
guint t_trace:1;
};

/*:1028*/
#line 10828 "./marpa.w"

struct s_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,gint)
Bit_Vector t_and_node_in_use;
Marpa_Order t_order;
/*986:*/
#line 10886 "./marpa.w"

gint t_ref_count;
/*:986*//*993:*/
#line 10966 "./marpa.w"
gint t_pause_counter;
/*:993*/
#line 10834 "./marpa.w"

gint t_parse_count;
};

/*:980*//*1104:*/
#line 12454 "./marpa.w"

struct s_dqueue{gint t_current;struct s_dstack t_stack;};

/*:1104*//*1111:*/
#line 12522 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
gpointer t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1111*//*1113:*/
#line 12547 "./marpa.w"

struct s_per_earley_set_arena{
gint t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1113*/
#line 13230 "./marpa.w"

/*508:*/
#line 5223 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*521:*/
#line 5331 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:521*//*533:*/
#line 5394 "./marpa.w"
gpointer*t_sym_workarea;
/*:533*//*537:*/
#line 5405 "./marpa.w"
gpointer*t_workarea2;
/*:537*//*541:*/
#line 5422 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:541*//*545:*/
#line 5448 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:545*//*567:*/
#line 5605 "./marpa.w"
struct obstack t_obs;
/*:567*//*592:*/
#line 5748 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:592*//*613:*/
#line 6010 "./marpa.w"

EIM t_trace_earley_item;
/*:613*//*643:*/
#line 6390 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:643*//*677:*/
#line 6847 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:677*//*717:*/
#line 7377 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:717*//*738:*/
#line 7675 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:738*//*742:*/
#line 7687 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:742*//*746:*/
#line 7699 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:746*//*815:*/
#line 8552 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:815*//*1114:*/
#line 12555 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1114*/
#line 5226 "./marpa.w"

/*511:*/
#line 5255 "./marpa.w"
gint t_ref_count;
/*:511*//*525:*/
#line 5358 "./marpa.w"
gint t_earley_item_warning_threshold;
/*:525*//*529:*/
#line 5381 "./marpa.w"
EARLEME t_furthest_earleme;
/*:529*//*587:*/
#line 5701 "./marpa.w"

gint t_earley_set_count;
/*:587*/
#line 5227 "./marpa.w"

/*518:*/
#line 5323 "./marpa.w"

guint t_input_phase:2;
/*:518*//*559:*/
#line 5543 "./marpa.w"

guint t_use_leo_flag:1;
guint t_is_using_leo:1;
/*:559*//*563:*/
#line 5581 "./marpa.w"
guint t_is_exhausted:1;
/*:563*//*678:*/
#line 6850 "./marpa.w"

guint t_trace_source_type:3;
/*:678*/
#line 5228 "./marpa.w"

};

/*:508*/
#line 13231 "./marpa.w"

/*657:*/
#line 6584 "./marpa.w"

struct s_source{
gpointer t_predecessor;
union{
gpointer t_completion;
TOK t_token;
}t_cause;
};

/*:657*//*659:*/
#line 6596 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:659*//*660:*/
#line 6602 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:660*//*661:*/
#line 6609 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:661*/
#line 13232 "./marpa.w"

/*606:*/
#line 5882 "./marpa.w"

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
/*611:*/
#line 5982 "./marpa.w"

guint t_source_type:3;

/*:611*/
#line 5893 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:606*/
#line 13233 "./marpa.w"

/*910:*/
#line 10017 "./marpa.w"

struct s_bocage{
/*848:*/
#line 9034 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:848*//*912:*/
#line 10026 "./marpa.w"

INPUT t_input;

/*:912*//*914:*/
#line 10036 "./marpa.w"

struct obstack t_obs;
/*:914*/
#line 10019 "./marpa.w"

/*849:*/
#line 9037 "./marpa.w"

gint t_or_node_count;
gint t_and_node_count;
ORID t_top_or_node_id;

/*:849*//*939:*/
#line 10331 "./marpa.w"
gint t_ref_count;
/*:939*/
#line 10020 "./marpa.w"

/*915:*/
#line 10038 "./marpa.w"

unsigned int is_obstack_initialized:1;
/*:915*/
#line 10021 "./marpa.w"

};

/*:910*/
#line 13234 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1166:*/
#line 13072 "./marpa.w"

static gchar*eim_tag_safe(gchar*buffer,EIM eim);
static gchar*eim_tag(EIM eim);
/*:1166*//*1168:*/
#line 13097 "./marpa.w"

static gchar*lim_tag_safe(gchar*buffer,LIM lim);
static gchar*lim_tag(LIM lim);
/*:1168*//*1170:*/
#line 13123 "./marpa.w"

static const gchar*or_tag_safe(gchar*buffer,OR or);
static const gchar*or_tag(OR or);
/*:1170*//*1172:*/
#line 13155 "./marpa.w"

static const gchar*aim_tag_safe(gchar*buffer,AIM aim);
static const gchar*aim_tag(AIM aim);
/*:1172*/
#line 13237 "./marpa.w"

/*1167:*/
#line 13076 "./marpa.w"

static gchar*
eim_tag_safe(gchar*buffer,EIM eim)
{
if(!eim)return"NULL";
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_EIM(eim),Origin_Earleme_of_EIM(eim),
Earleme_of_EIM(eim));
return buffer;
}

static char DEBUG_eim_tag_buffer[1000];
static gchar*
eim_tag(EIM eim)
{
return eim_tag_safe(DEBUG_eim_tag_buffer,eim);
}

/*:1167*//*1169:*/
#line 13102 "./marpa.w"

static gchar*
lim_tag_safe(gchar*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_SYMID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}

static char DEBUG_lim_tag_buffer[1000];
static gchar*
lim_tag(LIM lim)
{
return lim_tag_safe(DEBUG_lim_tag_buffer,lim);
}

/*:1169*//*1171:*/
#line 13127 "./marpa.w"

static const gchar*
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
static const gchar*
or_tag(OR or)
{
return or_tag_safe(DEBUG_or_tag_buffer,or);
}

/*:1171*//*1173:*/
#line 13158 "./marpa.w"

static const gchar*
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
static const gchar*
aim_tag(AIM aim)
{
return aim_tag_safe(DEBUG_aim_tag_buffer,aim);
}

/*:1173*/
#line 13238 "./marpa.w"

#endif
/*35:*/
#line 538 "./marpa.w"

PRIVATE
const gchar*check_alpha_version(
guint required_major,
guint required_minor,
guint required_micro)
{
if(required_major!=MARPA_MAJOR_VERSION)
return"major mismatch in alpha version";
if(required_minor!=MARPA_MINOR_VERSION)
return"minor mismatch in alpha version";
if(required_micro!=MARPA_MICRO_VERSION)
return"micro mismatch in alpha version";
return NULL;
}

/*:35*//*36:*/
#line 554 "./marpa.w"

const gchar*
marpa_check_version(guint required_major,
guint required_minor,
guint required_micro)
{
gint marpa_effective_micro= 
100*MARPA_MINOR_VERSION+MARPA_MICRO_VERSION;
gint required_effective_micro= 100*required_minor+required_micro;

if(required_major<=2)
return check_alpha_version(required_major,required_minor,
required_micro);
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
#line 615 "./marpa.w"

Marpa_Grammar marpa_g_new(guint required_major,
guint required_minor,
guint required_micro)
{
GRAMMAR g;

if(check_alpha_version(required_major,required_minor,required_micro))
return NULL;
g= g_slice_new(struct marpa_g);

g->t_is_ok= 0;
/*45:*/
#line 634 "./marpa.w"

g->t_ref_count= 1;

/*:45*//*51:*/
#line 687 "./marpa.w"

g->t_symbols= g_array_new(FALSE,FALSE,sizeof(SYM));
/*:51*//*59:*/
#line 724 "./marpa.w"

g->t_rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:59*//*68:*/
#line 759 "./marpa.w"

g->t_original_start_symid= -1;
/*:68*//*72:*/
#line 789 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;
/*:72*//*76:*/
#line 816 "./marpa.w"

Size_of_G(g)= 0;

/*:76*//*79:*/
#line 829 "./marpa.w"

g->t_max_rule_length= 0;

/*:79*//*82:*/
#line 835 "./marpa.w"

g->t_is_precomputed= FALSE;
/*:82*//*85:*/
#line 847 "./marpa.w"

g->t_has_loop= FALSE;
/*:85*//*88:*/
#line 863 "./marpa.w"

g->t_is_lhs_terminal_ok= TRUE;
/*:88*//*92:*/
#line 895 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:92*//*99:*/
#line 933 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:99*//*106:*/
#line 1001 "./marpa.w"

obstack_init(&g->t_obs);
obstack_init(&g->t_obs_tricky);
/*:106*//*113:*/
#line 1047 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:113*//*365:*/
#line 3497 "./marpa.w"

g->t_AHFA_items= NULL;
g->t_AHFA_items_by_rule= NULL;
/*:365*//*418:*/
#line 3953 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:418*/
#line 627 "./marpa.w"


g->t_is_ok= I_AM_OK;
return g;
}
/*:42*//*46:*/
#line 644 "./marpa.w"

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
#line 661 "./marpa.w"

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
#line 673 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
/*52:*/
#line 689 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->t_symbols->len;id++)
{symbol_free(SYM_by_ID(id));}}
g_array_free(g->t_symbols,TRUE);

/*:52*//*60:*/
#line 726 "./marpa.w"

g_array_free(g->t_rules,TRUE);

/*:60*//*93:*/
#line 896 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:93*//*100:*/
#line 935 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:100*//*107:*/
#line 1004 "./marpa.w"

obstack_free(&g->t_obs,NULL);
obstack_free(&g->t_obs_tricky,NULL);

/*:107*//*366:*/
#line 3500 "./marpa.w"

if(g->t_AHFA_items){g_free(g->t_AHFA_items);};
if(g->t_AHFA_items_by_rule){g_free(g->t_AHFA_items_by_rule);};

/*:366*//*419:*/
#line 3957 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*420:*/
#line 3967 "./marpa.w"
{
TRANS*ahfa_transitions= TRANSs_of_AHFA(ahfa_state);
if(ahfa_transitions)
g_free(TRANSs_of_AHFA(ahfa_state));
}

/*:420*/
#line 3961 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:419*/
#line 677 "./marpa.w"

g_slice_free(struct marpa_g,g);
}

/*:49*//*54:*/
#line 696 "./marpa.w"

gint marpa_g_symbol_count(struct marpa_g*g){
return SYM_Count_of_G(g);
}

/*:54*//*56:*/
#line 706 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,SYMID symid,SYM symbol)
{
g_array_insert_val(g->t_symbols,(unsigned)symid,symbol);
}

/*:56*//*57:*/
#line 714 "./marpa.w"

PRIVATE gint symbol_is_valid(GRAMMAR g,SYMID symid)
{
return symid>=0&&(guint)symid<g->t_symbols->len;
}

/*:57*//*63:*/
#line 731 "./marpa.w"

gint marpa_g_rule_count(struct marpa_g*g){
return RULE_Count_of_G(g);
}

/*:63*//*65:*/
#line 741 "./marpa.w"

PRIVATE
void rule_add(
GRAMMAR g,
RULEID rule_id,
RULE rule)
{
g_array_insert_val(g->t_rules,(unsigned)rule_id,rule);
Size_of_G(g)+= 1+Length_of_RULE(rule);
g->t_max_rule_length= MAX(Length_of_RULE(rule),g->t_max_rule_length);
}

/*:65*//*69:*/
#line 761 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 764 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 765 "./marpa.w"

return g->t_original_start_symid;
}
/*:69*//*70:*/
#line 770 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 773 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 774 "./marpa.w"

/*1144:*/
#line 12833 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1144*/
#line 775 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 776 "./marpa.w"

return g->t_original_start_symid= symid;
}

/*:70*//*83:*/
#line 837 "./marpa.w"

gint marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 840 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 841 "./marpa.w"

return G_is_Precomputed(g);
}

/*:83*//*86:*/
#line 849 "./marpa.w"

gint marpa_g_has_loop(Marpa_Grammar g)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 852 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 853 "./marpa.w"

return g->t_has_loop;
}

/*:86*//*89:*/
#line 866 "./marpa.w"

gint marpa_g_is_lhs_terminal_ok(Marpa_Grammar g)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 869 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 870 "./marpa.w"

return g->t_is_lhs_terminal_ok;
}
/*:89*//*90:*/
#line 875 "./marpa.w"

gint marpa_g_is_lhs_terminal_ok_set(
struct marpa_g*g,gint value)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 879 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 880 "./marpa.w"

/*1144:*/
#line 12833 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1144*/
#line 881 "./marpa.w"

return g->t_is_lhs_terminal_ok= value?1:0;
}

/*:90*//*102:*/
#line 945 "./marpa.w"

PRIVATE
void event_new(struct marpa_g*g,gint type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:102*//*103:*/
#line 954 "./marpa.w"

PRIVATE
void int_event_new(struct marpa_g*g,gint type,gint value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:103*//*104:*/
#line 964 "./marpa.w"

gint
marpa_g_event(Marpa_Grammar g,Marpa_Event public_event,
gint ix)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 969 "./marpa.w"

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

/*:104*//*115:*/
#line 1058 "./marpa.w"

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

/*:115*//*121:*/
#line 1104 "./marpa.w"

PRIVATE SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= g_malloc(sizeof(SYM_Object));
/*120:*/
#line 1100 "./marpa.w"

symbol->t_or_node_type= NULLING_TOKEN_OR_NODE;
ID_of_SYM(symbol)= g->t_symbols->len;

/*:120*//*125:*/
#line 1138 "./marpa.w"

symbol->t_lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:125*//*130:*/
#line 1184 "./marpa.w"

symbol->t_rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:130*//*135:*/
#line 1223 "./marpa.w"

symbol->t_is_accessible= FALSE;
/*:135*//*138:*/
#line 1245 "./marpa.w"

symbol->t_is_counted= FALSE;
/*:138*//*141:*/
#line 1259 "./marpa.w"

symbol->t_is_nullable= FALSE;
/*:141*//*144:*/
#line 1274 "./marpa.w"

symbol->t_is_nulling= FALSE;
/*:144*//*147:*/
#line 1288 "./marpa.w"

symbol->t_is_terminal= FALSE;
/*:147*//*151:*/
#line 1313 "./marpa.w"

symbol->t_is_productive= FALSE;
/*:151*//*154:*/
#line 1328 "./marpa.w"
symbol->t_is_start= FALSE;
/*:154*//*158:*/
#line 1350 "./marpa.w"

symbol->t_is_proper_alias= FALSE;
symbol->t_is_nulling_alias= FALSE;
symbol->t_alias= NULL;

/*:158*//*165:*/
#line 1436 "./marpa.w"

symbol->t_virtual_lhs_rule= NULL;

/*:165*/
#line 1109 "./marpa.w"

{
SYMID id= ID_of_SYM(symbol);
symbol_add(g,id,symbol);
}
return symbol;
}

/*:121*//*122:*/
#line 1117 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(struct marpa_g*g)
{
SYMID id= ID_of_SYM(symbol_new(g));
return id;
}

/*:122*//*123:*/
#line 1125 "./marpa.w"

PRIVATE void symbol_free(SYM symbol)
{
/*126:*/
#line 1140 "./marpa.w"

g_array_free(symbol->t_lhs,TRUE);

/*:126*//*131:*/
#line 1186 "./marpa.w"
g_array_free(symbol->t_rhs,TRUE);

/*:131*/
#line 1128 "./marpa.w"
g_free(symbol);
}

/*:123*//*127:*/
#line 1143 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_lhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1146 "./marpa.w"

GArray*symbol_lh_rules;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1148 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1149 "./marpa.w"

symbol_lh_rules= SYM_by_ID(symid)->t_lhs;
return symbol_lh_rules->len;
}
Marpa_Rule_ID marpa_g_symbol_lhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1155 "./marpa.w"

GArray*symbol_lh_rules;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1157 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1158 "./marpa.w"

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

/*:127*//*128:*/
#line 1171 "./marpa.w"

PRIVATE
void symbol_lhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{
g_array_append_val(symbol->t_lhs,rule_id);
}

/*:128*//*132:*/
#line 1188 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_rhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1191 "./marpa.w"

GArray*symbol_rh_rules;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1193 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1194 "./marpa.w"

symbol_rh_rules= SYM_by_ID(symid)->t_rhs;
return symbol_rh_rules->len;
}
Marpa_Rule_ID marpa_g_symbol_rhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1200 "./marpa.w"

GArray*symbol_rh_rules;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1202 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1203 "./marpa.w"

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

/*:132*//*133:*/
#line 1216 "./marpa.w"

PRIVATE
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_rhs,rule_id);}

/*:133*//*136:*/
#line 1233 "./marpa.w"

gint marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1236 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1237 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 1238 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1239 "./marpa.w"

return SYM_by_ID(symid)->t_is_accessible;
}

/*:136*//*139:*/
#line 1247 "./marpa.w"

gint marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1251 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1252 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1253 "./marpa.w"

return SYM_by_ID(symid)->t_is_counted;
}

/*:139*//*142:*/
#line 1261 "./marpa.w"

gint marpa_g_symbol_is_nullable(GRAMMAR g,SYMID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1264 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1265 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 1266 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1267 "./marpa.w"

return SYM_by_ID(symid)->t_is_nullable;
}

/*:142*//*145:*/
#line 1276 "./marpa.w"

gint marpa_g_symbol_is_nulling(GRAMMAR g,SYMID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1279 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1280 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 1281 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1282 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));
}

/*:145*//*148:*/
#line 1292 "./marpa.w"

gint marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1296 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1297 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1298 "./marpa.w"

return SYMID_is_Terminal(symid);
}
/*:148*//*149:*/
#line 1301 "./marpa.w"

gint marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,gint value)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1305 "./marpa.w"

/*1144:*/
#line 12833 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1144*/
#line 1306 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1307 "./marpa.w"

return SYMID_is_Terminal(symid)= value;
}

/*:149*//*152:*/
#line 1315 "./marpa.w"

gint marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1320 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 1321 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1322 "./marpa.w"

return SYM_by_ID(symid)->t_is_productive;
}

/*:152*//*155:*/
#line 1329 "./marpa.w"

gint marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1332 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 1333 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1334 "./marpa.w"

return SYM_by_ID(symid)->t_is_start;
}

/*:155*//*159:*/
#line 1359 "./marpa.w"

PRIVATE
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1367 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1368 "./marpa.w"

symbol= SYM_by_ID(symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}

/*:159*//*160:*/
#line 1378 "./marpa.w"

PRIVATE
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1386 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1387 "./marpa.w"

symbol= SYM_by_ID(symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
MARPA_DEV_ERROR("no alias");
return-1;
}
return ID_of_SYM(alias);
}

/*:160*//*162:*/
#line 1403 "./marpa.w"

PRIVATE
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

/*:162*//*167:*/
#line 1444 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_virtual_lhs_rule(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
RULE virtual_lhs_rule;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1449 "./marpa.w"

/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1450 "./marpa.w"

symbol= SYM_by_ID(symid);
virtual_lhs_rule= symbol->t_virtual_lhs_rule;
return virtual_lhs_rule==NULL?-1:ID_of_RULE(virtual_lhs_rule);
}

/*:167*//*173:*/
#line 1481 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length)
{
/*1142:*/
#line 12825 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1142*/
#line 1486 "./marpa.w"

RULE rule;
const gint rule_sizeof= G_STRUCT_OFFSET(struct s_rule,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
/*196:*/
#line 1865 "./marpa.w"

{
SYMID symid= lhs;
/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1868 "./marpa.w"

}
{gint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1146:*/
#line 12843 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1146*/
#line 1873 "./marpa.w"

}
}

/*:196*/
#line 1490 "./marpa.w"

rule= obstack_alloc(&g->t_obs,rule_sizeof);
/*197:*/
#line 1877 "./marpa.w"

Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
{gint i;for(i= 0;i<length;i++){
rule->t_symbols[i+1]= rhs[i];}}
/*:197*/
#line 1492 "./marpa.w"

/*206:*/
#line 1924 "./marpa.w"
rule->t_id= g->t_rules->len;

/*:206*//*209:*/
#line 1936 "./marpa.w"

rule->t_is_discard= FALSE;
/*:209*//*218:*/
#line 2017 "./marpa.w"

rule->t_is_loop= FALSE;
/*:218*//*222:*/
#line 2036 "./marpa.w"

rule->t_is_virtual_loop= FALSE;
/*:222*//*227:*/
#line 2068 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:227*//*230:*/
#line 2097 "./marpa.w"

RULE_has_Virtual_LHS(rule)= FALSE;
/*:230*//*233:*/
#line 2114 "./marpa.w"

RULE_has_Virtual_RHS(rule)= FALSE;
/*:233*//*236:*/
#line 2133 "./marpa.w"
rule->t_virtual_start= -1;
/*:236*//*239:*/
#line 2150 "./marpa.w"
rule->t_virtual_end= -1;
/*:239*//*243:*/
#line 2167 "./marpa.w"
rule->t_original= -1;
/*:243*//*247:*/
#line 2186 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:247*//*250:*/
#line 2212 "./marpa.w"

RULE_is_Ask_Me(rule)= FALSE;
/*:250*//*254:*/
#line 2270 "./marpa.w"

rule->t_is_semantic_equivalent= FALSE;
/*:254*//*261:*/
#line 2311 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:261*/
#line 1493 "./marpa.w"

rule_add(g,rule->t_id,rule);
/*189:*/
#line 1743 "./marpa.w"

symbol_lhs_add(SYM_by_ID(rule->t_symbols[0]),rule->t_id);
if(Length_of_RULE(rule)> 0){
gint rh_list_ix;
const guint alloc_size= Length_of_RULE(rule)*sizeof(SYMID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*193:*/
#line 1810 "./marpa.w"

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

/*:193*/
#line 1751 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(rh_symbol_list[rh_list_ix]),
rule->t_id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:189*/
#line 1495 "./marpa.w"

return rule;
}

/*:173*//*174:*/
#line 1499 "./marpa.w"

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

/*:174*//*175:*/
#line 1519 "./marpa.w"

gint marpa_g_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags)
{
RULE original_rule;
RULEID original_rule_id;
SYM internal_lhs;
SYMID internal_lhs_id,*temp_rhs;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1528 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1529 "./marpa.w"

/*1144:*/
#line 12833 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1144*/
#line 1530 "./marpa.w"

if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE)
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
return failure_indicator;
}
G_EVENTS_CLEAR(g);

/*176:*/
#line 1556 "./marpa.w"

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
int_event_new(g,MARPA_EVENT_NEW_RULE,original_rule_id);
}

/*:176*/
#line 1538 "./marpa.w"

/*177:*/
#line 1571 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
MARPA_DEV_ERROR("bad separator");
return failure_indicator;
}

/*:177*/
#line 1539 "./marpa.w"

/*178:*/
#line 1577 "./marpa.w"

SYM_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(separator_id)->t_is_counted= 1;}
/*:178*/
#line 1540 "./marpa.w"

if(min==0){/*179:*/
#line 1580 "./marpa.w"

{
RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1151:*/
#line 12868 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1151*/
#line 1583 "./marpa.w"
}
rule->t_is_semantic_equivalent= TRUE;
rule->t_original= original_rule_id;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}
/*:179*/
#line 1541 "./marpa.w"
}
min= 1;
/*180:*/
#line 1588 "./marpa.w"

{
internal_lhs= symbol_new(g);
internal_lhs_id= ID_of_SYM(internal_lhs);
int_event_new(g,MARPA_EVENT_NEW_SYMBOL,internal_lhs_id);
}

/*:180*/
#line 1543 "./marpa.w"

/*181:*/
#line 1606 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:181*/
#line 1544 "./marpa.w"

/*183:*/
#line 1609 "./marpa.w"

{
RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1151:*/
#line 12868 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1151*/
#line 1614 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;

RULE_has_Virtual_RHS(rule)= TRUE;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}

/*:183*/
#line 1545 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*184:*/
#line 1623 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1151:*/
#line 12868 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1151*/
#line 1628 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;
RULE_has_Virtual_RHS(rule)= TRUE;
Real_SYM_Count_of_RULE(rule)= 1;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}
/*:184*/
#line 1547 "./marpa.w"

}
/*185:*/
#line 1638 "./marpa.w"

{RULE rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1151:*/
#line 12868 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1151*/
#line 1648 "./marpa.w"
}
RULE_has_Virtual_LHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}
/*:185*/
#line 1549 "./marpa.w"

/*186:*/
#line 1653 "./marpa.w"

{RULE rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1151:*/
#line 12868 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1151*/
#line 1660 "./marpa.w"
}
RULE_has_Virtual_LHS(rule)= 1;
RULE_has_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix-1;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}

/*:186*/
#line 1550 "./marpa.w"

/*182:*/
#line 1608 "./marpa.w"
g_free(temp_rhs);
/*:182*/
#line 1551 "./marpa.w"

return G_EVENT_COUNT(g);
}

/*:175*//*188:*/
#line 1709 "./marpa.w"

PRIVATE
gint is_rule_duplicate(GRAMMAR g,
SYMID lhs_id,SYMID*rhs_ids,gint length)
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

/*:188*//*198:*/
#line 1882 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:198*//*199:*/
#line 1886 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1888 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 1889 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));}
/*:199*//*200:*/
#line 1891 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:200*//*201:*/
#line 1895 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix){
RULE rule;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1898 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 1899 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:201*//*202:*/
#line 1904 "./marpa.w"

PRIVATE gsize rule_length_get(RULE rule)
{
return Length_of_RULE(rule);}
/*:202*//*203:*/
#line 1908 "./marpa.w"

gint marpa_g_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1910 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 1911 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}

/*:203*//*210:*/
#line 1938 "./marpa.w"

gint marpa_g_rule_is_discard_separation(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1943 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 1944 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 1945 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_discard;
}

/*:210*//*213:*/
#line 1976 "./marpa.w"

PRIVATE gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(lhs_id)->t_is_accessible;}
gint marpa_g_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 1983 "./marpa.w"

RULE rule;
/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 1985 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}

/*:213*//*215:*/
#line 1992 "./marpa.w"

PRIVATE gint rule_is_productive(struct marpa_g*g,RULE rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++){
Marpa_Symbol_ID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_by_ID(rhs_id)->t_is_productive)return FALSE;
}
return TRUE;}
gint marpa_g_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2003 "./marpa.w"

RULE rule;
/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2005 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}

/*:215*//*219:*/
#line 2021 "./marpa.w"

gint marpa_g_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2024 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2025 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}

/*:219*//*223:*/
#line 2040 "./marpa.w"

gint marpa_g_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2043 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2044 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;}

/*:223*//*225:*/
#line 2050 "./marpa.w"

PRIVATE gint
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

/*:225*//*228:*/
#line 2072 "./marpa.w"

gint marpa_g_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2075 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2076 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}

/*:228*//*231:*/
#line 2100 "./marpa.w"

gint marpa_g_rule_is_virtual_lhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2105 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 2106 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2107 "./marpa.w"

return RULE_has_Virtual_LHS(RULE_by_ID(g,rule_id));
}

/*:231*//*234:*/
#line 2117 "./marpa.w"

gint marpa_g_rule_is_virtual_rhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2122 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 2123 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2124 "./marpa.w"

return RULE_has_Virtual_RHS(RULE_by_ID(g,rule_id));
}

/*:234*//*237:*/
#line 2134 "./marpa.w"

guint marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2139 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 2140 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2141 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}

/*:237*//*240:*/
#line 2151 "./marpa.w"

guint marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2156 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 2157 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2158 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}

/*:240*//*244:*/
#line 2168 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_original(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2173 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2174 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_original;
}

/*:244*//*248:*/
#line 2187 "./marpa.w"

gint marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2192 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 2193 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2194 "./marpa.w"

return Real_SYM_Count_of_RULE(RULE_by_ID(g,rule_id));
}

/*:248*//*251:*/
#line 2214 "./marpa.w"

gint marpa_g_rule_is_ask_me(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2219 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2220 "./marpa.w"

return RULE_is_Ask_Me(RULE_by_ID(g,rule_id));
}
/*:251*//*252:*/
#line 2239 "./marpa.w"

gint marpa_g_rule_whatever_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2244 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2245 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}
gint marpa_g_rule_ask_me_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2253 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2254 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 1;
}
gint marpa_g_rule_first_child_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2262 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2263 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}

/*:252*//*257:*/
#line 2281 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2286 "./marpa.w"

/*1147:*/
#line 12848 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1147*/
#line 2287 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(RULE_has_Virtual_LHS(rule))return-1;
if(rule->t_is_semantic_equivalent)return rule->t_original;
return rule_id;
}

/*:257*//*263:*/
#line 2325 "./marpa.w"

PRIVATE gint
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

/*:263*//*264:*/
#line 2351 "./marpa.w"

gint marpa_g_precompute(struct marpa_g*g)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 2354 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 2355 "./marpa.w"

G_EVENTS_CLEAR(g);
if(!census(g))return failure_indicator;
if(!CHAF_rewrite(g))return failure_indicator;
if(!g_augment(g))return failure_indicator;
if(!G_is_Trivial(g)){
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*490:*/
#line 5109 "./marpa.w"
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

/*:490*/
#line 2364 "./marpa.w"

}
return G_EVENT_COUNT(g);
}

/*:264*//*266:*/
#line 2401 "./marpa.w"

PRIVATE_NOT_INLINE GRAMMAR census(GRAMMAR g)
{
/*1142:*/
#line 12825 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1142*/
#line 2404 "./marpa.w"

/*267:*/
#line 2432 "./marpa.w"

guint pre_rewrite_rule_count= g->t_rules->len;
guint pre_rewrite_symbol_count= g->t_symbols->len;

/*:267*//*272:*/
#line 2466 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_original_start_symid;
SYM original_start_symbol;

/*:272*//*276:*/
#line 2505 "./marpa.w"

Bit_Vector terminal_v;
gint have_marked_terminals= 0;

/*:276*//*282:*/
#line 2556 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gint have_empty_rule= 0;

/*:282*//*284:*/
#line 2588 "./marpa.w"

Bit_Vector nullable_v;
/*:284*//*288:*/
#line 2613 "./marpa.w"

Bit_Vector productive_v;
/*:288*//*291:*/
#line 2654 "./marpa.w"
Bit_Matrix reach_matrix;
/*:291*//*294:*/
#line 2672 "./marpa.w"

Bit_Vector accessible_v;

/*:294*/
#line 2405 "./marpa.w"

/*268:*/
#line 2436 "./marpa.w"

if(g->t_rules->len<=0){MARPA_ERROR(MARPA_ERR_NO_RULES);return NULL;}
/*:268*/
#line 2406 "./marpa.w"

/*269:*/
#line 2443 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return NULL;}
/*:269*/
#line 2407 "./marpa.w"

/*271:*/
#line 2451 "./marpa.w"

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

/*:271*/
#line 2408 "./marpa.w"

/*273:*/
#line 2470 "./marpa.w"

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
/*:273*/
#line 2409 "./marpa.w"

/*274:*/
#line 2489 "./marpa.w"

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
/*:274*/
#line 2410 "./marpa.w"

if(have_marked_terminals){
/*278:*/
#line 2523 "./marpa.w"

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

/*:278*/
#line 2412 "./marpa.w"

}else{
/*277:*/
#line 2509 "./marpa.w"

if(have_empty_rule&&g->t_is_lhs_terminal_ok){
MARPA_ERROR(MARPA_ERR_NULL_RULE_UNMARKED_TERMINALS);
return NULL;
}
/*:277*/
#line 2414 "./marpa.w"
;
if(g->t_is_lhs_terminal_ok){
/*279:*/
#line 2536 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->t_symbols->len;symid++)
{SYMID_is_Terminal(symid)= 1;}}
/*:279*/
#line 2416 "./marpa.w"

}else{
/*280:*/
#line 2541 "./marpa.w"

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
/*:280*/
#line 2418 "./marpa.w"

}
}
/*283:*/
#line 2561 "./marpa.w"

{
guint min,max,start;
SYMID symid;
gint counted_nullables= 0;
nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2)
{
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;
symid++)
{
SYM symbol= SYM_by_ID(symid);
if(symbol->t_is_counted)
{
counted_nullables++;
int_event_new(g,MARPA_EVENT_COUNTED_NULLABLE,symid);
}
symbol->t_is_nullable= 1;
}
}
if(counted_nullables)
{
MARPA_ERROR(MARPA_ERR_COUNTED_NULLABLE);
return NULL;
}
}
/*:283*/
#line 2421 "./marpa.w"

/*286:*/
#line 2593 "./marpa.w"

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
/*:286*/
#line 2422 "./marpa.w"

/*287:*/
#line 2607 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)original_start_symid))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
return NULL;
}
/*:287*/
#line 2423 "./marpa.w"

/*290:*/
#line 2636 "./marpa.w"

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
/*:290*/
#line 2424 "./marpa.w"

/*293:*/
#line 2658 "./marpa.w"

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
/*:293*/
#line 2425 "./marpa.w"

/*295:*/
#line 2677 "./marpa.w"

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

/*:295*/
#line 2426 "./marpa.w"

/*275:*/
#line 2501 "./marpa.w"

bv_free(terminal_v);
/*:275*//*281:*/
#line 2553 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:281*//*285:*/
#line 2590 "./marpa.w"

bv_free(nullable_v);

/*:285*//*289:*/
#line 2615 "./marpa.w"

bv_free(productive_v);

/*:289*/
#line 2427 "./marpa.w"

/*292:*/
#line 2655 "./marpa.w"

matrix_free(reach_matrix);

/*:292*/
#line 2428 "./marpa.w"

g->t_is_precomputed= TRUE;
return g;
}
/*:266*//*302:*/
#line 2753 "./marpa.w"

PRIVATE struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*303:*/
#line 2774 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:303*//*307:*/
#line 2824 "./marpa.w"

gint factor_count;
gint*factor_positions;
/*:307*//*312:*/
#line 2874 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:312*/
#line 2756 "./marpa.w"

/*308:*/
#line 2827 "./marpa.w"

factor_positions= g_new(gint,g->t_max_rule_length);
/*:308*//*313:*/
#line 2877 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:313*/
#line 2757 "./marpa.w"

/*305:*/
#line 2786 "./marpa.w"

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

/*:305*/
#line 2758 "./marpa.w"

no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const gint rule_length= Length_of_RULE(rule);
gint nullable_suffix_ix= 0;
/*304:*/
#line 2778 "./marpa.w"

if(!RULE_is_Used(rule)){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}

/*:304*/
#line 2764 "./marpa.w"

/*306:*/
#line 2808 "./marpa.w"

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
/*:306*/
#line 2765 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*310:*/
#line 2833 "./marpa.w"

RULE_is_Used(rule)= 0;
{


gint unprocessed_factor_count;

gint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);


gint piece_end,piece_start= 0;
for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*316:*/
#line 2887 "./marpa.w"

SYMID chaf_virtual_symid;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*311:*/
#line 2857 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:311*/
#line 2895 "./marpa.w"

/*317:*/
#line 2914 "./marpa.w"

{
gint remaining_rhs_length,piece_rhs_length;
/*318:*/
#line 2926 "./marpa.w"

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
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 2941 "./marpa.w"

}

/*:318*/
#line 2917 "./marpa.w"
;
/*319:*/
#line 2944 "./marpa.w"

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
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 2962 "./marpa.w"

}

/*:319*/
#line 2918 "./marpa.w"
;
/*320:*/
#line 2967 "./marpa.w"
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
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 2977 "./marpa.w"

}

/*:320*/
#line 2919 "./marpa.w"
;
/*321:*/
#line 2986 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 2991 "./marpa.w"

}

/*:321*/
#line 2920 "./marpa.w"
;
}

/*:317*/
#line 2896 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*311:*/
#line 2857 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:311*/
#line 2901 "./marpa.w"

/*323:*/
#line 2996 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
gint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:323*//*324:*/
#line 3005 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3011 "./marpa.w"


/*:324*//*325:*/
#line 3014 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3019 "./marpa.w"


/*:325*//*326:*/
#line 3022 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3028 "./marpa.w"


/*:326*//*327:*/
#line 3031 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3034 "./marpa.w"


/*:327*//*328:*/
#line 3037 "./marpa.w"
}

/*:328*/
#line 2902 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:316*/
#line 2848 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*329:*/
#line 3041 "./marpa.w"
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

/*:329*//*330:*/
#line 3055 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3060 "./marpa.w"


/*:330*//*331:*/
#line 3063 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3068 "./marpa.w"


/*:331*//*332:*/
#line 3071 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3077 "./marpa.w"


/*:332*//*333:*/
#line 3081 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3085 "./marpa.w"

}

/*:333*//*334:*/
#line 3089 "./marpa.w"
}

/*:334*/
#line 2851 "./marpa.w"

}else{
/*335:*/
#line 3092 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
gint real_symbol_count;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:335*//*336:*/
#line 3103 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3108 "./marpa.w"


/*:336*//*337:*/
#line 3112 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*339:*/
#line 3128 "./marpa.w"

{
const SYM current_lhs= SYM_by_ID(current_lhs_id);
const gint is_virtual_lhs= (piece_start> 0);
RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_has_Virtual_LHS(chaf_rule)= is_virtual_lhs;
chaf_rule->t_is_semantic_equivalent= !is_virtual_lhs;
RULE_has_Virtual_RHS(chaf_rule)= 
Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
current_lhs->t_virtual_lhs_rule= chaf_rule;
}

/*:339*/
#line 3118 "./marpa.w"

}

/*:337*//*338:*/
#line 3122 "./marpa.w"
}

/*:338*/
#line 2853 "./marpa.w"

}
}

/*:310*/
#line 2768 "./marpa.w"

NEXT_RULE:;
}
/*309:*/
#line 2829 "./marpa.w"

g_free(factor_positions);

/*:309*//*314:*/
#line 2880 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:314*/
#line 2771 "./marpa.w"

return g;
}
/*:302*//*340:*/
#line 3147 "./marpa.w"

PRIVATE
SYMID alias_by_id(GRAMMAR g,SYMID proper_id)
{
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
return ID_of_SYM(alias);
}

/*:340*//*342:*/
#line 3158 "./marpa.w"

PRIVATE
GRAMMAR g_augment(GRAMMAR g)
{
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g->t_original_start_symid);
/*343:*/
#line 3173 "./marpa.w"

if(SYM_is_Nulling(old_start)){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:343*/
#line 3167 "./marpa.w"

if(proper_old_start){/*344:*/
#line 3183 "./marpa.w"
{
RULE new_start_rule;
proper_old_start->t_is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= ID_of_SYM(proper_new_start);
proper_new_start->t_is_accessible= TRUE;
proper_new_start->t_is_productive= TRUE;
proper_new_start->t_is_start= TRUE;
new_start_rule= rule_start(g,proper_new_start_id,&ID_of_SYM(old_start),1);
RULE_has_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= 1;
g->t_proper_start_rule= new_start_rule;
}

/*:344*/
#line 3168 "./marpa.w"
}
if(nulling_old_start){/*345:*/
#line 3202 "./marpa.w"
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
SYM_is_Nulling(nulling_new_start)= TRUE;
nulling_new_start->t_is_nullable= TRUE;
nulling_new_start->t_is_productive= TRUE;
nulling_new_start->t_is_accessible= TRUE;
}
nulling_new_start->t_is_start= TRUE;
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
RULE_has_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= FALSE;
g->t_null_start_rule= new_start_rule;
}

/*:345*/
#line 3169 "./marpa.w"
}
return g;
}

/*:342*//*350:*/
#line 3277 "./marpa.w"

PRIVATE
void loop_detect(struct marpa_g*g)
{
gint no_of_rules= RULE_Count_of_G(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_create((guint)no_of_rules,(guint)no_of_rules);
/*351:*/
#line 3301 "./marpa.w"
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

/*:351*/
#line 3285 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*352:*/
#line 3340 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule;
if(!matrix_bit_test(unit_transition_matrix,(guint)rule_id,(guint)rule_id))
continue;
loop_rule_count++;
rule= RULE_by_ID(g,rule_id);
rule->t_is_loop= TRUE;
rule->t_is_virtual_loop= rule->t_virtual_start<0||!RULE_has_Virtual_RHS(rule);
}}

/*:352*/
#line 3287 "./marpa.w"

if(loop_rule_count)
{
g->t_has_loop= TRUE;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
matrix_free(unit_transition_matrix);
}

/*:350*//*367:*/
#line 3505 "./marpa.w"

PRIVATE gint item_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:367*//*372:*/
#line 3542 "./marpa.w"

gint marpa_g_AHFA_item_count(struct marpa_g*g){
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 3544 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 3545 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:372*//*373:*/
#line 3549 "./marpa.w"

Marpa_Rule_ID marpa_g_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 3552 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 3553 "./marpa.w"

/*1148:*/
#line 12853 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1148*/
#line 3554 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(item_id))->t_id;
}

/*:373*//*375:*/
#line 3559 "./marpa.w"

gint marpa_g_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 3562 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 3563 "./marpa.w"

/*1148:*/
#line 12853 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1148*/
#line 3564 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:375*//*377:*/
#line 3569 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 3572 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 3573 "./marpa.w"

/*1148:*/
#line 12853 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1148*/
#line 3574 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:377*//*378:*/
#line 3578 "./marpa.w"

gint marpa_g_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 3581 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 3582 "./marpa.w"

/*1148:*/
#line 12853 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1148*/
#line 3583 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:378*//*380:*/
#line 3594 "./marpa.w"

PRIVATE
void create_AHFA_items(GRAMMAR g)
{
RULEID rule_id;
guint no_of_items;
guint no_of_rules= RULE_Count_of_G(g);
AIM base_item= g_new(struct s_AHFA_item,Size_of_G(g));
AIM current_item= base_item;
guint symbol_instance_of_next_rule= 0;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
if(RULE_is_Used(rule)){
/*381:*/
#line 3619 "./marpa.w"

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
/*382:*/
#line 3643 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:382*/
#line 3630 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*383:*/
#line 3652 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:383*/
#line 3639 "./marpa.w"

current_item++;
}

/*:381*/
#line 3607 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
no_of_items= AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*384:*/
#line 3666 "./marpa.w"

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

/*:384*/
#line 3615 "./marpa.w"

/*389:*/
#line 3738 "./marpa.w"

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

/*:389*/
#line 3616 "./marpa.w"

}

/*:380*//*386:*/
#line 3698 "./marpa.w"

PRIVATE_NOT_INLINE gint cmp_by_aimid(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:386*//*388:*/
#line 3714 "./marpa.w"

PRIVATE_NOT_INLINE gint cmp_by_postdot_and_aimid(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED)
{
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

/*:388*//*400:*/
#line 3871 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*414:*/
#line 3943 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;

/*:414*//*431:*/
#line 4051 "./marpa.w"
Leo_LHS_ID_of_AHFA(ahfa)= -1;
/*:431*/
#line 3874 "./marpa.w"

}

/*:400*//*408:*/
#line 3904 "./marpa.w"

PRIVATE AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM sought_aim)
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

/*:408*//*422:*/
#line 3978 "./marpa.w"

PRIVATE gint AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:422*//*425:*/
#line 3992 "./marpa.w"

gint marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:425*//*426:*/
#line 3997 "./marpa.w"

gint
marpa_g_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 4000 "./marpa.w"

AHFA state;
/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 4002 "./marpa.w"

/*1149:*/
#line 12858 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1149*/
#line 4003 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:426*//*427:*/
#line 4010 "./marpa.w"

Marpa_AHFA_Item_ID marpa_g_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
gint item_ix){
AHFA state;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 4015 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 4016 "./marpa.w"

/*1149:*/
#line 12858 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1149*/
#line 4017 "./marpa.w"

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

/*:427*//*428:*/
#line 4030 "./marpa.w"

gint marpa_g_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 4034 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 4035 "./marpa.w"

/*1149:*/
#line 12858 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1149*/
#line 4036 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:428*//*432:*/
#line 4052 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 4055 "./marpa.w"

AHFA state;
/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 4057 "./marpa.w"

/*1149:*/
#line 12858 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1149*/
#line 4058 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:432*//*435:*/
#line 4079 "./marpa.w"

PRIVATE_NOT_INLINE gint AHFA_state_cmp(
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

/*:435*//*436:*/
#line 4106 "./marpa.w"

PRIVATE_NOT_INLINE
void create_AHFA_states(struct marpa_g*g)
{
/*437:*/
#line 4126 "./marpa.w"

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

/*:437*/
#line 4110 "./marpa.w"

/*438:*/
#line 4141 "./marpa.w"

/*439:*/
#line 4145 "./marpa.w"

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

/*:439*/
#line 4142 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:438*/
#line 4111 "./marpa.w"

/*459:*/
#line 4651 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_create(symbol_count_of_g,symbol_count_of_g);
/*460:*/
#line 4660 "./marpa.w"

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

/*:460*/
#line 4654 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*461:*/
#line 4697 "./marpa.w"
{
AIM*items_by_rule= g->t_AHFA_items_by_rule;
SYMID from_symid;
guint*sort_key_by_rule_id= g_new(guint,rule_count_of_g);
guint no_of_predictable_rules= 0;
/*462:*/
#line 4729 "./marpa.w"

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

/*:462*/
#line 4703 "./marpa.w"

/*463:*/
#line 4749 "./marpa.w"

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

/*:463*/
#line 4704 "./marpa.w"

/*465:*/
#line 4780 "./marpa.w"

{
guint sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:465*/
#line 4705 "./marpa.w"

/*466:*/
#line 4790 "./marpa.w"

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

/*:466*/
#line 4706 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:461*/
#line 4656 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:459*/
#line 4112 "./marpa.w"

/*446:*/
#line 4289 "./marpa.w"

{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
Marpa_Rule_ID start_rule_id= ID_of_RULE(g->t_proper_start_rule);
SYMID*postdot_symbol_ids;
AIM start_item;
AIM*item_list= obstack_alloc(&g->t_obs,sizeof(AIM));

start_item= g->t_AHFA_items_by_rule[start_rule_id];
item_list[0]= start_item;
AHFA_initialize(p_initial_state);
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= 1;
p_initial_state->t_key.t_id= 0;
AHFA_is_Predicted(p_initial_state)= 0;
TRANSs_of_AHFA(p_initial_state)= transitions_new(g);
Postdot_SYM_Count_of_AHFA(p_initial_state)= 1;
postdot_symbol_ids= Postdot_SYMID_Ary_of_AHFA(p_initial_state)= 
obstack_alloc(&g->t_obs,sizeof(SYMID));
*postdot_symbol_ids= Postdot_SYMID_of_AIM(start_item);
Complete_SYM_Count_of_AHFA(p_initial_state)= 0;
p_initial_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(guint)
Postdot_SYMID_of_AIM
(start_item)),rule_by_sort_key,
&states,duplicates);
}

/*:446*/
#line 4113 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*440:*/
#line 4158 "./marpa.w"
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
/*448:*/
#line 4349 "./marpa.w"
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

AHFA_initialize(p_new_state);
singleton_duplicates[single_item_id]= p_new_state;
new_state_item_list= p_new_state->t_items= 
obstack_alloc(&g->t_obs,sizeof(AIM));
new_state_item_list[0]= single_item_p;
p_new_state->t_item_count= 1;
AHFA_is_Predicted(p_new_state)= 0;
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
/*450:*/
#line 4434 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(predot_symid))
> 0)
{
Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:450*/
#line 4402 "./marpa.w"

}
}

/*:448*/
#line 4178 "./marpa.w"

}else{
/*451:*/
#line 4459 "./marpa.w"
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
AHFA_initialize(p_new_state);
AHFA_is_Predicted(p_new_state)= 0;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
/*452:*/
#line 4509 "./marpa.w"

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

/*:452*/
#line 4503 "./marpa.w"

transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
/*454:*/
#line 4589 "./marpa.w"
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

/*:454*/
#line 4506 "./marpa.w"

}

/*:451*/
#line 4180 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:440*/
#line 4115 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*441:*/
#line 4190 "./marpa.w"

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

/*:441*/
#line 4120 "./marpa.w"

/*443:*/
#line 4246 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++)
{
AHFA from_ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(from_ahfa);
AIM*aims= AIMs_of_AHFA(from_ahfa);
gint aim_count= AIM_Count_of_AHFA(from_ahfa);
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

/*:443*/
#line 4121 "./marpa.w"

/*442:*/
#line 4213 "./marpa.w"

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

/*:442*/
#line 4122 "./marpa.w"

/*444:*/
#line 4279 "./marpa.w"

g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*445:*/
#line 4285 "./marpa.w"

g_free(singleton_duplicates);
g_tree_destroy(duplicates);

/*:445*/
#line 4282 "./marpa.w"

obstack_free(&ahfa_work_obs,NULL);

/*:444*/
#line 4123 "./marpa.w"

}

/*:436*//*453:*/
#line 4578 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,GTree*duplicates)
{
const AHFA state_found= g_tree_lookup(duplicates,sought_state);
if(state_found)return state_found;
g_tree_insert(duplicates,sought_state,sought_state);
return NULL;
}

/*:453*//*464:*/
#line 4761 "./marpa.w"

PRIVATE_NOT_INLINE gint
cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data)
{
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

/*:464*//*467:*/
#line 4830 "./marpa.w"

PRIVATE_NOT_INLINE AHFA
create_predicted_AHFA_state(
GRAMMAR g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
)
{
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
AHFA_initialize(p_new_state);
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
p_new_state->t_empty_transition= NULL;
TRANSs_of_AHFA(p_new_state)= transitions_new(g);
Complete_SYM_Count_of_AHFA(p_new_state)= 0;
/*468:*/
#line 4885 "./marpa.w"

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

/*:468*/
#line 4881 "./marpa.w"

return p_new_state;
}

/*:467*//*479:*/
#line 4994 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:479*//*480:*/
#line 5000 "./marpa.w"

PRIVATE gint completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:480*//*481:*/
#line 5007 "./marpa.w"

PRIVATE
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix)
{
URTRANS transition;
transition= obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:481*//*482:*/
#line 5018 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g)
{
gint symbol_count= SYM_Count_of_G(g);
gint symid= 0;
TRANS*transitions;
transitions= g_malloc(symbol_count*sizeof(transitions[0]));
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:482*//*483:*/
#line 5031 "./marpa.w"

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

/*:483*//*484:*/
#line 5045 "./marpa.w"

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

/*:484*//*486:*/
#line 5060 "./marpa.w"

gint marpa_g_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5065 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
gint symbol_count;

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 5071 "./marpa.w"

/*1149:*/
#line 12858 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1149*/
#line 5072 "./marpa.w"

/*1150:*/
#line 12863 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
MARPA_DEV_ERROR("garray size mismatch");
return failure_indicator;
}
/*:1150*/
#line 5073 "./marpa.w"

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

/*:486*//*489:*/
#line 5092 "./marpa.w"

AHFAID marpa_g_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5097 "./marpa.w"

/*1145:*/
#line 12838 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1145*/
#line 5098 "./marpa.w"

/*1149:*/
#line 12858 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1149*/
#line 5099 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:489*//*494:*/
#line 5135 "./marpa.w"

PRIVATE INPUT
input_new(GRAMMAR g)
{
const gint symbol_count_of_g= SYM_Count_of_G(g);
TOK*tokens_by_symid;
INPUT input= g_slice_new(struct s_input);
obstack_init(TOK_Obs_of_I(input));
/*497:*/
#line 5150 "./marpa.w"

input->t_ref_count= 1;

/*:497*//*505:*/
#line 5209 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:505*/
#line 5143 "./marpa.w"

return input;
}

/*:494*//*498:*/
#line 5154 "./marpa.w"

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

/*:498*//*499:*/
#line 5167 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:499*//*500:*/
#line 5180 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
obstack_free(TOK_Obs_of_I(input),NULL);
g_slice_free(struct s_input,input);
}

/*:500*//*509:*/
#line 5237 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
gint symbol_count_of_g;
/*1142:*/
#line 12825 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1142*/
#line 5242 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
r= g_slice_new(struct marpa_r);
symbol_count_of_g= SYM_Count_of_G(g);
/*568:*/
#line 5606 "./marpa.w"
obstack_init(&r->t_obs);
/*:568*/
#line 5249 "./marpa.w"

/*512:*/
#line 5256 "./marpa.w"

r->t_ref_count= 1;

/*:512*//*520:*/
#line 5326 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:520*//*522:*/
#line 5335 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:522*//*526:*/
#line 5359 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:526*//*530:*/
#line 5382 "./marpa.w"
r->t_furthest_earleme= 0;
/*:530*//*534:*/
#line 5395 "./marpa.w"
r->t_sym_workarea= NULL;
/*:534*//*538:*/
#line 5406 "./marpa.w"
r->t_workarea2= NULL;
/*:538*//*542:*/
#line 5426 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:542*//*546:*/
#line 5449 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:546*//*560:*/
#line 5546 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:560*//*564:*/
#line 5582 "./marpa.w"
r->t_is_exhausted= 0;
/*:564*//*588:*/
#line 5703 "./marpa.w"

r->t_earley_set_count= 0;

/*:588*//*593:*/
#line 5750 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:593*//*614:*/
#line 6012 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:614*//*644:*/
#line 6393 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:644*//*679:*/
#line 6852 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:679*//*712:*/
#line 7334 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:712*//*718:*/
#line 7385 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:718*//*739:*/
#line 7676 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:739*//*743:*/
#line 7688 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:743*//*747:*/
#line 7700 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:747*//*816:*/
#line 8558 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:816*//*1115:*/
#line 12557 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1115*/
#line 5250 "./marpa.w"

return r;
}

/*:509*//*513:*/
#line 5260 "./marpa.w"

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

/*:513*//*514:*/
#line 5278 "./marpa.w"

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

/*:514*//*515:*/
#line 5292 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5296 "./marpa.w"

/*517:*/
#line 5313 "./marpa.w"
input_unref(input);

/*:517*//*590:*/
#line 5727 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
if(EIMs_of_ES(set))
g_free(EIMs_of_ES(set));
}
}

/*:590*//*719:*/
#line 7387 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:719*//*741:*/
#line 7681 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:741*//*745:*/
#line 7693 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:745*//*748:*/
#line 7701 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:748*//*817:*/
#line 8560 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:817*//*1116:*/
#line 12559 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1116*/
#line 5297 "./marpa.w"

grammar_unref(g);
if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*544:*/
#line 5435 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:544*//*548:*/
#line 5452 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:548*/
#line 5301 "./marpa.w"

/*569:*/
#line 5607 "./marpa.w"
obstack_free(&r->t_obs,NULL);

/*:569*/
#line 5302 "./marpa.w"

g_slice_free(struct marpa_r,r);
}

/*:515*//*523:*/
#line 5343 "./marpa.w"

guint marpa_r_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:523*//*524:*/
#line 5348 "./marpa.w"

PRIVATE ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:524*//*527:*/
#line 5361 "./marpa.w"

gint marpa_r_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:527*//*528:*/
#line 5367 "./marpa.w"

gint marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,gint threshold)
{
r->t_earley_item_warning_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:528*//*531:*/
#line 5383 "./marpa.w"

guint marpa_r_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:531*//*549:*/
#line 5462 "./marpa.w"

gint marpa_r_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5465 "./marpa.w"

/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5466 "./marpa.w"

guint min,max,start;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 5468 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 5469 "./marpa.w"

/*1158:*/
#line 12907 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
R_DEV_ERROR("garray size mismatch");
return failure_indicator;
}

/*:1158*/
#line 5470 "./marpa.w"

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

/*:549*//*561:*/
#line 5552 "./marpa.w"

gint marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5555 "./marpa.w"

/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5556 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 5557 "./marpa.w"

return r->t_use_leo_flag;
}
/*:561*//*562:*/
#line 5560 "./marpa.w"

gint marpa_r_is_use_leo_set(
Marpa_Recognizer r,gint value)
{
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5564 "./marpa.w"

/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5565 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 5566 "./marpa.w"

/*1152:*/
#line 12876 "./marpa.w"

if(Input_Phase_of_R(r)!=R_BEFORE_INPUT){
R_DEV_ERROR("recce started");
return failure_indicator;
}
/*:1152*/
#line 5567 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:562*//*566:*/
#line 5592 "./marpa.w"

gint marpa_r_is_exhausted(struct marpa_r*r)
{
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5595 "./marpa.w"

/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5596 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 5597 "./marpa.w"

return R_is_Exhausted(r);
}

/*:566*//*571:*/
#line 5611 "./marpa.w"

Marpa_Error_Code marpa_r_error(Marpa_Recognizer r,const char**p_error_string)
{
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5614 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:571*//*573:*/
#line 5620 "./marpa.w"

gint marpa_r_event(Marpa_Recognizer r,Marpa_Event public_event,gint ix)
{
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5623 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:573*//*589:*/
#line 5707 "./marpa.w"

PRIVATE ES
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
/*1121:*/
#line 12603 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1121*/
#line 5722 "./marpa.w"

return set;
}

/*:589*//*594:*/
#line 5753 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5756 "./marpa.w"

/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5757 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 5759 "./marpa.w"

if(!trace_earley_set){
R_DEV_ERROR("no trace es");
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:594*//*595:*/
#line 5767 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5770 "./marpa.w"

/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5771 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 5772 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:595*//*596:*/
#line 5776 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const gint es_does_not_exist= -1;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5780 "./marpa.w"

/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5781 "./marpa.w"

ES earley_set;
/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 5783 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 5784 "./marpa.w"

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

/*:596*//*598:*/
#line 5800 "./marpa.w"

gint marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 5803 "./marpa.w"

ES earley_set;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5805 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 5806 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 5807 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
R_DEV_ERROR("invalid es ordinal");
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:598*//*607:*/
#line 5903 "./marpa.w"

PRIVATE EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1142:*/
#line 12825 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1142*/
#line 5907 "./marpa.w"

/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 5908 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const gint count= ++EIM_Count_of_ES(set);
/*609:*/
#line 5955 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(G_UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
R_FATAL(MARPA_ERR_EIM_COUNT,"eim count exceeds fatal threshold");
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:609*/
#line 5913 "./marpa.w"

new_item= obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:607*//*608:*/
#line 5923 "./marpa.w"

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

/*:608*//*612:*/
#line 5987 "./marpa.w"

PRIVATE_NOT_INLINE const char*invalid_source_type_message(guint type)
{
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

/*:612*//*619:*/
#line 6052 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const gint es_does_not_exist= -1;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6058 "./marpa.w"

/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6059 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6060 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*620:*/
#line 6083 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*646:*/
#line 6432 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:646*/
#line 6086 "./marpa.w"

}

/*:620*/
#line 6067 "./marpa.w"

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

/*:619*//*621:*/
#line 6089 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const gint eim_does_not_exist= -1;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6094 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6098 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6099 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*620:*/
#line 6083 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*646:*/
#line 6432 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:646*/
#line 6086 "./marpa.w"

}

/*:620*/
#line 6103 "./marpa.w"

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

/*:621*//*623:*/
#line 6132 "./marpa.w"

PRIVATE void trace_earley_item_clear(struct marpa_r*r)
{
/*622:*/
#line 6129 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:622*/
#line 6135 "./marpa.w"

trace_source_link_clear(r);
}

/*:623*//*624:*/
#line 6139 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6142 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 6144 "./marpa.w"

if(!item){
/*622:*/
#line 6129 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:622*/
#line 6146 "./marpa.w"

R_DEV_ERROR("no trace eim");
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:624*//*631:*/
#line 6219 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6223 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6226 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6227 "./marpa.w"

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

/*:631*//*632:*/
#line 6241 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6245 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6247 "./marpa.w"

EIM base_earley_item;
/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6249 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:632*//*633:*/
#line 6259 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6263 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6266 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6267 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:633*//*637:*/
#line 6301 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6305 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6307 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6308 "./marpa.w"

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


/*:637*//*641:*/
#line 6357 "./marpa.w"

PRIVATE PIM*
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
/*:641*//*642:*/
#line 6377 "./marpa.w"

PRIVATE PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:642*//*645:*/
#line 6407 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6412 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6416 "./marpa.w"

/*646:*/
#line 6432 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:646*/
#line 6417 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6418 "./marpa.w"

/*1157:*/
#line 12902 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
R_DEV_ERROR("invalid symid");
return failure_indicator;
}
/*:1157*/
#line 6419 "./marpa.w"

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

/*:645*//*647:*/
#line 6442 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6446 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6449 "./marpa.w"

PIM*pim_sym_p;
/*646:*/
#line 6432 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:646*/
#line 6451 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6452 "./marpa.w"

if(!current_earley_set){
/*622:*/
#line 6129 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:622*/
#line 6454 "./marpa.w"

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

/*:647*//*648:*/
#line 6473 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6478 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6482 "./marpa.w"


pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*646:*/
#line 6432 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:646*/
#line 6486 "./marpa.w"

if(!pim_sym_p||!pim){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6491 "./marpa.w"

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

/*:648*//*649:*/
#line 6511 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_postdot_item_symbol(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6514 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6516 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6517 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:649*//*665:*/
#line 6645 "./marpa.w"
PRIVATE
void
token_link_add(RECCE r,
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

/*:665*//*670:*/
#line 6721 "./marpa.w"

PRIVATE
void
completion_link_add(RECCE r,
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

/*:670*//*671:*/
#line 6749 "./marpa.w"

PRIVATE void
leo_link_add(RECCE r,
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

/*:671*//*673:*/
#line 6796 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
guint previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*674:*/
#line 6813 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= new_link;
}

/*:674*/
#line 6804 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*675:*/
#line 6822 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= new_link;
First_Token_Link_of_EIM(item)= NULL;
}

/*:675*/
#line 6806 "./marpa.w"

return;
case SOURCE_IS_LEO:/*676:*/
#line 6831 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= new_link;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= NULL;
}

/*:676*/
#line 6808 "./marpa.w"

return;
}
}

/*:673*//*681:*/
#line 6863 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6866 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6870 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6871 "./marpa.w"

/*695:*/
#line 7090 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:695*/
#line 6872 "./marpa.w"

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

/*:681*//*684:*/
#line 6907 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6910 "./marpa.w"

SRCL full_link;
EIM item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6913 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6914 "./marpa.w"

/*695:*/
#line 7090 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:695*/
#line 6915 "./marpa.w"

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

/*:684*//*686:*/
#line 6938 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6941 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6945 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6946 "./marpa.w"

/*695:*/
#line 7090 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:695*/
#line 6947 "./marpa.w"

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

/*:686*//*689:*/
#line 6981 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 6984 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 6988 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 6989 "./marpa.w"

/*695:*/
#line 7090 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:695*/
#line 6990 "./marpa.w"

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

/*:689*//*691:*/
#line 7014 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_leo_link_trace(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 7018 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7022 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 7023 "./marpa.w"

/*695:*/
#line 7090 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:695*/
#line 7024 "./marpa.w"

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

/*:691*//*694:*/
#line 7060 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_leo_link_trace(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 7064 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7068 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 7069 "./marpa.w"

/*695:*/
#line 7090 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:695*/
#line 7070 "./marpa.w"

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

/*:694*//*696:*/
#line 7099 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:696*//*697:*/
#line 7115 "./marpa.w"

AHFAID marpa_r_source_predecessor_state(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 7118 "./marpa.w"

guint source_type;
SRC source;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7121 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 7122 "./marpa.w"

source_type= r->t_trace_source_type;
/*704:*/
#line 7266 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:704*/
#line 7124 "./marpa.w"

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

/*:697*//*698:*/
#line 7156 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,gpointer*value_p)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 7159 "./marpa.w"

guint source_type;
SRC source;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7162 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 7163 "./marpa.w"

source_type= r->t_trace_source_type;
/*704:*/
#line 7266 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:704*/
#line 7165 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:698*//*700:*/
#line 7188 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 7191 "./marpa.w"

guint source_type;
SRC source;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7194 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 7195 "./marpa.w"

source_type= r->t_trace_source_type;
/*704:*/
#line 7266 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:704*/
#line 7197 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:700*//*703:*/
#line 7234 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 7237 "./marpa.w"

const EARLEME no_predecessor= -1;
guint source_type;
SRC source;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7241 "./marpa.w"

/*1155:*/
#line 12892 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 12893 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 12894 "./marpa.w"


/*:1155*/
#line 7242 "./marpa.w"

source_type= r->t_trace_source_type;
/*704:*/
#line 7266 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:704*/
#line 7244 "./marpa.w"

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

/*:703*//*713:*/
#line 7339 "./marpa.w"

PRIVATE
TOK token_new(INPUT input,SYMID symbol_id,gpointer value)
{
TOK token;
token= obstack_alloc(TOK_Obs_of_I(input),sizeof(*token));
Type_of_TOK(token)= VALUED_TOKEN_OR_NODE;
SYMID_of_TOK(token)= symbol_id;
Value_of_TOK(token)= value;
return token;
}

/*:713*//*721:*/
#line 7393 "./marpa.w"

PRIVATE gint
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

/*:721*//*723:*/
#line 7437 "./marpa.w"

PRIVATE gint alternative_cmp(const ALT_Const a,const ALT_Const b)
{
gint subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:723*//*724:*/
#line 7454 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:724*//*725:*/
#line 7469 "./marpa.w"

PRIVATE gint alternative_insert(RECCE r,ALT new_alternative)
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

/*:725*//*726:*/
#line 7488 "./marpa.w"
gint marpa_r_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7494 "./marpa.w"

const gint symbol_count_of_g= SYM_Count_of_G(g);
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 7496 "./marpa.w"

/*1152:*/
#line 12876 "./marpa.w"

if(Input_Phase_of_R(r)!=R_BEFORE_INPUT){
R_DEV_ERROR("recce started");
return failure_indicator;
}
/*:1152*/
#line 7497 "./marpa.w"

Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g)){
/*565:*/
#line 5583 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:565*/
#line 7500 "./marpa.w"

return TRUE;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
/*539:*/
#line 5407 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*535:*/
#line 5396 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:535*/
#line 5410 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:539*/
#line 7504 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*543:*/
#line 5430 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:543*//*547:*/
#line 5450 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:547*/
#line 7506 "./marpa.w"

/*740:*/
#line 7677 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT(r->t_eim_work_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:740*//*744:*/
#line 7689 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT(r->t_completion_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:744*/
#line 7507 "./marpa.w"

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

/*:726*//*733:*/
#line 7575 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID token_id,
gpointer value,
gint length)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 7582 "./marpa.w"

/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7583 "./marpa.w"

const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1154:*/
#line 12886 "./marpa.w"

if(Input_Phase_of_R(r)!=R_DURING_INPUT){
R_DEV_ERROR("recce not accepting input");
return failure_indicator;
}

/*:1154*/
#line 7589 "./marpa.w"

/*734:*/
#line 7597 "./marpa.w"
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

/*:734*/
#line 7590 "./marpa.w"

/*736:*/
#line 7628 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:736*/
#line 7591 "./marpa.w"

/*735:*/
#line 7613 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
R_DEV_ERROR("parse too long");
return failure_indicator;
}
}

/*:735*/
#line 7592 "./marpa.w"

/*737:*/
#line 7651 "./marpa.w"

{
TOK token= token_new(input,token_id,value);
ALT_Object alternative;
if(Furthest_Earleme_of_R(r)<target_earleme)
Furthest_Earleme_of_R(r)= target_earleme;
alternative.t_token= token;
alternative.t_start_earley_set= current_earley_set;
alternative.t_end_earleme= target_earleme;
if(alternative_insert(r,&alternative)<0)
{
/*714:*/
#line 7354 "./marpa.w"
obstack_free(TOK_Obs_of_R(r),token);

/*:714*/
#line 7662 "./marpa.w"

return duplicate_token_indicator;
}
}

/*:737*/
#line 7593 "./marpa.w"

return current_earleme;
}

/*:733*//*750:*/
#line 7720 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(struct marpa_r*r)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 7724 "./marpa.w"

/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7725 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
gint count_of_expected_terminals;
/*1154:*/
#line 12886 "./marpa.w"

if(Input_Phase_of_R(r)!=R_DURING_INPUT){
R_DEV_ERROR("recce not accepting input");
return failure_indicator;
}

/*:1154*/
#line 7730 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*751:*/
#line 7758 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*565:*/
#line 5583 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:565*/
#line 7762 "./marpa.w"

R_DEV_ERROR("parse exhausted");
return failure_indicator;
}
}

/*:751*/
#line 7734 "./marpa.w"

/*753:*/
#line 7783 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:753*/
#line 7735 "./marpa.w"

/*752:*/
#line 7770 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:752*/
#line 7736 "./marpa.w"

/*754:*/
#line 7789 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*755:*/
#line 7796 "./marpa.w"

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

/*:755*/
#line 7793 "./marpa.w"

}

/*:754*/
#line 7737 "./marpa.w"

/*756:*/
#line 7823 "./marpa.w"
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

/*:756*/
#line 7738 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*757:*/
#line 7842 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*758:*/
#line 7855 "./marpa.w"

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
/*759:*/
#line 7878 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*760:*/
#line 7894 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:760*/
#line 7887 "./marpa.w"

}
/*761:*/
#line 7901 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:761*/
#line 7889 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:759*/
#line 7866 "./marpa.w"

}
else
{
/*762:*/
#line 7911 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*760:*/
#line 7894 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:760*/
#line 7920 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:762*/
#line 7870 "./marpa.w"

break;


}
}
}

/*:758*/
#line 7851 "./marpa.w"

}
}

/*:757*/
#line 7741 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


/*565:*/
#line 5583 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:565*/
#line 7751 "./marpa.w"

event_new(g,MARPA_EVENT_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:750*//*763:*/
#line 7925 "./marpa.w"

PRIVATE void earley_set_update_items(RECCE r,ES set)
{
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

/*:763*//*764:*/
#line 7950 "./marpa.w"

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

/*:764*//*770:*/
#line 7994 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,ES current_earley_set)
{
gpointer*const pim_workarea= r->t_sym_workarea;
/*516:*/
#line 5310 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:516*/
#line 7999 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*771:*/
#line 8016 "./marpa.w"
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
Next_PIM_of_PIM(new_pim)= old_pim;
if(!old_pim)current_earley_set->t_postdot_sym_count++;
pim_workarea[symid]= new_pim;
bv_bit_set(bv_pim_symbols,(guint)symid);
}
}
}

/*:771*/
#line 8005 "./marpa.w"

if(r->t_is_using_leo){
/*775:*/
#line 8074 "./marpa.w"

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
if(EIM_is_Potential_Leo_Base(leo_base))
{
AHFA base_to_ahfa= 
To_AHFA_of_EIM_by_SYMID(leo_base,symid);
if(AHFA_is_Leo_Completion(base_to_ahfa))
{
/*776:*/
#line 8108 "./marpa.w"
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

/*:776*/
#line 8094 "./marpa.w"

}
}
}
}
}
}

/*:775*/
#line 8007 "./marpa.w"

/*785:*/
#line 8193 "./marpa.w"
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

/*788:*/
#line 8252 "./marpa.w"
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

/*:788*/
#line 8211 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*794:*/
#line 8344 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:794*/
#line 8213 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*796:*/
#line 8365 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:796*/
#line 8219 "./marpa.w"

continue;
}
/*789:*/
#line 8267 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*792:*/
#line 8288 "./marpa.w"
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

/*788:*/
#line 8252 "./marpa.w"
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

/*:788*/
#line 8314 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:792*/
#line 8270 "./marpa.w"

/*793:*/
#line 8333 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*794:*/
#line 8344 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:794*/
#line 8337 "./marpa.w"

}else{
/*796:*/
#line 8365 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:796*/
#line 8339 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:793*/
#line 8271 "./marpa.w"

}

/*:789*/
#line 8222 "./marpa.w"

}
}
}

/*:785*/
#line 8008 "./marpa.w"

}
/*797:*/
#line 8371 "./marpa.w"
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

/*:797*/
#line 8010 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:770*//*818:*/
#line 8563 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:818*//*819:*/
#line 8571 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:819*//*820:*/
#line 8577 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)obstack_free(&stack->t_obs,NULL);
stack->t_base= NULL;
}

/*:820*//*821:*/
#line 8584 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:821*//*822:*/
#line 8594 "./marpa.w"

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

/*:822*//*823:*/
#line 8610 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:823*//*827:*/
#line 8673 "./marpa.w"

PRIVATE gint psia_test_and_set(
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

/*:827*//*863:*/
#line 9301 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:863*//*864:*/
#line 9313 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:864*//*870:*/
#line 9432 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause);
return draft_and_node;
}

/*:870*//*872:*/
#line 9455 "./marpa.w"

PRIVATE
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:872*//*899:*/
#line 9899 "./marpa.w"

gint marpa_b_and_node_count(Marpa_Bocage b)
{
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 9902 "./marpa.w"

/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 9903 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 9904 "./marpa.w"

return AND_Count_of_B(b);
}

/*:899*//*901:*/
#line 9925 "./marpa.w"

gint marpa_b_and_node_parent(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 9929 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 9930 "./marpa.w"

/*900:*/
#line 9908 "./marpa.w"
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

/*:900*/
#line 9931 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:901*//*902:*/
#line 9935 "./marpa.w"

gint marpa_b_and_node_predecessor(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 9939 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 9940 "./marpa.w"

/*900:*/
#line 9908 "./marpa.w"
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

/*:900*/
#line 9941 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:902*//*903:*/
#line 9950 "./marpa.w"

gint marpa_b_and_node_cause(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 9954 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 9955 "./marpa.w"

/*900:*/
#line 9908 "./marpa.w"
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

/*:900*/
#line 9956 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:903*//*904:*/
#line 9965 "./marpa.w"

gint marpa_b_and_node_symbol(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 9969 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 9970 "./marpa.w"

/*900:*/
#line 9908 "./marpa.w"
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

/*:900*/
#line 9971 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:904*//*905:*/
#line 9980 "./marpa.w"

Marpa_Symbol_ID marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,gpointer*value_p)
{
TOK token;
AND and_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 9986 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 9987 "./marpa.w"

/*900:*/
#line 9908 "./marpa.w"
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

/*:900*/
#line 9988 "./marpa.w"

token= and_node_token(and_node);
if(token){
if(value_p)
*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
return-1;
}
/*:905*//*906:*/
#line 9997 "./marpa.w"

PRIVATE TOK and_node_token(AND and_node)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
return TOK_of_OR(cause_or);
}
return NULL;
}

/*:906*//*920:*/
#line 10061 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Rule_ID rule_id,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1142:*/
#line 12825 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1142*/
#line 10066 "./marpa.w"

/*921:*/
#line 10105 "./marpa.w"

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

/*:921*//*924:*/
#line 10129 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:924*/
#line 10067 "./marpa.w"

INPUT input;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10069 "./marpa.w"

/*1153:*/
#line 12881 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1153*/
#line 10070 "./marpa.w"

b= g_slice_new(struct s_bocage);
/*850:*/
#line 9042 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;

/*:850*//*916:*/
#line 10040 "./marpa.w"

b->is_obstack_initialized= 1;
obstack_init(&OBS_of_B(b));
/*:916*//*940:*/
#line 10332 "./marpa.w"

b->t_ref_count= 1;

/*:940*/
#line 10072 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
r_update_earley_sets(r);
/*925:*/
#line 10132 "./marpa.w"

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

/*:925*/
#line 10081 "./marpa.w"

if(end_of_parse_earleme==0){
if(!g->t_null_start_rule)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
/*926:*/
#line 10153 "./marpa.w"

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

/*:926*/
#line 10086 "./marpa.w"

/*932:*/
#line 10262 "./marpa.w"

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

/*:932*/
#line 10087 "./marpa.w"

if(!start_eim)goto B_NEW_RETURN_ERROR;
obstack_init(&bocage_setup_obs);
/*929:*/
#line 10210 "./marpa.w"

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

/*:929*/
#line 10090 "./marpa.w"

/*825:*/
#line 8632 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*826:*/
#line 8660 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:826*/
#line 8641 "./marpa.w"

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
/*828:*/
#line 8701 "./marpa.w"

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
/*826:*/
#line 8660 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:826*/
#line 8729 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:828*/
#line 8654 "./marpa.w"

/*830:*/
#line 8770 "./marpa.w"

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
/*826:*/
#line 8660 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:826*/
#line 8806 "./marpa.w"

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
/*826:*/
#line 8660 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:826*/
#line 8819 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:830*/
#line 8655 "./marpa.w"

/*831:*/
#line 8829 "./marpa.w"

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
/*826:*/
#line 8660 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:826*/
#line 8862 "./marpa.w"

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
/*826:*/
#line 8660 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:826*/
#line 8878 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:831*/
#line 8656 "./marpa.w"

}
}

/*:825*/
#line 10091 "./marpa.w"

/*852:*/
#line 9065 "./marpa.w"

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
/*1127:*/
#line 12660 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1127*/
#line 9085 "./marpa.w"

/*853:*/
#line 9093 "./marpa.w"

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
/*854:*/
#line 9113 "./marpa.w"

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
/*1127:*/
#line 12660 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1127*/
#line 9126 "./marpa.w"

/*856:*/
#line 9144 "./marpa.w"

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
/*857:*/
#line 9174 "./marpa.w"

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


/*:857*/
#line 9155 "./marpa.w"

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

/*:856*/
#line 9127 "./marpa.w"

/*859:*/
#line 9199 "./marpa.w"

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
const OR cause= (OR)TOK_by_SYMID(RHS_ID_of_RULE(rule,rhs_ix));
/*857:*/
#line 9174 "./marpa.w"

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


/*:857*/
#line 9223 "./marpa.w"

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

/*:859*/
#line 9128 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*860:*/
#line 9243 "./marpa.w"
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
/*862:*/
#line 9283 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const gint ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const gint symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*865:*/
#line 9324 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1127:*/
#line 12660 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1127*/
#line 9331 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*857:*/
#line 9174 "./marpa.w"

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


/*:857*/
#line 9335 "./marpa.w"

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

/*:865*/
#line 9293 "./marpa.w"

/*866:*/
#line 9353 "./marpa.w"

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
const OR cause= (OR)TOK_by_SYMID(RHS_ID_of_RULE(path_rule,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_RULE(path_rule))
MARPA_ASSERT(symbol_instance>=0)
/*857:*/
#line 9174 "./marpa.w"

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


/*:857*/
#line 9370 "./marpa.w"

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

/*:866*/
#line 9294 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:862*/
#line 9265 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:860*/
#line 9136 "./marpa.w"

}

/*:854*/
#line 9107 "./marpa.w"

}
}
}
}

/*:853*/
#line 9086 "./marpa.w"

/*873:*/
#line 9465 "./marpa.w"

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
/*875:*/
#line 9502 "./marpa.w"

{
guint work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const gint work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*876:*/
#line 9518 "./marpa.w"
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
#line 9550 "./marpa.w"

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
/*878:*/
#line 9579 "./marpa.w"

{
if(higher_path_leo_item){
/*882:*/
#line 9627 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:882*/
#line 9582 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:878*/
#line 9565 "./marpa.w"

/*880:*/
#line 9593 "./marpa.w"

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

/*:880*/
#line 9566 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*878:*/
#line 9579 "./marpa.w"

{
if(higher_path_leo_item){
/*882:*/
#line 9627 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:882*/
#line 9582 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:878*/
#line 9573 "./marpa.w"

/*883:*/
#line 9637 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const gint origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
MARPA_OFF_DEBUG2("lim=%s",lim_tag(path_leo_item));
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:883*/
#line 9574 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:877*/
#line 9540 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:876*/
#line 9513 "./marpa.w"

/*884:*/
#line 9648 "./marpa.w"

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
/*885:*/
#line 9678 "./marpa.w"

{
OR dand_predecessor;
/*886:*/
#line 9687 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:886*/
#line 9681 "./marpa.w"

MARPA_OFF_DEBUG2("or=%s",or_tag(work_proper_or_node));
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:885*/
#line 9670 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:884*/
#line 9514 "./marpa.w"

/*887:*/
#line 9698 "./marpa.w"

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
/*888:*/
#line 9738 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const gint middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*886:*/
#line 9687 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:886*/
#line 9746 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
MARPA_OFF_DEBUG2("completion source, or=%s",or_tag(work_proper_or_node));
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:888*/
#line 9729 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:887*/
#line 9515 "./marpa.w"

}

/*:875*/
#line 9480 "./marpa.w"

}
}
}
}
}

/*:873*/
#line 9087 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= g_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:852*/
#line 10092 "./marpa.w"

/*896:*/
#line 9854 "./marpa.w"

{
gint unique_draft_and_node_count= 0;
/*889:*/
#line 9753 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const gint or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
gint or_node_id= 0;
psar_init(and_psar,rule_count_of_g+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*891:*/
#line 9785 "./marpa.w"

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

/*:891*/
#line 9763 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:889*/
#line 9857 "./marpa.w"

/*897:*/
#line 9861 "./marpa.w"

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

/*:897*/
#line 9858 "./marpa.w"

}

/*:896*/
#line 10093 "./marpa.w"

/*933:*/
#line 10290 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const gint start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:933*/
#line 10094 "./marpa.w"
;
obstack_free(&bocage_setup_obs,NULL);
return b;
B_NEW_RETURN_ERROR:;
input_unref(input);
if(b){
/*943:*/
#line 10369 "./marpa.w"

/*851:*/
#line 9048 "./marpa.w"

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

/*:851*/
#line 10370 "./marpa.w"
;
/*917:*/
#line 10043 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:917*/
#line 10371 "./marpa.w"
;

/*:943*/
#line 10100 "./marpa.w"
;
}
return NULL;
}

/*:920*//*928:*/
#line 10177 "./marpa.w"

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
(OR)TOK_by_SYMID(RHS_ID_of_RULE(null_start_rule,rule_length-1));

return b;
}

/*:928*//*935:*/
#line 10313 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10316 "./marpa.w"

return g;
}

/*:935*//*937:*/
#line 10321 "./marpa.w"

Marpa_Or_Node_ID marpa_b_top_or_node(Marpa_Bocage b)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10324 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10325 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10326 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:937*//*941:*/
#line 10336 "./marpa.w"

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

/*:941*//*942:*/
#line 10354 "./marpa.w"

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

/*:942*//*944:*/
#line 10376 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10380 "./marpa.w"

input_unref(input);
if(b)
{
/*943:*/
#line 10369 "./marpa.w"

/*851:*/
#line 9048 "./marpa.w"

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

/*:851*/
#line 10370 "./marpa.w"
;
/*917:*/
#line 10043 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:917*/
#line 10371 "./marpa.w"
;

/*:943*/
#line 10384 "./marpa.w"
;
g_slice_free(struct s_bocage,b);
}
}

/*:944*//*947:*/
#line 10409 "./marpa.w"

gint marpa_b_or_node_set(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10413 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10414 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10415 "./marpa.w"

/*946:*/
#line 10392 "./marpa.w"
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

/*:946*/
#line 10416 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:947*//*948:*/
#line 10420 "./marpa.w"

gint marpa_b_or_node_origin(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10424 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10425 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10426 "./marpa.w"

/*946:*/
#line 10392 "./marpa.w"
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

/*:946*/
#line 10427 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:948*//*949:*/
#line 10431 "./marpa.w"

gint marpa_b_or_node_rule(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10435 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10436 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10437 "./marpa.w"

/*946:*/
#line 10392 "./marpa.w"
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

/*:946*/
#line 10438 "./marpa.w"

return ID_of_RULE(RULE_of_OR(or_node));
}

/*:949*//*950:*/
#line 10442 "./marpa.w"

gint marpa_b_or_node_position(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10446 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10447 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10448 "./marpa.w"

/*946:*/
#line 10392 "./marpa.w"
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

/*:946*/
#line 10449 "./marpa.w"

return Position_of_OR(or_node);
}

/*:950*//*951:*/
#line 10453 "./marpa.w"

gint marpa_b_or_node_first_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10457 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10458 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10459 "./marpa.w"

/*946:*/
#line 10392 "./marpa.w"
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

/*:946*/
#line 10460 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:951*//*952:*/
#line 10464 "./marpa.w"

gint marpa_b_or_node_last_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10468 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10469 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10470 "./marpa.w"

/*946:*/
#line 10392 "./marpa.w"
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

/*:946*/
#line 10471 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:952*//*953:*/
#line 10476 "./marpa.w"

gint marpa_b_or_node_and_count(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10480 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10481 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10482 "./marpa.w"

/*946:*/
#line 10392 "./marpa.w"
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

/*:946*/
#line 10483 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:953*//*960:*/
#line 10524 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1142:*/
#line 12825 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1142*/
#line 10527 "./marpa.w"

/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10528 "./marpa.w"

ORDER o;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10530 "./marpa.w"

o= g_slice_new(struct s_order);
B_of_O(o)= b;
bocage_ref(b);
/*957:*/
#line 10512 "./marpa.w"

{
o->t_and_node_in_use= NULL;
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
}

/*:957*//*963:*/
#line 10540 "./marpa.w"

o->t_ref_count= 1;

/*:963*/
#line 10534 "./marpa.w"

return o;
}

/*:960*//*964:*/
#line 10544 "./marpa.w"

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

/*:964*//*965:*/
#line 10562 "./marpa.w"

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

/*:965*//*966:*/
#line 10576 "./marpa.w"

PRIVATE void order_strip(ORDER o)
{
if(o->t_and_node_in_use)
{
bv_free(o->t_and_node_in_use);
o->t_and_node_in_use= NULL;
}
}
/*:966*//*967:*/
#line 10585 "./marpa.w"

PRIVATE void order_freeze(ORDER o)
{
order_strip(o);
O_is_Frozen(o)= 0;
}
/*:967*//*968:*/
#line 10591 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10594 "./marpa.w"

bocage_unref(b);
order_strip(o);
if(o->t_and_node_orderings){
o->t_and_node_orderings= NULL;
obstack_free(&OBS_of_O(o),NULL);
}
g_slice_free(struct s_order,o);
}

/*:968*//*971:*/
#line 10620 "./marpa.w"

Marpa_Grammar marpa_o_g(Marpa_Order o)
{
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10623 "./marpa.w"

return g;
}

/*:971*//*975:*/
#line 10676 "./marpa.w"

gint marpa_o_and_order_set(
Marpa_Order o,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length)
{
OR or_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10684 "./marpa.w"

/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10685 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10686 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*946:*/
#line 10392 "./marpa.w"
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

/*:946*/
#line 10692 "./marpa.w"

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

/*:975*//*976:*/
#line 10756 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,gint ix)
{
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10759 "./marpa.w"

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

/*:976*//*977:*/
#line 10781 "./marpa.w"

Marpa_And_Node_ID marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,gint ix)
{
OR or_node;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 10786 "./marpa.w"

/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10787 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10788 "./marpa.w"

/*946:*/
#line 10392 "./marpa.w"
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

/*:946*/
#line 10789 "./marpa.w"

if(ix<0){
MARPA_DEV_ERROR("negative and ix");
return failure_indicator;
}
return and_order_get(o,or_node,ix);
}

/*:977*//*982:*/
#line 10842 "./marpa.w"

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
if(t->t_and_node_in_use){
bv_free(t->t_and_node_in_use);
t->t_and_node_in_use= NULL;
}
}

/*:982*//*983:*/
#line 10861 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1142:*/
#line 12825 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1142*/
#line 10864 "./marpa.w"

TREE t;
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10866 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 10867 "./marpa.w"

t= g_slice_new(struct s_tree);
O_of_T(t)= o;
order_ref(o);
order_freeze(o);
/*984:*/
#line 10876 "./marpa.w"

{
const gint and_count= AND_Count_of_B(b);
t->t_parse_count= 0;
t->t_and_node_in_use= bv_create((guint)and_count);
FSTACK_INIT(t->t_nook_stack,NOOK_Object,and_count);
FSTACK_INIT(t->t_nook_worklist,gint,and_count);
}

/*:984*//*987:*/
#line 10888 "./marpa.w"

t->t_ref_count= 1;

/*:987*//*994:*/
#line 10967 "./marpa.w"
t->t_pause_counter= 0;
/*:994*/
#line 10872 "./marpa.w"

return t;
}

/*:983*//*988:*/
#line 10892 "./marpa.w"

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

/*:988*//*989:*/
#line 10910 "./marpa.w"

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

/*:989*//*990:*/
#line 10924 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
g_slice_free(struct s_tree,t);
}

/*:990*//*995:*/
#line 10968 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:995*//*996:*/
#line 10977 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:996*//*998:*/
#line 10999 "./marpa.w"

Marpa_Grammar marpa_t_g(Marpa_Tree t)
{
/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11002 "./marpa.w"

return g;
}

/*:998*//*999:*/
#line 11006 "./marpa.w"

gint marpa_t_next(Marpa_Tree t)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11009 "./marpa.w"

gint is_first_tree_attempt= 0;
/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11011 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11012 "./marpa.w"

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
/*1004:*/
#line 11070 "./marpa.w"

{
ORID top_or_id= Top_ORID_of_B(b);
OR top_or_node= OR_of_B_by_ID(b,top_or_id);
NOOK nook;
gint choice;
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

/*:1004*/
#line 11025 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
}else{
/*1005:*/
#line 11095 "./marpa.w"
{
while(1){
NOOK iteration_candidate= FSTACK_TOP(t->t_nook_stack,NOOK_Object);
gint choice;
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

const gint parent_nook_ix= Parent_of_NOOK(iteration_candidate);
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
gint stack_length= Size_of_T(t);
gint i;
if(stack_length<=0)goto TREE_IS_EXHAUSTED;
FSTACK_CLEAR(t->t_nook_worklist);
for(i= 0;i<stack_length;i++){
*(FSTACK_PUSH(t->t_nook_worklist))= i;
}
}
}

/*:1005*/
#line 11032 "./marpa.w"

}
/*1006:*/
#line 11147 "./marpa.w"
{
while(1){
NOOKID*p_work_nook_id;
NOOK work_nook;
ANDID work_and_node_id;
AND work_and_node;
OR work_or_node;
OR child_or_node= NULL;
gint choice;
gint child_is_cause= 0;
gint child_is_predecessor= 0;
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
/*1008:*/
#line 11208 "./marpa.w"

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

/*:1008*/
#line 11189 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1006*/
#line 11034 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return-1;

}

/*:999*//*1001:*/
#line 11050 "./marpa.w"

PRIVATE void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1001*//*1002:*/
#line 11056 "./marpa.w"

PRIVATE void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1002*//*1003:*/
#line 11064 "./marpa.w"

PRIVATE gint tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(guint)and_node_id);
}

/*:1003*//*1007:*/
#line 11195 "./marpa.w"

PRIVATE gint or_node_next_choice(ORDER o,TREE tree,OR or_node,gint start_choice)
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

/*:1007*//*1009:*/
#line 11226 "./marpa.w"

gint marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1009*//*1010:*/
#line 11234 "./marpa.w"

gint marpa_t_size(Marpa_Tree t)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11237 "./marpa.w"

/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11238 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11239 "./marpa.w"

if(T_is_Exhausted(t)){
return-1;
}
return Size_of_T(t);
}

/*:1010*//*1017:*/
#line 11297 "./marpa.w"

gint marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11301 "./marpa.w"

/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11302 "./marpa.w"

/*1016:*/
#line 11279 "./marpa.w"
{
NOOK base_nook;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11281 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1016*/
#line 11303 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1017*//*1018:*/
#line 11307 "./marpa.w"

gint marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11311 "./marpa.w"

/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11312 "./marpa.w"

/*1016:*/
#line 11279 "./marpa.w"
{
NOOK base_nook;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11281 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1016*/
#line 11313 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1018*//*1019:*/
#line 11317 "./marpa.w"

gint marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11321 "./marpa.w"

/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11322 "./marpa.w"

/*1016:*/
#line 11279 "./marpa.w"
{
NOOK base_nook;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11281 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1016*/
#line 11323 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1019*//*1020:*/
#line 11327 "./marpa.w"

gint marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11331 "./marpa.w"

/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11332 "./marpa.w"

/*1016:*/
#line 11279 "./marpa.w"
{
NOOK base_nook;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11281 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1016*/
#line 11333 "./marpa.w"

return NOOK_Cause_is_Ready(nook);
}

/*:1020*//*1021:*/
#line 11337 "./marpa.w"

gint marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11341 "./marpa.w"

/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11342 "./marpa.w"

/*1016:*/
#line 11279 "./marpa.w"
{
NOOK base_nook;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11281 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1016*/
#line 11343 "./marpa.w"

return NOOK_Predecessor_is_Ready(nook);
}

/*:1021*//*1022:*/
#line 11347 "./marpa.w"

gint marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11351 "./marpa.w"

/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11352 "./marpa.w"

/*1016:*/
#line 11279 "./marpa.w"
{
NOOK base_nook;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11281 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1016*/
#line 11353 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1022*//*1023:*/
#line 11357 "./marpa.w"

gint marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11361 "./marpa.w"

/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11362 "./marpa.w"

/*1016:*/
#line 11279 "./marpa.w"
{
NOOK base_nook;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11281 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_DEV_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
if(nook_id<0){
MARPA_DEV_ERROR("bad nook id");
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
nook= base_nook+nook_id;
}

/*:1016*/
#line 11363 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1023*//*1032:*/
#line 11487 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1142:*/
#line 12825 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1142*/
#line 11490 "./marpa.w"

/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11491 "./marpa.w"
;
/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11492 "./marpa.w"

if(!T_is_Exhausted(t))
{
VALUE v= g_slice_new(struct s_value);
const gint minimum_stack_size= (8192/sizeof(gint));
const gint initial_stack_size= 
MAX(Size_of_TREE(t)/1024,minimum_stack_size);
DSTACK_INIT(VStack_of_V(v),gint,initial_stack_size);
Next_Value_Type_of_V(v)= V_GET_DATA;
V_is_Trace(v)= 1;
TOS_of_V(v)= -1;
NOOK_of_V(v)= -1;
/*1035:*/
#line 11516 "./marpa.w"

v->t_ref_count= 1;

/*:1035*/
#line 11504 "./marpa.w"

tree_pause(t);
T_of_V(v)= t;
return v;
}
MARPA_DEV_ERROR("tree is exhausted");
return NULL;
}

/*:1032*//*1036:*/
#line 11520 "./marpa.w"

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
marpa_v_unref(Marpa_Value v)
{
value_unref(v);
}

/*:1036*//*1037:*/
#line 11538 "./marpa.w"

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
return value_ref(v);
}

/*:1037*//*1038:*/
#line 11552 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
if(DSTACK_IS_INITIALIZED(v->t_virtual_stack))
{
DSTACK_DESTROY(v->t_virtual_stack);
}
g_slice_free(struct s_value,v);
}

/*:1038*//*1040:*/
#line 11568 "./marpa.w"

Marpa_Grammar marpa_v_g(Marpa_Value v)
{
/*1039:*/
#line 11563 "./marpa.w"

TREE t= T_of_V(v);
/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11565 "./marpa.w"


/*:1039*/
#line 11571 "./marpa.w"

return g;
}

/*:1040*//*1041:*/
#line 11575 "./marpa.w"

gint marpa_v_trace(Marpa_Value v,gint flag)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11578 "./marpa.w"

/*1039:*/
#line 11563 "./marpa.w"

TREE t= T_of_V(v);
/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11565 "./marpa.w"


/*:1039*/
#line 11579 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11580 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1041*//*1042:*/
#line 11588 "./marpa.w"

Marpa_Nook_ID marpa_v_nook(Marpa_Value v)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11591 "./marpa.w"

/*1039:*/
#line 11563 "./marpa.w"

TREE t= T_of_V(v);
/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11565 "./marpa.w"


/*:1039*/
#line 11592 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11593 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1042*//*1044:*/
#line 11606 "./marpa.w"

Marpa_Value_Type marpa_v_step(Marpa_Value v)
{
/*1143:*/
#line 12828 "./marpa.w"
const int failure_indicator= -2;

/*:1143*/
#line 11609 "./marpa.w"


while(V_is_Active(v)){
Marpa_Value_Type current_value_type= Next_Value_Type_of_V(v);
MARPA_DEBUG3("%s: value type = %d",G_STRLOC,current_value_type);
switch(current_value_type)
{
case V_GET_DATA:
/*1045:*/
#line 11652 "./marpa.w"

{
AND and_nodes;
/*1039:*/
#line 11563 "./marpa.w"

TREE t= T_of_V(v);
/*981:*/
#line 10838 "./marpa.w"

ORDER o= O_of_T(t);
/*969:*/
#line 10604 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*913:*/
#line 10029 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:913*/
#line 10606 "./marpa.w"


/*:969*/
#line 10840 "./marpa.w"
;

/*:981*/
#line 11565 "./marpa.w"


/*:1039*/
#line 11655 "./marpa.w"

/*1156:*/
#line 12896 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1156*/
#line 11656 "./marpa.w"

and_nodes= ANDs_of_B(B_of_O(o));

Arg_N_of_V(v)= TOS_of_V(v);
if(NOOK_of_V(v)<0){
NOOK_of_V(v)= Size_of_TREE(t);
}

while(1){
OR or;
RULE nook_rule;
Token_Value_of_V(v)= NULL;
SYMID_of_V(v)= -1;
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
gint token_type;
const NOOK nook= NOOK_of_TREE_by_IX(t,NOOK_of_V(v));
const gint choice= Choice_of_NOOK(nook);
or= OR_of_NOOK(nook);
and_node_id= and_order_get(o,or,choice);
and_node= and_nodes+and_node_id;
token= and_node_token(and_node);
token_type= token?Type_of_TOK(token):DUMMY_OR_NODE;
Token_Type_of_V(v)= token_type;
if(token_type!=DUMMY_OR_NODE)
{
SYMID_of_V(v)= SYMID_of_TOK(token);
TOS_of_V(v)= ++Arg_N_of_V(v);
Token_Type_of_V(v)= token_type;
if(token_type==VALUED_TOKEN_OR_NODE)
{
Token_Value_of_V(v)= Value_of_TOK(token);
}
}
}
nook_rule= RULE_of_OR(or);
if(Position_of_OR(or)==Length_of_RULE(nook_rule)){
gint virtual_rhs= RULE_has_Virtual_RHS(nook_rule);
gint virtual_lhs= RULE_has_Virtual_LHS(nook_rule);
gint real_symbol_count;
const DSTACK virtual_stack= &VStack_of_V(v);
if(virtual_lhs){
real_symbol_count= Real_SYM_Count_of_RULE(nook_rule);
if(virtual_rhs){
*(DSTACK_TOP(*virtual_stack,gint))+= real_symbol_count;
}else{
*DSTACK_PUSH(*virtual_stack,gint)= real_symbol_count;
}
}else{

if(virtual_rhs){
real_symbol_count= Real_SYM_Count_of_RULE(nook_rule);
real_symbol_count+= *DSTACK_POP(*virtual_stack,gint);
}else{
real_symbol_count= Length_of_RULE(nook_rule);
}
{
RULEID original_rule_id= 
nook_rule->t_is_semantic_equivalent?
nook_rule->t_original:ID_of_RULE(nook_rule);
if(RULE_is_Ask_Me(RULE_by_ID(g,original_rule_id)))
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

/*:1045*/
#line 11617 "./marpa.w"

if(!V_is_Active(v))break;

case MARPA_VALUE_TOKEN:
{
gint token_type= Token_Type_of_V(v);
if(token_type!=DUMMY_OR_NODE)
{
Next_Value_Type_of_V(v)= MARPA_VALUE_RULE;
if(token_type==NULLING_TOKEN_OR_NODE)
return MARPA_VALUE_NULLING_TOKEN;
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

/*:1044*//*1048:*/
#line 11763 "./marpa.w"

PRIVATE guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1048*//*1049:*/
#line 11769 "./marpa.w"

PRIVATE guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}

/*:1049*//*1051:*/
#line 11783 "./marpa.w"

PRIVATE Bit_Vector bv_create(guint bits)
{
guint size= bv_bits_to_size(bits);
guint bytes= (size+bv_hiddenwords)<<sizeof(guint);
guint*addr= (Bit_Vector)g_malloc0((size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}

/*:1051*//*1053:*/
#line 11801 "./marpa.w"

PRIVATE Bit_Vector
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


/*:1053*//*1054:*/
#line 11822 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}

/*:1054*//*1055:*/
#line 11832 "./marpa.w"

PRIVATE
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

/*:1055*//*1056:*/
#line 11850 "./marpa.w"

PRIVATE
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}

/*:1056*//*1057:*/
#line 11858 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
vector-= bv_hiddenwords;
g_free(vector);
}

/*:1057*//*1058:*/
#line 11866 "./marpa.w"

PRIVATE gint bv_bytes(Bit_Vector bv)
{
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}

/*:1058*//*1059:*/
#line 11873 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1059*//*1060:*/
#line 11884 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1060*//*1062:*/
#line 11898 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,guint bit)
{
guint length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1062*//*1064:*/
#line 11906 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,guint bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1064*//*1065:*/
#line 11913 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,guint bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1065*//*1066:*/
#line 11920 "./marpa.w"

PRIVATE gint bv_bit_test(Bit_Vector vector,guint bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1066*//*1067:*/
#line 11928 "./marpa.w"

PRIVATE gint
bv_bit_test_and_set(Bit_Vector vector,guint bit)
{
Bit_Vector addr= vector+(bit/bv_wordbits);
guint mask= bv_lsb<<(bit%bv_wordbits);
if((*addr&mask)!=0u)
return 1;
*addr|= mask;
return 0;
}

/*:1067*//*1068:*/
#line 11941 "./marpa.w"

PRIVATE
gint bv_is_empty(Bit_Vector addr)
{
guint size= BV_SIZE(addr);
gint r= TRUE;
if(size> 0){
*(addr+size-1)&= BV_MASK(addr);
while(r&&(size--> 0))r= (*addr++==0);
}
return(r);
}

/*:1068*//*1069:*/
#line 11955 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1069*//*1070:*/
#line 11965 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1070*//*1071:*/
#line 11975 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1071*//*1072:*/
#line 11985 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1072*//*1073:*/
#line 11995 "./marpa.w"

PRIVATE
gint bv_scan(Bit_Vector bv,guint start,
guint*min,guint*max)
{
guint size= BV_SIZE(bv);
guint mask= BV_MASK(bv);
guint offset;
guint bitmask;
guint value;
gint empty;

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

/*:1073*//*1074:*/
#line 12067 "./marpa.w"

PRIVATE guint
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

/*:1074*//*1079:*/
#line 12119 "./marpa.w"

PRIVATE_NOT_INLINE void
rhs_closure(GRAMMAR g,Bit_Vector bv)
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

/*:1079*//*1083:*/
#line 12196 "./marpa.w"

PRIVATE Bit_Matrix matrix_create(guint rows,guint columns)
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

/*:1083*//*1084:*/
#line 12214 "./marpa.w"

PRIVATE void matrix_free(Bit_Matrix matrix)
{
g_free(matrix);
}

/*:1084*//*1085:*/
#line 12226 "./marpa.w"

PRIVATE gint matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1085*//*1086:*/
#line 12242 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,guint row)
{
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1086*//*1088:*/
#line 12251 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,guint row,guint column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1088*//*1090:*/
#line 12259 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1090*//*1092:*/
#line 12267 "./marpa.w"

PRIVATE gint matrix_bit_test(Bit_Matrix matrix,guint row,guint column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1092*//*1093:*/
#line 12280 "./marpa.w"

PRIVATE_NOT_INLINE void transitive_closure(Bit_Matrix matrix)
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

/*:1093*//*1102:*/
#line 12422 "./marpa.w"

PRIVATE gpointer dstack_resize(struct s_dstack*this,gsize type_bytes)
{
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}

/*:1102*//*1117:*/
#line 12561 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,gint length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1117*//*1118:*/
#line 12568 "./marpa.w"

PRIVATE void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl)
{
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
if(owner)
*owner= NULL;
g_slice_free1(Sizeof_PSL(psar),psl);
psl= next_psl;
}
}
/*:1118*//*1119:*/
#line 12582 "./marpa.w"

PRIVATE PSL psl_new(const PSAR psar)
{
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
/*:1119*//*1122:*/
#line 12613 "./marpa.w"

PRIVATE void psar_reset(const PSAR psar)
{
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

/*:1122*//*1124:*/
#line 12631 "./marpa.w"

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

/*:1124*//*1126:*/
#line 12651 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1126*//*1128:*/
#line 12675 "./marpa.w"

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

/*:1128*//*1161:*/
#line 12953 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(struct marpa_g*g,Marpa_Error_Code code,const char*message,guint flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}

PRIVATE_NOT_INLINE void
r_error(struct marpa_r*r,Marpa_Error_Code code,const char*message,guint flags)
{
set_error(G_of_R(r),code,message,flags);
}

/*:1161*/
#line 13240 "./marpa.w"


/*:1179*/
