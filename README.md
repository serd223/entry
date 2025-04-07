# Entry Programming Language
`Entry` is a quirky and potentially Turing-complete interpreted joke programming language. Perchance.

This language is *heavily* inspired by [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck).

The implementation is inside the [entry.h](https://github.com/serd223/entry/blob/master/entry.h) file which is an stb style single-header file library.

For a working example, see [example.c](https://github.com/serd223/entry/blob/master/example.c).

## Quick Start
```console
  $ make
  $ ./example
```

## Overview

Just like Brainfuck, `Entry` also has a stack/array of cells and a stack pointer/cursor that you can move around to select different cells.

A cell in `Entry` is a 32 bit signed integer.

The stack consists of 256 cells and the stack pointer will wrap around if you try to make it go out of bounds.
So if you try to decrement it when it is 0, it will be set to 255 and if you try to increment it when it is 255, it will be set to 0.

## Keywords
`Entry` consists of a handful of keywords. Here, we can see the main difference between `Entry` and Brainfuck:

`Entry` doesn't have a built-in looping mechanism. Instead, it offers basic conditional execution and the ability to reverse the order of execution which allows programs to imitate looping behaviour.

```
> : Increments the stack pointer[*]

< : Decrements the stack pointer[*]

add : Increments current cell by 1

dec : Decrements current cell by 1

print : Prints the ascii representation of the current cell (Program returns PRINT_ERROR if current cell is above 255)

input: Gets text input from user and sets the current cell to the value of the inputted character

if : Skips next instruction if the current cell is above 0

nfi : Skips next instruction if the current cell is less than or equal to 0

rev : Reverses the order of execution
[*] 'rev' also reverses the roles of '>' and '<', so if you use 'rev' to reverse the order of execution, '>' will be decrementing the stack pointer
instead of incrementing it. The same also applies to '<'.
```

## Other Implementations
Here are some alternative implementations of `Entry`:
 - [vlang-entry](https://github.com/MrEAZL223/vlang-entry): `Entry` implementation written in [V](https://vlang.io/).
 - [entry_haskell](https://github.com/serd223/entry_haskell): `Entry` implemtation written in [Haskell](https://www.haskell.org/).
