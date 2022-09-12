#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        // O(log(N) * log(log(N)))
        vector<int> odds, evens;
        int n = num;
        while (num > 0) {
            int cur = num % 10;
            num /= 10;
            if (cur % 2)
                evens.push_back(cur);
            else
                odds.push_back(cur);
        }
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        auto e = evens.begin();
        auto o = odds.begin();
        int result = 0;
        long long k = 1;
        while (n > 0) {
            int cur = n % 10;
            n /= 10;
            if (cur % 2)
                result += k * *e++;
            else
                result += k * *o++;
            k *= 10;
        }     
        return result;
    }
};