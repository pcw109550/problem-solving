#include<bits/stdc++.h>
using namespace std;
vector<bool> is_prime(10000, true);

inline void task(void) {
    int start, end;
    cin >> start >> end;
    bool visited[10000] = {};
    int distance[10000] = {};
    queue<int> Q;
    visited[start] = true;
    Q.push(start);
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        int acc = 1;
        while (acc < 10000) {
            for (int i = 1; i < 10; i++) {
                int digit = (current / acc) % 10;
                int next = current - digit * acc;
                next += (i + digit) % 10 * acc;
                if (next < 1000)
                    continue;
                if (!visited[next] && is_prime[next]) {
                    visited[next] = true;
                    distance[next] = distance[current] + 1;
                    Q.push(next);
                }
            }
            acc *= 10;
        }
    }
    if (visited[end])
        cout << distance[end] << '\n';
    else
        cout << "Impossible\n";
}

inline void init(void) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < 10000; i++) {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j < 10000; j += i)
            is_prime[j] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--)
        task();
}   