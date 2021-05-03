// 386. Lexicographical Numbers
#include <iostream>
#include <vector>

class Solution {
    std::vector<int> result;
    int N;
    public:
        std::vector<int> lexicalOrder(int n) {
            // O(N * log(N))
            N = n;
            for (int i = 1; i <= 9; i++)
                traverse(0, i);
            return result;
        }
    
        void traverse(int base, int idx) {
            if (base + idx <= N)
                result.push_back(base + idx);
            else
                return;
            int next_base = (base + idx) * 10;
            for (int i = 0; i <= 9; i++)
                traverse(next_base, i);
        }
};

int main(void) {
    Solution s;
}