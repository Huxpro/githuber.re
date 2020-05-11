# [Githuber.RE](https://huangxuan.me/githuber.re/)

> ⚠️ The tech stack used by this project is old and considered deprecated. Check out [V2](https://github.com/Huxpro/githuber.re-v2)!

This project demonstrates the following tech stack:

## [🐫 ReasonML](https://reasonml.github.io/)

Reason is a statically-typed, functional programming language backing by OCaml.

It leverage both the JavaScript & OCaml ecosystems by providing a familiar syntax geared toward JavaScript programmers and by catering to the existing NPM/Yarn workflow folks already know.

## [⚛️ ReasonReact](https://reasonml.github.io/reason-react/en/)

ReasonReact is Reason's official binding to [React.js](https://reactjs.org/). By leveraging the Reason's built-in language features, it pack React.js' APIs into one that is statically-typed, simple, familiar and feels "Just using Reason".

Two of the cool examples are its built-in [ReducerComponent](https://reasonml.github.io/reason-react/docs/en/state-actions-reducer.html) and its built-in [ReasonReact Router](https://reasonml.github.io/reason-react/docs/en/router.html). Both are used in this project!

## [🕸 Graph_PPX](https://github.com/mhallin/graphql_ppx)

GraphQL_PPX is a syntax extension for BuckleScript/Reason. It make constructing GraphQL queries in Reason a first-class experience and type-safe, with compile time type check instead of runtime errors.

Check out the super cool VSCode editor support on its [homepage](https://github.com/mhallin/graphql_ppx#examples).

## [🚀 Reason Scripts](https://github.com/reasonml-community/reason-scripts)

Reason Scripts is a thin Reason layer over Create-React-App, which provides a JS-like development environment for developing webapps with ReasonReact. Though in most cases, use the [bsb option](https://reasonml.github.io/reason-react/docs/en/installation.html#bsb).

It bootstraps an environment to automatically compile all Reason code to JS, provides features like hot reloading and bundling, and seamlessly uses JS code from Reason.

## [📦 BuckleScript](https://bucklescript.github.io/)

BuckleScript is a compiler and toolchain that transforms OCaml/Reason into readable JavaScript code. It comes with a powerful API to talk to JS, allowing you to access the latter's vast ecosystem.

## [🐙 Github GraphQL API](https://developer.github.com/v4/)

[Github announced its public APIs v4 that supports GraphQL](https://githubengineering.com/the-github-graphql-api/). Thanks to that, we can play and demonstrate GraphQL's power without needing to build our own server first.
