#include <iostream>
#include <string>
const long long p = 1000000000 + 7;
const long long x_ = 257;

int main () {
    int d;
    std::string S;
    std::cin >> d >> S;
    S.insert(0, 1, ' ');
    int n = S.length();
    std::string reverse_S(n, ' ');
    for (int i = 1; i < n; i++)
        reverse_S[i] = S[n-i];

    long long h[n], x[n], h_r[n], x_r[n];
    h[0] = 0; x[0] = 1;
    h_r[0] = 0; x_r[0] = 1;

    for (int i = 1; i < n; i++) {
        h[i] = ((h[i-1] * x_) + (long long)S[i]) % p;
        x[i] = (x[i-1]*x_) % p;
        h_r[i] = ((h_r[i-1] * x_) + (long long)reverse_S[i]) % p;
        x_r[i] = (x_r[i-1]*x_) % p;
    }

    auto isEqual = [&](int posA, int posB, int len) {
        return ((h[posA + len] + h_r[posB] * x_r[len]) % p) ==
               ((h_r[posB + len] + h[posA] * x[len]) % p);
    };

    int z[n-1];
    for (int i = 1; i < n; i++) {
        int l = 0, r = i, m;
        while(l < r) {
            m = (l + r + 1) / 2;
            if (isEqual(0, n-1-i, m))
                l = m;
            else
                r = m - 1;
        }
        z[i-1] = l;
    }

    for (auto& i : z)
        std::cout << i << ' ';
    return 0;
}