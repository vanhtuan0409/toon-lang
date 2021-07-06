const PREC = {
    unary: 2,
    multiply: 1,
    add: 0,
  },
  letter = choice(/[a-zA-Z]/, "_"),
  digit = /[0-9]/,
  int_lit = repeat1(digit),
  float_lit = choice(
    seq(int_lit, ".", optional(int_lit)),
    seq(".", int_lit),
  ),
  terminator = choice(";");

module.exports = grammar({
  name: "toon",

  extras: ($) => [
    $.comment,
    /\s/,
  ],

  word: ($) => $.ident,

  rules: {
    root: ($) =>
      choice(
        repeat($.statement),
      ),

    ident: ($) =>
      token(seq(
        letter,
        repeat(choice(letter, digit)),
      )),

    comment: ($) => token(seq("//", /.*/)),

    bool_lit: ($) => choice("true", "false"),

    number_lit: ($) =>
      token(choice(
        int_lit,
        float_lit,
      )),

    escape_sequence: ($) =>
      token.immediate(
        seq(
          "\\",
          choice(
            /[^xu]/,
            /u[0-9a-fA-F]{4}/,
            /u{[0-9a-fA-F]+}/,
            /x[0-9a-fA-F]{2}/,
          ),
        ),
      ),

    string_lit: ($) =>
      seq(
        '"',
        repeat(
          choice(token.immediate(prec(1, /[^"\n\\]+/)), $.escape_sequence),
        ),
        '"',
      ),

    _literal: ($) => choice($.bool_lit, $.number_lit, $.string_lit),

    type: ($) =>
      choice(
        $._prime_type,
      ),

    _prime_type: ($) => choice("number", "bool"),

    statement: ($) =>
      choice(
        $.var_decl,
        $.assign_stm,
        seq($._expression, terminator),
      ),

    var_decl: ($) =>
      seq(
        "let",
        field("var_name", $.ident),
        choice(
          seq(
            ":",
            field("var_type", $.type), //no value assigned. Eg: let x: number;
            optional(seq("=", field("var_expr", $._expression))), //with value assigned. Eg: let x: number = 1;
          ),
          seq("=", field("var_expr", $._expression)), //with value assigned but no type. Eg: let x = 1;
        ),
        terminator,
      ),

    assign_stm: ($) =>
      seq(
        field("var_name", $.ident),
        "=",
        field("var_expr", $._expression),
        terminator,
      ),

    _expression: ($) =>
      choice(
        $._literal,
        $.unary_expression,
        $.binary_expression,
        $.parenthesised_expression,
        $.call_expression,
        $.ident,
      ),

    parenthesised_expression: ($) =>
      seq(
        "(",
        field("inner", $._expression),
        ")",
      ),

    unary_expression: ($) =>
      prec(
        PREC.unary,
        seq(
          field("operator", choice("-")),
          field("operand", $._expression),
        ),
      ),

    binary_expression: ($) => {
      const table = [
        [PREC.multiply, choice("*", "/")],
        [PREC.add, choice("+", "-")],
      ];
      return choice(...table.map(([precedence, operator]) =>
        prec.left(
          precedence,
          seq(
            field("left", $._expression),
            field("operator", operator),
            field("right", $._expression),
          ),
        )
      ));
    },

    argument_list: ($) =>
      seq(
        "(",
        optional(seq($._expression, repeat(seq(",", $._expression)))),
        ")",
      ),

    call_expression: ($) =>
      seq(
        field("func_name", $.ident),
        field("args", $.argument_list),
      ),
  },
});
