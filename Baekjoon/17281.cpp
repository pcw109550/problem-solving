#include <bits/stdc++.h>
using namespace std;
int accs[50][9] = {};
int N;
class GameState {
    public:
        GameState(vector<int> cseq);
        int inning;
        int idx;
        int outs;
        int score;
        vector<int> seq;
        bool bases[4];
        void simulate(void);
};

GameState::GameState(vector<int> cseq) {
    inning = idx = outs = score = 0;
    for (int i = 0; i < 4; i++) { bases[i] = false; }
    seq = cseq;
}

void GameState::simulate(void) {
    while (inning < N) {
        int acc = accs[inning][seq[idx]];
        idx = (idx + 1) % 9;
        if (acc) {
            for (int i = 3; i >= 1; i--) {
                if (bases[i]) {
                    bases[i] = false;
                    if (i + acc > 3) {   score++; }
                    else { bases[i + acc] = true; }
                }
            }
            if (acc == 4) { score++; }
            else          { bases[acc] = true; }
        } else {
            if (++outs > 2) {
                inning++;
                outs = 0; 
                for (int i = 0; i < 4; i++) { bases[i] = false; }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int result = -1; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> accs[i][j];
        }
    }
    vector<int> seq;
    for (int i = 1; i < 9; i++) {
        seq.push_back(i);
    }
    do {
        vector<int> cseq = seq; int idx = 0;
        cseq.insert(cseq.begin() + 3, 0);
        GameState state(cseq);
        state.simulate();
        result = max(result, state.score);
    } while (next_permutation(seq.begin(), seq.end()));
    cout << result;
}