// 552. Student Attendance Record II
#include <vector>
#include <iostream>
#define RING 1000000007

class Solution {
public:
    int checkRecord(int N) {
        std::vector<std::vector<std::vector<long long> > > D(N, std::vector<std::vector<long long> >(2, std::vector<long long> (3, 0)));
        D[0][0][0] = D[0][0][1] = D[0][1][0] = 1;
        for (int i = 1; i < N; i++) {
            D[i][0][0] = D[i - 1][0][0] + D[i - 1][0][1] + D[i - 1][0][2];
            D[i][0][0] %= RING;
            D[i][0][1] = D[i - 1][0][0];
            D[i][0][2] = D[i - 1][0][1];
            D[i][1][0] = D[i - 1][0][0] + D[i - 1][0][1] + D[i - 1][0][2] +
                         D[i - 1][1][0] + D[i - 1][1][1] + D[i - 1][1][2];
            D[i][1][0] %= RING;
            D[i][1][1] = D[i - 1][1][0];
            D[i][1][2] = D[i - 1][1][1];
        }
        long long result = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                result += D[N - 1][i][j];
        result %= RING;
        return result;
    }
};

int main(void) {
    Solution s;
}