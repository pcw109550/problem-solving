#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    getline(cin, input);
    int array[9] = {};
    for (char const &c: input) {
        if (c - '0' == 6 || c - '0' == 9) {
            array[6]++;
        } else {
            array[c - '0']++;
        }
    }
    array[6]++;
    array[6] /= 2;
    cout << *max_element(begin(array), end(array));
}