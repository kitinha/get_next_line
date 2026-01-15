*This project has been created as part of the 42 curriculum by ineguill*

## Description

A C function that reads a file line-by-line, returning one complete line per call. It handles edge cases like missing newlines and multiple file descriptors using a static buffer to persist data between calls.

## Instructions

Compile with:
```bash
make
```

Use in your code:
```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

Customize `BUFFER_SIZE` at compile time (default is 42):
```bash
gcc -D BUFFER_SIZE=1024 get_next_line.c
```

## Resources

- [Linux read() documentation](https://man7.org/linux/man-pages/man2/read.2.html)
- [C memory management](https://en.cppreference.com/w/c/memory)
- [C string functions](https://en.cppreference.com/w/c/string)

### AI Usage

AI assisted with code review, documentation.
