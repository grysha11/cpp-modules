#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctype.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <climits>
#include <ctime>
#include <stdexcept>

template <typename Container>
std::string get_container_name();

template <>
std::string get_container_name<std::vector<int> >() {
    return "vector";
}

template <>
std::string get_container_name<std::deque<int> >() {
    return "deque";
}

template <typename Container>
class PmergeMe {
private:
    Container _arr;
public:
    PmergeMe() { }
    PmergeMe(const PmergeMe& other) { _arr = other._arr; }
    PmergeMe& operator=(const PmergeMe& other) {
        if (this != &other) _arr = other._arr;
        return *this;
    }

    ~PmergeMe() {}

    Container getArr() const {
        return _arr;
    }

    bool is_valid_num(const std::string num) {
        if (num.empty()) {
            throw std::runtime_error("Found empty string");
        }

        if (num[0] == '-') {
            throw std::runtime_error("Found negative number");
        }

        for (std::string::const_iterator it = num.begin(); it != num.end(); ++it) {
            if (!std::isdigit(*it)) {
                throw std::runtime_error("Found non-numeric value");
            }
        }

        long val = std::strtol(num.c_str(), NULL, 10);
        if (val > INT_MAX || val < 0) {
            throw std::runtime_error("Number is out of range");
        }

        return true;
    }

    bool checkForDups() {
        for (typename Container::iterator it1 = _arr.begin(); it1 != _arr.end(); ++it1) {
            for (typename Container::iterator it2 = it1 + 1; it2 != _arr.end(); ++it2) {
                if (*it1 == *it2) {
                    return false;
                }
            }
        }

        return true;
    }

    void parse_av(char **av) {
        for (size_t i = 1; av[i]; i++) {
            if (!is_valid_num(std::string(av[i]))) {
                break;
            }
            _arr.push_back(std::atoi(av[i]));
        }

        if (!checkForDups()) {
            throw std::runtime_error("Found duplicates values");
        }
    }

    int jacobsthal(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
    }

    Container sort_pair(int num1, int num2) {
        Container res;

        if (num1 > num2) {
            res.push_back(num2);
            res.push_back(num1);
        } else {
            res.push_back(num1);
            res.push_back(num2);
        }

        return res;
    }

    int binary_search_insert(const Container& main_chain, int val, int limit) {
        int low = 0;
        int high = limit;

        while (low < high) {
            int mid = (low + high) / 2;
            if (main_chain[mid] < val) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    Container sort(Container arr) {
        if (arr.size() < 2) {
            return arr;
        }

        std::vector<Container> pairs;
        int non_pair = -1;

        if (arr.size() % 2 != 0) {
            non_pair = arr.back();
            arr.pop_back();
        }

        for (size_t i = 0; i < arr.size(); i += 2) {
            pairs.push_back(sort_pair(arr[i], arr[i + 1]));
        }

        Container large_elems;
        std::vector<Container> original_pairs = pairs;

        for (typename std::vector<Container>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
            large_elems.push_back((*it)[1]);
        }

        Container sorted_large_elems = sort(large_elems);

        Container main_chain;
        Container pendulum;

        for (typename Container::iterator it1 = sorted_large_elems.begin(); it1 != sorted_large_elems.end(); ++it1) {
            for (typename std::vector<Container>::iterator it2 = original_pairs.begin(); it2 != original_pairs.end();) {
                if ((*it2)[1] == *it1) {
                    main_chain.push_back((*it2)[1]);
                    pendulum.push_back((*it2)[0]);
                    it2 = original_pairs.erase(it2);
                    break;
                } else {
                    ++it2;
                }
            }
        }

        if (!pendulum.empty()) {
            main_chain.insert(main_chain.begin(), pendulum[0]);
        }

        int last_insert_idx = 1;
        int jacob_idx = 3;
        while (last_insert_idx < static_cast<int>(pendulum.size())) {
            int k = jacobsthal(jacob_idx);
            int end_idx = std::min(static_cast<int>(last_insert_idx + k), static_cast<int>(pendulum.size()));
            for (int i = end_idx - 1; i >= last_insert_idx; --i) {
                int val = pendulum[i];
                int partner = sorted_large_elems[i];
                int limit = 0;
                for (size_t j = 0; j < main_chain.size(); ++j) {
                    if (main_chain[j] == partner) {
                        limit = j;
                        break;
                    }
                }
                int pos = binary_search_insert(main_chain, val, limit);
                main_chain.insert(main_chain.begin() + pos, val);
            }
            last_insert_idx = end_idx;
            jacob_idx++;
        }

        if (non_pair != -1) {
            int pos = binary_search_insert(main_chain, non_pair, main_chain.size());
            main_chain.insert(main_chain.begin() + pos, non_pair);
        }

        return main_chain;
    }
};