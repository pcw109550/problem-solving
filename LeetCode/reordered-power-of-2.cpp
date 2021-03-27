// 869. Reordered Power of 2
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        bool reorderedPowerOf2(int N) {
            // O(M!)
            std::vector<int> digits;
            while (N > 0) {
                digits.push_back(N % 10);
                N /= 10;
            }
            std::sort(digits.begin(), digits.end());
            do {
                if (digits[0] == 0)
                    continue;
                int test = 0;
                for (int i = 0; i < digits.size(); i++) {
                    test *= 10;
                    test += digits[i];
                }
                if (powerOf2(test))
                    return true;
            } while(std::next_permutation(digits.begin(), digits.end()));
            return false;
        }
    
        inline bool powerOf2(int N) {
            return (N & (N - 1)) == 0;
        }
};

int main(void) {
    Solution s;
}