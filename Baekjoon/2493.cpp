#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N; scanf("%d\n", &N);
    int stack[N] = {}; int idx = -1;
    int index[N] = {}; int data;
    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        if (i == 0) {
            ++idx;
            stack[idx] = data;
            index[idx] = i;
            cout << "0 ";
            continue;
        }
        if (data < stack[idx]) {
            cout << index[idx] + 1;
            ++idx;
            stack[idx] = data;
            index[idx] = i;
        } else {
            while (stack[idx] < data && idx >= 0) {
                --idx;
            }
            if (idx == -1) {
                cout << "0 ";
                ++idx;
                stack[idx] = data;
                index[idx] = i;
                continue;
            }
            cout << index[idx] + 1;
            ++idx;
            stack[idx] = data;
            index[idx] = i;   
        }
        if (i != N - 1) { cout << " "; }
    }
}