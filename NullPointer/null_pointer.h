#ifndef NULL_POINTER_H
#define NULL_POINTER_H

#include <iostream>

/**
 * If you want to use as usual, open the RELEASE only.
 * If you want to test which function will be called, open the TEST only.
 */
#define NULL_POINTER_RELEASE
// #define NULL_POINTER_TEST

namespace hb {

/**
 * Imitate "nullptr" in cpp.
 */
class NullPointer {
public:
    // Type conversion function for pointer of any type
    // except pointer to data member of class.
    template <typename T>
    operator T*() const;

    // Type conversion function for pointer to data member of class.
    template <typename C, typename T>
    operator T C::*() const;

private:
    // Addressing null pointers is not allowed.
    void operator&();
};

#ifdef NULL_POINTER_RELEASE
template <typename T>
NullPointer::operator T*() const {
    return 0;
}
#endif

#ifdef NULL_POINTER_RELEASE
template <typename C, typename T>
NullPointer::operator T C::*() const {
    return 0;
}
#endif

#ifdef NULL_POINTER_TEST
template <typename T>
NullPointer::operator T*() const {
    std::cout << "NullPointer::operator T*() called." << std::endl;
    return 0;
}
#endif

#ifdef NULL_POINTER_TEST
template <typename C, typename T>
NullPointer::operator T C::*() const {
    std::cout << "NullPointer::operator T C::*() called." << std::endl;
    return 0;
}
#endif

/**
 * API like "nullptr".
 * Return the same object of NullPointer.
 */
const NullPointer& NullPtr(void);

} // namespace hb

#endif