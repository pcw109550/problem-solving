#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // O(N)
        int N = arr.size();
        string result;
        unordered_set<string> S;
        unordered_set<string> everything;
        for (int i = 0; i < N; i++) {
            if (everything.count(arr[i])) {
                S.erase(arr[i]);
            } else {
                everything.insert(arr[i]);
                S.insert(arr[i]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (S.count(arr[i])) {
                cnt++;
                if (cnt == k) {
                    result = arr[i];
                    break;
                }
            }
        return result;
    }
};