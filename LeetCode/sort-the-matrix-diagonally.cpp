// 1329. Sort the Matrix Diagonally
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<int> > diagonalSort(std::vector<std::vector<int> >& mat) {
            // O(M * N + (M + N) * log(min(M, N)))
            int M = mat.size(), N = mat[0].size();
            std::vector<std::vector<int> > result (M, std::vector<int> (N, 0));
            for (int i = 0; i < M; i++) {
                int X = i, Y = 0;
                std::vector<int> temp;
                while (X < M && Y < N) {
                    temp.push_back(mat[X][Y]);
                    X++; Y++;
                }
                std::sort(temp.begin(), temp.end());
                X = i, Y = 0;
                while (X < M && Y < N) {
                    result[X][Y] = temp[Y];
                    X++; Y++;
                }
            }
            for (int i = 1; i < N; i++) {
                int X = 0, Y = i;
                std::vector<int> temp;
                while (X < M && Y < N) {
                    temp.push_back(mat[X][Y]);
                    X++; Y++;
                }
                std::sort(temp.begin(), temp.end());
                X = 0, Y = i;
                while (X < M && Y < N) {
                    result[X][Y] = temp[X];
                    X++; Y++;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}