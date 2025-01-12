#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "\t\tMemory adresses are" << std::endl;

    std::cout << "The memory adress of the string variable is:" << std::endl << &str << std::endl;
    std::cout << "The memory adress held by stringPTR is:" << std::endl << stringPTR << std::endl;
    std::cout << "The memory adress held by stringREF is:" << std::endl << &stringREF << std::endl;

    std::cout << "\t\tThe Values are" << std::endl;

    std::cout << "The value of a string is:" << std::endl << str << std::endl;
    std::cout << "The value held by stringPTR:" << std::endl << *stringPTR << std::endl;
    std::cout << "The value held by stringREF:" << std::endl << stringREF << std::endl;

    return 0;
}