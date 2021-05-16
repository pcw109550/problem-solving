// 1354. Construct Target Array With Multiple Sums
#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        bool isPossible(std::vector<int>& target) {
            // O(N * log(N))
            int N = target.size();
            if (N == 1)
                return target[0] == 1;
            std::priority_queue<long long> Q;
            long long sum = 0;
            for (auto it : target) {
                Q.push(it);
                sum += it;
            }
            while (sum > N) {
                long long cur = Q.top(); Q.pop();
                long long y = (cur - Q.top()) / (sum - cur);
                if (y == 0)
                    y++;
                long long x = cur - (sum - cur) * y;
                if (x < 1)
                    return false;
                Q.push(x);
                sum = sum - cur + x;
            }
            return true;
        }
};

int main(void) {
    Solution s;
}