#include <iostream>
#include <string.h>
#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
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
