#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    long double R; cin >> R;
    long double euclidean = R * R * M_PI;
    long double taxi = R * R * 2;
    cout << setprecision(15) << euclidean << '\n' << taxi;
}