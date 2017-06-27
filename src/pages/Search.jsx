import React, { Component } from 'react';
import Model from '../model/model'
import { Link } from 'react-router-dom';

export default class Search extends Component {

  state = {
    data: null
  }

  fetchData(search){
    const success = (json)=> {
      this.setState({
        data: json
      })
    }
    const failure = console.log;
    Model.searchUsers(search, success, failure)
  }

  componentWillReceiveProps(nextProps) {
    let old = this.props.match.params.search
    let next = nextProps.match.params.search

    if(next && next !== old){
      this.fetchData(next);
    }
  }

  componentDidMount() {
    const search = this.props.match.params.search
    this.fetchData(search)
  }

  render() {
    const search = this.props.match.params.search
    const { data } = this.state;
    if (!data) return null;

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
