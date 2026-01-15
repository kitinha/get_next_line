*This project has been created as part of the 42 curriculum by ineguill*

## Description

The **get_next_line** project is a fundamental C programming exercise that implements a function capable of reading a file line-by-line. The main goal is to create a robust utility function that reads any valid file and returns one complete line at a time, handling edge cases such as files without newline characters, empty files, and multiple consecutive reads.

This project teaches essential concepts including:
- Dynamic memory allocation and management
- File I/O operations in C
- Buffer management
- String manipulation
- Static variables for state persistence across function calls

## Instructions

### Compilation

Compile the project using the provided Makefile:

```bash
make
```

This creates a static library `libftprintf.a` containing the compiled object files.

To clean up object files:
```bash
make clean
```

To perform a full clean and rebuild:
```bash
make fclean
make re
```

### Execution

The `get_next_line` function is designed to be linked with your own main program. Include the header file and call the function:

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Configuration

The `BUFFER_SIZE` macro can be customized at compile time (default is 42):

```bash
gcc -D BUFFER_SIZE=1024 -c get_next_line.c
```

## Algorithm Explanation

### Core Approach: Static Remainder Buffer

The implementation uses a **static variable** (`remainder`) to persist data across multiple function calls. This is the key algorithmic choice that makes the solution elegant and efficient.

**How it works:**

1. **Read in chunks**: Data is read from the file descriptor in `BUFFER_SIZE` byte chunks into a temporary buffer.

2. **Accumulate with remainder**: Each chunk is concatenated with the `remainder` (persistent data from previous reads) using `ft_strjoin()`.

3. **Search for newline**: The accumulated string is searched for a newline character (`\n`) using `strchr()`.

4. **Extract line**: Once a newline is found:
   - A new string is allocated and filled with characters up to and including the newline
   - The remainder is updated to contain everything after the newline for the next call

5. **Handle EOF**: When end-of-file is reached:
   - If there's remaining data, it's returned as the final line
   - Subsequent calls return `NULL`

### Why this design?

- **State persistence**: The static remainder eliminates the need for external buffer management or passing state between calls
- **Efficiency**: Data is reused across calls rather than re-read from disk
- **Simplicity**: The interface is clean (just a file descriptor parameter)
- **Memory safety**: Proper allocation and freeing of dynamically created strings

### Time Complexity

- Per call: O(n + m) where n is `BUFFER_SIZE` and m is the line length
- Reading entire file: O(total_bytes)

### Space Complexity

- O(max_line_length) for storing the accumulated line plus remainder buffer

## Resources

### Documentation & References

- [Linux read() system call documentation](https://man7.org/linux/man-pages/man2/read.2.html)
- [C Standard Library string functions](https://en.cppreference.com/w/c/string)
- [Memory management in C (malloc/free)](https://en.cppreference.com/w/c/memory)
- [File I/O in C](https://en.cppreference.com/w/c/io)
- Buffer management patterns in C

### AI Usage

The core algorithm design and implementation logic were developed independently, with AI serving as a verification and documentation tool.

