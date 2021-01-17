// 733. Flood Fill
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    public:
        std::vector<std::vector<int>> floodFill(std::vector<std::vector<int> >& image, int sr, int sc, int newColor) {
            // O(M * N)
            int target = image[sr][sc];
            int M = image.size();
            int N = image[0].size();
            std::queue<std::pair<int, int> > Q;
            std::vector<std::vector<bool> > visited (M, std::vector<bool> (N, false));
            Q.push({sr, sc});
            visited[sr][sc] = true;
            image[sr][sc] = newColor;
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int X = current.first + dx[dir];
                    int Y = current.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= M || Y >= N)
                        continue;
                    if (!visited[X][Y] && image[X][Y] == target) {
                        visited[X][Y] = true;
                        image[X][Y] = newColor;
                        Q.push({X, Y});
                    }
                }
            }
            return image;
        }
};

int main(void) {
    Solution s;
}