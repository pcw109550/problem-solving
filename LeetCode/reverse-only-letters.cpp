// 917. Reverse Only Letters
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        // O(N)
        int N = s.size();
        int lo = 0, hi = N - 1;
        while (lo <= hi) {
            if (isalpha(s[lo]) && isalpha(s[hi])) {
                swap(s[lo], s[hi]);
                hi--; lo++;
            } else if (isalpha(s[lo]) && !isalpha(s[hi]))
                hi--;
            else if (!isalpha(s[lo]) && isalpha(s[hi]))
                lo++;
            else {
                hi--; lo++;
            }
        }
        return s;
    }
};

int main(void) {
    Solution s;
}