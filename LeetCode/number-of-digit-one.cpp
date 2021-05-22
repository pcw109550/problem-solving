// 233. Number of Digit One
#include <iostream>
#include <vector>

class Solution {
    public:
        int countDigitOne(int n) {
            // O(log(N))
            int result = 0;
            int temp = n;
            std::vector<int> T;
            while (temp) {
                T.push_back(temp % 10);
                temp /= 10;
            }
            int N = T.size();
            for (int i = N - 1; i >= 0; i--) {
                int cur = T[i];
                int a = pow(10, i - 1) * i;
                result += cur * a;
                if (cur > 1)
                    result += pow(10, i);
                else if (cur == 1)
                    result += n % pow(10, i) + 1;
            }
            return result;
        }
    
        int pow(long long n, int k) {
            if (n == 0 || k < 0)
                return 0;
            int result = 1;
            while (k) {
                if (k & 1)
                    result *= n;
                n *= n;
                k >>= 1;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}