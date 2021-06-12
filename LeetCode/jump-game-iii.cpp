// 1306. Jump Game III
#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        bool canReach(std::vector<int>& arr, int start) {
            // O(N)
            int N = arr.size();
            std::vector<bool> visited (N, false);
            std::queue<int> Q;
            visited[start] = true;
            Q.push(start);
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                if (cur + arr[cur] < N && !visited[cur + arr[cur]]) {
                    visited[cur + arr[cur]] = true;
                    Q.push(cur + arr[cur]);
                }
                if (cur - arr[cur] >= 0 && !visited[cur - arr[cur]]) {
                    visited[cur - arr[cur]] = true;
                    Q.push(cur - arr[cur]);
                }
            }
            for (int i = 0; i < N; i++)
                if (arr[i] == 0 && visited[i])
                    return true;
            return false;
        }
};

int main(void) {
    Solution s;
}