#include <iostream>
#include <string.h>
#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::getFirstName() {
    return this->_firstName;
}

std::string Contact::getLastName() {
    return this->_lastName;
}

std::string Contact::getNickname() {
    return this->_nickname;
}

std::string Contact::getSecret() {
    return this->_secret;
}

std::string Contact::getPhoneNumber() {
    return this->_phoneNumber;
}

void Contact::setFirstName(std::string value) {
    this->_firstName = value;
}

void Contact::setLastName(std::string value) {
    this->_lastName = value;
}

void Contact::setNickname(std::string value) {
    this->_nickname = value;
}

void Contact::setSecret(std::string value) {
    this->_secret = value;
}

void Contact::setPhoneNumber(std::string value) {
    this->_phoneNumber = value;
}
