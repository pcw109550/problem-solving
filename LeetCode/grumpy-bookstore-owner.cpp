// 1052. Grumpy Bookstore Owner
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
            // O(N)
            int base = 0, add = 0, temp = 0, result;
            int N = customers.size();
            for (int i = 0; i < N; i++) {
                base += customers[i] * !grumpy[i];
                if (grumpy[i])
                    temp += customers[i];
                if (i - minutes >= 0 && grumpy[i - minutes])
                    temp -= customers[i - minutes];
                add = std::max(add, temp);
            }
            result = base + add;
            return result;
        }
};

int main(void) {
    Solution s;
}