// 223. Rectangle Area
#include <algorithm>
#include <iostream>

class Solution {
    public:
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {       
            // O(1)
            int S1 = (ax2 - ax1) * (ay2 - ay1);
            int S2 = (bx2 - bx1) * (by2 - by1);
            int xmin = std::min(ax1, bx1);
            int xmax = std::max(ax2, bx2);
            int ymin = std::min(ay1, by1);
            int ymax = std::max(ay2, by2);
            int xoverlap = (ax2 - ax1) + (bx2 - bx1) - (xmax - xmin);
            int yoverlap = (ay2 - ay1) + (by2 - by1) - (ymax - ymin);
            int S = (xoverlap > 0 && yoverlap > 0) ? xoverlap * yoverlap : 0;
            return S1 + S2 - S;
        }
};

int main(void) {
    Solution s;
}