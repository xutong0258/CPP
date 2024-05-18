#include <iostream>
template <class type>
void Swap(type &a, type &b);

int main(int argc, char const *argv[]) {
    using namespace std;
    int i = 10;
    int j = 20;

    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;

    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    return 0;
}

template <class type>
void Swap(type &a, type &b) {
    type temp;
    temp = a;
    a = b;
    b = temp;
}