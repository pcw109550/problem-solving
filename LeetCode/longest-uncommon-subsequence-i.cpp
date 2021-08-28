// 521. Longest Uncommon Subsequence I
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        // O(N)
        if (a.size() < b.size())
            swap(a, b);
        int p1 = 0, p2 = 0;
        int subseq_len = 0;
        while (p1 < a.size()) {
            if (p2 == b.size())
                break;
            if (a[p1] == b[p2]) {
                p1++;
                subseq_len++;
            }
            p2++;
        }
        return subseq_len == a.size() ? -1 : a.size();
    }
};

int main(void) {
    Solution s;
}