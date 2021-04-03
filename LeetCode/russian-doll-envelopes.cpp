// 354. Russian Doll Envelopes
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

class Solution {
    public:
        int maxEnvelopes(std::vector<std::vector<int> >& envelopes) {
            // O(N ** 2)
            int size = envelopes.size();
            if (!size)
                return 0;
            std::sort(envelopes.begin(), envelopes.end());
            std::vector<int> maxrolls(size, 0); int maxroll = 1;
            maxrolls[0] = 1;
            for (int i = 1; i < size; ++i) {
                maxrolls[i] = 1;
                for(int j = i - 1; j >= 0; --j)
                    if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                        maxrolls[i] = std::max(maxrolls[i], maxrolls[j] + 1);
                maxroll = std::max(maxroll, maxrolls[i]);
            }
            return maxroll;
        }
};

int main(void) {
    Solution s;
}