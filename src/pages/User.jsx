import React, { Component } from 'react';
import Model from '../model/model'

export default class User extends Component {

  state = {
    data: null,
    error: null
  }

  componentDidMount() {
    const username = this.props.match.params.username
    const success = (json) => {
      this.setState({
        data: json
      })
    }
    const failure = (err) => {
      this.setState({
        error: err
      })
    }
    Model.fetchUser(username, success, failure)
  }

  render() {
    const { data, error } = this.state;

     // before any response
    if(!data && !error) return null;

    // error state
    if(error) return (
      <div className="app-container">
        <h4 className="rc-box"> 
          {String(error)}
        </h4>
      </div>
    )

    return (
      <div className="rc-box app-user app-container">
        <img src={data.avatar_url}/>
        <h3>
          <a href={data.html_url}>
            {data.name} 
          </a>
        </h3>
        <h5> {data.bio } </h5>
        <section className="rc-typography--caption-large">
          FOLLOWING
          <h3> {data.following} </h3>
        </section>
        <section className="rc-typography--caption-large">
          FOLLOWERS
          <h3> {data.followers} </h3>
        </section>   
      </div>
    );
  }
}
