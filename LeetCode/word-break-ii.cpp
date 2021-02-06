// 140. Word Break II
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
    std::unordered_set<std::string> wordSet;
    std::vector<std::unordered_set<int> > visited;
    std::vector<std::string> result;
    std::string target;
    int N;
    public:
        std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
            // O(2 ** N)
            N = s.size(); target = s;
            visited = std::vector<std::unordered_set<int> > (N, std::unordered_set<int>() );
            for (auto word : wordDict)
                wordSet.insert(word);
            backtrack(0);
            accumulate(N - 1, std::string (""));
            return result;
        }
    
        void accumulate(int end, std::string acc) {
            if (end < 0) {
                result.push_back(acc);
                return;
            }
            for (auto start : visited[end]) {
                auto temp = target.substr(start, end - start + 1);
                if (end != N - 1)
                    temp += " " + acc;
                accumulate(start - 1, temp);
            }
        }
    
        void backtrack(int start) {
            if (start == N)
                return;
            for (int i = N - start; i >= 1; i--) {
                auto temp = target.substr(start, i);
                if (wordSet.count(temp) && !visited[start + i - 1].count(start)) {
                    visited[start + i - 1].insert(start);
                    backtrack(start + i);
                }
            }
        }
};

int main(void) {
    Solution s;
}