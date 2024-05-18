#include <iostream>
#include <fstream>

int main() {
    // Write file
    std::ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Hello, World!";
        outFile.close();
        std::cout << "success write file" << std::endl;
    } else {
        std::cout << "can't write file'" << std::endl;
    }

    // read file
    std::ifstream inFile("example.txt");
    if (inFile.is_open()) {
        std::string line;
        while (getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cout << "Can't read file'" << std::endl;
    }

    return 0;
}

