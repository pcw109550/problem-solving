// 51. N-Queens
#include <iostream>
#include <string>
#include <vector>

class Solution {
    int N;
    std::vector<std::vector<std::string> > result;
    std::vector<std::string> plane;
    std::vector<bool> isused1, isused2, isused3;
    std::vector<int> pos;
    public:
        std::vector<std::vector<std::string> > solveNQueens(int n) {
            // O(N!)
            N = n;
            isused1.resize(2 * n - 1, false);
            isused2.resize(2 * n - 1, false);
            isused3.resize(n, false);
            pos.resize(n, -1);
            for (int i = 0; i < n; i++)
                plane.emplace_back(std::string (n, '.'));
            backtrack(0);
            return result;
        }

        inline void encode(void) {
            result.push_back(plane);
            for (int i = 0; i < N; i++)
                result.back()[i][pos[i]] = 'Q';
        }

        void backtrack(int y) {
            if (y == N) {
                encode();
                return;
            }
            for (int x = 0; x < N; x++) {
                if (isused1[x + y] || isused2[x - y + N - 1] || isused3[x])
                    continue;
                isused1[x + y] = isused2[x - y + N - 1] = isused3[x] = true;
                pos[y] = x;
                backtrack(y + 1);
                isused1[x + y] = isused2[x - y + N - 1] = isused3[x] = false;
                pos[y] = -1;
            }
        }
};

inline void pprint(std::vector<std::string> sol) {
    for (auto row : sol)
        std::cout << row << std::endl;
    std::cout << std::endl;
}

int main(void) {
    Solution s;
    auto result = s.solveNQueens(6);
    for (auto sol : result)
        pprint(sol);
}