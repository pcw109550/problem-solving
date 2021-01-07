
// 48. Rotate Image
#include <iostream>
#include <vector>

class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    public:
        void rotate(std::vector<std::vector<int> >& matrix) {
            // O(N ** 2)
            int n = matrix.size();
            int N = n, i = 0;
            while (N > 0) {
                int x = 0, y = 0, sx = 0, sy = 0;
                int acc = 0;
                while (acc < 3 * (N - 1)) {
                    sx = x + (N - 1) * dx[acc / (N - 1)];
                    sy = y + (N - 1) * dy[acc / (N - 1)];
                    if (sx > N - 1) {
                        sy += sx % (N - 1);
                        sx = N - 1;
                    } else if (sx < 0) {
                        sy += sx;
                        sx = 0;
                    }
                    if (sy > N - 1) {
                        sx -= sy % (N - 1);
                        sy = N - 1;
                    } else if (sy < 0) {
                        sx -= sy;
                        sy = 0;
                    }
                    std::swap(matrix[i + x][i + y], matrix[i + sx][i + sy]);
                    x = x + dx[acc / (N - 1)];
                    y = y + dy[acc / (N - 1)];
                    acc++;
                }
                N -= 2;
                i++;
            }
        }
};

int main(void) {
    Solution s;
}