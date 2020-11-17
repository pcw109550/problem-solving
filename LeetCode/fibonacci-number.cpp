// 509. Fibonacci Number
#include <iostream>

class Solution {
    public:
        int fib(int N) {
            // O(N)
            int a = 0, b = 1, temp;
            while (N--) {
                temp = a + b;
                a = b;
                b = temp;
            }
            return a;
    }
};

int main(void) {
    Solution s;
    int N = 30;
    std::cout << s.fib(N);
}