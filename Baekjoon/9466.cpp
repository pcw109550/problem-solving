#include <bits/stdc++.h>
using namespace std;
#define totalsize 400000
int input[100000];
int resolved[100000];
int store[100000];

enum state {NOTUSED, CYCLE, CHAIN, NOTCYCLE};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, N, result = 0, size = 0; cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N; memset(resolved, 0, totalsize); memset(store, 0, totalsize);
        for (int j = 0; j < N; j++) { cin >> input[j]; input[j]--; }
        for (int j = 0; j < N; j++) {
            if (resolved[j] == CYCLE || resolved[j] == NOTCYCLE) { continue; }
            int idx = j; bool cycle = false;
            while (!cycle) {
                if (resolved[idx] == CHAIN) {
                    resolved[idx] = CYCLE;
                    for (int k = 0; k < size; k++) {
                        if (store[k] == idx) {
                            resolved[store[k]] = CYCLE;
                            cycle = true; continue;
                        }
                        resolved[store[k]] = cycle ? CYCLE : NOTCYCLE;
                    }
                    size = 0;
                    if (cycle) { break; }
                }
                else if (resolved[idx] == NOTUSED) {
                    resolved[idx] = CHAIN; store[size++] = idx; 
                    idx = input[idx];
                }
                else if (resolved[idx] == NOTCYCLE || resolved[idx] == CYCLE) {
                    for (int k = 0; k < size; k++) {
                        resolved[store[k]] = NOTCYCLE;
                    }
                    size = 0;
                    break;
                }
            }
        }
        result = 0;
        for (int j = 0; j < N; j++) {
            result += resolved[j] != CYCLE;
        }
        cout << result << '\n';
    }
}