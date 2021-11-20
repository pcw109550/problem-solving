// 1483. Kth Ancestor of a Tree Node
#include <iostream>
#include <vector>
using namespace std;

class TreeAncestor {
    vector<vector<int> > D;    
public:
    TreeAncestor(int n, vector<int>& parent) {
        // O(N * log(N)) Sparse Table
        D = vector<vector<int> > (17, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            D[0][i] = parent[i - 1] + 1;
        for (int i = 1; i <= 16; i++)
            for (int j = 1; j <= n; j++)
                D[i][j] = D[i - 1][D[i - 1][j]];
    }
    
    int getKthAncestor(int node, int k) {
        // O(log(K))
        int cur_node = node + 1;
        int cur_k = k;
        int i = 0;
        while (k > 0) {
            if (k & 1)
                cur_node = D[i][cur_node];
            k >>= 1;
            i++;
        }
        int result = cur_node - 1;
        return result;
    }
};

int main(void) {
    TreeAncestor* obj;
}
