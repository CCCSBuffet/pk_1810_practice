# A stupidly complex way to tell if a number is a multiple of three

This program will determine if an input number is a multiple of three. Of course, this can be done simply by checking the value of the number modded with the literal 3. But what fun would that be?

The needlessly complex algorithm is this:

    While the number of digits in a string is larger than one:
        Sum up the value of the digits
        Replace the old value of the string with the 
        string version of the sum.
    If the single digit remaining is 0, 3, 6 or 9 the original was a multiple of three.

For example, test "6792":

* sum of digits in "6792" is 24
* sum of digits in "24" is 6
* "6" is one of the special values

The solution code contains the use of:

* user defined functions
* a range-based for loop (c++11 and later required)
* a char as a small integer
* checking for end-of-file with `getline()` and how to enter an EOF on Mac and Windows

Here is sample output:

    pkivolowitz@jekyl pk_1810_practice % ./a.out
    Enter a number to check (or "quit"): badinput
    Enter a number to check (or "quit"): 6792
    Using a needlessly complex method, 6792 has been shown to be a multiple of  three
    Enter a number to check (or "quit"): 0
    Using a needlessly complex method, 0 has been shown to be a multiple of  three
    Enter a number to check (or "quit"): 6793
    Using a needlessly complex method, 6793 has been shown not to be a  multiple of three
    Enter a number to check (or "quit"): 12345678901234567890
    Using a needlessly complex method, 12345678901234567890 has been shown to  be a multiple of three
    Enter a number to check (or "quit"): 12345678901234567891
    Using a needlessly complex method, 12345678901234567891 has been shown not  to be a multiple of three
    Enter a number to check (or "quit"): quit

## Source code

DO NOT LOOK AT [THIS](./dumb_mod_three.cpp) UNTIL YOU HAVE TRIED TO WRITE THE CODE YOURSELF! With that said, don't feel bad about taking a peek and reading the comments.
