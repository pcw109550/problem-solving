// 1029. Two City Scheduling
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>&a, const vector<int>&b){
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        
        int price = 0;
        for(int i = 0; i < costs.size() / 2; i++){
            price += costs[i][0];
        }
        for(int i = costs.size() / 2; i < costs.size(); i++){
            price += costs[i][1];
        }
        return price;
    }
};

int main(void) {
    Solution s;
}
