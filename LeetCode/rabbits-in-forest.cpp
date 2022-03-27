// 781. Rabbits in Forest
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // O(N)
        int result = 0;
        int N = answers.size();
        unordered_map<int, int> M;
        for (auto answer : answers)
            M[answer + 1]++;
        for (auto it : M)
            result += it.first * (it.second / it.first + (it.second % it.first != 0));
        return result;
    }
};

int main(void) {
    Solution s;
}
