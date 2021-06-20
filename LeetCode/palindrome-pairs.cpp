// 336. Palindrome Pairs
#include <algorithm>
#include <vector>
#include <string>

class Solution {
    public:
        std::vector<std::vector<int> > palindromePairs(std::vector<std::string>& words) {
            // O(N ** 2)
            std::vector<std::vector<int> > result;
            int N = words.size();
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (i != j && isPalindrome(words, i, j))
                        result.push_back(std::vector<int> {i, j});    
            return result;
        }
    
        inline bool isPalindrome(std::vector<std::string> &words, int i, int j) {
            int M = std::min(words[i].size(), words[j].size());
            for (int idx = 0; idx < M; idx++)
                if (words[i][idx] != words[j][words[j].size() - 1 - idx])
                    return false;
            if (words[i].size() == M) {
                for (int idx = 0; idx < (words[j].size() - M) / 2; idx++)
                    if (words[j][idx] != words[j][words[j].size() - M - 1 - idx])
                        return false;
            } else {
                for (int idx = 0; idx < (words[i].size() - M) / 2; idx++)
                    if (words[i][idx + M] != words[i][words[i].size() - 1 - idx])
                        return false;
            }
            return true;
        }
};

int main(void) {
    Solution s;
}