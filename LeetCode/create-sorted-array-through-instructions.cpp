// 1649. Create Sorted Array through Instructions
#include <algorithm>
#include <iostream>
#include <vector>
#define FIELD 1000000007
#define MAX 100000

class Solution {
    // SegmentTree
    int N, h, tree_size;
    std::vector<int> tree; 
    public:
        int createSortedArray(std::vector<int>& instructions) {
            // O(N log(N))
            int result = 0;
            init();
            for (auto instr : instructions) {
                int l = sumRange(0, instr - 1);
                int r = sumRange(instr + 1, MAX);
                result = (result + std::min(l, r)) % FIELD;
                update(instr);
            }
            return result;
        }
    
        void init(void) {
            N = MAX + 1;
            h = static_cast<int>(std::ceil(std::log2(N)));
            tree_size = 1 << (h + 1);
            tree.resize(tree_size, 0);
        }
        
        inline void update(int i) {
            // O(log(N))
            i += N;
            tree[i]++;
            while (i >>= 1)
                tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
        
        inline int sumRange(int i, int j) {
            // O(log(N))
            int result = 0;
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
    Solution s;
}