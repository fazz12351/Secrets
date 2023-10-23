express = require("express");
bodyParser = require("body-parser");
ejs = require("ejs");
mongodb = require("mongodb");
mongoose = require("mongoose");
app = express();
encrypt=require("mongoose-encryption")
md5=require("md5")


module.exports = { express, bodyParser, ejs, mongodb, mongoose, app,encrypt,md5 };
