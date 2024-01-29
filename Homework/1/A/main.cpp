#include <iostream>

int main () {
    int N;
    std::cin >> N;

    long int array[N];
    for (int i = 0; i < N; i++)
        std::cin >> array[i];

    long int x;
    std::cin >> x;

    int lower = 0, other = 0;

    for (const auto& elem : array)
        elem < x ? lower++ : other++;
    std::cout << lower << '\n' << other;
    return 0;
}