// 946. Validate Stack Sequences
#include <iostream>
#include <vector>
#include <stack>

class Solution {
    public:
        bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
            // O(N)
            int idx = 0;
            int N = pushed.size();
            std::stack<int> S;
            for (int i = 0; i < N; i++) {
                S.push(pushed[i]);
                while (!S.empty() && S.top() == popped[idx]) {
                    idx++;
                    S.pop();
                }
            }
            return S.empty();
        }
};

int main(void) {
    Solution s;
}