#include <iostream>
#include <string.h>
#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::getFirstName() {
    return _firstName;
}

std::string Contact::getLastName() {
    return _lastName;
}

std::string Contact::getNickname() {
    return _nickname;
}

std::string Contact::getSecret() {
    return _secret;
}

std::string Contact::getPhoneNumber() {
    return _phoneNumber;
}

void Contact::setFirstName(std::string value) {
    _firstName = value;
}

void Contact::setLastName(std::string value) {
    _lastName = value;
}

void Contact::setNickname(std::string value) {
    _nickname = value;
}

void Contact::setSecret(std::string value) {
    _secret = value;
}

void Contact::setPhoneNumber(std::string value) {
    _phoneNumber = value;
}
