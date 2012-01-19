/*1185:*/
#line 13193 "./marpa.w"

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

/*:1185*//*1186:*/
#line 13216 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1172:*/
#line 13038 "./marpa.w"

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

/*:1172*/
#line 13219 "./marpa.w"

#define PRIVATE_NOT_INLINE static
#define PRIVATE static inline \

#define SYM_Count_of_G(g) ((g) ->t_symbols->len) 
#define SYM_by_ID(id) (g_array_index(g->t_symbols,SYM,(id) ) )  \

#define RULE_Count_of_G(g) ((g) ->t_rules->len) 
#define RULE_by_ID(g,id) (g_array_index((g) ->t_rules,RULE,(id) ) )  \

#define RULEID_of_G_is_Valid(g,rule_id)  \
((rule_id) >=0&&(guint) (rule_id) <(g) ->t_rules->len)  \

#define Default_Token_Value_of_G(g) ((g) ->t_default_token_value) 
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
#define TOKs_by_SYMID_of_I(i)  \
((i) ->t_tokens_by_symid) 
#define TOK_by_ID_of_I(i,symbol_id)  \
(TOKs_by_SYMID_of_I(i) [symbol_id]) 
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
#define SYMID_of_STEP(step) ((step) ->marpa_token_id) 
#define Value_of_STEP(step) ((step) ->marpa_value) 
#define RULEID_of_STEP(step) ((step) ->marpa_rule_id) 
#define Arg0_of_STEP(step) ((step) ->marpa_arg_0) 
#define ArgN_of_STEP(step) ((step) ->marpa_arg_n) 
#define V_is_Active(val) ((val) ->t_active) 
#define V_is_Trace(val) ((val) ->t_trace) 
#define NOOK_of_V(val) ((val) ->t_nook) 
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

#line 13220 "./marpa.w"

#include "marpa_obs.h"
/*1170:*/
#line 12982 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1170*/
#line 13222 "./marpa.w"

/*98:*/
#line 934 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:98*//*122:*/
#line 1107 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:122*//*365:*/
#line 3493 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:365*//*403:*/
#line 3877 "./marpa.w"
struct s_AHFA_state;
/*:403*//*480:*/
#line 4998 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:480*//*588:*/
#line 5709 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:588*//*612:*/
#line 5924 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:612*//*632:*/
#line 6213 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:632*//*635:*/
#line 6248 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:635*//*716:*/
#line 7366 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:716*//*722:*/
#line 7408 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:722*//*820:*/
#line 8571 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:820*//*848:*/
#line 9010 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:848*//*875:*/
#line 9457 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:875*//*901:*/
#line 9879 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:901*//*916:*/
#line 10051 "./marpa.w"

typedef struct s_bocage*BOCAGE;
/*:916*//*929:*/
#line 10157 "./marpa.w"

struct s_bocage_setup_per_es;
/*:929*//*986:*/
#line 10855 "./marpa.w"

typedef Marpa_Tree TREE;
/*:986*//*1020:*/
#line 11299 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1020*//*1036:*/
#line 11454 "./marpa.w"

typedef struct s_value*VALUE;
/*:1036*//*1107:*/
#line 12412 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1107*//*1110:*/
#line 12446 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1110*//*1117:*/
#line 12511 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1117*//*1119:*/
#line 12526 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1119*/
#line 13223 "./marpa.w"

/*40:*/
#line 611 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:40*//*121:*/
#line 1105 "./marpa.w"

typedef gint SYMID;
/*:121*//*175:*/
#line 1492 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:175*//*263:*/
#line 2318 "./marpa.w"
typedef gint SYMI;
/*:263*//*420:*/
#line 3968 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:420*//*481:*/
#line 5003 "./marpa.w"
typedef gint AEX;
/*:481*//*497:*/
#line 5149 "./marpa.w"

struct s_input;
typedef struct s_input*INPUT;
/*:497*//*514:*/
#line 5266 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:514*//*585:*/
#line 5700 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:585*//*587:*/
#line 5704 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:587*//*663:*/
#line 6630 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:663*//*665:*/
#line 6642 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:665*//*840:*/
#line 8946 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:840*//*874:*/
#line 9445 "./marpa.w"

typedef gint WHEID;


/*:874*//*900:*/
#line 9875 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:900*//*1019:*/
#line 11296 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1019*//*1033:*/
#line 11430 "./marpa.w"

typedef Marpa_Step*STEP;

/*:1033*//*1053:*/
#line 11743 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1053*//*1088:*/
#line 12183 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1088*/
#line 13224 "./marpa.w"

/*34:*/
#line 532 "./marpa.w"

const guint marpa_major_version= MARPA_MAJOR_VERSION;
const guint marpa_minor_version= MARPA_MINOR_VERSION;
const guint marpa_micro_version= MARPA_MICRO_VERSION;
const guint marpa_interface_age= MARPA_INTERFACE_AGE;
const guint marpa_binary_age= MARPA_BINARY_AGE;
/*:34*//*854:*/
#line 9064 "./marpa.w"

static const gint dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:854*//*1054:*/
#line 11750 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1054*/
#line 13225 "./marpa.w"

/*1108:*/
#line 12415 "./marpa.w"

struct s_dstack{gint t_count;gint t_capacity;gpointer t_base;};
/*:1108*/
#line 13226 "./marpa.w"

/*39:*/
#line 605 "./marpa.w"
struct marpa_g{
/*113:*/
#line 1056 "./marpa.w"

gint t_is_ok;

/*:113*/
#line 606 "./marpa.w"

/*50:*/
#line 689 "./marpa.w"
GArray*t_symbols;
/*:50*//*58:*/
#line 726 "./marpa.w"
GArray*t_rules;
/*:58*//*67:*/
#line 762 "./marpa.w"
gpointer t_default_token_value;
/*:67*//*95:*/
#line 922 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:95*//*102:*/
#line 953 "./marpa.w"

DSTACK_DECLARE(t_events);
/*:102*//*109:*/
#line 1026 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:109*//*115:*/
#line 1071 "./marpa.w"

const gchar*t_error_string;
/*:115*//*367:*/
#line 3510 "./marpa.w"

AIM t_AHFA_items;
AIM*t_AHFA_items_by_rule;
/*:367*//*421:*/
#line 3972 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:421*/
#line 607 "./marpa.w"

/*44:*/
#line 633 "./marpa.w"
gint t_ref_count;
/*:44*//*71:*/
#line 786 "./marpa.w"
Marpa_Symbol_ID t_original_start_symid;
/*:71*//*75:*/
#line 814 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:75*//*79:*/
#line 843 "./marpa.w"
int t_size;
/*:79*//*82:*/
#line 856 "./marpa.w"
gint t_max_rule_length;
/*:82*//*116:*/
#line 1073 "./marpa.w"

Marpa_Error_Code t_error;
/*:116*//*264:*/
#line 2320 "./marpa.w"

gint t_symbol_instance_count;
/*:264*//*368:*/
#line 3515 "./marpa.w"

guint t_aim_count;
/*:368*//*422:*/
#line 3975 "./marpa.w"
gint t_AHFA_len;
/*:422*/
#line 608 "./marpa.w"

/*85:*/
#line 862 "./marpa.w"
guint t_is_precomputed:1;
/*:85*//*88:*/
#line 874 "./marpa.w"
guint t_has_loop:1;
/*:88*//*91:*/
#line 890 "./marpa.w"
guint t_is_lhs_terminal_ok:1;
/*:91*/
#line 609 "./marpa.w"

};
/*:39*//*101:*/
#line 946 "./marpa.w"

struct s_g_event{
gint t_type;
gint t_value;
};
typedef struct s_g_event GEV_Object;
/*:101*//*123:*/
#line 1114 "./marpa.w"

struct s_symbol{
/*129:*/
#line 1160 "./marpa.w"
GArray*t_lhs;
/*:129*//*134:*/
#line 1206 "./marpa.w"
GArray*t_rhs;
/*:134*//*162:*/
#line 1371 "./marpa.w"

struct s_symbol*t_alias;
/*:162*//*169:*/
#line 1457 "./marpa.w"

RULE t_virtual_lhs_rule;
/*:169*/
#line 1116 "./marpa.w"

/*127:*/
#line 1151 "./marpa.w"
SYMID t_symbol_id;
/*:127*/
#line 1117 "./marpa.w"

/*139:*/
#line 1245 "./marpa.w"
guint t_is_accessible:1;
/*:139*//*142:*/
#line 1267 "./marpa.w"
guint t_is_counted:1;
/*:142*//*145:*/
#line 1281 "./marpa.w"
guint t_is_nullable:1;
/*:145*//*148:*/
#line 1296 "./marpa.w"
guint t_is_nulling:1;
/*:148*//*151:*/
#line 1310 "./marpa.w"
guint t_is_terminal:1;
/*:151*//*155:*/
#line 1335 "./marpa.w"
guint t_is_productive:1;
/*:155*//*158:*/
#line 1350 "./marpa.w"
guint t_is_start:1;
/*:158*//*161:*/
#line 1368 "./marpa.w"

guint t_is_proper_alias:1;
guint t_is_nulling_alias:1;
/*:161*/
#line 1118 "./marpa.w"

};
typedef struct s_symbol SYM_Object;

/*:123*//*174:*/
#line 1483 "./marpa.w"

struct s_rule{
/*199:*/
#line 1883 "./marpa.w"
gint t_rhs_length;
/*:199*//*210:*/
#line 1946 "./marpa.w"
Marpa_Rule_ID t_id;
/*:210*//*240:*/
#line 2155 "./marpa.w"
gint t_virtual_start;
/*:240*//*243:*/
#line 2172 "./marpa.w"
gint t_virtual_end;
/*:243*//*247:*/
#line 2189 "./marpa.w"
Marpa_Rule_ID t_original;
/*:247*//*251:*/
#line 2208 "./marpa.w"
gint t_real_symbol_count;
/*:251*//*254:*/
#line 2234 "./marpa.w"
guint t_is_ask_me:1;
/*:254*//*265:*/
#line 2331 "./marpa.w"

gint t_symbol_instance_base;
gint t_last_proper_symi;
/*:265*/
#line 1485 "./marpa.w"

/*213:*/
#line 1958 "./marpa.w"
guint t_is_discard:1;
/*:213*//*222:*/
#line 2039 "./marpa.w"
guint t_is_loop:1;
/*:222*//*226:*/
#line 2058 "./marpa.w"
guint t_is_virtual_loop:1;
/*:226*//*231:*/
#line 2090 "./marpa.w"
guint t_is_used:1;
/*:231*//*234:*/
#line 2119 "./marpa.w"
guint t_is_virtual_lhs:1;
/*:234*//*237:*/
#line 2136 "./marpa.w"
guint t_is_virtual_rhs:1;
/*:237*//*258:*/
#line 2292 "./marpa.w"
guint t_is_semantic_equivalent:1;
/*:258*/
#line 1486 "./marpa.w"

/*200:*/
#line 1886 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:200*/
#line 1487 "./marpa.w"

};
/*:174*//*364:*/
#line 3487 "./marpa.w"

struct s_AHFA_item{
gint t_sort_key;
/*373:*/
#line 3539 "./marpa.w"

RULE t_rule;

/*:373*/
#line 3490 "./marpa.w"

/*374:*/
#line 3545 "./marpa.w"

gint t_position;

/*:374*//*375:*/
#line 3552 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:375*//*376:*/
#line 3561 "./marpa.w"

gint t_leading_nulls;

/*:376*/
#line 3491 "./marpa.w"

};
/*:364*//*404:*/
#line 3878 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*408:*/
#line 3905 "./marpa.w"

SYMID*t_complete_symbols;

/*:408*//*410:*/
#line 3912 "./marpa.w"

AIM*t_items;
/*:410*//*428:*/
#line 4011 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:428*//*483:*/
#line 5015 "./marpa.w"

TRANS*t_transitions;
/*:483*/
#line 3885 "./marpa.w"

/*407:*/
#line 3903 "./marpa.w"

guint t_complete_symbol_count;
/*:407*//*411:*/
#line 3915 "./marpa.w"

gint t_item_count;
/*:411*//*429:*/
#line 4012 "./marpa.w"
guint t_postdot_sym_count;

/*:429*//*435:*/
#line 4073 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:435*/
#line 3886 "./marpa.w"

/*415:*/
#line 3956 "./marpa.w"

guint t_is_predict:1;

/*:415*//*418:*/
#line 3964 "./marpa.w"

guint t_is_potential_leo_base:1;
/*:418*/
#line 3887 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:404*//*482:*/
#line 5004 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
gint t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:482*//*498:*/
#line 5152 "./marpa.w"

struct s_input{
/*507:*/
#line 5226 "./marpa.w"

struct obstack t_token_obs;
TOK*t_tokens_by_symid;

/*:507*//*511:*/
#line 5253 "./marpa.w"

GRAMMAR t_grammar;
/*:511*/
#line 5154 "./marpa.w"

/*501:*/
#line 5170 "./marpa.w"

int t_ref_count;
/*:501*/
#line 5155 "./marpa.w"

};

/*:498*//*589:*/
#line 5715 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:589*//*590:*/
#line 5720 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
gint t_postdot_sym_count;
/*591:*/
#line 5732 "./marpa.w"

gint t_eim_count;
/*:591*//*593:*/
#line 5746 "./marpa.w"

gint t_ordinal;
/*:593*/
#line 5724 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*592:*/
#line 5735 "./marpa.w"

EIM*t_earley_items;

/*:592*//*1127:*/
#line 12599 "./marpa.w"

PSL t_dot_psl;
/*:1127*/
#line 5727 "./marpa.w"

};

/*:590*//*633:*/
#line 6217 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:633*//*636:*/
#line 6251 "./marpa.w"

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

/*:636*//*646:*/
#line 6390 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:646*//*717:*/
#line 7374 "./marpa.w"

struct s_token{
gint t_type;
SYMID t_symbol_id;
gpointer t_value;
};

/*:717*//*723:*/
#line 7418 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:723*//*821:*/
#line 8588 "./marpa.w"

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
/*:821*//*851:*/
#line 9039 "./marpa.w"

struct s_draft_or_node
{
/*850:*/
#line 9033 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:850*/
#line 9042 "./marpa.w"

DAND t_draft_and_node;
};
/*:851*//*852:*/
#line 9045 "./marpa.w"

struct s_final_or_node
{
/*850:*/
#line 9033 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:850*/
#line 9048 "./marpa.w"

gint t_first_and_node_id;
gint t_and_node_count;
};
/*:852*//*853:*/
#line 9056 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:853*//*876:*/
#line 9464 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:876*//*902:*/
#line 9886 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:902*//*930:*/
#line 10159 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:930*//*963:*/
#line 10543 "./marpa.w"

