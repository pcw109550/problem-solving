// 630. Course Schedule III
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        int scheduleCourse(std::vector<std::vector<int> >& courses) {
            // O(N * log(N))
            std::sort(courses.begin(), courses.end(), [](std::vector<int> &a, std::vector<int> &b){return a[1] < b[1];});
            std::priority_queue<int> heap;
            int now = 0;
            for (int i = 0; i < courses.size(); i++) {
                heap.push(courses[i][0]);
                now += courses[i][0];
                if (now > courses[i][1]) {
                    now -= heap.top();
                    heap.pop();
                }
            }
            return heap.size();
        }
};

int main(void) {
    Solution s;
}