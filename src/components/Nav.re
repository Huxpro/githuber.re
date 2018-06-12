let component = ReasonReact.statelessComponent("App");

let make = _children => {
  let searchRef = ref(None);
  let setInputRef = (theRef, _self) =>
    searchRef := Js.Nullable.toOption(theRef);
  let onSearch = event => {
    ReactEventRe.Form.preventDefault(event);
    switch (searchRef^) {
    | None => ()
    | Some(eleRef) =>
      let ele = ReactDOMRe.domElementToObj(eleRef);
      switch (ele##value) {
      | "" => ()
      | searchVal =>
        Router.push("/search/" ++ searchVal);
        ele##value#="";
        ele##blur();
      };
    };
  };
  {
    ...component,
    render: self =>
      <div className="rc-navbar app-navbar">
        <h1 onClick=((_) => Router.push("/"))>
          (ReasonReact.string("Githuber.RE"))
        </h1>
        <form className="flex" onSubmit=onSearch>
          <input
            type_="search"
            ref=(self.handle(setInputRef))
            placeholder="Search someone"
          />
          <button className="rc-button"> (ReasonReact.string("Go")) </button>
        </form>
      </div>,
  };
};