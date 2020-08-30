#include<bits/stdc++.h>
using namespace std;
char chset[4] = {'L', 'O', 'V', 'E'};
enum ch {L, O, V, E};

inline int num_occur(string s, char c) {
    int result = 0;
    for (auto it : s)
        if (it == c)
            result++;
    return result;
}

inline vector<int> cnt(string s) {
    vector<int> result;
    for (int i = 0; i < 4; i++) {
        result.emplace_back(num_occur(s, chset[i]));
    }
    return result;
}

inline int eval(vector<int> cnt1, vector<int> cnt2) {
    assert(cnt1.size() == 4 && cnt2.size() == 4);
    vector<int> cur;
    for (int i = 0; i < 4; i++)
        cur.emplace_back(cnt1[i] + cnt2[i]);
    int result = (cur[L] + cur[O]) % 100;
    result *= (cur[L] + cur[V]) % 100;
    result *= (cur[L] + cur[E]) % 100;
    result *= (cur[O] + cur[V]) % 100;
    result *= (cur[O] + cur[E]) % 100;
    result *= (cur[V] + cur[E]) % 100;
    result %= 100;
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string name, temp;
    int N;
    cin >> name >> N;
    vector<int> global = cnt(name);
    vector<string> names;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        names.emplace_back(temp);
    }
    int result = -1, Max = -1, eval_res;
    for (int i = 0; i < N; i++) {
        eval_res = eval(global, cnt(names[i]));
        if (eval_res > Max) {
            Max = eval_res;
            result = i;
        } else if (eval_res == Max) {
            if (names[result] > names[i])
                result = i;
        }
    }
    cout << names[result];
}   