// 341. Flatten Nested List Iterator
#include <iostream>
#include <vector>
#include <stack>
#include <utility>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};

class NestedIterator {
    std::vector<int> result;
    int idx;
    public:
        NestedIterator(std::vector<NestedInteger> &nestedList) {
            // O(N)
            idx = 0;
            iterate(nestedList);
        }
        
        void iterate(std::vector<NestedInteger> &nestedList) {
            for (auto i : nestedList) {
                if (i.isInteger())
                    result.push_back(i.getInteger());
                else
                    iterate(i.getList());
            }   
        }

        int next() {
            return result[idx++];
        }

        bool hasNext() {
            return idx < result.size();
        }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(void) {
}