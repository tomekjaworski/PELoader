#if !defined(_HANDLE_MANAGER_HPP_)
#define _HANDLE_MANAGER_HPP_

#include <vector>
#include <queue>
#include <array>

#include "HandleType.hpp"
#include "HandleEntry.hpp"

class HandleManager {
private:
    constexpr static int MaxHandles = 8;
    std::array<HandleEntry, MaxHandles> entries;
    std::array<HandleEntry*, MaxHandles> free_entries;
    int read_position, write_position;
    int in_use;
public:
    HandleManager();

    ~HandleManager() = default;

    int GetMaxHandleCount(void) const noexcept { return HandleManager::MaxHandles; }

    int AllocateHandle(HandleType handleType, void* handleDescriptor = nullptr) noexcept;

    bool ReleaseHandle(int handle) noexcept;

    void* GetDescriptor(int handle) noexcept;

    bool SetDescriptor(int handle, void* handleDescriptor) noexcept;
};

#endif // _HANDLE_MANAGER_HPP_
