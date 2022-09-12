#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // O(N)
        unordered_map<char, int> M;
        for (auto c : magazine)
            M[c]++;
        for (auto c : ransomNote) {
            M[c]--;
            if (M[c] < 0)
                return false;
        }
        return true;
    }
};