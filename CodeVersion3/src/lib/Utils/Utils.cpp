#include "Utils.h"

FaaRay::Error::Error(const char *procName)
{
    std::cout << "[FaaRay Error: " << procName << " ]" << std::endl;
}

FaaRay::Error::Error(const char *procName, const char *msg)
{
    std::cout << "[FaaRay Error: " << procName << " ]" << std::endl;
    if (msg[0] != '\0')
        std::cout << "- " << msg << std::endl;
}

const char * FaaRay::Error::what(const char *msg) const throw ()
{
    std::cout << "- " << msg << std::endl;
    return msg;
}


