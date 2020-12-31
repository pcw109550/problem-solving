// 605. Can Place Flowers

#include <iostream>
#include <vector>

class Solution {
    public:
        bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
            // O(N)
            int amount = 0;
            int length = 0;
            for (int i = 0; i < flowerbed.size(); i++) {
                if (flowerbed[i] == 0)
                    length++;
                else {
                    if (length != 0)
                        amount += length / 2;
                    length = 0;
                    i++;
                }
            }
            if (length > 0)
                amount += (length + 1) / 2;
            return amount >= n;
        }
};

int main(void) {
    Solution s;
}