#include "null_pointer.h"

namespace hb {

const NullPointer&
NullPtr(void) {
    static NullPointer np;
    return np;
}

} // namespace hb