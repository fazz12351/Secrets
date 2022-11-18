const express = require("express")

const bodyParser = require("body-parser")

const app = express();
const ejs = require("ejs")

let events = []
let chosenEvent;
app.use(bodyParser.urlencoded({
    extended: true
}))
app.use(express.static("public"));
app.set("view engine", "ejs")


app.get("/", function (req, res) {
    res.render("home", {
        event: chosenEvent
    })
})


app.post("/suggestion", function (req, res) {
    events.push(req.body);
    res.redirect("/")

})


app.post("/Reveal", function (req, res) {
    let random = Math.floor(Math.random() * events.length);
    console.log(random)

    for (var i = 0; i < events.length; i++) {
        chosenEvent = events[random].text
    }
    console.log(events)
    // console.log(chosenEvent)
    res.redirect("/")
})


app.listen(3000, function () {
    console.log("server is running")
})