// 447. Number of Boomerangs
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // O(N ** 2)
        int result = 0;
        int N = points.size();
        for (int i = 0; i < N; i++) {
            unordered_map<int, int> M;
            for (int j = 0; j < N; j++) {
                if (i == j)
                    continue;
                int dist = sq(points[i][0] - points[j][0]) + sq(points[i][1] - points[j][1]);
                M[dist]++;
            }
            for (auto it : M)
                result += it.second * (it.second - 1);
        }
        return result;
    }
                            
    inline int sq(int n)  {
        return n * n;
    }
};

int main(void) {
    Solution s;
}