#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K, a;
    std::cin >> N >> K;
    std::vector<int> red(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a;
        red[i] = K - a;
    }
    std::unordered_set<int> blue;
    for (int i = 0; i < N; i++) {
        std::cin >> a;
        blue.insert(a);
    }
    bool success = false;
    for (int i = 0; i < N; i++) {
        if (blue.count(red[i])) {
            success = true;
            break;
        }
    }
    std::cout << ((success) ? "Yes\n" : "No\n");
    return 0;
}
//Two Cards