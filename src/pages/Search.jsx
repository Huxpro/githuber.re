import React, { Component } from 'react';
import Model from '../model/model'
import { Link } from 'react-router-dom';

export default class Search extends Component {

  state = {
    data: null,
    error: null,
  }

  fetchData(inJS, search){
    const success = (json)=> {
      this.setState({
        data: json
      })
    }
    const failure = (err) => {
      this.setState({
        error: err
      })
    }
    if(inJS){
      Model.searchUsersInJS(search, success, failure)
    }else{
      Model.searchUsers(search, success, failure)
    }
    
  }

  componentWillReceiveProps(nextProps) {
    // url = path + params
    let old = this.props.match.url
    let next = nextProps.match.url
    let oldInJS = this.props.inJS
    let nextInJS = nextProps.inJS

    if(nextInJS !== oldInJS){
      this.fetchData(nextInJS, nextProps.match.params.search);
    }

    if(next && next !== old){
      this.fetchData(nextInJS, nextProps.match.params.search);
    }
  }

  componentDidMount() {
    const search = this.props.match.params.search
    this.fetchData(this.props.inJS, search)
  }

  render() {
    const search = this.props.match.params.search
    const { data, error } = this.state;
    if (!data) return null;

    // error state
    if(error) return (
      <div className="app-container">
        <h4 className="rc-box"> 
          {String(error)} 
        </h4>
      </div>
    )

    // empty state
    if(data.total_count == 0){
      return (
        <div className="app-container">
          <h4 className="rc-box">
            Hmm...we found no one
          </h4>
        </div>
      )
    }

    const list = data.items.map(item => (
      <Link to={`/${item.login}`} key={item.id}>
        <li className="rc-list-item">
          <img src={item.avatar_url} />
          <span className="rc-list-item__text">
            {item.login}
          </span>
        </li>
      </Link>
    ))

    return (
      <ul className="rc-list app-container">
        <h4 className="rc-box" style={{
          marginBottom: 0
        }}> Top Results - {search}</h4>
        {list}
      </ul>
    );
  }
}
