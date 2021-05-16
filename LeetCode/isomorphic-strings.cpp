// 205. Isomorphic Strings
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    public:
        bool isIsomorphic(std::string s, std::string t) {
            // O(N)
            std::unordered_map<char, char> M1, M2;
            int N = s.size();
            for (int i = 0; i < N; i++) {
                if (!M1.count(s[i]))
                    M1[s[i]] = t[i];
                else if (M1[s[i]] != t[i])
                    return false;
                if (!M2.count(t[i]))
                    M2[t[i]] = s[i];
                else if (M2[t[i]] != s[i])
                    return false;
            }
            return true;
        }
};

int main(void) {
    Solution s;
}