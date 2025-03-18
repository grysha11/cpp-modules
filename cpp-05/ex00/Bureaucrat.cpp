#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("No-name"), _grade(150) {
    std::cout << this->_name << " Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
    if (this != &other) {
        this->_grade = other._grade;
    }
}

const std::string Bureaucrat::getName() const {
    return this->_name;
}

void Bureaucrat::setGrade(int grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade = grade;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade(int n) {
    if (this->_grade + n > 150) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade += n;
}

void Bureaucrat::decrementGrade(int n) {
    if (this->_grade - n < 1) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade -= n;
}


Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    std::cout << this->_name << " Copy assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << this->_name << " Default destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream &operator <<(std::ostream &os, const Bureaucrat &i) {
    os << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
    return os;
}