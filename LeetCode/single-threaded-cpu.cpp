#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // O(N * log(N))
        vector<int> result;
        int N = tasks.size();
        for (int i = 0; i < N; i++)
            tasks[i].push_back(i); // {enqueueTime, processingTime, idx}
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > PQ;  // {processingTime, idx, enqueueTime}
        long long cur_time = 0, probe = 0;
        while (probe < N) {
            PQ.push({tasks[probe][1], tasks[probe][2], tasks[probe][0]});
            probe++;
            while (!PQ.empty()) {
                auto cur = PQ.top(); PQ.pop();
                long long pt = cur[0], et = cur[2], idx = cur[1];
                result.push_back(idx);
                cur_time = max(cur_time, et) + pt;
                while (probe < N) {
                    if (tasks[probe][0] <= cur_time) {
                        PQ.push({tasks[probe][1], tasks[probe][2], tasks[probe][0]});
                        probe++;
                    } else
                        break;
                }
            }
        }
        return result;
    }
};