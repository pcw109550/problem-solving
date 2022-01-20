// 167. Two Sum II - Input Array Is Sorted
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Time O(N) Space O(1)
        vector<int> result;
        int N = numbers.size();
        int lo = 0, hi = N - 1;
        while (true) {
            int cand = numbers[lo] + numbers[hi];
            if (cand == target)
                break;
            if (cand < target)
                lo++;
            else if (cand > target)
                hi--;
        }
        result = vector<int> {lo + 1, hi + 1};
        return result;
    }
}; 

int main(void) {
    Solution s;
}
