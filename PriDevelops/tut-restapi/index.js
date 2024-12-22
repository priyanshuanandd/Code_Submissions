const express = require("express");
const users = require("./data.json");
const app = express();
const port = 8000;
const mongoose = require("mongoose");
//routes

//what does this file do>

// get /users - list all users
app.use(express.urlencoded({ extended: false }));
// get/users/1  - get user 1
app.get("/api/users", (req, res) => {node 
  return res.json(data);
});
app.post("/api/users", (req, res) => {
  const body = req.body;
  console.log("Body", body);
  return res.json({ status: "pending" });
});

app.listen(port, () => console.log(`chl rha hai at ${port}`));
