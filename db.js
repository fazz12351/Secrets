const { express, bodyParser, ejs, mongodb, mongoose,app } = require('./setup');

const schema=new mongoose.Schema({
    userName:String,
    password:String
})
const model=new mongoose.model("user",schema)

module.exports={schema,model}

