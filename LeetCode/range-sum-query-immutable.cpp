// 303. Range Sum Query - Immutable
#include <iostream>
#include <vector>

class NumArray {
    public:
        std::vector<int> D;
        NumArray(std::vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            std::cout.tie(NULL);
            // O(N)
            D.emplace_back(0);
            for (int i = 0; i < nums.size(); i++) {
                D.emplace_back(D.back() + nums[i]);
            }
        }
        
        int sumRange(int i, int j) {
            // O(1)
            return D[j + 1] - D[i];    
        }
};

int main(void) {
    std::vector<int> nums {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    int param_1 = obj->sumRange(0, 2);
    std::cout << param_1 << std::endl;
    int param_2 = obj->sumRange(2, 5);
    std::cout << param_2 << std::endl;
    int param_3 = obj->sumRange(0, 5);
    std::cout << param_3 << std::endl;
}