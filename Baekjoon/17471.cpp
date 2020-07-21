#include<bits/stdc++.h>
using namespace std;
int N;
int num_people[10];
vector<int> path[10];

int summation(vector<bool> &avail, bool ind) {
    int sum, start = -1, cnt = 0, added = 1;
    for (int i = 0; i < N; i++)
        if (avail[i] == ind) {
            start = i;
            cnt++;
        }
    sum = num_people[start];
    queue<int> Q; bool visited[N] = {};
    Q.push(start); visited[start] = true;
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (auto it : path[current]) {
            if (avail[it] == ind) {
                if (!visited[it]) {
                    visited[it] = true;
                    added++;
                    sum += num_people[it];
                    Q.push(it);
                }
            }
        }
    }
    return added != cnt ? -1 : sum;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int total_sum = 0, result = 1 << 30;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num_people[i];
        total_sum += num_people[i];
    }
    for (int i = 0; i < N; i++) {
        int path_num, temp;
        cin >> path_num;
        for (int p = 0; p < path_num; p++) {
            cin >> temp;
            path[i].push_back(temp - 1);
        }
    }
    for (int i = 1; i < (1 << N) - 1; i++) {
        vector<bool> avail;
        int encoded = i;
        for (int pos = 0; pos < N; pos++) {
            avail.push_back(encoded & 1);
            encoded >>= 1;
        }
        int sum_true = summation(avail, true);
        int sum_false = summation(avail, false);
        if (sum_true == -1 || sum_false == -1)
            continue;
        result = min(result, abs(sum_true - sum_false));
    }
    cout << (result == 1 << 30 ? -1 : result);
}