#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string A, B;
    cin >> A >> B;
    int Min = 1 << 30;
    for (int i = 0; i < B.length() - A.length() + 1; i++) {
        int num_diff = 0;
        for (int j = 0; j < A.length(); j++)
            if (A[j] != B[i + j])
                num_diff++;
        Min = min(Min, num_diff);
    }
    cout << Min;
}