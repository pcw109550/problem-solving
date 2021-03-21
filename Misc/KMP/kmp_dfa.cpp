#include <iostream>
#include <string>
#include <vector>

class KMP {
    std::vector<std::vector<int> > D;
    public:
        int strStr(std::string txt, std::string pat) {
            // O(N)
            if (!pat.size())
                return 0;
            preprocess(pat);
            int M = pat.size();
            int N = txt.size();
            int j = 0;
            for (int i = 0; i < N; i++) {
                j = D[j][txt[i] - 'a'];
                if (j == M)
                    return i - M + 1;
            }
            return -1;
        }

        void preprocess(std::string &pat) {
            // O(M)
            int M = pat.size();
            int X = 0;
            D = std::vector<std::vector<int> > (M, std::vector<int>('z' - 'a' + 1, 0));
            D[0][pat[0] - 'a'] = 1;
            for (int i = 1; i < M; i++) {
                for (int c = 0; c < 'z' - 'a' + 1; c++)
                    D[i][c] = D[X][c];
                D[i][pat[i] - 'a'] = i + 1;
                X = D[X][pat[i] - 'a'];
            }
        }
};

int main(void) {
    KMP s;
} 