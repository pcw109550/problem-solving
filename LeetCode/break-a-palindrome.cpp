// 1328. Break a Palindrome
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        // O(N)
        int N = palindrome.size();
        if (N == 1)
            return "";
        bool changed = false;
        for (int i = 0; i < N; i++) {
            if (i == N / 2 && N % 2 == 1)
                continue; 
            if (palindrome[i] > 'a') {
                palindrome[i] = 'a';
                changed = true;
                break;
            }
        }
        if (!changed)
            palindrome[N - 1]++;
        return palindrome;
    }
};

int main(void) {
    Solution s;
}