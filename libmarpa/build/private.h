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
 * This file is written by w2private_h.pl
 * It is not intended to be modified directly
 */


static RULE rule_start(GRAMMAR g,
SYMID lhs, SYMID *rhs, int length);
static int cmp_by_aimid (const void* ap,
	const void* bp);
static int cmp_by_postdot_and_aimid (const void* ap,
	const void* bp);
static int AHFA_state_cmp(
    const void* ap,
    const void* bp,
    void *param UNUSED);
static void create_AHFA_states(struct marpa_g* g);
static int
cmp_by_rule_sort_key(const void* ap, const void* bp);
static AHFA
create_predicted_AHFA_state(
     GRAMMAR g,
     Bit_Vector prediction_rule_vector,
     RULE* rule_by_sort_key,
     DQUEUE states_p,
     struct avl_table* duplicates
     );
static Marpa_Error_Code invalid_source_type_code(unsigned int type);
static void earley_item_ambiguate (struct marpa_r * r, EIM item);
static void
postdot_items_create (RECCE r, ES current_earley_set);
static BOCAGE r_create_null_bocage(RECCE r, BOCAGE b);
static void
rhs_closure (GRAMMAR g, Bit_Vector bv);
static void transitive_closure(Bit_Matrix matrix);
static void
default_out_of_memory(void);
static void
set_error (struct marpa_g *g, Marpa_Error_Code code, const char* message, unsigned int flags);
static int marpa_default_debug_handler (const char *format, ...);
static inline const char* check_alpha_version(
    unsigned int required_major,
		unsigned int required_minor,
		unsigned int required_micro);
static inline void
grammar_unref (GRAMMAR g);
static inline GRAMMAR
grammar_ref (GRAMMAR g);
static inline void grammar_free(GRAMMAR g);
static inline void symbol_add( GRAMMAR g, SYM symbol);
static inline int symbol_is_valid(GRAMMAR g, SYMID symid);
static inline void rule_add(
    GRAMMAR g,
    RULE rule);
static inline void event_new(struct marpa_g* g, int type);
static inline void int_event_new(struct marpa_g* g, int type, int value);
static inline SYM
symbol_new (struct marpa_g *g);
static inline void symbol_free(SYM symbol);
static inline void symbol_lhs_add(SYM symbol, RULEID rule_id);
static inline void symbol_rhs_add(SYM symbol, RULEID rule_id);
static inline SYM symbol_proper_alias(SYM symbol);
static inline SYM symbol_null_alias(SYM symbol);
static inline SYM symbol_alias_create(GRAMMAR g, SYM symbol);
static inline int is_rule_duplicate(GRAMMAR g,
SYMID lhs_id, SYMID* rhs_ids, int length);
static inline int rule_check(GRAMMAR g,
SYMID lhs, SYMID *rhs, int length);
static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
static inline Marpa_Symbol_ID* rule_rhs_get(RULE rule);
static inline size_t rule_length_get(RULE rule);
static inline int rule_is_accessible(struct marpa_g* g, RULE  rule);
static inline int rule_is_productive(struct marpa_g* g, RULE  rule);
static inline int
rule_is_nulling (GRAMMAR g, RULE rule);
static inline int
symbol_instance_of_ahfa_item_get (AIM aim);
static inline GRAMMAR census(GRAMMAR g);
static inline struct marpa_g* CHAF_rewrite(struct marpa_g* g);
static inline SYMID alias_by_id(GRAMMAR g, SYMID proper_id);
static inline GRAMMAR g_augment(GRAMMAR g);
static inline void loop_detect(struct marpa_g* g);
static inline int aim_is_valid(
GRAMMAR g, AIMID item_id);
static inline void create_AHFA_items(GRAMMAR g);
static inline void AHFA_initialize(AHFA ahfa);
static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa, AIM sought_aim);
static inline int AHFA_state_id_is_valid(GRAMMAR g, AHFAID AHFA_state_id);
static inline AHFA
assign_AHFA_state (AHFA sought_state, struct avl_table* duplicates);
static inline AHFA to_ahfa_of_transition_get(TRANS transition);
static inline int completion_count_of_transition_get(TRANS transition);
static inline URTRANS transition_new(struct obstack *obstack, AHFA to_ahfa, int aim_ix);
static inline TRANS* transitions_new(GRAMMAR g);
static inline void transition_add(struct obstack *obstack, AHFA from_ahfa, SYMID symid, AHFA to_ahfa);
static inline void completion_count_inc(struct obstack *obstack, AHFA from_ahfa, SYMID symid);
static inline INPUT
input_new (GRAMMAR g);
static inline void
input_unref (INPUT input);
static inline INPUT
input_ref (INPUT input);
static inline void input_free(INPUT input);
static inline void
recce_unref (RECCE r);
static inline RECCE recce_ref (RECCE r);
static inline void recce_free(struct marpa_r *r);
static inline ES current_es_of_r(RECCE r);
static inline ES
earley_set_new( RECCE r, EARLEME id);
static inline EIM earley_item_create(const RECCE r,
    const EIK_Object key);
static inline EIM
earley_item_assign (const RECCE r, const ES set, const ES origin,
		    const AHFA state);
