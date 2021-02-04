#if !defined(_WINAPI_SYNCHRONIZATION_STRUCTURES_HPP_)
#define _WINAPI_SYNCHRONIZATION_STRUCTURES_HPP_

namespace Core::WinAPI::Synchronization {

//
// POSIXowa implementacja sekcji krytycznych (muteksów) ma dłuższe struktury niż odpowiedniki w WinAPI.
// A ponieważ interfejs zakłada przekazywanie wskaźników do zmiennych lokalnych/niealokowanych, to reżim długości
// tych struktur musi być zachowany. Stąd wskaźniki + alokacja + paddingi.
//

#if defined(CPU32)
struct CRITICAL_SECTION {
    pthread_mutex_t* mutex;
    uint8_t __padding[24 - 4];
};
static_assert(sizeof(CRITICAL_SECTION) == 24);
#else // CPU64
struct CRITICAL_SECTION {
    pthread_mutex_t* mutex;
    uint8_t __padding[40 - 8];
};
static_assert(sizeof(CRITICAL_SECTION) == 40);
#endif

typedef CRITICAL_SECTION* LPCRITICAL_SECTION;

}

#endif // _WINAPI_SYNCHRONIZATION_STRUCTURES_HPP_

