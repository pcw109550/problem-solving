// 526. Beautiful Arrangement
#include <iostream>
#include <vector>

class Solution {
    int result;
    bool used[16];
    int N;
    public:
        int countArrangement(int n) {
            // O(N!)
            result = 0;
            N = n;
            backtrack(1);
            return result;
        }
    
        void backtrack(int idx) {
            if (idx > N)
                result++;
            for (int i = 1; i <= N; i++) {
                if (!used[i]) {
                    if (idx % i == 0 || i % idx == 0) {
                        used[i] = true;
                        backtrack(idx + 1);
                        used[i] = false;
                    }
                }
            }
        }
};

int main(void) {
    Solution s;
}