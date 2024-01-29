#include <iostream>

int main() {
    unsigned short  a, b, c, d;
    std::cin >> a >> b >> c >> d;
    unsigned short n = b * d; // знаменатель
    unsigned short m = a * d + b * c; // числитель
    unsigned short n_ = n, m_ = m;
    while (n_ != 0 && m_ != 0)
        if (n_ > m_)
            n_ = n_ % m_;
        else
            m_ = m_ % n_;
    std::cout << m/(m_ + n_) << ' ' << n/(m_ + n_) << '\n';
}
