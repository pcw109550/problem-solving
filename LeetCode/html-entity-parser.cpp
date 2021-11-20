// 1410. HTML Entity Parser
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string, char> M;
public:
    string entityParser(string text) {
        // O(N)
        string result, temp;
        int N = text.size();
        bool cand = false;
        init();
        for (int i = 0; i < N; i++) {
            if (!cand) {
                if (text[i] != '&')
                    result.push_back(text[i]);
                else {
                    temp.clear();
                    temp.push_back('&');
                    cand = true;
                }
                continue;
            }
            if (text[i] == '&') {
                result += temp;
                temp.clear();
                temp.push_back('&');
                continue;
            }
            temp.push_back(text[i]);
            if (temp.back() == ';') {
                if (M.count(temp)) {
                    result.push_back(M[temp]);
                    temp.clear();
                    cand = false;
                }
            }
        }
        result += temp;
        return result;
    }
    
    void init() {
        M["&quot;"] = '"';
        M["&apos;"] = '\'';
        M["&amp;"] = '&';
        M["&gt;"] = '>';
        M["&lt;"] = '<';
        M["&frasl;"] = '/';
    }
};

int main(void) {
    Solution s;
}