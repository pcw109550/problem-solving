#include<bits/stdc++.h>
using namespace std;

inline string wrap(int n) {
    stringstream ss;
    if (n >= 2)
        ss << n << " bottles ";
    else if (n == 1)
        ss << 1 << " bottle ";
    else
        ss << "no more bottles ";
    return ss.str();
}

inline void iter(int n) {
    cout << wrap(n);
    cout << "of beer on the wall, ";
    cout << wrap(n);
    cout << "of beer.\nTake one down and pass it around, ";
    cout << wrap(n - 1);
    cout << "of beer on the wall.\n\n";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = N; i >= 1; i--)
        iter(i);
    cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
    cout << "Go to the store and buy some more, " << wrap(N) << "of beer on the wall.\n";
}   