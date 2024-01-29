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
}

int main () {
    int N, M;

    std::cin >> N;
    long arr1[N];
    for (int i = 0; i < N; i++)
        std::cin >> arr1[i];

    std::cin >> M;
    long arr2[M];
    for (int i = 0; i < M; i++)
        std::cin >> arr2[i];

    long res[M+N];
    merge(arr1, N, arr2, M, res);

    for (int i = 0; i < M + N; i++)
        std::cout << res[i] << ' ';

    return 0;
}