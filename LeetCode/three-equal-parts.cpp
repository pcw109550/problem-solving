// 927. Three Equal Parts
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        // O(N)
        vector<int> result {-1, -1};
        vector<int> pos;
        int N = arr.size();
        for (int i = 0; i < N; i++)
            if (arr[i] == 1)
                pos.push_back(i);
        int M = pos.size();
        if (M % 3 != 0)
            return result;
        if (M == 0)
            return vector<int> {0, 2};
        for (int i = 0; i < M / 3; i++) {
            if (pos[i] - pos[0] != pos[i + M / 3] - pos[M / 3])
                return vector<int> {-1, -1};
            if (pos[i] - pos[0] != pos[i + 2 * M / 3] - pos[2 * M / 3])
                return vector<int> {-1, -1};
        }
        int trail = N - 1 - pos[M - 1];
        if (pos[2 * M / 3] - pos[2 * M / 3 - 1] - 1 < trail)
            return vector<int> {-1, -1};
        else
            result[1] = pos[2 * M / 3 - 1] + trail + 1;
        if (pos[M / 3] - pos[M / 3 - 1] - 1 < trail)
            return vector<int> {-1, -1};
        else
            result[0] = pos[M / 3 - 1] + trail;
        return result;
    }
};

int main(void) {
    Solution s;
}