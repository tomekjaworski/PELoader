#if !defined(_LOADER_ImportLookupTableEntry_HPP_)
#define _LOADER_ImportLookupTableEntry_HPP_

namespace Core::Loader::Structures::ImportTable {

template<typename T>
struct IMPORT_LOOKUP_TABLE_ENTRY {
private:
    constexpr static T type_size = sizeof(T);
    constexpr static T bits = (type_size << static_cast<T>(3)) - 1;
    constexpr static T msb_mask = (static_cast<T>(1) << bits);

public:
    T data;

    bool IsOrdinal(void) const { return (this->data & msb_mask) != 0; }

    bool IsName(void) const { return (this->data & msb_mask) == 0; }

    uint16_t OrdinalNumber(void) const { return this->data & 0x0000FFFF; }

    uint32_t HintNameRVA(void) const { return this->data & 0x7FFFFFFF; }

    bool End(void) const { return this->data == 0x00000000; }
};

}

#endif // _LOADER_ImportLookupTableEntry_HPP_

