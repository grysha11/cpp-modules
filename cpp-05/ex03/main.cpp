#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat mid("Mid", 70);
        Bureaucrat internB("Intern", 150);

        Intern someIntern;

        std::cout << "\n--- Intern creates forms ---" << std::endl;
        AForm* shrub = someIntern.createForm("ShrubberyCreationForm", "Home");
        AForm* robot = someIntern.createForm("RobotomyRequestForm", "Bender");
        AForm* pardon = someIntern.createForm("PresidentialPardonForm", "Alice");

        try {
            AForm* fail = someIntern.createForm("unknown form", "Nobody");
            delete fail;
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "\n--- Bureaucrats and forms ---" << std::endl;
        std::cout << boss << std::endl;
        std::cout << mid << std::endl;
        std::cout << internB << std::endl;
        if (shrub) std::cout << *shrub << std::endl;
        if (robot) std::cout << *robot << std::endl;
        if (pardon) std::cout << *pardon << std::endl;

        std::cout << "\n--- Intern tries to sign and execute Shrubbery ---" << std::endl;
        if (shrub) {
            try {
                shrub->beSigned(internB);
            } catch (std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            try {
                shrub->execute(internB);
            } catch (std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        std::cout << "\n--- Mid signs and executes Shrubbery ---" << std::endl;
        if (shrub) {
            shrub->beSigned(mid);
            shrub->execute(mid);
        }

        std::cout << "\n--- Boss signs and executes Robotomy ---" << std::endl;
        if (robot) {
            robot->beSigned(boss);
            robot->execute(boss);
        }

        std::cout << "\n--- Boss signs and executes Pardon ---" << std::endl;
        if (pardon) {
            pardon->beSigned(boss);
            pardon->execute(boss);
        }

        std::cout << "\n--- Try to execute unsigned form ---" << std::endl;
        AForm* notSigned = someIntern.createForm("PresidentialPardonForm", "Bob");
        if (notSigned) {
            try {
                notSigned->execute(boss);
            } catch (std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            delete notSigned;
        }

        delete shrub;
        delete robot;
        delete pardon;

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}