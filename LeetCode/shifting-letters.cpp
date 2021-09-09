// 848. Shifting Letters
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        // O(N)
        string result = s;
        int N = shifts.size();
        int acc = 0;
        for (int i = N - 1; i >= 0; i--) {
            acc += shifts[i];
            acc %= 26;
            result[i] = shift(s[i], acc);
        }
        return result;
    }
    
    inline char shift(char c, int i) {
        return 'a' + (c - 'a' + i) % 26;
    }
};

int main(void) {
    Solution s;
}