#include "PhoneBook.hpp"
#include "colors.hpp"

void print_str10(std::string str) {
    if (str.length() > 10) {
            std::cout << str.substr(0, 9) << "." << SKY500 << "|" << RESET;
        } else {
            for (int i = 0; i < (10 - (int)str.length()); i++) {
                std::cout << " ";
            }
            std::cout << str;
            std::cout << SKY500 << "|" << RESET;
        }
}

void print_column() {
    std::cout << SKY500;
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
    this->_contacts[i] = new_contact;
    i = (i + 1) % 8;
}

void PhoneBook::displayPhoneBook() {
    print_column();
    std::cout << SKY500 << "|" << RESET << "     Index|First Name| Last Name|  Nickname" SKY500 "|\n" << RESET;
    for (int i = 0; i < 8; i++) {
        if (!this->_contacts[i].getFirstName().empty()) {
            std::cout << SKY500 << "|" << RESET << "         " << i + 1 << SKY500 "|" << RESET;
            print_str10(this->_contacts[i].getFirstName());
            print_str10(this->_contacts[i].getLastName());
            print_str10(this->_contacts[i].getNickname());
            std::cout << "\n";
        }
    }
    print_column();
}

void PhoneBook::displayContact(int index) {
    std::cout << CYAN500 << "Contact details\n" << RESET;
    std::cout << BLUE500 << "First Name: " << RESET << this->_contacts[index].getFirstName() << "\n";
    std::cout << BLUE500 << "Last Name: " << RESET << this->_contacts[index].getLastName() << "\n";
    std::cout << BLUE500 << "Nickname: " << RESET << this->_contacts[index].getNickname() << "\n";
    std::cout << BLUE500 << "Phone number: " << RESET << this->_contacts[index].getPhoneNumber() << "\n";
    std::cout << BLUE500 << "Deepest darkest secret: " << RESET << this->_contacts[index].getSecret() << "\n";
}

int PhoneBook::getNumContacts() {
    int i = 0;

    while (i < 8 && !this->_contacts[i].getFirstName().empty()) {
        i++;
    }
    return i;
}
