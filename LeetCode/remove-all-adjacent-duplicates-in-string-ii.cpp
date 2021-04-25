// 1209. Remove All Adjacent Duplicates in String II
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::string removeDuplicates(std::string s, int k) {
            // O(N)
            std::string result;
            std::vector<int> cons;
            std::vector<char> store;
            for (int i = 0; i < s.size(); i++) {
                if (i == 0 || store.size() == 0 || s[i] != store.back())
                    cons.push_back(1);
                else if (s[i] == store.back())
                    cons.push_back(cons.back() + 1);
                store.push_back(s[i]);
                if (cons.back() == k) {
                    for (int j = 0; j < k; j++) {
                        cons.pop_back();
                        store.pop_back();
                    }    
                }
            }
            result = std::string(store.begin(), store.end());
            return result;
        }
};

int main(void) {
    Solution s;
}