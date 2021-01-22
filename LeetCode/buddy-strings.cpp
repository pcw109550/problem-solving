// 859. Buddy Strings
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        bool buddyStrings(std::string A, std::string B) {
            // O(N)
            if (A.size() != B.size())
                return false;
            int diff = 0;
            std::vector<int> idx;
            std::unordered_set<char> S;
            for (int i = 0; i < A.size(); i++) {
                if (A[i] != B[i]) {
                    if (idx.size() == 2)
                        return false;
                    idx.push_back(i);
                    diff++;
                }        
                S.insert(A[i]);
            }
            if (idx.size() == 2) {
                if (A[idx[0]] != B[idx[1]])
                    return false;
                if (A[idx[1]] != B[idx[0]])
                    return false;
            } else if (idx.size() == 0) {
                if (S.size() == A.size())
                    return false;
            } else {
                return false;
            }
            return true;
        }
};

int main(void) {
    Solution s;
}