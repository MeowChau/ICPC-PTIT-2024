#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    int M;
    std::cin >> M;
    std::vector<int> a(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> flip_count(n / 2, 0);

    for (int i = 0; i < M; ++i) {
        int ai = a[i];
        flip_count[ai - 1]++;
        if (n - ai < n / 2) {
            flip_count[n - ai]--;
        }
    }
    int current_flip = 0;
    for (int i = 0; i < n / 2; ++i) {
        current_flip += flip_count[i];
        if (current_flip % 2 != 0) {
            std::swap(s[i], s[n - i - 1]);
        }
    }
    std::cout << s << std::endl;

    return 0;
}