struct s_order{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
/*966:*/
#line 10561 "./marpa.w"

BOCAGE t_bocage;

/*:966*/
#line 10548 "./marpa.w"

/*969:*/
#line 10579 "./marpa.w"
gint t_ref_count;
/*:969*/
#line 10549 "./marpa.w"

guint t_is_frozen:1;
};
/*:963*//*987:*/
#line 10869 "./marpa.w"

/*1021:*/
#line 11310 "./marpa.w"

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

/*:1021*/
#line 10870 "./marpa.w"

/*1037:*/
#line 11471 "./marpa.w"

struct s_value{
DSTACK_DECLARE(t_virtual_stack);
NOOKID t_nook;
Marpa_Tree t_tree;
/*1042:*/
#line 11549 "./marpa.w"

int t_ref_count;
/*:1042*/
#line 11476 "./marpa.w"

gint t_tos;
guint t_trace:1;
guint t_active:1;
};

/*:1037*/
#line 10871 "./marpa.w"

struct s_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,gint)
Bit_Vector t_and_node_in_use;
Marpa_Order t_order;
/*993:*/
#line 10929 "./marpa.w"

gint t_ref_count;
/*:993*//*1000:*/
#line 11011 "./marpa.w"
gint t_pause_counter;
/*:1000*/
#line 10877 "./marpa.w"

gint t_parse_count;
};

/*:987*//*1111:*/
#line 12449 "./marpa.w"

struct s_dqueue{gint t_current;struct s_dstack t_stack;};

/*:1111*//*1118:*/
#line 12517 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
gpointer t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1118*//*1120:*/
#line 12542 "./marpa.w"

struct s_per_earley_set_arena{
gint t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1120*/
#line 13227 "./marpa.w"

/*515:*/
#line 5269 "./marpa.w"

struct marpa_r{
INPUT t_input;
/*528:*/
#line 5380 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:528*//*540:*/
#line 5443 "./marpa.w"
gpointer*t_sym_workarea;
/*:540*//*544:*/
#line 5454 "./marpa.w"
gpointer*t_workarea2;
/*:544*//*548:*/
#line 5471 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:548*//*552:*/
#line 5497 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:552*//*574:*/
#line 5654 "./marpa.w"
struct obstack t_obs;
/*:574*//*599:*/
#line 5797 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:599*//*620:*/
#line 6059 "./marpa.w"

EIM t_trace_earley_item;
/*:620*//*650:*/
#line 6439 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:650*//*684:*/
#line 6896 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:684*//*724:*/
#line 7426 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:724*//*745:*/
#line 7724 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:745*//*749:*/
#line 7736 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:749*//*753:*/
#line 7748 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:753*//*822:*/
#line 8601 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:822*//*1121:*/
#line 12550 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1121*/
#line 5272 "./marpa.w"

/*518:*/
#line 5301 "./marpa.w"
gint t_ref_count;
/*:518*//*532:*/
#line 5407 "./marpa.w"
gint t_earley_item_warning_threshold;
/*:532*//*536:*/
#line 5430 "./marpa.w"
EARLEME t_furthest_earleme;
/*:536*//*594:*/
#line 5750 "./marpa.w"

gint t_earley_set_count;
/*:594*/
#line 5273 "./marpa.w"

/*525:*/
#line 5372 "./marpa.w"

guint t_input_phase:2;
/*:525*//*566:*/
#line 5592 "./marpa.w"

guint t_use_leo_flag:1;
guint t_is_using_leo:1;
/*:566*//*570:*/
#line 5630 "./marpa.w"
guint t_is_exhausted:1;
/*:570*//*685:*/
#line 6899 "./marpa.w"

guint t_trace_source_type:3;
/*:685*/
#line 5274 "./marpa.w"

};

/*:515*/
#line 13228 "./marpa.w"

/*664:*/
#line 6633 "./marpa.w"

struct s_source{
gpointer t_predecessor;
union{
gpointer t_completion;
TOK t_token;
}t_cause;
};

/*:664*//*666:*/
#line 6645 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:666*//*667:*/
#line 6651 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:667*//*668:*/
#line 6658 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:668*/
#line 13229 "./marpa.w"

/*613:*/
#line 5931 "./marpa.w"

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
/*618:*/
#line 6031 "./marpa.w"

guint t_source_type:3;

/*:618*/
#line 5942 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:613*/
#line 13230 "./marpa.w"

/*917:*/
#line 10053 "./marpa.w"

struct s_bocage{
/*855:*/
#line 9074 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:855*//*919:*/
#line 10062 "./marpa.w"

INPUT t_input;

/*:919*//*921:*/
#line 10072 "./marpa.w"

struct obstack t_obs;
/*:921*/
#line 10055 "./marpa.w"

/*856:*/
#line 9077 "./marpa.w"

gint t_or_node_count;
gint t_and_node_count;
ORID t_top_or_node_id;

/*:856*//*946:*/
#line 10368 "./marpa.w"
gint t_ref_count;
/*:946*/
#line 10056 "./marpa.w"

/*922:*/
#line 10074 "./marpa.w"

unsigned int is_obstack_initialized:1;
/*:922*/
#line 10057 "./marpa.w"

};

/*:917*/
#line 13231 "./marpa.w"

#include "private.h"
#if MARPA_DEBUG
/*1173:*/
#line 13069 "./marpa.w"

static gchar*eim_tag_safe(gchar*buffer,EIM eim);
static gchar*eim_tag(EIM eim);
/*:1173*//*1175:*/
#line 13094 "./marpa.w"

static gchar*lim_tag_safe(gchar*buffer,LIM lim);
static gchar*lim_tag(LIM lim);
/*:1175*//*1177:*/
#line 13120 "./marpa.w"

static const gchar*or_tag_safe(gchar*buffer,OR or);
static const gchar*or_tag(OR or);
/*:1177*//*1179:*/
#line 13152 "./marpa.w"

static const gchar*aim_tag_safe(gchar*buffer,AIM aim);
static const gchar*aim_tag(AIM aim);
/*:1179*/
#line 13234 "./marpa.w"

/*1174:*/
#line 13073 "./marpa.w"

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

/*:1174*//*1176:*/
#line 13099 "./marpa.w"

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

/*:1176*//*1178:*/
#line 13124 "./marpa.w"

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

/*:1178*//*1180:*/
#line 13155 "./marpa.w"

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

/*:1180*/
#line 13235 "./marpa.w"

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
#line 690 "./marpa.w"

g->t_symbols= g_array_new(FALSE,FALSE,sizeof(SYM));
/*:51*//*59:*/
#line 727 "./marpa.w"

g->t_rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:59*//*68:*/
#line 763 "./marpa.w"

Default_Token_Value_of_G(g)= NULL;
/*:68*//*72:*/
#line 787 "./marpa.w"

g->t_original_start_symid= -1;
/*:72*//*76:*/
#line 817 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;
/*:76*//*80:*/
#line 844 "./marpa.w"

Size_of_G(g)= 0;

/*:80*//*83:*/
#line 857 "./marpa.w"

g->t_max_rule_length= 0;

/*:83*//*86:*/
#line 863 "./marpa.w"

g->t_is_precomputed= FALSE;
/*:86*//*89:*/
#line 875 "./marpa.w"

g->t_has_loop= FALSE;
/*:89*//*92:*/
#line 891 "./marpa.w"

g->t_is_lhs_terminal_ok= TRUE;
/*:92*//*96:*/
#line 923 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:96*//*103:*/
#line 961 "./marpa.w"

DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:103*//*110:*/
#line 1029 "./marpa.w"

obstack_init(&g->t_obs);
obstack_init(&g->t_obs_tricky);
/*:110*//*117:*/
#line 1075 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:117*//*370:*/
#line 3520 "./marpa.w"

g->t_AHFA_items= NULL;
g->t_AHFA_items_by_rule= NULL;
/*:370*//*423:*/
#line 3976 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:423*/
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

/*:46*//*48:*/
#line 662 "./marpa.w"

PRIVATE GRAMMAR
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

/*:48*//*49:*/
#line 675 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
MARPA_DEBUG3("%s: Destroying grammar %p",G_STRLOC,g);
/*52:*/
#line 692 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->t_symbols->len;id++)
{symbol_free(SYM_by_ID(id));}}
g_array_free(g->t_symbols,TRUE);

/*:52*//*60:*/
#line 729 "./marpa.w"

g_array_free(g->t_rules,TRUE);

/*:60*//*97:*/
#line 924 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:97*//*104:*/
#line 963 "./marpa.w"
DSTACK_DESTROY(g->t_events);

/*:104*//*111:*/
#line 1032 "./marpa.w"

obstack_free(&g->t_obs,NULL);
obstack_free(&g->t_obs_tricky,NULL);

/*:111*//*371:*/
#line 3523 "./marpa.w"

if(g->t_AHFA_items){g_free(g->t_AHFA_items);};
if(g->t_AHFA_items_by_rule){g_free(g->t_AHFA_items_by_rule);};

/*:371*//*424:*/
#line 3980 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*425:*/
#line 3990 "./marpa.w"
{
TRANS*ahfa_transitions= TRANSs_of_AHFA(ahfa_state);
if(ahfa_transitions)
g_free(TRANSs_of_AHFA(ahfa_state));
}

/*:425*/
#line 3984 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:424*/
#line 680 "./marpa.w"

g_slice_free(struct marpa_g,g);
}

/*:49*//*54:*/
#line 699 "./marpa.w"

gint marpa_g_symbol_count(struct marpa_g*g){
return SYM_Count_of_G(g);
}

/*:54*//*56:*/
#line 709 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,SYMID symid,SYM symbol)
{
g_array_insert_val(g->t_symbols,(unsigned)symid,symbol);
}

/*:56*//*57:*/
#line 717 "./marpa.w"

PRIVATE gint symbol_is_valid(GRAMMAR g,SYMID symid)
{
return symid>=0&&(guint)symid<g->t_symbols->len;
}

/*:57*//*63:*/
#line 734 "./marpa.w"

gint marpa_g_rule_count(struct marpa_g*g){
return RULE_Count_of_G(g);
}

/*:63*//*65:*/
#line 744 "./marpa.w"

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
#line 767 "./marpa.w"

gint marpa_g_default_token_value(GRAMMAR g,gpointer*value)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 770 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 771 "./marpa.w"

*value= Default_Token_Value_of_G(g);
return 1;
}
/*:69*//*70:*/
#line 775 "./marpa.w"

gint marpa_g_default_token_value_set(GRAMMAR g,gpointer default_value)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 778 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 779 "./marpa.w"

/*1151:*/
#line 12831 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1151*/
#line 780 "./marpa.w"

Default_Token_Value_of_G(g)= default_value;
return 1;
}

/*:70*//*73:*/
#line 789 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 792 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 793 "./marpa.w"

return g->t_original_start_symid;
}
/*:73*//*74:*/
#line 798 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 801 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 802 "./marpa.w"

/*1151:*/
#line 12831 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1151*/
#line 803 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 804 "./marpa.w"

return g->t_original_start_symid= symid;
}

/*:74*//*87:*/
#line 865 "./marpa.w"

gint marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 868 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 869 "./marpa.w"

return G_is_Precomputed(g);
}

/*:87*//*90:*/
#line 877 "./marpa.w"

gint marpa_g_has_loop(Marpa_Grammar g)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 880 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 881 "./marpa.w"

return g->t_has_loop;
}

/*:90*//*93:*/
#line 894 "./marpa.w"

gint marpa_g_is_lhs_terminal_ok(Marpa_Grammar g)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 897 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 898 "./marpa.w"

return g->t_is_lhs_terminal_ok;
}
/*:93*//*94:*/
#line 903 "./marpa.w"

gint marpa_g_is_lhs_terminal_ok_set(
struct marpa_g*g,gint value)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 907 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 908 "./marpa.w"

/*1151:*/
#line 12831 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1151*/
#line 909 "./marpa.w"

return g->t_is_lhs_terminal_ok= value?1:0;
}

/*:94*//*106:*/
#line 973 "./marpa.w"

PRIVATE
void event_new(struct marpa_g*g,gint type)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= 0;
}
/*:106*//*107:*/
#line 982 "./marpa.w"

PRIVATE
void int_event_new(struct marpa_g*g,gint type,gint value)
{

GEV top_of_stack= G_EVENT_PUSH(g);
top_of_stack->t_type= type;
top_of_stack->t_value= value;
}

/*:107*//*108:*/
#line 992 "./marpa.w"

gint
marpa_g_event(Marpa_Grammar g,Marpa_Event public_event,
gint ix)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 997 "./marpa.w"

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

/*:108*//*119:*/
#line 1086 "./marpa.w"

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

/*:119*//*124:*/
#line 1122 "./marpa.w"

PRIVATE SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= g_malloc(sizeof(SYM_Object));
/*128:*/
#line 1152 "./marpa.w"
ID_of_SYM(symbol)= g->t_symbols->len;

/*:128*//*130:*/
#line 1161 "./marpa.w"

symbol->t_lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:130*//*135:*/
#line 1207 "./marpa.w"

symbol->t_rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:135*//*140:*/
#line 1246 "./marpa.w"

symbol->t_is_accessible= FALSE;
/*:140*//*143:*/
#line 1268 "./marpa.w"

symbol->t_is_counted= FALSE;
/*:143*//*146:*/
#line 1282 "./marpa.w"

symbol->t_is_nullable= FALSE;
/*:146*//*149:*/
#line 1297 "./marpa.w"

symbol->t_is_nulling= FALSE;
/*:149*//*152:*/
#line 1311 "./marpa.w"

symbol->t_is_terminal= FALSE;
/*:152*//*156:*/
#line 1336 "./marpa.w"

symbol->t_is_productive= FALSE;
/*:156*//*159:*/
#line 1351 "./marpa.w"
symbol->t_is_start= FALSE;
/*:159*//*163:*/
#line 1373 "./marpa.w"

symbol->t_is_proper_alias= FALSE;
symbol->t_is_nulling_alias= FALSE;
symbol->t_alias= NULL;

/*:163*//*170:*/
#line 1459 "./marpa.w"

symbol->t_virtual_lhs_rule= NULL;

/*:170*/
#line 1127 "./marpa.w"

{
SYMID id= ID_of_SYM(symbol);
symbol_add(g,id,symbol);
}
return symbol;
}

/*:124*//*125:*/
#line 1135 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(struct marpa_g*g)
{
SYMID id= ID_of_SYM(symbol_new(g));
return id;
}

