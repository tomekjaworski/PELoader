//
// Created by root on 4/10/21.
//

#include <system_error>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "FileDataProvider.hpp"
#include "Trace/Trace.hpp"
#include <cstdint>

FileDataProvider::FileDataProvider(const std::string& fileName) {
    struct stat st;
    if (stat(fileName.c_str(), &st) != 0)
        throw std::system_error(errno, std::system_category(), "stat");

    this->data = new uint8_t[st.st_size];
    this->length = static_cast<size_t>(st.st_size);

    int fd;
    if ((fd = open(fileName.c_str(), O_RDONLY)) == -1)
        throw std::system_error(errno, std::system_category(), "open");

    ssize_t bytes_read;
    if ((bytes_read = read(fd, this->data, this->length)) == -1)
        throw std::system_error(errno, std::system_category(), "read");

    ASSERT(static_cast<size_t>(bytes_read) == this->length, "Nie odczytano całego pliku; kod do poprawki");
    close(fd);

    this->view = ByteMemoryView(this->data, this->length);
}
