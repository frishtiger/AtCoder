#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> results(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        std::cin >> results[i];
        if (results[i] == 0) results[i]--;
    }
    int Q;
    std::cin >> Q;
    std::vector<std::pair<int, int>> questions(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> questions[i].first >> questions[i].second;
    }
    std::vector<int> prefix_sum(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + results[i];
    }
    for (int i = 0; i < Q; i++) {
        std::cout << ((prefix_sum[questions[i].second] - prefix_sum[questions[i].first - 1] > 0) ? "win\n" : (prefix_sum[questions[i].second] - prefix_sum[questions[i].first - 1] < 0) ? "lose\n" : "draw\n");
    }
    return 0;
}
//Lottery