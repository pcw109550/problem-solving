// 1345. Jump Game IV
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        // O(N)
        int N = arr.size();
        int result;
        unordered_map<int, unordered_set<int> > M;
        for (int i = 0; i < N; i++)
            M[arr[i]].insert(i);
        vector<int> visited(N);
        queue<int> Q; Q.push(0);
        visited[0] = 1;
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            if (cur - 1 >= 0)
                if (!visited[cur - 1] || visited[cur - 1] > visited[cur] + 1) {
                    visited[cur - 1] = visited[cur] + 1;
                    Q.push(cur - 1);
                }
            if (cur + 1 < N)
                if (!visited[cur + 1] || visited[cur + 1] > visited[cur] + 1) {
                    visited[cur + 1] = visited[cur] + 1;
                    Q.push(cur + 1);
                }
            vector<int> temp;
            for (auto it : M[arr[cur]])
                if (!visited[it]) {
                    visited[it] = visited[cur] + 1;
                    Q.push(it);
                    temp.push_back(it);
                }
            for (auto it : temp)
                M[arr[cur]].erase(it);
        }
        result = visited[N - 1] - 1;
        return result;
    }
};

int main(void) {
    Solution s;
}
