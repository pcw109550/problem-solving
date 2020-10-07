// 474. Ones and Zeroes
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
    public:
        int findMaxForm(std::vector<std::string>& strs, int m, int n) {
            // Time O(M * N * K) Space (M * N)
            std::vector<std::vector<int> > M(m + 1, std::vector<int>(n + 1, 0));
            for (auto &str: strs) {
                auto cnt = count(str);
                for (int i = m; i >= cnt.first; i--) {
                    for (int j = n; j >= cnt.second; j--) {
                        M[i][j] = std::max(M[i][j], M[i - cnt.first][j - cnt.second] + 1);
                    }
                }
            }
            return M[m][n];
        }
        std::pair<int, int> count(std::string &str) {
            int cnt1 = std::count(str.begin(), str.end(), '1');
            return {str.size() - cnt1, cnt1};
        }
};

int main(void) {
    Solution s;
    std::vector<std::string> strs {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;
    int result = s.findMaxForm(strs, m, n);
    std::cout << result;
}
