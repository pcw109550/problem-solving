// 587. Erect the Fence
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void Add(int x, int y) {
        cout << "Add [" << x << ", " << y << "]" << endl;
    }
    
    void Del(int x, int y) {
        cout << "Del [" << x << ", " << y << "]" << endl;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // O(N * log(N))
        if (trees.size() <= 3)
            return trees;
        int N = trees.size();
        vector<int> result_idx;
        sort(trees.begin(), trees.end());        
        vector<int> A;
        for (int i = 0; i < N; i++) {
            if (A.size() < 2) {
                A.push_back(i);
                continue;
            }
            while (A.size() >= 2) {
                int x1 = trees[A[A.size() - 2]][0];
                int y1 = trees[A[A.size() - 2]][1];
                int x2 = trees[A[A.size() - 1]][0];
                int y2 = trees[A[A.size() - 1]][1];
                int x3 = trees[i][0];
                int y3 = trees[i][1];
                if ((x1 - x2) * (y2 - y3) - (x2 - x3) * (y1 - y2) < 0) {
                    A.pop_back();
                    if (A.size() == 1) {
                        A.push_back(i);
                        break;
                    }
                } else {
                    A.push_back(i);
                    break;
                }
            }
        }
        vector<int> B;
        for (int i = N - 1; i >= 0; i--) {
            if (B.size() < 2) {
                B.push_back(i);
                continue;
            }
            while (B.size() >= 2) {
                int x1 = trees[B[B.size() - 2]][0];
                int y1 = trees[B[B.size() - 2]][1];
                int x2 = trees[B[B.size() - 1]][0];
                int y2 = trees[B[B.size() - 1]][1];
                int x3 = trees[i][0];
                int y3 = trees[i][1];
                if ((x1 - x2) * (y2 - y3) - (x2 - x3) * (y1 - y2) < 0) {
                    B.pop_back();
                    if (B.size() == 1) {
                        B.push_back(i);
                        break;
                    }
                } else {
                    B.push_back(i);
                    break;
                }
            }
        }
        vector<vector<int> > result;
        unordered_set<int> S;
        for (int i = 0; i < A.size() - 1; i++) {
            S.insert(A[i]);
            result.push_back(trees[A[i]]);
        }
        for (int i = 0; i < B.size() - 1; i++)
            if (!S.count(B[i]))
                result.push_back(trees[B[i]]);
        return result;
    }
};

int main(void) {
    Solution s;
}