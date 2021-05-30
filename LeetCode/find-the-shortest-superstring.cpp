// 943. Find the Shortest Superstring
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        string shortestSuperstring(vector<string>& A) {
            int n = A.size();
            // dp[mask][i] : min superstring made by strings in mask,
            // and the last one is A[i]
            vector<vector<string>> dp(1<<n,vector<string>(n));
            vector<vector<int>> overlap(n,vector<int>(n,0));
            
            // 1. calculate overlap for A[i]+A[j].substr(?)
            for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(i!=j){
                for(int k = min(A[i].size(), A[j].size()); k>0; --k)
                    if(A[i].substr(A[i].size()-k)==A[j].substr(0,k)){
                        overlap[i][j] = k; 
                        break;
                    }
            }
            // 2. set inital val for dp
            for(int i=0; i<n; ++i) dp[1<<i][i] += A[i];
            // 3. fill the dp
            for(int mask=1; mask<(1<<n); ++mask){
                for(int j=0; j<n; ++j) if((mask&(1<<j))>0){
                    for(int i=0; i<n; ++i) if(i!=j && (mask&(1<<i))>0){
                        string tmp = dp[mask^(1<<j)][i]+A[j].substr(overlap[i][j]);
                        if(dp[mask][j].empty() || tmp.size()<dp[mask][j].size())
                            dp[mask][j] = tmp;
                    }
                }
            }
            // 4. get the result
            int last = (1<<n)-1;
            string res = dp[last][0];
            for(int i=1; i<n; ++i) if(dp[last][i].size()<res.size()){
                res = dp[last][i];
            }
            return res;
        }
};

int main(void) {
    Solution s;
}