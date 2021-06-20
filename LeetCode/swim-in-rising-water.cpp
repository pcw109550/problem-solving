// 778. Swim in Rising Water
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    // Union Find: {rank, parent}
    std::vector<std::pair<int, int> > mySet;
    public:
        int swimInWater(std::vector<std::vector<int> >& grid) {
            // O(N ** 2)
            int N = grid.size();
            mySet = std::vector<std::pair<int, int> > (N * N, {0, -1});
            std::vector<std::pair<int, int> > D(N * N);
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    D[grid[i][j]] = {i, j};
            for (int t = 0; t < N * N; t++) {
                int x = D[t].first;
                int y = D[t].second;
                for (int dir = 0; dir < 4; dir++) {
                    int X = x + dx[dir];
                    int Y = y + dy[dir];
                    if (X < 0 || Y < 0 || X >= N || Y >= N)
                        continue;
                    if (grid[X][Y] <= t)
                        Union(N * x + y, N * X + Y);
                }
                if (Find(N * 0 + 0) == Find(N * (N - 1) + (N - 1)))
                    return t;
            }
            return N * N - 1;
        }
    
        int Find(int x) {
            if (mySet[x].second < 0) { return x; }
            // Path compression
            return mySet[x].second = Find(mySet[x].second);
        }

        bool Union(int x, int y) {
            // O(invack(N))
            int X = Find(x);
            int Y = Find(y);
            if (X == Y) { return true; }
            if (mySet[X].first < mySet[Y].first) {
                std::swap(X, Y);
            }
            mySet[Y].second = X;
            if (mySet[X].first == mySet[Y].first) {
                mySet[X].first++;
            }
            return false;
        }  
};


class Solution2 {
    public:
        int swimInWater(std::vector<std::vector<int> >& grid) {
            // O(N ** 4)
            int N = grid.size();
            for (int t = 0; t < N * N - 1; t++) {
                if (grid[0][0] > t)
                    continue;
                std::vector<std::vector<bool> > visited (N, std::vector<bool>(N, false));
                std::queue<std::pair<int, int> > Q;
                visited[0][0] = true; Q.push({0, 0});
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = cur.first + dx[dir];
                        int Y = cur.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= N)
                            continue;
                        if (visited[X][Y])
                            continue;
                        if (grid[X][Y] <= t) {
                            if (X == N - 1 && Y == N - 1)
                                return t;
                            visited[X][Y] = true;
                            Q.push({X, Y});
                        }
                    }
                }
            }
            return N * N - 1;
        }
};

int main(void) {
    Solution s;
}