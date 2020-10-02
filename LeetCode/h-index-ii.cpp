// 275. H-Index II
#include <iostream>
#include <vector>

class Solution {
    public:
        int hIndex(std::vector<int>& citations) {
            // O(log(N))
            int size = citations.size();
            if (size == 0)
                return 0;
            int lo = 0, hi = size - 1, mid;
            int h = 0;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (citations[mid] >= size - mid) {
                    h = size - mid;
                    hi = mid - 1;
                } else {
                    lo  = mid + 1;
                }
            }
            return h;
        }
};

int main(void) {
    Solution s;
    std::vector<int> citations {0, 1, 3, 5, 6};
    int result = s.hIndex(citations);
    std::cout << result;
}