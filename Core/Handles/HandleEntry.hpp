#if !defined(_HANDLE_ENTRY_HPP_)
#define _HANDLE_ENTRY_HPP_

class HandleEntry {
    int id;
    HandleType type;
    void* descriptor;

public:
    HandleEntry() noexcept
        : id(-1), type(HandleType::Free), descriptor(nullptr) {
        //
    }

    HandleEntry* Initialize(int id) noexcept {
        this->id = id;
        return this;
    }

    void Free(void) noexcept {
        this->descriptor = nullptr;
        this->type = HandleType::Free;
    }

    void Allocate(HandleType handleType, void* handleDescriptor) noexcept {
        this->type = handleType;
        this->descriptor = handleDescriptor;
    }

    HandleType GetType(void) const noexcept {
        return this->type;
    }

    int GetID(void) const noexcept {
        return this->id;
    }

    template<typename T = void>
    T* GetDescriptor(void) const noexcept {
        return reinterpret_cast<T*>(this->descriptor);
    }

    template<typename T=void>
    void SetDescriptor(T* handleDescriptor) noexcept {
        this->descriptor = reinterpret_cast<void*>(handleDescriptor);
    }

};

#endif // _HANDLE_ENTRY_HPP_
