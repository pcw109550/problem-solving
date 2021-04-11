// 1813. Sentence Similarity III
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution {
    public:
        bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
            // O(N)
            auto t1 = tokenize(sentence1);
            auto t2 = tokenize(sentence2);
            return check(t1, t2) || check(t2, t1);
        }

        bool check(std::vector<std::string> &t1, std::vector<std::string> &t2) {
            if (t1.size() < t2.size())
                return false;
            std::vector<bool> conq(t2.size(), false);
            for (int i = 0; i < t2.size(); i++) {
                if (t1[i] == t2[i])
                    conq[i] = true;
                else
                    break;
            }
            for (int i = t2.size() - 1; i >= 0; i--) {
                if (t1[t1.size() - 1 - (t2.size() - 1 - i)] == t2[i])
                    conq[i] = true;
                else
                    break;
            }
            for (auto it : conq)
                if (!it)
                    return false;
            return true;
        }

        std::vector<std::string> tokenize(std::string &s) {
            std::vector<std::string> result;
            std::istringstream f(s);
            std::string token;    
            while (std::getline(f, token, ' '))
                result.push_back(token);
            return result;
        }
};

int main(void) {
    Solution s;
}