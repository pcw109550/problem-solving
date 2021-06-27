// 155. Min Stack
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class MinStack {
    std::stack<int> S;
    std::vector<int> D;
    public:
        /** initialize your data structure here. */
        MinStack() {
        }

        void push(int val) {
            // O(1)
            S.push(val);
            D.push_back(D.empty() ? val : std::min(val, D.back()));
        }

        void pop() {
            // O(1)
            S.pop();
            D.pop_back();
        }

        int top() {
            // O(1)
            return S.top();
        }

        int getMin() {
            return D.back();
        }
};

int main(void) {
    MinStack* obj;
}