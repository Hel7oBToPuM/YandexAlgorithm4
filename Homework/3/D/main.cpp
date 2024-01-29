#include <iostream>
#include <vector>
#include <set>

int main() {
    int N, d, v, R;
    std::cin >> N >> d >> v >> R;

    std::vector<std::pair<int, bool>> shortest_time (N+1, {INT_MAX, false});
    shortest_time[0].second = true; shortest_time[d].first = 0;

    std::vector<std::vector<std::pair<int, std::pair<int, int>>>> races(N+1);
    while (R--) {
        int departure, depart_time, destination, dest_time;
        std::cin >> departure >> depart_time >> destination >> dest_time;
        races[departure].push_back({destination, {depart_time, dest_time}});
    }

    std::multiset<std::pair<int, int>, decltype([](const auto& a, const auto& b){return a.first < b.first;})> ways;
    ways.emplace(0, d);

    while (!ways.empty()) {
        const auto& way = ways.begin();
        const auto [arrival_time, city] = *way;
        ways.erase(way);

        if (shortest_time[city].second) continue;

        if (city == v) {
            std::cout << arrival_time;
            return 0;
        }

        for (const auto& [dest_city, time] : races[city]) {
            const auto& [depart_time, dest_time] = time;
            if (depart_time >= arrival_time && dest_time < shortest_time[dest_city].first) {
                shortest_time[dest_city].first = dest_time;
                ways.emplace(dest_time, dest_city);
            }
        }

        shortest_time[city].second = true;
    }

    std::cout << -1;
    return 0;
}
