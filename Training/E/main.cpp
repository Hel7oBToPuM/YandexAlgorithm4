#include <iostream>
#include <vector>

int main() {
    int n, sum = 0;
    std::cin >> n;
    std::vector<int> stud_rating(n), stud_complaint(n);

    for (int i = 0; i < n; i++) {
        std::cin >> stud_rating[i];
        sum += stud_rating[i];
    }
    for (int i = 0; i < n; i++) {
        stud_complaint[i] = sum - (n-2*i) * stud_rating[i];
        sum -= 2*stud_rating[i];
    }

    for (const auto& r: stud_complaint)
        std::cout << r << ' ';
    return 0;
}