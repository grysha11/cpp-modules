#ifndef AForm_HPP
#define AForm_HPP
#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _toSign;
        const int _toExec;
        void setToSign(bool toSign, int burGrade);
    public:
        AForm();
        AForm(const std::string name, const int toSign, const int toExec);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator = (const AForm& other);
        std::string getName() const;
        bool getSigned() const;
        int getToSign() const;
        int getToExec() const;
        void beSigned(const Bureaucrat& bur);
        virtual void execute(const Bureaucrat& executor) const = 0;
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

std::ostream &operator <<(std::ostream &os, const AForm &i);
#endif