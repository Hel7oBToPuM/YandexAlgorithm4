#include <iostream>
#include <vector>
#include <algorithm>

int main () {
    int N;
    std::cin >> N;
    if (N == 1) {
        std::cout << 0;
        return 0;
    }
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    for (auto& row : matrix)
        for (auto& elem : row)
            std::cin >> elem;

    int minDistance = -1;

    std::vector<int> permutation(N);
    for (int i = 0; i < N; ++i)
        permutation[i] = i;

    do {
        int buf = 0;
        for (int i = 0; i < N; i++) {
            if (int cost = matrix[permutation[i]][permutation[(i != N-1) ? i+1 : 0]]; cost != 0)
                buf += cost;
            else {
                buf = -1;
                break;
            }
        }
        if ((buf < minDistance || minDistance == -1) && buf != -1)
            minDistance = buf;
    } while (std::next_permutation(permutation.begin(), permutation.end()));

    std::cout << minDistance;
}