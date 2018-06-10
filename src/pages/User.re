let component = ReasonReact.statelessComponent("User");

let make = (~username, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
        <h2> (ReasonReact.string(username)) </h2>
      </div>
    </div>,
};