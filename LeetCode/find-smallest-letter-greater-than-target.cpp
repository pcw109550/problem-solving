#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // O(log(N))
        letters.push_back('}'); // larger than "z"
        int N = letters.size();
        target++;
        int lo = 0, hi = N - 1, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (letters[mid] < target) 
                lo = mid + 1;
            else
                hi = mid;
        }
        if (letters[mid] <= target - 1)
            mid = (mid + 1) % N;
        if (letters[mid] == '}')
            mid = 0;
        return letters[mid];
    }
};