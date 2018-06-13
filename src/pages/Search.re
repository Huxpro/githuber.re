module SearchQuery = [%graphql
  {|
    query($username: String!) {
      search(query: $username, type:USER, first: 10) {
        pageInfo {
          hasNextPage
          hasPreviousPage
          endCursor
        }
        userCount
        nodes {
          ...on User{
            id
            login
            avatarUrl
          }
        }
      }
    }
  |}
];

type state = {
  data: option(SearchQuery.t),
  prevSearch: string,
};

type action =
  | Resp(SearchQuery.t);

let component = ReasonReact.reducerComponent("Search");

/*
 type iSearchResultItem = [
   | `Nonexhaustive
   | `User(
       {
         .
         "avatarUrl": Js.Json.t,
         "id": string,
         "login": string,
       },
     )
 ];
 */
let renderList = nodes : ReasonReact.reactElement =>
  switch (nodes) {
  | None => assert(false) /* Empty nodes shouldn't pass usercount check */
  | Some(nodes) =>
    nodes
    |> Js.Array.map(node =>
         switch (node) {
         | None => ReasonReact.null
         | Some(node) =>
           switch (node) {
           | `Nonexhaustive => ReasonReact.null
           | `User(user) =>
             let avatarUrl =
               switch (Js.Json.decodeString(user##avatarUrl)) {
               | None => assert(false)
               | Some(url) => url
               };
             <li
               className="rc-list-item"
               key=user##id
               onClick=(_ => Router.push("/user/" ++ user##login))>
               <img src=avatarUrl alt=user##login />
               <span className="rc-list-item__text">
                 (ReasonReact.string(user##login))
               </span>
             </li>;
           }
         }
       )
    |> ReasonReact.array
  };

let renderNotFound =
  <div className="app-container">
    <h4 className="rc-box">
      (ReasonReact.string("Hmm...we found no one"))
    </h4>
  </div>;

let make = (~search, _children) => {
  let fetchData = (search, self) =>
    SearchQuery.make(~username=search, ())
    |> Api.sendQuery
    |> Js.Promise.then_(data => {
         Js.log(data);
         ReasonReact.(self.send(Resp(data)));
         Js.Promise.resolve();
       })
    |> ignore;
  {
    ...component,
    initialState: () => {data: None, prevSearch: search},
    didMount: self => fetchData(search, self),
    willReceiveProps: self => {
      if (self.state.prevSearch != search) {
        fetchData(search, self);
      };
      {...self.state, prevSearch: search};
    },
    reducer: (action, state) =>
      switch (action) {
      | Resp(resp) => ReasonReact.Update({...state, data: Some(resp)})
      },
    render: self =>
      switch (self.state.data) {
      | None => ReasonReact.null
      | Some(data) =>
        if (data##search##userCount == 0) {
          renderNotFound;
        } else {
          <ul className="rc-list app-container">
            <h4
              className="rc-box"
              style=(ReactDOMRe.Style.make(~marginBottom="0", ()))>
              (ReasonReact.string("Top Results - " ++ search))
            </h4>
            (renderList(data##search##nodes))
          </ul>;
        }
      },
  };
};