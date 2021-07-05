// 10. Regular Expression Matching
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    bool result;
    unordered_map<int, bool> M;
    public:
        bool isMatch(string s, string p) {
            // O(M * N)
            result = false;
            backtrack(s, p, 0, 0);
            return result;
        }
    
        inline int encode(int i, int j) {
            return 100 * i + j;
        }
    
        inline pair<int, int> decode(int k) {
            return {k / 100, k % 100};
        }
    
        bool backtrack(string &s, string &p, int i, int j) {
            if (M.count(encode(i, j)))
                return M[encode(i, j)];
            if (i == s.size() && j == p.size()) {
                M[encode(i, j)] = true;
                result = true;
                return true;
            }
            
            bool temp = false;
            if (j < p.size() && p[j] == '.') {
                temp |= backtrack(s, p, i + 1, j + 1);
                if (j + 1 < p.size() && p[j + 1] == '*')
                    temp |= backtrack(s, p, i, j + 2);
            } else if (j < p.size() && p[j] == '*') {
                char prev = p[j - 1]; // must be valid
                if (prev == '.') {
                    for (int k = i; k < s.size(); k++)
                        temp |= backtrack(s, p, k + 1, j + 1);
                } else if (i < s.size() && prev == s[i]){
                    for (int k = i; k < s.size() && prev == s[k]; k++)
                        temp |= backtrack(s, p, k + 1, j + 1);
                }
                // ignore *
                temp |= backtrack(s, p, i, j + 1);
            } else {
                if (i < s.size() && j < p.size() && s[i] == p[j])
                    temp |= backtrack(s, p, i + 1, j + 1);
                if (j + 1 < p.size() && p[j + 1] == '*')
                    temp |= backtrack(s, p, i, j + 1);
            }
            
            M[encode(i, j)] = temp;
            return temp;
        }
};

int main(void) {
    Solution s;
}