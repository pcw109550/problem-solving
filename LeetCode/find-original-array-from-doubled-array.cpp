// 2007. Find Original Array From Doubled Array
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // O(N * log(N))
        int N = changed.size();
        if (N % 2)
            return vector<int>();
        multiset<int> S;
        for (int i = 0; i < N; i++)
            S.insert(changed[i]);
        vector<int> result;
        while (true) {
            if (S.empty())
                break;
            auto it = S.begin();
            int cur = *it;
            S.erase(it);
            auto it2 = S.find(cur * 2);
            if (it2 == S.end())
                return vector<int> ();
            S.erase(it2);
            result.push_back(cur);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
