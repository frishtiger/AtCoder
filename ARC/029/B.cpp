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
    int A, B, N;
    std::cin >> A >> B >> N;
    std::vector<int> C(N), D(N);
    for (int i = 0; i < N; i++) {
        std::cin >> C[i] >> D[i];
    }
    if (A < B) std::swap(A, B);
    for (int i = 0; i < N; i++) {
        if (C[i] < D[i]) std::swap(C[i], D[i]);
    }
    std::vector<bool> OK(N, false);
    for (int i = 0; i < N; i++) {
        if (A <= C[i] && B <= D[i]) OK[i] = true;
        else if ((A > C[i]) && ((__int128)A * (__int128)A + (__int128)B * (__int128)B <= (__int128)C[i] * (__int128)C[i] + (__int128)D[i] * (__int128)D[i]) && (((__int128)C[i] * (__int128)C[i] + (__int128)D[i] * (__int128)D[i]) * ((__int128)A * (__int128)A + (__int128)B * (__int128)B) - 4 * (__int128)A * (__int128)B * (__int128)C[i] * (__int128)D[i] >= ((__int128)A * (__int128)A - (__int128)B * (__int128)B) * ((__int128)A * (__int128)A - (__int128)B * (__int128)B))) OK[i] = true;
    }
    for (int i = 0; i < N; i++) {
        std::cout << (OK[i] ? "YES" : "NO") << '\n';
    }
}
//高橋君と禁断の書