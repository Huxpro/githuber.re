//https://github.com/rstacruz/nprogress
import LOADING from 'nprogress'

// Model
const Model = {
  _get(api, success, failure){
    LOADING.start();
    fetch(api, {method: 'GET'})
      .then(this.checkStatus)
      .then(resp => resp.json())
      .then(json => success(json))
      .catch(err => failure(err)) 
      .then(_ => LOADING.done())
  },

  handleError(err, failure){
    console.log(err)
    err.response.json()
      .then((data) => {
        if(data.message) failure(data.message)
        failure(err)
      })
  },

  checkStatus(resp){
    if(resp.ok) return resp 
    console.log(resp)
    throw Error(`${resp.status} ${resp.statusText}`)
  },

  fetchUser(username, success, failure){
    let api = `https://api.github.com/users/${username}`
    this._get(api, success, failure)
  },

  searchUsers(search, success, failure){
    // only top 100 + sort by followers
    let api= `https://api.github.com/search/users?q=${search}&sort=followers`
    this._get(api, success, failure)
  },

  searchUsersInJS(search, success, failure){
    // only top 100 + only javascript + sort by followers
    let api= `https://api.github.com/search/users?q=${search}+language:javascript&sort=followers`
    this._get(api, success, failure)
  }



}

export default Model;