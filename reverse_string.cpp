#include <iostream>
#include <string>
#include <algorithm>

inline void reverse(std::string& str, int first, int last) {
  while (first < last) {
    std::swap(str[first++], str[last--]);
  }
}

void reverse_string(std::string& str) {
  reverse(str, 0, str.size()-1);
  for (int i = str.size()-1; i > 0; --i) {
    if ((str[i] & 0b11100000) == 0b11000000) {
      reverse(str, i-1, i);
      i -= 1;
    } else if ((str[i] & 0b11110000) == 0b11100000) {
      reverse(str, i-2, i);
      i -= 2;
    } else if ((str[i] & 0b11111000) == 0b11110000) {
      reverse(str, i-3, i);
      i -= 3;
    }
  }
}

int main() {
  std::string str;
  std::getline(std::cin, str);
  
  reverse_string(str);
  std::cout << str << '\n';
  
  return 0;
}

