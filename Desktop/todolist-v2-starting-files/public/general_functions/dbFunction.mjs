export async function setup(){
    try{
      await mongoose.connect('mongodb://127.0.0.1:27017/myapp').then(()=>{
        console.log("connected to DB")
      })
    }
    catch(err){
      console.error(err)
    }
}

  