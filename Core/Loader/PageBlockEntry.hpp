#if !defined(_LOADER_PageBlockEntry_HPP_)
#define _LOADER_PageBlockEntry_HPP_

namespace Core::Loader {

class PageBlockEntry {
    void* address;
    std::size_t count;

public:
    PageBlockEntry(void* firstPageAddress, size_t pageCount)
        : address(firstPageAddress), count(pageCount) {}

    void* GetAddress(void) const {
        return this->address;
    }

    std::size_t GetPageCount(void) const {
        return this->count;
    }
};

}

#endif // _LOADER_PageBlockEntry_HPP_
