*This project has been created as part of the 42 curriculum by yaattaou.*

# Libft

## Description

**Libft** is the foundational project of the 42 curriculum. The primary goal is to build a custom C static library (`libft.a`) from scratch, re-implementing key functions from the standard C library (`libc`), developing custom string and memory manipulation utilities, and implementing a singly linked list API.

This project deepens understanding of low-level concepts including dynamic memory allocation, pointer arithmetic, function pointers, and data structure management, providing a reusable library for future 42 projects.

The project is split into three main parts:

1. **Part 1 - Libc functions:** Custom implementations of standard functions from `<ctype.h>`, `<string.h>`, and `<stdlib.h>` using original prototypes and behaviors (prefixed with `ft_`).
2. **Part 2 - Additional functions:** Utility routines not available in standard `libc` (or presented in an alternative form) designed for string parsing, formatting, and file descriptor output.
3. **Part 3 - Linked lists:** A minimal API to create, modify, and manipulate singly linked lists using the `t_list` structure.

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

## Library Contents

### Part 1 - Libc Functions

| Category | Functions |
|----------|-----------|
| **Character checks** | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| **Character conversion** | `ft_toupper`, `ft_tolower` |
| **String length / copy** | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup` |
| **String search / compare** | `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` |
| **Memory management** | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| **Conversion** | `ft_atoi` |

#### Specific Implementation Notes

- `ft_atoi`: Skips leading whitespace (`\t`, `\n`, `\v`, `\f`, `\r`, space), handles one optional `+` or `-` sign, and manages numerical values within standard `int` limits.
- `ft_memmove`: Safely handles overlapping source and destination memory buffers by determining the copy direction.
- `ft_calloc`: Safely allocates zero-initialized memory while checking for multiplication overflow during sizing (`n * size`).
- `ft_strlcpy` / `ft_strlcat`: Follow BSD semantics by guaranteeing NUL-termination when size allows and returning total target string length tried to be created.
- `ft_strnstr`: Returns target string `big` if search string `little` is empty, bounded strictly by search length limit `len`.

### Part 2 - Additional Functions

| Function | Description |
|----------|-------------|
| `ft_substr(s, start, len)` | Allocates and returns a substring from `s` starting at index `start` up to length `len`. |
| `ft_strjoin(s1, s2)` | Allocates and returns a new string concatenating `s1` and `s2`. |
| `ft_strtrim(s1, set)` | Allocates and returns a copy of `s1` with characters specified in `set` removed from beginning and end. |
| `ft_split(s, c)` | Splits `s` into a `NULL`-terminated array of strings using delimiter character `c`. |
| `ft_itoa(n)` | Allocates and returns the string representation of an integer `n` (handles `INT_MIN`). |
| `ft_strmapi(s, f)` | Applies function `f(index, char)` to each character of `s` to create a newly allocated string. |
| `ft_striteri(s, f)` | Applies function `f(index, &char)` to each character of string `s` in place. |
| `ft_putchar_fd(c, fd)` | Writes a single character `c` to the specified file descriptor `fd`. |
| `ft_putstr_fd(s, fd)` | Writes string `s` to the specified file descriptor `fd`. |
| `ft_putendl_fd(s, fd)` | Writes string `s` followed by a newline to the specified file descriptor `fd`. |
| `ft_putnbr_fd(n, fd)` | Writes integer `n` to the specified file descriptor `fd`. |

### Part 3 - Linked-List Functions

| Function | Description |
|----------|-------------|
| `ft_lstnew(content)` | Creates a new list node initialized with `content`. |
| `ft_lstadd_front(lst, new)` | Adds node `new` at the beginning of list `lst`. |
| `ft_lstadd_back(lst, new)` | Adds node `new` at the end of list `lst`. |
| `ft_lstsize(lst)` | Returns the total count of nodes in list `lst`. |
| `ft_lstlast(lst)` | Returns the final node in list `lst`. |
| `ft_lstdelone(lst, del)` | Frees a single node's content using deletion function `del`, then frees the node. |
| `ft_lstclear(lst, del)` | Deletes and frees a node and all successor nodes, setting the list pointer to `NULL`. |
| `ft_lstiter(lst, f)` | Applies function `f` to the content of every node in list `lst`. |
| `ft_lstmap(lst, f, del)` | Maps function `f` over a list to construct a new list, executing `del` on memory allocation failure. |

## Instructions

### Requirements

- A C compiler (`cc`)
- GNU `make`
- `ar` static library tool

### Compilation

Build the library using the provided `Makefile` compiled under `-Wall -Wextra -Werror` flags:

```sh
make        # Compiles mandatory and bonus source files into libft.a
make clean  # Removes object files (.o)
make fclean # Removes object files and static library libft.a
make re     # Rebuilds the static library from scratch
```

### Usage Example

1. Include the header file in your C code:

   ```c
   #include "libft.h"
   ```

2. Sample application (`main.c`):

   ```c
   #include "libft.h"

   int main(void)
   {
       char **words;
       int  i;

       words = ft_split("Libft static library example", ' ');
       if (!words)
           return (1);
       i = 0;
       while (words[i])
       {
           ft_putendl_fd(words[i], 1);
           free(words[i]);
           i++;
       }
       free(words);
       return (0);
   }
   ```

3. Compile your program linking `libft.a`:

   ```sh
   cc -Wall -Wextra -Werror -I. main.c -L. -lft -o program
   ./program
   ```

### Testing & Debugging

Source files can be tested by linking compiled object files against unit tests or custom test suites. Running test builds with memory diagnostic tools such as `valgrind` or compilation flags `-fsanitize=address` is recommended to verify zero memory leaks and catch invalid memory accesses.

## Resources

- Unix system manual pages: `man 3 malloc`, `man 3 memcpy`, `man 3 write`, `man 3 standard`.
- [cppreference C Standard Library Documentation](https://en.cppreference.com/w/c).
- GNU C Library & GNU Make reference manuals.
- Official 42 School Libft Subject specification (v19.3).

### AI Usage

AI assistance was heavily utilized throughout this project. It helped me significantly in understanding the underlying logic, algorithm designs, and theoretical concepts of C functions, pointer manipulation, and memory edge cases (such as overflow handling in `atoi`/`calloc` and memory overlap in `memmove`). Additionally, AI tools were used to help structure and draft this `README.md` file according to 42 curriculum requirements.
