// 139. Word Break
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
    std::unordered_set<std::string> wordSet;
    std::unordered_set<int> visited;
    bool result;
    std::string target;
    int N;
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
            // O(N ** 2)
            result = false;
            target = s;
            N = s.size();
            for (auto word : wordDict)
                wordSet.insert(word);
            backtrack(0);
            return result;
        }
    
        void backtrack(int start) {
            if (start == N || result) {
                result = true;
                return;
            }
            if (visited.count(start))
                return;
            visited.insert(start);
            for (int i = N - start; i >= 1; i--) {
                auto temp = target.substr(start, i);
                if (wordSet.count(temp))
                    backtrack(start + i);
            }
        }
};

int main(void) {
    Solution s;
}