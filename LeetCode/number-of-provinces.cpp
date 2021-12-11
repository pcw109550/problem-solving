// 547. Number of Provinces
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // O(N ** 2)
        int N = isConnected.size();
        int result = 0;
        vector<bool> visited(N);
        for (int i = 0; i < N; i++) {
            if (visited[i])
                continue;
            result++;
            queue<int> Q;
            Q.push(i); visited[i] = true;
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                for (int j = 0; j < N; j++) {
                    if (!isConnected[cur][j] || visited[j])
                        continue;
                    visited[j] = true;
                    Q.push(j);
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}