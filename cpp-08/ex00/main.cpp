#include "easyfind.hpp"
#include <list>
#include <deque>

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);
        deq.push_back(300);

        std::cout << "Found in vector: " << *easyfind(vec, 3) << std::endl;

        std::cout << "Found in list: " << *easyfind(lst, 40) << std::endl;

        std::cout << "Found in deque: " << *easyfind(deq, 200) << std::endl;

        std::cout << "Trying to find 99 in vector..." << std::endl;
        std::cout << *easyfind(vec, 99) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int> emptyVec;
        std::cout << "Trying to find in empty vector..." << std::endl;
        std::cout << *easyfind(emptyVec, 1) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
