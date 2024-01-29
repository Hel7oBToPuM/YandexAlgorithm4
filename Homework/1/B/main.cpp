#include <iostream>
#include <random>
#include <algorithm>

std::random_device rd;
std::mt19937 gen(rd());

std::pair<long*, long*> partition(long *arr_l, long *arr_r, const long x) {
    long *E = arr_l, *G = arr_l, *N = arr_l;
    for (; N != arr_r + 1; N++) {
        if (*N < x) {
            if (G != N)
                std::swap(*G, *N);
            if (E != G)
                std::swap(*E, *G);
            E++; G++;
        }
        else if (*N == x) {
            if (G != N)
                std::swap(*G, *N);
            G++;
        }
    }
    return std::pair<long*, long*>{E, G};
}

void quicksort(long int* arr_l, long int* arr_r) {
    std::uniform_int_distribution<> dis(0, arr_r - arr_l);
    std::pair<long*, long*> p = partition(arr_l, arr_r, *(arr_l + dis(gen)));
    if (p.first-1 - arr_l > 0)
        quicksort(arr_l, p.first-1);
    if (arr_r - p.second > 0)
        quicksort(p.second, arr_r);
}

int main () {
    int N;
    std::cin >> N;

    if (N == 0)
        return 0;
    long int array[N];
    for (int i = 0; i < N; i++)
        std::cin >> array[i];

    quicksort(array, array + N - 1);

    for (int i = 0; i < N; i++)
        std::cout << array[i] << ' ';
    return 0;
}