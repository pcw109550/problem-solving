// 454. 4Sum II
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // Time O(N ** 2) Space O(N ** 2)
        int N = nums1.size();
        int result = 0;
        unordered_map<int, int> M1, M2;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                M1[nums1[i] + nums2[j]]++;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                M2[nums3[i] + nums4[j]]++;
        for (auto it : M1)
            result += it.second * M2[-it.first];
        return result;
    }
};

int main(void) {
    Solution s;
}
