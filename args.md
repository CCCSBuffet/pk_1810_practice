# Learning to use command line arguments

If you are learning C++ using an IDE like `xcode` or `Visual Studio` you may not have used the command line directly as of yet. Being able to use the command line is a valuable job skill and greatly expands the flexibility of programs that you may write. Well, maybe I'm being generous with the `Windows` command line...

Writing programs that can make use of arguments from the command line lies in the ability to customize the operation of the program varying from invocation to invocation.

## `main()`

You may have seen this:

```c++
int main() {
}
```

This is not the whole story however. The complete signature of the `main()` function is this:

```c++
int main(int argc, char * argv[]) {
}
```

The parameters that are passed to `main()` are the arguments specified on the command line when the program is run (prepended with the name of the program being run).

The syntax of `char * argv[]` means that `argv` is an array of *pointers* to characters. *Pointer* is a fancy way of saying *address*. Everything in a running program's memory space has an address. It isn't important to master *pointers* right now. It is worth mentioning that *pointers* seem to scare a lot of people, but when you realize that everything is an *address* they really aren't that scary.

## Source code

Rather than ask you to write a program to enumerate a program's command line arguments, I'll just show you - a couple of ways - with explanation.

[Method 1](./args1.cpp)

[Method 2](./args2.cpp)

Here is a sample of outputs of either program:

```text
hyde pk_1810_practice $> ./a.out
Argument [  0] is ./a.out
hyde pk_1810_practice $> ./a.out pokwrf pokwrfwwrfwrf "powpok pok pok pok"
Argument [  0] is ./a.out
Argument [  1] is pokwrf
Argument [  2] is pokwrfwwrfwrf
Argument [  3] is powpok pok pok pok
hyde pk_1810_practice $>
```

`args1.cpp` shows the basic usage of command line arguments.

`args2.cpp` shows enumerating command line arguments in a more advanced way and serves only as a teaser for your future understanding of scary pointers. Hint: pointers are not scary.

## How you get to command line arguments if you are not using the command line

The project properties in `xcode` and `Visual Studio` allow for adding command line aguments. It isn't as convenient as using a command line, but it can be done and makes testing programs easier. In `xcode`, edit the `Run / Debug` scheme. In `Visual Studio`, edit the project's properties under `Debugging`.

## Common mistake

Things can end in tears (EOT) if you attempt to use an argument that isn't there. So, don't do that. Check `argc` to determine if any particular index into `argv` is valid or not.
