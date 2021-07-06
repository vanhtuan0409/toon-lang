#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 50
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 40
#define ALIAS_COUNT 0
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 10
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 9

enum {
  sym_ident = 1,
  sym_comment = 2,
  anon_sym_true = 3,
  anon_sym_false = 4,
  sym_number_lit = 5,
  sym_escape_sequence = 6,
  anon_sym_DQUOTE = 7,
  aux_sym_string_lit_token1 = 8,
  anon_sym_number = 9,
  anon_sym_bool = 10,
  anon_sym_SEMI = 11,
  anon_sym_let = 12,
  anon_sym_COLON = 13,
  anon_sym_EQ = 14,
  anon_sym_LPAREN = 15,
  anon_sym_RPAREN = 16,
  anon_sym_DASH = 17,
  anon_sym_STAR = 18,
  anon_sym_SLASH = 19,
  anon_sym_PLUS = 20,
  anon_sym_COMMA = 21,
  sym_root = 22,
  sym_bool_lit = 23,
  sym_string_lit = 24,
  sym__literal = 25,
  sym_type = 26,
  sym__prime_type = 27,
  sym_statement = 28,
  sym_var_decl = 29,
  sym_assign_stm = 30,
  sym__expression = 31,
  sym_parenthesised_expression = 32,
  sym_unary_expression = 33,
  sym_binary_expression = 34,
  sym_argument_list = 35,
  sym_call_expression = 36,
  aux_sym_root_repeat1 = 37,
  aux_sym_string_lit_repeat1 = 38,
  aux_sym_argument_list_repeat1 = 39,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_ident] = "ident",
  [sym_comment] = "comment",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_number_lit] = "number_lit",
  [sym_escape_sequence] = "escape_sequence",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_lit_token1] = "string_lit_token1",
  [anon_sym_number] = "number",
  [anon_sym_bool] = "bool",
  [anon_sym_SEMI] = ";",
  [anon_sym_let] = "let",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PLUS] = "+",
  [anon_sym_COMMA] = ",",
  [sym_root] = "root",
  [sym_bool_lit] = "bool_lit",
  [sym_string_lit] = "string_lit",
  [sym__literal] = "_literal",
  [sym_type] = "type",
  [sym__prime_type] = "_prime_type",
  [sym_statement] = "statement",
  [sym_var_decl] = "var_decl",
  [sym_assign_stm] = "assign_stm",
  [sym__expression] = "_expression",
  [sym_parenthesised_expression] = "parenthesised_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym_argument_list] = "argument_list",
  [sym_call_expression] = "call_expression",
  [aux_sym_root_repeat1] = "root_repeat1",
  [aux_sym_string_lit_repeat1] = "string_lit_repeat1",
  [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_ident] = sym_ident,
  [sym_comment] = sym_comment,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_number_lit] = sym_number_lit,
  [sym_escape_sequence] = sym_escape_sequence,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_lit_token1] = aux_sym_string_lit_token1,
  [anon_sym_number] = anon_sym_number,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym_root] = sym_root,
  [sym_bool_lit] = sym_bool_lit,
  [sym_string_lit] = sym_string_lit,
  [sym__literal] = sym__literal,
  [sym_type] = sym_type,
  [sym__prime_type] = sym__prime_type,
  [sym_statement] = sym_statement,
  [sym_var_decl] = sym_var_decl,
  [sym_assign_stm] = sym_assign_stm,
  [sym__expression] = sym__expression,
  [sym_parenthesised_expression] = sym_parenthesised_expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_argument_list] = sym_argument_list,
  [sym_call_expression] = sym_call_expression,
  [aux_sym_root_repeat1] = aux_sym_root_repeat1,
  [aux_sym_string_lit_repeat1] = aux_sym_string_lit_repeat1,
  [aux_sym_argument_list_repeat1] = aux_sym_argument_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_ident] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_number_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_lit_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_number] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym_root] = {
    .visible = true,
    .named = true,
  },
  [sym_bool_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_string_lit] = {
    .visible = true,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym__prime_type] = {
    .visible = false,
    .named = true,
  },
  [sym_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_var_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_assign_stm] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_parenthesised_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_argument_list] = {
    .visible = true,
    .named = true,
  },
  [sym_call_expression] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_root_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_lit_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_argument_list_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_args = 1,
  field_func_name = 2,
  field_inner = 3,
  field_left = 4,
  field_operand = 5,
  field_operator = 6,
  field_right = 7,
  field_var_expr = 8,
  field_var_name = 9,
  field_var_type = 10,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_args] = "args",
  [field_func_name] = "func_name",
  [field_inner] = "inner",
  [field_left] = "left",
  [field_operand] = "operand",
  [field_operator] = "operator",
  [field_right] = "right",
  [field_var_expr] = "var_expr",
  [field_var_name] = "var_name",
  [field_var_type] = "var_type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 2},
  [3] = {.index = 4, .length = 1},
  [4] = {.index = 5, .length = 3},
  [5] = {.index = 8, .length = 2},
  [6] = {.index = 10, .length = 2},
  [7] = {.index = 12, .length = 2},
  [8] = {.index = 14, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_args, 1},
    {field_func_name, 0},
  [2] =
    {field_operand, 1},
    {field_operator, 0},
  [4] =
    {field_inner, 1},
  [5] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [8] =
    {field_var_expr, 2},
    {field_var_name, 0},
  [10] =
    {field_var_name, 1},
    {field_var_type, 3},
  [12] =
    {field_var_expr, 3},
    {field_var_name, 1},
  [14] =
    {field_var_expr, 5},
    {field_var_name, 1},
    {field_var_type, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(13);
      if (lookahead == '"') ADVANCE(19);
      if (lookahead == '(') ADVANCE(26);
      if (lookahead == ')') ADVANCE(27);
      if (lookahead == '*') ADVANCE(29);
      if (lookahead == '+') ADVANCE(31);
      if (lookahead == ',') ADVANCE(32);
      if (lookahead == '-') ADVANCE(28);
      if (lookahead == '.') ADVANCE(7);
      if (lookahead == '/') ADVANCE(30);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == ';') ADVANCE(23);
      if (lookahead == '=') ADVANCE(25);
      if (lookahead == '\\') ADVANCE(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '"') ADVANCE(19);
      if (lookahead == '/') ADVANCE(21);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0) ADVANCE(22);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(19);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '/') ADVANCE(15);
      END_STATE();
    case 4:
      if (lookahead == 'u') ADVANCE(5);
      if (lookahead == 'x') ADVANCE(11);
      if (lookahead != 0) ADVANCE(18);
      END_STATE();
    case 5:
      if (lookahead == '{') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(8);
      END_STATE();
    case 6:
      if (lookahead == '}') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(6);
      END_STATE();
    case 7:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 8:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 9:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(18);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(6);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(9);
      END_STATE();
    case 12:
      if (eof) ADVANCE(13);
      if (lookahead == '"') ADVANCE(19);
      if (lookahead == '(') ADVANCE(26);
      if (lookahead == ')') ADVANCE(27);
      if (lookahead == '*') ADVANCE(29);
      if (lookahead == '+') ADVANCE(31);
      if (lookahead == ',') ADVANCE(32);
      if (lookahead == '-') ADVANCE(28);
      if (lookahead == '.') ADVANCE(7);
      if (lookahead == '/') ADVANCE(30);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == ';') ADVANCE(23);
      if (lookahead == '=') ADVANCE(25);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_ident);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '.') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_number_lit);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_string_lit_token1);
      if (lookahead == '/') ADVANCE(21);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(22);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_string_lit_token1);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(22);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_string_lit_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(15);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'b') ADVANCE(1);
      if (lookahead == 'f') ADVANCE(2);
      if (lookahead == 'l') ADVANCE(3);
      if (lookahead == 'n') ADVANCE(4);
      if (lookahead == 't') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(6);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(7);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 4:
      if (lookahead == 'u') ADVANCE(9);
      END_STATE();
    case 5:
      if (lookahead == 'r') ADVANCE(10);
      END_STATE();
    case 6:
      if (lookahead == 'o') ADVANCE(11);
      END_STATE();
    case 7:
      if (lookahead == 'l') ADVANCE(12);
      END_STATE();
    case 8:
      if (lookahead == 't') ADVANCE(13);
      END_STATE();
    case 9:
      if (lookahead == 'm') ADVANCE(14);
      END_STATE();
    case 10:
      if (lookahead == 'u') ADVANCE(15);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 12:
      if (lookahead == 's') ADVANCE(17);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 14:
      if (lookahead == 'b') ADVANCE(18);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 21:
      if (lookahead == 'r') ADVANCE(22);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_number);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 1},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_ident] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_number_lit] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_number] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
  },
  [1] = {
    [sym_root] = STATE(48),
    [sym_bool_lit] = STATE(34),
    [sym_string_lit] = STATE(34),
    [sym__literal] = STATE(34),
    [sym_statement] = STATE(2),
    [sym_var_decl] = STATE(15),
    [sym_assign_stm] = STATE(15),
    [sym__expression] = STATE(34),
    [sym_parenthesised_expression] = STATE(34),
    [sym_unary_expression] = STATE(34),
    [sym_binary_expression] = STATE(34),
    [sym_call_expression] = STATE(34),
    [aux_sym_root_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_ident] = ACTIONS(7),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_number_lit] = ACTIONS(11),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_let] = ACTIONS(15),
    [anon_sym_LPAREN] = ACTIONS(17),
    [anon_sym_DASH] = ACTIONS(19),
  },
  [2] = {
    [sym_bool_lit] = STATE(34),
    [sym_string_lit] = STATE(34),
    [sym__literal] = STATE(34),
    [sym_statement] = STATE(3),
    [sym_var_decl] = STATE(15),
    [sym_assign_stm] = STATE(15),
    [sym__expression] = STATE(34),
    [sym_parenthesised_expression] = STATE(34),
    [sym_unary_expression] = STATE(34),
    [sym_binary_expression] = STATE(34),
    [sym_call_expression] = STATE(34),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_ident] = ACTIONS(7),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_number_lit] = ACTIONS(11),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_let] = ACTIONS(15),
    [anon_sym_LPAREN] = ACTIONS(17),
    [anon_sym_DASH] = ACTIONS(19),
  },
  [3] = {
    [sym_bool_lit] = STATE(34),
    [sym_string_lit] = STATE(34),
    [sym__literal] = STATE(34),
    [sym_statement] = STATE(3),
    [sym_var_decl] = STATE(15),
    [sym_assign_stm] = STATE(15),
    [sym__expression] = STATE(34),
    [sym_parenthesised_expression] = STATE(34),
    [sym_unary_expression] = STATE(34),
    [sym_binary_expression] = STATE(34),
    [sym_call_expression] = STATE(34),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym_ident] = ACTIONS(25),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(28),
    [anon_sym_false] = ACTIONS(28),
    [sym_number_lit] = ACTIONS(31),
    [anon_sym_DQUOTE] = ACTIONS(34),
    [anon_sym_let] = ACTIONS(37),
    [anon_sym_LPAREN] = ACTIONS(40),
    [anon_sym_DASH] = ACTIONS(43),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(46), 1,
      sym_ident,
    ACTIONS(48), 1,
      sym_number_lit,
    ACTIONS(50), 1,
      anon_sym_RPAREN,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(31), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [36] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(46), 1,
      sym_ident,
    ACTIONS(52), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [69] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(46), 1,
      sym_ident,
    ACTIONS(54), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(36), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [102] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(46), 1,
      sym_ident,
    ACTIONS(56), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(23), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [135] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(46), 1,
      sym_ident,
    ACTIONS(58), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(35), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [168] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(46), 1,
      sym_ident,
    ACTIONS(60), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(33), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [201] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(46), 1,
      sym_ident,
    ACTIONS(62), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(37), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [234] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(46), 1,
      sym_ident,
    ACTIONS(64), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(38), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [267] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(46), 1,
      sym_ident,
    ACTIONS(66), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(30), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [300] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(70), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(68), 5,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [317] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(74), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(72), 5,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [334] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(78), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(76), 5,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [351] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(82), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(80), 5,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [368] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(86), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(84), 5,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [385] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      anon_sym_LPAREN,
    ACTIONS(92), 1,
      anon_sym_SLASH,
    STATE(24), 1,
      sym_argument_list,
    ACTIONS(88), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [406] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(96), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(94), 5,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [423] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      anon_sym_LPAREN,
    ACTIONS(92), 1,
      anon_sym_SLASH,
    ACTIONS(98), 1,
      anon_sym_EQ,
    STATE(24), 1,
      sym_argument_list,
    ACTIONS(88), 4,
      anon_sym_SEMI,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
  [445] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(102), 1,
      anon_sym_SLASH,
    ACTIONS(100), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [460] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(106), 1,
      anon_sym_SLASH,
    ACTIONS(104), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [475] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(110), 1,
      anon_sym_SLASH,
    ACTIONS(108), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [490] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(114), 1,
      anon_sym_SLASH,
    ACTIONS(112), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [505] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(118), 1,
      anon_sym_SLASH,
    ACTIONS(116), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [520] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(122), 1,
      anon_sym_SLASH,
    ACTIONS(120), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [535] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(126), 1,
      anon_sym_SLASH,
    ACTIONS(124), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [550] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(130), 1,
      anon_sym_SLASH,
    ACTIONS(128), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [565] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_SLASH,
    ACTIONS(132), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [580] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(138), 1,
      anon_sym_SLASH,
    ACTIONS(132), 5,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [597] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(138), 1,
      anon_sym_SLASH,
    ACTIONS(140), 1,
      anon_sym_RPAREN,
    ACTIONS(144), 1,
      anon_sym_COMMA,
    STATE(43), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(142), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [620] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(148), 1,
      anon_sym_SLASH,
    ACTIONS(146), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [635] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(138), 1,
      anon_sym_SLASH,
    ACTIONS(142), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(150), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [653] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(138), 1,
      anon_sym_SLASH,
    ACTIONS(152), 1,
      anon_sym_SEMI,
    ACTIONS(142), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [670] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(138), 1,
      anon_sym_SLASH,
    ACTIONS(154), 1,
      anon_sym_SEMI,
    ACTIONS(142), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [687] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(138), 1,
      anon_sym_SLASH,
    ACTIONS(156), 1,
      anon_sym_RPAREN,
    ACTIONS(142), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [704] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(138), 1,
      anon_sym_SLASH,
    ACTIONS(158), 1,
      anon_sym_SEMI,
    ACTIONS(142), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [721] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_STAR,
    ACTIONS(138), 1,
      anon_sym_SLASH,
    ACTIONS(160), 1,
      anon_sym_SEMI,
    ACTIONS(142), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [738] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(46), 1,
      sym__prime_type,
    STATE(47), 1,
      sym_type,
    ACTIONS(162), 2,
      anon_sym_number,
      anon_sym_bool,
  [752] = 4,
    ACTIONS(164), 1,
      sym_comment,
    ACTIONS(168), 1,
      anon_sym_DQUOTE,
    STATE(42), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(166), 2,
      sym_escape_sequence,
      aux_sym_string_lit_token1,
  [766] = 4,
    ACTIONS(164), 1,
      sym_comment,
    ACTIONS(172), 1,
      anon_sym_DQUOTE,
    STATE(40), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(170), 2,
      sym_escape_sequence,
      aux_sym_string_lit_token1,
  [780] = 4,
    ACTIONS(164), 1,
      sym_comment,
    ACTIONS(177), 1,
      anon_sym_DQUOTE,
    STATE(42), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(174), 2,
      sym_escape_sequence,
      aux_sym_string_lit_token1,
  [794] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(144), 1,
      anon_sym_COMMA,
    ACTIONS(179), 1,
      anon_sym_RPAREN,
    STATE(44), 1,
      aux_sym_argument_list_repeat1,
  [807] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(150), 1,
      anon_sym_RPAREN,
    ACTIONS(181), 1,
      anon_sym_COMMA,
    STATE(44), 1,
      aux_sym_argument_list_repeat1,
  [820] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(184), 1,
      anon_sym_COLON,
    ACTIONS(186), 1,
      anon_sym_EQ,
  [830] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(188), 2,
      anon_sym_SEMI,
      anon_sym_EQ,
  [838] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(190), 1,
      anon_sym_SEMI,
    ACTIONS(192), 1,
      anon_sym_EQ,
  [848] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(194), 1,
      ts_builtin_sym_end,
  [855] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(196), 1,
      sym_ident,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 36,
  [SMALL_STATE(6)] = 69,
  [SMALL_STATE(7)] = 102,
  [SMALL_STATE(8)] = 135,
  [SMALL_STATE(9)] = 168,
  [SMALL_STATE(10)] = 201,
  [SMALL_STATE(11)] = 234,
  [SMALL_STATE(12)] = 267,
  [SMALL_STATE(13)] = 300,
  [SMALL_STATE(14)] = 317,
  [SMALL_STATE(15)] = 334,
  [SMALL_STATE(16)] = 351,
  [SMALL_STATE(17)] = 368,
  [SMALL_STATE(18)] = 385,
  [SMALL_STATE(19)] = 406,
  [SMALL_STATE(20)] = 423,
  [SMALL_STATE(21)] = 445,
  [SMALL_STATE(22)] = 460,
  [SMALL_STATE(23)] = 475,
  [SMALL_STATE(24)] = 490,
  [SMALL_STATE(25)] = 505,
  [SMALL_STATE(26)] = 520,
  [SMALL_STATE(27)] = 535,
  [SMALL_STATE(28)] = 550,
  [SMALL_STATE(29)] = 565,
  [SMALL_STATE(30)] = 580,
  [SMALL_STATE(31)] = 597,
  [SMALL_STATE(32)] = 620,
  [SMALL_STATE(33)] = 635,
  [SMALL_STATE(34)] = 653,
  [SMALL_STATE(35)] = 670,
  [SMALL_STATE(36)] = 687,
  [SMALL_STATE(37)] = 704,
  [SMALL_STATE(38)] = 721,
  [SMALL_STATE(39)] = 738,
  [SMALL_STATE(40)] = 752,
  [SMALL_STATE(41)] = 766,
  [SMALL_STATE(42)] = 780,
  [SMALL_STATE(43)] = 794,
  [SMALL_STATE(44)] = 807,
  [SMALL_STATE(45)] = 820,
  [SMALL_STATE(46)] = 830,
  [SMALL_STATE(47)] = 838,
  [SMALL_STATE(48)] = 848,
  [SMALL_STATE(49)] = 855,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(20),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(21),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(34),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(41),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(49),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(6),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(7),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 2),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 2),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 7, .production_id = 8),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_decl, 7, .production_id = 8),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 5, .production_id = 6),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_decl, 5, .production_id = 6),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign_stm, 4, .production_id = 5),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assign_stm, 4, .production_id = 5),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 5, .production_id = 7),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_decl, 5, .production_id = 7),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_lit, 1),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_lit, 1),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_lit, 2),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_lit, 2),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2, .production_id = 2),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2, .production_id = 2),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expression, 2, .production_id = 1),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_expression, 2, .production_id = 1),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 4),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 4),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 2),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 3),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 3),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_lit, 3),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_lit, 3),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 4),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, .production_id = 4),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesised_expression, 3, .production_id = 3),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesised_expression, 3, .production_id = 3),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [168] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [172] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [174] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_lit_repeat1, 2), SHIFT_REPEAT(42),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_lit_repeat1, 2),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [181] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(9),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [194] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_toon(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_ident,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
