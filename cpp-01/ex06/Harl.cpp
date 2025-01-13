#include "Harl.hpp"

Harl::Harl() {
    std::cout << GREEN500 << "Harl constructor called" << RESET << std::endl;
}

Harl::~Harl() {
    std::cout << RED500 << "Harl destructor called" << RESET << std::endl;
}

enum Commands {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
};

int resolveCommand(std::string level) {
    if ( level == "DEBUG" ) return DEBUG;
    if ( level == "INFO" ) return INFO;
    if ( level == "WARNING" ) return WARNING;
    if ( level == "ERROR" ) return ERROR;
    return -1;
}

void Harl::complain(std::string level) {
    switch(resolveCommand(level)) {
        case DEBUG:
            this->debug();
            break;
        case INFO:
            this->info();
            break;
        case WARNING:
            this->warning();
            break;
        case ERROR:
            this->error();
            break;
        default:
            std::cout << "Incorrect argument passed" << std::endl;
            break;
    }
}

void Harl::harlFilter(std::string level) {
    int i = resolveCommand(level);
    if (i == -1) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

    while (i <= ERROR) {
        switch(i) {
            case DEBUG: this->debug();
                break;
            case INFO: this->info();
                break;
            case WARNING: this->warning();
                break;
            case ERROR: this->error();
                break;
        }
        i++;
    }
}

void Harl::debug(void) {
    std::cout << PURPLE500 "[ DEBUG ]" << RESET << std::endl;
    std::cout << CYAN500 << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RESET << std::endl;
}

void Harl::info(void) {
    std::cout << PURPLE500 "[ INFO ]" << RESET << std::endl;
    std::cout << CYAN500 << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void Harl::warning(void) {
    std::cout << PURPLE500 "[ WARNING ]" << RESET << std::endl;
    std::cout << CYAN500 << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void Harl::error(void) {
    std::cout << PURPLE500 "[ ERROR ]" << RESET << std::endl;
    std::cout << CYAN500 << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}
