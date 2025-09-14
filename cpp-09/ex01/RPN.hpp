#pragma once
#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>

class RPN {
    private:
        std::stack<int> _stack;
        std::string _tokens;
        void parseAndCalculateTokens();
        bool isValidToken(std::string token);
    public:
        RPN(std::string tokens);
        ~RPN();
};