/*:125*//*126:*/
#line 1143 "./marpa.w"

PRIVATE void symbol_free(SYM symbol)
{
/*131:*/
#line 1163 "./marpa.w"

g_array_free(symbol->t_lhs,TRUE);

/*:131*//*136:*/
#line 1209 "./marpa.w"
g_array_free(symbol->t_rhs,TRUE);

/*:136*/
#line 1146 "./marpa.w"
g_free(symbol);
}

/*:126*//*132:*/
#line 1166 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_lhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1169 "./marpa.w"

GArray*symbol_lh_rules;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1171 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1172 "./marpa.w"

symbol_lh_rules= SYM_by_ID(symid)->t_lhs;
return symbol_lh_rules->len;
}
Marpa_Rule_ID marpa_g_symbol_lhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1178 "./marpa.w"

GArray*symbol_lh_rules;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1180 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1181 "./marpa.w"

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

/*:132*//*133:*/
#line 1194 "./marpa.w"

PRIVATE
void symbol_lhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{
g_array_append_val(symbol->t_lhs,rule_id);
}

/*:133*//*137:*/
#line 1211 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_rhs_count(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1214 "./marpa.w"

GArray*symbol_rh_rules;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1216 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1217 "./marpa.w"

symbol_rh_rules= SYM_by_ID(symid)->t_rhs;
return symbol_rh_rules->len;
}
Marpa_Rule_ID marpa_g_symbol_rhs(struct marpa_g*g,Marpa_Symbol_ID symid,gint ix)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1223 "./marpa.w"

GArray*symbol_rh_rules;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1225 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1226 "./marpa.w"

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

/*:137*//*138:*/
#line 1239 "./marpa.w"

PRIVATE
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_rhs,rule_id);}

/*:138*//*141:*/
#line 1256 "./marpa.w"

gint marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1259 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1260 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 1261 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1262 "./marpa.w"

return SYM_by_ID(symid)->t_is_accessible;
}

/*:141*//*144:*/
#line 1270 "./marpa.w"

gint marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1274 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1275 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1276 "./marpa.w"

return SYM_by_ID(symid)->t_is_counted;
}

/*:144*//*147:*/
#line 1284 "./marpa.w"

gint marpa_g_symbol_is_nullable(GRAMMAR g,SYMID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1287 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1288 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 1289 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1290 "./marpa.w"

return SYM_by_ID(symid)->t_is_nullable;
}

/*:147*//*150:*/
#line 1299 "./marpa.w"

gint marpa_g_symbol_is_nulling(GRAMMAR g,SYMID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1302 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1303 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 1304 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1305 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));
}

/*:150*//*153:*/
#line 1315 "./marpa.w"

gint marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1319 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1320 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1321 "./marpa.w"

return SYMID_is_Terminal(symid);
}
/*:153*//*154:*/
#line 1324 "./marpa.w"

gint marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID symid,gint value)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1328 "./marpa.w"

/*1151:*/
#line 12831 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1151*/
#line 1329 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1330 "./marpa.w"

return SYMID_is_Terminal(symid)= value;
}

/*:154*//*157:*/
#line 1338 "./marpa.w"

gint marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1343 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 1344 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1345 "./marpa.w"

return SYM_by_ID(symid)->t_is_productive;
}

/*:157*//*160:*/
#line 1352 "./marpa.w"

gint marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1355 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 1356 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1357 "./marpa.w"

return SYM_by_ID(symid)->t_is_start;
}

/*:160*//*164:*/
#line 1382 "./marpa.w"

PRIVATE
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1390 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1391 "./marpa.w"

symbol= SYM_by_ID(symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}

/*:164*//*165:*/
#line 1401 "./marpa.w"

PRIVATE
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_g_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1409 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1410 "./marpa.w"

symbol= SYM_by_ID(symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
MARPA_DEV_ERROR("no alias");
return-1;
}
return ID_of_SYM(alias);
}

/*:165*//*167:*/
#line 1426 "./marpa.w"

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

/*:167*//*172:*/
#line 1467 "./marpa.w"

Marpa_Rule_ID marpa_g_symbol_virtual_lhs_rule(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
RULE virtual_lhs_rule;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1472 "./marpa.w"

/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1473 "./marpa.w"

symbol= SYM_by_ID(symid);
virtual_lhs_rule= symbol->t_virtual_lhs_rule;
return virtual_lhs_rule==NULL?-1:ID_of_RULE(virtual_lhs_rule);
}

/*:172*//*178:*/
#line 1504 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length)
{
/*1149:*/
#line 12823 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1149*/
#line 1509 "./marpa.w"

RULE rule;
const gint rule_sizeof= G_STRUCT_OFFSET(struct s_rule,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
/*201:*/
#line 1888 "./marpa.w"

{
SYMID symid= lhs;
/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1891 "./marpa.w"

}
{gint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1153:*/
#line 12841 "./marpa.w"

if(!symbol_is_valid(g,symid)){
MARPA_DEV_ERROR("invalid symbol id");
return failure_indicator;
}
/*:1153*/
#line 1896 "./marpa.w"

}
}

/*:201*/
#line 1513 "./marpa.w"

rule= obstack_alloc(&g->t_obs,rule_sizeof);
/*202:*/
#line 1900 "./marpa.w"

Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
{gint i;for(i= 0;i<length;i++){
rule->t_symbols[i+1]= rhs[i];}}
/*:202*/
#line 1515 "./marpa.w"

/*211:*/
#line 1947 "./marpa.w"
rule->t_id= g->t_rules->len;

/*:211*//*214:*/
#line 1959 "./marpa.w"

rule->t_is_discard= FALSE;
/*:214*//*223:*/
#line 2040 "./marpa.w"

rule->t_is_loop= FALSE;
/*:223*//*227:*/
#line 2059 "./marpa.w"

rule->t_is_virtual_loop= FALSE;
/*:227*//*232:*/
#line 2091 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:232*//*235:*/
#line 2120 "./marpa.w"

RULE_has_Virtual_LHS(rule)= FALSE;
/*:235*//*238:*/
#line 2137 "./marpa.w"

RULE_has_Virtual_RHS(rule)= FALSE;
/*:238*//*241:*/
#line 2156 "./marpa.w"
rule->t_virtual_start= -1;
/*:241*//*244:*/
#line 2173 "./marpa.w"
rule->t_virtual_end= -1;
/*:244*//*248:*/
#line 2190 "./marpa.w"
rule->t_original= -1;
/*:248*//*252:*/
#line 2209 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:252*//*255:*/
#line 2235 "./marpa.w"

RULE_is_Ask_Me(rule)= FALSE;
/*:255*//*259:*/
#line 2293 "./marpa.w"

rule->t_is_semantic_equivalent= FALSE;
/*:259*//*266:*/
#line 2334 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:266*/
#line 1516 "./marpa.w"

rule_add(g,rule->t_id,rule);
/*194:*/
#line 1766 "./marpa.w"

symbol_lhs_add(SYM_by_ID(rule->t_symbols[0]),rule->t_id);
if(Length_of_RULE(rule)> 0){
gint rh_list_ix;
const guint alloc_size= Length_of_RULE(rule)*sizeof(SYMID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*198:*/
#line 1833 "./marpa.w"

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

/*:198*/
#line 1774 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(rh_symbol_list[rh_list_ix]),
rule->t_id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:194*/
#line 1518 "./marpa.w"

return rule;
}

/*:178*//*179:*/
#line 1522 "./marpa.w"

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

/*:179*//*180:*/
#line 1542 "./marpa.w"

gint marpa_g_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags)
{
RULE original_rule;
RULEID original_rule_id;
SYM internal_lhs;
SYMID internal_lhs_id,*temp_rhs;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1551 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1552 "./marpa.w"

/*1151:*/
#line 12831 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
/*:1151*/
#line 1553 "./marpa.w"

if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE)
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
return failure_indicator;
}
G_EVENTS_CLEAR(g);

/*181:*/
#line 1579 "./marpa.w"

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

/*:181*/
#line 1561 "./marpa.w"

/*182:*/
#line 1594 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
MARPA_DEV_ERROR("bad separator");
return failure_indicator;
}

/*:182*/
#line 1562 "./marpa.w"

/*183:*/
#line 1600 "./marpa.w"

SYM_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(separator_id)->t_is_counted= 1;}
/*:183*/
#line 1563 "./marpa.w"

if(min==0){/*184:*/
#line 1603 "./marpa.w"

{
RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1158:*/
#line 12866 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1158*/
#line 1606 "./marpa.w"
}
rule->t_is_semantic_equivalent= TRUE;
rule->t_original= original_rule_id;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}
/*:184*/
#line 1564 "./marpa.w"
}
min= 1;
/*185:*/
#line 1611 "./marpa.w"

{
internal_lhs= symbol_new(g);
internal_lhs_id= ID_of_SYM(internal_lhs);
int_event_new(g,MARPA_EVENT_NEW_SYMBOL,internal_lhs_id);
}

/*:185*/
#line 1566 "./marpa.w"

/*186:*/
#line 1629 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:186*/
#line 1567 "./marpa.w"

/*188:*/
#line 1632 "./marpa.w"

{
RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1158:*/
#line 12866 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1158*/
#line 1637 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;

RULE_has_Virtual_RHS(rule)= TRUE;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}

/*:188*/
#line 1568 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*189:*/
#line 1646 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1158:*/
#line 12866 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1158*/
#line 1651 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;
RULE_has_Virtual_RHS(rule)= TRUE;
Real_SYM_Count_of_RULE(rule)= 1;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}
/*:189*/
#line 1570 "./marpa.w"

}
/*190:*/
#line 1661 "./marpa.w"

{RULE rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1158:*/
#line 12866 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1158*/
#line 1671 "./marpa.w"
}
RULE_has_Virtual_LHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}
/*:190*/
#line 1572 "./marpa.w"

/*191:*/
#line 1676 "./marpa.w"

{RULE rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1158:*/
#line 12866 "./marpa.w"
{
MARPA_DEV_ERROR("internal error");
return failure_indicator;
}

/*:1158*/
#line 1683 "./marpa.w"
}
RULE_has_Virtual_LHS(rule)= 1;
RULE_has_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix-1;
int_event_new(g,MARPA_EVENT_NEW_RULE,rule->t_id);
}

/*:191*/
#line 1573 "./marpa.w"

/*187:*/
#line 1631 "./marpa.w"
g_free(temp_rhs);
/*:187*/
#line 1574 "./marpa.w"

return G_EVENT_COUNT(g);
}

/*:180*//*193:*/
#line 1732 "./marpa.w"

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

/*:193*//*203:*/
#line 1905 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:203*//*204:*/
#line 1909 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1911 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 1912 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));}
/*:204*//*205:*/
#line 1914 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:205*//*206:*/
#line 1918 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix){
RULE rule;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1921 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 1922 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:206*//*207:*/
#line 1927 "./marpa.w"

PRIVATE gsize rule_length_get(RULE rule)
{
return Length_of_RULE(rule);}
/*:207*//*208:*/
#line 1931 "./marpa.w"

gint marpa_g_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1933 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 1934 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}

/*:208*//*215:*/
#line 1961 "./marpa.w"

gint marpa_g_rule_is_discard_separation(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 1966 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 1967 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 1968 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_discard;
}

/*:215*//*218:*/
#line 1999 "./marpa.w"

PRIVATE gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(lhs_id)->t_is_accessible;}
gint marpa_g_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2006 "./marpa.w"

RULE rule;
/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2008 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}

/*:218*//*220:*/
#line 2015 "./marpa.w"

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
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2026 "./marpa.w"

RULE rule;
/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2028 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}

/*:220*//*224:*/
#line 2044 "./marpa.w"

gint marpa_g_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2047 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2048 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}

/*:224*//*228:*/
#line 2063 "./marpa.w"

gint marpa_g_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2066 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2067 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;}

/*:228*//*230:*/
#line 2073 "./marpa.w"

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

/*:230*//*233:*/
#line 2095 "./marpa.w"

gint marpa_g_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2098 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2099 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}

/*:233*//*236:*/
#line 2123 "./marpa.w"

gint marpa_g_rule_is_virtual_lhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2128 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 2129 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2130 "./marpa.w"

return RULE_has_Virtual_LHS(RULE_by_ID(g,rule_id));
}

/*:236*//*239:*/
#line 2140 "./marpa.w"

gint marpa_g_rule_is_virtual_rhs(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2145 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 2146 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2147 "./marpa.w"

return RULE_has_Virtual_RHS(RULE_by_ID(g,rule_id));
}

/*:239*//*242:*/
#line 2157 "./marpa.w"

guint marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2162 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 2163 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2164 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}

/*:242*//*245:*/
#line 2174 "./marpa.w"

guint marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2179 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 2180 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2181 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}

/*:245*//*249:*/
#line 2191 "./marpa.w"

Marpa_Rule_ID marpa_g_rule_original(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2196 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2197 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_original;
}

/*:249*//*253:*/
#line 2210 "./marpa.w"

gint marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2215 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 2216 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2217 "./marpa.w"

return Real_SYM_Count_of_RULE(RULE_by_ID(g,rule_id));
}

/*:253*//*256:*/
#line 2237 "./marpa.w"

gint marpa_g_rule_is_ask_me(
Marpa_Grammar g,
Marpa_Rule_ID rule_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2242 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2243 "./marpa.w"

return RULE_is_Ask_Me(RULE_by_ID(g,rule_id));
}
/*:256*//*257:*/
#line 2262 "./marpa.w"

gint marpa_g_rule_whatever_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2267 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2268 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}
gint marpa_g_rule_ask_me_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2276 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2277 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 1;
}
gint marpa_g_rule_first_child_set(
Marpa_Grammar g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2285 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2286 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return RULE_is_Ask_Me(rule)= 0;
}

/*:257*//*262:*/
#line 2304 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2309 "./marpa.w"

/*1154:*/
#line 12846 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
MARPA_DEV_ERROR("invalid rule id");
return failure_indicator;
}
/*:1154*/
#line 2310 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(RULE_has_Virtual_LHS(rule))return-1;
if(rule->t_is_semantic_equivalent)return rule->t_original;
return rule_id;
}

/*:262*//*268:*/
#line 2348 "./marpa.w"

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

/*:268*//*269:*/
#line 2374 "./marpa.w"

gint marpa_g_precompute(struct marpa_g*g)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 2377 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 2378 "./marpa.w"

G_EVENTS_CLEAR(g);
if(!census(g))return failure_indicator;
if(!CHAF_rewrite(g))return failure_indicator;
if(!g_augment(g))return failure_indicator;
if(!G_is_Trivial(g)){
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*495:*/
#line 5132 "./marpa.w"
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

/*:495*/
#line 2387 "./marpa.w"

}
return G_EVENT_COUNT(g);
}

