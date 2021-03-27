// 870. Advantage Shuffle
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
class Solution {
    public:
        std::vector<int> advantageCount(std::vector<int>& A, std::vector<int>& B) {
            // O(N * log(N))
            int N = A.size();
            std::vector<int> result(N, 0);
            std::vector<std::pair<int, int> > a, b;
            std::unordered_set<int> a_left, b_left;
            for (int i = 0; i < N; i++) {
                a.push_back({A[i], i});
                b.push_back({B[i], i});
                a_left.insert(i);
                b_left.insert(i);
            }
            std::sort(a.begin(), a.end());
            std::sort(b.begin(), b.end());
            int a_probe = N - 1, b_probe = N - 1;
            while (b_probe >= 0) {
                if (a[a_probe].first > b[b_probe].first) {
                    result[b[b_probe].second] = a[a_probe].first;
                    a_left.erase(a[a_probe].second);
                    b_left.erase(b[b_probe].second);
                    a_probe--;
                }
                b_probe--;
            }
            auto it1 = b_left.begin(), it2 = a_left.begin();
            while (it1 != b_left.end())
                result[*it1++] = A[*it2++];
            return result;
        }
};

int main(void) {
    Solution s;
}