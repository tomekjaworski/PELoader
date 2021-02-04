#if !defined(_UCS16_HPP_)
#define _UCS16_HPP_

namespace UCS16 {

static constexpr int strlen(const char16_t* str) {
    const char16_t* pstart = str;
    while (*str != 0)
        str++;
    return str - pstart;
}

}

#endif // _UCS16_HPP_
