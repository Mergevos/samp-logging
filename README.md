# samp-logging

[![Mergevos](https://img.shields.io/badge/Mergevos-samp--logging-2f2f2f.svg?style=for-the-badge)](https://github.com/Mergevos/samp-logging)

This library allow you logging your file in 4 different types.

## Installation

Simply install to your project:

```bash
sampctl package install Mergevos/samp-logging
```

Include in your code and begin using the library:

```pawn
#include <logging>
```

## Usage

There're 4 functions. Since the last version has had params for line and file name, this one doesn't. 
File and line are now automatically detected and it returns the full path to the file and line number.

This function logs an debug message.

```c
Log_Debug(const handle[], const message[], Logging_Fields: ...)
```

```
handle[] - Debug handle
message[] - Text to log
... - Other arguments (fields)
```

This function logs an info message.

```c
Log_Info(const handle[], const message[], Logging_Fields: ...)
```

```
handle[] - Debug handle
message[] - Text to log
... - Other arguments (fields)
```

This function logs an error message.

```c
Log_Error(const handle[], const message[], Logging_Fields: ...)
```

```
handle[] - Debug handle
message[] - Text to log
... - Other arguments (fields)
```

This function logs an usage message.

```c
Log_Usage(const handle[], const message[], Logging_Fields: ...)
```

```
handle[] - Debug handle
message[] - Text to log
... - Other arguments (fields)
```


## Testing

To test, configure pawn.json and simply run the package:

```bash
sampctl package run
```
