// 39. Combination Sum
#include <iostream>
#include <vector>

class Solution {
    std::vector<std::vector<int> > result;
    std::vector<int> cand;
    int N;
    public:
        std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates, int target) {
            cand = candidates;
            N = cand.size();
            std::vector<int> sol;
            backtrack(0, target, sol);
            return result;
        }
        void backtrack(int start, int sum, std::vector<int> &sol) {
            if (sum == 0) {
                result.push_back(sol); 
                return;
            }   
            if (start == N)
                return;
            for (int i = start; i < N; i++) {
                if (sum - cand[i] >= 0) {
                    sol.push_back(cand[i]);
                    backtrack(i, sum - cand[i], sol);
                    sol.pop_back();
                }
            }            
        }
};

int main(void) {
    Solution s;
    std::vector<int> candidates {1};
    int target = 2;
    auto result = s.combinationSum(candidates, target);
    for (auto it : result) {
        for (auto elem : it)
            std::cout << elem << ' ';
        std::cout << std::endl;
    }
}