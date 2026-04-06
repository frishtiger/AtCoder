#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> beginmax(N);
    for (int i = 0; i < N; i++) {
        std::cin >> beginmax[i];
    }
    int D;
    std::cin >> D;
    std::vector<std::pair<int, int>> days(D);
    for (int i = 0; i < D; i++) {
        std::cin >> days[i].first >> days[i].second;
    }
    std::vector<int> endmax(N, beginmax[N - 1]);
    for (int i = 0; i < N - 1; i++) {
        endmax[N - i - 2] = std::max(beginmax[N - i - 2], endmax[N - i - 1]);
    }
    for (int i = 0; i < N - 1; i++) {
        beginmax[i + 1] = std::max(beginmax[i], beginmax[i + 1]);
    }
    for (int i = 0; i < D; i++) {
        std::cout << std::max(beginmax[days[i].first - 2], endmax[days[i].second]) << '\n';
    }
    return 0;
}
//Resort Hotel