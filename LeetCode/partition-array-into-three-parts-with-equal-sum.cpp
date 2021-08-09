// 1013. Partition Array Into Three Parts With Equal Sum
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        // O(N)
        int N = arr.size();
        int sum = 0;
        for (auto a : arr)
            sum += a;
        if (sum % 3 != 0)
            return false;
        int target = sum / 3;
        sum = 0;
        int cnt = 0;
        int len = 0;
        for (auto a : arr) {
            sum += a;
            len++;
            if (sum == target && cnt < 2) {
                cnt++;
                sum = 0;
                len = 0;
            }
        }
        return len != 0 && sum == target && cnt == 2;
    }
};

int main(void) {
    Solution s;
}