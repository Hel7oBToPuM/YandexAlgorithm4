#include <iostream>
#include <vector>
#include <limits>
#include <set>

int main () {
    int N, K;
    std::cin >> N >> K;
    std::vector<std::pair<unsigned long long, bool>> path(N+1, {-1, false});

    // Город-{{назначение, стоимость}, {назначение, стоимость}}
    std::vector<std::vector<std::pair<int, unsigned long long>>> roads(N+1);
    for (unsigned long long city, destination, cost, i = 0; i < K; i++) {
        std::cin >> city >> destination >> cost;
        roads[city].emplace_back(destination, cost);
        roads[destination].emplace_back(city, cost);
    }

    int A, B;
    std::cin >> A >> B;
    path[A].first = 0; path[0].second = true;

    //Стоимость - Город
    std::multiset<std::pair<unsigned long long, int>, decltype([](const auto& a, const auto& b){return a.first < b.first;})> shortest_way;
    shortest_way.emplace(0, A);

    while (!shortest_way.empty()) {
        const auto [cost_to_start, start_city] = shortest_way.extract(shortest_way.begin()).value();

        if (path[start_city].second) continue;

        if (start_city == B) {
            std::cout << cost_to_start;
            return 0;
        }

        for (const auto& [dest_city, cost_to_dest] : roads[start_city])
            if (unsigned long long dest_cost = cost_to_start + cost_to_dest; dest_cost < path[dest_city].first) {
                path[dest_city].first = dest_cost;
                shortest_way.emplace(dest_cost, dest_city);
            }

        path[start_city].second = true;
    }

    std::cout << -1;
    return 0;
}