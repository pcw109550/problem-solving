// 788. Rotated Digits
#include <iostream>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        // O(N * log(N))
        int result = 0;
        for (int i = 1; i <= n; i++)
            if (isValid(i))
                result++;
        return result;
    }
    
    bool isValid(int n) {
        bool changed = false;
        while (n > 0) {
            int c = n % 10;
            if (c == 3 || c == 4 || c == 7)
                return false;
            if (c == 2 || c == 5 || c == 6 || c == 9)
                changed = true;
            n /= 10;
        }
        return changed;
    }
};

int main(void) {
    Solution s;
} 
