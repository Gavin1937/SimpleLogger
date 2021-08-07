
```
Author: Gavin1937
GitHub: https://github.com/Gavin1937/SimpleLogger


A simple C++ program logger library

To use it, #include "./includes/SimpleLogger.h" to your project.
And then using the functions under SimpleLogger:: namespace to
log your program. Be sure to setLogFilePath() first.

Be aware that Keyword "Error" in this file might conflict with
the same keyword in other file



                       LoggingLevel Explain

Following levels are all the LoggingLevels. 
You can set specific level to logger.
When logging messages, only the message with level that is
equal or higher than user-defined level will be log.
Default level is Notset

    Notset    = 0
    Debug     = 1
    Info      = 2
    Warning   = 3
    Error     = 4
    Critical  = 5



               Message Formatting Rules for SimpleLogger
 *
Subtitute following Symbols into a std::string and set LogFormat
Default formatting is: [%v][%Y-%M-%D %h:%m:%s,%S]: %l

Symbols:
  %v  => LoggingLevels (Notset, Debug, Info, Warning, Error, Critical)
  %Y  => Year of logging
  %M  => Month of logging
  %D  => Day of logging
  %h  => Hour of logging
  %m  => Minute after Hour of logging
  %s  => Second after Minute of logging
  %S  => Miliseconds after Second of logging
  %l  => Message to be log

```