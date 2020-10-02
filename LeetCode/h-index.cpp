// 274. H-Index
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int hIndex(std::vector<int>& citations) {
            // O(N log(N))
            int size = citations.size();
            if (size == 0)
                return 0;
            std::sort(citations.begin(), citations.end(), std::greater<int>());
            int result = 0;
            while (result < size && citations[result] >= result + 1)
                result++;
            return result;
        }   
};

class Solution2 {
    public:
        int hIndex(std::vector<int>& citations) {
            // O(N log(N))
            int size = citations.size();
            if (size == 0)
                return 0;
            std::sort(citations.begin(), citations.end());
            int result = 0, upper;
            for (int i = 1; i <= size; i++) {
                upper = citations.end() - std::lower_bound(citations.begin(), citations.end(), i);
                if (i <= upper)
                    result = i;
                else
                    break;
            }
            return result;
        }   
};

int main(void) {
    Solution s;
    std::vector<int> citations {3, 0, 6, 1, 5};
    int result = s.hIndex(citations);
    std::cout << result;
}