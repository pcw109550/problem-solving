// 670. Maximum Swap
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maximumSwap(int num) {
            // O(N ** 2)
            vector<int> digits;
            int result = num;
            int temp = num;
            while (temp > 0) {
                digits.push_back(temp % 10);
                temp /= 10;
            }
            reverse(digits.begin(), digits.end());
            int N = digits.size();
            for (int i = 0; i < N; i++)
                for (int j = i + 1; j < N; j++) {
                    swap(digits[i], digits[j]);
                    result = max(result, reconstruct(digits));
                    swap(digits[i], digits[j]);            
                }
            return result;
        }
    
        int reconstruct(vector<int> &digits) {
            int result = 0;
            for (auto digit : digits) {
                result *= 10;
                result += digit;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}