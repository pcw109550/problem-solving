// 77. Combinations
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<int> > combine(int n, int k) {
            // iterative
            std::vector<std::vector<int> > result;
            std::vector<int> comb(k, 0);
            int i = 0;
            while (i >= 0) {
                comb[i]++;
                if (comb[i] > n)
                    i--;
                else if (i == k - 1)
                    result.push_back(comb);
                else {
                    i++;
                    comb[i] = comb[i - 1];
                }
            }
            return result;
        }
};

class Solution2 {
    std::vector<std::vector<int> > result;
    std::vector<bool> isused;
    std::vector<int> arr;
    int N, K;
    public:
        std::vector<std::vector<int> > combine(int n, int k) {
            // recursive
            isused.resize(n, false);
            arr.resize(k, 0);
            N = n; K = k;
            backtrack(0);
            return result;
        }

        void backtrack(int k) {
            if (k == K) {
                result.emplace_back(arr);
                return;
            }
            for (int i = 0; i < N; i++) {
                if (!isused[i]) {
                    if (k == 0 || arr[k - 1] < i + 1) {
                        arr[k] = i + 1;
                        isused[i] = true;
                        backtrack(k + 1);
                        isused[i] = false;
                    }
                }
            }
        }
};

int main(void) {
    Solution s;
    auto result = s.combine(4, 2);
    for (auto comb : result) {
        for (auto it : comb)
            std::cout << it << ' ';
        std::cout << std::endl;
    }
}