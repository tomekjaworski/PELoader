#ifndef PELOADER_WINAPIFUNCTION_H
#define PELOADER_WINAPIFUNCTION_H

#include <type_traits>
#include <algorithm>
#include <string>

class WinApiFunction {
    std::string library_name;
    std::string function_name;
    void* function_address;
public:

    template <typename T>
    WinApiFunction(const std::string& libraryName, const std::string& functionName, T ptr) {
        static_assert(std::is_pointer<T>::value, "ptr has to be a pointer");
        //static_assert(std::is_function<void __attribute__((ms_abi)) (int)>::value, "ptr has to be a function pointer");
        //static_assert(std::is_function<typename std::remove_pointer<T>::type>::value, "ptr has to be a function pointer");

        this->function_address = (void*)ptr;
        this->library_name = libraryName;
        this->function_name = functionName;
        std::transform(std::begin(this->library_name), std::end(this->library_name), std::begin(this->library_name), ::tolower);
    }

    bool Match(const std::string& libraryName, const std::string& functionName) const {
        if (this->library_name == libraryName && this->function_name == functionName)
            return true;
        return false;
    }

    uintptr_t GetProcAddress(void) const {
        return reinterpret_cast<uintptr_t>(this->function_address);
    }

};


#endif //PELOADER_WINAPIFUNCTION_H
