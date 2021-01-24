// 241. Different Ways to Add Parentheses
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::vector<int> diffWaysToCompute(std::string input) {
            // O(Catalan)
            std::vector<int> nums;
            std::vector<char> op;
            int start = 0;
            for (int i = 0; i < input.size(); i++) {
                if ('0' <= input[i] && input[i] <= '9')
                    continue;
                op.push_back(input[i]);
                nums.push_back(std::stoi(input.substr(start, i - start)));
                start = i + 1;
            }
            nums.push_back(std::stoi(input.substr(start, input.size() - start)));
            int N = nums.size();
            std::vector<std::vector<std::vector<int> > > D (N, std::vector<std::vector<int> > (N,
                                std::vector<int> () ));
            for (int i = 0; i < N; i++)
                D[i][i].push_back(nums[i]);
            for (int i = 1; i < N; i++) {
                for (int j = 0; j < N - i; j++) {
                    int x = j, y = i + j;
                    for (int z = x; z < y; z++) {
                        auto temp = calc(D[x][z], D[z + 1][y], op[z]);
                        D[x][y].insert(D[x][y].begin(), temp.begin(), temp.end());
                    }
                }
            }
            return D[0][N - 1];
        }
    
        inline std::vector<int> calc(std::vector<int> &a, std::vector<int> &b, char op) {
            std::vector<int> temp;
            if (op == '+') {
                for (auto e1 : a)
                    for (auto e2 : b)
                        temp.push_back(e1 + e2);
            } else if (op == '-') {
                for (auto e1 : a)
                    for (auto e2 : b)
                        temp.push_back(e1 - e2);
            } else if (op == '*') {
                for (auto e1 : a)
                    for (auto e2 : b)
                        temp.push_back(e1 * e2);
            }
            return temp;
        }
};

int main(void) {
    Solution s;
}