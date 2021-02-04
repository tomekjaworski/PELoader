//
// Created by root on 4/5/21.
//

#ifndef PELOADER_PROCESSCONTROLBLOCK_HPP
#define PELOADER_PROCESSCONTROLBLOCK_HPP


#include <string>

class ProcessControlBlock {
    std::string command_line;
    std::u16string wide_command_line;

    std::string image_file_name;
    std::u16string wide_image_file_name;
    std::string arguments;

public:
    ProcessControlBlock();

    void SetImageFileName(std::string imageFileName);
    const std::string& GetAnsiImageFileName(void) noexcept;
    const std::u16string& GetWideImageFileName(void) noexcept;

    void SetCommandLineArguments(std::string arguments);


    const std::string& GetAnsiCommandLine(void) const { return this->command_line; }
    const std::u16string& GetWideCommandLine(void) const { return this->wide_command_line; }

};

#endif //PELOADER_PROCESSCONTROLBLOCK_HPP
