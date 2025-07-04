//auth_users.js

const express = require('express');
const jwt = require('jsonwebtoken');
let books = require("./booksdb.js");
const regd_users = express.Router();

let users = [];

const isValid = (username)=>{ //returns boolean
//write code to check is the username is valid
// Filter the users array for any user with the same username
    let userswithsamename = users.filter((user) => {
        return user.username === username;
    });
    // Return true if any user with the same username is found, otherwise false
    if (userswithsamename.length > 0) {
        return true;
    } else {
        return false;
    }
}

const authenticatedUser = (username,password)=>{ //returns boolean
//write code to check if username and password match the one we have in records.
// Check if the user with the given username and password exists
// Filter the users array for any user with the same username and password
    let validusers = users.filter((user) => {
        return (user.username === username && user.password === password);
    });
    // Return true if any valid user is found, otherwise false
    if (validusers.length > 0) {
        return true;
    } else {
        return false;
    }

}

//only registered users can login
regd_users.post("/login", (req,res) => {
const username = req.body.username;
const password = req.body.password;

 if (authenticatedUser(username, password)) {
        // Generate JWT access token
        let accessToken = jwt.sign({
            data: password
        }, 'access', { expiresIn: 60*60 });
        // Store access token and username in session
        req.session.authorization = {
            accessToken, username
        }
        return res.status(200).send("User successfully logged in");
    } else {
        return res.status(208).json({ message: "Invalid Login. Check username and password" });
    }
});

// Add a book review
regd_users.put("/auth/review/:isbn", (req, res) => {
const isbn = req.params.isbn;
const review = req.query.review;

// Check if review text was provided
  if (!review) {
    return res.status(400).json({ message: "Review query parameter is required." });
  }

  // Check if book exists
  const book = books[isbn];
  if (!book) {
    return res.status(404).json({ message: `Book with ISBN ${isbn} not found.` });
  }

  // Get the username from the session
  const username = req.session.authorization?.username;
  if (!username) {
    return res.status(401).json({ message: "Unauthorized. Please log in." });
  }

  // Add or update the user's review
  book.reviews[username] = review;

  return res.status(200).json({
    message: "Review successfully added/modified.",
    ISBN: isbn,
    reviews: book.reviews
  });
});

regd_users.delete("/auth/review/:isbn", (req, res) => {
const isbn = req.params.isbn;

  // Check if book exists
  const book = books[isbn];
  if (!book) {
    return res.status(404).json({ message: `Book with ISBN ${isbn} not found.` });
  }

  // Get username from session
  const username = req.session.authorization?.username;
  if (!username) {
    return res.status(401).json({ message: "Unauthorized. Please log in." });
  }

  // Check if the review exists
  if (book.reviews && book.reviews[username]) {
    // Delete the user's review
    delete book.reviews[username];

    return res.status(200).json({
      message: "Review successfully deleted.",
      reviews: book.reviews
    });
  } else {
    return res.status(404).json({ message: "Review by this user not found." });
  }
});

regd_users.post("/logout", (req, res) => {
  // Option 1: destroy the whole session
  req.session.destroy((err) => {
    if (err) {
      return res.status(500).json({ message: "Error logging out." });
    } else {
      return res.status(200).json({ message: "User successfully logged out." });
    }
  });
});



module.exports.authenticated = regd_users;
module.exports.isValid = isValid;
module.exports.users = users;
 