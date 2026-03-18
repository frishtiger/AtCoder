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
    int N, M, x;
    std::cin >> N;
    std::bitset<50> A, B, C;
    for (int i = 0; i < N; i++) {
        std::cin >> x;
        A.set(x);
    }
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> x;
        B.set(x);
    }
    std::string command;
    std::cin >> command;
    bool p = false;
    if (command == "intersection") C = A & B;
    else if (command == "union_set") C = A | B;
    else if (command == "symmetric_diff") C = A ^ B;
    else if (command == "increment") {
        if (A[49] == 1) p = true;
        A <<= 1;
        if (p == true) A.set(0);
        C = A;
    }
    else if (command == "decrement") {
        if (A[0] == 1) p = true;
        A >>= 1;
        if (p == true) A.set(49);
        C = A;
    }
    else {
        std::cin >> x;
        A.reset(x);
        C = A;
    }
    p = false;
    for (int i = 0; i < 50; i++) {
        if (C[i] == 1) {
            if (p == true) std::cout << ' ' << i;
            else std::cout << i;
            p = true;
        }
    }
    std::cout << '\n';
    return 0;
}
//集合の操作