// 784. Letter Case Permutation
#include <iostream>
#include <cctype>
#include <vector>
#include <string>

class Solution {
    std::vector<std::string> result;
    public:
        std::vector<std::string> letterCasePermutation(std::string S) {
            // O(N * 2 ** M)
            std::vector<int> idxs;
            int N = S.size();
            for (int i = 0; i < S.size(); i++)
                if (std::isalpha(S[i]))
                    idxs.push_back(i);
            if (idxs.size() == 0) {
                result.push_back(S);
                return result;
            }
            for (int i = 0; i < 1 << idxs.size(); i++) {
                int temp = i;
                std::string res = S;
                for (int j = 0; j < idxs.size(); j++) {
                    if (temp & 1)
                        res[idxs[j]] = convert(res[idxs[j]]); 
                    temp >>= 1;
                }
                result.push_back(res);
            }
            return result;
        }
    
        inline char convert(char c) {
            return c >= 'a' ? c - 'a' + 'A' : c + 'a' - 'A';   
        }
};

int main(void) {
    Solution s;
}