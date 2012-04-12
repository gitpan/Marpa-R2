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
 * This file is written by texi2proto.pl
 * It is not intended to be modified directly
 */

/*
 * This file is not part compiled into libmarpa
 * It exists for use by the higher levels,
 * which can either compile it as a C file,
 * or read it a a text file.
 */

/*
 * This is not a complete C file.
 * In particular, it lacks definitions of its structures.
 * To compile this code, you must include it in a larger file.
 * Applications may prefer to read it as a text file.
 */;

const struct s_marpa_error_description marpa_error_description[] = {
  { 0, "MARPA_ERR_NONE", "No error." },
  { 1, "MARPA_ERR_AHFA_IX_NEGATIVE", "MARPA_ERR_AHFA_IX_NEGATIVE" },
  { 2, "MARPA_ERR_AHFA_IX_OOB", "MARPA_ERR_AHFA_IX_OOB" },
  { 3, "MARPA_ERR_ANDID_NEGATIVE", "MARPA_ERR_ANDID_NEGATIVE" },
  { 4, "MARPA_ERR_ANDID_NOT_IN_OR", "MARPA_ERR_ANDID_NOT_IN_OR" },
  { 5, "MARPA_ERR_ANDIX_NEGATIVE", "MARPA_ERR_ANDIX_NEGATIVE" },
  { 6, "MARPA_ERR_BAD_SEPARATOR", "MARPA_ERR_BAD_SEPARATOR" },
  { 7, "MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED", "MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED" },
  { 8, "MARPA_ERR_COUNTED_NULLABLE", "Nullable symbol on RHS of a sequence rule." },
  { 9, "MARPA_ERR_DEVELOPMENT", "Development error, see string." },
  { 10, "MARPA_ERR_DUPLICATE_AND_NODE", "MARPA_ERR_DUPLICATE_AND_NODE" },
  { 11, "MARPA_ERR_DUPLICATE_RULE", "Duplicate rule." },
  { 12, "MARPA_ERR_EIM_COUNT", "Maximum number of earley items exceeded." },
  { 13, "MARPA_ERR_EIM_ID_INVALID", "MARPA_ERR_EIM_ID_INVALID" },
  { 14, "MARPA_ERR_INTERNAL", "Internal error." },
  { 15, "MARPA_ERR_INTERNAL_SYM", "Symbol is internal." },
  { 16, "MARPA_ERR_INVALID_AHFA_ID", "MARPA_ERR_INVALID_AHFA_ID" },
  { 17, "MARPA_ERR_INVALID_AIMID", "MARPA_ERR_INVALID_AIMID" },
  { 18, "MARPA_ERR_INVALID_BOOLEAN", "Argument is not boolean." },
  { 19, "MARPA_ERR_INVALID_ES_ORDINAL", "MARPA_ERR_INVALID_ES_ORDINAL" },
  { 20, "MARPA_ERR_INVALID_RULEID", "MARPA_ERR_INVALID_RULEID" },
  { 21, "MARPA_ERR_INVALID_START_SYM", "MARPA_ERR_INVALID_START_SYM" },
  { 22, "MARPA_ERR_INVALID_SYMID", "MARPA_ERR_INVALID_SYMID" },
  { 23, "MARPA_ERR_NOOKID_NEGATIVE", "MARPA_ERR_NOOKID_NEGATIVE" },
  { 24, "MARPA_ERR_NOT_PRECOMPUTED", "MARPA_ERR_NOT_PRECOMPUTED" },
  { 25, "MARPA_ERR_NOT_TRACING_COMPLETION_LINKS", "MARPA_ERR_NOT_TRACING_COMPLETION_LINKS" },
  { 26, "MARPA_ERR_NOT_TRACING_LEO_LINKS", "MARPA_ERR_NOT_TRACING_LEO_LINKS" },
  { 27, "MARPA_ERR_NOT_TRACING_TOKEN_LINKS", "MARPA_ERR_NOT_TRACING_TOKEN_LINKS" },
  { 28, "MARPA_ERR_NO_ALIAS", "MARPA_ERR_NO_ALIAS" },
  { 29, "MARPA_ERR_NO_AND_NODES", "MARPA_ERR_NO_AND_NODES" },
  { 30, "MARPA_ERR_NO_OR_NODES", "MARPA_ERR_NO_OR_NODES" },
  { 31, "MARPA_ERR_NO_PARSE", "No parse." },
  { 32, "MARPA_ERR_NO_RULES", "This grammar does not have any rules." },
  { 33, "MARPA_ERR_NO_START_SYM", "This grammar has no start symbol." },
  { 34, "MARPA_ERR_NO_TRACE_ES", "MARPA_ERR_NO_TRACE_ES" },
  { 35, "MARPA_ERR_NO_TRACE_PIM", "MARPA_ERR_NO_TRACE_PIM" },
  { 36, "MARPA_ERR_NO_TRACE_EIM", "MARPA_ERR_NO_TRACE_EIM" },
  { 37, "MARPA_ERR_NO_TRACE_SRCL", "MARPA_ERR_NO_TRACE_SRCL" },
  { 38, "MARPA_ERR_NULLING_TERMINAL", "A symbol is both terminal and nulling." },
  { 39, "MARPA_ERR_ORID_NEGATIVE", "MARPA_ERR_ORID_NEGATIVE" },
  { 40, "MARPA_ERR_OR_ALREADY_ORDERED", "MARPA_ERR_OR_ALREADY_ORDERED" },
  { 41, "MARPA_ERR_ORDER_FROZEN", "MARPA_ERR_ORDER_FROZEN" },
  { 42, "MARPA_ERR_PARSE_EXHAUSTED", "MARPA_ERR_PARSE_EXHAUSTED" },
  { 43, "MARPA_ERR_PARSE_TOO_LONG", "MARPA_ERR_PARSE_TOO_LONG" },
  { 44, "MARPA_ERR_PIM_IS_NOT_LIM", "MARPA_ERR_PIM_IS_NOT_LIM" },
  { 45, "MARPA_ERR_PRECOMPUTED", "This grammar is precomputed." },
  { 46, "MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT", "MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT" },
  { 47, "MARPA_ERR_RECCE_NOT_STARTED", "MARPA_ERR_RECCE_NOT_STARTED" },
  { 48, "MARPA_ERR_RECCE_STARTED", "MARPA_ERR_RECCE_STARTED" },
  { 49, "MARPA_ERR_RHS_TOO_LONG", "MARPA_ERR_RHS_TOO_LONG" },
  { 50, "MARPA_ERR_SOURCE_TYPE_IS_NONE", "A source type of 'none' is not allowed here." },
  { 51, "MARPA_ERR_SOURCE_TYPE_IS_TOKEN", "Token source type is not allowed here." },
  { 52, "MARPA_ERR_SOURCE_TYPE_IS_COMPLETION", "Completion source type is not allowed here." },
  { 53, "MARPA_ERR_SOURCE_TYPE_IS_LEO", "Leo source type is not allowed here." },
  { 54, "MARPA_ERR_SOURCE_TYPE_IS_AMBIGUOUS", "Ambiguous source type is not allowed here." },
  { 55, "MARPA_ERR_SOURCE_TYPE_IS_UNKNOWN", "The source type is unknown." },
  { 56, "MARPA_ERR_START_NOT_LHS", "Start symbol not on LHS of any rule." },
  { 57, "MARPA_ERR_SYMIX_NEGATIVE", "MARPA_ERR_SYMIX_NEGATIVE" },
  { 58, "MARPA_ERR_SYMIX_OOB", "MARPA_ERR_SYMIX_OOB" },
  { 59, "MARPA_ERR_SYM_NOT_NULLABLE", "Symbol not nullable." },
  { 60, "MARPA_ERR_TOKEN_IS_NOT_TERMINAL", "MARPA_ERR_TOKEN_IS_NOT_TERMINAL" },
  { 61, "MARPA_ERR_TOKEN_LENGTH_LE_ZERO", "MARPA_ERR_TOKEN_LENGTH_LE_ZERO" },
  { 62, "MARPA_ERR_TOKEN_TOO_LONG", "MARPA_ERR_TOKEN_TOO_LONG" },
  { 63, "MARPA_ERR_TREE_EXHAUSTED", "MARPA_ERR_TREE_EXHAUSTED" },
  { 64, "MARPA_ERR_TREE_PAUSED", "MARPA_ERR_TREE_PAUSED" },
  { 65, "MARPA_ERR_UNKNOWN", "Unknown error." },
  { 66, "MARPA_ERR_UNPRODUCTIVE_START", "Unproductive start symbol." },
};
const struct s_marpa_event_description marpa_event_description[] = {
  { 0, "MARPA_EVENT_NONE", "No event." },
  { 1, "MARPA_EVENT_EXHAUSTED", "Recognizer is exhausted." },
  { 2, "MARPA_EVENT_EARLEY_ITEM_THRESHOLD", "Too many Earley items." },
  { 3, "MARPA_EVENT_LOOP_RULES", "A rule is part of a infinite loop." },
  { 4, "MARPA_EVENT_COUNTED_NULLABLE", "Grammar has a counted nullable." },
  { 5, "MARPA_EVENT_NULLING_TERMINAL", "Grammar has a nulling terminal." },
};
const struct s_marpa_value_type_description marpa_value_type_description[] = {
  { 0, "MARPA_VALUE_INTERNAL1" },
  { 1, "MARPA_VALUE_RULE" },
  { 2, "MARPA_VALUE_TOKEN" },
  { 3, "MARPA_VALUE_NULLING_TOKEN" },
  { 4, "MARPA_VALUE_TRACE" },
  { 5, "MARPA_VALUE_INACTIVE" },
  { 6, "MARPA_VALUE_INTERNAL2" },
};
