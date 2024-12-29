#include "PhoneBook.hpp"
#include "colors.hpp"

void print_str10(std::string str) {
    if (str.length() > 10) {
            std::cout << str.substr(0, 8) << "." << SKY100 << "|" << RESET;
        } else {
            for (int i = 0; i < (10 - (int)str.length()); i++) {
                std::cout << " ";
            }
            std::cout << str;
            std::cout << SKY100 << "|" << RESET;
        }
}

void print_column() {
    std::cout << SKY100;
    std::cout << "*";
    for (int i = 0; i < 43; i++) {
        std::cout << "-";
    }
    std::cout << "*\n" << RESET;
}

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact(Contact new_contact) {
    static int i = 0;
    contacts[i] = new_contact;
    i = (i + 1) % 8;
}

void PhoneBook::displayPhoneBook() {
    print_column();
    std::cout << SKY100 << "|" << RESET << "     Index|First Name| Last Name|  Nickname" SKY100 "|\n" << RESET;
    for (int i = 0; i < 8; i++) {
        if (!contacts[i].getFirstName().empty()) {
            std::cout << SKY100 << "|" << RESET << "         " << i + 1 << SKY100 "|" << RESET;
            print_str10(contacts[i].getFirstName());
            print_str10(contacts[i].getLastName());
            print_str10(contacts[i].getNickname());
            std::cout << "\n";
        }
    }
    print_column();
}

void PhoneBook::displayContact(int index) {
    std::cout << CYAN100 << "Contact details\n" << RESET;
    std::cout << BLUE100 << "First Name: " << RESET << contacts[index].getFirstName() << "\n";
    std::cout << BLUE100 << "Last Name: " << RESET << contacts[index].getLastName() << "\n";
    std::cout << BLUE100 << "Nickname: " << RESET << contacts[index].getNickname() << "\n";
    std::cout << BLUE100 << "Phone number: " << RESET << contacts[index].getPhoneNumber() << "\n";
    std::cout << BLUE100 << "Deepest darkest secret: " << RESET << contacts[index].getSecret() << "\n";
}

int PhoneBook::getNumContacts() {
    int i = 0;

    while (i < 8 && !contacts[i].getFirstName().empty()) {
        i++;
    }
    return i;
}
