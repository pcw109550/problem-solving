// 823. Binary Trees With Factors
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#define FIELD 1000000007

class Solution {
    public:
        int numFactoredBinaryTrees(std::vector<int>& arr) {
            // O(N ** 2)
            std::sort(arr.begin(), arr.end());
            std::unordered_map<long, long> M;
            int result = 0;
            int N = arr.size();
            for (int i = 0; i < N; i++) {
                M[arr[i]]++;
                for (int j = 0; j < i; j++) {
                    if (arr[i] % arr[j] == 0) {
                        M[arr[i]] += M[arr[j]] * M[arr[i] / arr[j]];
                        M[arr[i]] %= FIELD;
                    }
                }
            }
            for (auto it : M)
                result = (result + it.second) % FIELD;
            return result;
        }
};

int main(void) {
    Solution s;
}