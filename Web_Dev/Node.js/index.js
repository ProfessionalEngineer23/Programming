const express = require("express");
const app = express();

app.use(express.urlencoded({ extended: true }));

// Serve the HTML file
app.get("/", (req, res) => {
  res.sendFile(__dirname + "/index.html");
});

// Handle POST request (form submission)
app.post("/", (req, res) => {
  const num1 = Number(req.body.num1);
  const num2 = Number(req.body.num2);
  const result = num1 + num2;

  res.send("Result: " + result);
});

// Start server
app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});
