#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // O(M * log(N))
        vector<int> result;
        vector<int> D;
        int N = s.size(), M = queries.size();
        for (int i = 0; i < N; i++)
            if (s[i] == '|')
                D.push_back(i);
        for (int i = 0; i < M; i++) {
            int start = queries[i][0], end = queries[i][1];
            auto it1 = lower_bound(D.begin(), D.end(), start);
            if (it1 == D.end() || *it1 >= end) {
                result.push_back(0);
                continue;
            }
            int startpos = *it1;
            auto it2 = lower_bound(D.begin(), D.end(), end);
            if (it2 == D.end() || *it2 != end)
                it2--;
            int endpos = *it2;
            if (startpos >= endpos) {
                result.push_back(0);
                continue;
            }
            int curResult = endpos - startpos - 1;
            curResult -= it2 - it1 - 1;
            result.push_back(curResult);
        }
        return result;
    }
};