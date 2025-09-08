#pragma once
#include <iostream>
#include <map>
#include <algorithm>

class BitcoinExchange {
    private:
        std::map<std::string, double> _data;
        std::map<std::string, double> _input;
        const std::string _dataFile;
        const std::string _inputFile;
    public:
        BitcoinExchange(const std::string& inputFile);
        ~BitcoinExchange();
};