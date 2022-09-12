#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // O(max(A, K) * log(A))
        vector<vector<int> > result;
        int A = nums1.size(), B = nums2.size();
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > PQ;
        for (int i = 0; i < A; i++)
            PQ.push(vector<int> {nums1[i] + nums2[0], i, 0});
        while (result.size() < k && !PQ.empty()) {
            auto cur = PQ.top(); PQ.pop();
            result.push_back(vector<int> {nums1[cur[1]], nums2[cur[2]]});
            if (cur[2] + 1 < B) 
                PQ.push({nums1[cur[1]] + nums2[cur[2] + 1], cur[1], cur[2] + 1});    
        }
        return result;
    }
};