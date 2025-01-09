#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"
#include <stdlib.h>

bool check_phone(std::string num) {
    for (int i = 0; num[i]; i++) {
        if ((num[i] >= '0' && num[i] <= '9') || num[i] == '-') {
            continue;
        } else {
            return false;
        }
    }
    return (true);
}

void add_loop(PhoneBook &pb) {
    Contact n_contact;
    std::string input;

    std::cout << VIOLET500 << "Enter a first name of contact" << std::endl << RESET;
    while ((std::getline(std::cin, input)) && input.empty()) {
        std::cout << VIOLET500 << "Enter a first name of contact" << std::endl << RESET;
    }
    n_contact.setFirstName(input);
    std::cout << VIOLET500 << "Enter a last name of contact" << std::endl << RESET;
    while ((std::getline(std::cin, input)) && input.empty()) {
        std::cout << VIOLET500 << "Enter a last name of contact" << std::endl << RESET;
    }
    n_contact.setLastName(input);
    std::cout << VIOLET500 << "Enter a nickname of contact" << std::endl << RESET;
    while ((std::getline(std::cin, input)) && input.empty()) {
        std::cout << VIOLET500 << "Enter a nickname of contact" << std::endl << RESET;
    }
    n_contact.setNickname(input);
    std::cout << VIOLET500 << "Enter a phone number of contact" << std::endl << RESET;
    while ((std::getline(std::cin, input)) && !check_phone(input)) {
        std::cout << RED500 << "Error: Argument can only contain numbers" << std::endl << RESET;
        std::cout << VIOLET500 << "Enter a phone number of contact" << std::endl << RESET;
    }
    n_contact.setPhoneNumber(input);
    std::cout << VIOLET500 << "Enter darkest secret of contact" << std::endl << RESET;
    while ((std::getline(std::cin, input)) && input.empty()) {
        std::cout << VIOLET500 << "Enter darkest secret of contact" << std::endl << RESET;
    }
    n_contact.setSecret(input);
    pb.addContact(n_contact);
}

bool check_number(std::string str, PhoneBook &pb) {
    int value;
    if (str.empty()) {
        return false;
    }
    for (std::size_t i = 0; i < str.size(); i++) {
        if ((str[i] >= '0' && str[i] <= '9')) {
            continue;
        } else {
            return false;
        }
    }
    value = atoi(str.c_str());
    if (value > 0 && value <= pb.getNumContacts()) {
        return true;
    }
    return false;
}

void search_loop(PhoneBook &pb) {
    std::string input;

    if (pb.getNumContacts() < 1) {
        std::cout << RED500 << "Phonebook is empty :(" << std::endl << RESET;
        return ;
    }
    pb.displayPhoneBook();
    std::cout << VIOLET500 << "Enter the index of a contact to see details" << std::endl << RESET;
    while ((std::getline(std::cin, input)) && !check_number(input, pb)) {
        std::cout << RED500 << "Error: Only accept numeric arguments in range (1-8) and contact should exist" << std::endl << RESET;
        std::cout << VIOLET500 << "Enter the index of a contact to see details" << std::endl << RESET;
    }
    pb.displayContact(atoi(input.c_str()) - 1);
}

void test_8(PhoneBook &pb) {
    for (int i = 0; i < 8; i++) {
        Contact c;
        c.setFirstName("test");
        c.setLastName("l_name");
        c.setNickname("nickname");
        c.setPhoneNumber("1234");
        c.setSecret("secret");
        pb.addContact(c);
    }
}

int main() {
    std::string line;
    PhoneBook pb;

    std::cout << PINK500 << "This is my amazing crappy phonebook" << std::endl << RESET;
    while (1) {
        std::cout << VIOLET500 << "Enter a command: ADD | SEARCH | EXIT" << std::endl << RESET;
        if (!std::getline(std::cin, line)) {
            return 0;
        }
        if (line == "ADD") {
            add_loop(pb);
        } else if (line == "test_8") {
            test_8(pb);
        } else if (line == "SEARCH") {
            search_loop(pb);
        } else if (line == "EXIT") {
            break;
        }
    }

    return 0;
}
