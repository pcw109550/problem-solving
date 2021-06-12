// 729. My Calendar I
#include <iostream>
#include <vector>
#include <utility>

class MyCalendar {
    std::vector<std::pair<int, int > > DB;
    public:
        MyCalendar() {
        }

        bool book(int start, int end) {
            // O(N ** 2)
            for (auto it : DB) {
                if (it.second < start || it.first > end - 1)
                    continue;
                return false;
            }
            DB.push_back({start, end - 1});
            return true;
        }
};

int main(void) {
    MyCalendar* obj = new MyCalendar();
}

