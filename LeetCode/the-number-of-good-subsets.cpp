#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define FIELD 1000000007

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        // O(N + 18 * 2 ** 18)
        int N = nums.size();
        long long result = 0;
        vector<int> primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        // At most three factors: 18 out of 30
        vector<int> enc;
        vector<int> M;
        vector<int> cnts(31, 0);
        unordered_set<int> S;
        for (int num = 2; num <= 30; num++) {
            int cur = 0;
            bool square_free = true;
            for (int j = 0; j < 10; j++) {
                int p = primes[j];
                if (num % p == 0) {
                    if (num % (p * p) == 0) {
                        square_free = false;
                        break;
                    }
                    cur |= (1 << j);
                }
            }
            if (square_free) {
                enc.push_back(cur);
                M.push_back(num);
                S.insert(num);
            }
        }
        int one_effect = 1;
        for (auto num : nums) {
            if (S.count(num))
                cnts[num]++;
            else if (num == 1)
                one_effect = (2 * one_effect) % FIELD;
        }
        for (int i = 1; i < 1 << enc.size(); i++) {
            int cur = i;
            int state = 0;
            bool err = false;
            long long _result = 1;
            int j = 0;
            while (cur > 0) {
                if (cur & 1) {
                    if ((state + enc[j]) != (state | enc[j])) {
                        err = true;
                        break;
                    }
                    state |= enc[j];
                    _result = _result * cnts[M[j]] % FIELD;
                    if (_result == 0)
                        break;
                }
                cur >>= 1;
                j++;
            }
            if (!err)
                result = (result + _result) % FIELD;
        }
        result = (result * one_effect) % FIELD;
        return result;
    }
};