#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, target, num = 0, cnt; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    sort(input, input + N);        // O(N log(N))
    pair<int, int> processed[N] = {};
    processed[0] = {input[0], 1};
    for (int i = 1; i < N; i++) {  // O(N)
        if (processed[num].first == input[i]) { processed[num].second++; }
        else { processed[++num].first = input[i]; processed[num].second++; }
    } num++;
    cin >> M;
    for (int t = 0; t < M; t++) {
        int start = 0, end = num - 1, mid; cin >> target;
        while (start <= end) { // Binary Search O(M * num log (num)) where num < N
            mid = (start + end) / 2;
            if      (processed[mid].first < target) { start = mid + 1; }
            else if (processed[mid].first > target) { end = mid - 1; }
            else {
                cout << processed[mid].second << " ";
                break;
            }
        }
        if (start > end) { cout << "0 "; }
    }
}