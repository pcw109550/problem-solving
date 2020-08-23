// 204. Count Primes
#include <iostream>
#include <vector>

class Solution {
    public:
        int countPrimes(int n) {
            // O(N * log(log(N)))
            if (n == 0)
                return 0;
            int result = 0;
            std::vector<bool> is_prime(n, true);
            is_prime[0] = is_prime[1] = false;
            for (int i = 2; i * i < n; i++) {
                if (!is_prime[i])
                    continue;
                for (int j = i * i; j < n; j += i)
                    is_prime[j] = false;
            }
            for (int i = 2; i < n; i++)
                if (is_prime[i])
                    result++;
            return result;
        }
};

int main(void) {
    Solution s;
    int result = s.countPrimes(3);
    std::cout << result;
}