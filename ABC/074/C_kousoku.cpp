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

// 砂糖の構成 (C, D) から、各 mod C における最小の構成値を求める O(C)
std::vector<int> get_sugar_dist(int C, int D) {
    std::vector<int> dist(C, -1);
    dist[0] = 0;
    int g = std::gcd(C, D);
    // C と D で作れる値は必ず g の倍数。
    // Dijkstra的に最小値を確定させる
    for (int k = 0; k < 2; ++k) { // 2周で全余り確定
        for (int i = 0; i < C; ++i) {
            if (dist[i] == -1) continue;
            int next_val = dist[i] + D;
            int next_r = next_val % C;
            if (dist[next_r] == -1 || next_val < dist[next_r]) {
                dist[next_r] = next_val;
            }
        }
    }
    return dist;
}

int main() {
    int A, B, C, D, E, F;
    if (!(std::cin >> A >> B >> C >> D >> E >> F)) return 0;

    // 1. 作れる「水の量」を全列挙
    // (A, B) から 100A*i + 100B*j <= F となる全ての「水の総量」を求める
    // Fが非常に大きい場合はMod DPで「作れる最小」を出し、そこから上限まで走査
    std::vector<int> possible_waters;
    {
        // 重複排除のため set を使用（Fが中規模なら bool 配列でも可）
        // 100g 単位で考える
        std::vector<bool> can_w_unit(F / 100 + 1, false);
        for (int i = 0; i * A <= F / 100; ++i) {
            for (int j = 0; i * A + j * B <= F / 100; ++j) {
                if (i == 0 && j == 0) continue;
                can_w_unit[i * A + j * B] = true;
            }
        }
        for (int w = 1; w <= F / 100; ++w) {
            if (can_w_unit[w]) possible_waters.push_back(w * 100);
        }
    }

    // 2. 砂糖の Modulo DP データを準備
    std::vector<int> dist_sugar = get_sugar_dist(C, D);

    int best_w = 100 * A, best_s = 0;

    // 3. 列挙した各「水」に対して、O(C) で最適な「砂糖」を計算
    for (int water : possible_waters) {
        // 溶ける限界量 (水 w に対する上限)
        int sugar_limit = std::min((water / 100) * E, F - water);
        if (sugar_limit < 0) continue;

        int max_s = 0;
        // 各余り r について、limit 以下の最大値を O(C) で算出
        for (int r = 0; r < C; ++r) {
            int min_val = dist_sugar[r];
            if (min_val == -1 || min_val > sugar_limit) continue;
            // min_val に C を足せるだけ足した値が、その余りでの最大値
            int current_s = min_val + ((sugar_limit - min_val) / C) * C;
            max_s = std::max(max_s, current_s);
        }

        // 4. 厳密な濃度比較 (整数による積の比較)
        // s1/(w1+s1) > s2/(w2+s2)  <=>  s1*(w2+s2) > s2*(w1+s1)
        if (max_s * (best_w + best_s) > best_s * (water + max_s)) {
            best_w = water;
            best_s = max_s;
        } else if (best_s == 0 && max_s == 0) {
            // どちらも砂糖 0 なら、初期の水の量を維持（または任意）
        }
    }

    std::cout << best_w + best_s << " " << best_s << "\n";

    return 0;
}
//Sugar Water