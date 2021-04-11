// 622. Design Circular Queue
#include <iostream>
#include <vector>

class MyCircularQueue {
    std::vector<int> Q;
    int size, start, end, cnt;
    // O(1)
    public:
        MyCircularQueue(int k): size(k){
            Q = std::vector<int> (k, -1);
            start = end = cnt = 0;
        }

        bool enQueue(int value) {
            if (cnt == size)
                return false;
            Q[start] = value;
            start = (start + 1) % size;
            cnt++;
            return true;
        }

        bool deQueue() {
            if (cnt == 0)
                return false;
            Q[end] = -1;
            end = (end + 1) % size;
            cnt--;
            return true;
        }

        int Front() {
            return cnt == 0 ? -1 : Q[end];
        }

        int Rear() {
            int pos = (size + start - 1) % size;
            return cnt == 0 ? -1 : Q[pos];
        }

        bool isEmpty() {
            return cnt == 0;
        }

        bool isFull() {
            return cnt == size;
        }
};

int main(void) {
    int k = 5, value = 3;
    MyCircularQueue* obj = new MyCircularQueue(k);
    bool param_1 = obj->enQueue(value);
    bool param_2 = obj->deQueue();
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
}