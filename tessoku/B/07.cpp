#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T, N;
    std::cin >> T >> N;
    std::vector<std::pair<int, int>> attendance(N);
    for (int i = 0; i < N; i++) {
        std::cin >> attendance[i].first >> attendance[i].second;
    }
    std::vector<int> changes(T + 2, 0);
    for (int i = 0; i < N; i++) {
        changes[attendance[i].first]++;
        changes[attendance[i].second]--;
    }
    std::vector<int> numbers(T + 2, changes[0]);
    for (int i = 1; i < T + 1; i++) {
        numbers[i] = numbers[i - 1] + changes[i];
    }
    for (int i = 0; i < T; i++) {
        std::cout << numbers[i] << '\n';
    }
    return 0;
}
//Convenience Store 2