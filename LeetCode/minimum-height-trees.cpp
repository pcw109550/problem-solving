// 310. Minimum Height Trees
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans;
        
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n;i++){
            if(indegree[i]==1) q.push(i), indegree[i]--;
        } 
        
        while(!q.empty()){
            int s = q.size();
            ans.clear();
            for(int i=0; i<s;i++){
                int curr = q.front(); q.pop();
                ans.push_back(curr);
                for(auto child : graph[curr]){ 
                    indegree[child]--;
                    if(indegree[child] == 1)
                        q.push(child);   
                }
            }
        }
        if(n==1) ans.push_back(0);
        return ans;
        
    }
};

class Solution2 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // O(N ** 2)
        vector<int> result;
        vector<vector<int> > neighbor(n, vector<int>());
        // O(N)
        for (auto it : edges) {
            int a = it[0], b = it[1];
            neighbor[a].push_back(b);
            neighbor[b].push_back(a);
        }
        unordered_map<int, vector<int> > M;
        int Min = INT_MAX;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            vector<int> visited (n, -1);
            queue<int> Q;
            visited[i] = 0; Q.push(i);
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                for (auto it : neighbor[cur]) {
                    if (visited[it] != -1)
                        continue;
                    visited[it] = visited[cur] + 1;
                    Q.push(it);
                    temp = max(temp, visited[it]);
                }
            }
            M[temp].push_back(i);
            Min = min(Min, temp);
        }
        result = M[Min];
        return result;
    }
};

int main(void) {
    Solution s;
}