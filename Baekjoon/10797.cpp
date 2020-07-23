#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int result = 0, T, temp;
    cin >> T;
    for (int i = 0; i < 5; i++) {
        cin >> temp;
        if (T == temp)
            result++;
    }
    cout << result;
}