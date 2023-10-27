
const express = require('express');
const app = express();
const passport = require('passport');
const session = require('express-session');
// ...

app.use(session({
  secret: "Wagwaaannn People",
  resave: false,
  saveUninitialized: false
}));

app.use(passport.initialize());
app.use(passport.session());

const {bodyParser,ejs,mongodb,mongoose,encrypt,} = require("./setup");
const { schema, model, User } = require("./db");


app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({ extended: true }));


app.get("/", async (req, res) => {
  try {
    res.render("home", {});
  } catch (err) {
    console.error(err);
  }
});

app.get("/register", async (req, res) => {
  try {
    res.render("register", {});
  } catch (err) {
    console.err(err);
  }
});


app.post("/register", async (req, res) => {
  User.register({username:req.body.username},req.body.password,(err,user)=>{
    if(err){
      console.log("error")
      res.redirect("/register")
    }
    else{
      passport.authenticate("local")(req,res,()=>{
        res.redirect("/secrets")
      })

    }
  })

});

app.get("/secrets",(req,res)=>{

  if(req.isAuthenticated()){
    res.render("secrets",{
    })
  }
  else{
    res.redirect("/login")
  }
})

app.get("/login", (req, res) => {
  try {
    res.render("login", {});
  } catch (err) {
    console.err(err);
  }
});



app.post("/login", async (req, res) => {
  const user=new User({
    username:req.body.username,
    password:req.body.passport
  })

  req.login(user,(err)=>{
    if(err){
      console.log(err)
    }
    else{
      passport.authenticate("local")(req,res,()=>{
        res.redirect("/secrets")
      })
    }
  })

});

app.listen(3000, () => {
  console.log("server running on Port 3000");
});

app.get("/logout",(req,res)=>{
  req.logout(()=>{
    console.log("logged out")
  })
  
  res.redirect("/")
})