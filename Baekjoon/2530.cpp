#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int h, m, s, t; cin >> h >> m >> s >> t;
    int hd = t / 3600;
    int md = (t - hd * 3600) / 60;
    int sd = (t - hd * 3600 - md * 60);
    cout << (h + hd + (m + md + (s + sd) / 60) / 60) % 24 << ' ';
    cout << (m + md + (s + sd) / 60) % 60 << ' ';
    cout << (s + sd) % 60;
}