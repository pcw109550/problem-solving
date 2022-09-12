#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // O(N * log(N))
        int result = 0;
        int N = stones.size();
        priority_queue<int> PQ;
        for (auto stone : stones)
            PQ.push(stone);
        while (PQ.size() >= 2) {
            int y = PQ.top(); PQ.pop();
            int x = PQ.top(); PQ.pop();
            if (y > x)
                PQ.push(y - x);
        }
        result = PQ.empty() ? 0 : PQ.top();
        return result;
    }
};