#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> findMaxOfMins(const vector<int>& A, int N) {
    vector<int> left(N), right(N), result(N, INT_MIN);
    stack<int> s;

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = N - 1; i >= 0; --i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        right[i] = s.empty() ? N : s.top();
        s.push(i);
    }
    for (int i = 0; i < N; ++i) {
        int len = right[i] - left[i] - 1;
        result[len - 1] = max(result[len - 1], A[i]);
    }
    for (int i = N - 2; i >= 0; --i) {
        result[i] = max(result[i], result[i + 1]);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int> result = findMaxOfMins(A, N);
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    return 0;
}