/*:269*//*271:*/
#line 2424 "./marpa.w"

PRIVATE_NOT_INLINE GRAMMAR census(GRAMMAR g)
{
/*1149:*/
#line 12823 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1149*/
#line 2427 "./marpa.w"

/*272:*/
#line 2455 "./marpa.w"

guint pre_rewrite_rule_count= g->t_rules->len;
guint pre_rewrite_symbol_count= g->t_symbols->len;

/*:272*//*277:*/
#line 2489 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_original_start_symid;
SYM original_start_symbol;

/*:277*//*281:*/
#line 2528 "./marpa.w"

Bit_Vector terminal_v;
gint have_marked_terminals= 0;

/*:281*//*287:*/
#line 2579 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gint have_empty_rule= 0;

/*:287*//*289:*/
#line 2611 "./marpa.w"

Bit_Vector nullable_v;
/*:289*//*293:*/
#line 2636 "./marpa.w"

Bit_Vector productive_v;
/*:293*//*296:*/
#line 2677 "./marpa.w"
Bit_Matrix reach_matrix;
/*:296*//*299:*/
#line 2695 "./marpa.w"

Bit_Vector accessible_v;

/*:299*/
#line 2428 "./marpa.w"

/*273:*/
#line 2459 "./marpa.w"

if(g->t_rules->len<=0){MARPA_ERROR(MARPA_ERR_NO_RULES);return NULL;}
/*:273*/
#line 2429 "./marpa.w"

/*274:*/
#line 2466 "./marpa.w"

if(G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return NULL;}
/*:274*/
#line 2430 "./marpa.w"

/*276:*/
#line 2474 "./marpa.w"

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

/*:276*/
#line 2431 "./marpa.w"

/*278:*/
#line 2493 "./marpa.w"

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
/*:278*/
#line 2432 "./marpa.w"

/*279:*/
#line 2512 "./marpa.w"

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
/*:279*/
#line 2433 "./marpa.w"

if(have_marked_terminals){
/*283:*/
#line 2546 "./marpa.w"

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

/*:283*/
#line 2435 "./marpa.w"

}else{
/*282:*/
#line 2532 "./marpa.w"

if(have_empty_rule&&g->t_is_lhs_terminal_ok){
MARPA_ERROR(MARPA_ERR_NULL_RULE_UNMARKED_TERMINALS);
return NULL;
}
/*:282*/
#line 2437 "./marpa.w"
;
if(g->t_is_lhs_terminal_ok){
/*284:*/
#line 2559 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->t_symbols->len;symid++)
{SYMID_is_Terminal(symid)= 1;}}
/*:284*/
#line 2439 "./marpa.w"

}else{
/*285:*/
#line 2564 "./marpa.w"

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
/*:285*/
#line 2441 "./marpa.w"

}
}
/*288:*/
#line 2584 "./marpa.w"

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
/*:288*/
#line 2444 "./marpa.w"

/*291:*/
#line 2616 "./marpa.w"

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
/*:291*/
#line 2445 "./marpa.w"

/*292:*/
#line 2630 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)original_start_symid))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
return NULL;
}
/*:292*/
#line 2446 "./marpa.w"

/*295:*/
#line 2659 "./marpa.w"

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
/*:295*/
#line 2447 "./marpa.w"

/*298:*/
#line 2681 "./marpa.w"

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
/*:298*/
#line 2448 "./marpa.w"

/*300:*/
#line 2700 "./marpa.w"

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

/*:300*/
#line 2449 "./marpa.w"

/*280:*/
#line 2524 "./marpa.w"

bv_free(terminal_v);
/*:280*//*286:*/
#line 2576 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:286*//*290:*/
#line 2613 "./marpa.w"

bv_free(nullable_v);

/*:290*//*294:*/
#line 2638 "./marpa.w"

bv_free(productive_v);

/*:294*/
#line 2450 "./marpa.w"

/*297:*/
#line 2678 "./marpa.w"

matrix_free(reach_matrix);

/*:297*/
#line 2451 "./marpa.w"

g->t_is_precomputed= TRUE;
return g;
}
/*:271*//*307:*/
#line 2776 "./marpa.w"

PRIVATE struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*308:*/
#line 2797 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:308*//*312:*/
#line 2847 "./marpa.w"

gint factor_count;
gint*factor_positions;
/*:312*//*317:*/
#line 2897 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:317*/
#line 2779 "./marpa.w"

/*313:*/
#line 2850 "./marpa.w"

factor_positions= g_new(gint,g->t_max_rule_length);
/*:313*//*318:*/
#line 2900 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:318*/
#line 2780 "./marpa.w"

/*310:*/
#line 2809 "./marpa.w"

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

/*:310*/
#line 2781 "./marpa.w"

no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const gint rule_length= Length_of_RULE(rule);
gint nullable_suffix_ix= 0;
/*309:*/
#line 2801 "./marpa.w"

if(!RULE_is_Used(rule)){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}

/*:309*/
#line 2787 "./marpa.w"

/*311:*/
#line 2831 "./marpa.w"

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
/*:311*/
#line 2788 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*315:*/
#line 2856 "./marpa.w"

RULE_is_Used(rule)= 0;
{


gint unprocessed_factor_count;

gint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);


gint piece_end,piece_start= 0;
for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*321:*/
#line 2910 "./marpa.w"

SYMID chaf_virtual_symid;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*316:*/
#line 2880 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:316*/
#line 2918 "./marpa.w"

/*322:*/
#line 2937 "./marpa.w"

{
gint remaining_rhs_length,piece_rhs_length;
/*323:*/
#line 2949 "./marpa.w"

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
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 2964 "./marpa.w"

}

/*:323*/
#line 2940 "./marpa.w"
;
/*324:*/
#line 2967 "./marpa.w"

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
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 2985 "./marpa.w"

}

/*:324*/
#line 2941 "./marpa.w"
;
/*325:*/
#line 2990 "./marpa.w"
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
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3000 "./marpa.w"

}

/*:325*/
#line 2942 "./marpa.w"
;
/*326:*/
#line 3009 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3014 "./marpa.w"

}

/*:326*/
#line 2943 "./marpa.w"
;
}

/*:322*/
#line 2919 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*316:*/
#line 2880 "./marpa.w"

{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
}

/*:316*/
#line 2924 "./marpa.w"

/*328:*/
#line 3019 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
gint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:328*//*329:*/
#line 3028 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3034 "./marpa.w"


/*:329*//*330:*/
#line 3037 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3042 "./marpa.w"


/*:330*//*331:*/
#line 3045 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3051 "./marpa.w"


/*:331*//*332:*/
#line 3054 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3057 "./marpa.w"


/*:332*//*333:*/
#line 3060 "./marpa.w"
}

/*:333*/
#line 2925 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:321*/
#line 2871 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*334:*/
#line 3064 "./marpa.w"
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

/*:334*//*335:*/
#line 3078 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3083 "./marpa.w"


/*:335*//*336:*/
#line 3086 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3091 "./marpa.w"


/*:336*//*337:*/
#line 3094 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3100 "./marpa.w"


/*:337*//*338:*/
#line 3104 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3108 "./marpa.w"

}

/*:338*//*339:*/
#line 3112 "./marpa.w"
}

/*:339*/
#line 2874 "./marpa.w"

}else{
/*340:*/
#line 3115 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
gint real_symbol_count;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:340*//*341:*/
#line 3126 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3131 "./marpa.w"


/*:341*//*342:*/
#line 3135 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*344:*/
#line 3151 "./marpa.w"

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

/*:344*/
#line 3141 "./marpa.w"

}

/*:342*//*343:*/
#line 3145 "./marpa.w"
}

/*:343*/
#line 2876 "./marpa.w"

}
}

/*:315*/
#line 2791 "./marpa.w"

NEXT_RULE:;
}
/*314:*/
#line 2852 "./marpa.w"

g_free(factor_positions);

/*:314*//*319:*/
#line 2903 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:319*/
#line 2794 "./marpa.w"

return g;
}
/*:307*//*345:*/
#line 3170 "./marpa.w"

PRIVATE
SYMID alias_by_id(GRAMMAR g,SYMID proper_id)
{
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
return ID_of_SYM(alias);
}

/*:345*//*347:*/
#line 3181 "./marpa.w"

PRIVATE
GRAMMAR g_augment(GRAMMAR g)
{
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g->t_original_start_symid);
/*348:*/
#line 3196 "./marpa.w"

if(SYM_is_Nulling(old_start)){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:348*/
#line 3190 "./marpa.w"

if(proper_old_start){/*349:*/
#line 3206 "./marpa.w"
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

/*:349*/
#line 3191 "./marpa.w"
}
if(nulling_old_start){/*350:*/
#line 3225 "./marpa.w"
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

/*:350*/
#line 3192 "./marpa.w"
}
return g;
}

/*:347*//*355:*/
#line 3300 "./marpa.w"

PRIVATE
void loop_detect(struct marpa_g*g)
{
gint no_of_rules= RULE_Count_of_G(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_create((guint)no_of_rules,(guint)no_of_rules);
/*356:*/
#line 3324 "./marpa.w"
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

/*:356*/
#line 3308 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*357:*/
#line 3363 "./marpa.w"
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

/*:357*/
#line 3310 "./marpa.w"

if(loop_rule_count)
{
g->t_has_loop= TRUE;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
matrix_free(unit_transition_matrix);
}

/*:355*//*372:*/
#line 3528 "./marpa.w"

PRIVATE gint item_is_valid(
GRAMMAR g,AIMID item_id)
{
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}

/*:372*//*377:*/
#line 3565 "./marpa.w"

gint marpa_g_AHFA_item_count(struct marpa_g*g){
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 3567 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 3568 "./marpa.w"

return AIM_Count_of_G(g);
}

/*:377*//*378:*/
#line 3572 "./marpa.w"

Marpa_Rule_ID marpa_g_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 3575 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 3576 "./marpa.w"

/*1155:*/
#line 12851 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1155*/
#line 3577 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(item_id))->t_id;
}

/*:378*//*380:*/
#line 3582 "./marpa.w"

gint marpa_g_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 3585 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 3586 "./marpa.w"

/*1155:*/
#line 12851 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1155*/
#line 3587 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:380*//*382:*/
#line 3592 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 3595 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 3596 "./marpa.w"

/*1155:*/
#line 12851 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1155*/
#line 3597 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:382*//*383:*/
#line 3601 "./marpa.w"

gint marpa_g_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 3604 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 3605 "./marpa.w"

/*1155:*/
#line 12851 "./marpa.w"

if(!item_is_valid(g,item_id)){
MARPA_DEV_ERROR("invalid item id");
return failure_indicator;
}
/*:1155*/
#line 3606 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:383*//*385:*/
#line 3617 "./marpa.w"

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
/*386:*/
#line 3642 "./marpa.w"

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
/*387:*/
#line 3666 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:387*/
#line 3653 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*388:*/
#line 3675 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:388*/
#line 3662 "./marpa.w"

current_item++;
}

/*:386*/
#line 3630 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
no_of_items= AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*389:*/
#line 3689 "./marpa.w"

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

/*:389*/
#line 3638 "./marpa.w"

/*394:*/
#line 3761 "./marpa.w"

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

/*:394*/
#line 3639 "./marpa.w"

}

/*:385*//*391:*/
#line 3721 "./marpa.w"

PRIVATE_NOT_INLINE gint cmp_by_aimid(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED)
{
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:391*//*393:*/
#line 3737 "./marpa.w"

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

/*:393*//*405:*/
#line 3894 "./marpa.w"

PRIVATE void AHFA_initialize(AHFA ahfa)
{
/*419:*/
#line 3966 "./marpa.w"
AHFA_is_Potential_Leo_Base(ahfa)= 0;

/*:419*//*436:*/
#line 4074 "./marpa.w"
Leo_LHS_ID_of_AHFA(ahfa)= -1;
/*:436*/
#line 3897 "./marpa.w"

}

/*:405*//*413:*/
#line 3927 "./marpa.w"

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

/*:413*//*427:*/
#line 4001 "./marpa.w"

PRIVATE gint AHFA_state_id_is_valid(GRAMMAR g,AHFAID AHFA_state_id)
{
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}


/*:427*//*430:*/
#line 4015 "./marpa.w"

gint marpa_g_AHFA_state_count(Marpa_Grammar g){
return AHFA_Count_of_G(g);
}

/*:430*//*431:*/
#line 4020 "./marpa.w"

gint
marpa_g_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 4023 "./marpa.w"

AHFA state;
/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 4025 "./marpa.w"

/*1156:*/
#line 12856 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1156*/
#line 4026 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}

/*:431*//*432:*/
#line 4033 "./marpa.w"

Marpa_AHFA_Item_ID marpa_g_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
gint item_ix){
AHFA state;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 4038 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 4039 "./marpa.w"

/*1156:*/
#line 12856 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1156*/
#line 4040 "./marpa.w"

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

/*:432*//*433:*/
#line 4053 "./marpa.w"

gint marpa_g_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 4057 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 4058 "./marpa.w"

/*1156:*/
#line 12856 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1156*/
#line 4059 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}

/*:433*//*437:*/
#line 4075 "./marpa.w"

Marpa_Symbol_ID marpa_g_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 4078 "./marpa.w"

AHFA state;
/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 4080 "./marpa.w"

/*1156:*/
#line 12856 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1156*/
#line 4081 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:437*//*440:*/
#line 4102 "./marpa.w"

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

/*:440*//*441:*/
#line 4129 "./marpa.w"

PRIVATE_NOT_INLINE
void create_AHFA_states(struct marpa_g*g)
{
/*442:*/
#line 4149 "./marpa.w"

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

/*:442*/
#line 4133 "./marpa.w"

/*443:*/
#line 4164 "./marpa.w"

/*444:*/
#line 4168 "./marpa.w"

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

/*:444*/
#line 4165 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:443*/
#line 4134 "./marpa.w"

/*464:*/
#line 4674 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_create(symbol_count_of_g,symbol_count_of_g);
/*465:*/
#line 4683 "./marpa.w"

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

/*:465*/
#line 4677 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*466:*/
#line 4720 "./marpa.w"
{
AIM*items_by_rule= g->t_AHFA_items_by_rule;
SYMID from_symid;
guint*sort_key_by_rule_id= g_new(guint,rule_count_of_g);
guint no_of_predictable_rules= 0;
/*467:*/
#line 4752 "./marpa.w"

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

/*:467*/
#line 4726 "./marpa.w"

/*468:*/
#line 4772 "./marpa.w"

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

/*:468*/
#line 4727 "./marpa.w"

/*470:*/
#line 4803 "./marpa.w"

{
guint sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:470*/
#line 4728 "./marpa.w"

/*471:*/
#line 4813 "./marpa.w"

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

/*:471*/
#line 4729 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:466*/
#line 4679 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:464*/
#line 4135 "./marpa.w"

/*451:*/
#line 4312 "./marpa.w"

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

/*:451*/
#line 4136 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*445:*/
#line 4181 "./marpa.w"
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
/*453:*/
#line 4372 "./marpa.w"
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
/*455:*/
#line 4457 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(predot_symid))
> 0)
{
Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:455*/
#line 4425 "./marpa.w"

}
}

/*:453*/
#line 4201 "./marpa.w"

}else{
/*456:*/
#line 4482 "./marpa.w"
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
/*457:*/
#line 4532 "./marpa.w"

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

/*:457*/
#line 4526 "./marpa.w"

transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
/*459:*/
#line 4612 "./marpa.w"
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

/*:459*/
#line 4529 "./marpa.w"

}

/*:456*/
#line 4203 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:445*/
#line 4138 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*446:*/
#line 4213 "./marpa.w"

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

/*:446*/
#line 4143 "./marpa.w"

/*448:*/
#line 4269 "./marpa.w"

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

/*:448*/
#line 4144 "./marpa.w"

/*447:*/
#line 4236 "./marpa.w"

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

/*:447*/
#line 4145 "./marpa.w"

/*449:*/
#line 4302 "./marpa.w"

g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*450:*/
#line 4308 "./marpa.w"

g_free(singleton_duplicates);
g_tree_destroy(duplicates);

/*:450*/
#line 4305 "./marpa.w"

obstack_free(&ahfa_work_obs,NULL);

/*:449*/
#line 4146 "./marpa.w"

}

