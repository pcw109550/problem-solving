// 973. K Closest Points to Origin
#include <iostream>
#include <vector>
#include <functional>
#include <queue>

class Solution {
    public:
        std::vector<std::vector<int> > kClosest(std::vector<std::vector<int> >& points, int K) {
            // O(N * log(K))
            std::vector<std::vector<int> > result;
            auto cmp = [=](std::vector<int> &left, std::vector<int> &right) {
                return dist(left) < dist(right);
            };
            std::priority_queue<std::vector<int>, std::vector<std::vector<int> >, decltype(cmp)> Q(cmp);
            for (auto point : points) {
                Q.push(point);
                if (Q.size() > K)
                    Q.pop();
            }
            while (!Q.empty()) {
                result.push_back(Q.top()); Q.pop();
            }
            return result;
        }
    
        inline int dist(std::vector<int> &P) {
            return P[0] * P[0] + P[1] * P[1];
        }
};

int main(void) {
    Solution s;
}