#include <iostream>
#include <vector>
using namespace std;

string canBuySandwich(int N) {
    vector<bool> dp(N + 1, false);
    dp[0] = true;

    for (int i = 1; i <= N; ++i) {
        if (i >= 4 && dp[i - 4]) dp[i] = true;
        if (i >= 7 && dp[i - 7]) dp[i] = true;
    }

    return dp[N] ? "Yes" : "No";
}

int main() {
    int N;
    cin >> N;

    cout << canBuySandwich(N) << endl;

    return 0;
}
