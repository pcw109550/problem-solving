#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        // O(N ** 4)
        int result = 0;
        int N = img1.size();
        for (int i = - N; i < N; i++)
            for (int j = - N; j < N; j++) {
                int temp = 0;
                for (int a = 0; a < N; a++)
                    for (int b = 0; b < N; b++) {
                        int x = a + i, y = b + j;
                        if (x < 0 || y < 0 || x >= N || y >= N)
                            continue;
                        if (img1[a][b] == img2[x][y] && img2[x][y] == 1)
                            temp++;
                    }              
                result = max(result, temp);
            }
        return result;
    }
};