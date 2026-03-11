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
    long long Acin, A, A10, bannedA;
    std::vector<int> vecA;
    long long countA = 0;
    std::cin >> Acin;
    A = Acin - 1;
    A10 = A;
    int Abanned = 0;
    while (true) {
        vecA.push_back (A10 % 10);
        if (A10 % 10 == 4 || A10 % 10 == 9) Abanned = 1;
        A10 /= 10;
        if (A10 == 0) break;
    }
    reverse (vecA.begin(), vecA.end());
    int x = 0;
    long long a = 1;
    if (vecA.size() != 1) {
        for (int i = 0; i < vecA.size() - 1; i++) a *= 8;
    }
    for (int i = 0; i < vecA.size(); i++) {
        if (vecA[i] == 0 || vecA[i] == 1 || vecA[i] == 2 || vecA[i] == 3 || vecA[i] == 4) x = vecA[i];
        else if (vecA[i] == 5 || vecA[i] == 6 || vecA[i] == 7 || vecA[i] == 8 || vecA[i] == 9) x = vecA[i] - 1;
        countA += x * a;
        if (vecA[i] == 4 || vecA[i] == 9) break;
        a /= 8;
    }
    bannedA = A - countA + Abanned;
    long long B, B10, bannedB;
    std::vector<int> vecB;
    long long countB = 0;
    std::cin >> B;
    B10 = B;
    int Bbanned = 0;
    while (true) {
        vecB.push_back (B10 % 10);
        if (B10 % 10 == 4 || B10 % 10 == 9) Bbanned = 1;
        B10 /= 10;
        if (B10 == 0) break;
    }
    reverse (vecB.begin(), vecB.end());
    long long b = 1;
    if (vecB.size() != 1) {
        for (int i = 0; i < vecB.size() - 1; i++) b *= 8;
    }
    for (int i = 0; i < vecB.size(); i++) {
        if (vecB[i] == 0 || vecB[i] == 1 || vecB[i] == 2 || vecB[i] == 3 || vecB[i] == 4) x = vecB[i];
        else if (vecB[i] == 5 || vecB[i] == 6 || vecB[i] == 7 || vecB[i] == 8 || vecB[i] == 9) x = vecB[i] - 1;
        countB += x * b;
        if (vecB[i] == 4 || vecB[i] == 9) break;
        b /= 8;
    }
    bannedB = B - countB + Bbanned;
    long long banned = bannedB - bannedA;
    std::cout << banned << std::endl;
    return 0;
}
//禁止された数字