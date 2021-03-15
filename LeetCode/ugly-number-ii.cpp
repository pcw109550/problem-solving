// 264. Ugly Number II
#include <algorithm>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class Solution {
    public:
        int nthUglyNumber(int n) {
            // O(N)
            std::vector<int> temp(n, 0);
            int p2 = 0, p3 = 0, p5 = 0;
            temp[0] = 1;
            for (int i = 1; i < n; i++) {
                temp[i] = std::min(2 * temp[p2], std::min(3 * temp[p3], 5 * temp[p5]));
                if (temp[i] == 2 * temp[p2])
                    p2++;
                if (temp[i] == 3 * temp[p3])
                    p3++;
                if (temp[i] == 5 * temp[p5])
                    p5++;
            }
            return temp.back();
        }
};

class Solution2 {
    public:
        int nthUglyNumber(int n) {
            // O(N ** 2)
            std::vector<long long> temp;
            std::vector<long long> cand {2, 3, 5};
            temp.push_back(1);
            int start = 0;
            while (temp.size() < n) {
                long long back = temp.back();
                long long next = INT_MAX;
                for (int i = start; i < temp.size(); i++)
                    for (auto m : cand)
                        if (temp[i] * m > back && next > temp[i] * m)
                            next = m * temp[i];
                temp.push_back(next);
            }
            return temp.back();
        }
};

int main(void) {
    Solution s;
}