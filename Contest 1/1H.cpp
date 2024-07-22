#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxGCD(const vector<int>& A) {
    int maxElement = *max_element(A.begin(), A.end());
    vector<int> frequency(maxElement + 1, 0);
    for (int num : A) {
        frequency[num]++;
    }
    for (int g = maxElement; g >= 1; --g) {
        int count = 0;
        for (int multiple = g; multiple <= maxElement; multiple += g) {
            count += frequency[multiple];
            if (count > 1) {
                return g; 
            }
        }
    }
    return 1; 
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        int result = findMaxGCD(A);
        cout << result << endl;
    }
    return 0;
}
