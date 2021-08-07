
#include "../include/SimpleLogger.h"

// ========================= public functions =========================

// compare 2 LoggingLevel, is lv1 > lv2 ?
bool isHigherLoggingLv(LoggingLevel lv1, LoggingLevel lv2)
{
    if (int(lv1) > int(lv2))
        return true;
    else return false;
}

// ========================= public functions End =========================




// ========================= SimpleLogger =========================



// ========================= SimpleLogger End =========================