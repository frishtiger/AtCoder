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
    int N, K;
    std::cin >> N >> K;
    std::cout << ((N == 1) ? 2 : (N == 2) ? ((K == 1) ? 3 : 4) : (N == 3) ? ((K == 1) ? 4 : (K == 2) ? 6 : (K == 3) ? 7 : 8) : (N == 4) ? ((K == 1) ? 5 : (K == 2) ? 8 : (K == 3) ? 10 : (K == 4) ? 12 : (K == 5) ? 13 : (K == 6) ? 14 : (K == 7) ? 15 : 16) : ((K == 1) ? (N + 1) : (K == 2) ? (2 * N) : (K == 3) ? (3 * N - 2) : (K == 4) ? (4 * N - 4) : (K == 5) ? (5 * N - 7) : (K == 6) ? (6 * N - 10) : (K == 7) ? (7 * N - 13) : (K == 8) ? (8 * N - 16) : (K == 9) ? (9 * N - 20) : (10 * N - 24))) << '\n';
}
//Addition and Multiplication
