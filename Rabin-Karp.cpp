#include <iostream>
#include <string>
#include <string_view>

void RkSearch(std::string_view str, const std::string_view pat) {
  auto hash_func = std::hash<std::string_view>{};
  size_t p_hash = hash_func(pat);
  for (int i = 0; i < str.size() - pat.size() + 1; ++i) {
    std::string_view substr = str.substr(i, pat.size());
    if (hash_func(substr) == p_hash && substr == pat) {
      std::cout << "Found pattern at index " << i << "\n";
    } 
  }
}

int main() {
  std::string str;
  std::string pat;
  std::cout << "KMP algorithm: search occurences of a pattern in a string in O(n) time\n" 
            << "----------------------------------------------------------------------\n"
            << "string:" << std::endl;
  std::getline(std::cin, str);
  std::cout << "pattern:" << std::endl;
  std::getline(std::cin, pat);
  RkSearch(str, pat);
  return 0;
}
