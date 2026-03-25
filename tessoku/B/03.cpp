#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> price(N);
    for (int i = 0; i < N; i++) {
        std::cin >> price[i];
    }
    bool OK = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            for (int k = 0; k < N; k++) {
                if (i == k || j == k) continue;
                if (price[i] + price[j] + price[k] == 1000) OK = true;
            }
        }
    }
    std::cout << ((OK) ? "Yes\n" : "No\n");
    return 0;
}
//Supermarket 1