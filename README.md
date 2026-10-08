# ft_printf

A lightweight C implementation of the 42 `ft_printf` project. This repository builds a static library, `libftprintf.a`, that provides a variadic `ft_printf` function with the core formatted-output conversions from the standard `printf` family.

## Features

- Variadic formatted output through `ft_printf`.
- Character, string, signed integer, unsigned integer, hexadecimal, and pointer output.
- Return value equal to the number of characters written.
- C99-style variadic arguments through `<stdarg.h>`.
- No external libraries or runtime dependencies beyond the standard C/POSIX interfaces.

## Supported Conversions

| Conversion | Description |
| --- | --- |
| `%c` | Prints a character |
| `%s` | Prints a string; `NULL` is displayed as `(null)` |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned hexadecimal integer in lowercase |
| `%X` | Prints an unsigned hexadecimal integer in uppercase |
| `%p` | Prints a pointer address with a `0x` prefix |
| `%%` | Prints a literal percent sign |

Width, precision, flags, length modifiers, and dynamic formatting are not
implemented in this version.

## Public API

Include the project header and call `ft_printf` like the standard function:

```c
#include "libftprintf.h"

int written;

written = ft_printf("Name: %s | Score: %d\n", "Alice", 42);
```

The function is declared as:

```c
int ft_printf(const char *input, ...);
```

The return value is the total number of characters written to standard output.

## Build

Build the static library from the `mandatory/` directory:

```bash
cd mandatory
make
```

This creates:

```text
libftprintf.a
```

Available Make targets:

```bash
make          # Build the library
make clean    # Remove object files
make fclean   # Remove object files and libftprintf.a
make re       # Rebuild from scratch
```

## Use the Library

Compile your own program together with the library:

```bash
cc -Wall -Wextra -Werror \
    main.c \
    -I. \
    -L. -lftprintf \
    -o example
```

Example `main.c`:

```c
#include "libftprintf.h"

int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello, printf!");
    ft_printf("Signed: %d / %i\n", -42, 42);
    ft_printf("Unsigned: %u\n", 42u);
    ft_printf("Hex: %x / %X\n", 255u, 255u);
    ft_printf("Pointer: %p\n", (void *)main);
    ft_printf("Percent: %%\n");
    return (0);
}
```

After building `mandatory/libftprintf.a`, compile and run it with:

```bash
cc -Wall -Wextra -Werror main.c -Imandatory \
    mandatory/libftprintf.a -o example
./example
```

## Project Structure

```text
.
├── mandatory/
│   ├── ft_printf.c
│   ├── ft_printf_Cutils.c
│   ├── ft_printf_utils.c
│   ├── libftprintf.h
│   └── Makefile
└── README.md
```

### Implementation Overview

- `ft_printf.c` parses the format string and dispatches each conversion.
- `ft_printf_utils.c` contains signed, unsigned, and hexadecimal number output.
- `ft_printf_Cutils.c` contains character, string, and pointer output helpers.
- `libftprintf.h` exposes the public API and internal helper declarations.

## Requirements

- A C compiler such as GCC or Clang
- GNU Make
- A UNIX-like environment

The project is compiled with:

```text
cc -Wall -Wextra -Werror
```

## Scope

This is a focused implementation of the mandatory `ft_printf` conversion set.
It is intended as a learning project for variadic functions, format parsing,
recursion, file-descriptor output, and static-library creation.
