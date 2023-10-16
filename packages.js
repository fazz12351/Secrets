export async function setup() {
  const express = require("express");
  const bodyParser = require("body-parser");
  const ejs = require("ejs");
  const mongodb = require("mongodb");
  const mongoose = require("mongoose");

  const app = express();
  app.set("view engine", "ejs");
  app.use(bodyParser.urlencoded({ extended: true }));
}
