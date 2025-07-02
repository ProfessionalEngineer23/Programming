// Requiring prompt-sync module to enable synchronous user input
let prompt = require('prompt-sync')();

// Requiring fs module - fs is used for File I/O or filesystem functionality
let fs = require('fs');

// Creating a new Promise to handle file reading
const methCall = new Promise((resolve, reject) => {
    // Prompting the user to input the filename
    let filename = prompt('What is the name of the file?');
    try {
        // Reading the file synchronously
        const data = fs.readFileSync(filename, { encoding: 'utf8', flag: 'r' });
        // Resolving the promise with the file data if read successfully
        resolve(data);
    } catch (err) {
        // Rejecting the promise if an error occurs
        reject(err);
    }
});

// Logging the promise object
console.log(methCall);

// Handling the resolved and rejected states of the promise
methCall.then(
    // Logging the file data if the promise is resolved
    (data) => console.log(data),
    // Logging an error message if the promise is rejected
    (err) => console.log("Error reading file")
);

//==============================================================//
/*Using fs.readFile with explicit Promise wrapping

const prompt = require('prompt-sync')();
const fs = require('fs');

let filename = prompt('What is the name of the file?');

const methCall = new Promise((resolve, reject) => {
  fs.readFile(filename, 'utf8', (err, data) => {
    if (err) {
      reject(err);
    } else {
      resolve(data);
    }
  });
});

// No need to log the promise object
methCall
  .then(data => console.log(data))
  .catch(err => console.error("Error reading file:", err));


*/
//====================================================================//
/* 
> node asyncPromise.js
What is the name of the file?asyncAxiosRequest.js
Promise {
  '// Requiring axios module for making HTTP requests\r\n' +
    "const axios = require('axios').default;\r\n" +
    '\r\n' +
    '// Function to connect to a URL and handle the response\r\n' +
    'const connectToURL = (url) => {\r\n' +
    '    // Sending a GET request to the specified URL using axios\r\n' +
    '    const req = axios.get(url);\r\n' +
    '    // Logging the initial promise object\r\n' +
    '    console.log(req);\r\n' +
    '    // Handling the promise resolution\r\n' +
    '    req.then(resp => {\r\n' +
    '        // Logging the fulfillment message\r\n' +
    '        console.log("Fulfilled");\r\n' +
    '        // Logging the response data\r\n' +
    '        console.log(resp.data);\r\n' +
    '    })\r\n' +
    '    // Handling the promise rejection\r\n' +
    '    .catch(err => {\r\n' +
    '        // Logging the rejection message with the URL\r\n' +
    '        console.log("Rejected for url " + url);\r\n' +
    '        // Logging the error message\r\n' +
    '        console.log(err.toString());\r\n' +
    '    });\r\n' +
    '}\r\n' +
    '\r\n' +
    '// Valid URL\r\n' +
    "connectToURL('https://raw.githubusercontent.com/ibm-developer-skills-network/lkpho-Cloud-applications-with-Node.js-and-React/master/CD220Labs/async_callback/sampleData.json');\r\n" +
    '// Invalid URL\r\n' +
    "connectToURL('https://raw.githubusercontent.com/ibm-developer-skills-network/lkpho-Cloud-applications-with-Node.js-and-React/master/CD220Labs/async_callback/sampleDate.json');\r\n"
}
// Requiring axios module for making HTTP requests
const axios = require('axios').default;

// Function to connect to a URL and handle the response
const connectToURL = (url) => {
    // Sending a GET request to the specified URL using axios
    const req = axios.get(url);
    // Logging the initial promise object
    console.log(req);
    // Handling the promise resolution
    req.then(resp => {
        // Logging the fulfillment message
        console.log("Fulfilled");
        // Logging the response data
        console.log(resp.data);
    })
    // Handling the promise rejection
    .catch(err => {
        // Logging the rejection message with the URL
        console.log("Rejected for url " + url);
        // Logging the error message
        console.log(err.toString());
    });
}

// Valid URL
connectToURL('https://raw.githubusercontent.com/ibm-developer-skills-network/lkpho-Cloud-applications-with-Node.js-and-React/master/CD220Labs/async_callback/sampleData.json');
// Invalid URL
connectToURL('https://raw.githubusercontent.com/ibm-developer-skills-network/lkpho-Cloud-applications-with-Node.js-and-React/master/CD220Labs/async_callback/sampleDate.json');

PS C:\Users\nikit\Documents\GitHub\Programming\Backend_Dev\lkpho-Cloud-applications-with-Node.js-and-React\CD220Labs\async_callback>
*/
//=====================================================================================================================================================================================//
/*
> node asyncPromise.js
What is the name of the file?bob
Promise {
  <rejected> Error: ENOENT: no such file or directory, open 'C:\Users\nikit\Documents\GitHub\Programming\Backend_Dev\lkpho-Cloud-applications-with-Node.js-and-React\CD220Labs\async_callback\bob'
      at Object.readFileSync (node:fs:442:20)
      at C:\Users\nikit\Documents\GitHub\Programming\Backend_Dev\lkpho-Cloud-applications-with-Node.js-and-React\CD220Labs\async_callback\asyncPromise.js:13:25
      at new Promise (<anonymous>)
      at Object.<anonymous> (C:\Users\nikit\Documents\GitHub\Programming\Backend_Dev\lkpho-Cloud-applications-with-Node.js-and-React\CD220Labs\async_callback\asyncPromise.js:8:18)
      at Module._compile (node:internal/modules/cjs/loader:1730:14)
      at Object..js (node:internal/modules/cjs/loader:1895:10)
      at Module.load (node:internal/modules/cjs/loader:1465:32)
      at Function._load (node:internal/modules/cjs/loader:1282:12)
      at TracingChannel.traceSync (node:diagnostics_channel:322:14)
      at wrapModuleLoad (node:internal/modules/cjs/loader:235:24) {
    errno: -4058,
    code: 'ENOENT',
    syscall: 'open',
    path: 'C:\\Users\\nikit\\Documents\\GitHub\\Programming\\Backend_Dev\\lkpho-Cloud-applications-with-Node.js-and-React\\CD220Labs\\async_callback\\bob'
  }
}
Error reading file

ENOENT: Error NO ENTry (i.e., no file or directory found).
*/