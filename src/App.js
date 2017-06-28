import React, {PureComponent} from 'react';
import { 
  BrowserRouter as Router,
  withRouter,
  Switch,
  Route
} from 'react-router-dom';

// import styles 
import './style/rc.css';
import './style/app.css';
import './style/nprogress.css';

// import pages
import Home from './pages/Home';
import User from './pages/User';
import Search from './pages/Search';
import NotFound from './pages/NotFound';

// import components
import Nav from './components/Nav';

/**
 * <App store={store}/>
 * @PureComponent 
 * 
 * Stateless functional component under PureComponent are
 * considered PureComponent as well.
 * https://github.com/facebook/react/pull/6914
 */
class App extends PureComponent{

  render(){
    const NavWithRouter = withRouter(Nav)
    return(
      <Router>
        <div className="rc-typography">
          <NavWithRouter/>
          <Switch>
            <Route exact path="/" component={Home} />
            <Route path="/search/:search" component={Search}/>
            <Route path="/:username" component={User}/>
            <Route component={NotFound}/>
          </Switch>
        </div>
      </Router>
    )
  }
}

window.__App__ = App;
export default App;