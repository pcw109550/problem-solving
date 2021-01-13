// 88. Merge Sorted Array
#include <iostream>
#include <vector>

class Solution {
    public:
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
            // O(N)
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;
            while(i >= 0 && j >= 0) {
                if(nums1[i] > nums2[j])
                    nums1[k--] = nums1[i--];
                else
                    nums1[k--] = nums2[j--];
            }
            while(j >= 0)
                nums1[k--] = nums2[j--];
        }
};

int main(void) {
    Solution s;
}
