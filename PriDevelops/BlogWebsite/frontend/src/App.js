import logo from './logo.svg';
import './App.css';
import { Routes } from 'react-router-dom';
import Home from './Pages/Home'
import Login from './Pages/Login'
import Register from './Pages/Register'
import CreatePost from './Pages/CreatePost'
import PostDetails from './Pages/PostDetails'
import { Route,Routes } from 'react-router-dom';
function App() {
  return (
   <>
   <Routes>
    <Route exact path ='/' element = {<Home/>}/>
    <Route exact path ='/login' element = {<Login/>}/>
    <Route exact path ='/register' element = {<Register/>}/>
    <Route exact path ='/write' element = {<CreatePost/>}/>
    <Route exact path ='/Post/post/:id' element = {<PostDetails/>}/>
   </Routes>
   </>
  );
}

export default App;
