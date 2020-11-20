# More Practice with Command Line Args - Print the File Backwards

While we're here, how about getting some practice with `vector`? Modify the program you just wrote to add the lines you read into a `vector` of `string`. Then, enumerate the `vector` backwards, printing out each `string`. More than that, print each *line* backwards.

To reverse a string, you'll need `<algorithm>` and a function called, wait for it, `reverse()`. `reverse()` takes `enumerators` as arguments. Every `string` has some built-in enumerators, `.begin()` and `.end()`. These are precisely the enumerators you need.

There's a bit of a trick here to avoid warnings *and* not cause errors in the loop enumerating the vector backwards. `vector` `.size()` returns a `size_t` which is an `uint64_t` - unsigned. So, if you made a `for` loop that stopped at `counter >= 0` you're in for trouble because an unsigned integer is **always** greater than or equal to zero.

There are several ways to avoid this. The [solution code](./printbackwards.cpp) shows just one of these ways.
