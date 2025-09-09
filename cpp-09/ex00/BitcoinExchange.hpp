#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstdlib>
#include <fstream>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, double> _data;
        std::map<std::string, double> _input;
        const std::string _dataFile;
        const std::string _inputFile;
        bool isValidNum(std::string num);
        bool isValidDate(std::string date);
        bool isValidDateNumber(std::string num);
        void parseData();
    public:
        BitcoinExchange(const std::string& inputFile);
        ~BitcoinExchange();
};