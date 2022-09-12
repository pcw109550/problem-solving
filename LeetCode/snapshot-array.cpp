#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class SnapshotArray {
    vector<map<int, int> > D; // update_idx -> value
    int L, num_snap, update_idx;
    unordered_map<int, int> M; // snap_idx -> update_idx
public:
    SnapshotArray(int length): L(length), num_snap(0), update_idx(0) {
        // O(N * log(N))
        D = vector<map<int, int> > (length);
    }
    
    void set(int index, int val) {
        // O(1)
        update_idx++;
        D[index][update_idx] = val;
    }
    
    int snap() {
        // O(1)
        int result = num_snap;
        M[num_snap] = update_idx;
        num_snap++;
        return result;
    }
    
    int get(int index, int snap_id) {
        // O(log(N))
        int cur_update_idx = M[snap_id];
        auto it = D[index].lower_bound(cur_update_idx);
        if (it->first == cur_update_idx)
            return it->second;
        else if (it == D[index].begin())
            return 0;
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */