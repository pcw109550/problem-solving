// 421. Maximum XOR of Two Numbers in an Array
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode *child[2] = {};
    void increase(int number) {
        TrieNode *cur = this;
        for (int i = 31; i >= 0; --i) {
            int bit = (number >> i) & 1;
            if (cur->child[bit] == nullptr) cur->child[bit] = new TrieNode();
            cur = cur->child[bit];
        }
    }
    int findMax(int number) {
        TrieNode *cur = this;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (number >> i) & 1;
            if (cur->child[1 - bit] != nullptr) {
                cur = cur->child[1 - bit];
                ans |= (1 << i);
            } else cur = cur->child[bit];
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        TrieNode *trieNode = new TrieNode();
        for (int x : nums) trieNode->increase(x);
        
        int ans = 0;
        for (int x : nums) ans = max(ans, trieNode->findMax(x));
        return ans;
    }
};

int main(void) {
    Solution s;
}
