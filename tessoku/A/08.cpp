#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int H, W;
    std::cin >> H >> W;
    std::vector<std::vector<int>> data(H + 1, std::vector<int>(W + 1, 0));
    for (int i = 1; i < H + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            std::cin >> data[i][j];
        }
    }
    int Q;
    std::cin >> Q;
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> questions(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> questions[i].first.first >> questions[i].first.second >> questions[i].second.first >> questions[i].second.second;
    }
    for (int i = 0; i < H + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            data[i][j] += data[i][j - 1];
        }
    }
    for (int i = 1; i < H + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            data[i][j] += data[i - 1][j];
        }
    }
    for (int i = 0; i < Q; i++) {
        std::cout << data[questions[i].second.first][questions[i].second.second] - data[questions[i].second.first][questions[i].first.second - 1] - data[questions[i].first.first - 1][questions[i].second.second] + data[questions[i].first.first - 1][questions[i].first.second - 1] << '\n';
    }
    return 0;
}
//Two Dimensional Sum