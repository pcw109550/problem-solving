#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, start, trial = 0; bool less; cin >> N; start = N;
    do {
        less = false;
        if (N < 10) { N *= 10; less = true;}
        N = (less ? N / 10 : N % 10) * 10 + ((N / 10 + N % 10) % 10);
        trial++;
    } while (N != start);
    cout << trial;
}