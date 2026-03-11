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
void input(int i, int j,int &H,int &W, int &sH, int &sW, int &gH, int &gW, std::vector<std::vector<char>> &data) {
    if (i == H) return;
    std::cin >> data[i][j];
    if (data[i][j] == 's') {
        sH = i;
        sW = j;
    }
    if (data[i][j] == 'g') {
        gH = i;
        gW = j;
    }
    j == W - 1 ? input(i + 1, 0, H, W, sH, sW, gH, gW, data) : input(i, j + 1, H, W, sH, sW, gH, gW, data);
}
void expand(int i, int j, int &H, int &W, std::vector<std::vector<char>> &data, std::vector<std::vector<bool>> &checked) {
    if (i == -1 || i == H || j == -1 || j == W) return;
    if (checked[i][j]) return;
    if (data[i][j] == '#') return;
    checked[i][j] = true;
    expand(i - 1, j, H, W, data, checked);
    expand(i + 1, j, H, W, data, checked);
    expand(i, j - 1, H, W, data, checked);
    expand(i, j + 1, H, W, data, checked);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int H, W, sH, sW, gH, gW;
    std::cin >> H >> W;
    std::vector<std::vector<char>> data(H, std::vector<char>(W));
    input(0, 0, H, W, sH, sW, gH, gW, data);
    std::vector<std::vector<bool>> checked(H, std::vector<bool>(W, false));
    expand(sH, sW, H, W, data, checked);
    std::cout << (checked[gH][gW] ? "Yes" : "No") << '\n';
    return 0;
}
//深さ優先探索