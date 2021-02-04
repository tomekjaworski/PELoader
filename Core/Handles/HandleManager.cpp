#include "HandleManager.hpp"

HandleManager::HandleManager()
    : read_position(0), write_position(0), in_use(0) {
    for (int id = 0; id < HandleManager::MaxHandles; id++) {
        HandleEntry* pentry = entries[id].Initialize(id);
        this->free_entries[id] = pentry;
    }
}

bool HandleManager::ReleaseHandle(int handle) noexcept {
    if (handle < 0 || handle >= HandleManager::MaxHandles)
        return false;

    HandleEntry& entry = this->entries[handle];
    if (entry.GetType() == HandleType::Free)
        return false;

    entry.Free();
    this->free_entries[this->write_position] = &entry;
    this->write_position = (this->write_position + 1) % HandleManager::MaxHandles;
    this->in_use--;
    return true;
}

int HandleManager::AllocateHandle(HandleType handleType, void* handleDescriptor) noexcept {
    if (this->in_use == HandleManager::MaxHandles)
        return -1;

    HandleEntry* pentry = this->free_entries[this->read_position];
    this->read_position = (this->read_position + 1) % HandleManager::MaxHandles;
    this->in_use++;

    pentry->Allocate(handleType, handleDescriptor);
    return pentry->GetID();
}

void* HandleManager::GetDescriptor(int handle) noexcept {
    if (handle < 0 || handle >= HandleManager::MaxHandles)
        return nullptr;
    if (this->entries[handle].GetType() == HandleType::Free)
        return nullptr;

    return this->entries[handle].GetDescriptor();
}

bool HandleManager::SetDescriptor(int handle, void* handleDescriptor) noexcept {
    if (handle < 0 || handle >= HandleManager::MaxHandles)
        return false;
    if (this->entries[handle].GetType() == HandleType::Free)
        return false;

    this->entries[handle].SetDescriptor(handleDescriptor);
    return true;
}
