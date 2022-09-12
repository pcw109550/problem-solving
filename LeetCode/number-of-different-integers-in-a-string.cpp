#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        // O(N)
        int result = 0;
        unordered_set<string> temp;
        string cur;
        word.push_back('z');
        for (auto c : word) {
            if (isalpha(c)) {
                if (!cur.empty()) {
                    bool zero = true;
                    string real;
                    for (auto k : cur) {
                        if (k == '0') {
                            if (zero) {
                                continue;
                            } else
                                real.push_back(k);
                        } else {
                            zero = false;
                            real.push_back(k);
                        }
                    }
                    temp.insert(real);
                }
                cur.clear();
            } else {
                cur.push_back(c);     
            }
        }
        result = temp.size();
        return result;
    }
};