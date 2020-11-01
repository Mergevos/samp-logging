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

There're 4 functions and 4 extended ones. 

This function logsan info message.

```c
Log_Debug(const handle[], const message[], const filename[], line, va_args<>)
```

```
handle[] - Debug handle
message[] - Text to log
filename[] - Name of the file being logged
line - Line which is being logged
va_args - Other arguments
```

This function logs an info message.

```c
Log_Info(const handle[], const message[], const filename[], line, va_args<>)
```

```
handle[] - Debug handle
message[] - Text to log
filename[] - Name of the file being logged
line - Line which is being logged
va_args - Other arguments
```

This function logs an error message.

```c
Log_Error(const handle[], const message[], const filename[], line, va_args<>)
```

```
handle[] - Debug handle
message[] - Text to log
filename[] - Name of the file being logged
line - Line which is being logged
va_args - Other arguments
```

This function logs an usage message.

```c
Log_Usage(const handle[], const message[], const filename[], line, va_args<>)
```

```
handle[] - Debug handle
message[] - Text to log
filename[] - Name of the file being logged
line - Line which is being logged
va_args - Other arguments
```


## Testing

To test, configure pawn.json and simply run the package:

```bash
sampctl package run
```
