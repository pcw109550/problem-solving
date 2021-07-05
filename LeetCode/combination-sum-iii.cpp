// 216. Combination Sum III
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int> > result;
    int N, K;
    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            // O(K * 9 ** K)
            N = n; K = k;
            backtrack(1, 0, 0, vector<int>());
            return result;
        }
    
        void backtrack(int start, int sum, int num, vector<int> storage) {
            if (num == K) {
                if (sum == N)
                    result.push_back(storage);
                return;
            }
            for (int i = start; i < 10; i++) {
                if (sum + i <= N) {
                    storage.push_back(i);
                    backtrack(i + 1, sum + i, num + 1, storage);
                    storage.pop_back();
                }
            }
        }
};

int main(void) {
    Solution s;
}