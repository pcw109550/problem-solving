// 792. Number of Matching Subsequences
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<char, vector<int> > M;
    public:
        int numMatchingSubseq(string s, vector<string>& words) {
            // O(M * K * log(N))
            int result = 0;
            int N = s.size();
            for (int i = 0; i < N; i++)
                M[s[i]].push_back(i);
            for (auto word : words)
                if (check(word))
                    result++;
            return result;
        }
    
        inline bool check(string &word) {
            // O(K * log(N))
            int idx = -1;
            for (auto c : word) {
                if (!M.count(c))
                    return false;
                auto it = lower_bound(M[c].begin(), M[c].end(), idx);
                if (it == M[c].end())
                    return false;
                idx = *it + 1;
            }
            return true;
        }
};


class Solution2 {
    public:
        int numMatchingSubseq(string s, vector<string>& words) {
            // O(M * N * K)
            int result = 0;
            for (auto word : words)
                if (check(word, s))
                    result++;
            return result;
        }
    
        inline bool check(string &word, string &s) {
            int idx = 0;
            for (int i = 0; i < s.size(); i++) {
                if (word[idx] == s[i])
                    idx++;
                if (idx == word.size())
                    return true;
            }
            return false;
        }
};

int main(void) {
    Solution s;
}