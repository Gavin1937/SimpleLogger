#include "../includes/SimpleLogger.h"

using LOG = SimpleLogger;

int main()
{
    // setting up log filepath
    LOG::LogFilePath("./Test.log");
    
    // demonstrate logging level with different log methods
    LOG::Info("Current LoggingLevel = " + LoggingLv2Str(LOG::LoggingLv()));
    
    LOG::LoggingLv(LoggingLevel::Debug);
    LOG::Debug("Set LoggingLevel to Debug");
    
    LOG::LoggingLv(LoggingLevel::Error);
    LOG::Error("Set LoggingLevel to Error");
    LOG::Info("Info msg"); // not showing up
    LOG::Critical("Critical msg");
    LOG::Debug("Debug msg"); // not showing up
    
    LOG::LoggingLv(LoggingLevel::Info);
    LOG::Info("Set Logging Level to Info");
    LOG::Debug("Debug msg"); // not showing up
    LOG::Warning("Warning msg");
    
    // using SimpleLogger::instance()
    SimpleLogger& inst = SimpleLogger::instance();
    
    // using other getters
    inst.logInfo("LogFilePath is: " + inst.getLogFilePath());
    inst.logInfo("LogFilePath is: " + inst.getLogFilePath());
    inst.logInfo("LoggingLv is: " + LoggingLv2Str(inst.getLoggingLv()));
    
    // changing log format
    inst.logInfo("Before changing LogFormat");
    inst.setLogFormat("{%v}[%h:%m:%s]: %l");
    inst.logInfo("After change LogFormat");
    
    return 0;
}