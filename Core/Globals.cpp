#include <csetjmp>

#include "ProcessControlBlock.hpp"
#include "Handles/HandleManager.hpp"
#include "WinAPI/ErrorCodes.hpp"

namespace Core::Globals {

ProcessControlBlock process_control_block;

HandleManager handle_manager;

__thread ErrorCode last_error_code = ErrorCode::NO_ERROR;

DWORD process_exit_code;

std::jmp_buf process_exit_point;

}


