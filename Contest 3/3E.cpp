#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    if (N == 1) {
        cout << "1 " << arr[0] << endl;
        return 0;
    }

    vector<int> maxLeft(N), minRight(N);
    maxLeft[0] = arr[0];
    for (int i = 1; i < N; ++i) {
        maxLeft[i] = max(maxLeft[i - 1], arr[i]);
    }

    minRight[N - 1] = arr[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        minRight[i] = min(minRight[i + 1], arr[i]);
    }

    vector<int> pivots;
    for (int i = 0; i < N; ++i) {
        bool isPivot = true;
        if (i > 0 && arr[i] < maxLeft[i - 1]) {
            isPivot = false;
        }
        if (i < N - 1 && arr[i] > minRight[i + 1]) {
            isPivot = false;
        }
        if (isPivot) {
            pivots.push_back(arr[i]);
        }
    }

    cout << pivots.size() << " ";
    for (int i = 0; i < min((int)pivots.size(), 100); ++i) {
        cout << pivots[i] << " ";
    }
    cout << endl;

    return 0;
}
