

const { express, bodyParser, ejs, mongodb, mongoose,app, encrypt } = require('./setup');
const session=require('express-session')
const passport=require("passport")
const passportLocalMongoose=require("passport-local-mongoose")

app.use(session({
    secret:"Our Little Secret.",
    resave:false,
    saveUninitialized:false
  
  }))

app.use(passport.initialize())
passport.use(passport.session())
mongoose.connect("mongodb://localhost:27017/userDB");


const userSchema=new mongoose.Schema({
    username:String,
    password:String
})
 
userSchema.plugin(passportLocalMongoose)
const User=new mongoose.model("User",userSchema)
passport.use(User.createStrategy())
passport.serializeUser(User.serializeUser())
passport.deserializeUser(User.deserializeUser())



module.exports={userSchema,User}

