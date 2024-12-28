#include <iostream>
#include <string.h>
#include "Contact.hpp"

Contact::Contact() {
    f_name = "";
    l_name = "";
    nickname = "";
    secret = "";
    phone_number = "";
    index = -1;
}

std::string Contact::getFirstName() {
    return f_name;
}

std::string Contact::getLastName() {
    return l_name;
}

std::string Contact::getNickname() {
    return nickname;
}

std::string Contact::getSecret() {
    return secret;
}

std::string Contact::getPhoneNumber() {
    return phone_number;
}

int Contact::getIndex() {
    return index;
}

void Contact::setFirstName(std::string value) {
    f_name = value;
}

void Contact::setLastName(std::string value) {
    l_name = value;
}

void Contact::setNickname(std::string value) {
    nickname = value;
}

void Contact::setSecret(std::string value) {
    secret = value;
}

void Contact::setPhoneNumber(std::string value) {
    phone_number = value;
}

void Contact::setIndex(int i) {
    index = i;
}
