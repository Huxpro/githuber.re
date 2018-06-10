let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self => ReasonReact.string("Home"),
};