#include "AForm.hpp"

AForm::AForm() : _name("No-name"), _signed(false), _toSign(148), _toExec(148) {

}

AForm::AForm(const std::string name, const int toSign, const int toExec) : _name(name), _signed(false), _toSign(toSign), _toExec(toExec) {
    if (toSign < 1 || toExec < 1) {
        throw AForm::GradeTooLowExcepetion();
    } else if (toSign > 150 || toExec > 150) {
        throw AForm::GradeTooHighExcepetion();
    }
}

AForm::~AForm() {

}

AForm::AForm(const AForm& other) : _name(other._name), _toSign(other._toSign), _toExec(other._toExec) {
    if (this != &other) {
        this->_signed = other._signed;
    }
}

AForm& AForm::operator = (const AForm& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getSigned() const {
    return this->_signed;
}

int AForm::getToSign() const {
    return this->_toSign;
}

int AForm::getToExec() const {
    return this->_toExec;
}

void AForm::setToSign(bool toSign, int burGrade) {
    if (burGrade > this->_toSign) {
        throw AForm::GradeTooLowExcepetion();
    }
    if (this->_signed) {
        throw AForm::AlreadySignedException();
    }
    this->_signed = toSign;
}

void AForm::beSigned(const Bureaucrat& bur) {
    try {
        this->setToSign(true, bur.getGrade());
        std::cout << bur.getName() << " Trying to sign the AForm xixi" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << bur.getName() << "couldn't sign AForm because " << e.what() << std::endl;
        return ;
    }
    std::cout << this->getName() << " AForm was signed by " << bur.getName() << "." << std::endl;
}

const char* AForm::GradeTooHighExcepetion::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowExcepetion::what() const throw() {
    return "Grade is too low";
}

const char* AForm::AlreadySignedException::what() const throw() {
    return "AForm is already signed";
}

std::ostream &operator <<(std::ostream &os, const AForm &i) {
    os << i.getName() << ", AForm grade to sign " << i.getToSign() << ", grade to execute " << i.getToExec() << " and AForm is signed: " << i.getSigned() << ".";
    return os;
}
