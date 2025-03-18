#include "Bureaucrat.hpp"

int main() {
    Bureaucrat* hello = new Bureaucrat();
    Bureaucrat* test = new Bureaucrat("pridurok", 150);

    std::cout << *test << std::endl;
    test->decrementGrade(149);
    delete hello;
    delete test;

    return 0;
}