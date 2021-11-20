// 832. Flipping an Image
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // O(N ** 2)
        int N = image.size();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N / 2; j++)
                swap(image[i][j], image[i][N - 1 - j]);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                image[i][j] = 1 - image[i][j];
        return image;
    }
};

int main(void) {
    Solution s;
}
