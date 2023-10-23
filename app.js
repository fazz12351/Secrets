//jshint esversion:6

const { express, bodyParser, ejs, mongodb, mongoose,app,encrypt } = require('./setup');
const {schema,model, userModel}=require("./db")
      
app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({ extended: true }));



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

app.post("/register",async(req,res)=>{
  
    const newUser=new userModel({
        username:req.body.username,
        password:req.body.password 
    })

    newUser.save().then((err)=>{
        res.render("secrets",{

        })
    })

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

app.post("/login",async(req,res)=>{
   const {username,password}=req.body;
   try{
    await userModel.find({username:username}).then((responce)=>{
        if(responce.length>0){
            if(responce[0].password===password){
                res.render("secrets",{

                })
            }
            else{
                res.status(200).json({message:"password is wrong"})
            }
        }
        else{
            res.status(400).json({message:"Couldnt find user in db"})
        }
    })

   }
   catch(err){
    console.error(err)
   }

})





app.listen(3000,()=>{
    console.log("server running on Port 3000")
})