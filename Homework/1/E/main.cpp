#include <iostream>
#include <vector>
#include <string>
#include <map>

int main () {
    int n;
    std::cin >> n;
    std::vector<std::string> array(n);
    std::map<char, std::vector<std::string>> phase = {{'0', std::vector<std::string>{}},
                                                      {'1', std::vector<std::string>{}},
                                                      {'2', std::vector<std::string>{}},
                                                      {'3', std::vector<std::string>{}},
                                                      {'4', std::vector<std::string>{}},
                                                      {'5', std::vector<std::string>{}},
                                                      {'6', std::vector<std::string>{}},
                                                      {'7', std::vector<std::string>{}},
                                                      {'8', std::vector<std::string>{}},
                                                      {'9', std::vector<std::string>{}}};
    for (int i = 0; i < n; i++)
        std::cin >> array[i];

    std::cout << "Initial array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << array[i];
        if (i < n-1)
            std::cout << ", ";
    }
    std::cout << "\n**********\n";

    for (int i = array[0].length() - 1; i >= 0; i--) {
        std::cout << "Phase " << array[0].length() - i << '\n';
        for (const auto& str : array)
            phase[str[i]].push_back(str);
        array.clear();

        for (auto& pair : phase) {
            std::cout << "Bucket " << pair.first << ": ";
            if (!pair.second.empty()) {
                for (int s = 0; s < pair.second.size(); s++) {
                    array.push_back(pair.second[s]);
                    std::cout << pair.second[s];
                    if (s < pair.second.size()-1)
                        std::cout << ", ";
                }
                pair.second.clear();
            }
            else
                std::cout << "empty";
            std::cout << "\n";
        }
        std::cout << "**********\n";
    }
    std::cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << array[i];
        if (i < n-1)
            std::cout << ", ";
    }
}
