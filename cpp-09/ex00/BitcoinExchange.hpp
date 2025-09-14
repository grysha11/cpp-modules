#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstdlib>
#include <fstream>
#include <string>

enum num_flag {
    DATA,
    INPUT,
};

class BitcoinExchange {
    private:
        std::map<std::string, double> _data;
        const std::string _dataFile;
        const std::string _inputFile;
        bool isValidNum(std::string num, num_flag flag);
        bool isValidDate(std::string date);
        bool isValidDateNumber(std::string num);
        bool parseData();
        void parseInput();
    public:
        BitcoinExchange(const std::string& inputFile);
        ~BitcoinExchange();
};