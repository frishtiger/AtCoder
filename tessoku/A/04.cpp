#include <iostream>
#include <bitset>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::cout << std::bitset<10>(N) << '\n';
    return 0;
}
//Binary Representation 1