// 1311. Get Watched Videos by Your Friends
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        // O(N + M * log(M))
        vector<string> result;
        int N = watchedVideos.size();
        vector<int> visited (N, -1);
        queue<int> Q;
        visited[id] = 0; Q.push(id);
        unordered_map<string, int> M;
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            if (visited[cur] == level) {
                for (auto c : watchedVideos[cur])
                    M[c]++;
            }
            for (auto f : friends[cur]) {
                if (visited[f] != -1)
                    continue;
                visited[f] = visited[cur] + 1;
                Q.push(f);
            }
        }
        vector<pair<int, string> > V;
        for (auto it : M)
            V.push_back({it.second, it.first});
        sort(V.begin(), V.end());
        for (auto it : V)
            result.push_back(it.second);
        return result;
    }
};

int main(void) {
    Solution s;
}
