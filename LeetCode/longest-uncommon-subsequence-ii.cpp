// 522. Longest Uncommon Subsequence II
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        // O(N ** 2 * 2 ** M)
        int result = 0;
        int N = strs.size();
        for (int i = 0; i < N; i++) {
            int cur_max = 0;
            int M = strs[i].size();
            for (int j = 0; j < (1 << M); j++) {
                string temp_str;
                int temp = j, idx = 0;
                while (temp > 0) {
                    if (temp & 1)
                        temp_str.push_back(strs[i][idx]);
                    idx++;
                    temp >>= 1;
                }
                int temp_str_size = temp_str.size();
                if (compare(temp_str, i, strs))
                    cur_max = max(cur_max, temp_str_size);
            }
            result = max(result, cur_max);
        }
        return result == 0 ? -1 : result;
    }
    
    inline bool compare(string &target, int idx, vector<string> &strs) {
        int result = 0;
        for (int i = 0; i < strs.size(); i++)
            if (i != idx && is_subseq(target, strs[i]))
                return false;
        return true;
    }
    
    inline bool is_subseq(string &target, string &aim) {
        int idx = 0, probe = 0;
        while (idx < target.size()) {
            if (probe == aim.size())
                return false;
            if (target[idx] == aim[probe])
                idx++;
            probe++;
        }
        return true;
    }
};

int main(void) {
    Solution s;
}