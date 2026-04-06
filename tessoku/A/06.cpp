#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> people(N + 1, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> people[i + 1];
    }
    std::vector<std::pair<int, int>> days(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> days[i].first >> days[i].second;
    }
    std::vector<long long> sum(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        sum[i] = sum[i - 1] + people[i];
    }
    for (int i = 0; i < Q; i++) {
        std::cout << sum[days[i].second] - sum[days[i].first - 1] << '\n';
    }
    return 0;
}
//How Many Guests?