#include <iostream>
#include <string>
#include <vector>
#include <map>

const std::map<char, char> brackets {{'{', '}'}, {'(', ')'}, {'[', ']'}};

int main() {
    std::string sequence;
    std::cin >> sequence;
    std::vector<char> stack;

    for (char s: sequence) {
        if (brackets.contains(s))
            stack.push_back(s);
        else if (!stack.empty() && brackets.at(stack.back()) == s)
            stack.pop_back();
        else {
            std::cout << "no";
            return 0;
        }
    }

    std::cout << (stack.empty() ? "yes" : "no");
    return 0;
}