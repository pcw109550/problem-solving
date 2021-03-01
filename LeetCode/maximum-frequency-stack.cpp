// 895. Maximum Frequency Stack
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <set>

class FreqStack {
    int max_occ, idx;
    std::unordered_map<int, int> occ; // elem -> num_occ
    std::unordered_map<int, std::set<std::pair<int, int> > > elems; // num_occ -> set of {max_idx, elem}
    std::unordered_map<int, std::vector<int> > position; // elem -> vector of position
    public:
        FreqStack() {
            max_occ = 0;
            idx = 0;
        }

        void push(int x) {
            // log(N)
            if (!position[x].empty())
                elems[occ[x]].erase({position[x].back(), x});
            occ[x]++;
            max_occ = std::max(max_occ, occ[x]);
            elems[occ[x]].insert({idx, x});
            position[x].push_back(idx);
            idx++;
        }

        int pop() {
            // log(N)
            int result = (*elems[max_occ].rbegin()).second;
            elems[occ[result]].erase({position[result].back(), result});
            if (elems[occ[result]].empty())
                max_occ--;
            occ[result]--;
            position[result].pop_back();
            if (!position[result].empty())
                elems[occ[result]].insert({position[result].back(), result});
            return result;
        }
};

class FreqStack2 {
    int max_occ, idx;
    std::unordered_map<int, int> occ; // elem -> num_occ
    std::unordered_map<int, std::unordered_set<int> > elems; // num_occ -> unordered set of elem
    std::unordered_map<int, std::vector<int> > position; // elem -> vector of position
    public:
        FreqStack2() {
            max_occ = 0;
            idx = 0;
        }

        void push(int x) {
            // O(1)
            elems[occ[x]].erase(x);
            occ[x]++;
            max_occ = std::max(max_occ, occ[x]);
            elems[occ[x]].insert(x);
            position[x].push_back(idx);
            idx++;
        }

        int pop() {
            // O(N)
            int result = 0;
            int pos = -1;
            for (auto elem : elems[max_occ])
                if (pos < position[elem].back()) {
                    pos = position[elem].back();
                    result = elem;
                }
            elems[occ[result]].erase(result);
            if (elems[occ[result]].empty())
                max_occ--;
            occ[result]--;
            elems[occ[result]].insert(result);
            position[result].pop_back();
            return result;
        }
};

int main(void) {
    FreqStack *obj = new FreqStack();
}