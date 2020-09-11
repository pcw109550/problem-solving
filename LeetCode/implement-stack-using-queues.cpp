// 225. Implement Stack using Queues
#include <cassert>
#include <iostream>
#include <queue>

class MyStack {
    public:
        std::queue<int> Q;
        /** Initialize your data structure here. */
        MyStack() {
        }
        
        /** Push element x onto stack. */
        void push(int x) {
            // O(N)
            Q.push(x);
            for (int i = 0; i < Q.size() - 1; i++)
                Q.push(pop());
        }
        
        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            // O(1)
            int result = Q.front();
            Q.pop();
            return result;
        }
        
        /** Get the top element. */
        int top() {
            // O(1)
            return Q.front();
        }
        
        /** Returns whether the stack is empty. */
        bool empty() {
            // O(1)
            return Q.empty();
        }
};

int main(void) {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    std::cout << obj->top() << std::endl;
    std::cout << obj->pop() << std::endl;
    std::cout << obj->pop() << std::endl;
    std::cout << obj->empty() << std::endl;
    std::cout << obj->top() << std::endl;
    std::cout << obj->pop() << std::endl;
    std::cout << obj->empty() << std::endl;
}