#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long result = N * (N - 1) / 2;
    cout << result << endl;
    return 0;
}
