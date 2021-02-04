#ifndef PELOADER_DOSSTUBHEADERPARSER_HPP
#define PELOADER_DOSSTUBHEADERPARSER_HPP

#include <cstdint>

namespace Core::Loader::Parsers {

class DosStubHeaderParser {
    using DOS_HEADER = Core::Loader::Structures::DOS_EXECUTABLE_STUB_HEADER;
private:
    const DOS_HEADER* pheader;
    ByteMemoryView memory_view;
public:
    DosStubHeaderParser(ByteMemoryView memoryView, std::intptr_t offset = 0)
        : memory_view(memoryView) {
        this->pheader = reinterpret_cast<const DOS_HEADER*>(memoryView.GetData(offset));
    }

    bool IsValid(void) const {
        if (this->pheader->magic != Core::Loader::Structures::DosHeaderMagic)
            return false;

        if (this->pheader->pe.offset == 0)
            return false;

        // todo: inne testy?
        return true;
    }

    std::uint32_t GetNewExecutableOffset(void) const {
        return this->pheader->pe.offset;
    }
};

}

#endif //PELOADER_DOSSTUBHEADERPARSER_HPP
