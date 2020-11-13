// 89. Gray Code
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> grayCode(int n) {
            // O(2 ** N)
            std::vector<int> result {0};
            for (int i = 0; i < n; i++)
                for (int j =  (1 << i) - 1; j >= 0; j--)
                    result.emplace_back(result[j] + (1 << i));
            return result;
        }
};

int main(void) {
    Solution s;
    int n = 5;
    auto result = s.grayCode(n);
    for (auto &it: result)
        std::cout << it << ' ';
}