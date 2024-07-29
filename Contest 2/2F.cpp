#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Tính số phép biến đổi tối thiểu
    int result = (N - 1) / (K - 1);
    if ((N - 1) % (K - 1) != 0) {
        result += 1;
    }

    cout << result << endl;

    return 0;
}
