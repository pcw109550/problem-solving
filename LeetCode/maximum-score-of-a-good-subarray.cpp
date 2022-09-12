#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // O(N * log(N))
        int N = nums.size();
        int result = 0;
        vector<pair<int, int> > D;
        for (int i = 0; i < N; i++)
            D.push_back({nums[i], i});
        sort(D.begin(), D.end(), greater<pair<int, int> > ());
        vector<pair<int, int> > span(N, {-1, -1});        
        for (int i = 0; i < N; i++) {
            //cout << i << endl;
            int cur = D[i].first;
            int pos = D[i].second;
            int start = pos, end = pos;
            bool s1 = false, s2 = false;
            if (pos >= 1 && nums[pos - 1] >= cur && span[pos - 1].first != -1) {
                start = span[pos - 1].first;
                s1 = true;
            }
            if (pos + 1 < N && nums[pos + 1] >= cur && span[pos + 1].second != -1) {
                end = span[pos + 1].second;
                s2 = true;
            }
            if (s1)
                span[span[pos - 1].first].second = end;
            if (s2)
                span[span[pos + 1].second].first = start;
            span[pos] = {start, end};
            //cout << pos << ' ' << cur << " [" << start << " " << end << "]\n";
            if (start <= k && k <= end)
                result = max(result, (end - start + 1) * cur);
        }
        return result;
    }
};