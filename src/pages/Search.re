type state = let component = ReasonReact.reducerComponent("Search");

let make = (~search, _children) => {
  ...component,
  render: _self =>
    <div className="app-container">
      <h4 className="rc-box">
        (ReasonReact.string("Hmm...we found no one"))
        (ReasonReact.string(search))
      </h4>
    </div>,
};