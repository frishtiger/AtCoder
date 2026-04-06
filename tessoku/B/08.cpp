#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].first >> points[i].second;
    }
    int Q;
    std::cin >> Q;
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> questions(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> questions[i].first.first >> questions[i].first.second >> questions[i].second.first >> questions[i].second.second;
    }
    std::vector<std::vector<int>> sum(1501, std::vector<int>(1501, 0));
    for (int i = 0; i < N; i++) {
        sum[points[i].first][points[i].second]++;
    }
    for (int i = 0; i < 1501; i++) {
        for (int j = 1; j < 1501; j++) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    for (int i = 1; i < 1501; i++) {
        for (int j = 0; j < 1501; j++) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    for (int i = 0; i < Q; i++) {
        std::cout << sum[questions[i].second.first][questions[i].second.second] - sum[questions[i].second.first][questions[i].first.second - 1] - sum[questions[i].first.first - 1][questions[i].second.second] + sum[questions[i].first.first - 1][questions[i].first.second - 1] << '\n';
    }
    return 0;
}
//Counting points