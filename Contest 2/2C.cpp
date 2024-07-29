#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<int> operation1(const vector<int>& P, int N) {
    vector<int> result = P;
    for (int i = 0; i < 2 * N; i += 2) {
        swap(result[i], result[i + 1]);
    }
    return result;
}

vector<int> operation2(const vector<int>& P, int N) {
    vector<int> result = P;
    for (int i = 0; i < N; ++i) {
        swap(result[i], result[N + i]);
    }
    return result;
}

int minOperations(int N, vector<int>& P) {
    vector<int> target(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        target[i] = i + 1;
    }

    if (P == target) {
        return 0;  
    }

    queue<pair<vector<int>, int>> q; 
    set<vector<int>> visited; 
    q.push({P, 0});
    visited.insert(P);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();
        vector<int> next1 = operation1(current, N);
        if (next1 == target) {
            return steps + 1;
        }
        if (visited.find(next1) == visited.end()) {
            q.push({next1, steps + 1});
            visited.insert(next1);
        }
        vector<int> next2 = operation2(current, N);
        if (next2 == target) {
            return steps + 1;
        }
        if (visited.find(next2) == visited.end()) {
            q.push({next2, steps + 1});
            visited.insert(next2);
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> P[i];
    }

    int result = minOperations(N, P);
    cout << result << endl;

    return 0;
}
