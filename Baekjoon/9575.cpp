#include <bits/stdc++.h>
using namespace std;

bool lucky(int t) {
    while (t) {
        if (t % 10 != 5 && t % 10 != 8)
            return false;
        t /= 10;
    }
    return true;
}

void task() {
    unordered_set<int> S;
    int a; cin >> a;
    vector<int> A(a);
    for (int i = 0; i < a; i++)
        cin >> A[i];
    int b; cin >> b;
    vector<int> B(b);
    for (int i = 0; i < b; i++)
        cin >> B[i];
    int c; cin >> c;
    vector<int> C(c);
    for (int i = 0; i < c; i++)
        cin >> C[i];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            for (int k = 0; k < c; k++) {
                int temp = A[i] + B[j] + C[k];
                if (lucky(temp))
                    S.insert(temp);
            }
    cout << S.size() << endl;    
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--)
        task();
}