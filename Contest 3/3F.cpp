#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, long long mod) {
    int size = A.size();
    vector<vector<long long>> C(size, vector<long long>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

vector<vector<long long>> matrix_pow(vector<vector<long long>> F, long long n, long long mod) {
    int size = F.size();
    vector<vector<long long>> result(size, vector<long long>(size, 0));
    for (int i = 0; i < size; ++i) {
        result[i][i] = 1;
    }
    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply(result, F, mod);
        }
        F = multiply(F, F, mod);
        n /= 2;
    }
    return result;
}

long long fibonacci(long long n, long long mod) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    vector<vector<long long>> F = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = matrix_pow(F, n - 1, mod);
    return result[0][0];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long a, b, M;
        cin >> a >> b >> M;
        
        long long g = gcd(a, b);
        long long fib_g = fibonacci(g, M);
        cout << fib_g << endl;
    }
    return 0;
}