/*:441*//*458:*/
#line 4601 "./marpa.w"

PRIVATE AHFA
assign_AHFA_state(AHFA sought_state,GTree*duplicates)
{
const AHFA state_found= g_tree_lookup(duplicates,sought_state);
if(state_found)return state_found;
g_tree_insert(duplicates,sought_state,sought_state);
return NULL;
}

/*:458*//*469:*/
#line 4784 "./marpa.w"

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

/*:469*//*472:*/
#line 4853 "./marpa.w"

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
/*473:*/
#line 4908 "./marpa.w"

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

/*:473*/
#line 4904 "./marpa.w"

return p_new_state;
}

/*:472*//*484:*/
#line 5017 "./marpa.w"

PRIVATE AHFA to_ahfa_of_transition_get(TRANS transition)
{
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:484*//*485:*/
#line 5023 "./marpa.w"

PRIVATE gint completion_count_of_transition_get(TRANS transition)
{
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:485*//*486:*/
#line 5030 "./marpa.w"

PRIVATE
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix)
{
URTRANS transition;
transition= obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:486*//*487:*/
#line 5041 "./marpa.w"

PRIVATE TRANS*transitions_new(GRAMMAR g)
{
gint symbol_count= SYM_Count_of_G(g);
gint symid= 0;
TRANS*transitions;
transitions= g_malloc(symbol_count*sizeof(transitions[0]));
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:487*//*488:*/
#line 5054 "./marpa.w"

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

/*:488*//*489:*/
#line 5068 "./marpa.w"

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

/*:489*//*491:*/
#line 5083 "./marpa.w"

gint marpa_g_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5088 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
gint symbol_count;

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 5094 "./marpa.w"

/*1156:*/
#line 12856 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1156*/
#line 5095 "./marpa.w"

/*1157:*/
#line 12861 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
MARPA_DEV_ERROR("garray size mismatch");
return failure_indicator;
}
/*:1157*/
#line 5096 "./marpa.w"

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

/*:491*//*494:*/
#line 5115 "./marpa.w"

AHFAID marpa_g_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5120 "./marpa.w"

/*1152:*/
#line 12836 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_DEV_ERROR("grammar not precomputed");
return failure_indicator;
}
/*:1152*/
#line 5121 "./marpa.w"

/*1156:*/
#line 12856 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
MARPA_DEV_ERROR("invalid AHFA state id");
return failure_indicator;
}
/*:1156*/
#line 5122 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:494*//*499:*/
#line 5158 "./marpa.w"

PRIVATE INPUT
input_new(GRAMMAR g)
{
const gint symbol_count_of_g= SYM_Count_of_G(g);
TOK*tokens_by_symid;
INPUT input= g_slice_new(struct s_input);
/*502:*/
#line 5172 "./marpa.w"

input->t_ref_count= 1;

/*:502*//*508:*/
#line 5230 "./marpa.w"

{
gint ix;
obstack_init(TOK_Obs_of_I(input));
tokens_by_symid= 
obstack_alloc(TOK_Obs_of_I(input),sizeof(TOK)*symbol_count_of_g);
for(ix= 0;ix<symbol_count_of_g;ix++)
{
tokens_by_symid[ix]= token_new(input,ix,Default_Token_Value_of_G(g));
}
TOKs_by_SYMID_of_I(input)= tokens_by_symid;
}
/*:508*//*512:*/
#line 5255 "./marpa.w"

{
G_of_I(input)= g;
grammar_ref(g);
}

/*:512*/
#line 5165 "./marpa.w"

return input;
}

/*:499*//*503:*/
#line 5176 "./marpa.w"

PRIVATE void
input_unref(INPUT input)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,input->t_ref_count);
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count--;
if(input->t_ref_count<=0)
{
input_free(input);
}
}

/*:503*//*504:*/
#line 5190 "./marpa.w"

PRIVATE INPUT
input_ref(INPUT input)
{
MARPA_DEBUG4("%s %s: ref_count=%d",G_STRFUNC,G_STRLOC,input->t_ref_count);
MARPA_ASSERT(input->t_ref_count> 0)
input->t_ref_count++;
return input;
}

/*:504*//*505:*/
#line 5200 "./marpa.w"

PRIVATE void input_free(INPUT input)
{
/*509:*/
#line 5242 "./marpa.w"

{
TOK*tokens_by_symid= TOKs_by_SYMID_of_I(input);
if(tokens_by_symid){
obstack_free(TOK_Obs_of_I(input),NULL);
TOKs_by_SYMID_of_I(input)= NULL;
}
}

/*:509*/
#line 5203 "./marpa.w"

g_slice_free(struct s_input,input);
}

/*:505*//*516:*/
#line 5283 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
gint symbol_count_of_g;
/*1149:*/
#line 12823 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1149*/
#line 5288 "./marpa.w"

if(!G_is_Precomputed(g)){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}
r= g_slice_new(struct marpa_r);
symbol_count_of_g= SYM_Count_of_G(g);
/*575:*/
#line 5655 "./marpa.w"
obstack_init(&r->t_obs);
/*:575*/
#line 5295 "./marpa.w"

/*519:*/
#line 5302 "./marpa.w"

r->t_ref_count= 1;

/*:519*//*527:*/
#line 5375 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:527*//*529:*/
#line 5384 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:529*//*533:*/
#line 5408 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:533*//*537:*/
#line 5431 "./marpa.w"
r->t_furthest_earleme= 0;
/*:537*//*541:*/
#line 5444 "./marpa.w"
r->t_sym_workarea= NULL;
/*:541*//*545:*/
#line 5455 "./marpa.w"
r->t_workarea2= NULL;
/*:545*//*549:*/
#line 5475 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:549*//*553:*/
#line 5498 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:553*//*567:*/
#line 5595 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:567*//*571:*/
#line 5631 "./marpa.w"
r->t_is_exhausted= 0;
/*:571*//*595:*/
#line 5752 "./marpa.w"

r->t_earley_set_count= 0;

/*:595*//*600:*/
#line 5799 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:600*//*621:*/
#line 6061 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:621*//*651:*/
#line 6442 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:651*//*686:*/
#line 6901 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:686*//*719:*/
#line 7383 "./marpa.w"

{
I_of_R(r)= input_new(g);
}

/*:719*//*725:*/
#line 7434 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:725*//*746:*/
#line 7725 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:746*//*750:*/
#line 7737 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:750*//*754:*/
#line 7749 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:754*//*823:*/
#line 8607 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:823*//*1122:*/
#line 12552 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1122*/
#line 5296 "./marpa.w"

return r;
}

/*:516*//*520:*/
#line 5306 "./marpa.w"

PRIVATE void
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

/*:520*//*521:*/
#line 5325 "./marpa.w"

PRIVATE
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

/*:521*//*522:*/
#line 5340 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
MARPA_DEBUG4("%s %s: Destroying %p",G_STRFUNC,G_STRLOC,r)
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5345 "./marpa.w"

/*524:*/
#line 5362 "./marpa.w"
input_unref(input);

/*:524*//*597:*/
#line 5776 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
if(EIMs_of_ES(set))
g_free(EIMs_of_ES(set));
}
}

/*:597*//*726:*/
#line 7436 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:726*//*748:*/
#line 7730 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:748*//*752:*/
#line 7742 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:752*//*755:*/
#line 7750 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:755*//*824:*/
#line 8609 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:824*//*1123:*/
#line 12554 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1123*/
#line 5346 "./marpa.w"

grammar_unref(g);
if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*551:*/
#line 5484 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:551*//*555:*/
#line 5501 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:555*/
#line 5350 "./marpa.w"

/*576:*/
#line 5656 "./marpa.w"
obstack_free(&r->t_obs,NULL);

/*:576*/
#line 5351 "./marpa.w"

g_slice_free(struct marpa_r,r);
}

/*:522*//*530:*/
#line 5392 "./marpa.w"

guint marpa_r_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:530*//*531:*/
#line 5397 "./marpa.w"

PRIVATE ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:531*//*534:*/
#line 5410 "./marpa.w"

gint marpa_r_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:534*//*535:*/
#line 5416 "./marpa.w"

gint marpa_r_earley_item_warning_threshold_set(struct marpa_r*r,gint threshold)
{
r->t_earley_item_warning_threshold= threshold<=0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:535*//*538:*/
#line 5432 "./marpa.w"

guint marpa_r_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:538*//*556:*/
#line 5511 "./marpa.w"

gint marpa_r_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5514 "./marpa.w"

/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5515 "./marpa.w"

guint min,max,start;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 5517 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 5518 "./marpa.w"

/*1165:*/
#line 12905 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
R_DEV_ERROR("garray size mismatch");
return failure_indicator;
}

/*:1165*/
#line 5519 "./marpa.w"

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

/*:556*//*568:*/
#line 5601 "./marpa.w"

gint marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5604 "./marpa.w"

/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5605 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 5606 "./marpa.w"

return r->t_use_leo_flag;
}
/*:568*//*569:*/
#line 5609 "./marpa.w"

gint marpa_r_is_use_leo_set(
Marpa_Recognizer r,gint value)
{
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5613 "./marpa.w"

/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5614 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 5615 "./marpa.w"

/*1159:*/
#line 12874 "./marpa.w"

if(Input_Phase_of_R(r)!=R_BEFORE_INPUT){
R_DEV_ERROR("recce started");
return failure_indicator;
}
/*:1159*/
#line 5616 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:569*//*573:*/
#line 5641 "./marpa.w"

gint marpa_r_is_exhausted(struct marpa_r*r)
{
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5644 "./marpa.w"

/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5645 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 5646 "./marpa.w"

return R_is_Exhausted(r);
}

/*:573*//*578:*/
#line 5660 "./marpa.w"

Marpa_Error_Code marpa_r_error(Marpa_Recognizer r,const char**p_error_string)
{
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5663 "./marpa.w"

return marpa_g_error(g,p_error_string);
}

/*:578*//*580:*/
#line 5669 "./marpa.w"

gint marpa_r_event(Marpa_Recognizer r,Marpa_Event public_event,gint ix)
{
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5672 "./marpa.w"

return marpa_g_event(g,public_event,ix);
}

/*:580*//*596:*/
#line 5756 "./marpa.w"

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
/*1128:*/
#line 12601 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1128*/
#line 5771 "./marpa.w"

return set;
}

/*:596*//*601:*/
#line 5802 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_trace_earley_set(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5805 "./marpa.w"

/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5806 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 5808 "./marpa.w"

if(!trace_earley_set){
R_DEV_ERROR("no trace es");
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:601*//*602:*/
#line 5816 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5819 "./marpa.w"

/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5820 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 5821 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:602*//*603:*/
#line 5825 "./marpa.w"

Marpa_Earleme marpa_r_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const gint es_does_not_exist= -1;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5829 "./marpa.w"

/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5830 "./marpa.w"

ES earley_set;
/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 5832 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 5833 "./marpa.w"

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

/*:603*//*605:*/
#line 5849 "./marpa.w"

gint marpa_r_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 5852 "./marpa.w"

ES earley_set;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5854 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 5855 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 5856 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
R_DEV_ERROR("invalid es ordinal");
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:605*//*614:*/
#line 5952 "./marpa.w"

PRIVATE EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1149:*/
#line 12823 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1149*/
#line 5956 "./marpa.w"

/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 5957 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const gint count= ++EIM_Count_of_ES(set);
/*616:*/
#line 6004 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(G_UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
R_FATAL(MARPA_ERR_EIM_COUNT,"eim count exceeds fatal threshold");
return failure_indicator;
}
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,count);
}

/*:616*/
#line 5962 "./marpa.w"

new_item= obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:614*//*615:*/
#line 5972 "./marpa.w"

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

/*:615*//*619:*/
#line 6036 "./marpa.w"

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

/*:619*//*626:*/
#line 6101 "./marpa.w"

Marpa_Earleme
marpa_r_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const gint es_does_not_exist= -1;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6107 "./marpa.w"

/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6108 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6109 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*627:*/
#line 6132 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*653:*/
#line 6481 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:653*/
#line 6135 "./marpa.w"

}

/*:627*/
#line 6116 "./marpa.w"

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

/*:626*//*628:*/
#line 6138 "./marpa.w"

Marpa_AHFA_State_ID
marpa_r_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const gint eim_does_not_exist= -1;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6143 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6147 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6148 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*627:*/
#line 6132 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*653:*/
#line 6481 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:653*/
#line 6135 "./marpa.w"

}

/*:627*/
#line 6152 "./marpa.w"

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

/*:628*//*630:*/
#line 6181 "./marpa.w"

PRIVATE void trace_earley_item_clear(struct marpa_r*r)
{
/*629:*/
#line 6178 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:629*/
#line 6184 "./marpa.w"

trace_source_link_clear(r);
}

