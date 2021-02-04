#ifndef PELOADER_FILEDATAPROVIDER_HPP
#define PELOADER_FILEDATAPROVIDER_HPP


#include <cstdint>
#include <string>
#include "Loader/MemoryView.hpp"

class FileDataProvider {
private:
    std::uint8_t* data;
    std::size_t length;
    ByteMemoryView view;

public:
    FileDataProvider(const std::string& fileName);

    const ByteMemoryView& GetMemoryView(void) const {
        return this->view;
    }

    ~FileDataProvider() {
        delete[] this->data;
    }
};



#endif //PELOADER_FILEDATAPROVIDER_HPP
