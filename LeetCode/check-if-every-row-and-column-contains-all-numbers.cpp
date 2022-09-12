#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        // O(N ** 2)
        int N = matrix.size();
        set<int> S;
        for (int i = 0; i < N; i++)
            S.insert(matrix[i][0]);
        if (S.size() != N)
            return false;
        for (int i = 0; i < N; i++) {
            int start = matrix[i][0] - 1;
            for (int j = 1; j < N; j++) {
                if ((start + 1) % N != matrix[i][j] - 1)
                    return false;
                start = (start + 1) % N;
            }
        }
        return true;
    }
};