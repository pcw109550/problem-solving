// 621. Task Scheduler
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
    public:
        int leastInterval(std::vector<char>& tasks, int n) {
            // O(N)
            std::unordered_map<char,int> mp;
            int count = 0;
            for (auto e : tasks) {
                mp[e]++;
                count = std::max(count, mp[e]);
            }
            int ans = (count - 1) * (n + 1);
            for (auto e : mp)
                if(e.second == count)
                    ans++;
            return std::max((int)tasks.size(), ans);
        }
};

class Solution2 {
    std::unordered_set<char> window;
    std::unordered_map<char, int> occ;
    std::vector<char> store;
    public:
        int leastInterval(std::vector<char>& tasks, int n) {
            if (n == 0)
                return tasks.size();
            int result = 0, exhausted = 0;
            for (auto it : tasks)
                occ[it]++;
            while (exhausted < tasks.size()) {
                auto cand = next();
                if (cand != '\0') {
                    exhausted++;
                    occ[cand]--;
                    if (occ[cand] == 0)
                        occ.erase(cand);
                    window.insert(cand);
                }
                if (result - n >= 0)
                    window.erase(store[result - n]);
                store.push_back(cand);
                result++;
            }
            return result;
        }
    
        char next() {
            char result = '\0';
            int Max = -1;
            for (auto it : occ) {
                auto key = it.first;
                auto num = it.second;
                if (window.count(key))
                    continue;
                if (Max < num) {
                    Max = num;
                    result = key;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}