#include<bits/stdc++.h>
using namespace std;
// https://cme.h-its.org/exelixis/pubs/Exelixis-RRDR-2013-5.pdf

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    pair<int, int> edge[N - 1];
    long long weight[N + 1] = {};
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        weight[x]++;
        weight[y]++;    
        edge[i] = {x, y};
    }
    long long numD = 0;
    long long numG = 0;
    // G
    for (int i = 1; i <= N; i++) {
        long long cur_weight = weight[i];
        if (cur_weight >= 3) {
            long long result = 1;
            for (int j = 1; j <= 3; j++) {
                result = result * (cur_weight - j + 1) / j;
            }
            numG += result;
        }
    }
    // D
    for (int i = 0; i < N - 1; i++) {
        int x = edge[i].first;
        int y = edge[i].second;
        numD += (weight[x] - 1) * (weight[y] - 1);
    }
    if (numD > 3 * numG)
        cout << 'D';
    else if (numD < 3 * numG)
        cout << 'G';
    else
        cout << "DUDUDUNGA";
}