#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact {
    private:
        std::string f_name;
        std::string l_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;
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