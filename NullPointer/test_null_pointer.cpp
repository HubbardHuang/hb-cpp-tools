#include <iostream>

#include "null_pointer.h"

class Student {
public:
    int number;
    int age;
};

int
main(void) {
    int* p = hb::NullPtr();
    std::cout << "p = " << p << std::endl;
    int Student::*number_ptr = hb::NullPtr();
    int Student::*age_ptr = &Student::age;
    std::cout << "number_ptr = " << number_ptr << std::endl;
    std::cout << "age_ptr = " << age_ptr << std::endl;
    return 0;
}