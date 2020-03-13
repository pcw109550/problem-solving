#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int sum = 0, temp;
    for (int i = 0; i < 5; i++) {
        cin >> temp; sum += temp;
    }
    cout << sum;
}