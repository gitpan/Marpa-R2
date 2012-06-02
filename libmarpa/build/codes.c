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
  { 15, "MARPA_ERR_INVALID_AHFA_ID", "MARPA_ERR_INVALID_AHFA_ID" },
  { 16, "MARPA_ERR_INVALID_AIMID", "MARPA_ERR_INVALID_AIMID" },
  { 17, "MARPA_ERR_INVALID_BOOLEAN", "Argument is not boolean." },
  { 18, "MARPA_ERR_INVALID_ES_ORDINAL", "MARPA_ERR_INVALID_ES_ORDINAL" },
  { 19, "MARPA_ERR_INVALID_IRLID", "No IRL with that ID exists." },
  { 20, "MARPA_ERR_INVALID_ISYID", "No ISY with that ID exists." },
  { 21, "MARPA_ERR_INVALID_START_SYM", "MARPA_ERR_INVALID_START_SYM" },
  { 22, "MARPA_ERR_INVALID_SYMID", "MARPA_ERR_INVALID_SYMID" },
  { 23, "MARPA_ERR_INVALID_XRLID", "No rule with that ID exists." },
  { 24, "MARPA_ERR_INVALID_XSYID", "No symbol with that ID exists." },
  { 25, "MARPA_ERR_NOOKID_NEGATIVE", "MARPA_ERR_NOOKID_NEGATIVE" },
  { 26, "MARPA_ERR_MAJOR_VERSION_MISMATCH", "MARPA_ERR_MAJOR_VERSION_MISMATCH" },
  { 27, "MARPA_ERR_MICRO_VERSION_MISMATCH", "MARPA_ERR_MICRO_VERSION_MISMATCH" },
  { 28, "MARPA_ERR_MINOR_VERSION_MISMATCH", "MARPA_ERR_MINOR_VERSION_MISMATCH" },
  { 29, "MARPA_ERR_NOT_PRECOMPUTED", "MARPA_ERR_NOT_PRECOMPUTED" },
  { 30, "MARPA_ERR_NOT_TRACING_COMPLETION_LINKS", "MARPA_ERR_NOT_TRACING_COMPLETION_LINKS" },
  { 31, "MARPA_ERR_NOT_TRACING_LEO_LINKS", "MARPA_ERR_NOT_TRACING_LEO_LINKS" },
  { 32, "MARPA_ERR_NOT_TRACING_TOKEN_LINKS", "MARPA_ERR_NOT_TRACING_TOKEN_LINKS" },
  { 33, "MARPA_ERR_NO_AND_NODES", "MARPA_ERR_NO_AND_NODES" },
  { 34, "MARPA_ERR_NO_OR_NODES", "MARPA_ERR_NO_OR_NODES" },
  { 35, "MARPA_ERR_NO_PARSE", "No parse." },
  { 36, "MARPA_ERR_NO_RULES", "This grammar does not have any rules." },
  { 37, "MARPA_ERR_NO_START_SYM", "This grammar has no start symbol." },
  { 38, "MARPA_ERR_NO_TRACE_EIM", "MARPA_ERR_NO_TRACE_EIM" },
  { 39, "MARPA_ERR_NO_TRACE_ES", "MARPA_ERR_NO_TRACE_ES" },
  { 40, "MARPA_ERR_NO_TRACE_PIM", "MARPA_ERR_NO_TRACE_PIM" },
  { 41, "MARPA_ERR_NO_TRACE_SRCL", "MARPA_ERR_NO_TRACE_SRCL" },
  { 42, "MARPA_ERR_NULLING_TERMINAL", "A symbol is both terminal and nulling." },
  { 43, "MARPA_ERR_ORDER_FROZEN", "MARPA_ERR_ORDER_FROZEN" },
  { 44, "MARPA_ERR_ORID_NEGATIVE", "MARPA_ERR_ORID_NEGATIVE" },
  { 45, "MARPA_ERR_OR_ALREADY_ORDERED", "MARPA_ERR_OR_ALREADY_ORDERED" },
  { 46, "MARPA_ERR_PARSE_EXHAUSTED", "MARPA_ERR_PARSE_EXHAUSTED" },
  { 47, "MARPA_ERR_PARSE_TOO_LONG", "MARPA_ERR_PARSE_TOO_LONG" },
  { 48, "MARPA_ERR_PIM_IS_NOT_LIM", "MARPA_ERR_PIM_IS_NOT_LIM" },
  { 49, "MARPA_ERR_POINTER_ARG_NULL", "An argument is null when it should not be." },
  { 50, "MARPA_ERR_PRECOMPUTED", "This grammar is precomputed." },
  { 51, "MARPA_ERR_PROGRESS_REPORT_NOT_STARTED", "No progress report has been started." },
  { 52, "MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT", "MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT" },
  { 53, "MARPA_ERR_RECCE_NOT_STARTED", "MARPA_ERR_RECCE_NOT_STARTED" },
  { 54, "MARPA_ERR_RECCE_STARTED", "MARPA_ERR_RECCE_STARTED" },
  { 55, "MARPA_ERR_RHS_TOO_LONG", "MARPA_ERR_RHS_TOO_LONG" },
  { 56, "MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE", "LHS of sequence rule would not be unique." },
  { 57, "MARPA_ERR_SOURCE_TYPE_IS_NONE", "A source type of 'none' is not allowed here." },
  { 58, "MARPA_ERR_SOURCE_TYPE_IS_TOKEN", "Token source type is not allowed here." },
  { 59, "MARPA_ERR_SOURCE_TYPE_IS_COMPLETION", "Completion source type is not allowed here." },
  { 60, "MARPA_ERR_SOURCE_TYPE_IS_LEO", "Leo source type is not allowed here." },
  { 61, "MARPA_ERR_SOURCE_TYPE_IS_AMBIGUOUS", "Ambiguous source type is not allowed here." },
  { 62, "MARPA_ERR_SOURCE_TYPE_IS_UNKNOWN", "The source type is unknown." },
  { 63, "MARPA_ERR_START_NOT_LHS", "Start symbol not on LHS of any rule." },
  { 64, "MARPA_ERR_SYM_NOT_NULLABLE", "Symbol not nullable." },
  { 65, "MARPA_ERR_TOKEN_IS_NOT_TERMINAL", "MARPA_ERR_TOKEN_IS_NOT_TERMINAL" },
  { 66, "MARPA_ERR_TOKEN_LENGTH_LE_ZERO", "MARPA_ERR_TOKEN_LENGTH_LE_ZERO" },
  { 67, "MARPA_ERR_TOKEN_TOO_LONG", "MARPA_ERR_TOKEN_TOO_LONG" },
  { 68, "MARPA_ERR_TREE_EXHAUSTED", "MARPA_ERR_TREE_EXHAUSTED" },
  { 69, "MARPA_ERR_TREE_PAUSED", "MARPA_ERR_TREE_PAUSED" },
  { 70, "MARPA_ERR_UNKNOWN", "Unknown error." },
  { 71, "MARPA_ERR_UNPRODUCTIVE_START", "Unproductive start symbol." },
  { 72, "MARPA_ERR_VALUATOR_INACTIVE", "Valuator inactive." },
};
const struct s_marpa_event_description marpa_event_description[] = {
  { 0, "MARPA_EVENT_NONE", "No event." },
  { 1, "MARPA_EVENT_EXHAUSTED", "Recognizer is exhausted." },
  { 2, "MARPA_EVENT_EARLEY_ITEM_THRESHOLD", "Too many Earley items." },
  { 3, "MARPA_EVENT_LOOP_RULES", "A rule is part of a infinite loop." },
  { 4, "MARPA_EVENT_COUNTED_NULLABLE", "Grammar has a counted nullable." },
  { 5, "MARPA_EVENT_NULLING_TERMINAL", "Grammar has a nulling terminal." },
};
const struct s_marpa_step_type_description marpa_step_type_description[] = {
  { 0, "MARPA_STEP_INTERNAL1" },
  { 1, "MARPA_STEP_RULE" },
  { 2, "MARPA_STEP_TOKEN" },
  { 3, "MARPA_STEP_NULLING_SYMBOL" },
  { 4, "MARPA_STEP_TRACE" },
  { 5, "MARPA_STEP_INACTIVE" },
  { 6, "MARPA_STEP_INTERNAL2" },
};