/*:630*//*631:*/
#line 6188 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_earley_item_origin(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6191 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 6193 "./marpa.w"

if(!item){
/*629:*/
#line 6178 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:629*/
#line 6195 "./marpa.w"

R_DEV_ERROR("no trace eim");
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:631*//*638:*/
#line 6268 "./marpa.w"

Marpa_Symbol_ID marpa_r_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6272 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6275 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6276 "./marpa.w"

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

/*:638*//*639:*/
#line 6290 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6294 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6296 "./marpa.w"

EIM base_earley_item;
/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6298 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:639*//*640:*/
#line 6308 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6312 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6315 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6316 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:640*//*644:*/
#line 6350 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6354 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6356 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6357 "./marpa.w"

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


/*:644*//*648:*/
#line 6406 "./marpa.w"

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
/*:648*//*649:*/
#line 6426 "./marpa.w"

PRIVATE PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:649*//*652:*/
#line 6456 "./marpa.w"

Marpa_Symbol_ID
marpa_r_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6461 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6465 "./marpa.w"

/*653:*/
#line 6481 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:653*/
#line 6466 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6467 "./marpa.w"

/*1164:*/
#line 12900 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
R_DEV_ERROR("invalid symid");
return failure_indicator;
}
/*:1164*/
#line 6468 "./marpa.w"

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

/*:652*//*654:*/
#line 6491 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_postdot_item_trace(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6495 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6498 "./marpa.w"

PIM*pim_sym_p;
/*653:*/
#line 6481 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:653*/
#line 6500 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6501 "./marpa.w"

if(!current_earley_set){
/*629:*/
#line 6178 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:629*/
#line 6503 "./marpa.w"

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

/*:654*//*655:*/
#line 6522 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6527 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6531 "./marpa.w"


pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*653:*/
#line 6481 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:653*/
#line 6535 "./marpa.w"

if(!pim_sym_p||!pim){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6540 "./marpa.w"

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

/*:655*//*656:*/
#line 6560 "./marpa.w"

Marpa_AHFA_State_ID marpa_r_postdot_item_symbol(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6563 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6565 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6566 "./marpa.w"

if(!postdot_item){
R_DEV_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:656*//*672:*/
#line 6694 "./marpa.w"
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

/*:672*//*677:*/
#line 6770 "./marpa.w"

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

/*:677*//*678:*/
#line 6798 "./marpa.w"

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

/*:678*//*680:*/
#line 6845 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
guint previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*681:*/
#line 6862 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= new_link;
}

/*:681*/
#line 6853 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*682:*/
#line 6871 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= NULL;
First_Completion_Link_of_EIM(item)= new_link;
First_Token_Link_of_EIM(item)= NULL;
}

/*:682*/
#line 6855 "./marpa.w"

return;
case SOURCE_IS_LEO:/*683:*/
#line 6880 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
First_Leo_SRCL_of_EIM(item)= new_link;
First_Completion_Link_of_EIM(item)= NULL;
First_Token_Link_of_EIM(item)= NULL;
}

/*:683*/
#line 6857 "./marpa.w"

return;
}
}

/*:680*//*688:*/
#line 6912 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_token_link_trace(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6915 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6919 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6920 "./marpa.w"

/*702:*/
#line 7139 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:702*/
#line 6921 "./marpa.w"

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

/*:688*//*691:*/
#line 6956 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_token_link_trace(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6959 "./marpa.w"

SRCL full_link;
EIM item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6962 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6963 "./marpa.w"

/*702:*/
#line 7139 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:702*/
#line 6964 "./marpa.w"

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

/*:691*//*693:*/
#line 6987 "./marpa.w"

Marpa_Symbol_ID marpa_r_first_completion_link_trace(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 6990 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 6994 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 6995 "./marpa.w"

/*702:*/
#line 7139 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:702*/
#line 6996 "./marpa.w"

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

/*:693*//*696:*/
#line 7030 "./marpa.w"

Marpa_Symbol_ID marpa_r_next_completion_link_trace(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7033 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7037 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 7038 "./marpa.w"

/*702:*/
#line 7139 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:702*/
#line 7039 "./marpa.w"

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

/*:696*//*698:*/
#line 7063 "./marpa.w"

Marpa_Symbol_ID
marpa_r_first_leo_link_trace(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7067 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7071 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 7072 "./marpa.w"

/*702:*/
#line 7139 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:702*/
#line 7073 "./marpa.w"

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

/*:698*//*701:*/
#line 7109 "./marpa.w"

Marpa_Symbol_ID
marpa_r_next_leo_link_trace(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7113 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7117 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 7118 "./marpa.w"

/*702:*/
#line 7139 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_DEV_ERROR("no eim");
return failure_indicator;
}

/*:702*/
#line 7119 "./marpa.w"

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

/*:701*//*703:*/
#line 7148 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:703*//*704:*/
#line 7164 "./marpa.w"

AHFAID marpa_r_source_predecessor_state(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7167 "./marpa.w"

guint source_type;
SRC source;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7170 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 7171 "./marpa.w"

source_type= r->t_trace_source_type;
/*711:*/
#line 7315 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:711*/
#line 7173 "./marpa.w"

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

/*:704*//*705:*/
#line 7205 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_token(struct marpa_r*r,gpointer*value_p)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7208 "./marpa.w"

guint source_type;
SRC source;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7211 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 7212 "./marpa.w"

source_type= r->t_trace_source_type;
/*711:*/
#line 7315 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:711*/
#line 7214 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:705*//*707:*/
#line 7237 "./marpa.w"

Marpa_Symbol_ID marpa_r_source_leo_transition_symbol(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7240 "./marpa.w"

guint source_type;
SRC source;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7243 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 7244 "./marpa.w"

source_type= r->t_trace_source_type;
/*711:*/
#line 7315 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:711*/
#line 7246 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
R_DEV_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:707*//*710:*/
#line 7283 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_source_middle(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7286 "./marpa.w"

const EARLEME no_predecessor= -1;
guint source_type;
SRC source;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7290 "./marpa.w"

/*1162:*/
#line 12890 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 12891 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 12892 "./marpa.w"


/*:1162*/
#line 7291 "./marpa.w"

source_type= r->t_trace_source_type;
/*711:*/
#line 7315 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_DEV_ERROR("no trace source link");
return failure_indicator;
}

/*:711*/
#line 7293 "./marpa.w"

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

/*:710*//*720:*/
#line 7388 "./marpa.w"

PRIVATE
TOK token_new(INPUT input,SYMID symbol_id,gpointer value)
{
TOK token;
token= obstack_alloc(TOK_Obs_of_I(input),sizeof(*token));
Type_of_TOK(token)= TOKEN_OR_NODE;
SYMID_of_TOK(token)= symbol_id;
Value_of_TOK(token)= value;
return token;
}

/*:720*//*728:*/
#line 7442 "./marpa.w"

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

/*:728*//*730:*/
#line 7486 "./marpa.w"

PRIVATE gint alternative_cmp(const ALT_Const a,const ALT_Const b)
{
gint subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:730*//*731:*/
#line 7503 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:731*//*732:*/
#line 7518 "./marpa.w"

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

/*:732*//*733:*/
#line 7537 "./marpa.w"
gint marpa_r_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7543 "./marpa.w"

const gint symbol_count_of_g= SYM_Count_of_G(g);
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7545 "./marpa.w"

/*1159:*/
#line 12874 "./marpa.w"

if(Input_Phase_of_R(r)!=R_BEFORE_INPUT){
R_DEV_ERROR("recce started");
return failure_indicator;
}
/*:1159*/
#line 7546 "./marpa.w"

Current_Earleme_of_R(r)= 0;
if(G_is_Trivial(g)){
/*572:*/
#line 5632 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:572*/
#line 7549 "./marpa.w"

return TRUE;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
/*546:*/
#line 5456 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*542:*/
#line 5445 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:542*/
#line 5459 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:546*/
#line 7553 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*550:*/
#line 5479 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:550*//*554:*/
#line 5499 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:554*/
#line 7555 "./marpa.w"

/*747:*/
#line 7726 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT(r->t_eim_work_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:747*//*751:*/
#line 7738 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT(r->t_completion_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:751*/
#line 7556 "./marpa.w"

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

/*:733*//*740:*/
#line 7624 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID token_id,
gpointer value,
gint length)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7631 "./marpa.w"

/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7632 "./marpa.w"

const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1161:*/
#line 12884 "./marpa.w"

if(Input_Phase_of_R(r)!=R_DURING_INPUT){
R_DEV_ERROR("recce not accepting input");
return failure_indicator;
}

/*:1161*/
#line 7638 "./marpa.w"

/*741:*/
#line 7646 "./marpa.w"
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

/*:741*/
#line 7639 "./marpa.w"

/*743:*/
#line 7677 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:743*/
#line 7640 "./marpa.w"

/*742:*/
#line 7662 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
R_DEV_ERROR("parse too long");
return failure_indicator;
}
}

/*:742*/
#line 7641 "./marpa.w"

/*744:*/
#line 7700 "./marpa.w"

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
/*721:*/
#line 7403 "./marpa.w"
obstack_free(TOK_Obs_of_R(r),token);

/*:721*/
#line 7711 "./marpa.w"

return duplicate_token_indicator;
}
}

/*:744*/
#line 7642 "./marpa.w"

return current_earleme;
}

/*:740*//*757:*/
#line 7769 "./marpa.w"

Marpa_Earleme
marpa_r_earleme_complete(struct marpa_r*r)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 7773 "./marpa.w"

/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 7774 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
gint count_of_expected_terminals;
/*1161:*/
#line 12884 "./marpa.w"

if(Input_Phase_of_R(r)!=R_DURING_INPUT){
R_DEV_ERROR("recce not accepting input");
return failure_indicator;
}

/*:1161*/
#line 7779 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*758:*/
#line 7807 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*572:*/
#line 5632 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:572*/
#line 7811 "./marpa.w"

R_DEV_ERROR("parse exhausted");
return failure_indicator;
}
}

/*:758*/
#line 7783 "./marpa.w"

/*760:*/
#line 7832 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:760*/
#line 7784 "./marpa.w"

/*759:*/
#line 7819 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
Latest_ES_of_R(r)= current_earley_set;
}

/*:759*/
#line 7785 "./marpa.w"

/*761:*/
#line 7838 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*762:*/
#line 7845 "./marpa.w"

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

/*:762*/
#line 7842 "./marpa.w"

}

/*:761*/
#line 7786 "./marpa.w"

/*763:*/
#line 7872 "./marpa.w"
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

/*:763*/
#line 7787 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*764:*/
#line 7891 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*765:*/
#line 7904 "./marpa.w"

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
/*766:*/
#line 7927 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*767:*/
#line 7943 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:767*/
#line 7936 "./marpa.w"

}
/*768:*/
#line 7950 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:768*/
#line 7938 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:766*/
#line 7915 "./marpa.w"

}
else
{
/*769:*/
#line 7960 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*767:*/
#line 7943 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:767*/
#line 7969 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:769*/
#line 7919 "./marpa.w"

break;


}
}
}

/*:765*/
#line 7900 "./marpa.w"

}
}

/*:764*/
#line 7790 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


/*572:*/
#line 5632 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
}

/*:572*/
#line 7800 "./marpa.w"

event_new(g,MARPA_EVENT_EXHAUSTED);
}
earley_set_update_items(r,current_earley_set);
return G_EVENT_COUNT(g);
}

/*:757*//*770:*/
#line 7974 "./marpa.w"

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

/*:770*//*771:*/
#line 7999 "./marpa.w"

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

/*:771*//*777:*/
#line 8043 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,ES current_earley_set)
{
gpointer*const pim_workarea= r->t_sym_workarea;
/*523:*/
#line 5359 "./marpa.w"

const INPUT input= I_of_R(r);
const GRAMMAR g= G_of_I(input);
/*:523*/
#line 8048 "./marpa.w"

EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*778:*/
#line 8065 "./marpa.w"
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

/*:778*/
#line 8054 "./marpa.w"

if(r->t_is_using_leo){
/*782:*/
#line 8123 "./marpa.w"

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
/*783:*/
#line 8157 "./marpa.w"
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

/*:783*/
#line 8143 "./marpa.w"

}
}
}
}
}
}

/*:782*/
#line 8056 "./marpa.w"

/*792:*/
#line 8242 "./marpa.w"
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

/*795:*/
#line 8301 "./marpa.w"
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

/*:795*/
#line 8260 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*801:*/
#line 8393 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:801*/
#line 8262 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*803:*/
#line 8414 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:803*/
#line 8268 "./marpa.w"

continue;
}
/*796:*/
#line 8316 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*799:*/
#line 8337 "./marpa.w"
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

/*795:*/
#line 8301 "./marpa.w"
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

/*:795*/
#line 8363 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:799*/
#line 8319 "./marpa.w"

/*800:*/
#line 8382 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*801:*/
#line 8393 "./marpa.w"
{
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:801*/
#line 8386 "./marpa.w"

}else{
/*803:*/
#line 8414 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:803*/
#line 8388 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:800*/
#line 8320 "./marpa.w"

}

/*:796*/
#line 8271 "./marpa.w"

}
}
}

/*:792*/
#line 8057 "./marpa.w"

}
/*804:*/
#line 8420 "./marpa.w"
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

/*:804*/
#line 8059 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:777*//*825:*/
#line 8612 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:825*//*826:*/
#line 8620 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:826*//*827:*/
#line 8626 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)obstack_free(&stack->t_obs,NULL);
stack->t_base= NULL;
}

/*:827*//*828:*/
#line 8633 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:828*//*829:*/
#line 8643 "./marpa.w"

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

/*:829*//*830:*/
#line 8659 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:830*//*834:*/
#line 8722 "./marpa.w"

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

/*:834*//*870:*/
#line 9341 "./marpa.w"

PRIVATE AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:870*//*871:*/
#line 9353 "./marpa.w"

PRIVATE AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:871*//*877:*/
#line 9472 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause);
return draft_and_node;
}

/*:877*//*879:*/
#line 9495 "./marpa.w"

PRIVATE
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:879*//*906:*/
#line 9939 "./marpa.w"

gint marpa_b_and_node_count(Marpa_Bocage b)
{
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 9942 "./marpa.w"

/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 9943 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 9944 "./marpa.w"

return AND_Count_of_B(b);
}

/*:906*//*908:*/
#line 9965 "./marpa.w"

