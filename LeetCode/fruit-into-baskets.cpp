// 904. Fruit Into Baskets
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // O(N)
        int N = fruits.size();
        int result = 1;
        unordered_set<int> S;
        unordered_map<int, int> M;
        int p1 = 0, p2 = 0;
        while (p1 < N && p2 < N) {
            if (S.count(fruits[p2])) {
                result = max(result, p2 - p1 + 1);
                M[fruits[p2]] = p2;
                p2++;
            } else {
                if (S.size() < 2) {
                    result = max(result, p2 - p1 + 1);
                    S.insert(fruits[p2]);
                    M[fruits[p2]] = p2;
                    p2++;
                } else if (S.size() == 2) {
                    vector<int> temp;
                    for (auto it : S)
                        temp.push_back(it);
                    int a = temp[0], b = temp[1];
                    p1 = min(M[a], M[b]) + 1;
                    S.erase(M[a] < M[b] ? a : b);
                    result = max(result, p2 - p1 + 1);
                    M[fruits[p2]] = p2;
                    S.insert(fruits[p2]);
                    p2++;
                } 
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
