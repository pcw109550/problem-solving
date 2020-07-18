#include<bits/stdc++.h>
using namespace std;

int d(int probe) {
    int acc = probe;
    while (probe > 0) {
        acc += probe % 10;
        probe = (probe - probe % 10) / 10;
    }
    return acc;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    bool is_selfnum[10001];
    fill(is_selfnum, is_selfnum + 10001, true);
    for (int i = 1; i <= 10000; i++) {
        if (!is_selfnum[i])
            continue;
        int probe = i;
        cout << i << '\n';
        while (true) {
            probe = d(probe);
            if (probe <= 10000)
                is_selfnum[probe] = false;
            else
                break;
        }
    }
}