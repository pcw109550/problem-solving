#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // O(log(N))
        int result = 0;
        int curFilled = numBottles;
        int curNotFilled = 0;
        while (curFilled > 0) {
            result += curFilled;
            curNotFilled += curFilled;
            curFilled = curNotFilled / numExchange;
            curNotFilled %= numExchange;
        } 
        return result;
    }
};