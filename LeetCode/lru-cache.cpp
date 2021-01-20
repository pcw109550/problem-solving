// 146. LRU Cache
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

class LRUCache {
    int size;
    std::list<int> lru;                              // MRU ... LRU
    std::unordered_map<int, std::list<int>::iterator> mp; // key -> iterator
    std::unordered_map<int, int> kv;                 // key -> value

    public:
        LRUCache(int capacity) : size(capacity) {}

        int get(int key) {
            // O(1)
            if (kv.find(key) == kv.end())
                return -1;
            updateLRU(key);
            return kv[key];
        }

        void put(int key, int value) {
            // O(1)
            if (kv.size() == size && kv.find(key) == kv.end())
                evict();
            updateLRU(key);
            kv[key] = value;
        }

        void updateLRU(int key) {
            // O(1)
            if (kv.find(key) != kv.end()) 
                lru.erase(mp[key]);
            lru.push_front(key);
            mp[key] = lru.begin();
        }

        void evict() {
            // O(1)
            mp.erase(lru.back());
            kv.erase(lru.back());
            lru.pop_back();
        }
};

int main(void) {
    LRUCache* obj = new LRUCache(1);
}