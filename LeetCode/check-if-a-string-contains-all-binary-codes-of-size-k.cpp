// 1461. Check If a String Contains All Binary Codes of Size K
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
    public:
        bool hasAllCodes(std::string s, int k) {
            // O(N + 2 ** K)
            int N = s.size();
            if (N < k)
                return false;
            std::unordered_set<int> S;
            for (int i = 0; i <= s.size() - k; i++) {
                int cur = std::stoi(s.substr(i, k), 0, 2); 
                S.insert(cur);
            }
            return S.size() == 1 << k;
        }
};

int main(void) {
    Solution s;
}