//
// Created by root on 4/5/21.
//

#include "ProcessControlBlock.hpp"
#include <algorithm>

#include "ProcessControlBlockError.hpp"

//
// #################
//

ProcessControlBlock::ProcessControlBlock() {
    //
}

void ProcessControlBlock::SetImageFileName(std::string imageFileName) {
    if (!this->image_file_name.empty())
        throw ProcessControlBlockError("Image file has been set previously");

    this->image_file_name = std::move(imageFileName);
    std::u16string wname;
    std::transform(this->image_file_name.begin(), this->image_file_name.end(), std::back_inserter(wname), [](char ch) {
        return static_cast<char16_t>(ch);
    });
    this->wide_image_file_name = std::move(wname);
}

const std::string& ProcessControlBlock::GetAnsiImageFileName(void) noexcept {
    return this->image_file_name;
}

const std::u16string& ProcessControlBlock::GetWideImageFileName(void) noexcept {
    return this->wide_image_file_name;
}


void ProcessControlBlock::SetCommandLineArguments(std::string arguments) {
    if (this->image_file_name.empty())
        throw ProcessControlBlockError("Image file is not set");

    this->arguments = std::move(arguments);
    this->command_line = this->image_file_name + " " + this->arguments;

    std::u16string wcommand_line;
    std::transform(command_line.begin(), command_line.end(), std::back_inserter(wcommand_line), [](char ch) {
        return static_cast<char16_t>(ch);
    });
    this->wide_command_line = std::move(wcommand_line);
}
