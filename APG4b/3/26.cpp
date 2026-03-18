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

// 問題文の形式でvec値を出力
void print_vec(std::vector<int> vec) {
  std::cout << "[ ";
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << "]\n";
}

// 変数名を読み取りイコールを読み飛ばす
std::string read_name() {
  std::string name, equal;
  std::cin >> name >> equal;
  return name;
}

// int式の項を1つ読み取る。
// 数字ならその値を返し、そうでないなら変数として解釈し変数の値を返す
// var_int : intの変数を保持するmap
int read_int(std::map<std::string, int> &var_int) {
  std::string val;
  std::cin >> val;

  // 最初の文字が数字かどうかで数字か変数かを判定（3.06で紹介した条件演算子を使用。if文で書いても良い。）
  return isdigit(val[0])
    ? std::stoi(val) // 数値の場合
    : var_int[val]; // 変数の場合

  // isdigit関数は3.06で、stoi関数は3.01で紹介している
  // これらを使わず自分で変換する処理を書いても良い
}

// int式全体を読み取って計算する
// var_int : intの変数を保持するmap
int calc_int(std::map<std::string, int> &var_int) {

  std::string symbol = ""; // 演算子を受け取る変数
  int result = 0; // 結果を保持する変数

  // 式の終わりである";"が出てくるまで読み取る
  while (symbol != ";") {
    // 項を1つ読み取る
    int val = read_int(var_int);

    // 記号が入力されてない場合（式の最初の項）は結果にそのまま代入
    if (symbol == "") {
      result = val;
    }
    // 足し算の場合
    if (symbol == "+") {
      result += val;
    }
    // 引き算の場合
    if (symbol == "-") {
      result -= val;
    }

    // symbolには"+", "-", ";"のいずれかが入力される
    std::cin >> symbol;
  }

  return result;
}

// vec値を読み取る
// 最初の"["は読み取ってある前提であることに注意
// var_int : intの変数を保持するmap
std::vector<int> read_vec_val(std::map<std::string, int> &var_int) {

  std::vector<int> result; // 結果を保持する変数
  std::string symbol = ""; // vec値中の記号を受け取る変数

  // vec値の終わりである"]"が出てくるまで読み取る
  while (symbol != "]") {
    // 数値を1つ読み取ってvecに追加
    int val = read_int(var_int);
    result.push_back(val);

    // symbolには","か"]"が入力される
    std::cin >> symbol;
  }

  return result;
}

// vec式の項を1つ読み取る
// vec値ならその値を返し、そうでないなら変数として解釈し変数の値を返す
// var_int : intの変数を保持するmap
// var_vec : vecの変数を保持するmap
std::vector<int> read_vec(std::map<std::string, int> &var_int, std::map<std::string, std::vector<int>> &var_vec) {

  std::string val;
  std::cin >> val;

  // "["かどうかでvec値か変数かを判定（3.06で紹介した条件演算子を使用。if文で書いても良い。）
  return val == "["
    ? read_vec_val(var_int) // vec値の場合
    : var_vec[val]; // 変数の場合
}

// vec式全体を読み取って計算する
// var_int : intの変数を保持するmap
// var_vec : vecの変数を保持するmap
std::vector<int> calc_vec(std::map<std::string, int> &var_int, std::map<std::string, std::vector<int>> &var_vec) {

  std::string symbol; // 演算子を受け取る変数
  std::vector<int> result; // 結果を保持する変数

  // 式の終わりである";"が出てくるまで読み取る
  while (symbol != ";") {

    // 項を1つ読み取る
    std::vector<int> vec = read_vec(var_int, var_vec);

    // 記号が入力されてない場合（式の最初の項）は結果にそのまま代入
    if (symbol == "") {
      result = vec;
    }
    // 足し算の場合
    if (symbol == "+") {
      for (size_t i = 0; i < result.size(); i++) {
        result[i] += vec[i];
      }
    }
    // 引き算の場合
    if (symbol == "-") {
      for (size_t i = 0; i < result.size(); i++) {
        result[i] -= vec[i];
      }
    }

    // symbolには"+", "-", ";"のいずれかが入力される
    std::cin >> symbol;
  }

  return result;
}

int main() {

  // 命令の行数を取得
  int N;
  std::cin >> N;

  std::map<std::string, int> var_int; // intの変数を管理するmap
  std::map<std::string, std::vector<int>> var_vec; // vectorの変数を管理するmap

  // 行数分の処理
  for (int i = 0; i < N; i++) {

    // 命令を受け取る
    std::string s;
    std::cin >> s;

    // int命令の処理
    if (s == "int") {
      // 変数名を読み取る
      std::string name = read_name();
      // 右辺の式を計算して変数に代入
      var_int[name] = calc_int(var_int);
    }

    // vec命令の処理
    if (s == "vec") {
      // 変数名を読み取る
      std::string name = read_name();
      // 右辺の式を計算して変数に代入
      var_vec[name] = calc_vec(var_int, var_vec);
    }

    // print_int命令の処理
    if (s == "print_int") {
      // 式を計算して出力
      std::cout << calc_int(var_int) << '\n';
    }

    // print_vec命令の処理
    if (s == "print_vec") {
      // 式を計算して出力
      print_vec(calc_vec(var_int, var_vec));
    }
  }
}

//電卓を作ろう3