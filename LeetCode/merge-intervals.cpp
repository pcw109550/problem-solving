// 56. Merge Intervals
#include <vector>
#include <iostream>
#define MAX 10002 * 3 + 2

class Solution {
    public:
        std::vector<std::vector<int> > merge(std::vector<std::vector<int> >& intervals) {
            std::vector<std::vector<int> > result;
            // O(N)
            std::vector<int> D(MAX, 0);
            int max_end = -1;
            for (auto &interval : intervals) {
                D[3 * interval[0] + 1]++;
                D[3 * interval[1] + 1 + 1]--;
                max_end = std::max(max_end, 3 * interval[1] + 1 + 1);
            }
            for (int i = 1; i <= max_end + 1; i++) {
                D[i] += D[i - 1];
            }
            int start = -1; bool in = false;
            for (int i = 0; i <= max_end + 1; i++) {
                if (D[i]) {
                    if (!in) {
                        in = true;
                        start = i / 3;
                    }
                } else {
                    if (in) {
                        result.push_back(std::vector<int> {start, (i - 1) / 3});
                        in = false;
                    }
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}