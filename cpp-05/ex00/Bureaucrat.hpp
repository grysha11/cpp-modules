#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        const std::string getName();
        void setGrade(int grade);
        int getGrade();
        void incrementGrade(int n);
        void decrementGrade(int n);
        Bureaucrat& operator = (const Bureaucrat& other);
        ~Bureaucrat();
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator <<(std::ostream &os, Bureaucrat &i);
#endif