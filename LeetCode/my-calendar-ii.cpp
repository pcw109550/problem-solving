// 731. My Calendar II
#include <iostream>
#include <map>
#include <climits>
using namespace std;

class MyCalendarTwo {
    multimap<int, int> M; // M[start] = end;
public:
    MyCalendarTwo() {
        // O(N ** 2)
    }
    
    bool book(int start, int end) {
        // O(N)
        auto it = M.upper_bound(end);
        if (it != M.begin() || (!M.empty() && it->second > start))
            it--;
        int num_overlap = 0;
        int prev_start = INT_MAX;
        while (true) {
            int cur_start = it->first;
            int cur_end = it->second;
            if (end > cur_start && cur_end > start) { 
                if (prev_start < cur_end) {
                    return false;
                }
                prev_start = cur_start;
            }
            if (it == M.begin())
                break;
            it--;
        }
        M.insert({start, end});
        return true;
    }
};

int main(void) {
    MyCalendarTwo* obj = new MyCalendarTwo();
}