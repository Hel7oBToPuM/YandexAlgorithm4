#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int N, M, max_side = 0;
    std::cin >> N >> M;
    std::vector<std::vector<int>> grid = std::vector<std::vector<int>>(N, std::vector<int>(M)),
    dp = std::vector<std::vector<int>>(N + 1, std::vector<int>(M + 1));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> grid[i][j];

    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < M + 1; j++)
            if (grid[i-1][j-1] == 1) {
                dp[i][j] = std::min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                max_side = std::max(max_side, dp[i][j]);
            }

    std::cout << max_side;
    return 0;
}