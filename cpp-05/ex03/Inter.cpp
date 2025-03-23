#include "Intern.hpp"

Intern::Intern() {

}

Intern::~Intern() {

}

AForm* Intern::createPresident(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

const char* Intern::FormNotExist::what() const throw() {
    return "Non-existing form";
}


AForm* Intern::createForm(const std::string& name, const std::string& target) {
    static const std::string names[3] = {
        "PresidentialPardonForm",
        "RobotomyRequestForm",
        "ShrubberyCreationForm"
    };

    static const FormPointer funcPointers[3] = {
        &Intern::createPresident,
        &Intern::createRobotomy,
        &Intern::createShrubbery
    };

    for (size_t i = 0; i < 3; i++) {
        if (name == names[i]) {
            std::cout << "Intern created form " << name << std::endl;
            return (this->*funcPointers[i])(target);
        }
    }

    throw Intern::FormNotExist();
}
