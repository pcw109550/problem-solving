// 902. Numbers At Most N Given Digit Set
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // O(log(N))
        long long result = 0;
        long long N = n;
        vector<int> T(10);
        int probe = 0;
        long long K = digits.size();
        unordered_set<int> S;
        for (auto digit : digits)
            S.insert(digit[0] - '0');
        for (int i = 1; i <= 9; i++) {
            T[i] = T[i - 1];
            if (probe < digits.size() && digits[probe][0] - '0' == i) {
                T[i]++;
                probe++;
            }
        }
        vector<int> d;
        while (n > 0) {
            d.push_back(n % 10);
            n /= 10;
        }
        reverse(d.begin(), d.end());
        int L = d.size();
        long long t = K, a = 10;
        vector<long long> acc;
        while (a <= N) {
            acc.push_back(t);
            result += t;
            t *= K;
            a *= 10;
        }
        reverse(acc.begin(), acc.end());
        acc.push_back(1);
        probe = 0;
        while (probe < d.size()) {
            int cnt = T[d[probe]];
            if (S.count(d[probe])) {
                result += acc[probe] * (cnt - 1);
                if (probe == d.size() - 1)
                    result += acc[probe];
                probe++;
            } else {
                result += acc[probe] * cnt;
                break;
            }
        }
        return static_cast<int>(result);
    }
};

int main(void) {
    Solution s;
}