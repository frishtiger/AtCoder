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
    std::string S;
    std::cin >> S;
    bool can = true;
    int i;
    if (S.size() <5) can = false;
    else if (S.size() == 5 && (S[0] != 'd' || S[1] != 'r' || S[2] != 'e' || S[3] != 'a' || S[4] != 'm') && (S[0] != 'e' || S[1] != 'r' || S[2] != 'a' || S[3] != 's' || S[4] != 'e')) can = false;
    else if (S.size() == 6 && (S[0] != 'e' || S[1] != 'r' || S[2] != 'a' || S[3] != 's' || S[4] != 'e' || S[5] != 'r')) can = false;
    else if (S.size() == 7 && (S[0] != 'd' || S[1] != 'r' || S[2] != 'e' || S[3] != 'a' || S[4] != 'm' || S[5] != 'e' || S[6] != 'r')) can = false;
    else {
        for (i = 0; i < S.size() - 7;) {
            if (S[i] == 'd' && S[i + 1] == 'r' && S[i + 2] == 'e' && S[i + 3] == 'a' && S[i + 4] == 'm') {
                if (S[i + 5] == 'd') i+= 5;
                else if (S[i + 5] == 'e' && S[i + 6] == 'r') {
                    if (S[i + 7] == 'a') i += 5;
                    else if (S[i + 7] == 'd' || S[i + 7] == 'e') i += 7;
                    else can = false;
                }
                else can = false;
            }
            else if (S[i] == 'e' && S[i + 1] == 'r' && S[i + 2] == 'a' && S[i + 3] == 's' && S[i + 4] == 'e') {
                if (S[i + 5] == 'd' || S[i + 5] == 'e') i += 5;
                else if (S[i + 5] == 'r') i += 6;
                else can = false;
            }
            else can = false;
            if (can == false) break;
        }
        if (i != S.size() - 7 && i != S.size() - 6 && i != S.size() - 5) can = false;
        else if (i == S.size() - 7 && (S[i] != 'd' || S[i + 1] != 'r' || S[i + 2] != 'e' || S[i + 3] != 'a' || S[i + 4] != 'm' || S[i + 5] != 'e' || S[i + 6] != 'r')) can = false;
        else if (i == S.size() - 6 && (S[i] != 'e' || S[i + 1] != 'r' || S[i + 2] != 'a' || S[i + 3] != 's' || S[i + 4] != 'e' || S[i + 5] != 'r')) can = false;
        else if (i == S.size() - 5 && (S[i] != 'd' || S[i + 1] != 'r' || S[i + 2] != 'e' || S[i + 3] != 'a' || S[i + 4] != 'm') && (S[i] != 'e' || S[i + 1] != 'r' || S[i + 2] != 'a' || S[i + 3] != 's' || S[i + 4] != 'e')) can = false;
    }
    std::cout << (can ? "YES" : "NO") << '\n';
    return 0;
}
//白昼夢