#include <iostream>
#include <array>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::array<bool, 26> arr{};
  std::vector<int> numbers(n);
  int used_letters_cnt = 0;
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    used_letters_cnt += !arr[num - 1];
    arr[num - 1] = true;
    if (used_letters_cnt == 26) {
      std::cout << i + 1;
      return 0;
    }
  }
  std::cout << "NONE";
  return 0;
}