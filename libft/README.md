# NewLibft
Just another libft.
Take a look at the demo folder to see what it can achieve.

# NewLibftMo
*NEW*

LibftMO to detect memory leaks.
- Either link with -libftmo or at runtime, and get flashy warnings and errors when your programs leaks or double-free
- You can see the order index of the allocation, its address and its size.
- You can see the call stack from when the malloc was done.
- You can also force the mallocs you want to fail, using environnement variables.
- Test incredible scenarios durring defenses MOUHAHAHAHAHA.
LibftMo does not depend on Libft. Do 'make ftmo\_help' for details.

# Demo files
Folder 'demo' contains sources, not part of the library, but demonstrating the use of some functions.

# Features / Functions
This list is not finished.
Lot of functions are unlisted.

## Libft Project functions
This project contains all the libft functions.

## Macros
- FT_PI: PI with 12 digits (3.14159265359)

## Reading file/input
- get_next_line(): From get_next_line project.
- ft_readline(): Same as get_naxt_line, but also read non-ascii chars, also put the '\n' in the returned string if any, and return the count of bytes read, allowing for better error checking.
- ft_readtonl(): Same as ft_readline, but read char by char until a '\n' is found, and take the maximum lengh of a line, to detect too high input. Return nice error codes.
- ft_pause(): Just a convenient function to pause until a '\n' is provided (cf useful to check leaks).

## ft_printf
- ft_printf(): From the ft_printf project. Handle some bonuses, including %r, colors, rgb/code colors with %y, and others. See demo/ft_printf_demo\*.c for details.
- ft_dprintf(): Same as ft_printf, print to a file descriptor.
- ft_asprintf(): Same as ft_printf, but return as a string instead of printing.
- ft_vprintf(): Same as ft_printf but take a va_list as param.
- ft_vdprintf(): Same as ft_dprintf but take a va_list as param.
- ft_vasprintf(): Same as ft_asprintf but take a va_list as param.

## String
- Contains the classic libft string related functions.
- ft_strfuse(): Lets you join two string, choosing with a third parameter wich will be free in what cases.
- ft_isblank(), ft_iscntrl(), ft_isspace(), ft_isxdigit(), ft_isupper().
- ft_isstrnum().
- ft_strbegins(), ft_strends(): check if a string start or ends with a given string.
- ft_strtolower(), ft_strtoupper().
- ft_strrev().
- ft_strpopnls(): Pop the last '\n's and return how many were removed. For use with ft_readline() and ft_readtonl().
- ft_putstrvec(), ft_dputstrvec(): Print an array of strings.
- Other parsing helpers.
- Others...

## Unicode
This contains some Unicode translation functions. Check the headers/sources for details.

## Chained Lists
This contains classic libft list functions, and also some other additional helpers. See sources for details.

## Conversion
- Contains the classic libft functions.
- ldtoa(): Get a string representation of a long double.
- ft_atoi32check(): like ft_atoi but with error checking.

## Random
- ft_random(): Return a random from /dev/random.
- ft_urandom(): Return an unsigned random from /dev/random.
- ft_llrandom(): Return a long long random from /dev/random.
- ft_ullrandom(): Return an unsigned long long random from /dev/random.
- ft_intsshuffle(): Randomly shuffle a list of ints.
- ft_intsnshuffle(): Shuffle a list of ints by a given number of random swaps.

## Math
- typedefs for int types. Cf, 't_ull' is 'unsigned long long'. See libft_intdefs.h for details.
- ft_min().
- ft_max().
- ft_abs().
- ft_pow().
- ft_sqrt().
- ft_intsize(): Count of chars requiered to represent an integer.
- ft_llpow().
- ft_intsrot(): Rotate an int array.

## Float / Double functions
- ft_ldsign(): Long double sign.
- ft_dclamp: Clamp a double between two values.
- ft_dmix: Linear blend of two values.

## Dynamic arrays
- libft_array.h: Do you know <vector> in c++? it look like that a bit.

## Memory
- ft_memdel0(): same as ft_memdel() but return 0.
- ft_free0: Same.
~- ft_free_vectors: Recursively free pointers (cf can fully free the return of ft_strsplit()).~
- ft_vecdel(): Free vectors recusively, to cleanly free arrays of multiple dimensions.
- ft_memdup(): Same as ft_strdup() but with a chunk of memory.
- ft_memrealloc(): look like realloc().
- "Autofree" functions. Remember the pointers they create, to destroy them in a single call. See sources for details.

## Variadic
- ft_va_as\_<type>() read a va_list without jumping to the next one.
- Some of the ft_printf functions may be used to get informations about a format, a an array of variadics. See sources for details.

## Other
- ft_welcome(), ft_goodbye(): Very useless functions.
- ft_pushpop(): 4 parameters per function is not enough? Then push them and pop them!
- ft_swap<type>: Swap types from pointers.
- Lot of things.

## Files
- ft_listdir(): list entries in a directory.

# Norm/Practices
- Before any other, the 42 norm is used.
- Includes are grouped per projects, from lowest to highest level, then sorted alphabetically.
- Newest functions will alway be commented.
