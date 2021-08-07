#include "../includes/SimpleLogger.h"

using LOG = SimpleLogger;

int main()
{
    // setting up log filepath
    LOG::LogFilePath("./Test.log");
    
    // demonstrate logging level with different log methods
    LOG::INFO("Current LoggingLevel = " + GLOB_LOGGINGLV_STR_TABLE[(int)LOG::LoggingLv()]);
    
    LOG::LoggingLv(LoggingLevel::DEBUG);
    LOG::DEBUG("Set LoggingLevel to DEBUG");
    
    LOG::LoggingLv(LoggingLevel::ERROR);
    LOG::ERROR("Set LoggingLevel to ERROR");
    LOG::INFO("Info msg"); // not showing up
    LOG::CRITICAL("Critical msg");
    LOG::DEBUG("Debug msg"); // not showing up
    
    LOG::LoggingLv(LoggingLevel::INFO);
    LOG::INFO("Set Logging Level to INFO");
    LOG::DEBUG("Debug msg"); // not showing up
    LOG::WARNING("Warning msg");
    
    // using SimpleLogger::instance()
    SimpleLogger& inst = SimpleLogger::instance();
    
    // using other getters
    inst.logINFO("LogFilePath is: " + inst.getLogFilePath());
    inst.logINFO("LogFilePath is: " + inst.getLogFilePath());
    inst.logINFO("LoggingLv is: " + GLOB_LOGGINGLV_STR_TABLE[(int)inst.getLoggingLv()]);
    
    // changing log format
    inst.logINFO("Before changing LogFormat");
    inst.setLogFormat("{%v}[%h:%m:%s]: %l");
    inst.logINFO("After change LogFormat");
    
    return 0;
}