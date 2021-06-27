// 1376. Time Needed to Inform All Employees
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class Solution {
    public:
        int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
            // O(N)
            int result = 0;
            unordered_map<int, vector<int> > M;
            for (int i = 0; i < manager.size(); i++)
                M[manager[i]].push_back(i);
            queue<pair<int, int > > Q;
            Q.push({headID, informTime[headID]});
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                result = max(result, current.second);
                if (!M.count(current.first))
                    continue;
                for (auto it : M[current.first])
                    Q.push({it, current.second + informTime[it]});
            }
            return result;
        }
};

int main(void) {
    Solution s;
}