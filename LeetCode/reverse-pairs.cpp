#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <climits>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // O(N * log(N))
        // kinda mergesort yeah
        int result = 0;
        pad(nums);
        int N = nums.size();
        vector<pair<long long, int> > D;
        for (auto it : nums)
            D.push_back({it, 0});
        conq(D, 0, N - 1);
        for (auto it : D)
            result += it.second;
        return result;
    }
    
    void conq(vector<pair<long long, int> > &D, int start, int end) {
        if (start >= end)
            return;
        int mid = (start + end) / 2;
        conq(D, start, mid);
        conq(D, mid + 1, end);
        vector<pair<long long, int> > merge;
        int p1 = start, p2 = mid + 1, p = start;
        for (int i = start; i <= end; i++) {
            if (p1 == mid + 1) {
                int delta = 0;
                while (p <= mid) {
                    if (D[p].first > 2 * D[p2].first) {
                        delta += mid - p + 1;
                        break;
                    }
                    p++;
                }
                merge.push_back({D[p2].first, D[p2].second + delta});
                p2++;
            } else if (p2 == end + 1)
                merge.push_back(D[p1++]);
            else {
                if (D[p1].first >= D[p2].first) {
                    int delta = 0;
                    while (p <= mid) {
                        if (D[p].first > 2 * D[p2].first) {
                            delta += mid - p + 1;
                            break;
                        }                    
                        p++;
                    }
                    merge.push_back({D[p2].first, D[p2].second + delta});
                    p2++;
                } else
                    merge.push_back(D[p1++]);
            }
        }
        for (int i = start; i <= end; i++) {
            D[i].first = merge[i - start].first;
            D[i].second = merge[i - start].second;
        }
    }
    
    void pad(vector<int> &nums) {
        int N = nums.size();
        int cnt = 0;
        while (N > 0) {
            N >>= 1;
            cnt++;
        }
        N = nums.size();
        if (nums.size() != (1 << (cnt - 1)))
            for (int i = 0; i < (1 << cnt) - N; i++) {
                nums.push_back(INT_MAX);
            }
    }
};