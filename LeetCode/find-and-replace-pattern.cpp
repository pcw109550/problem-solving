// 890. Find and Replace Pattern
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

class Solution {
    int N;
    public:
        std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
            // O(N)
            std::vector<std::string> result;
            N = pattern.size();
            for (auto word : words)
                if (check(word, pattern))
                    result.push_back(word);
            return result;            
        }
    
        bool check(std::string &word, std::string &target) {
            std::unordered_map<char, char> M;
            std::unordered_set<char> S;
            for (int i = 0; i < N; i++) {
                if (!M.count(word[i])) {
                    if (S.count(target[i]))
                        return false;
                    M[word[i]] = target[i];
                    S.insert(target[i]);
                } else if (M[word[i]] != target[i])
                    return false;
            }
            return true;
        }
};

int main(void) {
    Solution s;
}