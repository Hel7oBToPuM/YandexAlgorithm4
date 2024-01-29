#include <iostream>
#include <vector>

struct floor_ {
    unsigned long number;
    unsigned long people;
};

int main() {
    unsigned long max_lift, floors_cnt, time = 0, lift = 0;
    std::cin >> max_lift >> floors_cnt;
    std::vector<floor_> building;
    for (unsigned  long i = 0; i < floors_cnt; i++) {
        unsigned long buf;
       std::cin >> buf;
       if (buf > 0)
            building.push_back({i+1, buf});
    }
    if (!building.empty())
        time += 2 * building.rbegin()->number;

    for (auto it = building.rbegin(); it != building.rend(); ++it) {
        if (max_lift - lift < it->people) {
            it->people -= max_lift - lift;
            time += 2 * ((it->people) / max_lift) * it->number;
            lift = it->people % max_lift;
            if (lift > 0)
                time += 2 * (it->number);
            else if ((it+1) != building.rend())
                time += 2 * (it+1)->number;
        }
        else {
            lift += it->people;
            if (lift == max_lift) {
                lift = 0;
                if ((it+1) != building.rend())
                    time += 2 * ((it+1)->number);
            }
        }

    }
    std::cout << time;
    return 0;
}
