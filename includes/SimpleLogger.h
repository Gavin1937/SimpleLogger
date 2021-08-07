
#pragma once

/* ***************************************************************************
 * 
 * Author: Gavin1937
 * GitHub: https://github.com/Gavin1937/SimpleLogger
 * 
 * 
 * A simple C++ program logger library
 * 
 * To use it, #include "./includes/SimpleLogger.h" to your project.
 * And then using the functions under SimpleLogger:: namespace to
 * log your program. Be sure to setLogFilePath() first.
 * 
 * Be aware that Keyword "Error" in this file might conflict with
 * the same keyword in other file
 * 
 * 
 * 
 *                        LoggingLevel Explain
 * 
 * Following levels are all the LoggingLevels. 
 * You can set specific level to logger.
 * When logging messages, only the message with level that is
 * equal or higher than user-defined level will be log.
 * Default level is Notset
 * 
 *     Notset    = 0
 *     Debug     = 1
 *     Info      = 2
 *     Warning   = 3
 *     Error     = 4
 *     Critical  = 5
 * 
 * 
 * 
 *                Message Formatting Rules for SimpleLogger
 *
 * Subtitute following Symbols into a std::string and set LogFormat
 * Default formatting is: [%v][%Y-%M-%D %h:%m:%s,%S]: %l
 * 
 * Symbols:
 *   %v  => LoggingLevels (Notset, Debug, Info, Warning, Error, Critical)
 *   %Y  => Year of logging
 *   %M  => Month of logging
 *   %D  => Day of logging
 *   %h  => Hour of logging
 *   %m  => Minute after Hour of logging
 *   %s  => Second after Minute of logging
 *   %S  => Miliseconds after Second of logging
 *   %l  => Message to be log
 * 
 * ***************************************************************************/


// C++ STL
#include <string>

// class declarations
class SimpleLogger;
enum class LoggingLevel;

// public functions & glob variables

std::string getGlobLoggingFormat();
std::string LoggingLv2Str(LoggingLevel lv);
std::string getFormattedStr(
    LoggingLevel lv,
    const std::string& msg,
    const std::string& format = getGlobLoggingFormat());


// Singleton Logger class definition
class SimpleLogger
{
public:
    // disable copy constructor
    SimpleLogger(const SimpleLogger&) = delete;
    // disable rvalue copy constructor
    SimpleLogger(const SimpleLogger&&) = delete;
    
    // disable assignment
    void operator=(const SimpleLogger&) = delete;
    // disable rvalue assignment
    void operator=(const SimpleLogger&&) = delete;
    
public: // static interface functions
    // Following functions are designed for 
    // calling w/ SimpleLogger:: namespace
    // e.g. SimpleLogger::Debug("message");
    
    // get instance of singleton class
    static SimpleLogger& instance()
    {
        static SimpleLogger inst;
        return inst;
    }
    
    // static logging functions
    static void Debug(const std::string& msg)
    {
        SimpleLogger::instance().logDebug(msg);
    }
    static void Info(const std::string& msg)
    {
        SimpleLogger::instance().logInfo(msg);
    }
    static void Warning(const std::string& msg)
    {
        SimpleLogger::instance().logWarning(msg);
    }
    static void Error(const std::string& msg)
    {
        SimpleLogger::instance().logError(msg);
    }
    static void Critical(const std::string& msg)
    {
        SimpleLogger::instance().logCritical(msg);
    }
    
    // getters
    static std::string LogFilePath()
    {
        return SimpleLogger::instance().getLogFilePath();
    }
    static std::string LogFormat()
    {
        return SimpleLogger::instance().getLogFormat();
    }
    static LoggingLevel LoggingLv()
    {
        return SimpleLogger::instance().getLoggingLv();
    }
    
    // static setters
    static void LogFilePath(const std::string& filepath)
    {
        SimpleLogger::instance().setLogFilePath(filepath);
    }
    static void LogFormat(const std::string& format)
    {
        SimpleLogger::instance().setLogFormat(format);
    }
    static void LoggingLv(LoggingLevel lv)
    {
        SimpleLogger::instance().setLoggingLv(lv);
    }
    
public: // non-static interface functions
    
    // logging functions
    void logDebug(const std::string& msg);
    void logInfo(const std::string& msg);
    void logWarning(const std::string& msg);
    void logError(const std::string& msg);
    void logCritical(const std::string& msg);
    
    // getters
    std::string getLogFilePath() const;
    std::string getLogFormat() const;
    LoggingLevel getLoggingLv() const;
    
    // setters
    void setLogFilePath(const std::string& filepath);
    void setLogFormat(const std::string& format);
    void setLoggingLv(LoggingLevel lv);
    
private:
    // private default constructor
    SimpleLogger();
    
    // helper functions
    void write2LogFile(LoggingLevel lv, const std::string& msg);
    
private:
    std::string m_LogFilePath;
    std::string m_LogFormat;
    LoggingLevel m_CurrentLv;
};

// Logging Level
enum class LoggingLevel {
    Notset    = 0,
    Debug     = 1,
    Info      = 2,
    Warning   = 3,
    Error     = 4,
    Critical  = 5
};
