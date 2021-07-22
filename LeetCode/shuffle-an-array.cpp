// 384. Shuffle an Array
#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <list>
using namespace std;

class Solution {
    vector<int> original;
    vector<int> state;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> distrib;
    int N;
public:
    Solution(vector<int>& nums) {
        original = nums;
        state = nums;
        N = nums.size();
        gen = mt19937(rd());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return state = original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // O(N ** 2)
        vector<int> result;
        for (int i = N - 1; i >= 0; i--) {
            distrib = uniform_int_distribution<>(0, i);
            int idx = distrib(gen);
            result.push_back(state[idx]);
            state.erase(state.begin() + idx);
        }
        state = result;
        return state;
    }
};

int main(void) {
    Solution *obj;
}
