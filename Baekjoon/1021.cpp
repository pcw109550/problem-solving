#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, M; scanf("%d %d\n", &N, &M);
    int cnt = 0, input = 0, temp;
    deque<int> deq;
    for (int i = 1; i <= N; i++) {
        deq.push_back(i);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &input);
        deque<int>::iterator probe = deq.begin();
        for (auto it = deq.begin(); it != deq.end(); ++it) {
            if (*it == input) {probe = it; break; }
            temp++;
        }
        int size = deq.size();
        int value = min(temp, size - temp);
        cnt += value;
        probe = deq.erase(probe);
        rotate(deq.begin(), deq.begin() + temp, deq.end());
        temp = 0;
    }
    cout << cnt;
}