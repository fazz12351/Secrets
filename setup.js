express = require("express");
bodyParser = require("body-parser");
ejs = require("ejs");
mongodb = require("mongodb");
mongoose = require("mongoose");
app = express();
mongoose.connect("mongodb://localhost:27017/userDB");

module.exports = { express, bodyParser, ejs, mongodb, mongoose, app };
