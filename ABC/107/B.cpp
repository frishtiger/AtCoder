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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int H, W;
    bool a = false;
    std::cin >> H >> W;
    std::vector<std::vector<char>> data(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> data[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        a = true;
        for (int j = 0; j < W; j++) {
            if (data[i][j] == '#') {
                a = false;
            }
        }
        if (a == true) {
            for (int j = 0; j < W; j++) {
                data[i][j] = '_';
            }
        }
    }
    for (int i = 0; i < W; i++) {
        a = true;
        for (int j = 0; j < H; j++) {
            if (data[j][i] == '#') {
                a = false;
            }
        }
        if (a == true) {
            for (int j = 0; j < H; j++) {
                data[j][i] = '_';
            }
        }
    }
    for (int i = 0; i < H; i++) {
        a = false;
        for (int j = 0; j < W; j++) {
            if (data[i][j] != '_') {
                std::cout << data[i][j];
                a = true;
            }
            if (j == W - 1 && a == true) std::cout << '\n';
        }
    }
    return 0;
}
//Grid Compression