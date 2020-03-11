#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int acc = 0, minute, hour, temp;
    for (int i = 0; i < 4; i++) {
        cin >> temp; acc += temp;
    }
    hour = acc / 60;
    minute = acc % 60;
    cout << hour << '\n' << minute;
}