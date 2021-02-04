// 990. Satisfiability of Equality Equations
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Solution {
    // Union Find: {rank, parent}
    std::vector<std::pair<int, int> > mySet;
    public:
        bool equationsPossible(std::vector<std::string>& equations) {
            // O(N)
            mySet = std::vector<std::pair<int, int> > (26, {0, -1});
            for (auto equation : equations) {
                int x = equation[0] - 'a', y = equation[3] - 'a';
                bool is_equal = equation[1] == '=';
                if (is_equal)
                    Union(x, y);
            }
            for (auto equation : equations) {
                int x = equation[0] - 'a', y = equation[3] - 'a';
                bool is_equal = equation[1] == '=';
                if (!is_equal && (Find(x) == Find(y)))
                    return false;
            }
            return true;
        }
    
        int Find(int x) {
            if (mySet[x].second < 0) { return x; }
            // Path compression
            return mySet[x].second = Find(mySet[x].second);
        }

        bool Union(int x, int y) {
            // O(invack(N))
            int X = Find(x);
            int Y = Find(y);
            if (X == Y) { return true; }
            if (mySet[X].first < mySet[Y].first) {
                std::swap(X, Y);
            }
            mySet[Y].second = X;
            if (mySet[X].first == mySet[Y].first) {
                mySet[X].first++;
            }
            return false;
        }      
};

int main(void) {
    Solution s;
}