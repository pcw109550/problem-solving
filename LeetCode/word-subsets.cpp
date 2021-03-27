// 916. Word Subsets
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
    public:
        std::vector<std::string> wordSubsets(std::vector<std::string>& A, std::vector<std::string>& B) {
            // O(N)
            std::vector<std::string> result;
            std::unordered_map<char, int> B_occs;
            for (auto word : B) {
                std::unordered_map<char, int> temp;
                for (auto c : word)
                    temp[c]++;
                for (auto it : temp)
                    if (!B_occs.count(it.first) || B_occs[it.first] < it.second)
                        B_occs[it.first] = it.second;
            }
            for (auto word : A) {
                auto occ = count(word);
                if (check(B_occs, occ))
                    result.push_back(word);
            }
            return result;
        }
    
        inline std::unordered_map<char, int> count(std::string &word) {
            std::unordered_map<char, int> M;
            for (auto c : word)
                M[c]++;
            return M;
        }
    
        inline bool check(std::unordered_map<char, int> &B_occs, std::unordered_map<char, int> &A) {
            for (auto it : B_occs) {
                if (!A.count(it.first))
                    return false;
                if (A[it.first] < it.second)
                    return false;
            }
            return true;
        }    
};

int main(void) {
    Solution s;
}