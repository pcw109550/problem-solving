// 480. Sliding Window Median
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    int N;
    vector<double> result;
    multiset<int> S;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // O(N * log(K))
        N = nums.size();
        if (k % 2)
            medianSlidingWindowOdd(nums, k);
        else
            medianSlidingWindowEven(nums, k);
        return result;
    }
    
    void medianSlidingWindowOdd(vector<int>& nums, int k) {
        if (k == 1) {
            for (auto num: nums)
                result.push_back(num);
            return;
        }
        for (int i = 0; i < k; i++)
            S.insert(nums[i]);
        auto it = S.begin();
        for (int i = 0; i < k / 2; i++)
            it++;
        result.push_back(*it);
        for (int i = k; i < N; i++) {
            // erase
            auto e_probe = S.find(nums[i - k]);
            if (nums[i - k] >= *it) {
                if (e_probe == it)
                    it++;
                S.erase(e_probe);
                it--;
            } else
                S.erase(e_probe);
            // insert
            S.insert(nums[i]);
            if (*it <= nums[i])
                it++;
            // report
            result.push_back(*it);
        }
    }
    
    double avg(multiset<int>::iterator it) {
        double sum = *it++;
        sum += *it;
        return sum / 2;
    }
    
    void medianSlidingWindowEven(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)
            S.insert(nums[i]);
        auto it = S.begin();
        for (int i = 0; i < k / 2 - 1; i++)
            it++;
        result.push_back(avg(it));
        for (int i = k; i < N; i++) {
            // erase
            auto e_probe = S.find(nums[i - k]);
            if (nums[i - k] < *it) {
                S.erase(e_probe);
                it++;
            } else {
                if (*e_probe == *it)
                    it++;
                S.erase(e_probe);
            }
            // insert
            S.insert(nums[i]);
            if (*it > nums[i])
                it--;
            // report
            result.push_back(avg(it));
        }
    }
};

int main(void) {
    Solution s;
}