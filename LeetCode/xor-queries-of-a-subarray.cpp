// 1310. XOR Queries of a Subarray
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int> >& queries) {
            // O(N)
            std::vector<int> result;
            int N = arr.size();
            std::vector<int> D (N + 1, 0);
            for (int i = 1; i <= N; i++)
                D[i] = D[i - 1] ^ arr[i - 1];
            for (auto query : queries)
                result.emplace_back(D[query[0]] ^ D[query[1] + 1]);
            return result;
        }
};

int main(void) {
    Solution s;
}