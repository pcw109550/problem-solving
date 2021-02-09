// 912. Sort an Array
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> sortArray(std::vector<int>& nums) {
            int N = nums.size();
            mergesort(nums, 0, N - 1);
            return nums;
        }
    
        void mergesort(std::vector<int> &nums, int start, int end) {
            if (start >= end)
                return;
            mergesort(nums, start, (start + end) / 2);
            mergesort(nums, (start + end) / 2 + 1, end);
            merge(nums, start, end);
        }
    
        void merge(std::vector<int> &nums, int start, int end) {
            int mid = (start + end) / 2;
            std::vector<int> merged;
            int a = start, b = mid + 1;
            while (!(a == mid + 1 && b == end + 1)) {
                if (a == mid + 1)
                    merged.push_back(nums[b++]);
                else if (b == end + 1)
                    merged.push_back(nums[a++]);
                else if (nums[a] > nums[b])
                    merged.push_back(nums[b++]);
                else if (nums[a] <= nums[b])
                    merged.push_back(nums[a++]);
            }
            for (int i = 0; i <= end - start; i++)
                nums[start + i] = merged[i];
        }
};

int main(void) {
    Solution s;
}