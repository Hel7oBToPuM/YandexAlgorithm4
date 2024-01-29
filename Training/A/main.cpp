#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    int array[N];
    for (int i = 0; i < N; i++)
        std::cin >> array[i];

    for (int i = 0; i < M; i++) {
        int lower_bound, upper_bound, cur = 0, prev = 0;
        std::cin >> lower_bound >> upper_bound;
        int prop = array[lower_bound];
        prev = prop;
        for (int j = lower_bound+1; j <= upper_bound; j++) {
            cur = array[j];
            if (prev != cur) {
                if (cur > prop)
                    prop = cur;
                else
                    prev = cur;
                std::cout << prop << '\n';
                break;
            }
            prev = cur;
        }
        if (prop == prev)
            std::cout << "NOT FOUND\n";
    }
    return 0;
}
