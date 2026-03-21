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
void input(int i, int &M, std::vector<std::pair<int, int>> &data) {
    if (i == M) return;
    std::cin >> data[i].first >> data[i].second;
    input(i + 1, M, data);
}
void vec_initialize(int i, int &N, std::vector<int> &vec) {
    if (i == N) return;
    vec[i] = i + 1;
    vec_initialize(i + 1, N, vec);
}
void compare(int i, int &M, bool &OK, std::vector<std::pair<int, int>> &data, std::pair<int, int> &pair) {
    if (i == M) return;
    if (pair == data[i]) OK = true;
    compare(i + 1, M, OK, data, pair);
}
void trying(int i, int &N, int &M, bool &OK, bool &all_OK, std::vector<int> &vec, std::vector<std::pair<int, int>> &data, std::pair<int, int> &pair) {
    if (i == N - 1) return;
    pair = {std::min(vec[i], vec[i + 1]), std::max(vec[i], vec[i + 1])};
    OK = false;
    compare(0, M, OK, data, pair);
    if (OK == false) all_OK = false;
    if (all_OK) trying(i + 1, N, M, OK, all_OK, vec, data, pair);
    else return;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<int, int>> data(M, std::pair<int, int>(0, 0));
    input(0, M, data);
    std::vector<int> vec(N);
    vec_initialize(0, N, vec);
    bool OK = false;
    bool all_OK = true;
    std::pair<int, int> pair;
    int count = 0;
    do {
        if (vec[0] != 1) goto skip;
        all_OK = true;
        trying(0, N, M, OK, all_OK, vec, data, pair);
        if(all_OK) count++;
    } while(next_permutation(vec.begin(), vec.end()));
    skip:
    std::cout << count << '\n';
    return 0;
}
//One-stroke Path