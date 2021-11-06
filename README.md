# Get Next Line

![42-Badge](https://img.shields.io/badge/%C3%89cole-42SP-blue)![C-Badge](https://img.shields.io/badge/Language-C-lightgrey)[![42Unlicense](https://img.shields.io/badge/License-42Unlicense-yellowgreen)](https://github.com/gcamerli/42unlicense)

## Description

This project aims to code a function that returns a line, read from a file descriptor.


## Goals

This project will not only add a very convenient function into the library, but it will also require the use of a highly interesting new concept in C programming:
static variables.

## Mandatory

• Calling your function get_next_line in a loop will then allow you to read the text
available on the file descriptor one line at a time until the end of it.

• Your function should return the line that has just been read. If there is nothing
else to read or if an error has occurred it should return NULL.

## Bonus

• To succeed get_next_line with a single static variable.

• To be able to manage multiple file descriptors with your get_next_line.

## Usage

Include the header:
```
#include "get_next_line.h"
```
A file description must be provided to the function.
```
get_next_line(fd);
```

Add the BUFFER flag when compiling the code:
```
-D BUFFER_SIZE=XX
```

## License

This work is published under the terms of [42 Unlicense](https://github.com/gcamerli/42unlicense)
