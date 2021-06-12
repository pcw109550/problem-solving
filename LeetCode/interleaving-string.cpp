// 97. Interleaving String
#include <iostream>
#include <string>
#include <utility>
#include <unordered_set>

class Solution {
    public:
        bool isInterleave(std::string s1, std::string s2, std::string s3) {
            // Time O(N ** 2) Space O(N)
            int N1 = s1.size(), N2 = s2.size();
            if (N1 + N2 != s3.size())
                return false;
            std::unordered_set<int> S;
            for (int i = 0; i < s3.size(); i++) {
                std::unordered_set<int> temp;
                if (i == 0) {
                    if (0 < N1 && s1[0] == s3[0])
                        temp.insert(1 * 101 + 0);
                    if (0 < N2 && s2[0] == s3[0])
                        temp.insert(0 * 101 + 1);
                } else {
                    for (auto it : S) {
                        int p1 = it / 101;
                        int p2 = it % 101;
                        if (p1 < N1 && s1[p1] == s3[i])
                            temp.insert((p1 + 1) * 101 + p2);
                        if (p2 < N2 && s2[p2] == s3[i])
                            temp.insert(p1 * 101 + (p2 + 1));
                    }
                }
                S = temp;
            }
            return !S.empty() || s3.size() == 0;
        }
};

int main(void) {
    Solution s;
}