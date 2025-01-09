#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
    public:
        PhoneBook();
        ~PhoneBook();
        void addContact(Contact new_contact);
        void displayPhoneBook();
        void displayContact(int index);
        int getNumContacts();
};

#endif