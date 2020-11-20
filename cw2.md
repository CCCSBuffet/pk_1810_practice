# Problem 2 from [codewars.com](https://www.codewars.com)

Inspired by a kata on codewars.com...

Write a program that determines whether or not a number is a [Narcissistic Number](https://en.wikipedia.org/wiki/Narcissistic_number).

From codewars.com, "A Narcissistic Number is a positive number which is the sum of its own digits, each raised to the power of the number of digits in a given base. In this Kata, we will restrict ourselves to decimal (base 10)."

codewars.com provides an example:

153 is a narcissistic number because it has 3 digits and each individual digit raised to the 3rd power, added together, equals the original number. As shown next:

```text
1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
```

The codewars.com project creates just one function, and promises that only valid input will be passed to it. Here, you'll write a full program and must screen out and otherwise handle bad input. This might be a good place to practice with `SafeStreamINput()`.

## Source code

The source code is [here](./narc.cpp), but you should try to write this yourself.
