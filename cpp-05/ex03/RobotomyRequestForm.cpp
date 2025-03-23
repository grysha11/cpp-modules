#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::robotomize() const {
    std::cout << "brbrbrbrrrrrr!!..1.1.!!" << std::endl;
    std::srand(std::time(0));

    int random = (std::rand() % 2 + 1);
    if (random == 1) {
        std::cout << this->getTarget() << " Was succesfuly robotomized !!" << std::endl;
    } else {
        std::cout << this->getTarget() << " Unlucky :( robotomization failed" << std::endl;
    }
}

void RobotomyRequestForm::execute(const Bureaucrat& target) const {
    if (!this->getSigned()) {
        throw AForm::UnsignedException();
    } else if (target.getGrade() > this->getToExec()) {
        throw AForm::GradeTooLowExcepetion();
    } else {
        robotomize();
    }
}
