// 295. Find Median from Data Stream
#include <iostream>
#include <set>
#include <iterator>
using namespace std;

class MedianFinder {
    multiset<int> S;
    multiset<int>::iterator probe;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        // O(log(N))
        int N = S.size();
        if (N == 0) {
            S.insert(num);
            probe = S.begin();
            return;
        }
        S.insert(num);
        if (N % 2 == 0)
            addNumEven(num);
        else
            addNumOdd(num);
    }
    
    void addNumEven(int num) {
        int prevnum = *probe;
        if (prevnum <= num)
            probe++;
    }
    
    void addNumOdd(int num) {
        int prevnum = *probe;
        if (prevnum > num)
            probe--;
    }
    
    double findMedian() {
        // O(1)
        double result = 0.0;
        int N = S.size();
        if (N % 2 == 0)
            result += (*probe + *next(probe, 1)) / 2.0;
        else
            result += *probe;
        return result;
    }
};

int main(void) {
    MedianFinder* obj;
}
