#if !defined(_LOCALE_TYPES_HPP_)
#define _LOCALE_TYPES_HPP_

#include <cstdint>

namespace Core::Locales {

struct ANSI_TO_UCS16_ENTRY {
    BYTE ansi_code;
    char16_t ucs16_code;
};

struct UCS16_TO_ANSI_ENTRY {
    WORD base; // kod bazowy
    SHORT ansi; // kod znaku ANSI lub -1 jeżeli brak mapowania
};

//
//

struct WIDE_CHARACTER_TYPE_ENTRY {
    WORD ucs16_code;
    WORD c1; // Character type information.
    WORD c2; // Bidirectional layout information.
    WORD c3; // Text processing information.
};

struct UCS16_LETTER_CASE_ENTRY {
    WORD base; // kod bazowy
    WORD upper; // kod litery dużej
    WORD lower; // kod litery małej
};

//
//

extern const struct ANSI_TO_UCS16_ENTRY Conversion_Ansi_To_CP1250[256];
extern const struct ANSI_TO_UCS16_ENTRY Conversion_Ansi_To_CP1252[256];
extern const struct UCS16_TO_ANSI_ENTRY Conversion_CP1250_To_Ansi[65536];
extern const struct UCS16_TO_ANSI_ENTRY Conversion_CP1252_To_Ansi[65536];

extern const struct WIDE_CHARACTER_TYPE_ENTRY ucs16_type_table[65536];
extern const struct UCS16_LETTER_CASE_ENTRY ucs16_case_table[65536];
}

#endif // _LOCALE_TYPES_HPP_
