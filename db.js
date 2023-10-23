require("dotenv").config();

const { express, bodyParser, ejs, mongodb, mongoose,app, encrypt } = require('./setup');

mongoose.connect("mongodb://localhost:27017/userDB");
const userSchema=new mongoose.Schema({
    username:String,
    password:String
})


userSchema.plugin(encrypt,{secret:process.env.SECRET,encryptedFields:["password"] });

const userModel=new mongoose.model("User",userSchema)

module.exports={userSchema,userModel}

