//jshint esversion:6

const { express, bodyParser, ejs, mongodb, mongoose,app } = require('./setup');
const {schema,model}=require("./db")
      
app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({ extended: true }));
const user1=new model({
    userName:"Fazz12351",
    password:"HelloKitty"
})
user1.save()

app.get("/",async(req,res)=>{
    try{
        res.render("home",{

        })
    }catch(err){
        console.error(err)
    }

})

app.get("/register",async(req,res)=>{
    try{
        res.render("register",{
        })
    }
    catch(err){
        console.err(err)
    }
})

app.get("/login",(req,res)=>{
    try{
        res.render("login",{
        })
    }
    catch(err){
        console.err(err)
    }
})





app.listen(3000,()=>{
    console.log("server running")
})