gint marpa_b_and_node_parent(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 9969 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 9970 "./marpa.w"

/*907:*/
#line 9948 "./marpa.w"
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

/*:907*/
#line 9971 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:908*//*909:*/
#line 9975 "./marpa.w"

gint marpa_b_and_node_predecessor(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 9979 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 9980 "./marpa.w"

/*907:*/
#line 9948 "./marpa.w"
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

/*:907*/
#line 9981 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:909*//*910:*/
#line 9990 "./marpa.w"

gint marpa_b_and_node_cause(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 9994 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 9995 "./marpa.w"

/*907:*/
#line 9948 "./marpa.w"
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

/*:907*/
#line 9996 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:910*//*911:*/
#line 10005 "./marpa.w"

gint marpa_b_and_node_symbol(Marpa_Bocage b,int and_node_id)
{
AND and_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10009 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10010 "./marpa.w"

/*907:*/
#line 9948 "./marpa.w"
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

/*:907*/
#line 10011 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:911*//*912:*/
#line 10020 "./marpa.w"

Marpa_Symbol_ID marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,gpointer*value_p)
{
AND and_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10025 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10026 "./marpa.w"

/*907:*/
#line 9948 "./marpa.w"
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

/*:907*/
#line 10027 "./marpa.w"

return and_node_token(and_node,value_p);
}
/*:912*//*913:*/
#line 10030 "./marpa.w"

PRIVATE SYMID and_node_token(AND and_node,gpointer*value_p)
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

/*:913*//*927:*/
#line 10097 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Rule_ID rule_id,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1149:*/
#line 12823 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1149*/
#line 10102 "./marpa.w"

/*928:*/
#line 10141 "./marpa.w"

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

/*:928*//*931:*/
#line 10165 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:931*/
#line 10103 "./marpa.w"

INPUT input;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10105 "./marpa.w"

/*1160:*/
#line 12879 "./marpa.w"

if(Input_Phase_of_R(r)==R_BEFORE_INPUT){
R_DEV_ERROR("recce not started");
return failure_indicator;
}
/*:1160*/
#line 10106 "./marpa.w"

b= g_slice_new(struct s_bocage);
/*857:*/
#line 9082 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;

/*:857*//*923:*/
#line 10076 "./marpa.w"

b->is_obstack_initialized= 1;
obstack_init(&OBS_of_B(b));
/*:923*//*947:*/
#line 10369 "./marpa.w"

b->t_ref_count= 1;

/*:947*/
#line 10108 "./marpa.w"

input= I_of_B(b)= I_of_R(r);
input_ref(input);

if(G_is_Trivial(g)){
if(ordinal_arg> 0)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
r_update_earley_sets(r);
/*932:*/
#line 10168 "./marpa.w"

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

/*:932*/
#line 10117 "./marpa.w"

if(end_of_parse_earleme==0){
if(!g->t_null_start_rule)goto B_NEW_RETURN_ERROR;
return r_create_null_bocage(r,b);
}
/*933:*/
#line 10189 "./marpa.w"

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

/*:933*/
#line 10122 "./marpa.w"

/*939:*/
#line 10299 "./marpa.w"

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

/*:939*/
#line 10123 "./marpa.w"

if(!start_eim)goto B_NEW_RETURN_ERROR;
obstack_init(&bocage_setup_obs);
/*936:*/
#line 10247 "./marpa.w"

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

/*:936*/
#line 10126 "./marpa.w"

/*832:*/
#line 8681 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*833:*/
#line 8709 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:833*/
#line 8690 "./marpa.w"

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
/*835:*/
#line 8750 "./marpa.w"

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
/*833:*/
#line 8709 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:833*/
#line 8778 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:835*/
#line 8703 "./marpa.w"

/*837:*/
#line 8819 "./marpa.w"

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
/*833:*/
#line 8709 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:833*/
#line 8855 "./marpa.w"

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
/*833:*/
#line 8709 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:833*/
#line 8868 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:837*/
#line 8704 "./marpa.w"

/*838:*/
#line 8878 "./marpa.w"

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
/*833:*/
#line 8709 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:833*/
#line 8911 "./marpa.w"

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
/*833:*/
#line 8709 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:833*/
#line 8927 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:838*/
#line 8705 "./marpa.w"

}
}

/*:832*/
#line 10127 "./marpa.w"

/*859:*/
#line 9105 "./marpa.w"

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
/*1134:*/
#line 12658 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1134*/
#line 9125 "./marpa.w"

/*860:*/
#line 9133 "./marpa.w"

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
/*861:*/
#line 9153 "./marpa.w"

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
/*1134:*/
#line 12658 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1134*/
#line 9166 "./marpa.w"

/*863:*/
#line 9184 "./marpa.w"

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
/*864:*/
#line 9214 "./marpa.w"

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


/*:864*/
#line 9195 "./marpa.w"

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

/*:863*/
#line 9167 "./marpa.w"

/*866:*/
#line 9239 "./marpa.w"

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
/*864:*/
#line 9214 "./marpa.w"

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


/*:864*/
#line 9263 "./marpa.w"

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

/*:866*/
#line 9168 "./marpa.w"

}




MARPA_OFF_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*867:*/
#line 9283 "./marpa.w"
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
/*869:*/
#line 9323 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const gint ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const gint symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*872:*/
#line 9364 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1134:*/
#line 12658 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1134*/
#line 9371 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*864:*/
#line 9214 "./marpa.w"

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


/*:864*/
#line 9375 "./marpa.w"

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

/*:872*/
#line 9333 "./marpa.w"

/*873:*/
#line 9393 "./marpa.w"

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
/*864:*/
#line 9214 "./marpa.w"

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


/*:864*/
#line 9410 "./marpa.w"

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

/*:873*/
#line 9334 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:869*/
#line 9305 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:867*/
#line 9176 "./marpa.w"

}

/*:861*/
#line 9147 "./marpa.w"

}
}
}
}

/*:860*/
#line 9126 "./marpa.w"

/*880:*/
#line 9505 "./marpa.w"

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
/*882:*/
#line 9542 "./marpa.w"

{
guint work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const gint work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*883:*/
#line 9558 "./marpa.w"
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
/*884:*/
#line 9590 "./marpa.w"

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
/*885:*/
#line 9619 "./marpa.w"

{
if(higher_path_leo_item){
/*889:*/
#line 9667 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:889*/
#line 9622 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:885*/
#line 9605 "./marpa.w"

/*887:*/
#line 9633 "./marpa.w"

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

/*:887*/
#line 9606 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*885:*/
#line 9619 "./marpa.w"

{
if(higher_path_leo_item){
/*889:*/
#line 9667 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:889*/
#line 9622 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:885*/
#line 9613 "./marpa.w"

/*890:*/
#line 9677 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const gint origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
MARPA_OFF_DEBUG2("lim=%s",lim_tag(path_leo_item));
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:890*/
#line 9614 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:884*/
#line 9580 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:883*/
#line 9553 "./marpa.w"

/*891:*/
#line 9688 "./marpa.w"

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
/*892:*/
#line 9718 "./marpa.w"

{
OR dand_predecessor;
/*893:*/
#line 9727 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:893*/
#line 9721 "./marpa.w"

MARPA_OFF_DEBUG2("or=%s",or_tag(work_proper_or_node));
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:892*/
#line 9710 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:891*/
#line 9554 "./marpa.w"

/*894:*/
#line 9738 "./marpa.w"

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
/*895:*/
#line 9778 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const gint middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*893:*/
#line 9727 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:893*/
#line 9786 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
MARPA_OFF_DEBUG2("completion source, or=%s",or_tag(work_proper_or_node));
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:895*/
#line 9769 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:894*/
#line 9555 "./marpa.w"

}

/*:882*/
#line 9520 "./marpa.w"

}
}
}
}
}

/*:880*/
#line 9127 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= g_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:859*/
#line 10128 "./marpa.w"

/*903:*/
#line 9894 "./marpa.w"

{
gint unique_draft_and_node_count= 0;
/*896:*/
#line 9793 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const gint or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
gint or_node_id= 0;
psar_init(and_psar,rule_count_of_g+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*898:*/
#line 9825 "./marpa.w"

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

/*:898*/
#line 9803 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:896*/
#line 9897 "./marpa.w"

/*904:*/
#line 9901 "./marpa.w"

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

/*:904*/
#line 9898 "./marpa.w"

}

/*:903*/
#line 10129 "./marpa.w"

/*940:*/
#line 10327 "./marpa.w"

{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_earley_set);
OR**const nodes_by_item= 
per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const gint start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
Top_ORID_of_B(b)= ID_of_OR(top_or_node);
}

/*:940*/
#line 10130 "./marpa.w"
;
obstack_free(&bocage_setup_obs,NULL);
return b;
B_NEW_RETURN_ERROR:;
input_unref(input);
if(b){
/*950:*/
#line 10408 "./marpa.w"

/*858:*/
#line 9088 "./marpa.w"

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

/*:858*/
#line 10409 "./marpa.w"
;
/*924:*/
#line 10079 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:924*/
#line 10410 "./marpa.w"
;

/*:950*/
#line 10136 "./marpa.w"
;
}
return NULL;
}

/*:927*//*935:*/
#line 10213 "./marpa.w"

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

/*:935*//*942:*/
#line 10350 "./marpa.w"

Marpa_Grammar marpa_b_g(Marpa_Bocage b)
{
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10353 "./marpa.w"

return g;
}

/*:942*//*944:*/
#line 10358 "./marpa.w"

Marpa_Or_Node_ID marpa_b_top_or_node(Marpa_Bocage b)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10361 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10362 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10363 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:944*//*948:*/
#line 10373 "./marpa.w"

PRIVATE void
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

/*:948*//*949:*/
#line 10392 "./marpa.w"

PRIVATE BOCAGE
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

/*:949*//*951:*/
#line 10415 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
MARPA_DEBUG4("%s %s: Destroying %p",G_STRFUNC,G_STRLOC,b)
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10420 "./marpa.w"

input_unref(input);
if(b)
{
/*950:*/
#line 10408 "./marpa.w"

/*858:*/
#line 9088 "./marpa.w"

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

/*:858*/
#line 10409 "./marpa.w"
;
/*924:*/
#line 10079 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:924*/
#line 10410 "./marpa.w"
;

/*:950*/
#line 10424 "./marpa.w"
;
g_slice_free(struct s_bocage,b);
}
}

/*:951*//*954:*/
#line 10449 "./marpa.w"

gint marpa_b_or_node_set(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10453 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10454 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10455 "./marpa.w"

/*953:*/
#line 10432 "./marpa.w"
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

/*:953*/
#line 10456 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:954*//*955:*/
#line 10460 "./marpa.w"

gint marpa_b_or_node_origin(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10464 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10465 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10466 "./marpa.w"

/*953:*/
#line 10432 "./marpa.w"
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

/*:953*/
#line 10467 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:955*//*956:*/
#line 10471 "./marpa.w"

gint marpa_b_or_node_rule(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10475 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10476 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10477 "./marpa.w"

/*953:*/
#line 10432 "./marpa.w"
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

/*:953*/
#line 10478 "./marpa.w"

return ID_of_RULE(RULE_of_OR(or_node));
}

/*:956*//*957:*/
#line 10482 "./marpa.w"

gint marpa_b_or_node_position(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10486 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10487 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10488 "./marpa.w"

/*953:*/
#line 10432 "./marpa.w"
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

/*:953*/
#line 10489 "./marpa.w"

return Position_of_OR(or_node);
}

/*:957*//*958:*/
#line 10493 "./marpa.w"

gint marpa_b_or_node_first_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10497 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10498 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10499 "./marpa.w"

/*953:*/
#line 10432 "./marpa.w"
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

/*:953*/
#line 10500 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:958*//*959:*/
#line 10504 "./marpa.w"

gint marpa_b_or_node_last_and(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10508 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10509 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10510 "./marpa.w"

/*953:*/
#line 10432 "./marpa.w"
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

/*:953*/
#line 10511 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:959*//*960:*/
#line 10516 "./marpa.w"

gint marpa_b_or_node_and_count(Marpa_Bocage b,int or_node_id)
{
OR or_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10520 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10521 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10522 "./marpa.w"

/*953:*/
#line 10432 "./marpa.w"
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

/*:953*/
#line 10523 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:960*//*967:*/
#line 10564 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1149:*/
#line 12823 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1149*/
#line 10567 "./marpa.w"

/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10568 "./marpa.w"

ORDER o;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10570 "./marpa.w"

o= g_slice_new(struct s_order);
B_of_O(o)= b;
bocage_ref(b);
/*964:*/
#line 10552 "./marpa.w"

{
o->t_and_node_in_use= NULL;
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
}

/*:964*//*970:*/
#line 10580 "./marpa.w"

o->t_ref_count= 1;

/*:970*/
#line 10574 "./marpa.w"

return o;
}

/*:967*//*971:*/
#line 10584 "./marpa.w"

PRIVATE void
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

/*:971*//*972:*/
#line 10603 "./marpa.w"

PRIVATE ORDER
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

/*:972*//*973:*/
#line 10618 "./marpa.w"

PRIVATE void order_strip(ORDER o)
{
if(o->t_and_node_in_use)
{
bv_free(o->t_and_node_in_use);
o->t_and_node_in_use= NULL;
}
}
/*:973*//*974:*/
#line 10627 "./marpa.w"

PRIVATE void order_freeze(ORDER o)
{
order_strip(o);
O_is_Frozen(o)= 0;
}
/*:974*//*975:*/
#line 10633 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
MARPA_DEBUG4("%s %s: Destroying %p",G_STRFUNC,G_STRLOC,o)
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10637 "./marpa.w"

bocage_unref(b);
order_strip(o);
if(o->t_and_node_orderings){
o->t_and_node_orderings= NULL;
obstack_free(&OBS_of_O(o),NULL);
}
g_slice_free(struct s_order,o);
}

/*:975*//*978:*/
#line 10663 "./marpa.w"

Marpa_Grammar marpa_o_g(Marpa_Order o)
{
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10666 "./marpa.w"

return g;
}

/*:978*//*982:*/
#line 10719 "./marpa.w"

gint marpa_o_and_order_set(
Marpa_Order o,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length)
{
OR or_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10727 "./marpa.w"

/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10728 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10729 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*953:*/
#line 10432 "./marpa.w"
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

/*:953*/
#line 10735 "./marpa.w"

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

/*:982*//*983:*/
#line 10799 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,gint ix)
{
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10802 "./marpa.w"

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

/*:983*//*984:*/
#line 10824 "./marpa.w"

Marpa_And_Node_ID marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,gint ix)
{
OR or_node;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 10829 "./marpa.w"

/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10830 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10831 "./marpa.w"

/*953:*/
#line 10432 "./marpa.w"
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

/*:953*/
#line 10832 "./marpa.w"

if(ix<0){
MARPA_DEV_ERROR("negative and ix");
return failure_indicator;
}
return and_order_get(o,or_node,ix);
}

/*:984*//*989:*/
#line 10885 "./marpa.w"

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

/*:989*//*990:*/
#line 10904 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1149:*/
#line 12823 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1149*/
#line 10907 "./marpa.w"

TREE t;
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10909 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 10910 "./marpa.w"

t= g_slice_new(struct s_tree);
O_of_T(t)= o;
order_ref(o);
order_freeze(o);
/*991:*/
#line 10919 "./marpa.w"

{
const gint and_count= AND_Count_of_B(b);
t->t_parse_count= 0;
t->t_and_node_in_use= bv_create((guint)and_count);
FSTACK_INIT(t->t_nook_stack,NOOK_Object,and_count);
FSTACK_INIT(t->t_nook_worklist,gint,and_count);
}

/*:991*//*994:*/
#line 10931 "./marpa.w"

t->t_ref_count= 1;

/*:994*//*1001:*/
#line 11012 "./marpa.w"
t->t_pause_counter= 0;
/*:1001*/
#line 10915 "./marpa.w"

return t;
}

/*:990*//*995:*/
#line 10935 "./marpa.w"

PRIVATE void
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

/*:995*//*996:*/
#line 10954 "./marpa.w"

PRIVATE TREE
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

/*:996*//*997:*/
#line 10969 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
g_slice_free(struct s_tree,t);
}

/*:997*//*1002:*/
#line 11013 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1002*//*1003:*/
#line 11022 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1003*//*1005:*/
#line 11044 "./marpa.w"

Marpa_Grammar marpa_t_g(Marpa_Tree t)
{
/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11047 "./marpa.w"

return g;
}

/*:1005*//*1006:*/
#line 11051 "./marpa.w"

gint marpa_t_next(Marpa_Tree t)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11054 "./marpa.w"

gint is_first_tree_attempt= 0;
/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11056 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11057 "./marpa.w"

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
/*1011:*/
#line 11115 "./marpa.w"

{
ORID top_or_id= Top_ORID_of_B(b);
OR top_or_node= OR_of_B_by_ID(b,top_or_id);
NOOK nook;
gint choice;
choice= or_node_next_choice(o,t,top_or_node,0);


MARPA_DEBUG3("%s %s",G_STRFUNC,G_STRLOC);
if(choice<0)
goto TREE_IS_EXHAUSTED;
MARPA_DEBUG3("%s %s",G_STRFUNC,G_STRLOC);
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

/*:1011*/
#line 11070 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
}else{
/*1012:*/
#line 11142 "./marpa.w"
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

/*:1012*/
#line 11077 "./marpa.w"

}
/*1013:*/
#line 11194 "./marpa.w"
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
/*1015:*/
#line 11255 "./marpa.w"

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

/*:1015*/
#line 11236 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1013*/
#line 11079 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
return-1;

}

