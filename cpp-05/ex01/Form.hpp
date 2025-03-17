#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _toSign;
        const int _toExec;
        void setToSign(bool toSign, int burGrade);
    public:
        Form();
        Form(const std::string name, const int toSign, const int toExec);
        ~Form();
        Form(const Form& other);
        Form& operator = (const Form& other);
        std::string getName() const;
        bool getSigned() const;
        int getToSign() const;
        int getToExec() const;
        void beSigned(const Bureaucrat& bur);
        class GradeTooHighExcepetion : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowExcepetion : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class AlreadySignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator <<(std::ostream &os, const Form &i);
#endif