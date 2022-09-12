#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // O(N)
        int N = s.size();
        int result = 0;
        int probe = N - 1;
        while (s[probe] == ' ')
            probe--;
        for (int i = probe; i >= 0; i--)
            if (s[i] == ' ')
                break;
            else
                result++;
        return result;
    }
};