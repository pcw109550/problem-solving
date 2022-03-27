// 1851. Minimum Interval to Include Each Query
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& A, vector<int>& queries) {
                priority_queue<vector<int>> pq;
        unordered_map<int, int> res;
        vector<int> Q = queries, res2;
        sort(A.begin(), A.end());
        sort(Q.begin(), Q.end());
        int i = 0, n = A.size();
        for (int q : Q) {
            while (i < n && A[i][0] <= q) {
                int l = A[i][0], r = A[i++][1];
                pq.push({l - r - 1, r});
            }
            while (pq.size() && pq.top()[1] < q)
                pq.pop();
            res[q] = pq.size() ? -pq.top()[0] : -1;
        }
        for (int q : queries)
            res2.push_back(res[q]);
        return res2;
    }
};

int main(void) {
    Solution s;
}
