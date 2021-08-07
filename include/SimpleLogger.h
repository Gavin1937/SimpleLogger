
// C++ STL
#include <string>

// class declarations
class SimpleLogger;
enum class LoggingLevel;

// public functions

// compare 2 LoggingLevel, is lv1 > lv2 ?
bool isHigherLoggingLv(LoggingLevel lv1, LoggingLevel lv2);


// Singleton Logger
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
    
    // get instance of singleton class
    static SimpleLogger& instance()
    {
        static SimpleLogger inst;
        return inst;
    }
    
    // logging functions
    
    void DEBUG(const std::string& msg);
    void INFO(const std::string& msg);
    void WARNING(const std::string& msg);
    void ERROR(const std::string& msg);
    void CRITICAL(const std::string& msg);
    
    // setters
    
    void setLogFilePath(const std::string& filepath);
    void setLogFormat(const std::string& format);
    void setLoggingLv(LoggingLevel lv);
    
private:
    // private default constructor
    SimpleLogger() {}
    
private:
    std::string m_LogFilePath;
    std::string m_LogFormat;
    LoggingLevel m_CurrentLv;
};

// Logging Level
enum class LoggingLevel {
    NOTSET = 0,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

