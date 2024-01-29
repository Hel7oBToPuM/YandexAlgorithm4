#include <iostream>
#include <string>
const long long p = 1000000000 + 7;
const long long x_ = 257;

int main () {
    std::string S;
    std::cin >> S;
    S.insert(0, 1, ' ');
    int n = S.length();
    long long h[n], x[n];
    h[0] = 0; x[0] = 1;

    for (int i = 1; i < n; i++) {
        h[i] = ((h[i-1] * x_) + (long long)S[i]) % p;
        x[i] = (x[i-1]*x_) % p;
    }

    auto isEqual = [&](int posA, int posB, int len) {
        return ((h[posA + len] + h[posB] * x[len]) % p) ==
               ((h[posB + len] + h[posA] * x[len]) % p);
    };

    for (int len = n - 2; len > 0; len--)
        if (isEqual(0, n - len - 1, len)) {
            std::cout << n - len - 1;
            return 0;
        }

    std::cout << n - 1;
    return 0;
}
