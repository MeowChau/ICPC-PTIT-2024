#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    unordered_map<int, int> mod_count;
    mod_count[0] = 1;  

    long long prefix_sum = 0;
    long long result = 0;

    for (int i = 0; i < N; ++i) {
        prefix_sum += A[i];
        int mod_value = (prefix_sum % M + M) % M;  

        if (mod_count.find(mod_value) != mod_count.end()) {
            result += mod_count[mod_value];
        }

        mod_count[mod_value]++;
    }

    cout << result << endl;

    return 0;
}

