#include <bits/stdc++.h>
using namespace std;
vector<bool> isused(33554433, false);

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int temp;
    while (!cin.eof()) {
        cin >> temp;
        if (!isused[temp]) {
            cout << temp << ' ';
            isused[temp] = true;
        }
    }
 }