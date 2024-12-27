#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
    public:
        void addContact();
        void removeContact();
        void displayPhoneBook();
        void displayContact(int index);
};

#endif