static inline void trace_earley_item_clear(struct marpa_r* r);
static inline PIM*
pim_sym_p_find (ES set, SYMID symid);
static inline PIM first_pim_of_es_by_symid(ES set, SYMID symid);
static inline void
completion_link_add (RECCE r,
		EIM item,
		EIM predecessor,
		EIM cause);
static inline void
leo_link_add (RECCE r,
		EIM item,
		LIM predecessor,
		EIM cause);
static inline void trace_source_link_clear(RECCE r);
static inline TOK token_new(INPUT input, SYMID symbol_id, int value);
static inline int
alternative_insertion_point (RECCE r, ALT new_alternative);
static inline int alternative_cmp(const ALT_Const a, const ALT_Const b);
static inline ALT alternative_pop(RECCE r, EARLEME earleme);
static inline int alternative_insert(RECCE r, ALT new_alternative);
static inline void earley_set_update_items(RECCE r, ES set);
static inline void r_update_earley_sets(RECCE r);
static inline void ur_node_stack_init(URS stack);
static inline void ur_node_stack_reset(URS stack);
static inline void ur_node_stack_destroy(URS stack);
static inline UR ur_node_new(URS stack, UR prev);
static inline void
ur_node_push (URS stack, EIM earley_item, AEX aex);
static inline UR
ur_node_pop (URS stack);
static inline int psia_test_and_set(
    struct obstack* obs,
    struct s_bocage_setup_per_es* per_es_data,
    EIM earley_item,
    AEX ahfa_element_ix);
static inline AEX lim_base_data_get(LIM leo_item, EIM* p_base);
static inline AIM base_aim_of_lim(LIM leo_item);
static inline DAND draft_and_node_new(struct obstack *obs, OR predecessor, OR cause);
static inline void draft_and_node_add(struct obstack *obs, OR parent, OR predecessor, OR cause);
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
static inline void order_strip(ORDER o);
static inline void order_freeze(ORDER o);
static inline void order_free(ORDER o);
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
static inline void tree_and_node_claim(TREE tree, ANDID and_node_id);
static inline void tree_and_node_release(TREE tree, ANDID and_node_id);
static inline int tree_and_node_try(TREE tree, ANDID and_node_id);
static inline int or_node_next_choice(ORDER o, TREE tree, OR or_node, int start_choice);
static inline void
value_unref (VALUE v);
static inline VALUE
value_ref (VALUE v);
static inline void value_free(VALUE v);
static inline unsigned int bv_bits_to_size(unsigned int bits);
static inline unsigned int bv_bits_to_unused_mask(unsigned int bits);
static inline Bit_Vector bv_create(unsigned int bits);
static inline Bit_Vector
bv_obs_create (struct obstack *obs, unsigned int bits);
static inline Bit_Vector bv_shadow(Bit_Vector bv);
static inline Bit_Vector bv_copy(Bit_Vector bv_to, Bit_Vector bv_from);
static inline Bit_Vector bv_clone(Bit_Vector bv);
static inline void bv_free(Bit_Vector vector);
static inline int bv_bytes(Bit_Vector bv);
static inline void bv_fill(Bit_Vector bv);
static inline void bv_clear(Bit_Vector bv);
static inline void bv_over_clear(Bit_Vector bv, unsigned int bit);
static inline void bv_bit_set(Bit_Vector vector, unsigned int bit);
static inline void bv_bit_clear(Bit_Vector vector, unsigned int bit);
static inline int bv_bit_test(Bit_Vector vector, unsigned int bit);
static inline int
bv_bit_test_and_set (Bit_Vector vector, unsigned int bit);
static inline int bv_is_empty(Bit_Vector addr);
static inline void bv_not(Bit_Vector X, Bit_Vector Y);
static inline void bv_and(Bit_Vector X, Bit_Vector Y, Bit_Vector Z);
static inline void bv_or(Bit_Vector X, Bit_Vector Y, Bit_Vector Z);
static inline void bv_or_assign(Bit_Vector X, Bit_Vector Y);
static inline int bv_scan(Bit_Vector bv, unsigned int start,
                                    unsigned int* min, unsigned int* max);
static inline unsigned int
bv_count (Bit_Vector v);
static inline Bit_Matrix matrix_create(unsigned int rows, unsigned int columns);
static inline void matrix_free(Bit_Matrix matrix);
static inline int matrix_columns(Bit_Matrix matrix);
static inline Bit_Vector matrix_row(Bit_Matrix matrix, unsigned int row);
static inline void matrix_bit_set(Bit_Matrix matrix, unsigned int row, unsigned int column);
static inline void matrix_bit_clear(Bit_Matrix matrix, unsigned int row, unsigned int column);
static inline int matrix_bit_test(Bit_Matrix matrix, unsigned int row, unsigned int column);
static inline void * dstack_resize(struct s_dstack* this, size_t type_bytes);
static inline void
psar_init (const PSAR psar, int length);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
static inline void psar_reset(const PSAR psar);
static inline void psar_dealloc(const PSAR psar);
static inline void psl_claim(
    PSL* const psl_owner, const PSAR psar);
static inline PSL psl_alloc(const PSAR psar);
static inline void*
my_malloc(size_t size);
static inline void*
my_malloc0(size_t size);
static inline void*
my_realloc(void* mem, size_t size);
