#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _secret;
    public:
        Contact();
        ~Contact();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getSecret();
        std::string getPhoneNumber();
        void setFirstName(std::string value);
        void setLastName(std::string value);
        void setNickname(std::string value);
        void setSecret(std::string value);
        void setPhoneNumber(std::string value);
};

#endif