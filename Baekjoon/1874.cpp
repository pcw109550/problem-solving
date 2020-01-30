#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; getline(cin, s); int N = stoi(s);
    int max = 0, low = 0, idx = 0; int input[N] = {};
    for (int i = 0; i < N; i++) {
        getline(cin, s); input[i] = stoi(s);
        if (input[i] >= max){ 
            max = input[i];
            low = 0;
        } else {
            if (low != 0 && low < input[i]) {
                cout << "NO";
                return 0;
            }
            low = input[i];
        }
    }
    max = 0;
    for (int i = 0; i < N; i++) {
        if (input[i] >= max) {
            max = input[i];
        }
        for (int j = idx; j < max; j++) {
            cout << "+\n";
        }
        idx = max;
        cout << "-\n";
    }
}