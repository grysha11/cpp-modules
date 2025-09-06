#include "Span.hpp"

int main()
{
try {
    Span sp = Span(1000);
    sp.coolAddNumber(1001);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
} catch (std::exception &e) {
    std::cout << e.what() << std::endl;
}
}