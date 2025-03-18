#include "Form.hpp"

int main() {
    Bureaucrat* hello = new Bureaucrat();
    Bureaucrat* test = new Bureaucrat("pridurok", 150);
    Form* form = new Form("myForm", 120, 40);

    std::cout << *test << std::endl;
    test->decrementGrade(149);
    form->beSigned(*test);
    std::cout << *form << std::endl;
    delete hello;
    delete test;

    return 0;
}