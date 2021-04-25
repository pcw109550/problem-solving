// 667. Beautiful Arrangement II
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> constructArray(int n, int k) {
            // O(N)
            std::vector<int> result;
            for (int i = 1; i <= n - k - 1; i++)
                result.push_back(i);
            int c = n - k, d = n;
            int cnt = 0;
            bool state = true;
            while (cnt < k + 1) {
                if (cnt % 2 == 0) {
                    result.push_back(c); 
                    c++;
                } else {
                    result.push_back(d);
                    d--;
                }
                cnt++;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}