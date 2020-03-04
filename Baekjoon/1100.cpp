#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    char temp; bool flip = true; int result = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> temp;
            if (flip && temp == 'F') { result++; }
            flip = !flip;
        }
        flip = !flip;
    }
    cout << result;
}