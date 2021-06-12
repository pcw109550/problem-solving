// 752. Open the Lock
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <utility>

class Solution {
    public:
        int openLock(std::vector<std::string>& deadends, std::string target) {
            // O(N)
            std::unordered_set<std::string> S;
            for (auto deadend: deadends)
                S.insert(deadend);
            if (S.count("0000"))
                return -1;
            std::unordered_set<std::string> visited;
            std::queue<std::pair<std::string, int> > Q;
            Q.push({"0000", 0});
            visited.insert("0000");
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                if (cur.first == target)
                    return cur.second;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; j++) {
                        auto temp = cur.first;
                        temp[i] = '0' + (temp[i] - '0' + 2 * j - 1 + 10) % 10;
                        if (visited.count(temp) || S.count(temp))
                            continue;
                        visited.insert(temp);
                        Q.push({temp, cur.second + 1});
                    }
                }
            }
            return -1;
        }
};

int main(void) {
    Solution s;
}