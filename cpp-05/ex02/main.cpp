#include "AForm.hpp"

int main() {
    Bureaucrat* hello = new Bureaucrat();
    Bureaucrat* test = new Bureaucrat("pridurok", 150);
    AForm* AForm = new AForm("myAForm", 120, 40);

    std::cout << *test << std::endl;
    test->decrementGrade(149);
    AForm->beSigned(*test);
    std::cout << *AForm << std::endl;
    delete hello;
    delete test;

    return 0;
}