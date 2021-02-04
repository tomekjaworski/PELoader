#ifndef PELOADER_PROCESSCONTROLBLOCKERROR_HPP
#define PELOADER_PROCESSCONTROLBLOCKERROR_HPP

#include <stdexcept>

class ProcessControlBlockError : public std::runtime_error {
    std::string message;
public:
    ProcessControlBlockError(std::string message)
        : std::runtime_error(message), message(std::move(message))
    {
        //
    }
};


#endif //PELOADER_PROCESSCONTROLBLOCKERROR_HPP
