const { express, bodyParser, ejs, mongodb, mongoose,app } = require('./setup');

const userSchema=new mongoose.Schema({
    email:String,
    password:String
})
const userModel=new mongoose.model("User",userSchema)

module.exports={userSchema,userModel}

