#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack1;

    for (int i = 0; i < 10; i++) {
        mstack1.push(i);
        std::cout << "top element of mstack1: " << mstack1.top() << std::endl;
    }

    MutantStack<int> mstack2 = mstack1;

    for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
        std::cout << "iterator element of mstack2: " << *it << std::endl;
    }

    mstack1.pop();
    std::cout << "mstack1 top after pop: " << mstack1.top() << std::endl;

    std::cout << "mstack2 top after mstack1 pop: " << mstack2.top() << std::endl;

    return 0;
}

// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }