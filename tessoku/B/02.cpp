#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int A, B;
    std::cin >> A >> B;
    std::vector<int> vec{1, 2, 4, 5, 10, 20, 25, 50, 100};
    bool exist = false;
    for (int i = 0; i < 9; i++) {
        if (vec[i] >= A && vec[i] <= B) exist = true;
    }
    std::cout << ((exist) ? "Yes\n" : "No\n");
    return 0;
}
//Divisor Check