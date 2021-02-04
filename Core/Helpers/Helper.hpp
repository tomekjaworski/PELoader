#ifndef PELOADER_Helper_HPP
#define PELOADER_Helper_HPP


template<auto mask>
constexpr bool IsFlagSet(decltype(mask) value) {
    return (
               static_cast<std::underlying_type_t<decltype(mask)>>(value)
               &
               static_cast<std::underlying_type_t<decltype(mask)>>(mask)
           ) != 0;
}


template<typename T>
bool is_power_of_two(T value) {
    static_assert(std::is_integral<T>::value);
    int_fast32_t counter = 0;
    for (; value > 0; value >>= 1)
        counter += ((value & 1) == 1);
    return counter == 1;
}



#endif // PELOADER_Helper_HPP
