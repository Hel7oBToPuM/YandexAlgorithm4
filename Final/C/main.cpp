#include <iostream>
#include <map>
#include <set>
#include <vector>

struct crossroad {
    int time;
    unsigned long long weight;
};

int main () {
    int N, M;
    std::cin >> N >> M;

    if (N == 1) {
        std::cout << 10000000;
        return 0;
    }

    std::vector<std::map<int, crossroad>> roads (N+1);
    for (int i = 0; i < M; i++) {
        int depart, dest;
        std::cin >> depart >> dest;
        std::cin >> roads[depart][dest].time >> roads[depart][dest].weight;
        roads[dest][depart].time = roads[depart][dest].time;
        roads[dest][depart].weight = roads[depart][dest].weight;
    }

    unsigned long long max_weight = 0;
    std::vector<bool> visited(N+1);
    std::multiset<std::pair<int, std::pair<unsigned long long, int>>, decltype([](const auto& a, const auto& b){return a.second.first > b.second.first;})> set;
    set.insert({{1, {0, 0}}});
    while (!set.empty()) {
        const auto& way = set.begin();
        const auto [city, cost] = *way;
        const auto [weight, time] = cost;
        set.erase(way);

        for (const auto& [dest, cross] : roads[city]) {
            if (!visited[dest]) {
                int all_time = time + cross.time;
                if (all_time <= 1440 && cross.weight >= 3000100) {
                    unsigned long long all_weight = weight > cross.weight || weight == 0 ? cross.weight : weight;
                    if (dest == N && max_weight < all_weight)
                        max_weight = all_weight;
                    set.emplace(dest, std::make_pair(all_weight, all_time));
                }
            }
        }
        visited[city] = true;
    }

    if (max_weight != 0) {
        std::cout << (max_weight-3000000)/100;
    }
    else
        std::cout << 0;
    return 0;
}