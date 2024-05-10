#include <iostream>
#include <vector>

using namespace std;
int main() {
    std::vector<int> vec; 


    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);


    std::cout << "vec[0]:" << vec[0] << std::endl;
    std::cout << "vec[1]:" << vec[1] << std::endl;
    std::cout << "vec[2]:" << vec[2] << std::endl;


    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    std::cout << "vectorµÄ´óÐ¡£º " << vec.size() << std::endl;

    return 0;
}

