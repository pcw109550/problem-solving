// 400. Nth Digit
#include <iostream>
#include <vector>

class Solution {
    public:
        int findNthDigit(int n) {
            // O(log(N))
            long long N = n;
            long long acc = 0;
            long long chunk = 9;
            long long sub = 0;
            long long idx = 1;
            while ((acc + chunk * idx) < n) {
                acc += chunk * idx;
                chunk *= 10;
                idx++;
            }
            long long pos = n - acc;
            long long target = (chunk / 9) + (pos + idx - 1) / idx - 1;
            std::vector<long long> temp;
            while (target) {
                temp.push_back(target % 10);
                target /= 10;
            }
            long long result = temp[idx - 1 - (pos - 1) % idx];
            return result;
        }
};

int main(void) {
    Solution s;
}