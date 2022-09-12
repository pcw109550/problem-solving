#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        // O(N + M)
        vector<string> result;
        int M = list1.size(), N = list2.size(), cur = INT_MAX;
        unordered_map<string, int> Map;
        for (int i = 0; i < M; i++)
            Map[list1[i]] = i;
        for (int i = 0; i < N; i++)
            if (Map.count(list2[i])) {
                int sum = i + Map[list2[i]];
                if (cur > sum) {
                    cur = sum;
                    result.clear();
                    result.push_back(list2[i]);
                } else if (cur == sum)
                    result.push_back(list2[i]);
            }
        return result;
    }
};