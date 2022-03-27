// 406. Queue Reconstruction by Height
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // O(N ** 2)
        vector<vector<int> > result;
        int N = people.size();
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0])
                return a[0] > b[0];
            return a[1] < b[1];
        });
        for (int i = 0; i < N; i++) {
            int h = people[i][0], k = people[i][1];
            int idx = 0;
            result.insert(result.begin() + k, people[i]);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
