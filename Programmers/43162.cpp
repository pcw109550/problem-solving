#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int> > computers) {
    int answer = 0, idx = 0;
    vector<bool> visited(n, false);
    queue<int> Q;
    while (idx < n) {
        if (visited[idx]) {
            idx++;
            continue;
        }
        Q.push(idx); visited[idx] = true;
        idx++;
        while (!Q.empty()) {
            int current = Q.front(); Q.pop();
            for (int i = 0; i < n; i++) {
                if (computers[current][i] == 1 && !visited[i]) {
                    Q.push(i); visited[i] = true;
                    if (i == idx)
                        idx++;
                }
            }
        }
        answer++;
    }
    return answer;
}

int main(void) {
}