#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 77
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 44
#define ALIAS_COUNT 0
#define TOKEN_COUNT 25
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
  anon_sym_string = 11,
  anon_sym_SEMI = 12,
  anon_sym_let = 13,
  anon_sym_COLON = 14,
  anon_sym_EQ = 15,
  anon_sym_LBRACE = 16,
  anon_sym_RBRACE = 17,
  anon_sym_LPAREN = 18,
  anon_sym_RPAREN = 19,
  anon_sym_DASH = 20,
  anon_sym_STAR = 21,
  anon_sym_SLASH = 22,
  anon_sym_PLUS = 23,
  anon_sym_COMMA = 24,
  sym_root = 25,
  sym_bool_lit = 26,
  sym_string_lit = 27,
  sym__literal = 28,
  sym_type = 29,
  sym__prime_type = 30,
  sym_statement = 31,
  sym_var_decl = 32,
  sym_assign_stm = 33,
  sym_block = 34,
  sym__expression = 35,
  sym_parenthesised_expression = 36,
  sym_unary_expression = 37,
  sym_binary_expression = 38,
  sym_argument_list = 39,
  sym_call_expression = 40,
  aux_sym_root_repeat1 = 41,
  aux_sym_string_lit_repeat1 = 42,
  aux_sym_argument_list_repeat1 = 43,
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
  [anon_sym_string] = "string",
  [anon_sym_SEMI] = ";",
  [anon_sym_let] = "let",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
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
  [sym_block] = "block",
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
  [anon_sym_string] = anon_sym_string,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
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
  [sym_block] = sym_block,
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
  [anon_sym_string] = {
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
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
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
  [sym_block] = {
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
      if (lookahead == '(') ADVANCE(28);
      if (lookahead == ')') ADVANCE(29);
      if (lookahead == '*') ADVANCE(31);
      if (lookahead == '+') ADVANCE(33);
      if (lookahead == ',') ADVANCE(34);
      if (lookahead == '-') ADVANCE(30);
      if (lookahead == '.') ADVANCE(7);
      if (lookahead == '/') ADVANCE(32);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == ';') ADVANCE(23);
      if (lookahead == '=') ADVANCE(25);
      if (lookahead == '\\') ADVANCE(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead == '{') ADVANCE(26);
      if (lookahead == '}') ADVANCE(27);
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
      if (lookahead == '(') ADVANCE(28);
      if (lookahead == ')') ADVANCE(29);
      if (lookahead == '*') ADVANCE(31);
      if (lookahead == '+') ADVANCE(33);
      if (lookahead == ',') ADVANCE(34);
      if (lookahead == '-') ADVANCE(30);
      if (lookahead == '.') ADVANCE(7);
      if (lookahead == '/') ADVANCE(32);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == ';') ADVANCE(23);
      if (lookahead == '=') ADVANCE(25);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead == '{') ADVANCE(26);
      if (lookahead == '}') ADVANCE(27);
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
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(15);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 34:
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
      if (lookahead == 's') ADVANCE(5);
      if (lookahead == 't') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(7);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(8);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(9);
      END_STATE();
    case 4:
      if (lookahead == 'u') ADVANCE(10);
      END_STATE();
    case 5:
      if (lookahead == 't') ADVANCE(11);
      END_STATE();
    case 6:
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 7:
      if (lookahead == 'o') ADVANCE(13);
      END_STATE();
    case 8:
      if (lookahead == 'l') ADVANCE(14);
      END_STATE();
    case 9:
      if (lookahead == 't') ADVANCE(15);
      END_STATE();
    case 10:
      if (lookahead == 'm') ADVANCE(16);
      END_STATE();
    case 11:
      if (lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 12:
      if (lookahead == 'u') ADVANCE(18);
      END_STATE();
    case 13:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 14:
      if (lookahead == 's') ADVANCE(20);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 16:
      if (lookahead == 'b') ADVANCE(21);
      END_STATE();
    case 17:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 22:
      if (lookahead == 'n') ADVANCE(26);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 25:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 26:
      if (lookahead == 'g') ADVANCE(28);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_number);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_string);
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
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
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
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
  },
  [1] = {
    [sym_root] = STATE(74),
    [sym_bool_lit] = STATE(58),
    [sym_string_lit] = STATE(58),
    [sym__literal] = STATE(58),
    [sym_statement] = STATE(6),
    [sym_var_decl] = STATE(23),
    [sym_assign_stm] = STATE(23),
    [sym_block] = STATE(23),
    [sym__expression] = STATE(58),
    [sym_parenthesised_expression] = STATE(58),
    [sym_unary_expression] = STATE(58),
    [sym_binary_expression] = STATE(58),
    [sym_call_expression] = STATE(58),
    [aux_sym_root_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_ident] = ACTIONS(7),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_number_lit] = ACTIONS(11),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_let] = ACTIONS(15),
    [anon_sym_LBRACE] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(21),
  },
  [2] = {
    [sym_bool_lit] = STATE(53),
    [sym_string_lit] = STATE(53),
    [sym__literal] = STATE(53),
    [sym_statement] = STATE(2),
    [sym_var_decl] = STATE(31),
    [sym_assign_stm] = STATE(31),
    [sym_block] = STATE(31),
    [sym__expression] = STATE(53),
    [sym_parenthesised_expression] = STATE(53),
    [sym_unary_expression] = STATE(53),
    [sym_binary_expression] = STATE(53),
    [sym_call_expression] = STATE(53),
    [aux_sym_root_repeat1] = STATE(2),
    [sym_ident] = ACTIONS(23),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(26),
    [anon_sym_false] = ACTIONS(26),
    [sym_number_lit] = ACTIONS(29),
    [anon_sym_DQUOTE] = ACTIONS(32),
    [anon_sym_let] = ACTIONS(35),
    [anon_sym_LBRACE] = ACTIONS(38),
    [anon_sym_RBRACE] = ACTIONS(41),
    [anon_sym_LPAREN] = ACTIONS(43),
    [anon_sym_DASH] = ACTIONS(46),
  },
  [3] = {
    [sym_bool_lit] = STATE(53),
    [sym_string_lit] = STATE(53),
    [sym__literal] = STATE(53),
    [sym_statement] = STATE(2),
    [sym_var_decl] = STATE(31),
    [sym_assign_stm] = STATE(31),
    [sym_block] = STATE(31),
    [sym__expression] = STATE(53),
    [sym_parenthesised_expression] = STATE(53),
    [sym_unary_expression] = STATE(53),
    [sym_binary_expression] = STATE(53),
    [sym_call_expression] = STATE(53),
    [aux_sym_root_repeat1] = STATE(2),
    [sym_ident] = ACTIONS(49),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_number_lit] = ACTIONS(51),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_let] = ACTIONS(53),
    [anon_sym_LBRACE] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(57),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(21),
  },
  [4] = {
    [sym_bool_lit] = STATE(53),
    [sym_string_lit] = STATE(53),
    [sym__literal] = STATE(53),
    [sym_statement] = STATE(8),
    [sym_var_decl] = STATE(31),
    [sym_assign_stm] = STATE(31),
    [sym_block] = STATE(31),
    [sym__expression] = STATE(53),
    [sym_parenthesised_expression] = STATE(53),
    [sym_unary_expression] = STATE(53),
    [sym_binary_expression] = STATE(53),
    [sym_call_expression] = STATE(53),
    [aux_sym_root_repeat1] = STATE(8),
    [sym_ident] = ACTIONS(49),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_number_lit] = ACTIONS(51),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_let] = ACTIONS(53),
    [anon_sym_LBRACE] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(59),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(21),
  },
  [5] = {
    [sym_bool_lit] = STATE(53),
    [sym_string_lit] = STATE(53),
    [sym__literal] = STATE(53),
    [sym_statement] = STATE(3),
    [sym_var_decl] = STATE(31),
    [sym_assign_stm] = STATE(31),
    [sym_block] = STATE(31),
    [sym__expression] = STATE(53),
    [sym_parenthesised_expression] = STATE(53),
    [sym_unary_expression] = STATE(53),
    [sym_binary_expression] = STATE(53),
    [sym_call_expression] = STATE(53),
    [aux_sym_root_repeat1] = STATE(3),
    [sym_ident] = ACTIONS(49),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_number_lit] = ACTIONS(51),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_let] = ACTIONS(53),
    [anon_sym_LBRACE] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(61),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(21),
  },
  [6] = {
    [sym_bool_lit] = STATE(58),
    [sym_string_lit] = STATE(58),
    [sym__literal] = STATE(58),
    [sym_statement] = STATE(7),
    [sym_var_decl] = STATE(23),
    [sym_assign_stm] = STATE(23),
    [sym_block] = STATE(23),
    [sym__expression] = STATE(58),
    [sym_parenthesised_expression] = STATE(58),
    [sym_unary_expression] = STATE(58),
    [sym_binary_expression] = STATE(58),
    [sym_call_expression] = STATE(58),
    [aux_sym_root_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(63),
    [sym_ident] = ACTIONS(7),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_number_lit] = ACTIONS(11),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_let] = ACTIONS(15),
    [anon_sym_LBRACE] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(21),
  },
  [7] = {
    [sym_bool_lit] = STATE(58),
    [sym_string_lit] = STATE(58),
    [sym__literal] = STATE(58),
    [sym_statement] = STATE(7),
    [sym_var_decl] = STATE(23),
    [sym_assign_stm] = STATE(23),
    [sym_block] = STATE(23),
    [sym__expression] = STATE(58),
    [sym_parenthesised_expression] = STATE(58),
    [sym_unary_expression] = STATE(58),
    [sym_binary_expression] = STATE(58),
    [sym_call_expression] = STATE(58),
    [aux_sym_root_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_ident] = ACTIONS(65),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(26),
    [anon_sym_false] = ACTIONS(26),
    [sym_number_lit] = ACTIONS(68),
    [anon_sym_DQUOTE] = ACTIONS(32),
    [anon_sym_let] = ACTIONS(71),
    [anon_sym_LBRACE] = ACTIONS(74),
    [anon_sym_LPAREN] = ACTIONS(43),
    [anon_sym_DASH] = ACTIONS(46),
  },
  [8] = {
    [sym_bool_lit] = STATE(53),
    [sym_string_lit] = STATE(53),
    [sym__literal] = STATE(53),
    [sym_statement] = STATE(2),
    [sym_var_decl] = STATE(31),
    [sym_assign_stm] = STATE(31),
    [sym_block] = STATE(31),
    [sym__expression] = STATE(53),
    [sym_parenthesised_expression] = STATE(53),
    [sym_unary_expression] = STATE(53),
    [sym_binary_expression] = STATE(53),
    [sym_call_expression] = STATE(53),
    [aux_sym_root_repeat1] = STATE(2),
    [sym_ident] = ACTIONS(49),
    [sym_comment] = ACTIONS(3),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_number_lit] = ACTIONS(51),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_let] = ACTIONS(53),
    [anon_sym_LBRACE] = ACTIONS(55),
    [anon_sym_RBRACE] = ACTIONS(77),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(21),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(81), 1,
      sym_number_lit,
    ACTIONS(83), 1,
      anon_sym_RPAREN,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(45), 8,
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
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(85), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(61), 8,
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
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(87), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(63), 8,
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
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(89), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(54), 8,
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
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(91), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(43), 8,
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
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(93), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(49), 8,
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
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(95), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 8,
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
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(97), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(62), 8,
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
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(99), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(59), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [300] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(101), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(52), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [333] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(103), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(51), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [366] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(79), 1,
      sym_ident,
    ACTIONS(105), 1,
      sym_number_lit,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(60), 8,
      sym_bool_lit,
      sym_string_lit,
      sym__literal,
      sym__expression,
      sym_parenthesised_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_call_expression,
  [399] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(109), 6,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [417] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(113), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(111), 6,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [435] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(117), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(115), 6,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [453] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(121), 6,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [471] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(109), 6,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [489] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(125), 6,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [507] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(129), 6,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [525] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(133), 6,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [543] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(137), 6,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [561] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(113), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(111), 6,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [579] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(117), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(115), 6,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [597] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(137), 6,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [615] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(121), 6,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [633] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(125), 6,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [651] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(129), 6,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [669] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 4,
      sym_ident,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(133), 6,
      ts_builtin_sym_end,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [687] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(141), 1,
      anon_sym_LPAREN,
    ACTIONS(143), 1,
      anon_sym_SLASH,
    STATE(48), 1,
      sym_argument_list,
    ACTIONS(139), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [708] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(141), 1,
      anon_sym_LPAREN,
    ACTIONS(143), 1,
      anon_sym_SLASH,
    ACTIONS(145), 1,
      anon_sym_EQ,
    STATE(48), 1,
      sym_argument_list,
    ACTIONS(139), 4,
      anon_sym_SEMI,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
  [730] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(141), 1,
      anon_sym_LPAREN,
    ACTIONS(143), 1,
      anon_sym_SLASH,
    ACTIONS(147), 1,
      anon_sym_EQ,
    STATE(48), 1,
      sym_argument_list,
    ACTIONS(139), 4,
      anon_sym_SEMI,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
  [752] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      anon_sym_SLASH,
    ACTIONS(149), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [767] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(155), 1,
      anon_sym_SLASH,
    ACTIONS(153), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [782] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(159), 1,
      anon_sym_SLASH,
    ACTIONS(157), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [797] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(163), 1,
      anon_sym_SLASH,
    ACTIONS(161), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [812] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(167), 1,
      anon_sym_SLASH,
    ACTIONS(165), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [827] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(169), 1,
      anon_sym_RPAREN,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(177), 1,
      anon_sym_COMMA,
    STATE(68), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [850] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(181), 1,
      anon_sym_SLASH,
    ACTIONS(179), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [865] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(185), 1,
      anon_sym_SLASH,
    ACTIONS(183), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [880] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(189), 1,
      anon_sym_SLASH,
    ACTIONS(187), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [895] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(191), 5,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [912] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(195), 1,
      anon_sym_SLASH,
    ACTIONS(193), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [927] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(197), 1,
      anon_sym_SLASH,
    ACTIONS(191), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_COMMA,
  [942] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(199), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [960] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(201), 1,
      anon_sym_SEMI,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [977] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(203), 1,
      anon_sym_RPAREN,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [994] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(70), 1,
      sym_type,
    STATE(72), 1,
      sym__prime_type,
    ACTIONS(205), 3,
      anon_sym_number,
      anon_sym_bool,
      anon_sym_string,
  [1009] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(71), 1,
      sym_type,
    STATE(72), 1,
      sym__prime_type,
    ACTIONS(205), 3,
      anon_sym_number,
      anon_sym_bool,
      anon_sym_string,
  [1024] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(207), 1,
      anon_sym_SEMI,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1041] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(209), 1,
      anon_sym_SEMI,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1058] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(211), 1,
      anon_sym_SEMI,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1075] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(213), 1,
      anon_sym_SEMI,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1092] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(215), 1,
      anon_sym_SEMI,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1109] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(217), 1,
      anon_sym_SEMI,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1126] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(175), 1,
      anon_sym_SLASH,
    ACTIONS(219), 1,
      anon_sym_SEMI,
    ACTIONS(171), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1143] = 4,
    ACTIONS(221), 1,
      sym_comment,
    ACTIONS(226), 1,
      anon_sym_DQUOTE,
    STATE(64), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(223), 2,
      sym_escape_sequence,
      aux_sym_string_lit_token1,
  [1157] = 4,
    ACTIONS(221), 1,
      sym_comment,
    ACTIONS(230), 1,
      anon_sym_DQUOTE,
    STATE(66), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(228), 2,
      sym_escape_sequence,
      aux_sym_string_lit_token1,
  [1171] = 4,
    ACTIONS(221), 1,
      sym_comment,
    ACTIONS(234), 1,
      anon_sym_DQUOTE,
    STATE(64), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(232), 2,
      sym_escape_sequence,
      aux_sym_string_lit_token1,
  [1185] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(199), 1,
      anon_sym_RPAREN,
    ACTIONS(236), 1,
      anon_sym_COMMA,
    STATE(67), 1,
      aux_sym_argument_list_repeat1,
  [1198] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(177), 1,
      anon_sym_COMMA,
    ACTIONS(239), 1,
      anon_sym_RPAREN,
    STATE(67), 1,
      aux_sym_argument_list_repeat1,
  [1211] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(241), 1,
      anon_sym_COLON,
    ACTIONS(243), 1,
      anon_sym_EQ,
  [1221] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(245), 1,
      anon_sym_SEMI,
    ACTIONS(247), 1,
      anon_sym_EQ,
  [1231] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(249), 1,
      anon_sym_SEMI,
    ACTIONS(251), 1,
      anon_sym_EQ,
  [1241] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(253), 2,
      anon_sym_SEMI,
      anon_sym_EQ,
  [1249] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(255), 1,
      anon_sym_COLON,
    ACTIONS(257), 1,
      anon_sym_EQ,
  [1259] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(259), 1,
      ts_builtin_sym_end,
  [1266] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(261), 1,
      sym_ident,
  [1273] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(263), 1,
      sym_ident,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 36,
  [SMALL_STATE(11)] = 69,
  [SMALL_STATE(12)] = 102,
  [SMALL_STATE(13)] = 135,
  [SMALL_STATE(14)] = 168,
  [SMALL_STATE(15)] = 201,
  [SMALL_STATE(16)] = 234,
  [SMALL_STATE(17)] = 267,
  [SMALL_STATE(18)] = 300,
  [SMALL_STATE(19)] = 333,
  [SMALL_STATE(20)] = 366,
  [SMALL_STATE(21)] = 399,
  [SMALL_STATE(22)] = 417,
  [SMALL_STATE(23)] = 435,
  [SMALL_STATE(24)] = 453,
  [SMALL_STATE(25)] = 471,
  [SMALL_STATE(26)] = 489,
  [SMALL_STATE(27)] = 507,
  [SMALL_STATE(28)] = 525,
  [SMALL_STATE(29)] = 543,
  [SMALL_STATE(30)] = 561,
  [SMALL_STATE(31)] = 579,
  [SMALL_STATE(32)] = 597,
  [SMALL_STATE(33)] = 615,
  [SMALL_STATE(34)] = 633,
  [SMALL_STATE(35)] = 651,
  [SMALL_STATE(36)] = 669,
  [SMALL_STATE(37)] = 687,
  [SMALL_STATE(38)] = 708,
  [SMALL_STATE(39)] = 730,
  [SMALL_STATE(40)] = 752,
  [SMALL_STATE(41)] = 767,
  [SMALL_STATE(42)] = 782,
  [SMALL_STATE(43)] = 797,
  [SMALL_STATE(44)] = 812,
  [SMALL_STATE(45)] = 827,
  [SMALL_STATE(46)] = 850,
  [SMALL_STATE(47)] = 865,
  [SMALL_STATE(48)] = 880,
  [SMALL_STATE(49)] = 895,
  [SMALL_STATE(50)] = 912,
  [SMALL_STATE(51)] = 927,
  [SMALL_STATE(52)] = 942,
  [SMALL_STATE(53)] = 960,
  [SMALL_STATE(54)] = 977,
  [SMALL_STATE(55)] = 994,
  [SMALL_STATE(56)] = 1009,
  [SMALL_STATE(57)] = 1024,
  [SMALL_STATE(58)] = 1041,
  [SMALL_STATE(59)] = 1058,
  [SMALL_STATE(60)] = 1075,
  [SMALL_STATE(61)] = 1092,
  [SMALL_STATE(62)] = 1109,
  [SMALL_STATE(63)] = 1126,
  [SMALL_STATE(64)] = 1143,
  [SMALL_STATE(65)] = 1157,
  [SMALL_STATE(66)] = 1171,
  [SMALL_STATE(67)] = 1185,
  [SMALL_STATE(68)] = 1198,
  [SMALL_STATE(69)] = 1211,
  [SMALL_STATE(70)] = 1221,
  [SMALL_STATE(71)] = 1231,
  [SMALL_STATE(72)] = 1241,
  [SMALL_STATE(73)] = 1249,
  [SMALL_STATE(74)] = 1259,
  [SMALL_STATE(75)] = 1266,
  [SMALL_STATE(76)] = 1273,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(39),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(42),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(53),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(65),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(76),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(5),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(12),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(13),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(38),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(58),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(75),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(4),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 2),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 1),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_decl, 7, .production_id = 8),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 7, .production_id = 8),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_decl, 5, .production_id = 7),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 5, .production_id = 7),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_decl, 5, .production_id = 6),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 5, .production_id = 6),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assign_stm, 4, .production_id = 5),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign_stm, 4, .production_id = 5),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesised_expression, 3, .production_id = 3),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesised_expression, 3, .production_id = 3),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_lit, 3),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_lit, 3),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_lit, 1),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_lit, 1),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2, .production_id = 2),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2, .production_id = 2),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 2),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [175] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 3),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 3),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 4),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 4),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expression, 2, .production_id = 1),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_expression, 2, .production_id = 1),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 4),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_lit, 2),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_lit, 2),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, .production_id = 4),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [223] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_lit_repeat1, 2), SHIFT_REPEAT(64),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_lit_repeat1, 2),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [230] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [234] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [236] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(18),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [259] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
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
