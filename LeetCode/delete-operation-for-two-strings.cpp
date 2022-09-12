class Solution {
public:
    int minDistance(string word1, string word2) {
        // LCS O(M * N)
        int M = word1.size(), N = word2.size();
        int result = 0, cur = 0;
        vector<vector<int> > D(M, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (word1[i] == word2[j])
                    D[i][j] = ((i >= 1 && j >= 1) ? D[i - 1][j - 1] : 0) + 1;
                else {
                    int next = 0;
                    next = max(next, (i >= 1 && j >= 1) ? D[i - 1][j - 1] : 0);
                    next = max(next, i >= 1 ? D[i - 1][j] : 0);
                    next = max(next, j >= 1 ? D[i][j - 1] : 0);
                    D[i][j] = next;
                }
                cur = max(cur, D[i][j]);
            }
        }
        result = M + N - 2 * cur;
        return result;
    }
};