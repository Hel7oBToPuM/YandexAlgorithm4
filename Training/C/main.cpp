#define DOUBLE(x) static_cast<long double>(x)
#include <iostream>
#include <cmath>
#include <iomanip>
struct point {
    long long x;
    long long y;
} A, B;

int main() {
    std::cin >> A.x >> A.y >> B.x >> B.y;
    long long r_sqr_A = A.x * A.x + A.y * A.y, r_sqr_B = B.x * B.x + B.y * B.y; //квадраты расстояния до центра
    long double dist_through = std::sqrt(r_sqr_A)+std::sqrt(r_sqr_B);
    std::cout << std::setprecision(10);

    if ((B.y - A.y) * (0 - B.x) == (0 - B.y) * (B.x - A.x)) {
        std::cout << std::sqrt(std::pow(B.x-A.x, 2) + std::pow(B.y-A.y, 2));
    }
    else {
        if (r_sqr_A == r_sqr_B) {
            long double distance = 2 * std::sqrt(r_sqr_A) * std::asin(std::sqrt(std::pow(B.x-A.x, 2) + std::pow(B.y-A.y, 2)) / (2 * std::sqrt(r_sqr_A)));
            std::cout << (dist_through < distance ? dist_through : distance);
        }
        else if (r_sqr_A < r_sqr_B) {
            long double distance = 2 * std::sqrt(r_sqr_A);
            distance *= std::asin(std::sqrt(std::pow(B.x*std::sqrt(DOUBLE(r_sqr_A)/r_sqr_B)-A.x, 2) + std::pow(B.y*std::sqrt(DOUBLE(r_sqr_A)/r_sqr_B)-A.y, 2)) / (2 * std::sqrt(r_sqr_A)));
            distance += std::sqrt(r_sqr_B)-std::sqrt(r_sqr_A);
            std::cout << (dist_through < distance ? dist_through : distance);
        }
        else {
            long double distance = 2 * std::sqrt(r_sqr_B);
            distance *= std::asin(std::sqrt(std::pow(A.x*std::sqrt(DOUBLE(r_sqr_B)/r_sqr_A)-B.x, 2) + std::pow(A.y*std::sqrt(DOUBLE(r_sqr_B)/r_sqr_A)-B.y, 2)) / (2 * std::sqrt(r_sqr_B)));
            distance += std::sqrt(r_sqr_A)-std::sqrt(r_sqr_B);
            std::cout << (dist_through < distance ? dist_through : distance);
        }
    }
}