/*:1006*//*1008:*/
#line 11095 "./marpa.w"

PRIVATE void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1008*//*1009:*/
#line 11101 "./marpa.w"

PRIVATE void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1009*//*1010:*/
#line 11109 "./marpa.w"

PRIVATE gint tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(guint)and_node_id);
}

/*:1010*//*1014:*/
#line 11242 "./marpa.w"

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

/*:1014*//*1016:*/
#line 11273 "./marpa.w"

gint marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1016*//*1017:*/
#line 11281 "./marpa.w"

gint marpa_t_size(Marpa_Tree t)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11284 "./marpa.w"

/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11285 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11286 "./marpa.w"

if(T_is_Exhausted(t)){
return-1;
}
return Size_of_T(t);
}

/*:1017*//*1024:*/
#line 11344 "./marpa.w"

gint marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11348 "./marpa.w"

/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11349 "./marpa.w"

/*1023:*/
#line 11326 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11328 "./marpa.w"

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

/*:1023*/
#line 11350 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1024*//*1025:*/
#line 11354 "./marpa.w"

gint marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11358 "./marpa.w"

/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11359 "./marpa.w"

/*1023:*/
#line 11326 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11328 "./marpa.w"

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

/*:1023*/
#line 11360 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1025*//*1026:*/
#line 11364 "./marpa.w"

gint marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11368 "./marpa.w"

/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11369 "./marpa.w"

/*1023:*/
#line 11326 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11328 "./marpa.w"

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

/*:1023*/
#line 11370 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1026*//*1027:*/
#line 11374 "./marpa.w"

gint marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11378 "./marpa.w"

/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11379 "./marpa.w"

/*1023:*/
#line 11326 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11328 "./marpa.w"

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

/*:1023*/
#line 11380 "./marpa.w"

return NOOK_Cause_is_Ready(nook);
}

/*:1027*//*1028:*/
#line 11384 "./marpa.w"

gint marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11388 "./marpa.w"

/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11389 "./marpa.w"

/*1023:*/
#line 11326 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11328 "./marpa.w"

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

/*:1023*/
#line 11390 "./marpa.w"

return NOOK_Predecessor_is_Ready(nook);
}

/*:1028*//*1029:*/
#line 11394 "./marpa.w"

gint marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11398 "./marpa.w"

/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11399 "./marpa.w"

/*1023:*/
#line 11326 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11328 "./marpa.w"

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

/*:1023*/
#line 11400 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1029*//*1030:*/
#line 11404 "./marpa.w"

gint marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11408 "./marpa.w"

/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11409 "./marpa.w"

/*1023:*/
#line 11326 "./marpa.w"
{
NOOK base_nook;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11328 "./marpa.w"

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

/*:1023*/
#line 11410 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1030*//*1040:*/
#line 11522 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1149:*/
#line 12823 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1149*/
#line 11525 "./marpa.w"

/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11526 "./marpa.w"
;
/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11527 "./marpa.w"

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
NOOK_of_V(v)= -1;
/*1043:*/
#line 11551 "./marpa.w"

v->t_ref_count= 1;

/*:1043*/
#line 11539 "./marpa.w"

tree_pause(t);
T_of_V(v)= t;
return v;
}
MARPA_DEV_ERROR("tree is exhausted");
return NULL;
}

/*:1040*//*1044:*/
#line 11555 "./marpa.w"

PRIVATE void
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

/*:1044*//*1045:*/
#line 11574 "./marpa.w"

PRIVATE VALUE
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

/*:1045*//*1046:*/
#line 11589 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
if(DSTACK_IS_INITIALIZED(v->t_virtual_stack))
{
DSTACK_DESTROY(v->t_virtual_stack);
}
g_slice_free(struct s_value,v);
}

/*:1046*//*1048:*/
#line 11605 "./marpa.w"

Marpa_Grammar marpa_v_g(Marpa_Value v)
{
/*1047:*/
#line 11600 "./marpa.w"

TREE t= T_of_V(v);
/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11602 "./marpa.w"


/*:1047*/
#line 11608 "./marpa.w"

return g;
}

/*:1048*//*1049:*/
#line 11612 "./marpa.w"

gint marpa_v_trace(Marpa_Value v,gint flag)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11615 "./marpa.w"

/*1047:*/
#line 11600 "./marpa.w"

TREE t= T_of_V(v);
/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11602 "./marpa.w"


/*:1047*/
#line 11616 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11617 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
V_is_Trace(v)= flag;
return 1;
}

/*:1049*//*1050:*/
#line 11625 "./marpa.w"

Marpa_Nook_ID marpa_v_nook(Marpa_Value v)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11628 "./marpa.w"

/*1047:*/
#line 11600 "./marpa.w"

TREE t= T_of_V(v);
/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11602 "./marpa.w"


/*:1047*/
#line 11629 "./marpa.w"

/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11630 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1050*//*1051:*/
#line 11637 "./marpa.w"

Marpa_Nook_ID marpa_v_step(Marpa_Value v,Marpa_Step*step)
{
/*1150:*/
#line 12826 "./marpa.w"
const int failure_indicator= -2;

/*:1150*/
#line 11640 "./marpa.w"

AND and_nodes;
NOOKID nook_ix;
gint arg_0= -1;
gint arg_n= -1;
/*1047:*/
#line 11600 "./marpa.w"

TREE t= T_of_V(v);
/*988:*/
#line 10881 "./marpa.w"

ORDER o= O_of_T(t);
/*976:*/
#line 10647 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*920:*/
#line 10065 "./marpa.w"

const INPUT input= I_of_B(b);
const GRAMMAR g G_GNUC_UNUSED= G_of_I(input);

/*:920*/
#line 10649 "./marpa.w"


/*:976*/
#line 10883 "./marpa.w"
;

/*:988*/
#line 11602 "./marpa.w"


/*:1047*/
#line 11645 "./marpa.w"



/*1163:*/
#line 12894 "./marpa.w"

if(!IS_G_OK(g)){
MARPA_DEV_ERROR(g->t_error_string);
return failure_indicator;
}

/*:1163*/
#line 11648 "./marpa.w"

if(!V_is_Active(v)){
return failure_indicator;
}

and_nodes= ANDs_of_B(B_of_O(o));

arg_0= arg_n= TOS_of_V(v);
nook_ix= NOOK_of_V(v);
if(nook_ix<0){
nook_ix= Size_of_TREE(t);
}

while(nook_ix>=1){
OR or;
RULE nook_rule;
gint semantic_rule_id= -1;
gint token_id= -1;
gpointer token_value= NULL;
nook_ix--;
{
ANDID and_node_id;
AND and_node;
const NOOK nook= NOOK_of_TREE_by_IX(t,nook_ix);
const gint choice= Choice_of_NOOK(nook);
or= OR_of_NOOK(nook);
and_node_id= and_order_get(o,or,choice);
and_node= and_nodes+and_node_id;
token_id= and_node_token(and_node,&token_value);
}
if(token_id>=0){
arg_0= ++arg_n;
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
goto RETURN_VALUE_IF_APPROPRIATE;
}
if(virtual_rhs){
real_symbol_count= Real_SYM_Count_of_RULE(nook_rule);
real_symbol_count+= *DSTACK_POP(*virtual_stack,gint);
}else{
real_symbol_count= Length_of_RULE(nook_rule);
}
arg_0= arg_n-real_symbol_count+1;
semantic_rule_id= 
nook_rule->t_is_semantic_equivalent?
nook_rule->t_original:ID_of_RULE(nook_rule);
}
if(semantic_rule_id>=0
&&!RULE_is_Ask_Me(RULE_by_ID(g,semantic_rule_id))){
semantic_rule_id= -1;
arg_n= arg_0;
}
RETURN_VALUE_IF_APPROPRIATE:;
if(semantic_rule_id>=0||token_id>=0||V_is_Trace(v)){
/*1052:*/
#line 11724 "./marpa.w"

{
SYMID_of_STEP(step)= token_id;
Value_of_STEP(step)= token_value;
RULEID_of_STEP(step)= semantic_rule_id;
TOS_of_V(v)= Arg0_of_STEP(step)= arg_0;
NOOK_of_V(v)= nook_ix;
ArgN_of_STEP(step)= arg_n;
}

/*:1052*/
#line 11714 "./marpa.w"

return NOOK_of_V(v);
}
}

V_is_Active(v)= 0;
return-1;

}

/*:1051*//*1055:*/
#line 11758 "./marpa.w"

PRIVATE guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1055*//*1056:*/
#line 11764 "./marpa.w"

PRIVATE guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}

/*:1056*//*1058:*/
#line 11778 "./marpa.w"

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

/*:1058*//*1060:*/
#line 11796 "./marpa.w"

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


/*:1060*//*1061:*/
#line 11817 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}

/*:1061*//*1062:*/
#line 11827 "./marpa.w"

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

/*:1062*//*1063:*/
#line 11845 "./marpa.w"

PRIVATE
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}

/*:1063*//*1064:*/
#line 11853 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
vector-= bv_hiddenwords;
g_free(vector);
}

/*:1064*//*1065:*/
#line 11861 "./marpa.w"

PRIVATE gint bv_bytes(Bit_Vector bv)
{
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}

/*:1065*//*1066:*/
#line 11868 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1066*//*1067:*/
#line 11879 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1067*//*1069:*/
#line 11893 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,guint bit)
{
guint length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1069*//*1071:*/
#line 11901 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,guint bit)
{
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1071*//*1072:*/
#line 11908 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,guint bit)
{
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1072*//*1073:*/
#line 11915 "./marpa.w"

PRIVATE gint bv_bit_test(Bit_Vector vector,guint bit)
{
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1073*//*1074:*/
#line 11923 "./marpa.w"

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

/*:1074*//*1075:*/
#line 11936 "./marpa.w"

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

/*:1075*//*1076:*/
#line 11950 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1076*//*1077:*/
#line 11960 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1077*//*1078:*/
#line 11970 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1078*//*1079:*/
#line 11980 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1079*//*1080:*/
#line 11990 "./marpa.w"

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

/*:1080*//*1081:*/
#line 12062 "./marpa.w"

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

/*:1081*//*1086:*/
#line 12114 "./marpa.w"

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

/*:1086*//*1090:*/
#line 12191 "./marpa.w"

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

/*:1090*//*1091:*/
#line 12209 "./marpa.w"

PRIVATE void matrix_free(Bit_Matrix matrix)
{
g_free(matrix);
}

/*:1091*//*1092:*/
#line 12221 "./marpa.w"

PRIVATE gint matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}

/*:1092*//*1093:*/
#line 12237 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,guint row)
{
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}

/*:1093*//*1095:*/
#line 12246 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,guint row,guint column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1095*//*1097:*/
#line 12254 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1097*//*1099:*/
#line 12262 "./marpa.w"

PRIVATE gint matrix_bit_test(Bit_Matrix matrix,guint row,guint column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1099*//*1100:*/
#line 12275 "./marpa.w"

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

/*:1100*//*1109:*/
#line 12417 "./marpa.w"

PRIVATE gpointer dstack_resize(struct s_dstack*this,gsize type_bytes)
{
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}

/*:1109*//*1124:*/
#line 12556 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,gint length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1124*//*1125:*/
#line 12563 "./marpa.w"

PRIVATE void psar_destroy(const PSAR psar)
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
/*:1125*//*1126:*/
#line 12580 "./marpa.w"

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
/*:1126*//*1129:*/
#line 12611 "./marpa.w"

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

/*:1129*//*1131:*/
#line 12629 "./marpa.w"

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

/*:1131*//*1133:*/
#line 12649 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1133*//*1135:*/
#line 12673 "./marpa.w"

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

/*:1135*//*1168:*/
#line 12950 "./marpa.w"

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

/*:1168*/
#line 13237 "./marpa.w"


/*:1186*/
