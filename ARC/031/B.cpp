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
int whole_count = 0, a = 0, b = 0, c = 0, d = 0;
std::vector<std::vector<char>> data(10, std::vector<char>(10));
std::vector<std::vector<bool>> first(10, std::vector<bool>(10, false));
std::vector<std::vector<bool>> second(10, std::vector<bool>(10, false));
void input(int i, int j) {
    if (i == 10) return;
    std::cin >> data[i][j];
    if (data[i][j] == 'o') whole_count++;
    j == 9 ? input(i + 1, 0) : input(i, j + 1);
}
void first_cell (int i, int j) {
    if (i == 10) return;
    if (data[i][j] == 'o') {
        a = i;
        b = j;
        return;
    }
    j == 9 ? first_cell(i + 1, 0) : first_cell(i, j + 1);
}
void expand(int i, int j, int &count, std::vector<std::vector<bool>> &checked) {
    if (i == -1 || i == 10 || j == -1 || j == 10) return;
    if (checked[i][j]) return;
    if (data[i][j] == 'x') return;
    checked[i][j] = true;
    count++;
    expand(i - 1, j, count, checked);
    expand(i + 1, j, count, checked);
    expand(i, j - 1, count, checked);
    expand(i, j + 1, count, checked);
}
bool before_oneisland (int i, int j) {
    int count = 0;
    std::vector<std::vector<bool>> checked(10, std::vector<bool>(10, false));
    expand(i, j, count, checked);
    return (count == whole_count) ? true : false;
}
void first_island (int i, int j) {
    int e = 0;
    expand(i, j, e, first);
}
void second_cell (int i, int j) {
    if (i == 10) return;
    if (data[i][j] == 'o' && first[i][j] == false) {
        c = i;
        d = j;
        return;
    }
    j == 9 ? second_cell(i + 1, 0) : second_cell(i, j + 1);
}
void expand2(int i, int j, int &count, std::vector<std::vector<bool>> &checked) {
    if (i == -1 || i == 10 || j == -1 || j == 10) return;
    if (checked[i][j]) return;
    if (data[i][j] == 'x') return;
    if (first[i][j] == true) return;
    checked[i][j] = true;
    count++;
    expand2(i - 1, j, count, checked);
    expand2(i + 1, j, count, checked);
    expand2(i, j - 1, count, checked);
    expand2(i, j + 1, count, checked);
}
void second_island (int i, int j) {
    int f = 0;
    expand2(i, j, f, second);
} 
bool after_oneisland (int i, int j) {
    if (i == 10) return false;
    if (data[i][j] == 'x' && ((i != 0 && first[i - 1][j] == true) || (i != 9 && first[i + 1][j] == true) || (j != 0 && first[i][j - 1] == true) || (j != 9 && first[i][j + 1] == true)) && ((i != 0 && second[i - 1][j] == true) || (i != 9 && second[i + 1][j] == true) || (j != 0 && second[i][j - 1] == true) || (j != 9 && second[i][j + 1] == true))) {
        data[i][j] = 'o';
        int count = 0;
        std::vector<std::vector<bool>> checked(10, std::vector<bool>(10, false));
        expand(i, j, count, checked);
        data[i][j] = 'x';
        if (count == whole_count + 1) return true;
    }
    return j == 9 ? after_oneisland(i + 1, 0) : after_oneisland(i, j + 1);
}
void x() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    input(0, 0);
    first_cell(0, 0);
    if (before_oneisland(a, b)) std::cout << "YES" << '\n';
    else {
        first_island(a, b);
        second_cell(0, 0);
        second_island(c, d);
        std::cout << (after_oneisland(0, 0) ? "YES" : "NO") << '\n';
    }
}
int main() {x();}
//埋め立て