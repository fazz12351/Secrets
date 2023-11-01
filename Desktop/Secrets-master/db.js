

const { express, bodyParser, ejs, mongodb, mongoose,app, encrypt } = require('./setup');
const session=require('express-session')
const passport=require("passport")
const passportLocalMongoose=require("passport-local-mongoose")

mongoose.connect("mongodb://localhost:27017/userDB");

const userSchema=new mongoose.Schema({
    username:String,
    password:String,
    secrets:Array
})
 
userSchema.plugin(passportLocalMongoose)
const User=new mongoose.model("User",userSchema)
passport.use(User.createStrategy())
passport.serializeUser(User.serializeUser())
passport.deserializeUser(User.deserializeUser())



module.exports={userSchema,User}

