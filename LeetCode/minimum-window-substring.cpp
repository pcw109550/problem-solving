// 76. Minimum Window Substring
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
    unordered_map<char, int> t_occ, s_occ;
public:
    string minWindow(string s, string t) {
        // O(M + N)
        for (auto it : t)
            t_occ[it]++;
        string result;
        int Min = INT_MAX;
        int r_start = 0, r_end = -1;
        int start = 0, end = 0;
        int M = s.size(), N = t.size();
        while (start <= end && end < M) {
            s_occ[s[end]]++; 
            while (is_included()) {
                if (Min > end - start + 1) {
                    Min = end - start + 1;
                    r_start = start;
                    r_end = end;
                }
                s_occ[s[start]]--;
                if (s_occ[s[start]] == 0)
                    s_occ.erase(s[start]);
                start++;
            }
            end++;
        }
        result = s.substr(r_start, r_end - r_start + 1);
        return result;
    }
    
    inline bool is_included() {
        // O(1)
        for (auto it : t_occ)
            if (!s_occ.count(it.first) || s_occ[it.first] < it.second)
                return false;
        return true;
    }
};

int main(void) {
    Solution s;
}