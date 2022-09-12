#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // O(N)
        int N = s1.size();
        vector<char> A, B;
        for (int i = 0; i < N; i++)
            if (s1[i] != s2[i]) {
                if (A.size() == 2)
                    return false;
                A.push_back(s1[i]);
                B.push_back(s2[i]);
            }
        if (A.size() == 0)
            return true;
        if (A.size() == 1)
            return false;
        return A[0] == B[1] && A[1] == B[0];
    }
};