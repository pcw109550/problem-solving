#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // O(N)
        int N = arr.size();
        list<int> L(arr.begin(), arr.end());
        int cnt = 0, prev = -1;
        int Max = *max_element(arr.begin(), arr.end());
        while (true) {
            int a = *L.begin();
            int b = *next(L.begin(), 1);
            if (a == Max)
                return a;
            if (a < b) {
                cnt = (prev == b ? cnt + 1 : 1);
                prev = b;
                if (cnt == k)
                    return b;
                L.erase(L.begin());
                L.push_back(a);
            } else if (a > b) {
                cnt = (prev == a ? cnt + 1 : 1);
                prev = a;
                if (cnt == k)
                    return a;
                L.erase(next(L.begin(), 1));
                L.push_back(b);
            }
        }
        return -1;
    }
};