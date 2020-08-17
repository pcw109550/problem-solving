#include<bits/stdc++.h>
using namespace std;

inline int task(int x[]) {
    if (x[0] == x[1])
        return x[2];
    else if (x[1] == x[2])
        return x[0];
    else
        return x[1];
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int x[3] = {}, y[3] = {};
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    cout << task(x) << ' ' << task(y);
}   