//#define _GLIBCXX_DEBUG
#include <algorithm>
#include <any>
#include <array>
#include <atomic>
#include <barrier>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <charconv>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <clocale>
#include <cmath>
#include <compare>
#include <complex>
#include <concepts>
#include <condition_variable>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <expected>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <latch>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <memory_resource>
#include <mutex>
#include <new>
#include <numbers>
#include <numeric>
#include <optional>
#include <ostream>
#include <queue>
#include <random>
#include <ranges>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <semaphore>
#include <shared_mutex>
#include <source_location>
#include <span>
#include <spanstream>
#include <sstream>
#include <stack>
#include <stacktrace>
#include <stdatomic.h>
#include <stdexcept>
#include <stop_token>
#include <streambuf>
#include <string>
#include <string_view>
#include <syncstream>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>
#include <version>

void input_A(int i, int j, int &N, std::vector<std::vector<char>> &A) {
    if (i == N) return;
    std::cin >> A[i][j];
    j == N - 1 ? input_A(i + 1, 0, N, A) : input_A(i, j + 1, N, A);
}
void input_B(int i, int j, int &M, std::vector<std::vector<char>> &B) {
    if (i == M) return;
    std::cin >> B[i][j];
    j == M - 1 ? input_B(i + 1, 0, M, B) : input_B(i, j + 1, M, B);
}
void working(int &i, int &j, int k, int l, int &M, std::vector<std::vector<char>> &A, std::vector<std::vector<char>> &C) {
    if (k == M) return;
    C[k][l] = A[i + k][j + l];
    l == M - 1 ? working(i, j, k + 1, 0, M, A, C) : working(i, j, k, l + 1, M, A, C);
}
void trying(int i, int j, int &N, int &M, bool &OK, std::vector<std::vector<char>> &A, std::vector<std::vector<char>> &B) {
    if (i == N - M + 1) return;
    std::vector<std::vector<char>> C(M, std::vector<char>(M));
    working(i, j, 0, 0, M, A, C);
    if (B == C) {
        OK = true;
        return;
    }
    if (!OK) j == N - M ? trying(i + 1, 0, N, M, OK, A, B) : trying(i, j + 1, N, M, OK, A, B);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<char>> A(N, std::vector<char>(N));
    input_A(0, 0, N, A);
    std::vector<std::vector<char>> B(M, std::vector<char>(M));
    input_B(0, 0, M, B);
    bool OK = false;
    trying(0, 0, N, M, OK, A, B);
    std::cout << (OK ? "Yes" : "No") << '\n';
    return 0;
}
//Template Matching