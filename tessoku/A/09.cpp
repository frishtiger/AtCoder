#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int H, W, N;
    std::cin >> H >> W >> N;
    std::vector<std::vector<int>> data(H + 1, std::vector<int>(W + 1, 0));
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> range(N);
    for (int i = 0; i < N; i++) {
        std::cin >> range[i].first.first >> range[i].first.second >> range[i].second.first >> range[i].second.second;
    }
    for (int i = 0; i < N; i++) {
        data[range[i].first.first - 1][range[i].first.second - 1]++;
        data[range[i].first.first - 1][range[i].second.second]--;
        data[range[i].second.first][range[i].first.second - 1]--;
        data[range[i].second.first][range[i].second.second]++;
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
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cout << data[i][j];
            std::cout << ((j == W - 1) ? '\n' : ' ');
        }
    }
    return 0;
}
//Winter in ALGO Kingdom