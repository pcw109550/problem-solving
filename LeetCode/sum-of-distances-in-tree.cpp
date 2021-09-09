// 834. Sum of Distances in Tree
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    vector<vector<int> > E;
    vector<unordered_map<int, int> > M;
    vector<int> result;
    int N;
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // O(N)
        N = edges.size() + 1;
        result = vector<int> (N, 0);
        M = vector<unordered_map<int, int> > (N, unordered_map<int, int>());
        E = vector<vector<int> > (N, vector<int>());
        for (auto e : edges) {
            E[e[0]].push_back(e[1]);
            E[e[1]].push_back(e[0]);
        }
        dfs(-1, 0);
        calc(-1, 0);
        return result;
    }
    
    void calc(int parent, int k) {
        for (auto e : E[k])
            if (e != parent) {
                int s = M[k][e];
                result[e] = result[k] - s + (N - s);
                calc(k, e);
            }
    }
    
    int dfs(int parent, int k) {
        int cur = 0;
        for (auto e : E[k]) {
            if (e != parent) {
                int s = dfs(k, e);
                M[k][e] = s;
                cur += s;
                result[0] += s;
            }
        }
        return cur + 1;
    }
};

int main(void) {
    Solution s;
}