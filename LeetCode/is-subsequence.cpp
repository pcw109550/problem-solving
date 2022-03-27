// 392. Is Subsequence
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // O(N)
        int N = t.size();
        int probe = 0;
        for (int i = 0; i < N; i++) {
            if (s[probe] == t[i])
                probe++;
        }
        return probe == s.size();
    }
};

int main(void) {
    Solution s;
}
