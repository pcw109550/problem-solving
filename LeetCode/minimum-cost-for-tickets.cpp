// 983. Minimum Cost For Tickets
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>

class Solution {
    int result = INT_MAX;
    std::vector<int> span {1, 7, 30};
    std::vector<int> temp_costs;
    public:
        int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
            // O(N)
            temp_costs = std::vector<int> (days.size(), INT_MAX);
            backtrack(days, costs, 0, 0);
            return result;
        }
    
        void backtrack(std::vector<int>& days, std::vector<int>& costs, int idx, int cost) {
            if (idx >= days.size()) {
                result = std::min(result, cost);
                return;
            }
            for (int i = 0; i < 3; i++) {
                int next_idx = calc_next_idx(days, idx, span[i]);
                int next_cost = cost + costs[i];
                if (temp_costs[next_idx - 1] > next_cost) {
                    temp_costs[next_idx - 1] = next_cost;
                    backtrack(days, costs, next_idx, next_cost);
                }
            }
        }
    
        inline int calc_next_idx(std::vector<int>& days, int cur_idx, int span) {
            int expire = days[cur_idx] + span;
            int next_idx = cur_idx;  
            while (next_idx < days.size()) {
                if (days[next_idx] < expire)
                    next_idx++;
                else
                    break;
            }
            return next_idx;
        }
};

int main(void) {
    Solution s;
}