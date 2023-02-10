#include "ransome.hpp"

int main() {
    rw t;
    t.encode();
    for (int i = 0; i < 3; i++) {
        if (t.login())
        {
            std::cout << "Unlocking Success" << std::endl;
            std::cin.get();
            break;
        }
        else
        {
            std::cout << "Unlocking Failure" << std::endl;
            std::cin.get();
        }
    }
    return 0;
}