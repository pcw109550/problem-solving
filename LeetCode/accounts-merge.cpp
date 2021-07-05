// 721. Accounts Merge
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
    vector<pair<int, int> > mySet; // {rank, parent}
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            // O(M * N * log(M * N))
            mySet = vector<pair<int, int> > (10000, {0, -1});
            int cnt = 0, prev_end = 0;
            unordered_map<int, string> M1;
            unordered_map<string, int> M2;
            unordered_map<int, string> names;
            unordered_map<int, vector<int> > M;
            vector<vector<string> > result;
            for (int i = 0; i < accounts.size(); i++) {
                auto name = accounts[i][0];
                for (int j = 1; j < accounts[i].size(); j++) {
                    M1[cnt] = accounts[i][j];
                    if (M2.count(accounts[i][j])) {
                        Union(M2[accounts[i][j]], cnt);
                    } else
                        M2[accounts[i][j]] = cnt;
                    names[cnt] = name;
                    if (cnt - 1 >= prev_end)
                        Union(cnt - 1, cnt);
                    cnt++;
                }
                prev_end = cnt;
            }
            for (int i = 0; i < cnt; i++)
                M[Find(i)].push_back(i);
            
            for (auto it : M) {
                vector<string> temp;
                vector<string> email;
                unordered_set<string> S;
                temp.push_back(names[it.first]);
                for (auto i : it.second) {
                    if (!S.count(M1[i])) {
                        email.push_back(M1[i]);
                        S.insert(M1[i]);
                    }
                }
                sort(email.begin(), email.end());
                temp.insert(temp.end(), email.begin(), email.end());
                result.push_back(temp);
            }
            return result;
        }
    
        int Find(int x) {
            if (mySet[x].second < 0)
                return x;
            return mySet[x].second = Find(mySet[x].second);
        }
    
        bool Union(int x, int y) {
            int X = Find(x);
            int Y = Find(y);
            if (X == Y)
                return true;
            if (mySet[X].first < mySet[Y].first)
                swap(X, Y);
            mySet[Y].second = X;
            if (mySet[X].first == mySet[Y].first)
                mySet[X].first++;
            return false;
        }
};

int main(void) {
    Solution s;
}