#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // O()
        int N = nums.size();
        int result = 0;
        int Min = *min_element(nums.begin(), nums.end());
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        result = Sum - Min * N;
        return result;
    }
};