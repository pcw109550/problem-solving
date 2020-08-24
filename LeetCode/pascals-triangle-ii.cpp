// 119. Pascal's Triangle II
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> getRow(int rowIndex) {
            // Space O(N) Time O(N ** 2)
            std::vector<int> result;
            std::vector<int> temp;
            for (int i = 1; i <= rowIndex + 1; i++) {
                for (int j = 1; j <= i; j++) {
                    if (j == 1 || j == i)
                        temp.emplace_back(1);
                    else
                        temp.emplace_back(result[j - 2] + result[j - 1]);
                }
                result = temp;
                temp.resize(0);
            }
            return result;
        }
};

int main(void) {
    Solution s;
    auto result = s.getRow(0);
    for (auto it : result)
        std::cout << it << ' ';
}