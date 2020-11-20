# Practice using `argc` and `argv`

Write a program that will read the contents of a file that you specify on the command line.

Here's an outline:

* Vet the existence of `argv[1]`
* If valid, attempt to use it as a file name in an `ifstream` open.
* If the file is incorrectly opened, don't do the rest.
* Loop while getting lines from the file, printing each one.
* Close the file.

[Here](./readfile.cpp) is the source code to my solution if you want to compare. In addition to showing a use of `argc` and `argv`, the program models three good practices.

1. Only one `return` statement in a function.
2. Use of `perror()`.
3. Use of `cerr`.
4. Setting alternate values to return from the program.
