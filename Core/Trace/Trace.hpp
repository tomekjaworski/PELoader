#if !defined(_TRACE_HPP_)
#define _TRACE_HPP_

#include <cassert>


#if 0
#define TRACE() Trace::Log(__FUNCTION__)
#define TRACEA(__msg, ...) Trace::Log(__FUNCTION__, __msg, __VA_ARGS__)
#else
#define TRACE()
#define TRACEA(__msg, ...)
#endif


#define TRACE_NOT_IMPLEMENTED Trace::NotImplemented(__PRETTY_FUNCTION__)
#define ASSERT(__cond, __message) \
     do { \
        if (!static_cast<bool>(__cond)) Trace::Assert(#__cond, __message, __FILE__, __LINE__, __ASSERT_FUNCTION); \
     } while (false)


namespace Trace {

void NotImplemented(const char* functionName);

void Log(const char* functionName);

void Log(const char* functionName, const char* message, ...);

void Assert(const char* expression, const char* message, const char* fileName, int fileLine, const char* functionName);

}

#endif // _TRACE_HPP_

