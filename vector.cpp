#include <iostream>
#include <vector>


using namespace std;
int test() {
    vector<int> vec; 

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << std::endl;

    cout << "vectorµÄ´óÐ¡£º " << vec.size() << std::endl;
    

    return 0;
}

