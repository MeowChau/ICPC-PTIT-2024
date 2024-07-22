#include <iostream>
#include <vector>

using namespace std;

void solveNQueens(int row, int n, int& solutions, int cols, int diags1, int diags2) {
    if (row == n) {
        ++solutions;
        return;
    }
    int availablePositions = ((1 << n) - 1) & (~(cols | diags1 | diags2));
    while (availablePositions) {
        int position = availablePositions & (-availablePositions);
        availablePositions -= position; 

        solveNQueens(row + 1, n, solutions, cols | position, (diags1 | position) << 1, (diags2 | position) >> 1);
    }
}
int main() {
    int n;
    cin >> n;
    if (n < 4 || n > 14) {
        cout << "N phải nằm trong khoảng từ 4 đến 14" << endl;
        return 0;
    }
    int solutions = 0;
    solveNQueens(0, n, solutions, 0, 0, 0);

    cout << solutions << endl;

    return 0;
}
