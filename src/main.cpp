#include "cut_enumerates.h"

int main() {
    auto res = enumerate_cuts("/home/vsevolod/PycharmProjects/mockturtle_wrapper/aig_bench");
    for (auto& [name, info] : res) {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Info: " << std::endl;
        std::cout << info << std::endl << "============" << std::endl;

    }
    return 0;
}