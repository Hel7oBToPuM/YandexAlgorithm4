#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

struct vertex {
    bool visited;
    int distance;
    bool operator<(const vertex& other) const {
        if (!visited)
            return distance < other.distance || other.visited;
        return false;
    }
};


int main () {
    int N, S, F;
    std::cin >> N >> S >> F;
    std::vector<vertex> distance(N+1);
    for (int i = 0; i < N + 1; i++)
        distance[i] = {i == 0, i == S ? 0 : INT_MAX};

    int matrix[N+1][N+1];
    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            std::cin >> matrix[i][j];

    while (std::count_if(distance.begin(), distance.end(),
                         [](const auto& v){return !v.visited;})) {

        int v_index = std::distance(distance.begin(), std::min_element(distance.begin(), distance.end()));

        for (int i = 1; i < N + 1; i++)
            if (i != v_index)
                if (int dis = matrix[v_index][i]; dis != -1)
                    if (int cost = dis + distance[v_index].distance; cost < distance[i].distance)
                        distance[i].distance = cost;

        distance[v_index].visited = true;
    }

    std::cout << (distance[F].distance != INT_MAX ? distance[F].distance : -1);

    return 0;
}