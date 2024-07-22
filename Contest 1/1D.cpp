#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, ST, EN, u, d;
    cin >> N >> ST >> EN >> u >> d;
    if (ST == EN) {
        cout << 0 << endl;
        return 0;
    }
    if (u == 0 && d == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (u == 0 && ST < EN) {
        cout << -1 << endl;
        return 0;
    }
    if (d == 0 && ST > EN) {
        cout << -1 << endl;
        return 0;
    }

    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q;
    q.push({ST, 0});
    visited[ST] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();
        int next_up = current + u;
        if (next_up <= N && !visited[next_up]) {
            if (next_up == EN) {
                cout << steps + 1 << endl;
                return 0;
            }
            visited[next_up] = true;
            q.push({next_up, steps + 1});
    }
        int next_down = current - d;
        if (next_down >= 1 && !visited[next_down]) {
            if (next_down == EN) {
                cout << steps + 1 << endl;
                return 0;
            }
            visited[next_down] = true;
            q.push({next_down, steps + 1});
        }
    }
    cout << -1 << endl;
    return 0;
}
