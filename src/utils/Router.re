/* Wrap ReasonReact.Router to support base_name */
let base_name = "/githuber.re";

let push = path => ReasonReact.Router.push(base_name ++ path);

let cdr = list =>
  switch (list) {
  | [] => []
  | [_base, ...tl] => tl
  };

let watchUrl = callback =>
  ReasonReact.Router.watchUrl(url =>
    callback({...url, path: cdr(url.path)})
  );

let getInitialUrl = () => {
  let url = ReasonReact.Router.dangerouslyGetInitialUrl();
  {...url, path: cdr(url.path)};
};