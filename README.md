# Entry Programming Language
`Entry` is a quirky, freaky, based and potentially Turing-complete interpreted programming language. Perchance.

## Language Reference

> = move stack pointer to the right (goes back to 0 if above 255)
< = move stack pointer to the left (goes up to 255 if less than 0)
add = increment current stack cell by 1
dec = decrement current stack cell by 1
print = print the ascii representation of the current stack cell (returns WTF HEADACHE if current stack cell is above 255)
ftext = get text input from user and set the current stack cell to the value of the inputted character
if = skip next instruction if the value of the current stack cell is above 0
nfi = skip next instruction if the value of the current stack cell is 0
rev = reverse the order of execution

## Quick Start
```console
  $ make
  $ ./example
```
