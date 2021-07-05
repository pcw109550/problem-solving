// 460. LFU Cache
#include <list>
#include <utility>
#include <unordered_map>
using namespace std;

class LFUCache {
    int capacity;
    unordered_map<int, int> M; // frequency
    unordered_map<int, pair<list<int>, unordered_map<int, list<int>::iterator> > > L;
    unordered_map<int, int> V; // value
    
    list<int> F;
    unordered_map<int, int> T; // frequency
    unordered_map<int, list<int>::iterator> K;
    public:
        LFUCache(int c): capacity(c){
        }

        int get(int key) {
            if (V.count(key)) {
                inc_freq(key);
                return V[key];
            }
            return -1;
        }

        void put(int key, int value) {
            if (capacity == 0)
                return;
            if (V.count(key))
                _put(key, value);
            else {
                if (V.size() == capacity)
                    delete_lfu();
                _put(key, value);
            }
        }
    
        void delete_lfu() {
            int least_freq = get_least_freq();
            int val = *L[least_freq].first.begin();
            L[least_freq].second.erase(val);
            L[least_freq].first.erase(L[least_freq].first.begin());
            if (L[least_freq].second.empty())
                L.erase(least_freq);
            V.erase(val);
            M.erase(val);
            delete_freq_freq(least_freq);
        }
    
        int get_least_freq() {
            return *F.begin();
        }
    
        void _put(int key, int value) {
            V[key] = value;
            inc_freq(key);            
        }
    
        void inc_freq(int key) {
            int prev_freq = M.count(key) ? M[key] : 0;
            M[key] += 1;
            if (M[key] > 1)
                delete_info(prev_freq, key);
            add_info(M[key], key);
            update_freq_freq(M[key]);
        }
    
        void update_freq_freq(int freq) {
            list<int>::iterator it;
            bool updated = false;
            if (T.count(freq - 1)) {
                updated = true;
                it = K[freq - 1];
                if (T[freq - 1] == 1) {
                    T.erase(freq - 1);
                    it = F.erase(it);
                    K.erase(freq - 1);
                } else {
                    it++;
                    T[freq - 1]--;
                }
            }
            if (T.count(freq))
                T[freq]++;
            else {
                T[freq] = 1;
                if (updated) {
                    it = F.insert(it, freq);
                    K[freq] = it;
                } else {
                    F.push_front(freq);
                    K[freq] = F.begin();
                }
            }
        }
    
        void delete_freq_freq(int freq) {
            if (T[freq] == 1) {
                T.erase(freq);
                F.erase(K[freq]);
                K.erase(freq);
            } else
                T[freq]--;
        }
    
        void delete_info(int freq, int key) {
            auto it = L[freq].second[key];
            L[freq].second.erase(key);
            L[freq].first.erase(it);
            if (L[freq].second.empty())
                L.erase(freq);
        }
    
        void add_info(int freq, int key) {
            L[freq].first.push_back(key);
            L[freq].second[key] = --L[freq].first.end();
        }
    
        
};

int main(void) {
    int capacity = 5;
    LFUCache* obj = new LFUCache(capacity); 
}
