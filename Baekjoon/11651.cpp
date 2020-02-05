#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, a, b; cin >> N; pair<int, int> input[N];
    for (int i = 0; i < N; i++) {
        cin >> a >> b; input[i] = {b, a};
    }
    sort(input, input + N);
    for (int i = 0; i < N; i++) {
        cout << input[i].second << " " << input[i].first << "\n";
    }
}