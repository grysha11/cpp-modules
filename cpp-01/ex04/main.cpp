#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Incorrect amount of arguments" << std::endl;
        return 1;
    }

    std::string resultFile(av[1]);
    std::ifstream src(av[1]);
    std::ofstream res(resultFile.append(".replace").c_str());
    if (!src.is_open() || !res.is_open()) {
        std::cerr << "Error: Cannot open the file" << std::endl;
        return 1;
    }

    std::string to_find(av[2]);
    std::string to_replace(av[3]);
    std::string line;
    while (getline(src, line)) {
        while (line.find(to_find) != std::string::npos) {
            std::size_t pos = line.find(to_find);
            line.erase(pos, to_find.length());
            line.insert(pos, to_replace);
        }
        res << line << "\n";
    }

    src.close();
    res.close();

    return 0;
}
