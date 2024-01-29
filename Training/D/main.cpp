#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<char, unsigned int> symbols;
    std::string str1, str2;
    str1.reserve(100000);
    str2.reserve(100000);
    std::cin >> str1 >> str2;

    for (const auto& c : str1)
        symbols[c]++;
    for (const auto& c : str2) {
        if (symbols[c] == 0) {
            std::cout << "NO";
            return 0;
        }
        symbols[c]--;
    }
    std::cout << "YES" << std::endl;
    return 0;
}
