#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        // O(N)
        int N = s.size();
        int lo = 0, hi = N - 1;
        bool skipped = false;
        bool r1 = true, r2 = true;
        while (lo < hi) {
            if (s[lo] == s[hi]) {
                lo++; hi--;
                continue;
            }
            if (skipped) {
                r1 = false;
                break;   
            }
            if (lo <= hi - 1 && s[lo] == s[hi - 1]) {
                skipped = true;
                hi -= 2;
                lo++;
                continue;
            }
            r1 = false;
            break;
        }
        lo = 0, hi = N - 1, skipped = false;
        while (lo < hi) {
            if (s[lo] == s[hi]) {
                lo++; hi--;
                continue;
            }
            if (skipped) {
                r2 = false;
                break;
            }
            if (lo + 1 <= hi && s[lo + 1] == s[hi]) {
                skipped = true;
                lo += 2;
                hi--;
                continue;
            }
            r2 = false;
            break;
        }
        return r1 || r2;
    }
};