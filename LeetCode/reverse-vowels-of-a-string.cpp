#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        // O(N)
        int N = s.size();
        int lo = 0, hi = N - 1;
        while (lo < hi) {
            if (!is_vowel(s[lo])) {
                lo++;
                continue;
            }
            if (!is_vowel(s[hi])) {
                hi--;
                continue;
            }
            swap(s[lo], s[hi]);
            lo++; hi--;
        }
        return s;
    }
    
    inline bool is_vowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};