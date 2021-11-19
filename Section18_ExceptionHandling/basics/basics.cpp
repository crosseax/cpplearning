// Basics

// -Exceptions
// should only be used for synchronized code
// dealing with extraordinary situations
// indicates that an extraordinary situation has been detected or has occurred
// program can deal with the extraordinary situations in a suitable manner
// the situation depends

// -What causes exceptions
// insufficient resources
// missing resources
// invalid operations
// range vilations
// underflows and overflows
// illegal data and many others

// -Exception sage
// when your code handles exceptions
// difficult to do completely


// Terminology

// -Exception
// an object or primitive type that signals that an error has occurred

// -Throwing an exception (raising an exception)
// your code detects that an error has occurred
// the place where the error occurred may not know how to handle the error
// code can throw an exception describing the error to another part of the program that knows how to handle the error

// -Catching an exception (handle the exception)
// code that handles the exception
// may or may not cause the program to terminate


// Key words
// -throw
// throws an exception
// followed by an argument

// -try {code that may throw an exception}
// your place code that may throw an exception in a try block
// if the code throws and exception the try block is exited
// the thrown exception is handled by a catch handler
// if no catch handler exists the program terminates

// -catch (Exception ex) {code to handle}
// code that handles the exception
// can have multiple catch handlers
// may or may not cause the program to terminate
// only execute if an exception is thrown, and the type of the thrown exception matches the parameter in the catch block
