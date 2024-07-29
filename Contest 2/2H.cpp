#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    unordered_map<int, vector<int>> sumToMasks;
    
    int totalSubsets = 1 << N;
    
    for (int mask = 1; mask < totalSubsets; ++mask) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sum += A[i];
            }
        }
        sumToMasks[sum].push_back(mask);
    }
    set<int> validSums;
    for (const auto& entry : sumToMasks) {
        const vector<int>& masks = entry.second;
        int size = masks.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    validSums.insert(entry.first);
                    break; 
                }
            }
        }
    }
    
    cout << validSums.size() << endl;
    for (const int& x : validSums) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
