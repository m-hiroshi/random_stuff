#include <algorithm>
#include <iostream>
#include <string>

void reverse_string(std::string &str) {
    std::reverse(str.begin(), str.end());
    auto it = str.rbegin();
    while (it != str.rend()) {
        if ((*it & 0b11100000) == 0b11000000) {
            std::reverse(it, it + 2);
            it += 2;
        } else if ((*it & 0b11110000) == 0b11100000) {
            std::reverse(it, it + 3);
            it += 3;
        } else if ((*it & 0b11111000) == 0b11110000) {
            std::reverse(it, it + 4);
            it += 4;
        } else {
            ++it;
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
