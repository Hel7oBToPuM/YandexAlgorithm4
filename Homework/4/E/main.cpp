#include <iostream>
#include <vector>
int n;
std::vector<std::string> sd;

const std::string open = "([";
const std::string close = ")]";

void generate(int pos, std::vector<char> stack, std::string& str) {
    if (stack.size() < n - pos) {
        for (auto& c : open) {
            stack.push_back(c);
            str[pos] = c;
            generate(++pos, stack, str);
            stack.pop_back();
            --pos;
        }
    }
    if (!stack.empty()) {
        str[pos] = (stack.back() == '(' ? ')' : ']');
        stack.pop_back();
        if (pos == n - 1)
            sd.push_back(str);
        else {
            generate(++pos, stack, str);
            --pos;
        }
    }
    else
        --pos;
}

int main () {
    std::cin >> n;
    std::vector<char> stack;
    std::string buf(n, ' ');
    if (n % 2 == 0)
        generate(0, stack, buf);
    for (auto& i : sd)
        std::cout << i << '\n';
    return 0;
}