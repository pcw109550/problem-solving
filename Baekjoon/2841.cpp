#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, P, idx, num, result = 0;
    cin >> N >> P;
    stack<int> S[7];
    for (int i = 0; i < N; i++) {
        cin >> idx >> num;
        if (S[idx].empty()) {
            result++;
            S[idx].push(num);
        } else if (S[idx].top() == num) {
            continue;
        } else if (S[idx].top() < num) {
            result++;
            S[idx].push(num);
        } else if (S[idx].top() > num) {
            while (S[idx].top() > num) {
                S[idx].pop();
                result++;
                if (S[idx].empty())
                    break;
            }
            if (S[idx].empty() || S[idx].top() < num) {
                result++;
                S[idx].push(num);
            }
        }
    }
    cout << result;
}   