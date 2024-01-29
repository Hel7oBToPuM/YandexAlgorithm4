#include <iostream>
#include <string>
#include <vector>

const long long p = 1000000000 + 7;
const long long x_ = 257;

int main () {
    std::string S {" #"};
    char c;
    int answer = 0;
    while(std::cin.get(c) && c != '\n') {
        S.push_back(c);
        S.push_back('#');
        answer++;
    }
    int n = S.length();
    std::string reverse_S(n,' ');
    for (int i = 1; i < n; i++)
        reverse_S[i] = S[n-i];

    std::vector<long long> h(n), x(n), h_r(n), x_r(n);
    h[0] = 0; x[0] = 1;
    h_r[0] = 0; x_r[0] = 1;
    for (int i = 1; i < n; i++) {
        h[i] = ((h[i-1] * x_) + S[i]) % p;
        x[i] = (x[i-1]*x_) % p;

        h_r[i] = ((h_r[i-1] * x_) + reverse_S[i]) % p;
        x_r[i] = (x_r[i-1]*x_) % p;
    }

    auto isEqual = [&](int posA, int posB, int len) {
        return ((h[posA + len] + h_r[posB] * x_r[len]) % p) ==
               ((h_r[posB + len] + h[posA] * x[len]) % p);
    };

    for (int i = 3; i < n-2; i++) {
        int l = 0, r = (i < n/2 ? i : n-i) - 1, m;
        while(l < r) {
            m = (l + r + 1) / 2;
            if (isEqual(i-1-m, (n-1)-i-m, m))
                l = m;
            else
                r = m - 1;
        }
            answer += l/2;
    }
    std::cout << answer;
}

