#include "Form.hpp"

int main() {
    Bureaucrat* hello = new Bureaucrat();
    Bureaucrat* test = new Bureaucrat("grisha", 150);
    Form* form = new Form("myForm", 120, 40);

    std::cout << *test << std::endl;
    test->incrementGrade(149);
    form->beSigned(*test);
    // hello->incrementGrade(30);
    // form->beSigned(*hello);
    std::cout << *form << std::endl;
    delete hello;
    delete test;
    delete form;

    return 0;
}