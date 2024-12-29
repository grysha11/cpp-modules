#include "PhoneBook.hpp"

void print_str10(std::string str) {
    if (str.length() > 10) {
            std::cout << str.substr(0, 8) << ".|";
        } else {
            for (int i = 0; i < (10 - (int)str.length()); i++) {
                std::cout << " ";
            }
            std::cout << str;
            std::cout << "|";
        }
}

void print_column() {
    std::cout << "*";
    for (int i = 0; i < 43; i++) {
        std::cout << "-";
    }
    std::cout << "*\n";
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
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    for (int i = 0; i < 8; i++) {
        if (!contacts[i].getFirstName().empty()) {
            std::cout << "|" << "         " << i + 1 << "|";
            print_str10(contacts[i].getFirstName());
            print_str10(contacts[i].getLastName());
            print_str10(contacts[i].getNickname());
            std::cout << "\n";
        }
    }
    print_column();
}

void PhoneBook::displayContact(int index) {
    std::cout << "Contact details\n";
    std::cout << "First Name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last Name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNickname() << "\n";
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << "\n";
    std::cout << "Deepest darkest secret: " << contacts[index].getSecret() << "\n";
}

int PhoneBook::getNumContacts() {
    int i = 0;

    while (i < 8 && !contacts[i].getFirstName().empty()) {
        i++;
    }
    return i;
}
