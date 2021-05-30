// 1878. Get Biggest Three Rhombus Sums in a Grid
#include <iostream>
#include <vector>
#include <set>

class Solution {
    int M, N;
    public:
        std::vector<int> getBiggestThree(std::vector<std::vector<int>>& grid) {
            // O(N ** 3)
            M = grid.size();
            N = grid[0].size();
            std::set<int, std::greater<int> > S;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k <= N; k++) {
                        int sum = 0;
                        if (k == 0) {
                            sum += grid[i][j];
                            S.insert(sum);
                            continue;
                        } else {
                            bool valid = true;
                            if (!valid)
                                continue;
                            for (int x = i - k; x < i; x++) {
                                if (check(x, j - x + (i - k)))
                                    sum += grid[x][j - x + (i - k)];
                                else {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                                continue;
                            for (int y = j - k; y < j; y++) {
                                if (check(i + y - (j - k), y))
                                    sum += grid[i + y - (j - k)][y];
                                else {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                                continue;
                            for (int x = i + k; x > i; x--) {
                                if (check(x, j + (i + k) - x))
                                    sum += grid[x][j + (i + k) - x];
                                else {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid)
                                continue;
                            for (int y = j + k; y > j; y--) {
                                if (check(i - (j + k - y), y))
                                    sum += grid[i - (j + k - y)][y];
                                else {
                                    valid = false;
                                    break;
                                }
                            }
                            if (valid)
                                S.insert(sum);
                        }
                    }
                }
            std::vector<int> result;
            auto it = S.begin();
            while (result.size() < 3 && it != S.end()) {
                result.push_back(*it);
                it++;
            }
            return result;
        }
    
    inline bool check(int x, int y) {
        if (x < 0 || y < 0 || x >= M || y >= N)
            return false;
        return true;
    }
};

int main(void) {
    Solution s;
}