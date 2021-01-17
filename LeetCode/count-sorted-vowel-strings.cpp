// 1641. Count Sorted Vowel Strings
#include <algorithm>
#include <iostream>

class Solution {
    public:
        int countVowelStrings(int n) {
            int result = 0;
            int D[5] = {1, 1, 1, 1, 1};
            int D2[5] = {};
            for (int i = 2; i <= n; i++) {
                int acc = 0;
                for (int j = 0; j < 5; j++) {
                    acc += D[j];
                    D2[j] = acc;
                }
                for (int j = 0; j < 5; j++)
                    D[j] = D2[j];
            }
            for (int i = 0; i < 5; i++)
                result += D[i];
            return result;                
        }
};

int main(void) {
    Solution s;
}