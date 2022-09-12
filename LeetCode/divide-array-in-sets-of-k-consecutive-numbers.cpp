#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // O(N * log(N))
        int N = nums.size();
        map<int, int> M;
        for (auto num : nums)
            M[num]++;
        while (!M.empty()) {
            auto it = M.begin();
            int val = it->first;
            for (int i = val; i < val + k; i++) {
                if (!M.count(i))
                    return false;
                M[i]--;
                if (M[i] == 0)
                    M.erase(i);
            }
        }    
        return true;
    }
};