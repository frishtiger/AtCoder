#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    std::cin >> N >> K;
    std::cout << (K - 1) * (K - 2) / 2 - 3 * (std::max(0, (K - N - 1)) * (K - N - 2) / 2) + 3 * (std::max(0, (K - 2 * N - 1)) * (K - 2 * N - 2) / 2) - std::max(0, (K - 3 * N - 1)) * (K - 3 * N - 2) / 2 << '\n';
    return 0;
}
//Three Cards