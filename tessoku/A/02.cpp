#include <iostream>
#include <unordered_set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, X, a;
    std::cin >> N >> X;
    std::unordered_set<int> data;
    for (int i = 0; i < N; i++) {
        std::cin >> a;
        data.insert(a);
    }
    std::cout << ((data.count(X)) ? "Yes\n" : "No\n");
    return 0;
}
//Linear Search