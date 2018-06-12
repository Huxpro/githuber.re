module UserQuery = [%graphql
  {|
    query($login: String!) {
      user(login: $login){
        id
        url
        bio
        name
        login
        avatarUrl
        followers {
          totalCount
        }
        following {
          totalCount
        }
      }
    }
  |}
];

type state = {data: option(UserQuery.t)};

type action =
  | Resp(UserQuery.t);

let component = ReasonReact.reducerComponent("User");

let renderPlaceholder =
  <div className="rc-box app-user app-container"> <img alt="" /> </div>;

let renderNotFound =
  <div className="app-container">
    <h4 className="rc-box">
      (ReasonReact.string("Hmm...we found no one"))
    </h4>
  </div>;

let make = (~username, _children) => {
  let fetchData = (login, self) =>
    UserQuery.make(~login, ())
    |> Api.sendQuery
    |> Js.Promise.then_(data => {
         Js.log(data);
         ReasonReact.(self.send(Resp(data)));
         Js.Promise.resolve();
       })
    |> ignore;
  {
    ...component,
    initialState: () => {data: None},
    didMount: self => fetchData(username, self),
    reducer: (action, _state) =>
      switch (action) {
      | Resp(resp) => ReasonReact.Update({data: Some(resp)})
      },
    render: self =>
      switch (self.state.data) {
      | None => renderPlaceholder
      | Some(data) =>
        switch (data##user) {
        | None => renderNotFound
        | Some(data) =>
          let name =
            switch (data##name) {
            | None => ""
            | Some(name) => name
            };
          let bio =
            switch (data##bio) {
            | None => ""
            | Some(bio) => bio
            };
          let url =
            switch (Js.Json.decodeString(data##url)) {
            | None => ""
            | Some(url) => url
            };
          let avatarUrl =
            switch (Js.Json.decodeString(data##avatarUrl)) {
            | None => ""
            | Some(url) => url
            };
          <div className="rc-box app-user app-container">
            <img src=avatarUrl alt=name />
            <h3> <a href=url> (ReasonReact.string(name)) </a> </h3>
            <h5> (ReasonReact.string(data##login)) </h5>
            <h5> (ReasonReact.string(bio)) </h5>
            <section className="rc-typography--caption-large">
              (ReasonReact.string("FOLLOWING"))
              <h3>
                (
                  string_of_int(data##following##totalCount)
                  |> ReasonReact.string
                )
              </h3>
            </section>
            <section className="rc-typography--caption-large">
              (ReasonReact.string("FOLLOWERS"))
              <h3>
                (
                  string_of_int(data##followers##totalCount)
                  |> ReasonReact.string
                )
              </h3>
            </section>
          </div>;
        }
      },
  };
};