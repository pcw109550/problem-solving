#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    vector<string> book {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    };
    
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // O(N)
        int result = 0;
        unordered_set<string> S;
        for (auto word : words) {
            auto translated_word = translate(word);
            S.insert(translated_word);
        }
        result = S.size();
        return result;
    }
    
    string translate(string &word) {
        string result;
        for (auto c : word)
            result += book[c - 'a'];
        return result;
    }
};