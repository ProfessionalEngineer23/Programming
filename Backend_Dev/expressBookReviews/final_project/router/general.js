//general.js

const express = require('express');
let books = require("./booksdb.js");
let isValid = require("./auth_users.js").isValid;
let users = require("./auth_users.js").users;
const public_users = express.Router();
const axios = require('axios');

// Register a new user
public_users.post("/register", (req,res) => {
    const username = req.body.username;
    const password = req.body.password;
    // Check if both username and password are provided
    if (username && password) {
        // Check if the user does not already exist
        if (!isValid(username)) {
            // Add the new user to the users array
            users.push({"username": username, "password": password});
            return res.status(200).json({message: "User successfully registered. Now you can login"});
        } else {
            return res.status(404).json({message: "User already exists!"});
        }
    }
    // Return error if username or password is missing
    return res.status(404).json({message: "Unable to register user."});
});
/*
// Get the book list available in the shop
public_users.get('/',function (req, res) {
res.send(JSON.stringify(books,null,4));
});
*/
/*
// Get book list using a Promise
public_users.get('/', (req, res) => {
//Promise resolving books array
let getBooksPromise = new Promise((resolve, reject) => {
    resolve(books);
});
// Calling promise
getBooksPromise
    .then((bookData) => {
      res.json(bookData);
    })
    .catch((err) => {
      console.error("Error resolving promise:", err);
      res.status(500).json({ message: "Error retrieving books." });
    });
});
*/

// Get book list using async/await
public_users.get('/', async (req, res) => {
  try {
    // Wrap books retrieval in a Promise (for demonstration)
    const getBooks = () => {
      return new Promise((resolve, reject) => {
        resolve(books);
      });
    };

    const bookData = await getBooks();
    res.json(bookData);
  } catch (error) {
    console.error("Error retrieving books:", error);
    res.status(500).json({ message: "Error retrieving books." });
  }
});

/*
// Get book details based on ISBN
public_users.get('/isbn/:isbn',function (req, res) {
const isbn = req.params.isbn;
    const book = books[isbn];
    if (book) {
        res.json({
      isbn: isbn, book
    });
    } else {
        res.status(404).json({ message: `Book with isbn ${isbn} not found.` });
    }
});
*/

// Get book details by ISBN using Promises
public_users.get('/isbn/:isbn', (req, res) => {
  const isbn = req.params.isbn;

  //Promise that resolves the book
  const getBookPromise = new Promise((resolve, reject) => {
    const book = books[isbn];
    if (book) {
      resolve({
        isbn: isbn,
        book: book
      });
    } else {
      reject(`Book with ISBN ${isbn} not found.`);
    }
  });
  // Calling the Promise
  getBookPromise
    .then((result) => {
      res.json(result);
    })
    .catch((errorMessage) => {
      console.error("Error retrieving book:", errorMessage);
      res.status(404).json({ message: errorMessage });
    });
});

/*
// Get book details based on author
public_users.get('/author/:author',function (req, res) {
  // Extract the author parameter from the request URL
  const author = req.params.author;
  // Filter the books array to find book whose author matches the extracted author parameter
  let filtered_book = Object.entries(books)
  .filter(([id, book]) => book.author === author)
  .map(([id, book]) => ({ id, book }));
  // Send the filtered_book array as the response to the client
  res.send(filtered_book);
});
*/

// Get books by author using async/await
public_users.get('/author-async/:author', async (req, res) => {
  const author = req.params.author;

  // Create a Promise that resolves matching books
  const getBooksByAuthor = () => {
    return new Promise((resolve, reject) => {
      const booksByAuthor = Object.entries(books)
        .filter(([id, book]) => book.author === author)
        .map(([id, book]) => ({ id, book }));

      if (booksByAuthor.length > 0) {
        resolve(booksByAuthor);
      } else {
        reject(`No books found for author '${author}'.`);
      }
    });
  };
  try {
    const result = await getBooksByAuthor();
    res.json(result);
  } catch (errorMessage) {
    console.error("Error retrieving books:", errorMessage);
    res.status(404).json({ message: errorMessage });
  }
});

/*
// Get all books based on title
public_users.get('/title/:title',function (req, res) {
  // Extract the title parameter from the request URL
  const title = req.params.title;
  // Filter the books array to find book whose title matches the extracted title parameter
  let filtered_book2 = Object.entries(books)
  .filter(([id, book]) => book.title === title)
  .map(([id, book]) => ({ id, book }));
  // Send the filtered_book2 array as the response to the client
  res.send(filtered_book2);
});
*/

// Get books by title using Promises
public_users.get('/title-promise/:title', (req, res) => {
  const title = req.params.title;

  // Create a Promise that resolves matching books
  const getBooksByTitle = new Promise((resolve, reject) => {
    const booksByTitle = Object.entries(books)
      .filter(([id, book]) => book.title === title)
      .map(([id, book]) => ({ id, book }));

    if (booksByTitle.length > 0) {
      resolve(booksByTitle);
    } else {
      reject(`No books found with title '${title}'.`);
    }
  });

  // Call the Promise with .then()/.catch()
  getBooksByTitle
    .then((result) => {
      res.json(result);
    })
    .catch((errorMessage) => {
      console.error("Error retrieving books:", errorMessage);
      res.status(404).json({ message: errorMessage });
    });
});

//  Get book review
public_users.get('/review/:isbn',function (req, res) {
const isbn = req.params.isbn;
  const book = books[isbn];
  if (book) {
    res.json(book.reviews);
  } else {
    res.status(404).json({ message: `Book review with ISBN ${isbn} not found.` });
  }
});

module.exports.general = public_users;
 