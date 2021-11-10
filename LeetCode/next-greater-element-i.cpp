// 496. Next Greater Element I
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // O(M + N)
        int M = nums1.size(), N = nums2.size();
        vector<int> result;
        vector<int> cache(N, -1);
        unordered_map<int, int> Map;
        stack<int> S; // idx
        for (int i = 0; i < N - 1; i++) {
            if (nums2[i] < nums2[i + 1]) {
                cache[i] = nums2[i + 1];
                while (!S.empty() && nums2[S.top()] < nums2[i + 1]) {
                    cache[S.top()] = nums2[i + 1];
                    S.pop();
                }
            } else
                S.push(i);
        }
        for (int i = 0; i < N; i++)
            Map[nums2[i]] = i;
        for (auto num : nums1)
            result.push_back(cache[Map[num]]);
        return result;
    }
};

int main(void) {
    Solution s;
}