#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // O(N)
        vector<int> in(n, 0), out(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int l = leftChild[i];
            int r = rightChild[i];
            if (l != -1) {
                cnt++;
                in[l]++;
                out[i]++;
            }
            if (r != -1) {
                cnt++;
                in[r]++;
                out[i]++;
            }
        }
        if (cnt != n - 1)
            return false;
        int start = -1;
        for (int i = 0; i < n; i++)
            if (in[i] > 1)
                return false;
            else if (in[i] == 0)
                start = i;
        for (int i = 0; i < n; i++)
            if (out[i] > 2)
                return false;
        vector<bool> visited(n, false);
        queue<int> Q; visited[start] = true;
        Q.push(start);
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            int l = leftChild[cur];
            int r = rightChild[cur];
            if (l != -1) {
                if (visited[l])
                    return false;
                visited[l] = true;
                Q.push(l);
            }
            if (r != -1) {
                if (visited[r])
                    return false;
                visited[r] = true;
                Q.push(r);
            }
        }
        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;
        return true;
    }
};