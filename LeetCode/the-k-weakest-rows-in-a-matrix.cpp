// 1337. The K Weakest Rows in a Matrix
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>

class Solution {
    public:
        std::vector<int> kWeakestRows(std::vector<std::vector<int> >& mat, int k) {
            // O(M * N * log(M))
            std::vector<std::pair<int, int> > temp;
            std::vector<int> result;
            for (int i = 0; i < mat.size(); i++)
                temp.push_back({std::accumulate(mat[i].begin(), mat[i].end(), 0), i});
            std::sort(temp.begin(), temp.end());
            for (int i = 0; i < k; i++)
                result.push_back(temp[i].second);
            return result;
        }
};

int main(void) {
    Solution s;
}