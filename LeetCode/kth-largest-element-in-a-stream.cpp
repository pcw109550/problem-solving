// 703. Kth Largest Element in a Stream
#include <iostream>
#include <vector>
#include <queue>


class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
    int K;
    public:
        KthLargest(int k, std::vector<int>& nums): K{k} {
            // O(N * log(K))
            for (auto num : nums) {
                Q.push(num);
                if (Q.size() > K)
                    Q.pop();
            }
        }

        int add(int val) {
            // O(log(K))
            Q.push(val);
            if (Q.size() > K)
                Q.pop();
            return Q.top();
        }
};

int main(void) {
    
}