*This project has been created as part of the 42 curriculum by ineguill.*

# get_next_line

## Description

`get_next_line` is a C function that reads and returns one line at a time from a file descriptor. Called in a loop, it lets you read a file line by line, returning `NULL` when there is nothing left to read.

This project is mainly an exercise in static variables and memory management.

**Prototype:** `char *get_next_line(int fd);`

## Instructions

Compile it alongside your own code, setting `BUFFER_SIZE` at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o program
```

Basic usage:

```c
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
```

## Resources

- [read() man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static variables in C — cppreference](https://en.cppreference.com/w/c/language/storage_duration)
- [File descriptors — Wikipedia](https://en.wikipedia.org/wiki/File_descriptor)


### AI Usage

AI assisted with code review, documentation.