#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include "../Host/AnsiCodes.h"
#include "Trace.hpp"


namespace Trace {

void NotImplemented(const char* functionName) {
    std::printf(ARED "[NOT IMPLEMENTED] %s\n" ARESET, functionName);
}

void Log(const char* functionName) {
    std::printf("[TRACE] " ARED "%s " ARESET "\n", functionName);
}

void Log(const char* functionName, const char* message, ...) {
    char buffer[1024];

    std::va_list args;
    va_start(args, message);
    std::vsnprintf(buffer, sizeof(buffer), message, args);
    va_end(args);

    std::printf("[TRACE] " ARED "%s" ARESET "(" AYELLOW "%s" ARESET ")\n", functionName, buffer);
}

void Assert(const char* expression, const char* message, const char* fileName, int fileLine, const char* functionName) {
    printf("[ASSERT] %s: assertion failed for '%s' in %s:%s (%s)\n",
           functionName, expression, fileName, fileLine, message);
    std::abort();
}


}

