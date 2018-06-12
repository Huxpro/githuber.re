exception Graphql_error;

let ppx_printed_query: string;

let query: string;

let parse:
  Js.Json.t =>
  {
    .
    "search": {
      .
      "nodes":
        option(
          Js.Array.t(
            option(
              [
                | `Nonexhaustive
                | `User(
                    {
                      .
                      "avatarUrl": Js.Json.t,
                      "id": string,
                      "login": string,
                    },
                  )
              ],
            ),
          ),
        ),
      "pageInfo": {
        .
        "endCursor": option(string),
        "hasNextPage": bool,
        "hasPreviousPage": bool,
      },
      "userCount": int,
    },
  };

let json_of_optional: ('a => Js.Json.t, option('a)) => Js.Json.t;

let json_of_array: ('a => Js.Json.t, array('a)) => Js.Json.t;

let json_of_String: string => Js.Json.t;

let make:
  (~username: string, unit) =>
  {
    .
    "parse":
      Js.Json.t =>
      {
        .
        "search": {
          .
          "nodes":
            option(
              Js.Array.t(
                option(
                  [
                    | `Nonexhaustive
                    | `User(
                        {
                          .
                          "avatarUrl": Js.Json.t,
                          "id": string,
                          "login": string,
                        },
                      )
                  ],
                ),
              ),
            ),
          "pageInfo": {
            .
            "endCursor": option(string),
            "hasNextPage": bool,
            "hasPreviousPage": bool,
          },
          "userCount": int,
        },
      },
    "query": string,
    "variables": Js.Json.t,
  };

let makeWithVariables:
  {.. "username": string} =>
  {
    .
    "parse":
      Js.Json.t =>
      {
        .
        "search": {
          .
          "nodes":
            option(
              Js.Array.t(
                option(
                  [
                    | `Nonexhaustive
                    | `User(
                        {
                          .
                          "avatarUrl": Js.Json.t,
                          "id": string,
                          "login": string,
                        },
                      )
                  ],
                ),
              ),
            ),
          "pageInfo": {
            .
            "endCursor": option(string),
            "hasNextPage": bool,
            "hasPreviousPage": bool,
          },
          "userCount": int,
        },
      },
    "query": string,
    "variables": Js.Json.t,
  };

module type mt_ret = {type t;};

type typed_ret('a) = (module mt_ret with type t = 'a);

let ret_type: ('a, 'b) => typed_ret('b);

module MT_Ret: {
  type t = {
    .
    "search": {
      .
      "nodes":
        option(
          Js.Array.t(
            option(
              [
                | `Nonexhaustive
                | `User(
                    {
                      .
                      "avatarUrl": Js.Json.t,
                      "id": string,
                      "login": string,
                    },
                  )
              ],
            ),
          ),
        ),
      "pageInfo": {
        .
        "endCursor": option(string),
        "hasNextPage": bool,
        "hasPreviousPage": bool,
      },
      "userCount": int,
    },
  };
};

type t = MT_Ret.t;