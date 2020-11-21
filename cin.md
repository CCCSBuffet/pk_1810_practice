# SAFE Input From `cin`

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

Again, you have to kill the program manually.

The problem is that when a `cin` fails to convert input to the type you've asked it to, certain error bits inside `cin` get set and they don't get unset. While the error bits are turned on, future attempts to use `cin` fail immediately.

This mini-project is likely too advanced for you to attempt yourself. Instead read the source code located [here](./safe_stream_input.cpp).

Feel free to use this code in your projects when using stream input and *you're interested in ensuring that conversion failures don't hurt you*.
