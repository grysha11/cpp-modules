#include "Indentify.hpp"

int main() {
    srand(time(0));
    for (int i = 0; i < 5; ++i) {
        std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;
        Base* ptr = Indentify::generate();

        std::cout << "Pointer identification: ";
        Indentify::indentify(ptr);

        std::cout << "Reference identification: ";
        Indentify::indentify(*ptr);

        delete ptr;
    }

    return 0;
}