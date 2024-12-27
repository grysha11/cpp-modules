#include "PhoneBook.hpp"
#include "Contact.hpp"

bool check_phone(std::string num) {
    for (int i = 0; num[i]; i++) {
        if (num[i] >= '0' && num[i] <= '9' || num[i] == '-') {
            continue;
        } else {
            return (false);
        }
    }
    return (true);
}

void add_loop(PhoneBook pb) {
    Contact n_contact;
    std::string input;

    std::cout << "Enter a first name of contact";
    while ((std::cin >> input) && input == "") {
        std::cout << "Enter a first name of contact";
    }
    n_contact.setFirstName(input);
    std::cout << "Enter a last name of contact";
    while ((std::cin >> input) && input == "") {
        std::cout << "Enter a last name of contact";
    }
    n_contact.setLastName(input);
    std::cout << "Enter a nickname of contact";
    while ((std::cin >> input) && input == "") {
        std::cout << "Enter a nickname of contact";
    }
    n_contact.setNickname(input);
    std::cout << "Enter a phone number of contact";
    while ((std::cin >> input) && !check_phone(input)) {
        std::cout << "Enter a phone number of contact";
    }
    n_contact.setPhoneNumber(input);
    std::cout << "Enter darkest secret of contact";
    while ((std::cin >> input) && input == "") {
        std::cout << "Enter darkest secret of contact";
    }
    n_contact.setSecret(input);
    //have to create a logic for putting contact to the phonebook with overwriting
}

int main() {
    std::cout << "This is my amazing crappy phonebook" << "\n";
    std::string line;
    PhoneBook pb;

    while (1) {
        std::cin >> line;
        std::cout << "Try:\n\tADD | SEARCH | EXIT\n";
        if (line == "ADD") {

        } else if (line == "SEARCH") {

        } else if (line == "EXIT") {

        }
    }
}