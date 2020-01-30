#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int input[9];
    for (int i = 0; i < 9; i++) {
        cin >> input[i];
    }
    int sum = 0; list<int> output;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < 9; k++) {
                if (k != i && k != j) {
                    sum += input[k];
                }
            }
            if (sum == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        output.push_front(input[k]);
                    }
                }
                output.sort();
                for (auto it = output.begin(); it != output.end(); it++) {
                    cout << *it << '\n';
                }
                return 0;
            }
            sum = 0;
        }
    }
}