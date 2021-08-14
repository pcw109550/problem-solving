// 541. Reverse String II
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        // O(N)
        int N = s.size();
        int probe = 0;
        while (probe < N) {
            int end;
            if (probe + k < N)
                end = k;
            else
                end = N % (2 * k);
            for (int i = 0; i < end / 2; i++)
                swap(s[probe + i], s[probe + end - 1 - i]);
            probe += 2 * k;
        }
        return s;
    }
};

int main(void) {
    Solution s;
}