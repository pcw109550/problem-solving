#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // O(N)
        unordered_map<int, unordered_set<int> > M;
        int result = 2 * n;
        for (auto it : reservedSeats)
            M[it[0]].insert(it[1]);
        for (auto it : M) {
            int i = it.first;
            bool l = M[i].count(2) || M[i].count(3) || M[i].count(4) || M[i].count(5);
            bool r = M[i].count(6) || M[i].count(7) || M[i].count(8) || M[i].count(9);
            bool m = M[i].count(4) || M[i].count(5) || M[i].count(6) || M[i].count(7);
            if (l)
                result--;
            if (r)
                result--;
            if (l && r)
                if (!m)
                    result++;
        }
        return result;
    }
};