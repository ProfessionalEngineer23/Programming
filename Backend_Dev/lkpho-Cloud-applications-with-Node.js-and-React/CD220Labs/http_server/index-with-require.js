// Import the HTTP module
const http = require('http');

// Import the 'today' module
const today = require('./today');

// Define the request listener function
const requestListener = function (req, res) {
    res.writeHead(200, { "Content-Type": "text/plain" }); // Set the status code and content type

    let dateVal = today.getDate(); // This is a Luxon DateTime object
    let hour = dateVal.hour; // Extract the hour directly

    // Determine the appropriate greeting based on the current hour
    let greeting = "It is not morning";
    if (hour > 6 && hour < 12) {
        greeting = "Good morning!";
    } else if (hour >= 12 && hour < 18) {
        greeting = "Good afternoon!";
    } else if (hour >= 18 && hour < 21) {
        greeting = "Good evening!";
    } else if (hour >= 21 && hour < 24) {
        greeting = "Good night!";
    }

    // Send the response
    res.end(`Hello, ${greeting}\nCurrent Dublin time: ${dateVal.toFormat("yyyy-MM-dd HH:mm:ss")}`);
};

// Define the port number
const port = 8080;

// Create an HTTP server using the request listener function
const server = http.createServer(requestListener);

// Start the server and listen on the specified port
server.listen(port);
console.log('Server listening on port: ' + port);
