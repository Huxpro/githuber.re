let component = ReasonReact.statelessComponent("NotFound");

let make = _children => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
        <div className="app-container">
          <h2 className="rc-box"> (ReasonReact.string("404")) </h2>
        </div>
      </div>
    </div>,
};