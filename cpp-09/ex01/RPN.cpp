#include "RPN.hpp"

RPN::RPN(std::string tokens) : _tokens(tokens) {
    parseAndCalculateTokens();
}

RPN::~RPN() {

}

void RPN::parseAndCalculateTokens() {
    std::stringstream ss(this->_tokens);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int res;
            if (this->_stack.size() < 2) {
                throw std::runtime_error("Error: too little amount of operands");
                return;
            }

            int oper2 = this->_stack.top();
            this->_stack.pop();
            int oper1 = this->_stack.top();
            this->_stack.pop();

            if (token == "+") {
                res = oper1 + oper2;
            } else if (token == "-") {
                res = oper1 - oper2;
            } else if (token == "*") {
                res = oper1 * oper2;
            } else if (token == "/") {
                if (oper2 == 0) {
                    throw std::runtime_error("Error: cannot do divison on 0");
                    return;
                }
                res = oper1 / oper2;
            }

            this->_stack.push(res);
        } else if (isValidToken(token)) {
            std::stringstream ss_n(token);
            int res;

            ss_n >> res;
            this->_stack.push(res);
        }
    }

    if (this->_stack.size() != 1) {
        throw std::runtime_error("Error: incorrect amount of operands and operators");
        return;
    }

    std::cout << this->_stack.top() << std::endl;
}

bool RPN::isValidToken(std::string token) {
    std::stringstream ss_n(token);
    int res;

    for (std::string::iterator it = token.begin(); it != token.end(); ++it) {
        if (!std::isdigit(static_cast<unsigned char>(*it))) {
            throw std::runtime_error("Error: invalid token");
            return false;
        }
    }

    if (!(ss_n >> res)) {
        throw std::runtime_error("Error: invalid token");
        return false;
    }
    if (res < 0 || res > 10) {
        throw std::runtime_error("Error: token is too big or too small");
        return false;
    }

    return true;
}

