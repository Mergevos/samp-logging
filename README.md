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
Log_Debug(const fmt[], const filename[], line, va_args<>)
```

```
fmt[] - Text to log</param>
filename[] - Name of the file being logged</param>
line - Line which is being logged</param>
va_args - Other arguments
```

This function logs an info message.

```c
Log_Info(const fmt[], const filename[], line, va_args<>)
```

```
fmt[] - Text to log</param>
filename[] - Name of the file being logged</param>
line - Line which is being logged</param>
va_args - Other arguments
```

This function logs an error message.

```c
Log_Error(const fmt[], const filename[], line, va_args<>)
```

```
fmt[] - Text to log</param>
filename[] - Name of the file being logged</param>
line - Line which is being logged</param>
va_args - Other arguments
```

This function logs an usage message.

```c
Log_Usage(const fmt[], const filename[], line, va_args<>)
```

```
fmt[] - Text to log</param>
filename[] - Name of the file being logged</param>
line - Line which is being logged</param>
va_args - Other arguments
```

Extended ones are. They use `file[]` param. That param is used to determine a file in which log is being stored. 
```
Log_UsageEx(const fmt[], const filename[], line, const file[], va_args<>)
Log_DebugEx(const fmt[], const filename[], line, const file[], va_args<>)
Log_InfoEx(const fmt[], const filename[], line, const file[], va_args<>)
Log_ErrorEx(const fmt[], const filename[], line, const file[], va_args<>)
```


## Testing

To test, configure pawn.json and simply run the package:

```bash
sampctl package run
```
