// 1275. Find Winner on a Tic Tac Toe Game
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        // O(1)
        vector<vector<int> > D(3, vector<int>(3, 0));
        int N = moves.size();
        for (int i = 0; i < N; i++)    
            D[moves[i][0]][moves[i][1]] = (i % 2 == 0 ? 1 : 2);
        bool c1 = check(D, 1);
        bool c2 = check(D, 2);
        if (c1 && !c2)
            return "A";
        if (!c1 && c2)
            return "B";
        return N < 9 ? "Pending" : "Draw";
    }
    
    inline bool check(vector<vector<int> > &D, int k) {
        for (int i = 0; i < 3; i++) {
            if (D[i][0] == D[i][1] && D[i][1] == D[i][2] && D[i][2] == k)
                return true;
            if (D[0][i] == D[1][i] && D[1][i] == D[2][i] && D[2][i] == k)
                return true;
        }
        if (D[0][0] == D[1][1] && D[1][1] == D[2][2] && D[2][2] == k)
            return true;
        if (D[0][2] == D[1][1] && D[1][1] == D[2][0] && D[2][0] == k)
            return true;
        return false;
    }
};

int main(void) {
    Solution s;
}