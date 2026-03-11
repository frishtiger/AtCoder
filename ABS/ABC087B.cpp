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
// 数学的に正しい floor(a / b), b > 0
long long floordiv(long long a, long long b) {
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
}

// 数学的に正しい ceil(a / b), b > 0
long long ceildiv(long long a, long long b) {
    if (a >= 0) return (a + b - 1) / b;
    return -((-a) / b);
}

// sum_{a=l..r} (p*a + q) を計算する（区間内ですべて非負であることが前提）
long long sum_arithmetic(long long p, long long q, long long l, long long r) {
    if (l > r) return 0;
    long long n = r - l + 1;
    long long first = p * l + q;
    long long last = p * r + q;
    return n * (first + last) / 2;
}

// a を固定したときの b の個数 f(a) = max(0, R(a) - L(a) + 1)
long long get_f(long long a, long long K, long long B, long long C) {
    long long Ra = std::min(B, floordiv(K - 10 * a, 2));
    long long La = std::max(0LL, ceildiv(K - 10 * a - C, 2));
    return std::max(0LL, Ra - La + 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long A, B, C, X;
    if (!(std::cin >> A >> B >> C >> X)) return 0;

    long long K = X / 50;
    long long a_max_limit = std::min(A, K / 10);

    // 境界点のリスト
    std::vector<long long> pts = {-1, 0, a_max_limit};
    
    // 式が折れ曲がる、または 0 になる可能性のあるポイントを列挙
    auto add_point = [&](long long v) {
        // 周辺 2 マスを含めることで、整数除算の不連続性を区間分割で吸収する
        for (long long d = -2; d <= 2; ++d) {
            if (v + d >= -1 && v + d <= a_max_limit) {
                pts.push_back(v + d);
            }
        }
    };

    add_point(floordiv(K, 10));                 // Ra が 0 付近
    add_point(ceildiv(K - 2 * B, 10));          // Ra が B 付近
    add_point(floordiv(K - C, 10));              // La が 0 付近
    add_point(ceildiv(K - C - 2 * B, 10));      // La が B 付近

    std::sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    long long total_ans = 0;

    for (int i = 0; i + 1 < (int)pts.size(); i++) {
        long long l = pts[i] + 1;
        long long r = pts[i + 1];
        if (l > r) continue;

        long long f_l = get_f(l, K, B, C);
        if (l == r) {
            total_ans += f_l;
        } else {
            long long l2 = l + 1;
            long long f_l2 = get_f(l2, K, B, C);

            // この区間 [l, r] で f(a) = p*a + q が成立するか確認
            // もし f(l) と f(l+1) が共に 0 なら、その区間はすべて 0
            if (f_l == 0 && f_l2 == 0) {
                continue;
            }
            
            // 2点から 1次式 f(a) = p*a + q を復元
            long long p = f_l2 - f_l;
            long long q = f_l - p * l;
            
            // 区間全体が線形であることを利用して和を計算
            total_ans += sum_arithmetic(p, q, l, r);
        }
    }

    std::cout << total_ans << '\n';
    return 0;
}