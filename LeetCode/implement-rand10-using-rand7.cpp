// 470. Implement Rand10() Using Rand7()
#include <iostream>
#include <random>

class Solution {
    public:
        int rand10() {
            // Rejection sampling
            int x, y, idx;
            do {
                x = rand7();
                y = rand7();
                idx = x + (y - 1) * 7;
            } while (idx > 40);
            return 1 + (idx - 1) % 10;
        }
        
        int rand7() {
            std::random_device rd;
            std::mt19937 mersenne(rd());
            std::uniform_int_distribution<> dist(1, 7);
            return dist(mersenne);
        }
};

int main(void) {
    Solution s;
    for (int i = 0; i < 100; i++)
        std::cout << s.rand10() << ' ';
}