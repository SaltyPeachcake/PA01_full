#include <iostream>
#include "DSString.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    DSString str01;
    DSString str02, str03;

    str03 = str01 + str02;
    str03.operator=(str01.operator+(str02));

    str03.getLength();

    DSString* str01ptr = &str01;
    str01ptr->getLength();
    (*str01ptr).getLength();

    return 0;
}
