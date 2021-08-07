
#include <iostream>

#include "../include/SimpleLogger.h"

int main()
{
    // std::cout << "Hello World!" << std::endl;
    
    // SimpleLogger::instance()->printMsg("Hello Singleton");
    
    auto& inst = SimpleLogger::instance();
    
    std::cout << &inst << std::endl;

    std::cout << &SimpleLogger::instance() << std::endl;

    auto& inst2 = SimpleLogger::instance();
    
    std::cout << &inst2 << std::endl;
    
    return 0;
}