#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string S;
    std::cin >> S;
    std::cout << std::stoi(S, nullptr, 2) << '\n';
    return 0;
}
//Binary Representation 2