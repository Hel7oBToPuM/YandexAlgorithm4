#include <iostream>
#include <vector>

int main() {
    int a, b, n;
    std::cin >> a >> b >> n;
    std::cout << (a > b / n + ((b % n) ? 1 : 0) ? "Yes" : "No");
    return 0;
}