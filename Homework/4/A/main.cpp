#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> permutation;
    for(int i = 1; i <= N; i++)
        permutation.push_back(i);

    do {
        for (auto& c : permutation)
            std::cout << c;
        std::cout << '\n';
    }
    while (std::next_permutation(permutation.begin(), permutation.end()));
}
