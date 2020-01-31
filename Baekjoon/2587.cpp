#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int input[5]; int sum = 0; for (int i = 0; i < 5; i++) { cin >> input[i]; sum += input[i]; }
    sort(input, input + 5);
    cout << (sum / 5) << "\n" << input[2];
}