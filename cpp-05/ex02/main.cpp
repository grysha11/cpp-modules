#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Bureaucrat mid("Mid", 70);

        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Alice");

        std::cout << "\n--- Initial States ---" << std::endl;
        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
        std::cout << mid << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n--- Intern tries to sign and execute Shrubbery ---" << std::endl;
        try {
            shrub.beSigned(intern);
        } catch (std::exception &e) {
            std::cerr << "Erorr: " << e.what() << std::endl;
        }
        try {
            shrub.execute(intern);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "\n--- Mid signs and executes Shrubbery ---" << std::endl;
        shrub.beSigned(mid);
        mid.executeForm(shrub);

        std::cout << "\n--- Boss signs and executes Robotomy ---" << std::endl;
        robot.beSigned(boss);
        robot.execute(boss);

        std::cout << "\n--- Boss signs and executes Pardon ---" << std::endl;
        pardon.beSigned(boss);
        pardon.execute(boss);

        std::cout << "\n--- Try to execute unsigned form ---" << std::endl;
        PresidentialPardonForm notSigned("Bob");
        try {
            notSigned.execute(boss);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}