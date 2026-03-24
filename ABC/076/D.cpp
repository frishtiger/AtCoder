//C++03
#include <cstddef>
#include <limits>
#include <climits>
#include <cfloat>
#include <new>
#include <typeinfo>
#include <exception>
#include <cstdarg>
#include <cstdlib>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <cerrno>
#include <string>
#include <cctype>
#include <cwctype>
#include <cstring>
#include <cwchar>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#include <functional>
#include <bitset>
#include <cmath>
#include <complex>
#include <valarray>
#include <numeric>
#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
//#include <strstream> //非推奨
#include <iomanip>
#include <streambuf>
#include <cstdio>
#include <locale>
#include <clocale>
//#include <ciso646> //<ciso646> is not a standard header since C++20, use <version> to detect implementation-specific macros
#include <csetjmp>
#include <csignal>
#include <ctime>

//C++11
#include <cstdint>
#include <cinttypes>
#include <type_traits>
#include <initializer_list>
//#include <cstdalign> //非推奨
//#include <cstdbool> //非推奨
#include <scoped_allocator>
#include <system_error>
#include <regex>
#include <cuchar>
#include <array>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <chrono>
#include <ratio>
#include <random>
#include <cfenv>
//#include <codecvt> //非推奨
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
//#include <ccomplex> //非推奨
//#include <ctgmath> //非推奨

//C++14
#include <shared_mutex>

//C++17
#include <memory_resource>
#include <string_view>
#include <charconv>
#include <execution>
#include <optional>
#include <variant>
#include <any>
#include <filesystem>

//C++20
#include <concepts>
#include <coroutine>
#include <ranges>
#include <compare>
#include <format>
#include <span>
#include <numbers>
#include <bit>
#include <version>
#include <barrier>
#include <latch>
#include <semaphore>
#include <stop_token>
#include <source_location>
#include <syncstream>
#include <spanstream>

//C++23
#include <expected>
//#include <mdspan> //mdspan: No such file or directory
#include <print>
#include <generator>
#include <flat_map>
#include <flat_set>
//#include <stdatomic.h> //非推奨
#include <stacktrace>
#include <stdfloat>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> time(N + 2, 1); //最初と最後に1分間速度0で走ったとする
    for (int i = 0; i < N; i++) {
        std::cin >> time[i + 1];
        time[i + 1] *= 2; //交点をすべて格子点に
    }
    std::vector<int> velocity(N + 2, 0); //両端での速度は0
    for (int i = 0; i < N; i++) {
        std::cin >> velocity[i + 1];
        velocity[i + 1] *= 2; //交点をすべて格子点に
    }
    std::vector<int> time_sum(N + 3, 0);
    for (int i = 0; i < N + 2; i++) {
        time_sum[i + 1] = time_sum[i] + time[i];
    }
    std::vector<int> speed(time_sum[N + 2], 100000); //1秒ごとの速度の最大値
    for (int i = 0; i < time_sum[N + 2]; i++) {
        for (int j = 0; j < N + 2; j++) {
            int max_speed = velocity[j] + std::max(std::max(time_sum[j] - i, i - time_sum[j + 1]), 0);
            if (max_speed < speed[i]) {
                speed[i] = max_speed;
            }
        }
    }
    int sum = 0; //正しい値の4倍
    for (int i = 0; i < time_sum[N + 2]; i++) {
        sum += speed[i];
    }
    std::cout << std::fixed << std::setprecision(15);
    std::cout << (double)sum / 4.0 << '\n';
    return 0;
}
//AtCoder Express