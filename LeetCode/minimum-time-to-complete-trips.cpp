#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // O(N * log(M))
        long long result = 0;
        long long Max = *max_element(time.begin(), time.end()); 
        long long lo = 0, hi = Max * (long long)totalTrips;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long cnt = eval(time, mid);
            if (cnt < (long long)totalTrips)
                lo = mid + 1;
            else
                hi = mid;
        }
        result = hi;
        return result;
    }
    
    long long eval(vector<int>& time, long long target) {
        long long res = 0;
        for (int i = 0; i < time.size(); i++)
            res += target / (long long)time[i];
        return res;
    } 
    
    
};