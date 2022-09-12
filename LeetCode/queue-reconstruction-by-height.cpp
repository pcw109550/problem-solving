#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // O(N ** 2)
        vector<vector<int> > result;
        int N = people.size();
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);
        });
        list<vector<int> > L;
        for (auto it : people) {
            int idx = it[1];
            auto iter = L.begin();
            advance(iter, idx);
            L.insert(iter, it);
        }
        for (auto it : L)
            result.push_back(it);
        return result;
    }
};