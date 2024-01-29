#include <iostream>

void merge (long *fst, int N, long *sec, int M, long *res) {
    long *arr1 = fst, *arr2 = sec, *arr = res;
    for (; arr != res + M + N; arr++) {
        if ((*arr1 <= *arr2 && arr1 != fst + N) || arr2 == sec + M) {
            *arr = *arr1;
            arr1++;
        }
        else if (arr2 != sec + M || arr1 == fst + N) {
            *arr = *arr2;
            arr2++;
        }
    }
    std::copy(res, arr, fst);
}

void mergesort(long* array, int N, long* result) {
    if (N > 1) {
        mergesort(array, N-N/2, result);
        mergesort(array + N/2, N - N/2, result + N/2);
        merge(array, N/2, array + N/2, N/2 + N%2, result);
    }
}

int main () {
    int N;
    std::cin >> N;
    if (N == 0)
        return 0;

    long array[N];
    for (int i = 0; i < N; i++)
        std::cin >> array[i];

    long result[N];

     mergesort(array, N, result);

    for (const auto& i : array)
        std::cout << i << ' ';
    return 0;
}