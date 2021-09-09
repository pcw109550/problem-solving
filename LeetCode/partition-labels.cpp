// 763. Partition Labels
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // O(N + M * log(M))
        vector<int> result;
        unordered_map<char, pair<int, int> > Map;
        vector<pair<int, int> > D;
        int N = s.size();
        for (int i = 0; i < N; i++) {
            if (Map.count(s[i]))
                Map[s[i]].second = i;
            else
                Map[s[i]] = {i, i};
        }
        for (auto it : Map)
            D.push_back(it.second);
        sort(D.begin(), D.end());
        int M = D.size();
        int base = D[0].first, cur = D[0].second;
        for (int i = 1; i < M; i++) {
            if (cur > D[i].first) {
                cur = max(cur, D[i].second);
            } else {
                result.push_back(cur - base + 1);
                base = D[i].first, cur = D[i].second;
            }
        }
        result.push_back(cur - base + 1);
        return result;
    }
};

int main(void) {
    Solution s;
}