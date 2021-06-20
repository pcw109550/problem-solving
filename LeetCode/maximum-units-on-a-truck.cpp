// 1710. Maximum Units on a Truck
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

class Solution {
    public:
        int maximumUnits(std::vector<std::vector<int> >& boxTypes, int truckSize) {
            // O(N * log(N))
            int result = 0;
            std::vector<std::pair<int, int> > temp;
            int N = boxTypes.size();
            for (int i = 0; i < N; i++) {
                int numAvail = boxTypes[i][0];
                int units = boxTypes[i][1];
                temp.push_back({units, numAvail});
            }
            std::sort(temp.begin(), temp.end());
            int leftSize = truckSize;
            for (int i = N - 1; i >= 0; i--) {
                if (truckSize > 0) {
                    int numAvail = temp[i].second;
                    int units = temp[i].first;
                    int num = std::min(truckSize, numAvail);
                    result += num * units;
                    truckSize -= num;
                } else
                    break;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}