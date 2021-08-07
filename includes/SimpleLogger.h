
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
 * Be aware that Keyword "ERROR" in this file might conflict with
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
 * Default level is NOTSET
 * 
 *     NOTSET    = 0
 *     DEBUG     = 1
 *     INFO      = 2
 *     WARNING   = 3
 *     ERROR     = 4
 *     CRITICAL  = 5
 * 
 * 
 * 
 *                Message Formatting Rules for SimpleLogger
 *
 * Subtitute following Symbols into a std::string and set LogFormat
 * Default formatting is: [%v][%Y-%M-%D %h:%m:%s,%S]: %l
 * 
 * Symbols:
 *   %v  => LoggingLevels (NOTSET, DEBUG, INFO, WARNING, ERROR, CRITICAL)
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


// undefine "ERROR" for logger
#undef ERROR

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
    // e.g. SimpleLogger::DEBUG("message");
    
    // get instance of singleton class
    static SimpleLogger& instance()
    {
        static SimpleLogger inst;
        return inst;
    }
    
    // static logging functions
    static void DEBUG(const std::string& msg)
    {
        SimpleLogger::instance().logDEBUG(msg);
    }
    static void INFO(const std::string& msg)
    {
        SimpleLogger::instance().logINFO(msg);
    }
    static void WARNING(const std::string& msg)
    {
        SimpleLogger::instance().logWARNING(msg);
    }
    static void ERROR(const std::string& msg)
    {
        SimpleLogger::instance().logERROR(msg);
    }
    static void CRITICAL(const std::string& msg)
    {
        SimpleLogger::instance().logCRITICAL(msg);
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
    void logDEBUG(const std::string& msg);
    void logINFO(const std::string& msg);
    void logWARNING(const std::string& msg);
    void logERROR(const std::string& msg);
    void logCRITICAL(const std::string& msg);
    
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
    NOTSET    = 0,
    DEBUG     = 1,
    INFO      = 2,
    WARNING   = 3,
    ERROR     = 4,
    CRITICAL  = 5
};
