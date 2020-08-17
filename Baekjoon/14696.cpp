#include<bits/stdc++.h>
using namespace std;
enum Shape {DUMMY, TRI, SQU, CIR, STAR}; 

inline vector<int> count(void) {
    vector<int> cnt(5, 0);
    int len, temp;
    cin >> len;
    while (len--) {
        cin >> temp;
        cnt[temp]++;
    }
    return cnt;
}

inline void task(void) {
    vector<int> A_cnt = count();
    vector<int> B_cnt = count();
    if (A_cnt[STAR] == B_cnt[STAR]) {
        if (A_cnt[CIR] == B_cnt[CIR]) {
            if (A_cnt[SQU] == B_cnt[SQU]) {
                if (A_cnt[TRI] == B_cnt[TRI]) {
                    cout << 'D';
                } else 
                    cout << (A_cnt[TRI] > B_cnt[TRI] ? 'A' : 'B');
            } else
                cout << (A_cnt[SQU] > B_cnt[SQU] ? 'A' : 'B');
        } else
            cout << (A_cnt[CIR] > B_cnt[CIR] ? 'A' : 'B');
    } else
        cout << (A_cnt[STAR] > B_cnt[STAR] ? 'A' : 'B');
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        task();
}   