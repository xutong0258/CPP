#include <iostream>
#include "helper.h"

int main() {
    int a = 5;
    int b = 3;

    // 调用helper.cpp中定义的addNumbers函数
    int result = addNumbers(a, b);

    std::cout << "The sum of " << a << " and " << b << " is: " << result << std::endl;

    return 0;
}