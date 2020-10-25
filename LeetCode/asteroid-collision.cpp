// 735. Asteroid Collision
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
            // O(N)
            std::vector<int> result;
            for (auto it : asteroids) {
                if (result.empty())
                    result.emplace_back(it);
                else {
                    auto back = result.back();
                    if (!(back > 0 && it < 0)) {
                        result.emplace_back(it);
                        continue;
                    }
                    while (back > 0 && it < 0) {
                        if (back + it > 0)
                            break;
                        else if (back + it < 0)
                            result.pop_back();
                        else if (back + it == 0) {
                            result.pop_back();
                            break;
                        }
                        if (result.empty()) {
                            result.emplace_back(it);
                            break;
                        }
                        back = result.back();
                    }
                    if (back < 0 && it < 0)
                        result.emplace_back(it);
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> asteroids {1,2,3,4,5,-6};
    auto result = s.asteroidCollision(asteroids);
    for (auto &it : result)
        std::cout << it << ' ';
}