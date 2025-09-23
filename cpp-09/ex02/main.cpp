#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 3) {
        std::cerr << "Error: too little amount of numbers" << std::endl;
        return 1;
    }
    try {
        std::cout << "Before:";
        for (int i = 1; av[i]; ++i)
            std::cout << " " << av[i];
        std::cout << std::endl;

        // Vector
        PmergeMe<std::vector<int> > vec_merger;
        vec_merger.parse_av(av);
        clock_t start_vec = clock();
        std::vector<int> sorted_vec = vec_merger.sort(vec_merger.getArr());
        clock_t end_vec = clock();
        std::cout << "After:";
        for (size_t i = 0; i < sorted_vec.size(); ++i)
            std::cout << " " << sorted_vec[i];
        std::cout << std::endl;
        double time_vec = 1000000.0 * (end_vec - start_vec) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << sorted_vec.size()
                  << " elements with std::vector : " << time_vec << " us" << std::endl;

        // Deque
        PmergeMe<std::deque<int> > deq_merger;
        deq_merger.parse_av(av);
        clock_t start_deq = clock();
        std::deque<int> sorted_deq = deq_merger.sort(deq_merger.getArr());
        clock_t end_deq = clock();
        double time_deq = 1000000.0 * (end_deq - start_deq) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << sorted_deq.size()
                  << " elements with std::deque : " << time_deq << " us" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}