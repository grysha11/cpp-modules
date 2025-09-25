#include "Bureaucrat.hpp"

int main() {
    Bureaucrat* normal_grisha = NULL;
    Bureaucrat* new_grisha = NULL;
    try {
        // Bureaucrat* grisha = new Bureaucrat("Grisha", 160);

        normal_grisha = new Bureaucrat("Norm_grisha", 30);
        std::cout << *normal_grisha << std::endl;

        new_grisha = new Bureaucrat(*normal_grisha);
        std::cout << *new_grisha << std::endl;
        new_grisha->decrementGrade(100);
        std::cout << *new_grisha << std::endl;
        // new_grisha->incrementGrade(150);
        // std::cout << *new_grisha << std::endl;

        normal_grisha->incrementGrade(29);
        std::cout << *normal_grisha << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    delete normal_grisha;
    delete new_grisha;

    return 0;
}