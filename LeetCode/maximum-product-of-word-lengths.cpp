// 318. Maximum Product of Word Lengths
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

class Solution {
    std::vector<int> encoded;
    public:
        int maxProduct(std::vector<std::string>& words) {
            // O(N ** 2)
            int result = 0;
            int N = words.size();
            for (auto word : words)
                encoded.push_back(encode(word));
            for (int i = 0; i < N; i++)
                for (int j = i + 1; j < N; j++)
                    if (!(encoded[i] & encoded[j])) {
                        int temp = words[i].size() * words[j].size();
                        result = std::max(result, temp);
                    }   
            return result;
        }
    
        int encode(std::string word) {
            int result = 0;
            for (auto c : word)
                result |= 1 << (c - 'a');
            return result;
        }
};

int main(void) {
    Solution s;
}