#include <iostream>
#include <vector>
#include <cmath>

int main () {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    for (auto& row : matrix)
        for (auto& elem : row)
            std::cin >> elem;

    int sum = 0;
    int best_permutation = 0;
    for (int permutation = 1; permutation < pow(2, N)-1; permutation++) {
        int buf = 0;
        for (int j = 0; j < N; j++) {
            bool j_dol = (permutation >> j) & 1;
            for (int k = j; k < N; k++)
                if (k != j && j_dol != ((permutation >> k) & 1))
                    buf += matrix[j][k];
        }
        if (buf > sum) {
            sum = buf;
            best_permutation = permutation;
        }
    }
    std::cout << sum << '\n';
    for (int i = 0; i < N; i++) {
        std::cout << (int)((best_permutation >> i) & 1) + 1 << ' ';
    }
}