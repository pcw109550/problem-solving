// 427. Construct Quad Tree
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    vector<vector<int> > D;
    int N;
    public:
        Node* construct(vector<vector<int>>& grid) {
            // O(N ** 2 * log(N))
            int N = grid.size();
            D = vector<vector<int> > (N + 1, vector<int>(N + 1, 0));
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + grid[i - 1][j - 1];
            return recurse(0, 0, N);
        }
        
        Node* recurse(int x, int y, int len) {
            int cnt = D[x + len][y + len] - D[x + len][y] - D[x][y + len] + D[x][y];
            Node *node = new Node();
            node->val = cnt > 0;
            if (len * len == cnt || cnt == 0)
                node->isLeaf = true;
            else if (len >= 2) {
                node->topLeft = recurse(x, y, len / 2);
                node->topRight = recurse(x, y + len / 2, len / 2);
                node->bottomLeft = recurse(x + len / 2, y, len / 2);
                node->bottomRight = recurse(x + len / 2, y + len / 2, len / 2);
            }
            return node;
        }
};

int main(void) {
    Solution s;
}