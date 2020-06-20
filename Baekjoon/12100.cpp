#include <bits/stdc++.h>
using namespace std;
#define NUMMOVE 5
int N, Max, sum;
enum Move { U, D, L, R };
// VERY SLOW because using 2d vector. change to 2d array
vector<vector<int> > Map(20, vector<int> (20, 0));
vector<vector<int> > tempMap;

inline void printMap(vector<vector<int> > &tempMap) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tempMap[i][j] << ' ';
        } cout << '\n';
    }
}

inline void updateMap(vector<vector<int> > &tempMap, Move move) {
    for (int idx = 0; idx < N; idx++) {
        int acc[N] = {};
        int probe = 0, prev = -1;
        register int current;
        for (int i = 0; i < N; i++) {
            switch (move) {
                case U:
                    current = tempMap[i][idx];
                    break;
                case D:
                    current = tempMap[N - 1 - i][idx];
                    break;
                case L:
                    current = tempMap[idx][N - 1 - i];
                    break;
                case R:
                    current = tempMap[idx][i];
                    break;
                default:
                    assert(false);
                    break;
            }
            if (!current) { continue; }
            if (current == prev) {
                acc[probe - 1] <<= 1;
                prev = -1;
            } else {
                acc[probe++] = current;
                prev = current;
            }
            Max = max(Max, acc[probe - 1]);
            if (Max == sum) {
                cout << sum;
                exit(0);
            }
        }
        for (int i = 0; i < N; i++) {
            switch (move) {
                case U:
                    tempMap[i][idx] = acc[i];
                    break;
                case D:
                    tempMap[N - 1 - i][idx] = acc[i];
                    break;
                case L:
                    tempMap[idx][N - 1 - i] = acc[i];
                    break;
                case R:
                    tempMap[idx][i] = acc[i];
                    break;
                default:
                    assert(false);
                    break;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    Map.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Map[i][j];
            sum += Map[i][j];
        }
    }
    for (int m = 0; m < 1 << (NUMMOVE * 2); m++) {
        tempMap = Map;
        Move move; int encoded = m;
        for (int t = 0; t < NUMMOVE; t++) {
            move = static_cast<Move>(encoded & 0b11); encoded >>= 2;
            updateMap(tempMap, move);
        }
    }
    cout << Max;
}