#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av) {
    std::size_t len = 0;
    while (av[2][len]) {
        len++;
    }
    if (ac == 4) {
        std::string file(av[1]);
        std::string to_find(av[2]);
        std::string to_replace(av[3]);
        std::ifstream src(file);
        std::ofstream res(file);
        if (!src.is_open() || !res.is_open()) {
            std::cerr << "Error: Cannot open the file" << std::endl;
            return 1;
        }
        std::string line;
        while (getline(src, line)) {
            while (line.find(to_find)) {
                std::size_t pos = line.find(to_find);
                line.erase(line.find(to_find), to_find.length());
                line.insert(pos, to_replace.begin(), to_replace.end());
            }
        }
        res << line;
    } else {
        std::cerr << "Incorrect amount of arguments" << std::endl;
        return 1;
    }

    return 0;
}
