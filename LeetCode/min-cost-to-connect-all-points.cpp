#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
using namespace std;

class Solution {
    vector<pair<int, int> > mySet;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // O(E * log(E)) = O(N ** 2 * log(N))
        // Kruskal's algorithm
        int N = points.size();
        mySet = vector<pair<int, int> > (N + 1, {0, -1});
        vector<tuple<int, int, int> > edge;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                int dx = abs(points[i][0] - points[j][0]);
                int dy = abs(points[i][1] - points[j][1]);
                edge.push_back({dx + dy, i, j});
            }
        sort(edge.begin(), edge.end());
        int cnt = 0, result = 0;
        for (int i = 0; i < edge.size(); i++) {
            int cost, v1, v2;
            tie(cost, v1, v2) = edge[i];
            if (Union(v1, v2))
                continue;
            result += cost;
            if (++cnt == N - 1)
                break;
        }
        return result;
    }
    
    int Find(int x) {
        if (mySet[x].second < 0)
            return x;
        return mySet[x].second = Find(mySet[x].second);
    }
    
    bool Union(int x, int y) {
        int X = Find(x);
        int Y = Find(y);
        if (X == Y)
            return true;
        if (mySet[X].first < mySet[Y].first)
            swap(X, Y);
        mySet[Y].second = X;
        if (mySet[X].first == mySet[Y].first)
            mySet[X].first++;
        return false;
    }
};