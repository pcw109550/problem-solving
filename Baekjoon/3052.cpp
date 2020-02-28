#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); int temp;
    bool output[42] = {}; int result = 0;
    for (int i = 0; i < 10; i++) {
        cin >> temp; output[temp % 42] = true;
    }
    for (int i = 0; i < 42; i++) {
        result += output[i];
    }
    cout << result;
}