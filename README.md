# ft_printf

`ft_printf` is a function that formats and prints data to the standard output (`STDOUT_FILENO`).
It can be used as a replacement for the standard C library function `printf`.
It is the third project I made in 42 school.

The code is written in C and should work on any platform that supports the standard C library.

### Example of main function

To use `ft_printf` in your program, you need to include the `ft_printf.h` header file and link your program with the `ft_printf` source code. Here's an example program that uses `ft_printf` to print some formatted output:

```c
#include <stdio.h>
#include "libftprintf.h"

int main(void)
{
    int i = 42;
    char *s = "hello, world!";

    ft_printf("i = %d\n", i);
    ft_printf("addr = %p\n", &i);
    ft_printf("hex = %x\n", i);
    ft_printf("s = %s\n", s);
    ft_printf("char = %c\n", 'A');
    
    return (0);
}
```

In this example, `ft_printf` is called with various format specifiers to print different types of data. The function behaves like `printf`, interpreting the format specifiers and printing the corresponding data.

The format specifiers supported by `ft_printf` are:

| Specifier | Type |
| --------- | ---- |
| `%c`      | Character |
| `%s`      | String |
| `%d` or `%i`| Signed decimal integer |
| `%u`      | Unsigned decimal integer |
| `%x`      | Hexadecimal integer |
| `%X`      | Hexadecimal integer (uppercase) |
| `%p`      | Pointer address |

The format specifiers can be modified with various flags:

| Flag | Action | Example
| --------- | ---- | ---- |
| `.`      | Precision | `%.2d` |
| an integer | Field width | `%10s` |
| `-` | Justification to the left | `%-10s` |
| `0` | Zero padding | `%010s` |
| `*` | Take the field width or the precision from an argument | `"%*c", 10, 'a'` |

You can have a look at `man 3 printf` to know the precise meaning and use of each flag.

### Compilation

```bash
make
clang -L. main.c -lftprintf
```
