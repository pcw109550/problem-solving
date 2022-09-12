#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<vector<NestedInteger> > state;
    vector<int> idxs;
    int peek;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        auto it = nestedList[0];
        idxs.push_back(0);
        state.push_back(nestedList);
        while (!it.isInteger()) {
            state.push_back(it.getList());
            if (it.getList().empty()) {
                idxs.push_back(-1);
                break;
            } else {
                auto it2 = it.getList()[0];
                it = it2;
                idxs.push_back(0);
            }
        }
    }
    
    int next() {
        // O(1)
        return peek;
    }
    
    int _next() {
        // O(H)
        if (state.empty())
            return INT_MIN;
        auto b = state.back();
        int n = b.size();
        int idx = idxs.back();
        int res = INT_MAX;
        bool jump = false;
        if (idx == -1) {
            jump = true;
        } else { 
            res = b[idx].getInteger();
            idx++;
        }
        if (n == idx || jump) {
            while (true) {
                idxs.pop_back();
                state.pop_back();
                if (state.empty())
                    break;
                int n = state.back().size();
                int idx = idxs.back();
                if (n == idx + 1) {
                    continue;
                } else {
                    idxs[idxs.size() - 1]++;
                    idx++;
                    auto it = state.back()[idx];
                    while (!it.isInteger()) {
                        state.push_back(it.getList());
                        if (it.getList().empty()) {
                            idxs.push_back(-1);
                            break;
                        } else {
                            auto it2 = it.getList()[0];
                            it = it2;
                            idxs.push_back(0);
                        }
                    }
                    break;
                }
            }
        } else {
            auto it = b[idx];
            idxs[idxs.size() - 1]++;
            while (!it.isInteger()) {
                state.push_back(it.getList());
                if (it.getList().empty()) {
                    idxs.push_back(-1);
                    break;
                } else {
                    auto it2 = it.getList()[0];
                    it = it2;
                    idxs.push_back(0);
                }
            }
            
        }
        return res;
    }
    
    bool hasNext() {
        // O(H)
        int res = INT_MAX;
        while (true) {
            int temp = _next();
            if (temp != INT_MAX) {
                res = temp;
                break;
            }
        }
        peek = res;
        return res != INT_MIN;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */