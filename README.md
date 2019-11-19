# build own lisp

## some notes

### preprocessor
To declare what code the compiler should emit we can wrap it in #ifdef, #else, and #endif preprocessor statements.
These are like an if function that happens before the code is compiled. 
All the contents of the file from the first #ifdef to the next #else are used if the condition is true, otherwise all the contents from the #else to the final #endif are used instead.
