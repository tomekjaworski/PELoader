#ifndef _PELOADER_LoaderError_HPP_
#define _PELOADER_LoaderError_HPP_

#include <stdexcept>

class LoaderError : public std::runtime_error {
    std::string message;
public:
    LoaderError(std::string message)
        : std::runtime_error(message), message(std::move(message))
    {
        //
    }
};


#endif // _PELOADER_LoaderError_HPP_
