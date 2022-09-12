#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> S;
    int size, _peek;
public:
    MyQueue() {
        size = 0;
    }
    
    void push(int x) {
        // O(1)
        S.push(x);
        size++;
        if (size == 1)
            _peek = x;
    }
    
    int pop() {
        // O(N)
        stack<int> temp;
        for (int i = 0; i < size - 1; i++) {
            int cur = S.top(); S.pop();
            temp.push(cur);
        }
        if (!temp.empty())
            _peek = temp.top();
        int res = S.top(); S.pop();
        size--;
        S = stack<int>();
        while (!temp.empty()) {
            S.push(temp.top());
            temp.pop();
        }
        return res;
    }
    
    int peek() {
        // O(1)
        return _peek;
    }
    
    bool empty() {
        // O(1)
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */