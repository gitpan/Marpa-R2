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
  { 1, "MARPA_ERR_UNKNOWN", "Unknown error." },
  { 2, "MARPA_ERR_INTERNAL", "Internal error." },
  { 3, "MARPA_ERR_DEVELOPMENT", "Development error, see string." },
  { 4, "MARPA_ERR_COUNTED_NULLABLE", "Nullable symbol on RHS of a sequence rule." },
  { 5, "MARPA_ERR_DUPLICATE_RULE", "Duplicate rule." },
  { 6, "MARPA_ERR_EIM_COUNT", "Maximum number of earley items exceeded." },
  { 7, "MARPA_ERR_LHS_IS_TERMINAL", "There is a LHS terminal in a grammar which has disallowed them." },
  { 8, "MARPA_ERR_NO_PARSE", "No parse." },
  { 9, "MARPA_ERR_NO_RULES", "This grammar does not have any rules." },
  { 10, "MARPA_ERR_NO_START_SYMBOL", "This grammar has no start symbol." },
  { 11, "MARPA_ERR_NULL_RULE_UNMARKED_TERMINALS", "A grammar with null rules must mark its terminals." },
  { 12, "MARPA_ERR_ORDER_FROZEN", "Unknown error" },
  { 13, "MARPA_ERR_PRECOMPUTED", "This grammar is precomputed." },
  { 14, "MARPA_ERR_START_NOT_LHS", "Start symbol not on LHS of any rule." },
  { 15, "MARPA_ERR_SYMBOL_NOT_NULLABLE", "Symbol not nullable." },
  { 16, "MARPA_ERR_UNPRODUCTIVE_START", "Unproductive start symbol." },
};
const struct s_marpa_event_description marpa_event_description[] = {
  { 0, "MARPA_EVENT_NONE", "No error." },
  { 1, "MARPA_EVENT_EXHAUSTED", "Recognizer is exhausted." },
  { 2, "MARPA_EVENT_EARLEY_ITEM_THRESHOLD", "Too many Earley items." },
  { 3, "MARPA_EVENT_LOOP_RULES", "A rule is part of a infinite loop." },
  { 4, "MARPA_EVENT_NEW_SYMBOL", "New symbol." },
  { 5, "MARPA_EVENT_NEW_RULE", "New rule." },
  { 6, "MARPA_EVENT_COUNTED_NULLABLE", "Grammar has a counted nullable." },
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
