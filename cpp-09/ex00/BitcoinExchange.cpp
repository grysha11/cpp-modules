#include "BitcoinExchange.hpp"

bool BitcoinExchange::isValidNum(std::string num, num_flag flag) {
    bool isComa = false;
    size_t c_afterComa = 0;
    char* pEnd;
    double res = std::strtod(num.c_str(), &pEnd);

    if (num.empty()) {
        std::cerr << "Error: Number was not found" << std::endl;
        return false;
    }

    for (std::string::iterator it = num.begin(); it != num.end(); ++it) {
        if (*it == '.') {
            if (isComa) {
                std::cerr << "Error: illegal amount of comas in number => " << num << std::endl;
                return false;
            }
            if (it == num.begin() || it + 1 == num.end()) {
                std::cerr << "Error: coma in illegal place of number => " << num << std::endl;
                return false;
            }
            isComa = true;
        } else if (!std::isdigit(static_cast<unsigned char>(*it))) {
            std::cerr << "Error: non-numeric value in number => " << num << std::endl;
            return false;
        } else if (isComa) {
            c_afterComa++;
        }
    }

    if (flag == DATA) {
        if (isComa && c_afterComa > 2) {
            std::cerr << "Error: decimal part is too big => " << num << std::endl;
            return false;
        }
    }

    if (*pEnd != '\0') {
        std::cerr << "Error: wrong format of number => " << num << std::endl;
        return false;
    }

    if (res < 0) {
        std::cerr << "Error: negative number => " << num << std::endl;
        return false;
    }

    if (flag == INPUT) {
        if (res > 1000) {
            std::cerr << "Error: number is too big => " << num << std::endl;
            return false;
        }
    }

    return true;
}

bool BitcoinExchange::isValidDateNumber(std::string num) {
    for (std::string::iterator it = num.begin(); it != num.end(); ++it) {
        if (!std::isdigit(static_cast<unsigned char>(*it))) {
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::isValidDate(std::string date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: wrong format of date => " << date << std::endl;
        return false;
    }

    std::string y = date.substr(0, 4);
    std::string m = date.substr(5, 2);
    std::string d = date.substr(8, 2);

    if (!this->isValidDateNumber(y)) {
        std::cerr << "Error: non-numeric value in year => " << date << std::endl;
        return false;
    }

    if (!this->isValidDateNumber(m)) {
        std::cerr << "Error: non-numeric value in month => " << date << std::endl;
        return false;
    }

    if (!this->isValidDateNumber(d)) {
        std::cerr << "Error: non-numeric value in day => " << date << std::endl;
        return false;
    }

    int yNum = std::atoi(y.c_str());
    int mNum = std::atoi(m.c_str());
    int dNum = std::atoi(d.c_str());

    if (yNum < 2009 || yNum > 2025) {
        std::cerr << "Error: invalid year => " << date << std::endl;
        return false;
    }

    if (mNum < 1 || mNum > 12) {
        std::cerr << "Error: invalid month => " << date << std::endl;
        return false;
    }

    if (dNum < 1 || dNum > 31) {
        std::cerr << "Error: invalid day => " << date << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::parseData() {
    std::fstream f(this->_dataFile.c_str());
    std::string line;

    if (!f.is_open()) {
        throw std::runtime_error("Error: could not open data file");
    }

    getline(f, line);
    if (line != "date,exchange_rate") {
        std::cerr << "Not complete data file => Missing \"date,exchange_rate\" line" << std::endl;
        return false;
    }

    while (getline(f, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos) {
            std::cerr << "Error: wrong format of data => " << line << std::endl;
        }
        std::string date = line.substr(0, pos);
        std::string val = line.substr(pos + 1);
        if (this->isValidDate(date) && this->isValidNum(val, DATA)) {
            double value = std::atof(val.c_str());
            this->_data[date] = value;
        } else {
            return false;
        }
    }

    return true;
}

void BitcoinExchange::parseInput() {
    std::fstream f(this->_inputFile.c_str());
    std::string line;

    if (!f.is_open()) {
        throw std::runtime_error("Error: could not open input file");
    }

    while (getline(f, line)) {
        size_t pos = line.find("|");
        if (pos == std::string::npos) {
            std::cerr << "Error wrong format of input => " << line << std::endl;
        }
        std::string date = line.substr(0, pos);
        std::string val = line.substr(pos + 1);
        while (!date.empty() && std::isspace(date[date.size() - 1])) {
            date.erase(date.size() - 1);
        }
        while (!val.empty() && std::isspace(val[0])) {
            val.erase(0, 1);
        }
        if (this->isValidDate(date) && this->isValidNum(val, INPUT)) {
            double value = std::atof(val.c_str());

            std::map<std::string, double>::iterator it = _data.find(date);
            if (it == this->_data.end()) {
                it = this->_data.lower_bound(date);
                if (it == this->_data.begin()) {
                    std::cerr << "Error: could not find date (too early date) => " << date << std::endl;
                    continue;
                }
                --it;
            }
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        }
    }
}

BitcoinExchange::BitcoinExchange(const std::string& inputFile) : _dataFile("data.csv"), _inputFile(inputFile) {
    if (parseData()) {
        parseInput();
    }
}

BitcoinExchange::~BitcoinExchange() {

}
