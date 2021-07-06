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
  );

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

    type: ($) =>
      choice(
        $._type_identifier,
      ),

    _type_identifier: ($) => choice("number", "bool"),

    statement: ($) =>
      choice(
        $.var_decl,
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
        ";",
      ),

    _expression: ($) =>
      choice(
        $.unary_expression,
        $.binary_expression,
        $.number_lit,
        $._parenthesised_expression,
        $.ident,
      ),

    _parenthesised_expression: ($) =>
      seq(
        "(",
        $._expression,
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
  },
});
