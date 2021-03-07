// 820. Short Encoding of Words
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
    std::unordered_set<std::string> occ;
    public:
        int minimumLengthEncoding(std::vector<std::string>& words) {
            // O(K * N * log(N))
            int result = 0;
            for (auto &word : words)
                std::reverse(word.begin(), word.end());
            std::sort(words.begin(), words.end());
            std::string ref;
            for (auto &word : words) {
                if (!check(ref, word))
                    result += ref.size() + 1;   
                ref = word;
            }
            result += ref.size() + 1;
            return result;            
        }
    
        inline bool check(std::string &ref, std::string &target) {
            if (ref.size() <= target.size())
                if (target.substr(0, ref.size()) == ref)
                    return true;
            return false;
        }
};

int main(void) {
    Solution s;
}