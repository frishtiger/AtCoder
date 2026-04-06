#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> data(1502, std::vector<int>(1502, 0));
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> range(N);
    for (int i = 0; i < N; i++) {
        std::cin >> range[i].first.first >> range[i].first.second >> range[i].second.first >> range[i].second.second;
    }
    for (int i = 0; i < N; i++) {
        data[range[i].first.first][range[i].first.second]++;
        data[range[i].first.first][range[i].second.second]--;
        data[range[i].second.first][range[i].first.second]--;
        data[range[i].second.first][range[i].second.second]++;
    }
    for (int i = 0; i < 1502; i++) {
        for (int j = 1; j < 1502; j++) {
            data[i][j] += data[i][j - 1];
        }
    }
    for (int i = 1; i < 1502; i++) {
        for (int j = 0; j < 1502; j++) {
            data[i][j] += data[i - 1][j];
        }
    }
    int count = 0;
    for (int i = 0; i < 1502; i++) {
        for (int j = 0; j < 1502; j++) {
            if (data[i][j] > 0) count++;
        }
    }
    std::cout << count << '\n';
    return 0;
}
//Papers