#include <iostream>
#include <exception>

int main(int argc, char** argv) {
    try {

    } catch (std::exception &e) {
        std::cerr << "server run error" << e.what() << std::endl;
    }
    return -1;
}