#if !defined(_BASIC_MACROS_HPP_)
#define _BASIC_MACROS_HPP_

#define RETURN_WITH_ERROR(__return_value, __error_code) \
do{ \
    Core::Globals::last_error_code = (__error_code); \
    return (__return_value); \
} while(false)

#define FORWARD_POINTER(name) typedef void* name;


#endif // _BASIC_MACROS_HPP_

