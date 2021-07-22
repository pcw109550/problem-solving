// 1338. Reduce Array Size to The Half
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
    public:
        int minSetSize(vector<int>& arr) {
            // O(N * log(N))
            int result = 0;
            int N = arr.size();
            unordered_map<int, int> M;
            for (auto i : arr)
                M[i]++;
            vector<pair<int, int> > temp;
            for (auto it : M)
                temp.push_back({it.second, it.first});
            sort(temp.begin(), temp.end());
            int acc = 0;
            for (int i = temp.size() - 1; i >= 0; i--) {
                acc += temp[i].first;
                result++;
                if (acc >= N / 2)
                    break;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}