#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // O(E + V * log(V))
        int N = s.size();
        int M = pairs.size();
        vector<unordered_set<int> > neighbors (N, unordered_set<int>());
        for (auto pair : pairs) {
            neighbors[pair[0]].insert(pair[1]);
            neighbors[pair[1]].insert(pair[0]);
        }
        vector<bool> visited(N);
        for (int i = 0; i < N; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            vector<char> curr;
            vector<int> idxs;
            curr.push_back(s[i]);
            idxs.push_back(i);
            queue<int> Q;
            Q.push(i);
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                for (auto neighbor : neighbors[cur])
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        Q.push(neighbor);
                        curr.push_back(s[neighbor]);
                        idxs.push_back(neighbor);
                    }
            }
            sort(curr.begin(), curr.end());
            sort(idxs.begin(), idxs.end());
            int L = curr.size();
            for (int j = 0; j < L; j++)
                s[idxs[j]] = curr[j];
        }
        return s;
    }
};