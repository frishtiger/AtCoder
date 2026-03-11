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
    int N;
    std::cin >> N;
    std::cout << (N==1 ? 1 : N==2 ? 3 : N==3 ? 4 : N==4 ? 7 : N==5 ? 11 : N==6 ? 18 : N==7 ? 29 : N==8 ? 47 : N==9 ? 76 : N==10 ? 123 : N==11 ? 199 : N==12 ? 322 : N==13 ? 521 : N==14 ? 843 : N==15 ? 1364 : N==16 ? 2207 : N==17 ? 3571 : N==18 ? 5778 : N==19 ? 9349 : N==20 ? 15127 : N==21 ? 24476 : N==22 ? 39603 : N==23 ? 64079 : N==24 ? 103682 : N==25 ? 167761 : N==26 ? 271443 : N==27 ? 439204 : N==28 ? 710647 : N==29 ? 1149851 : N==30 ? 1860498 : N==31 ? 3010349 : N==32 ? 4870847 : N==33 ? 7881196 : N==34 ? 12752043 : N==35 ? 20633239 : N==36 ? 33385282 : N==37 ? 54018521 : N==38 ? 87403803 : N==39 ? 141422324 : N==40 ? 228826127 : N==41 ? 370248451 : N==42 ? 599074578 : N==43 ? 969323029 : N==44 ? 1568397607 : N==45 ? 2537720636LL : N==46 ? 4106118243LL : N==47 ? 6643838879LL : N==48 ? 10749957122LL : N==49 ? 17393796001LL : N==50 ? 28143753123LL : N==51 ? 45537549124LL : N==52 ? 73681302247LL : N==53 ? 119218851371LL : N==54 ? 192900153618LL : N==55 ? 312119004989LL : N==56 ? 505019158607LL : N==57 ? 817138163596LL : N==58 ? 1322157322203LL : N==59 ? 2139295485799LL : N==60 ? 3461452808002LL : N==61 ? 5600748293801LL : N==62 ? 9062201101803LL : N==63 ? 14662949395604LL : N==64 ? 23725150497407LL : N==65 ? 38388099893011LL : N==66 ? 62113250390418LL : N==67 ? 100501350283429LL : N==68 ? 162614600673847LL : N==69 ? 263115950957276LL : N==70 ? 425730551631123LL : N==71 ? 688846502588399LL : N==72 ? 1114577054219522LL : N==73 ? 1803423556807921LL : N==74 ? 2918000611027443LL : N==75 ? 4721424167835364LL : N==76 ? 7639424778862807LL : N==77 ? 12360848946698171LL : N==78 ? 20000273725560978LL : N==79 ? 32361122672259149LL : N==80 ? 52361396397820127LL : N==81 ? 84722519070079276LL : N==82 ? 137083915467899403LL : N==83 ? 221806434537978679LL : N==84 ? 358890350005878082LL : N==85 ? 580696784543856761LL : 939587134549734843LL) << '\n';
}
//Lucas Number
/*
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    if (N == 1) std::cout << 1 << '\n';
    else if (N == 2) std::cout << 3 << '\n';
    else if (N == 3) std::cout << 4 << '\n';
    else if (N == 4) std::cout << 7 << '\n';
    else if (N == 5) std::cout << 11 << '\n';
    else if (N == 6) std::cout << 18 << '\n';
    else if (N == 7) std::cout << 29 << '\n';
    else if (N == 8) std::cout << 47 << '\n';
    else if (N == 9) std::cout << 76 << '\n';
    else if (N == 10) std::cout << 123 << '\n';
    else if (N == 11) std::cout << 199 << '\n';
    else if (N == 12) std::cout << 322 << '\n';
    else if (N == 13) std::cout << 521 << '\n';
    else if (N == 14) std::cout << 843 << '\n';
    else if (N == 15) std::cout << 1364 << '\n';
    else if (N == 16) std::cout << 2207 << '\n';
    else if (N == 17) std::cout << 3571 << '\n';
    else if (N == 18) std::cout << 5778 << '\n';
    else if (N == 19) std::cout << 9349 << '\n';
    else if (N == 20) std::cout << 15127 << '\n';
    else if (N == 21) std::cout << 24476 << '\n';
    else if (N == 22) std::cout << 39603 << '\n';
    else if (N == 23) std::cout << 64079 << '\n';
    else if (N == 24) std::cout << 103682 << '\n';
    else if (N == 25) std::cout << 167761 << '\n';
    else if (N == 26) std::cout << 271443 << '\n';
    else if (N == 27) std::cout << 439204 << '\n';
    else if (N == 28) std::cout << 710647 << '\n';
    else if (N == 29) std::cout << 1149851 << '\n';
    else if (N == 30) std::cout << 1860498 << '\n';
    else if (N == 31) std::cout << 3010349 << '\n';
    else if (N == 32) std::cout << 4870847 << '\n';
    else if (N == 33) std::cout << 7881196 << '\n';
    else if (N == 34) std::cout << 12752043 << '\n';
    else if (N == 35) std::cout << 20633239 << '\n';
    else if (N == 36) std::cout << 33385282 << '\n';
    else if (N == 37) std::cout << 54018521 << '\n';
    else if (N == 38) std::cout << 87403803 << '\n';
    else if (N == 39) std::cout << 141422324 << '\n';
    else if (N == 40) std::cout << 228826127 << '\n';
    else if (N == 41) std::cout << 370248451 << '\n';
    else if (N == 42) std::cout << 599074578 << '\n';
    else if (N == 43) std::cout << 969323029 << '\n';
    else if (N == 44) std::cout << 1568397607 << '\n';
    else if (N == 45) std::cout << 2537720636LL << '\n';
    else if (N == 46) std::cout << 4106118243LL << '\n';
    else if (N == 47) std::cout << 6643838879LL << '\n';
    else if (N == 48) std::cout << 10749957122LL<< '\n';
    else if (N == 49) std::cout << 17393796001LL<< '\n';
    else if (N == 50) std::cout << 28143753123LL<< '\n';
    else if (N == 51) std::cout << 45537549124LL<< '\n';
    else if (N == 52) std::cout << 73681302247LL<< '\n';
    else if (N == 53) std::cout << 119218851371LL<< '\n';
    else if (N == 54) std::cout << 192900153618LL<< '\n';
    else if (N == 55) std::cout << 312119004989LL<< '\n';
    else if (N == 56) std::cout << 505019158607LL<< '\n';
    else if (N == 57) std::cout << 817138163596LL<< '\n';
    else if (N == 58) std::cout << 1322157322203LL<< '\n';
    else if (N == 59) std::cout << 2139295485799LL<< '\n';
    else if (N == 60) std::cout << 3461452808002LL<< '\n';
    else if (N == 61) std::cout << 5600748293801LL<< '\n';
    else if (N == 62) std::cout << 9062201101803LL<< '\n';
    else if (N == 63) std::cout << 14662949395604LL<< '\n';
    else if (N == 64) std::cout << 23725150497407LL<< '\n';
    else if (N == 65) std::cout << 38388099893011LL<< '\n';
    else if (N == 66) std::cout << 62113250390418LL<< '\n';
    else if (N == 67) std::cout << 100501350283429LL<< '\n';
    else if (N == 68) std::cout << 162614600673847LL<< '\n';
    else if (N == 69) std::cout << 263115950957276LL<< '\n';
    else if (N == 70) std::cout << 425730551631123LL<< '\n';
    else if (N == 71) std::cout << 688846502588399LL<< '\n';
    else if (N == 72) std::cout << 1114577054219522LL<< '\n';
    else if (N == 73) std::cout << 1803423556807921LL<< '\n';
    else if (N == 74) std::cout << 2918000611027443LL<< '\n';
    else if (N == 75) std::cout << 4721424167835364LL<< '\n';
    else if (N == 76) std::cout << 7639424778862807LL<< '\n';
    else if (N == 77) std::cout << 12360848946698171LL<< '\n';
    else if (N == 78) std::cout << 20000273725560978LL<< '\n';
    else if (N == 79) std::cout << 32361122672259149LL<< '\n';
    else if (N == 80) std::cout << 52361396397820127LL<< '\n';
    else if (N == 81) std::cout << 84722519070079276LL<< '\n';
    else if (N == 82) std::cout << 137083915467899403LL<< '\n';
    else if (N == 83) std::cout << 221806434537978679LL<< '\n';
    else if (N == 84) std::cout << 358890350005878082LL<< '\n';
    else if (N == 85) std::cout << 580696784543856761LL<< '\n';
    else std::cout << 939587134549734843LL<< '\n';
    return 0;
}
*/
//Lucas Number
/*
1
3
4
7
11
18
29
47
76
123
199
322
521
843
1364
2207
3571
5778
9349
15127
24476
39603
64079
103682
167761
271443
439204
710647
1149851
1860498
3010349
4870847
7881196
12752043
20633239
33385282
54018521
87403803
141422324
228826127
370248451
599074578
969323029
1568397607
2537720636
4106118243
6643838879
10749957122
17393796001
28143753123
45537549124
73681302247
119218851371
192900153618
312119004989
505019158607
817138163596
1322157322203
2139295485799
3461452808002
5600748293801
9062201101803
14662949395604
23725150497407
38388099893011
62113250390418
100501350283429
162614600673847
263115950957276
425730551631123
688846502588399
1114577054219522
1803423556807921
2918000611027443
4721424167835364
7639424778862807
12360848946698171
20000273725560978
32361122672259149
52361396397820127
84722519070079276
137083915467899403
221806434537978679
358890350005878082
580696784543856761
939587134549734843
*/
//Lucas Number