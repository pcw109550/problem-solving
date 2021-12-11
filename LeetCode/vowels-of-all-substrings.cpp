// 2063. Vowels of All Substrings
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    long long countVowels(string word) {
        // O(N)
        long long result = 0;
        long long N = word.size();
        for (long long i = 0; i < N; i++)
            if (is_vowel(word[i]))
                result += (N - i) * (i + 1);
        return result;
    }
    
    inline bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main(void) {
    Solution s;
}
