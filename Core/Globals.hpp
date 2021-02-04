#if !defined(_GLOBALS_HPP_)
#define _GLOBALS_HPP_

#include "ProcessControlBlock.hpp"
#include "Handles/HandleManager.hpp"
#include "WinAPI/ErrorCodes.hpp"


namespace Core::Globals {

extern ProcessControlBlock process_control_block;
extern HandleManager handle_manager;

extern __thread ErrorCode last_error_code;
extern DWORD process_exit_code;

#if defined WANT_PROCESS_EXIT_POINT
extern std::jmp_buf process_exit_point;
#endif

}

#endif // _GLOBALS_HPP_
