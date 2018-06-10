[@bs.module] external logo : string = "./logo.svg";

/* import styles */
[%bs.raw {|require('./style/rc.css')|}];

[%bs.raw {|require('./style/app.css')|}];

[%bs.raw {|require('./style/nprogress.css')|}];

type action =
  | Navigate(ReasonReact.reactElement);

type state = {currentRoute: ReasonReact.reactElement};

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {currentRoute: <Home />},
  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url =>
        switch (url.path) {
        | [] => self.send(Navigate(<Home />))
        | ["search", search] => self.send(Navigate(<Search search />))
        | ["user", username] => self.send(Navigate(<User username />))
        | _ => self.send(Navigate(<NotFound />))
        }
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  reducer: (action, _state) =>
    switch (action) {
    | Navigate(comp) => ReasonReact.Update({currentRoute: comp})
    },
  render: self =>
    <div className="rc-typography"> <Nav /> self.state.currentRoute </div>,
};