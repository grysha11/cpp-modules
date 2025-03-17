#include "Form.hpp"

Form::Form() : _name("No-name"), _signed(false), _toSign(148), _toExec(148) {

}

Form::Form(const std::string name, const int toSign, const int toExec) : _name(name), _signed(false), _toSign(toSign), _toExec(toExec) {
    if (toSign < 1 || toExec < 1) {
        throw Form::GradeTooLowExcepetion();
    } else if (toSign > 150 || toExec > 150) {
        throw Form::GradeTooHighExcepetion();
    }
}

Form::~Form() {

}

Form::Form(const Form& other) : _name(other._name), _toSign(other._toSign), _toExec(other._toExec) {
    if (this != &other) {
        this->_signed = other._signed;
    }
}

Form& Form::operator = (const Form& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

std::string Form::getName() const {
    return this->_name;
}

bool Form::getSigned() const {
    return this->_signed;
}

int Form::getToSign() const {
    return this->_toSign;
}

int Form::getToExec() const {
    return this->_toExec;
}

void Form::setToSign(bool toSign, int burGrade) {
    if (burGrade > this->_toSign) {
        throw Form::GradeTooLowExcepetion();
    }
    if (this->_signed) {
        throw Form::AlreadySignedException();
    }
    this->_signed = toSign;
}

void Form::beSigned(const Bureaucrat& bur) {
    try {
        this->setToSign(true, bur.getGrade());
        std::cout << bur << "Trying to sign the form xixi" << std::endl;
    } catch (char *msg) {
        std::cerr << bur.getName() << "couldn't sign form because " << msg << std::endl;
    }
}

const char* Form::GradeTooHighExcepetion::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowExcepetion::what() const throw() {
    return "Grade is too low";
}

const char* Form::AlreadySignedException::what() const throw() {
    return "Form is already signed";
}

std::ostream &operator <<(std::ostream &os, const Form &i) {
    os << i.getName() << ", form grade to sign " << i.getToSign() << ", grade to execute " << i.getToExec() << " and form is signed: " << i.getSigned() << "." << std::endl;
    return os;
}
