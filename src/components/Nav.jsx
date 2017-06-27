import React, { Component } from 'react';
import { Link } from 'react-router-dom';

export default class Nav extends Component {

  onSearch = (e) => {
    e.preventDefault()
    const val = this.$search.value
    // empty validation
    if(!val) return;

    // redirect
    const {history} = this.props;
    window.$h = history
    history.push(`/search/${val}`)

    // reset
    this.$search.value = ""
    this.$search.blur()
  }

  render() {
    return (
      <div className="rc-navbar app-navbar">
        <Link to="/">
          <h1> Githuber.JS </h1>
        </Link>
        <form className="flex" onSubmit={this.onSearch}> 
          <input  
            type="search" 
            ref={_ => this.$search=_}
            placeholder="Search someone"
          />
          <button className="rc-button">
            Go
          </button>
        </form>
      </div>
    );
  }
}
