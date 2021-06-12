// 1383. Maximum Performance of a Team
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#define FIELD 1000000007

class Solution {
    public:
        int maxPerformance(int n, std::vector<int>& speed, std::vector<int>& efficiency, int k) {
            // O(N * log(N))
            long long result = 0;
            std::vector<std::pair<int, int> > P;
            std::multiset<int> S;
            for (int i = 0; i < n; i++) {
                P.push_back({efficiency[i], speed[i]});
                S.insert(speed[i]);
            }
            std::sort(P.begin(), P.end());
            long long acc = 0;
            std::multiset<int> hi, lo;
            std::unordered_multiset<int> hi2;
            for (auto it = S.rbegin(); it != S.rend(); it++) {
                if (hi.size() < k) {
                    hi.insert(*it);
                    hi2.insert(*it);
                    acc += *it;
                } else
                    lo.insert(*it);
            }
            for (int i = 0; i < n; i++) {
                long long e = P[i].first;
                long long s = P[i].second;
                result = std::max(result, e * acc);
                if (hi2.find(s) != hi2.end()) {
                    acc -= s;
                    if (!hi.empty()) {
                        auto it1 = hi.find(s);
                        hi.erase(it1);
                        auto it2 = hi2.find(s);
                        hi2.erase(it2);
                    }
                    if (!lo.empty()) {
                        int add = *lo.rbegin();
                        auto it3 = lo.find(add);
                        lo.erase(it3);
                        acc += add;
                        hi.insert(add);
                        hi2.insert(add);
                    }
                } else {
                    if (!lo.empty()) {
                        auto it1 = lo.find(s);
                        lo.erase(it1);
                    }
                }
            }
            result %= FIELD;
            return result;
        }
};

int main(void) {
    Solution s;
}