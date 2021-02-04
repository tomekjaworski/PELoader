#if !defined(_HANDLE_TYPE_HPP_)
#define _HANDLE_TYPE_HPP_

enum class HandleType {
    Free = -1,
    CriticalSection = 1,
    File = 2,
    Semaphore = 3,
    Mutex = 4,
    Pipe = 5,
    SharedMemory = 6,
    Socket = 7,

    __min_type = 1,
    __max_type = 255
};

#endif // _HANDLE_TYPE_HPP_

