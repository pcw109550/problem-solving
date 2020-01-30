#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int N; cin >> N; short input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    int m; cin >> m; int cnt = 0;
    for (int i = 0; i < N; i++) { cnt += (m == input[i]); }
    cout << cnt;
}