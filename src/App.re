[@bs.module] external logo : string = "./logo.svg";

/* import styles */
[%bs.raw {|require('./style/rc.css')|}];

[%bs.raw {|require('./style/app.css')|}];

[%bs.raw {|require('./style/nprogress.css')|}];

/* alias */
type reactElement = ReasonReact.reactElement;

module Router = ReasonReact.Router;

/* component */
type action =
  | Navigate(reactElement);

type state = {currentRoute: reactElement};

let component = ReasonReact.reducerComponent("App");

let comp_of_path = url =>
  switch (Router.(url.path)) {
  | [] => <Home />
  | ["search", search] => <Search search />
  | ["user", username] => <User username />
  | _ => <NotFound />
  };

let make = _children => {
  ...component,
  initialState: () => {
    currentRoute: comp_of_path(Router.dangerouslyGetInitialUrl()),
  },
  didMount: self => {
    let watcherID =
      Router.watchUrl(url => Navigate(comp_of_path(url)) |> self.send);
    self.onUnmount(() => Router.unwatchUrl(watcherID));
  },
  reducer: (action, _state) =>
    switch (action) {
    | Navigate(comp) => ReasonReact.Update({currentRoute: comp})
    },
  render: self =>
    <div className="rc-typography"> <Nav /> self.state.currentRoute </div>,
};