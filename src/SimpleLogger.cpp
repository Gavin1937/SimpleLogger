
#include "../includes/SimpleLogger.h"

// C++ STL
#include <chrono>
#include <ctime>
#include <fstream>
#include <locale>


// ========================= public functions & glob variables =========================

namespace {
    // compare 2 LoggingLevel, is lv1 <= lv2 ?
    bool isLowerEqLoggingLv(LoggingLevel lv1, LoggingLevel lv2)
    {
        if (int(lv1) <= int(lv2))
            return true;
        else return false;
    }
}

std::string getGlobLoggingFormat()
{
    const static std::string LOGGING_FORMAT("[%v][%Y-%M-%D %h:%m:%s,%S]: %l");
    return LOGGING_FORMAT;
}
std::string LoggingLv2Str(LoggingLevel lv)
{
    const static std::string LOGGINGLV_STR_TABLE[6] = {
        "NOTSET",
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
        "CRITICAL"
    };
    return LOGGINGLV_STR_TABLE[int(lv)];
}
std::string getFormattedStr(
    LoggingLevel lv,
    const std::string& msg,
    const std::string& format)
{
    // get current system time
    int64_t rawtime_mili = 
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();
    time_t rawtime = time(NULL);
    tm tm_obj;
#ifdef WIN32
    localtime_s(&tm_obj, &rawtime);
#else
    localtime_r(&rawtime, &tm_obj);
#endif
    
    // get parameter strings
    std::string year = std::to_string(tm_obj.tm_year + 1900);
    std::string month = std::to_string(tm_obj.tm_mon + 1);
    std::string day = std::to_string(tm_obj.tm_mday);
    std::string hour = std::to_string(tm_obj.tm_hour);
    std::string min = std::to_string(tm_obj.tm_min);
    std::string sec = std::to_string(tm_obj.tm_sec);
    std::string mili_sec = std::to_string(rawtime_mili-((rawtime_mili/1000)*1000));
    
    // subsitute all parameters into formatted string
    std::string output(format);
    size_t pos = 0;
    while (pos != std::string::npos) {
        pos = output.find('%', pos);
        switch (output[pos+1])
        {
        case 'v':
            output.replace(pos, 2, LoggingLv2Str(lv));
            break;
        case 'Y':
            output.replace(pos, 2, year);
            break;
        case 'M':
            output.replace(pos, 2, month);
            break;
        case 'D':
            output.replace(pos, 2, day);
            break;
        case 'h':
            output.replace(pos, 2, hour);
            break;
        case 'm':
            output.replace(pos, 2, min);
            break;
        case 's':
            output.replace(pos, 2, sec);
            break;
        case 'S':
            output.replace(pos, 2, mili_sec);
            break;
        case 'l':
            output.replace(pos, 2, msg);
            break;
        }
    }
    
    return output;
}


// ========================= public functions End =========================




// ========================= SimpleLogger =========================

// logging functions
void SimpleLogger::logDEBUG(const std::string& msg)
{
    // only log msg if m_CurrentLv <= DEBUG
    if (isLowerEqLoggingLv(m_CurrentLv, LoggingLevel::DEBUG))
        write2LogFile(LoggingLevel::DEBUG, msg);
}
void SimpleLogger::logINFO(const std::string& msg)
{
    // only log msg if m_CurrentLv <= INFO
    if (isLowerEqLoggingLv(m_CurrentLv, LoggingLevel::INFO))
        write2LogFile(LoggingLevel::INFO, msg);
}
void SimpleLogger::logWARNING(const std::string& msg)
{
    // only log msg if m_CurrentLv <= WARNING
    if (isLowerEqLoggingLv(m_CurrentLv, LoggingLevel::WARNING))
        write2LogFile(LoggingLevel::WARNING, msg);
}
void SimpleLogger::logERROR(const std::string& msg)
{
    // only log msg if m_CurrentLv <= ERROR
    if (isLowerEqLoggingLv(m_CurrentLv, LoggingLevel::ERROR))
        write2LogFile(LoggingLevel::ERROR, msg);
}
void SimpleLogger::logCRITICAL(const std::string& msg)
{
    // only log msg if m_CurrentLv <= CRITICAL
    if (isLowerEqLoggingLv(m_CurrentLv, LoggingLevel::CRITICAL))
        write2LogFile(LoggingLevel::CRITICAL, msg);
}

// getters
std::string SimpleLogger::getLogFilePath() const
{
    return m_LogFilePath;
}
std::string SimpleLogger::getLogFormat() const
{
    return m_LogFormat;
}
LoggingLevel SimpleLogger::getLoggingLv() const
{
    return m_CurrentLv;
}

// setters
void SimpleLogger::setLogFilePath(const std::string& filepath)
{
    m_LogFilePath.assign(filepath);
}
void SimpleLogger::setLogFormat(const std::string& format)
{
    m_LogFormat.assign(format);
}
void SimpleLogger::setLoggingLv(LoggingLevel lv)
{
    m_CurrentLv = lv;
}

// private: 

// private default constructor
SimpleLogger::SimpleLogger() 
    : m_LogFilePath(""),
    m_LogFormat(getGlobLoggingFormat()),
    m_CurrentLv(LoggingLevel::NOTSET)
{}

// helper functions
void SimpleLogger::write2LogFile(LoggingLevel lv, const std::string& msg)
{
    std::ofstream log(m_LogFilePath, std::ios::app);
    log << getFormattedStr(lv, msg, m_LogFormat) << '\n';
    log.close();
}

// ========================= SimpleLogger End =========================