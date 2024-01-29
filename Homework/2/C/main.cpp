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

    int z[n-1];
    z[0] = 0;
    for (int i = 1; i < n-1; i++) {
        int l = 0, r = n - 1 - i, m;
        while(l < r) {
            m = (l + r + 1) / 2;
            if (isEqual(0, i, m))
                l = m;
            else
                r = m - 1;
        }
        z[i] = l;
    }

    for (auto& i : z)
        std::cout << i << ' ';
    return 0;
}
