#include "PhoneBook.hpp"
#include "Contact.hpp"

bool check_phone(std::string num) {
    for (int i = 0; num[i]; i++) {
        if ((num[i] >= '0' && num[i] <= '9') || num[i] == '-') {
            continue;
        } else {
            return (false);
        }
    }
    return (true);
}

void add_loop(PhoneBook &pb) {
    Contact n_contact;
    std::string input;

    std::cout << "Enter a first name of contact\n";
    while ((!std::getline(std::cin, input)) && input.empty()) {
        std::cout << "Enter a first name of contact\n";
    }
    n_contact.setFirstName(input);
    std::cout << "Enter a last name of contact\n";
    while ((!std::getline(std::cin, input)) && input.empty()) {
        std::cout << "Enter a last name of contact\n";
    }
    n_contact.setLastName(input);
    std::cout << "Enter a nickname of contact\n";
    while ((!std::getline(std::cin, input)) && input.empty()) {
        std::cout << "Enter a nickname of contact\n";
    }
    n_contact.setNickname(input);
    std::cout << "Enter a phone number of contact\n";
    while ((!std::getline(std::cin, input)) && !check_phone(input)) {
        std::cout << "Error: Argument can only contain numbers\n";
        std::cout << "Enter a phone number of contact\n";
    }
    n_contact.setPhoneNumber(input);
    std::cout << "Enter darkest secret of contact\n";
    while ((!std::getline(std::cin, input)) && input.empty()) {
        std::cout << "Enter darkest secret of contact\n";
    }
    n_contact.setSecret(input);
    pb.addContact(n_contact);
}

bool check_number(std::string str, PhoneBook &pb) {
    int value;
    if (!str.empty() && !std::all_of(str.begin(), str.end(), ::isdigit)) {
        return false;
    }
    value = std::stoi(str);
    if (value > 0 && value <= pb.getNumContacts()) {
        std::cout << "HERE2";
        return true;
    }
    return false;
}

void search_loop(PhoneBook &pb) {
    std::string input;

    if (pb.getNumContacts() < 1) {
        std::cout << pb.getNumContacts();
        std::cout << "Phonebook is empty :(\n";
        return ;
    }
    pb.displayPhoneBook();
    std::cout << "Enter the index of a contact to see details\n";
    while ((!std::getline(std::cin, input)) && !check_number(input, pb)) {
        std::cout << "Only accept numeric arguments in range (1-8) and contact should exist\n";
    }
    pb.displayContact(std::stoi(input) - 1);
}

void test_8(PhoneBook &pb) {
    for (int i = 0; i < 8; i++) {
        Contact c;
        c.setFirstName("test " + std::to_string(i));
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
    std::cout << "This is my amazing crappy phonebook" << "\n";

    while (1) {
        std::cout << "Enter a command: ADD | SEARCH | EXIT\n";
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