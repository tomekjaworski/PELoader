#if !defined(__MEMORY_VIEW_HPP__)
#define __MEMORY_VIEW_HPP__

#include <type_traits>
#include <system_error>


template<typename T>
class MemoryView {
    static_assert(std::is_integral<T>::value, "Wymagana zgodność z is_integral");
    typedef T value_type;

    const void* ptr;
    std::size_t length;

public:
    MemoryView(void) : ptr(nullptr), length(0) {
        //
    }

    MemoryView(const T* ptr, std::size_t length) {
        if (ptr == nullptr)
            throw std::invalid_argument("ptr");
        this->ptr = ptr;
        this->length = length;
    }

    const T* GetData(intptr_t offset) const {
        return reinterpret_cast<const T*>(
            reinterpret_cast<intptr_t>(this->ptr) + offset
            );
    }

    std::size_t GetLength(void) const {
        return this->length;
    }

    bool IsEmpty(void) const {
        return this->length == 0;
    }
};

typedef MemoryView<uint8_t> ByteMemoryView;

#endif // __MEMORY_VIEW_HPP__

