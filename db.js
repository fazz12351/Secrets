const { express, bodyParser, ejs, mongodb, mongoose,app, encrypt } = require('./setup');
mongoose.connect("mongodb://localhost:27017/userDB");
const userSchema=new mongoose.Schema({
    username:String,
    password:String
})
const secret="Thisisourlittlesecret"


userSchema.plugin(encrypt,{secret:secret,encryptedFields:["password"] });

const userModel=new mongoose.model("User",userSchema)

module.exports={userSchema,userModel}

