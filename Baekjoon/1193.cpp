#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int X; cin >> X; int N;
    int i = (int)sqrt(X) - 1;
    while (true) {
        if (i * (i + 1) / 2 < X) { i++; }
        else {
            int temp =  X - (i - 1) * i / 2;
            if (i % 2) { cout << i - temp + 1 << '/' << temp; }
            else       { cout << temp << '/' << i - temp + 1; }
            return 0;    
        }
    }
}