express = require("express");
bodyParser = require("body-parser");
ejs = require("ejs");
mongodb = require("mongodb");
mongoose = require("mongoose");
app = express();
encrypt=require("mongoose-encryption")


module.exports = { express, bodyParser, ejs, mongodb, mongoose, app,encrypt };
