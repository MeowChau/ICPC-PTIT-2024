#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int totalDivSteps = 0; 
    for (int i = 0; i < N; ++i) {
        int divSteps = 0;
        while (A[i] % 2 == 0) {
            A[i] /= 2;
            ++divSteps;
        }
        totalDivSteps += divSteps;
    }
    cout << totalDivSteps << '\n';
    return 0;
}




