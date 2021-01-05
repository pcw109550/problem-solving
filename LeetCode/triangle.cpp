// 120. Triangle
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int minimumTotal(std::vector<std::vector<int> >& triangle) {
            // Time O(N ** 2) Space O(N)
            int N = triangle.size();
            int D1[202] = {}; 
            for (int i = 1; i <= N; i++) {
                int D2[202] = {};
                D2[1] = D1[1] + triangle[i - 1][0];
                D2[i] = D1[i - 1] + triangle[i - 1][i - 1];
                for (int j = 2; j < i; j++)
                    D2[j] = std::min(D1[j], D1[j - 1]) + triangle[i - 1][j - 1];   
                for (int j = 1; j <= i; j++)
                    D1[j] = D2[j];
            }
            int result = 1 << 30;
            for (int i = 1; i <= N; i++)
                result = std::min(result, D1[i]);
            return result;
        }
};

int main(void) {
    Solution s;
}