#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        // O(N)
        vector<int> result(k);
        unordered_map<int, unordered_set<int> > S;
        for (auto log : logs) {
            int idx = log[0], m = log[1];
            S[idx].insert(m);
        }
        for (auto it : S)
            if (it.second.size() >= 1)
                result[it.second.size() - 1]++;
        return result;
    }
};