// 118. Pascal's Triangle
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<int> > generate(int numRows) {
            // Space O(N ** 2) Time O(N ** 2)
            std::vector<std::vector<int> > result;
            for (int i = 0; i < numRows; i++) {
                result.emplace_back(std::vector<int>());
                for (int j = 0; j <= i; j++) {
                    if (j == 0 || j == i)
                        result[i].emplace_back(1);
                    else
                        result[i].emplace_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
    auto result = s.generate(10);
    for (auto row : result) {
        for (auto elem : row)
            std::cout << elem << ' ';
        std::cout << std::endl;
    }
}