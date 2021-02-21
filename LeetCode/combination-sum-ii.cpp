// 40. Combination Sum II
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    std::vector<std::vector<int> > result;
    std::vector<bool> visited;
    int N;
    int _target;
    public:
        std::vector<std::vector<int> > combinationSum2(std::vector<int>& candidates, int target) {
            // O(2 ** N)
            N = candidates.size(); _target = target;
            visited = std::vector<bool> (N, false);
            std::sort(candidates.begin(), candidates.end());
            backtrack(candidates, 0, std::vector<int> (), 0);
            return result;        
        }
    
        void backtrack(std::vector<int>& candidates, int start, std::vector<int> temp, int sum) {
            if (sum == _target) {
                result.push_back(temp);
                return; 
            }
            for (int i = start; i < N; i++) {
                if (i == start || candidates[i] != candidates[i - 1]) {
                    if (sum <= _target) {
                        temp.push_back(candidates[i]); sum += candidates[i];
                        backtrack(candidates, i + 1, temp, sum);
                        temp.pop_back(); sum -= candidates[i];
                    }
                }
            }
        }
};

int main(void) {
    Solution s;
}