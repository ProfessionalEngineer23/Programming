//To run type: node ExampleAsyncCallBack.js

// This method will be provided as a parameter
function firstCallBackMethod() {
    // Logging a message inside the callback method
    console.log("Inside the first call back method");
}

// Log message before calling setTimeout
console.log("Going to call setTimeout with a delay of 5 seconds");

// Call the function firstCallBackMethod after a delay using setTimeout
setTimeout(firstCallBackMethod, 5000);

/*
setTimeout is a built-in library method which allows you to pass a method which needs to be called on timeout, as aparameter. 
Here firstCallBackMethod is defined and then passed as a parameter to setTimeOut. 
The method will be called after 5 seconds. 
This is called callback.
*/
