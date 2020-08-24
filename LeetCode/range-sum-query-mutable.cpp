// 307. Range Sum Query - Mutable
#include <iostream>
#include <cmath>
#include <vector>

class NumArray {
    // SegmentTree
    int N, h, tree_size;
    std::vector<long> tree;    
    public:
        NumArray(std::vector<int>& nums) {
            // O(N)
            N = nums.size();
            if (N == 0)
                return;
            h = static_cast<int>(std::ceil(std::log2(N)));
            tree_size = 1 << (h + 1);
            tree.resize(tree_size, 0);
            for (int i = 0; i < N; i++)
                tree[N + i] = nums[i];
            for (int i = N - 1; i >= 1; i--)
                tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
        
        void update(int i, int val) {
            // O(log(N))
            i += N;
            tree[i] = val;
            while (i >>= 1)
                tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
        
        int sumRange(int i, int j) {
            // O(log(N))
            long long result = 0;
            i += N; j += N;
            while (i <= j) {
                if (i & 1)
                    result += tree[i++];
                if (!(j & 1))
                    result += tree[j--];
                i /= 2; j /= 2;
            }
            return result;
        }
};

int main(void) {
    std::vector<int> nums {1, 2, 3, 4, 5};
    NumArray* obj = new NumArray(nums);
    obj->update(2, 7);
    int result = obj->sumRange(0, 4);
    std::cout << result;
}

