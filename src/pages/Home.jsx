import React, { Component } from 'react';
import RECO from '../model/reco'
import { Link } from 'react-router-dom';

export default class Home extends Component {
  state = {
    data: RECO
  }

  render() {
    const { data } = this.state;
    if (!data) return null;

    const list = data.items.map(item => (
      <Link to={`/${item.login}`} key={item.login}>
        <li className="rc-list-item">
          <img src={item.avatar_url} alt={item.login} />
          <span className="rc-list-item__text">
            {item.login}
          </span>
        </li>
      </Link>
    ))

    return (
      <div className="rc-list app-container">
        <h4 className="rc-box" style={{
          marginBottom: 0
        }}> RECOMM - JSConfCN 2017</h4>
        {list}
      </div>
    )
  }
}
