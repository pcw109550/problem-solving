#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; getline(cin, s);
    char stack[31] = {}; int idx = -1;
    long temp[100] = {}; //fill(temp, temp + 100, 1);
    for (auto it = s.begin(); it != s.end(); it++ ) {
        if (*it == '(' || *it == '[') {
            stack[++idx] = *it;
        } else if (*it == ')') {
            if (stack[idx] != '(') { temp[0] = 0; break; }
            if (temp[idx + 1] == 0) {
                temp[idx] += 2;
            } else {
                temp[idx] = temp[idx] + temp[idx + 1] * 2;
                temp[idx + 1] = 0;
            }
            idx--;
        } else if (*it == ']') {
            if (stack[idx] != '[') { temp[0] = 0; break; }
            if (temp[idx + 1] == 0) {
                temp[idx] += 3;
            } else {
                temp[idx] = temp[idx] + temp[idx + 1] * 3;
                temp[idx + 1] = 0;
            }
            idx--;
        }
        //for (int j = 0; j < 10; j++) {
        //    cout << temp[j] << " ";
        //}
        //cout << "\n";
    }
    if (idx != -1) {temp[0] = 0;}
    cout << temp[0];
}