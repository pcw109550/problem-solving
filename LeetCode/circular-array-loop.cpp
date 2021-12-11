// 457. Circular Array Loop
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
#define MAX  1001
#define MIN -1001

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        // Time O(N) Space O(N)
        unordered_map<int, vector<int> > M;
        int N = nums.size();
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int curr = i;
            int next = (i + nums[curr] + MAX * N) % N;
            M[next].push_back(curr);
        }
        for (int i = 0; i < N; i++) {
            int curr = i;
            int next = (i + nums[curr] + MAX * N) % N;
            if (nums[curr] == MAX || nums[curr] == MIN)
                continue;
            if (curr == next || nums[curr] * nums[next] < 0) {
                nums[curr] = nums[curr] > 0 ? MAX : MIN;
                cnt++;
                queue<int> Q; Q.push(curr);
                while (!Q.empty()) {
                    int c = Q.front(); Q.pop();
                    for (auto it : M[c]) {
                        if (nums[it] == MAX || nums[it] == MIN)
                            continue;
                        nums[it] = nums[it] > 0 ? MAX : MIN;
                        Q.push(it);
                        cnt++;
                    }
                }
            }
        }
        return cnt != N;
    }
};

int main(void) {
    Solution s;
}
