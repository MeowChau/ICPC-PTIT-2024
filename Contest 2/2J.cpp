#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }
    vector<int> voteCount(M + 1, 0); 
    for (int vote : votes) {
        voteCount[vote]++;
    }
    int maxVotes = 0;
    int secondMaxVotes = 0;
    int firstCandidate = -1;
    int secondCandidate = -1;

    for (int i = 1; i <= M; ++i) {
        if (voteCount[i] > maxVotes) {
            secondMaxVotes = maxVotes;
            secondCandidate = firstCandidate;

            maxVotes = voteCount[i];
            firstCandidate = i;
        } else if (voteCount[i] > secondMaxVotes && voteCount[i] < maxVotes) {
            secondMaxVotes = voteCount[i];
            secondCandidate = i;
        } else if (voteCount[i] == secondMaxVotes && voteCount[i] < maxVotes) {
            if (secondCandidate == -1 || i < secondCandidate) {
                secondCandidate = i;
            }
        }
    }

    if (secondCandidate == -1) {
        cout << "NONE" << endl;
    } else {
        cout << secondCandidate << endl;
    }

    return 0;
}
