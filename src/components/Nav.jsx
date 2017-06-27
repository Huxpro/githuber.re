import React, { Component } from 'react';
import { Link } from 'react-router-dom';

export default class Nav extends Component {
  onSearch = (e) => {
    e.preventDefault()
    const val = this.$search.value
    // empty validation
    if(!val) return;

    // redirect
    const {history, inJS} = this.props;
    if(inJS){
      history.push(`/searchjs/${val}`)
    }else{
      history.push(`/search/${val}`)
    }
    

    // reset
    this.$search.value = ""
    this.$search.blur()
  }

  render() {
    const {inJS, toggleInJS} = this.props
    const JS = (!inJS) 
      ? <span>.JS</span>
      : <span style={{color: "#ff1744"}}>.JS</span>

    return (
      <div className="rc-navbar app-navbar">
        <h1> 
           <Link to="/">Githuber</Link>
           <span onClick={toggleInJS}>{JS}</span>
        </h1>
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
