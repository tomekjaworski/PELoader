#if !defined(_LOADER_NameHintEntry_HPP_)
#define _LOADER_NameHintEntry_HPP_

#include <cstring>

namespace Core::Loader::Structures::ImportTable {

struct NAME_HINT_ENTRY {
    uint16_t Hint;
    char Name[1];

    uint32_t Size(void) const {
        return ALIGN(sizeof(uint16_t) + std::strlen(Name), 2);
    }
};

}

#endif // _LOADER_NameHintEntry_HPP_
