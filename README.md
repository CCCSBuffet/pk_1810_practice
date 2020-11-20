# CSC1810 Practice Programs

## Specifications are skimpy

The projects described and contained here are meant for fun practice. You won't find these specified to the usual degree.

## Projects

* [Single Star](./single_star.md)
* [Cylon Effect](./cylon.md)
* [Walkies](./walkies.md)
* [Fizzle](./fizzle.md)
* [Stupid Multiple of Three](./stupid.md)
* [Learning to Use Command Line Arguments](./args.md) - just lessons
* [Practice Using Command Line Arguments](./args_practice.md)

## Follow up - print the file backwards

While we're here, how about getting some practice with `vector`? Modify the program you just wrote to add the lines you read into a `vector` of `string`. Then, enumerate the `vector` backwards, printing out each `string`. More than that, print each *line* backwards.

To reverse a string, you'll need `<algorithm>` and a function called, wait for it, `reverse()`. `reverse()` takes `enumerators` as arguments. Every `string` has some built-in enumerators, `.begin()` and `.end()`. These are precisely the enumerators you need.

There's a bit of a trick here to avoid warnings *and* not cause errors in the loop enumerating the vector backwards. `vector` `.size()` returns a `size_t` which is an `uint64_t` - unsigned. So, if you made a `for` loop that stopped at `counter >= 0` you're in for trouble because an unsigned integer is **always** greater than or equal to zero.

There are several ways to avoid this. The [solution code](./printbackwards.cpp) shows just one of these ways.

## SAFE input from `cin`

Try this program:

```c++
#include <iostream>

using namespace std;

int main() {
	int i = 0;
	while (i != 10) {
		cout << "Enter a number: ";
		cin >> i;
	}
	return 0;
}
```

What could possibly go wrong? This program will plainly loop until you enter 10.

```text
hyde pk_1810_practice $> ./a.out
Enter a number: 5
Enter a number: 6
Enter a number: 9
Enter a number: 10
hyde pk_1810_practice $>
```

Run the program again, and enter `a` instead of a number. Prepare to terminate the program with extraordinary means.

How about this, create a text file (`numbers.txt`) with perfectly good input. Such as:

```text
1
2
3
4
```

Then run the program using redirected input.

```text
hyde pk_1810_practice $> ./a.out < numbers.txt
```

Again, you have to kill the program.

The problem is that when a `cin` fails to convert input to the type you've asked it to, certain error bits inside `cin` get set and they don't get unset. While the error bits are turned on, future attempts to use `cin` fail immediately.

This mini-project is likely too advanced for you to attempt yourself. Instead read the source code located [here](./safe_stream_input.cpp).

Feel free to use this code in your projects when using stream input and *you're interested in ensuring that conversion failures don't hurt you*.

## Problem 1 from [codewars.com](https://www.codewars.com)

Inspired by a `kata` on codewars.com...

Write a program that prompts for a string. If the string is "quit", exit the program. Otherwise split the string into a vector of strings each containing two letters. If there are an odd number of characters in the string, return the last character joined with '_'.

### Sample output 

```text
pkivolowitz@jekyl pk_1810_practice % ./a.out
Enter a string (or "quit"): mhutaq
mh
ut
aq
Enter a string (or "quit"): mi7bq
mi
7b
q_
Enter a string (or "quit"): quit
pkivolowitz@jekyl pk_1810_practice %
```

### Source code

The source code is [here](./pairs.cpp), but you should try to write this yourself.

## Problem 2 from [codewars.com](https://www.codewars.com)

Inspired by a kata on codewars.com...

Write a program that determines whether or not a number is a [Narcissistic Number](https://en.wikipedia.org/wiki/Narcissistic_number). 

From codewars.com, "A Narcissistic Number is a positive number which is the sum of its own digits, each raised to the power of the number of digits in a given base. In this Kata, we will restrict ourselves to decimal (base 10)."

codewars.com provides an example:

153 is a narcissistic number because it has 3 digits and each individual digit raised to the 3rd power, added together, equals the original number. As shown next:

```text
1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
```

The codewars.com project creates just one function, and promises that only valid input will be passed to it. Here, you'll write a full program and must screen out and otherwise handle bad input. This might be a good place to practice with `SafeStreamINput()`.

### Source code

The source code is [here](./narc.cpp), but you should try to write this yourself.

