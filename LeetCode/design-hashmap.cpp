// 706. Design HashMap
#include <algorithm>
#include <iostream>
#define MAX 1000000

class MyHashMap {
    int Map[MAX + 1];
    public:
        /** Initialize your data structure here. */
        MyHashMap() {
            std::fill(Map, Map + MAX + 1, -1);
        }

        /** value will always be non-negative. */
        void put(int key, int value) {
            Map[key] = value;
        }

        /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
        int get(int key) {
            return Map[key];
        }

        /** Removes the mapping of the specified value key if this map contains a mapping for the key */
        void remove(int key) {
            Map[key] = -1;
        }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(void) {
}