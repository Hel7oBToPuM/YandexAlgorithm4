#include <iostream>
#include <ranges>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

struct short_way {
    int city;
    double time = -1;
    std::vector<int> path;
    bool visited;
};

int main () {
    const int MOSCOW = 1;
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> coachmen(N+1);
    for(int i = 1; i < N + 1; i++)
        std::cin >> coachmen[i].first >> coachmen[i].second;

    std::vector<std::map<int, int>> roads (N+1);
    for (int i = 1; i < N; i++) {
        int depart_city, dest_city, dist;
        std::cin >> depart_city >> dest_city >> dist;
        roads[depart_city][dest_city] = dist;
        roads[dest_city][depart_city] = dist;
    }

    std::vector<std::map<int, double>> dest_depart_time(N + 1);
    for (int i = 2; i < N + 1; i++) {
        std::vector<bool> visited(N + 1, false);
        std::vector<int> cities(1, i);
        while (!cities.empty()) {
            int cur_city = cities.back(); cities.pop_back();
            if (cur_city == MOSCOW) continue;
            for (const auto &[dest_city, dist_cur_dest]: roads[cur_city]) {
                if (!visited[dest_city]) {
                    dest_depart_time[dest_city][i] = double(dist_cur_dest) / double(coachmen[i].second) + (i != cur_city ? dest_depart_time[cur_city][i] : 0);
                    cities.push_back(dest_city);
                }
            }
            visited[cur_city] = true;
        }
    }

    std::vector<short_way> participants (N + 1);
    for(int i = 0; i < N + 1; i++)
        participants[i].city = i;
    std::multiset<std::pair<double, int>, decltype([](const auto& a, const auto& b){return a.first < b.first;})> ways;
    participants[1].time = 0;
    ways.emplace(0, 1);
    while (!ways.empty()) {
        const auto& way = ways.begin();
        const auto [time_from_cur, city] = *way;
        ways.erase(way);

        if (participants[city].visited)
            continue;

        for (const auto& [depart_city, time_to_cur] : dest_depart_time[city]) {
            double time = time_from_cur + coachmen[depart_city].first + time_to_cur; //Время из city до 1 + Время пересадки на сани + Время из следующего города до city
            if (time < participants[depart_city].time || participants[depart_city].time < 0) {
                participants[depart_city].time = time;
                participants[depart_city].path = participants[city].path;
                participants[depart_city].path.push_back(city);
                ways.emplace(time, depart_city);
            }
        }
        participants[city].visited = true;
    }

    const auto& max_time_participant = *std::max_element(participants.begin(), participants.end(),
                                                [](const auto& a, const auto& b){return a.time < b.time;});
    std::cout << std::setprecision(16) << max_time_participant.time << '\n' << max_time_participant.city << ' ';
    for (int it : std::ranges::reverse_view(max_time_participant.path))
        std::cout << it << ' ';

    return 0;
}