#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        unsigned long n, a, b;
        std::cin >> n >> a >> b;
        std::cout << ((a <= n && n / a * b >= n) ? "YES\n" : "NO\n") << std::endl;
    }
    return 0;
}
