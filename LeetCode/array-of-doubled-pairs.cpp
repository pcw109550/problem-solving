// 954. Array of Doubled Pairs
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        // O(N * log(N))
        int N = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, vector<int> > M;
        for (int i = 0; i < N; i++)
            M[arr[i]].push_back(i);
        vector<bool> visited (N, false);
        if (M.count(0)) {
            if (M[0].size() % 2 == 1)
                return false;
            for (auto it : M[0])
                visited[it] = true;
        }
        int probe = N - 1;
        while (probe >= 0 && arr[probe] > 0) {
            if (!visited[probe]) {
                if (arr[probe] % 2 == 1)
                    return false;
                int target = arr[probe] / 2;
                if (!M.count(target) || M[target].size() == 0)
                    return false;
                visited[probe] = true;
                visited[M[target].back()] = true;
                M[target].pop_back();
            }
            probe--;
        }
        probe = 0;
        while (probe < N && arr[probe] < 0) {
            if (!visited[probe]) {
                if (abs(arr[probe]) % 2 == 1)
                    return false;
                int target = arr[probe] / 2;
                if (!M.count(target) || M[target].size() == 0)
                    return false;
                visited[probe] = true;
                visited[M[target].back()] = true;
                M[target].pop_back();
            }
            probe++;
        }
        return true;
    }
};

int main(void) {
    Solution s;
}