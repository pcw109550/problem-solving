#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // O(N * log(N))
        vector<vector<int> > result;
        int N = matches.size();
        vector<int> ans1, ans2;
        unordered_map<int, int> indegree, outdegree;
        for (auto match : matches) {
            int W = match[0], L = match[1];
            indegree[L]++; outdegree[W]++;
        }
        for (auto it : outdegree)
            if (!indegree.count(it.first))
                ans1.push_back(it.first);
        for (auto it : indegree)
            if (it.second == 1)
                ans2.push_back(it.first);
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());
        result.push_back(ans1);
        result.push_back(ans2);
        return result;
    }
};