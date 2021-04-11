// 953. Verifying an Alien Dictionary
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
    public:
        bool isAlienSorted(std::vector<std::string>& words, std::string order) {
            // O(N * log(N))
            std::vector<std::string> temp;
            std::unordered_map<char, char> table;
            for (int i = 0; i < 26; i++)
                table[order[i]] = i + 'a'; 
            for (auto word : words)
                temp.push_back(translate(word, table));
            std::vector<std::string> temp2 = temp;
            std::sort(temp2.begin(), temp2.end());
            return temp == temp2;
        }
    
        std::string translate(std::string word, std::unordered_map<char, char> &table) {
            std::string result;
            for (auto c : word)
                result.push_back(table[c]);
            return result;
        }
};

int main(void) {
    Solution s;
}