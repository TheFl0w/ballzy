#include <ballzy/Vector.hpp>
#include <cassert>
#include <iostream>

int main() {
    ballzy::Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    ballzy::Vector v2 = v;
    while (v2.size() > 0) {
        std::cout << v2.pop_back() << " ";
    }
    std::cout << "\n";
    std::cout << "v2 " << (v2.empty() ? "is empty" : "is not empty") << "\n";
    return 0;
}
