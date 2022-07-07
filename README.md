# dnd-5e-dice-rolling

This program does basic pseudo-random dice rolling for use in Dungeons and Dragons 5e (5th edition). I'm currently adding to and adapting the code to work with full character sheet support.

## Usage
```c++
../src$ make
../src$ ./main

// Commands are either /roll or /newcharacter
../src$ /newcharacter

// With /roll, you must provide the number of dice
// to be rolled, and the die size. You may also provide
// a modifier, and/or a damage type. For example:

// Only rolling two 10-sided dice without a modifier or damage type:
../src$ /roll 2d10

// Adding a modifier:
../src$ /roll 2d10 + 7

//Adding a modifier and a damage type:
../src$ /roll 2d10 + 7 Necrotic

// The standardized die-sizes are: d4, d6, d8, d10, d12, d20
// However, any die size will work.
```


## License
[GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/)
