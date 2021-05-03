// 970. Powerful Integers
#include <iostream>
#include <vector>
#include <set>


class Solution {
    public:
        std::vector<int> powerfulIntegers(int x, int y, int bound) {
            // O(N * log(N))
            std::vector<int> result;
            std::set<int> a, b;
            int s = 1;
            do {
                a.insert(s);
                s *= x;
            } while (x != 1 && s <= bound);
            s = 1;
            do {
                b.insert(s);
                s *= y;
            } while (y != 1 && s <= bound);
            for (int i = 0; i <= bound; i++) {
                for (auto it : a) {
                    if (b.count(i - it)) {
                        result.push_back(i);
                        break;
                    }
                    if (i - it <= 0)
                        break;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}