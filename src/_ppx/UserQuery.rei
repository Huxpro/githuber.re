exception Graphql_error;

let ppx_printed_query: string;

let query: string;

let parse:
  Js.Json.t =>
  {
    .
    "user":
      option(
        {
          .
          "avatarUrl": Js.Json.t,
          "bio": option(string),
          "followers": {. "totalCount": int},
          "following": {. "totalCount": int},
          "id": string,
          "login": string,
          "name": option(string),
          "url": Js.Json.t,
        },
      ),
  };

let json_of_optional: ('a => Js.Json.t, option('a)) => Js.Json.t;

let json_of_array: ('a => Js.Json.t, array('a)) => Js.Json.t;

let json_of_String: string => Js.Json.t;

let make:
  (~login: string, unit) =>
  {
    .
    "parse":
      Js.Json.t =>
      {
        .
        "user":
          option(
            {
              .
              "avatarUrl": Js.Json.t,
              "bio": option(string),
              "followers": {. "totalCount": int},
              "following": {. "totalCount": int},
              "id": string,
              "login": string,
              "name": option(string),
              "url": Js.Json.t,
            },
          ),
      },
    "query": string,
    "variables": Js.Json.t,
  };

let makeWithVariables:
  {.. "login": string} =>
  {
    .
    "parse":
      Js.Json.t =>
      {
        .
        "user":
          option(
            {
              .
              "avatarUrl": Js.Json.t,
              "bio": option(string),
              "followers": {. "totalCount": int},
              "following": {. "totalCount": int},
              "id": string,
              "login": string,
              "name": option(string),
              "url": Js.Json.t,
            },
          ),
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
    "user":
      option(
        {
          .
          "avatarUrl": Js.Json.t,
          "bio": option(string),
          "followers": {. "totalCount": int},
          "following": {. "totalCount": int},
          "id": string,
          "login": string,
          "name": option(string),
          "url": Js.Json.t,
        },
      ),
  };
};

type t = MT_Ret.t;