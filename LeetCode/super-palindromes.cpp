// 906. Super Palindromes
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#define BOUND 1000000000

class Solution {
    __int128_t l, r;
    public:
        int superpalindromesInRange(std::string left, std::string right) {
            // O(W ** (1 / 4) * log(W))
            int result = 0;
            l = std::stol(left);
            r = std::stol(right);
            for (long long i = 1; i <= 1 << 16; i++) {
                int t = check(i, true);
                if (t == 1)
                    result++;
                if (t != -1) {
                    t = check(i);
                    if (t == 1)
                        result++;
                }
            }
            return result;
        }
        
        inline int check(long long i, bool is_odd=false) {
            long long temp = make(i, is_odd);
            if (temp > BOUND)
                return -1;
            temp *= temp;
            if (l <= temp && temp <= r && is_palindrome(temp))
                return 1;
            return 0;
        }
    
        inline long long make(long long n, bool is_odd=false) {
            long long result = n;
            while (n) {
                if (is_odd)
                    is_odd = false;
                else {
                    result *= 10;
                    result += n % 10;
                }
                n /= 10;
            }
            return result;
        }
    
        inline bool is_palindrome(long long n) {
            std::vector<int> temp;
            while (n) {
                temp.push_back(n % 10);
                n /= 10;
            }
            for (int i = 0; i < temp.size() / 2; i++)
                if (temp[i] != temp[temp.size() - 1 - i])
                    return false;
            return true;
        }
};

int main(void) {
    Solution s;
}