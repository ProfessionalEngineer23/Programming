// Requiring axios module for making HTTP requests
const axios = require('axios').default;

// Sending a GET request to the specified URL using axios
const req = axios.get("https://raw.githubusercontent.com/ibm-developer-skills-network/lkpho-Cloud-applications-with-Node.js-and-React/master/CD220Labs/async_callback/courseDetails.json");
// Logging the initial promise object
console.log(req);
// Handling the promise resolution
req.then(resp => {
    // Storing the response data in the courseDetails variable
    let courseDetails = resp.data;
    // Logging the course details as a formatted JSON string
    console.log(JSON.stringify(courseDetails, null, 4));
})
// Handling the promise rejection
.catch(err => {
    // Logging the error message
    console.log(err.toString());
    // This will console log the error with the code. e.g., Error: Request failed with status code 404
});


/*Output:
> node jsonParse.js
Promise { <pending> }
{
    "course": {
        "name": "Cloud Application Development",
        "modules": {
            "module1": {
                "name": "Introduction to Server-Side JavaScript",
                "topics": [
                    "Course Intro",
                    "Module Introduction",
                    "Introduction to Node.js",
                    "Introduction to Server-Side Javascript",
                    "Creating a Web Server with Node.js",
                    "Working with Node.js Modules",
                    "Lab - Introduction to Server-side JavaScript",
                    "Module Summary",
                    "Practice Quiz",
                    "Graded Quiz"
                ]
            },
            "module2": {
                "name": "Asynchronous IO with Callback Programming",
                "topics": [
                    "Module Introduction",
                    "Asynchronous I/O with Callback Programming",
                    "Creating Callback Functions",
                    "Promises",
                    "Working with JSON",
                    "Lab",
                    "Module Summary",
                    "Practice Quiz",
                    "Graded Quiz"
                ]
            },
            "module3": {
                "name": "Express Web Application Framework",
                "topics": [
                    "Module Introduction",
                    "Extending Node.js",
                    "Express Web Application Framework",
                    "Your first Express Web Application",
                    "Routing, Middleware, and Templating",
                    "Lab",
                    "Module Summary",
                    "Practice Quiz",
                    "Graded Quiz"
                ]
            },
            "module4": {
                "name": "Building a Rich Front-End Application using REACT & ES6",
                "topics": [
                    "Module Introduction",
                    "Introduction to ES6",
                    "Introduction to Front End Frameworks and React.JS",
                    "Working with React Components",
                    "Passing Data and States between Components",
                    "Connecting React App to External Services (WIP)",
                    "Lab",
                    "Module Summary",
                    "Practice Quiz",
                    "Graded Quiz"
                ]
            }
        }
    }
}
*/