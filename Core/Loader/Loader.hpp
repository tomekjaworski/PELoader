#if !defined(_CORE_LOADER_HPP_)
#define _CORE_LOADER_HPP_

// Struktury MS: https://docs.microsoft.com/en-us/windows/win32/debug/imagehlp-structures

//
// Ogólne makra

#if defined(ALIGN)
#error Kolizja nazw
#endif

#define ALIGN(value, __alignment) (((value) + (__alignment - 1)) & ~(__alignment - 1))


//
// Klasy i szablony pomocnicze
#include "MemoryView.hpp"
#include "PageBlockEntry.hpp"

//
// Typy wyliczeniowe oraz flagi
#include "Enums/ImageCharacteristicFlags.hpp"
#include "Enums/MachineType.hpp"
#include "Enums/SectionFlags.hpp"

#include "Enums/PEOptionalHeaderMagic.hpp"
#include "Enums/DllCharacteristicFlags.hpp"
#include "Enums/ImageSubsystem.hpp"

#include "Enums/ImageDataDirectoryIndex.hpp"

//
// Struktury systemowe
#include "Structures/ThreadInformationBlock.hpp"

#include "Structures/DosExecutableStubHeader.hpp"
#include "Structures/PEExecutableHeader.hpp"

constexpr int ImageDataDirectoryEntries = 16;

#include "Structures/ImageDataDirectoryEntry.hpp"
#include "Structures/ImportTable/ImportDirectoryTableHeader.hpp"
#include "Structures/ImportTable/ImportLookupTableEntry.hpp"
#include "Structures/ImportTable/NameHintEntry.hpp"

#include "Structures/PE32OptionalHeader.hpp"
#include "Structures/PE64OptionalHeader.hpp"
#include "Structures/PESectionHeader.hpp"

//
// Parsery struktur systemowych
#include "Parsers/DosStubHeaderParser.hpp"

#endif // _CORE_LOADER_HPP_

