// 398. Random Pick Index
#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
using namespace std;

class Solution {
    unordered_map<int, vector<int> > M;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> distrib;
public:
    Solution(vector<int>& nums) {
        // O(N)
        int N = nums.size();
        for (int i = 0; i < N; i++)
            M[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        // O(1)
        int K = M[target].size();
        distrib = uniform_int_distribution<>(0, K - 1);
        int idx = distrib(gen);
        return M[target][idx];
    }
};

int main(void) {
    Solution* obj;
}
