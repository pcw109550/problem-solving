#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int start = true; double temp, input;
    while (true) {
        cin >> input;
        if (input == 999) { return 0; }
        if (start) { start = false; temp = input; }
        else {
            cout << fixed << setprecision(2) << input - temp << '\n'; 
            temp = input;
        }
    }
}