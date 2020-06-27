#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, temp, prev = -1;
    while (true) {
        cin >> N; if (!N) { return 0; }
        for (int i = 0; i < N; i++) {
            cin >> temp;
            if (temp != prev) { cout << temp << ' '; }
            prev = temp;
        }
        cout << "$\n";
        prev = -1;
    }
}